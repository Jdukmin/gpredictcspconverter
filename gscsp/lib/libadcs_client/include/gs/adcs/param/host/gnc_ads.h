#ifndef GS_ADCS_PARAM_HOST_GNC_ADS_H
#define GS_ADCS_PARAM_HOST_GNC_ADS_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a gnc_ads.
*/

#include <gs/adcs/param/gnc_ads.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_gnc_ads_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Model covariance, quaternion */
    float    Q_quat;
    /** Model covarinace, angular rate */
    float    Q_rate;
    /** Model covariance, magnetic dipole bias */
    float    Q_magbias;
    /** Model covariance, gyroscope bias */
    float    Q_gyrobias;
    /** Not used */
    float    Q_dtorque;
    /** Measurement covariance, CSS */
    float    R_css;
    /** Measurement covariance, magnetometer */
    float    R_mag;
    /** Measurement covariance, gyroscope */
    float    R_gyro;
    /** Measurement covariance, FSS */
    float    R_fss;
    /** Measurement covariance, star tracker */
    float    R_st;
    /** Measurement covariance, horizon sensor */
    float    R_htpa;
    /** Covariance matrix initial value */
    float    P_quat;
    /** Covariance matrix initial value */
    float    P_rate;
    /** Covariance matrix initial value */
    float    P_magbias;
    /** Covariance matrix initial value */
    float    P_gyrobias;
    /** Not used */
    float    P_dtorque;
    /** Enables/Disables that no change in a sensor measurement will disable it in the meas update */
    bool     no_chng_dsbl;
    /** Enables/Disables the use of control torque in UKF model */
    bool     en_ctrltorque;
    /** Enable/Disable FSS input to the kalman filter */
    uint8_t  enable_fss;
    /** Enables/Disables the use of the Star Tracker in the UKF */
    bool     enable_st;
    /** Enables/Disables the use of the Horizon sensor in the UKF */
    bool     enable_htpa;
    /** Enables/Disables the max-current algorithm */
    bool     enable_maxcur;
    /** Enable/Disable normalization of mag */
    bool     en_norm_mag;
    /** Enable/Disable normalization of mag bias */
    bool     en_norm_bias;
    /** Choose which magnetormeter to use for the UKF */
    uint8_t  mag_choice;
    /** Choose which magnetormeter to use for the UKF */
    uint8_t  gyro_choice;
    /** Integrator choice */
    uint8_t  int_choice;
    /** Which type of kalman filter to use */
    uint8_t  kf_choice;
    /** Magnetic field bias (body axis) [A/m^2] */
    float    M_bias[3];
    /** Minimum accepted angle between magnetic field and sun [deg] */
    float    min_angle;
    /** Maximum error angle between a measured magnetic field vector, rotated by the htpa rotation to the LVLH, and the estimated IGRF field vector in the LVLH frame [deg] */
    float    htpa_err;
    /** enable/disable using the ST estimate of q_I_SC to override the UKF state estimate */
    bool     st_override;
} gs_adcs_gnc_ads_memory_t;

