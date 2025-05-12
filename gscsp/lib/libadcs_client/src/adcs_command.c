/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include "../include/gs/adcs/adcs_command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <util/console.h>
#include <util/timestamp.h>
#include <util/error.h>
#include <util/log.h>

#include <gs/adcs/adcs_types.h>
#include <gs/adcs/adcs_client.h>
#include <gs/adcs/adcs_client_periph.h>
#include <gs/adcs/adcs_client_gps.h>
#include <gs/adcs/adcs_param_types.h>
#include <gs/adcs/adcs_param.h>



#define ADCS_CSPERR "An error occured communicating with the satellite\r\n"


int cmd_adcs_node_set(struct command_context *ctx) {
	if (ctx->argc != 3)
		return CMD_ERROR_SYNTAX;
	int node = atoi(ctx->argv[1]);
	int port = atoi(ctx->argv[2]);
	adcs_node_set(node, port);
	return CMD_ERROR_NONE;
}


/**********************************************************************/
// Log commands 
/**********************************************************************/

int cmd_adcs_hk_basic(struct command_context *ctx) {
    adcs_hk_basic_t hk_basic;
    if (adcs_hk_basic(&hk_basic) <= 0)
        return CMD_ERROR_FAIL;

    printf("Julian date: %.8f, Eclipse %d\r\n", hk_basic.jdate,
            hk_basic.eclipse);
    printf("Q   %.3f %.3f %.3f %.3f\r\n", hk_basic.q[0], hk_basic.q[1],
            hk_basic.q[2], hk_basic.q[3]);
    printf("W   %.3f %.3f %.3f\r\n", hk_basic.w[0], hk_basic.w[1],
            hk_basic.w[2]);
    printf("Pos %.3f %.3f %.3f\r\n", hk_basic.pos[0], hk_basic.pos[1],
            hk_basic.pos[2]);

    return CMD_ERROR_NONE;
}

