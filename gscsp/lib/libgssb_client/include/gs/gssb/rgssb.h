#ifndef _GS_RGSSB_IO_GSSB_H_
#define _GS_RGSSB_IO_GSSB_H_
/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
/**
   @file

   Remote GSSB API
*/

#include <stdint.h>
#include <gs/util/error.h>
#include <gs/gssb/gssb.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
   RGSSB destination conf
 */
typedef struct __attribute__((__packed__)) rgssb_dest_t {
    /**
       CSP node for host
     */
    uint8_t csp_node;
    /**
       CSP timeout [ms]
     */
    uint16_t csp_timeout;
    /**
       CSP port for host
     */
    uint8_t csp_port;
    /**
       I2C address of GSSB board connected to host
     */
    uint8_t i2c_addr;
    /**
       I2C timeout [ms]
     */
    uint16_t i2c_timeout;
} gs_rgssb_dest_t;

/**
   Get software version and uuid. 

   Gets the 20 character long version tag from the device. 
   Gets the 4 byte uuid.
   Generic GSSB cmd.

   @see gs_gssb_ident_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] id SW version and uuid.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ident(gs_rgssb_dest_t dest, gs_gssb_ident_t * id);

/**
   Software reset.

   Resets GSSB MCU from software. Generic GSSB cmd.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_reboot(gs_rgssb_dest_t dest);

/**
   Get model type. 

   Gets the GSSB device type at the given destination. 
   Generic GSSB cmd.

   @see gs_gssb_model_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] model Device type.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_model(gs_rgssb_dest_t dest, gs_gssb_model_t * model);

/**
   Get ant6 status. 

   @see gs_gssb_ant6_status_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] status Status.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ant6_status(gs_rgssb_dest_t dest, gs_gssb_ant6_status_t * status);

/**
   Get ant6 internal MCU temperature.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] internal_temp Temperature.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ant6_internal_temp(gs_rgssb_dest_t dest, int16_t * internal_temp);

/**
   Burn ant6 channel.

   Burns a specific duration on the specific channel (side).

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] channel Channel to be burned on (1 = closest MCU, 0 = farthest from MCU).
   @param[in] burn_seconds Duration in seconds to burn.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ant6_burn_channel(gs_rgssb_dest_t dest, uint8_t channel, uint8_t burn_seconds);

/**
   Stop ant6 burn.

   Stops burning on both channels.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ant6_stop_burn(gs_rgssb_dest_t dest);

/**
   Reset ant6 counters.

   Resets both reboot counter and burn counters.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ant6_reset_count(gs_rgssb_dest_t dest);

/**
   Get ant6 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] settings Settings.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ant6_get_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t * settings);

/**
   Set ant6 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] settings Settings.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ant6_set_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t settings);

/**
   Get i4 status. 

   @see gs_gssb_i4_status_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] status Status.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_i4_status(gs_rgssb_dest_t dest, gs_gssb_i4_status_t * status);

/**
   Get i4 internal MCU temperature.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] internal_temp Temperature.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_i4_internal_temp(gs_rgssb_dest_t dest, int16_t * internal_temp);

/**
   Burn i4 channel.

   Burns a specific duration on the specific channel.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] channel Channel to be burned on.
   @param[in] burn_seconds Duration in seconds to burn.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_i4_burn_channel(gs_rgssb_dest_t dest, uint8_t channel, uint8_t burn_seconds);

/**
   Stop i4 burn.

   Stops burning on all channels.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_i4_stop_burn(gs_rgssb_dest_t dest);

/**
   Reset i4 counters.

   Resets both reboot counter and burn counters.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_i4_reset_count(gs_rgssb_dest_t dest);

/**
   Get i4 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] settings Settings.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_i4_get_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t * settings);

/**
   Set i4 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] settings Settings.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_i4_set_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t settings);

/**
   Get ar6 status. 

   @see gs_gssb_ar6_status_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] status Status.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ar6_status(gs_rgssb_dest_t dest, gs_gssb_ar6_status_t * status);

/**
   Get ar6 internal MCU temperature.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] internal_temp Temperature.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ar6_internal_temp(gs_rgssb_dest_t dest, int16_t * internal_temp);

/**
   Burn ar6.

   Burns a specific duration.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] burn_seconds Duration in seconds to burn.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ar6_burn(gs_rgssb_dest_t dest, uint8_t burn_seconds);

/**
   Stop ar6 burn.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ar6_stop_burn(gs_rgssb_dest_t dest);

/**
   Reset ar6 counters.

   Resets both reboot counter and burn counters.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ar6_reset_count(gs_rgssb_dest_t dest);

/**
   Get ar6 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] settings Settings.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ar6_get_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t * settings);

/**
   Set ar6 backup settings.

   @see gs_gssb_backup_settings_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] settings Settings.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_ar6_set_backup_settings(gs_rgssb_dest_t dest, gs_gssb_backup_settings_t settings);

/**
   Get istage status.

   @see gs_gssb_istage_status_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] status Status.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_istage_status(gs_rgssb_dest_t dest, gs_gssb_istage_status_t * status);

/**
   Get istage sensors.

   @see gs_gssb_istage_sensors_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] sensors Sensors.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_istage_sensors(gs_rgssb_dest_t dest, gs_gssb_istage_sensors_t * sensors);

/**
   Manual deploy istage.

   Makes the interstages deploy, when it is armed for manual deploy.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_istage_deploy(gs_rgssb_dest_t dest);

/**
   Set istage arm auto mode.

   Arms or disarms the interstage for autodeploy.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] arm CMD (0x01 = ARMED FOR AUTO, 0x00 = DISARMED).
   @return_gs_error_t
*/
gs_error_t gs_rgssb_istage_arm(gs_rgssb_dest_t dest, uint8_t arm);

