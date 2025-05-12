/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_ISL_PARAM_RADIO_TX_ADV_H_
#define _GS_ISL_PARAM_RADIO_TX_ADV_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_ISL_RADIO_TX_ADV_SPS(idx)                                (    0 + ( 2 * idx))  // 0x0000 uint16
#define GS_ISL_RADIO_TX_ADV_SPS_ARRAY_SIZE                               2
#define GS_ISL_RADIO_TX_ADV_SCALE(idx)                              (    4 + ( 2 * idx))  // 0x0004 uint16
#define GS_ISL_RADIO_TX_ADV_SCALE_ARRAY_SIZE                             2
#define GS_ISL_RADIO_TX_ADV_SAMP_FREQ(idx)                          (    8 + ( 4 * idx))  // 0x0008 uint32
#define GS_ISL_RADIO_TX_ADV_SAMP_FREQ_ARRAY_SIZE                         2
#define GS_ISL_RADIO_TX_ADV_RF_BW(idx)                              (   16 + ( 4 * idx))  // 0x0010 uint32
#define GS_ISL_RADIO_TX_ADV_RF_BW_ARRAY_SIZE                             2
#define GS_ISL_RADIO_TX_ADV_DMA_BUFF_SIZE(idx)                      (   24 + ( 4 * idx))  // 0x0018 uint32
#define GS_ISL_RADIO_TX_ADV_DMA_BUFF_SIZE_ARRAY_SIZE                     2
#define GS_ISL_RADIO_TX_ADV_FRAME_LEN(idx)                          (   32 + ( 2 * idx))  // 0x0020 uint16
#define GS_ISL_RADIO_TX_ADV_FRAME_LEN_ARRAY_SIZE                         2
#define GS_ISL_RADIO_TX_ADV_QUEUE_LEN(idx)                          (   36 + ( 2 * idx))  // 0x0024 uint16
#define GS_ISL_RADIO_TX_ADV_QUEUE_LEN_ARRAY_SIZE                         2

#ifndef __cplusplus
static const param_table_t gs_isl_radio_tx_adv_table[] = {
    {.name = "sps",           .addr = GS_ISL_RADIO_TX_ADV_SPS(0),                        .type = PARAM_UINT16,   .size =   2, .count = 2, .flags = 0},
    {.name = "scale",         .addr = GS_ISL_RADIO_TX_ADV_SCALE(0),                      .type = PARAM_UINT16,   .size =   2, .count = 2, .flags = 0},
    {.name = "samp-freq",     .addr = GS_ISL_RADIO_TX_ADV_SAMP_FREQ(0),                  .type = PARAM_UINT32,   .size =   4, .count = 2, .flags = 0},
    {.name = "rf-bw",         .addr = GS_ISL_RADIO_TX_ADV_RF_BW(0),                      .type = PARAM_UINT32,   .size =   4, .count = 2, .flags = 0},
    {.name = "dma-buff-size", .addr = GS_ISL_RADIO_TX_ADV_DMA_BUFF_SIZE(0),              .type = PARAM_UINT32,   .size =   4, .count = 2, .flags = 0},
    {.name = "frame-len",     .addr = GS_ISL_RADIO_TX_ADV_FRAME_LEN(0),                  .type = PARAM_UINT16,   .size =   2, .count = 2, .flags = 0},
    {.name = "queue-len",     .addr = GS_ISL_RADIO_TX_ADV_QUEUE_LEN(0),                  .type = PARAM_UINT16,   .size =   2, .count = 2, .flags = 0},
};
#endif

#define GS_ISL_RADIO_TX_ADV_TABLE_NAME                   "radio-tx-adv"
#define GS_ISL_RADIO_TX_ADV_TABLE_SIZE                   40 // bytes
#define GS_ISL_RADIO_TX_ADV_TABLE_ROWS                   (sizeof(gs_isl_radio_tx_adv_table) / sizeof(gs_isl_radio_tx_adv_table[0]))
#define GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID                 6
#define GS_ISL_RADIO_TX_ADV_TABLE_FILE_ID                6

#if GS_PARAM_SETTERS_GETTERS
#define GS_ISL_RADIO_TX_ADV_SPS_SET(idx, value) param_set_uint16(GS_ISL_RADIO_TX_ADV_SPS(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_SPS_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_RADIO_TX_ADV_SPS(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_SPS_GET(idx) param_get_uint16(GS_ISL_RADIO_TX_ADV_SPS(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_ADV_SCALE_SET(idx, value) param_set_uint16(GS_ISL_RADIO_TX_ADV_SCALE(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_SCALE_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_RADIO_TX_ADV_SCALE(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_SCALE_GET(idx) param_get_uint16(GS_ISL_RADIO_TX_ADV_SCALE(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_ADV_SAMP_FREQ_SET(idx, value) param_set_uint32(GS_ISL_RADIO_TX_ADV_SAMP_FREQ(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_SAMP_FREQ_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_RADIO_TX_ADV_SAMP_FREQ(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_SAMP_FREQ_GET(idx) param_get_uint32(GS_ISL_RADIO_TX_ADV_SAMP_FREQ(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_ADV_RF_BW_SET(idx, value) param_set_uint32(GS_ISL_RADIO_TX_ADV_RF_BW(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_RF_BW_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_RADIO_TX_ADV_RF_BW(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_RF_BW_GET(idx) param_get_uint32(GS_ISL_RADIO_TX_ADV_RF_BW(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_ADV_DMA_BUFF_SIZE_SET(idx, value) param_set_uint32(GS_ISL_RADIO_TX_ADV_DMA_BUFF_SIZE(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_DMA_BUFF_SIZE_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_RADIO_TX_ADV_DMA_BUFF_SIZE(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_DMA_BUFF_SIZE_GET(idx) param_get_uint32(GS_ISL_RADIO_TX_ADV_DMA_BUFF_SIZE(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_ADV_FRAME_LEN_SET(idx, value) param_set_uint16(GS_ISL_RADIO_TX_ADV_FRAME_LEN(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_FRAME_LEN_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_RADIO_TX_ADV_FRAME_LEN(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_FRAME_LEN_GET(idx) param_get_uint16(GS_ISL_RADIO_TX_ADV_FRAME_LEN(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_TX_ADV_QUEUE_LEN_SET(idx, value) param_set_uint16(GS_ISL_RADIO_TX_ADV_QUEUE_LEN(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_QUEUE_LEN_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_RADIO_TX_ADV_QUEUE_LEN(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_TX_ADV_QUEUE_LEN_GET(idx) param_get_uint16(GS_ISL_RADIO_TX_ADV_QUEUE_LEN(idx), GS_ISL_RADIO_TX_ADV_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_ISL_PARAM_RADIO_TX_ADV_H_ */
