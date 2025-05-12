#if (GS_HK_INTERNAL_USE)
#ifndef GS_HK_TYPES_H
#define GS_HK_TYPES_H
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Protocol between client and server - message for
   requesting housekeeping/telemetry.

   @note Do not create this message manually, use the API in client.h instead.
   @warning Content of this file might be changed without notice.
*/

#include <stdint.h>
#include <gs/hk/client.h>

#define GS_HK_REQUEST_PROTOCOL_V1  0x01
#define GS_HK_REQUEST_PROTOCOL_MAX 0x10

typedef struct __attribute__((__packed__)) {

    /**
     * Protocol version - should always be GS_HK_REQUEST_PROTOCOL_V1
     */
    uint8_t p_version;

    /**
     * Type of beacon to request.
     */
    uint8_t type;

    /**
     * Time of newest sample.
     */
    uint32_t t0;

    /**
     * Sample interval.
     */
    uint32_t interval;

    /**
     * Number of samples requested.
     */
    uint32_t count;

    /**
     * File to write beacon data to - if 0 beacons will be tx'ed instead.
     */
    char path[GS_HK_REQUEST_BEACON_FILE_MAX_PATH_LENGTH];
} gs_hk_housekeeping_request_t;

/*Legacy command for communication with libhk3 (makes it possible to use the new client with legacy components)*/
typedef struct __attribute__((__packed__)) {

    /**
     * Type of beacon to request.
     */
    uint8_t type;

    /**
     * Time of newest sample.
     */
    uint32_t t0;

    /**
     * Sample interval.
     */
    uint32_t interval;

    /**
     * Number of samples requested.
     */
    uint32_t count;

    /**
     * File to write beacon data to - if 0 beacons will be tx'ed instead.
     */
    char path[GS_HK_REQUEST_BEACON_FILE_MAX_PATH_LENGTH];
} gs_hk_housekeeping_request_legacy_t;

#define GS_HK_RELOAD_REQUEST GS_HK_REQUEST_PROTOCOL_MAX + 1
#define GS_HK_RELOAD_MAGIC 0x42
typedef struct __attribute__((__packed__)) {
    uint8_t command;
    uint8_t magic;
} gs_hk_reload_request_t;


#endif /* GS_HK_TYPES_H */
#endif /* GS_HK_INTERNAL_USE */
