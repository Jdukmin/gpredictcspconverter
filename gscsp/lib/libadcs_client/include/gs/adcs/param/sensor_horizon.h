#ifndef GS_ADCS_PARAM_SENSOR_HORIZON_H
#define GS_ADCS_PARAM_SENSOR_HORIZON_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a sensor_horizon.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_SENSOR_HORIZON_TABLE_NAME                "sensor_horizon"
/** Table id */
#define GS_ADCS_SENSOR_HORIZON_TABLE_ID                  88
/** Legacy table id definition */
#define GS_ADCS_SENSOR_HORIZON_TABLE_MEM_ID              88
/** Table data size (bytes */
#define GS_ADCS_SENSOR_HORIZON_TABLE_SIZE                176 // bytes
/** Table rows (count) */
#define GS_ADCS_SENSOR_HORIZON_TABLE_ROWS                14

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of enable_task: Enable disable HTPA task */
#define GS_ADCS_SENSOR_HORIZON_ENABLE_TASK                               0                  // 0x0000 bool
/** Address of htpa_div: HTPA sample time divider */
#define GS_ADCS_SENSOR_HORIZON_HTPA_DIV                                  1                  // 0x0001 uint8
/** Address of addr: I2C address of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_ADDR(idx)                            (    2 + ( 1 * (idx)))  // 0x0002 uint8
/** Array size of addr: I2C address of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_ADDR_ARRAY_SIZE                           4
/** Address of addr_eeprom: I2C address of the horizon sensor eeprom */
#define GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM(idx)                     (    6 + ( 1 * (idx)))  // 0x0006 uint8
/** Array size of addr_eeprom: I2C address of the horizon sensor eeprom */
#define GS_ADCS_SENSOR_HORIZON_ADDR_EEPROM_ARRAY_SIZE                    4
/** Address of focal_len: Focal length of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_FOCAL_LEN(idx)                       (   12 + ( 4 * (idx)))  // 0x000c float
/** Array size of focal_len: Focal length of the horizon sensor */
#define GS_ADCS_SENSOR_HORIZON_FOCAL_LEN_ARRAY_SIZE                      4
/** Address of px_pitch: Pixle pitch */
#define GS_ADCS_SENSOR_HORIZON_PX_PITCH(idx)                        (   28 + ( 4 * (idx)))  // 0x001c float
/** Array size of px_pitch: Pixle pitch */
#define GS_ADCS_SENSOR_HORIZON_PX_PITCH_ARRAY_SIZE                       4
/** Address of px_size: Pixle size */
#define GS_ADCS_SENSOR_HORIZON_PX_SIZE(idx)                         (   44 + ( 4 * (idx)))  // 0x002c float
/** Array size of px_size: Pixle size */
#define GS_ADCS_SENSOR_HORIZON_PX_SIZE_ARRAY_SIZE                        4
/** Address of dis_coeff: Radial distortion coefficients 4*[k1 k2] */
#define GS_ADCS_SENSOR_HORIZON_DIS_COEFF(idx)                       (   60 + ( 4 * (idx)))  // 0x003c float
/** Array size of dis_coeff: Radial distortion coefficients 4*[k1 k2] */
#define GS_ADCS_SENSOR_HORIZON_DIS_COEFF_ARRAY_SIZE                      8
/** Address of grad_thrs: Gradient threshold for the estimation algorithm (tuning parameter) */
#define GS_ADCS_SENSOR_HORIZON_GRAD_THRS(idx)                       (   92 + ( 4 * (idx)))  // 0x005c float
/** Array size of grad_thrs: Gradient threshold for the estimation algorithm (tuning parameter) */
#define GS_ADCS_SENSOR_HORIZON_GRAD_THRS_ARRAY_SIZE                      4
/** Address of enable: enable the horizon sensor  */
#define GS_ADCS_SENSOR_HORIZON_ENABLE(idx)                          (  108 + ( 1 * (idx)))  // 0x006c bool
/** Array size of enable: enable the horizon sensor  */
#define GS_ADCS_SENSOR_HORIZON_ENABLE_ARRAY_SIZE                         4
/** Address of htpa0_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA0_Q(idx)                         (  112 + ( 4 * (idx)))  // 0x0070 float
/** Array size of htpa0_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA0_Q_ARRAY_SIZE                        4
/** Address of htpa1_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA1_Q(idx)                         (  128 + ( 4 * (idx)))  // 0x0080 float
/** Array size of htpa1_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA1_Q_ARRAY_SIZE                        4
/** Address of htpa2_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA2_Q(idx)                         (  144 + ( 4 * (idx)))  // 0x0090 float
/** Array size of htpa2_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA2_Q_ARRAY_SIZE                        4
/** Address of htpa3_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA3_Q(idx)                         (  160 + ( 4 * (idx)))  // 0x00a0 float
/** Array size of htpa3_q: Quaternion describing the orientation of the sensor relative to the body frame */
#define GS_ADCS_SENSOR_HORIZON_HTPA3_Q_ARRAY_SIZE                        4
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
