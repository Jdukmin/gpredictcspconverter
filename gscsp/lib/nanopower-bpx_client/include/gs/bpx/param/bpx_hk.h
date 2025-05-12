#ifndef GS_BPX_PARAM_BPX_HK_H
#define GS_BPX_PARAM_BPX_HK_H

/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_BPX_BPX_HK_C_CHARGE                                           0                // 0x0000 uint16
#define GS_BPX_BPX_HK_C_DCHARGE                                          2                // 0x0002 uint16
#define GS_BPX_BPX_HK_C_HEATER                                           4                // 0x0004 uint16
#define GS_BPX_BPX_HK_VBATT                                              6                // 0x0006 uint16
#define GS_BPX_BPX_HK_BAT_TEMP1                                          8                // 0x0008 int16
#define GS_BPX_BPX_HK_BAT_TEMP2                                         10                // 0x000a int16
#define GS_BPX_BPX_HK_BAT_TEMP3                                         12                // 0x000c int16
#define GS_BPX_BPX_HK_BAT_TEMP4                                         14                // 0x000e int16
#define GS_BPX_BPX_HK_BOOTCOUNT                                         16                // 0x0010 uint32
#define GS_BPX_BPX_HK_BOOTCAUSE                                         20                // 0x0014 uint8

#ifndef __cplusplus
static const gs_param_table_row_t gs_bpx_bpx_hk_table[] = {
    {.name = "c_charge",      .addr = GS_BPX_BPX_HK_C_CHARGE,                            .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "c_dcharge",     .addr = GS_BPX_BPX_HK_C_DCHARGE,                           .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "c_heater",      .addr = GS_BPX_BPX_HK_C_HEATER,                            .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "vbatt",         .addr = GS_BPX_BPX_HK_VBATT,                               .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "bat_temp1",     .addr = GS_BPX_BPX_HK_BAT_TEMP1,                           .type = GS_PARAM_INT16,   .size =   2, .array_size =  1, .flags = 0},
    {.name = "bat_temp2",     .addr = GS_BPX_BPX_HK_BAT_TEMP2,                           .type = GS_PARAM_INT16,   .size =   2, .array_size =  1, .flags = 0},
    {.name = "bat_temp3",     .addr = GS_BPX_BPX_HK_BAT_TEMP3,                           .type = GS_PARAM_INT16,   .size =   2, .array_size =  1, .flags = 0},
    {.name = "bat_temp4",     .addr = GS_BPX_BPX_HK_BAT_TEMP4,                           .type = GS_PARAM_INT16,   .size =   2, .array_size =  1, .flags = 0},
    {.name = "bootcount",     .addr = GS_BPX_BPX_HK_BOOTCOUNT,                           .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "bootcause",     .addr = GS_BPX_BPX_HK_BOOTCAUSE,                           .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
};
#endif

#define GS_BPX_BPX_HK_TABLE_NAME                         "bpx_hk"
#define GS_BPX_BPX_HK_TABLE_SIZE                         21 // bytes
#define GS_BPX_BPX_HK_TABLE_ROWS                         (sizeof(gs_bpx_bpx_hk_table) / sizeof(gs_bpx_bpx_hk_table[0]))

#ifdef __cplusplus
}
#endif
#endif
