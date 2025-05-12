#ifndef GS_ADCS_PARAM_HOST_SENSOR_COMMON_H
#define GS_ADCS_PARAM_HOST_SENSOR_COMMON_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a sensor_common.
*/

#include <gs/adcs/param/sensor_common.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_sensor_common_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Number of FSS attached to GSSB */
    uint8_t  fss_num;
    /** Filler for alignment */
    uint8_t  _filler_0x0001[3];
    /** Combined dark threshold for sensor */
    float    fss_darkth;
    /** Individual dark threshold for sensor */
    float    fss_idarkth;
    /** Individual bright threshold */
    float    fss_brightth;
    /** Enable the GPS module */
    bool     en_gps;
    /** Enable system-timesync from GNSS */
    bool     en_gps_tsync;
    /** Enable VARF output */
    bool     en_gps_varf;
    /** Filler for alignment */
    uint8_t  _fillerx_0x0013[1];
} gs_adcs_sensor_common_memory_t;

/** Table default values. */
extern const gs_adcs_sensor_common_memory_t gs_adcs_sensor_common_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set fss_num: Number of FSS attached to GSSB */
#define GS_ADCS_SENSOR_COMMON_FSS_NUM_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_NUM, value, 0)
/** Set fss_num (no callback): Number of FSS attached to GSSB */
#define GS_ADCS_SENSOR_COMMON_FSS_NUM_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_NUM, value, GS_PARAM_F_NO_CALLBACK)
/** Get fss_num: Number of FSS attached to GSSB */
#define GS_ADCS_SENSOR_COMMON_FSS_NUM_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_NUM, value, 0)
/** Get fss_num (no check - return 0 on failure): Number of FSS attached to GSSB */
#define GS_ADCS_SENSOR_COMMON_FSS_NUM_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_NUM, 0)
/** Set fss_darkth: Combined dark threshold for sensor */
#define GS_ADCS_SENSOR_COMMON_FSS_DARKTH_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_DARKTH, value, 0)
/** Set fss_darkth (no callback): Combined dark threshold for sensor */
#define GS_ADCS_SENSOR_COMMON_FSS_DARKTH_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_DARKTH, value, GS_PARAM_F_NO_CALLBACK)
/** Get fss_darkth: Combined dark threshold for sensor */
#define GS_ADCS_SENSOR_COMMON_FSS_DARKTH_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_DARKTH, value, 0)
/** Get fss_darkth (no check - return 0 on failure): Combined dark threshold for sensor */
#define GS_ADCS_SENSOR_COMMON_FSS_DARKTH_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_DARKTH, 0)
/** Set fss_idarkth: Individual dark threshold for sensor */
#define GS_ADCS_SENSOR_COMMON_FSS_IDARKTH_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_IDARKTH, value, 0)
/** Set fss_idarkth (no callback): Individual dark threshold for sensor */
#define GS_ADCS_SENSOR_COMMON_FSS_IDARKTH_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_IDARKTH, value, GS_PARAM_F_NO_CALLBACK)
/** Get fss_idarkth: Individual dark threshold for sensor */
#define GS_ADCS_SENSOR_COMMON_FSS_IDARKTH_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_IDARKTH, value, 0)
/** Get fss_idarkth (no check - return 0 on failure): Individual dark threshold for sensor */
#define GS_ADCS_SENSOR_COMMON_FSS_IDARKTH_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_IDARKTH, 0)
/** Set fss_brightth: Individual bright threshold */
#define GS_ADCS_SENSOR_COMMON_FSS_BRIGHTTH_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_BRIGHTTH, value, 0)
/** Set fss_brightth (no callback): Individual bright threshold */
#define GS_ADCS_SENSOR_COMMON_FSS_BRIGHTTH_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_BRIGHTTH, value, GS_PARAM_F_NO_CALLBACK)
/** Get fss_brightth: Individual bright threshold */
#define GS_ADCS_SENSOR_COMMON_FSS_BRIGHTTH_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_BRIGHTTH, value, 0)
/** Get fss_brightth (no check - return 0 on failure): Individual bright threshold */
#define GS_ADCS_SENSOR_COMMON_FSS_BRIGHTTH_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_FSS_BRIGHTTH, 0)
/** Set en_gps: Enable the GPS module */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS, value, 0)
/** Set en_gps (no callback): Enable the GPS module */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_gps: Enable the GPS module */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS, value, 0)
/** Get en_gps (no check - return 0 on failure): Enable the GPS module */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS, 0)
/** Set en_gps_tsync: Enable system-timesync from GNSS */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_TSYNC_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS_TSYNC, value, 0)
/** Set en_gps_tsync (no callback): Enable system-timesync from GNSS */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_TSYNC_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS_TSYNC, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_gps_tsync: Enable system-timesync from GNSS */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_TSYNC_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS_TSYNC, value, 0)
/** Get en_gps_tsync (no check - return 0 on failure): Enable system-timesync from GNSS */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_TSYNC_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS_TSYNC, 0)
/** Set en_gps_varf: Enable VARF output */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_VARF_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS_VARF, value, 0)
/** Set en_gps_varf (no callback): Enable VARF output */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_VARF_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS_VARF, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_gps_varf: Enable VARF output */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_VARF_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS_VARF, value, 0)
/** Get en_gps_varf (no check - return 0 on failure): Enable VARF output */
#define GS_ADCS_SENSOR_COMMON_EN_GPS_VARF_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_SENSOR_COMMON_TABLE_ID), GS_ADCS_SENSOR_COMMON_EN_GPS_VARF, 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