/**********************************************************************/
// General commands 
/**********************************************************************/
int cmd_adcs_restart(struct command_context *ctx) {
    if (adcs_restart() <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

int cmd_adcs_start(struct command_context *ctx) {
    if (adcs_start() <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

int cmd_adcs_sensors(struct command_context *ctx) {
    if (adcs_sensors() <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

int cmd_adcs_stop(struct command_context *ctx) {
    if (adcs_stop() <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

int cmd_adcs_get_adcs_state(struct command_context *ctx) {
    adcs_mode_t state;
    int retval;

    retval = adcs_get_adcs_state(&state);

    if (retval > 0) {

        printf("Current Ephem state is ");

        switch (state.ephem_mode) {
        case EPHEM_IDLE:
            printf("%d: IDLE\n\r", state.ephem_mode);
            break;
        case EPHEM_TLE:
            printf("%d: TLE\n\r", state.ephem_mode);
            break;
        case EPHEM_GPS:
            printf("%d: GPS\n\r", state.ephem_mode);
            break;
        default:
            printf("Unknown mode %d\n\r", state.ephem_mode);
        }

        printf("Desired Ephem state is ");
        switch (state.desired_ephem_mode) {
        case EPHEM_IDLE:
            printf("%d: IDLE\n\r", state.desired_ephem_mode);
            break;
        case EPHEM_TLE:
            printf("%d: TLE\n\r", state.desired_ephem_mode);
            break;
        case EPHEM_GPS:
            printf("%d: GPS\n\r", state.desired_ephem_mode);
            break;
        default:
            printf("Unknown mode %d\n\r", state.desired_ephem_mode);
        }

        printf("Current ADS state is   ");

        switch (state.ads_mode) {
        case ADS_IDLE:
            printf("%d: IDLE\n\r", state.ads_mode);
            break;
        case ADS_SENSORS:
            printf("%d: SENSORS!\n\r", state.ads_mode);
            break;
        case ADS_KALMANFILTER:
            printf("%d: KALMANFILTER\n\r", state.ads_mode);
            break;
        default:
            printf("Unknown mode %d\n\r", state.ads_mode);

        }
        printf("Desired ADS state is   ");
        switch (state.desired_ads_mode) {
        case ADS_IDLE:
            printf("%d: IDLE\n\r", state.desired_ads_mode);
            break;
        case ADS_SENSORS:
            printf("%d: SENSORS!\n\r", state.desired_ads_mode);
            break;
        case ADS_KALMANFILTER:
            printf("%d: KALMANFILTER\n\r", state.desired_ads_mode);
            break;
        default:
            printf("Unknown mode %d\n\r", state.desired_ads_mode);
        }
        printf("Current ACS state is   ");
        switch (state.acs_mode) {
        case ACS_IDLE:
            printf("%d: IDLE\n\r", state.acs_mode);
            break;
        case ACS_CONST:
            printf("%d: CONST\n\r", state.acs_mode);
            break;
        case ACS_BDOT:
            printf("%d: BDOT\n\r", state.acs_mode);
            break;
        case ACS_SPIN:
            printf("%d: SPIN\n\r", state.acs_mode);
            break;
        case ACS_WHEELS:
            printf("%d: MW_SMC\n\r", state.acs_mode);
            break;
        case ACS_ACTUATOR:
            printf("%d: ACTUATOR\n\r", state.acs_mode);
            break;
        case ACS_ORBITPOINTING:
            printf("%d: ORBIT_POINT\n\r", state.acs_mode);
            break;
        case ACS_SUNPOINTING:
            printf("%d: SUN_POINT\n\r", state.acs_mode);
            break;
        default:
            printf("Unknown mode %d\n\r", state.acs_mode);
        }
        printf("Desired ACS state is   ");
        switch (state.desired_acs_mode) {
        case ACS_IDLE:
            printf("%d: IDLE\n\r", state.desired_acs_mode);
            break;
        case ACS_CONST:
            printf("%d: CONST\n\r", state.desired_acs_mode);
            break;
        case ACS_BDOT:
            printf("%d: BDOT\n\r", state.desired_acs_mode);
            break;
        case ACS_SPIN:
            printf("%d: SPIN\n\r", state.desired_acs_mode);
            break;
        case ACS_WHEELS:
            printf("%d: MW_SMC\n\r", state.desired_acs_mode);
            break;
        case ACS_ACTUATOR:
            printf("%d: ACTUATOR\n\r", state.desired_acs_mode);
            break;
        case ACS_ORBITPOINTING:
            printf("%d: ORBIT_POINT\n\r", state.desired_acs_mode);
            break;
        case ACS_SUNPOINTING:
            printf("%d: SUN_POINT\n\r", state.desired_acs_mode);
            break;
        default:
            printf("Unknown mode %d\n\r", state.desired_acs_mode);
        }
    } else {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_ads_state(struct command_context *ctx) {
    const char * args = command_args(ctx);
    int state;
    if (args == NULL) {
        printf("usage: setads <state> : 0=IDLE, 3=KF\r\n");
        return CMD_ERROR_FAIL;
    }
    state = atoi(ctx->argv[1]);
    if (state < 0) {
        printf("Invalid state<r\n");
        return CMD_ERROR_FAIL;
    }

    printf("Setting ads state to %d\r\n", state);
    adcs_set_ads_state(state);
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_ephem_state(struct command_context *ctx) {
    const char * args = command_args(ctx);
    int state;
    if (args == NULL) {
        printf("usage: setephem <state> : 0=IDLE, 1=TLE, 2=GPS\r\n");
        return CMD_ERROR_FAIL;
    }
    state = atoi(ctx->argv[1]);
    if (state < 0) {
        printf("Invalid state<r\n");
        return CMD_ERROR_FAIL;
    }

    printf("Setting ephem state to %d\r\n", state);
    adcs_set_ephem_state(state);
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_acs_state(struct command_context *ctx) {
    const char * args = command_args(ctx);
    int state;

    if (args == NULL) {
        printf("usage: setacs <state> : 0=IDLE, 1=CONST, 2=BDOT, 3=NADIR, 4=INERTIAL\r\n");
        return CMD_ERROR_FAIL;
    }
    state = atoi(ctx->argv[1]);
    if (state < 0) {
        printf("Invalid state<r\n");
        return CMD_ERROR_FAIL;
    }
    printf("Setting acs state to %d\r\n", state);
    adcs_set_acs_state(state);
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_ads_state_kalman(struct command_context *ctx) {
    ads_mode_t state = ADS_KALMANFILTER;
    adcs_set_ads_state(state);
    return CMD_ERROR_NONE;
}

/**********************************************************************/
// BDOT commands 
/**********************************************************************/

int cmd_adcs_bdot_force_detumbled(struct command_context *ctx) {
    if (adcs_bdot_force_detumbled() <= 0) {
        return CMD_ERROR_FAIL;
    }
    log_info("BDOT CMD Received");
    return CMD_ERROR_NONE;
}

/**********************************************************************/
// Pointing commands
/**********************************************************************/

int cmd_adcs_set_reset(struct command_context *ctx) {
    if (!adcs_set_reset()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_nadir(struct command_context *ctx) {
    if (!adcs_set_nadir()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_ram(struct command_context *ctx) {
    if (!adcs_set_ram()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_mindrag(struct command_context *ctx) {
    if (!adcs_set_mindrag()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_maxdrag(struct command_context *ctx) {
    if (!adcs_set_maxdrag()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_custom0(struct command_context *ctx) {
    if (!adcs_set_custom0()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_custom1(struct command_context *ctx) {
    if (!adcs_set_custom1()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_set_custom2(struct command_context *ctx) {
    if (!adcs_set_custom2()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

/**********************************************************************/
// Target commands
/**********************************************************************/

int cmd_adcs_track_reset(struct command_context *ctx) {
    if (!adcs_track_reset()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_track_sun(struct command_context *ctx) {
    if (!adcs_track_sun()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_track_moon(struct command_context *ctx) {
    if (!adcs_track_moon()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_track_target0(struct command_context *ctx) {
    if (!adcs_track_target0()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_track_target1(struct command_context *ctx) {
    if (!adcs_track_target1()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_track_target2(struct command_context *ctx) {
    if (!adcs_track_target2()) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

/**********************************************************************/
// Sensor commands 
/**********************************************************************/

int cmd_adcs_sensors_init(struct command_context *ctx) {
    if (adcs_sensor_init() <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

int cmd_adcs_sensors_htpa_init(struct command_context *ctx)
{
    if (ctx->argc != 1)
    {
        return CMD_ERROR_SYNTAX;
    }
    // uint8_t id = atoi(ctx->argv[1]);
    
    if (adcs_sensors_htpa_init() <= 0)
    {
        return CMD_ERROR_FAIL;
    }
    
    return CMD_ERROR_NONE;
}

int cmd_adcs_sensors_htpa_shutdown(struct command_context *ctx)
{
    if (ctx->argc != 1)
    {
        return CMD_ERROR_SYNTAX;
    }
    // uint8_t id = atoi(ctx->argv[1]);

    if (adcs_sensors_htpa_shutdown() <= 0)
    {
        return CMD_ERROR_FAIL;
    }
    
    return CMD_ERROR_NONE;

}

int cmd_adcs_sensors_htpa_saveimage(struct command_context *ctx)
{
    if (ctx->argc != 3)
    {
        return CMD_ERROR_SYNTAX;
    }
    uint8_t id = atoi(ctx->argv[1]);
    const char * filepath = ctx->argv[2];
    if (adcs_sensors_htpa_saveimage(id, filepath) <= 0)
    {
        return CMD_ERROR_FAIL;
    }

    return CMD_ERROR_NONE;
}

int cmd_adcs_sensors_htpa_sample(struct command_context *ctx)
{
    gs_adcs_htpa_sample_t sample;
    if (ctx->argc != 2){
        return CMD_ERROR_SYNTAX;
    }
    sample.id = atoi(ctx->argv[1]);

    if(sample.id > 3){
        return CMD_ERROR_SYNTAX;
    }

    if (adcs_sensors_htpa_rsample(&sample) <= 0){
        return CMD_ERROR_FAIL;
    } else {
        printf("HTPA_ID: %d\r\n", sample.id);
        printf("EDGE_CNT: %d\r\n", sample.edge_cnt);
        printf("[roll, pitch] : [%.3f , %.3f][rad]\r\n", sample.roll, sample.pitch);
        printf("[Cy, Cz, Cr]  : [%.3f , %.3f , %.3f][px]\r\n", sample.Cy, sample.Cz, sample.Cr);
        printf("[Gy, Gz, G]   : [%.3f , %.3f , %.3f][-]\r\n", sample.Gy, sample.Gz, sample.G);
        return CMD_ERROR_NONE;
    }
}


/**********************************************************************/
// Actuator commands
/**********************************************************************/

int cmd_adcs_act_mw_get_status(struct command_context *ctx) {
    adcs_act_mw_get_status_t status;
    if (adcs_act_mw_get_status(&status) <= 0)
        return CMD_ERROR_FAIL;
    for (int i = 0; i < 4; i++) {
        printf("MW%i: Enabled: %i\t Speed: %f\t Torque: %f \r\n", i,
                status.enable[i], status.speed[i], status.torque[i]);
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_act_mw_set(struct command_context *ctx) {

    if (ctx->argc != 4) {
        return CMD_ERROR_SYNTAX;
    }
    adcs_act_mw_set_t cmd;
    cmd.mw = atoi(ctx->argv[1]);
    cmd.torque = (float) atol(ctx->argv[2])/1e7; // Scale from 1/100 nNm -> Nm
    cmd.time = atoi(ctx->argv[3]);

    if (cmd.mw > 5){
        return CMD_ERROR_SYNTAX;
    }

    if (adcs_act_mw_set(cmd) <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

int cmd_adcs_act_mw_config(struct command_context *ctx) {

    if (ctx->argc != 4) {
        return CMD_ERROR_SYNTAX;
    }
    adcs_act_mw_config_t cmd;
    cmd.axis = atoi(ctx->argv[1]);
    cmd.torque = (float) atol(ctx->argv[2])/1e7; // Scale from 1/100 nNm -> Nm
    cmd.time = atoi(ctx->argv[3]);

    if(cmd.axis > 2){
        return CMD_ERROR_SYNTAX;
    }

    if (adcs_act_mw_config(cmd) <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

int cmd_adcs_act_mw_enable(struct command_context *ctx) {

    if (ctx->argc != 3) {
        return CMD_ERROR_SYNTAX;
    }
    adcs_act_mw_enable_t enable;
    enable.mw = atoi(ctx->argv[1]);
    enable.enable = atoi(ctx->argv[2]);

    if (adcs_act_mw_enable(enable) <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

int cmd_adcs_act_mw_on(struct command_context *ctx) {
    adcs_act_mw_on();
    return CMD_ERROR_NONE;
}

int cmd_adcs_act_mw_off(struct command_context *ctx) {
    adcs_act_mw_off();
    return CMD_ERROR_NONE;
}

int cmd_adcs_act_mw_tb(struct command_context *ctx) {
    
    if (ctx->argc != 6) {
        return CMD_ERROR_SYNTAX;
    }
    // set limits for torquebox
    uint8_t t_limit = 60; // [s]
    uint8_t cycles_limit = 5; // [-]

    adcs_act_mw_tb_t cmd;
    cmd.mw = atoi(ctx->argv[1]);
    cmd.torque = (float) atol(ctx->argv[2])/1e7; // Scale from 1/100 nNm -> Nm
    cmd.time = atoi(ctx->argv[3]);
    cmd.cycles = atoi(ctx->argv[4]);

    if (cmd.time > t_limit || cmd.cycles > cycles_limit){
        return CMD_ERROR_SYNTAX;
    }

    memset(cmd.filepath, 0, sizeof(cmd.filepath));
    strcpy(cmd.filepath, ctx->argv[5]);

    if (adcs_act_mw_tb(cmd) <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

int cmd_adcs_act_trq_get(struct command_context *ctx) {
    adcs_act_torquers_t trq;
    if (adcs_act_get_torquers(&trq) <= 0) {
        return CMD_ERROR_FAIL;
    }
    printf("[ch0, ch1, ch2] : [%f, %f, %f]\r\n", trq.pwm[0], trq.pwm[1], trq.pwm[2]);
    return CMD_ERROR_NONE;
}

int cmd_adcs_act_trq_set(struct command_context *ctx) {

    if (ctx->argc != 4) {
        return CMD_ERROR_SYNTAX;
    }
    adcs_act_torquers_t trq;
    trq.pwm[0] = atoi(ctx->argv[1]);
    trq.pwm[1] = atoi(ctx->argv[2]);
    trq.pwm[2] = atoi(ctx->argv[3]);
    if (adcs_act_set_torquers(&trq) <= 0) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

/**********************************************************************/
// GPS commands
/**********************************************************************/
int cmd_gps_sample(struct command_context *ctx) {
    adcs_gps_sample_t sample;
    if (adcs_gps_get_sample(&sample) <= 0) {
        return CMD_ERROR_FAIL;
    }
    printf("Pos X: %f Y: %f Z: %f \r\n", sample.posxyz[0], sample.posxyz[1], sample.posxyz[2]);
    printf("Vel X: %f,Y: %f Z: %f \r\n", sample.velxyz[0], sample.velxyz[1], sample.velxyz[2]);
    printf("Satellites tracked: %i, used: %i\r\n", sample.satellitesTrack, sample.satellitesSol);
    return CMD_ERROR_NONE;
}

int cmd_gps_reset(struct command_context *ctx) {
    if (adcs_gps_reset() <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

int cmd_adcs_gps_on(struct command_context *ctx) {
    adcs_gps_on();
    return CMD_ERROR_NONE;
}

int cmd_adcs_gps_off(struct command_context *ctx) {
    adcs_gps_off();
    return CMD_ERROR_NONE;
}

int cmd_adcs_gps_ascii(struct command_context *ctx) {
    gps_ascii_cmd_t cmd;

    if (ctx->argc != 3)
        return CMD_ERROR_SYNTAX;

    cmd.timeout = atoi(ctx->argv[1]);
    strncpy(cmd.data, ctx->argv[2], GPS_CSP_MAX_LEN);

    cmd.length = strlen(cmd.data);
    strcpy(&cmd.data[cmd.length], "\r\n");
    cmd.length = strlen(cmd.data);

    if (cmd.length > 250)
        return CMD_ERROR_FAIL;

    adcs_gps_ascii(&cmd);
    return CMD_ERROR_NONE;
}

int cmd_adcs_gps_trackstat(struct command_context *ctx) {
    adcs_gps_trackstat();
    return CMD_ERROR_NONE;
}

int cmd_adcs_gps_rxstatus(struct command_context *ctx) {
    adcs_gps_rxstatus_t rxstatus;
    adcs_gps_rxstat(&rxstatus);
    printf("Error: %"PRIu32" \r\n",rxstatus.error);
    printf("Number of stat. codes: %"PRIu32" \r\n",rxstatus.nr_stats);
    printf("RXstat: %"PRIu32" \r\n",rxstatus.rxstat);
    printf("AUX1stat: %"PRIu32" \r\n",rxstatus.aux1stat);
    printf("AUX2stat: %"PRIu32" \r\n",rxstatus.aux2stat);
    printf("AUX3stat: %"PRIu32" \r\n",rxstatus.aux3stat);

    return CMD_ERROR_NONE;
}

int cmd_adcs_gps_temp(struct command_context *ctx) {
    adcs_float_t temperature;
    if (adcs_gps_temp(&temperature)) {
        printf("Temp: %f \r\n",temperature);
    }
    return CMD_ERROR_NONE;
}

int cmd_adcs_gps_ecutoff(struct command_context *ctx) {
    if (ctx->argc != 2) {
        return CMD_ERROR_SYNTAX;
    }
    float value = atof(ctx->argv[1]);
    adcs_gps_ecutoff(value);
    return CMD_ERROR_NONE;
}

int cmd_gps_lastsample(struct command_context *ctx) {
    adcs_gps_last_sample_t data;
    adcs_gps_last_sample(&data);
    printf("Position:     %f %f %f \r\n", data.posxyz[0], data.posxyz[1], data.posxyz[2]);
    printf("Velocity:     %f %f %f \r\n", data.velxyz[0], data.velxyz[1], data.velxyz[2]);
    printf("Valid:        %u\r\n", data.valid);

    return 0;
}

int cmd_gps_lastpps(struct command_context *ctx) {
    adcs_gps_last_pps_t data;
    adcs_gps_last_pps(&data);
    printf("Unixtime: %"PRIu32" \r\n", data.unixtime);
    printf("Valid:        %u\r\n", data.valid);
    return 0;
}

int cmd_gps_en_varf(struct command_context *ctx) {

    adcs_gps_en_varf_t en_varf;
    en_varf.enable = atoi(ctx->argv[1]);

    if (adcs_gps_en_varf(en_varf) <= 0)
        return CMD_ERROR_FAIL;
    return CMD_ERROR_NONE;
}

/**********************************************************************/
// TLE commands
/**********************************************************************/
int cmd_adcs_ephem_new_tle(struct command_context *ctx) {
    if (adcs_ephem_new_tle() <= 0) {
        return CMD_ERROR_FAIL;
    }
    log_info("TLE SET");
    return CMD_ERROR_NONE;
}

/* State commands */
static const gs_command_t state_commands[] = {
		{
				.name = "get",
				.help = "Get ADCS state",
				.handler = cmd_adcs_get_adcs_state,
		},{
				.name = "setads",
				.help = "Set ADS state",
				.handler = cmd_adcs_set_ads_state,
		},{
				.name = "setacs",
				.help = "Set ACS state",
				.handler = cmd_adcs_set_acs_state,
		},{
				.name = "setephem",
				.help = "Set EPHEM state",
				.handler = cmd_adcs_set_ephem_state,
		}
};



/* tle commands */
static const gs_command_t tle_commands[] = {
		{
				.name = "new",
				.help = "Use new TLE",
				.handler = cmd_adcs_ephem_new_tle,
		}
};

/* Bdot commands */

static const gs_command_t bdot_commands[] = {
		{
				.name = "detumble",
				.help = "Force bdot into detumbled state",
				.handler = cmd_adcs_bdot_force_detumbled,
		},
};

static const gs_command_t htpa_commands[] = {
    {
        .name = "init",
        .help = "Initialise all configured Horizon sensors",
        .handler = cmd_adcs_sensors_htpa_init,
    },
    {
        .name = "shutdown",
        .help = "Shutdown all configured Horizon sensors",
        .handler = cmd_adcs_sensors_htpa_shutdown,
    },
    {
        .name = "saveimage",
        .help = "saveimage <id> <filename> save an image to disk, id[0-3]. Sensor must be woken first",
        .usage = "<id> <filename>",
        .handler = cmd_adcs_sensors_htpa_saveimage,
    },
    {
        .name = "sample",
        .help = "Get htpa sample id[0-3]",
        .usage = "sample <id>",
        .handler = cmd_adcs_sensors_htpa_sample,
    }
};

static const gs_command_t sensor_commands[] = {
		{
				.name = "init",
				.help = "Do an all-sensor-init ",
				.handler = cmd_adcs_sensors_init,
		},
        {
                .name = "htpa",
                .help = "HTPA interface",
                .chain = INIT_CHAIN(htpa_commands),
        }
};


static const gs_command_t mw_commands[] = {
		{		.name = "get",
				.help = "Wheel status",
				.handler = cmd_adcs_act_mw_get_status,
		},
		{		.name = "set",
				.usage = "Set <MW> <torque [1/100 nNm]> <time [s]>",
                .help = "Sets torque references [1/100 nNm] and the torque duration time [s]",
				.handler = cmd_adcs_act_mw_set,
		},
        {       .name = "config",
                .usage = "Set <axis [0-2]> <torque [1/100 nNm]> <time [s]>",
                .help = "Set torque on reaction wheel configuration",
                .handler = cmd_adcs_act_mw_config,
        },
		{		.name = "tb",
                .usage = "Set <MW [0-3]> <torque [1/100 nNm]> <time [1-60][s]> <cycles [1-5]> <filename>",
				.help = "Run a torquebox on a RW and save to file",
				.handler = cmd_adcs_act_mw_tb,
		},
        {       .name = "enable",
                .help = "Enable <MW>",
                .handler = cmd_adcs_act_mw_enable,
        },
        {       .name = "on",
                .help = "Turn on WDE",
                .handler = cmd_adcs_act_mw_on,
        },
        {       .name = "off",
                .help = "Turn off the WDE",
                .handler = cmd_adcs_act_mw_off,
        }
};

static const gs_command_t trq_commands[] = {
		{		.name = "get",
				.help = "Get channel output level",
				.handler = cmd_adcs_act_trq_get,
		},
		{		.name = "set",
                .usage = "Set <X> <Y> <Z>",
                .help = "Set torquer dutycycle in the body frame",
				.handler = cmd_adcs_act_trq_set,
		}
};



static const gs_command_t act_commands[] = {
		{
				.name = "mw",
				.help = "Wheel interface",
				.chain = INIT_CHAIN(mw_commands),
		},{
				.name = "trq",
				.help = "Magnetorquer interface",
				.chain = INIT_CHAIN(trq_commands),
		}
};

static const gs_command_t gps_commands[] = {
        {
				.name = "sample",
				.help = "Get GPS data",
				.handler = cmd_gps_sample,
		},
		{
				.name = "reset",
				.help = "GPS Reset",
				.handler = cmd_gps_reset,
		},{
				.name = "on",
				.help = "GPS on",
				.handler = cmd_adcs_gps_on,
		},{
				.name = "off",
				.help = "GPS off",
				.handler = cmd_adcs_gps_off,
		},{
				.name = "ascii",
				.help = "ascii cmd to the GPS",
				.usage = "<timeout_ms> <ascii string>",
				.handler = cmd_adcs_gps_ascii,
		},{
				.name = "trackstat",
				.help = "GPS Trackstatus",
				.usage = "void",
				.handler = cmd_adcs_gps_trackstat,
		},{
				.name = "rxstatus",
				.help = "Retrieve status of GPS reciever",
				.usage = "void",
				.handler = cmd_adcs_gps_rxstatus,
		},{
				.name = "temp",
				.help = "GPS Temperature",
				.handler = cmd_adcs_gps_temp,
		},{
				.name = "ecutoff",
				.help = "Set the elevation cutoff angle",
				.handler = cmd_adcs_gps_ecutoff,
		},{
				.name = "lastsample",
				.help = "Last GPS sample",
				.handler = cmd_gps_lastsample,
		},{
				.name = "lastpps",
				.help = "Last PPS value",
				.handler = cmd_gps_lastpps,
		},{
                .name = "varf",
                .help = "Enable/Disable VARF",
                .usage = "<1/0>",
                .handler = cmd_gps_en_varf,
        }
};

/* Ephemeris commands */

static const gs_command_t ephem_commands[] = {
		{
				.name = "tle",
				.help = "TLE commands",
				.chain = INIT_CHAIN(tle_commands),
		},
};


static const gs_command_t runmode_commands[] = {
		{
				.name = "start",
				.help = "Start ADCS",
				.handler = cmd_adcs_start,
		},{
				.name = "sensors",
				.help = "Stop ADCS",
				.handler = cmd_adcs_sensors,
		},{
				.name = "stop",
				.help = "Full stop ADCS (no sensor sample)",
				.handler = cmd_adcs_stop,
		},{
				.name = "restart",
				.help = "Restart ADCS",
				.handler = cmd_adcs_restart,
		}
};

static const gs_command_t hk_commands[] = {
		{
				.name = "basic",
				.help = "Get basic housekeeping",
				.handler = cmd_adcs_hk_basic,
		}
};

static const gs_command_t set_commands[] = {
		{
				.name = "reset",
				.help = "Default pointing",
				.handler = cmd_adcs_set_reset,
		},{
				.name = "nadir",
				.help = "Nadir pointing",
				.handler = cmd_adcs_set_nadir,
		},{
				.name = "ram",
				.help = "RAM pointing",
				.handler = cmd_adcs_set_ram,
		},{
				.name = "mindrag",
				.help = "Min surface",
				.handler = cmd_adcs_set_mindrag,
		},{
				.name = "maxdrag",
				.help = "Max surface",
				.handler = cmd_adcs_set_maxdrag,
		},{
				.name = "custom0",
				.help = "Custom pointing offset",
				.handler = cmd_adcs_set_custom0,
		},{
				.name = "custom1",
				.help = "Custom pointing offset",
				.handler = cmd_adcs_set_custom1,
		},{
				.name = "custom2",
				.help = "Custom pointing offset",
				.handler = cmd_adcs_set_custom2,
		},
};

static const gs_command_t track_commands[] = {
        {
                .name = "reset",
                .help = "Default pointing",
                .handler = cmd_adcs_track_reset,
        },{
                .name = "sun",
                .help = "Sun pointing",
                .handler = cmd_adcs_track_sun,
        },{
                .name = "moon",
                .help = "Moon pointing",
                .handler = cmd_adcs_track_moon,
        },{
                .name = "target0",
                .help = "Track target0",
                .handler = cmd_adcs_track_target0,
        },{
                .name = "target1",
                .help = "Track target1",
                .handler = cmd_adcs_track_target1,
        },{
                .name = "target2",
                .help = "Track target2",
                .handler = cmd_adcs_track_target2,
        }

};

/* Main commands */
static const gs_command_t adcs_subcommands[] = {
		{
				.name = "hk",
				.help = "hk request",
				.chain = INIT_CHAIN(hk_commands),
		},{
				.name = "run",
				.help = "Start/Stop/Restart ADCS system",
				.chain = INIT_CHAIN(runmode_commands),
		},{
				.name = "sensor",
				.help = "Sensor commands",
				.chain = INIT_CHAIN(sensor_commands),
		},{
				.name = "act",
				.help = "Actuator commands",
				.chain = INIT_CHAIN(act_commands),
		},{
				.name = "state",
				.help = "State commands",
				.chain = INIT_CHAIN(state_commands),
		},{
				.name = "bdot",
				.help = "Bdot commands",
				.chain = INIT_CHAIN(bdot_commands),
		},{
				.name = "ephem",
				.help = "ephem commands",
				.chain = INIT_CHAIN(ephem_commands),
		},{
				.name = "server",
				.help = "Set remote adcs service",
				.usage = "<node> <port>",
				.handler = cmd_adcs_node_set,
		},{
				.name = "set",
				.help = "Set ADCS pointing",
				.chain = INIT_CHAIN(set_commands),
		},{
                .name = "track",
                .help = "Set ADCS tracking",
                .chain = INIT_CHAIN(track_commands),
        }
};

static const gs_command_t GS_COMMAND_ROOT adcs_commands[] = {
		{
				.name = "adcs",
				.help = "ADCS client",
				.chain = INIT_CHAIN(adcs_subcommands),
		},{
				.name = "gps",
				.help = "GPS client",
				.chain = INIT_CHAIN(gps_commands),
		}
};

gs_error_t gs_adcs_register_commands(void)
{
    return GS_COMMAND_REGISTER(adcs_commands);
}
