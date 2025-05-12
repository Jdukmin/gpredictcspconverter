/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include "hk.h"

static const gs_command_t GS_COMMAND_SUB hk_commands[] = {
    {
        .name="server",
        .help="Setup CSP address of HK server.",
        .usage="<server> [burst_size] [burst_idle]",
        .mandatory_args=1,
        .optional_args=2,
        .handler=cmd_handler_hk_server,
    },
    {
        .name="get",
        .help="Request beacons from HK server.",
        .usage="<type> <interval> <samples> [t0] [path] [protocol_version]",
        .mandatory_args=3,
        .optional_args=3,
        .handler=cmd_handler_hk_get,
    },
    {
        .name="reload",
        .help="Ask server to reload its configuration from files.",
        .mandatory_args=GS_COMMAND_NO_ARGS,
        .handler=cmd_handler_hk_reload,
    },
};

static const gs_command_t GS_COMMAND_ROOT root_commands[] = {
    {
        .name="hk",
        .help="Housekeeping client",
        .chain=GS_COMMAND_INIT_CHAIN(hk_commands),
    },
};

gs_error_t gs_hk_register_commands(void)
{
    return GS_COMMAND_REGISTER(root_commands);
}
