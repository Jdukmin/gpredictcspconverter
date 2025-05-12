/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
#ifndef _GS_SOFT_PARAM_SEM_H_
#define _GS_SOFT_PARAM_SEM_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

// Table parameters address/offset
#define GS_SOFT_SEM_TOTERR                                               0                // 0x0000 uint32
#define GS_SOFT_SEM_TOTCORRERR                                           4                // 0x0004 uint32
#define GS_SOFT_SEM_TOTUNCORRERR                                         8                // 0x0008 uint32
#define GS_SOFT_SEM_LAST_TIME                                           12                // 0x000c uint32
#define GS_SOFT_SEM_LAST_PA                                             16                // 0x0010 uint32
#define GS_SOFT_SEM_LAST_LA                                             20                // 0x0014 uint32
#define GS_SOFT_SEM_LAST_WD                                             24                // 0x0018 uint8
#define GS_SOFT_SEM_LAST_BT                                             25                // 0x0019 uint8
#define GS_SOFT_SEM_STATE                                               26                // 0x001a int8

#ifndef __cplusplus
static const param_table_t gs_soft_sem_table[] = {
    {.name = "toterr",        .addr = GS_SOFT_SEM_TOTERR,                                .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = PARAM_F_PERSIST},
    {.name = "totcorrerr",    .addr = GS_SOFT_SEM_TOTCORRERR,                            .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = PARAM_F_PERSIST},
    {.name = "totuncorrerr",  .addr = GS_SOFT_SEM_TOTUNCORRERR,                          .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = PARAM_F_PERSIST},
    {.name = "last-time",     .addr = GS_SOFT_SEM_LAST_TIME,                             .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = PARAM_F_PERSIST},
    {.name = "last-pa",       .addr = GS_SOFT_SEM_LAST_PA,                               .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = PARAM_F_PERSIST},
    {.name = "last-la",       .addr = GS_SOFT_SEM_LAST_LA,                               .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = PARAM_F_PERSIST},
    {.name = "last-wd",       .addr = GS_SOFT_SEM_LAST_WD,                               .type = PARAM_UINT8,    .size =   1, .count = 1, .flags = PARAM_F_PERSIST},
    {.name = "last-bt",       .addr = GS_SOFT_SEM_LAST_BT,                               .type = PARAM_UINT8,    .size =   1, .count = 1, .flags = PARAM_F_PERSIST},
    {.name = "state",         .addr = GS_SOFT_SEM_STATE,                                 .type = PARAM_INT8,     .size =   1, .count = 1, .flags = 0},
};
#endif

#define GS_SOFT_SEM_TABLE_NAME                           "sem"
#define GS_SOFT_SEM_TABLE_SIZE                           27 // bytes
#define GS_SOFT_SEM_TABLE_ROWS                           (sizeof(gs_soft_sem_table) / sizeof(gs_soft_sem_table[0]))
#define GS_SOFT_SEM_TABLE_MEM_ID                         3

#if GS_PARAM_SETTERS_GETTERS
#define GS_SOFT_SEM_TOTERR_SET(value) param_set_uint32(GS_SOFT_SEM_TOTERR, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_TOTERR_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_SEM_TOTERR, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_TOTERR_GET() param_get_uint32(GS_SOFT_SEM_TOTERR, GS_SOFT_SEM_TABLE_MEM_ID)
#define GS_SOFT_SEM_TOTCORRERR_SET(value) param_set_uint32(GS_SOFT_SEM_TOTCORRERR, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_TOTCORRERR_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_SEM_TOTCORRERR, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_TOTCORRERR_GET() param_get_uint32(GS_SOFT_SEM_TOTCORRERR, GS_SOFT_SEM_TABLE_MEM_ID)
#define GS_SOFT_SEM_TOTUNCORRERR_SET(value) param_set_uint32(GS_SOFT_SEM_TOTUNCORRERR, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_TOTUNCORRERR_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_SEM_TOTUNCORRERR, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_TOTUNCORRERR_GET() param_get_uint32(GS_SOFT_SEM_TOTUNCORRERR, GS_SOFT_SEM_TABLE_MEM_ID)
#define GS_SOFT_SEM_LAST_TIME_SET(value) param_set_uint32(GS_SOFT_SEM_LAST_TIME, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_LAST_TIME_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_SEM_LAST_TIME, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_LAST_TIME_GET() param_get_uint32(GS_SOFT_SEM_LAST_TIME, GS_SOFT_SEM_TABLE_MEM_ID)
#define GS_SOFT_SEM_LAST_PA_SET(value) param_set_uint32(GS_SOFT_SEM_LAST_PA, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_LAST_PA_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_SEM_LAST_PA, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_LAST_PA_GET() param_get_uint32(GS_SOFT_SEM_LAST_PA, GS_SOFT_SEM_TABLE_MEM_ID)
#define GS_SOFT_SEM_LAST_LA_SET(value) param_set_uint32(GS_SOFT_SEM_LAST_LA, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_LAST_LA_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_SEM_LAST_LA, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_LAST_LA_GET() param_get_uint32(GS_SOFT_SEM_LAST_LA, GS_SOFT_SEM_TABLE_MEM_ID)
#define GS_SOFT_SEM_LAST_WD_SET(value) param_set_uint8(GS_SOFT_SEM_LAST_WD, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_LAST_WD_SET_NOCALLBACK(value) param_set_uint8_nocallback(GS_SOFT_SEM_LAST_WD, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_LAST_WD_GET() param_get_uint8(GS_SOFT_SEM_LAST_WD, GS_SOFT_SEM_TABLE_MEM_ID)
#define GS_SOFT_SEM_LAST_BT_SET(value) param_set_uint8(GS_SOFT_SEM_LAST_BT, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_LAST_BT_SET_NOCALLBACK(value) param_set_uint8_nocallback(GS_SOFT_SEM_LAST_BT, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_LAST_BT_GET() param_get_uint8(GS_SOFT_SEM_LAST_BT, GS_SOFT_SEM_TABLE_MEM_ID)
#define GS_SOFT_SEM_STATE_SET(value) param_set_int8(GS_SOFT_SEM_STATE, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_STATE_SET_NOCALLBACK(value) param_set_int8_nocallback(GS_SOFT_SEM_STATE, GS_SOFT_SEM_TABLE_MEM_ID, value)
#define GS_SOFT_SEM_STATE_GET() param_get_int8(GS_SOFT_SEM_STATE, GS_SOFT_SEM_TABLE_MEM_ID)
#endif

#ifdef __cplusplus
}
#endif
#endif /*_GS_SOFT_PARAM_SEM_H_ */
