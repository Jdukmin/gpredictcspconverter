#ifndef GS_ADCS_PARAM_GNC_ADS_H
#define GS_ADCS_PARAM_GNC_ADS_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a gnc_ads.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_GNC_ADS_TABLE_NAME                       "gnc_ads"
/** Table id */
#define GS_ADCS_GNC_ADS_TABLE_ID                         51
/** Legacy table id definition */
#define GS_ADCS_GNC_ADS_TABLE_MEM_ID                     51
/** Table data size (bytes */
#define GS_ADCS_GNC_ADS_TABLE_SIZE                       97 // bytes
/** Table rows (count) */
#define GS_ADCS_GNC_ADS_TABLE_ROWS                       32

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of Q_quat: Model covariance, quaternion */
#define GS_ADCS_GNC_ADS_Q_QUAT                                           0                  // 0x0000 float
/** Address of Q_rate: Model covarinace, angular rate */
#define GS_ADCS_GNC_ADS_Q_RATE                                           4                  // 0x0004 float
/** Address of Q_magbias: Model covariance, magnetic dipole bias */
#define GS_ADCS_GNC_ADS_Q_MAGBIAS                                        8                  // 0x0008 float
/** Address of Q_gyrobias: Model covariance, gyroscope bias */
#define GS_ADCS_GNC_ADS_Q_GYROBIAS                                      12                  // 0x000c float
/** Address of Q_dtorque: Not used */
#define GS_ADCS_GNC_ADS_Q_DTORQUE                                       16                  // 0x0010 float
/** Address of R_css: Measurement covariance, CSS */
#define GS_ADCS_GNC_ADS_R_CSS                                           20                  // 0x0014 float
/** Address of R_mag: Measurement covariance, magnetometer */
#define GS_ADCS_GNC_ADS_R_MAG                                           24                  // 0x0018 float
/** Address of R_gyro: Measurement covariance, gyroscope */
#define GS_ADCS_GNC_ADS_R_GYRO                                          28                  // 0x001c float
/** Address of R_fss: Measurement covariance, FSS */
#define GS_ADCS_GNC_ADS_R_FSS                                           32                  // 0x0020 float
/** Address of R_st: Measurement covariance, star tracker */
#define GS_ADCS_GNC_ADS_R_ST                                            36                  // 0x0024 float
/** Address of R_htpa: Measurement covariance, horizon sensor */
#define GS_ADCS_GNC_ADS_R_HTPA                                          40                  // 0x0028 float
/** Address of P_quat: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_QUAT                                          44                  // 0x002c float
/** Address of P_rate: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_RATE                                          48                  // 0x0030 float
/** Address of P_magbias: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_MAGBIAS                                       52                  // 0x0034 float
/** Address of P_gyrobias: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_GYROBIAS                                      56                  // 0x0038 float
/** Address of P_dtorque: Not used */
#define GS_ADCS_GNC_ADS_P_DTORQUE                                       60                  // 0x003c float
/** Address of no_chng_dsbl: Enables/Disables that no change in a sensor measurement will disable it in the meas update */
#define GS_ADCS_GNC_ADS_NO_CHNG_DSBL                                    64                  // 0x0040 bool
/** Address of en_ctrltorque: Enables/Disables the use of control torque in UKF model */
#define GS_ADCS_GNC_ADS_EN_CTRLTORQUE                                   65                  // 0x0041 bool
/** Address of enable_fss: Enable/Disable FSS input to the kalman filter */
#define GS_ADCS_GNC_ADS_ENABLE_FSS                                      66                  // 0x0042 uint8
/** Address of enable_st: Enables/Disables the use of the Star Tracker in the UKF */
#define GS_ADCS_GNC_ADS_ENABLE_ST                                       67                  // 0x0043 bool
/** Address of enable_htpa: Enables/Disables the use of the Horizon sensor in the UKF */
#define GS_ADCS_GNC_ADS_ENABLE_HTPA                                     68                  // 0x0044 bool
/** Address of enable_maxcur: Enables/Disables the max-current algorithm */
#define GS_ADCS_GNC_ADS_ENABLE_MAXCUR                                   69                  // 0x0045 bool
/** Address of en_norm_mag: Enable/Disable normalization of mag */
#define GS_ADCS_GNC_ADS_EN_NORM_MAG                                     70                  // 0x0046 bool
/** Address of en_norm_bias: Enable/Disable normalization of mag bias */
#define GS_ADCS_GNC_ADS_EN_NORM_BIAS                                    71                  // 0x0047 bool
/** Address of mag_choice: Choose which magnetormeter to use for the UKF */
#define GS_ADCS_GNC_ADS_MAG_CHOICE                                      72                  // 0x0048 uint8
/** Address of gyro_choice: Choose which magnetormeter to use for the UKF */
#define GS_ADCS_GNC_ADS_GYRO_CHOICE                                     73                  // 0x0049 uint8
/** Address of int_choice: Integrator choice */
#define GS_ADCS_GNC_ADS_INT_CHOICE                                      74                  // 0x004a uint8
/** Address of kf_choice: Which type of kalman filter to use */
#define GS_ADCS_GNC_ADS_KF_CHOICE                                       75                  // 0x004b uint8
/** Address of M_bias: Magnetic field bias (body axis) [A/m^2] */
#define GS_ADCS_GNC_ADS_M_BIAS(idx)                                 (   76 + ( 4 * (idx)))  // 0x004c float
/** Array size of M_bias: Magnetic field bias (body axis) [A/m^2] */
#define GS_ADCS_GNC_ADS_M_BIAS_ARRAY_SIZE                                3
/** Address of min_angle: Minimum accepted angle between magnetic field and sun [deg] */
#define GS_ADCS_GNC_ADS_MIN_ANGLE                                       88                  // 0x0058 float
/** Address of htpa_err: Maximum error angle between a measured magnetic field vector, rotated by the htpa rotation to the LVLH, and the estimated IGRF field vector in the LVLH frame [deg] */
#define GS_ADCS_GNC_ADS_HTPA_ERR                                        92                  // 0x005c float
/** Address of st_override: enable/disable using the ST estimate of q_I_SC to override the UKF state estimate */
#define GS_ADCS_GNC_ADS_ST_OVERRIDE                                     96                  // 0x0060 bool
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
