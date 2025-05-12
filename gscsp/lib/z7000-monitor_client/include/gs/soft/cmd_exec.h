#ifndef __CMD_EXEC_H
#define __CMD_EXEC_H

#include <command/command.h>
#include <csp/csp.h>

#define PROG_NAME_MAX_LEN 30
#define PROCESS_NAME_MAX_LEN 8
#define ARGS_MAX_LEN 30
#define ARGS_MAX_NUM 4

typedef struct _exec_cmd {
	char prog[PROG_NAME_MAX_LEN + 1];
	char process_name[PROCESS_NAME_MAX_LEN + 1];
	char args[ARGS_MAX_NUM][ARGS_MAX_LEN];
	uint8_t num_of_args;
} exec_cmd_t;

int cmd_exec(struct command_context *ctx);
int soft_exec_cmd(exec_cmd_t exec_cmd);

#endif /* __CMD_EXEC_H */
