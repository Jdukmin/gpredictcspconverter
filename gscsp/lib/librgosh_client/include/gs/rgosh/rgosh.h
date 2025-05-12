#ifndef GS_GOSH_REMOTE_H
#define GS_GOSH_REMOTE_H
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file
   Remote GOSH API
*/

#include <gs/util/error.h>
#include <gs/util/timestamp.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Initialize rgosh.

   @version 1.0.2
   @return_gs_error_t
*/
gs_error_t gs_rgosh_init(void);

/**
   RGOSH callback function for capturing results.

   Called by the RGOSH client with results from the command execution.
   @param[in] ctx user defined context required by the callback.
   @param[in] group group
   @param[in] key key
   @param[in] value value
   @return void.
*/
typedef void (*gs_command_result_cb_t)(void* ctx, const char *group, const char *key, const char *value);

/**
   RGOSH callback function for capturing std out.

   Called by the RGOSH client with stdout from the command execution.
   @param[in] ctx user defined context required by the callback.
   @param[in] out stdout from the command execution.
   @return void.
*/
typedef void (*gs_command_stdout_cb_t)(void* ctx, const char *out);

/**
   RGOSH Command output interface
*/
typedef struct gs_rgosh_run_if {
    /** callback function called with result data */
    gs_command_result_cb_t result_cb;
    /** callback function called with std_out data */
    gs_command_stdout_cb_t stdout_cb;
} gs_rgosh_run_if_t;


/**
   Run Command on Remote GOSH server node

   @param[in]  node        CSP address of remote server
   @param[in]  port        CSP port of remote server. Use default RGOSH port #GS_CSP_PORT_RGOSH.
   @param[in]  command     command to run on the remote server
   @param[in]  timeout_ms  timeout for the command to complete
   @param[out] return_code Return code from command execution.
   @param[in]  cb_if       Call-back interface for capturing results/output
   @param[in]  cb_ctx      pointer for storing a context for use by the call-back interface
   @return_gs_error_t
*/
gs_error_t gs_rgosh_run_command(uint8_t node,
                                uint8_t port,
                                const char * command,
                                uint32_t timeout_ms,
                                gs_error_t *return_code,
                                const gs_rgosh_run_if_t *cb_if,
                                void *cb_ctx);


/**
   Register RGOSH client commands

   @return_gs_error_t
*/
gs_error_t gs_rgosh_register_commands(void);

#ifdef __cplusplus
}
#endif
#endif
