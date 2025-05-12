#ifndef _GS_GSSB_MSP_H_
#define _GS_GSSB_MSP_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   API for the board type NanoPower GSSB MSP (msp)
*/

#include <gs/gssb/gssb_dev.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Get msp internal MCU temperature.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] temp_out Temperature.
   @return_gs_error_t
*/
gs_error_t gs_gssb_msp_get_internal_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp_out);

/**
   Get msp temperature.

   Gets the msp external temperature on solar panel.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] temp Temperature.
   @return_gs_error_t
*/
gs_error_t gs_gssb_msp_get_outside_temp(uint8_t addr, uint16_t timeout_ms, int16_t * temp);

/**
   Get msp sun voltage.

   Gets the msp measurement of the sun voltage.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] voltage Voltage.
   @return_gs_error_t
*/
gs_error_t gs_gssb_msp_get_sun_voltage(uint8_t addr, uint16_t timeout_ms, uint16_t * voltage);

#ifdef __cplusplus
}
#endif
#endif
