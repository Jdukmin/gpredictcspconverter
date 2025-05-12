/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#ifndef ADCS_PARAM_TYPES_H_
#define ADCS_PARAM_TYPES_H_

#include <gs/util/types.h>
#include <gs/adcs/adcs_types.h>

#include <gs/adcs/param/host/sensor_css.h>
#include <gs/adcs/param/host/sensor_common.h>
#include <gs/adcs/param/host/sensor_fss.h>
#include <gs/adcs/param/host/sensor_gyro.h>
#include <gs/adcs/param/host/sensor_horizon.h>
#include <gs/adcs/param/host/sensor_magnetometer.h>
#include <gs/adcs/param/host/sensor_startracker.h>
#include <gs/adcs/param/host/sensor_a3200.h>

#include <gs/adcs/param/host/act_magnetorquer.h>
#include <gs/adcs/param/host/act_rw.h>

#include <gs/adcs/param/host/gnc_common.h>
#include <gs/adcs/param/host/gnc_ads.h>
#include <gs/adcs/param/host/gnc_ctrl_pointing.h>
#include <gs/adcs/param/host/gnc_ctrl_spin.h>

/*
 * Configuration parameters for peripherals
 * sensors and actuators
 */
#define FSS_THETA_POINTS 6

typedef struct {
    quaternion_t st1align;  /**< Alignment quaterion q_startracker->body */
    quaternion_t st2align;  /**< Alignment quaterion q_startracker->body */
    uint8_t enable[2];      /**< Startracker enables */
    float confidence;
} gs_adcs_config_star_t;

typedef struct {
    gs_adcs_sensor_a3200_memory_t a3200;
    int extmag_count;
    int *extmag_handles;
    gs_adcs_sensor_magnetometer_memory_t extmag[MAX_NUM_EXTMAG];
    gs_adcs_sensor_gyro_memory_t extgyro;
    gs_adcs_sensor_css_memory_t css;
    gs_adcs_sensor_common_memory_t common;
    gs_adcs_sensor_startracker_memory_t str;
    gs_adcs_sensor_horizon_memory_t htpa;
    gs_adcs_config_star_t star;
} gs_adcs_config_sensor_t;

typedef struct {
    gs_adcs_act_magnetorquer_memory_t torquer;
    gs_adcs_act_rw_memory_t *mw;
    int rw_count;
    int *rw_handles;
} gs_adcs_config_act_t;

typedef struct {
    gs_adcs_config_sensor_t sensor;
    gs_adcs_config_act_t act;
} gs_adcs_config_periph_t;


typedef struct {
    float inv_inertia[3];       /**< The inverse of the satellites inertias - defined for ease of computation */
    float torquer_scale;        /**< Scale factor for for torquer duty cycle, necessary because of pwm dead time */
    uint8_t torquer_sat[3];     /**< Saturation value of torquers */
} gs_adcs_config_work_t;

typedef struct gs_adcs_config_gnc{
    gs_adcs_gnc_common_memory_t common;
    gs_adcs_gnc_ads_memory_t ads;
    gs_adcs_gnc_ctrl_pointing_memory_t ctrl;
    gs_adcs_gnc_ctrl_spin_memory_t mb;
    gs_adcs_config_work_t work;
} gs_adcs_config_gnc_t;

/**
 * Configuration struct, which holds all basic configuration parameters for the GS_ADCS system
 */
typedef struct {
    gs_adcs_sensor_fss_memory_t *fss[MAX_NUM_FSS];
    gs_adcs_config_periph_t *periph;
    gs_adcs_config_gnc_t *gnc;
} gs_adcs_config_t;

extern gs_adcs_config_t gs_adcs_config;

#endif /* ADCS_PARAM_TYPES_H_ */
