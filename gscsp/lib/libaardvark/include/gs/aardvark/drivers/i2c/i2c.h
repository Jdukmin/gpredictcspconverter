#ifndef INCLUDE_GS_AARDVARK_DRIVERS_I2C_I2C_H_
#define INCLUDE_GS_AARDVARK_DRIVERS_I2C_I2C_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Aardvark I2C driver.

   Plugs into the framework provided by libutil: gs/util/drivers/i2c/i2c.h.
*/

#include <gs/util/drivers/i2c/master.h>
#include <gs/util/drivers/i2c/slave.h>
#include <gs/util/linux/drivers/i2c/i2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   I2C bus configuration
*/
typedef struct {
    /**
       Unique id for the adapter. Use 0 (zero) for any adapter.
    */
    uint32_t unique_id;
    /**
       Command I2C configuration.
    */
    gs_i2c_bus_config_t common;
    /**
       Max Transfer Unit (in bytes).
    */
    uint16_t mtu;
} gs_aardvark_i2c_bus_config_t;

/**
   Aardvark I2C driver data.
*/
typedef struct {
    /**
       Aardvark I2C handle.
    */
    uint8_t handle;
} gs_aardvark_i2c_driver_data_t;

/**
   I2C master driver interface.
*/
extern const gs_i2c_master_driver_t gs_aardvark_i2c_master_driver;

/**
   I2C slave driver interface
*/
extern const gs_i2c_slave_driver_t gs_aardvark_i2c_slave_driver;

/**
   Get default config.
   @param[out] config defult configuration.
*/
void gs_aardvark_i2c_get_default_config(gs_aardvark_i2c_bus_config_t * config);

/**
   Initialize Aardvark I2C.
   @param config Aardvark I2C configuration.
   @param return_handle Aardvark return handle @see gs_aardvark_i2c_driver_data_t.
   @return_gs_error_t
*/
gs_error_t gs_aardvark_i2c_init(const gs_aardvark_i2c_bus_config_t * config, uint8_t * return_handle);

/**
   Close Aardvark handle
   @param[in] handle Aardvark I2C handle
   @return_gs_error_t
*/
gs_error_t gs_aardvark_i2c_close(uint8_t handle);

#ifdef __cplusplus
}
#endif
#endif
