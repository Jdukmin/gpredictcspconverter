/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <gs/util/error.h>

gs_error_t gs_rgssb_common_internal_temp(gs_rgssb_dest_t dest, int16_t * internal_temp);
gs_error_t gs_rgssb_common_stop_burn(gs_rgssb_dest_t dest);
gs_error_t gs_rgssb_common_reset_count(gs_rgssb_dest_t dest);
gs_error_t gs_rgssb_common_get_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t * settings);
gs_error_t gs_rgssb_common_set_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t settings);
gs_error_t gs_rgssb_common_burn_channel(gs_rgssb_dest_t dest, uint8_t channel, uint8_t burn_seconds);

gs_error_t gs_gssb_msp_calibrate_outside_temp(uint8_t addr, uint16_t timeout_ms, uint16_t current, uint16_t resistor);
