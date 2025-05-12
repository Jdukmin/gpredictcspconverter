/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <stdio.h>
#include <csp/csp.h>
#include <csp/csp_endian.h>

#include <util/log.h>
#include <util/hexdump.h>
#include <util/byteorder.h>

#include <gs/adcs/adcs_types.h>
#include <gs/adcs/adcs_param.h>

#define ADCS_CSP_TIMEOUT 2000
#define ADCS_GPS_CSP_TIMEOUT 10000
#define ADCS_HTPA_CSP_TIMEOUT 5000

/* Node / Server declaration */
static int node_adcs = 4;
static int port_adcs = 20;
static int timeout_adcs = ADCS_CSP_TIMEOUT;

void adcs_periph_node_set(int node, int port) {
	node_adcs = node;
	port_adcs = port;
}

void adcs_periph_timeout_set(int timeout) {
	timeout_adcs = timeout;
}

/* Sensor commands */
int adcs_sensor_init(void){
	adcs_server_packet_t p;
	p.cmd = ADCS_CMD_SENSOR_INIT;
	return csp_transaction(CSP_PRIO_NORM, node_adcs, port_adcs, timeout_adcs, &p, ADCS_SERVER_PACKET_SIZE(0), NULL, 0);
}

/* Act commands */
int adcs_act_mw_get_status(adcs_act_mw_get_status_t *value){
	int retval;
	adcs_server_packet_t p;
	p.cmd = ADCS_CMD_ACT_MW_GET_STAT;
	retval = csp_transaction(CSP_PRIO_NORM, node_adcs, port_adcs, timeout_adcs,
			&p, ADCS_SERVER_PACKET_SIZE(NULL),
			&p,	ADCS_SERVER_PACKET_SIZE(adcs_act_mw_get_status_t));
	if (retval == ADCS_SERVER_PACKET_SIZE(adcs_act_mw_get_status_t)) {
		for (int i=0; i<4; i++){
			value->enable[i] = p.mw.mw_status.enable[i];
			value->speed[i] = util_ntohflt(p.mw.mw_status.speed[i]);
			value->torque[i] = util_ntohflt(p.mw.mw_status.torque[i]);
		}
	}
	else
		retval = 0;
	return retval;
}

int adcs_act_mw_set(adcs_act_mw_set_t value){
	int retval;
	adcs_server_packet_t p;
	p.cmd = ADCS_CMD_ACT_MW_SET;
	p.mw.mw_set.mw = value.mw;
	p.mw.mw_set.torque = util_htonflt(value.torque);
	p.mw.mw_set.time = value.time;

	retval = csp_transaction(CSP_PRIO_NORM, node_adcs, port_adcs, timeout_adcs,
			&p, ADCS_SERVER_PACKET_SIZE(adcs_act_mw_set_t),
			&p,	ADCS_SERVER_PACKET_SIZE(adcs_act_mw_set_t));
	if (retval == ADCS_SERVER_PACKET_SIZE(adcs_act_mw_set_t)) {
	}
	else {
		retval = 0;
	}
	return retval;
}

int adcs_act_mw_config(adcs_act_mw_config_t value){
	int retval;
	adcs_server_packet_t p;
	p.cmd = ADCS_CMD_ACT_MW_CONFIG;
	p.mw.mw_config.axis = value.axis;
	p.mw.mw_config.torque = util_htonflt(value.torque);
	p.mw.mw_config.time = value.time;

	retval = csp_transaction(CSP_PRIO_NORM, node_adcs, port_adcs, timeout_adcs,
			&p, ADCS_SERVER_PACKET_SIZE(adcs_act_mw_config_t),
			&p,	ADCS_SERVER_PACKET_SIZE(adcs_act_mw_config_t));
	if (retval == ADCS_SERVER_PACKET_SIZE(adcs_act_mw_config_t)) {
	}
	else {
		retval = 0;
	}
	return retval;
}

