#ifndef GS_HK_PARAM_HKCFG_H
#define GS_HK_PARAM_HKCFG_H
/* Copyright (c) 2013 GomSpace A/S. All rights reserved. (AUTO GENERATED) */
/**
   @file
   Table definitions for \a hkcfg.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** Table name */
#define GS_HK_HKCFG_TABLE_NAME                           "hkcfg"
/** Table id */
#define GS_HK_HKCFG_TABLE_ID                             21
/** Legacy table id definition */
#define GS_HK_HKCFG_TABLE_MEM_ID                         21
/** Table data size (bytes */
#define GS_HK_HKCFG_TABLE_SIZE                           64 // bytes
/** Table rows (count) */
#define GS_HK_HKCFG_TABLE_ROWS                           8

/**
   @defgroup param_addr Parameter addresses within the table.
   @{
*/
/** Address of bcn_atx_tpds: Temporarily disable all automatic beacon transmits for this number of seconds */
#define GS_HK_HKCFG_BCN_ATX_TPDS                                         0                  // 0x0000 uint16
/** Address of bcn_atx_da: CSP destination address for automatic beacon transmits */
#define GS_HK_HKCFG_BCN_ATX_DA                                           2                  // 0x0002 uint8
/** Address of bcn_atx_dp: CSP destination port for automatic beacon transmits */
#define GS_HK_HKCFG_BCN_ATX_DP                                           3                  // 0x0003 uint8
/** Address of bcn_satid: Identifier to stamp into each beacon to show from which satellite the beacon originates */
#define GS_HK_HKCFG_BCN_SATID                                            4                  // 0x0004 uint16
/** Address of persist_intv: Interval for persisting table samples */
#define GS_HK_HKCFG_PERSIST_INTV                                         8                  // 0x0008 uint32
/** Address of persist_en: Flag to completely enable/disable persisting of table samples */
#define GS_HK_HKCFG_PERSIST_EN                                          12                  // 0x000c bool
/** Address of data_path: Filesystem path used by the housekeeping system to read and write data */
#define GS_HK_HKCFG_DATA_PATH                                           13                  // 0x000d string
/** Length/size of data_path (bytes): Filesystem path used by the housekeeping system to read and write data */
#define GS_HK_HKCFG_DATA_PATH_LENGTH                                    50
/** Address of hk_en: Flag to completely enable/disable the housekeeping system */
#define GS_HK_HKCFG_HK_EN                                               63                  // 0x003f bool
/**@}*/
#ifdef __cplusplus
}
#endif
#endif
