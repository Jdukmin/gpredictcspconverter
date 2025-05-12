/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_SOFT_PARAM_TELEM_H_
#define _GS_SOFT_PARAM_TELEM_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_SOFT_TELEM_CORETEMP                                           0                // 0x0000 int16
#define GS_SOFT_TELEM_SOFTADCTEMP                                        2                // 0x0002 int16
#define GS_SOFT_TELEM_FEMTEMP(idx)                                  (    4 + ( 2 * idx))  // 0x0004 int16
#define GS_SOFT_TELEM_FEMTEMP_ARRAY_SIZE                                 3
#define GS_SOFT_TELEM_FEMADCTEMP(idx)                               (   10 + ( 2 * idx))  // 0x000a int16
#define GS_SOFT_TELEM_FEMADCTEMP_ARRAY_SIZE                              3
#define GS_SOFT_TELEM_COREVCC                                           16                // 0x0010 uint16
#define GS_SOFT_TELEM_VCCAUX                                            18                // 0x0012 uint16
#define GS_SOFT_TELEM_VCCBRAM                                           20                // 0x0014 uint16
#define GS_SOFT_TELEM_VCCPINT                                           22                // 0x0016 uint16
#define GS_SOFT_TELEM_VCCPAUX                                           24                // 0x0018 uint16
#define GS_SOFT_TELEM_VCCODDR                                           26                // 0x001a uint16
#define GS_SOFT_TELEM_VREFP                                             28                // 0x001c uint16
#define GS_SOFT_TELEM_VREFN                                             30                // 0x001e uint16
#define GS_SOFT_TELEM_UNIXTIME                                          32                // 0x0020 uint64
#define GS_SOFT_TELEM_FEM1V3B(idx)                                  (   40 + ( 2 * idx))  // 0x0028 uint16
#define GS_SOFT_TELEM_FEM1V3B_ARRAY_SIZE                                 3
#define GS_SOFT_TELEM_FEM_LNA1_MA(idx)                              (   46 + ( 2 * idx))  // 0x002e uint16
#define GS_SOFT_TELEM_FEM_LNA1_MA_ARRAY_SIZE                             3
#define GS_SOFT_TELEM_FEM_LNA2_MA(idx)                              (   52 + ( 2 * idx))  // 0x0034 uint16
#define GS_SOFT_TELEM_FEM_LNA2_MA_ARRAY_SIZE                             3
#define GS_SOFT_TELEM_FEM1V3AMA(idx)                                (   58 + ( 2 * idx))  // 0x003a uint16
#define GS_SOFT_TELEM_FEM1V3AMA_ARRAY_SIZE                               3
#define GS_SOFT_TELEM_FEM1V8MA(idx)                                 (   64 + ( 2 * idx))  // 0x0040 uint16
#define GS_SOFT_TELEM_FEM1V8MA_ARRAY_SIZE                                3
#define GS_SOFT_TELEM_FEM1V3A(idx)                                  (   70 + ( 2 * idx))  // 0x0046 uint16
#define GS_SOFT_TELEM_FEM1V3A_ARRAY_SIZE                                 3
#define GS_SOFT_TELEM_FEM1V8(idx)                                   (   76 + ( 2 * idx))  // 0x004c uint16
#define GS_SOFT_TELEM_FEM1V8_ARRAY_SIZE                                  3
#define GS_SOFT_TELEM_FEM1V3BMA(idx)                                (   82 + ( 2 * idx))  // 0x0052 uint16
#define GS_SOFT_TELEM_FEM1V3BMA_ARRAY_SIZE                               3
#define GS_SOFT_TELEM_UPTIME                                            88                // 0x0058 uint32
#define GS_SOFT_TELEM_LOADS(idx)                                    (   92 + ( 4 * idx))  // 0x005c uint32
#define GS_SOFT_TELEM_LOADS_ARRAY_SIZE                                   3
#define GS_SOFT_TELEM_FREERAM                                          104                // 0x0068 uint32
#define GS_SOFT_TELEM_PROCS                                            108                // 0x006c uint16
#define GS_SOFT_TELEM_PS1V8MW                                          110                // 0x006e uint16
#define GS_SOFT_TELEM_PS1VMW                                           112                // 0x0070 uint16
#define GS_SOFT_TELEM_PS3V3MW                                          114                // 0x0072 uint16
#define GS_SOFT_TELEM_PL1V8MW                                          116                // 0x0074 uint16
#define GS_SOFT_TELEM_PL1VMW                                           118                // 0x0076 uint16
#define GS_SOFT_TELEM_RAM1V35MW                                        120                // 0x0078 uint16
#define GS_SOFT_TELEM_PL3V3MW                                          122                // 0x007a uint16
#define GS_SOFT_TELEM_BOOT_COUNT                                       124                // 0x007c uint32
#define GS_SOFT_TELEM_SOFTVIN7                                         128                // 0x0080 uint16

