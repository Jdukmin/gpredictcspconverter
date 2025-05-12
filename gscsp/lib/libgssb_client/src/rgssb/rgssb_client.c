/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#define GS_GSSB_INTERNAL_USE 1
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <gs/gssb/rgssb.h>
#include <gs/gssb/internal/rgssb_cmd_id.h>
#include <gs/gssb/internal/rgssb.h>
#include <gs/util/crc32.h>
#include <gs/util/byteorder.h>
#include <gs/util/log.h>
#include <gs/csp/csp.h>
#include <csp/csp_endian.h>
#include "local.h"

static gs_error_t rgssb_cmd(gs_rgssb_dest_t dest, gs_rgssb_cmd_t cmd, gs_rgssb_resp_t * resp)
{
    size_t byte_read;
    uint8_t error_flg = 0;
    if ((cmd.data_length > GS_RGSSB_MAX_DATA_LENGTH) || (resp->data_length > GS_RGSSB_MAX_DATA_LENGTH)) {
        log_error("%s: RGSSB max data length exceeded", __FUNCTION__);
        return GS_ERROR_OVERFLOW;
    }
    cmd.prot_version = GS_RGSSB_PROTOCOL_VERSION;
    cmd.i2c_addr = dest.i2c_addr;
    cmd.i2c_timeout_ms = csp_hton16(dest.i2c_timeout);
    cmd.cmd_id = csp_hton16(cmd.cmd_id);
    uint8_t expected_resp_len = resp->data_length;
    gs_error_t csp_error = gs_csp_transaction(CSP_PRIO_NORM, dest.csp_node, dest.csp_port, dest.csp_timeout,
                                           &cmd, (cmd.data_length + GS_RGSSB_CMD_HEADER_SIZE),
                                           resp, (resp->data_length + GS_RGSSB_RESP_HEADER_SIZE), &byte_read);

    if (csp_error != GS_OK) {
        log_error("%s: csp_transaction(): %d", __FUNCTION__, csp_error);
        error_flg = 1;
    }

    if (expected_resp_len != resp->data_length) {
        log_error("%s: received %d data byte, expected %d data byte", __FUNCTION__, resp->data_length, expected_resp_len);
        error_flg = 1;
    }

    if (cmd.cmd_id != resp->cmd_id) {
        if(csp_ntoh16(resp->cmd_id) == RGSSB_CMD_NOT_FOUND) {
            log_error("%s: Sent cmd_id %d not implemented on GSSB server" , __FUNCTION__, csp_ntoh16(cmd.cmd_id));
        } else {
            log_error("%s: received cmd_id %d did not match sent cmd_id %d", __FUNCTION__, csp_ntoh16(resp->cmd_id), csp_ntoh16(cmd.cmd_id));
        }
        error_flg = 1;
    }

    if (resp->i2c_error != GS_OK) {
        log_error("%s: remote i2c_result: %d", __FUNCTION__, (int)csp_ntoh32(resp->i2c_error));
        error_flg = 1;
    }
    if(error_flg) {
        return GS_ERROR_IO;
    }
    return GS_OK;
}

gs_error_t gs_rgssb_ident(gs_rgssb_dest_t dest, gs_gssb_ident_t * id)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_IDENT,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*id),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(id, resp.data, sizeof(*id));
    id->uuid = csp_ntoh32(id->uuid);
    return GS_OK;
}

gs_error_t gs_rgssb_reboot(gs_rgssb_dest_t dest)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_REBOOT,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };
    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_model(gs_rgssb_dest_t dest, gs_gssb_model_t * model)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_MODEL,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = 1,
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    *model = resp.data[0];
    return GS_OK;
}

gs_error_t gs_rgssb_common_internal_temp(gs_rgssb_dest_t dest, int16_t * internal_temp)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_COMMON_INTERNAL_TEMP,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*internal_temp),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(internal_temp, resp.data, sizeof(*internal_temp));
    *internal_temp = csp_ntoh16(*internal_temp);
    return GS_OK;
}

gs_error_t gs_rgssb_common_stop_burn(gs_rgssb_dest_t dest)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_COMMON_STOP_BURN,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };
    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_common_reset_count(gs_rgssb_dest_t dest)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_COMMON_RESET_CNT,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };
    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_common_get_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t * settings)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_COMMON_GET_BACKUP_SETTINGS,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*settings),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(settings, resp.data, sizeof(*settings));
    settings->minutes = csp_ntoh16(settings->minutes);
    return GS_OK;
}

gs_error_t gs_rgssb_common_set_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t settings)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_COMMON_SET_BACKUP_SETTINGS,
        .data_length = sizeof(settings),
    };
    settings.minutes = csp_ntoh16(settings.minutes);
    memcpy(cmd.data, &settings, sizeof(settings));
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };
    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_common_burn_channel(gs_rgssb_dest_t dest, uint8_t channel, uint8_t burn_seconds)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_COMMON_BURN_CHANNEL,
        .data[0] = channel,
        .data[1] = burn_seconds,
        .data_length = 2,
    };
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };
    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_i4_burn_channel(gs_rgssb_dest_t dest, uint8_t channel, uint8_t burn_seconds)
{
    return gs_rgssb_common_burn_channel(dest, channel, burn_seconds);
}

