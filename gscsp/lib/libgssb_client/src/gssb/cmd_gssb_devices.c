/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <gs/gssb/gssb_all_devices.h>
#include <gs/gssb/gssb_autodeploy.h>
#include <gs/gssb/gssb_command.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <gs/gosh/command/command.h>
#include <gs/gssb/gssb.h>
#include <gs/util/crc32.h>
#include <gs/util/hexdump.h>
#include <gs/gosh/util/console.h>
#include <gs/util/stdio.h>
#include <gs/util/error.h>
#include <gs/util/thread.h>
#define GS_GSSB_INTERNAL_USE 1
#include <gs/gssb/internal/gssb_common.h>
#include <conf_gssb.h>
#include "local.h"

static uint8_t i2c_addr = 5;
static const uint16_t i2c_timeout_ms = 300;

static int cmd_set_addr(struct command_context *ctx)
{
    if (gs_string_to_uint8(ctx->argv[1], &i2c_addr) != GS_OK) {
        return GS_ERROR_ARG;
    }

    return GS_OK;
}

static int cmd_gssb_bus_scan(struct command_context *ctx)
{
    uint8_t start_addr = 1;
    if ((ctx->argc > 1) && (gs_string_to_uint8(ctx->argv[1], &start_addr) != GS_OK)) {
        return GS_ERROR_ARG;
    }
    uint8_t stop_addr = 126;
    if ((ctx->argc > 2) && (gs_string_to_uint8(ctx->argv[2], &stop_addr) != GS_OK)) {
        return GS_ERROR_ARG;
    }
    if (start_addr > stop_addr) {
        return GS_ERROR_RANGE;
    }

    int8_t devices[stop_addr + 1];
    gs_gssb_bus_scan(start_addr, stop_addr, i2c_timeout_ms, devices);
    for (uint8_t addr = start_addr; addr <= stop_addr; addr++) {
        if (devices[addr] == 0) {
            printf("Found device at: %d\r\n", addr);
        }
    }

    return GS_OK;
}

static int cmd_read_sunsensor(struct command_context *ctx)
{
    uint16_t sun[4];
    int i;

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    /* Start sampling */
    if (gs_gssb_sun_sample_sensor(i2c_addr, i2c_timeout_ms) != GS_OK)
        return CMD_ERROR_FAIL;

    /* Wait for result to be ready */
    gs_thread_sleep_ms(30);
    if (gs_gssb_sun_read_sensor_samples(i2c_addr, i2c_timeout_ms, sun) != GS_OK)
        return CMD_ERROR_FAIL;

    printf("\r\n ---- Values ----\r\n");
    for (i = 0; i < 4; i++) {
        printf("Data %d: %d\r\n", i, sun[i]);
    }

    return CMD_ERROR_NONE;
}

static int cmd_get_temp(struct command_context *ctx)
{
    float temp;

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    /* Command ADC to sample temp */
    if (gs_gssb_sun_sample_temp(i2c_addr, i2c_timeout_ms) != GS_OK)
        return CMD_ERROR_FAIL;

    /* Wait for conversion to finish and then read result */
    gs_thread_sleep_ms(20);
    if (gs_gssb_sun_get_temp(i2c_addr, i2c_timeout_ms, &temp) != GS_OK)
        return CMD_ERROR_FAIL;

    printf("Temp: %f\r\n", temp);

    return CMD_ERROR_NONE;
}

static int cmd_sunsensor_conf(struct command_context *ctx)
{
    uint16_t conf;

    if (ctx->argc != 2)
        return CMD_ERROR_SYNTAX;

    conf = atoi(ctx->argv[1]);

    if (gs_gssb_sun_sensor_conf(i2c_addr, i2c_timeout_ms, conf) != GS_OK)
        return CMD_ERROR_FAIL;

    return CMD_ERROR_NONE;
}

static int cmd_sunsensor_conf_save(struct command_context *ctx)
{

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_sun_sensor_conf_save(i2c_addr, i2c_timeout_ms) != GS_OK)
        return CMD_ERROR_FAIL;

    return CMD_ERROR_NONE;
}

