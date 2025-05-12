/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/gnc_ctrl_spin.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_gnc_ctrl_spin_table[] = {
    {.name = "axis",          .addr = GS_ADCS_GNC_CTRL_SPIN_AXIS,                        .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "mw_smc",        .addr = GS_ADCS_GNC_CTRL_SPIN_MW_SMC(0),                   .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  3, .flags = 0},
    {.name = "dumpgain",      .addr = GS_ADCS_GNC_CTRL_SPIN_DUMPGAIN,                    .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "mt_gain",       .addr = GS_ADCS_GNC_CTRL_SPIN_MT_GAIN(0),                  .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  4, .flags = 0},
    {.name = "pd_ctrl",       .addr = GS_ADCS_GNC_CTRL_SPIN_PD_CTRL(0),                  .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  2, .flags = 0},
    {.name = "ref_mnt",       .addr = GS_ADCS_GNC_CTRL_SPIN_REF_MNT,                     .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "en_dtmbl",      .addr = GS_ADCS_GNC_CTRL_SPIN_EN_DTMBL,                    .type = GS_PARAM_BOOL,    .size =   1, .array_size =  1, .flags = 0},
    {.name = "en_reini",      .addr = GS_ADCS_GNC_CTRL_SPIN_EN_REINI,                    .type = GS_PARAM_BOOL,    .size =   1, .array_size =  1, .flags = 0},
    {.name = "mode_dly",      .addr = GS_ADCS_GNC_CTRL_SPIN_MODE_DLY,                    .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "eclipdly",      .addr = GS_ADCS_GNC_CTRL_SPIN_ECLIPDLY,                    .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "spin_dly",      .addr = GS_ADCS_GNC_CTRL_SPIN_SPIN_DLY,                    .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "err_dly",       .addr = GS_ADCS_GNC_CTRL_SPIN_ERR_DLY,                     .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "err_rate",      .addr = GS_ADCS_GNC_CTRL_SPIN_ERR_RATE,                    .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "err_att",       .addr = GS_ADCS_GNC_CTRL_SPIN_ERR_ATT,                     .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "max_ape",       .addr = GS_ADCS_GNC_CTRL_SPIN_MAX_APE,                     .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
};

const gs_adcs_gnc_ctrl_spin_memory_t gs_adcs_gnc_ctrl_spin_default_values GS_PGM_OBJECT = {
    .mw_smc = {0.5, 0.9, 5.0},
    .dumpgain = 0.05,
    .mt_gain = {10.0, 100.0, 10.0, 100.0},
    .ref_mnt = -0.00058,
    .en_dtmbl = true,
    .en_reini = true,
    .mode_dly = 100,
    .eclipdly = 100,
    .spin_dly = 1500,
    .err_dly = 1500,
    .err_rate = 0.005,
    .err_att = 0.95,
    .max_ape = 0.95,
};

