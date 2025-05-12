#ifndef GS_ADCS_PARAM_HOST_ACT_RW_H
#define GS_ADCS_PARAM_HOST_ACT_RW_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a act_rw.
*/

#include <gs/adcs/param/act_rw.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_act_rw_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Maximum speed of the momentum wheels */
    float    max_speed;
    /** Maximum torque to be produced by the wheels */
    float    max_torque;
    /** Spin-axis inertia of each momentum wheel */
    float    inertia;
    /** Inverse of the spin-axis inertia of each momentum wheel */
    float    inv_inertia;
    /** Layout matrix from MW orientation to body axes */
    float    layout[12];
    /** Inverse of the layout matrix from MW orientation to body axes */
    float    inv_layout[12];
    /** Override command to force WDE on / off */
    uint8_t  mw_override;
    /** Filler for alignment */
    uint8_t  _filler_end[2];
} gs_adcs_act_rw_memory_t;

/** Table default values. */
extern const gs_adcs_act_rw_memory_t gs_adcs_act_rw_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set max_speed: Maximum speed of the momentum wheels */
#define GS_ADCS_ACT_RW_MAX_SPEED_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MAX_SPEED, value, 0)
/** Set max_speed (no callback): Maximum speed of the momentum wheels */
#define GS_ADCS_ACT_RW_MAX_SPEED_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MAX_SPEED, value, GS_PARAM_F_NO_CALLBACK)
/** Get max_speed: Maximum speed of the momentum wheels */
#define GS_ADCS_ACT_RW_MAX_SPEED_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MAX_SPEED, value, 0)
/** Get max_speed (no check - return 0 on failure): Maximum speed of the momentum wheels */
#define GS_ADCS_ACT_RW_MAX_SPEED_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MAX_SPEED, 0)
/** Set max_torque: Maximum torque to be produced by the wheels */
#define GS_ADCS_ACT_RW_MAX_TORQUE_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MAX_TORQUE, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set max_torque (no callback): Maximum torque to be produced by the wheels */
#define GS_ADCS_ACT_RW_MAX_TORQUE_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MAX_TORQUE, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get max_torque: Maximum torque to be produced by the wheels */
#define GS_ADCS_ACT_RW_MAX_TORQUE_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MAX_TORQUE, value, 0)
/** Get max_torque (no check - return 0 on failure): Maximum torque to be produced by the wheels */
#define GS_ADCS_ACT_RW_MAX_TORQUE_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MAX_TORQUE, 0)
/** Set inertia: Spin-axis inertia of each momentum wheel */
#define GS_ADCS_ACT_RW_INERTIA_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INERTIA, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set inertia (no callback): Spin-axis inertia of each momentum wheel */
#define GS_ADCS_ACT_RW_INERTIA_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INERTIA, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get inertia: Spin-axis inertia of each momentum wheel */
#define GS_ADCS_ACT_RW_INERTIA_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INERTIA, value, 0)
/** Get inertia (no check - return 0 on failure): Spin-axis inertia of each momentum wheel */
#define GS_ADCS_ACT_RW_INERTIA_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INERTIA, 0)
/** Set inv_inertia: Inverse of the spin-axis inertia of each momentum wheel */
#define GS_ADCS_ACT_RW_INV_INERTIA_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INV_INERTIA, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set inv_inertia (no callback): Inverse of the spin-axis inertia of each momentum wheel */
#define GS_ADCS_ACT_RW_INV_INERTIA_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INV_INERTIA, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get inv_inertia: Inverse of the spin-axis inertia of each momentum wheel */
#define GS_ADCS_ACT_RW_INV_INERTIA_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INV_INERTIA, value, 0)
/** Get inv_inertia (no check - return 0 on failure): Inverse of the spin-axis inertia of each momentum wheel */
#define GS_ADCS_ACT_RW_INV_INERTIA_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INV_INERTIA, 0)
/** Set layout: Layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_LAYOUT_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_LAYOUT(idx), value, 0)
/** Set layout (no callback): Layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_LAYOUT_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_LAYOUT(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get layout: Layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_LAYOUT_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_LAYOUT(idx), value, 0)
/** Get layout (no check - return 0 on failure): Layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_LAYOUT_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_LAYOUT(idx), 0)
/** Set inv_layout: Inverse of the layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_INV_LAYOUT_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INV_LAYOUT(idx), value, 0)
/** Set inv_layout (no callback): Inverse of the layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_INV_LAYOUT_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INV_LAYOUT(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get inv_layout: Inverse of the layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_INV_LAYOUT_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INV_LAYOUT(idx), value, 0)
/** Get inv_layout (no check - return 0 on failure): Inverse of the layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_INV_LAYOUT_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_INV_LAYOUT(idx), 0)
/** Set mw_override: Override command to force WDE on / off */
#define GS_ADCS_ACT_RW_MW_OVERRIDE_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MW_OVERRIDE, value, 0)
/** Set mw_override (no callback): Override command to force WDE on / off */
#define GS_ADCS_ACT_RW_MW_OVERRIDE_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MW_OVERRIDE, value, GS_PARAM_F_NO_CALLBACK)
/** Get mw_override: Override command to force WDE on / off */
#define GS_ADCS_ACT_RW_MW_OVERRIDE_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MW_OVERRIDE, value, 0)
/** Get mw_override (no check - return 0 on failure): Override command to force WDE on / off */
#define GS_ADCS_ACT_RW_MW_OVERRIDE_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW_MW_OVERRIDE, 0)
/** Set _filler_end: Filler for alignment */
#define GS_ADCS_ACT_RW__FILLER_END_SET(value, value_size) gs_param_set_data(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW__FILLER_END, value, value_size, 0)
/** Set _filler_end (no callback): Filler for alignment */
#define GS_ADCS_ACT_RW__FILLER_END_SET_NO_CALLBACK(value, value_size) gs_param_set_data(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW__FILLER_END, value, value_size, GS_PARAM_F_NO_CALLBACK)
/** Get _filler_end: Filler for alignment */
#define GS_ADCS_ACT_RW__FILLER_END_GET(buf, buf_size) gs_param_get_data(gs_param_table_by_id(GS_ADCS_ACT_RW_TABLE_ID), GS_ADCS_ACT_RW__FILLER_END, buf, buf_size, 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
