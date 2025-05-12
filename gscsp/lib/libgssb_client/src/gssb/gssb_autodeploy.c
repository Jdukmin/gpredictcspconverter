/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <gs/gssb/gssb_all_devices.h>
#include <gs/gssb/gssb_autodeploy.h>
#include <gs/util/thread.h>
#include <gs/util/time.h>
#include <gs/util/mutex.h>
#include <gs/util/log.h>
#define GS_GSSB_INTERNAL_USE 1
#include <gs/gssb/internal/gssb_common.h>

/* Deploy states ant6 (the order must not be changed) */
#define ANTENNA_PAIR_1              2
#define ANTENNA_PAIR_2              3
#define DEPLOY_ALGORITHM_FINISHED   4

/* Deploy states ar6 (the order must not be changed) */
#define BOARD_0                     0
#define BOARD_1                     1
#define BOARD_2                     2
#define BOARD_3                     3

#define CHANNEL_0                   0
#define CHANNEL_1                   1

/* Auto burn parameters */
#define ANT6_START_BURNTIME         12
#define ANT6_INCREMENT              3
#define AR6_START_BURNTIME          2
#define AR6_INCREMENT               1
#define MAX_RETRIES_SINGLE_CHANNEL  10

uint8_t reset_variables_ant6, reset_variables_ar6;

/* Creates a task, which handles the autodeploy  */
gs_autodeploy_task_status_t gs_autodeploy_six_u(uint16_t seconds_delay, uint8_t addr_ant6_0,
                                                uint8_t addr_ant6_1, uint8_t addr_ar6_0, uint8_t addr_ar6_1,
                                                uint8_t addr_ar6_2, uint8_t addr_ar6_3)
{
    /* Create task for auto deploy */
    static uint16_t parameters[8];
    static uint8_t running = 0;
    if (running == 0) {
        parameters[0] = seconds_delay;
        parameters[1] = addr_ant6_0;
        parameters[2] = addr_ant6_1;
        parameters[3] = addr_ar6_0;
        parameters[4] = addr_ar6_1;
        parameters[5] = addr_ar6_2;
        parameters[6] = addr_ar6_3;
        parameters[7] = RUNNING;
        void * gs_autodeploy_task(void *parameters);
        gs_thread_create("antenna_deploy", gs_autodeploy_task, &parameters, 2000, GS_THREAD_PRIORITY_NORMAL, 0, NULL);

        running = 1;
        reset_variables_ant6 = 1;
        reset_variables_ar6 = 1;
        return STARTING;
    } else {
        if ((int8_t) parameters[7] != RUNNING)
            running = 0;
        return (int8_t) parameters[7];

    }
}

/* This task runs the state machine for deploying the four antennas through two ant6 boards.
 * The frequency is 1 Hz. It deletes it self after end of algorithm and updates the result
 * in the parameters[3]
 * */
