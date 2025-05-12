/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#ifndef ADCS_STATEM_TYPES_H_
#define ADCS_STATEM_TYPES_H_

/**
 * @file adcs_statem_types.h
 *
 * The Gomspace ADCS state machine is built around the X-macro pattern.
 * This pattern uses contextually defined macros functions.
 * With this, it is possible to provide an extendable state machine for all
 * the subsystems in the ADCS, that is, ACS, ADS and ephemeris.
 *
 * This is done by defining a symbol, GS_{ACS, ADS, EPHEM}_STATE_TABLE,
 * that uses a (for now) undefined macro function, GS_STATE_MAPPER().
 *
 * This macro function is then defined contextually, such that is creates a finite state machine,
 * based on a state table. It further provides a type definition for an enum for the states of the FSM.
 *
 * A new state is defined with the undefined macro:
 *   GS_STATE_MAPPER(state table name, state id, state name)
 *
 * Example:
 *
 * We define a new state table, say GS_ACS_STATE_TABLE with an idle and a bdot state
 * @code
 * #define GS_TEST_STATE_TABLE        \
 *     GS_STATE_MAPPER(TEST, 0, IDLE) \
 *     GS_STATE_MAPPER(TEST, 1, BDOT)
 * @endcode
 * Later, this is used to create an enum:
 * @code
 * typedef enum __attribute__ ((packed)) test_mode_e{
 * #define GS_STATE_MAPPER(prefix, idx, state)  \
 *     TEST_##state = idx,
 *
 * GS_TEST_STATE_TABLE
 *
 * #undef GS_STATE_MAPPER
 * } test_mode_t;
 * @endcode
 * Later this is used to create a state table entry, which expands into a ::gs_acs_fsm_state_t on form form:
 * @code
 * gs_test_fsm_state_t state{.name=state,
 *                           .guard_fun=gs_##prefix##_##state##_gaurd_f,
 *                           .action_fun=gs_##prefix##_##state##_action_f
 * };
 * @endcode
 * Where the guard_fun must implement the interface of:
 *   - #gs_acs_guard_f (for a ACS state)
 *   - #gs_ads_guard_f (for a ADS state)
 *   - #gs_ephem_guard_f (for a ephemeris state)
 *
 * And similary, the action function must implement the interface of:
 *   - #gs_acs_action_f (for a ACS state)
 *   - #gs_ads_action_f (for a ADS state)
 *   - #gs_ephem_action_f (for a ephemeris state)
 *
 * **Adding Custom States**
 *
 * It is possible to add custom states to the state machines, by defining the following symbols:
 *
 *   - CUSTOM_EPHEM_STATE_TABLE - for custom ephem states
 *   - CUSTOM_ADS_STATE_TABLE - for custom ADS states
 *   - CUSTOM_ACS_STATE_TABLE - for custom ACS states
 *
 * These must be defines in the same way as the GS_{EPHEM, ADS, ACS}_STATE_TABLE, as shown in the example below, where the custom ACS state, with id 100, and name TEST is defined.
 * @code
 * #define CUSTOM_ACS_STATE_TABLE               \
 *            GS_STATE_MAPPER(ACS, 100, TEST)
 * @endcode
 *
 * Furhter must a #gs_acs_guard_f and #gs_acs_action_f function be implemented for the new state.

 * See also #gs_acs_fsm_state_t, #gs_ads_fsm_state_t and #gs_ephem_fsm_state_t.
 */

/**
 * @brief ACS state machine.
 *
 * The ACS statemachine are defined as described above, by defining a
 * symbol on the form GS_<table>_STATE_TABLE, with ACS as table.
 *
 * The table contains a list of calls to the undefined macro,
 * GS_STATE_MAPPER(table, ID, state) with an entry for each state in the ACS.
 *
 * @note The state IDs does not have to be in ascending order.
 *
 * The state table are generation by a creating a array of type #gs_acs_fsm_state_t[]
 * in compile time. Entries in this table are created by a contextual implementation of
 * the GS_STATE_MAPPER() macro. It gets expanded into
 * @code
 * {.name=state, .guard_fun=gs_<table>_<state>_guard_f, .action_fun=<table>_<state>_action_f}
 * @endcode
 *
 * @note The guard and action functions must comply with the naming convention as well as the interfaces (see gs/adcs/acs/statm/gs_acs.h).
 */
#define GS_ACS_STATE_TABLE                          \
    GS_STATE_MAPPER(ACS, 0, IDLE)                   \
    GS_STATE_MAPPER(ACS, 1, CONST)                  \
    GS_STATE_MAPPER(ACS, 2, BDOT)                   \
    GS_STATE_MAPPER(ACS, 5, SPIN)                   \
    GS_STATE_MAPPER(ACS, 6, WHEELS)                 \
    GS_STATE_MAPPER(ACS, 7, ACTUATOR)               \
    GS_STATE_MAPPER(ACS, 8, MAXDRAG)                \
    GS_STATE_MAPPER(ACS, 9, CALIBRATION)            \
    GS_STATE_MAPPER(ACS, 10, ORBITPOINTING)         \
    GS_STATE_MAPPER(ACS, 11, SUNPOINTING)

/**
 * @brief ADS state machine.
 *
 * Created in the same way as #GS_ACS_STATE_TABLE, but the ADS as the table,
 * and the states as seen in the value.
 *
 * (see gs/adcs/ads/statm/gs_ads.h)
 */
#define GS_ADS_STATE_TABLE                       \
    GS_STATE_MAPPER(ADS, 0, IDLE)                \
    GS_STATE_MAPPER(ADS, 1, SENSORS)             \
    GS_STATE_MAPPER(ADS, 3, KALMANFILTER)

/**
 * @brief ADS state machine.
 *
 * Created in the same way as #GS_ACS_STATE_TABLE, but the EPHEM as the table,
 * and the states as seen in the value.
 *
 * (see gs/adcs/ephemeris/statm/gs_ephem.h)
 */
#define GS_EPHEM_STATE_TABLE                         \
    GS_STATE_MAPPER(EPHEM, 0, IDLE)                  \
    GS_STATE_MAPPER(EPHEM, 1, TLE)                   \
    GS_STATE_MAPPER(EPHEM, 2, GPS)


/**
 * Control mode enumeration
 * @note These types are used in libadcs too
 */
typedef enum __attribute__ ((packed)) acs_mode_e{
#define GS_STATE_MAPPER(prefix, idx, state)     \
    ACS_##state = idx,

GS_ACS_STATE_TABLE

#undef GS_STATE_MAPPER
} acs_mode_t;

/**
 * Attitude determination mode enumeration
 * @note These types are used in libadcs too
 */
typedef enum __attribute__ ((packed)) ads_mode_e{
#define GS_STATE_MAPPER(prefix, idx, state)     \
    ADS_##state = idx,

GS_ADS_STATE_TABLE

#undef GS_STATE_MAPPER
} ads_mode_t;

/**
 * Ephemeris mode enumeration
 * @note These types are used in libadcs too
 */
typedef enum __attribute__ ((packed)) ephem_mode_e{
#define GS_STATE_MAPPER(prefix, idx, state)     \
    EPHEM_##state = idx,

    GS_EPHEM_STATE_TABLE

#undef GS_STATE_MAPPER
} ephem_mode_t;


#endif /* ADCS_STATEM_TYPES_H_ */
