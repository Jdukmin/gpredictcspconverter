/**
 * GomSpace 
 *
 * @author Morten Jensen
 * Copyright 2015 GomSpace ApS. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

#include <gs/soft/cmd_exec.h>
#include <gs/soft/param/soft.h>

int cmd_exec(struct command_context *ctx) {
	int i;

	if (ctx->argc > (ARGS_MAX_NUM + 3) || ctx->argc < 2)
		return CMD_ERROR_SYNTAX;

	exec_cmd_t exec_cmd;
	if (strlen(ctx->argv[1]) > PROG_NAME_MAX_LEN)
		return CMD_ERROR_FAIL;
	strcpy(exec_cmd.prog, ctx->argv[1]);

	if (strlen(ctx->argv[2]) > PROCESS_NAME_MAX_LEN)
		return CMD_ERROR_FAIL;
	strcpy(exec_cmd.process_name, ctx->argv[2]);

	for (i=3; i < (ctx->argc); i++) {
		if (strlen(ctx->argv[i]) > ARGS_MAX_LEN) {
			return CMD_ERROR_FAIL;
		}
		strcpy(exec_cmd.args[i - 3], ctx->argv[i]);
	}
	exec_cmd.num_of_args = i - 3;
	if (soft_exec_cmd(exec_cmd) < 0)
		return CMD_ERROR_FAIL;

	printf("Command was received\r\n");
	return CMD_ERROR_NONE;
}
