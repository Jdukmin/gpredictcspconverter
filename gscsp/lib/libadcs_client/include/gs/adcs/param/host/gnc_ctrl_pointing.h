#ifndef GS_ADCS_PARAM_HOST_GNC_CTRL_POINTING_H
#define GS_ADCS_PARAM_HOST_GNC_CTRL_POINTING_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions (host) for \a gnc_ctrl_pointing.
*/

#include <gs/adcs/param/gnc_ctrl_pointing.h>
#include <gs/param/table.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Table rows (layout). */
extern const gs_param_table_row_t gs_adcs_gnc_ctrl_pointing_table[];

/** Table data memory as a C struct. */
typedef struct __attribute__ ((packed)) {
    /** Sliding Mode Controller gain for MW, [Ks, Lambda, epsilon] */
    float    mw_smc[3];
    /** Gain used by the wheel controller [Common, K1, K2] */
    float    mw_gain[3];
    /** Momentum dunping sign and gain */
    float    mw_dumpgain;
    /** Option to reverse and scale mw 2 torquer assign */
    float    mw_mw2trq;
    /** The reaction wheel nullspace vector is used for the reaction wheel momentum management, null(rw_mapping[3x4]) */
    float    mw_mannull[4];
    /** The Reaction wheel momentum management gain, ajusts the transient time */
    float    mw_mangain;
    /** The reaction wheel momentum offset, biasing the reaction wheels [Nms] */
    float    mw_manoffset;
    /** Pointing offset between orbit- and body frame */
    float    euler_offset[3];
    /** Rate offset between orbit- and body frame */
    float    rate_offset[3];
    /** Body axis momentum reference [Nms] */
    float    ref_momentum[3];
    /** Enable MW momentum dumping */
    bool     en_mwdump;
    /** Enable MW momentum management */
    bool     en_mwman;
    /** BBQ parameters, [Enable, Ref */
    uint8_t  en_bbq[2];
    /** Enable/select which landmark to track, the antenna to use and coordinate system [gso, ant, coord] */
    uint8_t  en_gso[3];
    /** Mode used to track ground stations when they are close and else fly RAM */
    uint8_t  en_gstrack[2];
    /** Mode to change the reference vector to point at the sun */
    bool     en_sunpoint;
    /** Filler for alignment */
    uint8_t  _filler_0x0066[2];
    /** 3-2-1 Euler rotation from satellite to orbit */
    float    nadir[3];
    /** 3-2-1 Euler rotation from satellite to orbit */
    float    ram[3];
    /** 3-2-1 Euler rotation from satellite to orbit */
    float    mindrag[3];
    /** 3-2-1 Euler rotation from satellite to orbit */
    float    maxdrag[3];
    /** List of ECEF coordinates of 3 ground stations [GS1] [GS2] [GS3] */
    float    gs_list[9];
    /** List of euler offset to track ground station */
    float    gs_offset[9];
    /** Landmark ECEF [ECEF1 ECEF2 ECEF3] */
    float    gso_list[9];
    /** Antenna offset in body frame Euler angles [Ant1 Ant2 Ant3] */
    float    gso_ant[9];
    /** ECEF Landmark to track */
    float    target0[3];
    /** ECEF Landmark to track */
    float    target1[3];
    /** ECEF Landmark to track */
    float    target2[3];
    /** 3-2-1 Euler rotation from satellite to orbit */
    float    custom0[3];
    /** 3-2-1 Euler rotation from satellite to orbit */
    float    custom1[3];
    /** 3-2-1 Euler rotation from satellite to orbit */
    float    custom2[3];
} gs_adcs_gnc_ctrl_pointing_memory_t;

/** Table default values. */
extern const gs_adcs_gnc_ctrl_pointing_memory_t gs_adcs_gnc_ctrl_pointing_default_values;

