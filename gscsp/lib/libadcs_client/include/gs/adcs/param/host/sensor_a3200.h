#ifndef GS_ADCS_PARAM_HOST_SENSOR_A3200_H
#define GS_ADCS_PARAM_HOST_SENSOR_A3200_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a sensor_a3200.
*/

#include <gs/adcs/param/sensor_a3200.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_sensor_a3200_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Magnetometer offset vector [x y z] */
    float    mag_offset[3];
    /** Magnetometer scale vector [x y z] */
    float    mag_scale[3];
    /** Rotation matrix for magnetometer scale compensation */
    float    mag_rotation[9];
    /** Transpose of rotation matrix (read only) */
    float    mag_rot_t[9];
    /** Magnetometer expected max field length */
    float    mag_max;
    /** Magnetometer axis vector [x y z] */
    uint8_t  mag_axis[3];
    /** Magnetometer sign vector [x y z] */
    int8_t   mag_sign[3];
    /** Magnetometer gain calibration value */
    int8_t   mag_gain;
    /** Enable/disable magnetometer axis mesurement */
    uint8_t  mag_enable[3];
    /** Filler for alignment */
    uint8_t  _filler_0x006e[2];
    /** Gyro scale */
    float    gyro_scale[3];
    /** Gyro offset */
    float    gyro_offset[3];
    /** Gyro temperature scale */
    float    gyro_temp[3];
    /** Gyro axis */
    uint8_t  gyro_axis[3];
    /** Gyro sign */
    int8_t   gyro_sign[3];
    /** Enable/disable gyro axis mesurement */
    int8_t   gyro_enable[3];
    /** Filler for alignment */
    uint8_t  _filler_end[3];
} gs_adcs_sensor_a3200_memory_t;