int adcs_act_mw_enable(adcs_act_mw_enable_t value){
	int retval;
	adcs_server_packet_t p;
	p.cmd = ADCS_CMD_ACT_MW_EN;
	p.mw.mw_enable.mw = value.mw;
	p.mw.mw_enable.enable = value.enable;
	retval = csp_transaction(CSP_PRIO_NORM, node_adcs, port_adcs, timeout_adcs,
			&p, ADCS_SERVER_PACKET_SIZE(adcs_act_mw_enable_t),
			&p,	ADCS_SERVER_PACKET_SIZE(adcs_act_mw_enable_t));
	if (retval == ADCS_SERVER_PACKET_SIZE(adcs_act_mw_enable_t)) {
	}
	else {
		retval = 0;
	}
	return retval;
}

int adcs_act_mw_on(){
	int retval;
	adcs_server_packet_t p;
	p.cmd = ADCS_CMD_ACT_MW_ON;
	retval = csp_transaction(CSP_PRIO_NORM, node_adcs, port_adcs, timeout_adcs, &p, ADCS_SERVER_PACKET_SIZE(0), &p, ADCS_SERVER_PACKET_SIZE(0));
	if (retval == ADCS_SERVER_PACKET_SIZE(0)) {
	}
	else {
		retval = 0;
	}
	return retval;
}

int adcs_act_mw_off(){
	int retval;
	adcs_server_packet_t p;
	p.cmd = ADCS_CMD_ACT_MW_OFF;
	retval = csp_transaction(CSP_PRIO_NORM, node_adcs, port_adcs, timeout_adcs, &p, ADCS_SERVER_PACKET_SIZE(0), &p, ADCS_SERVER_PACKET_SIZE(0));
	if (retval == ADCS_SERVER_PACKET_SIZE(0)) {
	}
	else {
		retval = 0;
	}
	return retval;
}

int adcs_act_mw_tb(adcs_act_mw_tb_t value){
	int retval;
	adcs_server_packet_t p;
	if (strlen(value.filepath) > MAX_TB_FILEPATH_LENGTH-1) {
        return GS_ERROR_ARG;
    }

	p.cmd = ADCS_CMD_ACT_MW_TB;
	p.mw.mw_tb.mw = value.mw;
	p.mw.mw_tb.torque = util_htonflt(value.torque);
	p.mw.mw_tb.time = value.time;
	p.mw.mw_tb.cycles = value.cycles;

	memset(p.mw.mw_tb.filepath, 0, sizeof(p.mw.mw_tb.filepath));
    strcpy(p.mw.mw_tb.filepath, value.filepath);

	retval = csp_transaction(CSP_PRIO_NORM, node_adcs, port_adcs, timeout_adcs,
			&p, ADCS_SERVER_PACKET_SIZE(adcs_act_mw_tb_t),
			&p,	ADCS_SERVER_PACKET_SIZE(adcs_act_mw_tb_t));
	if (retval == ADCS_SERVER_PACKET_SIZE(adcs_act_mw_tb_t)) {
	}
	else {
		retval = 0;
	}
	return retval;
}

int adcs_act_get_torquers(adcs_act_torquers_t *value)
{
	int retval;
	adcs_server_packet_t p;
	p.cmd = ADCS_CMD_TRQ_GET;
	retval = csp_transaction(CSP_PRIO_NORM, node_adcs, port_adcs, timeout_adcs,
			&p, ADCS_SERVER_PACKET_SIZE(0), 
			&p, ADCS_SERVER_PACKET_SIZE(adcs_act_torquers_t));
	if (retval == ADCS_SERVER_PACKET_SIZE(adcs_act_torquers_t)) {
		value->pwm[0] = util_ntohflt(p.trq.trq.pwm[0]);
		value->pwm[1] = util_ntohflt(p.trq.trq.pwm[1]);
		value->pwm[2] = util_ntohflt(p.trq.trq.pwm[2]);
	}
	return retval;
}

int adcs_act_set_torquers(adcs_act_torquers_t *value)
{
	int retval;
	adcs_server_packet_t p;
	p.cmd = ADCS_CMD_TRQ_SET;
	p.trq.trq.pwm[0] = util_htonflt(value->pwm[0]);
	p.trq.trq.pwm[1] = util_htonflt(value->pwm[1]);
	p.trq.trq.pwm[2] = util_htonflt(value->pwm[2]);
	retval = csp_transaction(CSP_PRIO_NORM, node_adcs, port_adcs, timeout_adcs, &p, ADCS_SERVER_PACKET_SIZE(adcs_act_torquers_t), &p, ADCS_SERVER_PACKET_SIZE(0));
	return retval;
}

