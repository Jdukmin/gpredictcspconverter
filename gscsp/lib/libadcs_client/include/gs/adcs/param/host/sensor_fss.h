#ifndef GS_ADCS_PARAM_HOST_SENSOR_FSS_H
#define GS_ADCS_PARAM_HOST_SENSOR_FSS_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a sensor_fss.
*/

#include <gs/adcs/param/sensor_fss.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_sensor_fss_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** GSSB address of the FSS */
    uint8_t  addr;
    /** CSP node the FSS */
    uint8_t  csp_node;
    /** Filler for alignment */
    uint8_t  _filler_0x0002[2];
    /** Optic height (index 0), offset (x, y - index 1,2), and rotation (index 3) */
    float    p[4];
    /** Quaternion describing the location of the sensor relative to body frame */
    float    q[4];
    /** Specify whether the calibration values are valid or not */
    uint8_t  Cvalid;
    /** Filler for alignment */
    uint8_t  _filler_0x0025[3];
    /** Calibration lookup table for elevation theta index 0 */
    float    Ctheta0[27];
    /** Calibration lookup table for elevation theta index 1 */
    float    Ctheta1[27];
    /** Calibration lookup table for elevation theta index 2 */
    float    Ctheta2[27];
    /** Calibration lookup table for azimuth phi index 0 */
    float    Cphi0[27];
    /** Calibration lookup table for azimuth phi index 1 */
    float    Cphi1[27];
    /** Calibration lookup table for azimuth phi index 2 */
    float    Cphi2[27];
} gs_adcs_sensor_fss_memory_t;

