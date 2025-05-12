/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_SOFT_PARAM_BOARD_H_
#define _GS_SOFT_PARAM_BOARD_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_SOFT_BOARD_KISSBAUD                                           0                // 0x0000 uint32
#define GS_SOFT_BOARD_MAXTEMP                                            4                // 0x0004 uint8
#define GS_SOFT_BOARD_PWRDWN_DELAY                                       5                // 0x0005 uint8
#define GS_SOFT_BOARD_CMD_PWROFF                                         6                // 0x0006 int8
#define GS_SOFT_BOARD_USB_ENA                                            7                // 0x0007 bool
#define GS_SOFT_BOARD_CSP_RTABLE                                         8                // 0x0008 string
#define GS_SOFT_BOARD_CSP_ADDR                                         104                // 0x0068 uint8
#define GS_SOFT_BOARD_INIT_AD9361                                      105                // 0x0069 bool
#define GS_SOFT_BOARD_BOOTOK_NODE                                      106                // 0x006a uint8
#define GS_SOFT_BOARD_POWERCHAN                                        107                // 0x006b int8
#define GS_SOFT_BOARD_EPS_NODE                                         108                // 0x006c int8
#define GS_SOFT_BOARD_KISSDEVICE                                       109                // 0x006d string
#define GS_SOFT_BOARD_EN_UART1                                         141                // 0x008d bool
#define GS_SOFT_BOARD_EPS_TYPE                                         142                // 0x008e uint8
#define GS_SOFT_BOARD_PPP_CONFIG                                       143                // 0x008f uint8
#define GS_SOFT_BOARD_PPP_SERVER_IP                                    144                // 0x0090 string
#define GS_SOFT_BOARD_PPP_CLIENT_IP                                    160                // 0x00a0 string
#define GS_SOFT_BOARD_PPP_SERV_FILE                                    176                // 0x00b0 string
#define GS_SOFT_BOARD_PPP_CLI_FILE                                     192                // 0x00c0 string
#define GS_SOFT_BOARD_GW_IP_ADDR                                       208                // 0x00d0 string
#define GS_SOFT_BOARD_USB_IP_ADDR                                      224                // 0x00e0 string

#ifndef __cplusplus
static const param_table_t gs_soft_board_table[] = {
    {.name = "kissbaud",      .addr = GS_SOFT_BOARD_KISSBAUD,                            .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = 0},
    {.name = "maxtemp",       .addr = GS_SOFT_BOARD_MAXTEMP,                             .type = PARAM_UINT8,    .size =   1, .count = 1, .flags = 0},
    {.name = "pwrdwn_delay",  .addr = GS_SOFT_BOARD_PWRDWN_DELAY,                        .type = PARAM_UINT8,    .size =   1, .count = 1, .flags = 0},
    {.name = "cmd_pwroff",    .addr = GS_SOFT_BOARD_CMD_PWROFF,                          .type = PARAM_INT8,     .size =   1, .count = 1, .flags = 0},
    {.name = "usb_ena",       .addr = GS_SOFT_BOARD_USB_ENA,                             .type = PARAM_BOOL,     .size =   1, .count = 1, .flags = 0},
    {.name = "csp_rtable",    .addr = GS_SOFT_BOARD_CSP_RTABLE,                          .type = PARAM_STRING,   .size =  96, .count = 1, .flags = 0},
    {.name = "csp_addr",      .addr = GS_SOFT_BOARD_CSP_ADDR,                            .type = PARAM_UINT8,    .size =   1, .count = 1, .flags = 0},
    {.name = "init_ad9361",   .addr = GS_SOFT_BOARD_INIT_AD9361,                         .type = PARAM_BOOL,     .size =   1, .count = 1, .flags = 0},
    {.name = "bootok_node",   .addr = GS_SOFT_BOARD_BOOTOK_NODE,                         .type = PARAM_UINT8,    .size =   1, .count = 1, .flags = 0},
    {.name = "powerchan",     .addr = GS_SOFT_BOARD_POWERCHAN,                           .type = PARAM_INT8,     .size =   1, .count = 1, .flags = 0},
    {.name = "eps_node",      .addr = GS_SOFT_BOARD_EPS_NODE,                            .type = PARAM_INT8,     .size =   1, .count = 1, .flags = 0},
    {.name = "kissdevice",    .addr = GS_SOFT_BOARD_KISSDEVICE,                          .type = PARAM_STRING,   .size =  32, .count = 1, .flags = 0},
    {.name = "en_uart1",      .addr = GS_SOFT_BOARD_EN_UART1,                            .type = PARAM_BOOL,     .size =   1, .count = 1, .flags = 0},
    {.name = "eps_type",      .addr = GS_SOFT_BOARD_EPS_TYPE,                            .type = PARAM_UINT8,    .size =   1, .count = 1, .flags = 0},
    {.name = "ppp_config",    .addr = GS_SOFT_BOARD_PPP_CONFIG,                          .type = PARAM_UINT8,    .size =   1, .count = 1, .flags = 0},
    {.name = "ppp_server_ip", .addr = GS_SOFT_BOARD_PPP_SERVER_IP,                       .type = PARAM_STRING,   .size =  16, .count = 1, .flags = 0},
    {.name = "ppp_client_ip", .addr = GS_SOFT_BOARD_PPP_CLIENT_IP,                       .type = PARAM_STRING,   .size =  16, .count = 1, .flags = 0},
    {.name = "ppp_serv_file", .addr = GS_SOFT_BOARD_PPP_SERV_FILE,                       .type = PARAM_STRING,   .size =  16, .count = 1, .flags = 0},
    {.name = "ppp_cli_file",  .addr = GS_SOFT_BOARD_PPP_CLI_FILE,                        .type = PARAM_STRING,   .size =  16, .count = 1, .flags = 0},
    {.name = "gw_ip_addr",    .addr = GS_SOFT_BOARD_GW_IP_ADDR,                          .type = PARAM_STRING,   .size =  16, .count = 1, .flags = 0},
    {.name = "usb_ip_addr",   .addr = GS_SOFT_BOARD_USB_IP_ADDR,                         .type = PARAM_STRING,   .size =  16, .count = 1, .flags = 0},
};
#endif

