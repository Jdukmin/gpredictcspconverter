#ifndef _GS_GSSB_ANT6_H_
#define _GS_GSSB_ANT6_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   API for the board type Nanocom ANT-6F UHF (ANT6)
*/

#include <gs/gssb/gssb_dev.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Get ant6 internal MCU temperature.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] temp_out Temperature.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ant6_get_internal_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out);

/**
   Burn ant6 channel.

   Burns a specific duration on the specific channel (side).

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] channel Channel to be burned on (1 = closest MCU, 0 = farthest from MCU).
   @param[in] duration Duration in seconds to burn.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ant6_burn_channel(uint8_t addr, uint16_t timeout_ms, uint8_t channel, uint8_t duration);

/**
   Stop ant6 burn.

   Stops burning on both channels immediately.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ant6_stop_burn_all_channels(uint8_t addr, uint16_t timeout_ms);

/**
   Get ant6 release status.

   @see gs_gssb_ant6_release_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] channel_status Release status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ant6_get_release_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_ant6_release_status_t * channel_status);

/**
   Get ant6 backup status.

   @see gs_gssb_backup_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] backup_status Backup status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ant6_get_backup_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_status_t * backup_status);

/**
   Get ant6 board status.

   @see gs_gssb_board_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] board_status Board status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ant6_get_board_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_board_status_t * board_status);

/**
   Get ant6 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] settings Backup settings.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ant6_get_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t * settings);

/**
   Set ant6 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] settings Backup settings.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ant6_set_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t settings);

/**
   Reset ant6 counters.

   Resets burn counters and reboot counter on ant6.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ant6_reset_count(uint8_t addr, uint16_t timeout_ms);

#ifdef __cplusplus
}
#endif
#endif
