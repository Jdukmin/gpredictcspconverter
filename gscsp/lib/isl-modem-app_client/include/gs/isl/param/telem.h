/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_ISL_PARAM_TELEM_H_
#define _GS_ISL_PARAM_TELEM_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_ISL_TELEM_LAST_RSSI_DB(idx)                              (    0 + ( 4 * idx))  // 0x0000 float
#define GS_ISL_TELEM_LAST_RSSI_DB_ARRAY_SIZE                             2
#define GS_ISL_TELEM_LAST_RFERR_HZ(idx)                             (    8 + ( 4 * idx))  // 0x0008 int32
#define GS_ISL_TELEM_LAST_RFERR_HZ_ARRAY_SIZE                            2
#define GS_ISL_TELEM_LOCK_SOF(idx)                                  (   16 + ( 1 * idx))  // 0x0010 bool
#define GS_ISL_TELEM_LOCK_SOF_ARRAY_SIZE                                 2
#define GS_ISL_TELEM_LOCK_VITERBI(idx)                              (   18 + ( 1 * idx))  // 0x0012 bool
#define GS_ISL_TELEM_LOCK_VITERBI_ARRAY_SIZE                             2
#define GS_ISL_TELEM_LOCK_CARRIER(idx)                              (   20 + ( 1 * idx))  // 0x0014 bool
#define GS_ISL_TELEM_LOCK_CARRIER_ARRAY_SIZE                             2
#define GS_ISL_TELEM_SIGNAL_PRSNT(idx)                              (   22 + ( 1 * idx))  // 0x0016 bool
#define GS_ISL_TELEM_SIGNAL_PRSNT_ARRAY_SIZE                             2
#define GS_ISL_TELEM_ANT_STATUS(idx)                                (   24 + ( 4 * idx))  // 0x0018 uint32
#define GS_ISL_TELEM_ANT_STATUS_ARRAY_SIZE                               4
#define GS_ISL_TELEM_ANT_UPTIME(idx)                                (   40 + ( 4 * idx))  // 0x0028 uint32
#define GS_ISL_TELEM_ANT_UPTIME_ARRAY_SIZE                               4
#define GS_ISL_TELEM_ANT_TEMP_EXT(idx)                              (   56 + ( 2 * idx))  // 0x0038 int16
#define GS_ISL_TELEM_ANT_TEMP_EXT_ARRAY_SIZE                             4
#define GS_ISL_TELEM_ANT_TEMP_INT(idx)                              (   64 + ( 2 * idx))  // 0x0040 int16
#define GS_ISL_TELEM_ANT_TEMP_INT_ARRAY_SIZE                             4
#define GS_ISL_TELEM_ANT_IBOARD(idx)                                (   72 + ( 2 * idx))  // 0x0048 int16
#define GS_ISL_TELEM_ANT_IBOARD_ARRAY_SIZE                               4
#define GS_ISL_TELEM_ANT_VCURR(idx)                                 (   80 + ( 2 * idx))  // 0x0050 uint16
#define GS_ISL_TELEM_ANT_VCURR_ARRAY_SIZE                                4
#define GS_ISL_TELEM_ANT_VDETI(idx)                                 (   88 + ( 2 * idx))  // 0x0058 uint16
#define GS_ISL_TELEM_ANT_VDETI_ARRAY_SIZE                                4
#define GS_ISL_TELEM_ANT_VDETA(idx)                                 (   96 + ( 2 * idx))  // 0x0060 uint16
#define GS_ISL_TELEM_ANT_VDETA_ARRAY_SIZE                                4
#define GS_ISL_TELEM_ANT_VDETB(idx)                                 (  104 + ( 2 * idx))  // 0x0068 uint16
#define GS_ISL_TELEM_ANT_VDETB_ARRAY_SIZE                                4
#define GS_ISL_TELEM_TDD_STATE(idx)                                 (  112 + ( 1 * idx))  // 0x0070 int8
#define GS_ISL_TELEM_TDD_STATE_ARRAY_SIZE                                2
#define GS_ISL_TELEM_RX_CNT(idx)                                    (  116 + ( 4 * idx))  // 0x0074 uint32
#define GS_ISL_TELEM_RX_CNT_ARRAY_SIZE                                   2
#define GS_ISL_TELEM_TX_CNT(idx)                                    (  124 + ( 4 * idx))  // 0x007c uint32
#define GS_ISL_TELEM_TX_CNT_ARRAY_SIZE                                   2
#define GS_ISL_TELEM_RS_CORR(idx)                                   (  132 + ( 2 * idx))  // 0x0084 uint16
#define GS_ISL_TELEM_RS_CORR_ARRAY_SIZE                                  2
#define GS_ISL_TELEM_RS_FAIL(idx)                                   (  136 + ( 2 * idx))  // 0x0088 uint16
#define GS_ISL_TELEM_RS_FAIL_ARRAY_SIZE                                  2

