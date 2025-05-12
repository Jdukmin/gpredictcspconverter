/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <gs/bpx/io.h>
#include <csp/csp.h>
#include <csp/csp_endian.h>

#include <gs/util/drivers/i2c/master.h>
#include <gs/util/error.h>
#include <gs/gosh/util/console.h>


static int slave_node = NODE_BPX;

// Defined in cmd_bpx
extern bpx_config_t bpx_config;
extern int cmd_bpx_config_edit(struct command_context *ctx);

static int timeout_ms = 1000;
static int i2c_bus_handle = 0;

int bpx_slave_node(struct command_context *ctx) {

	const char * args = command_args(ctx);
	unsigned int node;
	if (sscanf(args, "%u", &node) != 1)
		return CMD_ERROR_SYNTAX;
	printf("Setting BPX slave node address to %u\r\n", node);
	slave_node = node;

	return CMD_ERROR_NONE;
}

int bpx_slave_ping(struct command_context *ctx) {
	gs_error_t error;

	/* TX */
	const uint8_t tx_buff[2] = {
		CSP_PING, 	// Ping port
		0x55 		// Dummy byte
	};
	size_t tx_len = 2;

	/* RX */
	uint8_t rx_buff[3];
	size_t rx_len = 3;

	printf("Ping address: %i, Timeout: %i\n\r", slave_node, timeout_ms);

	/* Send and receive */
	error = gs_i2c_master_transaction(i2c_bus_handle, slave_node, tx_buff, tx_len, rx_buff, rx_len, timeout_ms);

	/* Return error code if not success full */
	if(error != GS_OK){
		printf("error: %i in gs_i2c_master_transaction()\n\r",error);
		return error;
	}

	/* Check error code from reply (byte 1, 0x00 = OK and 0xFF = CMD ERROR)
	 * Check reply data (byte 2, shall equal dummy byte) */
	if (rx_buff[1] == 0x00 && rx_buff[2] == 0x55) {
		printf("Reply SUCCESSFULL\r\n");
		return GS_OK;
	} else if (rx_buff[1] == 0xFF){
		printf("Received CMD ERROR from BPX\n\r");
		return GS_ERROR_IO;
	} else if (rx_buff[2] != 0x55 && rx_buff[1] == 0x00){
		printf("Received byte NOT equal to send dummy byte\n\r");
		return GS_ERROR_IO;
	} else {
		return GS_ERROR_IO;
	}
}

int bpx_slave_reboot(struct command_context *ctx) {
	/* TX */
	const uint8_t tx_buff[5] = {
		CSP_REBOOT, // Reboot port
		0x80, 		// Magic sequence byte 1
		0x07, 		// Magic sequence byte 2
		0x80, 		// Magic sequence byte 3
		0x07,		// Magic sequence byte 4
	};
	size_t tx_len = 5;

	/* RX */
	uint8_t * rx_buff = NULL;	// No RX
	size_t rx_len = 0;			// No RX

	/* Send and receive */
	return gs_i2c_master_transaction(i2c_bus_handle, slave_node, tx_buff, tx_len, rx_buff, rx_len, timeout_ms);

}

