/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#include <gs/gosh/remote/client.h>
#include <gs/util/gosh/command.h>
#include <gs/util/string.h>
#include <gs/csp/csp.h>
#include <stdio.h>
#include <stdlib.h>

static uint8_t remote_node = 255;
static unsigned int remote_timeout = 10000;

static uint8_t get_node(void)
{
    if (remote_node == 255) {
        return  csp_get_address();
    }
    return remote_node;
}

static int cmd_remote_node(struct command_context *ctx)
{
    if (ctx->argc > 1) {
        if (gs_string_to_uint8(ctx->argv[1], &remote_node)) {
            return GS_ERROR_ARG;
        }
    }

    fprintf(ctx->out, "%u\r\n", get_node());

    return GS_OK;
}

static int cmd_remote_run(struct command_context *ctx)
{
    return gs_gosh_remote_shell_stdio(get_node(), remote_timeout, true, gs_command_args(ctx), stdin, ctx->out);
}

static const gs_command_t GS_COMMAND_SUB gosh_remote_subcommands[] = {
    {
        .name = "node",
        .help = "Set or display remote node",
        .usage = "[node]",
        .handler = cmd_remote_node,
        .optional_args = 1
    },{
        .name = "run",
        .help = "Run command or shell",
        .usage = "<command> [arguments...]",
        .handler = cmd_remote_run,
        .mandatory_args = 1,
        .optional_args = 30,
    },
};

static const gs_command_t GS_COMMAND_ROOT gosh_remote_commands[] = {
    {
        .name = "shell",
        .help = "Remote shell client",
        .chain = GS_COMMAND_INIT_CHAIN(gosh_remote_subcommands),
    },
};

gs_error_t gs_gosh_remote_register_commands(void)
{
    return GS_COMMAND_REGISTER(gosh_remote_commands);
}
