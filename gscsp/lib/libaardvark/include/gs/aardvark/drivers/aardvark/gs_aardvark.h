/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */
#ifndef _GS_AARDVARK_DRIVERS_AARDVARK_GS_AARDVARK_H_
#define _GS_AARDVARK_DRIVERS_AARDVARK_GS_AARDVARK_H_
/**
   @file

   Convenience API for accessing Aardvark adapters.
*/

#include <gs/aardvark/drivers/aardvark/aardvark.h>
#include <gs/util/stdio.h>

/**
   Convert Aardvark status/error to #gs_error_t.

   @param[in] status Aardvark status/error code.
   @return Best possible matching #gs_error_t error code.
*/
gs_error_t gs_aardvark_status_to_error(enum AardvarkStatus status);

/**
   Handle for an Aardvark adapter.
*/
typedef struct {
    /**
       Adapters port number - set by gs_aardvark_open_device().
    */
    uint16_t port;
    /**
       Adapters unique id - set by gs_aardvark_open_device().
    */
    uint32_t unique_id;
    /**
       Aardvark handle.
    */
    Aardvark handle;
    /**
       Extended Aardvark information.
    */
    AardvarkExt aa_ext;
} gs_aardvark_handle_t;

/**
   Open Aardvark adapter.

   @param[in] unique_id od of the adapter to open. Use 0 (zero) for any device.
   @param[out] handle opened handle.
   @return_gs_error_t
*/
gs_error_t gs_aardvark_open_device(uint32_t unique_id, gs_aardvark_handle_t * handle);

/**
   List all Aardvark adapters.

   @param[in] out output stream, e.g. stdout.
   @return_gs_error_t
*/
gs_error_t gs_aardvark_list_devices(FILE * out);

#endif
