/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#ifndef CLIENT_ADCS_H_
#include <gs/adcs/adcs_types.h>

void adcs_node_set(int node, int port);
void adcs_timeout_set(int timeout);

/* ADCS HK */
int adcs_hk_basic(adcs_hk_basic_t *hkbasic);

/* ADCS RUN */
int adcs_start(void);
int adcs_sensors(void);
int adcs_stop(void);
int adcs_restart(void);

/* ADCS BDOT  */
int adcs_bdot_force_detumbled(void);

/* ADCS EPHEMERIS */
int adcs_ephem_new_tle(void);

/* ADCS STATE */
int adcs_set_ads_state(ads_mode_t state);
int adcs_set_acs_state(acs_mode_t mode);
int adcs_set_ephem_state(ephem_mode_t mode);
int adcs_get_adcs_state(adcs_mode_t *mode);

/* ADCS POINTING MODES */
int adcs_set_reset(void);
int adcs_set_nadir(void);
int adcs_set_ram(void);
int adcs_set_mindrag(void);
int adcs_set_maxdrag(void);
int adcs_set_custom0(void);
int adcs_set_custom1(void);
int adcs_set_custom2(void);

/* ADCS TRACKING MODES */
int adcs_track_reset(void);
int adcs_track_sun(void);
int adcs_track_moon(void);
int adcs_track_target0(void);
int adcs_track_target1(void);
int adcs_track_target2(void);


#define CLIENT_ADCS_H_

#endif /* CLIENT_ADCS_H_ */
