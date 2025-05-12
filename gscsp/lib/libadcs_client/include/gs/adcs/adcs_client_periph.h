/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#ifndef CLIENT_ADCS_PERIPH_H_
#include <gs/adcs/adcs_types.h>

void adcs_periph_node_set(int node, int port);
void adcs_periph_timeout_set(int timeout);

/* ADCS SENSORS */
int adcs_sensor_init(void);

/* ADCS ACTUATORS */
int adcs_act_get_torquers(adcs_act_torquers_t *value);
int adcs_act_set_torquers(adcs_act_torquers_t *value);

int adcs_act_mw_on();
int adcs_act_mw_off();
int adcs_act_mw_set(adcs_act_mw_set_t value);
int adcs_act_mw_config(adcs_act_mw_config_t value);
int adcs_act_mw_tb(adcs_act_mw_tb_t value);
int adcs_act_mw_enable(adcs_act_mw_enable_t value);
int adcs_act_mw_get_status(adcs_act_mw_get_status_t *value);

int adcs_sensors_htpa_init(void);
int adcs_sensors_htpa_shutdown(void);
int adcs_sensors_htpa_saveimage(uint8_t id, const char * filepath);
int adcs_sensors_htpa_rsample(gs_adcs_htpa_sample_t *sample);

#define CLIENT_ADCS_PERIPH_H_

#endif /* CLIENT_ADCS_H_ */
