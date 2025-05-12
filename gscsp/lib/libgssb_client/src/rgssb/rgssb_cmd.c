/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <gs/gssb/rgssb.h>

#include <stdlib.h>
#include <string.h>

#include <gs/gosh/command/command.h>
#include <gs/gosh/util/console.h>
#include <gs/util/stdio.h>
#include <gs/csp/csp.h>
#include <gs/csp/port.h>
#include "local.h"

static gs_rgssb_dest_t dest = { .csp_node = 1,
                      .csp_timeout = 2000,
                      .csp_port = GS_CSP_PORT_GSSB,
                      .i2c_addr = 5,
                      .i2c_timeout = 100 };


static int cmd_set_gssb_node(struct command_context *ctx) {

    if ((ctx->argc == 2) || (ctx->argc == 3) || (ctx->argc ==4)) {
        int tmp = atoi(ctx->argv[1]);
        if ((tmp > 32) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Node %d out of range [0 - 32]\r\n", tmp);
            return CMD_ERROR_SYNTAX;
        }
        dest.csp_node = tmp;
        if (ctx->argc >= 3) {
            tmp = atoi(ctx->argv[2]);
            if ((tmp > 10000) || (tmp < 0)) {
                gs_color_printf(GS_COLOR_RED, "Timeout %d out of range [0 - 10000]\r\n", tmp);
                return CMD_ERROR_SYNTAX;
            }
            dest.csp_timeout = tmp;
        }
        if (ctx->argc >= 4) {
            tmp = atoi(ctx->argv[3]);
            if ((tmp > 63) || (tmp < 0)) {
                gs_color_printf(GS_COLOR_RED, "Port %d out of range [0 - 63]\r\n", tmp);
                return CMD_ERROR_SYNTAX;
            }
            dest.csp_port = tmp;
        }

    } else {
        return CMD_ERROR_SYNTAX;
    }
    return CMD_ERROR_NONE;
}

static int cmd_set_addr_csp(struct command_context *ctx) {

    if ((ctx->argc == 2) || (ctx->argc == 3)) {
        int tmp = atoi(ctx->argv[1]);
        if ((tmp > 128) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Addr %d out of range [0 - 128]\r\n", tmp);
            return CMD_ERROR_SYNTAX;
        }
        dest.i2c_addr = tmp;
        if (ctx->argc == 3) {
            tmp = atoi(ctx->argv[2]);
            if ((tmp > 500) || (tmp < 0)) {
                gs_color_printf(GS_COLOR_RED, "Timeout %d out of range [0 - 500]\r\n", tmp);
                return CMD_ERROR_SYNTAX;
            }
            dest.i2c_timeout = tmp;
        }
    } else {
        return CMD_ERROR_SYNTAX;
    }
    return CMD_ERROR_NONE;
}

static int cmd_gssb_ident_csp(struct command_context *ctx) {
	gs_gssb_ident_t resp;

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_ident(dest, &resp) != GS_OK)
		return CMD_ERROR_FAIL;

	resp.version[19] = '\0';

	printf("Version: \t%s\r\n", (char *) resp.version);
	printf("Device UUID: %"PRIu32"\r\n", resp.uuid);

	return CMD_ERROR_NONE;
}

static int cmd_gssb_get_model_csp(struct command_context *ctx) {
    gs_gssb_model_t model;

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_model(dest, &model) != GS_OK)
		return CMD_ERROR_FAIL;
	printf("Model: ");
	switch(model){
		case GS_GSSB_MODEL_MSP:
			printf("MSP\n\r");
			break;
		case GS_GSSB_MODEL_AR6:
			printf("AR6\n\r");
			break;
		case GS_GSSB_MODEL_ISTAGE:
			printf("Interstage\n\r");
			break;
		case GS_GSSB_MODEL_ANT6:
			printf("ANT6\n\r");
			break;
		default:
		    printf("Unknown\r\n");
	}
	return CMD_ERROR_NONE;
}

