/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include <io/nanopower2.h>
#include <gs/csp/port.h>
#include <gs/util/drivers/i2c/master.h>
#include <gs/util/byteorder.h>
#include <gs/util/error.h>
#include <gs/util/gosh/command.h>


/* EPS I2C slave mode commands */
static int slave_node = NODE_EPS;
/* I2C timeout_ms in ms */
static const int timeout_ms = 200;
/* I2C device */
static const uint8_t device = 0;
/* Defined in cmd_eps */
extern eps_config_t nanopower_config;
extern eps_config2_t nanopower_config2;
extern int cmd_eps_config_edit(struct command_context *ctx);


gs_error_t eps_slave_node(struct command_context *ctx) {
    uint16_t node;

    if(gs_string_to_uint16(ctx->argv[1], &node) != GS_OK) {
        return GS_ERROR_ARG;
    }

    printf("Setting EPS slave node address to %u\r\n", node);
    slave_node = node;
    return GS_OK;
}


gs_error_t eps_slave_ping(struct command_context *ctx) {
    uint8_t len_rx = 3;
    uint8_t len_tx = 2;
    uint8_t frame_data[len_rx];
    frame_data[0] = CSP_PING;
    frame_data[1] = 0x55;
    frame_data[2] = 0x00;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    if (res_tx == GS_OK && frame_data[2]==0x55) {
        printf("Received reply from EPS: 0x%02X%02X\r\n", frame_data[1], frame_data[2]);
    } else if (res_tx == GS_OK && frame_data[2]!=0x55 ){
        printf("Wrong reply from EPS, got 0x%02X%02X - expected: 0x55\r\n", frame_data[1], frame_data[2]);
        res_tx = GS_ERROR_UNKNOWN;
    }
    return res_tx;
}


gs_error_t eps_slave_reboot(struct command_context *ctx) {
    uint8_t len_rx = 0;
    uint8_t len_tx = 5;
    uint8_t frame_data[5];
    frame_data[0] = CSP_REBOOT;
    frame_data[1] = 0x80;
    frame_data[2] = 0x07;
    frame_data[3] = 0x80;
    frame_data[4] = 0x07;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    if (res_tx == GS_OK) {
        printf("Sent reboot command to EPS\r\n");
    }
    return res_tx;
}


gs_error_t eps_slave_hk(struct command_context *ctx) {
    int bintmp;
    eps_hk_1_t * chkparam;
    uint8_t len_rx = 2 + (uint8_t) sizeof(eps_hk_1_t);
    uint8_t len_tx = 1;
    uint8_t frame_data[len_rx];
    frame_data[0] = EPS_PORT_HK;

    printf("Requesting EPS HK data\r\n");
    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    if (res_tx == GS_OK) {
        chkparam = (eps_hk_1_t *)&frame_data[2];

        chkparam->pv[0] = util_ntoh16(chkparam->pv[0]);
        chkparam->pv[1] = util_ntoh16(chkparam->pv[1]);
        chkparam->pv[2] = util_ntoh16(chkparam->pv[2]);
        chkparam->pc = util_ntoh16(chkparam->pc);
        chkparam->bv = util_ntoh16(chkparam->bv);
        chkparam->sc = util_ntoh16(chkparam->sc);
        chkparam->temp[0] = util_ntoh16(chkparam->temp[0]);
        chkparam->temp[1] = util_ntoh16(chkparam->temp[1]);
        chkparam->temp[2] = util_ntoh16(chkparam->temp[2]);
        chkparam->temp[3] = util_ntoh16(chkparam->temp[3]);
        chkparam->temp[4] = util_ntoh16(chkparam->temp[4]);
        chkparam->temp[5] = util_ntoh16(chkparam->temp[5]);
        chkparam->latchup[0] = util_ntoh16(chkparam->latchup[0]);
        chkparam->latchup[1] = util_ntoh16(chkparam->latchup[1]);
        chkparam->latchup[2] = util_ntoh16(chkparam->latchup[2]);
        chkparam->latchup[3] = util_ntoh16(chkparam->latchup[3]);
        chkparam->latchup[4] = util_ntoh16(chkparam->latchup[4]);
        chkparam->latchup[5] = util_ntoh16(chkparam->latchup[5]);
        chkparam->sw_errors = util_ntoh16(chkparam->sw_errors);
        chkparam->bootcount = util_ntoh16(chkparam->bootcount);

        printf("ADC sample:\r\n");
        printf("Temp 1 %"PRId16"\r\n", chkparam->temp[0]);
        printf("Temp 2 %"PRId16"\r\n", chkparam->temp[1]);
        printf("Temp 3 %"PRId16"\r\n", chkparam->temp[2]);
        printf("Temp PCB %"PRId16"\r\n", chkparam->temp[3]);
        printf("BV %u\r\n", chkparam->bv);
        printf("PC %u\r\n", chkparam->pc);
        printf("SC %u\r\n", chkparam->sc);
        printf("PV1 %u\r\n", chkparam->pv[0]);
        printf("PV2 %u\r\n", chkparam->pv[1]);
        printf("PV3 %u\r\n", chkparam->pv[2]);
        printf("Latch up 1 %u\r\n", chkparam->latchup[0]);
        printf("Latch up 2 %u\r\n", chkparam->latchup[1]);
        printf("Latch up 3 %u\r\n", chkparam->latchup[2]);
        printf("Latch up 4 %u\r\n", chkparam->latchup[3]);
        printf("Latch up 5 %u\r\n", chkparam->latchup[4]);
        printf("Latch up 6 %u\r\n", chkparam->latchup[5]);
        printf("User Channel Status %02X ; \r\n", chkparam->channel_status);
        bintmp = chkparam->channel_status;
        int n;
        for(n=0; n<8; n++)
           {
              if((bintmp & 0x80) !=0)
              {
                 printf("1");
              }
              else
              {
                 printf("0");
              }
              if (n==3)
              {
                 printf(" "); /* insert a space between nybbles */
              }
              bintmp = bintmp<<1;
           }
        printf("\r\n");
        printf("Battery temperature 1 %"PRId16"\r\n", chkparam->temp[4]);
        printf("Battery temperature 2 %"PRId16"\r\n", chkparam->temp[5]);
        printf("Reset %d   BootCount %d   SW Err %d   PPT mode %d\r\n",chkparam->reset,chkparam->bootcount,chkparam->sw_errors,chkparam->ppt_mode);
    }
    return res_tx;
}