void * gs_autodeploy_task(void *parameters)
{
    int8_t res_ant6, res_ar6;
    uint16_t delay = (*((uint16_t *) parameters));
    uint8_t i2c_addr_ant6_0 = (uint8_t) (*((uint16_t *) parameters + 1));
    uint8_t i2c_addr_ant6_1 = (uint8_t) (*((uint16_t *) parameters + 2));
    uint8_t i2c_addr_ar6_0 = (uint8_t) (*((uint16_t *) parameters + 3));
    uint8_t i2c_addr_ar6_1 = (uint8_t) (*((uint16_t *) parameters + 4));
    uint8_t i2c_addr_ar6_2 = (uint8_t) (*((uint16_t *) parameters + 5));
    uint8_t i2c_addr_ar6_3 = (uint8_t) (*((uint16_t *) parameters + 6));
    uint32_t seconds_since_boot;

    while (1) {
        /* Get seconds */
        seconds_since_boot = gs_time_rel_ms() / 1000;

        /* Run state machine for ANT6 */
        res_ant6 = gs_autodeploy_ant6_state_machine(delay, seconds_since_boot, i2c_addr_ant6_0, i2c_addr_ant6_1);

        /* Delay for 1 second*/
        gs_thread_sleep_ms(1000);

        /* Delete task if algorithm is done */
        if ((res_ant6 == FINISHED_SUCCESSFULLY) || (res_ant6 == FINISHED_UNSUCCESSFULLY)
                        || (res_ant6 == FINISHED_WITH_I2C_ERROR)) {
            /* If ANT6 finished then run AR6 state machine */
            res_ar6 = gs_autodeploy_ar6_state_machine(delay, seconds_since_boot, i2c_addr_ar6_0, i2c_addr_ar6_1,
                                                            i2c_addr_ar6_2, i2c_addr_ar6_3);
            if ((res_ar6 == FINISHED_SUCCESSFULLY) || (res_ar6 == FINISHED_UNSUCCESSFULLY)
                            || (res_ar6 == FINISHED_WITH_I2C_ERROR)) {
                /* If ANT6 deployed succesfully then return result of AR6 */
                if (res_ant6 == FINISHED_SUCCESSFULLY)
                    (*((uint16_t *) parameters + 7)) = res_ar6;
                else
                    (*((uint16_t *) parameters + 7)) = res_ant6;
                /* Delete task if finished */
                gs_thread_exit(0);
            }
        }
    }
}

static gs_error_t ant6_initiate_burn(uint8_t *burntimePTR, uint8_t *triesPTR, uint8_t i2c_addr,
                                     uint32_t *burn_start_timePTR, uint32_t seconds_since_boot, uint8_t channel)
{
    uint16_t i2c_timeout_ms = 1000;
    *burntimePTR = ANT6_START_BURNTIME + (ANT6_INCREMENT * (*triesPTR));
    *burn_start_timePTR = seconds_since_boot;
    (*triesPTR)++;
    return gs_gssb_ant6_burn_channel(i2c_addr, i2c_timeout_ms, channel, *burntimePTR);
}

