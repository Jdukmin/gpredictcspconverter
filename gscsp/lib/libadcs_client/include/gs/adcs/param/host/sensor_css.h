#ifndef GS_ADCS_PARAM_HOST_SENSOR_CSS_H
#define GS_ADCS_PARAM_HOST_SENSOR_CSS_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a sensor_css.
*/

#include <gs/adcs/param/sensor_css.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_sensor_css_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Calibration value for the CSS */
    float    scale[6];
    /** The address of the the interstage the CSS is mounted on */
    uint8_t  addr[6];
    /** Flag whether the CSS is enabled or not */
    uint8_t  enable[6];
    /** CSS Connection type 0/1 */
    uint8_t  type[6];
    /** Filler for alignment */
    uint8_t  _filler_0x002a[2];
    /** Current maximum value for the sunsensor in the sunsensor max tracking algorithm */
    float    max_init;
    /** Maximum permissible value for the sunsensor in the sunsensor max tracking algorithm */
    float    abs_max;
    /** Threshold for dark (eclipse) detection */
    float    threshold;
} gs_adcs_sensor_css_memory_t;

/** Table default values. */
extern const gs_adcs_sensor_css_memory_t gs_adcs_sensor_css_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set scale: Calibration value for the CSS */
#define GS_ADCS_SENSOR_CSS_SCALE_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_SCALE(idx), value, 0)
/** Set scale (no callback): Calibration value for the CSS */
#define GS_ADCS_SENSOR_CSS_SCALE_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_SCALE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get scale: Calibration value for the CSS */
#define GS_ADCS_SENSOR_CSS_SCALE_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_SCALE(idx), value, 0)
/** Get scale (no check - return 0 on failure): Calibration value for the CSS */
#define GS_ADCS_SENSOR_CSS_SCALE_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_SCALE(idx), 0)
/** Set addr: The address of the the interstage the CSS is mounted on */
#define GS_ADCS_SENSOR_CSS_ADDR_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ADDR(idx), value, 0)
/** Set addr (no callback): The address of the the interstage the CSS is mounted on */
#define GS_ADCS_SENSOR_CSS_ADDR_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ADDR(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get addr: The address of the the interstage the CSS is mounted on */
#define GS_ADCS_SENSOR_CSS_ADDR_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ADDR(idx), value, 0)
/** Get addr (no check - return 0 on failure): The address of the the interstage the CSS is mounted on */
#define GS_ADCS_SENSOR_CSS_ADDR_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ADDR(idx), 0)
/** Set enable: Flag whether the CSS is enabled or not */
#define GS_ADCS_SENSOR_CSS_ENABLE_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ENABLE(idx), value, 0)
/** Set enable (no callback): Flag whether the CSS is enabled or not */
#define GS_ADCS_SENSOR_CSS_ENABLE_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ENABLE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get enable: Flag whether the CSS is enabled or not */
#define GS_ADCS_SENSOR_CSS_ENABLE_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ENABLE(idx), value, 0)
/** Get enable (no check - return 0 on failure): Flag whether the CSS is enabled or not */
#define GS_ADCS_SENSOR_CSS_ENABLE_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ENABLE(idx), 0)
/** Set type: CSS Connection type 0/1 */
#define GS_ADCS_SENSOR_CSS_TYPE_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_TYPE(idx), value, 0)
/** Set type (no callback): CSS Connection type 0/1 */
#define GS_ADCS_SENSOR_CSS_TYPE_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_TYPE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get type: CSS Connection type 0/1 */
#define GS_ADCS_SENSOR_CSS_TYPE_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_TYPE(idx), value, 0)
/** Get type (no check - return 0 on failure): CSS Connection type 0/1 */
#define GS_ADCS_SENSOR_CSS_TYPE_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_TYPE(idx), 0)
/** Set max_init: Current maximum value for the sunsensor in the sunsensor max tracking algorithm */
#define GS_ADCS_SENSOR_CSS_MAX_INIT_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_MAX_INIT, value, 0)
/** Set max_init (no callback): Current maximum value for the sunsensor in the sunsensor max tracking algorithm */
#define GS_ADCS_SENSOR_CSS_MAX_INIT_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_MAX_INIT, value, GS_PARAM_F_NO_CALLBACK)
/** Get max_init: Current maximum value for the sunsensor in the sunsensor max tracking algorithm */
#define GS_ADCS_SENSOR_CSS_MAX_INIT_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_MAX_INIT, value, 0)
/** Get max_init (no check - return 0 on failure): Current maximum value for the sunsensor in the sunsensor max tracking algorithm */
#define GS_ADCS_SENSOR_CSS_MAX_INIT_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_MAX_INIT, 0)
/** Set abs_max: Maximum permissible value for the sunsensor in the sunsensor max tracking algorithm */
#define GS_ADCS_SENSOR_CSS_ABS_MAX_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ABS_MAX, value, 0)
/** Set abs_max (no callback): Maximum permissible value for the sunsensor in the sunsensor max tracking algorithm */
#define GS_ADCS_SENSOR_CSS_ABS_MAX_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ABS_MAX, value, GS_PARAM_F_NO_CALLBACK)
/** Get abs_max: Maximum permissible value for the sunsensor in the sunsensor max tracking algorithm */
#define GS_ADCS_SENSOR_CSS_ABS_MAX_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ABS_MAX, value, 0)
/** Get abs_max (no check - return 0 on failure): Maximum permissible value for the sunsensor in the sunsensor max tracking algorithm */
#define GS_ADCS_SENSOR_CSS_ABS_MAX_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_ABS_MAX, 0)
/** Set threshold: Threshold for dark (eclipse) detection */
#define GS_ADCS_SENSOR_CSS_THRESHOLD_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_THRESHOLD, value, 0)
/** Set threshold (no callback): Threshold for dark (eclipse) detection */
#define GS_ADCS_SENSOR_CSS_THRESHOLD_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_THRESHOLD, value, GS_PARAM_F_NO_CALLBACK)
/** Get threshold: Threshold for dark (eclipse) detection */
#define GS_ADCS_SENSOR_CSS_THRESHOLD_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_THRESHOLD, value, 0)
/** Get threshold (no check - return 0 on failure): Threshold for dark (eclipse) detection */
#define GS_ADCS_SENSOR_CSS_THRESHOLD_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_CSS_TABLE_ID), GS_ADCS_SENSOR_CSS_THRESHOLD, 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
