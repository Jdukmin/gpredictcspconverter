/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/sensor_a3200.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_sensor_a3200_table[] = {
    {.name = "mag_offset",    .addr = GS_ADCS_SENSOR_A3200_MAG_OFFSET(0),                .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "mag_scale",     .addr = GS_ADCS_SENSOR_A3200_MAG_SCALE(0),                 .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "mag_rotation",  .addr = GS_ADCS_SENSOR_A3200_MAG_ROTATION(0),              .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  9, .flags = 0},
    {.name = "mag_rot_t",     .addr = GS_ADCS_SENSOR_A3200_MAG_ROT_T(0),                 .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  9, .flags = 0},
    {.name = "mag_max",       .addr = GS_ADCS_SENSOR_A3200_MAG_MAX,                      .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "mag_axis",      .addr = GS_ADCS_SENSOR_A3200_MAG_AXIS(0),                  .type = GS_PARAM_UINT8,   .size =   1, .array_size =  3, .flags = 0},
    {.name = "mag_sign",      .addr = GS_ADCS_SENSOR_A3200_MAG_SIGN(0),                  .type = GS_PARAM_INT8,    .size =   1, .array_size =  3, .flags = 0},
    {.name = "mag_gain",      .addr = GS_ADCS_SENSOR_A3200_MAG_GAIN,                     .type = GS_PARAM_INT8,    .size =   1, .array_size =  1, .flags = 0},
    {.name = "mag_enable",    .addr = GS_ADCS_SENSOR_A3200_MAG_ENABLE(0),                .type = GS_PARAM_UINT8,   .size =   1, .array_size =  3, .flags = 0},
    {.name = "gyro_scale",    .addr = GS_ADCS_SENSOR_A3200_GYRO_SCALE(0),                .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "gyro_offset",   .addr = GS_ADCS_SENSOR_A3200_GYRO_OFFSET(0),               .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "gyro_temp",     .addr = GS_ADCS_SENSOR_A3200_GYRO_TEMP(0),                 .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "gyro_axis",     .addr = GS_ADCS_SENSOR_A3200_GYRO_AXIS(0),                 .type = GS_PARAM_UINT8,   .size =   1, .array_size =  3, .flags = 0},
    {.name = "gyro_sign",     .addr = GS_ADCS_SENSOR_A3200_GYRO_SIGN(0),                 .type = GS_PARAM_INT8,    .size =   1, .array_size =  3, .flags = 0},
    {.name = "gyro_enable",   .addr = GS_ADCS_SENSOR_A3200_GYRO_ENABLE(0),               .type = GS_PARAM_INT8,    .size =   1, .array_size =  3, .flags = 0},
    {.name = "_filler_end",   .addr = GS_ADCS_SENSOR_A3200__FILLER_END,                  .type = GS_PARAM_DATA,    .size =   3, .array_size =  1, .flags = 0},
};

const gs_adcs_sensor_a3200_memory_t gs_adcs_sensor_a3200_default_values GS_PGM_OBJECT = {
    .mag_offset = {0.0, 0.0, 0.0},
    .mag_scale = {1.0, 1.0, 1.0},
    .mag_rotation = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0},
    .mag_rot_t = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0},
    .mag_max = 600.0,
    .mag_axis = {0, 1, 2},
    .mag_sign = {1, 1, 1},
    .mag_gain = 1,
    .mag_enable = {1, 1, 1},
    .gyro_scale = {1.0, 1.0, 1.0},
    .gyro_offset = {0.0, 0.0, 0.0},
    .gyro_temp = {0.0, 0.0, 0.0},
    .gyro_axis = {0, 1, 2},
    .gyro_sign = {1, 1, 1},
    .gyro_enable = {1, 1, 1},
};

