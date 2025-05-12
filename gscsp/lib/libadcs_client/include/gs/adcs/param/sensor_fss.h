#ifndef GS_ADCS_PARAM_SENSOR_FSS_H
#define GS_ADCS_PARAM_SENSOR_FSS_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a sensor_fss.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_SENSOR_FSS_TABLE_NAME                    "sensor_fss"
/** Table id */
#define GS_ADCS_SENSOR_FSS_TABLE_ID                      71
/** Legacy table id definition */
#define GS_ADCS_SENSOR_FSS_TABLE_MEM_ID                  71
/** Table data size (bytes */
#define GS_ADCS_SENSOR_FSS_TABLE_SIZE                    688 // bytes
/** Table rows (count) */
#define GS_ADCS_SENSOR_FSS_TABLE_ROWS                    11

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of addr: GSSB address of the FSS */
#define GS_ADCS_SENSOR_FSS_ADDR                                          0                  // 0x0000 uint8
/** Address of csp_node: CSP node the FSS */
#define GS_ADCS_SENSOR_FSS_CSP_NODE                                      1                  // 0x0001 uint8
/** Address of p: Optic height (index 0), offset (x, y - index 1,2), and rotation (index 3) */
#define GS_ADCS_SENSOR_FSS_P(idx)                                   (    4 + ( 4 * (idx)))  // 0x0004 float
/** Array size of p: Optic height (index 0), offset (x, y - index 1,2), and rotation (index 3) */
#define GS_ADCS_SENSOR_FSS_P_ARRAY_SIZE                                  4
/** Address of q: Quaternion describing the location of the sensor relative to body frame */
#define GS_ADCS_SENSOR_FSS_Q(idx)                                   (   20 + ( 4 * (idx)))  // 0x0014 float
/** Array size of q: Quaternion describing the location of the sensor relative to body frame */
#define GS_ADCS_SENSOR_FSS_Q_ARRAY_SIZE                                  4
/** Address of Cvalid: Specify whether the calibration values are valid or not */
#define GS_ADCS_SENSOR_FSS_CVALID                                       36                  // 0x0024 uint8
/** Address of Ctheta0: Calibration lookup table for elevation theta index 0 */
#define GS_ADCS_SENSOR_FSS_CTHETA0(idx)                             (   40 + ( 4 * (idx)))  // 0x0028 float
/** Array size of Ctheta0: Calibration lookup table for elevation theta index 0 */
#define GS_ADCS_SENSOR_FSS_CTHETA0_ARRAY_SIZE                           27
/** Address of Ctheta1: Calibration lookup table for elevation theta index 1 */
#define GS_ADCS_SENSOR_FSS_CTHETA1(idx)                             (  148 + ( 4 * (idx)))  // 0x0094 float
/** Array size of Ctheta1: Calibration lookup table for elevation theta index 1 */
#define GS_ADCS_SENSOR_FSS_CTHETA1_ARRAY_SIZE                           27
/** Address of Ctheta2: Calibration lookup table for elevation theta index 2 */
#define GS_ADCS_SENSOR_FSS_CTHETA2(idx)                             (  256 + ( 4 * (idx)))  // 0x0100 float
/** Array size of Ctheta2: Calibration lookup table for elevation theta index 2 */
#define GS_ADCS_SENSOR_FSS_CTHETA2_ARRAY_SIZE                           27
/** Address of Cphi0: Calibration lookup table for azimuth phi index 0 */
#define GS_ADCS_SENSOR_FSS_CPHI0(idx)                               (  364 + ( 4 * (idx)))  // 0x016c float
/** Array size of Cphi0: Calibration lookup table for azimuth phi index 0 */
#define GS_ADCS_SENSOR_FSS_CPHI0_ARRAY_SIZE                             27
/** Address of Cphi1: Calibration lookup table for azimuth phi index 1 */
#define GS_ADCS_SENSOR_FSS_CPHI1(idx)                               (  472 + ( 4 * (idx)))  // 0x01d8 float
/** Array size of Cphi1: Calibration lookup table for azimuth phi index 1 */
#define GS_ADCS_SENSOR_FSS_CPHI1_ARRAY_SIZE                             27
/** Address of Cphi2: Calibration lookup table for azimuth phi index 2 */
#define GS_ADCS_SENSOR_FSS_CPHI2(idx)                               (  580 + ( 4 * (idx)))  // 0x0244 float
/** Array size of Cphi2: Calibration lookup table for azimuth phi index 2 */
#define GS_ADCS_SENSOR_FSS_CPHI2_ARRAY_SIZE                             27
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