static int cmd_gssb_set_i2c_addr(struct command_context *ctx)
{
    uint8_t new_i2c_addr;
    uint32_t uuid;

    if (ctx->argc != 2)
        return CMD_ERROR_SYNTAX;

    new_i2c_addr = atoi(ctx->argv[1]);

    gs_gssb_set_i2c_addr(i2c_addr, i2c_timeout_ms, new_i2c_addr);

    if (gs_gssb_get_uuid(new_i2c_addr, i2c_timeout_ms, &uuid) != GS_OK) {
        return CMD_ERROR_FAIL;
    }
    printf("Changed address from %hhu to %hhu\n\ron dev: %" PRIu32 "\n\n\rWorking address is %hhu\n\r", i2c_addr,
           new_i2c_addr, uuid, new_i2c_addr);
    i2c_addr = new_i2c_addr;

    return CMD_ERROR_NONE;
}

static int cmd_gssb_commit_i2c_addr(struct command_context *ctx)
{

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_commit_i2c_addr(i2c_addr, i2c_timeout_ms) != GS_OK)
        return CMD_ERROR_FAIL;

    return CMD_ERROR_NONE;
}

static int cmd_gssb_get_version(struct command_context *ctx)
{
    uint8_t rx_buff[20];

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_get_version(i2c_addr, i2c_timeout_ms, rx_buff, 20) != GS_OK)
        return CMD_ERROR_FAIL;

    rx_buff[19] = '\0';
    printf("Git version: %s\r\n", (char *) rx_buff);

    return CMD_ERROR_NONE;
}

static int cmd_gssb_get_uuid(struct command_context *ctx)
{
    uint32_t uuid;

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_get_uuid(i2c_addr, i2c_timeout_ms, &uuid) != GS_OK)
        return CMD_ERROR_FAIL;
    printf("Device UUID: %"PRIu32"\r\n", uuid);

    return CMD_ERROR_NONE;
}

static int cmd_get_model(struct command_context *ctx)
{
    gs_gssb_model_t model;

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_get_model(i2c_addr, i2c_timeout_ms, &model) != GS_OK)
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
        case GS_GSSB_MODEL_I4:
            printf("I4\n\r");
            break;
        default:
            printf("Unknown\r\n");
    }
    return CMD_ERROR_NONE;
}

#if GS_ISTAGE_ENABLED
static int cmd_interstage_temp(struct command_context *ctx)
{
    float temp;

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_istage_get_temp(i2c_addr, i2c_timeout_ms, &temp) != GS_OK)
        return CMD_ERROR_FAIL;

    printf("Temp: %f\r\n", temp);

    return CMD_ERROR_NONE;
}
#endif

#if GS_MSP_ENABLED
static int cmd_msp_outside_temp(struct command_context *ctx)
{
    int16_t temp;

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_msp_get_outside_temp(i2c_addr, i2c_timeout_ms, &temp) != GS_OK)
        return CMD_ERROR_FAIL;

    printf("Outside temp: %i\r\n", temp);

    return CMD_ERROR_NONE;
}
#endif

#if GS_MSP_ENABLED
static int cmd_msp_outside_temp_calibrate(struct command_context *ctx)
{
    uint16_t current, resistor;
    if (ctx->argc != 3)
        return CMD_ERROR_SYNTAX;
    /* Check range */
    int tmp;
    tmp = atoi(ctx->argv[1]);
    if ((tmp > 400000) || (tmp < 100000)) {
        gs_color_printf(GS_COLOR_RED, "Current of %d out of range [100000 - 400000]\r\n", tmp);
        return CMD_ERROR_SYNTAX;
    } else {
        /* Current is typed in nano Ampere but send in 10⁻⁸ Ampere to fit in 16 bit*/
        current = (uint16_t) (tmp / 10);
    }

    tmp = atoi(ctx->argv[2]);
    if ((tmp > 200000) || (tmp < 50000)) {
        gs_color_printf(GS_COLOR_RED, "Resistance of %d out of range [50000 - 200000]\r\n", tmp);
        return CMD_ERROR_SYNTAX;
    } else {
        /* Resistance is typed in mili Ohm but send in centi Ohm to fit in 16 bit */
        resistor = (uint16_t) (tmp / 10);
    }

    if (gs_gssb_msp_calibrate_outside_temp(i2c_addr, i2c_timeout_ms, current, resistor) != GS_OK)
        return CMD_ERROR_FAIL;

    return CMD_ERROR_NONE;
}
#endif