#ifndef __cplusplus
static const param_table_t gs_isl_telem_table[] = {
    {.name = "last-rssi-dB",  .addr = GS_ISL_TELEM_LAST_RSSI_DB(0),                      .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = PARAM_F_READONLY},
    {.name = "last-rferr-hz", .addr = GS_ISL_TELEM_LAST_RFERR_HZ(0),                     .type = PARAM_INT32,    .size =   4, .count = 2, .flags = PARAM_F_READONLY},
    {.name = "lock-sof",      .addr = GS_ISL_TELEM_LOCK_SOF(0),                          .type = PARAM_BOOL,     .size =   1, .count = 2, .flags = PARAM_F_READONLY},
    {.name = "lock-viterbi",  .addr = GS_ISL_TELEM_LOCK_VITERBI(0),                      .type = PARAM_BOOL,     .size =   1, .count = 2, .flags = PARAM_F_READONLY},
    {.name = "lock-carrier",  .addr = GS_ISL_TELEM_LOCK_CARRIER(0),                      .type = PARAM_BOOL,     .size =   1, .count = 2, .flags = PARAM_F_READONLY},
    {.name = "signal-prsnt",  .addr = GS_ISL_TELEM_SIGNAL_PRSNT(0),                      .type = PARAM_BOOL,     .size =   1, .count = 2, .flags = PARAM_F_READONLY},
    {.name = "ant-status",    .addr = GS_ISL_TELEM_ANT_STATUS(0),                        .type = PARAM_UINT32,   .size =   4, .count = 4, .flags = PARAM_F_READONLY},
    {.name = "ant-uptime",    .addr = GS_ISL_TELEM_ANT_UPTIME(0),                        .type = PARAM_UINT32,   .size =   4, .count = 4, .flags = PARAM_F_READONLY},
    {.name = "ant-temp-ext",  .addr = GS_ISL_TELEM_ANT_TEMP_EXT(0),                      .type = PARAM_INT16,    .size =   2, .count = 4, .flags = PARAM_F_READONLY},
    {.name = "ant-temp-int",  .addr = GS_ISL_TELEM_ANT_TEMP_INT(0),                      .type = PARAM_INT16,    .size =   2, .count = 4, .flags = PARAM_F_READONLY},
    {.name = "ant-iboard",    .addr = GS_ISL_TELEM_ANT_IBOARD(0),                        .type = PARAM_INT16,    .size =   2, .count = 4, .flags = PARAM_F_READONLY},
    {.name = "ant-vcurr",     .addr = GS_ISL_TELEM_ANT_VCURR(0),                         .type = PARAM_UINT16,   .size =   2, .count = 4, .flags = PARAM_F_READONLY},
    {.name = "ant-vdeti",     .addr = GS_ISL_TELEM_ANT_VDETI(0),                         .type = PARAM_UINT16,   .size =   2, .count = 4, .flags = PARAM_F_READONLY},
    {.name = "ant-vdeta",     .addr = GS_ISL_TELEM_ANT_VDETA(0),                         .type = PARAM_UINT16,   .size =   2, .count = 4, .flags = PARAM_F_READONLY},
    {.name = "ant-vdetb",     .addr = GS_ISL_TELEM_ANT_VDETB(0),                         .type = PARAM_UINT16,   .size =   2, .count = 4, .flags = PARAM_F_READONLY},
    {.name = "tdd-state",     .addr = GS_ISL_TELEM_TDD_STATE(0),                         .type = PARAM_INT8,     .size =   1, .count = 2, .flags = PARAM_F_READONLY},
    {.name = "rx-cnt",        .addr = GS_ISL_TELEM_RX_CNT(0),                            .type = PARAM_UINT32,   .size =   4, .count = 2, .flags = PARAM_F_READONLY},
    {.name = "tx-cnt",        .addr = GS_ISL_TELEM_TX_CNT(0),                            .type = PARAM_UINT32,   .size =   4, .count = 2, .flags = PARAM_F_READONLY},
    {.name = "rs-corr",       .addr = GS_ISL_TELEM_RS_CORR(0),                           .type = PARAM_UINT16,   .size =   2, .count = 2, .flags = PARAM_F_READONLY},
    {.name = "rs-fail",       .addr = GS_ISL_TELEM_RS_FAIL(0),                           .type = PARAM_UINT16,   .size =   2, .count = 2, .flags = PARAM_F_READONLY},
};
#endif

