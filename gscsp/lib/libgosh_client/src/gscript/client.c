/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#define GS_GOSH_GSCRIPT_INTERNAL_USE 1

#include <gs/gosh/internal/gscript.h>
#include <csp/csp_endian.h>
#include <gs/csp/csp.h>

gs_error_t gs_gscript_exec_remote(uint8_t node, const char * script, bool is_file, uint32_t when_utc, size_t stack_size, int priority)
{
    if (script == NULL) {
        return GS_ERROR_ARG;
    }

    // 1 is zero termination - currently the other end writes a zero termination, but it "assumes" the underlying
    // 'csp_buffer' is at least 1 byte larger than the data actually sent -> possible write out-of-bounds, causing crash.
    // This is not possible to fix from 'this end', instead we send the zero termination, so in time the other end can be fixed.
    const size_t SCRIPT_LENGTH = (strlen(script) + 1);

    gs_gscript_req_exec_t * req;
    const size_t PACKET_LENGTH = (sizeof(*req) + SCRIPT_LENGTH);

    // typically csp_buffers are 250 bytes or more - so we limit size of script to 'try' and compenstate for the others
    // forced zero termination.
    if (PACKET_LENGTH > 240) {
        return GS_ERROR_RANGE;
    }

    csp_packet_t * packet = csp_buffer_get(PACKET_LENGTH);
    if (packet == NULL) {
        return GS_ERROR_ALLOC;
    }

    req = (void *) packet->data;
    req->type = (is_file) ? GS_GSCRIPT_REQ_TYPE_EXEC_FILE : GS_GSCRIPT_REQ_TYPE_EXEC;
    req->priority = csp_hton16(priority);
    req->stack = csp_hton16(stack_size);
    req->when = csp_hton32(when_utc);
    strcpy(req->cmd, script);
    packet->length = PACKET_LENGTH;

    int error = csp_sendto(CSP_PRIO_HIGH, node, GS_CSP_PORT_GSCRIPT, 0, CSP_O_CRC32, packet, 0);
    if (error < 0) {
        csp_buffer_free(packet);
        return GS_ERROR_IO;
    }

    return GS_OK;
}

gs_error_t gs_gscript_stop_remote(uint8_t node)
{
    gs_gscript_req_stop_t req = { .type = GS_GSCRIPT_REQ_TYPE_STOP };
    return gs_csp_transaction(CSP_PRIO_HIGH, node, GS_CSP_PORT_GSCRIPT, 2000, &req, sizeof(req), NULL, 0, NULL);
}
