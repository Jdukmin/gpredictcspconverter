#ifndef LIB_LIBADCS_LIB_LIBADCS_CLIENT_INCLUDE_GS_ADCS_ADCS_COMMAND_H_
#define LIB_LIBADCS_LIB_LIBADCS_CLIENT_INCLUDE_GS_ADCS_ADCS_COMMAND_H_

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

gs_error_t gs_adcs_register_commands(void);

#endif /* LIB_LIBADCS_LIB_LIBADCS_CLIENT_INCLUDE_GS_ADCS_ADCS_COMMAND_H_ */
