/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <gs/aardvark/command_line.h>
#include <gs/aardvark/drivers/aardvark/gs_aardvark.h>
#include <gs/aardvark/drivers/i2c/i2c.h>
#include <gs/aardvark/drivers/spi/master.h>
#include <gs/util/linux/function.h>
#include <gs/util/string.h>
#include <gs/util/log.h>

#define KEY_AARDVARK_DEVICES     200
#define LD_LIBRARY_PATH          "LD_LIBRARY_PATH"

static gs_error_t set_ld_library_path(void)
{
    static bool set = false;

    if (set == false) {
        char new_path[1000] = ".:";
        const char * path = getenv(LD_LIBRARY_PATH);
        if (path) {
            if ((strlen(path) + strlen(new_path) + 1) > sizeof(new_path)) {
                log_error("length of environment variable: %s exceeds buffer size: %u", LD_LIBRARY_PATH, (unsigned int) sizeof(new_path));
                return GS_ERROR_ALLOC;
            }
            strncat(new_path, path, sizeof(new_path) - 1);
        }
        if (setenv(LD_LIBRARY_PATH, new_path, 1) != 0) {
            log_warning("could not set environment variable: %s, errno: %d", LD_LIBRARY_PATH, errno);
        }

        set = true;
    }
    return GS_OK;
}

static gs_error_t init_i2c(const char * options, bool register_slave)
{
    set_ld_library_path();

    gs_aardvark_i2c_bus_config_t config;
    gs_aardvark_i2c_get_default_config(&config);
    gs_error_t error = gs_string_get_suboption_uint32(options, NULL, config.unique_id, &config.unique_id);
    error |= gs_string_get_suboption_uint16(options, GS_I2C_COMMAND_LINE_ADDRESS, config.common.addr, &config.common.addr);
    error |= gs_string_get_suboption_uint32(options, GS_I2C_COMMAND_LINE_SPEED, config.common.bps, &config.common.bps);
    uint8_t device = GS_I2C_ALL_DEVICES;
    error |= gs_string_get_suboption_uint8(options, GS_I2C_COMMAND_LINE_DEVICE, device, &device);
    if (error) {
        log_error("%s: failed to parse options: [%s]", __FUNCTION__, options);
        return GS_ERROR_ARG;
    }

    gs_aardvark_i2c_driver_data_t * driver_data = calloc(1, sizeof(*driver_data));
    if (driver_data == NULL) {
        return GS_ERROR_ALLOC;
    }

    error = gs_aardvark_i2c_init(&config, &driver_data->handle);
    if (error) {
        free(driver_data);
        log_error("%s: gs_aardvark_i2c_init() failed, options: [%s], error: %s", __FUNCTION__, options, gs_error_string(error));
        return error;
    }

    // register master
    const gs_i2c_master_driver_entry_t master_driver = {
        .device = device,
        .addr = GS_I2C_ALL_ADDR,
        .driver = &gs_aardvark_i2c_master_driver,
        .driver_data = driver_data,
    };
    error = gs_i2c_master_register_driver(&master_driver);
    if (error) {
        log_error("%s: gs_i2c_master_register_driver() failed, options: [%s], error: %s", __FUNCTION__, options, gs_error_string(error));
        return error;
    }

    // register slave
    const gs_i2c_slave_driver_entry_t slave_driver = {
        .device = device,
        .driver = &gs_aardvark_i2c_slave_driver,
        .driver_data = driver_data,
    };
    error = gs_i2c_slave_register_driver(&slave_driver);
    if (error) {
        log_error("%s: gs_i2c_slave_register_driver() failed, options: [%s], error: %s", __FUNCTION__, options, gs_error_string(error));
        return error;
    }

    log_debug("%s: master address: %u, speed: %d, device: %u", __FUNCTION__, config.common.addr, config.common.bps, device);

    return GS_OK;
}

