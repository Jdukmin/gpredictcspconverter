/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#define GS_GSSB_INTERNAL_USE 1
#include <string.h>
#include <gs/util/thread.h>
#include <gs/util/time.h>
#include <gs/util/drivers/i2c/master.h>
#include <gs/gssb/gssb.h>
#include <gs/gssb/internal/gssb_cmd_id.h>
#include <conf_gssb.h>
#include <gs/gssb/internal/gssb_common.h>

gs_error_t gs_gssb_sun_sample_sensor(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[1] = { GSSB_CMD_SUN_SAMPLE_SUNSENSOR };
    uint8_t rx_buff[1];
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 1, &rx_buff[0], 1, timeout_ms);
    return res;
}

gs_error_t gs_gssb_sun_read_sensor_samples(uint8_t addr, uint16_t timeout_ms, uint16_t *sun)
{
    uint8_t tx_buff[1] = { GSSB_CMD_SUN_GET_SUNSENSOR_DATA };
    uint8_t rx_buff[8];
    int i, res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 1, rx_buff, 8, timeout_ms);
    for (i = 0; i <= 7; i += 2) {
        sun[i / 2] = (rx_buff[i] << 8) + rx_buff[i + 1];
    }

    return res;
}

gs_error_t gs_gssb_sun_sample_temp(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[1] = { GSSB_CMD_SUN_SAMPLE_TEMP };

    return gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, &tx_buff, 1, NULL, 0, timeout_ms);
}

gs_error_t gs_gssb_sun_get_temp(uint8_t addr, uint16_t timeout_ms, float * temp)
{
    uint8_t tx_buff[1] = { GSSB_CMD_SUN_GET_TEMP };
    uint8_t rx_buff[2];
    float res_temp;
    gs_error_t res;

    res = gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rx_buff, 2, timeout_ms);

    res_temp = (((int16_t) ((rx_buff[0] << 8) + rx_buff[1])) >> 2) * 0.03125;
    memcpy(temp, &res_temp, 4);

    return res;
}

gs_error_t gs_gssb_sun_sensor_conf(uint8_t addr, uint16_t timeout_ms, uint16_t conf)
{
    uint8_t tx_buff[4] = { GSSB_CMD_SUN_ADC_CONF };
    uint8_t rx_buff[1];

    tx_buff[1] = (conf >> 8);
    tx_buff[2] = (conf & 0xff);
    tx_buff[3] = 0;

    return gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 4, rx_buff, 1, timeout_ms);
}

gs_error_t gs_gssb_sun_sensor_conf_save(uint8_t addr, uint16_t timeout_ms)
{
    uint8_t tx_buff[1] = { GSSB_CMD_SUN_ADC_SAVE_CONF };
    uint8_t rx_buff[1];

    return gs_i2c_master_transaction(GSSB_TWI_HANDLER, addr, tx_buff, 1, rx_buff, 1, timeout_ms);
}
