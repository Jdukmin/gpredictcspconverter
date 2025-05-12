#ifndef GS_ADSB_PARAM_TELEMETRY_H
#define GS_ADSB_PARAM_TELEMETRY_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a telemetry.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADSB_TELEMETRY_TABLE_NAME                     "telemetry"
/** Table data size (bytes */
#define GS_ADSB_TELEMETRY_TABLE_SIZE                     84 // bytes
/** Table rows (count) */
#define GS_ADSB_TELEMETRY_TABLE_ROWS                     26

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of cur_1v2: Current consumption, 1v2 */
#define GS_ADSB_TELEMETRY_CUR_1V2                                        0                  // 0x0000 uint16
/** Address of cur_2v5: Current consumption, 2v5 */
#define GS_ADSB_TELEMETRY_CUR_2V5                                        2                  // 0x0002 uint16
/** Address of cur_3v3_fpga: Current consumption, 3v3 FPGA */
#define GS_ADSB_TELEMETRY_CUR_3V3_FPGA                                   4                  // 0x0004 uint16
/** Address of cur_3v3_adc: Current consumption, 3v3 ADC */
#define GS_ADSB_TELEMETRY_CUR_3V3_ADC                                    6                  // 0x0006 uint16
/** Address of cur_5v0_board: Current consumption, 5v0 Board */
#define GS_ADSB_TELEMETRY_CUR_5V0_BOARD                                  8                  // 0x0008 uint16
/** Address of cur_3v3_board: Current consumption, 3v3 Board */
#define GS_ADSB_TELEMETRY_CUR_3V3_BOARD                                 10                  // 0x000a uint16
/** Address of cur_3v3_sd: Current consumption, 3v3 SD */
#define GS_ADSB_TELEMETRY_CUR_3V3_SD                                    12                  // 0x000c uint16
/** Address of avg_fps_10sec: Average frames/sec over the last 10 seconds */
#define GS_ADSB_TELEMETRY_AVG_FPS_10SEC                                 14                  // 0x000e uint16
/** Address of avg_fps_1min: Average frames/sec over the last 1 minute */
#define GS_ADSB_TELEMETRY_AVG_FPS_1MIN                                  16                  // 0x0010 uint16
/** Address of avg_fps_5min: Average frames/sec over the last 5 minutes */
#define GS_ADSB_TELEMETRY_AVG_FPS_5MIN                                  18                  // 0x0012 uint16
/** Address of plane_count: Number of unique airplanes with at least one position decoded since boot */
#define GS_ADSB_TELEMETRY_PLANE_COUNT                                   20                  // 0x0014 uint32
/** Address of frame_count: Number of frames received since boot */
#define GS_ADSB_TELEMETRY_FRAME_COUNT                                   24                  // 0x0018 uint32
/** Address of crc_corrected: Number of CRC errors corrected since boot */
#define GS_ADSB_TELEMETRY_CRC_CORRECTED                                 28                  // 0x001c uint32
/** Address of last_icao24: ICAO24 address of the latest airplane received */
#define GS_ADSB_TELEMETRY_LAST_ICAO24                                   32                  // 0x0020 uint32
/** Address of last_lat: Latitude of latest airplane received */
#define GS_ADSB_TELEMETRY_LAST_LAT                                      36                  // 0x0024 float
/** Address of last_lon: Longitude of latest airplane received */
#define GS_ADSB_TELEMETRY_LAST_LON                                      40                  // 0x0028 float
/** Address of last_alt: Altitude of latest airplane received */
#define GS_ADSB_TELEMETRY_LAST_ALT                                      44                  // 0x002c uint32
/** Address of last_ts: Timestamp of latest airplane received */
#define GS_ADSB_TELEMETRY_LAST_TS                                       48                  // 0x0030 uint32
/** Address of bootcount: Board boot count */
#define GS_ADSB_TELEMETRY_BOOTCOUNT                                     52                  // 0x0034 uint32
/** Address of bootcause: Board boot cause */
#define GS_ADSB_TELEMETRY_BOOTCAUSE                                     56                  // 0x0038 uint16
/** Address of current_time: Current board time in seconds since UNIX epoch */
#define GS_ADSB_TELEMETRY_CURRENT_TIME                                  60                  // 0x003c uint32
/** Address of tot_frames: Total number of frames received */
#define GS_ADSB_TELEMETRY_TOT_FRAMES                                    64                  // 0x0040 uint32
/** Address of tot_planes: Total number of unique airplanes with at least one position decoded */
#define GS_ADSB_TELEMETRY_TOT_PLANES                                    68                  // 0x0044 uint32
/** Address of tot_crc_cor: Total number of CRC errors corrected */
#define GS_ADSB_TELEMETRY_TOT_CRC_COR                                   72                  // 0x0048 uint32
/** Address of fpga_crc_cnt: Total number of CRC errors in FPGA configuration */
#define GS_ADSB_TELEMETRY_FPGA_CRC_CNT                                  76                  // 0x004c uint32
/** Address of flash_lw:  */
#define GS_ADSB_TELEMETRY_FLASH_LW                                      80                  // 0x0050 uint32
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
