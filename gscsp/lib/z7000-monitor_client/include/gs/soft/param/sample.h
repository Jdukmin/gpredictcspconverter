#ifndef _GS_SOFT_PARAM_SAMPLE_H_
#define _GS_SOFT_PARAM_SAMPLE_H_

/* auto generated file!!! */

#include <param/param_types.h>
#if GS_PARAM_SETTERS_GETTERS
#include <param/param_host.h>
#endif

// Table parameters address/offset
#define GS_SOFT_SAMPLE_NUMOFSAMP                                         0                // 0x0000 uint32
#define GS_SOFT_SAMPLE_MAXFILESIZE                                       4                // 0x0004 uint32
#define GS_SOFT_SAMPLE_FS_HZ                                             8                // 0x0008 uint32
#define GS_SOFT_SAMPLE_BW_HZ                                            12                // 0x000c uint32
#define GS_SOFT_SAMPLE_LO_HZ                                            16                // 0x0010 uint64
#define GS_SOFT_SAMPLE_CMD_START                                        24                // 0x0018 bool
#define GS_SOFT_SAMPLE_PWR                                              25                // 0x0019 uint8
#define GS_SOFT_SAMPLE_STATUS                                           26                // 0x001a int8
#define GS_SOFT_SAMPLE_FILENAME                                         27                // 0x001b string

static const param_table_t gs_soft_sample_table[] = {
    {.name = "numofsamp",     .addr = GS_SOFT_SAMPLE_NUMOFSAMP,                          .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = 0},
    {.name = "maxfilesize",   .addr = GS_SOFT_SAMPLE_MAXFILESIZE,                        .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = 0},
    {.name = "fs_hz",         .addr = GS_SOFT_SAMPLE_FS_HZ,                              .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = 0},
    {.name = "bw_hz",         .addr = GS_SOFT_SAMPLE_BW_HZ,                              .type = PARAM_UINT32,   .size =   4, .count = 1, .flags = 0},
    {.name = "lo_hz",         .addr = GS_SOFT_SAMPLE_LO_HZ,                              .type = PARAM_UINT64,   .size =   8, .count = 1, .flags = 0},
    {.name = "cmd_start",     .addr = GS_SOFT_SAMPLE_CMD_START,                          .type = PARAM_BOOL,     .size =   1, .count = 1, .flags = 0},
    {.name = "pwr",           .addr = GS_SOFT_SAMPLE_PWR,                                .type = PARAM_UINT8,    .size =   1, .count = 1, .flags = 0},
    {.name = "status",        .addr = GS_SOFT_SAMPLE_STATUS,                             .type = PARAM_INT8,     .size =   1, .count = 1, .flags = 0},
    {.name = "filename",      .addr = GS_SOFT_SAMPLE_FILENAME,                           .type = PARAM_STRING,   .size =  48, .count = 1, .flags = 0},
};

#define GS_SOFT_SAMPLE_TABLE_NAME                        "sample"
#define GS_SOFT_SAMPLE_TABLE_SIZE                        75 // bytes
#define GS_SOFT_SAMPLE_TABLE_ROWS                        (sizeof(gs_soft_sample_table) / sizeof(gs_soft_sample_table[0]))
#define GS_SOFT_SAMPLE_TABLE_MEM_ID                      5

#if GS_PARAM_SETTERS_GETTERS
#define GS_SOFT_SAMPLE_NUMOFSAMP_SET(value) param_set_uint32(GS_SOFT_SAMPLE_NUMOFSAMP, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_NUMOFSAMP_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_SAMPLE_NUMOFSAMP, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_NUMOFSAMP_GET() param_get_uint32(GS_SOFT_SAMPLE_NUMOFSAMP, GS_SOFT_SAMPLE_TABLE_MEM_ID)
#define GS_SOFT_SAMPLE_MAXFILESIZE_SET(value) param_set_uint32(GS_SOFT_SAMPLE_MAXFILESIZE, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_MAXFILESIZE_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_SAMPLE_MAXFILESIZE, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_MAXFILESIZE_GET() param_get_uint32(GS_SOFT_SAMPLE_MAXFILESIZE, GS_SOFT_SAMPLE_TABLE_MEM_ID)
#define GS_SOFT_SAMPLE_FS_HZ_SET(value) param_set_uint32(GS_SOFT_SAMPLE_FS_HZ, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_FS_HZ_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_SAMPLE_FS_HZ, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_FS_HZ_GET() param_get_uint32(GS_SOFT_SAMPLE_FS_HZ, GS_SOFT_SAMPLE_TABLE_MEM_ID)
#define GS_SOFT_SAMPLE_BW_HZ_SET(value) param_set_uint32(GS_SOFT_SAMPLE_BW_HZ, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_BW_HZ_SET_NOCALLBACK(value) param_set_uint32_nocallback(GS_SOFT_SAMPLE_BW_HZ, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_BW_HZ_GET() param_get_uint32(GS_SOFT_SAMPLE_BW_HZ, GS_SOFT_SAMPLE_TABLE_MEM_ID)
#define GS_SOFT_SAMPLE_LO_HZ_SET(value) param_set_uint64(GS_SOFT_SAMPLE_LO_HZ, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_LO_HZ_SET_NOCALLBACK(value) param_set_uint64_nocallback(GS_SOFT_SAMPLE_LO_HZ, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_LO_HZ_GET() param_get_uint64(GS_SOFT_SAMPLE_LO_HZ, GS_SOFT_SAMPLE_TABLE_MEM_ID)
#define GS_SOFT_SAMPLE_CMD_START_SET(value) param_set_bool(GS_SOFT_SAMPLE_CMD_START, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_CMD_START_SET_NOCALLBACK(value) param_set_bool_nocallback(GS_SOFT_SAMPLE_CMD_START, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_CMD_START_GET() param_get_bool(GS_SOFT_SAMPLE_CMD_START, GS_SOFT_SAMPLE_TABLE_MEM_ID)
#define GS_SOFT_SAMPLE_PWR_SET(value) param_set_uint8(GS_SOFT_SAMPLE_PWR, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_PWR_SET_NOCALLBACK(value) param_set_uint8_nocallback(GS_SOFT_SAMPLE_PWR, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_PWR_GET() param_get_uint8(GS_SOFT_SAMPLE_PWR, GS_SOFT_SAMPLE_TABLE_MEM_ID)
#define GS_SOFT_SAMPLE_STATUS_SET(value) param_set_int8(GS_SOFT_SAMPLE_STATUS, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_STATUS_SET_NOCALLBACK(value) param_set_int8_nocallback(GS_SOFT_SAMPLE_STATUS, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_STATUS_GET() param_get_int8(GS_SOFT_SAMPLE_STATUS, GS_SOFT_SAMPLE_TABLE_MEM_ID)
#define GS_SOFT_SAMPLE_FILENAME_SET(value) param_set_string(GS_SOFT_SAMPLE_FILENAME, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_FILENAME_SET_NOCALLBACK(value) param_set_string_nocallback(GS_SOFT_SAMPLE_FILENAME, GS_SOFT_SAMPLE_TABLE_MEM_ID, value)
#define GS_SOFT_SAMPLE_FILENAME_GET() param_get_string(GS_SOFT_SAMPLE_FILENAME, GS_SOFT_SAMPLE_TABLE_MEM_ID)
#endif

#endif /*_GS_SOFT_PARAM_SAMPLE_H_ */
