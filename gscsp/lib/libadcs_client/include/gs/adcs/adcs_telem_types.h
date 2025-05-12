/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#ifndef ADCS_TELEM_TYPES_H_
#define ADCS_TELEM_TYPES_H_

#define MAX_NUM_CSS 6
#define MAX_NUM_FSS 8
#define MAX_NUM_EXTMAG 2
#define MAX_NUM_HTPA 4

#include <stdint.h>
#include <stdbool.h>
#include "adcs_statem_types.h"

/* Type def for quaternion type defaulting to unit quaterion*/
typedef struct {
	float q1;	// xi
	float q2;	// yj
	float q3;	// zk
	float q4;	// w (real part)
} quaternion_t;

/****************************************************************************************/
// Horizon sensor telemetry
//---------------------------------------------------------------------------
typedef struct {
    bool valid[MAX_NUM_HTPA];
    uint8_t edge_cnt[MAX_NUM_HTPA]; // Number of edges detected 
    float g_th[MAX_NUM_HTPA];
    float roll[MAX_NUM_HTPA];            // Horizon sensor output [Roll][deg]
    float pitch[MAX_NUM_HTPA];           // Horizon sensor output [Pitch][deg]
    float roll_sc[MAX_NUM_HTPA];
    float pitch_sc[MAX_NUM_HTPA];
    float yaw_sc[MAX_NUM_HTPA];
    float roll_lvlh[MAX_NUM_HTPA];
    float pitch_lvlh[MAX_NUM_HTPA];
    float yaw_lvlh[MAX_NUM_HTPA];
    float Gy[MAX_NUM_HTPA];
    float Gz[MAX_NUM_HTPA];     // Horizon sensor mean gradient [x, y, norm]
    float G[MAX_NUM_HTPA];
    float Cy[MAX_NUM_HTPA];
    float Cz[MAX_NUM_HTPA];          // Horizon coefficients fit on circle [Xc Yc Rc][pixel]
    float Cr[MAX_NUM_HTPA];
    uint16_t time_image[MAX_NUM_HTPA];
    uint16_t time_edge[MAX_NUM_HTPA];
    quaternion_t q_htpa[MAX_NUM_HTPA];
} gs_adcs_htpa_t;

/****************************************************************************************/
/**
 * Structure used to contain the raw sensor data along with the current status
 */
typedef struct {
    float meas[3];
} gs_adcs_meas_t;