#ifndef __cplusplus
static const param_table_t gs_soft_telem_table[] = {
    {.name = "coretemp",      .addr = GS_SOFT_TELEM_CORETEMP,                            .type = PARAM_INT16,    .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "softadctemp",   .addr = GS_SOFT_TELEM_SOFTADCTEMP,                         .type = PARAM_INT16,    .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "femtemp",       .addr = GS_SOFT_TELEM_FEMTEMP(0),                          .type = PARAM_INT16,    .size =   2, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "femadctemp",    .addr = GS_SOFT_TELEM_FEMADCTEMP(0),                       .type = PARAM_INT16,    .size =   2, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "corevcc",       .addr = GS_SOFT_TELEM_COREVCC,                             .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "vccaux",        .addr = GS_SOFT_TELEM_VCCAUX,                              .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "vccbram",       .addr = GS_SOFT_TELEM_VCCBRAM,                             .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "vccpint",       .addr = GS_SOFT_TELEM_VCCPINT,                             .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "vccpaux",       .addr = GS_SOFT_TELEM_VCCPAUX,                             .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "vccoddr",       .addr = GS_SOFT_TELEM_VCCODDR,                             .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "vrefp",         .addr = GS_SOFT_TELEM_VREFP,                               .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "vrefn",         .addr = GS_SOFT_TELEM_VREFN,                               .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "unixtime",      .addr = GS_SOFT_TELEM_UNIXTIME,                            .type = PARAM_UINT64,   .size =   8, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "fem1v3b",       .addr = GS_SOFT_TELEM_FEM1V3B(0),                          .type = PARAM_UINT16,   .size =   2, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "fem-lna1-ma",   .addr = GS_SOFT_TELEM_FEM_LNA1_MA(0),                      .type = PARAM_UINT16,   .size =   2, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "fem-lna2-ma",   .addr = GS_SOFT_TELEM_FEM_LNA2_MA(0),                      .type = PARAM_UINT16,   .size =   2, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "fem1v3ama",     .addr = GS_SOFT_TELEM_FEM1V3AMA(0),                        .type = PARAM_UINT16,   .size =   2, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "fem1v8ma",      .addr = GS_SOFT_TELEM_FEM1V8MA(0),                         .type = PARAM_UINT16,   .size =   2, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "fem1v3a",       .addr = GS_SOFT_TELEM_FEM1V3A(0),                          .type = PARAM_UINT16,   .size =   2, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "fem1v8",        .addr = GS_SOFT_TELEM_FEM1V8(0),                           .type = PARAM_UINT16,   .size =   2, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "fem1v3bma",     .addr = GS_SOFT_TELEM_FEM1V3BMA(0),                        .type = PARAM_UINT16,   .size =   2, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "uptime",        .addr = GS_SOFT_TELEM_UPTIME,                              .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "loads",         .addr = GS_SOFT_TELEM_LOADS(0),                            .type = PARAM_UINT32,   .size =   4, .count = 3, .flags = PARAM_F_READONLY},
    {.name = "freeram",       .addr = GS_SOFT_TELEM_FREERAM,                             .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "procs",         .addr = GS_SOFT_TELEM_PROCS,                               .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "ps1v8mw",       .addr = GS_SOFT_TELEM_PS1V8MW,                             .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "ps1vmw",        .addr = GS_SOFT_TELEM_PS1VMW,                              .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "ps3v3mw",       .addr = GS_SOFT_TELEM_PS3V3MW,                             .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "pl1v8mw",       .addr = GS_SOFT_TELEM_PL1V8MW,                             .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "pl1vmw",        .addr = GS_SOFT_TELEM_PL1VMW,                              .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "ram1v35mw",     .addr = GS_SOFT_TELEM_RAM1V35MW,                           .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "pl3v3mw",       .addr = GS_SOFT_TELEM_PL3V3MW,                             .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
    {.name = "boot_count",    .addr = GS_SOFT_TELEM_BOOT_COUNT,                          .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = PARAM_F_READONLY | PARAM_F_PERSIST},
    {.name = "softvin7",      .addr = GS_SOFT_TELEM_SOFTVIN7,                            .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = PARAM_F_READONLY},
};
#endif

#define GS_SOFT_TELEM_TABLE_NAME                         "telem"
#define GS_SOFT_TELEM_TABLE_SIZE                         130 // bytes
#define GS_SOFT_TELEM_TABLE_ROWS                         (sizeof(gs_soft_telem_table) / sizeof(gs_soft_telem_table[0]))
#define GS_SOFT_TELEM_TABLE_MEM_ID                       4

#if GS_PARAM_SETTERS_GETTERS
#define GS_SOFT_TELEM_CORETEMP_SET(value) param_set_int16(GS_SOFT_TELEM_CORETEMP, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_CORETEMP_SET_NOCALLBACK(value) param_set_int16_nocallback(GS_SOFT_TELEM_CORETEMP, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_CORETEMP_GET() param_get_int16(GS_SOFT_TELEM_CORETEMP, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_SOFTADCTEMP_SET(value) param_set_int16(GS_SOFT_TELEM_SOFTADCTEMP, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_SOFTADCTEMP_SET_NOCALLBACK(value) param_set_int16_nocallback(GS_SOFT_TELEM_SOFTADCTEMP, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_SOFTADCTEMP_GET() param_get_int16(GS_SOFT_TELEM_SOFTADCTEMP, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FEMTEMP_SET(idx, value) param_set_int16(GS_SOFT_TELEM_FEMTEMP(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEMTEMP_SET_NOCALLBACK(idx, value) param_set_int16_nocallback(GS_SOFT_TELEM_FEMTEMP(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEMTEMP_GET(idx) param_get_int16(GS_SOFT_TELEM_FEMTEMP(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FEMADCTEMP_SET(idx, value) param_set_int16(GS_SOFT_TELEM_FEMADCTEMP(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEMADCTEMP_SET_NOCALLBACK(idx, value) param_set_int16_nocallback(GS_SOFT_TELEM_FEMADCTEMP(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEMADCTEMP_GET(idx) param_get_int16(GS_SOFT_TELEM_FEMADCTEMP(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_COREVCC_SET(value) param_set_uint16(GS_SOFT_TELEM_COREVCC, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_COREVCC_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_COREVCC, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_COREVCC_GET() param_get_uint16(GS_SOFT_TELEM_COREVCC, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_VCCAUX_SET(value) param_set_uint16(GS_SOFT_TELEM_VCCAUX, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VCCAUX_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_VCCAUX, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VCCAUX_GET() param_get_uint16(GS_SOFT_TELEM_VCCAUX, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_VCCBRAM_SET(value) param_set_uint16(GS_SOFT_TELEM_VCCBRAM, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VCCBRAM_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_VCCBRAM, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VCCBRAM_GET() param_get_uint16(GS_SOFT_TELEM_VCCBRAM, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_VCCPINT_SET(value) param_set_uint16(GS_SOFT_TELEM_VCCPINT, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VCCPINT_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_VCCPINT, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VCCPINT_GET() param_get_uint16(GS_SOFT_TELEM_VCCPINT, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_VCCPAUX_SET(value) param_set_uint16(GS_SOFT_TELEM_VCCPAUX, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VCCPAUX_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_VCCPAUX, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VCCPAUX_GET() param_get_uint16(GS_SOFT_TELEM_VCCPAUX, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_VCCODDR_SET(value) param_set_uint16(GS_SOFT_TELEM_VCCODDR, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VCCODDR_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_VCCODDR, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VCCODDR_GET() param_get_uint16(GS_SOFT_TELEM_VCCODDR, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_VREFP_SET(value) param_set_uint16(GS_SOFT_TELEM_VREFP, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VREFP_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_VREFP, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VREFP_GET() param_get_uint16(GS_SOFT_TELEM_VREFP, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_VREFN_SET(value) param_set_uint16(GS_SOFT_TELEM_VREFN, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VREFN_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_VREFN, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_VREFN_GET() param_get_uint16(GS_SOFT_TELEM_VREFN, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_UNIXTIME_SET(value) param_set_uint64(GS_SOFT_TELEM_UNIXTIME, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_UNIXTIME_SET_NOCALLBACK(value) param_set_uint64_nocallback(GS_SOFT_TELEM_UNIXTIME, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_UNIXTIME_GET() param_get_uint64(GS_SOFT_TELEM_UNIXTIME, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FEM1V3B_SET(idx, value) param_set_uint16(GS_SOFT_TELEM_FEM1V3B(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V3B_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_SOFT_TELEM_FEM1V3B(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V3B_GET(idx) param_get_uint16(GS_SOFT_TELEM_FEM1V3B(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FEM_LNA1_MA_SET(idx, value) param_set_uint16(GS_SOFT_TELEM_FEM_LNA1_MA(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM_LNA1_MA_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_SOFT_TELEM_FEM_LNA1_MA(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM_LNA1_MA_GET(idx) param_get_uint16(GS_SOFT_TELEM_FEM_LNA1_MA(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FEM_LNA2_MA_SET(idx, value) param_set_uint16(GS_SOFT_TELEM_FEM_LNA2_MA(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM_LNA2_MA_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_SOFT_TELEM_FEM_LNA2_MA(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM_LNA2_MA_GET(idx) param_get_uint16(GS_SOFT_TELEM_FEM_LNA2_MA(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FEM1V3AMA_SET(idx, value) param_set_uint16(GS_SOFT_TELEM_FEM1V3AMA(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V3AMA_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_SOFT_TELEM_FEM1V3AMA(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V3AMA_GET(idx) param_get_uint16(GS_SOFT_TELEM_FEM1V3AMA(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FEM1V8MA_SET(idx, value) param_set_uint16(GS_SOFT_TELEM_FEM1V8MA(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V8MA_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_SOFT_TELEM_FEM1V8MA(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V8MA_GET(idx) param_get_uint16(GS_SOFT_TELEM_FEM1V8MA(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FEM1V3A_SET(idx, value) param_set_uint16(GS_SOFT_TELEM_FEM1V3A(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V3A_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_SOFT_TELEM_FEM1V3A(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V3A_GET(idx) param_get_uint16(GS_SOFT_TELEM_FEM1V3A(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FEM1V8_SET(idx, value) param_set_uint16(GS_SOFT_TELEM_FEM1V8(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V8_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_SOFT_TELEM_FEM1V8(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V8_GET(idx) param_get_uint16(GS_SOFT_TELEM_FEM1V8(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FEM1V3BMA_SET(idx, value) param_set_uint16(GS_SOFT_TELEM_FEM1V3BMA(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V3BMA_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_SOFT_TELEM_FEM1V3BMA(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FEM1V3BMA_GET(idx) param_get_uint16(GS_SOFT_TELEM_FEM1V3BMA(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_UPTIME_SET(value) param_set_uint32(GS_SOFT_TELEM_UPTIME, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_UPTIME_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_TELEM_UPTIME, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_UPTIME_GET() param_get_uint32(GS_SOFT_TELEM_UPTIME, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_LOADS_SET(idx, value) param_set_uint32(GS_SOFT_TELEM_LOADS(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_LOADS_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_SOFT_TELEM_LOADS(idx), GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_LOADS_GET(idx) param_get_uint32(GS_SOFT_TELEM_LOADS(idx), GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_FREERAM_SET(value) param_set_uint32(GS_SOFT_TELEM_FREERAM, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FREERAM_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_TELEM_FREERAM, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_FREERAM_GET() param_get_uint32(GS_SOFT_TELEM_FREERAM, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_PROCS_SET(value) param_set_uint16(GS_SOFT_TELEM_PROCS, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PROCS_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_PROCS, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PROCS_GET() param_get_uint16(GS_SOFT_TELEM_PROCS, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_PS1V8MW_SET(value) param_set_uint16(GS_SOFT_TELEM_PS1V8MW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PS1V8MW_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_PS1V8MW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PS1V8MW_GET() param_get_uint16(GS_SOFT_TELEM_PS1V8MW, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_PS1VMW_SET(value) param_set_uint16(GS_SOFT_TELEM_PS1VMW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PS1VMW_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_PS1VMW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PS1VMW_GET() param_get_uint16(GS_SOFT_TELEM_PS1VMW, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_PS3V3MW_SET(value) param_set_uint16(GS_SOFT_TELEM_PS3V3MW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PS3V3MW_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_PS3V3MW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PS3V3MW_GET() param_get_uint16(GS_SOFT_TELEM_PS3V3MW, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_PL1V8MW_SET(value) param_set_uint16(GS_SOFT_TELEM_PL1V8MW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PL1V8MW_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_PL1V8MW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PL1V8MW_GET() param_get_uint16(GS_SOFT_TELEM_PL1V8MW, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_PL1VMW_SET(value) param_set_uint16(GS_SOFT_TELEM_PL1VMW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PL1VMW_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_PL1VMW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PL1VMW_GET() param_get_uint16(GS_SOFT_TELEM_PL1VMW, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_RAM1V35MW_SET(value) param_set_uint16(GS_SOFT_TELEM_RAM1V35MW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_RAM1V35MW_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_RAM1V35MW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_RAM1V35MW_GET() param_get_uint16(GS_SOFT_TELEM_RAM1V35MW, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_PL3V3MW_SET(value) param_set_uint16(GS_SOFT_TELEM_PL3V3MW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PL3V3MW_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_PL3V3MW, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_PL3V3MW_GET() param_get_uint16(GS_SOFT_TELEM_PL3V3MW, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_BOOT_COUNT_SET(value) param_set_uint32(GS_SOFT_TELEM_BOOT_COUNT, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_BOOT_COUNT_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_TELEM_BOOT_COUNT, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_BOOT_COUNT_GET() param_get_uint32(GS_SOFT_TELEM_BOOT_COUNT, GS_SOFT_TELEM_TABLE_MEM_ID)
#define GS_SOFT_TELEM_SOFTVIN7_SET(value) param_set_uint16(GS_SOFT_TELEM_SOFTVIN7, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_SOFTVIN7_SET_NOCALLBACK(value) param_set_uint16_nocallback(GS_SOFT_TELEM_SOFTVIN7, GS_SOFT_TELEM_TABLE_MEM_ID, value)
#define GS_SOFT_TELEM_SOFTVIN7_GET() param_get_uint16(GS_SOFT_TELEM_SOFTVIN7, GS_SOFT_TELEM_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_SOFT_PARAM_TELEM_H_ */