static int cmd_istage_settings_csp(struct command_context *ctx) {

	gs_gssb_istage_burn_settings_t settings;

	if (ctx->argc == 1) {

		if (gs_rgssb_istage_settings_get(dest, &settings) != GS_OK)
			return CMD_ERROR_FAIL;

		if (settings.status == 2) {
			printf("\r\nDeploy mode:\t\t ARMED AUTO\r\n");
		} else {
			printf("\r\nDeploy mode:\t\t NOT ARMED\r\n");
		}
		printf("Deploy delay from boot:\t %"PRIu16" s\r\n", settings.short_cnt_down);

		printf("\r\n-------- Deploy algorithm config ----------\r\n");
		printf("Knife on time:\t\t %i ms\r\n", settings.std_time_ms);
		printf("Increment:\t\t %i ms\r\n", settings.increment_ms);
		printf("Max repeats:\t\t %i\r\n", settings.max_repeat);
		printf("Repeat time:\t\t %i s\r\n", settings.rep_time_s);
		printf("Switch polarity:\t %"PRIu8"\r\n", settings.switch_polarity);
		printf("Settings locked:\t %"PRIu8"\r\n", settings.locked);

	/* Else set settings */
	} else if (ctx->argc == 8) {
		/* Check settings range */
		int tmp;
		tmp = atoi(ctx->argv[1]);
		if ((tmp > 65535) || (tmp < 0)) {
			gs_color_printf(GS_COLOR_RED, "Knife on time of %d out of range [0 - 65535]\r\n", tmp);
			return CMD_ERROR_SYNTAX;
		} else {
			settings.std_time_ms = (uint16_t)tmp;
		}

		tmp = atoi(ctx->argv[2]);
		if ((tmp > 65535) || (tmp < 0)) {
			gs_color_printf(GS_COLOR_RED, "Increment of %d out of range [0 - 65535]\r\n", tmp);
			return CMD_ERROR_SYNTAX;
		} else {
			settings.increment_ms = (uint16_t)tmp;
		}

		tmp = atoi(ctx->argv[3]);
		if ((tmp > 65535) || (tmp < 0)) {
			gs_color_printf(GS_COLOR_RED, "Auto deploy delay of %d out of range [0 - 65535]\r\n", tmp);
			return CMD_ERROR_SYNTAX;
		} else {
			settings.short_cnt_down = (uint16_t)tmp;
		}

		tmp = atoi(ctx->argv[4]);
		if ((tmp > 255) || (tmp < 0)) {
			gs_color_printf(GS_COLOR_RED, "Max repeats of %d out of range [0 - 255]\r\n", tmp);
			return CMD_ERROR_SYNTAX;
		} else {
			settings.max_repeat = (uint8_t)tmp;
		}

		tmp = atoi(ctx->argv[5]);
		if ((tmp > 255) || (tmp < 0)) {
			gs_color_printf(GS_COLOR_RED, "Time between repeats of %d out of range [0 - 255]\r\n", tmp);
			return CMD_ERROR_SYNTAX;
		} else {
			settings.rep_time_s = (uint8_t)tmp;
		}

		tmp = atoi(ctx->argv[6]);
		if ((tmp > 1) || (tmp < 0)) {
			gs_color_printf(GS_COLOR_RED, "Polarity can only be selected to 0 or 1 not %d\r\n", tmp);
			return CMD_ERROR_SYNTAX;
		} else {
			settings.switch_polarity = (uint8_t)tmp;
		}

		tmp = atoi(ctx->argv[7]);
		if ((tmp > 255) || (tmp < 0)) {
			gs_color_printf(GS_COLOR_RED, "Reboot deploy number of %d out of range [0 - 255]\r\n", tmp);
			return CMD_ERROR_SYNTAX;
		} else {
			settings.reboot_deploy_cnt = (uint8_t)tmp;
		}

		if (gs_rgssb_istage_settings_set(dest, &settings) != GS_OK)
			return CMD_ERROR_FAIL;

	} else {
		return CMD_ERROR_SYNTAX;
	}

	return CMD_ERROR_NONE;
}

static int cmd_reboot_csp(struct command_context *ctx) {

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;


	if (gs_rgssb_reboot(dest) != GS_OK)
		return CMD_ERROR_FAIL;

	return CMD_ERROR_NONE;
}

