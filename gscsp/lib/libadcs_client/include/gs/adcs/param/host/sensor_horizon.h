#ifndef GS_ADCS_PARAM_HOST_SENSOR_HORIZON_H
#define GS_ADCS_PARAM_HOST_SENSOR_HORIZON_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a sensor_horizon.
*/

#include <gs/adcs/param/sensor_horizon.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_sensor_horizon_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Enable disable HTPA task */
    bool     enable_task;
    /** HTPA sample time divider */
    uint8_t  htpa_div;
    /** I2C address of the horizon sensor */
    uint8_t  addr[4];
    /** I2C address of the horizon sensor eeprom */
    uint8_t  addr_eeprom[4];
    /** Filler for alignment */
    uint8_t  _filler_0x000a[2];
    /** Focal length of the horizon sensor */
    float    focal_len[4];
    /** Pixle pitch */
    float    px_pitch[4];
    /** Pixle size */
    float    px_size[4];
    /** Radial distortion coefficients 4*[k1 k2] */
    float    dis_coeff[8];
    /** Gradient threshold for the estimation algorithm (tuning parameter) */
    float    grad_thrs[4];
    /** enable the horizon sensor  */
    bool     enable[4];
    /** Quaternion describing the orientation of the sensor relative to the body frame */
    float    htpa0_q[4];
    /** Quaternion describing the orientation of the sensor relative to the body frame */
    float    htpa1_q[4];
    /** Quaternion describing the orientation of the sensor relative to the body frame */
    float    htpa2_q[4];
    /** Quaternion describing the orientation of the sensor relative to the body frame */
    float    htpa3_q[4];
} gs_adcs_sensor_horizon_memory_t;

