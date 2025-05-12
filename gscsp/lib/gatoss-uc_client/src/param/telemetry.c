/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/adsb/param/host/telemetry.h>
#include <gs/util/pgm.h>

const gs_param_table_row_t gs_adsb_telemetry_table[] = {
    {.name = "cur_1v2",       .addr = GS_ADSB_TELEMETRY_CUR_1V2,                         .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "cur_2v5",       .addr = GS_ADSB_TELEMETRY_CUR_2V5,                         .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "cur_3v3_fpga",  .addr = GS_ADSB_TELEMETRY_CUR_3V3_FPGA,                    .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "cur_3v3_adc",   .addr = GS_ADSB_TELEMETRY_CUR_3V3_ADC,                     .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "cur_5v0_board", .addr = GS_ADSB_TELEMETRY_CUR_5V0_BOARD,                   .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "cur_3v3_board", .addr = GS_ADSB_TELEMETRY_CUR_3V3_BOARD,                   .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "cur_3v3_sd",    .addr = GS_ADSB_TELEMETRY_CUR_3V3_SD,                      .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "avg_fps_10sec", .addr = GS_ADSB_TELEMETRY_AVG_FPS_10SEC,                   .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "avg_fps_1min",  .addr = GS_ADSB_TELEMETRY_AVG_FPS_1MIN,                    .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "avg_fps_5min",  .addr = GS_ADSB_TELEMETRY_AVG_FPS_5MIN,                    .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "plane_count",   .addr = GS_ADSB_TELEMETRY_PLANE_COUNT,                     .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "frame_count",   .addr = GS_ADSB_TELEMETRY_FRAME_COUNT,                     .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "crc_corrected", .addr = GS_ADSB_TELEMETRY_CRC_CORRECTED,                   .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "last_icao24",   .addr = GS_ADSB_TELEMETRY_LAST_ICAO24,                     .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "last_lat",      .addr = GS_ADSB_TELEMETRY_LAST_LAT,                        .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "last_lon",      .addr = GS_ADSB_TELEMETRY_LAST_LON,                        .type = GS_PARAM_FLOAT,   .size =   4, .array_size =  1, .flags = 0},
    {.name = "last_alt",      .addr = GS_ADSB_TELEMETRY_LAST_ALT,                        .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "last_ts",       .addr = GS_ADSB_TELEMETRY_LAST_TS,                         .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "bootcount",     .addr = GS_ADSB_TELEMETRY_BOOTCOUNT,                       .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "bootcause",     .addr = GS_ADSB_TELEMETRY_BOOTCAUSE,                       .type = GS_PARAM_UINT16,  .size =   2, .array_size =  1, .flags = 0},
    {.name = "current_time",  .addr = GS_ADSB_TELEMETRY_CURRENT_TIME,                    .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "tot_frames",    .addr = GS_ADSB_TELEMETRY_TOT_FRAMES,                      .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "tot_planes",    .addr = GS_ADSB_TELEMETRY_TOT_PLANES,                      .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "tot_crc_cor",   .addr = GS_ADSB_TELEMETRY_TOT_CRC_COR,                     .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "fpga_crc_cnt",  .addr = GS_ADSB_TELEMETRY_FPGA_CRC_CNT,                    .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
    {.name = "flash_lw",      .addr = GS_ADSB_TELEMETRY_FLASH_LW,                        .type = GS_PARAM_UINT32,  .size =   4, .array_size =  1, .flags = 0},
};