static int cmd_istage_deploy_csp(struct command_context *ctx) {

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_istage_deploy(dest) != GS_OK)
		return CMD_ERROR_FAIL;

	return CMD_ERROR_NONE;
}

static int cmd_istage_arm_csp(struct command_context *ctx) {

	if (ctx->argc != 2)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_istage_arm(dest, atoi(ctx->argv[1])) != GS_OK)
		return CMD_ERROR_FAIL;

	return CMD_ERROR_NONE;
}

static int cmd_istage_state_csp(struct command_context *ctx) {

	if (ctx->argc != 2)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_istage_set_state(dest, atoi(ctx->argv[1])) != GS_OK)
		return CMD_ERROR_FAIL;

	return CMD_ERROR_NONE;
}

static int cmd_istage_sensors_csp(struct command_context *ctx) {
	gs_gssb_istage_sensors_t sensors;

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;


	if (gs_rgssb_istage_sensors(dest, &sensors) != GS_OK)
		return CMD_ERROR_FAIL;

	printf("Panel Temperature: %f\r\n", sensors.panel_temp);
	printf("Coarse Sunsensor: %d\r\n", sensors.sun_voltage);
    printf("Temp in MCU: %d\r\n", sensors.internal_temp);

	return CMD_ERROR_NONE;
}

static int cmd_istage_status_csp(struct command_context *ctx) {
	gs_gssb_istage_status_t status;
	const char *state_str;

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_istage_status(dest, &status) != GS_OK)
		return CMD_ERROR_FAIL;

	switch (status.state) {
		case 0:
			state_str = "Not armed";
			break;
		case 1:
			state_str = "Armed for manual deploy";
			break;
		case 2:
			state_str = "Armed for auto deploy";
			break;
		case 3:
		case 4:
			state_str = "Deploying";
			break;
		default:
			state_str = "Unknown state";
			break;
	};


	printf("Current state:\t\t\t\t %s\r\n", state_str);
	if (status.release_status == 1)
		gs_color_printf(GS_COLOR_GREEN, "Antenna state:\t\t\t\t %s\r\n", "Released");
	else
		gs_color_printf(GS_COLOR_RED, "Antenna state:\t\t\t\t %s\r\n", "Not released");
	printf("\r\n");

	printf("Delay till deploy:\t\t\t %"PRIu16" s\r\n", status.deploy_in_s);
	printf("Number of attemps since boot:\t\t %"PRIu8"\r\n", status.number_of_deploys);
	printf("Knife that will be use in next deploy:\t %"PRIu8"\r\n", status.active_knife);
	printf("Total deploy attemps:\t\t\t %"PRIu16"\r\n", status.total_number_of_deploys);
	printf("Reboot deploy cnt:\t\t\t %"PRIu8"\r\n", status.reboot_deploy_cnt);


	return CMD_ERROR_NONE;
}

