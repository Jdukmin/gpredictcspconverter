/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <gs/rgosh/rgosh.h>
#include <gs/util/check.h>
#include <gs/csp/csp.h>
#include <csp/arch/csp_malloc.h>
#include <gs/rgosh/internal/serialize.h>
#include <gs/rgosh/internal/rgosh_log.h>
#include "proto/gosh.pb.h"

#include <pb_encode.h>

#if (CSP_USE_RDP)
#define USE_RDP_TRANSPORT   CSP_O_RDP
#else
#define USE_RDP_TRANSPORT   CSP_O_NONE
#endif

/* create the log group - just once for all RGOSH client/server files */
GS_LOG_GROUP(gs_rgosh_log, "rgosh", GS_LOG_CAT_DEFAULT, LOG_DEFAULT_MASK);

gs_error_t gs_rgosh_init(void)
{
    return gs_log_group_register(LOG_DEFAULT);
}

static gs_error_t rgosh_run_command(uint8_t node, uint8_t port, const char * command, uint32_t timeout_ms,
                                    gs_error_t *return_code, const gs_rgosh_run_if_t *cb_if, void* cb_ctx)
{
    csp_conn_t * conn;
    GoshRequest req = GoshRequest_init_default;
    req.id = 11;
    req.which_command = GoshRequest_run_tag;
    strncpy(req.command.run.command, command, strnlen(command, sizeof(req.command.run.command)));

    uint8_t cmd_buffer[GoshRequest_size];
    uint32_t encoded_size = sizeof(cmd_buffer);
    if (gs_rgosh_serialize_request(&req, cmd_buffer, &encoded_size) != GS_OK) {
        return GS_ERROR_DATA;
    }

    conn = csp_connect(CSP_PRIO_HIGH, node, port, timeout_ms, CSP_O_CRC32 | USE_RDP_TRANSPORT);
    if (conn == NULL) {
        return GS_ERROR_IO;
    }

    if (csp_sfp_send(conn, cmd_buffer, encoded_size, GS_RGOSH_MTU_SIZE, timeout_ms) != 0) {
        csp_close(conn);
        return GS_ERROR_TIMEOUT;
    }

    bool more_data = true;
    gs_error_t err = GS_OK;
    do {
        void *data_ptr = NULL;
        int data_size = 0;
        if (csp_sfp_recv(conn, &data_ptr, &data_size, timeout_ms) != 0) {
            err = GS_ERROR_TIMEOUT;
            break;
        }

        GoshResponse resp;
        if (gs_rgosh_deserialize_response(data_ptr, data_size, &resp) != GS_OK) {
            err = GS_ERROR_DATA;
            break;
        }

        csp_free(data_ptr);

        if ((resp.id != req.id) || (resp.which_response != GoshResponse_command_tag)) {
            err = GS_ERROR_DATA;
            break;
        }

        CommandResponse *cmd_resp = &resp.response.command;

        /* Last response message */
        if (cmd_resp->completion_flag == true) {
            more_data = false;
        }
        *return_code = cmd_resp->return_code;

        if (cb_if) {
            if (cb_if->result_cb != NULL) {
                for (unsigned int i=0; i < cmd_resp->results_count; i++) {
                    cb_if->result_cb(cb_ctx, cmd_resp->results[i].group, cmd_resp->results[i].key, cmd_resp->results[i].value);
                }
            }
            if (cb_if->stdout_cb != NULL && cmd_resp->has_std_out) {
                cb_if->stdout_cb(cb_ctx, cmd_resp->std_out);
            }
        }
    } while (more_data);

    csp_close(conn);
    return err;
}

gs_error_t gs_rgosh_run_command(uint8_t node, uint8_t port, const char * command, uint32_t timeout_ms,
                                gs_error_t *return_code, const gs_rgosh_run_if_t *cb_if, void* cb_ctx)
{
    log_debug("client -> node: %u:%u, timeout: %"PRIu32", command: <%s>", node, port, timeout_ms, command);

    gs_error_t command_error = GS_ERROR_UNKNOWN;
    gs_error_t error = rgosh_run_command(node, port, command, timeout_ms, &command_error, cb_if, cb_ctx);

    log_debug("client <- node: %u:%u, framework error: %d(%s), command error: %d(%s)",
              node, port, error, gs_error_string(error), command_error, gs_error_string(command_error));

    if (return_code) {
        *return_code = command_error;
    }

    return error;
}
