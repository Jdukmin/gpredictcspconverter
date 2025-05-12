/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/sensor_startracker.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_sensor_startracker_table[] = {
    {.name = "str_uart",      .addr = GS_ADCS_SENSOR_STARTRACKER_STR_UART,               .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "en_str",        .addr = GS_ADCS_SENSOR_STARTRACKER_EN_STR,                 .type = GS_PARAM_BOOL,    .size =   1, .array_size =  1, .flags = 0},
    {.name = "str_q",         .addr = GS_ADCS_SENSOR_STARTRACKER_STR_Q(0),               .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = 0},
};

const gs_adcs_sensor_startracker_memory_t gs_adcs_sensor_startracker_default_values GS_PGM_OBJECT = {
    .str_uart = 0,
    .en_str = false,
    .str_q = {0.0, 0.0, 0.0, 1.0},
};

