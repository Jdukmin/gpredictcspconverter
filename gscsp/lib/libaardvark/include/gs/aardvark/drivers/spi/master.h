#ifndef _GS_AARDVARK_LINUX_DRIVERS_AARDVARK_SPI_MASTER_H_
#define _GS_AARDVARK_LINUX_DRIVERS_AARDVARK_SPI_MASTER_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Aardvark SPI driver.

   Plugs into the framework provided by libutil: gs/util/drivers/spi/spi.h.
*/

#include <gs/util/drivers/spi/master.h>
#include <gs/util/linux/drivers/spi/spi.h>

/**
   Aardvark master slave configuration
 */
typedef struct {
    /**
       Unique id from aardvark dongle
     */
    uint32_t unique_id;
    /**
       Common master slave configuration
     */
    gs_spi_master_slave_config_t common;
} gs_spi_aardvark_master_slave_config_t;

/**
   Aardvark SPI master driver data.
*/
typedef struct {
    /**
       Aardvark SPI slave handle.
    */
    uint8_t handle;
} gs_aardvark_spi_master_driver_data_t;

/**
   SPI master driver interface.
*/
extern const gs_spi_master_driver_t gs_aardvark_spi_master_driver;

/**
   Get default configuration

   @param[out] config Default configuration
 */
void gs_spi_aardvark_master_slave_default_config(gs_spi_aardvark_master_slave_config_t * config);

/**
   Configure a slave

   @param[in]  config slave configuration
   @param[out] return_handle aardvark handle @see gs_aardvark_spi_master_driver_data_t
   @return_gs_error_t
 */
gs_error_t gs_spi_aardvark_master_configure_slave(const gs_spi_aardvark_master_slave_config_t * config, uint8_t * return_handle);

/**
   Get unique ID

   @param[in]  slave slave, to which the ID is coupled
   @param[out] unique_id returned ID
   @return_gs_error_t
 */
gs_error_t gs_spi_aardvark_master_get_unique_id(uint8_t slave, uint32_t * unique_id);

#endif
