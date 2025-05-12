/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_ISL_PARAM_RADIO_TDD_H_
#define _GS_ISL_PARAM_RADIO_TDD_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_ISL_RADIO_TDD_TXTIME(idx)                                (    0 + ( 4 * idx))  // 0x0000 float
#define GS_ISL_RADIO_TDD_TXTIME_ARRAY_SIZE                               2
#define GS_ISL_RADIO_TDD_RXTIME(idx)                                (    8 + ( 4 * idx))  // 0x0008 float
#define GS_ISL_RADIO_TDD_RXTIME_ARRAY_SIZE                               2
#define GS_ISL_RADIO_TDD_TXGUARD(idx)                               (   16 + ( 4 * idx))  // 0x0010 float
#define GS_ISL_RADIO_TDD_TXGUARD_ARRAY_SIZE                              2
#define GS_ISL_RADIO_TDD_IFS(idx)                                   (   24 + ( 4 * idx))  // 0x0018 float
#define GS_ISL_RADIO_TDD_IFS_ARRAY_SIZE                                  2
#define GS_ISL_RADIO_TDD_VCODELAY(idx)                              (   32 + ( 4 * idx))  // 0x0020 float
#define GS_ISL_RADIO_TDD_VCODELAY_ARRAY_SIZE                             2
#define GS_ISL_RADIO_TDD_DPDELAY(idx)                               (   40 + ( 4 * idx))  // 0x0028 float
#define GS_ISL_RADIO_TDD_DPDELAY_ARRAY_SIZE                              2
#define GS_ISL_RADIO_TDD_TXDATADELAY(idx)                           (   48 + ( 4 * idx))  // 0x0030 float
#define GS_ISL_RADIO_TDD_TXDATADELAY_ARRAY_SIZE                          2
#define GS_ISL_RADIO_TDD_TXDATAHALT(idx)                            (   56 + ( 4 * idx))  // 0x0038 float
#define GS_ISL_RADIO_TDD_TXDATAHALT_ARRAY_SIZE                           2
#define GS_ISL_RADIO_TDD_SYNCDELAY(idx)                             (   64 + ( 4 * idx))  // 0x0040 float
#define GS_ISL_RADIO_TDD_SYNCDELAY_ARRAY_SIZE                            2
#define GS_ISL_RADIO_TDD_COMMIT(idx)                                (   72 + ( 1 * idx))  // 0x0048 uint8
#define GS_ISL_RADIO_TDD_COMMIT_ARRAY_SIZE                               2

#ifndef __cplusplus
static const param_table_t gs_isl_radio_tdd_table[] = {
    {.name = "txtime",        .addr = GS_ISL_RADIO_TDD_TXTIME(0),                        .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "rxtime",        .addr = GS_ISL_RADIO_TDD_RXTIME(0),                        .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "txguard",       .addr = GS_ISL_RADIO_TDD_TXGUARD(0),                       .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "ifs",           .addr = GS_ISL_RADIO_TDD_IFS(0),                           .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "vcodelay",      .addr = GS_ISL_RADIO_TDD_VCODELAY(0),                      .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "dpdelay",       .addr = GS_ISL_RADIO_TDD_DPDELAY(0),                       .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "txdatadelay",   .addr = GS_ISL_RADIO_TDD_TXDATADELAY(0),                   .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "txdatahalt",    .addr = GS_ISL_RADIO_TDD_TXDATAHALT(0),                    .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "syncdelay",     .addr = GS_ISL_RADIO_TDD_SYNCDELAY(0),                     .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "commit",        .addr = GS_ISL_RADIO_TDD_COMMIT(0),                        .type = PARAM_UINT8,    .size =   1, .count = 2, .flags = 0},
};
#endif