gs_error_t gs_rgssb_i4_internal_temp(gs_rgssb_dest_t dest, int16_t * internal_temp)
{
    return gs_rgssb_common_internal_temp(dest, internal_temp);
}

gs_error_t gs_rgssb_i4_reset_count(gs_rgssb_dest_t dest)
{
    return gs_rgssb_common_reset_count(dest);
}

gs_error_t gs_rgssb_i4_status(gs_rgssb_dest_t dest, gs_gssb_i4_status_t * status)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_I4_STATUS,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*status),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(status, resp.data, sizeof(*status));
    status->board.seconds_since_boot = csp_ntoh32(status->board.seconds_since_boot);
    status->backup.seconds_to_deploy = csp_ntoh32(status->backup.seconds_to_deploy);
    return GS_OK;
}

gs_error_t gs_rgssb_i4_stop_burn(gs_rgssb_dest_t dest)
{
    return gs_rgssb_common_stop_burn(dest);
}

gs_error_t gs_rgssb_i4_set_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t settings)
{
    return gs_rgssb_common_set_backup_settings(dest, settings);
}

gs_error_t gs_rgssb_i4_get_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t * settings)
{
    return gs_rgssb_common_get_backup_settings(dest, settings);
}


gs_error_t gs_rgssb_ant6_burn_channel(gs_rgssb_dest_t dest, uint8_t channel, uint8_t burn_seconds)
{
    return gs_rgssb_common_burn_channel(dest, channel, burn_seconds);
}

gs_error_t gs_rgssb_ant6_internal_temp(gs_rgssb_dest_t dest, int16_t * internal_temp)
{
    return gs_rgssb_common_internal_temp(dest, internal_temp);
}

gs_error_t gs_rgssb_ant6_reset_count(gs_rgssb_dest_t dest)
{
    return gs_rgssb_common_reset_count(dest);
}

gs_error_t gs_rgssb_ant6_status(gs_rgssb_dest_t dest, gs_gssb_ant6_status_t * status)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_ANT6_STATUS,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*status),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(status, resp.data, sizeof(*status));
    status->board.seconds_since_boot = csp_ntoh32(status->board.seconds_since_boot);
    status->backup.seconds_to_deploy = csp_ntoh32(status->backup.seconds_to_deploy);
    return GS_OK;
}

gs_error_t gs_rgssb_ant6_stop_burn(gs_rgssb_dest_t dest)
{
    return gs_rgssb_common_stop_burn(dest);
}

gs_error_t gs_rgssb_ant6_set_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t settings)
{
    return gs_rgssb_common_set_backup_settings(dest, settings);
}

gs_error_t gs_rgssb_ant6_get_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t * settings)
{
    return gs_rgssb_common_get_backup_settings(dest, settings);
}

gs_error_t gs_rgssb_ar6_burn(gs_rgssb_dest_t dest, uint8_t burn_seconds)
{
    gs_rgssb_cmd_t cmd;
    gs_rgssb_resp_t resp;
    cmd.cmd_id = RGSSB_CMD_AR6_BURN;
    memcpy(cmd.data, &burn_seconds, sizeof(burn_seconds));
    cmd.data_length = sizeof(burn_seconds);
    resp.data_length = 0;

    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_ar6_internal_temp(gs_rgssb_dest_t dest, int16_t * internal_temp)
{
    return gs_rgssb_common_internal_temp(dest, internal_temp);
}

gs_error_t gs_rgssb_ar6_reset_count(gs_rgssb_dest_t dest)
{
    return gs_rgssb_common_reset_count(dest);
}

gs_error_t gs_rgssb_ar6_status(gs_rgssb_dest_t dest, gs_gssb_ar6_status_t * status)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_AR6_STATUS,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*status),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(status, resp.data, sizeof(*status));
    status->board.seconds_since_boot = csp_ntoh32(status->board.seconds_since_boot);
    status->backup.seconds_to_deploy = csp_ntoh32(status->backup.seconds_to_deploy);
    return GS_OK;
}

gs_error_t gs_rgssb_ar6_set_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t settings)
{
    return gs_rgssb_common_set_backup_settings(dest, settings);
}

gs_error_t gs_rgssb_ar6_get_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t * settings)
{
    return gs_rgssb_common_get_backup_settings(dest, settings);
}

gs_error_t gs_rgssb_ar6_stop_burn(gs_rgssb_dest_t dest)
{
    return gs_rgssb_common_stop_burn(dest);
}