static int cmd_ant6_status_csp(struct command_context *ctx) {
	gs_gssb_ant6_status_t status;


	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_ant6_status(dest, &status) != GS_OK)
		return CMD_ERROR_FAIL;

	printf("Channel 0\n\r");
	if (status.release.channel_0_state == 1)
		gs_color_printf(GS_COLOR_RED, "\tBurn state:\t\t\t\t %s\r\n", "Burning");
	else
		printf("\tBurn state:\t\t\t\t %s\r\n", "Idle");

	printf("\tBurn time left:\t\t\t\t %hhu\r\n", status.release.channel_0_burn_time_left);

	if (status.release.channel_0_status == 1)
		gs_color_printf(GS_COLOR_GREEN, "\tAntenna state:\t\t\t\t %s\r\n", "Released");
	else
		gs_color_printf(GS_COLOR_RED,"\tAntenna state:\t\t\t\t %s\r\n", "Not released");

	printf("\tBurn attempts:\t\t\t\t %hhu\r\n", status.release.channel_0_burn_tries);

	printf("Channel 1\n\r");
	if (status.release.channel_1_state == 1)
		gs_color_printf(GS_COLOR_RED, "\tBurn state:\t\t\t\t %s\r\n", "Burning");
	else
		printf("\tBurn state:\t\t\t\t %s\r\n", "Idle");

	printf("\tBurn time left:\t\t\t\t %hhu\r\n", status.release.channel_1_burn_time_left);

	if (status.release.channel_1_status == 1)
		gs_color_printf(GS_COLOR_GREEN, "\tAntenna state:\t\t\t\t %s\r\n", "Released");
	else
		gs_color_printf(GS_COLOR_RED,"\tAntenna state:\t\t\t\t %s\r\n", "Not released");

	printf("\tBurn attempts:\t\t\t\t %hhu\r\n", status.release.channel_1_burn_tries);

    printf("Backup\n\r");
    printf("\tState:\t\t\t\t\t ");
    if (status.backup.state == 0) {
        gs_color_printf(GS_COLOR_GREEN, "Finished successful\r\n");
    } else if (status.backup.state == 1) {
        gs_color_printf(GS_COLOR_GREEN, "Waiting to deploy\r\n");
        printf("\tSeconds to backup deploy:\t\t %"PRIu32"\r\n", status.backup.seconds_to_deploy);
    } else if (status.backup.state == 2) {
        gs_color_printf(GS_COLOR_RED, "Deploying\r\n");
    } else if (status.backup.state == 3) {
        gs_color_printf(GS_COLOR_RED, "Finished unsuccessful\r\n");
    } else if (status.backup.state == 4) {
        gs_color_printf(GS_COLOR_RED, "Not active\r\n");
    }

    printf("Board\n\r");
    printf("\tSeconds since boot:\t\t\t %"PRIu32"\r\n", status.board.seconds_since_boot);
    printf("\tNumber of reboots:\t\t\t %hhu\r\n", status.board.reboot_count);

    return CMD_ERROR_NONE;
}

static int cmd_i4_status_csp(struct command_context *ctx)
{
    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    gs_gssb_i4_status_t status;

    if (gs_rgssb_i4_status(dest, &status) != GS_OK)
        return CMD_ERROR_FAIL;

    printf("Channel 0\n\r");
    if (status.release.channel_0_state == 1)
        gs_color_printf(GS_COLOR_RED, "\tBurn state:\t\t\t\t %s\r\n", "Burning");
    else
        printf("\tBurn state:\t\t\t\t %s\r\n", "Idle");

    printf("\tBurn time left:\t\t\t\t %hhu\r\n", status.release.channel_0_burn_time_left);

    if (status.release.channel_0_status_0 == 1)
        gs_color_printf(GS_COLOR_GREEN, "\tAntenna state:\t\t\t\t %s\r\n", "Released");
    else
        gs_color_printf(GS_COLOR_RED, "\tAntenna state:\t\t\t\t %s\r\n", "Not released");

    if (status.release.channel_0_status_1 == 2)
        gs_color_printf(GS_COLOR_GREEN, "\tAntenna state:\t\t\t\t %s\r\n", "Released");
    else
        gs_color_printf(GS_COLOR_RED, "\tAntenna state:\t\t\t\t %s\r\n", "Not released");

    printf("\tBurn attempts:\t\t\t\t %hhu\r\n", status.release.channel_0_burn_tries);

    printf("Channel 1\n\r");
    if (status.release.channel_1_state == 1)
        gs_color_printf(GS_COLOR_RED, "\tBurn state:\t\t\t\t %s\r\n", "Burning");
    else
        printf("\tBurn state:\t\t\t\t %s\r\n", "Idle");

    printf("\tBurn time left:\t\t\t\t %hhu\r\n", status.release.channel_1_burn_time_left);

    if (status.release.channel_1_status_0 == 1)
        gs_color_printf(GS_COLOR_GREEN, "\tAntenna state:\t\t\t\t %s\r\n", "Released");
    else
        gs_color_printf(GS_COLOR_RED, "\tAntenna state:\t\t\t\t %s\r\n", "Not released");

    if (status.release.channel_1_status_1== 2)
        gs_color_printf(GS_COLOR_GREEN, "\tAntenna state:\t\t\t\t %s\r\n", "Released");
    else
        gs_color_printf(GS_COLOR_RED, "\tAntenna state:\t\t\t\t %s\r\n", "Not released");

    printf("\tBurn attempts:\t\t\t\t %hhu\r\n", status.release.channel_1_burn_tries);

    printf("Backup\n\r");
    printf("\tState:\t\t\t\t\t ");
    if (status.backup.state == 0) {
        gs_color_printf(GS_COLOR_GREEN, "Finished successful\r\n");
    } else if (status.backup.state == 1) {
        gs_color_printf(GS_COLOR_GREEN, "Waiting to deploy\r\n");
        printf("\tSeconds to backup deploy:\t\t %"PRIu32"\r\n", status.backup.seconds_to_deploy);
    } else if (status.backup.state == 2) {
        gs_color_printf(GS_COLOR_RED, "Deploying\r\n");
    } else if (status.backup.state == 3) {
        gs_color_printf(GS_COLOR_RED, "Finished unsuccessful\r\n");
    } else if (status.backup.state == 4) {
        gs_color_printf(GS_COLOR_RED, "Not active\r\n");
    }

    printf("Board\n\r");
    printf("\tSeconds since boot:\t\t\t %"PRIu32"\r\n", status.board.seconds_since_boot);
    printf("\tNumber of reboots:\t\t\t %hhu\r\n", status.board.reboot_count);

    return CMD_ERROR_NONE;
}

