/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/act_rw.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_act_rw_table[] = {
    {.name = "max_speed",     .addr = GS_ADCS_ACT_RW_MAX_SPEED,                          .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "max_torque",    .addr = GS_ADCS_ACT_RW_MAX_TORQUE,                         .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = GS_PARAM_F_SHOW_SCIENTIFIC},
    {.name = "inertia",       .addr = GS_ADCS_ACT_RW_INERTIA,                            .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = GS_PARAM_F_SHOW_SCIENTIFIC},
    {.name = "inv_inertia",   .addr = GS_ADCS_ACT_RW_INV_INERTIA,                        .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = GS_PARAM_F_SHOW_SCIENTIFIC},
    {.name = "layout",        .addr = GS_ADCS_ACT_RW_LAYOUT(0),                          .type = GS_PARAM_FLOAT,   .size =   4, .array_size = 12, .flags = 0},
    {.name = "inv_layout",    .addr = GS_ADCS_ACT_RW_INV_LAYOUT(0),                      .type = GS_PARAM_FLOAT,   .size =   4, .array_size = 12, .flags = 0},
    {.name = "mw_override",   .addr = GS_ADCS_ACT_RW_MW_OVERRIDE,                        .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "_filler_end",   .addr = GS_ADCS_ACT_RW__FILLER_END,                        .type = GS_PARAM_DATA,    .size =   2, .array_size =  1, .flags = 0},
};

const gs_adcs_act_rw_memory_t gs_adcs_act_rw_default_values GS_PGM_OBJECT = {
    .max_speed = 6000.0,
    .max_torque = 0.0015,
    .inertia = 3e-05,
    .inv_inertia = 33333.0,
    .layout = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0},
    .inv_layout = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
    .mw_override = 0,
};

