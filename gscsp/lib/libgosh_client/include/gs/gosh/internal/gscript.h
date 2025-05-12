#ifndef GS_GOSH_INTERNAL_GSCRIPT_H
#define GS_GOSH_INTERNAL_GSCRIPT_H
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#if (GS_GOSH_GSCRIPT_INTERNAL_USE)

#include <gs/gosh/gscript/client.h>

/**
   G-script request codes.
*/
typedef enum __attribute__((__packed__)) {
    //! Execute gscript, gs_gscript_req_exec_t
    GS_GSCRIPT_REQ_TYPE_EXEC = 0,
    //! Execute gscript from file, gs_gscript_req_exec_t
    GS_GSCRIPT_REQ_TYPE_EXEC_FILE = 1,
    //! Request all running gscripts to stop/terminate
    GS_GSCRIPT_REQ_TYPE_STOP = 2,
} gs_gscript_req_type_t;

/**
   G-script request message.
*/
typedef struct __attribute__((__packed__)) {
    //! Request type.
    gs_gscript_req_type_t type;
    //! Task stack size used to execute the script on the remote G-script server. Not used in g-script servers 3.0.
    uint16_t stack;
    //! Task priority used to execute the script on the remote G-script server. Not used in g-script servers 3.0.
    uint16_t priority;
    //! When to execute the script in UTC. 0 means execute now.
    uint32_t when;
    //! script filename or commands.
    char cmd[];
} gs_gscript_req_exec_t;

/**
   G-script request stop message.
*/
typedef struct __attribute__((__packed__)) {
    //! Request type.
    gs_gscript_req_type_t type;
} gs_gscript_req_stop_t;

#endif
#endif
