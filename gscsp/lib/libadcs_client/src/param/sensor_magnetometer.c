/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/sensor_magnetometer.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_sensor_magnetometer_table[] = {
    {.name = "offset",        .addr = GS_ADCS_SENSOR_MAGNETOMETER_OFFSET(0),             .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "scale",         .addr = GS_ADCS_SENSOR_MAGNETOMETER_SCALE(0),              .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "rotation",      .addr = GS_ADCS_SENSOR_MAGNETOMETER_ROTATION(0),           .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  9, .flags = 0},
    {.name = "rot_trans",     .addr = GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS(0),          .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  9, .flags = 0},
    {.name = "max",           .addr = GS_ADCS_SENSOR_MAGNETOMETER_MAX,                   .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "axis",          .addr = GS_ADCS_SENSOR_MAGNETOMETER_AXIS(0),               .type = GS_PARAM_UINT8,   .size =   1, .array_size =  3, .flags = 0},
    {.name = "sign",          .addr = GS_ADCS_SENSOR_MAGNETOMETER_SIGN(0),               .type = GS_PARAM_INT8,    .size =   1, .array_size =  3, .flags = 0},
    {.name = "enable",        .addr = GS_ADCS_SENSOR_MAGNETOMETER_ENABLE(0),             .type = GS_PARAM_UINT8,   .size =   1, .array_size =  3, .flags = 0},
    {.name = "gain",          .addr = GS_ADCS_SENSOR_MAGNETOMETER_GAIN,                  .type = GS_PARAM_INT8,    .size =   1, .array_size =  1, .flags = 0},
    {.name = "addr",          .addr = GS_ADCS_SENSOR_MAGNETOMETER_ADDR,                  .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "temp_addr",     .addr = GS_ADCS_SENSOR_MAGNETOMETER_TEMP_ADDR,             .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
};

const gs_adcs_sensor_magnetometer_memory_t gs_adcs_sensor_magnetometer_default_values GS_PGM_OBJECT = {
    .offset = {0.0, 0.0, 0.0},
    .scale = {1.0, 1.0, 1.0},
    .rotation = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0},
    .rot_trans = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0},
    .max = 600.0,
    .axis = {0, 1, 2},
    .sign = {1, 1, 1},
    .enable = {0, 0, 0},
    .gain = 1,
    .addr = 32,
    .temp_addr = 72,
};