typedef struct {
    /* Internal Mag */
	float magnetometer[3]; 					/**< The magnetometer measurementes [mGauss] */
	uint8_t magnetometerValid; 				/**< True if the magnetometer was measured during this iteration */
    gs_adcs_meas_t extmagnetometer[MAX_NUM_EXTMAG];               /**< The magnetometer measurementes [mGauss] */
    float extmagnetometer_temp[MAX_NUM_EXTMAG];             /**< The external magnetometer temperature [degC] */
    uint8_t extmagnetometerValid[MAX_NUM_EXTMAG];           /**< True if the magnetometer was measured during this iteration */

	/* Coarse Sun Sensor */
	float sunsensor[6]; 					/**< The sunsensor measurements [bits 0-1023] */
	uint16_t sunsensor_raw[6]; 				/**< The raw sunsensor measurements [raw bits 0-1023] */
	int16_t sunsensorTemperatures[6]; 		/**< The raw sunsensor temperature measurements [raw bits 0-1023]*/
	uint8_t sunsensorValid; 				/**< True if the sunsensors were measured during this iteration */

	/* Gyroscope */
	float gyro[3]; 							/**< The gyro measurements [deg/s]*/
	float gyro_norm[3]; 					/**< Norm of gyro measurement taken at 50,200 and 500 s intervals */
	float gyro_trend[3]; 					/**< Trend of gyro measurement (derivative of norm measurements)*/
	float gyro_accumulated[3];				/**< Accumulated trend (integrated derivative of the norm)*/
	float gyro_temp; 						/**< Temperature of gyro */
	uint8_t gyroValid; 						/**< True if the gyros were measured during this iteration */
	float extgyro[3];						/**< The gyro measurements [deg/s]*/
	float extgyro_temp; 					/**< Temperature of gyro */
	uint8_t extgyro_valid; 					/**< True if the gyros were measured during this iteration */

	/* Fine Sun Sensor */
	float fss[MAX_NUM_FSS][3]; 				/**< Vectors from Fine sunsensors*/
	float fss_body[MAX_NUM_FSS][3];		    /**< Vectors from Fine sunsensors (in sensor frame)*/
	uint16_t fss_raw[MAX_NUM_FSS][4]; 		/**< Raw data from Fine sunsensors*/
	float fss_temp[MAX_NUM_FSS]; 			/**< Fine sunsensor temperatures */
	uint8_t fssValid[MAX_NUM_FSS]; 			/**< True if Fine sunsensors are valid*/

	/* GPS */
	float gps_pos[3]; 						/**< The gps position [m] in ECEF*/
	float gps_vel[3]; 						/**< The gps velocity [m/s] in ECEF*/
	uint32_t gps_unix; 						/**< GPS Epoch time [unit]*/
	int32_t gps_tdiff_ut; 					/**< Difference in time between GPS and system */
	uint8_t gps_valid;						/**< True if the gps measurements were collected during this iteration */
	uint8_t gps_sat;
	uint8_t gps_satsol;
	uint32_t gps_lastpps_unix;				/**< Latest PPS, Unixtime*/

	/* Star Tracker */
	quaternion_t st_q_raw;					/**< Startracker quat. output, sensor frame */
	quaternion_t st_q_body;					/**< Startracker quat. output, body frame */
	int8_t st_stars; 					    /**< Stars identified by star tracker*/
	uint8_t st_valid;						/**< Startracker valid */
	uint16_t st_exp_time;					/**< Star tracker exposure time */

    /* Horizon Sensor */
    bool htpa_valid[MAX_NUM_HTPA];
    float htpa_roll[MAX_NUM_HTPA];
    float htpa_pitch[MAX_NUM_HTPA];
    quaternion_t q_htpa[MAX_NUM_HTPA];
} gs_adcs_measurementdata_t;

/**
 * Actuator data
 */
typedef struct {
	float   torquerDutyCycle[3];            /**< The torquer duty cycle requested by controller (in Body frame) */
	float   torquerDutyCycleOut[3];         /**< The actual torquer duty cycle applied to torquers (limited and mapped) */
	float 	torquerTempScale[3]; 	        /**< Temperature compensation for the torquers */
	float	wheelTorque[4];                 /**< Assigned wheel torque */
	float	wheelMomentum[4];               /**< Assigned wheel momentum */
	float	wheelSpeed[4];                  /**< Assigned wheel speed */
	uint8_t wheelEnable[4];                 /**< Wheel status in WDE */
	int16_t wheelTemp[4];					/**< Wheel temperature, external [10x deg] */
	uint16_t wheelCur[4];					/**< Wheel current [mA]*/
} gs_adcs_actuatordata_t;

/****************************************************************************************/
/**
 * Structure used to contain status for the ADCS
 */

/**
 * Used at mode selection in the y-spin controller
 */
typedef enum __attribute__ ((packed)) yspin_mode_t {
    YSPIN_IDLE,                 /**< Idle mode	*/
    YSPIN_ECLIPSE,              /**< Satellite in Eclipse */
    YSPIN_ALIGN,                /**< Y axis alignment */
    YSPIN_SPINUP,               /**< Spin around Y axis */
    YSPIN_MWACTIVATION,         /**< Go from Y axis spin to MW ctrl */
    YSPIN_MWCTRL,               /**< MW spinning, satellite pointing */
} yspin_mode_t;

typedef enum __attribute__ ((packed)) lowpower_mode_t {
    LOWPOWER_IDLE,              /**< Idle mode	*/
    LOWPOWER_ALIGN,             /**< Rotate the satellite resulting in one RW is pointing in orbit normal */
    LOWPOWER_BIAS,              /**< Bias the angular momentum in the direction of the orbit normal */
    LOWPOWER_MOMENTUMTRANS,     /**< Transfer net angular momentum to wheel axis in orbit normal */
    LOWPOWER_UNICTRL,           /**< One wheel Pitch control */
} lowpower_mode_t;

