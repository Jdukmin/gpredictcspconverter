/*
 * Commands for SOFT
 * Copyright 2015 GomSpace ApS. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <command/command.h>

#include <gs/soft/cmd_exec.h>
#include <gs/soft/param/soft.h>

uint8_t soft_node = 6;
uint32_t soft_timeout = 2000;

static int cmd_set_node(struct command_context *ctx) 
{
        if (ctx->argc != 2)
		return CMD_ERROR_SYNTAX;

	soft_node = atoi(ctx->argv[1]);

	return CMD_ERROR_NONE;
}

static int cmd_set_timeout(struct command_context *ctx) 
{
        if (ctx->argc != 2)
		return CMD_ERROR_SYNTAX;

	soft_timeout = atoi(ctx->argv[1]);

	return CMD_ERROR_NONE;
}


static int cmd_set_blcb(struct command_context *ctx)
{
	int ret;
	int8_t result;
	uint8_t bootok, multibootreg;

        if (ctx->argc != 3)
		return CMD_ERROR_SYNTAX;

	bootok = atoi(ctx->argv[1]);
	multibootreg = atoi(ctx->argv[2]);

	ret = soft_set_blcb(soft_node, soft_timeout, bootok, multibootreg, &result);
	if (ret < 0)
		return CMD_ERROR_FAIL;

	printf("Result: %d\r\n", result);
	return CMD_ERROR_NONE;
}

command_t exec_commands[] = {
        {
                .name = "exec",
                .help = "Execute command",
                .usage = "<pgrm> <name> [args]",
                .handler = cmd_exec,
        },
};


command_t soft_commands[] = {
	{
		.name = "cmd",
		.help = "Execute command on z7000",
		.chain = INIT_CHAIN(exec_commands),
	},{
                .name = "node",
                .help = "Set node",
                .usage = "<node>",
                .handler = cmd_set_node,
        },{
                .name = "timeout",
                .help = "Set timeout",
                .usage = "<timeout [ms]>",
                .handler = cmd_set_timeout,
        },{
                .name = "blcb",
                .help = "set boot loader control block",
		.usage = "<bootok> <multibootreg>",
                .handler = cmd_set_blcb,
        },
};

command_t __root_command soft_root_command[] = {
	{
		.name = "z7000",
		.help = "client: z7000",
		.chain = INIT_CHAIN(soft_commands),
	},
};

void soft_register_commands(void)
{
    command_register(soft_root_command);
}
