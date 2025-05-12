/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_ISL_PARAM_ANTCALIB_H_
#define _GS_ISL_PARAM_ANTCALIB_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_ISL_ANTCALIB_START_CALIB                                      0                // 0x0000 int16
#define GS_ISL_ANTCALIB_GAIN_CURR                                        4                // 0x0004 float
#define GS_ISL_ANTCALIB_OFFS_CURR                                        8                // 0x0008 float
#define GS_ISL_ANTCALIB_NOM_DETI_25C                                    12                // 0x000c uint16
#define GS_ISL_ANTCALIB_GAIN_DETI_25C                                   16                // 0x0010 float
#define GS_ISL_ANTCALIB_OFFS_DETI_25C                                   20                // 0x0014 float
#define GS_ISL_ANTCALIB_TX_PLNOM(idx)                               (   24 + ( 4 * idx))  // 0x0018 float
#define GS_ISL_ANTCALIB_TX_PLNOM_ARRAY_SIZE                              3
#define GS_ISL_ANTCALIB_TX_FCOMP(idx)                               (   36 + ( 2 * idx))  // 0x0024 int16
#define GS_ISL_ANTCALIB_TX_FCOMP_ARRAY_SIZE                              7
#define GS_ISL_ANTCALIB_TX_TCL(idx)                                 (   50 + ( 2 * idx))  // 0x0032 int16
#define GS_ISL_ANTCALIB_TX_TCL_ARRAY_SIZE                                7
#define GS_ISL_ANTCALIB_TX_TCH(idx)                                 (   64 + ( 2 * idx))  // 0x0040 int16
#define GS_ISL_ANTCALIB_TX_TCH_ARRAY_SIZE                                7
#define GS_ISL_ANTCALIB_RX_FCOMP(idx)                               (   78 + ( 2 * idx))  // 0x004e int16
#define GS_ISL_ANTCALIB_RX_FCOMP_ARRAY_SIZE                              7
#define GS_ISL_ANTCALIB_RX_NOM_GAIN                                     92                // 0x005c float
#define GS_ISL_ANTCALIB_RX_TEMP_GAIN                                    96                // 0x0060 float

#ifndef __cplusplus
static const param_table_t gs_isl_antcalib_table[] = {
    {.name = "start_calib",   .addr = GS_ISL_ANTCALIB_START_CALIB,                       .type = PARAM_INT16,    .size =   2, .count = 1, .flags = 0},
    {.name = "gain_curr",     .addr = GS_ISL_ANTCALIB_GAIN_CURR,                         .type = PARAM_FLOAT,    .size =   4, .count = 1, .flags = 0},
    {.name = "offs_curr",     .addr = GS_ISL_ANTCALIB_OFFS_CURR,                         .type = PARAM_FLOAT,    .size =   4, .count = 1, .flags = 0},
    {.name = "nom_deti_25c",  .addr = GS_ISL_ANTCALIB_NOM_DETI_25C,                      .type = PARAM_UINT16,   .size =   2, .count = 1, .flags = 0},
    {.name = "gain_deti_25c", .addr = GS_ISL_ANTCALIB_GAIN_DETI_25C,                     .type = PARAM_FLOAT,    .size =   4, .count = 1, .flags = 0},
    {.name = "offs_deti_25c", .addr = GS_ISL_ANTCALIB_OFFS_DETI_25C,                     .type = PARAM_FLOAT,    .size =   4, .count = 1, .flags = 0},
    {.name = "tx_plnom",      .addr = GS_ISL_ANTCALIB_TX_PLNOM(0),                       .type = PARAM_FLOAT,    .size =   4, .count = 3, .flags = 0},
    {.name = "tx_fcomp",      .addr = GS_ISL_ANTCALIB_TX_FCOMP(0),                       .type = PARAM_INT16,    .size =   2, .count = 7, .flags = 0},
    {.name = "tx_tcl",        .addr = GS_ISL_ANTCALIB_TX_TCL(0),                         .type = PARAM_INT16,    .size =   2, .count = 7, .flags = 0},
    {.name = "tx_tch",        .addr = GS_ISL_ANTCALIB_TX_TCH(0),                         .type = PARAM_INT16,    .size =   2, .count = 7, .flags = 0},
    {.name = "rx_fcomp",      .addr = GS_ISL_ANTCALIB_RX_FCOMP(0),                       .type = PARAM_INT16,    .size =   2, .count = 7, .flags = 0},
    {.name = "rx_nom_gain",   .addr = GS_ISL_ANTCALIB_RX_NOM_GAIN,                       .type = PARAM_FLOAT,    .size =   4, .count = 1, .flags = 0},
    {.name = "rx_temp_gain",  .addr = GS_ISL_ANTCALIB_RX_TEMP_GAIN,                      .type = PARAM_FLOAT,    .size =   4, .count = 1, .flags = 0},
};
#endif

#define GS_ISL_ANTCALIB_TABLE_NAME                       "antcalib"
#define GS_ISL_ANTCALIB_TABLE_SIZE                       100 // bytes
#define GS_ISL_ANTCALIB_TABLE_ROWS                       (sizeof(gs_isl_antcalib_table) / sizeof(gs_isl_antcalib_table[0]))

#ifdef __cplusplus
}
#endif
#endif /*_GS_ISL_PARAM_ANTCALIB_H_ */
