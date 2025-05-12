#ifndef GS_ADCS_PARAM_HOST_GNC_COMMON_H
#define GS_ADCS_PARAM_HOST_GNC_COMMON_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a gnc_common.
*/

#include <gs/adcs/param/gnc_common.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_gnc_common_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** SC inertia along the three principal axes [kg*m^2] */
    float    inertia[3];
    /** The initial desired ACS state */
    uint8_t  acs_init;
    /** The initial desired ADS state */
    uint8_t  ads_init;
    /** The initial desired ephem state */
    uint8_t  ephem_init;
    /** Filler for alignment */
    uint8_t  _filler_0x000f[1];
    /** The ADCS sample time [ms] */
    uint16_t sampletime;
    /** How often should the Bdot controller be run as a multiplum of ADCS iterations */
    uint16_t bdot_divider;
    /** How often should the ephemeris calculations be run as a multiplum of ADCS iterations */
    uint16_t ephem_divider;
    /** How often should the UKF be run as a multiplum of ADCS iterations */
    uint16_t kf_divider;
    /** How often should the custom (fine pointing) controller be run as a multiplum of ADCS iterations */
    uint16_t ctrl_divider;
    /** Deprecated */
    uint16_t pwm_deadtime;
    /** The first line of the TLE for the SC */
    char     tleline1[70];
    /** The second line of the TLE for the SC */
    char     tleline2[70];
    /** 0=Do not do teme2eci conversion, 1=Do teme2eci conversion */
    bool     teme2eci;
    /** Filler for alignment */
    uint8_t  _filler_0x00a9[3];
    /** Constant dutycycle for the three magnetorquers */
    float    const_ctrl[3];
    /** Threshold for going from detumbling mode to pointing mode */
    float    bdot_to_ctrl;
    /** Threshold for going from pointing mode to detumbling mode */
    float    ctrl_to_bdot;
    /** Coefficient of averaging for BDOT filter - shall be between 0 and 1 */
    float    bdot_tconst;
    /** Coefficient of averaging for rate norm filter */
    float    bdot_tconst2;
    /** Time seperation between fast and slow filters, must be larger than 1 */
    float    bdot_tsep;
    /** Actuation thresholds nT/s - for each axis */
    float    bdot_thres[3];
    /** Maximum actuation signal allowed on each torquer axis */
    float    bdot_t_limit[3];
    /** Nn which axis is the bias 0=x, 1=y, 2=z */
    uint8_t  bdot_axis;
    /** 0-100 bias strength */
    uint8_t  bdot_bstreng;
    /** Direction, -1 or 1 */
    int8_t   bdot_sign;
    /** 0=internal magnetometer, 1=External magnetometer */
    uint8_t  bdot_mag;
    /** Reference rate to the bdot [mG/s] */
    float    bdot_rateref[3];
    /** The time to wait for the magnetorquers to decay before sampling magnetometers [ms] */
    uint8_t  mtq_decay_t;
    /** Estimate for how long it takes to sample magnetometers (upper bound) [ms] */
    uint8_t  mag_sample_t;
    /** Filler for alignment */
    uint8_t  _fillerx_0x00f6[2];
} gs_adcs_gnc_common_memory_t;