static int8_t ant6_burn_algorithm(uint8_t i2c_addr_board_1, uint8_t channel_board_1, uint8_t i2c_addr_board_2,
                                  uint8_t channel_board_2, uint32_t seconds_since_boot, uint8_t *current_state)
{
    uint16_t i2c_timeout_ms = 1000;
    static uint8_t burntime = 0;
    static uint8_t tries_1 = 0;
    static uint8_t tries_2 = 0;
    static uint32_t burn_start_time;
    static uint8_t burning;
    gs_gssb_ant6_release_status_t channel_status_board_1, channel_status_board_2;
    uint8_t release_status_board_1, release_status_board_2;
    gs_error_t res;
    static uint8_t switch_board = 0;

    if (reset_variables_ant6 == 1) {
        tries_1 = 0;
        tries_2 = 0;
    }

    res = gs_gssb_ant6_get_release_status(i2c_addr_board_1, i2c_timeout_ms, &channel_status_board_1);
    if (res != GS_OK) {
        channel_status_board_1.channel_0_status = 0;
        channel_status_board_1.channel_1_status = 0;
    }
    res = gs_gssb_ant6_get_release_status(i2c_addr_board_2, i2c_timeout_ms, &channel_status_board_2);
    if (res != GS_OK) {
        channel_status_board_2.channel_0_status = 0;
        channel_status_board_2.channel_1_status = 0;
    }
    if (channel_board_1 == CHANNEL_0)
        release_status_board_1 = channel_status_board_1.channel_0_status;
    else
        release_status_board_1 = channel_status_board_1.channel_1_status;
    if (channel_board_2 == CHANNEL_0)
        release_status_board_2 = channel_status_board_2.channel_0_status;
    else
        release_status_board_2 = channel_status_board_2.channel_1_status;

    /* If not released, tries less than max or first try and not burning - initiate burn */
    if (((((release_status_board_1 != 1) || (release_status_board_2 != 1)) && (tries_1 < MAX_RETRIES_SINGLE_CHANNEL)) ||
         ((tries_1 < 1) || (tries_2 < 1)))
        && (burning == 0)) {
        burning = 1;
        if (switch_board == 1) {
            switch_board = 0;
            res = ant6_initiate_burn(&burntime, &tries_1, i2c_addr_board_1, &burn_start_time, seconds_since_boot,
                                     channel_board_1);
        } else {
            switch_board = 1;
            res = ant6_initiate_burn(&burntime, &tries_2, i2c_addr_board_2, &burn_start_time, seconds_since_boot,
                                     channel_board_2);
        }
        if (res != GS_OK)
            return -1;
    }
    /* If double burntime passed - switch flag, and make sure that we are not burning */
    else if ((seconds_since_boot >= (burn_start_time + burntime * 2)) && (burning == 1)) {
        burning = 0;
        res = gs_gssb_common_stop_burn(i2c_addr_board_1, i2c_timeout_ms);
        if (res != GS_OK)
            return -1;
        res = gs_gssb_common_stop_burn(i2c_addr_board_2, i2c_timeout_ms);
        if (res != GS_OK)
            return -1;
    }
    /* If either released or max retries used and not burning - stop burn and switch state */
    else if ((((release_status_board_1 == 1) && (release_status_board_2 == 1))
                    || (tries_1 >= MAX_RETRIES_SINGLE_CHANNEL)) && (burning == 0)) {
        burning = 0;
        tries_1 = 0;
        tries_2 = 0;
        (*current_state)++;
        res = gs_gssb_common_stop_burn(i2c_addr_board_1, i2c_timeout_ms);
        if (res != GS_OK)
            return -1;
        res = gs_gssb_common_stop_burn(i2c_addr_board_2, i2c_timeout_ms);
        if (res != GS_OK)
            return -1;
    }
    if (((release_status_board_1 == 1) && (release_status_board_2 == 1)))
        return 1;
    else
        return 0;
}

/* This state machine should be called every second until its finished
 * It send commands to the two ant6 boards, which releases the four
 * antennas in the correct order.
 * */
gs_autodeploy_state_machine_status_t gs_autodeploy_ant6_state_machine(uint16_t delay, uint32_t seconds_since_boot,
                                                                      uint8_t i2c_addr_board_0,
                                                                      uint8_t i2c_addr_board_1)
{

    static int8_t global_state = WAITING;
    static uint8_t deploy_state = ANTENNA_PAIR_1;
    static int8_t release_status[2] = { 0, 0 };

    if (reset_variables_ant6 == 1) {
        global_state = WAITING;
        deploy_state = ANTENNA_PAIR_1;
        reset_variables_ant6 = 0;
    }

    switch (global_state) {
        case WAITING:
            if (seconds_since_boot >= delay)
                global_state = DEPLOYING;
            break;

        case DEPLOYING:
            switch (deploy_state) {
                case ANTENNA_PAIR_1:
                    release_status[0] = ant6_burn_algorithm(i2c_addr_board_0, CHANNEL_0, i2c_addr_board_1, CHANNEL_1,
                                                            seconds_since_boot, &deploy_state);
                    break;

                case ANTENNA_PAIR_2:
                    release_status[1] = ant6_burn_algorithm(i2c_addr_board_0, CHANNEL_1, i2c_addr_board_1, CHANNEL_0,
                                                            seconds_since_boot, &deploy_state);
                    break;

                case DEPLOY_ALGORITHM_FINISHED:
                    if (release_status[0] == 1 && release_status[1] == 1)
                        global_state = FINISHED_SUCCESSFULLY;
                    else if (release_status[0] == -1 || release_status[1] == -1)
                        global_state = FINISHED_WITH_I2C_ERROR;
                    else
                        global_state = FINISHED_UNSUCCESSFULLY;
                    break;
            }
            break;

        case FINISHED_SUCCESSFULLY:
            break;

        case FINISHED_UNSUCCESSFULLY:
            break;

        case FINISHED_WITH_I2C_ERROR:
            break;
    }
    return global_state;
}

