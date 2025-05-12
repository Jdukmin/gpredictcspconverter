#ifndef _GS_GSSB_I4_H_
#define _GS_GSSB_I4_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   API for the board type NanoUtil Interstage GSSB Starling (I4)
*/

#include <gs/gssb/gssb_dev.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Get i4 internal MCU temperature.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] temp_out Temperature.
   @return_gs_error_t
*/
gs_error_t gs_gssb_i4_get_internal_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out);

/**
   Burn i4 channel.

   Burns a specific duration on the specific channel.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] channel Channel to be burned on.
   @param[in] duration Duration in seconds to burn.
   @return_gs_error_t
*/
gs_error_t gs_gssb_i4_burn_channel(uint8_t addr, uint16_t timeout_ms, uint8_t channel, uint8_t duration);

/**
   Stop i4 burn.

   Stops burning on all channels immediately.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_i4_stop_burn_all_channels(uint8_t addr, uint16_t timeout_ms);

/**
   Get i4 release status.

   @see gs_gssb_i4_release_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] channel_status Release status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_i4_get_release_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_i4_release_status_t * channel_status);

/**
   Get i4 backup status.

   @see gs_gssb_backup_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] backup_status Backup status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_i4_get_backup_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_status_t * backup_status);

/**
   Get i4 board status.

   @see gs_gssb_board_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] board_status Board status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_i4_get_board_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_board_status_t * board_status);

/**
   Get i4 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] settings Backup settings.
   @return_gs_error_t
*/
gs_error_t gs_gssb_i4_get_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t * settings);

/**
   Set i4 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] settings Backup settings.
   @return_gs_error_t
*/
gs_error_t gs_gssb_i4_set_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t settings);

/**
   Reset i4 counters.

   Resets burn counters and reboot counter on i4.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_i4_reset_count(uint8_t addr, uint16_t timeout_ms);

#ifdef __cplusplus
}
#endif
#endif
