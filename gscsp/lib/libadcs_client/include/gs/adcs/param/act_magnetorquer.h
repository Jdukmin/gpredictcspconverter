#ifndef GS_ADCS_PARAM_ACT_MAGNETORQUER_H
#define GS_ADCS_PARAM_ACT_MAGNETORQUER_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a act_magnetorquer.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_ACT_MAGNETORQUER_TABLE_NAME              "act_magnetorquer"
/** Table id */
#define GS_ADCS_ACT_MAGNETORQUER_TABLE_ID                60
/** Legacy table id definition */
#define GS_ADCS_ACT_MAGNETORQUER_TABLE_MEM_ID            60
/** Table data size (bytes */
#define GS_ADCS_ACT_MAGNETORQUER_TABLE_SIZE              24 // bytes
/** Table rows (count) */
#define GS_ADCS_ACT_MAGNETORQUER_TABLE_ROWS              5

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of am: Dipole moment */
#define GS_ADCS_ACT_MAGNETORQUER_AM(idx)                            (    0 + ( 4 * (idx)))  // 0x0000 float
/** Array size of am: Dipole moment */
#define GS_ADCS_ACT_MAGNETORQUER_AM_ARRAY_SIZE                           3
/** Address of axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_AXIS(idx)                          (   12 + ( 1 * (idx)))  // 0x000c uint8
/** Array size of axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_AXIS_ARRAY_SIZE                         3
/** Address of sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_SIGN(idx)                          (   15 + ( 1 * (idx)))  // 0x000f int8
/** Array size of sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_SIGN_ARRAY_SIZE                         3
/** Address of max: Magnetometer enable vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_MAX(idx)                           (   18 + ( 1 * (idx)))  // 0x0012 uint8
/** Array size of max: Magnetometer enable vector [x y z] */
#define GS_ADCS_ACT_MAGNETORQUER_MAX_ARRAY_SIZE                          3
/** Address of _filler_end: Filler for alignment */
#define GS_ADCS_ACT_MAGNETORQUER__FILLER_END                            21                  // 0x0015 data
/** Length/size of _filler_end (bytes): Filler for alignment */
#define GS_ADCS_ACT_MAGNETORQUER__FILLER_END_LENGTH                      3
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
