/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <gs/aardvark/drivers/i2c/i2c.h>
#include <gs/util/linux/drivers/i2c/i2c.h>
#include <gs/aardvark/drivers/aardvark/gs_aardvark.h>
#include <gs/util/string.h>
#include <gs/util/check.h>
#include <gs/util/endian.h>
#include <gs/util/thread.h>
#include <gs/util/mutex.h>
#include <stdlib.h>

// Older libutil versions does not have this define (this causes a warning if not defined exactly the same as in libutil)
#define GS_I2C_DEFAULT_BPS_v2 400000

// change default log group
#define LOG_DEFAULT gs_i2c_log

typedef struct {
    //! Aardvark i2c_handle
    gs_aardvark_handle_t handle;
    //! Aardvark i2c_config
    gs_aardvark_i2c_bus_config_t config;
    //! Lock
    gs_mutex_t mutex;
    //! Bool true if active
    bool inuse;
    struct {
        //! Bool true if slave is running
        bool active;
        //! Device
        uint8_t device;
        //! Thread handle
        gs_thread_t thread;
        //! Slave/multimaster RX callback (can be null if only master mode is used)
        gs_i2c_slave_receive_t rx_callback;
        //! Slave/multimaster RX buffer get callback (can be null if only master mode is used)
        gs_i2c_slave_get_rx_buf_t get_rx_buf_callback;
        //! Slave/multimaster RX buffer
        uint8_t * rx_buffer;
        //! slave length of rx buffer
        size_t rx_length;
    } slave;
} gs_i2c_bus_t;

#define MAX_I2C_BUS   10
static gs_i2c_bus_t i2c_buses[MAX_I2C_BUS];

static inline gs_i2c_bus_t * gs_i2c_bus(uint8_t hdl)
{
    if (hdl < MAX_I2C_BUS) {
        if (i2c_buses[hdl].inuse) {
            return &i2c_buses[hdl];
        }
    }
    return NULL;
}

static inline gs_i2c_bus_t * gs_i2c_bus_by_driver_data(void * driver_data)
{
    if (driver_data) {
        return gs_i2c_bus(((gs_aardvark_i2c_driver_data_t*)driver_data)->handle);
    }
    return NULL;
}

static inline gs_error_t gs_aardvark_i2c_transfer(gs_i2c_bus_t * bus, uint8_t addr, const void * tx, size_t txlen,
                                                  void * rx, size_t rxlen)
{
    u16 bytes_written = 0;
    u16 bytes_read = 0;
    const bool tx_op = (tx && txlen);
    const bool rx_op = (rx && rxlen);
    const char * action;
    int res;
    if (tx_op && rx_op) {
        action = "aa_i2c_write_read()";
        res = aa_i2c_write_read(bus->handle.handle, addr, AA_I2C_NO_STOP, txlen, tx, &bytes_written, rxlen, rx, &bytes_read);
        aa_i2c_free_bus(bus->handle.handle);
    } else if (tx_op) {
        // tx only
        action = "aa_i2c_write_ext()";
        res = aa_i2c_write_ext (bus->handle.handle, addr, AA_I2C_NO_FLAGS, txlen, tx, &bytes_written);
    } else {
        // rx only
        action = "aa_i2c_read_ext()";
        res = aa_i2c_read_ext (bus->handle.handle, addr, AA_I2C_NO_FLAGS, rxlen, rx, &bytes_read);
    }

    gs_error_t return_val;
    if (res == 0) {
        // success
        return_val = GS_OK;
    } else if (res < 0) {
        log_error("%s: %s failed, res: %d", __FUNCTION__, action, res);
        return_val = gs_aardvark_status_to_error(res);
    } else {
        log_error("%s: %s failed, res: %d, write: %d, read: %d", __FUNCTION__, action, res, (res & 0xff), ((res >> 8) & 0xff));
        return_val = GS_ERROR_IO;
    }

    if (tx_op && (bytes_written != txlen)) {
        log_error("%s: %s send %d bytes instead of %lu", __FUNCTION__, action, bytes_written, txlen);
        if(return_val == GS_OK) {
            return_val = GS_ERROR_IO;
        }
    }

    if (rx_op && (bytes_read != rxlen)) {
        log_error("%s: %s received %d bytes instead of %lu", __FUNCTION__, action, bytes_read, rxlen);
        if(return_val == GS_OK) {
            return_val = GS_ERROR_IO;
        }
    }

    return return_val;
}