gs_error_t eps_slave_hk2(struct command_context *ctx) {
    eps_hk_t * chkparam;
    uint8_t len_rx = 2 + (uint8_t) sizeof(eps_hk_t);
    uint8_t len_tx = 2;
    uint8_t frame_data[len_rx];
    frame_data[0] = EPS_PORT_HK;
    frame_data[1] = 0;

    printf("Requesting EPS HK2 data\r\n");
    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    if (res_tx == GS_OK) {
        chkparam = (eps_hk_t *)&frame_data[2];
        eps_hk_unpack(chkparam);
        eps_hk_print(chkparam);
    }
    return res_tx;
}


gs_error_t eps_slave_hk2_vi(struct command_context *ctx) {
    eps_hk_vi_t * hk;
    uint8_t len_rx = 2 + (uint8_t) sizeof(eps_hk_vi_t);
    uint8_t len_tx = 2;
    uint8_t frame_data[len_rx];
    frame_data[0] = EPS_PORT_HK;
    frame_data[1] = 1;

    printf("Requesting EPS HK2 vi data\r\n");
    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    if (res_tx == GS_OK) {
        hk = (eps_hk_vi_t *)&frame_data[2];
        eps_hk_vi_unpack(hk);
        eps_hk_vi_print_text(hk);
    }
    return res_tx;
}


gs_error_t eps_slave_hk2_out(struct command_context *ctx) {
    eps_hk_out_t * hk;
    uint8_t len_rx = 2 + (uint8_t) sizeof(eps_hk_out_t);
    uint8_t len_tx = 2;
    uint8_t frame_data[len_rx];
    frame_data[0] = EPS_PORT_HK;
    frame_data[1] = 2;

    printf("Requesting EPS HK2 out data\r\n");
    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    if (res_tx == GS_OK) {
        hk = (eps_hk_out_t *)&frame_data[2];
        eps_hk_out_unpack(hk);
        eps_hk_out_print_text(hk);
    }
    return res_tx;
}


gs_error_t eps_slave_hk2_wdt(struct command_context *ctx) {
    eps_hk_wdt_t * hk;
    uint8_t len_rx = 2 + (uint8_t) sizeof(eps_hk_wdt_t);
    uint8_t len_tx = 2;
    uint8_t frame_data[len_rx];
    frame_data[0] = EPS_PORT_HK;
    frame_data[1] = 3;

    printf("Requesting EPS HK2 wdt data\r\n");
    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    if (res_tx == GS_OK) {
        hk = (eps_hk_wdt_t *)&frame_data[2];
        eps_hk_wdt_unpack(hk);
        eps_hk_wdt_print_text(hk);
    }
    return res_tx;
}


