/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_ISL_PARAM_RADIO_RX_H_
#define _GS_ISL_PARAM_RADIO_RX_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_ISL_RADIO_RX_FREQ(idx)                                   (    0 + ( 8 * idx))  // 0x0000 uint64
#define GS_ISL_RADIO_RX_FREQ_ARRAY_SIZE                                  2
#define GS_ISL_RADIO_RX_BAUD(idx)                                   (   16 + ( 4 * idx))  // 0x0010 uint32
#define GS_ISL_RADIO_RX_BAUD_ARRAY_SIZE                                  2
#define GS_ISL_RADIO_RX_GAIN(idx)                                   (   24 + ( 4 * idx))  // 0x0018 float
#define GS_ISL_RADIO_RX_GAIN_ARRAY_SIZE                                  2
#define GS_ISL_RADIO_RX_GAIN_MODE(idx)                              (   32 + (16 * idx))  // 0x0020 string
#define GS_ISL_RADIO_RX_GAIN_MODE_ARRAY_SIZE                             2
#define GS_ISL_RADIO_RX_REED_SOLOMON(idx)                           (   64 + ( 1 * idx))  // 0x0040 bool
#define GS_ISL_RADIO_RX_REED_SOLOMON_ARRAY_SIZE                          2
#define GS_ISL_RADIO_RX_SCRAMBLER(idx)                              (   66 + ( 1 * idx))  // 0x0042 bool
#define GS_ISL_RADIO_RX_SCRAMBLER_ARRAY_SIZE                             2
#define GS_ISL_RADIO_RX_CONVOLUTIONAL(idx)                          (   68 + ( 1 * idx))  // 0x0044 bool
#define GS_ISL_RADIO_RX_CONVOLUTIONAL_ARRAY_SIZE                         2
#define GS_ISL_RADIO_RX_ANT_RX_ON(idx)                              (   70 + ( 1 * idx))  // 0x0046 bool
#define GS_ISL_RADIO_RX_ANT_RX_ON_ARRAY_SIZE                             4

#ifndef __cplusplus
static const param_table_t gs_isl_radio_rx_table[] = {
    {.name = "freq",          .addr = GS_ISL_RADIO_RX_FREQ(0),                           .type = PARAM_UINT64,   .size =   8, .count = 2, .flags = 0},
    {.name = "baud",          .addr = GS_ISL_RADIO_RX_BAUD(0),                           .type = PARAM_UINT32,   .size =   4, .count = 2, .flags = 0},
    {.name = "gain",          .addr = GS_ISL_RADIO_RX_GAIN(0),                           .type = PARAM_FLOAT,    .size =   4, .count = 2, .flags = 0},
    {.name = "gain-mode",     .addr = GS_ISL_RADIO_RX_GAIN_MODE(0),                      .type = PARAM_STRING,   .size =  16, .count = 2, .flags = 0},
    {.name = "reed-solomon",  .addr = GS_ISL_RADIO_RX_REED_SOLOMON(0),                   .type = PARAM_BOOL,     .size =   1, .count = 2, .flags = 0},
    {.name = "scrambler",     .addr = GS_ISL_RADIO_RX_SCRAMBLER(0),                      .type = PARAM_BOOL,     .size =   1, .count = 2, .flags = 0},
    {.name = "convolutional", .addr = GS_ISL_RADIO_RX_CONVOLUTIONAL(0),                  .type = PARAM_BOOL,     .size =   1, .count = 2, .flags = 0},
    {.name = "ant-rx-on",     .addr = GS_ISL_RADIO_RX_ANT_RX_ON(0),                      .type = PARAM_BOOL,     .size =   1, .count = 4, .flags = 0},
};
#endif

#define GS_ISL_RADIO_RX_TABLE_NAME                       "radio-rx"
#define GS_ISL_RADIO_RX_TABLE_SIZE                       74 // bytes
#define GS_ISL_RADIO_RX_TABLE_ROWS                       (sizeof(gs_isl_radio_rx_table) / sizeof(gs_isl_radio_rx_table[0]))
#define GS_ISL_RADIO_RX_TABLE_MEM_ID                     1
#define GS_ISL_RADIO_RX_TABLE_FILE_ID                    1

#if GS_PARAM_SETTERS_GETTERS
#define GS_ISL_RADIO_RX_FREQ_SET(idx, value) param_set_uint64(GS_ISL_RADIO_RX_FREQ(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_FREQ_SET_NOCALLBACK(idx, value) param_set_uint64_nocallback(GS_ISL_RADIO_RX_FREQ(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_FREQ_GET(idx) param_get_uint64(GS_ISL_RADIO_RX_FREQ(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_BAUD_SET(idx, value) param_set_uint32(GS_ISL_RADIO_RX_BAUD(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_BAUD_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_RADIO_RX_BAUD(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_BAUD_GET(idx) param_get_uint32(GS_ISL_RADIO_RX_BAUD(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_GAIN_SET(idx, value) param_set_float(GS_ISL_RADIO_RX_GAIN(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_GAIN_SET_NOCALLBACK(idx, value) param_set_float_nocallback(GS_ISL_RADIO_RX_GAIN(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_GAIN_GET(idx) param_get_float(GS_ISL_RADIO_RX_GAIN(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_GAIN_MODE_SET(idx, value) param_set_string(GS_ISL_RADIO_RX_GAIN_MODE(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_GAIN_MODE_SET_NOCALLBACK(idx, value) param_set_string_nocallback(GS_ISL_RADIO_RX_GAIN_MODE(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_GAIN_MODE_GET(idx) param_get_string(GS_ISL_RADIO_RX_GAIN_MODE(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_REED_SOLOMON_SET(idx, value) param_set_bool(GS_ISL_RADIO_RX_REED_SOLOMON(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_REED_SOLOMON_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_RADIO_RX_REED_SOLOMON(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_REED_SOLOMON_GET(idx) param_get_bool(GS_ISL_RADIO_RX_REED_SOLOMON(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_SCRAMBLER_SET(idx, value) param_set_bool(GS_ISL_RADIO_RX_SCRAMBLER(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_SCRAMBLER_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_RADIO_RX_SCRAMBLER(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_SCRAMBLER_GET(idx) param_get_bool(GS_ISL_RADIO_RX_SCRAMBLER(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_CONVOLUTIONAL_SET(idx, value) param_set_bool(GS_ISL_RADIO_RX_CONVOLUTIONAL(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_CONVOLUTIONAL_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_RADIO_RX_CONVOLUTIONAL(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_CONVOLUTIONAL_GET(idx) param_get_bool(GS_ISL_RADIO_RX_CONVOLUTIONAL(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_ANT_RX_ON_SET(idx, value) param_set_bool(GS_ISL_RADIO_RX_ANT_RX_ON(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ANT_RX_ON_SET_NOCALLBACK(idx, value) param_set_bool_nocallback(GS_ISL_RADIO_RX_ANT_RX_ON(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ANT_RX_ON_GET(idx) param_get_bool(GS_ISL_RADIO_RX_ANT_RX_ON(idx), GS_ISL_RADIO_RX_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_ISL_PARAM_RADIO_RX_H_ */
