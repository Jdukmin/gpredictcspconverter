ADCS (libadcs_client)
=====================

**6.0.2 (2020-03-26)**

- Improvement: Updated dependencies
- Bug: fixed array size in adcs_telem3_152.json for UKF from 15 to 14. 

**6.0.1 (2019-12-12)**

- Improvement: Reintroduced stylecheck

**6.0.0 (2019-11-01)**

- Breaking: Added new parameters for Startracker implementation in the UKF

**5.1.0 (2019-03-28)**

- Improvement: Added Variable Frequency (VARF) as a parameter (en_gps_varf) 
- Improvement: Split pwm_deadtime into mtq_decay_t and mag_sample_t. This allows for tuning based on the placement and number of magnetometers. 

**5.0.3 (2019-03-01)**

- Bug: Torquerduty was not reported in body frame

**5.0.2 (2019-02-21)**

- Improvement: Updated documentation.

**5.0.1 (2019-02-07)**

- Improvement: Updated json telemetry tables to match acutal tables 

**5.0.0 (2019-02-01)**

- Breaking: Removed STR from table sensors_common and added its own
- Breaking: Updated GPS parameters in sensors_common
- Breaking: Updated telemetry table1 layout
- Breaking: Moved css_{initmax, absmax, th} the the sensor_css table, with the names max_init, abs_max and threshold
- Breaking: Moved tleline1, tleline2 and teme2eci from gnc_ads to gnc_common
- Feature: Added sun pointing mode
- Feature: Added orbit pointing mode
- Feature: Added handle to control VARF

**4.0.0 (2018-01-04)**

- Improvement: Updated documentation for libadcs 4.0.0

**3.3.1 (2018-12-20)**

- Improvement: Updated documentation.

**3.3.0 (2018-11-22)**

- Breaking: Updated the reaction wheel parameter table. It now assumes all wheels are the same type.
- Breaking: Created a new table to represent the on-board (internal) sensors of the A3200 (mpu3300 and hmc5843)
- Bug: Updated the GOSH command `gps ascii <timout> <cmd>` so it can't crash the A3200 on garbage input

**3.2.2 (2018-09-24)**

- Improvement: Separated solar panel control out to its own repository
- Improvement: Added a `type` field to the CSS parameter table
- Bug: Fixed an error where reading the `suns_semp` parameter would return garbage data

**3.2.0 (2018-09-19)**

- Feature: Initial SDK version
