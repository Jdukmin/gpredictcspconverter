#ifndef GS_GOSH_REMOTE_CLIENT_H
#define GS_GOSH_REMOTE_CLIENT_H
/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */
/**
   @file

   Execute shell command on remote node (over CSP) - Linux only.
*/

#include <gs/util/error.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Client send command to server.
*/
gs_error_t gs_gosh_remote_shell(uint8_t node, unsigned int timeout, bool raw, const char *command);

/**
   Client send command to server.
*/
gs_error_t gs_gosh_remote_shell_stdio(uint8_t node, unsigned int timeout, bool raw, const char *command, FILE *stdin, FILE *stdout);
    
/**
   Register commands.
   @return_gs_error_t
*/
gs_error_t gs_gosh_remote_register_commands(void);
    
#ifdef __cplusplus
}
#endif
#endif
