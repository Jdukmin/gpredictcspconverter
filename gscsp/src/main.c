/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gs/adcs/adcs_command.h>
#include <gs/param/rparam.h>
#include <gs/param/pp/pp.h>
#include <gs/gssb/rgssb.h>
#include <gs/gssb/gssb_command.h>
#include <gs/csp/csp.h>
#include <gs/csp/command.h>
#include <gs/csp/service_dispatcher.h>
#include <gs/csp/linux/command_line.h>
#include <gs/csp/router.h>
//#include <gs/aardvark/command_line.h>
#include <gs/ftp/client.h>
#include <gs/gosh/gscript/client.h>
#include <gs/rgosh/rgosh.h>
#include <gs/hk/client.h>
#include <gs/fp/fp_client.h>
#include <gs/util/linux/command_line.h>
#include <gs/util/gosh/command.h>
#include <gs/util/gosh/console.h>

#define DEFAULT_CSP_ADDRESS 28

static void csp_service_dispatcher(void)
{
    static const gs_csp_service_handler_t handlers[31] = {
        GS_CSP_BASIC_SERVICE_HANDLERS,
    };

    // Configuration for service handler - must remain valid as long as service handler is running
    static const gs_csp_service_dispatcher_conf_t conf = {
        .name = "CSPCLIENTSRV",
        .bind_any = true, // bind to any un-bounded ports, used for logging unexpected connections
        .disable_watchdog = true,
        .handler_array = handlers,
        .handler_array_size = GS_ARRAY_SIZE(handlers),
    };

    gs_csp_service_dispatcher_create(&conf, 0, GS_THREAD_PRIORITY_NORMAL, NULL);
}

// Initialize command-framework and register commands (GOSH).
static void init_and_register_commands(void)
{
    // Initialize command framework
    gs_command_init(0);

    // Register commands for libraries and services
    gs_pp_register_commands();
    gs_rparam_register_commands();
    gs_csp_register_commands();
    gs_ftp_register_commands();
    gs_gscript_register_commands();
    gs_rgosh_register_commands();
    fp_client_register_commands();
    gs_hk_register_commands();
    gs_rgssb_register_commands();
    gs_gssb_register_commands();

    // Register commands for product interfaces
    gs_adcs_register_commands();
    extern void cmd_ax100_setup(void);
    cmd_ax100_setup();
    extern void cmd_p60pdu_setup(void);
    cmd_p60pdu_setup();
    extern void cmd_p60dock_setup(void);
    cmd_p60dock_setup();
    extern void cmd_p60pdu_setup(void);
    cmd_p60pdu_setup();
    extern void cmd_p60acu_setup(void);
    cmd_p60acu_setup();
    extern void cmd_eps_setup(void);
    cmd_eps_setup();
    extern void cmd_bpx_setup(void);
    cmd_bpx_setup();
    extern void gatoss_cmd_setup(void);
    gatoss_cmd_setup();
    extern void nanocam_register_commands(void);
    nanocam_register_commands();
    extern void soft_register_commands(void);
    soft_register_commands();
    extern void cmd_power_if_setup(void);
    cmd_power_if_setup();
}

int main(int argc, char * argv[])
{
    // Register functions (by name) to initialize Aardvark I2C and SPI devices
    //gs_aardvark_register_initialize_functions();

    // Add command line options for sub-modules and parse command line
    const struct argp_child argp_childern[] = {
        gs_help_command_line_argp,
        gs_log_command_line_argp,
        gs_csp_command_line_options,
        //gs_aardvark_command_line_argp,
        {0},
    };
    const struct argp argp = {
        .doc = "Product Interface Application\nDefault CSP address: " GS_DEF2STRING(DEFAULT_CSP_ADDRESS), .children = argp_childern,
    };
    gs_argp_parse(&argp, argc, argv, 0, NULL, GS_BUILD_INFO_REVISION);

    // Initialize command-framework and register commands (GOSH).
    init_and_register_commands();

    // Initialize CSP
    {
        gs_csp_conf_t conf;
        gs_csp_conf_get_defaults_server(&conf);

        conf.address = DEFAULT_CSP_ADDRESS;
        conf.hostname = "csp-client";
        conf.model = "CSP-client";
        conf.revision = GS_BUILD_INFO_REVISION;

        csp_rdp_set_opt(6, 30000, 16000, 1, 8000, 3);

        gs_csp_init(&conf);

        // Configure routes - add default routes or use command line option
        gs_csp_rtable_load(NULL, true, true);
        
        // Start CSP router task
        gs_csp_router_task_start(0, GS_THREAD_PRIORITY_HIGH);
    }

    // Start service dispatcher -> invokes CSP handlers based on port in in-coming request.
    csp_service_dispatcher();

    // Start console for handling commands.
    gs_console_start(GS_BUILD_INFO_APPNAME, 0);

    // Block here forever (until someone calls exit)
    gs_thread_block();

    return 0;
}
