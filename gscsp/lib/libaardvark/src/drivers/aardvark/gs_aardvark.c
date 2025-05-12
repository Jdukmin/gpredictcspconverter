/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#include <gs/aardvark/drivers/aardvark/gs_aardvark.h>
#include <gs/util/check.h>

gs_error_t gs_aardvark_status_to_error(enum AardvarkStatus status)
{
    switch (status) {
        /* General codes (0 to -99) */
        case AA_OK: //                        =    0,
            return GS_OK;
        case AA_UNABLE_TO_LOAD_LIBRARY: //    =   -1,
        case AA_UNABLE_TO_LOAD_DRIVER: //     =   -2,
        case AA_UNABLE_TO_LOAD_FUNCTION: //  =   -3,
        case AA_INCOMPATIBLE_LIBRARY: //      =   -4,
            return GS_ERROR_ACCESS;
        case AA_INCOMPATIBLE_DEVICE: //       =   -5,
            return GS_ERROR_NOT_SUPPORTED;
        case AA_COMMUNICATION_ERROR: //       =   -6,
            return GS_ERROR_IO;
        case AA_UNABLE_TO_OPEN: //            =   -7,
            return GS_ERROR_ACCESS;
        case AA_UNABLE_TO_CLOSE: //           =   -8,
            return GS_ERROR_IO;
        case AA_INVALID_HANDLE: //            =   -9,
            return GS_ERROR_HANDLE;
        case AA_CONFIG_ERROR: //              =  -10,
            return GS_ERROR_TYPE;

            /* I2C codes (-100 to -199) */
        case AA_I2C_NOT_AVAILABLE: //         = -100,
            return GS_ERROR_NOT_SUPPORTED;
        case AA_I2C_NOT_ENABLED: //           = -101,
            return GS_ERROR_ACCESS;
        case AA_I2C_READ_ERROR: //            = -102,
        case AA_I2C_WRITE_ERROR: //           = -103,
            return GS_ERROR_IO;
        case AA_I2C_SLAVE_BAD_CONFIG: //      = -104,
            return GS_ERROR_TYPE;
        case AA_I2C_SLAVE_READ_ERROR: //      = -105,
            return GS_ERROR_IO;
        case AA_I2C_SLAVE_TIMEOUT: //         = -106,
            return GS_ERROR_TIMEOUT;
        case AA_I2C_DROPPED_EXCESS_BYTES: //  = -107,
            return GS_ERROR_RANGE;
        case AA_I2C_BUS_ALREADY_FREE: //      = -108,
            return GS_ERROR_AGAIN;

            /* SPI codes (-200 to -299) */
        case AA_SPI_NOT_AVAILABLE: //         = -200,
            return GS_ERROR_NOT_SUPPORTED;
        case AA_SPI_NOT_ENABLED: //           = -201,
            return GS_ERROR_ACCESS;
        case AA_SPI_WRITE_ERROR: //           = -202,
        case AA_SPI_SLAVE_READ_ERROR: //      = -203,
            return GS_ERROR_IO;
        case AA_SPI_SLAVE_TIMEOUT: //         = -204,
            return GS_ERROR_TIMEOUT;
        case AA_SPI_DROPPED_EXCESS_BYTES: //  = -205,
            return GS_ERROR_RANGE;

            /* GPIO codes (-400 to -499) */
        case AA_GPIO_NOT_AVAILABLE: //        = -400,
            return GS_ERROR_NOT_SUPPORTED;

            /* I2C bus monitor codes (-500 to -599) */
        case AA_I2C_MONITOR_NOT_AVAILABLE: //  = -500,
        case AA_I2C_MONITOR_NOT_ENABLED: //   = -501
            return GS_ERROR_NOT_SUPPORTED;
    }

    return GS_ERROR_NOT_IMPLEMENTED;
}

static gs_error_t gs_aardvark_find_port(uint32_t unique_id, gs_aardvark_handle_t * handle)
{
    // look up all devices (-> ports), need to find the unique id
    const int MAX_PORTS = 500;
    u16 ports[MAX_PORTS];
    u32 unique_ids[MAX_PORTS];
    int res = aa_find_devices_ext(MAX_PORTS, ports, MAX_PORTS, unique_ids);
    if (res < 0) {
        log_error("%s: aa_find_devices_ext() failed, res: %d", __FUNCTION__, res);
        return gs_aardvark_status_to_error(res);
    }

    bool busy = false;

    for (int i = 0; (i < MAX_PORTS) && (i < res); ++i) {

        const bool device_busy = (ports[i] & AA_PORT_NOT_FREE);
        busy |= device_busy;

        if (((unique_id == 0) && !device_busy) || // return any port
            (unique_id && (unique_id == unique_ids[i]))) { // return specific port

            if (device_busy) {
                return GS_ERROR_BUSY;
            }

            handle->port = ports[i];
            handle->unique_id = unique_ids[i];
            return GS_OK;
        }
    }

    if (busy) {
        return GS_ERROR_BUSY;
    }

    return GS_ERROR_NOT_FOUND;
}

gs_error_t gs_aardvark_list_devices(FILE * out)
{
    // look up all devices (-> ports), need to find the unique id
    const int MAX_PORTS = 500;
    u16 ports[MAX_PORTS];
    u32 unique_ids[MAX_PORTS];
    int res = aa_find_devices_ext(MAX_PORTS, ports, MAX_PORTS, unique_ids);
    if (res < 0) {
        log_error("%s: aa_find_devices_ext() failed, res: %d", __FUNCTION__, res);
        return gs_aardvark_status_to_error(res);
    }

    for (int i = 0; (i < MAX_PORTS) && (i < res); ++i) {
        const bool busy = (ports[i] & AA_PORT_NOT_FREE);
        //fprintf(out, "%u, port: %u, %s\n", unique_ids[i], ports[i], busy ? "BUSY" : "");
        fprintf(out, "%10u %s\n", unique_ids[i], busy ? "BUSY" : "");
    }

    return GS_OK;
}

gs_error_t gs_aardvark_open_device(uint32_t unique_id, gs_aardvark_handle_t * handle)
{
    GS_CHECK_ARG(handle != NULL);

    memset(handle, 0, sizeof(*handle));

    gs_error_t error = gs_aardvark_find_port(unique_id, handle);
    if (error) {
        return error;
    }

    Aardvark h = aa_open_ext(handle->port, &handle->aa_ext);
    if (h < 0) {
        log_error("%s: aa_open_ext() failed to open port: %d, res: %d", __FUNCTION__, handle->port, h);
        return gs_aardvark_status_to_error(h);
    }
    if (h == 0) {
        log_error("%s: aa_open_ext() failed to open port: %d, res: %d", __FUNCTION__, handle->port, h);
        return GS_ERROR_IO;
    }

    handle->handle = h;
    return GS_OK;
}
