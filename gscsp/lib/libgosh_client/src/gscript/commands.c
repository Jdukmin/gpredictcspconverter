/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#include <gs/gosh/gscript/client.h>
#include <stdlib.h>
#include <stdio.h>
#include <csp/csp_endian.h>
#include <gs/util/gosh/command.h>
#include <gs/util/clock.h>
#include <gs/util/string.h>
#include <gs/csp/csp.h>

#define CONTROL(X)  ((X) - '@')

#define LEGACY_STACK_SIZE 4000 // FreeRTOS size, not bytes
#define LEGACY_PRIORITY   1    // FreeRTOS priority -> GS_THREAD_PRIORITY_LOW

static int node = -1;

static int get_node(void)
{
    if (node < 0) {
        return csp_get_address();
    }
    return node;
}

static bool parse_when(const char * in, int * return_when)
{
    if ((in == NULL) || (in[0] == 0)) {
        return false;
    }

    // try utc timestamp
    gs_timestamp_t ts;
    if (gs_clock_from_string(in, &ts) == GS_OK) {
        *return_when = ts.tv_sec;
        return true;
    }

    bool relative = false;
    if (in[0] == '+') {
        relative = true;
        ++in;
    }

    int32_t value;
    if (gs_string_to_int32(in, &value) == GS_OK) {
        if (relative) {
            gs_clock_get_time(&ts);
            value += ts.tv_sec;
        }
        *return_when = value;
        return true;
    }
    return false;
}

static int gscript_cmd_run_file(struct command_context * ctx)
{
    const char * file = ctx->argv[1];

    int when = 0;
    if (ctx->argc > 2) {
        if (!parse_when(ctx->argv[2], &when)) {
            return GS_ERROR_ARG;
        }
    }

    return gs_gscript_exec_remote(get_node(), file, true, when, LEGACY_STACK_SIZE, LEGACY_PRIORITY);
}

static int gscript_cmd_run_shell(struct command_context * ctx)
{
    int when = 0;
    char when_str[30] = "";
    if (ctx->argc > 1) {
        GS_STRNCPY(when_str, ctx->argv[1]);
        if (!parse_when(when_str, &when)) {
            return GS_ERROR_ARG;
        }
    }

    char c;
    int quit = 0;
    int execute = 0;
    int count = 0;
    int max_count = 100;
    char * cmd = calloc(1, max_count);
    if (cmd == NULL) {
        return GS_ERROR_ALLOC;
    }

    printf("Gscript syntax: <delay mS> <retry> <err_goto line> <cmd>\r\n");
    printf("Type each command followed by enter, hit ctrl+e to end typing, ctrl+x to cancel:\r\n");

    /* Wait for ^q to quit. */
    while (quit == 0) {

        /* Get character */
        c = getchar();

        switch (c) {

            /* CTRL + X */
            case 0x18:
                quit = 1;
                break;

		/* CTRL + E */
            case 0x05:
                execute = 1;
                quit = 1;
                break;

		/* Backspace */
            case CONTROL('H'):
            case 0x7f:
                if (count > 0) {
                    putchar('\b');
                    putchar(' ');
                    putchar('\b');
                    count--;
                }
                break;

            case '\r':
                putchar('\r');
                c = '\n';
                // fallthrough - deliberate
            default:
                putchar(c);

                if (count + 1 == max_count) {
                    max_count += 100;
                    char * tmp_cmd = realloc(cmd, max_count);
                    if (tmp_cmd == NULL) {
                        free(cmd);
                        return GS_ERROR_ALLOC;
                    }
                    cmd = tmp_cmd;
                }

                if (count < max_count)
                    cmd[count++] = c;

                break;
        }
    }

    if (!execute) {
        free(cmd);
        return GS_OK;
    }

    // parse when again, in case it is relative time
    parse_when(when_str, &when);

    return gs_gscript_exec_remote(get_node(), cmd, false, when, LEGACY_STACK_SIZE, LEGACY_PRIORITY);
}

static int gscript_run_now(struct command_context * ctx)
{
    uint8_t local_node;
    if (gs_string_to_uint8(ctx->argv[1], &local_node)) {
        return GS_ERROR_ARG;
    }

    const size_t MAX_CMD_LENGTH = 200;
    char cmd[MAX_CMD_LENGTH];
    strcpy(cmd, "0 0 0");
    for (int i = 2; i < ctx->argc; i++) {
        if ((strlen(cmd) + strlen(ctx->argv[i]) + 2) >= MAX_CMD_LENGTH) {
            printf("Command exceeds package size - can't serialize command\r\n");
            return GS_ERROR_OVERFLOW;
        }
        strcat(cmd, " ");
        strcat(cmd, ctx->argv[i]);
    }

    printf("Gscript run now: '%s'\r\n", cmd);

    return gs_gscript_exec_remote(local_node, cmd, false, 0, LEGACY_STACK_SIZE, LEGACY_PRIORITY);
}

static int gscript_cmd_stop(struct command_context * ctx)
{
    int local_node = get_node();
    if (ctx->argc > 1) {
        local_node = atoi(ctx->argv[1]);
    }

    return gs_gscript_stop_remote(local_node);
}

static int gscript_cmd_server(struct command_context * ctx)
{
    if (ctx->argc > 1) {
        node = atoi(ctx->argv[1]);
    }

    fprintf(ctx->out, "node: %d (port: %u)\r\n", get_node(), GS_CSP_PORT_GSCRIPT);

    return GS_OK;
}

static const gs_command_t GS_COMMAND_SUB gscript_exec_commands[] = {
    {
        .name = "run_shell",
        .usage = "[when utc]",
        .help = "Run gscript written in shell",
        .handler = gscript_cmd_run_shell,
        .optional_args = 1,
    },{
        .name = "run",
        .usage = "<filename> [when utc]",
        .help = "Run gscript from file",
        .handler = gscript_cmd_run_file,
        .mandatory_args = 1,
        .optional_args = 1,
    },{
        .name = "stop",
        .usage = "[node]",
        .help = "Stop all gscript(s) on the node",
        .handler = gscript_cmd_stop,
        .optional_args = 1,
    },{
        .name = "server",
        .usage = "[node]",
        .help = "Set gscript server",
        .handler = gscript_cmd_server,
        .optional_args = 1,
    },{
        .name = "run_now",
        .usage = "<node> <command> [arguments]",
        .help = "Run single <command> on <node> now",
        .handler = gscript_run_now,
        .mandatory_args = 2,
        .optional_args = 30,
    }
};

static const gs_command_t GS_COMMAND_ROOT gscript_root_commands[] = {
    {
        .name = "gscript",
        .help = "G-script client",
        .chain = GS_COMMAND_INIT_CHAIN(gscript_exec_commands),
    }
};

gs_error_t gs_gscript_register_commands(void)
{
    return GS_COMMAND_REGISTER(gscript_root_commands);
}
