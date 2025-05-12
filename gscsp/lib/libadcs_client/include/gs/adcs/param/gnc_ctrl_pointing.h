#ifndef GS_ADCS_PARAM_GNC_CTRL_POINTING_H
#define GS_ADCS_PARAM_GNC_CTRL_POINTING_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a gnc_ctrl_pointing.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_ADCS_GNC_CTRL_POINTING_TABLE_NAME             "gnc_ctrl_pointing"
/** Table id */
#define GS_ADCS_GNC_CTRL_POINTING_TABLE_ID               53
/** Legacy table id definition */
#define GS_ADCS_GNC_CTRL_POINTING_TABLE_MEM_ID           53
/** Table data size (bytes */
#define GS_ADCS_GNC_CTRL_POINTING_TABLE_SIZE             368 // bytes
/** Table rows (count) */
#define GS_ADCS_GNC_CTRL_POINTING_TABLE_ROWS             30

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of mw_smc: Sliding Mode Controller gain for MW, [Ks, Lambda, epsilon] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_SMC(idx)                       (    0 + ( 4 * (idx)))  // 0x0000 float
/** Array size of mw_smc: Sliding Mode Controller gain for MW, [Ks, Lambda, epsilon] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_SMC_ARRAY_SIZE                      3
/** Address of mw_gain: Gain used by the wheel controller [Common, K1, K2] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_GAIN(idx)                      (   12 + ( 4 * (idx)))  // 0x000c float
/** Array size of mw_gain: Gain used by the wheel controller [Common, K1, K2] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_GAIN_ARRAY_SIZE                     3
/** Address of mw_dumpgain: Momentum dunping sign and gain */
#define GS_ADCS_GNC_CTRL_POINTING_MW_DUMPGAIN                           24                  // 0x0018 float
/** Address of mw_mw2trq: Option to reverse and scale mw 2 torquer assign */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MW2TRQ                             28                  // 0x001c float
/** Address of mw_mannull: The reaction wheel nullspace vector is used for the reaction wheel momentum management, null(rw_mapping[3x4]) */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANNULL(idx)                   (   32 + ( 4 * (idx)))  // 0x0020 float
/** Array size of mw_mannull: The reaction wheel nullspace vector is used for the reaction wheel momentum management, null(rw_mapping[3x4]) */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANNULL_ARRAY_SIZE                  4
/** Address of mw_mangain: The Reaction wheel momentum management gain, ajusts the transient time */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANGAIN                            48                  // 0x0030 float
/** Address of mw_manoffset: The reaction wheel momentum offset, biasing the reaction wheels [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_MW_MANOFFSET                          52                  // 0x0034 float
/** Address of euler_offset: Pointing offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_EULER_OFFSET(idx)                 (   56 + ( 4 * (idx)))  // 0x0038 float
/** Array size of euler_offset: Pointing offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_EULER_OFFSET_ARRAY_SIZE                3
/** Address of rate_offset: Rate offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_RATE_OFFSET(idx)                  (   68 + ( 4 * (idx)))  // 0x0044 float
/** Array size of rate_offset: Rate offset between orbit- and body frame */
#define GS_ADCS_GNC_CTRL_POINTING_RATE_OFFSET_ARRAY_SIZE                 3
/** Address of ref_momentum: Body axis momentum reference [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_REF_MOMENTUM(idx)                 (   80 + ( 4 * (idx)))  // 0x0050 float
/** Array size of ref_momentum: Body axis momentum reference [Nms] */
#define GS_ADCS_GNC_CTRL_POINTING_REF_MOMENTUM_ARRAY_SIZE                3
/** Address of en_mwdump: Enable MW momentum dumping */
#define GS_ADCS_GNC_CTRL_POINTING_EN_MWDUMP                             92                  // 0x005c bool
/** Address of en_mwman: Enable MW momentum management */
#define GS_ADCS_GNC_CTRL_POINTING_EN_MWMAN                              93                  // 0x005d bool
/** Address of en_bbq: BBQ parameters, [Enable, Ref */
#define GS_ADCS_GNC_CTRL_POINTING_EN_BBQ(idx)                       (   94 + ( 1 * (idx)))  // 0x005e uint8
/** Array size of en_bbq: BBQ parameters, [Enable, Ref */
#define GS_ADCS_GNC_CTRL_POINTING_EN_BBQ_ARRAY_SIZE                      2
/** Address of en_gso: Enable/select which landmark to track, the antenna to use and coordinate system [gso, ant, coord] */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSO(idx)                       (   96 + ( 1 * (idx)))  // 0x0060 uint8
/** Array size of en_gso: Enable/select which landmark to track, the antenna to use and coordinate system [gso, ant, coord] */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSO_ARRAY_SIZE                      3
/** Address of en_gstrack: Mode used to track ground stations when they are close and else fly RAM */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSTRACK(idx)                   (   99 + ( 1 * (idx)))  // 0x0063 uint8
/** Array size of en_gstrack: Mode used to track ground stations when they are close and else fly RAM */
#define GS_ADCS_GNC_CTRL_POINTING_EN_GSTRACK_ARRAY_SIZE                  2
/** Address of en_sunpoint: Mode to change the reference vector to point at the sun */
#define GS_ADCS_GNC_CTRL_POINTING_EN_SUNPOINT                          101                  // 0x0065 bool
/** Address of nadir: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_NADIR(idx)                        (  104 + ( 4 * (idx)))  // 0x0068 float
/** Array size of nadir: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_NADIR_ARRAY_SIZE                       3
/** Address of ram: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_RAM(idx)                          (  116 + ( 4 * (idx)))  // 0x0074 float
/** Array size of ram: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_RAM_ARRAY_SIZE                         3
/** Address of mindrag: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MINDRAG(idx)                      (  128 + ( 4 * (idx)))  // 0x0080 float
/** Array size of mindrag: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MINDRAG_ARRAY_SIZE                     3
/** Address of maxdrag: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MAXDRAG(idx)                      (  140 + ( 4 * (idx)))  // 0x008c float
/** Array size of maxdrag: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_MAXDRAG_ARRAY_SIZE                     3
/** Address of gs_list: List of ECEF coordinates of 3 ground stations [GS1] [GS2] [GS3] */
#define GS_ADCS_GNC_CTRL_POINTING_GS_LIST(idx)                      (  152 + ( 4 * (idx)))  // 0x0098 float
/** Array size of gs_list: List of ECEF coordinates of 3 ground stations [GS1] [GS2] [GS3] */
#define GS_ADCS_GNC_CTRL_POINTING_GS_LIST_ARRAY_SIZE                     9
/** Address of gs_offset: List of euler offset to track ground station */
#define GS_ADCS_GNC_CTRL_POINTING_GS_OFFSET(idx)                    (  188 + ( 4 * (idx)))  // 0x00bc float
/** Array size of gs_offset: List of euler offset to track ground station */
#define GS_ADCS_GNC_CTRL_POINTING_GS_OFFSET_ARRAY_SIZE                   9
/** Address of gso_list: Landmark ECEF [ECEF1 ECEF2 ECEF3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_LIST(idx)                     (  224 + ( 4 * (idx)))  // 0x00e0 float
/** Array size of gso_list: Landmark ECEF [ECEF1 ECEF2 ECEF3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_LIST_ARRAY_SIZE                    9
/** Address of gso_ant: Antenna offset in body frame Euler angles [Ant1 Ant2 Ant3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_ANT(idx)                      (  260 + ( 4 * (idx)))  // 0x0104 float
/** Array size of gso_ant: Antenna offset in body frame Euler angles [Ant1 Ant2 Ant3] */
#define GS_ADCS_GNC_CTRL_POINTING_GSO_ANT_ARRAY_SIZE                     9
/** Address of target0: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET0(idx)                      (  296 + ( 4 * (idx)))  // 0x0128 float
/** Array size of target0: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET0_ARRAY_SIZE                     3
/** Address of target1: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET1(idx)                      (  308 + ( 4 * (idx)))  // 0x0134 float
/** Array size of target1: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET1_ARRAY_SIZE                     3
/** Address of target2: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET2(idx)                      (  320 + ( 4 * (idx)))  // 0x0140 float
/** Array size of target2: ECEF Landmark to track */
#define GS_ADCS_GNC_CTRL_POINTING_TARGET2_ARRAY_SIZE                     3
/** Address of custom0: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM0(idx)                      (  332 + ( 4 * (idx)))  // 0x014c float
/** Array size of custom0: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM0_ARRAY_SIZE                     3
/** Address of custom1: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM1(idx)                      (  344 + ( 4 * (idx)))  // 0x0158 float
/** Array size of custom1: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM1_ARRAY_SIZE                     3
/** Address of custom2: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM2(idx)                      (  356 + ( 4 * (idx)))  // 0x0164 float
/** Array size of custom2: 3-2-1 Euler rotation from satellite to orbit */
#define GS_ADCS_GNC_CTRL_POINTING_CUSTOM2_ARRAY_SIZE                     3
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
