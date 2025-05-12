/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#include <gs/util/drivers/spi/slave.h>

gs_error_t gs_aardvark_spi_slave_start(uint8_t channel)
{
    return GS_ERROR_NOT_SUPPORTED;
}

gs_error_t gs_aardvark_spi_slave_set_rx(uint8_t channel, gs_spi_slave_receive_t rx)
{
    return GS_OK;
}

gs_error_t gs_aardvark_spi_slave_set_response(uint8_t channel, size_t offset, const uint8_t * tx, size_t size)
{
    return GS_ERROR_NOT_SUPPORTED;
}
