/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_ISL_PARAM_RADIO_RX_ADV_H_
#define _GS_ISL_PARAM_RADIO_RX_ADV_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_ISL_RADIO_RX_ADV_SPS(idx)                                (    0 + ( 2 * idx))  // 0x0000 uint16
#define GS_ISL_RADIO_RX_ADV_SPS_ARRAY_SIZE                               2
#define GS_ISL_RADIO_RX_ADV_FRAME_LEN(idx)                          (    4 + ( 2 * idx))  // 0x0004 uint16
#define GS_ISL_RADIO_RX_ADV_FRAME_LEN_ARRAY_SIZE                         2
#define GS_ISL_RADIO_RX_ADV_SAMP_FREQ(idx)                          (    8 + ( 4 * idx))  // 0x0008 uint32
#define GS_ISL_RADIO_RX_ADV_SAMP_FREQ_ARRAY_SIZE                         2
#define GS_ISL_RADIO_RX_ADV_RF_BW(idx)                              (   16 + ( 4 * idx))  // 0x0010 uint32
#define GS_ISL_RADIO_RX_ADV_RF_BW_ARRAY_SIZE                             2
#define GS_ISL_RADIO_RX_ADV_DMA_BUFF_SIZE(idx)                      (   24 + ( 4 * idx))  // 0x0018 uint32
#define GS_ISL_RADIO_RX_ADV_DMA_BUFF_SIZE_ARRAY_SIZE                     2
#define GS_ISL_RADIO_RX_ADV_RESET_INTV(idx)                         (   32 + ( 2 * idx))  // 0x0020 uint16
#define GS_ISL_RADIO_RX_ADV_RESET_INTV_ARRAY_SIZE                        2
#define GS_ISL_RADIO_RX_ADV_TDDSYNC_THRES(idx)                      (   36 + ( 1 * idx))  // 0x0024 uint8
#define GS_ISL_RADIO_RX_ADV_TDDSYNC_THRES_ARRAY_SIZE                     2
#define GS_ISL_RADIO_RX_ADV_TDD_RST_MODE(idx)                       (   38 + (16 * idx))  // 0x0026 string
#define GS_ISL_RADIO_RX_ADV_TDD_RST_MODE_ARRAY_SIZE                      2

#ifndef __cplusplus
static const param_table_t gs_isl_radio_rx_adv_table[] = {
    {.name = "sps",           .addr = GS_ISL_RADIO_RX_ADV_SPS(0),                        .type = PARAM_UINT16,   .size =   2, .count = 2, .flags = 0},
    {.name = "frame-len",     .addr = GS_ISL_RADIO_RX_ADV_FRAME_LEN(0),                  .type = PARAM_UINT16,   .size =   2, .count = 2, .flags = 0},
    {.name = "samp-freq",     .addr = GS_ISL_RADIO_RX_ADV_SAMP_FREQ(0),                  .type = PARAM_UINT32,   .size =   4, .count = 2, .flags = 0},
    {.name = "rf-bw",         .addr = GS_ISL_RADIO_RX_ADV_RF_BW(0),                      .type = PARAM_UINT32,   .size =   4, .count = 2, .flags = 0},
    {.name = "dma-buff-size", .addr = GS_ISL_RADIO_RX_ADV_DMA_BUFF_SIZE(0),              .type = PARAM_UINT32,   .size =   4, .count = 2, .flags = 0},
    {.name = "reset-intv",    .addr = GS_ISL_RADIO_RX_ADV_RESET_INTV(0),                 .type = PARAM_UINT16,   .size =   2, .count = 2, .flags = 0},
    {.name = "tddsync-thres", .addr = GS_ISL_RADIO_RX_ADV_TDDSYNC_THRES(0),              .type = PARAM_UINT8,    .size =   1, .count = 2, .flags = 0},
    {.name = "tdd-rst-mode",  .addr = GS_ISL_RADIO_RX_ADV_TDD_RST_MODE(0),               .type = PARAM_STRING,   .size =  16, .count = 2, .flags = 0},
};
#endif

