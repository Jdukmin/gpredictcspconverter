/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <csp/csp.h>
#include <csp/csp_endian.h>

#include <gs/csp/port.h>
#include <gs/util/clock.h>
#include <gs/util/gosh/command.h>
#include <gs/util/minmax.h>
#include <gs/hk/client.h>
#include "hk.h"

#define GS_HK_INTERNAL_USE 1
#include <gs/hk/internal/types.h>

static uint8_t node = 1;
static uint16_t burst_size = GS_HK_REQUEST_BURST_BEACON_COUNT;
static uint16_t burst_idle_time = GS_HK_REQUEST_BURST_IDLE_MSECS;

gs_error_t cmd_handler_hk_reload(gs_command_context_t *ctx)
{
    return gs_hk_request_reload(node);
}

gs_error_t cmd_handler_hk_server(gs_command_context_t *ctx)
{
    if (gs_string_to_uint8(ctx->argv[1], &node)) {
        return GS_ERROR_ARG;
    }

    if (ctx->argc > 2) {
        if (gs_string_to_uint16(ctx->argv[2], &burst_size)) {
            return GS_ERROR_ARG;
        }
    }

    if (ctx->argc > 3) {
        if (gs_string_to_uint16(ctx->argv[3], &burst_idle_time)) {
            return GS_ERROR_ARG;
        }
    }

    return GS_OK;
}

gs_error_t cmd_handler_hk_get(gs_command_context_t *ctx)
{
    uint32_t interval;
    if (gs_string_to_uint32(ctx->argv[2], &interval)) {
        return GS_ERROR_ARG;
    }

    uint32_t samples;
    if (gs_string_to_uint32(ctx->argv[3], &samples)) {
        return GS_ERROR_ARG;
    }

    int32_t t0 = GS_HK_REQUEST_BEACON_FIRST_SAMPLE_NOW;
    if (ctx->argc > 4) {
        if (gs_string_to_int32(ctx->argv[4], &t0)) {
            return GS_ERROR_ARG;
        }
    }

    gs_timestamp_t now;
    gs_clock_get_time(&now);
    if (t0 < 0) {
        /* a negative t0 is intepreted as now-t0 */
        t0 = now.tv_sec + t0;
        t0 = gs_max(t0, 0);
    } else if (t0 == 0) {
        t0 = now.tv_sec;
    }

    const char* file_path = NULL;
    if (ctx->argc > 5) {
        file_path = ctx->argv[5];
    }

    uint8_t protocol_version = GS_HK_REQUEST_PROTOCOL_V1;
    if (ctx->argc > 6) {
        if (gs_string_to_uint8(ctx->argv[6], &protocol_version)) {
            return GS_ERROR_ARG;
        }
    }

    // attempt to handle type argument as a list of types, 1,2,3
    char* tmp = NULL;
    char workbuf[strlen(ctx->argv[1]) + 1];
    strcpy(workbuf, ctx->argv[1]);
    char* type_string = strtok_r(workbuf, ",", &tmp);
    while (type_string != NULL) {
        fprintf(ctx->out, "type_string: %s\n", type_string);
        gs_error_t res = gs_hk_request_beacons3(node, atoi(type_string),
                                               interval, samples,
                                                t0, file_path, protocol_version,
                                                burst_size, burst_idle_time);
        if (res != GS_OK) {
            return res;
        }
        type_string = strtok_r(NULL, ",", &tmp);
    }

    return GS_OK;
}
