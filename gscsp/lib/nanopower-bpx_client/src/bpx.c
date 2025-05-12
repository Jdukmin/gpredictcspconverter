/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <stdio.h>

#include <csp/csp.h>
#include <csp/csp_endian.h>

#include <gs/bpx/io.h>
#include <gs/util/error.h>

static uint8_t node_bpx = NODE_BPX;
static uint32_t bpx_timeout = 1000;


void bpx_node_set(uint8_t node) {
	node_bpx = node;
}
void bpx_timeout_set(uint32_t timeout) {
	bpx_timeout = timeout;
}


int bpx_counters_reset(void) {
	uint8_t magic = 0x42;
	return csp_transaction(CSP_PRIO_HIGH, node_bpx, BPX_PORT_RESET_COUNTERS, bpx_timeout, &magic, 1, NULL, 0);
}

int bpx_hk_get(bpx_hk_t * hk) {
	int status = bpx_hk_get_p(hk, node_bpx, BPX_PORT_HK, bpx_timeout);
	return status;
} 

int bpx_hk_get_p(bpx_hk_t * hk, uint8_t dest, uint8_t port, uint32_t timeout) {

	int status = csp_transaction(CSP_PRIO_NORM, dest, port, timeout, NULL, 0, hk, sizeof(*hk));
	if (status != sizeof(bpx_hk_t))
		return status;
	hk->cur_charge = csp_ntoh16(hk->cur_charge);
	hk->cur_discharge = csp_ntoh16(hk->cur_discharge);
	hk->cur_heater = csp_ntoh16(hk->cur_heater);
	hk->vbatt = csp_ntoh16(hk->vbatt);
	hk->bat_temperature1 = csp_ntoh16(hk->bat_temperature1);
	hk->bat_temperature2 = csp_ntoh16(hk->bat_temperature2);
	hk->bat_temperature3 = csp_ntoh16(hk->bat_temperature3);
	hk->bat_temperature4 = csp_ntoh16(hk->bat_temperature4);
	hk->counter_boot = csp_ntoh32(hk->counter_boot);
	return status;
}


void bpx_config_print(bpx_config_t * conf) {
	printf("battheater mode: %"PRIu8", low: %"PRIi8" degC, high: %"PRIi8" degC\r\n", conf->battheater_mode, conf->battheater_low, conf->battheater_high);

}


int bpx_config_get(bpx_config_t * config) {
	return csp_transaction(CSP_PRIO_HIGH, node_bpx, BPX_PORT_CONFIG_GET, bpx_timeout, NULL, 0, config, sizeof(bpx_config_t));
}

int bpx_config_set(bpx_config_t * config) {
	return csp_transaction(CSP_PRIO_HIGH, node_bpx, BPX_PORT_CONFIG_SET, bpx_timeout, config, sizeof(bpx_config_t), NULL, 0);
}

int bpx_config_cmd(uint8_t cmd) {
	return csp_transaction(CSP_PRIO_HIGH, node_bpx, BPX_PORT_CONFIG_CMD, bpx_timeout, &cmd, 1, NULL, 0);
}

int bpx_heat_on(uint16_t heat_time, uint8_t * ok_flag){
	heat_time = csp_hton16(heat_time);
	return csp_transaction(CSP_PRIO_HIGH, node_bpx, BPX_PORT_MAN_HEAT_ON, bpx_timeout, &heat_time, sizeof(uint16_t), ok_flag, 1);
}

int bpx_heat_off(uint8_t * ok_flag){
	return csp_transaction(CSP_PRIO_HIGH, node_bpx, BPX_PORT_MAN_HEAT_OFF, bpx_timeout, NULL, 0, ok_flag, 1);
}

