#ifndef _GS_GSSB_GSSB_DEV_H_
#define _GS_GSSB_GSSB_DEV_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Generic GSSB API.

   Functions work for every type of GSSB device.
*/

#include <gs/gssb/gssb.h>
#include <gs/util/error.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Scan I2C bus for GSSB devices.

   If a GSSB device is found at \a address, \a devices[address] contains 0.

   @param[in] start_addr I2C address to start at (included in scan).
   @param[in] stop_addr I2C address to stop at (included in scan).
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] devices User supplied array for returning results, indexed by address. Size must be at least \a stop_addr + 1.
*/
void gs_gssb_bus_scan(uint8_t start_addr, uint8_t stop_addr, uint16_t timeout_ms, int8_t * devices);

/**
   Software reset.

   Resets GSSB MCU from software.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_soft_reset(uint8_t addr, uint16_t timeout_ms);

/**
   Get software version. 

   Gets the 20 character long version tag from the device.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] rxbuff RX buffer.
   @param[in] len Len of buffer. Must be 20.
   @return_gs_error_t
*/
gs_error_t gs_gssb_get_version(uint8_t addr, uint16_t timeout_ms, uint8_t * rxbuff, uint8_t len);

/**
   Get UUID.

   Gets the 4 byte long UUID from the device.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] uuid UUID.
   @return_gs_error_t
*/
gs_error_t gs_gssb_get_uuid(uint8_t addr, uint16_t timeout_ms, uint32_t * uuid);

/**
   Get model.

   Gets the specific GSSB device type at this address.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @param[out] model Model type.
   @return_gs_error_t
*/
gs_error_t gs_gssb_get_model(uint8_t addr, uint16_t timeout_ms, gs_gssb_model_t * model);

/**
   Set I2C address.

   Gives a new I2C address to device.

   @param[in] addr I2C address (current).
   @param[in] timeout_ms Timeout in milliseconds.
   @param[in] new_addr New I2C address.
   @return_gs_error_t
*/
gs_error_t gs_gssb_set_i2c_addr(uint8_t addr, uint16_t timeout_ms, uint8_t new_addr);

/**
   Commit address.

   Stores the newly set address in non volatile memory.

   @param[in] addr I2C address.
   @param[in] timeout_ms Timeout in milliseconds.
   @return_gs_error_t
*/
gs_error_t gs_gssb_commit_i2c_addr(uint8_t addr, uint16_t timeout_ms);

#ifdef __cplusplus
}
#endif
#endif