int bpx_slave_hk(struct command_context *ctx) {
	bpx_hk_t * hk;
	gs_error_t error;

	printf("Requesting BPX hk data\r\n");

	/* TX */
	const uint8_t tx_buff[1] = {
		BPX_PORT_HK, 	// HK port
	};
	size_t tx_len = 1;

	/* RX */
	uint8_t rx_buff[2 + (uint8_t) sizeof(bpx_hk_t)];
	size_t rx_len = 2 + (uint8_t) sizeof(bpx_hk_t);

	/* Send and receive */
	error = gs_i2c_master_transaction(i2c_bus_handle, slave_node, tx_buff, tx_len, rx_buff, rx_len, timeout_ms);

	/* Return error code if not success full */
	if(error != GS_OK){
		printf("error: %i in gs_i2c_master_transaction()\n\r",error);
		return error;
	}

	/* Check error code from reply (byte 1, 0x00 = OK and 0xFF = CMD ERROR) */
	if (rx_buff[1] == 0xFF){
		printf("Received CMD ERROR from BPX\n\r");
		return GS_ERROR_IO;
	} else if (rx_buff[1] != 0x00){
		return GS_ERROR_IO;
	}

	hk = (bpx_hk_t *)&rx_buff[2];

	hk->cur_charge = csp_ntoh16(hk->cur_charge);
	hk->cur_discharge = csp_ntoh16(hk->cur_discharge);
	hk->cur_heater = csp_ntoh16(hk->cur_heater);
	hk->vbatt = csp_ntoh16(hk->vbatt);
	hk->bat_temperature1 = csp_ntoh16(hk->bat_temperature1);
	hk->bat_temperature2 = csp_ntoh16(hk->bat_temperature2);
	hk->bat_temperature3 = csp_ntoh16(hk->bat_temperature3);
	hk->bat_temperature4 = csp_ntoh16(hk->bat_temperature4);
	hk->counter_boot = csp_ntoh32(hk->counter_boot);

	printf("Charge current        %"PRIu16" mA\r\n", hk->cur_charge);
	printf("Discharge current     %"PRIu16" mA\r\n", hk->cur_discharge);
	printf("Heater current        %"PRIu16" mA\r\n", hk->cur_heater);
	printf("Battery voltage       %"PRIu16" mV\r\n", hk->vbatt);
	printf("Battery temperature 1 %"PRId16" degC\r\n", hk->bat_temperature1);
	printf("Battery temperature 2 %"PRId16" degC\r\n", hk->bat_temperature2);
	printf("Battery temperature 3 %"PRId16" degC\r\n", hk->bat_temperature3);
	printf("Battery temperature 4 %"PRId16" degC\r\n", hk->bat_temperature4);
	printf("Bootcause %"PRIu8" \r\n", hk->bootcause);
	printf("Bootcount %"PRIu32" \r\n", hk->counter_boot);

	return GS_OK;
}

int bpx_slave_heat_on(struct command_context *ctx) {
	uint16_t heat_time;
	gs_error_t error;

	if (ctx->argc != 2)
		return GS_ERROR_ARG;
	heat_time = atoi(ctx->argv[1]);
	if(heat_time > 600){
		printf("heat_time has to be in interval [0 : 600]\n\r");
		return GS_ERROR_ARG;
	}

	/* TX */
	const uint8_t tx_buff[3] = {
		BPX_PORT_MAN_HEAT_ON, 		// Manual heat on port
		((heat_time >> 8) & 0xff), 	// Heat time MSB
		(heat_time & 0xff), 		// Heat time LSB
	};
	size_t tx_len = 3;

	/* RX */
	uint8_t rx_buff[3];
	size_t rx_len = 3;

	/* Send and receive */
	error = gs_i2c_master_transaction(i2c_bus_handle, slave_node, tx_buff, tx_len, rx_buff, rx_len, timeout_ms);

	/* Return error code if not success full */
	if(error != GS_OK){
		printf("error: %i in gs_i2c_master_transaction()\n\r",error);
		return error;
	}
	/* Check error code from reply (byte 1, 0x00 = OK and 0xFF = CMD ERROR) */
	if (rx_buff[1] == 0xFF){
		printf("Received CMD ERROR from BPX\n\r");
		return GS_ERROR_IO;
	} else if (rx_buff[1] != 0x00){
		return GS_ERROR_IO;
	}

	/* Check reply from heater */
	if (rx_buff[2] != BPX_MAN_HEAT_OK){
		return GS_ERROR_IO;
	}

	printf("Heat on for %u seconds\n\r",heat_time);
	return GS_OK;
}

