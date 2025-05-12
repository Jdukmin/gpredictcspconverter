/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <gs/rgosh/rgosh.h>

#include <stdio.h>
#include <stdlib.h>

#include <gs/util/stdio.h>
#include <gs/util/gosh/command.h>
#include <gs/csp/port.h>

#define DEFAULT_TIMEOUT     30000

static uint8_t g_rgosh_server = 0;

static void rgosh_run_cmd_result(void * ctx, const char * group, const char * key, const char * value)
{
    gs_command_set_output(ctx, group, key, value);
}

static void rgosh_run_cmd_stdout(void * ctx, const char * out)
{
    gs_command_context_t * cmd_ctx = (gs_command_context_t*)ctx;
    fprintf(cmd_ctx->out, "%s", out);
}

static const gs_rgosh_run_if_t rgosh_run_if = {
    .result_cb = rgosh_run_cmd_result,
    .stdout_cb = rgosh_run_cmd_stdout
};

static int cmd_rgosh_run_cmd(gs_command_context_t * context)
{
    gs_error_t ret_code;
    gs_error_t err = gs_rgosh_run_command(g_rgosh_server, GS_CSP_PORT_RGOSH, context->argv[1], DEFAULT_TIMEOUT, &ret_code, &rgosh_run_if, context);
    if (err == GS_OK) {
        err = ret_code;
    }
    return err;
}

static int cmd_rgosh_server(gs_command_context_t * context)
{
    if (context->argc > 1) {
        if (gs_string_to_uint8(context->argv[1], &g_rgosh_server)) {
            return GS_ERROR_ARG;
        }
    }
    fprintf(context->out, "server: %d (port: %d)\r\n", g_rgosh_server, GS_CSP_PORT_RGOSH);
    return GS_OK;
}

static const gs_command_t rgosh_commands[] = {
    {
        .name = "run",
        .help = "Run command on remote server",
        .usage = "<command [arg] ...>",
        .handler = cmd_rgosh_run_cmd,
        .mandatory_args = 1,
    },{
        .name = "server",
        .help = "Setup CSP address of RGOSH server",
        .usage = "[address]",
        .handler = cmd_rgosh_server,
        .optional_args = 1,
    }
};

static const gs_command_t GS_COMMAND_ROOT rgosh_root_command[] = {
    {
        .name = "rgosh",
        .help = "Command client",
        .chain = GS_COMMAND_INIT_CHAIN(rgosh_commands),
    },
};

gs_error_t gs_rgosh_register_commands(void)
{
    gs_rgosh_init();

    return GS_COMMAND_REGISTER(rgosh_root_command);
}
