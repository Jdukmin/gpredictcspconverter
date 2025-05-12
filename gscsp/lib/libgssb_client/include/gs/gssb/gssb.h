#ifndef _GS_GSSB_IO_GSSB_H_
#define _GS_GSSB_IO_GSSB_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   GSSB types
*/

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   GSSB board type
 */
typedef enum gs_gssb_model_t {
    /**
       MSP
     */
    GS_GSSB_MODEL_MSP = 1,
    /**
       AR6
     */
    GS_GSSB_MODEL_AR6 = 2,
    /**
       Interstage
     */
    GS_GSSB_MODEL_ISTAGE = 3,
    /**
       ANT6
     */
    GS_GSSB_MODEL_ANT6 = 4,
    /**
       I4
     */
    GS_GSSB_MODEL_I4 = 5
} gs_gssb_model_t;

/**
   Interstage burn settings
 */
typedef struct __attribute__((__packed__)) istage_burn_settings_t {
    /**
       Burn time for first burn [ms]
     */
    uint16_t std_time_ms;
    /**
       How much to increment burn time for each retry [ms]
     */
    uint16_t increment_ms;
    /**
      The burn process will run once after this cntr runs out [s]
     */
    uint16_t short_cnt_down;
    /**
       Max number of retries
     */
    uint8_t max_repeat;
    /**
       Time between retries [s]
     */
    uint8_t rep_time_s;
    /**
       Release sense switch polarity
     */
    uint8_t switch_polarity;
    /**
       Status (0 = not armed, 1 = armed for manual, 2 = armed for auto deploy)
     */
    uint8_t status;
    /**
       Lock (1 = locked, 0 = unlocked)
     */
    uint8_t locked;
    /**
       Number of reboots for when deployment happens immediately after boot
       ((reboots % reboot_deploy_cnt) == 0) -> immediately deployment
     */
    uint8_t reboot_deploy_cnt;
} gs_gssb_istage_burn_settings_t;

/**
   GSSB Identification
 */
typedef struct gs_gssb_ident_t {
    /**
       Unique ID
     */
    uint32_t uuid;
    /**
       GomSpace software version
     */
    uint8_t version[20];
} gs_gssb_ident_t;

/**
   Interstage status
 */
typedef struct __attribute__((__packed__)) gssb_csp_istage_status_t {
    /**
       Time before deploying
     */
    uint16_t deploy_in_s;
    /**
       Number of deploy tries since boot
     */
    uint8_t number_of_deploys;
    /**
       The thermal knife that will be used in next deploy
     */
    uint8_t active_knife;
    /**
       Interstage state (0 = not armed, 1 = armed for manual deploy, 2 = armed for auto deploy, 3 and 4 = deploying)
     */
    uint8_t state;
    /**
       Total number of deploys in interstage life time
     */
    uint16_t total_number_of_deploys;
    /**
       Number of reboots left before interstage will deploy on boot
     */
    uint8_t reboot_deploy_cnt;
    /**
       Release switch state. 1 = released, 0 = not released
     */
    uint8_t release_status;
} gs_gssb_istage_status_t;

/**
   Backup status
 */
typedef struct __attribute__((__packed__)) gs_gssb_backup_status_t {
    /**
       State of backup deployment (0 = not active/finished successful, 1 = active and counting, 2 = finished unsuccessful)
     */
    uint8_t state;
    /**
       Time to backup deploy [s]
     */
    uint32_t seconds_to_deploy;
} gs_gssb_backup_status_t;

/**
   Board status
 */
typedef struct __attribute__((__packed__)) gs_gssb_board_status_t {
    /**
       Time since last reboot [s]
     */
    uint32_t seconds_since_boot;
    /**
       Number of reboots
     */
    uint8_t reboot_count;
} gs_gssb_board_status_t;


/**
   ANT6 release status
 */
typedef struct __attribute__((__packed__)) gs_gssb_ant6_release_status_t {
    /**
       Burn state of the first channel (Burning = 1, Idle = 0)
     */
    uint8_t channel_0_state;
    /**
       Release status of the first channel (Released = 1, Not released = 0)
     */
    uint8_t channel_0_status;
    /**
       Burn time left of the first channel [s]
     */
    uint8_t channel_0_burn_time_left;
    /**
       Counter of have many burns there has been attempted
     */
    uint8_t channel_0_burn_tries;
    /**
       Burn state of the second channel (Burning = 1, Idle = 0)
     */
    uint8_t channel_1_state;
    /**
       Release status of the second channel (Released = 1, Not released = 0)
     */
    uint8_t channel_1_status;
    /**
       Burn time left of the second channel [s]
     */
    uint8_t channel_1_burn_time_left;
    /**
       Counter of have many burns there has been attempted
     */
    uint8_t channel_1_burn_tries;
} gs_gssb_ant6_release_status_t;

