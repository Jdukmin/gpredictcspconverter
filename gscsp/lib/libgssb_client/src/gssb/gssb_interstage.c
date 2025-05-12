/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#define GS_GSSB_INTERNAL_USE 1
#include <string.h>
#include <gs/util/drivers/i2c/master.h>
#include <gs/util/byteorder.h>
#include <gs/gssb/gssb.h>
#include <gs/gssb/internal/gssb_cmd_id.h>
#include <conf_gssb.h>
#include <gs/gssb/internal/gssb_common.h>

gs_error_t gs_gssb_istage_get_internal_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out)
{
    return gs_gssb_common_get_internal_temp(addr, timeout_ms, temp_out);
}

gs_error_t gs_gssb_istage_burn(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[1] = { GSSB_CMD_ISTAGE_BURN };
    uint8_t rx_buff[1];

    return gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rx_buff, 1, timeout_ms);
}

gs_error_t gs_gssb_istage_get_sun_voltage(uint8_t addr, uint16_t timeout_ms, uint16_t * voltage)
{
    return gs_gssb_common_get_sun_voltage(addr, timeout_ms, voltage);
}

gs_error_t gs_gssb_istage_get_burn_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_istage_burn_settings_t * settings)
{
    uint8_t cmd = GSSB_CMD_ISTAGE_GET_BURN_SETTINGS1;
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &cmd, 1, settings, 8, timeout_ms);
    if (res != GS_OK)
        return res;

    cmd = GSSB_CMD_ISTAGE_GET_BURN_SETTINGS2;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &cmd, 1, &settings->switch_polarity, 3, timeout_ms);
    if (res != GS_OK)
        return res;

    /* Fix endian from avr8 gcc compiler little endian */
    settings->std_time_ms = util_letoh16(settings->std_time_ms);
    settings->increment_ms = util_letoh16(settings->increment_ms);
    settings->short_cnt_down = util_letoh16(settings->short_cnt_down);

    return res;
}

gs_error_t gs_gssb_istage_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_istage_status_t * status)
{
    uint8_t txbuff[1] = { GSSB_CMD_ISTAGE_GET_BURN_CNT_RUNNING };
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, txbuff, 1, &status->deploy_in_s, 8, timeout_ms);
    if (res != GS_OK)
        return res;

    /* Fix endian from avr8 gcc compiler little endian */
    status->deploy_in_s = util_letoh16(status->deploy_in_s);
    status->total_number_of_deploys = util_letoh16(status->total_number_of_deploys);
    uint8_t tx_buff[1] = { GSSB_CMD_ISTAGE_GET_RELEASE_STATUS };

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 1, &status->release_status, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_istage_set_burn_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_istage_burn_settings_t * settings)
{
    uint8_t tx_buff[9] = { GSSB_CMD_ISTAGE_SET_BURN_SETTINGS1 };
    uint8_t rx_buff[1];
    gs_error_t res;

    /* Fix endian from avr8 gcc compiler little endian */
    settings->std_time_ms = util_htole16(settings->std_time_ms);
    settings->increment_ms = util_htole16(settings->increment_ms);
    settings->short_cnt_down = util_htole16(settings->short_cnt_down);

    memcpy(&tx_buff[1], settings, 8);
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 9, rx_buff, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_istage_set_burn_settings_cnt(uint8_t addr, uint16_t timeout_ms, gs_gssb_istage_burn_settings_t * settings)
{
    uint8_t tx_buff[3] = { GSSB_CMD_ISTAGE_SET_BURN_SETTINGS2 };
    uint8_t rx_buff[1];
    gs_error_t res;

    /* Fix endian from avr8 gcc compiler little endian */
    tx_buff[1] = settings->switch_polarity;
    tx_buff[2] = settings->reboot_deploy_cnt;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 3, rx_buff, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_istage_set_arm(uint8_t addr, uint16_t timeout_ms, uint8_t data)
{
    uint8_t tx_buff[3] = { GSSB_CMD_ISTAGE_SET_BURN_SETTINGS3 };
    uint8_t rx_buff[1];
    gs_error_t res;

    tx_buff[1] = 0x55;
    tx_buff[2] = data;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 3, rx_buff, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_istage_get_temp(uint8_t addr, uint16_t timeout_ms, float * temp_out)
{
    uint8_t tx_buff[1] = { GSSB_CMD_ISTAGE_GET_TEMP };
    uint8_t rx_buff[2];
    gs_error_t res;
    uint16_t temp;
    int16_t temp_s;
    float tmp;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 1, &rx_buff, 2, timeout_ms);
    temp = (int16_t) (rx_buff[1] | (rx_buff[0] << 8));

    temp_s = (int16_t) (temp << 5);
    temp_s = temp_s >> 5;
    tmp = temp_s * 0.25;

    memcpy(temp_out, &tmp, 4);

    return res;
}

gs_error_t gs_gssb_istage_reset_burn_cnt(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[2] = { GSSB_CMD_ISTAGE_RESET_BURN_CNT };
    uint8_t rx_buff[1];
    gs_error_t res;

    tx_buff[1] = 0x53;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 2, rx_buff, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_istage_set_state(uint8_t addr, uint16_t timeout_ms, uint8_t data)
{
    uint8_t tx_buff[2] = { GSSB_CMD_ISTAGE_CHANGE_STATE };
    uint8_t rx_buff[1];
    gs_error_t res;

    tx_buff[1] = data;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 2, rx_buff, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_istage_settings_unlock(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[4] = { GSSB_CMD_ISTAGE_SETTINGS_UNLOCK };
    uint8_t rx_buff[1];
    gs_error_t res;

    /* Magic numbers to unlock */
    tx_buff[1] = 0x52;
    tx_buff[2] = 0xA7;
    tx_buff[3] = 0xFF;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 4, rx_buff, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_istage_settings_lock(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[4] = { GSSB_CMD_ISTAGE_SETTINGS_UNLOCK };
    uint8_t rx_buff[1];
    gs_error_t res;

    /* All other values than the magic number will lock the settings */
    tx_buff[1] = 0x00;
    tx_buff[2] = 0x00;
    tx_buff[3] = 0x00;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 4, rx_buff, 1, timeout_ms);

    return res;
}