#define GS_ISL_RADIO_RX_ADV_TABLE_NAME                   "radio-rx-adv"
#define GS_ISL_RADIO_RX_ADV_TABLE_SIZE                   70 // bytes
#define GS_ISL_RADIO_RX_ADV_TABLE_ROWS                   (sizeof(gs_isl_radio_rx_adv_table) / sizeof(gs_isl_radio_rx_adv_table[0]))
#define GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID                 2
#define GS_ISL_RADIO_RX_ADV_TABLE_FILE_ID                2

#if GS_PARAM_SETTERS_GETTERS
#define GS_ISL_RADIO_RX_ADV_SPS_SET(idx, value) param_set_uint16(GS_ISL_RADIO_RX_ADV_SPS(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_SPS_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_RADIO_RX_ADV_SPS(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_SPS_GET(idx) param_get_uint16(GS_ISL_RADIO_RX_ADV_SPS(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_ADV_FRAME_LEN_SET(idx, value) param_set_uint16(GS_ISL_RADIO_RX_ADV_FRAME_LEN(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_FRAME_LEN_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_RADIO_RX_ADV_FRAME_LEN(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_FRAME_LEN_GET(idx) param_get_uint16(GS_ISL_RADIO_RX_ADV_FRAME_LEN(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_ADV_SAMP_FREQ_SET(idx, value) param_set_uint32(GS_ISL_RADIO_RX_ADV_SAMP_FREQ(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_SAMP_FREQ_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_RADIO_RX_ADV_SAMP_FREQ(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_SAMP_FREQ_GET(idx) param_get_uint32(GS_ISL_RADIO_RX_ADV_SAMP_FREQ(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_ADV_RF_BW_SET(idx, value) param_set_uint32(GS_ISL_RADIO_RX_ADV_RF_BW(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_RF_BW_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_RADIO_RX_ADV_RF_BW(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_RF_BW_GET(idx) param_get_uint32(GS_ISL_RADIO_RX_ADV_RF_BW(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_ADV_DMA_BUFF_SIZE_SET(idx, value) param_set_uint32(GS_ISL_RADIO_RX_ADV_DMA_BUFF_SIZE(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_DMA_BUFF_SIZE_SET_NOCALLBACK(idx, value) param_set_uint32_nocallback(GS_ISL_RADIO_RX_ADV_DMA_BUFF_SIZE(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_DMA_BUFF_SIZE_GET(idx) param_get_uint32(GS_ISL_RADIO_RX_ADV_DMA_BUFF_SIZE(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_ADV_RESET_INTV_SET(idx, value) param_set_uint16(GS_ISL_RADIO_RX_ADV_RESET_INTV(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_RESET_INTV_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_RADIO_RX_ADV_RESET_INTV(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_RESET_INTV_GET(idx) param_get_uint16(GS_ISL_RADIO_RX_ADV_RESET_INTV(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_ADV_TDDSYNC_THRES_SET(idx, value) param_set_uint8(GS_ISL_RADIO_RX_ADV_TDDSYNC_THRES(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_TDDSYNC_THRES_SET_NOCALLBACK(idx, value) param_set_uint8_nocallback(GS_ISL_RADIO_RX_ADV_TDDSYNC_THRES(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_TDDSYNC_THRES_GET(idx) param_get_uint8(GS_ISL_RADIO_RX_ADV_TDDSYNC_THRES(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID)
#define GS_ISL_RADIO_RX_ADV_TDD_RST_MODE_SET(idx, value) param_set_string(GS_ISL_RADIO_RX_ADV_TDD_RST_MODE(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_TDD_RST_MODE_SET_NOCALLBACK(idx, value) param_set_string_nocallback(GS_ISL_RADIO_RX_ADV_TDD_RST_MODE(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID, value)
#define GS_ISL_RADIO_RX_ADV_TDD_RST_MODE_GET(idx) param_get_string(GS_ISL_RADIO_RX_ADV_TDD_RST_MODE(idx), GS_ISL_RADIO_RX_ADV_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_ISL_PARAM_RADIO_RX_ADV_H_ */
