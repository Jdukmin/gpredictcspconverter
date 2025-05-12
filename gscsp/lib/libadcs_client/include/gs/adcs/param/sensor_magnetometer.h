#ifndef GS_ADCS_PARAM_SENSOR_MAGNETOMETER_H
#define GS_ADCS_PARAM_SENSOR_MAGNETOMETER_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a sensor_magnetometer.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_SENSOR_MAGNETOMETER_TABLE_NAME           "sensor_magnetometer"
/** Table id */
#define GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ID             82
/** Legacy table id definition */
#define GS_ADCS_SENSOR_MAGNETOMETER_TABLE_MEM_ID         82
/** Table data size (bytes */
#define GS_ADCS_SENSOR_MAGNETOMETER_TABLE_SIZE           112 // bytes
/** Table rows (count) */
#define GS_ADCS_SENSOR_MAGNETOMETER_TABLE_ROWS           11

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of offset: Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_OFFSET(idx)                     (    0 + ( 4 * (idx)))  // 0x0000 float
/** Array size of offset: Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_OFFSET_ARRAY_SIZE                    3
/** Address of scale: Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SCALE(idx)                      (   12 + ( 4 * (idx)))  // 0x000c float
/** Array size of scale: Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SCALE_ARRAY_SIZE                     3
/** Address of rotation: Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROTATION(idx)                   (   24 + ( 4 * (idx)))  // 0x0018 float
/** Array size of rotation: Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROTATION_ARRAY_SIZE                  9
/** Address of rot_trans: Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS(idx)                  (   60 + ( 4 * (idx)))  // 0x003c float
/** Array size of rot_trans: Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ROT_TRANS_ARRAY_SIZE                 9
/** Address of max: Magnetometer expected max field length */
#define GS_ADCS_SENSOR_MAGNETOMETER_MAX                                 96                  // 0x0060 float
/** Address of axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_AXIS(idx)                       (  100 + ( 1 * (idx)))  // 0x0064 uint8
/** Array size of axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_AXIS_ARRAY_SIZE                      3
/** Address of sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SIGN(idx)                       (  103 + ( 1 * (idx)))  // 0x0067 int8
/** Array size of sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_SIGN_ARRAY_SIZE                      3
/** Address of enable: Magnetometer enable vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_ENABLE(idx)                     (  106 + ( 1 * (idx)))  // 0x006a uint8
/** Array size of enable: Magnetometer enable vector [x y z] */
#define GS_ADCS_SENSOR_MAGNETOMETER_ENABLE_ARRAY_SIZE                    3
/** Address of gain: Magnetometer gain calibration value */
#define GS_ADCS_SENSOR_MAGNETOMETER_GAIN                               109                  // 0x006d int8
/** Address of addr: Magnetometer address (only used in external magnetometer) */
#define GS_ADCS_SENSOR_MAGNETOMETER_ADDR                               110                  // 0x006e uint8
/** Address of temp_addr: Magnetometer temperature address (only used in external magnetometer) */
#define GS_ADCS_SENSOR_MAGNETOMETER_TEMP_ADDR                          111                  // 0x006f uint8
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
