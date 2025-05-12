#ifndef GS_ADCS_PARAM_HOST_SENSOR_GYRO_H
#define GS_ADCS_PARAM_HOST_SENSOR_GYRO_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a sensor_gyro.
*/

#include <gs/adcs/param/sensor_gyro.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_sensor_gyro_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Gyro scale */
    float    scale[3];
    /** Gyro offset */
    float    offset[3];
    /** Gyro temperature scale */
    float    temp[3];
    /** Gyro axis */
    uint8_t  axis[3];
    /** Gyro sign */
    int8_t   sign[3];
    /** Power node (only used for the STIM210) */
    uint8_t  pwr_node;
    /** Power channel (only used for the STIM210) */
    uint8_t  pwr_chan;
    /** Enable flag (only used for the STIM210) */
    uint8_t  enable;
    /** Filler for alignment */
    uint8_t  _filler_end[3];
} gs_adcs_sensor_gyro_memory_t;

/** Table default values. */
extern const gs_adcs_sensor_gyro_memory_t gs_adcs_sensor_gyro_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set scale: Gyro scale */
#define GS_ADCS_SENSOR_GYRO_SCALE_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_SCALE(idx), value, 0)
/** Set scale (no callback): Gyro scale */
#define GS_ADCS_SENSOR_GYRO_SCALE_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_SCALE(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get scale: Gyro scale */
#define GS_ADCS_SENSOR_GYRO_SCALE_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_SCALE(idx), value, 0)
/** Get scale (no check - return 0 on failure): Gyro scale */
#define GS_ADCS_SENSOR_GYRO_SCALE_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_SCALE(idx), 0)
/** Set offset: Gyro offset */
#define GS_ADCS_SENSOR_GYRO_OFFSET_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_OFFSET(idx), value, 0)
/** Set offset (no callback): Gyro offset */
#define GS_ADCS_SENSOR_GYRO_OFFSET_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_OFFSET(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get offset: Gyro offset */
#define GS_ADCS_SENSOR_GYRO_OFFSET_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_OFFSET(idx), value, 0)
/** Get offset (no check - return 0 on failure): Gyro offset */
#define GS_ADCS_SENSOR_GYRO_OFFSET_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_OFFSET(idx), 0)
/** Set temp: Gyro temperature scale */
#define GS_ADCS_SENSOR_GYRO_TEMP_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_TEMP(idx), value, 0)
/** Set temp (no callback): Gyro temperature scale */
#define GS_ADCS_SENSOR_GYRO_TEMP_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_TEMP(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get temp: Gyro temperature scale */
#define GS_ADCS_SENSOR_GYRO_TEMP_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_TEMP(idx), value, 0)
/** Get temp (no check - return 0 on failure): Gyro temperature scale */
#define GS_ADCS_SENSOR_GYRO_TEMP_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_TEMP(idx), 0)
/** Set axis: Gyro axis */
#define GS_ADCS_SENSOR_GYRO_AXIS_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_AXIS(idx), value, 0)
/** Set axis (no callback): Gyro axis */
#define GS_ADCS_SENSOR_GYRO_AXIS_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_AXIS(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get axis: Gyro axis */
#define GS_ADCS_SENSOR_GYRO_AXIS_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_AXIS(idx), value, 0)
/** Get axis (no check - return 0 on failure): Gyro axis */
#define GS_ADCS_SENSOR_GYRO_AXIS_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_AXIS(idx), 0)
/** Set sign: Gyro sign */
#define GS_ADCS_SENSOR_GYRO_SIGN_SET(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_SIGN(idx), value, 0)
/** Set sign (no callback): Gyro sign */
#define GS_ADCS_SENSOR_GYRO_SIGN_SET_NO_CALLBACK(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_SIGN(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get sign: Gyro sign */
#define GS_ADCS_SENSOR_GYRO_SIGN_GET(idx, value) gs_param_get_int8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_SIGN(idx), value, 0)
/** Get sign (no check - return 0 on failure): Gyro sign */
#define GS_ADCS_SENSOR_GYRO_SIGN_GET_NC(idx) gs_param_get_int8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_SIGN(idx), 0)
/** Set pwr_node: Power node (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_PWR_NODE_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_PWR_NODE, value, 0)
/** Set pwr_node (no callback): Power node (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_PWR_NODE_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_PWR_NODE, value, GS_PARAM_F_NO_CALLBACK)
/** Get pwr_node: Power node (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_PWR_NODE_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_PWR_NODE, value, 0)
/** Get pwr_node (no check - return 0 on failure): Power node (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_PWR_NODE_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_PWR_NODE, 0)
/** Set pwr_chan: Power channel (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_PWR_CHAN_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_PWR_CHAN, value, 0)
/** Set pwr_chan (no callback): Power channel (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_PWR_CHAN_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_PWR_CHAN, value, GS_PARAM_F_NO_CALLBACK)
/** Get pwr_chan: Power channel (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_PWR_CHAN_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_PWR_CHAN, value, 0)
/** Get pwr_chan (no check - return 0 on failure): Power channel (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_PWR_CHAN_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_PWR_CHAN, 0)
/** Set enable: Enable flag (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_ENABLE_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_ENABLE, value, 0)
/** Set enable (no callback): Enable flag (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_ENABLE_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_ENABLE, value, GS_PARAM_F_NO_CALLBACK)
/** Get enable: Enable flag (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_ENABLE_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_ENABLE, value, 0)
/** Get enable (no check - return 0 on failure): Enable flag (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_ENABLE_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO_ENABLE, 0)
/** Set _filler_end: Filler for alignment */
#define GS_ADCS_SENSOR_GYRO__FILLER_END_SET(value, value_size) gs_param_set_data(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO__FILLER_END, value, value_size, 0)
/** Set _filler_end (no callback): Filler for alignment */
#define GS_ADCS_SENSOR_GYRO__FILLER_END_SET_NO_CALLBACK(value, value_size) gs_param_set_data(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO__FILLER_END, value, value_size, GS_PARAM_F_NO_CALLBACK)
/** Get _filler_end: Filler for alignment */
#define GS_ADCS_SENSOR_GYRO__FILLER_END_GET(buf, buf_size) gs_param_get_data(gs_param_table_by_id(GS_ADCS_SENSOR_GYRO_TABLE_ID), GS_ADCS_SENSOR_GYRO__FILLER_END, buf, buf_size, 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
