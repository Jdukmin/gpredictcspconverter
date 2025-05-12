/**
 * GomSpace 
 *
 * @author Morten Jensen
 * Copyright 2015 GomSpace ApS. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

#include <csp/csp_endian.h>
#include <csp/csp.h>

#include <gs/soft/cmd_exec.h>
#include <gs/soft/param/soft.h>

int soft_exec_cmd(exec_cmd_t exec_cmd) {
	uint8_t res;

	if (csp_transaction(CSP_PRIO_HIGH, soft_node, SOFT_PORT_EXEC, soft_timeout, &exec_cmd, sizeof(exec_cmd_t), &res, sizeof(uint8_t)) <= 0) {
		return -1;
	}

	return 0;
}
