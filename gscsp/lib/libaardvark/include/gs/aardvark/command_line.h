#ifndef GS_AARDVARK_COMMAND_LINE_H
#define GS_AARDVARK_COMMAND_LINE_H
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Command line support.
*/

#include <gs/util/error.h>
#include <gs/util/linux/argp.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Command line options.
*/
extern const struct argp_child gs_aardvark_command_line_argp;

/**
   Register initialize functions for I2C/SPI.

   Based on the \a function API in libutil.
   Used by libgscsp command line to initialize I2C.

   @return_gs_error_t
*/
gs_error_t gs_aardvark_register_initialize_functions(void);
    
#ifdef __cplusplus
}
#endif
#endif
