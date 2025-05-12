#ifndef _GS_GSSB_IO_RGSSB_CMD_ID_H_
#define _GS_GSSB_IO_RGSSB_CMD_ID_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Only for internal use

   Contains the cmd IDs used in the rgssb protocol.
*/

#if (GS_GSSB_INTERNAL_USE)
#ifdef __cplusplus
extern "C" {
#endif

enum {
    RGSSB_CMD_NOT_FOUND = 109, /* Answer when command is not found */
    RGSSB_CMD_IDENT, /* Request gssb dev version and uuid */
    RGSSB_CMD_REBOOT, /* Soft reboot */
    RGSSB_CMD_MODEL, /* Get GSSB model */
    RGSSB_CMD_ISTAGE_STATUS, /* Get interstage status */
    RGSSB_CMD_ISTAGE_CONF_GET, /* Get interstage configuration */
    RGSSB_CMD_ISTAGE_CONF_SET, /* Set interstage configuration */
    RGSSB_CMD_ISTAGE_ARM, /* Arm interstage for auto deploy */
    RGSSB_CMD_ISTAGE_DEPLOY, /* Manual deploy antenna */
    RGSSB_CMD_ISTAGE_STATE, /* Get the current interstage state */
    RGSSB_CMD_ISTAGE_SENSORS, /* Read interstage sensors */
    RGSSB_CMD_COMMON_INTERNAL_TEMP, /* Get internal temp */
    RGSSB_CMD_COMMON_STOP_BURN, /* Stop burn */
    RGSSB_CMD_COMMON_RESET_CNT, /* Resets the reboot counter */
    RGSSB_CMD_ANT6_STATUS, /* Get status from ANT6 */
    RGSSB_CMD_COMMON_BURN_CHANNEL, /* Burn on channel for a specific duration */
    RGSSB_CMD_AR6_STATUS, /* Get status from AR6 */
    RGSSB_CMD_AR6_BURN, /* Burn on AR6 for specific duration */
    RGSSB_CMD_MSP_SENSORS, /* Read MSP sensors */
    RGSSB_CMD_SUN_GET_TEMP, /* Read temp */
    RGSSB_CMD_SUN_SAMPLE_TEMP, /* Sample temp */
    RGSSB_CMD_SUN_SAMPLE_GET_TEMP, /* Sample read temp */
    RGSSB_CMD_SUN_GET_SUNSENSOR, /* Read sunsensor */
    RGSSB_CMD_SUN_SAMPLE_SUNSENSOR, /* Sample sunsensor */
    RGSSB_CMD_SUN_SAMPLE_GET_SUNSENSOR, /* Sample read sunsensor */
    RGSSB_CMD_AR6_GET_BACKUP_SETTINGS, /* Get backup deploy settings */
    RGSSB_CMD_AR6_SET_BACKUP_SETTINGS, /* Get backup deploy settings */
    RGSSB_CMD_COMMON_GET_BACKUP_SETTINGS, /* Get backup deploy settings */
    RGSSB_CMD_COMMON_SET_BACKUP_SETTINGS, /* Get backup deploy settings */
    RGSSB_CMD_I4_STATUS /* Get status from I4 */
};

#ifdef __cplusplus
}
#endif
#endif
#endif