/**
   Perform transaction to I2C slave.
   @param[in]  device I2C bus (not used in this driver).
   @param[in]  addr slave address.
   @param[in]  tx transmit buffer.
   @param[in]  txlen number of bytes to transmit.
   @param[out] rx receive buffer - can be NULL.
   @param[in]  rxlen number of bytes to receive.
   @param[in]  timeout_ms timeout in milliseconds, primarily for locking the I2C channel.
   @param[in]  driver_data Aardvark handle @see gs_aardvark_i2c_driver_data_t.
   @return_gs_error_t
*/
static gs_error_t gs_aardvark_i2c_master_transaction(uint8_t device, uint8_t addr, const void * tx, size_t txlen, void * rx,
                                                     size_t rxlen, int timeout_ms, void * driver_data)
{
    gs_i2c_bus_t * bus = gs_i2c_bus_by_driver_data(driver_data);
    GS_CHECK_HANDLE(bus != NULL);

    gs_error_t res = gs_mutex_lock(bus->mutex);
    if (res == GS_OK) {
        res = gs_aardvark_i2c_transfer(bus, addr, tx, txlen, rx, rxlen);
        gs_mutex_unlock(bus->mutex);
    }
    return res;
}

static uint8_t gs_i2c_alloc_bus(void)
{
    uint8_t handle_id;
    for (handle_id = 0; (handle_id < MAX_I2C_BUS) && (i2c_buses[handle_id].inuse == true); ++handle_id);

    if (handle_id < MAX_I2C_BUS) {
        gs_i2c_bus_t * handle = &i2c_buses[handle_id];
        memset(handle, 0, sizeof(*handle));
        handle->inuse = true;
    }

    return handle_id;
}

static void gs_i2c_close(gs_i2c_bus_t * handle)
{
    handle->slave.active = false;
    if (handle->slave.thread) {
        gs_thread_join(handle->slave.thread, NULL);
    }

    if (handle->handle.handle > 0) {
        aa_close(handle->handle.handle);
        handle->handle.handle = 0;
    }

    if (handle->mutex) {
        gs_mutex_destroy(handle->mutex);
        handle->mutex = NULL;
    }

    // free instance - must be the last thing done, no lock needed
    handle->inuse = false;
}

gs_error_t gs_aardvark_i2c_init(const gs_aardvark_i2c_bus_config_t * config, uint8_t * return_handle)
{
    gs_log_group_register(LOG_DEFAULT);

    GS_CHECK_ARG(config != NULL);
    GS_CHECK_ARG(config->common.bps >= 100000);
    GS_CHECK_ARG(return_handle != NULL);

    if (config->common.mode != GS_I2C_MASTER) {
        GS_CHECK_ARG(config->common.addr >= 1 && config->common.addr <= 127);
    }

    if (config->common.addrbits != 7) {
        return GS_ERROR_NOT_SUPPORTED;
    }

    // allocate handle
    uint8_t handle_id = gs_i2c_alloc_bus();
    if (handle_id >= MAX_I2C_BUS) {
        log_error("%s: no free handles", __FUNCTION__);
        return GS_ERROR_FULL;
    }
    gs_i2c_bus_t * handle = &i2c_buses[handle_id];

    // open/find device
    gs_error_t error = gs_aardvark_open_device(config->unique_id, &handle->handle);
    if (error) {
        gs_i2c_close(handle);
        return error;
    }

    handle->config = *config;

    // Ensure that the I2C subsystem is enabled
    int res = aa_configure(handle->handle.handle, AA_CONFIG_SPI_I2C);
    if (res < 0) {
        log_error("%s: aa_configure() failed, res: %d", __FUNCTION__, res);
        gs_i2c_close(handle);
        return gs_aardvark_status_to_error(res);
    }

    // Enable the I2C bus pullup resistors (2.2k resistors).
    // This command is only effective on v2.0 hardware or greater.
    // The pullup resistors on the v1.02 hardware are enabled by default.
    res = aa_i2c_pullup(handle->handle.handle, AA_I2C_PULLUP_BOTH);
    if (res < 0) {
        log_error("%s: aa_i2c_pullup() failed, res: %d", __FUNCTION__, res);
        gs_i2c_close(handle);
        return gs_aardvark_status_to_error(res);
    }

    res = aa_i2c_bitrate(handle->handle.handle, config->common.bps / 1000);
    if (res < 0) {
        log_error("%s: aa_i2c_bitrate() failed, res: %d", __FUNCTION__, res);
        gs_i2c_close(handle);
        return gs_aardvark_status_to_error(res);
    }

    // ensure correct mode
    if (config->common.mode == GS_I2C_MULTI_MASTER || config->common.mode == GS_I2C_SLAVE) {
        res = aa_i2c_slave_enable(handle->handle.handle, config->common.addr, config->mtu, config->mtu);
        if (res < 0) {
            log_error("%s: aa_i2c_slave_enable() failed, res: %d", __FUNCTION__, res);
            gs_i2c_close(handle);
            return gs_aardvark_status_to_error(res);
        }

    } else {
        res = aa_i2c_slave_disable(handle->handle.handle);
        if (res < 0) {
            log_error("%s: aa_i2c_slave_disable() failed, res: %d", __FUNCTION__, res);
            gs_i2c_close(handle);
            return gs_aardvark_status_to_error(res);
        }
    }

    res = gs_mutex_create(&handle->mutex);
    if (res != GS_OK) {
        log_error("%s: gs_mutex_create() failed, res: %d", __FUNCTION__, res);
        gs_i2c_close(handle);
        return GS_ERROR_HANDLE;
    }

    log_debug("%s: handle: %u, address: %u, bps: %u, MTU: %u", __FUNCTION__, handle_id, config->common.addr, config->common.bps, config->mtu);

    *return_handle = handle_id;
    return GS_OK;
}

