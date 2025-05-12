/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */
#ifndef _GS_ISL_PARAM_BOARD_H_
#define _GS_ISL_PARAM_BOARD_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_ISL_BOARD_CSP_NODE                                            0                // 0x0000 uint8
#define GS_ISL_BOARD_ANT_ADDR(idx)                                  (    1 + ( 1 * idx))  // 0x0001 uint8
#define GS_ISL_BOARD_ANT_ADDR_ARRAY_SIZE                                 4
#define GS_ISL_BOARD_FEM(idx)                                       (    5 + ( 1 * idx))  // 0x0005 uint8
#define GS_ISL_BOARD_FEM_ARRAY_SIZE                                      2
#define GS_ISL_BOARD_RFCHAIN(idx)                                   (    7 + ( 1 * idx))  // 0x0007 uint8
#define GS_ISL_BOARD_RFCHAIN_ARRAY_SIZE                                  2
#define GS_ISL_BOARD_ANT_GPIO(idx)                                  (   10 + ( 2 * idx))  // 0x000a uint16
#define GS_ISL_BOARD_ANT_GPIO_ARRAY_SIZE                                 4
#define GS_ISL_BOARD_CSP_RTABLE                                         18                // 0x0012 string
#define GS_ISL_BOARD_SL0_IP_ADDR                                       114                // 0x0072 string
#define GS_ISL_BOARD_SL1_IP_ADDR                                       130                // 0x0082 string

#ifndef __cplusplus
static const param_table_t gs_isl_board_table[] = {
    {.name = "csp_node",      .addr = GS_ISL_BOARD_CSP_NODE,                             .type = PARAM_UINT8,    .size =   1, .count = 1, .flags = 0},
    {.name = "ant_addr",      .addr = GS_ISL_BOARD_ANT_ADDR(0),                          .type = PARAM_UINT8,    .size =   1, .count = 4, .flags = 0},
    {.name = "fem",           .addr = GS_ISL_BOARD_FEM(0),                               .type = PARAM_UINT8,    .size =   1, .count = 2, .flags = 0},
    {.name = "rfchain",       .addr = GS_ISL_BOARD_RFCHAIN(0),                           .type = PARAM_UINT8,    .size =   1, .count = 2, .flags = 0},
    {.name = "ant_gpio",      .addr = GS_ISL_BOARD_ANT_GPIO(0),                          .type = PARAM_UINT16,   .size =   2, .count = 4, .flags = 0},
    {.name = "csp_rtable",    .addr = GS_ISL_BOARD_CSP_RTABLE,                           .type = PARAM_STRING,   .size =  96, .count = 1, .flags = 0},
    {.name = "sl0_ip_addr",   .addr = GS_ISL_BOARD_SL0_IP_ADDR,                          .type = PARAM_STRING,   .size =  16, .count = 1, .flags = 0},
    {.name = "sl1_ip_addr",   .addr = GS_ISL_BOARD_SL1_IP_ADDR,                          .type = PARAM_STRING,   .size =  16, .count = 1, .flags = 0},
};
#endif

#define GS_ISL_BOARD_TABLE_NAME                          "board"
#define GS_ISL_BOARD_TABLE_SIZE                          146 // bytes
#define GS_ISL_BOARD_TABLE_ROWS                          (sizeof(gs_isl_board_table) / sizeof(gs_isl_board_table[0]))
#define GS_ISL_BOARD_TABLE_MEM_ID                        0
#define GS_ISL_BOARD_TABLE_FILE_ID                       0

#if GS_PARAM_SETTERS_GETTERS
#define GS_ISL_BOARD_CSP_NODE_SET(value) param_set_uint8(GS_ISL_BOARD_CSP_NODE, GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_CSP_NODE_SET_NOCALLBACK(value) param_set_uint8_nocallback(GS_ISL_BOARD_CSP_NODE, GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_CSP_NODE_GET() param_get_uint8(GS_ISL_BOARD_CSP_NODE, GS_ISL_BOARD_TABLE_MEM_ID)
#define GS_ISL_BOARD_ANT_ADDR_SET(idx, value) param_set_uint8(GS_ISL_BOARD_ANT_ADDR(idx), GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_ANT_ADDR_SET_NOCALLBACK(idx, value) param_set_uint8_nocallback(GS_ISL_BOARD_ANT_ADDR(idx), GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_ANT_ADDR_GET(idx) param_get_uint8(GS_ISL_BOARD_ANT_ADDR(idx), GS_ISL_BOARD_TABLE_MEM_ID)
#define GS_ISL_BOARD_FEM_SET(idx, value) param_set_uint8(GS_ISL_BOARD_FEM(idx), GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_FEM_SET_NOCALLBACK(idx, value) param_set_uint8_nocallback(GS_ISL_BOARD_FEM(idx), GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_FEM_GET(idx) param_get_uint8(GS_ISL_BOARD_FEM(idx), GS_ISL_BOARD_TABLE_MEM_ID)
#define GS_ISL_BOARD_RFCHAIN_SET(idx, value) param_set_uint8(GS_ISL_BOARD_RFCHAIN(idx), GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_RFCHAIN_SET_NOCALLBACK(idx, value) param_set_uint8_nocallback(GS_ISL_BOARD_RFCHAIN(idx), GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_RFCHAIN_GET(idx) param_get_uint8(GS_ISL_BOARD_RFCHAIN(idx), GS_ISL_BOARD_TABLE_MEM_ID)
#define GS_ISL_BOARD_ANT_GPIO_SET(idx, value) param_set_uint16(GS_ISL_BOARD_ANT_GPIO(idx), GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_ANT_GPIO_SET_NOCALLBACK(idx, value) param_set_uint16_nocallback(GS_ISL_BOARD_ANT_GPIO(idx), GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_ANT_GPIO_GET(idx) param_get_uint16(GS_ISL_BOARD_ANT_GPIO(idx), GS_ISL_BOARD_TABLE_MEM_ID)
#define GS_ISL_BOARD_CSP_RTABLE_SET(value) param_set_string(GS_ISL_BOARD_CSP_RTABLE, GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_CSP_RTABLE_SET_NOCALLBACK(value) param_set_string_nocallback(GS_ISL_BOARD_CSP_RTABLE, GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_CSP_RTABLE_GET() param_get_string(GS_ISL_BOARD_CSP_RTABLE, GS_ISL_BOARD_TABLE_MEM_ID)
#define GS_ISL_BOARD_SL0_IP_ADDR_SET(value) param_set_string(GS_ISL_BOARD_SL0_IP_ADDR, GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_SL0_IP_ADDR_SET_NOCALLBACK(value) param_set_string_nocallback(GS_ISL_BOARD_SL0_IP_ADDR, GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_SL0_IP_ADDR_GET() param_get_string(GS_ISL_BOARD_SL0_IP_ADDR, GS_ISL_BOARD_TABLE_MEM_ID)
#define GS_ISL_BOARD_SL1_IP_ADDR_SET(value) param_set_string(GS_ISL_BOARD_SL1_IP_ADDR, GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_SL1_IP_ADDR_SET_NOCALLBACK(value) param_set_string_nocallback(GS_ISL_BOARD_SL1_IP_ADDR, GS_ISL_BOARD_TABLE_MEM_ID, value)
#define GS_ISL_BOARD_SL1_IP_ADDR_GET() param_get_string(GS_ISL_BOARD_SL1_IP_ADDR, GS_ISL_BOARD_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_ISL_PARAM_BOARD_H_ */
