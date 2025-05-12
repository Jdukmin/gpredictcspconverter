/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */
#include <gs/aardvark/drivers/aardvark/gs_aardvark.h>
#include <gs/aardvark/drivers/i2c/i2c.h>
#include <gs/aardvark/drivers/spi/master.h>
#include <gs/util/linux/drivers/spi/spi.h>
#include <Python.h>

#if PY_MAJOR_VERSION == 3
#define IS_PY3
#endif

static PyObject* pyaardvark_open_device(PyObject *self, PyObject *args)
{
    uint32_t unique_id;
    if (!PyArg_ParseTuple(args,"I", &unique_id))
    {
        Py_RETURN_NONE;
    }

    gs_aardvark_handle_t handle;
    gs_error_t error;
    error = gs_aardvark_open_device(unique_id, &handle);
    if (error != GS_OK)
    {
        return Py_BuildValue("i", error);
    }

    PyObject* ad_handle = PyDict_New();
    PyDict_SetItem(ad_handle, Py_BuildValue("s", "port"), Py_BuildValue("I", handle.port));
    PyDict_SetItem(ad_handle, Py_BuildValue("s", "unique_id"), Py_BuildValue("I", handle.unique_id));
    PyDict_SetItem(ad_handle, Py_BuildValue("s", "handle"), Py_BuildValue("i", handle.handle));
    PyDict_SetItem(ad_handle, Py_BuildValue("s", "features"), Py_BuildValue("", handle.aa_ext.features));
    PyDict_SetItem(ad_handle,
            Py_BuildValue("s", "software_version"),
            Py_BuildValue("I", handle.aa_ext.version.software));
    PyDict_SetItem(ad_handle,
            Py_BuildValue("s", "firmware_version"),
            Py_BuildValue("I", handle.aa_ext.version.firmware));
    PyDict_SetItem(ad_handle,
            Py_BuildValue("s", "hardware_version"),
            Py_BuildValue("I", handle.aa_ext.version.hardware));

    return Py_BuildValue("iO", error, ad_handle);

}

/* i2c/i2c.h */
/* gs_error_t gs_aardvark_i2c_init(
 *      const gs_i2c_aardvark__bus_config_t * config, uint8_t * return_bus); */

static PyObject* pyaadvarki2c_init_default_master(PyObject *self, PyObject *args)
{
    gs_aardvark_i2c_bus_config_t config;
    gs_aardvark_i2c_get_default_config(&config);

    config.common.mode = GS_I2C_MASTER;

    uint8_t bus;
    gs_error_t error = gs_aardvark_i2c_init(&config, &bus);

    return Py_BuildValue("iI", error, bus);

}

static PyObject* pyaadvarki2c_init_default_multimaster(PyObject *self, PyObject *args)
{
    uint8_t addr;
    if (!PyArg_ParseTuple(args, "B", &addr))
    {
        Py_RETURN_NONE;
    }
    
    gs_aardvark_i2c_bus_config_t config;
    gs_aardvark_i2c_get_default_config(&config);

    config.common.mode = GS_I2C_MULTI_MASTER;
    config.common.addr = addr;

    uint8_t bus;
    gs_error_t error = gs_aardvark_i2c_init(&config, &bus);

    return Py_BuildValue("iB", error, bus);

}

static PyObject* pyaardvarki2c_init(PyObject *self, PyObject *args)
{
    uint32_t bps;
    if (!PyArg_ParseTuple(args, "I", &bps))
    {
        Py_RETURN_NONE;
    }
    gs_aardvark_i2c_bus_config_t config;
    gs_aardvark_i2c_get_default_config(&config);
    config.common.bps = bps;
    uint8_t bus;
    gs_error_t error = gs_aardvark_i2c_init(&config, &bus);
    return Py_BuildValue("iB", error, bus);
}

static PyObject* pyaardvarki2c_master_register_driver(PyObject *self, PyObject *args)
{
    uint8_t bus;
    if (!PyArg_ParseTuple(args, "B", &bus))
    {
        Py_RETURN_NONE;
    }

    gs_aardvark_i2c_driver_data_t driver_data = {
        .handle = bus,
    };
    const gs_i2c_master_driver_entry_t master_driver = {
        .device = GS_I2C_ALL_DEVICES,
        .addr = GS_I2C_ALL_ADDR,
        .driver = &gs_aardvark_i2c_master_driver,
        .driver_data = &driver_data,
    };
    gs_error_t error = gs_i2c_master_register_driver(&master_driver);
    return Py_BuildValue("i", error);
}