void gs_aardvark_i2c_get_default_config(gs_aardvark_i2c_bus_config_t * config)
{
    gs_log_group_register(LOG_DEFAULT);

    if (config) {
        memset(config, 0, sizeof(*config));

        config->common.data_order_msb = GS_I2C_DEFAULT_DATA_ORDER_MSB ? true : false;
        config->common.mode = GS_I2C_MULTI_MASTER;
        config->common.addr = 1;
        config->common.bps = GS_I2C_DEFAULT_BPS_v2;
        config->common.addrbits = GS_I2C_DEFAULT_ADDRESS_SIZE;

        config->mtu = 4096;
    }
}

gs_error_t gs_aardvark_i2c_close(uint8_t handle)
{
    gs_i2c_bus_t * bus = gs_i2c_bus(handle);
    if (bus) {
        gs_i2c_close(bus);
    }

    return GS_OK;
}

/**
   Set rx callback.

   @param[in] device I2C bus (not used in this driver).
   @param[in] rx Rx callback.
   @param[in] driver_data Aardvark handle @see gs_aardvark_i2c_driver_data_t.
   @return_gs_error_t
*/
static gs_error_t gs_aardvark_i2c_slave_set_rx(uint8_t device, gs_i2c_slave_receive_t rx, void * driver_data)
{
    gs_i2c_bus_t * bus = gs_i2c_bus_by_driver_data(driver_data);
    if (bus) {
        if ((bus->config.common.mode == GS_I2C_MULTI_MASTER) || (bus->config.common.mode == GS_I2C_SLAVE)){
            bus->slave.rx_callback = rx;
            return GS_OK;
        }
    }
    return GS_ERROR_HANDLE;
}

/**
   Set rx buffer get callback.

   @param[in] device I2C bus (not used in this driver).
   @param[in] get_rx_buf get rx buffer callback.
   @param[in] buf_length length of buffer retrieved with this callback.
   @param[in] driver_data Aardvark handle @see gs_aardvark_i2c_driver_data_t.
   @return_gs_error_t
*/
static gs_error_t gs_aardvark_i2c_slave_set_get_rx_buf(uint8_t device, gs_i2c_slave_get_rx_buf_t get_rx_buf, size_t buf_length, void * driver_data)
{
    gs_i2c_bus_t * bus = gs_i2c_bus_by_driver_data(driver_data);
    GS_CHECK_HANDLE(bus != NULL);

    if(buf_length <= bus->config.mtu) {
        if ((bus->config.common.mode == GS_I2C_MULTI_MASTER) || (bus->config.common.mode == GS_I2C_SLAVE)){
            bus->slave.get_rx_buf_callback = get_rx_buf;
            bus->slave.rx_length = buf_length;
            return GS_OK;
        } else {
            log_error("I2C device configured as master");
            return GS_ERROR_NOT_SUPPORTED;
        }
    }
    log_error("%s: requested buf length: %lu is larger than configured MTU: %u", __FUNCTION__, buf_length, bus->config.mtu);
    return GS_ERROR_RANGE;
}

/**
   Set response data.

   @param[in] device I2C bus (not used in this driver).
   @param[in] tx pointer to data.
   @param[in] size length of data.
   @param[in] driver_data Aardvark handle @see gs_aardvark_i2c_driver_data_t.
   @return_gs_error_t
*/
static gs_error_t gs_aardvark_i2c_slave_set_response(uint8_t device, const uint8_t * tx, size_t size, void * driver_data)
{
    GS_CHECK_RANGE(size <= 64);
    gs_i2c_bus_t * bus = gs_i2c_bus_by_driver_data(driver_data);
    if (bus && ((bus->config.common.mode == GS_I2C_MULTI_MASTER) || (bus->config.common.mode == GS_I2C_SLAVE))) {
        int res = aa_i2c_slave_set_response (bus->handle.handle, size, tx);
        if (res < 0) {
            return gs_aardvark_status_to_error(res);
        } else {
            return GS_OK;
        }
    }
    return GS_ERROR_HANDLE;
}