#if GS_ISTAGE_ENABLED | GS_MSP_ENABLED | GS_AR6_ENABLED | GS_ANT6_ENABLED | GS_I4_ENABLED
static int cmd_internal_temp(struct command_context *ctx)
{
    int16_t temp;

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_common_get_internal_temp(i2c_addr, i2c_timeout_ms, &temp) != GS_OK)
        return CMD_ERROR_FAIL;

    printf("Internal temp: %i\r\n", temp);

    return CMD_ERROR_NONE;
}
#endif

#if GS_ISTAGE_ENABLED
static int cmd_interstage_burn(struct command_context *ctx)
{

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_istage_burn(i2c_addr, i2c_timeout_ms) != GS_OK)
        return CMD_ERROR_FAIL;

    return CMD_ERROR_NONE;
}
#endif

#if GS_ISTAGE_ENABLED | GS_MSP_ENABLED
static int cmd_common_sun_voltage(struct command_context *ctx)
{
    uint16_t voltage;

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_common_get_sun_voltage(i2c_addr, i2c_timeout_ms, &voltage) != GS_OK)
        return CMD_ERROR_FAIL;

    printf("Data: %i\r\n", voltage);

    return CMD_ERROR_NONE;
}
#endif

#if GS_ISTAGE_ENABLED
static int cmd_interstage_burn_settings(struct command_context *ctx)
{
    gs_gssb_istage_burn_settings_t settings;

    /* We the command is called with out arguments then print the settings */
    if (ctx->argc == 1) {

        if (gs_gssb_istage_get_burn_settings(i2c_addr, i2c_timeout_ms, &settings) != GS_OK)
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
        /* First fetch settings and check that the interstage is unlocked and if it
         * is not then print warning about the settings cannot be changed */

        /* Check settings range */
        int tmp;
        tmp = atoi(ctx->argv[1]);
        if ((tmp > 65535) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Knife on time of %d out of range [0 - 65535]\r\n", tmp);
            return CMD_ERROR_SYNTAX;
        } else {
            settings.std_time_ms = (uint16_t) tmp;
        }

        tmp = atoi(ctx->argv[2]);
        if ((tmp > 65535) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Increment of %d out of range [0 - 65535]\r\n", tmp);
            return CMD_ERROR_SYNTAX;
        } else {
            settings.increment_ms = (uint16_t) tmp;
        }

        tmp = atoi(ctx->argv[3]);
        if ((tmp > 65535) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Auto deploy delay of %d out of range [0 - 65535]\r\n", tmp);
            return CMD_ERROR_SYNTAX;
        } else {
            settings.short_cnt_down = (uint16_t) tmp;
        }

        tmp = atoi(ctx->argv[4]);
        if ((tmp > 255) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Max repeats of %d out of range [0 - 255]\r\n", tmp);
            return CMD_ERROR_SYNTAX;
        } else {
            settings.max_repeat = (uint8_t) tmp;
        }

        tmp = atoi(ctx->argv[5]);
        if ((tmp > 255) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Time between repeats of %d out of range [0 - 255]\r\n", tmp);
            return CMD_ERROR_SYNTAX;
        } else {
            settings.rep_time_s = (uint8_t) tmp;
        }

        tmp = atoi(ctx->argv[6]);
        if ((tmp > 1) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Polarity can only be selected to 0 or 1 not %d\r\n", tmp);
            return CMD_ERROR_SYNTAX;
        } else {
            settings.switch_polarity = (uint8_t) tmp;
        }

        tmp = atoi(ctx->argv[7]);
        if ((tmp > 255) || (tmp < 0)) {
            gs_color_printf(GS_COLOR_RED, "Reboot deploy number of %d out of range [0 - 255]\r\n", tmp);
            return CMD_ERROR_SYNTAX;
        } else {
            settings.reboot_deploy_cnt = (uint8_t) tmp;
        }

        if (gs_gssb_istage_settings_unlock(i2c_addr, i2c_timeout_ms) != GS_OK)
            return CMD_ERROR_FAIL;

        if (gs_gssb_istage_set_burn_settings(i2c_addr, i2c_timeout_ms, &settings) != GS_OK)
            return CMD_ERROR_FAIL;

        /* We need to have a delay as we write the settings to EEPROM which takes some time */
        gs_thread_sleep_ms(50);

        if (gs_gssb_istage_set_burn_settings_cnt(i2c_addr, i2c_timeout_ms, &settings) != GS_OK)
            return CMD_ERROR_FAIL;

        /* We need to have a delay as we write the settings to EEPROM which takes some time */
        gs_thread_sleep_ms(20);

        if (gs_gssb_istage_settings_lock(i2c_addr, i2c_timeout_ms) != GS_OK) {
            printf("\r\n Warning could not lock settings after they was unlocked\r\n");
            return CMD_ERROR_FAIL;
        }

        gs_gssb_soft_reset(i2c_addr, i2c_timeout_ms);
    } else {
        return CMD_ERROR_SYNTAX;
    }

    return CMD_ERROR_NONE;
}
#endif