static gs_error_t init_spi(const char * options)
{
    set_ld_library_path();

    gs_spi_aardvark_master_slave_config_t config;
    gs_spi_aardvark_master_slave_default_config(&config);

    gs_error_t error = gs_string_get_suboption_uint32(options, NULL, config.unique_id, &config.unique_id);
    error |= gs_string_get_suboption_uint32(options, GS_SPI_COMMAND_LINE_SPEED, config.common.bps, &config.common.bps);
    uint8_t slave = GS_SPI_ALL_SLAVES;
    error |= gs_string_get_suboption_uint8(options, GS_SPI_COMMAND_LINE_SLAVE, slave, &slave);
    if (error) {
        log_error("%s: failed to parse options: [%s]", __FUNCTION__, options);
        return GS_ERROR_ARG;
    }

    gs_aardvark_spi_master_driver_data_t * driver_data = calloc(1, sizeof(*driver_data));
    if (driver_data == NULL) {
        return GS_ERROR_ALLOC;
    }

    error = gs_spi_aardvark_master_configure_slave(&config, &driver_data->handle);
    if (error) {
        free(driver_data);
        log_error("%s: gs_aardvark_spi_init() failed, options: [%s], error: %s", __FUNCTION__, options, gs_error_string(error));
        return error;
    }

    // register master
    const gs_spi_master_driver_entry_t master_driver = {
        .slave = slave,
        .driver = &gs_aardvark_spi_master_driver,
        .driver_data = driver_data,
    };
    error = gs_spi_master_register_driver(&master_driver);
    if (error) {
        log_error("%s: gs_spi_master_register_driver() failed, options: [%s], error: %s", __FUNCTION__, options, gs_error_string(error));
        return error;
    }

    log_debug("%s: speed: %d, slave: %u", __FUNCTION__, config.common.bps, slave);

    return GS_OK;
}

static gs_error_t aardvark_devices(void)
{
    return gs_aardvark_list_devices(stdout);
}

static int parser(int key, char *arg, struct argp_state *state)
{
    switch (key) {
        case KEY_AARDVARK_DEVICES:
            {
                gs_error_t error = aardvark_devices();
                exit((error == GS_OK) ? 0 : GS_EXITCODE_ERROR);
            }
            break;   

        case 'I':
            return init_i2c(arg != NULL ? arg : "0", false);

        case 'S':
            return init_spi(arg != NULL ? arg : "0");

        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static const struct argp_option argp_options[] = {
    {
        .name = "aardvark-devices",
        .key = KEY_AARDVARK_DEVICES,
        .doc = "Show all devices"
    },
    {
        .name = "aardvark-i2c",
        .key = 'I',
        .arg = "DEVICE",
        .flags = OPTION_ARG_OPTIONAL,
        .doc = "Add I2C interface\nDEVICE=0,"GS_I2C_COMMAND_LINE_SPEED"=" GS_DEF2STRING(GS_I2C_DEFAULT_BPS_v2) "," GS_I2C_COMMAND_LINE_DEVICE "=" GS_DEF2STRING(GS_I2C_ALL_DEVICES) "," GS_I2C_COMMAND_LINE_ADDRESS "=1"
    },
    {
        .name = "aardvark-spi",
        .key = 'S',
        .arg = "DEVICE",
        .flags = OPTION_ARG_OPTIONAL,
        .doc = "Add SPI interface\nDEVICE=0,"GS_I2C_COMMAND_LINE_SPEED"=" GS_DEF2STRING(GS_SPI_DEFAULT_BPS) "," GS_SPI_COMMAND_LINE_SLAVE "=" GS_DEF2STRING(GS_SPI_ALL_SLAVES)
    },
    {0}
};

static const struct argp argp = {.options = argp_options, .parser = parser};
const struct argp_child gs_aardvark_command_line_argp =  {.argp = &argp, .header = "Aardvard I2C/SPI adapter"};

static gs_error_t function_init_i2c(void * options)
{
    return init_i2c(options, true);
}

static gs_error_t function_init_spi(void * options)
{
    return init_spi(options);
}

gs_error_t gs_aardvark_register_initialize_functions(void)
{
    gs_function_register("i2c", "aardvark-i2c", function_init_i2c);
    gs_function_register("spi", "aardvark-spi", function_init_spi);
    return GS_OK;
}
