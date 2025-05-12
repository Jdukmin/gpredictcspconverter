/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#include <gs/aardvark/drivers/spi/master.h>
#include <gs/aardvark/drivers/aardvark/gs_aardvark.h>
#include <gs/util/linux/drivers/spi/spi.h>
#include <gs/util/string.h>
#include <gs/util/check.h>

#include <alloca.h>

// change default log group
#define LOG_DEFAULT gs_spi_log

typedef struct {
    // true if handle is in use
    bool inuse;
    gs_spi_aardvark_master_slave_config_t config;
    gs_aardvark_handle_t handle;
} gs_spi_slave_t;

#define MAX_SPI_SLAVES   10
static gs_spi_slave_t spi_slaves[MAX_SPI_SLAVES];

static uint8_t gs_spi_alloc_slave(void)
{
    uint8_t handle_id;
    for (handle_id = 0; (handle_id < MAX_SPI_SLAVES) && (spi_slaves[handle_id].inuse == true); ++handle_id);

    if (handle_id < MAX_SPI_SLAVES) {
        gs_spi_slave_t * handle = &spi_slaves[handle_id];
        memset(handle, 0, sizeof(*handle));
        handle->inuse = true;
    }

    return handle_id;
}

static inline gs_spi_slave_t * gs_spi_slave(uint8_t slave)
{
    if ((slave < MAX_SPI_SLAVES) && spi_slaves[slave].inuse) {
        return &spi_slaves[slave];
    }
    return NULL;
}

static void gs_spi_close(gs_spi_slave_t * handle)
{
    if (handle->handle.handle > 0) {
        aa_close(handle->handle.handle);
        memset(&handle->handle, 0, sizeof(handle->handle));
    }

    // free instance - must be the last thing done, no lock needed
    handle->inuse = false;
}

void gs_spi_aardvark_master_slave_default_config(gs_spi_aardvark_master_slave_config_t * config)
{
    gs_log_group_register(LOG_DEFAULT);

    if (config) {
        memset(config, 0, sizeof(*config));
        config->common.data_order_msb = true;
        config->common.bps = GS_SPI_DEFAULT_BPS;
        config->common.mode = GS_SPI_MODE_CPOL0_CPHA0;
        config->common.bits = 8;
    }
}

gs_error_t gs_spi_aardvark_master_configure_slave(const gs_spi_aardvark_master_slave_config_t * config, uint8_t * return_handle)
{
    gs_log_group_register(LOG_DEFAULT);

    GS_CHECK_ARG(config != NULL);
    GS_CHECK_ARG(config->common.bps >= 1000);
    GS_CHECK_ARG(return_handle != NULL);

    if (config->common.bits != 8) {
        return GS_ERROR_NOT_SUPPORTED;
    }

    // allocate handle
    uint8_t handle_id = gs_spi_alloc_slave();
    if (handle_id >= MAX_SPI_SLAVES) {
        log_error("%s: no free handles", __FUNCTION__);
        return GS_ERROR_FULL;
    }
    gs_spi_slave_t * handle = &spi_slaves[handle_id];

    // open/find device
    gs_error_t error = gs_aardvark_open_device(config->unique_id, &handle->handle);
    if (error) {
        gs_spi_close(handle);
        return error;
    }

    handle->config = *config;

    // Ensure that the SPI subsystem is enabled
    int res = aa_configure(handle->handle.handle, AA_CONFIG_SPI_I2C);
    if (res < 0) {
        log_error("%s: aa_configure() failed, res: %d", __FUNCTION__, res);
        gs_spi_close(handle);
        return gs_aardvark_status_to_error(res);
    }

    // Enable the Aardvark adapter's power pins.
    // This command is only effective on v2.0 hardware or greater.
    // The power pins on the v1.02 hardware are not enabled by default.
    // aa_target_power(handle, AA_TARGET_POWER_BOTH);

    // Configure the SPI master
    res = aa_spi_configure(handle->handle.handle,
                           (config->common.mode & 0x2) ? AA_SPI_POL_FALLING_RISING : AA_SPI_POL_RISING_FALLING,
                           (config->common.mode & 0x1) ? AA_SPI_PHASE_SETUP_SAMPLE : AA_SPI_PHASE_SAMPLE_SETUP,
                           config->common.data_order_msb ? AA_SPI_BITORDER_MSB : AA_SPI_BITORDER_LSB);
    if (res < 0) {
        log_error("%s: aa_spi_configure() failed, res: %d", __FUNCTION__, res);
        gs_spi_close(handle);
        return gs_aardvark_status_to_error(res);
    }

    /**
     * Set the SPI bit rate in kilohertz.  If a zero is passed as the
     * bitrate, the bitrate is unchanged and the current bitrate is
     * returned.
     */
    res = aa_spi_bitrate(handle->handle.handle, config->common.bps / 1000);
    if (res < 0) {
        log_error("%s: aa_spi_bitrate() failed, res: %d", __FUNCTION__, res);
        gs_spi_close(handle);
        return gs_aardvark_status_to_error(res);
    }

    // ensure slave mode is disabled
    res = aa_spi_slave_disable (handle->handle.handle);
    if (res < 0) {
        log_error("%s: aa_spi_bitrate() failed, res: %d", __FUNCTION__, res);
        gs_spi_close(handle);
        return gs_aardvark_status_to_error(res);
    }

    *return_handle = handle_id;
    return GS_OK;
}

