#ifndef GS_ADCS_PARAM_HOST_GNC_CTRL_SPIN_H
#define GS_ADCS_PARAM_HOST_GNC_CTRL_SPIN_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a gnc_ctrl_spin.
*/

#include <gs/adcs/param/gnc_ctrl_spin.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_gnc_ctrl_spin_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** The axis parallel to the momentum wheel */
    uint8_t  axis;
    /** Filler for alignment */
    uint8_t  _filler_0x0001[3];
    /** SMC gain */
    float    mw_smc[3];
    /** Dump gain */
    float    dumpgain;
    /** Gains for the magnetorquers [Kd, Ks] */
    float    mt_gain[4];
    /** Magnetorquer PD control gain [k_p k_d] */
    float    pd_ctrl[2];
    /** The desired momentum for the momentum wheel */
    float    ref_mnt;
    /** Detumble while in idle submode */
    bool     en_dtmbl;
    /** Reinitialize when going from pointing control to idle due to instability */
    bool     en_reini;
    /** Submode switch delay [s] */
    uint16_t mode_dly;
    /** Required time in sun before transitioning to spin-up */
    uint16_t eclipdly;
    /** Minimum time to hold a stable spin before going to pointing mode */
    uint16_t spin_dly;
    /** Time to stay in pointing mode and attempt to stabilize before goring to idle */
    uint16_t err_dly;
    /** Filler for alignment */
    uint8_t  _filler_0x003a[2];
    /** Max allowed angular velocity error */
    float    err_rate;
    /** Maximum pointing error before transition from spin-up to pointing mode */
    float    err_att;
    /** Maximum allowed pointing error */
    float    max_ape;
} gs_adcs_gnc_ctrl_spin_memory_t;

