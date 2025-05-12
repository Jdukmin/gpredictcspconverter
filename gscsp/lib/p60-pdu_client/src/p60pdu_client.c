/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <csp/csp.h>
#include <csp/csp_endian.h>
#include <param/rparam_client.h>
#include <p60pdu.h>

/**
 * Setup info about hk parameters
 */
const param_table_t p60pdu_hk[] = {
	{.name = "c_out", 			.addr = P60PDU_HK_C_OUT(0),			.type = PARAM_INT16, 	.size = sizeof(int16_t), .count = 9},
	{.name = "v_out", 			.addr = P60PDU_HK_V_OUT(0),			.type = PARAM_UINT16, 	.size = sizeof(int16_t), .count = 9},
	{.name = "vcc", 			.addr = P60PDU_HK_VCC,				.type = PARAM_UINT16, 	.size = sizeof(int16_t)},
	{.name = "vbat", 			.addr = P60PDU_HK_VBAT,				.type = PARAM_UINT16, 	.size = sizeof(int16_t)},
	{.name = "temp", 			.addr = P60PDU_HK_TEMP,				.type = PARAM_INT16, 	.size = sizeof(int16_t)},
	{.name = "conv_en", 		.addr = P60PDU_HK_CONV(0),			.type = PARAM_UINT8, 	.size = sizeof(uint8_t), .count = 3},
	{.name = "out_en", 			.addr = P60PDU_HK_OUT_EN(0),		.type = PARAM_UINT8, 	.size = sizeof(uint8_t), .count = 9},
	{.name = "bootcause", 		.addr = P60PDU_HK_BOOT_CAUSE,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_READONLY},
	{.name = "bootcnt", 		.addr = P60PDU_HK_BOOT_COUNTER,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_PERSIST},
	{.name = "uptime", 			.addr = P60PDU_HK_UPTIME,			.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_READONLY},
	{.name = "resetcause", 		.addr = P60PDU_HK_RESET_CAUSE,		.type = PARAM_UINT16, 	.size = sizeof(uint16_t), .flags = PARAM_F_PERSIST},
	{.name = "batt_mode", 		.addr = P60PDU_HK_BATT_MODE,		.type = PARAM_UINT8, 	.size = sizeof(uint8_t)},
	{.name = "latchup", 		.addr = P60PDU_HK_LATCHUP(0),		.type = PARAM_UINT16, 	.size = sizeof(uint16_t), .count = 9, .flags = PARAM_F_PERSIST},
	{.name = "device_type", 	.addr = P60PDU_HK_DEVICE_TYPE(0),	.type = PARAM_UINT8, 	.size = sizeof(uint8_t),  .count = 8},
	{.name = "device_status", 	.addr = P60PDU_HK_DEVICE_STATUS(0),	.type = PARAM_UINT8, 	.size = sizeof(uint8_t),  .count = 8},
	{.name = "wdt_cnt_gnd", 	.addr = P60PDU_HK_CNT_WDTGND,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_PERSIST},
	{.name = "wdt_cnt_i2c", 	.addr = P60PDU_HK_CNT_WDTI2C,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_PERSIST},
	{.name = "wdt_cnt_can", 	.addr = P60PDU_HK_CNT_WDTCAN,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_PERSIST},
	{.name = "wdt_cnt_csp", 	.addr = P60PDU_HK_CNT_WDTCSP(0),	.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .count = 2, .flags = PARAM_F_PERSIST},
	{.name = "wdt_gnd_left", 	.addr = P60PDU_HK_WDTGND_LEFT,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t)},
	{.name = "wdt_i2c_left", 	.addr = P60PDU_HK_WDTI2C_LEFT,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t)},
	{.name = "wdt_can_left", 	.addr = P60PDU_HK_WDTCAN_LEFT,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t)},
	{.name = "wdt_csp_left", 	.addr = P60PDU_HK_WDTCSP_LEFT(0),	.type = PARAM_UINT8,	.size = sizeof(uint8_t), .count = 2},
};

const int p60pdu_hk_count = sizeof(p60pdu_hk) / sizeof(p60pdu_hk[0]);

int p60pdu_get_hk(param_index_t * mem, uint8_t node, uint32_t timeout) {

	mem->table = p60pdu_hk;
	mem->mem_id = P60PDU_HK;
	mem->count = p60pdu_hk_count;
	mem->size = P60PDU_HK_SIZE;
	int result = rparam_get_full_table(mem, node, P60_PORT_RPARAM, mem->mem_id, timeout);

	return (result == 0);

}

int p60pdu_gndwdt_clear(uint8_t node, uint32_t timeout) {
	uint8_t magic = 0x78;
	return csp_transaction(CSP_PRIO_HIGH, node, P60_PORT_GNDWDT_RESET, timeout, &magic, 1, NULL, 0);
}
