/* 
 * Client for SOFT
 * Copyright 2015 GomSpace ApS. All rights reserved.
 */ 

#ifndef _GS_SOFT_H_
#define _GS_SOFT_H_

#include <stdint.h>

#define SOFT_PORT_RPARAM	7
#define SOFT_PORT_LOG		8
#define SOFT_PORT_FTP		9
#define SOFT_PORT_EXEC		10
#define SOFT_PORT_RLOG		11
#define SOFT_PORT_BLCB		13

/* PARAM INDEX MAP */
#define SOFT_PARAM_RUNNING		0
#define SOFT_PARAM_RUNNING_DFL		24
#define SOFT_PARAM_RECOVERY_RUNNING	26
#define SOFT_PARAM_RECOVERY_RUNNING_DFL	27
#define SOFT_PARAM_SEM			3
#define SOFT_PARAM_TELEM		4
#define SOFT_PARAM_FEM			5

#define SOFT_FRAM_TELEM		0x5000
#define SOFT_FRAM_SEM		0x5100

#define GS_SOFT_BLCB_CMD        134

typedef struct __attribute__((packed)) {
	uint8_t cmd;
	uint8_t bootok;
	uint8_t multibootreg;
} gs_soft_blcb_cmd_t;

/* boot loader control block */
int soft_set_blcb(uint8_t node, uint32_t timeout, uint8_t bootok, uint8_t multibootreg, int8_t *result);

/* cmd */
extern uint8_t soft_node;
extern uint32_t soft_timeout;

#endif /* _GS_SOFT_H_ */
