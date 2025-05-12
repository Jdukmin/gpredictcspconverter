/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/act_magnetorquer.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_act_magnetorquer_table[] = {
    {.name = "am",            .addr = GS_ADCS_ACT_MAGNETORQUER_AM(0),                    .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "axis",          .addr = GS_ADCS_ACT_MAGNETORQUER_AXIS(0),                  .type = GS_PARAM_UINT8,   .size =   1, .array_size =  3, .flags = 0},
    {.name = "sign",          .addr = GS_ADCS_ACT_MAGNETORQUER_SIGN(0),                  .type = GS_PARAM_INT8,    .size =   1, .array_size =  3, .flags = 0},
    {.name = "max",           .addr = GS_ADCS_ACT_MAGNETORQUER_MAX(0),                   .type = GS_PARAM_UINT8,   .size =   1, .array_size =  3, .flags = 0},
    {.name = "_filler_end",   .addr = GS_ADCS_ACT_MAGNETORQUER__FILLER_END,              .type = GS_PARAM_DATA,    .size =   3, .array_size =  1, .flags = 0},
};

const gs_adcs_act_magnetorquer_memory_t gs_adcs_act_magnetorquer_default_values GS_PGM_OBJECT = {
    .am = {0.18, 0.18, 0.18},
    .axis = {0, 1, 2},
    .sign = {1, 1, 1},
    .max = {100, 100, 100},
};