/** Table default values. */
extern const gs_adcs_sensor_fss_memory_t gs_adcs_sensor_fss_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set addr: GSSB address of the FSS */
#define GS_ADCS_SENSOR_FSS_ADDR_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_ADDR, value, 0)
/** Set addr (no callback): GSSB address of the FSS */
#define GS_ADCS_SENSOR_FSS_ADDR_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_ADDR, value, GS_PARAM_F_NO_CALLBACK)
/** Get addr: GSSB address of the FSS */
#define GS_ADCS_SENSOR_FSS_ADDR_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_ADDR, value, 0)
/** Get addr (no check - return 0 on failure): GSSB address of the FSS */
#define GS_ADCS_SENSOR_FSS_ADDR_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_ADDR, 0)
/** Set csp_node: CSP node the FSS */
#define GS_ADCS_SENSOR_FSS_CSP_NODE_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CSP_NODE, value, 0)
/** Set csp_node (no callback): CSP node the FSS */
#define GS_ADCS_SENSOR_FSS_CSP_NODE_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CSP_NODE, value, GS_PARAM_F_NO_CALLBACK)
/** Get csp_node: CSP node the FSS */
#define GS_ADCS_SENSOR_FSS_CSP_NODE_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CSP_NODE, value, 0)
/** Get csp_node (no check - return 0 on failure): CSP node the FSS */
#define GS_ADCS_SENSOR_FSS_CSP_NODE_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CSP_NODE, 0)
/** Set p: Optic height (index 0), offset (x, y - index 1,2), and rotation (index 3) */
#define GS_ADCS_SENSOR_FSS_P_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_P(idx), value, 0)
/** Set p (no callback): Optic height (index 0), offset (x, y - index 1,2), and rotation (index 3) */
#define GS_ADCS_SENSOR_FSS_P_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_P(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get p: Optic height (index 0), offset (x, y - index 1,2), and rotation (index 3) */
#define GS_ADCS_SENSOR_FSS_P_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_P(idx), value, 0)
/** Get p (no check - return 0 on failure): Optic height (index 0), offset (x, y - index 1,2), and rotation (index 3) */
#define GS_ADCS_SENSOR_FSS_P_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_P(idx), 0)
/** Set q: Quaternion describing the location of the sensor relative to body frame */
#define GS_ADCS_SENSOR_FSS_Q_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_Q(idx), value, 0)
/** Set q (no callback): Quaternion describing the location of the sensor relative to body frame */
#define GS_ADCS_SENSOR_FSS_Q_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_Q(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get q: Quaternion describing the location of the sensor relative to body frame */
#define GS_ADCS_SENSOR_FSS_Q_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_Q(idx), value, 0)
/** Get q (no check - return 0 on failure): Quaternion describing the location of the sensor relative to body frame */
#define GS_ADCS_SENSOR_FSS_Q_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_Q(idx), 0)
/** Set Cvalid: Specify whether the calibration values are valid or not */
#define GS_ADCS_SENSOR_FSS_CVALID_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CVALID, value, 0)
/** Set Cvalid (no callback): Specify whether the calibration values are valid or not */
#define GS_ADCS_SENSOR_FSS_CVALID_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CVALID, value, GS_PARAM_F_NO_CALLBACK)
/** Get Cvalid: Specify whether the calibration values are valid or not */
#define GS_ADCS_SENSOR_FSS_CVALID_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CVALID, value, 0)
/** Get Cvalid (no check - return 0 on failure): Specify whether the calibration values are valid or not */
#define GS_ADCS_SENSOR_FSS_CVALID_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CVALID, 0)
/** Set Ctheta0: Calibration lookup table for elevation theta index 0 */
#define GS_ADCS_SENSOR_FSS_CTHETA0_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA0(idx), value, 0)
/** Set Ctheta0 (no callback): Calibration lookup table for elevation theta index 0 */
#define GS_ADCS_SENSOR_FSS_CTHETA0_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA0(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get Ctheta0: Calibration lookup table for elevation theta index 0 */
#define GS_ADCS_SENSOR_FSS_CTHETA0_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA0(idx), value, 0)
/** Get Ctheta0 (no check - return 0 on failure): Calibration lookup table for elevation theta index 0 */
#define GS_ADCS_SENSOR_FSS_CTHETA0_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA0(idx), 0)
/** Set Ctheta1: Calibration lookup table for elevation theta index 1 */
#define GS_ADCS_SENSOR_FSS_CTHETA1_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA1(idx), value, 0)
/** Set Ctheta1 (no callback): Calibration lookup table for elevation theta index 1 */
#define GS_ADCS_SENSOR_FSS_CTHETA1_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA1(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get Ctheta1: Calibration lookup table for elevation theta index 1 */
#define GS_ADCS_SENSOR_FSS_CTHETA1_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA1(idx), value, 0)
/** Get Ctheta1 (no check - return 0 on failure): Calibration lookup table for elevation theta index 1 */
#define GS_ADCS_SENSOR_FSS_CTHETA1_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA1(idx), 0)
/** Set Ctheta2: Calibration lookup table for elevation theta index 2 */
#define GS_ADCS_SENSOR_FSS_CTHETA2_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA2(idx), value, 0)
/** Set Ctheta2 (no callback): Calibration lookup table for elevation theta index 2 */
#define GS_ADCS_SENSOR_FSS_CTHETA2_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA2(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get Ctheta2: Calibration lookup table for elevation theta index 2 */
#define GS_ADCS_SENSOR_FSS_CTHETA2_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA2(idx), value, 0)
/** Get Ctheta2 (no check - return 0 on failure): Calibration lookup table for elevation theta index 2 */
#define GS_ADCS_SENSOR_FSS_CTHETA2_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CTHETA2(idx), 0)
/** Set Cphi0: Calibration lookup table for azimuth phi index 0 */
#define GS_ADCS_SENSOR_FSS_CPHI0_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI0(idx), value, 0)
/** Set Cphi0 (no callback): Calibration lookup table for azimuth phi index 0 */
#define GS_ADCS_SENSOR_FSS_CPHI0_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI0(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get Cphi0: Calibration lookup table for azimuth phi index 0 */
#define GS_ADCS_SENSOR_FSS_CPHI0_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI0(idx), value, 0)
/** Get Cphi0 (no check - return 0 on failure): Calibration lookup table for azimuth phi index 0 */
#define GS_ADCS_SENSOR_FSS_CPHI0_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI0(idx), 0)
/** Set Cphi1: Calibration lookup table for azimuth phi index 1 */
#define GS_ADCS_SENSOR_FSS_CPHI1_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI1(idx), value, 0)
/** Set Cphi1 (no callback): Calibration lookup table for azimuth phi index 1 */
#define GS_ADCS_SENSOR_FSS_CPHI1_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI1(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get Cphi1: Calibration lookup table for azimuth phi index 1 */
#define GS_ADCS_SENSOR_FSS_CPHI1_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI1(idx), value, 0)
/** Get Cphi1 (no check - return 0 on failure): Calibration lookup table for azimuth phi index 1 */
#define GS_ADCS_SENSOR_FSS_CPHI1_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI1(idx), 0)
/** Set Cphi2: Calibration lookup table for azimuth phi index 2 */
#define GS_ADCS_SENSOR_FSS_CPHI2_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI2(idx), value, 0)
/** Set Cphi2 (no callback): Calibration lookup table for azimuth phi index 2 */
#define GS_ADCS_SENSOR_FSS_CPHI2_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI2(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get Cphi2: Calibration lookup table for azimuth phi index 2 */
#define GS_ADCS_SENSOR_FSS_CPHI2_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI2(idx), value, 0)
/** Get Cphi2 (no check - return 0 on failure): Calibration lookup table for azimuth phi index 2 */
#define GS_ADCS_SENSOR_FSS_CPHI2_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_FSS_TABLE_ID), GS_ADCS_SENSOR_FSS_CPHI2(idx), 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
