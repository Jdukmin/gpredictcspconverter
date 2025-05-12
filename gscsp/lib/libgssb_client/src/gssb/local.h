#ifndef LIB_LIBGSSB_CLIENT_SRC_GSSB_LOCAL_H_
#define LIB_LIBGSSB_CLIENT_SRC_GSSB_LOCAL_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Local functions
*/

#include <gs/util/error.h>

/**
   Calibrate temperature sensor.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] current Current through resistor.
   @param[in] resistor Resistor value.
   @return_error_t
 */
gs_error_t gs_gssb_msp_calibrate_outside_temp(uint8_t addr, uint16_t timeout_ms, uint16_t current, uint16_t resistor);


#endif /* LIB_LIBGSSB_CLIENT_SRC_GSSB_LOCAL_H_ */