/** Table default values. */
extern const gs_adcs_gnc_ctrl_spin_memory_t gs_adcs_gnc_ctrl_spin_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set axis: The axis parallel to the momentum wheel */
#define GS_ADCS_GNC_CTRL_SPIN_AXIS_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_AXIS, value, 0)
/** Set axis (no callback): The axis parallel to the momentum wheel */
#define GS_ADCS_GNC_CTRL_SPIN_AXIS_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_AXIS, value, GS_PARAM_F_NO_CALLBACK)
/** Get axis: The axis parallel to the momentum wheel */
#define GS_ADCS_GNC_CTRL_SPIN_AXIS_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_AXIS, value, 0)
/** Get axis (no check - return 0 on failure): The axis parallel to the momentum wheel */
#define GS_ADCS_GNC_CTRL_SPIN_AXIS_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_AXIS, 0)
/** Set mw_smc: SMC gain */
#define GS_ADCS_GNC_CTRL_SPIN_MW_SMC_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MW_SMC(idx), value, 0)
/** Set mw_smc (no callback): SMC gain */
#define GS_ADCS_GNC_CTRL_SPIN_MW_SMC_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MW_SMC(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mw_smc: SMC gain */
#define GS_ADCS_GNC_CTRL_SPIN_MW_SMC_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MW_SMC(idx), value, 0)
/** Get mw_smc (no check - return 0 on failure): SMC gain */
#define GS_ADCS_GNC_CTRL_SPIN_MW_SMC_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MW_SMC(idx), 0)
/** Set dumpgain: Dump gain */
#define GS_ADCS_GNC_CTRL_SPIN_DUMPGAIN_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_DUMPGAIN, value, 0)
/** Set dumpgain (no callback): Dump gain */
#define GS_ADCS_GNC_CTRL_SPIN_DUMPGAIN_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_DUMPGAIN, value, GS_PARAM_F_NO_CALLBACK)
/** Get dumpgain: Dump gain */
#define GS_ADCS_GNC_CTRL_SPIN_DUMPGAIN_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_DUMPGAIN, value, 0)
/** Get dumpgain (no check - return 0 on failure): Dump gain */
#define GS_ADCS_GNC_CTRL_SPIN_DUMPGAIN_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_DUMPGAIN, 0)
/** Set mt_gain: Gains for the magnetorquers [Kd, Ks] */
#define GS_ADCS_GNC_CTRL_SPIN_MT_GAIN_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MT_GAIN(idx), value, 0)
/** Set mt_gain (no callback): Gains for the magnetorquers [Kd, Ks] */
#define GS_ADCS_GNC_CTRL_SPIN_MT_GAIN_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MT_GAIN(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mt_gain: Gains for the magnetorquers [Kd, Ks] */
#define GS_ADCS_GNC_CTRL_SPIN_MT_GAIN_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MT_GAIN(idx), value, 0)
/** Get mt_gain (no check - return 0 on failure): Gains for the magnetorquers [Kd, Ks] */
#define GS_ADCS_GNC_CTRL_SPIN_MT_GAIN_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MT_GAIN(idx), 0)
/** Set pd_ctrl: Magnetorquer PD control gain [k_p k_d] */
#define GS_ADCS_GNC_CTRL_SPIN_PD_CTRL_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_PD_CTRL(idx), value, 0)
/** Set pd_ctrl (no callback): Magnetorquer PD control gain [k_p k_d] */
#define GS_ADCS_GNC_CTRL_SPIN_PD_CTRL_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_PD_CTRL(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get pd_ctrl: Magnetorquer PD control gain [k_p k_d] */
#define GS_ADCS_GNC_CTRL_SPIN_PD_CTRL_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_PD_CTRL(idx), value, 0)
/** Get pd_ctrl (no check - return 0 on failure): Magnetorquer PD control gain [k_p k_d] */
#define GS_ADCS_GNC_CTRL_SPIN_PD_CTRL_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_PD_CTRL(idx), 0)
/** Set ref_mnt: The desired momentum for the momentum wheel */
#define GS_ADCS_GNC_CTRL_SPIN_REF_MNT_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_REF_MNT, value, 0)
/** Set ref_mnt (no callback): The desired momentum for the momentum wheel */
#define GS_ADCS_GNC_CTRL_SPIN_REF_MNT_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_REF_MNT, value, GS_PARAM_F_NO_CALLBACK)
/** Get ref_mnt: The desired momentum for the momentum wheel */
#define GS_ADCS_GNC_CTRL_SPIN_REF_MNT_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_REF_MNT, value, 0)
/** Get ref_mnt (no check - return 0 on failure): The desired momentum for the momentum wheel */
#define GS_ADCS_GNC_CTRL_SPIN_REF_MNT_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_REF_MNT, 0)
/** Set en_dtmbl: Detumble while in idle submode */
#define GS_ADCS_GNC_CTRL_SPIN_EN_DTMBL_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_EN_DTMBL, value, 0)
/** Set en_dtmbl (no callback): Detumble while in idle submode */
#define GS_ADCS_GNC_CTRL_SPIN_EN_DTMBL_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_EN_DTMBL, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_dtmbl: Detumble while in idle submode */
#define GS_ADCS_GNC_CTRL_SPIN_EN_DTMBL_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_EN_DTMBL, value, 0)
/** Get en_dtmbl (no check - return 0 on failure): Detumble while in idle submode */
#define GS_ADCS_GNC_CTRL_SPIN_EN_DTMBL_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_EN_DTMBL, 0)
/** Set en_reini: Reinitialize when going from pointing control to idle due to instability */
#define GS_ADCS_GNC_CTRL_SPIN_EN_REINI_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_EN_REINI, value, 0)
/** Set en_reini (no callback): Reinitialize when going from pointing control to idle due to instability */
#define GS_ADCS_GNC_CTRL_SPIN_EN_REINI_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_EN_REINI, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_reini: Reinitialize when going from pointing control to idle due to instability */
#define GS_ADCS_GNC_CTRL_SPIN_EN_REINI_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_EN_REINI, value, 0)
/** Get en_reini (no check - return 0 on failure): Reinitialize when going from pointing control to idle due to instability */
#define GS_ADCS_GNC_CTRL_SPIN_EN_REINI_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_EN_REINI, 0)
/** Set mode_dly: Submode switch delay [s] */
#define GS_ADCS_GNC_CTRL_SPIN_MODE_DLY_SET(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MODE_DLY, value, 0)
/** Set mode_dly (no callback): Submode switch delay [s] */
#define GS_ADCS_GNC_CTRL_SPIN_MODE_DLY_SET_NO_CALLBACK(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MODE_DLY, value, GS_PARAM_F_NO_CALLBACK)
/** Get mode_dly: Submode switch delay [s] */
#define GS_ADCS_GNC_CTRL_SPIN_MODE_DLY_GET(value) gs_param_get_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MODE_DLY, value, 0)
/** Get mode_dly (no check - return 0 on failure): Submode switch delay [s] */
#define GS_ADCS_GNC_CTRL_SPIN_MODE_DLY_GET_NC() gs_param_get_uint16_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MODE_DLY, 0)
/** Set eclipdly: Required time in sun before transitioning to spin-up */
#define GS_ADCS_GNC_CTRL_SPIN_ECLIPDLY_SET(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ECLIPDLY, value, 0)
/** Set eclipdly (no callback): Required time in sun before transitioning to spin-up */
#define GS_ADCS_GNC_CTRL_SPIN_ECLIPDLY_SET_NO_CALLBACK(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ECLIPDLY, value, GS_PARAM_F_NO_CALLBACK)
/** Get eclipdly: Required time in sun before transitioning to spin-up */
#define GS_ADCS_GNC_CTRL_SPIN_ECLIPDLY_GET(value) gs_param_get_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ECLIPDLY, value, 0)
/** Get eclipdly (no check - return 0 on failure): Required time in sun before transitioning to spin-up */
#define GS_ADCS_GNC_CTRL_SPIN_ECLIPDLY_GET_NC() gs_param_get_uint16_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ECLIPDLY, 0)
/** Set spin_dly: Minimum time to hold a stable spin before going to pointing mode */
#define GS_ADCS_GNC_CTRL_SPIN_SPIN_DLY_SET(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_SPIN_DLY, value, 0)
/** Set spin_dly (no callback): Minimum time to hold a stable spin before going to pointing mode */
#define GS_ADCS_GNC_CTRL_SPIN_SPIN_DLY_SET_NO_CALLBACK(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_SPIN_DLY, value, GS_PARAM_F_NO_CALLBACK)
/** Get spin_dly: Minimum time to hold a stable spin before going to pointing mode */
#define GS_ADCS_GNC_CTRL_SPIN_SPIN_DLY_GET(value) gs_param_get_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_SPIN_DLY, value, 0)
/** Get spin_dly (no check - return 0 on failure): Minimum time to hold a stable spin before going to pointing mode */
#define GS_ADCS_GNC_CTRL_SPIN_SPIN_DLY_GET_NC() gs_param_get_uint16_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_SPIN_DLY, 0)
/** Set err_dly: Time to stay in pointing mode and attempt to stabilize before goring to idle */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_DLY_SET(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_DLY, value, 0)
/** Set err_dly (no callback): Time to stay in pointing mode and attempt to stabilize before goring to idle */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_DLY_SET_NO_CALLBACK(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_DLY, value, GS_PARAM_F_NO_CALLBACK)
/** Get err_dly: Time to stay in pointing mode and attempt to stabilize before goring to idle */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_DLY_GET(value) gs_param_get_uint16(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_DLY, value, 0)
/** Get err_dly (no check - return 0 on failure): Time to stay in pointing mode and attempt to stabilize before goring to idle */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_DLY_GET_NC() gs_param_get_uint16_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_DLY, 0)
/** Set err_rate: Max allowed angular velocity error */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_RATE_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_RATE, value, 0)
/** Set err_rate (no callback): Max allowed angular velocity error */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_RATE_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_RATE, value, GS_PARAM_F_NO_CALLBACK)
/** Get err_rate: Max allowed angular velocity error */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_RATE_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_RATE, value, 0)
/** Get err_rate (no check - return 0 on failure): Max allowed angular velocity error */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_RATE_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_RATE, 0)
/** Set err_att: Maximum pointing error before transition from spin-up to pointing mode */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_ATT_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_ATT, value, 0)
/** Set err_att (no callback): Maximum pointing error before transition from spin-up to pointing mode */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_ATT_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_ATT, value, GS_PARAM_F_NO_CALLBACK)
/** Get err_att: Maximum pointing error before transition from spin-up to pointing mode */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_ATT_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_ATT, value, 0)
/** Get err_att (no check - return 0 on failure): Maximum pointing error before transition from spin-up to pointing mode */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_ATT_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_ERR_ATT, 0)
/** Set max_ape: Maximum allowed pointing error */
#define GS_ADCS_GNC_CTRL_SPIN_MAX_APE_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MAX_APE, value, 0)
/** Set max_ape (no callback): Maximum allowed pointing error */
#define GS_ADCS_GNC_CTRL_SPIN_MAX_APE_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MAX_APE, value, GS_PARAM_F_NO_CALLBACK)
/** Get max_ape: Maximum allowed pointing error */
#define GS_ADCS_GNC_CTRL_SPIN_MAX_APE_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MAX_APE, value, 0)
/** Get max_ape (no check - return 0 on failure): Maximum allowed pointing error */
#define GS_ADCS_GNC_CTRL_SPIN_MAX_APE_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_SPIN_TABLE_ID), GS_ADCS_GNC_CTRL_SPIN_MAX_APE, 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