#if GS_ISTAGE_ENABLED
static int cmd_interstage_arm(struct command_context *ctx)
{
    uint8_t data = 0;

    if (ctx->argc != 2)
        return CMD_ERROR_SYNTAX;

    if (atoi(ctx->argv[1])) {
        data |= 0x04;
    } else {
        data |= 0x08;
    }

    if (gs_gssb_istage_settings_unlock(i2c_addr, i2c_timeout_ms) != GS_OK)
        return CMD_ERROR_FAIL;

    if (gs_gssb_istage_set_arm(i2c_addr, i2c_timeout_ms, data) != GS_OK)
        return CMD_ERROR_FAIL;

    if (gs_gssb_istage_settings_lock(i2c_addr, i2c_timeout_ms) != GS_OK) {
        printf("\r\n Warning could not lock settings after they was unlocked\r\n");
        return CMD_ERROR_FAIL;
    }

    return CMD_ERROR_NONE;
}
#endif

#if GS_ISTAGE_ENABLED
static int cmd_interstage_state(struct command_context *ctx)
{
    uint8_t data = 0;

    if (ctx->argc != 2)
        return CMD_ERROR_SYNTAX;

    data = atoi(ctx->argv[1]);

    if (gs_gssb_istage_settings_unlock(i2c_addr, i2c_timeout_ms) != GS_OK)
        return CMD_ERROR_FAIL;

    if (gs_gssb_istage_set_state(i2c_addr, i2c_timeout_ms, data) != GS_OK)
        return CMD_ERROR_FAIL;

    if (gs_gssb_istage_settings_lock(i2c_addr, i2c_timeout_ms) != GS_OK) {
        printf("\r\n Warning could not lock settings after they was unlocked\r\n");
        return CMD_ERROR_FAIL;
    }

    return CMD_ERROR_NONE;
}
#endif

#if UNUSED_FUNCTION
static int cmd_interstage_settings_unlock(struct command_context *ctx)
{

    if (ctx->argc > 2)
        return CMD_ERROR_SYNTAX;

    if (ctx->argc == 1) {
        if (gs_gssb_istage_settings_unlock(i2c_addr, i2c_timeout_ms) != GS_OK)
            return CMD_ERROR_FAIL;
    } else {
        if (gs_gssb_istage_settings_lock(i2c_addr, i2c_timeout_ms) != GS_OK)
            return CMD_ERROR_FAIL;
    }

    return CMD_ERROR_NONE;
}
#endif

#if GS_ISTAGE_ENABLED | GS_AR6_ENABLED | GS_ANT6_ENABLED | GS_I4_ENABLED
static int cmd_soft_reset(struct command_context *ctx)
{

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_soft_reset(i2c_addr, i2c_timeout_ms) != GS_OK)
        return CMD_ERROR_FAIL;

    return CMD_ERROR_NONE;
}
#endif

