#ifndef GS_EPS_PARAM_P31U_TM_H
#define GS_EPS_PARAM_P31U_TM_H

/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_EPS_P31U_TM_VBOOST(idx)                                  (    0 + ( 2 * idx))  // 0x0000 uint16
#define GS_EPS_P31U_TM_VBOOST_ARRAY_SIZE                                 3
#define GS_EPS_P31U_TM_VBATT                                             6                // 0x0006 uint16
#define GS_EPS_P31U_TM_CUROUT(idx)                                  (    8 + ( 2 * idx))  // 0x0008 uint16
#define GS_EPS_P31U_TM_CUROUT_ARRAY_SIZE                                 6
#define GS_EPS_P31U_TM_CURIN(idx)                                   (   20 + ( 2 * idx))  // 0x0014 uint16
#define GS_EPS_P31U_TM_CURIN_ARRAY_SIZE                                  3
#define GS_EPS_P31U_TM_CURSUN                                           26                // 0x001a uint16
#define GS_EPS_P31U_TM_CURSYS                                           28                // 0x001c uint16
#define GS_EPS_P31U_TM_TEMP(idx)                                    (   30 + ( 2 * idx))  // 0x001e int16
#define GS_EPS_P31U_TM_TEMP_ARRAY_SIZE                                   6
#define GS_EPS_P31U_TM_OUT_VAL(idx)                                 (   42 + ( 1 * idx))  // 0x002a uint8
#define GS_EPS_P31U_TM_OUT_VAL_ARRAY_SIZE                                8
#define GS_EPS_P31U_TM_BATTMODE                                         50                // 0x0032 uint8
#define GS_EPS_P31U_TM_PPTMODE                                          51                // 0x0033 uint8
#define GS_EPS_P31U_TM_WDTI2CS                                          52                // 0x0034 uint32
#define GS_EPS_P31U_TM_WDTGNDS                                          56                // 0x0038 uint32
#define GS_EPS_P31U_TM_BOOTCOUNT                                        60                // 0x003c uint32
#define GS_EPS_P31U_TM_CNTWDTI2C                                        64                // 0x0040 uint32
#define GS_EPS_P31U_TM_CNTWDTGND                                        68                // 0x0044 uint32
#define GS_EPS_P31U_TM_CNTWDTCSP(idx)                               (   72 + ( 4 * idx))  // 0x0048 uint32
#define GS_EPS_P31U_TM_CNTWDTCSP_ARRAY_SIZE                              2
#define GS_EPS_P31U_TM_WDTCSPC(idx)                                 (   80 + ( 4 * idx))  // 0x0050 uint32
#define GS_EPS_P31U_TM_WDTCSPC_ARRAY_SIZE                                2
#define GS_EPS_P31U_TM_LATCHUPS(idx)                                (   88 + ( 2 * idx))  // 0x0058 uint16
#define GS_EPS_P31U_TM_LATCHUPS_ARRAY_SIZE                               6
#define GS_EPS_P31U_TM_BOOTCAUSE                                       100                // 0x0064 uint8

#ifndef __cplusplus
static const gs_param_table_row_t gs_eps_p31u_tm_table[] = {
    {.name = "vboost",        .addr = GS_EPS_P31U_TM_VBOOST(0),                          .type = GS_PARAM_UINT16,  .size =   2, .array_size =  3, .flags = 0},
    {.name = "vbatt",         .addr = GS_EPS_P31U_TM_VBATT,                              .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "curout",        .addr = GS_EPS_P31U_TM_CUROUT(0),                          .type = GS_PARAM_UINT16,  .size =   2, .array_size =  6, .flags = 0},
    {.name = "curin",         .addr = GS_EPS_P31U_TM_CURIN(0),                           .type = GS_PARAM_UINT16,  .size =   2, .array_size =  3, .flags = 0},
    {.name = "cursun",        .addr = GS_EPS_P31U_TM_CURSUN,                             .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "cursys",        .addr = GS_EPS_P31U_TM_CURSYS,                             .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "temp",          .addr = GS_EPS_P31U_TM_TEMP(0),                            .type = GS_PARAM_INT16,   .size =   2, .array_size =  6, .flags = 0},
    {.name = "out_val",       .addr = GS_EPS_P31U_TM_OUT_VAL(0),                         .type = GS_PARAM_UINT8,   .size =   1, .array_size =  8, .flags = 0},
    {.name = "battmode",      .addr = GS_EPS_P31U_TM_BATTMODE,                           .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "pptmode",       .addr = GS_EPS_P31U_TM_PPTMODE,                            .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "wdtI2cS",       .addr = GS_EPS_P31U_TM_WDTI2CS,                            .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "wdtGndS",       .addr = GS_EPS_P31U_TM_WDTGNDS,                            .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "bootcount",     .addr = GS_EPS_P31U_TM_BOOTCOUNT,                          .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "cntWdtI2c",     .addr = GS_EPS_P31U_TM_CNTWDTI2C,                          .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "cntWdtGnd",     .addr = GS_EPS_P31U_TM_CNTWDTGND,                          .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "cntWdtCsp",     .addr = GS_EPS_P31U_TM_CNTWDTCSP(0),                       .type = GS_PARAM_UINT32,  .size =   4, .array_size =  2, .flags = 0},
    {.name = "wdtCspC",       .addr = GS_EPS_P31U_TM_WDTCSPC(0),                         .type = GS_PARAM_UINT32,  .size =   4, .array_size =  2, .flags = 0},
    {.name = "latchups",      .addr = GS_EPS_P31U_TM_LATCHUPS(0),                        .type = GS_PARAM_UINT16,  .size =   2, .array_size =  6, .flags = 0},
    {.name = "bootcause",     .addr = GS_EPS_P31U_TM_BOOTCAUSE,                          .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
};
#endif

#define GS_EPS_P31U_TM_TABLE_NAME                        "p31u_tm"
#define GS_EPS_P31U_TM_TABLE_SIZE                        101 // bytes
#define GS_EPS_P31U_TM_TABLE_ROWS                        (sizeof(gs_eps_p31u_tm_table) / sizeof(gs_eps_p31u_tm_table[0]))

#ifdef __cplusplus
}
#endif
#endif