static gs_error_t gs_aardvark_i2c_poll(gs_i2c_bus_t * bus, int timeout)
{
    gs_error_t res = gs_mutex_lock(bus->mutex);
    if (res == GS_OK) {
        int poll_status = aa_async_poll(bus->handle.handle, timeout);
        if (poll_status == AA_ASYNC_I2C_WRITE) {
            log_debug("i2c slave wrote %i bytes", aa_i2c_slave_write_stats(bus->handle.handle));
        }
        if (poll_status != AA_ASYNC_I2C_READ) {
            gs_mutex_unlock(bus->mutex);
            return GS_ERROR_TIMEOUT;
        }
        gs_mutex_unlock(bus->mutex);
        return GS_OK;
    } else {
        return res;
    }
}

static gs_error_t gs_aardvark_i2c_multimaster_recieve(gs_i2c_bus_t * bus, size_t * rx_length)
{
    uint8_t addr = 0;
    gs_error_t res = gs_mutex_lock(bus->mutex);
    if (res == GS_OK) {
        int read = aa_i2c_slave_read(bus->handle.handle, &addr, bus->slave.rx_length, bus->slave.rx_buffer);
        if ((addr != bus->config.common.addr) || (read <= 0)) {
            gs_mutex_unlock(bus->mutex);
            return GS_ERROR_NO_DATA;
        }
        *rx_length = read;
        gs_mutex_unlock(bus->mutex);
        return GS_OK;
    } else {
        return res;
    }
}

static void i2c_slave_exit_handler(void)
{
    for (uint8_t handle = 0; handle < MAX_I2C_BUS; ++handle) {
        gs_i2c_bus_t * bus = &i2c_buses[handle];
        if (bus->inuse && bus->slave.active && bus->slave.thread) {
            bus->slave.active = false;
            pthread_cancel(bus->slave.thread);
            gs_thread_join(bus->slave.thread, NULL);
            bus->slave.thread = 0;
        }
    }
}

static void * i2c_slave_thread(void * parameter)
{
    gs_i2c_bus_t * bus = (gs_i2c_bus_t *) parameter;
    while (bus->slave.active) {
        if (GS_OK == gs_aardvark_i2c_poll(bus, 0)) {
            bus->slave.rx_buffer = bus->slave.get_rx_buf_callback(bus->slave.device);
            if (bus->slave.rx_buffer == NULL) {
                log_error("could not retrieve i2c rx buffer");
                continue;
            }
            size_t rx_length;
            gs_error_t res = gs_aardvark_i2c_multimaster_recieve(bus, &rx_length);
            if (res == GS_OK) {
                bus->slave.rx_callback(bus->slave.device, bus->slave.rx_buffer, rx_length, NULL);
            }
        }
    }
    return NULL;
}

/**
   Start/enable I2C bus reception.

   Reception should not automatically be enabled by their init() functions, as this will complicate adding additional layers/hooks.

   @param[in] device I2C bus (not used in this driver).
   @param[in] driver_data Aardvark handle @see gs_aardvark_i2c_driver_data_t.
   @return_gs_error_t
*/
static gs_error_t gs_aardvark_i2c_slave_start(uint8_t device, void * driver_data)
{
    gs_i2c_bus_t * bus = gs_i2c_bus_by_driver_data(driver_data);
    GS_CHECK_HANDLE(bus != NULL);
    GS_CHECK_HANDLE(bus->slave.get_rx_buf_callback != NULL);
    GS_CHECK_HANDLE(bus->slave.rx_callback != NULL);

    if (bus->slave.active) {
        return GS_ERROR_NOT_SUPPORTED;
    }
    bus->slave.active = true;
    bus->slave.device = device;

    static bool install_exit_handler;
    if (install_exit_handler == false) {
        atexit(i2c_slave_exit_handler);
        install_exit_handler = true;
    }

    return gs_thread_create("I2C_SLAVE_RX",
                            i2c_slave_thread,
                            bus,
                            0,
                            GS_THREAD_PRIORITY_NORMAL,
                            GS_THREAD_CREATE_JOINABLE,
                            &bus->slave.thread);
}

const gs_i2c_master_driver_t gs_aardvark_i2c_master_driver = {
    .master_transaction_handler = gs_aardvark_i2c_master_transaction,
};

const gs_i2c_slave_driver_t gs_aardvark_i2c_slave_driver = {
    .start_handler = gs_aardvark_i2c_slave_start,
    .set_rx_handler = gs_aardvark_i2c_slave_set_rx,
    .set_get_rx_buf_handler = gs_aardvark_i2c_slave_set_get_rx_buf,
    .set_response_handler = gs_aardvark_i2c_slave_set_response,
};