gs_error_t gs_rgssb_istage_deploy(gs_rgssb_dest_t dest)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_ISTAGE_DEPLOY,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };
    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_istage_arm(gs_rgssb_dest_t dest, uint8_t arm)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_ISTAGE_ARM,
        .data_length = sizeof(arm),
    };
    if (arm) {
        cmd.data[0] = 0x04;
    } else {
        cmd.data[0] = 0x08;
    }
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };

    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_istage_set_state(gs_rgssb_dest_t dest, uint8_t state)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_ISTAGE_STATE,
        .data_length = sizeof(state),
        .data[0] = state,
    };
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };

    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_istage_sensors(gs_rgssb_dest_t dest, gs_gssb_istage_sensors_t * sensors)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_ISTAGE_SENSORS,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*sensors),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(sensors, resp.data, sizeof(*sensors));
    sensors->panel_temp = csp_ntohflt(sensors->panel_temp);
    sensors->sun_voltage = csp_ntoh16(sensors->sun_voltage);
    sensors->internal_temp = csp_ntoh16(sensors->internal_temp);
    return GS_OK;
}

gs_error_t gs_rgssb_istage_settings_get(gs_rgssb_dest_t dest, gs_gssb_istage_burn_settings_t * settings)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_ISTAGE_CONF_GET,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*settings),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(settings, resp.data, sizeof(*settings));
    settings->std_time_ms = csp_ntoh16(settings->std_time_ms);
    settings->increment_ms = csp_ntoh16(settings->increment_ms);
    settings->short_cnt_down = csp_ntoh16(settings->short_cnt_down);
    return GS_OK;
}

gs_error_t gs_rgssb_istage_settings_set(gs_rgssb_dest_t dest, gs_gssb_istage_burn_settings_t * settings)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_ISTAGE_CONF_SET,
        .data_length = sizeof(*settings),
    };
    settings->std_time_ms = csp_hton16(settings->std_time_ms);
    settings->increment_ms = csp_hton16(settings->increment_ms);
    settings->short_cnt_down = csp_hton16(settings->short_cnt_down);
    memcpy(cmd.data, settings, sizeof(*settings));
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };
    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_istage_status(gs_rgssb_dest_t dest, gs_gssb_istage_status_t * status)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_ISTAGE_STATUS,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*status),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(status, resp.data, sizeof(*status));
    status->deploy_in_s = csp_ntoh16(status->deploy_in_s);
    status->total_number_of_deploys = csp_ntoh16(status->total_number_of_deploys);
    return GS_OK;
}

gs_error_t gs_rgssb_msp_reset_count(gs_rgssb_dest_t dest)
{
    return gs_rgssb_common_reset_count(dest);
}

gs_error_t gs_rgssb_msp_sensors(gs_rgssb_dest_t dest, gs_gssb_msp_sensors_t * sensors)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_MSP_SENSORS,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*sensors),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(sensors, resp.data, sizeof(*sensors));
    sensors->outside_temp = csp_ntoh16(sensors->outside_temp);
    sensors->internal_temp = csp_ntoh16(sensors->internal_temp);
    sensors->sun_voltage = csp_ntoh16(sensors->sun_voltage);
    return GS_OK;
}

gs_error_t gs_rgssb_sunsensor_get_data(gs_rgssb_dest_t dest, uint16_t *sun, uint8_t count)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_SUN_GET_SUNSENSOR,
        .data_length = sizeof(count),
        .data[0] = count,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(uint16_t) * count,
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(sun, resp.data, (sizeof(uint16_t) * count));
    for (uint8_t i = 0 ; i < count ; i++) {
        sun[i] = csp_ntoh16(sun[i]);
    }
    return GS_OK;
}

gs_error_t gs_rgssb_sunsensor_sample_data(gs_rgssb_dest_t dest)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_SUN_SAMPLE_SUNSENSOR,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };
    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_sunsensor_sample_get_data(gs_rgssb_dest_t dest, uint16_t *sun, uint8_t count)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_SUN_SAMPLE_GET_SUNSENSOR,
        .data_length = sizeof(count),
        .data[0] = count,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(uint16_t) * count,
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(sun, resp.data, (sizeof(uint16_t) * count));
    for (uint8_t i = 0 ; i < count ; i++) {
        sun[i] = csp_ntoh16(sun[i]);
    }
    return GS_OK;
}

gs_error_t gs_rgssb_sunsensor_get_temp(gs_rgssb_dest_t dest, float *temp)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_SUN_GET_TEMP,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*temp),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(temp, resp.data, sizeof(*temp));
    *temp = csp_ntohflt(*temp);
    return GS_OK;
}

gs_error_t gs_rgssb_sunsensor_sample_temp(gs_rgssb_dest_t dest)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_SUN_SAMPLE_TEMP,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = 0,
    };
    return rgssb_cmd(dest, cmd, &resp);
}

gs_error_t gs_rgssb_sunsensor_sample_get_temp(gs_rgssb_dest_t dest, float *temp)
{
    gs_rgssb_cmd_t cmd = {
        .cmd_id = RGSSB_CMD_SUN_SAMPLE_GET_TEMP,
        .data_length = 0,
    };
    gs_rgssb_resp_t resp = {
        .data_length = sizeof(*temp),
    };
    gs_error_t error = rgssb_cmd(dest, cmd, &resp);
    if (error != GS_OK) {
        return error;
    }
    memcpy(temp, resp.data, sizeof(*temp));
    *temp = csp_ntohflt(*temp);
    return GS_OK;
}
