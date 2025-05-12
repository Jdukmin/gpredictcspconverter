/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adcs/param/host/sensor_common.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adcs_sensor_common_table[] = {
    {.name = "fss_num",       .addr = GS_ADCS_SENSOR_COMMON_FSS_NUM,                     .type = GS_PARAM_UINT8,   .size =   1, .array_size =  1, .flags = 0},
    {.name = "fss_darkth",    .addr = GS_ADCS_SENSOR_COMMON_FSS_DARKTH,                  .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "fss_idarkth",   .addr = GS_ADCS_SENSOR_COMMON_FSS_IDARKTH,                 .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "fss_brightth",  .addr = GS_ADCS_SENSOR_COMMON_FSS_BRIGHTTH,                .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "en_gps",        .addr = GS_ADCS_SENSOR_COMMON_EN_GPS,                      .type = GS_PARAM_BOOL,    .size =   1, .array_size =  1, .flags = 0},
    {.name = "en_gps_tsync",  .addr = GS_ADCS_SENSOR_COMMON_EN_GPS_TSYNC,                .type = GS_PARAM_BOOL,    .size =   1, .array_size =  1, .flags = 0},
    {.name = "en_gps_varf",   .addr = GS_ADCS_SENSOR_COMMON_EN_GPS_VARF,                 .type = GS_PARAM_BOOL,    .size =   1, .array_size =  1, .flags = 0},
};

const gs_adcs_sensor_common_memory_t gs_adcs_sensor_common_default_values GS_PGM_OBJECT = {
    .fss_num = 6,
    .fss_darkth = 50000.0,
    .fss_idarkth = 10000.0,
    .fss_brightth = 32000.0,
    .en_gps = false,
    .en_gps_tsync = false,
    .en_gps_varf = false,
};