static PyObject* pyaardvarki2c_slave_register_driver(PyObject *self, PyObject *args)
{
    uint8_t bus;
    if (!PyArg_ParseTuple(args, "B", &bus))
    {
        Py_RETURN_NONE;
    }

    gs_aardvark_i2c_driver_data_t driver_data = {
        .handle = bus,
    };
    const gs_i2c_slave_driver_entry_t slave_driver = {
        .device = GS_I2C_ALL_DEVICES,
        .driver = &gs_aardvark_i2c_slave_driver,
        .driver_data = &driver_data,
    };
    gs_error_t error = gs_i2c_slave_register_driver(&slave_driver);
    return Py_BuildValue("i", error);
}


static PyObject* pyaardvarki2c_close(PyObject *self, PyObject *args)
{
    uint8_t bus;
    if (!PyArg_ParseTuple(args, "B", &bus))
    {
        Py_RETURN_NONE;
    }
    gs_error_t error = gs_aardvark_i2c_close(bus);
    return Py_BuildValue("i", error);
}


/* SPI */

static PyObject* pyaardvarkspi_init_default_master(PyObject *self, PyObject *args)
{
    gs_spi_aardvark_master_slave_config_t config;
    gs_spi_aardvark_master_slave_default_config(&config);

    gs_error_t error;
    uint8_t return_handle;

    error = gs_spi_aardvark_master_configure_slave(&config, &return_handle);
    return Py_BuildValue("iB", error, return_handle);
}

static PyObject* pyaardvarkspi_master_register_driver(PyObject *self, PyObject *args)
{
    uint8_t bus;
    if (!PyArg_ParseTuple(args, "B", &bus))
    {
        Py_RETURN_NONE;
    }

    gs_aardvark_spi_master_driver_data_t driver_data = {
        .handle = bus,
    };

    const gs_spi_master_driver_entry_t master_driver = {
        .slave = GS_SPI_ALL_DEVICES,
        .driver = &gs_aardvark_spi_master_driver,
        .driver_data = &driver_data,
    };
    gs_error_t error = gs_spi_master_register_driver(&master_driver);
    return Py_BuildValue("i", error);
}

static PyObject* pyaardvarkspi_close_slave(PyObject *self, PyObject *args)
{
    uint8_t slave;
    if (!PyArg_ParseTuple(args, "B", &slave))
    {
        Py_RETURN_NONE;
    }

    gs_error_t error = gs_spi_master_close_slave(slave);
    return Py_BuildValue("i", error);
}


static PyMethodDef methods[] = {

    /* gs_aardvark.h */
    {"open_device", pyaardvark_open_device, METH_VARARGS, ""},
    /* i2c/i2c.h */
    {"i2c_default_configure_bus_master", pyaadvarki2c_init_default_master, METH_VARARGS, ""},
    {"i2c_default_configure_bus_multimaster", pyaadvarki2c_init_default_multimaster, METH_VARARGS, ""},
    {"i2c_configure_bus", pyaardvarki2c_init, METH_VARARGS, ""},
    {"i2c_master_register_driver", pyaardvarki2c_master_register_driver, METH_VARARGS, ""},
    {"i2c_slave_register_driver", pyaardvarki2c_slave_register_driver, METH_VARARGS, ""},
    {"i2c_close", pyaardvarki2c_close, METH_VARARGS, ""},
    /* spi/master.h */
    {"spi_default_configure_bus_master", pyaardvarkspi_init_default_master, METH_VARARGS, ""},
    {"spi_master_register_driver", pyaardvarkspi_master_register_driver, METH_VARARGS, ""},
    {"spi_close_slave", pyaardvarkspi_close_slave, METH_VARARGS, ""},
    /* sentinel */
    {NULL, NULL, 0, NULL}
};

#ifdef IS_PY3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "pygsaardvark_py3",
    NULL, /* module documentation, may be NULL */
    -1,   /* size of per-interpreter state of the module,
             or -1 if the module keeps state in global variables. */
    methods,
    NULL,
    NULL,
    NULL,
    NULL
};
#endif

#ifdef IS_PY3
PyMODINIT_FUNC PyInit_libgsaardvark_py3(void) {
#else
PyMODINIT_FUNC initlibgsaardvark_py2(void) {
#endif

#ifdef IS_PY3
    PyObject* m = PyModule_Create(&moduledef);
#else
    Py_InitModule("libgsaardvark_py2", methods);
#endif

#ifdef IS_PY3
    return m;
#endif
}
