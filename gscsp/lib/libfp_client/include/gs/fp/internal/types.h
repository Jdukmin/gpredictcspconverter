#if (GS_FP_INTERNAL_USE)
#ifndef GS_FP_TYPES_H
#define GS_FP_TYPES_H
/* Copyright (c) 2013-2020 GomSpace A/S. All rights reserved. */
/**
   @file

   Internal Flight planner server types

   @note Do not create this message manually, use the API in client.h instead.
   @warning Content of this file might be changed without notice.
*/

#include <gs/util/timestamp.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Maximum size of keys for events, triggers, sequences and commands */
#define FP_KEY_SIZE	30

/** Maximum size of argument structures for commands */
#define FP_CMD_SIZE	120

/** Maximum path length for storage commands */
#define FP_MAX_PATH_LENGTH 50

/** Server packet */
typedef enum __attribute__ ((packed)) {
	FP_TYPE_REQUEST,		/**< Server request */
	FP_TYPE_REPLY,			/**< Server reply */
} fp_server_type_t;

/** Server commands */
typedef enum __attribute__ ((packed)) {
	/* General FP commands */
	FP_CMD_STORE_FP,		/**< Store current flight plan */
	FP_CMD_LOAD_FP,			/**< Load flight plan */
	FP_CMD_FLUSH_FP,		/**< Flush flight plan */
	/* Time commands */
	FP_CMD_TIMER_CREATE,		/**< Create new timer */
	FP_CMD_TIMER_DELETE,		/**< Delete timer */
	FP_CMD_TIMER_LIST,		/**< List timers */
	FP_CMD_TIMER_SET_ACTIVE,	/**< Set timer as active */
	FP_CMD_TIMER_SET_ALL_ACTIVE,	/**< Set all timers as active */
	FP_CMD_TIMER_SET_DORMANT,	/**< Set timer as dormant */
	FP_CMD_TIMER_SET_REPEAT,	/**< Set timer repeat count */
	FP_CMD_TIMER_SET_TIME,		/**< Set timer execution time */
} fp_server_cmd_t;

/** Server reply types */
typedef enum __attribute__ ((packed)) {
	FP_REPLY_OK,			/**< No error */
	FP_REPLY_NOENT,			/**< No such entry */
	FP_REPLY_EXISTS,		/**< Entry exists */
	FP_REPLY_INVAL,			/**< Invalid argument */
} fp_server_reply_t;

/*
 * General commands
 */
typedef struct __attribute__ ((packed)) {
	char path[FP_MAX_PATH_LENGTH];
} fp_server_store_fp_t;

typedef struct __attribute__ ((packed)) {
	char path[FP_MAX_PATH_LENGTH];
	bool fast_load_with_unique_keys;
} fp_server_load_fp_t;

/*
 * Timer commands
 */
typedef struct __attribute__ ((packed)) {
	char timer[FP_KEY_SIZE];
	char cmd[FP_CMD_SIZE];
	uint8_t basis;
	uint8_t state;
	gs_timestamp_t when;
	uint16_t repeat;
} fp_server_timer_create_t;

typedef struct __attribute__ ((packed)) {
	char timer[FP_KEY_SIZE];
} fp_server_timer_delete_t;

typedef struct __attribute__ ((packed)) {
	char timer[FP_KEY_SIZE];
} fp_server_timer_active_t;

typedef struct __attribute__ ((packed)) {
	char timer[FP_KEY_SIZE];
} fp_server_timer_dormant_t;

typedef struct __attribute__ ((packed)) {
	char timer[FP_KEY_SIZE];
	uint16_t repeat;
} fp_server_timer_set_repeat_t;

typedef struct __attribute__ ((packed)) {
	char timer[FP_KEY_SIZE];
	uint8_t basis;
	gs_timestamp_t when;
} fp_server_timer_set_time_t;

/*
 * Timer commands
 */
typedef struct __attribute__ ((packed)) {
	uint16_t seq;
	uint16_t total;
	char timer[FP_KEY_SIZE];
	char cmd[FP_CMD_SIZE];
	uint8_t basis;
	uint8_t state;
	gs_timestamp_t when;
	gs_timestamp_t last;
	uint16_t repeat;
	uint16_t remain;
} fp_server_timer_list_t;

/** The Great Flight-Planner Packet Union */
typedef struct __attribute__ ((packed)) {
	uint8_t type;
	uint8_t cmd;
	uint8_t reply;
	uint8_t pad;
	union {
		/* General commands */
		union {
			fp_server_store_fp_t store;
			fp_server_load_fp_t load;
		} fp;
		/* Timer commands */
		union {
			fp_server_timer_create_t create;
			fp_server_timer_delete_t delete;
			fp_server_timer_active_t active;
			fp_server_timer_dormant_t dormant;
			fp_server_timer_list_t list;
			fp_server_timer_set_repeat_t repeat;
			fp_server_timer_set_time_t time;
		} timer;
		/* void pointer to data field */
		uint8_t * data[0];
	};
} fp_server_packet_t;

#define FP_SERVER_PACKET_EMPTY		(offsetof(fp_server_packet_t, data))
#define FP_SERVER_PACKET_SIZE(t)	(FP_SERVER_PACKET_EMPTY + sizeof(t))

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* GS_FP_TYPES_H */
#endif /* GS_FP_INTERNAL_USE */
