#ifndef INCLUDE_GS_GSSB_GSSB_AUTODEPLOY_H_
#define INCLUDE_GS_GSSB_GSSB_AUTODEPLOY_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   API for auto deploy functions, which are running at the client
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
   Generic auto deploy status codes
 */
typedef enum gs_autodeploy_state_machine_status_t {
    /**
       Finished deploy algorithm with an I2C error
     */
    FINISHED_WITH_I2C_ERROR = -2,
    /**
       Finished deploy algorithm some undeployed items
     */
    FINISHED_UNSUCCESSFULLY = -1,
    /**
       Succesfull deployment of all items
     */
    FINISHED_SUCCESSFULLY = 0,
    /**
       Deploy algorithm waiting to start
     */
    WAITING = 1,
    /**
       Deployment is ongoing
     */
    DEPLOYING = 2
} gs_autodeploy_state_machine_status_t;

/**
   Auto deploy task status
 */
typedef enum gs_autodeploy_task_status_t {
    /**
       Task running
     */
    RUNNING = 1,
    /**
       Task just started
     */
    STARTING = 2
} gs_autodeploy_task_status_t;

/**
   Auto deploy four ar6 boards

   @note This function should be called every second.

   @param[in] delay Delay for auto deploy in seconds (delay since boot).
   @param[in] seconds_since_boot Number of seconds past since boot.
   @param[in] i2c_addr_board_0 I2C address for board 0.
   @param[in] i2c_addr_board_1 I2C address for board 1.
   @param[in] i2c_addr_board_2 I2C address for board 2.
   @param[in] i2c_addr_board_3 I2C address for board 3.
   @return gs_autodeploy_state_machine_status_t
 */
gs_autodeploy_state_machine_status_t gs_autodeploy_ar6_state_machine(uint16_t delay,
                                                                     uint32_t seconds_since_boot,
                                                                     uint8_t i2c_addr_board_0,
                                                                     uint8_t i2c_addr_board_1,
                                                                     uint8_t i2c_addr_board_2,
                                                                     uint8_t i2c_addr_board_3);

/**
   Auto deploy four ar6 boards

   @note This function should be called every second.

   @param delay Delay for auto deploy in seconds (delay since boot).
   @param seconds_since_boot Number of seconds past since boot.
   @param i2c_addr_board_0 I2C address for board 0.
   @param i2c_addr_board_1 I2C address for board 1.
   @return
 */
gs_autodeploy_state_machine_status_t gs_autodeploy_ant6_state_machine(uint16_t delay,
                                                                      uint32_t seconds_since_boot,
                                                                      uint8_t i2c_addr_board_0,
                                                                      uint8_t i2c_addr_board_1);

/**
   Auto deploy two DSPs (deployable solar panels),
   which relates to four Interstage 3u (AR6) boards

   @note This function start deploying immediately and takes as long time as the algorithm takes to finish.

   @param i2c_addr_11 I2C address for first board of first DSP.
   @param i2c_addr_12 I2C address for second board of first DSP.
   @param i2c_addr_21 I2C address for first board of second DSP.
   @param i2c_addr_22 I2C address for second board of second DSP.
   @param start_burntime Initial burn time [s].
   @param increment Burn time incrementation at every try [s].
   @param max_burn_time Maximum burn time [s].
   @return_gs_error_t
 */
gs_error_t gs_autodeploy_release_two_dsp(uint8_t i2c_addr_11,
                                         uint8_t i2c_addr_12,
                                         uint8_t i2c_addr_21,
                                         uint8_t i2c_addr_22,
                                         uint8_t start_burntime,
                                         uint8_t increment,
                                         uint8_t max_burn_time);


/**
   Auto deploy a 6u platform consisting two ant6 boards and four ar6 boards

   @note This function should be called every second.
   @note This function starts a task, which facilitates the state machines.
         It deletes itself after deployment.


   @param seconds_delay Delay for auto deploy in seconds (delay since boot).
   @param addr_ant6_0 I2C address for ant6 board 0.
   @param addr_ant6_1 I2C address for ant6 board 1.
   @param addr_ar6_0 I2C address for ar6 board 0.
   @param addr_ar6_1 I2C address for ar6 board 1.
   @param addr_ar6_2 I2C address for ar6 board 2.
   @param addr_ar6_3 I2C address for ar6 board 3.
   @return gs_autodeploy_task_status_t
 */
gs_autodeploy_task_status_t gs_autodeploy_six_u(uint16_t seconds_delay,
                                                uint8_t addr_ant6_0,
                                                uint8_t addr_ant6_1,
                                                uint8_t addr_ar6_0,
                                                uint8_t addr_ar6_1,
                                                uint8_t addr_ar6_2,
                                                uint8_t addr_ar6_3);


#ifdef __cplusplus
}
#endif
#endif