int adcs_sensors_htpa_init(void)
{
    adcs_server_packet_t p;
    p.cmd = ADCS_CMD_HTPA_INIT;
    int retval = csp_transaction(CSP_PRIO_NORM,
            node_adcs,
            port_adcs,
            timeout_adcs,
            &p,
            ADCS_SERVER_PACKET_SIZE(gs_adcs_htpa_bus_t),
            &p,
            ADCS_SERVER_PACKET_SIZE(empty_t));

	if (retval != ADCS_SERVER_PACKET_SIZE(0)) {
		retval = 0;
	}
	return retval;
}

int adcs_sensors_htpa_shutdown(void)
{
    adcs_server_packet_t p;
    p.cmd = ADCS_CMD_HTPA_SHUTDOWN;
    int retval = csp_transaction(CSP_PRIO_NORM,
            node_adcs,
            port_adcs,
            timeout_adcs,
            &p,
            ADCS_SERVER_PACKET_SIZE(gs_adcs_htpa_bus_t),
            &p,
            ADCS_SERVER_PACKET_SIZE(empty_t));
	
	if (retval != ADCS_SERVER_PACKET_SIZE(0)) {
		retval = 0;
	}
	return retval;
}

int adcs_sensors_htpa_saveimage(uint8_t id, const char * filepath)
{
    adcs_server_packet_t p;
    if (strlen(filepath) > MAX_HTPA_FILEPATH_LENGTH-1)
    {
        return GS_ERROR_ARG;
    }
    p.cmd = ADCS_CMD_HTPA_TAKEIMAGE;
    p.htpa.filesave.id = id;
    memset(p.htpa.filesave.filepath, 0, sizeof(p.htpa.filesave.filepath));
    strcpy(p.htpa.filesave.filepath, filepath);

    int retval = csp_transaction(CSP_PRIO_NORM,
            node_adcs,
            port_adcs,
            ADCS_HTPA_CSP_TIMEOUT,
            &p,
            ADCS_SERVER_PACKET_SIZE(gs_adcs_htpa_filesave_t),
            &p,
            ADCS_SERVER_PACKET_SIZE(empty_t));
	
	if (retval != ADCS_SERVER_PACKET_SIZE(0)) {
		retval = 0;
	}
	return retval;
}

int adcs_sensors_htpa_rsample(gs_adcs_htpa_sample_t *sample)
{
    adcs_server_packet_t p;
    p.cmd = ADCS_CMD_HTPA_SAMPLE;
    p.htpa.sample.id = sample->id;
    int retval = csp_transaction(CSP_PRIO_NORM,
            node_adcs,
            port_adcs,
            ADCS_HTPA_CSP_TIMEOUT,
            &p,
            ADCS_SERVER_PACKET_SIZE(gs_adcs_htpa_sample_t),
            &p,
            ADCS_SERVER_PACKET_SIZE(gs_adcs_htpa_sample_t));

   	if (retval != ADCS_SERVER_PACKET_SIZE(gs_adcs_htpa_sample_t)) {
   	    retval = 0;
   	}

   	if(p.reply != ADCS_REPLY_OK){
   		return -1;
   	}
    sample->edge_cnt = p.htpa.sample.edge_cnt;
    sample->roll = util_ntohflt(p.htpa.sample.roll);
    sample->pitch = util_ntohflt(p.htpa.sample.pitch);
    sample->Cy = util_ntohflt(p.htpa.sample.Cy);
    sample->Cz = util_ntohflt(p.htpa.sample.Cz);
    sample->Cr = util_ntohflt(p.htpa.sample.Cr);
    sample->Gy = util_ntohflt(p.htpa.sample.Gy);
    sample->Gz = util_ntohflt(p.htpa.sample.Gz);
    sample->G = util_ntohflt(p.htpa.sample.G);

    return retval;
}
