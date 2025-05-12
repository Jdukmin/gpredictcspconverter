/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/sensor_css.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_sensor_css_table[] = {
    {.name = "scale",         .addr = GS_ADCS_SENSOR_CSS_SCALE(0),                       .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  6, .flags = 0},
    {.name = "addr",          .addr = GS_ADCS_SENSOR_CSS_ADDR(0),                        .type = GS_PARAM_UINT8,   .size =   1, .array_size =  6, .flags = 0},
    {.name = "enable",        .addr = GS_ADCS_SENSOR_CSS_ENABLE(0),                      .type = GS_PARAM_UINT8,   .size =   1, .array_size =  6, .flags = 0},
    {.name = "type",          .addr = GS_ADCS_SENSOR_CSS_TYPE(0),                        .type = GS_PARAM_UINT8,   .size =   1, .array_size =  6, .flags = 0},
    {.name = "max_init",      .addr = GS_ADCS_SENSOR_CSS_MAX_INIT,                       .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "abs_max",       .addr = GS_ADCS_SENSOR_CSS_ABS_MAX,                        .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "threshold",     .addr = GS_ADCS_SENSOR_CSS_THRESHOLD,                      .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
};

const gs_adcs_sensor_css_memory_t gs_adcs_sensor_css_default_values GS_PGM_OBJECT = {
    .scale = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0},
    .addr = {0, 0, 0, 0, 0, 0},
    .enable = {1, 1, 1, 1, 1, 1},
    .type = {0, 0, 0, 0, 0, 0},
    .max_init = 500.0,
    .abs_max = 700.0,
    .threshold = 100.0,
};