#define GS_SOFT_BOARD_TABLE_NAME                         "board"
#define GS_SOFT_BOARD_TABLE_SIZE                         240 // bytes
#define GS_SOFT_BOARD_TABLE_ROWS                         (sizeof(gs_soft_board_table) / sizeof(gs_soft_board_table[0]))
#define GS_SOFT_BOARD_TABLE_MEM_ID                       0

#if GS_PARAM_SETTERS_GETTERS
#define GS_SOFT_BOARD_KISSBAUD_SET(value) param_set_uint32(GS_SOFT_BOARD_KISSBAUD, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_KISSBAUD_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_BOARD_KISSBAUD, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_KISSBAUD_GET() param_get_uint32(GS_SOFT_BOARD_KISSBAUD, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_MAXTEMP_SET(value) param_set_uint8(GS_SOFT_BOARD_MAXTEMP, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_MAXTEMP_SET_NOCALLBACK(value) param_set_uint8_nocallback(GS_SOFT_BOARD_MAXTEMP, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_MAXTEMP_GET() param_get_uint8(GS_SOFT_BOARD_MAXTEMP, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_PWRDWN_DELAY_SET(value) param_set_uint8(GS_SOFT_BOARD_PWRDWN_DELAY, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PWRDWN_DELAY_SET_NOCALLBACK(value) param_set_uint8_nocallback(GS_SOFT_BOARD_PWRDWN_DELAY, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PWRDWN_DELAY_GET() param_get_uint8(GS_SOFT_BOARD_PWRDWN_DELAY, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_CMD_PWROFF_SET(value) param_set_int8(GS_SOFT_BOARD_CMD_PWROFF, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_CMD_PWROFF_SET_NOCALLBACK(value) param_set_int8_nocallback(GS_SOFT_BOARD_CMD_PWROFF, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_CMD_PWROFF_GET() param_get_int8(GS_SOFT_BOARD_CMD_PWROFF, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_USB_ENA_SET(value) param_set_bool(GS_SOFT_BOARD_USB_ENA, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_USB_ENA_SET_NOCALLBACK(value) param_set_bool_nocallback(GS_SOFT_BOARD_USB_ENA, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_USB_ENA_GET() param_get_bool(GS_SOFT_BOARD_USB_ENA, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_CSP_RTABLE_SET(value) param_set_string(GS_SOFT_BOARD_CSP_RTABLE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_CSP_RTABLE_SET_NOCALLBACK(value) param_set_string_nocallback(GS_SOFT_BOARD_CSP_RTABLE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_CSP_RTABLE_GET() param_get_string(GS_SOFT_BOARD_CSP_RTABLE, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_CSP_ADDR_SET(value) param_set_uint8(GS_SOFT_BOARD_CSP_ADDR, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_CSP_ADDR_SET_NOCALLBACK(value) param_set_uint8_nocallback(GS_SOFT_BOARD_CSP_ADDR, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_CSP_ADDR_GET() param_get_uint8(GS_SOFT_BOARD_CSP_ADDR, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_INIT_AD9361_SET(value) param_set_bool(GS_SOFT_BOARD_INIT_AD9361, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_INIT_AD9361_SET_NOCALLBACK(value) param_set_bool_nocallback(GS_SOFT_BOARD_INIT_AD9361, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_INIT_AD9361_GET() param_get_bool(GS_SOFT_BOARD_INIT_AD9361, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_BOOTOK_NODE_SET(value) param_set_uint8(GS_SOFT_BOARD_BOOTOK_NODE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_BOOTOK_NODE_SET_NOCALLBACK(value) param_set_uint8_nocallback(GS_SOFT_BOARD_BOOTOK_NODE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_BOOTOK_NODE_GET() param_get_uint8(GS_SOFT_BOARD_BOOTOK_NODE, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_POWERCHAN_SET(value) param_set_int8(GS_SOFT_BOARD_POWERCHAN, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_POWERCHAN_SET_NOCALLBACK(value) param_set_int8_nocallback(GS_SOFT_BOARD_POWERCHAN, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_POWERCHAN_GET() param_get_int8(GS_SOFT_BOARD_POWERCHAN, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_EPS_NODE_SET(value) param_set_int8(GS_SOFT_BOARD_EPS_NODE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_EPS_NODE_SET_NOCALLBACK(value) param_set_int8_nocallback(GS_SOFT_BOARD_EPS_NODE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_EPS_NODE_GET() param_get_int8(GS_SOFT_BOARD_EPS_NODE, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_KISSDEVICE_SET(value) param_set_string(GS_SOFT_BOARD_KISSDEVICE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_KISSDEVICE_SET_NOCALLBACK(value) param_set_string_nocallback(GS_SOFT_BOARD_KISSDEVICE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_KISSDEVICE_GET() param_get_string(GS_SOFT_BOARD_KISSDEVICE, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_EN_UART1_SET(value) param_set_bool(GS_SOFT_BOARD_EN_UART1, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_EN_UART1_SET_NOCALLBACK(value) param_set_bool_nocallback(GS_SOFT_BOARD_EN_UART1, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_EN_UART1_GET() param_get_bool(GS_SOFT_BOARD_EN_UART1, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_EPS_TYPE_SET(value) param_set_uint8(GS_SOFT_BOARD_EPS_TYPE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_EPS_TYPE_SET_NOCALLBACK(value) param_set_uint8_nocallback(GS_SOFT_BOARD_EPS_TYPE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_EPS_TYPE_GET() param_get_uint8(GS_SOFT_BOARD_EPS_TYPE, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_PPP_CONFIG_SET(value) param_set_uint8(GS_SOFT_BOARD_PPP_CONFIG, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PPP_CONFIG_SET_NOCALLBACK(value) param_set_uint8_nocallback(GS_SOFT_BOARD_PPP_CONFIG, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PPP_CONFIG_GET() param_get_uint8(GS_SOFT_BOARD_PPP_CONFIG, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_PPP_SERVER_IP_SET(value) param_set_string(GS_SOFT_BOARD_PPP_SERVER_IP, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PPP_SERVER_IP_SET_NOCALLBACK(value) param_set_string_nocallback(GS_SOFT_BOARD_PPP_SERVER_IP, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PPP_SERVER_IP_GET() param_get_string(GS_SOFT_BOARD_PPP_SERVER_IP, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_PPP_CLIENT_IP_SET(value) param_set_string(GS_SOFT_BOARD_PPP_CLIENT_IP, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PPP_CLIENT_IP_SET_NOCALLBACK(value) param_set_string_nocallback(GS_SOFT_BOARD_PPP_CLIENT_IP, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PPP_CLIENT_IP_GET() param_get_string(GS_SOFT_BOARD_PPP_CLIENT_IP, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_PPP_SERV_FILE_SET(value) param_set_string(GS_SOFT_BOARD_PPP_SERV_FILE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PPP_SERV_FILE_SET_NOCALLBACK(value) param_set_string_nocallback(GS_SOFT_BOARD_PPP_SERV_FILE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PPP_SERV_FILE_GET() param_get_string(GS_SOFT_BOARD_PPP_SERV_FILE, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_PPP_CLI_FILE_SET(value) param_set_string(GS_SOFT_BOARD_PPP_CLI_FILE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PPP_CLI_FILE_SET_NOCALLBACK(value) param_set_string_nocallback(GS_SOFT_BOARD_PPP_CLI_FILE, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_PPP_CLI_FILE_GET() param_get_string(GS_SOFT_BOARD_PPP_CLI_FILE, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_GW_IP_ADDR_SET(value) param_set_string(GS_SOFT_BOARD_GW_IP_ADDR, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_GW_IP_ADDR_SET_NOCALLBACK(value) param_set_string_nocallback(GS_SOFT_BOARD_GW_IP_ADDR, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_GW_IP_ADDR_GET() param_get_string(GS_SOFT_BOARD_GW_IP_ADDR, GS_SOFT_BOARD_TABLE_MEM_ID)
#define GS_SOFT_BOARD_USB_IP_ADDR_SET(value) param_set_string(GS_SOFT_BOARD_USB_IP_ADDR, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_USB_IP_ADDR_SET_NOCALLBACK(value) param_set_string_nocallback(GS_SOFT_BOARD_USB_IP_ADDR, GS_SOFT_BOARD_TABLE_MEM_ID, value)
#define GS_SOFT_BOARD_USB_IP_ADDR_GET() param_get_string(GS_SOFT_BOARD_USB_IP_ADDR, GS_SOFT_BOARD_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_SOFT_PARAM_BOARD_H_ */
