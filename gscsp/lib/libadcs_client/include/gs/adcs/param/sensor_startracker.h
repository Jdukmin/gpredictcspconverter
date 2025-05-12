#ifndef GS_ADCS_PARAM_SENSOR_STARTRACKER_H
#define GS_ADCS_PARAM_SENSOR_STARTRACKER_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a sensor_startracker.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_SENSOR_STARTRACKER_TABLE_NAME            "sensor_startracker"
/** Table id */
#define GS_ADCS_SENSOR_STARTRACKER_TABLE_ID              89
/** Legacy table id definition */
#define GS_ADCS_SENSOR_STARTRACKER_TABLE_MEM_ID          89
/** Table data size (bytes */
#define GS_ADCS_SENSOR_STARTRACKER_TABLE_SIZE            20 // bytes
/** Table rows (count) */
#define GS_ADCS_SENSOR_STARTRACKER_TABLE_ROWS            3

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of str_uart: Star tracker uart instance [#] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_UART                              0                  // 0x0000 uint8
/** Address of en_str: Enable and initialize star tracker */
#define GS_ADCS_SENSOR_STARTRACKER_EN_STR                                1                  // 0x0001 bool
/** Address of str_q: Star tracker orientation, str to body [q1 q2 q3 q4] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_Q(idx)                       (    4 + ( 4 * (idx)))  // 0x0004 float
/** Array size of str_q: Star tracker orientation, str to body [q1 q2 q3 q4] */
#define GS_ADCS_SENSOR_STARTRACKER_STR_Q_ARRAY_SIZE                      4
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