/**
   I4 release status
 */
typedef struct __attribute__((__packed__)) gs_gssb_i4_release_status_t {
    /**
       Burn state of the first channel (Burning = 1, Idle = 0)
     */
    uint8_t channel_0_state;
    /**
       Release status of the first channel first antenna (Released = 1, Not released = 0)
     */
    uint8_t channel_0_status_0;
    /**
       Release status of the first channel second antenna (Released = 1, Not released = 0)
     */
    uint8_t channel_0_status_1;
    /**
       Burn time left of the first channel [s]
     */
    uint8_t channel_0_burn_time_left;
    /**
       Counter of have many burns there has been attempted
     */
    uint8_t channel_0_burn_tries;
    /**
       Burn state of the second channel (Burning = 1, Idle = 0)
     */
    uint8_t channel_1_state;
    /**
       Release status of the second channel first antenna (Released = 1, Not released = 0)
     */
    uint8_t channel_1_status_0;
    /**
       Release status of the second channel second antenna (Released = 1, Not released = 0)
     */
    uint8_t channel_1_status_1;
    /**
       Burn time left of the second channel [s]
     */
    uint8_t channel_1_burn_time_left;
    /**
       Counter of have many burns there has been attempted
     */
    uint8_t channel_1_burn_tries;
} gs_gssb_i4_release_status_t;

/**
   AR6 release status
 */
typedef struct __attribute__((__packed__)) gs_gssb_ar6_release_status_t {
    /**
       Burn state of the first channel (Burning = 1, Idle = 0)
     */
    uint8_t state;
    /**
       Release status of the first channel (Released = 1, Not released = 0)
     */
    uint8_t status;
    /**
       Burn time left of the first channel [s]
     */
    uint8_t burn_time_left;
    /**
       Counter of have many burns there has been attempted
     */
    uint8_t burn_tries;
} gs_gssb_ar6_release_status_t;

/**
   I4 status
 */
typedef struct __attribute__((__packed__)) gs_gssb_i4_status_t {
    /**
       Release status
     */
    gs_gssb_i4_release_status_t release;
    /**
       Backup status
     */
    gs_gssb_backup_status_t backup;
    /**
       Board status
     */
    gs_gssb_board_status_t board;
} gs_gssb_i4_status_t;

/**
   AR6 status
 */
typedef struct __attribute__((__packed__)) gs_gssb_ar6_status_t {
    /**
       Release status
     */
    gs_gssb_ar6_release_status_t release;
    /**
       Backup status
     */
    gs_gssb_backup_status_t backup;
    /**
       Board status
     */
    gs_gssb_board_status_t board;
} gs_gssb_ar6_status_t;

/**
   ANT6 status
 */
typedef struct __attribute__((__packed__)) gs_gssb_ant6_status_t {
    /**
       Release status
     */
    gs_gssb_ant6_release_status_t release;
    /**
       Backup status
     */
    gs_gssb_backup_status_t backup;
    /**
       Board status
     */
    gs_gssb_board_status_t board;
} gs_gssb_ant6_status_t;

/**
   MASP sensor readings
 */
typedef struct __attribute__((__packed__)) gssb_csp_msp_sensors_t {
    /**
       Outside temperature on solar panel
     */
    int16_t outside_temp;
    /**
       Internal MCU temperature
     */
    int16_t internal_temp;
    /**
       Sun sensor reading
     */
    uint16_t sun_voltage;
} gs_gssb_msp_sensors_t;

/**
   Interstage sensor readings
 */
typedef struct __attribute__((__packed__)) gssb_csp_istage_sensors_t {
    /**
       Sun sensor reading
     */
    uint16_t sun_voltage;
    /**
       Internal MCU temperature
     */
    int16_t internal_temp;
    /**
       Temperature on solar panel
     */
    float panel_temp;
} gs_gssb_istage_sensors_t;

/**
   Backup deploy settings
 */
typedef struct __attribute__((__packed__)) gs_gssb_backup_settings_t {
    /**
       Minutes until deployment
     */
    uint16_t minutes;
    /**
       Backup deployment activation (1 = active, 0 = not active)
     */
    uint8_t backup_active;
    /**
       Maximum burn duration for both backup burn and ordinary burns
     */
    uint8_t max_burn_duration;
} gs_gssb_backup_settings_t;

#ifdef __cplusplus
}
#endif
#endif