#define GS_ISL_TELEM_TABLE_NAME                          "telem"
#define GS_ISL_TELEM_TABLE_SIZE                          140 // bytes
#define GS_ISL_TELEM_TABLE_ROWS                          (sizeof(gs_isl_telem_table) / sizeof(gs_isl_telem_table[0]))
#define GS_ISL_TELEM_TABLE_MEM_ID                        4

#if GS_PARAM_SETTERS_GETTERS
#define GS_ISL_TELEM_LAST_RSSI_DB_SET(idx, value) param_set_float(GS_ISL_TELEM_LAST_RSSI_DB(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_LAST_RSSI_DB_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_TELEM_LAST_RSSI_DB(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_LAST_RSSI_DB_GET(idx) param_get_float(GS_ISL_TELEM_LAST_RSSI_DB(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_LAST_RFERR_HZ_SET(idx, value) param_set_int32(GS_ISL_TELEM_LAST_RFERR_HZ(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_LAST_RFERR_HZ_SET_NOCALLBACK(idx, value) param_set_int32_nocallback(GS_ISL_TELEM_LAST_RFERR_HZ(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_LAST_RFERR_HZ_GET(idx) param_get_int32(GS_ISL_TELEM_LAST_RFERR_HZ(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_LOCK_SOF_SET(idx, value) param_set_bool(GS_ISL_TELEM_LOCK_SOF(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_LOCK_SOF_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_TELEM_LOCK_SOF(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_LOCK_SOF_GET(idx) param_get_bool(GS_ISL_TELEM_LOCK_SOF(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_LOCK_VITERBI_SET(idx, value) param_set_bool(GS_ISL_TELEM_LOCK_VITERBI(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_LOCK_VITERBI_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_TELEM_LOCK_VITERBI(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_LOCK_VITERBI_GET(idx) param_get_bool(GS_ISL_TELEM_LOCK_VITERBI(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_LOCK_CARRIER_SET(idx, value) param_set_bool(GS_ISL_TELEM_LOCK_CARRIER(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_LOCK_CARRIER_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_TELEM_LOCK_CARRIER(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_LOCK_CARRIER_GET(idx) param_get_bool(GS_ISL_TELEM_LOCK_CARRIER(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_SIGNAL_PRSNT_SET(idx, value) param_set_bool(GS_ISL_TELEM_SIGNAL_PRSNT(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_SIGNAL_PRSNT_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_TELEM_SIGNAL_PRSNT(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_SIGNAL_PRSNT_GET(idx) param_get_bool(GS_ISL_TELEM_SIGNAL_PRSNT(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_ANT_STATUS_SET(idx, value) param_set_uint32(GS_ISL_TELEM_ANT_STATUS(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_STATUS_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_TELEM_ANT_STATUS(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_STATUS_GET(idx) param_get_uint32(GS_ISL_TELEM_ANT_STATUS(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_ANT_UPTIME_SET(idx, value) param_set_uint32(GS_ISL_TELEM_ANT_UPTIME(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_UPTIME_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_TELEM_ANT_UPTIME(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_UPTIME_GET(idx) param_get_uint32(GS_ISL_TELEM_ANT_UPTIME(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_ANT_TEMP_EXT_SET(idx, value) param_set_int16(GS_ISL_TELEM_ANT_TEMP_EXT(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_TEMP_EXT_SET_NOCALLBACK(idx, value) param_set_int16_nocallback(GS_ISL_TELEM_ANT_TEMP_EXT(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_TEMP_EXT_GET(idx) param_get_int16(GS_ISL_TELEM_ANT_TEMP_EXT(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_ANT_TEMP_INT_SET(idx, value) param_set_int16(GS_ISL_TELEM_ANT_TEMP_INT(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_TEMP_INT_SET_NOCALLBACK(idx, value) param_set_int16_nocallback(GS_ISL_TELEM_ANT_TEMP_INT(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_TEMP_INT_GET(idx) param_get_int16(GS_ISL_TELEM_ANT_TEMP_INT(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_ANT_IBOARD_SET(idx, value) param_set_int16(GS_ISL_TELEM_ANT_IBOARD(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_IBOARD_SET_NOCALLBACK(idx, value) param_set_int16_nocallback(GS_ISL_TELEM_ANT_IBOARD(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_IBOARD_GET(idx) param_get_int16(GS_ISL_TELEM_ANT_IBOARD(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_ANT_VCURR_SET(idx, value) param_set_uint16(GS_ISL_TELEM_ANT_VCURR(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_VCURR_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_TELEM_ANT_VCURR(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_VCURR_GET(idx) param_get_uint16(GS_ISL_TELEM_ANT_VCURR(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_ANT_VDETI_SET(idx, value) param_set_uint16(GS_ISL_TELEM_ANT_VDETI(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_VDETI_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_TELEM_ANT_VDETI(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_VDETI_GET(idx) param_get_uint16(GS_ISL_TELEM_ANT_VDETI(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_ANT_VDETA_SET(idx, value) param_set_uint16(GS_ISL_TELEM_ANT_VDETA(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_VDETA_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_TELEM_ANT_VDETA(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_VDETA_GET(idx) param_get_uint16(GS_ISL_TELEM_ANT_VDETA(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_ANT_VDETB_SET(idx, value) param_set_uint16(GS_ISL_TELEM_ANT_VDETB(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_VDETB_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_TELEM_ANT_VDETB(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_ANT_VDETB_GET(idx) param_get_uint16(GS_ISL_TELEM_ANT_VDETB(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_TDD_STATE_SET(idx, value) param_set_int8(GS_ISL_TELEM_TDD_STATE(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_TDD_STATE_SET_NOCALLBACK(idx, value) param_set_int8_nocallback(GS_ISL_TELEM_TDD_STATE(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_TDD_STATE_GET(idx) param_get_int8(GS_ISL_TELEM_TDD_STATE(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_RX_CNT_SET(idx, value) param_set_uint32(GS_ISL_TELEM_RX_CNT(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_RX_CNT_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_TELEM_RX_CNT(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_RX_CNT_GET(idx) param_get_uint32(GS_ISL_TELEM_RX_CNT(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_TX_CNT_SET(idx, value) param_set_uint32(GS_ISL_TELEM_TX_CNT(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_TX_CNT_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_TELEM_TX_CNT(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_TX_CNT_GET(idx) param_get_uint32(GS_ISL_TELEM_TX_CNT(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_RS_CORR_SET(idx, value) param_set_uint16(GS_ISL_TELEM_RS_CORR(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_RS_CORR_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_TELEM_RS_CORR(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_RS_CORR_GET(idx) param_get_uint16(GS_ISL_TELEM_RS_CORR(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#define GS_ISL_TELEM_RS_FAIL_SET(idx, value) param_set_uint16(GS_ISL_TELEM_RS_FAIL(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_RS_FAIL_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_TELEM_RS_FAIL(idx), GS_ISL_TELEM_TABLE_MEM_ID, value)
#define GS_ISL_TELEM_RS_FAIL_GET(idx) param_get_uint16(GS_ISL_TELEM_RS_FAIL(idx), GS_ISL_TELEM_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_ISL_PARAM_TELEM_H_ */
