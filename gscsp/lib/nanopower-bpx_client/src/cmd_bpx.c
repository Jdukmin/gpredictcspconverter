/* Copyright (c) 2013-2019 GomSpace A/S. All rights reserved. */

#include <math.h>
#include <inttypes.h>
#include <util/log.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include <gs/bpx/io.h>
#include <gs/gosh/util/console.h>

bpx_config_t bpx_config;

int cmd_bpx_counters_reset(struct command_context *ctx) {
    bpx_counters_reset();
    return CMD_ERROR_NONE;
}

int cmd_bpx_node_set(struct command_context *ctx) {
    if (ctx->argc != 2) {
        return CMD_ERROR_SYNTAX;
    }
    uint8_t node = atoi(ctx->argv[1]);
    bpx_node_set(node);
    return CMD_ERROR_NONE;
}

int cmd_bpx_hk_get(struct command_context *ctx) {
    bpx_hk_t hk;
    if (bpx_hk_get(&hk) <= 0) {
        return CMD_ERROR_FAIL;
    }
    printf("Charge current        %"PRIu16" mA\r\n", hk.cur_charge);
    printf("Discharge current     %"PRIu16" mA\r\n", hk.cur_discharge);
    printf("Heater current        %"PRIu16" mA\r\n", hk.cur_heater);
    printf("Battery voltage       %"PRIu16" mV\r\n", hk.vbatt);
    printf("Battery temperature 1 %"PRId16" degC\r\n", hk.bat_temperature1);
    printf("Battery temperature 2 %"PRId16" degC\r\n", hk.bat_temperature2);
    printf("Battery temperature 3 %"PRId16" degC\r\n", hk.bat_temperature3);
    printf("Battery temperature 4 %"PRId16" degC\r\n", hk.bat_temperature4);
    printf("Bootcause %"PRIu8" \r\n", hk.bootcause);
    printf("Bootcount %"PRIu32" \r\n", hk.counter_boot);
    return CMD_ERROR_NONE;
}

int cmd_bpx_config_get(struct command_context *ctx) {
    if(bpx_config_get(&bpx_config) <= 0) {
        return CMD_ERROR_FAIL;
    }
    bpx_config_print(&bpx_config);
    return CMD_ERROR_NONE;
}

int cmd_bpx_config_print(struct command_context *ctx) {
    bpx_config_print(&bpx_config);
    return CMD_ERROR_NONE;
}

