/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/sensor_horizon.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_sensor_horizon_table[] = {
    {.name = "enable_task",   .addr = GS_ADCS_SENSOR_HORIZON_ENABLE_TASK,                .type = GS_PARAM_BOOL,    .size =   1, .array_size =  1, .flags = 0},
    {.name = "htpa_div",      .addr = GS_ADCS_SENSOR_HORIZON_HTPA_DIV,                   .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "addr",          .addr = GS_ADCS_SENSOR_HORIZON_ADDR(0),                    .type = GS_PARAM_UINT8,   .size =   1, .array_size =  4, .flags = 0},
    {.name = "addr_eeprom",   .addr = GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM(0),             .type = GS_PARAM_UINT8,   .size =   1, .array_size =  4, .flags = 0},
    {.name = "focal_len",     .addr = GS_ADCS_SENSOR_HORIZON_FOCAL_LEN(0),               .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = GS_PARAM_F_SHOW_SCIENTIFIC},
    {.name = "px_pitch",      .addr = GS_ADCS_SENSOR_HORIZON_PX_PITCH(0),                .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = GS_PARAM_F_SHOW_SCIENTIFIC},
    {.name = "px_size",       .addr = GS_ADCS_SENSOR_HORIZON_PX_SIZE(0),                 .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = GS_PARAM_F_SHOW_SCIENTIFIC},
    {.name = "dis_coeff",     .addr = GS_ADCS_SENSOR_HORIZON_DIS_COEFF(0),               .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  8, .flags = 0},
    {.name = "grad_thrs",     .addr = GS_ADCS_SENSOR_HORIZON_GRAD_THRS(0),               .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = 0},
    {.name = "enable",        .addr = GS_ADCS_SENSOR_HORIZON_ENABLE(0),                  .type = GS_PARAM_BOOL,    .size =   1, .array_size =  4, .flags = 0},
    {.name = "htpa0_q",       .addr = GS_ADCS_SENSOR_HORIZON_HTPA0_Q(0),                 .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = 0},
    {.name = "htpa1_q",       .addr = GS_ADCS_SENSOR_HORIZON_HTPA1_Q(0),                 .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = 0},
    {.name = "htpa2_q",       .addr = GS_ADCS_SENSOR_HORIZON_HTPA2_Q(0),                 .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = 0},
    {.name = "htpa3_q",       .addr = GS_ADCS_SENSOR_HORIZON_HTPA3_Q(0),                 .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = 0},
};

const gs_adcs_sensor_horizon_memory_t gs_adcs_sensor_horizon_default_values GS_PGM_OBJECT = {
    .enable_task = false,
    .htpa_div = 8,
    .addr = {0, 0, 0, 0},
    .addr_eeprom = {0, 0, 0, 0},
    .focal_len = {0.0021, 0.0021, 0.0021, 0.0021},
    .px_pitch = {9e-05, 9e-05, 9e-05, 9e-05},
    .px_size = {4.4e-05, 4.4e-05, 4.4e-05, 4.4e-05},
    .dis_coeff = {585.884, -0.2516, 585.884, -0.2516, 585.884, -0.2516, 585.884, -0.2516},
    .grad_thrs = {0.5, 0.5, 0.5, 0.5},
    .enable = {false, false, false, false},
    .htpa0_q = {0.0, 0.0, 0.0, 1.0},
    .htpa1_q = {0.0, 0.0, 0.0, 1.0},
    .htpa2_q = {0.0, 0.0, 0.0, 1.0},
    .htpa3_q = {0.0, 0.0, 0.0, 1.0},
};