/** Table default values. */
extern const gs_adcs_gnc_common_memory_t gs_adcs_gnc_common_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set inertia: SC inertia along the three principal axes [kg*m^2] */
#define GS_ADCS_GNC_COMMON_INERTIA_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_INERTIA(idx), value, 0)
/** Set inertia (no callback): SC inertia along the three principal axes [kg*m^2] */
#define GS_ADCS_GNC_COMMON_INERTIA_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_INERTIA(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get inertia: SC inertia along the three principal axes [kg*m^2] */
#define GS_ADCS_GNC_COMMON_INERTIA_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_INERTIA(idx), value, 0)
/** Get inertia (no check - return 0 on failure): SC inertia along the three principal axes [kg*m^2] */
#define GS_ADCS_GNC_COMMON_INERTIA_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_INERTIA(idx), 0)
/** Set acs_init: The initial desired ACS state */
#define GS_ADCS_GNC_COMMON_ACS_INIT_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_ACS_INIT, value, 0)
/** Set acs_init (no callback): The initial desired ACS state */
#define GS_ADCS_GNC_COMMON_ACS_INIT_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_ACS_INIT, value, GS_PARAM_F_NO_CALLBACK)
/** Get acs_init: The initial desired ACS state */
#define GS_ADCS_GNC_COMMON_ACS_INIT_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_ACS_INIT, value, 0)
/** Get acs_init (no check - return 0 on failure): The initial desired ACS state */
#define GS_ADCS_GNC_COMMON_ACS_INIT_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_ACS_INIT, 0)
/** Set ads_init: The initial desired ADS state */
#define GS_ADCS_GNC_COMMON_ADS_INIT_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_ADS_INIT, value, 0)
/** Set ads_init (no callback): The initial desired ADS state */
#define GS_ADCS_GNC_COMMON_ADS_INIT_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_ADS_INIT, value, GS_PARAM_F_NO_CALLBACK)
/** Get ads_init: The initial desired ADS state */
#define GS_ADCS_GNC_COMMON_ADS_INIT_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_ADS_INIT, value, 0)
/** Get ads_init (no check - return 0 on failure): The initial desired ADS state */
#define GS_ADCS_GNC_COMMON_ADS_INIT_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_ADS_INIT, 0)
/** Set ephem_init: The initial desired ephem state */
#define GS_ADCS_GNC_COMMON_EPHEM_INIT_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_EPHEM_INIT, value, 0)
/** Set ephem_init (no callback): The initial desired ephem state */
#define GS_ADCS_GNC_COMMON_EPHEM_INIT_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_EPHEM_INIT, value, GS_PARAM_F_NO_CALLBACK)
/** Get ephem_init: The initial desired ephem state */
#define GS_ADCS_GNC_COMMON_EPHEM_INIT_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_EPHEM_INIT, value, 0)
/** Get ephem_init (no check - return 0 on failure): The initial desired ephem state */
#define GS_ADCS_GNC_COMMON_EPHEM_INIT_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_EPHEM_INIT, 0)
/** Set sampletime: The ADCS sample time [ms] */
#define GS_ADCS_GNC_COMMON_SAMPLETIME_SET(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_SAMPLETIME, value, 0)
/** Set sampletime (no callback): The ADCS sample time [ms] */
#define GS_ADCS_GNC_COMMON_SAMPLETIME_SET_NO_CALLBACK(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_SAMPLETIME, value, GS_PARAM_F_NO_CALLBACK)
/** Get sampletime: The ADCS sample time [ms] */
#define GS_ADCS_GNC_COMMON_SAMPLETIME_GET(value) gs_param_get_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_SAMPLETIME, value, 0)
/** Get sampletime (no check - return 0 on failure): The ADCS sample time [ms] */
#define GS_ADCS_GNC_COMMON_SAMPLETIME_GET_NC() gs_param_get_uint16_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_SAMPLETIME, 0)
/** Set bdot_divider: How often should the Bdot controller be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_BDOT_DIVIDER_SET(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_DIVIDER, value, 0)
/** Set bdot_divider (no callback): How often should the Bdot controller be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_BDOT_DIVIDER_SET_NO_CALLBACK(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_DIVIDER, value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_divider: How often should the Bdot controller be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_BDOT_DIVIDER_GET(value) gs_param_get_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_DIVIDER, value, 0)
/** Get bdot_divider (no check - return 0 on failure): How often should the Bdot controller be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_BDOT_DIVIDER_GET_NC() gs_param_get_uint16_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_DIVIDER, 0)
/** Set ephem_divider: How often should the ephemeris calculations be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_EPHEM_DIVIDER_SET(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_EPHEM_DIVIDER, value, 0)
/** Set ephem_divider (no callback): How often should the ephemeris calculations be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_EPHEM_DIVIDER_SET_NO_CALLBACK(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_EPHEM_DIVIDER, value, GS_PARAM_F_NO_CALLBACK)
/** Get ephem_divider: How often should the ephemeris calculations be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_EPHEM_DIVIDER_GET(value) gs_param_get_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_EPHEM_DIVIDER, value, 0)
/** Get ephem_divider (no check - return 0 on failure): How often should the ephemeris calculations be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_EPHEM_DIVIDER_GET_NC() gs_param_get_uint16_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_EPHEM_DIVIDER, 0)
/** Set kf_divider: How often should the UKF be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_KF_DIVIDER_SET(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_KF_DIVIDER, value, 0)
/** Set kf_divider (no callback): How often should the UKF be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_KF_DIVIDER_SET_NO_CALLBACK(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_KF_DIVIDER, value, GS_PARAM_F_NO_CALLBACK)
/** Get kf_divider: How often should the UKF be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_KF_DIVIDER_GET(value) gs_param_get_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_KF_DIVIDER, value, 0)
/** Get kf_divider (no check - return 0 on failure): How often should the UKF be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_KF_DIVIDER_GET_NC() gs_param_get_uint16_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_KF_DIVIDER, 0)
/** Set ctrl_divider: How often should the custom (fine pointing) controller be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_CTRL_DIVIDER_SET(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CTRL_DIVIDER, value, 0)
/** Set ctrl_divider (no callback): How often should the custom (fine pointing) controller be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_CTRL_DIVIDER_SET_NO_CALLBACK(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CTRL_DIVIDER, value, GS_PARAM_F_NO_CALLBACK)
/** Get ctrl_divider: How often should the custom (fine pointing) controller be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_CTRL_DIVIDER_GET(value) gs_param_get_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CTRL_DIVIDER, value, 0)
/** Get ctrl_divider (no check - return 0 on failure): How often should the custom (fine pointing) controller be run as a multiplum of ADCS iterations */
#define GS_ADCS_GNC_COMMON_CTRL_DIVIDER_GET_NC() gs_param_get_uint16_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CTRL_DIVIDER, 0)
/** Set pwm_deadtime: Deprecated */
#define GS_ADCS_GNC_COMMON_PWM_DEADTIME_SET(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_PWM_DEADTIME, value, 0)
/** Set pwm_deadtime (no callback): Deprecated */
#define GS_ADCS_GNC_COMMON_PWM_DEADTIME_SET_NO_CALLBACK(value) gs_param_set_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_PWM_DEADTIME, value, GS_PARAM_F_NO_CALLBACK)
/** Get pwm_deadtime: Deprecated */
#define GS_ADCS_GNC_COMMON_PWM_DEADTIME_GET(value) gs_param_get_uint16(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_PWM_DEADTIME, value, 0)
/** Get pwm_deadtime (no check - return 0 on failure): Deprecated */
#define GS_ADCS_GNC_COMMON_PWM_DEADTIME_GET_NC() gs_param_get_uint16_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_PWM_DEADTIME, 0)
/** Set tleline1: The first line of the TLE for the SC */
#define GS_ADCS_GNC_COMMON_TLELINE1_SET(value) gs_param_set_string(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_TLELINE1, value, 0)
/** Set tleline1 (no callback): The first line of the TLE for the SC */
#define GS_ADCS_GNC_COMMON_TLELINE1_SET_NO_CALLBACK(value) gs_param_set_string(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_TLELINE1, value, GS_PARAM_F_NO_CALLBACK)
/** Get tleline1: The first line of the TLE for the SC */
#define GS_ADCS_GNC_COMMON_TLELINE1_GET(buf, buf_size) gs_param_get_string(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_TLELINE1, buf, buf_size, 0)
/** Set tleline2: The second line of the TLE for the SC */
#define GS_ADCS_GNC_COMMON_TLELINE2_SET(value) gs_param_set_string(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_TLELINE2, value, 0)
/** Set tleline2 (no callback): The second line of the TLE for the SC */
#define GS_ADCS_GNC_COMMON_TLELINE2_SET_NO_CALLBACK(value) gs_param_set_string(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_TLELINE2, value, GS_PARAM_F_NO_CALLBACK)
/** Get tleline2: The second line of the TLE for the SC */
#define GS_ADCS_GNC_COMMON_TLELINE2_GET(buf, buf_size) gs_param_get_string(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_TLELINE2, buf, buf_size, 0)
/** Set teme2eci: 0=Do not do teme2eci conversion, 1=Do teme2eci conversion */
#define GS_ADCS_GNC_COMMON_TEME2ECI_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_TEME2ECI, value, 0)
/** Set teme2eci (no callback): 0=Do not do teme2eci conversion, 1=Do teme2eci conversion */
#define GS_ADCS_GNC_COMMON_TEME2ECI_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_TEME2ECI, value, GS_PARAM_F_NO_CALLBACK)
/** Get teme2eci: 0=Do not do teme2eci conversion, 1=Do teme2eci conversion */
#define GS_ADCS_GNC_COMMON_TEME2ECI_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_TEME2ECI, value, 0)
/** Get teme2eci (no check - return 0 on failure): 0=Do not do teme2eci conversion, 1=Do teme2eci conversion */
#define GS_ADCS_GNC_COMMON_TEME2ECI_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_TEME2ECI, 0)
/** Set const_ctrl: Constant dutycycle for the three magnetorquers */
#define GS_ADCS_GNC_COMMON_CONST_CTRL_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CONST_CTRL(idx), value, 0)
/** Set const_ctrl (no callback): Constant dutycycle for the three magnetorquers */
#define GS_ADCS_GNC_COMMON_CONST_CTRL_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CONST_CTRL(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get const_ctrl: Constant dutycycle for the three magnetorquers */
#define GS_ADCS_GNC_COMMON_CONST_CTRL_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CONST_CTRL(idx), value, 0)
/** Get const_ctrl (no check - return 0 on failure): Constant dutycycle for the three magnetorquers */
#define GS_ADCS_GNC_COMMON_CONST_CTRL_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CONST_CTRL(idx), 0)
/** Set bdot_to_ctrl: Threshold for going from detumbling mode to pointing mode */
#define GS_ADCS_GNC_COMMON_BDOT_TO_CTRL_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TO_CTRL, value, 0)
/** Set bdot_to_ctrl (no callback): Threshold for going from detumbling mode to pointing mode */
#define GS_ADCS_GNC_COMMON_BDOT_TO_CTRL_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TO_CTRL, value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_to_ctrl: Threshold for going from detumbling mode to pointing mode */
#define GS_ADCS_GNC_COMMON_BDOT_TO_CTRL_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TO_CTRL, value, 0)
/** Get bdot_to_ctrl (no check - return 0 on failure): Threshold for going from detumbling mode to pointing mode */
#define GS_ADCS_GNC_COMMON_BDOT_TO_CTRL_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TO_CTRL, 0)
/** Set ctrl_to_bdot: Threshold for going from pointing mode to detumbling mode */
#define GS_ADCS_GNC_COMMON_CTRL_TO_BDOT_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CTRL_TO_BDOT, value, 0)
/** Set ctrl_to_bdot (no callback): Threshold for going from pointing mode to detumbling mode */
#define GS_ADCS_GNC_COMMON_CTRL_TO_BDOT_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CTRL_TO_BDOT, value, GS_PARAM_F_NO_CALLBACK)
/** Get ctrl_to_bdot: Threshold for going from pointing mode to detumbling mode */
#define GS_ADCS_GNC_COMMON_CTRL_TO_BDOT_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CTRL_TO_BDOT, value, 0)
/** Get ctrl_to_bdot (no check - return 0 on failure): Threshold for going from pointing mode to detumbling mode */
#define GS_ADCS_GNC_COMMON_CTRL_TO_BDOT_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_CTRL_TO_BDOT, 0)
/** Set bdot_tconst: Coefficient of averaging for BDOT filter - shall be between 0 and 1 */
#define GS_ADCS_GNC_COMMON_BDOT_TCONST_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TCONST, value, 0)
/** Set bdot_tconst (no callback): Coefficient of averaging for BDOT filter - shall be between 0 and 1 */
#define GS_ADCS_GNC_COMMON_BDOT_TCONST_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TCONST, value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_tconst: Coefficient of averaging for BDOT filter - shall be between 0 and 1 */
#define GS_ADCS_GNC_COMMON_BDOT_TCONST_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TCONST, value, 0)
/** Get bdot_tconst (no check - return 0 on failure): Coefficient of averaging for BDOT filter - shall be between 0 and 1 */
#define GS_ADCS_GNC_COMMON_BDOT_TCONST_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TCONST, 0)
/** Set bdot_tconst2: Coefficient of averaging for rate norm filter */
#define GS_ADCS_GNC_COMMON_BDOT_TCONST2_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TCONST2, value, 0)
/** Set bdot_tconst2 (no callback): Coefficient of averaging for rate norm filter */
#define GS_ADCS_GNC_COMMON_BDOT_TCONST2_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TCONST2, value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_tconst2: Coefficient of averaging for rate norm filter */
#define GS_ADCS_GNC_COMMON_BDOT_TCONST2_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TCONST2, value, 0)
/** Get bdot_tconst2 (no check - return 0 on failure): Coefficient of averaging for rate norm filter */
#define GS_ADCS_GNC_COMMON_BDOT_TCONST2_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TCONST2, 0)
/** Set bdot_tsep: Time seperation between fast and slow filters, must be larger than 1 */
#define GS_ADCS_GNC_COMMON_BDOT_TSEP_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TSEP, value, 0)
/** Set bdot_tsep (no callback): Time seperation between fast and slow filters, must be larger than 1 */
#define GS_ADCS_GNC_COMMON_BDOT_TSEP_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TSEP, value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_tsep: Time seperation between fast and slow filters, must be larger than 1 */
#define GS_ADCS_GNC_COMMON_BDOT_TSEP_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TSEP, value, 0)
/** Get bdot_tsep (no check - return 0 on failure): Time seperation between fast and slow filters, must be larger than 1 */
#define GS_ADCS_GNC_COMMON_BDOT_TSEP_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_TSEP, 0)
/** Set bdot_thres: Actuation thresholds nT/s - for each axis */
#define GS_ADCS_GNC_COMMON_BDOT_THRES_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_THRES(idx), value, 0)
/** Set bdot_thres (no callback): Actuation thresholds nT/s - for each axis */
#define GS_ADCS_GNC_COMMON_BDOT_THRES_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_THRES(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_thres: Actuation thresholds nT/s - for each axis */
#define GS_ADCS_GNC_COMMON_BDOT_THRES_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_THRES(idx), value, 0)
/** Get bdot_thres (no check - return 0 on failure): Actuation thresholds nT/s - for each axis */
#define GS_ADCS_GNC_COMMON_BDOT_THRES_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_THRES(idx), 0)
/** Set bdot_t_limit: Maximum actuation signal allowed on each torquer axis */
#define GS_ADCS_GNC_COMMON_BDOT_T_LIMIT_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_T_LIMIT(idx), value, 0)
/** Set bdot_t_limit (no callback): Maximum actuation signal allowed on each torquer axis */
#define GS_ADCS_GNC_COMMON_BDOT_T_LIMIT_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_T_LIMIT(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_t_limit: Maximum actuation signal allowed on each torquer axis */
#define GS_ADCS_GNC_COMMON_BDOT_T_LIMIT_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_T_LIMIT(idx), value, 0)
/** Get bdot_t_limit (no check - return 0 on failure): Maximum actuation signal allowed on each torquer axis */
#define GS_ADCS_GNC_COMMON_BDOT_T_LIMIT_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_T_LIMIT(idx), 0)
/** Set bdot_axis: Nn which axis is the bias 0=x, 1=y, 2=z */
#define GS_ADCS_GNC_COMMON_BDOT_AXIS_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_AXIS, value, 0)
/** Set bdot_axis (no callback): Nn which axis is the bias 0=x, 1=y, 2=z */
#define GS_ADCS_GNC_COMMON_BDOT_AXIS_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_AXIS, value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_axis: Nn which axis is the bias 0=x, 1=y, 2=z */
#define GS_ADCS_GNC_COMMON_BDOT_AXIS_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_AXIS, value, 0)
/** Get bdot_axis (no check - return 0 on failure): Nn which axis is the bias 0=x, 1=y, 2=z */
#define GS_ADCS_GNC_COMMON_BDOT_AXIS_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_AXIS, 0)
/** Set bdot_bstreng: 0-100 bias strength */
#define GS_ADCS_GNC_COMMON_BDOT_BSTRENG_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_BSTRENG, value, 0)
/** Set bdot_bstreng (no callback): 0-100 bias strength */
#define GS_ADCS_GNC_COMMON_BDOT_BSTRENG_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_BSTRENG, value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_bstreng: 0-100 bias strength */
#define GS_ADCS_GNC_COMMON_BDOT_BSTRENG_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_BSTRENG, value, 0)
/** Get bdot_bstreng (no check - return 0 on failure): 0-100 bias strength */
#define GS_ADCS_GNC_COMMON_BDOT_BSTRENG_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_BSTRENG, 0)
/** Set bdot_sign: Direction, -1 or 1 */
#define GS_ADCS_GNC_COMMON_BDOT_SIGN_SET(value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_SIGN, value, 0)
/** Set bdot_sign (no callback): Direction, -1 or 1 */
#define GS_ADCS_GNC_COMMON_BDOT_SIGN_SET_NO_CALLBACK(value) gs_param_set_int8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_SIGN, value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_sign: Direction, -1 or 1 */
#define GS_ADCS_GNC_COMMON_BDOT_SIGN_GET(value) gs_param_get_int8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_SIGN, value, 0)
/** Get bdot_sign (no check - return 0 on failure): Direction, -1 or 1 */
#define GS_ADCS_GNC_COMMON_BDOT_SIGN_GET_NC() gs_param_get_int8_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_SIGN, 0)
/** Set bdot_mag: 0=internal magnetometer, 1=External magnetometer */
#define GS_ADCS_GNC_COMMON_BDOT_MAG_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_MAG, value, 0)
/** Set bdot_mag (no callback): 0=internal magnetometer, 1=External magnetometer */
#define GS_ADCS_GNC_COMMON_BDOT_MAG_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_MAG, value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_mag: 0=internal magnetometer, 1=External magnetometer */
#define GS_ADCS_GNC_COMMON_BDOT_MAG_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_MAG, value, 0)
/** Get bdot_mag (no check - return 0 on failure): 0=internal magnetometer, 1=External magnetometer */
#define GS_ADCS_GNC_COMMON_BDOT_MAG_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_MAG, 0)
/** Set bdot_rateref: Reference rate to the bdot [mG/s] */
#define GS_ADCS_GNC_COMMON_BDOT_RATEREF_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_RATEREF(idx), value, 0)
/** Set bdot_rateref (no callback): Reference rate to the bdot [mG/s] */
#define GS_ADCS_GNC_COMMON_BDOT_RATEREF_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_RATEREF(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get bdot_rateref: Reference rate to the bdot [mG/s] */
#define GS_ADCS_GNC_COMMON_BDOT_RATEREF_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_RATEREF(idx), value, 0)
/** Get bdot_rateref (no check - return 0 on failure): Reference rate to the bdot [mG/s] */
#define GS_ADCS_GNC_COMMON_BDOT_RATEREF_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_BDOT_RATEREF(idx), 0)
/** Set mtq_decay_t: The time to wait for the magnetorquers to decay before sampling magnetometers [ms] */
#define GS_ADCS_GNC_COMMON_MTQ_DECAY_T_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_MTQ_DECAY_T, value, 0)
/** Set mtq_decay_t (no callback): The time to wait for the magnetorquers to decay before sampling magnetometers [ms] */
#define GS_ADCS_GNC_COMMON_MTQ_DECAY_T_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_MTQ_DECAY_T, value, GS_PARAM_F_NO_CALLBACK)
/** Get mtq_decay_t: The time to wait for the magnetorquers to decay before sampling magnetometers [ms] */
#define GS_ADCS_GNC_COMMON_MTQ_DECAY_T_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_MTQ_DECAY_T, value, 0)
/** Get mtq_decay_t (no check - return 0 on failure): The time to wait for the magnetorquers to decay before sampling magnetometers [ms] */
#define GS_ADCS_GNC_COMMON_MTQ_DECAY_T_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_MTQ_DECAY_T, 0)
/** Set mag_sample_t: Estimate for how long it takes to sample magnetometers (upper bound) [ms] */
#define GS_ADCS_GNC_COMMON_MAG_SAMPLE_T_SET(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_MAG_SAMPLE_T, value, 0)
/** Set mag_sample_t (no callback): Estimate for how long it takes to sample magnetometers (upper bound) [ms] */
#define GS_ADCS_GNC_COMMON_MAG_SAMPLE_T_SET_NO_CALLBACK(value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_MAG_SAMPLE_T, value, GS_PARAM_F_NO_CALLBACK)
/** Get mag_sample_t: Estimate for how long it takes to sample magnetometers (upper bound) [ms] */
#define GS_ADCS_GNC_COMMON_MAG_SAMPLE_T_GET(value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_MAG_SAMPLE_T, value, 0)
/** Get mag_sample_t (no check - return 0 on failure): Estimate for how long it takes to sample magnetometers (upper bound) [ms] */
#define GS_ADCS_GNC_COMMON_MAG_SAMPLE_T_GET_NC() gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_COMMON_TABLE_ID), GS_ADCS_GNC_COMMON_MAG_SAMPLE_T, 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