gs_error_t gs_spi_master_close_slave(uint8_t slave)
{
    gs_spi_slave_t * handle = gs_spi_slave(slave);
    if (handle) {
        gs_spi_close(handle);
    }
    return GS_OK;
}

gs_error_t gs_spi_aardvark_master_get_unique_id(uint8_t slave, uint32_t * unique_id)
{
    GS_CHECK_ARG(unique_id != NULL);

    gs_spi_slave_t * handle = gs_spi_slave(slave);
    if (handle == NULL) {
        return GS_ERROR_HANDLE;
    }

    *unique_id = handle->handle.unique_id;
    return GS_OK;
}

/**
   Perform transaction to/from a pre-configured SPI slave.
   Basically for i < size: send tx[i] and receive rx[i].
   @note: 8 bit SPI character size required!
   @param[in]  slave SPI slave (not used in this driver)
   @param[in]  tx tx buffer
   @param[out] rx rx buffer - can be NULL.
   @param[in]  size number of to send and also receive.
   @param[in]  timeout_ms timeout in milliseconds, primarily for locking the SPI channel.
   @param[in]  driver_data data to driver of the form gs_aardvark_spi_master_driver_data_t, which hold the slave handle.
   @return_gs_error_t
*/
static gs_error_t gs_aardvark_spi_master_transaction(uint8_t slave, const void * tx, void * rx, size_t size, int timeout_ms, void * driver_data)
{
    gs_spi_slave_t * handle = gs_spi_slave(((gs_aardvark_spi_master_driver_data_t *)driver_data)->handle);
    if (handle == NULL) {
        return GS_ERROR_HANDLE;
    }

    if (rx == NULL) {
        rx = alloca(size);
    }

    /* Write a stream of bytes to the downstream SPI slave device. */
    int res = aa_spi_write(handle->handle.handle, size, tx, size, rx);
    if (res < 0) {
        log_error("%s: aa_spi_write() failed, res: %d", __FUNCTION__, res);
        return gs_aardvark_status_to_error(res);
    }

    return GS_OK;
}


/**
   Perform N transaction to/from a pre-configured SPI slave within one chip selection
   @note: 8 bit SPI character size required!

   @see gs_spi_master_transactions_t

   @param[in] slave SPI slave (not used in this driver)
   @param[in] trans Pointer to transactions
   @param[in] count Number of transactions (rx and/or tx) to complete
   @param[in] timeout_ms timeout in milliseconds, primarily for locking the SPI channel.
   @param[in] timeout_ms timeout in milliseconds, primarily for locking the SPI channel.
   @param[in] driver_data data to driver of the form gs_aardvark_spi_master_driver_data_t, which hold the slave handle.
   @return_gs_error_t
*/
static gs_error_t gs_aardvark_spi_master_transactions(uint8_t slave, gs_spi_master_trans_t *trans, size_t count, int timeout_ms, void * driver_data)
{
    return gs_aardvark_spi_master_transaction(slave, trans->tx, trans->rx, trans->size, timeout_ms, driver_data);
}

const gs_spi_master_driver_t gs_aardvark_spi_master_driver = {
    .master_transactions_handler = gs_aardvark_spi_master_transactions,
};