typedef struct {
    /* IGRF status 0=OK, -1=Error */
    int8_t igrf;
    /* SGP4 status:      0 - OK
     *                  -1 - mean elements, ecc >= 1.0 or ecc < -0.001 or a < 0.95 er
     *                  -2 - mean motion less than 0.0
     *                  -3 - pert elements, ecc < 0.0  or  ecc > 1.0
     *                  -4 - semi-latus rectum < 0.0
     *                  -5 - epoch elements are sub-orbital
     *                  -6 - satellite has decayed */
    int8_t sgp4;
    /* J2 element status:0 - OK
     *                  -1 - input position vector not valid (below earth surface)
     *                  -2 - input velocity vector not valid (faster than earth surface or slower than 10,000 km)
     *                  -3 - J2 elements invalid because input too old */
    int8_t j2elem;
    /* J2 propagation status: 0 - OK
     *                  -1 - could not solve for true anomaly within specified iterations
     *                  -2 - output position vector not valid (below earth surface)
     *                  -3 - output velocity vector not valid (faster than earth surface or slower than 10,000 km) */
    int8_t j2prop;
    /* Time Error:      0=OK
     *                  -1=time is too early */
    int8_t time;
    /* Overall status:  0=OK
     *                  -1=ephemeris is NOT valid */
    int8_t status;
} gs_adcs_ephem_status_t;

typedef struct {
	/* Magnetometer status:         0=OK
	 *                              -1=mag read error
	 *                              -2=calib index error
	 *                              -3=value error*/
	int8_t mag;
	/* External magnetometer status: 0=OK
	 *                              -1=mag read error
	 *                              -2=calib index error
	 *                              -3=value error*/
	int8_t extmag[MAX_NUM_EXTMAG];
	/* Coarse sunsensor status:     0=OK  */
	int8_t sun;
	/* Fine sunsensor status:       0=OK  */
	int8_t fss[MAX_NUM_FSS];
	/* Gyro status:                 0=OK
	 *                              -1=Not OK */
	int8_t gyro;
	/* External gyro status:        0=OK
	 *                              -1=Invalid sample
	 *                              -2=Used uninitialized */
	int8_t extgyro;
	/* GPS status:                  1=powered
	 *                              0=unpowered */
	int8_t gps;
	/* HTPA status:                 0=OK
	 *                              -1=Error*/
	int8_t htpa[MAX_NUM_HTPA];
    /* Star tracker status
     */
    uint8_t startracker;
} gs_adcs_sensor_status_t;

typedef struct {
	/**< Current sensor status  */
	gs_adcs_sensor_status_t sensorStatus;
	/**< Current bdot status. 1:tumble2detumble  0:valid,  -1:no sample,  -2:no previous sample  -3:detumble2tumble */
	int8_t bdotStatus;
	/**< Current UKF status. 0=OK, -1=nan in estimated state, -2=nan in measurement, -3=wrong array sizes  */
	int8_t ukfStatus;
	/**< Current ephemeris status.  */
	gs_adcs_ephem_status_t ephemStatus;
	/**< Current parameter file status: 2=AutoWrittenFile, 1=UploadedFile, 0=Problem in uploaded file, using partly defaults */
	//int8_t paramStatus;
	/**< Current run status on ADCS. 0=stopped, 1=running, -1=dead*/
	int8_t runStatus;
	/**< Average ADCS loop time in ms (over 50 runs)*/
	uint16_t looptime;
	/**< Maximum ADCS loop time in ms (over the last 50 runs) */
	uint16_t maxlooptime;
	/**< Current status on controllers */
	int8_t ctrlStatus;
} adcs_status_t;

typedef struct {
	/**< adcs code points */
	uint8_t task;
	uint8_t main;
} adcs_debug_t;

typedef struct {
	/**< adcs timing points */
	uint32_t ephem_time;
	uint32_t ads_time;
	uint32_t acs_time;
	uint32_t sensor_time;
} adcs_timing_t;


