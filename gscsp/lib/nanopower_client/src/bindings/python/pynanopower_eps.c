/* Copyright (c) 2013-2019 GomSpace A/S. All rights reserved. */
#include <Python.h>
#include <io/nanopower2.h>
#include "csp/csp_endian.h"
#include "csp/csp_endian.h"

#include <stdio.h>

#if PY_MAJOR_VERSION == 3
#define IS_PY3
#define PyInt_AsLong(x) (PyLong_AsLong((x)))
#endif


/**
 * Set Output Mask
 * @param output output mask
 * @return csp status
 */
//int eps_output_set(uint8_t output);
static PyObject* pyeps_output_set(PyObject* self, PyObject* args)
{
    uint8_t output;
    if (!PyArg_ParseTuple(args, "B", &output)) {
        Py_RETURN_NONE;
    }

    return Py_BuildValue("i", eps_output_set(output));
}

/**
 * Set single output
 * @param channel output channel number
 * @param mode 1 = ON, 0 = OFF
 * @param delay time to wait in ticks (0 = now)
 * @return csp status
 */
//int eps_output_set_single(uint8_t channel, uint8_t mode, int16_t delay);
static PyObject* pyeps_output_set_single(PyObject* self, PyObject* args)
{
    uint8_t channel, mode;
    int16_t delay;
    if (!PyArg_ParseTuple(args, "BBh", &channel, &mode, &delay)) {
        Py_RETURN_NONE;
    }
    return Py_BuildValue("i", eps_output_set_single(channel, mode, delay));
}

/* Reset EEPROM based counters @return csp status*/
//int eps_counters_reset(void);
static PyObject* pyeps_counters_reset(PyObject* self, PyObject* args)
{
    return Py_BuildValue("i", eps_counters_reset());
}

/* Perform HARD reset of EPS @return csp status */
//int eps_hardreset(void);
static PyObject* pyeps_hardreset(PyObject* self, PyObject* args)
{
    return Py_BuildValue("i", eps_hardreset());
}

/* Kick WDT GND  @return csp status */
//int eps_wdt_gnd_reset(void);
static PyObject* pyeps_wdt_gnd_reset(PyObject* self, PyObject* args)
{
    return Py_BuildValue("i", eps_wdt_gnd_reset());
}

/* Configure CSP timeout for outgoing EPS requests @param timeout */
//void eps_set_timeout(uint32_t timeout);
static PyObject* pyeps_set_timeout(PyObject* self, PyObject* args)
{
    uint32_t timeout;
    if (!PyArg_ParseTuple(args, "I", &timeout)) {
        Py_RETURN_NONE;
    }

    eps_set_timeout(timeout);
    Py_RETURN_NONE;
}

/*Configure CSP address for outgoing EPS requests */
//void eps_set_node(uint8_t node);
static PyObject* pyeps_set_node(PyObject* self, PyObject* args)
{
    uint8_t node;
    if (!PyArg_ParseTuple(args, "B", &node)) {
        Py_RETURN_NONE;
    }

    eps_set_node(node);
    Py_RETURN_NONE;
}

/** Manually control EPS heaters
 * @param heater heater number
 * @param mode on = 1, off = 0
 * @param state mode return pointer
 * @return status of csp transaction */
//int eps_heater(uint8_t heater, uint8_t mode, uint8_t *state);
static PyObject* pyeps_heater(PyObject* self, PyObject* args)
{
    uint8_t heater;
    uint8_t mode;
    uint8_t state[2];
    if (!PyArg_ParseTuple(args, "BB", &heater, &mode)) {
        Py_RETURN_NONE;
    }
    int ret = eps_heater(heater, mode, &state[0]);
    return Py_BuildValue("iBB", ret, state[0], state[1]);
}