static int cmd_common_backup_settings_csp(struct command_context *ctx)
{
    gs_gssb_backup_settings_t settings;

    if (ctx->argc != 4 && ctx->argc != 1)
        return CMD_ERROR_SYNTAX;
    if (ctx->argc == 4) {
        int tmp;
        tmp = atoi(ctx->argv[1]);
        if ((tmp > 5000) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Minutes until deploy out of range [0 - 5000]\r\n");
            return CMD_ERROR_SYNTAX;
        } else {
            settings.minutes = tmp;
        }

        tmp = atoi(ctx->argv[2]);
        if ((tmp != 1) && (tmp != 0)) {
            gs_color_printf(GS_COLOR_RED, "Backup active out of range [0 - 1]\r\n");
            return CMD_ERROR_SYNTAX;
        } else {
            settings.backup_active = tmp;
        }

        tmp = atoi(ctx->argv[3]);
        if ((tmp > 127) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Max burn duration out of range [0 - 127]\r\n");
            return CMD_ERROR_SYNTAX;
        } else {
            settings.max_burn_duration = tmp;
        }

        if (gs_rgssb_common_set_backup_settings(dest, settings) != GS_OK)
            return CMD_ERROR_FAIL;
    } else {
        if (gs_rgssb_common_get_backup_settings(dest, &settings) != GS_OK)
            return CMD_ERROR_FAIL;
    }
    printf("Backup deploy settings:\n\r\tMinutes until deploy:\t\t\t %hu\n\r\tBackup deployment:\t\t\t ",
           settings.minutes);
    if (settings.backup_active == 1) {
        gs_color_printf(GS_COLOR_GREEN, "Active\n\r");
    } else {
        gs_color_printf(GS_COLOR_RED, "Not active\n\r");
    }
    printf("\tMax burn duration:\t\t\t %hhu\n\r", settings.max_burn_duration);
    if (ctx->argc == 4) {
        printf("\n\rReboot board for changes to take effect\n\r");
    }
    return CMD_ERROR_NONE;
}

static int cmd_common_internal_temp_csp(struct command_context *ctx) {
    int16_t internal_temp;

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_common_internal_temp(dest, &internal_temp) != GS_OK)
		return CMD_ERROR_FAIL;

	printf("Temperature inside MCU: %d\r\n", internal_temp);

	return CMD_ERROR_NONE;
}

