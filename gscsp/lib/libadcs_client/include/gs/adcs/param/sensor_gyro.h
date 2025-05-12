#ifndef GS_ADCS_PARAM_SENSOR_GYRO_H
#define GS_ADCS_PARAM_SENSOR_GYRO_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a sensor_gyro.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_SENSOR_GYRO_TABLE_NAME                   "sensor_gyro"
/** Table id */
#define GS_ADCS_SENSOR_GYRO_TABLE_ID                     81
/** Legacy table id definition */
#define GS_ADCS_SENSOR_GYRO_TABLE_MEM_ID                 81
/** Table data size (bytes */
#define GS_ADCS_SENSOR_GYRO_TABLE_SIZE                   48 // bytes
/** Table rows (count) */
#define GS_ADCS_SENSOR_GYRO_TABLE_ROWS                   9

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of scale: Gyro scale */
#define GS_ADCS_SENSOR_GYRO_SCALE(idx)                              (    0 + ( 4 * (idx)))  // 0x0000 float
/** Array size of scale: Gyro scale */
#define GS_ADCS_SENSOR_GYRO_SCALE_ARRAY_SIZE                             3
/** Address of offset: Gyro offset */
#define GS_ADCS_SENSOR_GYRO_OFFSET(idx)                             (   12 + ( 4 * (idx)))  // 0x000c float
/** Array size of offset: Gyro offset */
#define GS_ADCS_SENSOR_GYRO_OFFSET_ARRAY_SIZE                            3
/** Address of temp: Gyro temperature scale */
#define GS_ADCS_SENSOR_GYRO_TEMP(idx)                               (   24 + ( 4 * (idx)))  // 0x0018 float
/** Array size of temp: Gyro temperature scale */
#define GS_ADCS_SENSOR_GYRO_TEMP_ARRAY_SIZE                              3
/** Address of axis: Gyro axis */
#define GS_ADCS_SENSOR_GYRO_AXIS(idx)                               (   36 + ( 1 * (idx)))  // 0x0024 uint8
/** Array size of axis: Gyro axis */
#define GS_ADCS_SENSOR_GYRO_AXIS_ARRAY_SIZE                              3
/** Address of sign: Gyro sign */
#define GS_ADCS_SENSOR_GYRO_SIGN(idx)                               (   39 + ( 1 * (idx)))  // 0x0027 int8
/** Array size of sign: Gyro sign */
#define GS_ADCS_SENSOR_GYRO_SIGN_ARRAY_SIZE                              3
/** Address of pwr_node: Power node (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_PWR_NODE                                    42                  // 0x002a uint8
/** Address of pwr_chan: Power channel (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_PWR_CHAN                                    43                  // 0x002b uint8
/** Address of enable: Enable flag (only used for the STIM210) */
#define GS_ADCS_SENSOR_GYRO_ENABLE                                      44                  // 0x002c uint8
/** Address of _filler_end: Filler for alignment */
#define GS_ADCS_SENSOR_GYRO__FILLER_END                                 45                  // 0x002d data
/** Length/size of _filler_end (bytes): Filler for alignment */
#define GS_ADCS_SENSOR_GYRO__FILLER_END_LENGTH                           3
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