/**
   @defgroup param_getters_setters Table getters/setters based on table id.
   @note include <gs/param/host_table.h> in order to use these macros.
   @{
*/
/** Set mw_smc: Sliding Mode Controller gain for MW, [Ks, Lambda, epsilon] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_SMC_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_SMC(idx), value, 0)
/** Set mw_smc (no callback): Sliding Mode Controller gain for MW, [Ks, Lambda, epsilon] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_SMC_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_SMC(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mw_smc: Sliding Mode Controller gain for MW, [Ks, Lambda, epsilon] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_SMC_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_SMC(idx), value, 0)
/** Get mw_smc (no check - return 0 on failure): Sliding Mode Controller gain for MW, [Ks, Lambda, epsilon] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_SMC_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_SMC(idx), 0)
/** Set mw_gain: Gain used by the wheel controller [Common, K1, K2] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_GAIN_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_GAIN(idx), value, 0)
/** Set mw_gain (no callback): Gain used by the wheel controller [Common, K1, K2] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_GAIN_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_GAIN(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mw_gain: Gain used by the wheel controller [Common, K1, K2] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_GAIN_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_GAIN(idx), value, 0)
/** Get mw_gain (no check - return 0 on failure): Gain used by the wheel controller [Common, K1, K2] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_GAIN_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_GAIN(idx), 0)
/** Set mw_dumpgain: Momentum dunping sign and gain */
#define GS_ADCS_GNC_CTRL_POINTING_MW_DUMPGAIN_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_DUMPGAIN, value, 0)
/** Set mw_dumpgain (no callback): Momentum dunping sign and gain */
#define GS_ADCS_GNC_CTRL_POINTING_MW_DUMPGAIN_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_DUMPGAIN, value, GS_PARAM_F_NO_CALLBACK)
/** Get mw_dumpgain: Momentum dunping sign and gain */
#define GS_ADCS_GNC_CTRL_POINTING_MW_DUMPGAIN_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_DUMPGAIN, value, 0)
/** Get mw_dumpgain (no check - return 0 on failure): Momentum dunping sign and gain */
#define GS_ADCS_GNC_CTRL_POINTING_MW_DUMPGAIN_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_DUMPGAIN, 0)
/** Set mw_mw2trq: Option to reverse and scale mw 2 torquer assign */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MW2TRQ_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MW2TRQ, value, 0)
/** Set mw_mw2trq (no callback): Option to reverse and scale mw 2 torquer assign */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MW2TRQ_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MW2TRQ, value, GS_PARAM_F_NO_CALLBACK)
/** Get mw_mw2trq: Option to reverse and scale mw 2 torquer assign */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MW2TRQ_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MW2TRQ, value, 0)
/** Get mw_mw2trq (no check - return 0 on failure): Option to reverse and scale mw 2 torquer assign */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MW2TRQ_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MW2TRQ, 0)
/** Set mw_mannull: The reaction wheel nullspace vector is used for the reaction wheel momentum management, null(rw_mapping[3x4]) */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANNULL_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANNULL(idx), value, 0)
/** Set mw_mannull (no callback): The reaction wheel nullspace vector is used for the reaction wheel momentum management, null(rw_mapping[3x4]) */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANNULL_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANNULL(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mw_mannull: The reaction wheel nullspace vector is used for the reaction wheel momentum management, null(rw_mapping[3x4]) */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANNULL_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANNULL(idx), value, 0)
/** Get mw_mannull (no check - return 0 on failure): The reaction wheel nullspace vector is used for the reaction wheel momentum management, null(rw_mapping[3x4]) */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANNULL_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANNULL(idx), 0)
/** Set mw_mangain: The Reaction wheel momentum management gain, ajusts the transient time */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANGAIN_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANGAIN, value, 0)
/** Set mw_mangain (no callback): The Reaction wheel momentum management gain, ajusts the transient time */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANGAIN_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANGAIN, value, GS_PARAM_F_NO_CALLBACK)
/** Get mw_mangain: The Reaction wheel momentum management gain, ajusts the transient time */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANGAIN_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANGAIN, value, 0)
/** Get mw_mangain (no check - return 0 on failure): The Reaction wheel momentum management gain, ajusts the transient time */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANGAIN_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANGAIN, 0)
/** Set mw_manoffset: The reaction wheel momentum offset, biasing the reaction wheels [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANOFFSET_SET(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANOFFSET, value, 0)
/** Set mw_manoffset (no callback): The reaction wheel momentum offset, biasing the reaction wheels [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANOFFSET_SET_NO_CALLBACK(value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANOFFSET, value, GS_PARAM_F_NO_CALLBACK)
/** Get mw_manoffset: The reaction wheel momentum offset, biasing the reaction wheels [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANOFFSET_GET(value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANOFFSET, value, 0)
/** Get mw_manoffset (no check - return 0 on failure): The reaction wheel momentum offset, biasing the reaction wheels [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANOFFSET_GET_NC() gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MW_MANOFFSET, 0)
/** Set euler_offset: Pointing offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_EULER_OFFSET_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EULER_OFFSET(idx), value, 0)
/** Set euler_offset (no callback): Pointing offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_EULER_OFFSET_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EULER_OFFSET(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get euler_offset: Pointing offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_EULER_OFFSET_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EULER_OFFSET(idx), value, 0)
/** Get euler_offset (no check - return 0 on failure): Pointing offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_EULER_OFFSET_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EULER_OFFSET(idx), 0)
/** Set rate_offset: Rate offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_RATE_OFFSET_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_RATE_OFFSET(idx), value, 0)
/** Set rate_offset (no callback): Rate offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_RATE_OFFSET_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_RATE_OFFSET(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get rate_offset: Rate offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_RATE_OFFSET_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_RATE_OFFSET(idx), value, 0)
/** Get rate_offset (no check - return 0 on failure): Rate offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_RATE_OFFSET_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_RATE_OFFSET(idx), 0)
/** Set ref_momentum: Body axis momentum reference [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_REF_MOMENTUM_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_REF_MOMENTUM(idx), value, 0)
/** Set ref_momentum (no callback): Body axis momentum reference [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_REF_MOMENTUM_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_REF_MOMENTUM(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get ref_momentum: Body axis momentum reference [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_REF_MOMENTUM_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_REF_MOMENTUM(idx), value, 0)
/** Get ref_momentum (no check - return 0 on failure): Body axis momentum reference [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_REF_MOMENTUM_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_REF_MOMENTUM(idx), 0)
/** Set en_mwdump: Enable MW momentum dumping */
#define GS_ADCS_GNC_CTRL_POINTING_EN_MWDUMP_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_MWDUMP, value, 0)
/** Set en_mwdump (no callback): Enable MW momentum dumping */
#define GS_ADCS_GNC_CTRL_POINTING_EN_MWDUMP_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_MWDUMP, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_mwdump: Enable MW momentum dumping */
#define GS_ADCS_GNC_CTRL_POINTING_EN_MWDUMP_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_MWDUMP, value, 0)
/** Get en_mwdump (no check - return 0 on failure): Enable MW momentum dumping */
#define GS_ADCS_GNC_CTRL_POINTING_EN_MWDUMP_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_MWDUMP, 0)
/** Set en_mwman: Enable MW momentum management */
#define GS_ADCS_GNC_CTRL_POINTING_EN_MWMAN_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_MWMAN, value, 0)
/** Set en_mwman (no callback): Enable MW momentum management */
#define GS_ADCS_GNC_CTRL_POINTING_EN_MWMAN_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_MWMAN, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_mwman: Enable MW momentum management */
#define GS_ADCS_GNC_CTRL_POINTING_EN_MWMAN_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_MWMAN, value, 0)
/** Get en_mwman (no check - return 0 on failure): Enable MW momentum management */
#define GS_ADCS_GNC_CTRL_POINTING_EN_MWMAN_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_MWMAN, 0)
/** Set en_bbq: BBQ parameters, [Enable, Ref */
#define GS_ADCS_GNC_CTRL_POINTING_EN_BBQ_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_BBQ(idx), value, 0)
/** Set en_bbq (no callback): BBQ parameters, [Enable, Ref */
#define GS_ADCS_GNC_CTRL_POINTING_EN_BBQ_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_BBQ(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get en_bbq: BBQ parameters, [Enable, Ref */
#define GS_ADCS_GNC_CTRL_POINTING_EN_BBQ_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_BBQ(idx), value, 0)
/** Get en_bbq (no check - return 0 on failure): BBQ parameters, [Enable, Ref */
#define GS_ADCS_GNC_CTRL_POINTING_EN_BBQ_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_BBQ(idx), 0)
/** Set en_gso: Enable/select which landmark to track, the antenna to use and coordinate system [gso, ant, coord] */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSO_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_GSO(idx), value, 0)
/** Set en_gso (no callback): Enable/select which landmark to track, the antenna to use and coordinate system [gso, ant, coord] */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSO_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_GSO(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get en_gso: Enable/select which landmark to track, the antenna to use and coordinate system [gso, ant, coord] */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSO_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_GSO(idx), value, 0)
/** Get en_gso (no check - return 0 on failure): Enable/select which landmark to track, the antenna to use and coordinate system [gso, ant, coord] */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSO_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_GSO(idx), 0)
/** Set en_gstrack: Mode used to track ground stations when they are close and else fly RAM */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSTRACK_SET(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_GSTRACK(idx), value, 0)
/** Set en_gstrack (no callback): Mode used to track ground stations when they are close and else fly RAM */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSTRACK_SET_NO_CALLBACK(idx, value) gs_param_set_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_GSTRACK(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get en_gstrack: Mode used to track ground stations when they are close and else fly RAM */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSTRACK_GET(idx, value) gs_param_get_uint8(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_GSTRACK(idx), value, 0)
/** Get en_gstrack (no check - return 0 on failure): Mode used to track ground stations when they are close and else fly RAM */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSTRACK_GET_NC(idx) gs_param_get_uint8_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_GSTRACK(idx), 0)
/** Set en_sunpoint: Mode to change the reference vector to point at the sun */
#define GS_ADCS_GNC_CTRL_POINTING_EN_SUNPOINT_SET(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_SUNPOINT, value, 0)
/** Set en_sunpoint (no callback): Mode to change the reference vector to point at the sun */
#define GS_ADCS_GNC_CTRL_POINTING_EN_SUNPOINT_SET_NO_CALLBACK(value) gs_param_set_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_SUNPOINT, value, GS_PARAM_F_NO_CALLBACK)
/** Get en_sunpoint: Mode to change the reference vector to point at the sun */
#define GS_ADCS_GNC_CTRL_POINTING_EN_SUNPOINT_GET(value) gs_param_get_bool(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_SUNPOINT, value, 0)
/** Get en_sunpoint (no check - return 0 on failure): Mode to change the reference vector to point at the sun */
#define GS_ADCS_GNC_CTRL_POINTING_EN_SUNPOINT_GET_NC() gs_param_get_bool_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_EN_SUNPOINT, 0)
/** Set nadir: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_NADIR_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_NADIR(idx), value, 0)
/** Set nadir (no callback): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_NADIR_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_NADIR(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get nadir: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_NADIR_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_NADIR(idx), value, 0)
/** Get nadir (no check - return 0 on failure): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_NADIR_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_NADIR(idx), 0)
/** Set ram: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_RAM_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_RAM(idx), value, 0)
/** Set ram (no callback): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_RAM_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_RAM(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get ram: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_RAM_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_RAM(idx), value, 0)
/** Get ram (no check - return 0 on failure): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_RAM_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_RAM(idx), 0)
/** Set mindrag: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MINDRAG_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MINDRAG(idx), value, 0)
/** Set mindrag (no callback): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MINDRAG_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MINDRAG(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get mindrag: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MINDRAG_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MINDRAG(idx), value, 0)
/** Get mindrag (no check - return 0 on failure): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MINDRAG_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MINDRAG(idx), 0)
/** Set maxdrag: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MAXDRAG_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MAXDRAG(idx), value, 0)
/** Set maxdrag (no callback): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MAXDRAG_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MAXDRAG(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get maxdrag: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MAXDRAG_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MAXDRAG(idx), value, 0)
/** Get maxdrag (no check - return 0 on failure): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MAXDRAG_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_MAXDRAG(idx), 0)
/** Set gs_list: List of ECEF coordinates of 3 ground stations [GS1] [GS2] [GS3] */
#define GS_ADCS_GNC_CTRL_POINTING_GS_LIST_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GS_LIST(idx), value, 0)
/** Set gs_list (no callback): List of ECEF coordinates of 3 ground stations [GS1] [GS2] [GS3] */
#define GS_ADCS_GNC_CTRL_POINTING_GS_LIST_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GS_LIST(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get gs_list: List of ECEF coordinates of 3 ground stations [GS1] [GS2] [GS3] */
#define GS_ADCS_GNC_CTRL_POINTING_GS_LIST_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GS_LIST(idx), value, 0)
/** Get gs_list (no check - return 0 on failure): List of ECEF coordinates of 3 ground stations [GS1] [GS2] [GS3] */
#define GS_ADCS_GNC_CTRL_POINTING_GS_LIST_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GS_LIST(idx), 0)
/** Set gs_offset: List of euler offset to track ground station */
#define GS_ADCS_GNC_CTRL_POINTING_GS_OFFSET_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GS_OFFSET(idx), value, 0)
/** Set gs_offset (no callback): List of euler offset to track ground station */
#define GS_ADCS_GNC_CTRL_POINTING_GS_OFFSET_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GS_OFFSET(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get gs_offset: List of euler offset to track ground station */
#define GS_ADCS_GNC_CTRL_POINTING_GS_OFFSET_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GS_OFFSET(idx), value, 0)
/** Get gs_offset (no check - return 0 on failure): List of euler offset to track ground station */
#define GS_ADCS_GNC_CTRL_POINTING_GS_OFFSET_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GS_OFFSET(idx), 0)
/** Set gso_list: Landmark ECEF [ECEF1 ECEF2 ECEF3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_LIST_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GSO_LIST(idx), value, 0)
/** Set gso_list (no callback): Landmark ECEF [ECEF1 ECEF2 ECEF3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_LIST_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GSO_LIST(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get gso_list: Landmark ECEF [ECEF1 ECEF2 ECEF3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_LIST_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GSO_LIST(idx), value, 0)
/** Get gso_list (no check - return 0 on failure): Landmark ECEF [ECEF1 ECEF2 ECEF3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_LIST_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GSO_LIST(idx), 0)
/** Set gso_ant: Antenna offset in body frame Euler angles [Ant1 Ant2 Ant3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_ANT_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GSO_ANT(idx), value, 0)
/** Set gso_ant (no callback): Antenna offset in body frame Euler angles [Ant1 Ant2 Ant3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_ANT_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GSO_ANT(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get gso_ant: Antenna offset in body frame Euler angles [Ant1 Ant2 Ant3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_ANT_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GSO_ANT(idx), value, 0)
/** Get gso_ant (no check - return 0 on failure): Antenna offset in body frame Euler angles [Ant1 Ant2 Ant3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_ANT_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_GSO_ANT(idx), 0)
/** Set target0: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET0_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET0(idx), value, 0)
/** Set target0 (no callback): ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET0_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET0(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get target0: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET0_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET0(idx), value, 0)
/** Get target0 (no check - return 0 on failure): ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET0_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET0(idx), 0)
/** Set target1: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET1_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET1(idx), value, 0)
/** Set target1 (no callback): ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET1_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET1(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get target1: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET1_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET1(idx), value, 0)
/** Get target1 (no check - return 0 on failure): ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET1_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET1(idx), 0)
/** Set target2: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET2_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET2(idx), value, 0)
/** Set target2 (no callback): ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET2_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET2(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get target2: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET2_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET2(idx), value, 0)
/** Get target2 (no check - return 0 on failure): ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET2_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_TARGET2(idx), 0)
/** Set custom0: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM0_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM0(idx), value, 0)
/** Set custom0 (no callback): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM0_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM0(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get custom0: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM0_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM0(idx), value, 0)
/** Get custom0 (no check - return 0 on failure): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM0_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM0(idx), 0)
/** Set custom1: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM1_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM1(idx), value, 0)
/** Set custom1 (no callback): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM1_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM1(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get custom1: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM1_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM1(idx), value, 0)
/** Get custom1 (no check - return 0 on failure): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM1_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM1(idx), 0)
/** Set custom2: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM2_SET(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM2(idx), value, 0)
/** Set custom2 (no callback): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM2_SET_NO_CALLBACK(idx, value) gs_param_set_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM2(idx), value, GS_PARAM_F_NO_CALLBACK)
/** Get custom2: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM2_GET(idx, value) gs_param_get_float(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM2(idx), value, 0)
/** Get custom2 (no check - return 0 on failure): 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM2_GET_NC(idx) gs_param_get_float_nc(gs_param_table_by_id(GS_ADCS_GNC_CTRL_POINTING_TABLE_ID), GS_ADCS_GNC_CTRL_POINTING_CUSTOM2(idx), 0)
/**@}*/

#ifdef __cplusplus
}
#endif
#endif
