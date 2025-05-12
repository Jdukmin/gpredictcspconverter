#ifndef GS_RGOSH_LOG_H
#define GS_RGOSH_LOG_H
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <gs/util/log.h>

GS_LOG_GROUP_EXTERN(gs_rgosh_log);

/* Change default LOG group for all files (RGOSH) including this header */
#define LOG_DEFAULT gs_rgosh_log

#endif
