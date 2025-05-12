/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/sensor_fss.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_sensor_fss_table[] = {
    {.name = "addr",          .addr = GS_ADCS_SENSOR_FSS_ADDR,                           .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "csp_node",      .addr = GS_ADCS_SENSOR_FSS_CSP_NODE,                       .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "p",             .addr = GS_ADCS_SENSOR_FSS_P(0),                           .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = 0},
    {.name = "q",             .addr = GS_ADCS_SENSOR_FSS_Q(0),                           .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = 0},
    {.name = "Cvalid",        .addr = GS_ADCS_SENSOR_FSS_CVALID,                         .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "Ctheta0",       .addr = GS_ADCS_SENSOR_FSS_CTHETA0(0),                     .type = GS_PARAM_FLOAT,   .size =   4, .array_size = 27, .flags = 0},
    {.name = "Ctheta1",       .addr = GS_ADCS_SENSOR_FSS_CTHETA1(0),                     .type = GS_PARAM_FLOAT,   .size =   4, .array_size = 27, .flags = 0},
    {.name = "Ctheta2",       .addr = GS_ADCS_SENSOR_FSS_CTHETA2(0),                     .type = GS_PARAM_FLOAT,   .size =   4, .array_size = 27, .flags = 0},
    {.name = "Cphi0",         .addr = GS_ADCS_SENSOR_FSS_CPHI0(0),                       .type = GS_PARAM_FLOAT,   .size =   4, .array_size = 27, .flags = 0},
    {.name = "Cphi1",         .addr = GS_ADCS_SENSOR_FSS_CPHI1(0),                       .type = GS_PARAM_FLOAT,   .size =   4, .array_size = 27, .flags = 0},
    {.name = "Cphi2",         .addr = GS_ADCS_SENSOR_FSS_CPHI2(0),                       .type = GS_PARAM_FLOAT,   .size =   4, .array_size = 27, .flags = 0},
};

const gs_adcs_sensor_fss_memory_t gs_adcs_sensor_fss_default_values GS_PGM_OBJECT = {
    .addr = 0,
    .csp_node = 0,
    .p = {0.0, 0.0, 0.0, 0.0},
    .q = {0.0, 0.0, 0.0, 1.0},
    .Cvalid = 0,
};