static gs_error_t ar6_initiate_burn(uint8_t *burntimePTR, uint8_t *triesPTR, uint8_t i2c_addr,
                                    uint32_t *burn_start_timePTR, uint32_t seconds_since_boot)
{
    uint16_t i2c_timeout_ms = 1000;
    *burntimePTR = AR6_START_BURNTIME + (AR6_INCREMENT * (*triesPTR));
    *burn_start_timePTR = seconds_since_boot;
    (*triesPTR)++;
    return gs_gssb_ar6_burn(i2c_addr, i2c_timeout_ms, *burntimePTR);
}

static int8_t ar6_burn_algorithm(uint8_t i2c_addr, uint32_t seconds_since_boot, uint8_t *current_state)
{
    uint16_t i2c_timeout_ms = 1000;
    static uint8_t burntime = 0;
    static uint8_t tries = 0;
    static uint32_t burn_start_time;
    static uint8_t burning;
    gs_gssb_ar6_release_status_t status;
    gs_error_t res;

    if (reset_variables_ar6 == 1) {
        tries = 0;
    }

    res = gs_gssb_ar6_get_release_status(i2c_addr, i2c_timeout_ms, &status);
    if (res != GS_OK) {
        status.status = 0;
    }
    /* If not released, tries less than max or first try and not burning - initiate burn */
    if ((((status.status != 1) && (tries < MAX_RETRIES_SINGLE_CHANNEL)) || (tries < 1)) && (burning == 0)) {
        burning = 1;
        res = ar6_initiate_burn(&burntime, &tries, i2c_addr, &burn_start_time, seconds_since_boot);
        if (res != GS_OK)
            return -1;
    }
    /* If double burntime passed - switch flag, and make sure that we are not burning */
    else if ((seconds_since_boot >= (burn_start_time + burntime * 2)) && (burning == 1)) {
        burning = 0;
        res = gs_gssb_common_stop_burn(i2c_addr, i2c_timeout_ms);
        if (res != GS_OK)
            return -1;
    }
    /* If either released or max retries used and not burning - stop burn and switch state */
    else if (((status.status == 1) || (tries >= MAX_RETRIES_SINGLE_CHANNEL)) && (burning == 0)) {
        burning = 0;
        tries = 0;
        (*current_state)++;
        res = gs_gssb_common_stop_burn(i2c_addr, i2c_timeout_ms);
        if (res != GS_OK)
            return -1;
    }
    if (status.status == 1)
        return 1;
    else
        return 0;
}
/* This state machine should be called every second until its finished
 * It send commands to the two ar6 boards, which releases the four
 * antennas.
 * */
gs_autodeploy_state_machine_status_t gs_autodeploy_ar6_state_machine(uint16_t delay, uint32_t seconds_since_boot,
                                                                     uint8_t i2c_addr_board_0, uint8_t i2c_addr_board_1,
                                                                     uint8_t i2c_addr_board_2, uint8_t i2c_addr_board_3)
{
    static int8_t global_state = WAITING;
    static uint8_t deploy_state = BOARD_0;
    static int8_t release_status[4] = { 0, 0, 0, 0 };

    if (reset_variables_ar6 == 1) {
        global_state = WAITING;
        deploy_state = BOARD_0;
        reset_variables_ar6 = 0;
    }

    switch (global_state) {
        case WAITING:
            if (seconds_since_boot >= delay)
                global_state = DEPLOYING;
            break;

        case DEPLOYING:
            switch (deploy_state) {
                case BOARD_0:
                    release_status[0] = ar6_burn_algorithm(i2c_addr_board_0, seconds_since_boot, &deploy_state);
                    break;

                case BOARD_1:
                    release_status[1] = ar6_burn_algorithm(i2c_addr_board_1, seconds_since_boot, &deploy_state);
                    break;

                case BOARD_2:
                    release_status[2] = ar6_burn_algorithm(i2c_addr_board_2, seconds_since_boot, &deploy_state);
                    break;

                case BOARD_3:
                    release_status[3] = ar6_burn_algorithm(i2c_addr_board_3, seconds_since_boot, &deploy_state);
                    break;

                case DEPLOY_ALGORITHM_FINISHED:
                    if (release_status[0] == 1 && release_status[1] == 1 && release_status[2] == 1
                                    && release_status[3] == 1)
                        global_state = FINISHED_SUCCESSFULLY;
                    else if (release_status[0] == -1 || release_status[1] == -1 || release_status[2] == -1
                                    || release_status[3] == -1)
                        global_state = FINISHED_WITH_I2C_ERROR;
                    else
                        global_state = FINISHED_UNSUCCESSFULLY;
                    break;
            }
            break;

        case FINISHED_SUCCESSFULLY:
            break;

        case FINISHED_UNSUCCESSFULLY:
            break;

        case FINISHED_WITH_I2C_ERROR:
            break;
    }
    return global_state;
}

