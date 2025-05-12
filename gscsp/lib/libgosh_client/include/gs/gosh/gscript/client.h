#ifndef GS_GOSH_GSCRIPT_CLIENT_H
#define GS_GOSH_GSCRIPT_CLIENT_H
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   gscript (GOMspace script).

   Gscripts consists of a number of GOSH commands and some simple control logic.
   The format is as follows:
   \<delay ms\> \<retry\> \<goto on error\> \<comamnd\> \[options\]
   delays ms: delay in mS before the command is executed.
   retry: number of times the command is tried executed, if it fails.
   goto on error: which line to goto, if command fails (after retry).
   command: GOSH command
   options: option(s) for command.
*/

#include <gs/util/error.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Execute script on remote node.

   @note This funtion does not wait for the script to execute.

   @param[in] node remote node.
   @param[in] script script or commands - depends on \a is_file
   @param[in] is_file true if \a script is a filename, false if \a script contains script commands.
   @param[in] when_utc_seconds when to execute the script (UTC), use 0 to execute now.
   @param[in] stack_size stack size for the executing thread. Not used in g-script servers 3.0.
   @param[in] priority priotity for the executing thread. Not used in g-script servers 3.0.
   @return_gs_error_t
*/
gs_error_t gs_gscript_exec_remote(uint8_t node, const char * script, bool is_file, uint32_t when_utc_seconds, size_t stack_size, int priority);

/**
   Request all scripts to terminate.
   @note this function signals all running scripts to terminate - it does not wait for them to terminate.

   @param[in] node remote node.
   @return_gs_error_t
*/
gs_error_t gs_gscript_stop_remote(uint8_t node);

/**
   Register commands.
   @return_gs_error_t
*/
gs_error_t gs_gscript_register_commands(void);

#ifdef __cplusplus
}
#endif
#endif