#if GS_ISTAGE_ENABLED
static int cmd_interstage_get_status(struct command_context *ctx)
{
    gs_gssb_istage_status_t status;
    const char *state_str;

    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_istage_status(i2c_addr, i2c_timeout_ms, &status) != GS_OK)
        return CMD_ERROR_FAIL;

    switch (status.state) {
        case 0:
            state_str = "Not armed";
            break;
        case 1:
            state_str = "Armed for manual deploy";
            break;
        case 2:
            state_str = "Armed for automatical deploy";
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
#endif

#if GS_AR6_ENABLED
static int cmd_ar6_burn(struct command_context *ctx)
{
    uint8_t duration;
    if (ctx->argc != 2)
        return CMD_ERROR_SYNTAX;
    int tmp;
    tmp = atoi(ctx->argv[1]);
    if ((tmp > 20) || (tmp < 0)) {
        gs_color_printf(GS_COLOR_RED, "Duration out of range [0 - 20]\r\n");
        return CMD_ERROR_SYNTAX;
    } else {
        duration = tmp;
    }

    if (gs_gssb_ar6_burn(i2c_addr, i2c_timeout_ms, duration) != GS_OK)
        return CMD_ERROR_FAIL;
    else
        return CMD_ERROR_NONE;
}
#endif

#if GS_AR6_ENABLED
static int cmd_ar6_get_status(struct command_context *ctx)
{
    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    gs_gssb_ar6_status_t status;

    if (gs_gssb_ar6_get_release_status(i2c_addr, i2c_timeout_ms, &status.release) != GS_OK)
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
        gs_color_printf(GS_COLOR_RED, "\tAntenna state:\t\t\t\t %s\r\n", "Not released");

    printf("\tBurn attempts:\t\t\t\t %hhu\r\n", status.release.burn_tries);

    if (gs_gssb_ant6_get_backup_status(i2c_addr, i2c_timeout_ms, &status.backup) != GS_OK)
        return CMD_ERROR_FAIL;

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

    if (gs_gssb_ar6_get_board_status(i2c_addr, i2c_timeout_ms, &status.board) != GS_OK)
        return CMD_ERROR_FAIL;

    printf("Board\n\r");
    printf("\tSeconds since boot:\t\t\t %"PRIu32"\r\n", status.board.seconds_since_boot);
    printf("\tNumber of reboots:\t\t\t %hhu\r\n", status.board.reboot_count);

    return CMD_ERROR_NONE;
}
#endif

#if GS_ANT6_ENABLED | GS_I4_ENABLED
static int cmd_common_burn_channel(struct command_context *ctx)
{
    uint8_t channel, duration;
    if (ctx->argc != 3)
        return CMD_ERROR_SYNTAX;
    int tmp;
    tmp = atoi(ctx->argv[1]);
    if ((tmp > 10) || (tmp < 0)) {
        gs_color_printf(GS_COLOR_RED, "Channels out of range [0 - 10]\r\n");
        return CMD_ERROR_SYNTAX;
    } else {
        channel = tmp;
    }
    tmp = atoi(ctx->argv[2]);
    if ((tmp > 60) || (tmp < 0)) {
        gs_color_printf(GS_COLOR_RED, "Duration out of range [0 - 60]\r\n");
        return CMD_ERROR_SYNTAX;
    } else {
        duration = tmp;
    }

    if (gs_gssb_common_burn_channel(i2c_addr, i2c_timeout_ms, channel, duration) != GS_OK)
        return CMD_ERROR_FAIL;
    else
        return CMD_ERROR_NONE;
}
#endif

#if GS_ANT6_ENABLED | GS_AR6_ENABLED | GS_I4_ENABLED
static int cmd_common_stop_burn(struct command_context *ctx)
{
    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_common_stop_burn(i2c_addr, i2c_timeout_ms) != GS_OK)
        return CMD_ERROR_FAIL;
    else
        return CMD_ERROR_NONE;
}
#endif

