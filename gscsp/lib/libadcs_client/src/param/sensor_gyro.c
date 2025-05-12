/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/sensor_gyro.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_sensor_gyro_table[] = {
    {.name = "scale",         .addr = GS_ADCS_SENSOR_GYRO_SCALE(0),                      .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "offset",        .addr = GS_ADCS_SENSOR_GYRO_OFFSET(0),                     .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "temp",          .addr = GS_ADCS_SENSOR_GYRO_TEMP(0),                       .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "axis",          .addr = GS_ADCS_SENSOR_GYRO_AXIS(0),                       .type = GS_PARAM_UINT8,   .size =   1, .array_size =  3, .flags = 0},
    {.name = "sign",          .addr = GS_ADCS_SENSOR_GYRO_SIGN(0),                       .type = GS_PARAM_INT8,    .size =   1, .array_size =  3, .flags = 0},
    {.name = "pwr_node",      .addr = GS_ADCS_SENSOR_GYRO_PWR_NODE,                      .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "pwr_chan",      .addr = GS_ADCS_SENSOR_GYRO_PWR_CHAN,                      .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "enable",        .addr = GS_ADCS_SENSOR_GYRO_ENABLE,                        .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "_filler_end",   .addr = GS_ADCS_SENSOR_GYRO__FILLER_END,                   .type = GS_PARAM_DATA,    .size =   3, .array_size =  1, .flags = 0},
};

const gs_adcs_sensor_gyro_memory_t gs_adcs_sensor_gyro_default_values GS_PGM_OBJECT = {
    .scale = {1.0, 1.0, 1.0},
    .offset = {0.0, 0.0, 0.0},
    .temp = {0.0, 0.0, 0.0},
    .axis = {0, 1, 2},
    .sign = {1, 1, 1},
    .pwr_node = 0,
    .pwr_chan = 0,
    .enable = 0,
};