/* int eps_hk_get(struct eps_hk * hk) */
static PyObject* pyeps_hk_get(PyObject* self, PyObject* args)
{
    eps_hk_t hk;
    int32_t ret = eps_hk_get(&hk);

    PyObject* hk_data = PyDict_New();
    PyDict_SetItem(hk_data, Py_BuildValue("s", "vboost"), Py_BuildValue("HHH", hk.vboost[0], hk.vboost[1], hk.vboost[2]));// uint16_t //! Voltage of boost converters [mV] [PV1, PV2, PV3]
    PyDict_SetItem(hk_data, Py_BuildValue("s", "vbatt"), Py_BuildValue("H", hk.vbatt));                                   // uint16_t //! Voltage of battery [mV]
    PyDict_SetItem(hk_data, Py_BuildValue("s", "curin"), Py_BuildValue("HHH", hk.curin[0], hk.curin[1], hk.curin[2]));    // uint16_t //! Current in [mA]
    PyDict_SetItem(hk_data, Py_BuildValue("s", "cursun"), Py_BuildValue("H", hk.cursun));                                 // uint16_t //! Current from boost converters [mA]
    PyDict_SetItem(hk_data, Py_BuildValue("s", "cursys"), Py_BuildValue("H", hk.cursys));                                 // uint16_t //! Current out of battery [mA]
    PyDict_SetItem(hk_data, Py_BuildValue("s", "curout"), Py_BuildValue("[HHHHHH]", hk.curout[0],                         // uint16_t //! Current out [mA]
                                                                        hk.curout[1],
                                                                        hk.curout[2],
                                                                        hk.curout[3],
                                                                        hk.curout[4],
                                                                        hk.curout[5]));
    PyDict_SetItem(hk_data, Py_BuildValue("s", "output"), Py_BuildValue("BBBBBBBB", hk.output[0],                         // uint8_t  //! Status of outputs [0 or 1]
                                                                          hk.output[1],
                                                                          hk.output[2],
                                                                          hk.output[3],
                                                                          hk.output[4],
                                                                          hk.output[5],
                                                                          hk.output[6],
                                                                          hk.output[7]));
    PyDict_SetItem(hk_data, Py_BuildValue("s", "output_on_delta"), Py_BuildValue("HHHHHHHH", hk.output_on_delta[0],       // uint16_t //! Time till power on [s]
                                                                                             hk.output_on_delta[1],
                                                                                             hk.output_on_delta[2],
                                                                                             hk.output_on_delta[3],
                                                                                             hk.output_on_delta[4],
                                                                                             hk.output_on_delta[5],
                                                                                             hk.output_on_delta[6],
                                                                                             hk.output_on_delta[7]));
    PyDict_SetItem(hk_data, Py_BuildValue("s", "output_off_delta"), Py_BuildValue("HHHHHHHH", hk.output_off_delta[0],     // uint16_t //! Time till power off [s]
                                                                                              hk.output_off_delta[1],
                                                                                              hk.output_off_delta[2],
                                                                                              hk.output_off_delta[3],
                                                                                              hk.output_off_delta[4],
                                                                                              hk.output_off_delta[5],
                                                                                              hk.output_off_delta[6],
                                                                                              hk.output_off_delta[7]));
    PyDict_SetItem(hk_data, Py_BuildValue("s", "latchup"), Py_BuildValue("HHHHHH", hk.latchup[0],                         // uint16_t //! Number of latch-ups []
                                                                                   hk.latchup[1],
                                                                                   hk.latchup[2],
                                                                                   hk.latchup[3],
                                                                                   hk.latchup[4],
                                                                                   hk.latchup[5]));
    PyDict_SetItem(hk_data, Py_BuildValue("s", "wdt_i2c_time_left"), Py_BuildValue("I", hk.wdt_i2c_time_left));           // uint32_t //! Time left on I2C wdt [s]
    PyDict_SetItem(hk_data, Py_BuildValue("s", "wdt_gnd_time_left"), Py_BuildValue("I", hk.wdt_gnd_time_left));           // uint32_t //! Time left on I2C wdt [s]
    PyDict_SetItem(hk_data, Py_BuildValue("s", "wdt_csp_pings_left"), Py_BuildValue("BB", hk.wdt_csp_pings_left[0],       // uint8_t  //! Pings left on CSP wdt []
                                                                                          hk.wdt_csp_pings_left[1]));

    PyDict_SetItem(hk_data, Py_BuildValue("s", "counter_wdt_i2c"), Py_BuildValue("I", hk.counter_wdt_i2c));               // uint32_t //! Number of WDT I2C reboots []
    PyDict_SetItem(hk_data, Py_BuildValue("s", "counter_wdt_gnd"), Py_BuildValue("I", hk.counter_wdt_gnd));               // uint32_t //! Number of WDT GND reboots []
    PyDict_SetItem(hk_data, Py_BuildValue("s", "counter_wdt_csp"), Py_BuildValue("II", hk.counter_wdt_csp[0],             // uint32_t //! Number of WDT CSP reboots []
                                                                                       hk.counter_wdt_csp[1]));
    PyDict_SetItem(hk_data, Py_BuildValue("s", "counter_boot"), Py_BuildValue("I", hk.counter_boot));                     // uint32_t //! Number of EPS reboots []
    PyDict_SetItem(hk_data, Py_BuildValue("s", "temp"), Py_BuildValue("hhhhhh", hk.temp[0],                               // int16_t  //! Temperature sensors [0 = TEMP1, TEMP2, TEMP3, TEMP4, BATT0, BATT1]
                                                                                hk.temp[1],
                                                                                hk.temp[2],
                                                                                hk.temp[3],
                                                                                hk.temp[4],
                                                                                hk.temp[5]));
    PyDict_SetItem(hk_data, Py_BuildValue("s", "bootcause"), Py_BuildValue("B", hk.bootcause));                           // uint8_t  //! Cause of last EPS reset
    PyDict_SetItem(hk_data, Py_BuildValue("s", "battmode"), Py_BuildValue("B", hk.battmode));                             // uint8_t  //! Mode for battery [0 = normal, 1 = undervoltage, 2 = overvoltage]
    PyDict_SetItem(hk_data, Py_BuildValue("s", "pptmode"), Py_BuildValue("B", hk.pptmode));                               // uint8_t  //! Mode of PPT tracker [1 = MPPT, 2 = fixed]

    return Py_BuildValue("iO", ret, hk_data);
}