/** Table default values. */
extern const gs_adcs_sensor_horizon_memory_t gs_adcs_sensor_horizon_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set enable_task: Enable disable HTPA task */
#define GS_ADCS_SENSOR_HORIZON_ENABLE_TASK_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ENABLE_TASK, value, 0)
/** Set enable_task (no callback): Enable disable HTPA task */
#define GS_ADCS_SENSOR_HORIZON_ENABLE_TASK_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ENABLE_TASK, value, GS_PARAM_F_NO_CALLBACK)
/** Get enable_task: Enable disable HTPA task */
#define GS_ADCS_SENSOR_HORIZON_ENABLE_TASK_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ENABLE_TASK, value, 0)
/** Get enable_task (no check - return 0 on failure): Enable disable HTPA task */
#define GS_ADCS_SENSOR_HORIZON_ENABLE_TASK_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ENABLE_TASK, 0)
/** Set htpa_div: HTPA sample time divider */
#define GS_ADCS_SENSOR_HORIZON_HTPA_DIV_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA_DIV, value, 0)
/** Set htpa_div (no callback): HTPA sample time divider */
#define GS_ADCS_SENSOR_HORIZON_HTPA_DIV_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA_DIV, value, GS_PARAM_F_NO_CALLBACK)
/** Get htpa_div: HTPA sample time divider */
#define GS_ADCS_SENSOR_HORIZON_HTPA_DIV_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA_DIV, value, 0)
/** Get htpa_div (no check - return 0 on failure): HTPA sample time divider */
#define GS_ADCS_SENSOR_HORIZON_HTPA_DIV_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA_DIV, 0)
/** Set addr: I2C address of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_ADDR_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ADDR(idx), value, 0)
/** Set addr (no callback): I2C address of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_ADDR_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ADDR(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get addr: I2C address of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_ADDR_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ADDR(idx), value, 0)
/** Get addr (no check - return 0 on failure): I2C address of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_ADDR_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ADDR(idx), 0)
/** Set addr_eeprom: I2C address of the horizon sensor eeprom */
#define GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM(idx), value, 0)
/** Set addr_eeprom (no callback): I2C address of the horizon sensor eeprom */
#define GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get addr_eeprom: I2C address of the horizon sensor eeprom */
#define GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM(idx), value, 0)
/** Get addr_eeprom (no check - return 0 on failure): I2C address of the horizon sensor eeprom */
#define GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM(idx), 0)
/** Set focal_len: Focal length of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_FOCAL_LEN_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_FOCAL_LEN(idx), value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set focal_len (no callback): Focal length of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_FOCAL_LEN_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_FOCAL_LEN(idx), value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get focal_len: Focal length of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_FOCAL_LEN_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_FOCAL_LEN(idx), value, 0)
/** Get focal_len (no check - return 0 on failure): Focal length of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_FOCAL_LEN_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_FOCAL_LEN(idx), 0)
/** Set px_pitch: Pixle pitch */
#define GS_ADCS_SENSOR_HORIZON_PX_PITCH_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_PX_PITCH(idx), value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set px_pitch (no callback): Pixle pitch */
#define GS_ADCS_SENSOR_HORIZON_PX_PITCH_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_PX_PITCH(idx), value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get px_pitch: Pixle pitch */
#define GS_ADCS_SENSOR_HORIZON_PX_PITCH_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_PX_PITCH(idx), value, 0)
/** Get px_pitch (no check - return 0 on failure): Pixle pitch */
#define GS_ADCS_SENSOR_HORIZON_PX_PITCH_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_PX_PITCH(idx), 0)
/** Set px_size: Pixle size */
#define GS_ADCS_SENSOR_HORIZON_PX_SIZE_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_PX_SIZE(idx), value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set px_size (no callback): Pixle size */
#define GS_ADCS_SENSOR_HORIZON_PX_SIZE_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_PX_SIZE(idx), value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get px_size: Pixle size */
#define GS_ADCS_SENSOR_HORIZON_PX_SIZE_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_PX_SIZE(idx), value, 0)
/** Get px_size (no check - return 0 on failure): Pixle size */
#define GS_ADCS_SENSOR_HORIZON_PX_SIZE_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_PX_SIZE(idx), 0)
/** Set dis_coeff: Radial distortion coefficients 4*[k1 k2] */
#define GS_ADCS_SENSOR_HORIZON_DIS_COEFF_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_DIS_COEFF(idx), value, 0)
/** Set dis_coeff (no callback): Radial distortion coefficients 4*[k1 k2] */
#define GS_ADCS_SENSOR_HORIZON_DIS_COEFF_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_DIS_COEFF(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get dis_coeff: Radial distortion coefficients 4*[k1 k2] */
#define GS_ADCS_SENSOR_HORIZON_DIS_COEFF_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_DIS_COEFF(idx), value, 0)
/** Get dis_coeff (no check - return 0 on failure): Radial distortion coefficients 4*[k1 k2] */
#define GS_ADCS_SENSOR_HORIZON_DIS_COEFF_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_DIS_COEFF(idx), 0)
/** Set grad_thrs: Gradient threshold for the estimation algorithm (tuning parameter) */
#define GS_ADCS_SENSOR_HORIZON_GRAD_THRS_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_GRAD_THRS(idx), value, 0)
/** Set grad_thrs (no callback): Gradient threshold for the estimation algorithm (tuning parameter) */
#define GS_ADCS_SENSOR_HORIZON_GRAD_THRS_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_GRAD_THRS(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get grad_thrs: Gradient threshold for the estimation algorithm (tuning parameter) */
#define GS_ADCS_SENSOR_HORIZON_GRAD_THRS_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_GRAD_THRS(idx), value, 0)
/** Get grad_thrs (no check - return 0 on failure): Gradient threshold for the estimation algorithm (tuning parameter) */
#define GS_ADCS_SENSOR_HORIZON_GRAD_THRS_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_GRAD_THRS(idx), 0)
/** Set enable: enable the horizon sensor  */
#define GS_ADCS_SENSOR_HORIZON_ENABLE_SET(idx, value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ENABLE(idx), value, 0)
/** Set enable (no callback): enable the horizon sensor  */
#define GS_ADCS_SENSOR_HORIZON_ENABLE_SET_NO_CALLBACK(idx, value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ENABLE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get enable: enable the horizon sensor  */
#define GS_ADCS_SENSOR_HORIZON_ENABLE_GET(idx, value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ENABLE(idx), value, 0)
/** Get enable (no check - return 0 on failure): enable the horizon sensor  */
#define GS_ADCS_SENSOR_HORIZON_ENABLE_GET_NC(idx) gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_ENABLE(idx), 0)
/** Set htpa0_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA0_Q_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA0_Q(idx), value, 0)
/** Set htpa0_q (no callback): Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA0_Q_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA0_Q(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get htpa0_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA0_Q_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA0_Q(idx), value, 0)
/** Get htpa0_q (no check - return 0 on failure): Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA0_Q_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA0_Q(idx), 0)
/** Set htpa1_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA1_Q_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA1_Q(idx), value, 0)
/** Set htpa1_q (no callback): Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA1_Q_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA1_Q(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get htpa1_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA1_Q_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA1_Q(idx), value, 0)
/** Get htpa1_q (no check - return 0 on failure): Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA1_Q_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA1_Q(idx), 0)
/** Set htpa2_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA2_Q_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA2_Q(idx), value, 0)
/** Set htpa2_q (no callback): Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA2_Q_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA2_Q(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get htpa2_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA2_Q_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA2_Q(idx), value, 0)
/** Get htpa2_q (no check - return 0 on failure): Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA2_Q_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA2_Q(idx), 0)
/** Set htpa3_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA3_Q_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA3_Q(idx), value, 0)
/** Set htpa3_q (no callback): Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA3_Q_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA3_Q(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get htpa3_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA3_Q_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA3_Q(idx), value, 0)
/** Get htpa3_q (no check - return 0 on failure): Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA3_Q_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_HORIZON_TABLE_ID), GS_ADCS_SENSOR_HORIZON_HTPA3_Q(idx), 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
