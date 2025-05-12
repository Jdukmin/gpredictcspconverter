/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#define GS_GSSB_INTERNAL_USE 1
#include <string.h>
#include <gs/util/drivers/i2c/master.h>
#include <gs/util/byteorder.h>
#include <gs/gssb/gssb.h>
#include <gs/gssb/internal/gssb_cmd_id.h>
#include <conf_gssb.h>
#include <gs/gssb/internal/gssb_common.h>

gs_error_t gs_gssb_ant6_get_internal_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out)
{
    return gs_gssb_common_get_internal_temp(addr, timeout_ms, temp_out);
}

gs_error_t gs_gssb_ant6_burn_channel(uint8_t addr, uint16_t timeout_ms, uint8_t channel, uint8_t duration)
{
    return gs_gssb_common_burn_channel(addr, timeout_ms, channel, duration);
}

gs_error_t gs_gssb_ant6_stop_burn_all_channels(uint8_t addr, uint16_t timeout_ms)
{
    return gs_gssb_common_stop_burn(addr, timeout_ms);
}

gs_error_t gs_gssb_ant6_get_release_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_ant6_release_status_t * channel_status)
{
    uint8_t tx_buff[1] = { GSSB_CMD_ANT6_GET_STATUS_ALL_CHANNELS };
    uint8_t rx_buff[8];
    gs_error_t res;
    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rx_buff, 8, timeout_ms);
    channel_status->channel_0_state = rx_buff[0];
    channel_status->channel_0_burn_time_left = rx_buff[1];
    channel_status->channel_0_status = rx_buff[2];
    channel_status->channel_1_state = rx_buff[3];
    channel_status->channel_1_burn_time_left = rx_buff[4];
    channel_status->channel_1_status = rx_buff[5];
    channel_status->channel_0_burn_tries = rx_buff[6];
    channel_status->channel_1_burn_tries = rx_buff[7];
    return res;
}

gs_error_t gs_gssb_ant6_get_board_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_board_status_t * board_status)
{
    return gs_gssb_common_get_board_status(addr, timeout_ms, board_status);
}

gs_error_t gs_gssb_ant6_reset_count(uint8_t addr, uint16_t timeout_ms)
{
    return gs_gssb_common_reset_count(addr, timeout_ms);
}

gs_error_t gs_gssb_ant6_get_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t * settings)
{
    return gs_gssb_common_get_backup_settings(addr, timeout_ms, settings);
}

gs_error_t gs_gssb_ant6_set_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t settings)
{
    return gs_gssb_common_set_backup_settings(addr, timeout_ms, settings);
}

gs_error_t gs_gssb_ant6_get_backup_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_status_t * backup_status)
{
    return gs_gssb_common_get_backup_status(addr, timeout_ms, backup_status);
}