//Python function gets and prints HK
/* void eps_hk_print(eps_hk_t * hk); */
static PyObject* pyeps_hk_print(PyObject* self, PyObject* args)
{
    eps_hk_t hk;
    int32_t ret = eps_hk_get(&hk);

    if (ret >= 0) {
        eps_hk_print(&hk);
    }

    Py_RETURN_NONE;
}

/* int eps_config_get(eps_config_t * config) */
static PyObject* pyeps_config_get(PyObject* self, PyObject* args)
{
    eps_config_t nanopower_config;
    int32_t ret = eps_config_get(&nanopower_config);
//        eps_config_print(&nanopower_config);

    PyObject* conf_data = PyDict_New();
    PyDict_SetItem(conf_data, Py_BuildValue("s", "ppt_mode"),           // uint8_t  //! Mode for MPPT [1 = AUTO, 2 = FIXED]
                   Py_BuildValue("B", nanopower_config.ppt_mode));
    PyDict_SetItem(conf_data, Py_BuildValue("s", "battheater_mode"),    // uint8_t  //! Mode for battheater [0 = Manual, 1 = Auto]
                   Py_BuildValue("B", nanopower_config.battheater_mode));
    PyDict_SetItem(conf_data, Py_BuildValue("s", "battheater_low"),     // uint16_t //! Voltage of battery [mV]
                   Py_BuildValue("b", nanopower_config.battheater_low));
    PyDict_SetItem(conf_data, Py_BuildValue("s", "battheater_high"),    // uint16_t //! Voltage of battery [mV]
                   Py_BuildValue("b", nanopower_config.battheater_high));
    PyDict_SetItem(conf_data,                                           // uint8_t   //! Nominal mode output value
                   Py_BuildValue("s", "output_normal_value"),
                   Py_BuildValue("BBBBBBBB", nanopower_config.output_normal_value[0],
                                 nanopower_config.output_normal_value[1], nanopower_config.output_normal_value[2],
                                 nanopower_config.output_normal_value[3], nanopower_config.output_normal_value[4],
                                 nanopower_config.output_normal_value[5], nanopower_config.output_normal_value[6],
                                 nanopower_config.output_normal_value[7]));
    PyDict_SetItem(conf_data,                                           // uint8_t   //! Safe mode output value
                   Py_BuildValue("s", "output_safe_value"),
                   Py_BuildValue("BBBBBBBB", nanopower_config.output_safe_value[0],
                                 nanopower_config.output_safe_value[1], nanopower_config.output_safe_value[2],
                                 nanopower_config.output_safe_value[3], nanopower_config.output_safe_value[4],
                                 nanopower_config.output_safe_value[5], nanopower_config.output_safe_value[6],
                                 nanopower_config.output_safe_value[7]));
    PyDict_SetItem(conf_data,                                           // uint16_t //! Output driver is initialized with these on delays [s]
                   Py_BuildValue("s", "output_initial_on_delay"),
                   Py_BuildValue("HHHHHHHH", nanopower_config.output_initial_on_delay[0],
                                 nanopower_config.output_initial_on_delay[1],
                                 nanopower_config.output_initial_on_delay[2],
                                 nanopower_config.output_initial_on_delay[3],
                                 nanopower_config.output_initial_on_delay[4],
                                 nanopower_config.output_initial_on_delay[5],
                                 nanopower_config.output_initial_on_delay[6],
                                 nanopower_config.output_initial_on_delay[7]));
    PyDict_SetItem(conf_data,                                           // uint16_t //! Output driver is initialized with these off delays [s]
                   Py_BuildValue("s", "output_initial_off_delay"),
                   Py_BuildValue("HHHHHHHH", nanopower_config.output_initial_off_delay[0],
                                 nanopower_config.output_initial_off_delay[1],
                                 nanopower_config.output_initial_off_delay[2],
                                 nanopower_config.output_initial_off_delay[3],
                                 nanopower_config.output_initial_off_delay[4],
                                 nanopower_config.output_initial_off_delay[5],
                                 nanopower_config.output_initial_off_delay[6],
                                 nanopower_config.output_initial_off_delay[7]));
    PyDict_SetItem(conf_data,                                           // uint16_t //! Fixed PPT point for boost converters [mV]
                   Py_BuildValue("s", "vboost"),
                   Py_BuildValue("HHH", nanopower_config.vboost[0], nanopower_config.vboost[1],
                                 nanopower_config.vboost[2]));
    return Py_BuildValue("iO", ret, conf_data);
}

