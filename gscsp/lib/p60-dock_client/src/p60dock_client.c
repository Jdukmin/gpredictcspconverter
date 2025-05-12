/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <stddef.h>
#include <stdlib.h>
#include <csp/csp.h>
#include <csp/csp_endian.h>
#include <param/rparam_client.h>
#include <p60dock.h>

/**
 * Setup info about hk parameters
 */
const param_table_t p60dock_hk[] = {
	{.name = "c_out", 			.addr = P60DOCK_HK_C_OUT(0),		.type = PARAM_INT16, 	.size = sizeof(int16_t),  .count = 13},
	{.name = "v_out", 			.addr = P60DOCK_HK_V_OUT(0),		.type = PARAM_UINT16, 	.size = sizeof(uint16_t), .count = 13},
	{.name = "out_en", 			.addr = P60DOCK_HK_OUT_EN(0),		.type = PARAM_UINT8, 	.size = sizeof(uint8_t),  .count = 13},
	{.name = "temp", 			.addr = P60DOCK_HK_TEMP(0),			.type = PARAM_INT16, 	.size = sizeof(int16_t), .count = 2},
	{.name = "bootcause", 		.addr = P60DOCK_HK_BOOT_CAUSE,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_READONLY},
	{.name = "bootcnt", 		.addr = P60DOCK_HK_BOOT_COUNTER,	.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_PERSIST},
	{.name = "uptime", 			.addr = P60DOCK_HK_UPTIME,			.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_READONLY},
	{.name = "resetcause", 		.addr = P60DOCK_HK_RESET_CAUSE,		.type = PARAM_UINT16, 	.size = sizeof(uint16_t), .flags = PARAM_F_PERSIST},
	{.name = "batt_mode", 		.addr = P60DOCK_HK_BATT_MODE,		.type = PARAM_UINT8, 	.size = sizeof(uint8_t)},
	{.name = "heater_on", 		.addr = P60DOCK_HK_HEATER_ON,		.type = PARAM_UINT8, 	.size = sizeof(uint8_t)},
	{.name = "conv_5v_en", 		.addr = P60DOCK_HK_CONV_5V0_EN,		.type = PARAM_UINT8, 	.size = sizeof(uint8_t)},
	{.name = "latchup", 		.addr = P60DOCK_HK_LATCHUP(0),		.type = PARAM_UINT16, 	.size = sizeof(uint16_t), .count = 13, .flags = PARAM_F_PERSIST},
	{.name = "vbat_v", 			.addr = P60DOCK_HK_VBAT_V,			.type = PARAM_UINT16, 	.size = sizeof(uint16_t)},
	{.name = "vcc_c", 			.addr = P60DOCK_HK_VCC_C,			.type = PARAM_INT16, 	.size = sizeof(int16_t)},
	{.name = "batt_c", 			.addr = P60DOCK_HK_BATTERY_C,		.type = PARAM_INT16, 	.size = sizeof(int16_t)},
	{.name = "batt_v", 			.addr = P60DOCK_HK_BATTERY_V,		.type = PARAM_UINT16, 	.size = sizeof(uint16_t)},
	{.name = "batt_temp", 		.addr = P60DOCK_HK_BP_TEMP(0),		.type = PARAM_INT16, 	.size = sizeof(int16_t), .count = 2},
	{.name = "device_type", 	.addr = P60DOCK_HK_DEVICE_TYPE(0),	.type = PARAM_UINT8, 	.size = sizeof(uint8_t),  .count = 8},
	{.name = "device_status", 	.addr = P60DOCK_HK_DEVICE_STATUS(0),.type = PARAM_UINT8, 	.size = sizeof(uint8_t),  .count = 8},
	{.name = "dearm_status", 	.addr = P60DOCK_HK_DEARM_STATUS,	.type = PARAM_UINT8, 	.size = sizeof(uint8_t)},
	{.name = "wdt_cnt_gnd", 	.addr = P60DOCK_HK_CNT_WDTGND,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_PERSIST},
	{.name = "wdt_cnt_i2c", 	.addr = P60DOCK_HK_CNT_WDTI2C,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_PERSIST},
	{.name = "wdt_cnt_can", 	.addr = P60DOCK_HK_CNT_WDTCAN,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .flags = PARAM_F_PERSIST},
	{.name = "wdt_cnt_csp", 	.addr = P60DOCK_HK_CNT_WDTCSP(0),	.type = PARAM_UINT32, 	.size = sizeof(uint32_t), .count = 2, .flags = PARAM_F_PERSIST},
	{.name = "wdt_gnd_left", 	.addr = P60DOCK_HK_WDTGND_LEFT,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t)},
	{.name = "wdt_i2c_left", 	.addr = P60DOCK_HK_WDTI2C_LEFT,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t)},
	{.name = "wdt_can_left", 	.addr = P60DOCK_HK_WDTCAN_LEFT,		.type = PARAM_UINT32, 	.size = sizeof(uint32_t)},
	{.name = "wdt_csp_left", 	.addr = P60DOCK_HK_WDTCSP_LEFT(0),	.type = PARAM_UINT8,	.size = sizeof(uint8_t), .count = 2},
	{.name = "batt_chrg", 		.addr = P60DOCK_HK_BATT_C_CHRG,		.type = PARAM_INT16, 	.size = sizeof(int16_t)},
	{.name = "batt_dischrg", 	.addr = P60DOCK_HK_BATT_C_DISCHRG,	.type = PARAM_INT16, 	.size = sizeof(int16_t)},
	{.name = "ant6_depl", 		.addr = P60DOCK_HK_ANT6_DEPL,		.type = PARAM_INT8, 	.size = sizeof(int8_t)},
	{.name = "ar6_depl", 		.addr = P60DOCK_HK_AR6_DEPL,		.type = PARAM_INT8, 	.size = sizeof(int8_t)},
};

const int p60dock_hk_count = sizeof(p60dock_hk) / sizeof(p60dock_hk[0]);

int p60dock_get_hk(param_index_t * mem, uint8_t node, uint32_t timeout) {

	mem->table = p60dock_hk;
	mem->mem_id = P60DOCK_HK;
	mem->count = p60dock_hk_count;
	mem->size = P60DOCK_HK_SIZE;
	int result = rparam_get_full_table(mem, node, P60_PORT_RPARAM, mem->mem_id, timeout);

	return (result == 0);

}

int p60dock_gndwdt_clear(uint8_t node, uint32_t timeout) {
	uint8_t magic = 0x78;
	return csp_transaction(CSP_PRIO_HIGH, node, P60_PORT_GNDWDT_RESET, timeout, &magic, 1, NULL, 0);
}