/**
 * Current and desired determination and control modes
 */
/**
 * Used to determine mode selection within controllers
 */
typedef struct {
	yspin_mode_t yspin_mode;            /**<  Yspin control modes	*/
	lowpower_mode_t lowpower_mode;      /**<  Lowpower control modes	*/
}acs_submode_t;

typedef struct {
    acs_mode_t acs_mode;                /**< Current control mode */
    acs_mode_t desired_acs_mode;        /**< Desired control mode if possible */
    ads_mode_t ads_mode;                /**< Current determination mode */
    ads_mode_t desired_ads_mode;        /**< Desired determination mode if possible */
    ephem_mode_t desired_ephem_mode;    /**< Desired ephemeris mode if possible */
    ephem_mode_t ephem_mode;            /**< Current ephemeris mode */
    acs_submode_t acs_submode;          /**< Submode in Yspin and LP mode */
} adcs_mode_t;

typedef struct {
    float rate[2];
    float diffmag[3];
    float torquerduty[3];
    uint8_t detumbled;                  /**< ADCS Detumbled, 1=True */
} gs_adcs_bdot_data_t;

/****************************************************************************************/
// UKF data struct
//---------------------------------------------------------------------------
/**
 * Define maximum sizes for arrays in client/server packets
 */
#define UKF_MAX_NUM_X 13				// Number of error states - real part of quaternion is not included!
#define UKF_MAX_NUM_ERR 12				// Number of error states - real part of quaternion is not included!
#define UKF_MAX_NUM_Z 14				// z = [v_sun (3), v_mag (3), v_fss (3), htpa (2: roll + pitch), q_startrack (3: q[0-2])]
#define UKF_MAX_NUM_SENS 45				// 6*css, 3*mag, 3*8*fss, 4*2*htpa, 4*startracker
#define MAX_NUM_SP (UKF_MAX_NUM_ERR*2+1)

// NOTE: All UKF vars are declared of MAX length, but may be used with smaller length depending on config.
typedef struct {
    // Statevector:
    // [q1 q2 q3 q4 w1 w2 w3 bm1 bm2 bm3 bg1 bg2 bg3]
    // [0  1  2  3  4  5  6  7   8   9   10  11  12 ]
    float EstimatedState[UKF_MAX_NUM_X];    // State vector estimated by UKF (X)
    float q[4];                             // Quaterion (duplicate from estimated state)
    float w[3];                             // rate (duplicate from estimated state)
    float Pdiag[UKF_MAX_NUM_ERR];           // Covariance matrix diagonal
    float Xpred[UKF_MAX_NUM_X];             // Copy of predicted state
    float Zpred[UKF_MAX_NUM_Z];             // Copy of predicted measurement
    float Pzzdiag[UKF_MAX_NUM_Z];           // Innovation Covariance matrix diagonal
    float sunsensorMax[6];                  // Current maximum value for the sunsensor max tracking algorithm
    uint8_t InEclipse;                      // UKF eclipse detection
    int8_t KFchoice;                        // Which KF is running ?
    float q_UKF_est[4];                     // holds the UKF estimate of q_I_SC through ST override
    float q_ST_est[4];                      // holds the ST estimate of q_I_SC
} GS_ADCS_UKF_Data_t;

// UKF measurement struct
//---------------------------------------------------------------------------
typedef struct {
    float Measurement[UKF_MAX_NUM_SENS];    // Sensor vector
    float MeasurementFilt[UKF_MAX_NUM_Z];   // Filtered sensorVector (Z) [sun1 sun2 sun3 mag1 mag2 mag3 fss1 fss2 fss3 htpa1 htpa2 st1 st2 st3]
    uint8_t Enable[UKF_MAX_NUM_Z];          // Enable vector for measurements (set to zero to disable sensor)
    bool stValidForOverride;                // this star tracker measurement is valid for override
} GS_ADCS_UKF_Measurement_t;

