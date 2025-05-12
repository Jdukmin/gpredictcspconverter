#ifndef FP_TIMER_H_
#define FP_TIMER_H_
/* Copyright (c) 2013-2019 GomSpace A/S. All rights reserved. */
/**
   @file

   Flight planner timer.
*/

#include <gs/util/timestamp.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   Unlimited repetitions, i.e. recurring event.
*/
#define FP_TIME_UNLIMITED UINT16_MAX

/**
   Timer basis
*/
typedef enum {
    /**
        Absolute timer.
    */
    FP_TIME_ABSOLUTE = 0,
    /**
        Relative to another timer execution.
    */
    FP_TIME_RELATIVE = 1,
} fp_timer_basis_t;

/**
   Timer state
*/
typedef enum {
    /**
        Active timer.
    */
    FP_TIME_ACTIVE = 0,
    /**
        Dormant timer.
    */
    FP_TIME_DORMANT = 1,
} fp_timer_state_t;

#ifdef __cplusplus
}
#endif
#endif
