#ifndef GS_HK_CLIENT_H
#define GS_HK_CLIENT_H
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Client interface for the Housekeeping system.
*/

#include <stdint.h>
#include <gs/util/error.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Max beacon file path.
*/
#define GS_HK_REQUEST_BEACON_FILE_MAX_PATH_LENGTH 50

/**
   First beacon sample now.
*/
#define GS_HK_REQUEST_BEACON_FIRST_SAMPLE_NOW 0

/**
   Max beacon burst.
*/
#define GS_HK_REQUEST_BURST_BEACON_COUNT 10

/**
   Idle time between beacon bursts.
*/
#define GS_HK_REQUEST_BURST_IDLE_MSECS 1000

/**
   Create and send a request for beacons.

   @param[in] server housekeeping server to request beacons from
   @param[in] beacon_type the beacon type to request
   @param[in] sample_interval sample interval
   @param[in] sample_count number of samples to request
   @param[in] newest_sample UNIX timestamp of the newest sample to request
   @param[in] file_path if not NULL requested beacons will be written to a local file on the server instead of being send using CSP.
   @return_gs_error_t
*/
gs_error_t gs_hk_request_beacons(uint8_t server,
                                 uint8_t beacon_type,
                                 uint32_t sample_interval,
                                 uint32_t sample_count,
                                 uint32_t newest_sample,
                                 const char* file_path);

/**
   Create and send a request for beacons.

   @param[in] server housekeeping server to request beacons from
   @param[in] beacon_type the beacon type to request
   @param[in] sample_interval sample interval
   @param[in] sample_count number of samples to request
   @param[in] newest_sample UNIX timestamp of the newest sample to request
   @param[in] file_path if not NULL requested beacons will be written to a local file on the server instead of being send using CSP.
   @param[in] protocol_version (GS_HK_REQUEST_PROTOCOL_XX) if version is 0 a legacy request command is sent (for LibHK3)
   @return_gs_error_t
*/
gs_error_t gs_hk_request_beacons2(uint8_t server,
                                 uint8_t beacon_type,
                                 uint32_t sample_interval,
                                 uint32_t sample_count,
                                 uint32_t newest_sample,
                                 const char* file_path,
                                 uint8_t protocol_version);

 /**
   Create and send a request for beacons.

   @param[in] server housekeeping server to request beacons from
   @param[in] beacon_type the beacon type to request
   @param[in] sample_interval sample interval
   @param[in] sample_count number of samples to request
   @param[in] newest_sample UNIX timestamp of the newest sample to request
   @param[in] file_path if not NULL requested beacons will be written to a local file on the server instead of being send using CSP.
   @param[in] protocol_version (GS_HK_REQUEST_PROTOCOL_XX) if version is 0 a legacy request command is sent (for LibHK3)
   @param[in] burst_size number of requests to send before sleeping for burst_idle_time msecs.
   @param[in] burst_idle_time number of msecs to sleep between request bursts.

   @return_gs_error_t
*/
gs_error_t gs_hk_request_beacons3(uint8_t server,
                                  uint8_t beacon_type,
                                  uint32_t sample_interval,
                                  uint32_t sample_count,
                                  uint32_t newest_sample,
                                  const char* file_path,
                                  uint8_t protocol_version,
                                  uint16_t burst_size,
                                  uint16_t burst_idle_time);


/**
   Request server to reload its configuration.

   @param[in] server housekeeping server to request re-loading configuration.
   @return_gs_error_t
*/
gs_error_t gs_hk_request_reload(uint8_t server);

/**
   Register client commands into the command system.

   @return_gs_error_t
*/
gs_error_t gs_hk_register_commands(void);

#ifdef __cplusplus
}
#endif
#endif