gs_error_t gs_autodeploy_release_two_dsp(uint8_t i2c_addr_11,
                                         uint8_t i2c_addr_12,
                                         uint8_t i2c_addr_21,
                                         uint8_t i2c_addr_22,
                                         uint8_t start_burntime,
                                         uint8_t increment,
                                         uint8_t max_burn_time)
{
    const uint16_t i2c_timeout_ms = 1000;
    uint8_t tries = 0;
    uint8_t burn_time;
    gs_gssb_ar6_release_status_t status;
    uint8_t release_status_dsp = 0;
    uint8_t release_status_both = 1;
    gs_error_t res;
    gs_error_t return_val = GS_OK;
    uint8_t i2c_addr_1 = i2c_addr_11;
    uint8_t i2c_addr_2 = i2c_addr_12;

    for (uint8_t i = 0; i <= 1; i++) {
        if (i == 1) {
            i2c_addr_1 = i2c_addr_21;
            i2c_addr_2 = i2c_addr_22;
            tries = 0;
        }
        do {
            burn_time = start_burntime + increment * tries;
            if (burn_time > max_burn_time) {
                burn_time = max_burn_time;
            }

            res = gs_gssb_ar6_burn(i2c_addr_1, i2c_timeout_ms, burn_time);
            if (res != GS_OK) {
                return_val = res;
            }
            log_info("Burning: %hhu s, res: %d", burn_time, res);

            res = gs_gssb_ar6_burn(i2c_addr_2, i2c_timeout_ms, burn_time);
            if (res != GS_OK) {
                return_val = res;
            }
            log_info("Burning: %hhu s, res: %d", burn_time, res);

            tries++;
            gs_thread_sleep_ms(burn_time * 1500);

            res = gs_gssb_ar6_get_release_status(i2c_addr_1, i2c_timeout_ms, &status);
            if (res != GS_OK) {
                return_val = res;
                status.status = 0;
            }
            log_info("Release status: %hhu s, res: %d", status.status, res);

            release_status_dsp = status.status;

            res = gs_gssb_ar6_get_release_status(i2c_addr_2, i2c_timeout_ms, &status);
            if (res != GS_OK) {
                return_val = res;
                status.status = 0;
            }
            log_info("Release status: %hhu s, res: %d", status.status, res);

            release_status_dsp &= status.status;

        } while ((burn_time < max_burn_time) && (release_status_dsp == 0));

        release_status_both &= release_status_dsp;
    }

    /* Return OK if released */
    if (release_status_both == 1) {
        return GS_OK;
    } else {
        /* Return result of gssb functions if one has failed */
        if (return_val != GS_OK) {
            return return_val;
        } else {
        /* Return ERROR_TIMEOUT if not released and no communication error */
            return GS_ERROR_TIMEOUT;
        }
    }
}

