/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */

#include <gs/util/gosh/command.h>

#ifdef __cplusplus
extern "C" {
#endif

int        gs_fp_cmd_fp_server_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_flush_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_load_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_store_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_create_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_delete_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_active_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_allactive_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_dormant_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_repeat_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_time_handler(gs_command_context_t* ctx);
int        gs_fp_cmd_fp_list_handler(gs_command_context_t* ctx);

gs_error_t gs_fp_register_commands(void);

#ifdef __cplusplus
}
#endif
