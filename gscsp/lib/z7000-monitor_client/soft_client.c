/*
 * Client for SOFT
 * Copyright 2015 GomSpace ApS. All rights reserved.
 */
#include <gs/soft/param/soft.h>
#include <csp/csp.h>
#include <csp/csp_endian.h>

int soft_set_blcb(uint8_t node, uint32_t timeout, uint8_t bootok, uint8_t multibootreg, int8_t *result) {

	gs_soft_blcb_cmd_t cmd;

	cmd.cmd = GS_SOFT_BLCB_CMD;
	cmd.bootok = bootok;
	cmd.multibootreg = multibootreg;

	if (csp_transaction(CSP_PRIO_HIGH, node, SOFT_PORT_BLCB, timeout, &cmd, sizeof(cmd), result, sizeof(uint8_t)) <= 0)
		return -1;

	return 0;
}
