#ifndef GS_ADSB_PARAM_HOST_TELEMETRY_H
#define GS_ADSB_PARAM_HOST_TELEMETRY_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a telemetry.
*/

#include <gs/adsb/param/telemetry.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adsb_telemetry_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Current consumption, 1v2 */
    uint16_t cur_1v2;
    /** Current consumption, 2v5 */
    uint16_t cur_2v5;
    /** Current consumption, 3v3 FPGA */
    uint16_t cur_3v3_fpga;
    /** Current consumption, 3v3 ADC */
    uint16_t cur_3v3_adc;
    /** Current consumption, 5v0 Board */
    uint16_t cur_5v0_board;
    /** Current consumption, 3v3 Board */
    uint16_t cur_3v3_board;
    /** Current consumption, 3v3 SD */
    uint16_t cur_3v3_sd;
    /** Average frames/sec over the last 10 seconds */
    uint16_t avg_fps_10sec;
    /** Average frames/sec over the last 1 minute */
    uint16_t avg_fps_1min;
    /** Average frames/sec over the last 5 minutes */
    uint16_t avg_fps_5min;
    /** Number of unique airplanes with at least one position decoded since boot */
    uint32_t plane_count;
    /** Number of frames received since boot */
    uint32_t frame_count;
    /** Number of CRC errors corrected since boot */
    uint32_t crc_corrected;
    /** ICAO24 address of the latest airplane received */
    uint32_t last_icao24;
    /** Latitude of latest airplane received */
    float    last_lat;
    /** Longitude of latest airplane received */
    float    last_lon;
    /** Altitude of latest airplane received */
    uint32_t last_alt;
    /** Timestamp of latest airplane received */
    uint32_t last_ts;
    /** Board boot count */
    uint32_t bootcount;
    /** Board boot cause */
    uint16_t bootcause;
    /** Filler for alignment */
    uint8_t  _filler_0x003a[2];
    /** Current board time in seconds since UNIX epoch */
    uint32_t current_time;
    /** Total number of frames received */
    uint32_t tot_frames;
    /** Total number of unique airplanes with at least one position decoded */
    uint32_t tot_planes;
    /** Total number of CRC errors corrected */
    uint32_t tot_crc_cor;
    /** Total number of CRC errors in FPGA configuration */
    uint32_t fpga_crc_cnt;
    /**  */
    uint32_t flash_lw;
} gs_adsb_telemetry_memory_t;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
