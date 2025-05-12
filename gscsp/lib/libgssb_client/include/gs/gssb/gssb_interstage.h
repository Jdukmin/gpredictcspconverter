#ifndef _GS_GSSB_ISTAGE_H_
#define _GS_GSSB_ISTAGE_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   API for the board type NanoUtil Interstage GSSB (istage)
*/

#include <gs/gssb/gssb_dev.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Get istage internal MCU temperature.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] temp_out Temperature.
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_get_internal_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out);

/**
   Get istage status.

   @see gs_gssb_istage_status_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] status Status.
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_status(uint8_t addr, uint16_t timeout_ms, gs_gssb_istage_status_t * status);

/**
   Get istage temperature.

   Gets the interstages external temperature sensor. Temp equals -256 if no sensor is connected.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] temp Temperature [degrees C].
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_get_temp(uint8_t addr, uint16_t timeout_ms, float * temp);

/**
   Manual burn istage.

   Makes the interstages burn, when it is armed for manual deploy.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_burn(uint8_t addr, uint16_t timeout_ms);

/**
   Get istage sun voltage.

   Gets the interstages external sun sensor reading.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] voltage Voltage.
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_get_sun_voltage(uint8_t addr, uint16_t timeout_ms, uint16_t * voltage);

/**
   Get istage burn settings.

   @see gs_gssb_istage_burn_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] settings Settings.
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_get_burn_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_istage_burn_settings_t * settings);

/**
   Set istage burn settings.

   @see gs_gssb_istage_burn_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] settings Burn settings (sets only std_time_ms, increment_ms and short_cnt_down).
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_set_burn_settings(uint8_t addr, uint16_t timeout_ms, gs_gssb_istage_burn_settings_t * settings);

/**
   Set istage burn settings count.

   @see gs_gssb_istage_burn_settings_t

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] settings Burn settings (sets only switch_polarity and reboot_deploy_cnt).
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_set_burn_settings_cnt(uint8_t addr, uint16_t timeout_ms, gs_gssb_istage_burn_settings_t * settings);

/**
   Reset istage burn count.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_reset_burn_cnt(uint8_t addr, uint16_t timeout_ms);

/**
   Set istage arm auto mode.

   Arms or disarms the interstage for autodeploy.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] data CMD (0x04 = ARMED FOR AUTO, 0x08 = DISARMED).
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_set_arm(uint8_t addr, uint16_t timeout_ms, uint8_t data);

/**
   Set istage arm manual mode.

   Arms or disarms the interstage for manual deploy.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] data CMD (0x01 = ARMED FOR MANUAL, 0x00 = DISARMED).
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_set_state(uint8_t addr, uint16_t timeout_ms, uint8_t data);

/**
   Unlock istage settings

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_settings_unlock(uint8_t addr, uint16_t timeout_ms);

/**
   Lock istage settings

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_istage_settings_lock(uint8_t addr, uint16_t timeout_ms);

#ifdef __cplusplus
}
#endif
#endif