int bpx_slave_heat_off(struct command_context *ctx) {
	gs_error_t error;

	/* TX */
	const uint8_t tx_buff[1] = {
		BPX_PORT_MAN_HEAT_OFF, 		// Manual heat off port
	};
	size_t tx_len = 1;

	/* RX */
	uint8_t rx_buff[3];
	size_t rx_len = 3;

	/* Send and receive */
	error = gs_i2c_master_transaction(i2c_bus_handle, slave_node, tx_buff, tx_len, rx_buff, rx_len, timeout_ms);

	/* Return error code if not success full */
	if(error != GS_OK){
		printf("error: %i in gs_i2c_master_transaction()\n\r",error);
		return error;
	}

	/* Check error code from reply (byte 1, 0x00 = OK and 0xFF = CMD ERROR) */
	if (rx_buff[1] == 0xFF){
		printf("Received CMD ERROR from BPX\n\r");
		return GS_ERROR_IO;
	} else if (rx_buff[1] != 0x00){
		return GS_ERROR_IO;
	}

	/* Check reply from heater */
	if (rx_buff[2] != BPX_MAN_HEAT_OK){
		return GS_ERROR_IO;
	}

	printf("Heat off\n\r");
	return GS_OK;
}

/***************************************************************/

int cmd_bpx_slave_config_get(struct command_context *ctx) {
	gs_error_t error;

	/* TX */
	const uint8_t tx_buff[1] = {
		BPX_PORT_CONFIG_GET, 	// Config get port
	};
	size_t tx_len = 1;

	/* RX */
	uint8_t rx_buff[2 + (uint8_t) sizeof(bpx_config_t)];
	size_t rx_len = 2 + (uint8_t) sizeof(bpx_config_t);

	/* Send and receive */
	error = gs_i2c_master_transaction(i2c_bus_handle, slave_node, tx_buff, tx_len, rx_buff, rx_len, timeout_ms);

	/* Return error code if not success full */
	if(error != GS_OK){
		printf("error: %i in gs_i2c_master_transaction()\n\r",error);
		return error;
	}

	/* Check error code from reply (byte 1, 0x00 = OK and 0xFF = CMD ERROR) */
	if (rx_buff[1] == 0xFF){
		printf("Received CMD ERROR from BPX\n\r");
		return GS_ERROR_IO;
	} else if (rx_buff[1] != 0x00){
		return GS_ERROR_IO;
	}

	/* Save to local config and print*/
	memcpy(&bpx_config, &rx_buff[2], sizeof(bpx_config_t));
	bpx_config_print((bpx_config_t *)&bpx_config);
	return GS_OK;
}


int cmd_bpx_slave_config_print(struct command_context *ctx) {
	bpx_config_print(&bpx_config);
	return GS_OK;
}

int cmd_bpx_slave_config_set(struct command_context *ctx) {
	gs_error_t error;

	printf("Setting BPX Config\r\n");

	/* TX */
	uint8_t tx_buff[1 + (uint8_t) sizeof(bpx_config_t)] = {
		BPX_PORT_CONFIG_SET, 	// Config set port
	};
	memcpy(&tx_buff[1], &bpx_config, sizeof(bpx_config_t));
	size_t tx_len = 1 + (uint8_t) sizeof(bpx_config_t);

	/* RX */
	uint8_t rx_buff[2];
	size_t rx_len = 2;

	/* Send and receive */
	error = gs_i2c_master_transaction(i2c_bus_handle, slave_node, tx_buff, tx_len, rx_buff, rx_len, timeout_ms);

	/* Return error code if not success full */
	if(error != GS_OK){
		printf("error: %i in gs_i2c_master_transaction()\n\r",error);
		return error;
	}

	/* Check error code from reply (byte 1, 0x00 = OK and 0xFF = CMD ERROR) */
	if (rx_buff[1] == 0xFF){
		printf("Received CMD ERROR from BPX\n\r");
		return GS_ERROR_IO;
	} else if (rx_buff[1] != 0x00){
		return GS_ERROR_IO;
	}
	return GS_OK;
}

int cmd_bpx_slave_config_restore(struct command_context *ctx) {
	gs_error_t error;

	printf("Restoring BPX Config\r\n");

	/* TX */
	uint8_t tx_buff[2] = {
		BPX_PORT_CONFIG_CMD, 	// Config restore port
		1						// Setting CMD = 1, which restores default config
	};
	size_t tx_len = 2;

	/* RX */
	uint8_t rx_buff[2];
	size_t rx_len = 2;

	/* Send and receive */
	error = gs_i2c_master_transaction(i2c_bus_handle, slave_node, tx_buff, tx_len, rx_buff, rx_len, timeout_ms);

	/* Return error code if not success full */
	if(error != GS_OK){
		printf("error: %i in gs_i2c_master_transaction()\n\r",error);
		return error;
	}

	/* Check error code from reply (byte 1, 0x00 = OK and 0xFF = CMD ERROR) */
	if (rx_buff[1] == 0xFF){
		printf("Received CMD ERROR from BPX\n\r");
		return GS_ERROR_IO;
	} else if (rx_buff[1] != 0x00){
		return GS_ERROR_IO;
	}
	return GS_OK;
}

