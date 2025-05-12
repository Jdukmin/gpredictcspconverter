#ifndef GS_GSSB_GSSB_COMMAND_H
#define GS_GSSB_GSSB_COMMAND_H
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   GSSB (host) commands.
*/

#include <gs/util/error.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Register host commands.
   @return_gs_error_t
*/
gs_error_t gs_gssb_register_commands(void);

#ifdef __cplusplus
}
#endif
#endif