static int cmd_common_burn_channel_csp(struct command_context *ctx) {
	uint8_t burn_seconds, channel;
	if (ctx->argc != 3)
		return CMD_ERROR_SYNTAX;
	int tmp;
	tmp = atoi(ctx->argv[1]);
	if ((tmp > 1) || (tmp < 0)) {
		gs_color_printf(GS_COLOR_RED, "Channels out of range [0 - 1]\r\n");
		return CMD_ERROR_SYNTAX;
	} else {
		channel = tmp;
	}
	tmp = atoi(ctx->argv[2]);
	if ((tmp > 255) || (tmp < 0)) {
		gs_color_printf(GS_COLOR_RED, "Duration out of range [0 - 255]\r\n");
		return CMD_ERROR_SYNTAX;
	} else {
		burn_seconds = tmp;
	}

	if (gs_rgssb_common_burn_channel(dest, channel, burn_seconds) != GS_OK){
		return CMD_ERROR_FAIL;
	}
	else{
		return CMD_ERROR_NONE;
	}
}

static int cmd_common_stop_burn_csp(struct command_context *ctx) {
	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_common_stop_burn(dest) != GS_OK)
		return CMD_ERROR_FAIL;

	return CMD_ERROR_NONE;
}

static int cmd_common_reset_count_csp(struct command_context *ctx) {
	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_common_reset_count(dest) != GS_OK)
		return CMD_ERROR_FAIL;

	return CMD_ERROR_NONE;
}

static int cmd_ar6_status_csp(struct command_context *ctx) {
	gs_gssb_ar6_status_t status;

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_ar6_status(dest, &status) != GS_OK)
		return CMD_ERROR_FAIL;

	printf("Antenna release\n\r");
	if (status.release.state == 1)
		gs_color_printf(GS_COLOR_RED, "\tBurn state:\t\t\t\t %s\r\n", "Burning");
	else
		printf("\tBurn state:\t\t\t\t %s\r\n", "Idle");

	printf("\tBurn time left:\t\t\t\t %hhu\r\n", status.release.burn_time_left);

	if (status.release.status == 1)
		gs_color_printf(GS_COLOR_GREEN, "\tAntenna state:\t\t\t\t %s\r\n", "Released");
	else
		gs_color_printf(GS_COLOR_RED,"\tAntenna state:\t\t\t\t %s\r\n", "Not released");

	printf("\tBurn attempts:\t\t\t\t %hhu\r\n", status.release.burn_tries);

    printf("Backup\n\r");
    printf("\tState:\t\t\t\t\t ");
    if (status.backup.state == 0) {
        gs_color_printf(GS_COLOR_GREEN, "Finished successful\r\n");
    } else if (status.backup.state == 1) {
        gs_color_printf(GS_COLOR_GREEN, "Waiting to deploy\r\n");
        printf("\tSeconds to backup deploy:\t\t %"PRIu32"\r\n", status.backup.seconds_to_deploy);
    } else if (status.backup.state == 2) {
        gs_color_printf(GS_COLOR_RED, "Deploying\r\n");
    } else if (status.backup.state == 3) {
        gs_color_printf(GS_COLOR_RED, "Finished unsuccessful\r\n");
    } else if (status.backup.state == 4) {
        gs_color_printf(GS_COLOR_RED, "Not active\r\n");
    }

	printf("Board\n\r");
	printf("\tSeconds since boot:\t\t\t %"PRIu32"\r\n", status.board.seconds_since_boot);
	printf("\tNumber of reboots:\t\t\t %hhu\r\n", status.board.reboot_count);

	return CMD_ERROR_NONE;
}

static int cmd_ar6_burn_csp(struct command_context *ctx) {
	if (ctx->argc != 2)
		return CMD_ERROR_SYNTAX;
	int tmp;
	uint16_t burn_seconds;
	tmp = atoi(ctx->argv[1]);
	if ((tmp > 255) || (tmp < 0)) {
		gs_color_printf(GS_COLOR_RED, "Duration out of range [0 - 255]\r\n");
		return CMD_ERROR_SYNTAX;
	} else {
		burn_seconds = tmp;
	}

	if (gs_rgssb_ar6_burn(dest, burn_seconds) != GS_OK){
		return CMD_ERROR_FAIL;
	}

	return CMD_ERROR_NONE;
}


