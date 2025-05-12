#ifndef BPX_H_
#define BPX_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <stdint.h>

#define NODE_BPX                7

#define BPX_PORT_RESET			7 //For slave interface
#define BPX_PORT_HK				9
#define BPX_PORT_RESET_COUNTERS 15
#define BPX_PORT_CONFIG_CMD		17
#define BPX_PORT_CONFIG_GET		18
#define BPX_PORT_CONFIG_SET		19
#define BPX_PORT_MAN_HEAT_ON	20
#define BPX_PORT_MAN_HEAT_OFF	21

#define BPX_MAN_HEAT_OK 		1



typedef struct __attribute__((packed)) {
	uint8_t battheater_mode;						//! Mode for battheater [0 = Manual, 1 = Auto]
	int8_t battheater_low;							//! Turn heater on at [degC]
	int8_t battheater_high;							//! Trun heater off at [degC]
} bpx_config_t;



typedef struct __attribute__((packed)) {
	uint16_t cur_charge;		//! Charge current in mA
	uint16_t cur_discharge;		//! Discharge current in mA
	uint16_t cur_heater;		//! Heater current in mA
	uint16_t vbatt;			//! Battery voltage in mV
	int16_t bat_temperature1;	//! Battery temperature 1 in degC
	int16_t bat_temperature2;	//! Battery temperature 2 in degC
	int16_t bat_temperature3;	//! Battery temperature 3 in degC
	int16_t bat_temperature4;	//! Battery temperature 4 in degC
	uint32_t counter_boot;		//! Number of reboots
	uint8_t	bootcause;		//! Cause of last reset
} bpx_hk_t;



/**
 * Return houskeeping values
 * @param hk pointer to struct
 * @return -1 if err 0 if ok
 */
int bpx_hk_get(bpx_hk_t * hk);

/**
 * Return houskeeping values with CSP parameters
 * @param hk pointer to hk struct
 * @param dest destination CSP address
 * @param port CSP port
 * @param timeout CSP transaction timeout
 * @return standard transaction error: 0 = success
 */
int bpx_hk_get_p(bpx_hk_t * hk, uint8_t dest, uint8_t port, uint32_t timeout);
/**
 * Reset EEPROM based counters
 * @return csp status
 */
int bpx_counters_reset(void);

void bpx_node_set(uint8_t node);


/**
 * Pack, unpack and print config
 * @param conf pointer to config
 */
void bpx_config_print(bpx_config_t * conf);

/**
 * Do config command
 * @param cmd
 * @return csp status
 */
int bpx_config_cmd(uint8_t cmd);

/**
 * Get running bpx config
 * @param config pointner to config
 * @return csp status
 */
int bpx_config_get(bpx_config_t * config);

/**
 * Set running config on bpx
 * @param config pointer to config
 * @return csp status
 */
int bpx_config_set(bpx_config_t * config);

/**
 * Either start manual heat or continue
 * @param heat timeout
 * @param pointer to ok flag send by the BPX (OK = 1)
 * @return csp status
 */
int bpx_heat_on(uint16_t heat_time, uint8_t * ok_flag);

/**
 * Stops manual heat
 * @return csp status
 * @param pointer to ok flag send by the BPX (OK = 1)
 */
int bpx_heat_off(uint8_t * ok_flag);






#endif /* BPX_H_ */