/* int eps_config_print(eps_config_t * config) */
static PyObject* pyeps_config_print(PyObject* self, PyObject* args)
{
    eps_config_t nanopower_config;
    if (eps_config_get(&nanopower_config) > 0) {
        eps_config_print(&nanopower_config);
    }
    Py_RETURN_NONE;
}

/* int eps_config2_get(eps_config2_t * config) */
static PyObject* pyeps_config2_get(PyObject* self, PyObject* args)
{
    eps_config2_t nanopower_config2;
    int32_t ret = eps_config2_get(&nanopower_config2);
//        eps_config2_print(&nanopower_config);

    PyObject* conf_data = PyDict_New();
    PyDict_SetItem(conf_data, Py_BuildValue("s", "batt_maxvoltage"),        // uint16_t  //! Max voltage of battery [mV]
                   Py_BuildValue("H", nanopower_config2.batt_maxvoltage));
    PyDict_SetItem(conf_data, Py_BuildValue("s", "batt_safevoltage"),       // uint16_t  //! Safe voltage of battery [mV]
                   Py_BuildValue("H", nanopower_config2.batt_safevoltage));
    PyDict_SetItem(conf_data, Py_BuildValue("s", "batt_criticalvoltage"),   // uint16_t //! Critical voltage of battery [mV]
                   Py_BuildValue("H", nanopower_config2.batt_criticalvoltage));
    PyDict_SetItem(conf_data, Py_BuildValue("s", "batt_normalvoltage"),     // uint16_t //! Normal voltage of battery [mV]
                   Py_BuildValue("H", nanopower_config2.batt_normalvoltage));

    return Py_BuildValue("iO", ret, conf_data);
}

/* int eps_config2_print(eps_config_t * config) */
static PyObject* pyeps_config2_print(PyObject* self, PyObject* args)
{
    eps_config2_t nanopower_config2;
    if (eps_config2_get(&nanopower_config2) > 0) {
        eps_config2_print(&nanopower_config2);
    }
    Py_RETURN_NONE;
}

