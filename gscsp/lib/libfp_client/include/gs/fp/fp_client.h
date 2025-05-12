#ifndef FP_CLIENT_H
#define FP_CLIENT_H
/* Copyright (c) 2013-2020 GomSpace A/S. All rights reserved. */
/**
   @file

   Flight planner - client interface.
*/

#include <gs/fp/fp_timer.h>
#include <gs/util/error.h>
#include <gs/util/gosh/command.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   General Flight Planner functions
   @{
*/

/**
   Set which node the flight planner server is listening on.

   @param[in] node csp node.
   @return_gs_error_t
*/
gs_error_t fp_client_host(uint8_t node);

/**
   Flush current flight plan.
   This deletes all sequences, timers, triggers and dynamic events.
   @return_gs_error_t
*/
gs_error_t fp_client_fp_flush(void);

/**
   Store current flight plan to file.

   @param[in] filename path where the flight plan should be stored.
   @return_gs_error_t
*/
gs_error_t fp_client_fp_store(const char * filename);

/**
   Load flight plan from file.
   This flushes the current flight plan.

   @param[in] filename path from where the flight plan should be loaded.
   @param[in] fast_load_with_unique_keys When set the keys in the flightplan aren't verified, they MUST be unique.
   @return_gs_error_t
*/
gs_error_t fp_client_fp_load(const char * filename, bool fast_load_with_unique_keys);

/**@}*/

/**
   Timer functions.
   @{
*/

/**
   Create new timer.

   @param[in] key id off timer.
   @param[in] cmd command to trigger when timer expires.
   @param[in] basis must either be FP_TIME_ABSOLUTE or FP_TIME_RELATIVE.
   @param[in] state initial state of timer FP_TIME_ACTIVE or FP_TIME_DORMANT.
   @param[in] when time to execute the timer.
   @param[in] repeat number of repetitions. Use FP_TIME_UNLIMITED for recurring timer.
   @return_gs_error_t
*/
gs_error_t fp_client_timer_create(const char * key, const char * cmd, fp_timer_basis_t basis, fp_timer_state_t state, gs_timestamp_t *when, uint16_t repeat);

/**
   Delete timer.

   @param[in] key id off timer to delete.
   @return_gs_error_t
*/
gs_error_t fp_client_timer_delete(const char * key);

/**
   Set timer active.

   @param[in] key id off timer to activate.
   @return_gs_error_t
*/
gs_error_t fp_client_timer_set_active(const char * key);

/**
   Set timer dormant.

   @param[in] key id off timer to set dormant.
   @return_gs_error_t
*/
gs_error_t fp_client_timer_set_dormant(const char * key);

/**
   Set repeat parameter of timer.

   @param[in] key id off timer.
   @param[in] count value of repeat parameter.
   @return_gs_error_t
*/
gs_error_t fp_client_timer_set_repeat(const char * key, uint16_t count);

/**
   Set time and basis parameters of timer.

   @param[in] key id off timer.
   @param[in] basis must either be FP_TIME_ABSOLUTE or FP_TIME_RELATIVE.
   @param[in] when time to execute the timer.
   @return_gs_error_t
*/
gs_error_t fp_client_timer_set_time(const char * key, fp_timer_basis_t basis, const gs_timestamp_t * when);

/**
   Set all timers active.

   @return_gs_error_t
*/
gs_error_t fp_client_timer_set_all_active(void);

/**
   List current timers on stdout.

   @param[in] ctx commands context reference.
   @return_gs_error_t
*/
gs_error_t fp_client_timer_list(gs_command_context_t *ctx);

/**@}*/

/**
   Register commands.
   @return_gs_error_t
*/
gs_error_t gs_fp_register_commands(void);

/**
   Register commands.
   @deprecated use gs_fp_register_commands()
   @return_gs_error_t
*/
static inline gs_error_t fp_client_register_commands(void)
{
    return gs_fp_register_commands();
}
    
#ifdef __cplusplus
}
#endif
#endif