// UKF input struct
//---------------------------------------------------------------------------
typedef struct {
    float CtrlTorques[3];                   // control torque vector
    float CtrlMomentum[3];                  // control momentum vector
    float Rate[3];                          // Rate measurement
} GS_ADCS_UKF_Inputs_t;

/****************************************************************************************/
// Ephemeris
//---------------------------------------------------------------------------
typedef struct {
    double julianDate;
    float scRECI[3];            // [m] Space craft pos in ECI
    float scVECI[3];            // [m/s] Space craft vel in ECI
    float sunECI[3];            // Sun vector
    float magECI[3];            // Magnetic field [nT]
    float dmagECI[3];           // Derivative of Magnetic field [nT]
    quaternion_t rotationIE;    // Rotation from ECI to ECEF frame
    int timeSinceEclipse;       // Number of samples since satellite came out of eclipse - if 0 then we're in eclipse. Max value: 10.000
    quaternion_t rotationIO;    // Rotation from ECI to orbit frame
    quaternion_t rotationIL;    // Rotation from ECI to LVLH frame
    float rateIO[3];            // Rotation rate from ECI to orbit frame
    float rateIL[3];            // Rotation rate from ECI to LVLH frame
} gs_adcs_ephem_t;

// defines the orbit elements at a given epoch
typedef struct {
    double epoch;               // [julianDate] epoch
    float pos_ECI[3];           // [km] ECI position vector translated from GPS used to generate the elements
    float vel_ECI[3];           // [km] ECI position vector translated from GPS used to generate the elements
    float ecc;                  // eccentricity
    float a;                    // [km] semi-major axis
    float n;                    // [rad/s] mean motion
    float p;                    // [km] parameter
    float incl;                 // [rad] inclination
    float raan;                 // [rad] right ascension of the ascending node
    float argPer;               // [rad] argument of perigee
    float trueAnom;             // [rad] true anomaly
    float eccAnom;              // [rad] eccentric anomaly
    float meanAnom;	            // [rad] mean anomaly
} gs_adcs_elem_t;



/****************************************************************************************/
// CTRL
//---------------------------------------------------------------------------
// Type def for controller
typedef struct {
    quaternion_t ref_q;         // Reference quaternion
    quaternion_t err_q;         // Error quaternion
    quaternion_t ierr_q;        // Integral error quaternion
    float err_rate[3];          // Error rate [rad/s}
    float M[3];                 // Control signal, magnetic moment [Am^2]
    float mw_torque[4];         // Control signal, Wheel torque
    float mw_speed[4];          // Wheel speed
    float mw_momentum[4];       // Control signal, Wheel momentum
    float ref_rate[3];          // Y-Thomson spin rate reference
    float euler_offset[3];      //RAM mode euler rotation offset [x y z]
    float offset_err[3];        // Ram error i Euler angles
    float bodyTorque[3];        // Torque at bodyframe axes
    float bodyMomentum[3];      // Momentum at bodyframe axes
} gs_adcs_ctrl_t;
/****************************************************************************************/


/****************************************************************************************/


/**
 * Telemetry tables
 */
typedef struct {
    gs_adcs_measurementdata_t sensordata;
    gs_adcs_actuatordata_t actdata;
} gs_adcs_telem1_t;

typedef struct {
    adcs_mode_t mode;
    adcs_status_t status;
    gs_adcs_bdot_data_t bdot;
    adcs_debug_t debug;
} gs_adcs_telem2_t;

typedef struct {
    GS_ADCS_UKF_Data_t ukfdata;
    GS_ADCS_UKF_Measurement_t ukfmeas;
    GS_ADCS_UKF_Inputs_t ukfinput;
} gs_adcs_telem3_t;

typedef struct {
    gs_adcs_ephem_t ephem;
    gs_adcs_elem_t elem;
} gs_adcs_telem4_t;

typedef struct {
    gs_adcs_ctrl_t ctrldata;
} gs_adcs_telem5_t;

typedef struct {
    gs_adcs_htpa_t htpadata;
} gs_adcs_telem6_t;

typedef struct {
    adcs_timing_t timing;
} gs_adcs_telem7_t;

#endif /* ADCS_TELEM_TYPES_H_ */