gs_error_t eps_slave_hk2_basic(struct command_context *ctx) {
    eps_hk_basic_t * hk;
    uint8_t len_rx = 2 + (uint8_t) sizeof(eps_hk_basic_t);
    uint8_t len_tx = 2;
    uint8_t frame_data[len_rx];
    frame_data[0] = EPS_PORT_HK;
    frame_data[1] = 4;

    printf("Requesting EPS HK2 basic data\r\n");
    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    if (res_tx == GS_OK) {
        hk = (eps_hk_basic_t *)&frame_data[2];
        eps_hk_basic_unpack(hk);
        eps_hk_basic_print_text(hk);
    }
    return res_tx;
}


gs_error_t eps_slave_output(struct command_context *ctx) {
    const char * args = gs_command_args(ctx);
    uint16_t outputs;
    printf("console args: %s\r\n", args);

    if(gs_string_to_uint16(ctx->argv[1], &outputs) != GS_OK) {
        return GS_ERROR_ARG;
    }
    printf("Outputs 0x%02X\r\n", outputs);

    uint8_t len_rx = 0;
    uint8_t len_tx = 2;
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_SET_OUTPUT;
    frame_data[1] = outputs;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t eps_slave_single_output(struct command_context *ctx) {
    uint8_t channel, mode;
    int16_t delay;
    printf("Input channel, mode (0=off, 1=on), and delay\r\n");

    if(gs_string_to_uint8(ctx->argv[1], &channel) != GS_OK) {
        return GS_ERROR_ARG;
    }
    if(gs_string_to_uint8(ctx->argv[2], &mode) != GS_OK) {
        return GS_ERROR_ARG;
    }
    if(gs_string_to_int16(ctx->argv[3], &delay) != GS_OK) {
        return GS_ERROR_ARG;
    }
    printf("Channel %u is set to %u with delay %d\r\n", channel, mode, delay);

    eps_output_set_single_req eps_switch;
    eps_switch.channel = channel;
    eps_switch.mode = mode;
    eps_switch.delay = util_hton16((int16_t)delay);

    uint8_t len_rx = 0;
    uint8_t len_tx = 1 + sizeof(eps_switch);
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_SET_SINGLE_OUTPUT;
    memcpy(&frame_data[1], &eps_switch, sizeof(eps_switch));

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t eps_slave_volt(struct command_context *ctx) {
    uint16_t pv1, pv2, pv3;

    if(gs_string_to_uint16(ctx->argv[1], &pv1) != GS_OK) {
        return GS_ERROR_ARG;
    }
    if(gs_string_to_uint16(ctx->argv[2], &pv2) != GS_OK) {
        return GS_ERROR_ARG;
    }
    if(gs_string_to_uint16(ctx->argv[3], &pv3) != GS_OK) {
        return GS_ERROR_ARG;
    }

    printf("PV1: %04u PV2: %04u PV3: %04u\r\n", pv1, pv2, pv3);

    uint16_t pvolt[3];
    pvolt[0] = util_hton16(pv1);
    pvolt[1] = util_hton16(pv2);
    pvolt[2] = util_hton16(pv3);

    uint8_t len_rx = 0;
    uint8_t len_tx = 1 + 3 * sizeof(uint16_t);
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_SET_VBOOST;
    memcpy(&frame_data[1], &pvolt, 3 * sizeof(uint16_t));

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t eps_slave_ppt_mode(struct command_context *ctx) {
    uint8_t mode;
    if(gs_string_to_uint8(ctx->argv[1], &mode) != GS_OK) {
        return GS_ERROR_ARG;
    }
    printf("Mode %u (", mode);
    switch(mode) {
        case 0: printf("Hardware)\r\n"); break;
        case 1: printf("MPPT)\r\n"); break;
        case 2: printf("Fixed)\r\n"); break;
        default: printf("Unknown)\r\n");
    }

    uint8_t len_rx = 0;
    uint8_t len_tx = 2;
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_SET_PPTMODE;
    frame_data[1] = (uint8_t)mode;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t eps_slave_hardreset(struct command_context *ctx) {
    uint8_t len_rx = 0;
    uint8_t len_tx = 1;
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_HARDRESET;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t eps_slave_wdt_gnd_reset(struct command_context *ctx) {
    uint8_t len_rx = 0;
    uint8_t len_tx = 2;
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_RESET_WDT_GND;
    frame_data[1] = 0x78;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}
/***************************************************************/


gs_error_t cmd_eps_slave_config_get(struct command_context *ctx) {
    printf("Requesting EPS Config\r\n");
    uint8_t len_rx = 2 + (uint8_t) sizeof(eps_config_t);
    uint8_t len_tx = 1;
    uint8_t frame_data[len_rx];
    frame_data[0] = EPS_PORT_CONFIG_GET;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    if (res_tx == GS_OK) {
        memcpy(&nanopower_config, &frame_data[2], sizeof(eps_config_t));
        eps_config_unpack(&nanopower_config);
        eps_config_print(&nanopower_config);
    }
    return res_tx;
}


gs_error_t cmd_eps_slave_config_print(struct command_context *ctx) {
    eps_config_print(&nanopower_config);
    return GS_OK;
}


gs_error_t cmd_eps_slave_config_set(struct command_context *ctx) {
    uint8_t len_rx = 2;
    uint8_t len_tx = 1 + (uint8_t) sizeof(eps_config_t);
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_CONFIG_SET;
    memcpy(&frame_data[1], &nanopower_config, sizeof(eps_config_t));
    eps_config_pack((eps_config_t *) &frame_data[1]);

    printf("Setting EPS Config\r\n");
    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t cmd_eps_slave_config_restore(struct command_context *ctx) {
    uint8_t len_rx = 0;
    uint8_t len_tx = 2;
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_CONFIG_CMD;
    frame_data[1] = 1;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t cmd_eps_slave_config_confirm(struct command_context *ctx) {
    uint8_t len_rx = 0;
    uint8_t len_tx = 2;
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_CONFIG_CMD;
    frame_data[1] = 2;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t cmd_eps_slave_config_edit(struct command_context *ctx) {
    cmd_eps_config_edit(NULL);
    return GS_OK;
}
/*********************************************************/


gs_error_t cmd_eps_slave_config2_get(struct command_context *ctx) {
    uint8_t len_rx = 2 + (uint8_t) sizeof(eps_config2_t);
    uint8_t len_tx = 1;
    uint8_t frame_data[len_rx];
    frame_data[0] = EPS_PORT_CONFIG2_GET;

    printf("Requesting EPS Config2\r\n");
    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    if (res_tx == GS_OK) {
        memcpy(&nanopower_config2, &frame_data[2], sizeof(eps_config2_t));
        eps_config2_unpack(&nanopower_config2);
        eps_config2_print(&nanopower_config2);
    }
    return res_tx;
}


gs_error_t cmd_eps_slave_config2_print(struct command_context *ctx) {
    eps_config2_print(&nanopower_config2);
    return GS_OK;
}


gs_error_t cmd_eps_slave_config2_set(struct command_context *ctx) {
    uint8_t len_rx = 2;
    uint8_t len_tx = 1 + (uint8_t) sizeof(eps_config2_t);
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_CONFIG2_SET;
    memcpy(&frame_data[1], &nanopower_config2, sizeof(eps_config2_t));
    eps_config2_pack((eps_config2_t *) &frame_data[1]);

    printf("Setting EPS Config2\r\n");
    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t cmd_eps_slave_config2_restore(struct command_context *ctx) {
    uint8_t len_rx = 0;
    uint8_t len_tx = 2;
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_CONFIG2_CMD;
    frame_data[1] = 1;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t cmd_eps_slave_config2_confirm(struct command_context *ctx) {
    uint8_t len_rx = 0;
    uint8_t len_tx = 2;
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_CONFIG2_CMD;
    frame_data[1] = 2;

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


gs_error_t cmd_eps_slave_config2_edit(struct command_context *ctx) {
    /* Call non slave function */
    gs_error_t cmd_eps_config2_edit(struct command_context *ctx);
    cmd_eps_config2_edit(ctx);

    return GS_OK;
}
/*********************************************************/


gs_error_t eps_slave_reset_persistent(struct command_context *ctx) {
    uint8_t len_rx = 0;
    uint8_t len_tx = 2;
    uint8_t frame_data[len_tx];
    frame_data[0] = EPS_PORT_RESET_COUNTERS;
    frame_data[1] = 0x42;  // magic

    gs_error_t res_tx = gs_i2c_master_transaction(device, slave_node, frame_data, len_tx, frame_data, len_rx, timeout_ms);
    return res_tx;
}


static const gs_command_t GS_COMMAND_SUB  eps_slave_config_subcommands[] = {
    {
        .name = "get",
        .help = "Conf get",
        .handler = cmd_eps_slave_config_get,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "set",
        .help = "Conf set",
        .handler = cmd_eps_slave_config_set,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "edit",
        .help = "Edit local config",
        .handler = cmd_eps_slave_config_edit,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "print",
        .help = "Print local config",
        .handler = cmd_eps_slave_config_print,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "restore",
        .help = "Restore config from default",
        .handler = cmd_eps_slave_config_restore,
        .mandatory_args=0,
        .optional_args=0,
    }
};


static const gs_command_t GS_COMMAND_SUB  eps_slave_config2_subcommands[] = {
    {
        .name = "get",
        .help = "Conf2 get",
        .handler = cmd_eps_slave_config2_get,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "set",
        .help = "Conf2 set",
        .handler = cmd_eps_slave_config2_set,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "edit",
        .help = "Edit local config2",
        .handler = cmd_eps_slave_config2_edit,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "print",
        .help = "Print local config2",
        .handler = cmd_eps_slave_config2_print,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "confirm",
        .help = "Confirm config2 from default",
        .handler = cmd_eps_slave_config2_confirm,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "restore",
        .help = "Restore config2 from default",
        .handler = cmd_eps_slave_config2_restore,
        .mandatory_args=0,
        .optional_args=0,
    }
};


static const gs_command_t GS_COMMAND_SUB  eps_slave_hk_subcommands[] = {
    {
        .name = "vi",
        .help = "Get Voltages and Currents",
        .handler = eps_slave_hk2_vi,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "out",
        .help = "Get output switch data",
        .handler = eps_slave_hk2_out,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "wdt",
        .help = "Get wdt data",
        .handler = eps_slave_hk2_wdt,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "basic",
        .help = "Get basic housekeeping data",
        .handler = eps_slave_hk2_basic,
        .mandatory_args=0,
        .optional_args=0,
    }
};


static const gs_command_t GS_COMMAND_SUB  eps_slavecommands[] = {
    {
        .name = "node",
        .help = "Set slave EPS address in OBC host table",
        .handler = eps_slave_node,
        .mandatory_args=1,
        .optional_args=0,
    },{
        .name = "hk",
        .help = "Get slave HK",
        .handler = eps_slave_hk,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "hk2",
        .help = "Get slave new HK",
        .handler = eps_slave_hk2,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "hksub",
        .help = "Get HK sub structs",
        .chain = GS_COMMAND_INIT_CHAIN(eps_slave_hk_subcommands),
    },{
        .name = "outputmask",
        .help = "Set slave on/off",
        .usage = "<output port hex>",
        .handler = eps_slave_output,
        .mandatory_args=1,
        .optional_args=0,
    },{
        .name = "output",
        .help = "Set slave channel on/off",
        .usage = "<channel> <1/0> <delay>",
        .handler = eps_slave_single_output,
        .mandatory_args=3,
        .optional_args=0,
    },{
        .name = "vboost",
        .help = "Set slave pvolt, arguments (mV)",
        .usage = "<pv1> <pv2> <pv3>",
        .handler = eps_slave_volt,
        .mandatory_args=3,
        .optional_args=0,
    },{
        .name = "ppt",
        .help = "Set slave PPT mode (0 = Hardware, 1 = MPPT, 2 = Fixed SW PPT)",
        .usage = "<mode>",
        .handler = eps_slave_ppt_mode,
        .mandatory_args=1,
        .optional_args=0,
    },{
        .name = "ping",
        .help = "Slave ping",
        .handler = eps_slave_ping,
    },{
        .name = "reboot",
        .help = "Slave reboot",
        .handler = eps_slave_reboot,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "persistentreset",
        .help = "Set persistent variables = 0",
        .handler = eps_slave_reset_persistent,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "hardreset",
        .help = "Completely powercycle EPS",
        .handler = eps_slave_hardreset,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "resetwdt",
        .help = "Resets the WDT GND",
        .handler = eps_slave_wdt_gnd_reset,
        .mandatory_args=0,
        .optional_args=0,
    },{
        .name = "conf",
        .help = "Configuration",
        .chain = GS_COMMAND_INIT_CHAIN(eps_slave_config_subcommands),
    },{
        .name = "conf2",
        .help = "Configuration2",
        .chain = GS_COMMAND_INIT_CHAIN(eps_slave_config2_subcommands),
    }
};


static const gs_command_t GS_COMMAND_ROOT epsslave_commands[] = {
    {
        .name = "epsslave",
        .help = "NanoPower P31u (slave)",
        .chain = GS_COMMAND_INIT_CHAIN(eps_slavecommands),
    }
};


void cmd_epsslave_setup(void) {
    GS_COMMAND_REGISTER(epsslave_commands);
}