#define GS_ISL_RADIO_TDD_TABLE_NAME                      "radio-tdd"
#define GS_ISL_RADIO_TDD_TABLE_SIZE                      74 // bytes
#define GS_ISL_RADIO_TDD_TABLE_ROWS                      (sizeof(gs_isl_radio_tdd_table) / sizeof(gs_isl_radio_tdd_table[0]))
#define GS_ISL_RADIO_TDD_TABLE_MEM_ID                    8
#define GS_ISL_RADIO_TDD_TABLE_FILE_ID                   8

#if GS_PARAM_SETTERS_GETTERS
#define GS_ISL_RADIO_TDD_TXTIME_SET(idx, value) param_set_float(GS_ISL_RADIO_TDD_TXTIME(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_TXTIME_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_TDD_TXTIME(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_TXTIME_GET(idx) param_get_float(GS_ISL_RADIO_TDD_TXTIME(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID)
#define GS_ISL_RADIO_TDD_RXTIME_SET(idx, value) param_set_float(GS_ISL_RADIO_TDD_RXTIME(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_RXTIME_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_TDD_RXTIME(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_RXTIME_GET(idx) param_get_float(GS_ISL_RADIO_TDD_RXTIME(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID)
#define GS_ISL_RADIO_TDD_TXGUARD_SET(idx, value) param_set_float(GS_ISL_RADIO_TDD_TXGUARD(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_TXGUARD_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_TDD_TXGUARD(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_TXGUARD_GET(idx) param_get_float(GS_ISL_RADIO_TDD_TXGUARD(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID)
#define GS_ISL_RADIO_TDD_IFS_SET(idx, value) param_set_float(GS_ISL_RADIO_TDD_IFS(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_IFS_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_TDD_IFS(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_IFS_GET(idx) param_get_float(GS_ISL_RADIO_TDD_IFS(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID)
#define GS_ISL_RADIO_TDD_VCODELAY_SET(idx, value) param_set_float(GS_ISL_RADIO_TDD_VCODELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_VCODELAY_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_TDD_VCODELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_VCODELAY_GET(idx) param_get_float(GS_ISL_RADIO_TDD_VCODELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID)
#define GS_ISL_RADIO_TDD_DPDELAY_SET(idx, value) param_set_float(GS_ISL_RADIO_TDD_DPDELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_DPDELAY_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_TDD_DPDELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_DPDELAY_GET(idx) param_get_float(GS_ISL_RADIO_TDD_DPDELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID)
#define GS_ISL_RADIO_TDD_TXDATADELAY_SET(idx, value) param_set_float(GS_ISL_RADIO_TDD_TXDATADELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_TXDATADELAY_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_TDD_TXDATADELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_TXDATADELAY_GET(idx) param_get_float(GS_ISL_RADIO_TDD_TXDATADELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID)
#define GS_ISL_RADIO_TDD_TXDATAHALT_SET(idx, value) param_set_float(GS_ISL_RADIO_TDD_TXDATAHALT(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_TXDATAHALT_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_TDD_TXDATAHALT(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_TXDATAHALT_GET(idx) param_get_float(GS_ISL_RADIO_TDD_TXDATAHALT(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID)
#define GS_ISL_RADIO_TDD_SYNCDELAY_SET(idx, value) param_set_float(GS_ISL_RADIO_TDD_SYNCDELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_SYNCDELAY_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_TDD_SYNCDELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_SYNCDELAY_GET(idx) param_get_float(GS_ISL_RADIO_TDD_SYNCDELAY(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID)
#define GS_ISL_RADIO_TDD_COMMIT_SET(idx, value) param_set_uint8(GS_ISL_RADIO_TDD_COMMIT(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_COMMIT_SET_NOCALLBACK(idx, value) param_set_uint8_nocallback(GS_ISL_RADIO_TDD_COMMIT(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TDD_COMMIT_GET(idx) param_get_uint8(GS_ISL_RADIO_TDD_COMMIT(idx), GS_ISL_RADIO_TDD_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_ISL_PARAM_RADIO_TDD_H_ */