int cmd_bpx_slave_config_edit(struct command_context *ctx) {

	cmd_bpx_config_edit(NULL);
	return CMD_ERROR_NONE;

}



/*********************************************************/

int bpx_slave_reset_persistent(struct command_context *ctx) {
	gs_error_t error;

	printf("Resetting BPX reboot counter\n\r");

	/* TX */
	uint8_t tx_buff[2] = {
		BPX_PORT_RESET_COUNTERS,// Reset counters port
		0x42					// Magic number = 0x42
	};
	size_t tx_len = 2;

	/* RX */
	uint8_t rx_buff[2];
	size_t rx_len = 2;

	/* Send and receive */
	error = gs_i2c_master_transaction(i2c_bus_handle, slave_node, tx_buff, tx_len, rx_buff, rx_len, timeout_ms);

	/* Return error code if not success full */
	if(error != GS_OK){
		printf("error: %i in gs_i2c_master_transaction()\n\r",error);
		return error;
	}

	/* Check error code from reply (byte 1, 0x00 = OK and 0xFF = CMD ERROR) */
	if (rx_buff[1] == 0xFF){
		printf("Received CMD ERROR from BPX\n\r");
		return GS_ERROR_IO;
	} else if (rx_buff[1] != 0x00){
		return GS_ERROR_IO;
	}
	return GS_OK;
}

static const command_t __sub_command bpx_slave_config_subcommands[] = {
	{
		.name = "get",
		.help = "Conf get",
		.handler = cmd_bpx_slave_config_get,
	},{
		.name = "set",
		.help = "Conf set",
		.handler = cmd_bpx_slave_config_set,
	},{
		.name = "edit",
		.help = "Edit local config",
		.handler = cmd_bpx_slave_config_edit,
	},{
		.name = "print",
		.help = "Print local config",
		.handler = cmd_bpx_slave_config_print,
	},{
		.name = "restore",
		.help = "Restore config from default",
		.handler = cmd_bpx_slave_config_restore,
	}
};

static const command_t __sub_command bpx_slave_man_heat_subcommands[] = {
	{
		.name = "off",
		.help = "Heat off",
		.handler = bpx_slave_heat_off,
	},{
		.name = "on",
		.help = "Heat on for specific time",
		.handler = bpx_slave_heat_on,
		.usage = "<time>"
	}
};



static const command_t __sub_command bpx_slavecommands[] = {
	{
		.name = "node",
		.help = "Set slave BPX address in host table",
		.handler = bpx_slave_node,
	},{
		.name = "hk",
		.help = "Get slave HK",
		.handler = bpx_slave_hk,
	},{
		.name = "ping",
		.help = "Slave ping",
		.handler = bpx_slave_ping,
	},{
		.name = "man_heat",
		.help = "Manual heating",
		.chain = INIT_CHAIN(bpx_slave_man_heat_subcommands),
	},{
		.name = "reboot",
		.help = "Slave reboot",
		.handler = bpx_slave_reboot,
	},{
		.name = "resetcount",
		.help = "Set counters = 0",
		.handler = bpx_slave_reset_persistent,
	},{
		.name = "conf",
		.help = "Configuration",
		.chain = INIT_CHAIN(bpx_slave_config_subcommands),
	}
};

static const command_t __root_command bpxslave_commands[] = {
	{
		.name = "bpxslave",
		.help = "NanoPower BPX (slave)",
		.chain = INIT_CHAIN(bpx_slavecommands),
	}
};

void cmd_bpxslave_setup(void) {
	command_register(bpxslave_commands);
}
