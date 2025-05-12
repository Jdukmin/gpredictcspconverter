#ifndef GS_ADCS_PARAM_HOST_SENSOR_STARTRACKER_H
#define GS_ADCS_PARAM_HOST_SENSOR_STARTRACKER_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a sensor_startracker.
*/

#include <gs/adcs/param/sensor_startracker.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_sensor_startracker_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Star tracker uart instance [#] */
    uint8_t  str_uart;
    /** Enable and initialize star tracker */
    bool     en_str;
    /** Filler for alignment */
    uint8_t  _filler_0x0002[2];
    /** Star tracker orientation, str to body [q1 q2 q3 q4] */
    float    str_q[4];
} gs_adcs_sensor_startracker_memory_t;

/** Table default values. */
extern const gs_adcs_sensor_startracker_memory_t gs_adcs_sensor_startracker_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set str_uart: Star tracker uart instance [#] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_UART_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_STR_UART, value, 0)
/** Set str_uart (no callback): Star tracker uart instance [#] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_UART_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_STR_UART, value, GS_PARAM_F_NO_CALLBACK)
/** Get str_uart: Star tracker uart instance [#] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_UART_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_STR_UART, value, 0)
/** Get str_uart (no check - return 0 on failure): Star tracker uart instance [#] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_UART_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_STR_UART, 0)
/** Set en_str: Enable and initialize star tracker */
#define GS_ADCS_SENSOR_STARTRACKER_EN_STR_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_EN_STR, value, 0)
/** Set en_str (no callback): Enable and initialize star tracker */
#define GS_ADCS_SENSOR_STARTRACKER_EN_STR_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_EN_STR, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_str: Enable and initialize star tracker */
#define GS_ADCS_SENSOR_STARTRACKER_EN_STR_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_EN_STR, value, 0)
/** Get en_str (no check - return 0 on failure): Enable and initialize star tracker */
#define GS_ADCS_SENSOR_STARTRACKER_EN_STR_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_EN_STR, 0)
/** Set str_q: Star tracker orientation, str to body [q1 q2 q3 q4] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_Q_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_STR_Q(idx), value, 0)
/** Set str_q (no callback): Star tracker orientation, str to body [q1 q2 q3 q4] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_Q_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_STR_Q(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get str_q: Star tracker orientation, str to body [q1 q2 q3 q4] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_Q_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_STR_Q(idx), value, 0)
/** Get str_q (no check - return 0 on failure): Star tracker orientation, str to body [q1 q2 q3 q4] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_Q_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_SENSOR_STARTRACKER_TABLE_ID), GS_ADCS_SENSOR_STARTRACKER_STR_Q(idx), 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