/**
   Set istage arm manual mode.

   Arms or disarms the interstage for manual deploy.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] state CMD (0x01 = ARMED FOR MANUAL, 0x00 = DISARMED).
   @return_gs_error_t
*/
gs_error_t gs_rgssb_istage_set_state(gs_rgssb_dest_t dest, uint8_t state);

/**
   Get istage burn settings.

   @see gs_gssb_istage_burn_settings_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] settings Settings.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_istage_settings_get(gs_rgssb_dest_t dest, gs_gssb_istage_burn_settings_t * settings);

/**
   Get istage burn settings.

   @see gs_gssb_istage_burn_settings_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] settings Settings.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_istage_settings_set(gs_rgssb_dest_t dest, gs_gssb_istage_burn_settings_t * settings);

/**
   Get msp sensors.

   @see gs_gssb_msp_sensors_t

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] sensors Sensors.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_msp_sensors(gs_rgssb_dest_t dest, gs_gssb_msp_sensors_t * sensors);

/**
   Reset msp counters.

   Resets reboot counter.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_msp_reset_count(gs_rgssb_dest_t dest);

/**
   Get sun sensor.

   Gets the sunsensors four measurements (4 * uint16).

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] count Number of samples to return (at most 4).
   @param[out] sun Pointer to array of four measurements.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_sunsensor_get_data(gs_rgssb_dest_t dest, uint16_t *sun, uint8_t count);

/**
   Sample sun sensor.

   Makes the sunsensor sample measurements.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_sunsensor_sample_data(gs_rgssb_dest_t dest);

/**
   Sample and get sun sensor.

   Samples and gets the sunsensors four measurements (4 * uint16). 
   Includes delays for letting sun sensor sample.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] count Number of samples to return (at most 4).
   @param[out] sun Pointer to array of four measurements.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_sunsensor_sample_get_data(gs_rgssb_dest_t dest, uint16_t *sun, uint8_t count);

/**
   Sample sun sensor temp.

   Makes the sunsensor sample temperature.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[in] temp Temperature.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_sunsensor_get_temp(gs_rgssb_dest_t dest, float *temp);

/**
   Get sun sensor temperature.

   Gets the sunsensors temperature.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_sunsensor_sample_temp(gs_rgssb_dest_t dest);

/**
   Sample and get sun sensor temperature.

   Samples and gets the sunsensors temperature.
   Includes delays for letting sun sensor sample.

   @param[in] dest Destination, containing CSP node, I2C addr and timeouts.
   @param[out] temp Temperature.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_sunsensor_sample_get_temp(gs_rgssb_dest_t dest, float *temp);

/**
   Register remote commands.
   @return_gs_error_t
*/
gs_error_t gs_rgssb_register_commands(void);

#ifdef __cplusplus
}
#endif
#endif
