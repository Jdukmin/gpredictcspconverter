#ifndef LIB_LIBGSSB_CLIENT_INCLUDE_GS_GSSB_INTERNAL_GSSB_COMMON_H_
#define LIB_LIBGSSB_CLIENT_INCLUDE_GS_GSSB_INTERNAL_GSSB_COMMON_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Only for internal use

   Contains functions which are supported by a subset of gssb devices.
*/

#if (GS_GSSB_INTERNAL_USE)

/**
   Get sun voltage.

   Gets the interstages external sun sensor reading.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] voltage Voltage.
   @return_gs_error_t
*/
gs_error_t gs_gssb_common_get_sun_voltage(uint8_t addr, uint16_t timeout_ms, uint16_t * voltage);

/**
   Reset counters.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_common_reset_count(uint8_t addr, uint16_t timeout_ms);

/**
   Stop burn.

   Stops burning on all channels immediately.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_common_stop_burn(uint8_t addr, uint16_t timeout_ms);



/**
   Get internal MCU temperature.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] temp_out Temperature.
   @return_gs_error_t
*/
gs_error_t gs_gssb_common_get_internal_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out);

/**
   Set backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] settings Backup settings.
   @return_gs_error_t
*/
gs_error_t gs_gssb_common_set_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t settings);

/**
   Get backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] settings Backup settings.
   @return_gs_error_t
*/
gs_error_t gs_gssb_common_get_backup_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_settings_t * settings);

/**
   Burn channel.

   Burns a specific duration on the specific channel.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] channel Channel to be burned on.
   @param[in] duration Duration in seconds to burn.
   @return_gs_error_t
*/
gs_error_t gs_gssb_common_burn_channel(uint8_t addr, uint16_t timeout_ms, uint8_t channel, uint8_t duration);

/**
   Get backup status.

   @see gs_gssb_backup_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] channel_status Backup status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_common_get_backup_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_backup_status_t * backup_status);

/**
   Get board status.

   @see gs_gssb_board_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] board_status Board status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_common_get_board_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_board_status_t * board_status);
#endif
#endif /* LIB_LIBGSSB_CLIENT_INCLUDE_GS_GSSB_INTERNAL_GSSB_COMMON_H_ */
