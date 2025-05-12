/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_ISL_PARAM_RADIO_GENERAL_H_
#define _GS_ISL_PARAM_RADIO_GENERAL_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_ISL_RADIO_GENERAL_ANT_INTV(idx)                          (    0 + ( 2 * idx))  // 0x0000 uint16
#define GS_ISL_RADIO_GENERAL_ANT_INTV_ARRAY_SIZE                         4
#define GS_ISL_RADIO_GENERAL_DUPLEX_MODE(idx)                       (    8 + ( 1 * idx))  // 0x0008 uint8
#define GS_ISL_RADIO_GENERAL_DUPLEX_MODE_ARRAY_SIZE                      2
#define GS_ISL_RADIO_GENERAL_MODULATION(idx)                        (   10 + ( 8 * idx))  // 0x000a string
#define GS_ISL_RADIO_GENERAL_MODULATION_ARRAY_SIZE                       2
#define GS_ISL_RADIO_GENERAL_ANT_AUTO_DUP(idx)                      (   26 + ( 1 * idx))  // 0x001a bool
#define GS_ISL_RADIO_GENERAL_ANT_AUTO_DUP_ARRAY_SIZE                     4
#define GS_ISL_RADIO_GENERAL_RX_TX_RATIO(idx)                       (   30 + ( 1 * idx))  // 0x001e int8
#define GS_ISL_RADIO_GENERAL_RX_TX_RATIO_ARRAY_SIZE                      2

#ifndef __cplusplus
static const param_table_t gs_isl_radio_general_table[] = {
    {.name = "ant-intv",      .addr = GS_ISL_RADIO_GENERAL_ANT_INTV(0),                  .type = PARAM_UINT16,   .size =   2, .count = 4, .flags = 0},
    {.name = "duplex-mode",   .addr = GS_ISL_RADIO_GENERAL_DUPLEX_MODE(0),               .type = PARAM_UINT8,    .size =   1, .count = 2, .flags = 0},
    {.name = "modulation",    .addr = GS_ISL_RADIO_GENERAL_MODULATION(0),                .type = PARAM_STRING,   .size =   8, .count = 2, .flags = 0},
    {.name = "ant-auto-dup",  .addr = GS_ISL_RADIO_GENERAL_ANT_AUTO_DUP(0),              .type = PARAM_BOOL,     .size =   1, .count = 4, .flags = 0},
    {.name = "rx-tx-ratio",   .addr = GS_ISL_RADIO_GENERAL_RX_TX_RATIO(0),               .type = PARAM_INT8,     .size =   1, .count = 2, .flags = 0},
};
#endif

#define GS_ISL_RADIO_GENERAL_TABLE_NAME                  "radio-general"
#define GS_ISL_RADIO_GENERAL_TABLE_SIZE                  32 // bytes
#define GS_ISL_RADIO_GENERAL_TABLE_ROWS                  (sizeof(gs_isl_radio_general_table) / sizeof(gs_isl_radio_general_table[0]))
#define GS_ISL_RADIO_GENERAL_TABLE_MEM_ID                7
#define GS_ISL_RADIO_GENERAL_TABLE_FILE_ID               7

#if GS_PARAM_SETTERS_GETTERS
#define GS_ISL_RADIO_GENERAL_ANT_INTV_SET(idx, value) param_set_uint16(GS_ISL_RADIO_GENERAL_ANT_INTV(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_GENERAL_ANT_INTV_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_RADIO_GENERAL_ANT_INTV(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_GENERAL_ANT_INTV_GET(idx) param_get_uint16(GS_ISL_RADIO_GENERAL_ANT_INTV(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID)
#define GS_ISL_RADIO_GENERAL_DUPLEX_MODE_SET(idx, value) param_set_uint8(GS_ISL_RADIO_GENERAL_DUPLEX_MODE(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_GENERAL_DUPLEX_MODE_SET_NOCALLBACK(idx, value) param_set_uint8_nocallback(GS_ISL_RADIO_GENERAL_DUPLEX_MODE(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_GENERAL_DUPLEX_MODE_GET(idx) param_get_uint8(GS_ISL_RADIO_GENERAL_DUPLEX_MODE(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID)
#define GS_ISL_RADIO_GENERAL_MODULATION_SET(idx, value) param_set_string(GS_ISL_RADIO_GENERAL_MODULATION(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_GENERAL_MODULATION_SET_NOCALLBACK(idx, value) param_set_string_nocallback(GS_ISL_RADIO_GENERAL_MODULATION(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_GENERAL_MODULATION_GET(idx) param_get_string(GS_ISL_RADIO_GENERAL_MODULATION(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID)
#define GS_ISL_RADIO_GENERAL_ANT_AUTO_DUP_SET(idx, value) param_set_bool(GS_ISL_RADIO_GENERAL_ANT_AUTO_DUP(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_GENERAL_ANT_AUTO_DUP_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_RADIO_GENERAL_ANT_AUTO_DUP(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_GENERAL_ANT_AUTO_DUP_GET(idx) param_get_bool(GS_ISL_RADIO_GENERAL_ANT_AUTO_DUP(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID)
#define GS_ISL_RADIO_GENERAL_RX_TX_RATIO_SET(idx, value) param_set_int8(GS_ISL_RADIO_GENERAL_RX_TX_RATIO(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_GENERAL_RX_TX_RATIO_SET_NOCALLBACK(idx, value) param_set_int8_nocallback(GS_ISL_RADIO_GENERAL_RX_TX_RATIO(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_GENERAL_RX_TX_RATIO_GET(idx) param_get_int8(GS_ISL_RADIO_GENERAL_RX_TX_RATIO(idx), GS_ISL_RADIO_GENERAL_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_ISL_PARAM_RADIO_GENERAL_H_ */
