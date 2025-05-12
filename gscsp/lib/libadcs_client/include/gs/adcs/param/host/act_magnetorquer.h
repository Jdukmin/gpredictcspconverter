#ifndef GS_ADCS_PARAM_HOST_ACT_MAGNETORQUER_H
#define GS_ADCS_PARAM_HOST_ACT_MAGNETORQUER_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a act_magnetorquer.
*/

#include <gs/adcs/param/act_magnetorquer.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_act_magnetorquer_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Dipole moment */
    float    am[3];
    /** Magnetometer axis vector [x y z] */
    uint8_t  axis[3];
    /** Magnetometer sign vector [x y z] */
    int8_t   sign[3];
    /** Magnetometer enable vector [x y z] */
    uint8_t  max[3];
    /** Filler for alignment */
    uint8_t  _filler_end[3];
} gs_adcs_act_magnetorquer_memory_t;

/** Table default values. */
extern const gs_adcs_act_magnetorquer_memory_t gs_adcs_act_magnetorquer_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set am: Dipole moment */
#define GS_ADCS_ACT_MAGNETORQUER_AM_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_AM(idx), value, 0)
/** Set am (no callback): Dipole moment */
#define GS_ADCS_ACT_MAGNETORQUER_AM_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_AM(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get am: Dipole moment */
#define GS_ADCS_ACT_MAGNETORQUER_AM_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_AM(idx), value, 0)
/** Get am (no check - return 0 on failure): Dipole moment */
#define GS_ADCS_ACT_MAGNETORQUER_AM_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_AM(idx), 0)
/** Set axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_AXIS_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_AXIS(idx), value, 0)
/** Set axis (no callback): Magnetometer axis vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_AXIS_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_AXIS(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_AXIS_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_AXIS(idx), value, 0)
/** Get axis (no check - return 0 on failure): Magnetometer axis vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_AXIS_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_AXIS(idx), 0)
/** Set sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_SIGN_SET(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_SIGN(idx), value, 0)
/** Set sign (no callback): Magnetometer sign vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_SIGN_SET_NO_CALLBACK(idx, value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_SIGN(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_SIGN_GET(idx, value) gs_param_get_int8(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_SIGN(idx), value, 0)
/** Get sign (no check - return 0 on failure): Magnetometer sign vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_SIGN_GET_NC(idx) gs_param_get_int8_nc(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_SIGN(idx), 0)
/** Set max: Magnetometer enable vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_MAX_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_MAX(idx), value, 0)
/** Set max (no callback): Magnetometer enable vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_MAX_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_MAX(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get max: Magnetometer enable vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_MAX_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_MAX(idx), value, 0)
/** Get max (no check - return 0 on failure): Magnetometer enable vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_MAX_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER_MAX(idx), 0)
/** Set _filler_end: Filler for alignment */
#define GS_ADCS_ACT_MAGNETORQUER__FILLER_END_SET(value, value_size) gs_param_set_data(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER__FILLER_END, value, value_size, 0)
/** Set _filler_end (no callback): Filler for alignment */
#define GS_ADCS_ACT_MAGNETORQUER__FILLER_END_SET_NO_CALLBACK(value, value_size) gs_param_set_data(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER__FILLER_END, value, value_size, GS_PARAM_F_NO_CALLBACK)
/** Get _filler_end: Filler for alignment */
#define GS_ADCS_ACT_MAGNETORQUER__FILLER_END_GET(buf, buf_size) gs_param_get_data(gs_param_table_by_id(GS_ADCS_ACT_MAGNETORQUER_TABLE_ID), GS_ADCS_ACT_MAGNETORQUER__FILLER_END, buf, buf_size, 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
