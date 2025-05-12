#ifndef GS_ADCS_PARAM_SENSOR_CSS_H
#define GS_ADCS_PARAM_SENSOR_CSS_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a sensor_css.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_SENSOR_CSS_TABLE_NAME                    "sensor_css"
/** Table id */
#define GS_ADCS_SENSOR_CSS_TABLE_ID                      80
/** Legacy table id definition */
#define GS_ADCS_SENSOR_CSS_TABLE_MEM_ID                  80
/** Table data size (bytes */
#define GS_ADCS_SENSOR_CSS_TABLE_SIZE                    56 // bytes
/** Table rows (count) */
#define GS_ADCS_SENSOR_CSS_TABLE_ROWS                    7

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of scale: Calibration value for the CSS */
#define GS_ADCS_SENSOR_CSS_SCALE(idx)                               (    0 + ( 4 * (idx)))  // 0x0000 float
/** Array size of scale: Calibration value for the CSS */
#define GS_ADCS_SENSOR_CSS_SCALE_ARRAY_SIZE                              6
/** Address of addr: The address of the the interstage the CSS is mounted on */
#define GS_ADCS_SENSOR_CSS_ADDR(idx)                                (   24 + ( 1 * (idx)))  // 0x0018 uint8
/** Array size of addr: The address of the the interstage the CSS is mounted on */
#define GS_ADCS_SENSOR_CSS_ADDR_ARRAY_SIZE                               6
/** Address of enable: Flag whether the CSS is enabled or not */
#define GS_ADCS_SENSOR_CSS_ENABLE(idx)                              (   30 + ( 1 * (idx)))  // 0x001e uint8
/** Array size of enable: Flag whether the CSS is enabled or not */
#define GS_ADCS_SENSOR_CSS_ENABLE_ARRAY_SIZE                             6
/** Address of type: CSS Connection type 0/1 */
#define GS_ADCS_SENSOR_CSS_TYPE(idx)                                (   36 + ( 1 * (idx)))  // 0x0024 uint8
/** Array size of type: CSS Connection type 0/1 */
#define GS_ADCS_SENSOR_CSS_TYPE_ARRAY_SIZE                               6
/** Address of max_init: Current maximum value for the sunsensor in the sunsensor max tracking algorithm */
#define GS_ADCS_SENSOR_CSS_MAX_INIT                                     44                  // 0x002c float
/** Address of abs_max: Maximum permissible value for the sunsensor in the sunsensor max tracking algorithm */
#define GS_ADCS_SENSOR_CSS_ABS_MAX                                      48                  // 0x0030 float
/** Address of threshold: Threshold for dark (eclipse) detection */
#define GS_ADCS_SENSOR_CSS_THRESHOLD                                    52                  // 0x0034 float
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
