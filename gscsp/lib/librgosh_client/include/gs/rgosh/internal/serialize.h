#ifndef GS_RGOSH_INTERNAL_SERIALIZE_H
#define GS_RGOSH_INTERNAL_SERIALIZE_H
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file
   Internal API for Remote GOSH serialization

   This API is used for serializing and de-serialization of RGOSH
   protocol messages.

   @note
   This API should not be used directly by 3rd parties as this is an
   internal API and breaking changes might be introduced by Gomspace
   without notice.
*/

#include <gs/util/error.h>
#include "proto/gosh.pb.h"

#ifdef __cplusplus
extern "C" {
#endif

/** RGOSH MTU Max Payload Size: Needs to fit in AX100 reduced packet payload size. */
#define GS_RGOSH_MTU_SIZE       180

/**
    Serialize a GoshRequest according to the RGOSH protocol

    @param[in] req        Remote Gosh response struct
    @param[in] buf        Buffer to serialize the response to
    @param[out] buf_size  Input size of the buffer and output size of response
    @return gs_error_t
 */
gs_error_t gs_rgosh_serialize_request(GoshRequest *req,
                                      uint8_t *buf,
                                      uint32_t *buf_size);

/**
    Serialize a GoshResponse according to the RGOSH protocol

    @param[in] resp       Remote Gosh response struct
    @param[in] buf        Buffer to serialize the response to
    @param[out] buf_size  Input size of the buffer and output size of response
    @return gs_error_t
 */
gs_error_t gs_rgosh_serialize_response(GoshResponse *resp,
                                       uint8_t *buf,
                                       uint32_t *buf_size);

/**
    De-Serialize a GoshRequest according to the RGOSH protocol

    @param[in] buf        Buffer to de-serialize the req. from
    @param[in] buf_size   Input size of the buffer
    @param[out] req       Remote Gosh request struct
    @return gs_error_t
 */
gs_error_t gs_rgosh_deserialize_request(uint8_t *buf,
                                        uint32_t buf_size,
                                        GoshRequest *req);

/**
    De-Serialize a GoshResponse according to the RGOSH protocol

    @param[in] buf        Buffer to de-serialize the resp from
    @param[in] buf_size   Input size of the buffer
    @param[out] resp      Remote Gosh response struct
    @return gs_error_t
 */
gs_error_t gs_rgosh_deserialize_response(uint8_t *buf,
                                         uint32_t buf_size,
                                         GoshResponse *resp);

#ifdef __cplusplus
}
#endif
#endif
