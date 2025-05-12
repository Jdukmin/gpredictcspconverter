/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#define GS_GSSB_INTERNAL_USE 1
#include <string.h>
#include <gs/util/byteorder.h>
#include <gs/util/drivers/i2c/master.h>
#include <gs/gssb/gssb.h>
#include <gs/gssb/internal/gssb_cmd_id.h>
#include <conf_gssb.h>

void gs_gssb_bus_scan(uint8_t start_addr, uint8_t stop_addr, uint16_t timeout_ms, int8_t * devices)
{
    uint8_t tx_buff[1] = { GSSB_CMD_GET_UUID };
    uint8_t rx_buff[4];

    for (uint8_t addr = start_addr; addr <= stop_addr; addr++) {
        devices[addr] = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr,
                                                  tx_buff, sizeof(tx_buff), rx_buff, sizeof(rx_buff), timeout_ms) == GS_OK ? 0 : -1;
    }
}

gs_error_t gs_gssb_set_i2c_addr(uint8_t addr, uint16_t timeout_ms, uint8_t new_addr)
{
    uint8_t tx_buff[3] = { GSSB_CMD_SET_I2C_ADDR };
    uint8_t rx_buff[1];

    tx_buff[1] = new_addr;
    tx_buff[2] = 0;

    return gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 3, rx_buff, 1, timeout_ms);
}

gs_error_t gs_gssb_commit_i2c_addr(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[2] = { GSSB_CMD_COMMIT_I2C_ADDR };
    uint8_t rx_buff[1];

    tx_buff[1] = 0x33;

    return gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 2, rx_buff, 1, timeout_ms);
}

gs_error_t gs_gssb_get_version(uint8_t addr, uint16_t timeout_ms, uint8_t * rxbuff, uint8_t len)
{
    uint8_t tx_buff[1] = { GSSB_CMD_GET_ID };

    return gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rxbuff, len, timeout_ms);
}

gs_error_t gs_gssb_get_uuid(uint8_t addr, uint16_t timeout_ms, uint32_t * uuid)
{
    uint8_t tx_buff[1] = { GSSB_CMD_GET_UUID };
    uint8_t rx_buff[4];
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rx_buff, 4, timeout_ms);
    memcpy(uuid, rx_buff, 4);
    *uuid = util_betoh32(*uuid);

    return res;
}

gs_error_t gs_gssb_get_model(uint8_t addr, uint16_t timeout_ms, gs_gssb_model_t * model)
{
    uint8_t tx_buff[1] = { GSSB_CMD_GET_MODEL };
    uint8_t rx_buff[2];
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rx_buff, 2, timeout_ms);
    *model = rx_buff[1];

    return res;
}

gs_error_t gs_gssb_soft_reset(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[2] = { GSSB_CMD_SOFT_RESET, 0x5A };
    uint8_t rx_buff[1];
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 2, rx_buff, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_common_get_internal_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out)
{
    uint8_t tx_buff[1] = { GSSB_CMD_COMMON_GET_INTERNAL_TEMP };
    uint8_t rx_buff[4];
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 1, &rx_buff, 4, timeout_ms);
    *temp_out = (int16_t) (rx_buff[2] | (rx_buff[3] << 8));

    return res;
}

gs_error_t gs_gssb_common_get_sun_voltage(uint8_t addr, uint16_t timeout_ms, uint16_t * voltage)
{
    uint8_t tx_buff[1] = { GSSB_CMD_COMMON_GET_SUNSENSOR_VOLTAGE };
    uint8_t rx_buff[4];
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 1, &rx_buff, 4, timeout_ms);
    *voltage = rx_buff[2] | (rx_buff[3] << 8);

    return res;
}

gs_error_t gs_gssb_common_stop_burn(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[1] = { GSSB_CMD_COMMON_STOP_BURN };
    uint8_t rx_buff[1];
    gs_error_t res;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rx_buff, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_common_reset_count(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[1] = { GSSB_CMD_COMMON_RESET_COUNT };
    uint8_t rx_buff[1];
    gs_error_t res;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rx_buff, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_common_get_board_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_board_status_t * board_status)
{
    uint8_t tx_buff[1] = { GSSB_CMD_COMMON_GET_BOARD_STATUS };
    uint8_t rx_buff[6];
    gs_error_t res;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rx_buff, 6, timeout_ms);
    board_status->seconds_since_boot = (rx_buff[4] << 24) | (rx_buff[3] << 16) | (rx_buff[2] << 8) | (rx_buff[1]);
    board_status->reboot_count = rx_buff[5];
    return res;
}

gs_error_t gs_gssb_common_get_backup_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_status_t * backup_status)
{
    uint8_t tx_buff[1] = { GSSB_CMD_COMMON_GET_BACKUP_STATUS };
    uint8_t rx_buff[5];
    gs_error_t res;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rx_buff, 5, timeout_ms);
    backup_status->state = rx_buff[0];
    backup_status->seconds_to_deploy = (rx_buff[4] << 24) | (rx_buff[3] << 16) | (rx_buff[2] << 8) | (rx_buff[1]);
    return res;
}

gs_error_t gs_gssb_common_set_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t settings)
{
    uint8_t tx_buff[7] = { GSSB_CMD_COMMON_SET_BACKUP_SETTINGS };
    uint8_t rx_buff[1];
    gs_error_t res;
    tx_buff[2] = settings.minutes;
    tx_buff[3] = settings.minutes >> 8;
    if (settings.backup_active > 0)
        settings.backup_active = 1;
    tx_buff[4] = settings.backup_active;
    tx_buff[5] = settings.max_burn_duration;
    /* Used in data validation */
    tx_buff[6] = 0x33;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 7, &rx_buff, 1, timeout_ms);

    return res;
}

gs_error_t gs_gssb_common_get_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t * settings)
{
    uint8_t tx_buff[1] = { GSSB_CMD_COMMON_GET_BACKUP_SETTINGS };
    uint8_t rx_buff[5];
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 1, &rx_buff, 5, timeout_ms);
    settings->minutes = (rx_buff[1] | (rx_buff[2] << 8));
    settings->backup_active = (rx_buff[3]);
    settings->max_burn_duration = (rx_buff[4]);

    return res;
}

gs_error_t gs_gssb_common_burn_channel(uint8_t addr, uint16_t timeout_ms, uint8_t channel, uint8_t duration)
{
    uint8_t tx_buff[3] = { GSSB_CMD_COMMON_BURN_CHANNEL };
    tx_buff[1] = channel;
    tx_buff[2] = duration;
    uint8_t rx_buff[1];
    gs_error_t res;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 3, rx_buff, 1, timeout_ms);

    return res;
}
