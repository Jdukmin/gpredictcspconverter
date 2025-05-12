/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#define GS_GSSB_INTERNAL_USE 1
#include <string.h>
#include <gs/util/drivers/i2c/master.h>
#include <gs/util/byteorder.h>
#include <gs/gssb/gssb.h>
#include <gs/gssb/internal/gssb_cmd_id.h>
#include <conf_gssb.h>
#include <gs/gssb/internal/gssb_common.h>

gs_error_t gs_gssb_msp_get_internal_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out)
{
    return gs_gssb_common_get_internal_temp(addr, timeout_ms, temp_out);
}

gs_error_t gs_gssb_msp_get_outside_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out)
{
    uint8_t tx_buff[1] = { GSSB_CMD_MSP_GET_OUTSIDE_TEMP };
    uint8_t rx_buff[8];
    gs_error_t res;
    uint16_t tmp_ui;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 1, &rx_buff, 8, timeout_ms);
    tmp_ui = (rx_buff[6] | (rx_buff[7] << 8));
    *temp_out = (int16_t) tmp_ui;
    return res;
}

gs_error_t gs_gssb_msp_get_sun_voltage(uint8_t addr, uint16_t timeout_ms, uint16_t * voltage)
{
    return gs_gssb_common_get_sun_voltage(addr, timeout_ms, voltage);
}

gs_error_t gs_gssb_msp_calibrate_outside_temp(uint8_t addr, uint16_t timeout_ms, uint16_t current, uint16_t resistor)
{
    uint8_t tx_buff[5] = { GSSB_CMD_MSP_CALIBRATE_OUTSIDE_TEMP };
    uint8_t rx_buff[1];
    tx_buff[1] = (current >> 8);
    tx_buff[2] = (current & 0xff);
    tx_buff[3] = (resistor >> 8);
    tx_buff[4] = (resistor & 0xff);
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 5, &rx_buff, 1, timeout_ms);
    return res;
}
