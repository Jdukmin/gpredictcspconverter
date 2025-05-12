/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_ISL_PARAM_RADIO_TX_H_
#define _GS_ISL_PARAM_RADIO_TX_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_ISL_RADIO_TX_FREQ(idx)                                   (    0 + ( 8 * idx))  // 0x0000 uint64
#define GS_ISL_RADIO_TX_FREQ_ARRAY_SIZE                                  2
#define GS_ISL_RADIO_TX_BAUD(idx)                                   (   16 + ( 4 * idx))  // 0x0010 uint32
#define GS_ISL_RADIO_TX_BAUD_ARRAY_SIZE                                  2
#define GS_ISL_RADIO_TX_GAIN(idx)                                   (   24 + ( 4 * idx))  // 0x0018 float
#define GS_ISL_RADIO_TX_GAIN_ARRAY_SIZE                                  2
#define GS_ISL_RADIO_TX_REED_SOLOMON(idx)                           (   32 + ( 1 * idx))  // 0x0020 bool
#define GS_ISL_RADIO_TX_REED_SOLOMON_ARRAY_SIZE                          2
#define GS_ISL_RADIO_TX_SCRAMBLER(idx)                              (   34 + ( 1 * idx))  // 0x0022 bool
#define GS_ISL_RADIO_TX_SCRAMBLER_ARRAY_SIZE                             2
#define GS_ISL_RADIO_TX_CONVOLUTIONAL(idx)                          (   36 + ( 1 * idx))  // 0x0024 bool
#define GS_ISL_RADIO_TX_CONVOLUTIONAL_ARRAY_SIZE                         2
#define GS_ISL_RADIO_TX_ANT_TX_ON(idx)                              (   38 + ( 1 * idx))  // 0x0026 bool
#define GS_ISL_RADIO_TX_ANT_TX_ON_ARRAY_SIZE                             4
#define GS_ISL_RADIO_TX_ANT_TX_EN(idx)                              (   42 + ( 1 * idx))  // 0x002a bool
#define GS_ISL_RADIO_TX_ANT_TX_EN_ARRAY_SIZE                             4
#define GS_ISL_RADIO_TX_ANT_TX_PWR(idx)                             (   46 + ( 1 * idx))  // 0x002e uint8
#define GS_ISL_RADIO_TX_ANT_TX_PWR_ARRAY_SIZE                            4

#ifndef __cplusplus
static const param_table_t gs_isl_radio_tx_table[] = {
    {.name = "freq",          .addr = GS_ISL_RADIO_TX_FREQ(0),                           .type = PARAM_UINT64,   .size =   8, .count = 2, .flags = 0},
    {.name = "baud",          .addr = GS_ISL_RADIO_TX_BAUD(0),                           .type = PARAM_UINT32,   .size =   4, .count = 2, .flags = 0},
    {.name = "gain",          .addr = GS_ISL_RADIO_TX_GAIN(0),                           .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "reed-solomon",  .addr = GS_ISL_RADIO_TX_REED_SOLOMON(0),                   .type = PARAM_BOOL,     .size =   1, .count = 2, .flags = 0},
    {.name = "scrambler",     .addr = GS_ISL_RADIO_TX_SCRAMBLER(0),                      .type = PARAM_BOOL,     .size =   1, .count = 2, .flags = 0},
    {.name = "convolutional", .addr = GS_ISL_RADIO_TX_CONVOLUTIONAL(0),                  .type = PARAM_BOOL,     .size =   1, .count = 2, .flags = 0},
    {.name = "ant-tx-on",     .addr = GS_ISL_RADIO_TX_ANT_TX_ON(0),                      .type = PARAM_BOOL,     .size =   1, .count = 4, .flags = 0},
    {.name = "ant-tx-en",     .addr = GS_ISL_RADIO_TX_ANT_TX_EN(0),                      .type = PARAM_BOOL,     .size =   1, .count = 4, .flags = 0},
    {.name = "ant-tx-pwr",    .addr = GS_ISL_RADIO_TX_ANT_TX_PWR(0),                     .type = PARAM_UINT8,    .size =   1, .count = 4, .flags = 0},
};
#endif

