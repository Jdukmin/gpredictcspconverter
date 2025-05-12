/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */

#include <Python.h>
#include <gs/adcs/adcs_param_types.h>
#include <gs/adcs/adcs_param.h>
#include <gs/adcs/adcs_types.h>

#if PY_MAJOR_VERSION == 3
#define IS_PY3
#endif

static PyMethodDef methods[] = {
    /* sentinel */
    {NULL, NULL, 0, NULL}
};

#ifdef IS_PY3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "libgsadcs_client_py3",
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
	methods,
    NULL,
    NULL,
    NULL,
    NULL
};
#endif

#ifdef IS_PY3
PyMODINIT_FUNC PyInit_libgsadcs_client_py3(void) {
#else
PyMODINIT_FUNC initlibgsadcs_client_py2(void) {
#endif

    PyObject* m;

#ifdef IS_PY3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule("libgsadcs_client_py2", methods);
#endif
    /**
     * adcs/adcs_param_types.h
     */

    PyModule_AddIntConstant(m, "MAX_ADCS_TLE_LINE", MAX_ADCS_TLE_LINE);

    /**
	 * adcs/adcs_param.h
	 */

	PyModule_AddIntConstant(m, "PARAM_ADCS_GNC", PARAM_ADCS_GNC);
    PyModule_AddIntConstant(m, "ADCS_PARAM_SGP4_TLE1", ADCS_PARAM_SGP4_TLE1);
    PyModule_AddIntConstant(m, "ADCS_PARAM_SGP4_TLE2", ADCS_PARAM_SGP4_TLE2);

    /**
	 * adcs/adcs_types.h
	 */

	PyModule_AddIntConstant(m, "ADCS_CMD_EPHEM_NEW_TLE", ADCS_CMD_EPHEM_NEW_TLE);

#ifdef IS_PY3
        return m;
#endif
}
