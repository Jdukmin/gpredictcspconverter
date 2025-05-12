#ifndef GS_ADCS_PARAM_GNC_COMMON_H
#define GS_ADCS_PARAM_GNC_COMMON_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a gnc_common.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_GNC_COMMON_TABLE_NAME                    "gnc_common"
/** Table id */
#define GS_ADCS_GNC_COMMON_TABLE_ID                      50
/** Legacy table id definition */
#define GS_ADCS_GNC_COMMON_TABLE_MEM_ID                  50
/** Table data size (bytes */
#define GS_ADCS_GNC_COMMON_TABLE_SIZE                    248 // bytes
/** Table rows (count) */
#define GS_ADCS_GNC_COMMON_TABLE_ROWS                    28

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of inertia: SC inertia along the three principal axes [kg*m^2] */
#define GS_ADCS_GNC_COMMON_INERTIA(idx)                             (    0 + ( 4 * (idx)))  // 0x0000 float
/** Array size of inertia: SC inertia along the three principal axes [kg*m^2] */
#define GS_ADCS_GNC_COMMON_INERTIA_ARRAY_SIZE                            3
/** Address of acs_init: The initial desired ACS state */
#define GS_ADCS_GNC_COMMON_ACS_INIT                                     12                  // 0x000c uint8
/** Address of ads_init: The initial desired ADS state */
#define GS_ADCS_GNC_COMMON_ADS_INIT                                     13                  // 0x000d uint8
/** Address of ephem_init: The initial desired ephem state */
#define GS_ADCS_GNC_COMMON_EPHEM_INIT                                   14                  // 0x000e uint8
/** Address of sampletime: The ADCS sample time [ms] */
#define GS_ADCS_GNC_COMMON_SAMPLETIME                                   16                  // 0x0010 uint16
/** Address of bdot_divider: How often should the Bdot controller be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_BDOT_DIVIDER                                 18                  // 0x0012 uint16
/** Address of ephem_divider: How often should the ephemeris calculations be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_EPHEM_DIVIDER                                20                  // 0x0014 uint16
/** Address of kf_divider: How often should the UKF be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_KF_DIVIDER                                   22                  // 0x0016 uint16
/** Address of ctrl_divider: How often should the custom (fine pointing) controller be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_CTRL_DIVIDER                                 24                  // 0x0018 uint16
/** Address of pwm_deadtime: Deprecated */
#define GS_ADCS_GNC_COMMON_PWM_DEADTIME                                 26                  // 0x001a uint16
/** Address of tleline1: The first line of the TLE for the SC */
#define GS_ADCS_GNC_COMMON_TLELINE1                                     28                  // 0x001c string
/** Length/size of tleline1 (bytes): The first line of the TLE for the SC */
#define GS_ADCS_GNC_COMMON_TLELINE1_LENGTH                              70
/** Address of tleline2: The second line of the TLE for the SC */
#define GS_ADCS_GNC_COMMON_TLELINE2                                     98                  // 0x0062 string
/** Length/size of tleline2 (bytes): The second line of the TLE for the SC */
#define GS_ADCS_GNC_COMMON_TLELINE2_LENGTH                              70
/** Address of teme2eci: 0=Do not do teme2eci conversion, 1=Do teme2eci conversion */
#define GS_ADCS_GNC_COMMON_TEME2ECI                                    168                  // 0x00a8 bool
/** Address of const_ctrl: Constant dutycycle for the three magnetorquers */
#define GS_ADCS_GNC_COMMON_CONST_CTRL(idx)                          (  172 + ( 4 * (idx)))  // 0x00ac float
/** Array size of const_ctrl: Constant dutycycle for the three magnetorquers */
#define GS_ADCS_GNC_COMMON_CONST_CTRL_ARRAY_SIZE                         3
/** Address of bdot_to_ctrl: Threshold for going from detumbling mode to pointing mode */
#define GS_ADCS_GNC_COMMON_BDOT_TO_CTRL                                184                  // 0x00b8 float
/** Address of ctrl_to_bdot: Threshold for going from pointing mode to detumbling mode */
#define GS_ADCS_GNC_COMMON_CTRL_TO_BDOT                                188                  // 0x00bc float
/** Address of bdot_tconst: Coefficient of averaging for BDOT filter - shall be between 0 and 1 */
#define GS_ADCS_GNC_COMMON_BDOT_TCONST                                 192                  // 0x00c0 float
/** Address of bdot_tconst2: Coefficient of averaging for rate norm filter */
#define GS_ADCS_GNC_COMMON_BDOT_TCONST2                                196                  // 0x00c4 float
/** Address of bdot_tsep: Time seperation between fast and slow filters, must be larger than 1 */
#define GS_ADCS_GNC_COMMON_BDOT_TSEP                                   200                  // 0x00c8 float
/** Address of bdot_thres: Actuation thresholds nT/s - for each axis */
#define GS_ADCS_GNC_COMMON_BDOT_THRES(idx)                          (  204 + ( 4 * (idx)))  // 0x00cc float
/** Array size of bdot_thres: Actuation thresholds nT/s - for each axis */
#define GS_ADCS_GNC_COMMON_BDOT_THRES_ARRAY_SIZE                         3
/** Address of bdot_t_limit: Maximum actuation signal allowed on each torquer axis */
#define GS_ADCS_GNC_COMMON_BDOT_T_LIMIT(idx)                        (  216 + ( 4 * (idx)))  // 0x00d8 float
/** Array size of bdot_t_limit: Maximum actuation signal allowed on each torquer axis */
#define GS_ADCS_GNC_COMMON_BDOT_T_LIMIT_ARRAY_SIZE                       3
/** Address of bdot_axis: Nn which axis is the bias 0=x, 1=y, 2=z */
#define GS_ADCS_GNC_COMMON_BDOT_AXIS                                   228                  // 0x00e4 uint8
/** Address of bdot_bstreng: 0-100 bias strength */
#define GS_ADCS_GNC_COMMON_BDOT_BSTRENG                                229                  // 0x00e5 uint8
/** Address of bdot_sign: Direction, -1 or 1 */
#define GS_ADCS_GNC_COMMON_BDOT_SIGN                                   230                  // 0x00e6 int8
/** Address of bdot_mag: 0=internal magnetometer, 1=External magnetometer */
#define GS_ADCS_GNC_COMMON_BDOT_MAG                                    231                  // 0x00e7 uint8
/** Address of bdot_rateref: Reference rate to the bdot [mG/s] */
#define GS_ADCS_GNC_COMMON_BDOT_RATEREF(idx)                        (  232 + ( 4 * (idx)))  // 0x00e8 float
/** Array size of bdot_rateref: Reference rate to the bdot [mG/s] */
#define GS_ADCS_GNC_COMMON_BDOT_RATEREF_ARRAY_SIZE                       3
/** Address of mtq_decay_t: The time to wait for the magnetorquers to decay before sampling magnetometers [ms] */
#define GS_ADCS_GNC_COMMON_MTQ_DECAY_T                                 244                  // 0x00f4 uint8
/** Address of mag_sample_t: Estimate for how long it takes to sample magnetometers (upper bound) [ms] */
#define GS_ADCS_GNC_COMMON_MAG_SAMPLE_T                                245                  // 0x00f5 uint8
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