/** Table default values. */
extern const gs_adcs_sensor_a3200_memory_t gs_adcs_sensor_a3200_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set mag_offset: Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_OFFSET_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_OFFSET(idx), value, 0)
/** Set mag_offset (no callback): Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_OFFSET_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_OFFSET(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_offset: Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_OFFSET_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_OFFSET(idx), value, 0)
/** Get mag_offset (no check - return 0 on failure): Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_OFFSET_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_OFFSET(idx), 0)
/** Set mag_scale: Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SCALE_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_SCALE(idx), value, 0)
/** Set mag_scale (no callback): Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SCALE_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_SCALE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_scale: Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SCALE_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_SCALE(idx), value, 0)
/** Get mag_scale (no check - return 0 on failure): Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SCALE_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_SCALE(idx), 0)
/** Set mag_rotation: Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_A3200_MAG_ROTATION_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ROTATION(idx), value, 0)
/** Set mag_rotation (no callback): Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_A3200_MAG_ROTATION_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ROTATION(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_rotation: Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_A3200_MAG_ROTATION_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ROTATION(idx), value, 0)
/** Get mag_rotation (no check - return 0 on failure): Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_A3200_MAG_ROTATION_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ROTATION(idx), 0)
/** Set mag_rot_t: Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_A3200_MAG_ROT_T_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ROT_T(idx), value, 0)
/** Set mag_rot_t (no callback): Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_A3200_MAG_ROT_T_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ROT_T(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_rot_t: Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_A3200_MAG_ROT_T_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ROT_T(idx), value, 0)
/** Get mag_rot_t (no check - return 0 on failure): Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_A3200_MAG_ROT_T_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ROT_T(idx), 0)
/** Set mag_max: Magnetometer expected max field length */
#define GS_ADCS_SENSOR_A3200_MAG_MAX_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_MAX, value, 0)
/** Set mag_max (no callback): Magnetometer expected max field length */
#define GS_ADCS_SENSOR_A3200_MAG_MAX_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_MAX, value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_max: Magnetometer expected max field length */
#define GS_ADCS_SENSOR_A3200_MAG_MAX_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_MAX, value, 0)
/** Get mag_max (no check - return 0 on failure): Magnetometer expected max field length */
#define GS_ADCS_SENSOR_A3200_MAG_MAX_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_MAX, 0)
/** Set mag_axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_AXIS_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_AXIS(idx), value, 0)
/** Set mag_axis (no callback): Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_AXIS_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_AXIS(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_AXIS_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_AXIS(idx), value, 0)
/** Get mag_axis (no check - return 0 on failure): Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_AXIS_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_AXIS(idx), 0)
/** Set mag_sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SIGN_SET(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_SIGN(idx), value, 0)
/** Set mag_sign (no callback): Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SIGN_SET_NO_CALLBACK(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_SIGN(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SIGN_GET(idx, value) gs_param_get_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_SIGN(idx), value, 0)
/** Get mag_sign (no check - return 0 on failure): Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SIGN_GET_NC(idx) gs_param_get_int8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_SIGN(idx), 0)
/** Set mag_gain: Magnetometer gain calibration value */
#define GS_ADCS_SENSOR_A3200_MAG_GAIN_SET(value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_GAIN, value, 0)
/** Set mag_gain (no callback): Magnetometer gain calibration value */
#define GS_ADCS_SENSOR_A3200_MAG_GAIN_SET_NO_CALLBACK(value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_GAIN, value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_gain: Magnetometer gain calibration value */
#define GS_ADCS_SENSOR_A3200_MAG_GAIN_GET(value) gs_param_get_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_GAIN, value, 0)
/** Get mag_gain (no check - return 0 on failure): Magnetometer gain calibration value */
#define GS_ADCS_SENSOR_A3200_MAG_GAIN_GET_NC() gs_param_get_int8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_GAIN, 0)
/** Set mag_enable: Enable/disable magnetometer axis mesurement */
#define GS_ADCS_SENSOR_A3200_MAG_ENABLE_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ENABLE(idx), value, 0)
/** Set mag_enable (no callback): Enable/disable magnetometer axis mesurement */
#define GS_ADCS_SENSOR_A3200_MAG_ENABLE_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ENABLE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_enable: Enable/disable magnetometer axis mesurement */
#define GS_ADCS_SENSOR_A3200_MAG_ENABLE_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ENABLE(idx), value, 0)
/** Get mag_enable (no check - return 0 on failure): Enable/disable magnetometer axis mesurement */
#define GS_ADCS_SENSOR_A3200_MAG_ENABLE_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_MAG_ENABLE(idx), 0)
/** Set gyro_scale: Gyro scale */
#define GS_ADCS_SENSOR_A3200_GYRO_SCALE_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_SCALE(idx), value, 0)
/** Set gyro_scale (no callback): Gyro scale */
#define GS_ADCS_SENSOR_A3200_GYRO_SCALE_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_SCALE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get gyro_scale: Gyro scale */
#define GS_ADCS_SENSOR_A3200_GYRO_SCALE_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_SCALE(idx), value, 0)
/** Get gyro_scale (no check - return 0 on failure): Gyro scale */
#define GS_ADCS_SENSOR_A3200_GYRO_SCALE_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_SCALE(idx), 0)
/** Set gyro_offset: Gyro offset */
#define GS_ADCS_SENSOR_A3200_GYRO_OFFSET_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_OFFSET(idx), value, 0)
/** Set gyro_offset (no callback): Gyro offset */
#define GS_ADCS_SENSOR_A3200_GYRO_OFFSET_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_OFFSET(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get gyro_offset: Gyro offset */
#define GS_ADCS_SENSOR_A3200_GYRO_OFFSET_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_OFFSET(idx), value, 0)
/** Get gyro_offset (no check - return 0 on failure): Gyro offset */
#define GS_ADCS_SENSOR_A3200_GYRO_OFFSET_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_OFFSET(idx), 0)
/** Set gyro_temp: Gyro temperature scale */
#define GS_ADCS_SENSOR_A3200_GYRO_TEMP_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_TEMP(idx), value, 0)
/** Set gyro_temp (no callback): Gyro temperature scale */
#define GS_ADCS_SENSOR_A3200_GYRO_TEMP_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_TEMP(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get gyro_temp: Gyro temperature scale */
#define GS_ADCS_SENSOR_A3200_GYRO_TEMP_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_TEMP(idx), value, 0)
/** Get gyro_temp (no check - return 0 on failure): Gyro temperature scale */
#define GS_ADCS_SENSOR_A3200_GYRO_TEMP_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_TEMP(idx), 0)
/** Set gyro_axis: Gyro axis */
#define GS_ADCS_SENSOR_A3200_GYRO_AXIS_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_AXIS(idx), value, 0)
/** Set gyro_axis (no callback): Gyro axis */
#define GS_ADCS_SENSOR_A3200_GYRO_AXIS_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_AXIS(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get gyro_axis: Gyro axis */
#define GS_ADCS_SENSOR_A3200_GYRO_AXIS_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_AXIS(idx), value, 0)
/** Get gyro_axis (no check - return 0 on failure): Gyro axis */
#define GS_ADCS_SENSOR_A3200_GYRO_AXIS_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_AXIS(idx), 0)
/** Set gyro_sign: Gyro sign */
#define GS_ADCS_SENSOR_A3200_GYRO_SIGN_SET(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_SIGN(idx), value, 0)
/** Set gyro_sign (no callback): Gyro sign */
#define GS_ADCS_SENSOR_A3200_GYRO_SIGN_SET_NO_CALLBACK(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_SIGN(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get gyro_sign: Gyro sign */
#define GS_ADCS_SENSOR_A3200_GYRO_SIGN_GET(idx, value) gs_param_get_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_SIGN(idx), value, 0)
/** Get gyro_sign (no check - return 0 on failure): Gyro sign */
#define GS_ADCS_SENSOR_A3200_GYRO_SIGN_GET_NC(idx) gs_param_get_int8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_SIGN(idx), 0)
/** Set gyro_enable: Enable/disable gyro axis mesurement */
#define GS_ADCS_SENSOR_A3200_GYRO_ENABLE_SET(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_ENABLE(idx), value, 0)
/** Set gyro_enable (no callback): Enable/disable gyro axis mesurement */
#define GS_ADCS_SENSOR_A3200_GYRO_ENABLE_SET_NO_CALLBACK(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_ENABLE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get gyro_enable: Enable/disable gyro axis mesurement */
#define GS_ADCS_SENSOR_A3200_GYRO_ENABLE_GET(idx, value) gs_param_get_int8(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_ENABLE(idx), value, 0)
/** Get gyro_enable (no check - return 0 on failure): Enable/disable gyro axis mesurement */
#define GS_ADCS_SENSOR_A3200_GYRO_ENABLE_GET_NC(idx) gs_param_get_int8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200_GYRO_ENABLE(idx), 0)
/** Set _filler_end: Filler for alignment */
#define GS_ADCS_SENSOR_A3200__FILLER_END_SET(value, value_size) gs_param_set_data(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200__FILLER_END, value, value_size, 0)
/** Set _filler_end (no callback): Filler for alignment */
#define GS_ADCS_SENSOR_A3200__FILLER_END_SET_NO_CALLBACK(value, value_size) gs_param_set_data(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200__FILLER_END, value, value_size, GS_PARAM_F_NO_CALLBACK)
/** Get _filler_end: Filler for alignment */
#define GS_ADCS_SENSOR_A3200__FILLER_END_GET(buf, buf_size) gs_param_get_data(gs_param_table_by_id(GS_ADCS_SENSOR_A3200_TABLE_ID), GS_ADCS_SENSOR_A3200__FILLER_END, buf, buf_size, 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
