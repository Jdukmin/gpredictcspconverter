#ifndef _GS_GSSB_SUN_H_
#define _GS_GSSB_SUN_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <gs/gssb/gssb_dev.h>
/**
   @file

   API for the board type NanoSense FSS (sun_sensor)
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
   Sample sun sensor.

   Makes the sunsensor sample measurements.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_sun_sample_sensor(uint8_t addr, uint16_t timeout_ms);

/**
   Read sun sensor.

   Reads the sunsensors four measurements (4 * uint16).

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] sun Pointer to array of four measurements.
   @return_gs_error_t
*/
gs_error_t gs_gssb_sun_read_sensor_samples(uint8_t addr, uint16_t timeout_ms, uint16_t *sun);

/**
   Sample sun sensor temp.

   Makes the sunsensor sample temperature.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_sun_sample_temp(uint8_t addr, uint16_t timeout_ms);

/**
   Get sun sensor temperature.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] temp Temperature.
   @return_gs_error_t
*/
gs_error_t gs_gssb_sun_get_temp(uint8_t addr, uint16_t timeout_ms, float * temp);

/**
   Set sun sensor configuration

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] conf New configuration.
   @return_gs_error_t
*/
gs_error_t gs_gssb_sun_sensor_conf(uint8_t addr, uint16_t timeout_ms, uint16_t conf);

/**
   Save sun sensor conf.

   Makes the sun sensors current configuration non volatile.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_sun_sensor_conf_save(uint8_t addr, uint16_t timeout_ms);

#ifdef __cplusplus
}
#endif
#endif
