/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#include <stdio.h>
#include <stdlib.h>

#include <gs/hk/client.h>
#include <gs/csp/csp.h>
#include <gs/csp/port.h>
#include <gs/util/clock.h>
#include <gs/util/time.h>
#include <gs/util/byteorder.h>

#define GS_HK_INTERNAL_USE 1
#include <gs/hk/internal/types.h>

gs_error_t gs_hk_request_beacons(uint8_t server,
                                 uint8_t beacon_type,
                                 uint32_t sample_interval,
                                 uint32_t sample_count,
                                 uint32_t newest_sample,
                                 const char* file_path) {

    return (gs_hk_request_beacons2(server,
                                   beacon_type,
                                   sample_interval,
                                   sample_count,
                                   newest_sample,
                                   file_path,
                                   GS_HK_REQUEST_PROTOCOL_V1));
}

gs_error_t gs_hk_request_beacons2(uint8_t server,
                                 uint8_t beacon_type,
                                 uint32_t sample_interval,
                                 uint32_t sample_count,
                                 uint32_t newest_sample,
                                 const char* file_path,
                                 uint8_t protocol_version)
{
    return (gs_hk_request_beacons3(server,
                                   beacon_type,
                                   sample_interval,
                                   sample_count,
                                   newest_sample,
                                   file_path,
                                   GS_HK_REQUEST_PROTOCOL_V1,
                                   GS_HK_REQUEST_BURST_BEACON_COUNT,
                                   GS_HK_REQUEST_BURST_IDLE_MSECS));
}

gs_error_t gs_hk_request_beacons3(uint8_t server,
                                  uint8_t beacon_type,
                                  uint32_t sample_interval,
                                  uint32_t sample_count,
                                  uint32_t newest_sample,
                                  const char* file_path,
                                  uint8_t protocol_version,
                                  uint16_t burst_size,
                                  uint16_t burst_idle_time) {
    if (protocol_version > 0) {
        gs_hk_housekeeping_request_t req;
        req.p_version = protocol_version;
        req.type = beacon_type;
        req.interval = util_hton32(sample_interval);
        req.path[0] = 0;
        if (file_path != NULL) {
            strncpy(req.path, file_path, GS_HK_REQUEST_BEACON_FILE_MAX_PATH_LENGTH);
            req.count = util_hton32(sample_count);
            req.t0 = util_hton32(newest_sample);
            return gs_csp_transaction(CSP_PRIO_NORM, server,
                                      GS_CSP_PORT_HK, 0,
                                      &req, sizeof(req), NULL, 0, NULL);
        }

        uint32_t first_sample_to_request = newest_sample;
        uint32_t remaining_samples = sample_count;
        while (remaining_samples > 0) {
            uint32_t samples_to_request = remaining_samples;
            if (samples_to_request > burst_size) {
                samples_to_request = burst_size;
            }

            req.count = util_hton32(samples_to_request);
            req.t0 = util_hton32(first_sample_to_request);
            gs_error_t res = gs_csp_transaction(CSP_PRIO_NORM, server,
                                                GS_CSP_PORT_HK, 0,
                                                &req, sizeof(req), NULL, 0, NULL);
            if (res != GS_OK) {
                return res;
            }

            // update first sample to request and remaining work
            first_sample_to_request -= sample_interval * samples_to_request;
            remaining_samples -= samples_to_request;

            /* wait burst_idle_time to avoid flooding a slow sender
               in the server end - e.g. the ax100 uhf radio */
            gs_time_sleep_ms(burst_idle_time);
        }
    } else {
        gs_hk_housekeeping_request_legacy_t req;
        req.type = beacon_type;
        req.interval = util_hton32(sample_interval);
        req.path[0] = 0;
        if (file_path != NULL) {
            strncpy(req.path, file_path, GS_HK_REQUEST_BEACON_FILE_MAX_PATH_LENGTH);
            req.count = util_hton32(sample_count);
            req.t0 = util_hton32(newest_sample);
            return gs_csp_transaction(CSP_PRIO_NORM, server,
                                      GS_CSP_PORT_HK, 0,
                                      &req, sizeof(req), NULL, 0, NULL);
        }

        uint32_t first_sample_to_request = newest_sample;
        uint32_t remaining_samples = sample_count;
        while (remaining_samples > 0) {
            uint32_t samples_to_request = remaining_samples;
            if (samples_to_request > burst_size) {
                samples_to_request = burst_size;
            }

            req.count = util_hton32(samples_to_request);
            req.t0 = util_hton32(first_sample_to_request);
            gs_error_t res = gs_csp_transaction(CSP_PRIO_NORM, server,
                                                GS_CSP_PORT_HK, 0,
                                                &req, sizeof(req), NULL, 0, NULL);
            if (res != GS_OK) {
                return res;
            }

            // update first sample to request and remaining work
            first_sample_to_request -= sample_interval * samples_to_request;
            remaining_samples -= samples_to_request;

            /* wait burst_idle_time to avoid flooding a slow sender
               in the server end - e.g. the ax100 uhf radio */
            gs_time_sleep_ms(burst_idle_time);
        }
    }
    return GS_OK;
}

gs_error_t gs_hk_request_reload(uint8_t server) {

    gs_hk_reload_request_t req;
    req.command = GS_HK_RELOAD_REQUEST;
    req.magic = GS_HK_RELOAD_MAGIC;
    return gs_csp_transaction(CSP_PRIO_NORM, server,
                              GS_CSP_PORT_HK, 0,
                              &req, sizeof(req), NULL, 0, NULL);
}
