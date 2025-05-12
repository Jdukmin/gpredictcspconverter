#ifndef GS_ADCS_PARAM_SENSOR_A3200_H
#define GS_ADCS_PARAM_SENSOR_A3200_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a sensor_a3200.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_SENSOR_A3200_TABLE_NAME                  "sensor_a3200"
/** Table id */
#define GS_ADCS_SENSOR_A3200_TABLE_ID                    82
/** Legacy table id definition */
#define GS_ADCS_SENSOR_A3200_TABLE_MEM_ID                82
/** Table data size (bytes */
#define GS_ADCS_SENSOR_A3200_TABLE_SIZE                  160 // bytes
/** Table rows (count) */
#define GS_ADCS_SENSOR_A3200_TABLE_ROWS                  16

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of mag_offset: Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_OFFSET(idx)                        (    0 + ( 4 * (idx)))  // 0x0000 float
/** Array size of mag_offset: Magnetometer offset vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_OFFSET_ARRAY_SIZE                       3
/** Address of mag_scale: Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SCALE(idx)                         (   12 + ( 4 * (idx)))  // 0x000c float
/** Array size of mag_scale: Magnetometer scale vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SCALE_ARRAY_SIZE                        3
/** Address of mag_rotation: Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_A3200_MAG_ROTATION(idx)                      (   24 + ( 4 * (idx)))  // 0x0018 float
/** Array size of mag_rotation: Rotation matrix for magnetometer scale compensation */
#define GS_ADCS_SENSOR_A3200_MAG_ROTATION_ARRAY_SIZE                     9
/** Address of mag_rot_t: Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_A3200_MAG_ROT_T(idx)                         (   60 + ( 4 * (idx)))  // 0x003c float
/** Array size of mag_rot_t: Transpose of rotation matrix (read only) */
#define GS_ADCS_SENSOR_A3200_MAG_ROT_T_ARRAY_SIZE                        9
/** Address of mag_max: Magnetometer expected max field length */
#define GS_ADCS_SENSOR_A3200_MAG_MAX                                    96                  // 0x0060 float
/** Address of mag_axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_AXIS(idx)                          (  100 + ( 1 * (idx)))  // 0x0064 uint8
/** Array size of mag_axis: Magnetometer axis vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_AXIS_ARRAY_SIZE                         3
/** Address of mag_sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SIGN(idx)                          (  103 + ( 1 * (idx)))  // 0x0067 int8
/** Array size of mag_sign: Magnetometer sign vector [x y z] */
#define GS_ADCS_SENSOR_A3200_MAG_SIGN_ARRAY_SIZE                         3
/** Address of mag_gain: Magnetometer gain calibration value */
#define GS_ADCS_SENSOR_A3200_MAG_GAIN                                  106                  // 0x006a int8
/** Address of mag_enable: Enable/disable magnetometer axis mesurement */
#define GS_ADCS_SENSOR_A3200_MAG_ENABLE(idx)                        (  107 + ( 1 * (idx)))  // 0x006b uint8
/** Array size of mag_enable: Enable/disable magnetometer axis mesurement */
#define GS_ADCS_SENSOR_A3200_MAG_ENABLE_ARRAY_SIZE                       3
/** Address of gyro_scale: Gyro scale */
#define GS_ADCS_SENSOR_A3200_GYRO_SCALE(idx)                        (  112 + ( 4 * (idx)))  // 0x0070 float
/** Array size of gyro_scale: Gyro scale */
#define GS_ADCS_SENSOR_A3200_GYRO_SCALE_ARRAY_SIZE                       3
/** Address of gyro_offset: Gyro offset */
#define GS_ADCS_SENSOR_A3200_GYRO_OFFSET(idx)                       (  124 + ( 4 * (idx)))  // 0x007c float
/** Array size of gyro_offset: Gyro offset */
#define GS_ADCS_SENSOR_A3200_GYRO_OFFSET_ARRAY_SIZE                      3
/** Address of gyro_temp: Gyro temperature scale */
#define GS_ADCS_SENSOR_A3200_GYRO_TEMP(idx)                         (  136 + ( 4 * (idx)))  // 0x0088 float
/** Array size of gyro_temp: Gyro temperature scale */
#define GS_ADCS_SENSOR_A3200_GYRO_TEMP_ARRAY_SIZE                        3
/** Address of gyro_axis: Gyro axis */
#define GS_ADCS_SENSOR_A3200_GYRO_AXIS(idx)                         (  148 + ( 1 * (idx)))  // 0x0094 uint8
/** Array size of gyro_axis: Gyro axis */
#define GS_ADCS_SENSOR_A3200_GYRO_AXIS_ARRAY_SIZE                        3
/** Address of gyro_sign: Gyro sign */
#define GS_ADCS_SENSOR_A3200_GYRO_SIGN(idx)                         (  151 + ( 1 * (idx)))  // 0x0097 int8
/** Array size of gyro_sign: Gyro sign */
#define GS_ADCS_SENSOR_A3200_GYRO_SIGN_ARRAY_SIZE                        3
/** Address of gyro_enable: Enable/disable gyro axis mesurement */
#define GS_ADCS_SENSOR_A3200_GYRO_ENABLE(idx)                       (  154 + ( 1 * (idx)))  // 0x009a int8
/** Array size of gyro_enable: Enable/disable gyro axis mesurement */
#define GS_ADCS_SENSOR_A3200_GYRO_ENABLE_ARRAY_SIZE                      3
/** Address of _filler_end: Filler for alignment */
#define GS_ADCS_SENSOR_A3200__FILLER_END                               157                  // 0x009d data
/** Length/size of _filler_end (bytes): Filler for alignment */
#define GS_ADCS_SENSOR_A3200__FILLER_END_LENGTH                          3
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
