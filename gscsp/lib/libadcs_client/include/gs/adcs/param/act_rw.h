#ifndef GS_ADCS_PARAM_ACT_RW_H
#define GS_ADCS_PARAM_ACT_RW_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a act_rw.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_ACT_RW_TABLE_NAME                        "act_rw"
/** Table id */
#define GS_ADCS_ACT_RW_TABLE_ID                          61
/** Legacy table id definition */
#define GS_ADCS_ACT_RW_TABLE_MEM_ID                      61
/** Table data size (bytes */
#define GS_ADCS_ACT_RW_TABLE_SIZE                        115 // bytes
/** Table rows (count) */
#define GS_ADCS_ACT_RW_TABLE_ROWS                        8

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of max_speed: Maximum speed of the momentum wheels */
#define GS_ADCS_ACT_RW_MAX_SPEED                                         0                  // 0x0000 float
/** Address of max_torque: Maximum torque to be produced by the wheels */
#define GS_ADCS_ACT_RW_MAX_TORQUE                                        4                  // 0x0004 float
/** Address of inertia: Spin-axis inertia of each momentum wheel */
#define GS_ADCS_ACT_RW_INERTIA                                           8                  // 0x0008 float
/** Address of inv_inertia: Inverse of the spin-axis inertia of each momentum wheel */
#define GS_ADCS_ACT_RW_INV_INERTIA                                      12                  // 0x000c float
/** Address of layout: Layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_LAYOUT(idx)                                  (   16 + ( 4 * (idx)))  // 0x0010 float
/** Array size of layout: Layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_LAYOUT_ARRAY_SIZE                                12
/** Address of inv_layout: Inverse of the layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_INV_LAYOUT(idx)                              (   64 + ( 4 * (idx)))  // 0x0040 float
/** Array size of inv_layout: Inverse of the layout matrix from MW orientation to body axes */
#define GS_ADCS_ACT_RW_INV_LAYOUT_ARRAY_SIZE                            12
/** Address of mw_override: Override command to force WDE on / off */
#define GS_ADCS_ACT_RW_MW_OVERRIDE                                     112                  // 0x0070 uint8
/** Address of _filler_end: Filler for alignment */
#define GS_ADCS_ACT_RW__FILLER_END                                     113                  // 0x0071 data
/** Length/size of _filler_end (bytes): Filler for alignment */
#define GS_ADCS_ACT_RW__FILLER_END_LENGTH                                2
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