/** Table default values. */
extern const gs_adcs_gnc_ads_memory_t gs_adcs_gnc_ads_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set Q_quat: Model covariance, quaternion */
#define GS_ADCS_GNC_ADS_Q_QUAT_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_QUAT, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set Q_quat (no callback): Model covariance, quaternion */
#define GS_ADCS_GNC_ADS_Q_QUAT_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_QUAT, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get Q_quat: Model covariance, quaternion */
#define GS_ADCS_GNC_ADS_Q_QUAT_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_QUAT, value, 0)
/** Get Q_quat (no check - return 0 on failure): Model covariance, quaternion */
#define GS_ADCS_GNC_ADS_Q_QUAT_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_QUAT, 0)
/** Set Q_rate: Model covarinace, angular rate */
#define GS_ADCS_GNC_ADS_Q_RATE_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_RATE, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set Q_rate (no callback): Model covarinace, angular rate */
#define GS_ADCS_GNC_ADS_Q_RATE_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_RATE, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get Q_rate: Model covarinace, angular rate */
#define GS_ADCS_GNC_ADS_Q_RATE_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_RATE, value, 0)
/** Get Q_rate (no check - return 0 on failure): Model covarinace, angular rate */
#define GS_ADCS_GNC_ADS_Q_RATE_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_RATE, 0)
/** Set Q_magbias: Model covariance, magnetic dipole bias */
#define GS_ADCS_GNC_ADS_Q_MAGBIAS_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_MAGBIAS, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set Q_magbias (no callback): Model covariance, magnetic dipole bias */
#define GS_ADCS_GNC_ADS_Q_MAGBIAS_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_MAGBIAS, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get Q_magbias: Model covariance, magnetic dipole bias */
#define GS_ADCS_GNC_ADS_Q_MAGBIAS_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_MAGBIAS, value, 0)
/** Get Q_magbias (no check - return 0 on failure): Model covariance, magnetic dipole bias */
#define GS_ADCS_GNC_ADS_Q_MAGBIAS_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_MAGBIAS, 0)
/** Set Q_gyrobias: Model covariance, gyroscope bias */
#define GS_ADCS_GNC_ADS_Q_GYROBIAS_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_GYROBIAS, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set Q_gyrobias (no callback): Model covariance, gyroscope bias */
#define GS_ADCS_GNC_ADS_Q_GYROBIAS_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_GYROBIAS, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get Q_gyrobias: Model covariance, gyroscope bias */
#define GS_ADCS_GNC_ADS_Q_GYROBIAS_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_GYROBIAS, value, 0)
/** Get Q_gyrobias (no check - return 0 on failure): Model covariance, gyroscope bias */
#define GS_ADCS_GNC_ADS_Q_GYROBIAS_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_GYROBIAS, 0)
/** Set Q_dtorque: Not used */
#define GS_ADCS_GNC_ADS_Q_DTORQUE_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_DTORQUE, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set Q_dtorque (no callback): Not used */
#define GS_ADCS_GNC_ADS_Q_DTORQUE_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_DTORQUE, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get Q_dtorque: Not used */
#define GS_ADCS_GNC_ADS_Q_DTORQUE_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_DTORQUE, value, 0)
/** Get Q_dtorque (no check - return 0 on failure): Not used */
#define GS_ADCS_GNC_ADS_Q_DTORQUE_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_Q_DTORQUE, 0)
/** Set R_css: Measurement covariance, CSS */
#define GS_ADCS_GNC_ADS_R_CSS_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_CSS, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set R_css (no callback): Measurement covariance, CSS */
#define GS_ADCS_GNC_ADS_R_CSS_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_CSS, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get R_css: Measurement covariance, CSS */
#define GS_ADCS_GNC_ADS_R_CSS_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_CSS, value, 0)
/** Get R_css (no check - return 0 on failure): Measurement covariance, CSS */
#define GS_ADCS_GNC_ADS_R_CSS_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_CSS, 0)
/** Set R_mag: Measurement covariance, magnetometer */
#define GS_ADCS_GNC_ADS_R_MAG_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_MAG, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set R_mag (no callback): Measurement covariance, magnetometer */
#define GS_ADCS_GNC_ADS_R_MAG_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_MAG, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get R_mag: Measurement covariance, magnetometer */
#define GS_ADCS_GNC_ADS_R_MAG_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_MAG, value, 0)
/** Get R_mag (no check - return 0 on failure): Measurement covariance, magnetometer */
#define GS_ADCS_GNC_ADS_R_MAG_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_MAG, 0)
/** Set R_gyro: Measurement covariance, gyroscope */
#define GS_ADCS_GNC_ADS_R_GYRO_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_GYRO, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set R_gyro (no callback): Measurement covariance, gyroscope */
#define GS_ADCS_GNC_ADS_R_GYRO_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_GYRO, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get R_gyro: Measurement covariance, gyroscope */
#define GS_ADCS_GNC_ADS_R_GYRO_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_GYRO, value, 0)
/** Get R_gyro (no check - return 0 on failure): Measurement covariance, gyroscope */
#define GS_ADCS_GNC_ADS_R_GYRO_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_GYRO, 0)
/** Set R_fss: Measurement covariance, FSS */
#define GS_ADCS_GNC_ADS_R_FSS_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_FSS, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set R_fss (no callback): Measurement covariance, FSS */
#define GS_ADCS_GNC_ADS_R_FSS_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_FSS, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get R_fss: Measurement covariance, FSS */
#define GS_ADCS_GNC_ADS_R_FSS_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_FSS, value, 0)
/** Get R_fss (no check - return 0 on failure): Measurement covariance, FSS */
#define GS_ADCS_GNC_ADS_R_FSS_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_FSS, 0)
/** Set R_st: Measurement covariance, star tracker */
#define GS_ADCS_GNC_ADS_R_ST_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_ST, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set R_st (no callback): Measurement covariance, star tracker */
#define GS_ADCS_GNC_ADS_R_ST_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_ST, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get R_st: Measurement covariance, star tracker */
#define GS_ADCS_GNC_ADS_R_ST_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_ST, value, 0)
/** Get R_st (no check - return 0 on failure): Measurement covariance, star tracker */
#define GS_ADCS_GNC_ADS_R_ST_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_ST, 0)
/** Set R_htpa: Measurement covariance, horizon sensor */
#define GS_ADCS_GNC_ADS_R_HTPA_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_HTPA, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set R_htpa (no callback): Measurement covariance, horizon sensor */
#define GS_ADCS_GNC_ADS_R_HTPA_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_HTPA, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get R_htpa: Measurement covariance, horizon sensor */
#define GS_ADCS_GNC_ADS_R_HTPA_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_HTPA, value, 0)
/** Get R_htpa (no check - return 0 on failure): Measurement covariance, horizon sensor */
#define GS_ADCS_GNC_ADS_R_HTPA_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_R_HTPA, 0)
/** Set P_quat: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_QUAT_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_QUAT, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set P_quat (no callback): Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_QUAT_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_QUAT, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get P_quat: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_QUAT_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_QUAT, value, 0)
/** Get P_quat (no check - return 0 on failure): Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_QUAT_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_QUAT, 0)
/** Set P_rate: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_RATE_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_RATE, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set P_rate (no callback): Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_RATE_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_RATE, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get P_rate: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_RATE_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_RATE, value, 0)
/** Get P_rate (no check - return 0 on failure): Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_RATE_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_RATE, 0)
/** Set P_magbias: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_MAGBIAS_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_MAGBIAS, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set P_magbias (no callback): Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_MAGBIAS_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_MAGBIAS, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get P_magbias: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_MAGBIAS_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_MAGBIAS, value, 0)
/** Get P_magbias (no check - return 0 on failure): Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_MAGBIAS_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_MAGBIAS, 0)
/** Set P_gyrobias: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_GYROBIAS_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_GYROBIAS, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set P_gyrobias (no callback): Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_GYROBIAS_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_GYROBIAS, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get P_gyrobias: Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_GYROBIAS_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_GYROBIAS, value, 0)
/** Get P_gyrobias (no check - return 0 on failure): Covariance matrix initial value */
#define GS_ADCS_GNC_ADS_P_GYROBIAS_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_GYROBIAS, 0)
/** Set P_dtorque: Not used */
#define GS_ADCS_GNC_ADS_P_DTORQUE_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_DTORQUE, value, GS_PARAM_F_SHOW_SCIENTIFIC)
/** Set P_dtorque (no callback): Not used */
#define GS_ADCS_GNC_ADS_P_DTORQUE_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_DTORQUE, value, GS_PARAM_F_SHOW_SCIENTIFIC | GS_PARAM_F_NO_CALLBACK)
/** Get P_dtorque: Not used */
#define GS_ADCS_GNC_ADS_P_DTORQUE_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_DTORQUE, value, 0)
/** Get P_dtorque (no check - return 0 on failure): Not used */
#define GS_ADCS_GNC_ADS_P_DTORQUE_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_P_DTORQUE, 0)
/** Set no_chng_dsbl: Enables/Disables that no change in a sensor measurement will disable it in the meas update */
#define GS_ADCS_GNC_ADS_NO_CHNG_DSBL_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_NO_CHNG_DSBL, value, 0)
/** Set no_chng_dsbl (no callback): Enables/Disables that no change in a sensor measurement will disable it in the meas update */
#define GS_ADCS_GNC_ADS_NO_CHNG_DSBL_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_NO_CHNG_DSBL, value, GS_PARAM_F_NO_CALLBACK)
/** Get no_chng_dsbl: Enables/Disables that no change in a sensor measurement will disable it in the meas update */
#define GS_ADCS_GNC_ADS_NO_CHNG_DSBL_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_NO_CHNG_DSBL, value, 0)
/** Get no_chng_dsbl (no check - return 0 on failure): Enables/Disables that no change in a sensor measurement will disable it in the meas update */
#define GS_ADCS_GNC_ADS_NO_CHNG_DSBL_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_NO_CHNG_DSBL, 0)
/** Set en_ctrltorque: Enables/Disables the use of control torque in UKF model */
#define GS_ADCS_GNC_ADS_EN_CTRLTORQUE_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_CTRLTORQUE, value, 0)
/** Set en_ctrltorque (no callback): Enables/Disables the use of control torque in UKF model */
#define GS_ADCS_GNC_ADS_EN_CTRLTORQUE_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_CTRLTORQUE, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_ctrltorque: Enables/Disables the use of control torque in UKF model */
#define GS_ADCS_GNC_ADS_EN_CTRLTORQUE_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_CTRLTORQUE, value, 0)
/** Get en_ctrltorque (no check - return 0 on failure): Enables/Disables the use of control torque in UKF model */
#define GS_ADCS_GNC_ADS_EN_CTRLTORQUE_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_CTRLTORQUE, 0)
/** Set enable_fss: Enable/Disable FSS input to the kalman filter */
#define GS_ADCS_GNC_ADS_ENABLE_FSS_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_FSS, value, 0)
/** Set enable_fss (no callback): Enable/Disable FSS input to the kalman filter */
#define GS_ADCS_GNC_ADS_ENABLE_FSS_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_FSS, value, GS_PARAM_F_NO_CALLBACK)
/** Get enable_fss: Enable/Disable FSS input to the kalman filter */
#define GS_ADCS_GNC_ADS_ENABLE_FSS_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_FSS, value, 0)
/** Get enable_fss (no check - return 0 on failure): Enable/Disable FSS input to the kalman filter */
#define GS_ADCS_GNC_ADS_ENABLE_FSS_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_FSS, 0)
/** Set enable_st: Enables/Disables the use of the Star Tracker in the UKF */
#define GS_ADCS_GNC_ADS_ENABLE_ST_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_ST, value, 0)
/** Set enable_st (no callback): Enables/Disables the use of the Star Tracker in the UKF */
#define GS_ADCS_GNC_ADS_ENABLE_ST_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_ST, value, GS_PARAM_F_NO_CALLBACK)
/** Get enable_st: Enables/Disables the use of the Star Tracker in the UKF */
#define GS_ADCS_GNC_ADS_ENABLE_ST_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_ST, value, 0)
/** Get enable_st (no check - return 0 on failure): Enables/Disables the use of the Star Tracker in the UKF */
#define GS_ADCS_GNC_ADS_ENABLE_ST_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_ST, 0)
/** Set enable_htpa: Enables/Disables the use of the Horizon sensor in the UKF */
#define GS_ADCS_GNC_ADS_ENABLE_HTPA_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_HTPA, value, 0)
/** Set enable_htpa (no callback): Enables/Disables the use of the Horizon sensor in the UKF */
#define GS_ADCS_GNC_ADS_ENABLE_HTPA_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_HTPA, value, GS_PARAM_F_NO_CALLBACK)
/** Get enable_htpa: Enables/Disables the use of the Horizon sensor in the UKF */
#define GS_ADCS_GNC_ADS_ENABLE_HTPA_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_HTPA, value, 0)
/** Get enable_htpa (no check - return 0 on failure): Enables/Disables the use of the Horizon sensor in the UKF */
#define GS_ADCS_GNC_ADS_ENABLE_HTPA_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_HTPA, 0)
/** Set enable_maxcur: Enables/Disables the max-current algorithm */
#define GS_ADCS_GNC_ADS_ENABLE_MAXCUR_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_MAXCUR, value, 0)
/** Set enable_maxcur (no callback): Enables/Disables the max-current algorithm */
#define GS_ADCS_GNC_ADS_ENABLE_MAXCUR_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_MAXCUR, value, GS_PARAM_F_NO_CALLBACK)
/** Get enable_maxcur: Enables/Disables the max-current algorithm */
#define GS_ADCS_GNC_ADS_ENABLE_MAXCUR_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_MAXCUR, value, 0)
/** Get enable_maxcur (no check - return 0 on failure): Enables/Disables the max-current algorithm */
#define GS_ADCS_GNC_ADS_ENABLE_MAXCUR_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ENABLE_MAXCUR, 0)
/** Set en_norm_mag: Enable/Disable normalization of mag */
#define GS_ADCS_GNC_ADS_EN_NORM_MAG_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_NORM_MAG, value, 0)
/** Set en_norm_mag (no callback): Enable/Disable normalization of mag */
#define GS_ADCS_GNC_ADS_EN_NORM_MAG_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_NORM_MAG, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_norm_mag: Enable/Disable normalization of mag */
#define GS_ADCS_GNC_ADS_EN_NORM_MAG_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_NORM_MAG, value, 0)
/** Get en_norm_mag (no check - return 0 on failure): Enable/Disable normalization of mag */
#define GS_ADCS_GNC_ADS_EN_NORM_MAG_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_NORM_MAG, 0)
/** Set en_norm_bias: Enable/Disable normalization of mag bias */
#define GS_ADCS_GNC_ADS_EN_NORM_BIAS_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_NORM_BIAS, value, 0)
/** Set en_norm_bias (no callback): Enable/Disable normalization of mag bias */
#define GS_ADCS_GNC_ADS_EN_NORM_BIAS_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_NORM_BIAS, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_norm_bias: Enable/Disable normalization of mag bias */
#define GS_ADCS_GNC_ADS_EN_NORM_BIAS_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_NORM_BIAS, value, 0)
/** Get en_norm_bias (no check - return 0 on failure): Enable/Disable normalization of mag bias */
#define GS_ADCS_GNC_ADS_EN_NORM_BIAS_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_EN_NORM_BIAS, 0)
/** Set mag_choice: Choose which magnetormeter to use for the UKF */
#define GS_ADCS_GNC_ADS_MAG_CHOICE_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_MAG_CHOICE, value, 0)
/** Set mag_choice (no callback): Choose which magnetormeter to use for the UKF */
#define GS_ADCS_GNC_ADS_MAG_CHOICE_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_MAG_CHOICE, value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_choice: Choose which magnetormeter to use for the UKF */
#define GS_ADCS_GNC_ADS_MAG_CHOICE_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_MAG_CHOICE, value, 0)
/** Get mag_choice (no check - return 0 on failure): Choose which magnetormeter to use for the UKF */
#define GS_ADCS_GNC_ADS_MAG_CHOICE_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_MAG_CHOICE, 0)
/** Set gyro_choice: Choose which magnetormeter to use for the UKF */
#define GS_ADCS_GNC_ADS_GYRO_CHOICE_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_GYRO_CHOICE, value, 0)
/** Set gyro_choice (no callback): Choose which magnetormeter to use for the UKF */
#define GS_ADCS_GNC_ADS_GYRO_CHOICE_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_GYRO_CHOICE, value, GS_PARAM_F_NO_CALLBACK)
/** Get gyro_choice: Choose which magnetormeter to use for the UKF */
#define GS_ADCS_GNC_ADS_GYRO_CHOICE_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_GYRO_CHOICE, value, 0)
/** Get gyro_choice (no check - return 0 on failure): Choose which magnetormeter to use for the UKF */
#define GS_ADCS_GNC_ADS_GYRO_CHOICE_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_GYRO_CHOICE, 0)
/** Set int_choice: Integrator choice */
#define GS_ADCS_GNC_ADS_INT_CHOICE_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_INT_CHOICE, value, 0)
/** Set int_choice (no callback): Integrator choice */
#define GS_ADCS_GNC_ADS_INT_CHOICE_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_INT_CHOICE, value, GS_PARAM_F_NO_CALLBACK)
/** Get int_choice: Integrator choice */
#define GS_ADCS_GNC_ADS_INT_CHOICE_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_INT_CHOICE, value, 0)
/** Get int_choice (no check - return 0 on failure): Integrator choice */
#define GS_ADCS_GNC_ADS_INT_CHOICE_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_INT_CHOICE, 0)
/** Set kf_choice: Which type of kalman filter to use */
#define GS_ADCS_GNC_ADS_KF_CHOICE_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_KF_CHOICE, value, 0)
/** Set kf_choice (no callback): Which type of kalman filter to use */
#define GS_ADCS_GNC_ADS_KF_CHOICE_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_KF_CHOICE, value, GS_PARAM_F_NO_CALLBACK)
/** Get kf_choice: Which type of kalman filter to use */
#define GS_ADCS_GNC_ADS_KF_CHOICE_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_KF_CHOICE, value, 0)
/** Get kf_choice (no check - return 0 on failure): Which type of kalman filter to use */
#define GS_ADCS_GNC_ADS_KF_CHOICE_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_KF_CHOICE, 0)
/** Set M_bias: Magnetic field bias (body axis) [A/m^2] */
#define GS_ADCS_GNC_ADS_M_BIAS_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_M_BIAS(idx), value, 0)
/** Set M_bias (no callback): Magnetic field bias (body axis) [A/m^2] */
#define GS_ADCS_GNC_ADS_M_BIAS_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_M_BIAS(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get M_bias: Magnetic field bias (body axis) [A/m^2] */
#define GS_ADCS_GNC_ADS_M_BIAS_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_M_BIAS(idx), value, 0)
/** Get M_bias (no check - return 0 on failure): Magnetic field bias (body axis) [A/m^2] */
#define GS_ADCS_GNC_ADS_M_BIAS_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_M_BIAS(idx), 0)
/** Set min_angle: Minimum accepted angle between magnetic field and sun [deg] */
#define GS_ADCS_GNC_ADS_MIN_ANGLE_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_MIN_ANGLE, value, 0)
/** Set min_angle (no callback): Minimum accepted angle between magnetic field and sun [deg] */
#define GS_ADCS_GNC_ADS_MIN_ANGLE_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_MIN_ANGLE, value, GS_PARAM_F_NO_CALLBACK)
/** Get min_angle: Minimum accepted angle between magnetic field and sun [deg] */
#define GS_ADCS_GNC_ADS_MIN_ANGLE_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_MIN_ANGLE, value, 0)
/** Get min_angle (no check - return 0 on failure): Minimum accepted angle between magnetic field and sun [deg] */
#define GS_ADCS_GNC_ADS_MIN_ANGLE_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_MIN_ANGLE, 0)
/** Set htpa_err: Maximum error angle between a measured magnetic field vector, rotated by the htpa rotation to the LVLH, and the estimated IGRF field vector in the LVLH frame [deg] */
#define GS_ADCS_GNC_ADS_HTPA_ERR_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_HTPA_ERR, value, 0)
/** Set htpa_err (no callback): Maximum error angle between a measured magnetic field vector, rotated by the htpa rotation to the LVLH, and the estimated IGRF field vector in the LVLH frame [deg] */
#define GS_ADCS_GNC_ADS_HTPA_ERR_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_HTPA_ERR, value, GS_PARAM_F_NO_CALLBACK)
/** Get htpa_err: Maximum error angle between a measured magnetic field vector, rotated by the htpa rotation to the LVLH, and the estimated IGRF field vector in the LVLH frame [deg] */
#define GS_ADCS_GNC_ADS_HTPA_ERR_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_HTPA_ERR, value, 0)
/** Get htpa_err (no check - return 0 on failure): Maximum error angle between a measured magnetic field vector, rotated by the htpa rotation to the LVLH, and the estimated IGRF field vector in the LVLH frame [deg] */
#define GS_ADCS_GNC_ADS_HTPA_ERR_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_HTPA_ERR, 0)
/** Set st_override: enable/disable using the ST estimate of q_I_SC to override the UKF state estimate */
#define GS_ADCS_GNC_ADS_ST_OVERRIDE_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ST_OVERRIDE, value, 0)
/** Set st_override (no callback): enable/disable using the ST estimate of q_I_SC to override the UKF state estimate */
#define GS_ADCS_GNC_ADS_ST_OVERRIDE_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ST_OVERRIDE, value, GS_PARAM_F_NO_CALLBACK)
/** Get st_override: enable/disable using the ST estimate of q_I_SC to override the UKF state estimate */
#define GS_ADCS_GNC_ADS_ST_OVERRIDE_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ST_OVERRIDE, value, 0)
/** Get st_override (no check - return 0 on failure): enable/disable using the ST estimate of q_I_SC to override the UKF state estimate */
#define GS_ADCS_GNC_ADS_ST_OVERRIDE_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_ADS_TABLE_ID), GS_ADCS_GNC_ADS_ST_OVERRIDE, 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