int cmd_bpx_config_set(struct command_context *ctx) {
    if(bpx_config_set(&bpx_config) <= 0) {
        return CMD_ERROR_FAIL;
    }
    bpx_config_t config_tmp;
    if(bpx_config_get(&config_tmp) <= 0) {
        return CMD_ERROR_FAIL;
    }
    if(config_tmp.battheater_high != bpx_config.battheater_high ||
       config_tmp.battheater_low != bpx_config.battheater_low   ||
       config_tmp.battheater_mode != bpx_config.battheater_mode ) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

int cmd_bpx_config_restore(struct command_context *ctx) {
    if(bpx_config_cmd(1) <= 0) {
        return CMD_ERROR_FAIL;
    }
    if(bpx_config_get(&bpx_config) <= 0) {
        return CMD_ERROR_FAIL;
    }
    printf("Conf restored to:\n\r");
    bpx_config_print(&bpx_config);
    return CMD_ERROR_NONE;
}

int cmd_bpx_config_edit(struct command_context *ctx) {
    int scan;
    int ret __attribute__((unused));

    if (ctx->argc == 4) {
        bpx_config.battheater_mode = atoi(ctx->argv[1]);
        bpx_config.battheater_low = atoi(ctx->argv[2]);
        bpx_config.battheater_high = atoi(ctx->argv[3]);
        bpx_config_print(&bpx_config);
    } else {
        printf("Edit BPX configuration\r\n");
        printf("Press <.> to skip\r\n");

        printf("Battheater mode: %u > ", bpx_config.battheater_mode);
        fflush(stdout);
        if ((ret = scanf("%d%*[^\r]", &scan)) == 1) {
            bpx_config.battheater_mode = scan;
        }
        if (scan != 1) {
            scan = 0;
        }
        printf(" [%d] > %u\r\n", ret, bpx_config.battheater_mode);
        ret = scanf("%*c");

        printf("Battheater LOW: %d > ", bpx_config.battheater_low);
        fflush(stdout);
        if ((ret = scanf("%d%*[^\r]", &scan)) == 1) {
            bpx_config.battheater_low = scan;
        }
        printf(" [%d] > %d\r\n", ret, bpx_config.battheater_low);
        ret = scanf("%*c");

        /* PPT mode */
        printf("Battheater HIGH: %d > ", bpx_config.battheater_high);
        fflush(stdout);
        if ((ret = scanf("%d%*[^\r]", &scan)) == 1) {
            bpx_config.battheater_high = scan;
        }
        printf(" [%d] > %d\r\n", ret, bpx_config.battheater_high);
        ret = scanf("%*c");
    }
    return CMD_ERROR_NONE;
}

int cmd_bpx_heat_on(struct command_context *ctx) {
    uint16_t heat_time;
    if (ctx->argc != 2) {
        return CMD_ERROR_SYNTAX;
    }
    heat_time = atoi(ctx->argv[1]);
    if(heat_time > 600) {
        printf("heat_time has to be in interval [0 : 600]\n\r");
        return CMD_ERROR_SYNTAX;
    }
    uint8_t ok_flag = 0;
    if(bpx_heat_on(heat_time, &ok_flag) <= 0) {
        return CMD_ERROR_FAIL;
    }
    if(ok_flag != BPX_MAN_HEAT_OK) {
        return CMD_ERROR_FAIL;
    }
    printf("Heat on for %u seconds\n\r",heat_time);
    return CMD_ERROR_NONE;
}

int cmd_bpx_heat_off(struct command_context *ctx) {
    uint8_t ok_flag = 0;
    if(bpx_heat_off(&ok_flag)<= 0) {
        return CMD_ERROR_FAIL;
    }
    if(ok_flag != BPX_MAN_HEAT_OK) {
        return CMD_ERROR_FAIL;
    }
    return CMD_ERROR_NONE;
}

static const command_t __sub_command bpx_config_subcommands[] = {
    {
        .name = "get",
        .help = "Conf get",
        .handler = cmd_bpx_config_get,
    },{
        .name = "set",
        .help = "Conf set",
        .handler = cmd_bpx_config_set,
    },{
        .name = "edit",
        .help = "Edit local config",
        .usage = "[<heater mode> <heat low temp> <heat high temp>]",
        .handler = cmd_bpx_config_edit,
    },{
        .name = "print",
        .help = "Print local config",
        .handler = cmd_bpx_config_print,
    },{
        .name = "restore",
        .help = "Restore config from default",
        .handler = cmd_bpx_config_restore,
    }
};

static const command_t __sub_command bpx_man_heat_subcommands[] = {
    {
        .name = "off",
        .help = "Heat off",
        .handler = cmd_bpx_heat_off,
    },{
        .name = "on",
        .help = "Heat on for specific time",
        .handler = cmd_bpx_heat_on,
        .usage = "<time>"
    }
};

static const command_t __sub_command bpx_subcommands[] = {
    {
        .name = "resetcount",
        .help = "Reset all counters to zero",
        .handler = cmd_bpx_counters_reset,
    },{
        .name = "conf",
        .help = "Configuration",
        .chain = INIT_CHAIN(bpx_config_subcommands),
    },{
        .name = "hk",
        .help = "Get HK values",
        .handler = cmd_bpx_hk_get,
    },{
        .name = "man_heat",
        .help = "Manual heating",
        .chain = INIT_CHAIN(bpx_man_heat_subcommands),
    },{
        .name = "node",
        .help = "Set client BPX csp/i2c add",
        .usage = "<add>",
        .handler = cmd_bpx_node_set,
    }
};

static const command_t __root_command bpx_commands[] = {
    {
        .name = "bpx",
        .help = "NanoPower BPX client",
        .chain = INIT_CHAIN(bpx_subcommands),
    }
};

void cmd_bpx_setup(void) {
    command_register(bpx_commands);
}
