#ifndef _GS_GSSB_AR6_H_
#define _GS_GSSB_AR6_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   API for the board type Nanoutil AR6 and board type Nanoutil Interstage 3u (AR6)
*/

#include <gs/gssb/gssb_dev.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Get ar6 internal MCU temperature.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] temp_out Temperature.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ar6_get_internal_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out);

/**
   Burn ar6.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] duration Duration in seconds to burn.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ar6_burn(uint8_t addr, uint16_t timeout_ms, uint8_t duration);

/**
   Stop ar6 burn.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ar6_stop_burn(uint8_t addr, uint16_t timeout_ms);

/**
   Get ar6 release status.

   @see gs_gssb_ar6_release_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] status Pointer to release status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ar6_get_release_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_ar6_release_status_t * status);

/**
   Get ar6 backup status.

   @see gs_gssb_backup_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] backup_status Backup status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ar6_get_backup_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_status_t * backup_status);

/**
   Get ar6 board status.

   @see gs_gssb_board_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] board_status Board status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ar6_get_board_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_board_status_t * board_status);

/**
   Get ar6 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] settings Backup settings.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ar6_get_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t * settings);

/**
   Set ar6 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] settings Backup settings.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ar6_set_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t settings);

/**
   Reset ar6 counters.

   Resets burn counters and reboot counter on ar6.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_ar6_reset_count(uint8_t addr, uint16_t timeout_ms);

#ifdef __cplusplus
}
#endif
#endif