/* int eps_config3_get(eps_config3_t * config) */
static PyObject* pyeps_config3_get(PyObject* self, PyObject* args)
{
    eps_config3_t nanopower_config3;
    int32_t ret = eps_config3_get(&nanopower_config3);
//        eps_config3_print(&nanopower_config3);

    PyObject* conf_data = PyDict_New();
    PyDict_SetItem(conf_data,                                                   // uint16_t //! Power Channel current limit (0=off) [s]
                   Py_BuildValue("s", "cur_lim"),
                   Py_BuildValue("HHHHHHHH", nanopower_config3.cur_lim[0], nanopower_config3.cur_lim[1],
                                 nanopower_config3.cur_lim[2], nanopower_config3.cur_lim[3],
                                 nanopower_config3.cur_lim[4], nanopower_config3.cur_lim[5],
                                 nanopower_config3.cur_lim[6], nanopower_config3.cur_lim[7]));
    PyDict_SetItem(conf_data, Py_BuildValue("s", "cur_ema_gain"),               // uint8_t  //! Current EMA gain (10-90)
                   Py_BuildValue("B", nanopower_config3.cur_ema_gain));
    PyDict_SetItem(conf_data, Py_BuildValue("s", "cspwdt_channel"),             // uint8_t //! CSP WDT - Power Channel
                   Py_BuildValue("BB", nanopower_config3.cspwdt_channel[0], nanopower_config3.cspwdt_channel[1]));
    PyDict_SetItem(conf_data, Py_BuildValue("s", "cspwdt_address"),             // uint8_t //! CSP WDT - CSP Address
                   Py_BuildValue("BB", nanopower_config3.cspwdt_address[0], nanopower_config3.cspwdt_address[1]));
    return Py_BuildValue("iO", ret, conf_data);
}

/* int eps_config3_print(eps_config_t * config) */
static PyObject* pyeps_config3_print(PyObject* self, PyObject* args)
{
    eps_config3_t nanopower_config3;
    if (eps_config3_get(&nanopower_config3) > 0) {
        eps_config3_print(&nanopower_config3);
    }
    Py_RETURN_NONE;
}

static PyMethodDef methods[] = {

    {"eps_output_set", pyeps_output_set, METH_VARARGS, ""},
    {"eps_output_set_single", pyeps_output_set_single, METH_VARARGS, ""},
    {"eps_counters_reset", pyeps_counters_reset, METH_VARARGS, ""},
    {"eps_hardreset", pyeps_hardreset, METH_VARARGS, ""},
    {"eps_wdt_gnd_reset", pyeps_wdt_gnd_reset, METH_VARARGS, ""},
    {"eps_set_timeout", pyeps_set_timeout, METH_VARARGS, ""},
    {"eps_set_node", pyeps_set_node, METH_VARARGS, ""},
    {"eps_heater", pyeps_heater, METH_VARARGS, ""},
    {"eps_hk_get", pyeps_hk_get, METH_VARARGS, ""},
    {"eps_hk_print", pyeps_hk_print, METH_VARARGS, ""},
    {"eps_config_get", pyeps_config_get, METH_VARARGS, ""},
    {"eps_config_print", pyeps_config_print, METH_VARARGS, ""},
    {"eps_config2_get", pyeps_config2_get, METH_VARARGS, ""},
    {"eps_config2_print", pyeps_config2_print, METH_VARARGS, ""},
    {"eps_config3_get", pyeps_config3_get, METH_VARARGS, ""},
    {"pyeps_config3_print", pyeps_config3_print, METH_VARARGS, ""},
    /* sentinel */
    {NULL, NULL, 0, NULL}
};

#ifdef IS_PY3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "libgsnanopower_client_py3",
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
PyMODINIT_FUNC PyInit_libgsnanopower_client_py3(void) {
#else
PyMODINIT_FUNC initlibgsnanopower_client_py2(void) {
#endif

#ifdef IS_PY3
    PyObject* m = PyModule_Create(&moduledef);
#else
    Py_InitModule("libgsnanopower_client_py2", methods);
#endif
    eps_set_timeout(1000);
#ifdef IS_PY3
    return m;
#endif
}
