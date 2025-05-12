#ifndef GS_ADCS_PARAM_SENSOR_COMMON_H
#define GS_ADCS_PARAM_SENSOR_COMMON_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a sensor_common.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_SENSOR_COMMON_TABLE_NAME                 "sensor_common"
/** Table id */
#define GS_ADCS_SENSOR_COMMON_TABLE_ID                   70
/** Legacy table id definition */
#define GS_ADCS_SENSOR_COMMON_TABLE_MEM_ID               70
/** Table data size (bytes */
#define GS_ADCS_SENSOR_COMMON_TABLE_SIZE                 20 // bytes
/** Table rows (count) */
#define GS_ADCS_SENSOR_COMMON_TABLE_ROWS                 7

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of fss_num: Number of FSS attached to GSSB */
#define GS_ADCS_SENSOR_COMMON_FSS_NUM                                    0                  // 0x0000 uint8
/** Address of fss_darkth: Combined dark threshold for sensor */
#define GS_ADCS_SENSOR_COMMON_FSS_DARKTH                                 4                  // 0x0004 float
/** Address of fss_idarkth: Individual dark threshold for sensor */
#define GS_ADCS_SENSOR_COMMON_FSS_IDARKTH                                8                  // 0x0008 float
/** Address of fss_brightth: Individual bright threshold */
#define GS_ADCS_SENSOR_COMMON_FSS_BRIGHTTH                              12                  // 0x000c float
/** Address of en_gps: Enable the GPS module */
#define GS_ADCS_SENSOR_COMMON_EN_GPS                                    16                  // 0x0010 bool
/** Address of en_gps_tsync: Enable system-timesync from GNSS */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_TSYNC                              17                  // 0x0011 bool
/** Address of en_gps_varf: Enable VARF output */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_VARF                               18                  // 0x0012 bool
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
