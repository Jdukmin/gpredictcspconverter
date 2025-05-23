/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9 */

#ifndef PB_GOSH_PB_H_INCLUDED
#define PB_GOSH_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _ListJobsCommand {
    char dummy_field;
/* @@protoc_insertion_point(struct:ListJobsCommand) */
} ListJobsCommand;

typedef struct _ResultTuple {
    bool has_group;
    char group[32];
    char key[32];
    char value[128];
/* @@protoc_insertion_point(struct:ResultTuple) */
} ResultTuple;

typedef struct _ShellCommand {
    bool has_stack_size;
    uint32_t stack_size;
    bool has_priority;
    uint32_t priority;
/* @@protoc_insertion_point(struct:ShellCommand) */
} ShellCommand;

typedef struct _TimeStamp {
    int64_t seconds;
    int32_t nanos;
/* @@protoc_insertion_point(struct:TimeStamp) */
} TimeStamp;

typedef struct _CommandResponse {
    pb_size_t results_count;
    ResultTuple results[4];
    int32_t return_code;
    bool completion_flag;
    bool has_std_out;
    char std_out[256];
/* @@protoc_insertion_point(struct:CommandResponse) */
} CommandResponse;

typedef struct _KeepAlive {
    bool has_time;
    TimeStamp time;
/* @@protoc_insertion_point(struct:KeepAlive) */
} KeepAlive;

typedef struct _RunCommand {
    char command[128];
    bool has_exec_time;
    TimeStamp exec_time;
/* @@protoc_insertion_point(struct:RunCommand) */
} RunCommand;

typedef struct _RunScriptCommand {
    bool has_script;
    char script[128];
    bool has_stack_size;
    uint32_t stack_size;
    bool has_priority;
    uint32_t priority;
    bool has_exec_time;
    TimeStamp exec_time;
/* @@protoc_insertion_point(struct:RunScriptCommand) */
} RunScriptCommand;

typedef struct _StopCommand {
    bool has_exec_time;
    TimeStamp exec_time;
/* @@protoc_insertion_point(struct:StopCommand) */
} StopCommand;

typedef struct _GoshRequest {
    uint32_t id;
    pb_size_t which_command;
    union {
        RunCommand run;
        RunScriptCommand runscript;
        ListJobsCommand listjobs;
        StopCommand stop;
        ShellCommand shell;
        KeepAlive keepalive;
    } command;
/* @@protoc_insertion_point(struct:GoshRequest) */
} GoshRequest;

typedef struct _GoshResponse {
    uint32_t id;
    pb_size_t which_response;
    union {
        CommandResponse command;
        KeepAlive keepalive;
    } response;
/* @@protoc_insertion_point(struct:GoshResponse) */
} GoshResponse;

/* Default values for struct fields */

/* Initializer values for message structs */
#define TimeStamp_init_default                   {0, 0}
#define RunCommand_init_default                  {"", false, TimeStamp_init_default}
#define RunScriptCommand_init_default            {false, "", false, 0, false, 0, false, TimeStamp_init_default}
#define ListJobsCommand_init_default             {0}
#define StopCommand_init_default                 {false, TimeStamp_init_default}
#define ShellCommand_init_default                {false, 0, false, 0}
#define KeepAlive_init_default                   {false, TimeStamp_init_default}
#define ResultTuple_init_default                 {false, "", "", ""}
#define CommandResponse_init_default             {0, {ResultTuple_init_default, ResultTuple_init_default, ResultTuple_init_default, ResultTuple_init_default}, 0, 0, false, ""}
#define GoshRequest_init_default                 {0, 0, {RunCommand_init_default}}
#define GoshResponse_init_default                {0, 0, {CommandResponse_init_default}}
#define TimeStamp_init_zero                      {0, 0}
#define RunCommand_init_zero                     {"", false, TimeStamp_init_zero}
#define RunScriptCommand_init_zero               {false, "", false, 0, false, 0, false, TimeStamp_init_zero}
#define ListJobsCommand_init_zero                {0}
#define StopCommand_init_zero                    {false, TimeStamp_init_zero}
#define ShellCommand_init_zero                   {false, 0, false, 0}
#define KeepAlive_init_zero                      {false, TimeStamp_init_zero}
#define ResultTuple_init_zero                    {false, "", "", ""}
#define CommandResponse_init_zero                {0, {ResultTuple_init_zero, ResultTuple_init_zero, ResultTuple_init_zero, ResultTuple_init_zero}, 0, 0, false, ""}
#define GoshRequest_init_zero                    {0, 0, {RunCommand_init_zero}}
#define GoshResponse_init_zero                   {0, 0, {CommandResponse_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define ResultTuple_group_tag                    1
#define ResultTuple_key_tag                      2
#define ResultTuple_value_tag                    3
#define ShellCommand_stack_size_tag              1
#define ShellCommand_priority_tag                2
#define TimeStamp_seconds_tag                    1
#define TimeStamp_nanos_tag                      2
#define CommandResponse_results_tag              1
#define CommandResponse_return_code_tag          2
#define CommandResponse_completion_flag_tag      3
#define CommandResponse_std_out_tag              10
#define KeepAlive_time_tag                       1
#define RunCommand_command_tag                   1
#define RunCommand_exec_time_tag                 2
#define RunScriptCommand_script_tag              1
#define RunScriptCommand_stack_size_tag          2
#define RunScriptCommand_priority_tag            3
#define RunScriptCommand_exec_time_tag           4
#define StopCommand_exec_time_tag                1
#define GoshRequest_run_tag                      10
#define GoshRequest_runscript_tag                11
#define GoshRequest_listjobs_tag                 12
#define GoshRequest_stop_tag                     13
#define GoshRequest_shell_tag                    14
#define GoshRequest_keepalive_tag                15
#define GoshRequest_id_tag                       1
#define GoshResponse_command_tag                 10
#define GoshResponse_keepalive_tag               20
#define GoshResponse_id_tag                      1

/* Struct field encoding specification for nanopb */
extern const pb_field_t TimeStamp_fields[3];
extern const pb_field_t RunCommand_fields[3];
extern const pb_field_t RunScriptCommand_fields[5];
extern const pb_field_t ListJobsCommand_fields[1];
extern const pb_field_t StopCommand_fields[2];
extern const pb_field_t ShellCommand_fields[3];
extern const pb_field_t KeepAlive_fields[2];
extern const pb_field_t ResultTuple_fields[4];
extern const pb_field_t CommandResponse_fields[5];
extern const pb_field_t GoshRequest_fields[8];
extern const pb_field_t GoshResponse_fields[4];

/* Maximum encoded size of messages (where known) */
#define TimeStamp_size                           22
#define RunCommand_size                          155
#define RunScriptCommand_size                    167
#define ListJobsCommand_size                     0
#define StopCommand_size                         24
#define ShellCommand_size                        12
#define KeepAlive_size                           24
#define ResultTuple_size                         199
#define CommandResponse_size                     1080
#define GoshRequest_size                         176
#define GoshResponse_size                        1089

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define GOSH_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
