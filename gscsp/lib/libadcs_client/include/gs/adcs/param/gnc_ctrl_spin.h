#ifndef GS_ADCS_PARAM_GNC_CTRL_SPIN_H
#define GS_ADCS_PARAM_GNC_CTRL_SPIN_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a gnc_ctrl_spin.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_GNC_CTRL_SPIN_TABLE_NAME                 "gnc_ctrl_spin"
/** Table id */
#define GS_ADCS_GNC_CTRL_SPIN_TABLE_ID                   52
/** Legacy table id definition */
#define GS_ADCS_GNC_CTRL_SPIN_TABLE_MEM_ID               52
/** Table data size (bytes */
#define GS_ADCS_GNC_CTRL_SPIN_TABLE_SIZE                 72 // bytes
/** Table rows (count) */
#define GS_ADCS_GNC_CTRL_SPIN_TABLE_ROWS                 15

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of axis: The axis parallel to the momentum wheel */
#define GS_ADCS_GNC_CTRL_SPIN_AXIS                                       0                  // 0x0000 uint8
/** Address of mw_smc: SMC gain */
#define GS_ADCS_GNC_CTRL_SPIN_MW_SMC(idx)                           (    4 + ( 4 * (idx)))  // 0x0004 float
/** Array size of mw_smc: SMC gain */
#define GS_ADCS_GNC_CTRL_SPIN_MW_SMC_ARRAY_SIZE                          3
/** Address of dumpgain: Dump gain */
#define GS_ADCS_GNC_CTRL_SPIN_DUMPGAIN                                  16                  // 0x0010 float
/** Address of mt_gain: Gains for the magnetorquers [Kd, Ks] */
#define GS_ADCS_GNC_CTRL_SPIN_MT_GAIN(idx)                          (   20 + ( 4 * (idx)))  // 0x0014 float
/** Array size of mt_gain: Gains for the magnetorquers [Kd, Ks] */
#define GS_ADCS_GNC_CTRL_SPIN_MT_GAIN_ARRAY_SIZE                         4
/** Address of pd_ctrl: Magnetorquer PD control gain [k_p k_d] */
#define GS_ADCS_GNC_CTRL_SPIN_PD_CTRL(idx)                          (   36 + ( 4 * (idx)))  // 0x0024 float
/** Array size of pd_ctrl: Magnetorquer PD control gain [k_p k_d] */
#define GS_ADCS_GNC_CTRL_SPIN_PD_CTRL_ARRAY_SIZE                         2
/** Address of ref_mnt: The desired momentum for the momentum wheel */
#define GS_ADCS_GNC_CTRL_SPIN_REF_MNT                                   44                  // 0x002c float
/** Address of en_dtmbl: Detumble while in idle submode */
#define GS_ADCS_GNC_CTRL_SPIN_EN_DTMBL                                  48                  // 0x0030 bool
/** Address of en_reini: Reinitialize when going from pointing control to idle due to instability */
#define GS_ADCS_GNC_CTRL_SPIN_EN_REINI                                  49                  // 0x0031 bool
/** Address of mode_dly: Submode switch delay [s] */
#define GS_ADCS_GNC_CTRL_SPIN_MODE_DLY                                  50                  // 0x0032 uint16
/** Address of eclipdly: Required time in sun before transitioning to spin-up */
#define GS_ADCS_GNC_CTRL_SPIN_ECLIPDLY                                  52                  // 0x0034 uint16
/** Address of spin_dly: Minimum time to hold a stable spin before going to pointing mode */
#define GS_ADCS_GNC_CTRL_SPIN_SPIN_DLY                                  54                  // 0x0036 uint16
/** Address of err_dly: Time to stay in pointing mode and attempt to stabilize before goring to idle */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_DLY                                   56                  // 0x0038 uint16
/** Address of err_rate: Max allowed angular velocity error */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_RATE                                  60                  // 0x003c float
/** Address of err_att: Maximum pointing error before transition from spin-up to pointing mode */
#define GS_ADCS_GNC_CTRL_SPIN_ERR_ATT                                   64                  // 0x0040 float
/** Address of max_ape: Maximum allowed pointing error */
#define GS_ADCS_GNC_CTRL_SPIN_MAX_APE                                   68                  // 0x0044 float
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