static int cmd_msp_sensors_csp(struct command_context *ctx) {
	gs_gssb_msp_sensors_t sensors;

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_msp_sensors(dest, &sensors) != GS_OK)
		return CMD_ERROR_FAIL;

	printf("Outside temperature: %"PRIi16"\r\n", sensors.outside_temp);
	printf("Temperature inside MCU: %"PRIi16"\r\n", sensors.internal_temp);
	printf("Coarse sun sensor: %"PRIu16"\r\n", sensors.sun_voltage);

	return CMD_ERROR_NONE;
}

static int cmd_sunsensor_read_csp(struct command_context *ctx) {
	uint16_t sun[4];
	int i;

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_sunsensor_sample_get_data(dest, sun, 4) != GS_OK)
		return CMD_ERROR_FAIL;

	printf("\r\n ---- Values ----\r\n");
	for (i=0; i < 4; i++) {
		printf("Data %d: %d\r\n", i, sun[i]);
	}

	return CMD_ERROR_NONE;
}

static int cmd_sunsensor_temp_csp(struct command_context *ctx) {
	float temp;

	if (ctx->argc != 1)
		return CMD_ERROR_SYNTAX;

	if (gs_rgssb_sunsensor_sample_get_temp(dest, &temp) != GS_OK)
		return CMD_ERROR_FAIL;

	printf("Temp: %f\r\n", temp);

	return CMD_ERROR_NONE;
}

static const command_t __sub_command interstage_csp_subcommands[] = {
	{
		.name = "sensors",
		.help = "Read sensors",
		.handler = cmd_istage_sensors_csp,
	},{
		.name = "status",
		.help = "Status",
		.handler = cmd_istage_status_csp,
	},{
		.name = "arm",
		.help = "Interstage arm",
		.handler = cmd_istage_arm_csp,
		.usage = "<1 = arm, 0 = disarm>",
	},{
		.name = "conf",
		.help = "Set or get configuration. To get give no arguments",
		.handler = cmd_istage_settings_csp,
		.usage = "<knife ON [ms]> <increment [ms]> <auto deploy delay [s]> <max repeat [#]> <repeat time [s]> <switch polarity> <deploy boot cnt>",
	},{
		.name = "state",
		.help = "Set current state",
		.handler = cmd_istage_state_csp,
		.usage = "<State 0=NOT ARMED, 1=ARMED MANUAL>",
	},{
		.name = "deploy",
		.help = "Manual trigger deploy",
		.handler = cmd_istage_deploy_csp,
	},{
		.name = "reboot",
		.help = "Soft reboot",
		.handler = cmd_reboot_csp,
	},
};

static const command_t __sub_command ant6_csp_subcommands[] = {
	{
		.name = "temp_internal",
		.help = "Read internal temperature",
		.handler = cmd_common_internal_temp_csp,
	},{
		.name = "status",
		.help = "Get status from the two channels",
		.handler = cmd_ant6_status_csp,
	},{
		.name = "burn",
		.help = "Burn on a channel for specific duration",
		.handler = cmd_common_burn_channel_csp,
		.usage = "<channel> <duration [s]>",
	},{
		.name = "stop",
		.help = "Stop burning on both channels",
		.handler = cmd_common_stop_burn_csp,
	},{
        .name = "settings",
        .help = "Get/set backup burn settings",
        .usage = "<delay_until_deploy [min]> <backup_active> <max_burn_duration>",
        .handler = cmd_common_backup_settings_csp,
    },{
		.name = "reset_counters",
		.help = "Resets counters",
		.handler = cmd_common_reset_count_csp,
	},{
		.name = "reboot",
		.help = "Soft reboot",
		.handler = cmd_reboot_csp,
	},
};