#define GS_ISL_RADIO_TX_TABLE_NAME                       "radio-tx"
#define GS_ISL_RADIO_TX_TABLE_SIZE                       50 // bytes
#define GS_ISL_RADIO_TX_TABLE_ROWS                       (sizeof(gs_isl_radio_tx_table) / sizeof(gs_isl_radio_tx_table[0]))
#define GS_ISL_RADIO_TX_TABLE_MEM_ID                     5
#define GS_ISL_RADIO_TX_TABLE_FILE_ID                    5

#if GS_PARAM_SETTERS_GETTERS
#define GS_ISL_RADIO_TX_FREQ_SET(idx, value) param_set_uint64(GS_ISL_RADIO_TX_FREQ(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_FREQ_SET_NOCALLBACK(idx, value) param_set_uint64_nocallback(GS_ISL_RADIO_TX_FREQ(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_FREQ_GET(idx) param_get_uint64(GS_ISL_RADIO_TX_FREQ(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_BAUD_SET(idx, value) param_set_uint32(GS_ISL_RADIO_TX_BAUD(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_BAUD_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_RADIO_TX_BAUD(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_BAUD_GET(idx) param_get_uint32(GS_ISL_RADIO_TX_BAUD(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_GAIN_SET(idx, value) param_set_float(GS_ISL_RADIO_TX_GAIN(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_GAIN_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_TX_GAIN(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_GAIN_GET(idx) param_get_float(GS_ISL_RADIO_TX_GAIN(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_REED_SOLOMON_SET(idx, value) param_set_bool(GS_ISL_RADIO_TX_REED_SOLOMON(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_REED_SOLOMON_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_RADIO_TX_REED_SOLOMON(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_REED_SOLOMON_GET(idx) param_get_bool(GS_ISL_RADIO_TX_REED_SOLOMON(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_SCRAMBLER_SET(idx, value) param_set_bool(GS_ISL_RADIO_TX_SCRAMBLER(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_SCRAMBLER_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_RADIO_TX_SCRAMBLER(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_SCRAMBLER_GET(idx) param_get_bool(GS_ISL_RADIO_TX_SCRAMBLER(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_CONVOLUTIONAL_SET(idx, value) param_set_bool(GS_ISL_RADIO_TX_CONVOLUTIONAL(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_CONVOLUTIONAL_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_RADIO_TX_CONVOLUTIONAL(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_CONVOLUTIONAL_GET(idx) param_get_bool(GS_ISL_RADIO_TX_CONVOLUTIONAL(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_ANT_TX_ON_SET(idx, value) param_set_bool(GS_ISL_RADIO_TX_ANT_TX_ON(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ANT_TX_ON_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_RADIO_TX_ANT_TX_ON(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ANT_TX_ON_GET(idx) param_get_bool(GS_ISL_RADIO_TX_ANT_TX_ON(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_ANT_TX_EN_SET(idx, value) param_set_bool(GS_ISL_RADIO_TX_ANT_TX_EN(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ANT_TX_EN_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_RADIO_TX_ANT_TX_EN(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ANT_TX_EN_GET(idx) param_get_bool(GS_ISL_RADIO_TX_ANT_TX_EN(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_ANT_TX_PWR_SET(idx, value) param_set_uint8(GS_ISL_RADIO_TX_ANT_TX_PWR(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ANT_TX_PWR_SET_NOCALLBACK(idx, value) param_set_uint8_nocallback(GS_ISL_RADIO_TX_ANT_TX_PWR(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ANT_TX_PWR_GET(idx) param_get_uint8(GS_ISL_RADIO_TX_ANT_TX_PWR(idx), GS_ISL_RADIO_TX_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_ISL_PARAM_RADIO_TX_H_ */
