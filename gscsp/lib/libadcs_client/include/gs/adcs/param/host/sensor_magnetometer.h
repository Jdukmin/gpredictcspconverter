#ifndef GS_ADCS_PARAM_HOST_SENSOR_MAGNETOMETER_H
#define GS_ADCS_PARAM_HOST_SENSOR_MAGNETOMETER_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a sensor_magnetometer.
*/

#include <gs/adcs/param/sensor_magnetometer.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_sensor_magnetometer_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Magnetometer offset vector [x y z] */
    float    offset[3];
    /** Magnetometer scale vector [x y z] */
    float    scale[3];
    /** Rotation matrix for magnetometer scale compensation */
    float    rotation[9];
    /** Transpose of rotation matrix (read only) */
    float    rot_trans[9];
    /** Magnetometer expected max field length */
    float    max;
    /** Magnetometer axis vector [x y z] */
    uint8_t  axis[3];
    /** Magnetometer sign vector [x y z] */
    int8_t   sign[3];
    /** Magnetometer enable vector [x y z] */
    uint8_t  enable[3];
    /** Magnetometer gain calibration value */
    int8_t   gain;
    /** Magnetometer address (only used in external magnetometer) */
    uint8_t  addr;
    /** Magnetometer temperature address (only used in external magnetometer) */
    uint8_t  temp_addr;
} gs_adcs_sensor_magnetometer_memory_t;

/** Table default values. */
extern const gs_adcs_sensor_magnetometer_memory_t gs_adcs_sensor_magnetometer_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set offset: Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_OFFSET_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_OFFSET(idx), value, 0)
/** Set offset (no callback): Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_OFFSET_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_OFFSET(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get offset: Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_OFFSET_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_OFFSET(idx), value, 0)
/** Get offset (no check - return 0 on failure): Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_OFFSET_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_OFFSET(idx), 0)
/** Set scale: Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SCALE_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_SCALE(idx), value, 0)
/** Set scale (no callback): Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SCALE_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_SCALE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get scale: Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SCALE_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_SCALE(idx), value, 0)
/** Get scale (no check - return 0 on failure): Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SCALE_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_SCALE(idx), 0)
/** Set rotation: Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROTATION_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ROTATION(idx), value, 0)
/** Set rotation (no callback): Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROTATION_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ROTATION(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get rotation: Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROTATION_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ROTATION(idx), value, 0)
/** Get rotation (no check - return 0 on failure): Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROTATION_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ROTATION(idx), 0)
/** Set rot_trans: Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS(idx), value, 0)
/** Set rot_trans (no callback): Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get rot_trans: Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS(idx), value, 0)
/** Get rot_trans (no check - return 0 on failure): Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS(idx), 0)
/** Set max: Magnetometer expected max field length */
#define GS_ADCS_SENSOR_MAGNETOMETER_MAX_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_MAX, value, 0)
/** Set max (no callback): Magnetometer expected max field length */
#define GS_ADCS_SENSOR_MAGNETOMETER_MAX_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_MAX, value, GS_PARAM_F_NO_CALLBACK)
/** Get max: Magnetometer expected max field length */
#define GS_ADCS_SENSOR_MAGNETOMETER_MAX_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_MAX, value, 0)
/** Get max (no check - return 0 on failure): Magnetometer expected max field length */
#define GS_ADCS_SENSOR_MAGNETOMETER_MAX_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_MAX, 0)
/** Set axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_AXIS_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_AXIS(idx), value, 0)
/** Set axis (no callback): Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_AXIS_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_AXIS(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_AXIS_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_AXIS(idx), value, 0)
/** Get axis (no check - return 0 on failure): Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_AXIS_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_AXIS(idx), 0)
/** Set sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SIGN_SET(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_SIGN(idx), value, 0)
/** Set sign (no callback): Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SIGN_SET_NO_CALLBACK(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_SIGN(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SIGN_GET(idx, value) gs_param_get_int8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_SIGN(idx), value, 0)
/** Get sign (no check - return 0 on failure): Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SIGN_GET_NC(idx) gs_param_get_int8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_SIGN(idx), 0)
/** Set enable: Magnetometer enable vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_ENABLE_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ENABLE(idx), value, 0)
/** Set enable (no callback): Magnetometer enable vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_ENABLE_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ENABLE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get enable: Magnetometer enable vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_ENABLE_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ENABLE(idx), value, 0)
/** Get enable (no check - return 0 on failure): Magnetometer enable vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_ENABLE_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ENABLE(idx), 0)
/** Set gain: Magnetometer gain calibration value */
#define GS_ADCS_SENSOR_MAGNETOMETER_GAIN_SET(value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_GAIN, value, 0)
/** Set gain (no callback): Magnetometer gain calibration value */
#define GS_ADCS_SENSOR_MAGNETOMETER_GAIN_SET_NO_CALLBACK(value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_GAIN, value, GS_PARAM_F_NO_CALLBACK)
/** Get gain: Magnetometer gain calibration value */
#define GS_ADCS_SENSOR_MAGNETOMETER_GAIN_GET(value) gs_param_get_int8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_GAIN, value, 0)
/** Get gain (no check - return 0 on failure): Magnetometer gain calibration value */
#define GS_ADCS_SENSOR_MAGNETOMETER_GAIN_GET_NC() gs_param_get_int8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_GAIN, 0)
/** Set addr: Magnetometer address (only used in external magnetometer) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ADDR_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ADDR, value, 0)
/** Set addr (no callback): Magnetometer address (only used in external magnetometer) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ADDR_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ADDR, value, GS_PARAM_F_NO_CALLBACK)
/** Get addr: Magnetometer address (only used in external magnetometer) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ADDR_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ADDR, value, 0)
/** Get addr (no check - return 0 on failure): Magnetometer address (only used in external magnetometer) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ADDR_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_ADDR, 0)
/** Set temp_addr: Magnetometer temperature address (only used in external magnetometer) */
#define GS_ADCS_SENSOR_MAGNETOMETER_TEMP_ADDR_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_TEMP_ADDR, value, 0)
/** Set temp_addr (no callback): Magnetometer temperature address (only used in external magnetometer) */
#define GS_ADCS_SENSOR_MAGNETOMETER_TEMP_ADDR_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_TEMP_ADDR, value, GS_PARAM_F_NO_CALLBACK)
/** Get temp_addr: Magnetometer temperature address (only used in external magnetometer) */
#define GS_ADCS_SENSOR_MAGNETOMETER_TEMP_ADDR_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_TEMP_ADDR, value, 0)
/** Get temp_addr (no check - return 0 on failure): Magnetometer temperature address (only used in external magnetometer) */
#define GS_ADCS_SENSOR_MAGNETOMETER_TEMP_ADDR_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID), GS_ADCS_SENSOR_MAGNETOMETER_TEMP_ADDR, 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