static const command_t __sub_command i4_csp_subcommands[] = {
    {
        .name = "temp_internal",
        .help = "Read internal temperature",
        .handler = cmd_common_internal_temp_csp,
    },{
        .name = "status",
        .help = "Get status from the two channels",
        .handler = cmd_i4_status_csp,
    },{
        .name = "burn",
        .help = "Burn on a channel for specific duration",
        .handler = cmd_common_burn_channel_csp,
        .usage = "<channel> <duration [s]>",
    },{
        .name = "stop",
        .help = "Stop burning on both channels",
        .handler = cmd_common_stop_burn_csp,
    },{
        .name = "settings",
        .help = "Get/set backup burn settings",
        .usage = "<delay_until_deploy [min]> <backup_active> <max_burn_duration>",
        .handler = cmd_common_backup_settings_csp,
    },{
        .name = "reset_counters",
        .help = "Resets counters",
        .handler = cmd_common_reset_count_csp,
    },{
        .name = "reboot",
        .help = "Soft reboot",
        .handler = cmd_reboot_csp,
    },
};

static const command_t __sub_command ar6_csp_subcommands[] = {
	{
        .name = "temp_internal",
        .help = "Read internal temperature",
		.handler = cmd_common_internal_temp_csp,
	},{
		.name = "status",
		.help = "Get status from the two channels",
		.handler = cmd_ar6_status_csp,
	},{
		.name = "burn",
		.help = "Burn on a channel for specific duration",
		.handler = cmd_ar6_burn_csp,
		.usage = "<duration [s]>",
	},{
		.name = "stop",
		.help = "Stop burning on both channels",
		.handler = cmd_common_stop_burn_csp,
	},{
        .name = "settings",
        .help = "Get/set backup burn settings",
        .usage = "<delay_until_deploy [min]> <backup_active> <max_burn_duration>",
        .handler = cmd_common_backup_settings_csp,
    },{
		.name = "reset_counters",
		.help = "Resets counters",
		.handler = cmd_common_reset_count_csp,
	},{
		.name = "reboot",
		.help = "Soft reboot",
		.handler = cmd_reboot_csp,
	},
};

static const command_t __sub_command msp_csp_subcommands[] = {
	{
		.name = "sensors",
		.help = "Read sensors",
		.handler = cmd_msp_sensors_csp,
	},
};

static const command_t __sub_command sunsensor_csp_subcommands[] = {
	{
		.name = "read",
		.help = "Read sunsensor values",
		.handler = cmd_sunsensor_read_csp,
	},{
		.name = "temp",
		.help = "Read sunsensor temperature",
		.handler = cmd_sunsensor_temp_csp,
	}
};

static const command_t  __sub_command gssb_csp_subcommands[] = {
	{
		.name = "node",
		.help = "Remote CSP node with GSSB",
		.handler = cmd_set_gssb_node,
		.usage = "<node> [timeout (2000)] [port (16)]",
	},{
		.name = "addr",
		.help = "GSSB device address",
		.handler = cmd_set_addr_csp,
		.usage = "<addr> [timeout]",
	},{
		.name = "ident",
		.help = "Get device version and uuid",
		.handler = cmd_gssb_ident_csp,
	},{
		.name = "interstage",
		.help = "Interstage commands",
		.chain = INIT_CHAIN(interstage_csp_subcommands),
	},{
		.name = "ant6",
		.help = "ANT6 commands",
		.chain = INIT_CHAIN(ant6_csp_subcommands),
	},{
        .name = "i4",
        .help = "I4 commands",
        .chain = INIT_CHAIN(i4_csp_subcommands),
    },{
		.name = "ar6",
		.help = "AR6 commands",
		.chain = INIT_CHAIN(ar6_csp_subcommands),
	},{
		.name = "msp",
		.help = "MSP commands",
		.chain = INIT_CHAIN(msp_csp_subcommands),
	},{
		.name = "sunsensor",
		.help = "Sunsensor commands",
		.chain = INIT_CHAIN(sunsensor_csp_subcommands),
	},{
		.name = "model",
		.help = "Get the GSSB model",
		.handler = cmd_gssb_get_model_csp,
	},


};

static const command_t __root_command gssb_csp_commands[] = {
	{
		.name = "rgssb",
		.help = "Sensor Bus client",
		.chain = INIT_CHAIN(gssb_csp_subcommands),
	}
};

gs_error_t gs_rgssb_register_commands(void)
{
    return GS_COMMAND_REGISTER(gssb_csp_commands);
}