#if GS_ANT6_ENABLED
static int cmd_ant6_get_status_all_channels(struct command_context *ctx)
{
    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    gs_gssb_ant6_status_t status;

    if (gs_gssb_ant6_get_release_status(i2c_addr, i2c_timeout_ms, &status.release) != GS_OK)
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
        gs_color_printf(GS_COLOR_RED, "\tAntenna state:\t\t\t\t %s\r\n", "Not released");

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
        gs_color_printf(GS_COLOR_RED, "\tAntenna state:\t\t\t\t %s\r\n", "Not released");

    printf("\tBurn attempts:\t\t\t\t %hhu\r\n", status.release.channel_1_burn_tries);

    if (gs_gssb_ant6_get_backup_status(i2c_addr, i2c_timeout_ms, &status.backup) != GS_OK)
        return CMD_ERROR_FAIL;

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

    if (gs_gssb_ant6_get_board_status(i2c_addr, i2c_timeout_ms, &status.board) != GS_OK)
        return CMD_ERROR_FAIL;

    printf("Board\n\r");
    printf("\tSeconds since boot:\t\t\t %"PRIu32"\r\n", status.board.seconds_since_boot);
    printf("\tNumber of reboots:\t\t\t %hhu\r\n", status.board.reboot_count);

    return CMD_ERROR_NONE;
}
#endif

#if GS_I4_ENABLED
static int cmd_i4_get_status_all_channels(struct command_context *ctx)
{
    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    gs_gssb_i4_status_t status;

    if (gs_gssb_i4_get_release_status(i2c_addr, i2c_timeout_ms, &status.release) != GS_OK)
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

    if (gs_gssb_i4_get_backup_status(i2c_addr, i2c_timeout_ms, &status.backup) != GS_OK)
        return CMD_ERROR_FAIL;

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

    if (gs_gssb_i4_get_board_status(i2c_addr, i2c_timeout_ms, &status.board) != GS_OK)
        return CMD_ERROR_FAIL;

    printf("Board\n\r");
    printf("\tSeconds since boot:\t\t\t %"PRIu32"\r\n", status.board.seconds_since_boot);
    printf("\tNumber of reboots:\t\t\t %hhu\r\n", status.board.reboot_count);

    return CMD_ERROR_NONE;
}
#endif

#if GS_ANT6_ENABLED | GS_AR6_ENABLED | GS_I4_ENABLED
static int cmd_common_reset_count(struct command_context *ctx)
{
    if (ctx->argc != 1)
        return CMD_ERROR_SYNTAX;

    if (gs_gssb_common_reset_count(i2c_addr, i2c_timeout_ms) != GS_OK)
        return CMD_ERROR_FAIL;
    else
        return CMD_ERROR_NONE;
}
#endif

