#ifndef LIB_LIBGSSB_CLIENT_INCLUDE_GS_GSSB_INTERNAL_RGSSB_H_
#define LIB_LIBGSSB_CLIENT_INCLUDE_GS_GSSB_INTERNAL_RGSSB_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Only for internal use

   Contains types for the rgssb protocol.
*/

#if (GS_GSSB_INTERNAL_USE)
/**
   Protocol version
 */
#define GS_RGSSB_PROTOCOL_VERSION   10   // Version 1.0

/**
   Protocol data MTU
 */
#define GS_RGSSB_MAX_DATA_LENGTH    32

/**
   RGSSB CSP Port
 */
#define GS_GSSB_PORT                16

/**
   RGSSB command
 */
typedef struct __attribute__((__packed__)) rgssb_cmd_t {
    /**
       Protocol version
     */
    uint8_t prot_version;
    /**
       Address of GSSB device
     */
    uint8_t i2c_addr;
    /**
       Timeout for server on I2C comm
     */
    uint16_t i2c_timeout_ms;
    /**
       Command ID-code
     */
    uint16_t cmd_id;
    /**
       Length of data
     */
    uint8_t data_length;
    /**
       For future use
     */
    uint8_t flags;
    /**
       Data buffer
     */
    uint8_t data[GS_RGSSB_MAX_DATA_LENGTH];
} gs_rgssb_cmd_t;

/**
   RGSSB protocol command header size
 */
#define GS_RGSSB_CMD_HEADER_SIZE (sizeof(gs_rgssb_cmd_t) - GS_RGSSB_MAX_DATA_LENGTH)

typedef struct __attribute__((__packed__)) rgssb_resp_t {
    /**
       Protocol version
     */
    uint8_t prot_version;
    /**
       Length of data
     */
    uint8_t data_length;
    /**
       Command ID-code
     */
    uint16_t cmd_id;
    /**
       gs_error code from I2C comm
     */
    int32_t i2c_error;
    /**
       Response data
     */
    uint8_t data [GS_RGSSB_MAX_DATA_LENGTH];
} gs_rgssb_resp_t;

/**
   RGSSB protocol respons header size
 */
#define GS_RGSSB_RESP_HEADER_SIZE (sizeof(gs_rgssb_resp_t) - GS_RGSSB_MAX_DATA_LENGTH)

#endif
#endif /* LIB_LIBGSSB_CLIENT_INCLUDE_GS_GSSB_INTERNAL_RGSSB_H_ */
