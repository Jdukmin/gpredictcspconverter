/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include "fp.h"

static const gs_command_t GS_COMMAND_SUB fp_commands[] = {
    {
        .name="server",
        .help="Setup CSP address of FP server",
        .usage="<server>",
        .mandatory_args=1,
        .handler=gs_fp_cmd_fp_server_handler,
    },
    {
        .name="flush",
        .help="Flush current FP",
        .mandatory_args=GS_COMMAND_NO_ARGS,
        .handler=gs_fp_cmd_fp_flush_handler,
    },
    {
        .name="load",
        .help="Load FP from file - Will Flush current FP",
        .usage="<path> [fast_load_with_unique_keys]",
        .mandatory_args=1,
        .optional_args=1,
        .handler=gs_fp_cmd_fp_load_handler,
    },
    {
        .name="store",
        .help="Store current FP to file",
        .usage="<path>",
        .mandatory_args=1,
        .handler=gs_fp_cmd_fp_store_handler,
    },
    {
        .name="create",
        .help="Create new timer",
        .usage="<timer> <[+]sec> <command> [repeat] [state]",
        .mandatory_args=3,
        .optional_args=2,
        .handler=gs_fp_cmd_fp_create_handler,
    },
    {
        .name="delete",
        .help="Delete timer",
        .usage="<timer>",
        .mandatory_args=1,
        .handler=gs_fp_cmd_fp_delete_handler,
    },
    {
        .name="active",
        .help="Set timer active",
        .usage="<timer>",
        .mandatory_args=1,
        .handler=gs_fp_cmd_fp_active_handler,
    },
    {
        .name="allactive",
        .help="Set all timers active",
        .mandatory_args=GS_COMMAND_NO_ARGS,
        .handler=gs_fp_cmd_fp_allactive_handler,
    },
    {
        .name="dormant",
        .help="Set timer dormant",
        .usage="<timer>",
        .mandatory_args=1,
        .handler=gs_fp_cmd_fp_dormant_handler,
    },
    {
        .name="repeat",
        .help="Set timer repeat",
        .usage="<timer> <count>",
        .mandatory_args=2,
        .handler=gs_fp_cmd_fp_repeat_handler,
    },
    {
        .name="time",
        .help="Set execution time",
        .usage="<timer> <[+]sec>",
        .mandatory_args=2,
        .handler=gs_fp_cmd_fp_time_handler,
    },
    {
        .name="list",
        .help="List timers",
        .mandatory_args=GS_COMMAND_NO_ARGS,
        .handler=gs_fp_cmd_fp_list_handler,
    },
};

static const gs_command_t GS_COMMAND_ROOT root_commands[] = {
    {
        .name="fp",
        .help="Flight Planner client",
        .chain=GS_COMMAND_INIT_CHAIN(fp_commands),
    },
};

gs_error_t gs_fp_register_commands(void)
{
    return GS_COMMAND_REGISTER(root_commands);
}