#if GS_ANT6_ENABLED | GS_AR6_ENABLED | GS_I4_ENABLED
static int cmd_common_backup_settings(struct command_context *ctx)
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

        if (gs_gssb_common_set_backup_settings(i2c_addr, i2c_timeout_ms, settings) != GS_OK)
            return CMD_ERROR_FAIL;
    } else {
        if (gs_gssb_common_get_backup_settings(i2c_addr, i2c_timeout_ms, &settings) != GS_OK)
            return CMD_ERROR_FAIL;
    }
    printf("Backup deploy settings:\n\r\tMinutes until deploy:\t\t\t %hi\n\r\tBackup deployment:\t\t\t ",
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
#endif

#if GS_SUNSENSOR_ENABLED
static const command_t __sub_command sunsensor_subcommands[] = {
    {
        .name = "sunread",
        .help = "Sunsensor read value",
        .handler = cmd_read_sunsensor,
    },{
        .name = "readtemp",
        .help = "Get ADC temp",
        .handler = cmd_get_temp,
    },{
        .name = "conf",
        .help = "Set sunsensor ADC configuration",
        .handler = cmd_sunsensor_conf,
        .usage = "<conf value>",
    },{
        .name = "conf_save",
        .help = "Save sunsensor ADC configuration",
        .handler = cmd_sunsensor_conf_save,
    },
};
#endif

#if GS_ISTAGE_ENABLED
static const command_t __sub_command interstage_sensor_subcommands[] = {
    {
        .name = "temp",
        .help = "Get panel temperature inside",
        .handler = cmd_interstage_temp,
    },{
        .name = "temp_internal",
        .help = "Get temperature in MCU",
        .handler = cmd_internal_temp,
    },{
        .name = "sunvoltage",
        .help = "Get sunsensor voltage",
        .handler = cmd_common_sun_voltage,
    },

};
#endif

#if GS_ISTAGE_ENABLED
static const command_t __sub_command interstage_subcommands[] = {
    {
        .name = "sensors",
        .help = "Read sensors",
        .chain = INIT_CHAIN(interstage_sensor_subcommands),
    },{
        .name = "conf",
        .help = "Set or get configuration. To get give no arguments",
        .handler = cmd_interstage_burn_settings,
        .usage = "<knife ON [ms]> <increment [ms]> <auto deploy delay [s]> <max repeat [#]> <repeat time [s]> <switch polarity> <deploy boot cnt>",
    },{
        .name = "arm",
        .help = "Interstage arm",
        .handler = cmd_interstage_arm,
        .usage = "<1 = arm, 0 = disarm>",
    },{
        .name = "deploy",
        .help = "Manual trigger deploy",
        .handler = cmd_interstage_burn,
    },{
        .name = "state",
        .help = "Set current state",
        .handler = cmd_interstage_state,
        .usage = "<State 0=NOT ARMED, 1=ARMED MANUAL>",
    },{
        .name = "status",
        .help = "Interstage status",
        .handler = cmd_interstage_get_status,
    },{
        .name = "reboot",
        .help = "Soft reboot of interstage",
        .handler = cmd_soft_reset,
    },

};
#endif

#if GS_ANT6_ENABLED
static const command_t __sub_command ant6_subcommands[] = {
    {
        .name = "burn",
        .help = "Burn on specific channel for specific duration",
        .handler = cmd_common_burn_channel,
        .usage = "<channel> <duration [s]>",
    },{
        .name = "stop",
        .help = "Stop burn on all channels",
        .handler = cmd_common_stop_burn,
    },{
        .name = "status",
        .help = "status from all channels",
        .handler = cmd_ant6_get_status_all_channels,
    },{
        .name = "reset_count",
        .help = "Resets counters",
        .handler = cmd_common_reset_count,
    },{
        .name = "settings",
        .help = "Set or get backup deploy settings",
        .usage = "<delay_until_deploy [min]> <backup_active> <max_burn_duration>",
        .handler = cmd_common_backup_settings,
    },{
        .name = "reboot",
        .help = "Soft reboot of interstage",
        .handler = cmd_soft_reset,
    },{
        .name = "temp_internal",
        .help = "Get temperature in MCU",
        .handler = cmd_internal_temp,
    },
};
#endif

#if GS_I4_ENABLED
static const command_t __sub_command i4_subcommands[] = {
    {
        .name = "burn",
        .help = "Burn on specific channel for specific duration",
        .handler = cmd_common_burn_channel,
        .usage = "<channel> <duration [s]>",
    },{
        .name = "stop",
        .help = "Stop burn on all channels",
        .handler = cmd_common_stop_burn,
    },{
        .name = "status",
        .help = "status from all channels",
        .handler = cmd_i4_get_status_all_channels,
    },{
        .name = "reset_count",
        .help = "Resets counters",
        .handler = cmd_common_reset_count,
    },{
        .name = "settings",
        .help = "Set or get backup deploy settings",
        .usage = "<delay_until_deploy [min]> <backup_active> <max_burn_duration>",
        .handler = cmd_common_backup_settings,
    },{
        .name = "reboot",
        .help = "Soft reboot of interstage",
        .handler = cmd_soft_reset,
    },{
        .name = "temp_internal",
        .help = "Get temperature in MCU",
        .handler = cmd_internal_temp,
    }
};
#endif

#if GS_AR6_ENABLED
static const command_t __sub_command ar6_subcommands[] = {
    {
        .name = "burn",
        .help = "Burn for specific duration",
        .handler = cmd_ar6_burn,
        .usage = "<duration [s]>",
    },{
        .name = "stop",
        .help = "Stop burn",
        .handler = cmd_common_stop_burn,
    },{
        .name = "status",
        .help = "status",
        .handler = cmd_ar6_get_status,
    },{
        .name = "reset_count",
        .help = "Resets counters",
        .handler = cmd_common_reset_count,
    },{
        .name = "settings",
        .help = "Set or get backup deploy settings",
        .usage = "<delay_until_deploy [min]> <backup_active> <max_burn_duration>",
        .handler = cmd_common_backup_settings,
    },{
        .name = "reboot",
        .help = "Soft reboot of interstage",
        .handler = cmd_soft_reset,
    },{
        .name = "temp_internal",
        .help = "Get temperature in MCU",
        .handler = cmd_internal_temp,
    },
};
#endif

#if GS_MSP_ENABLED
static const command_t __sub_command msp_subcommands[] = {
    {
        .name = "temp_outside_calibrate",
        .help = "Get panel temperature outside",
        .handler = cmd_msp_outside_temp_calibrate,
        .usage = "<current [nA]> <resistance [mOhm]>",
        .mode = CMD_HIDDEN,
    },{
        .name = "temp_outside",
        .help = "Get panel temperature outside",
        .handler = cmd_msp_outside_temp,
    },{
        .name = "temp_internal",
        .help = "Get temperature in MCU",
        .handler = cmd_internal_temp,
    },{
        .name = "sunvoltage",
        .help = "Get sunsensor voltage",
        .handler = cmd_common_sun_voltage,
    },

};
#endif

static const command_t  __sub_command gssb_subcommands[] = {
    {
        .name = "addr",
        .help = "GSSB set device addr",
        .handler = cmd_set_addr,
        .usage = "<addr>",
        .mandatory_args = 1,
    },{
        .name = "setaddr",
        .help = "Set device I2C addr",
        .handler = cmd_gssb_set_i2c_addr,
        .usage = "<addr>",
    },{
        .name = "commitaddr",
        .help = "Commit device I2C addr to NVM",
        .handler = cmd_gssb_commit_i2c_addr,
    },{
        .name = "get_version",
        .help = "Get software version",
        .handler = cmd_gssb_get_version,
    },{
        .name = "get_uuid",
        .help = "Get device uuid",
        .handler = cmd_gssb_get_uuid,
    },{
        .name = "scanbus",
        .help = "Scan bus for devices",
        .handler = cmd_gssb_bus_scan,
        .optional_args = 2, // only for debug -> no usage
    },
#if GS_SUNSENSOR_ENABLED
    {
        .name = "sunsensor",
        .help = "Sunsensor commands",
        .chain = INIT_CHAIN(sunsensor_subcommands),
    },
#endif
#if GS_ISTAGE_ENABLED
    {
        .name = "interstage",
        .help = "Interstage commands",
        .chain = INIT_CHAIN(interstage_subcommands),
    },
#endif
#if GS_MSP_ENABLED
    {
        .name = "msp",
        .help = "MSP commands",
        .chain = INIT_CHAIN(msp_subcommands),
    },
#endif
#if GS_AR6_ENABLED
    {
        .name = "ar6",
        .help = "AR6 commands",
        .chain = INIT_CHAIN(ar6_subcommands),
    },
#endif
#if GS_ANT6_ENABLED
    {
        .name = "ant6",
        .help = "ANT6 commands",
        .chain = INIT_CHAIN(ant6_subcommands),
    },
#endif
#if GS_I4_ENABLED
    {
        .name = "i4",
        .help = "I4 commands",
        .chain = INIT_CHAIN(i4_subcommands),
    },
#endif
    {
        .name = "model",
        .help = "Get the GSSB model",
        .handler = cmd_get_model,
    }
};


static const command_t __root_command gssb_commands[] = {
    {
        .name = "gssb",
        .help = "Sensor Bus (local)",
        .chain = INIT_CHAIN(gssb_subcommands),
    }
};

gs_error_t gs_gssb_register_commands(void)
{
    return GS_COMMAND_REGISTER(gssb_commands);
}
