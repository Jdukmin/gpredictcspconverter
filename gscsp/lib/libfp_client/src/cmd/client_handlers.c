/* Copyright (c) 2013-2020 GomSpace A/S. All rights reserved. */

#include <gs/csp/port.h>
#include <gs/fp/fp_client.h>

#define GS_FP_INTERNAL_USE 1
#include "gs/fp/internal/types.h"

#include "fp.h"
#include <gs/util/error.h>
#include <gs/util/gosh/command.h>
#include <gs/util/timestamp.h>
#include <gs/util/clock.h>
#include <gs/util/stdio.h>
#include <csp/csp.h>
#include <csp/csp_endian.h>
#include <stdlib.h>

int gs_fp_cmd_fp_server_handler(gs_command_context_t *ctx)
{
    uint8_t server;
    if (gs_string_to_uint8(ctx->argv[1], &server) != GS_OK) {
        return GS_ERROR_ARG;
    }

    return fp_client_host(server);
}

int gs_fp_cmd_fp_load_handler(gs_command_context_t *ctx)
{
    bool fast_load_with_unique_keys = false;
    // Path too long
    if (strnlen(ctx->argv[1], FP_MAX_PATH_LENGTH) == FP_MAX_PATH_LENGTH) {
        return GS_ERROR_ARG;
    }

    char path[FP_MAX_PATH_LENGTH];
    strncpy(path, ctx->argv[1], FP_MAX_PATH_LENGTH - 1);
    path[FP_MAX_PATH_LENGTH - 1] = '\0';
    if (ctx->argc > 2) {
        if (gs_string_to_bool(ctx->argv[2], &fast_load_with_unique_keys) != GS_OK) {
            return GS_ERROR_ARG;
        }
    }
    return fp_client_fp_load(path, fast_load_with_unique_keys);
}

int gs_fp_cmd_fp_store_handler(gs_command_context_t *ctx)
{
    // Path too long
    if (strnlen(ctx->argv[1], FP_MAX_PATH_LENGTH) == FP_MAX_PATH_LENGTH) {
        return GS_ERROR_ARG;
    }

    char path[FP_MAX_PATH_LENGTH];
    strcpy(path, ctx->argv[1]);

    return fp_client_fp_store(path);
}

int gs_fp_cmd_fp_flush_handler(gs_command_context_t *ctx)
{
    return fp_client_fp_flush();
}

int gs_fp_cmd_fp_create_handler(gs_command_context_t *ctx)
{
    const char *timer = ctx->argv[1];
    const char *when = ctx->argv[2];
    const char *cmd = ctx->argv[3];

    // Check if key or command is too long
    if ((strnlen(timer, FP_KEY_SIZE) == FP_KEY_SIZE) || (strnlen(cmd, FP_CMD_SIZE) == FP_CMD_SIZE)) {
        return GS_ERROR_ARG;
    }

    uint16_t repeat = 1;
    if (ctx->argc > 4) {
        if (gs_string_to_uint16(ctx->argv[4], &repeat) != GS_OK) {
            return GS_ERROR_ARG;
        }
    }

    fp_timer_state_t s = FP_TIME_ACTIVE;
    if (ctx->argc > 5) {
        if (!strcmp(ctx->argv[5], "active")) {
            s = FP_TIME_ACTIVE;
        } else if (!strcmp(ctx->argv[5], "dormant")) {
            s = FP_TIME_DORMANT;
        } else {
            return GS_ERROR_ARG;
        }
    }

    fp_timer_basis_t b;

    gs_error_t error;
    uint32_t sec;
    if (when[0] == '+') {
        b = FP_TIME_RELATIVE;
        error = gs_string_to_uint32((when + 1), &sec);
    } else {
        b = FP_TIME_ABSOLUTE;
        error = gs_string_to_uint32((when), &sec);
    }

    if (error != GS_OK) {
        return GS_ERROR_ARG;
    }

    gs_timestamp_t t;
    t.tv_sec = sec;
    t.tv_nsec = 0;

    return fp_client_timer_create(timer, cmd, b, s, &t, repeat);
}

int gs_fp_cmd_fp_delete_handler(gs_command_context_t *ctx)
{
    const char *timer = ctx->argv[1];
    if (strnlen(timer, FP_KEY_SIZE) == FP_KEY_SIZE) {
        return GS_ERROR_ARG;
    }

    return fp_client_timer_delete(timer);
}

int gs_fp_cmd_fp_active_handler(gs_command_context_t *ctx)
{
    const char *timer = ctx->argv[1];
    if (strnlen(timer, FP_KEY_SIZE) == FP_KEY_SIZE) {
        return GS_ERROR_ARG;
    }

    return fp_client_timer_set_active(timer);
}

int gs_fp_cmd_fp_allactive_handler(gs_command_context_t *ctx)
{
    return fp_client_timer_set_all_active();
}

int gs_fp_cmd_fp_dormant_handler(gs_command_context_t *ctx)
{
    const char *timer = ctx->argv[1];
    if (strnlen(timer, FP_KEY_SIZE) == FP_KEY_SIZE) {
        return GS_ERROR_ARG;
    }

    return fp_client_timer_set_dormant(timer);
}

int gs_fp_cmd_fp_repeat_handler(gs_command_context_t *ctx)
{
    const char *timer = ctx->argv[1];
    if (strnlen(timer, FP_KEY_SIZE) == FP_KEY_SIZE) {
        return GS_ERROR_ARG;
    }

    uint16_t count;
    if (gs_string_to_uint16(ctx->argv[2], &count) != GS_OK) {
        return GS_ERROR_ARG;
    }

    return fp_client_timer_set_repeat(timer, count);
}

int gs_fp_cmd_fp_time_handler(gs_command_context_t *ctx)
{
    const char *timer = ctx->argv[1];
    if (strnlen(timer, FP_KEY_SIZE) == FP_KEY_SIZE) {
        return GS_ERROR_ARG;
    }

    const char *when = ctx->argv[2];

    fp_timer_basis_t b;

    uint32_t sec;
    gs_error_t error;
    if (when[0] == '+') {
        b = FP_TIME_RELATIVE;
        error = gs_string_to_uint32((when + 1), &sec);
    } else {
        b = FP_TIME_ABSOLUTE;
        error = gs_string_to_uint32((when), &sec);
    }

    if (error != GS_OK) {
        return GS_ERROR_ARG;
    }

    gs_timestamp_t t;
    t.tv_sec = sec;
    t.tv_nsec = 0;

    return fp_client_timer_set_time(timer, b, &t);
}

int gs_fp_cmd_fp_list_handler(gs_command_context_t *ctx)
{
    return fp_client_timer_list(ctx);
}
