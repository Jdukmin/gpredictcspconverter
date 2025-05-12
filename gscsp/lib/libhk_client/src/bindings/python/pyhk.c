/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#include <Python.h>

#define GS_HK_INTERNAL_USE 1
#include <gs/hk/internal/types.h>
#include <gs/util/byteorder.h>
#include <gs/util/string.h>
#include <gs/csp/csp.h>
#include <gs/csp/port.h>
#define GS_HK_INTERNAL_USE 1
#include <gs/hk/internal/types.h>

#if PY_MAJOR_VERSION == 3
#define IS_PY3
#endif

/**
 * libhk.h
 */


static PyObject* pyhk_request_beacons(PyObject *self, PyObject *args) {
    uint8_t type;
    uint32_t t0;
    uint32_t interval;
    uint32_t count;
    uint8_t addr;
    uint8_t protocol_version = GS_HK_REQUEST_PROTOCOL_V1;
    const char* path = '\0';
    if (!PyArg_ParseTuple(args, "bIIIb|sb", &type, &t0, &interval,
                          &count, &addr, &path, &protocol_version)) {
        return NULL; // TypeError is thrown
    }

    if(protocol_version > 0) {
        gs_hk_housekeeping_request_t req;
        req.p_version = protocol_version;
        req.type = type;
        req.count = util_hton32(count);
        req.interval = util_hton32(interval);
        req.t0 = util_hton32(t0);
        req.path[0] = '\0';
        //GS_STRNCPY(req.path, path);

        gs_error_t result = gs_csp_transaction(CSP_PRIO_NORM,
                                               addr,
                                               GS_CSP_PORT_HK,
                                               0, // timeout
                                               &req,
                                               sizeof(req),
                                               NULL,
                                               0,
                                               NULL);
        return Py_BuildValue("i", result);
    } else {
        gs_hk_housekeeping_request_legacy_t req;
        req.type = type;
        req.count = util_hton32(count);
        req.interval = util_hton32(interval);
        req.t0 = util_hton32(t0);
        req.path[0] = '\0';
        //GS_STRNCPY(req.path, path);

        gs_error_t result = gs_csp_transaction(CSP_PRIO_NORM,
                                               addr,
                                               GS_CSP_PORT_HK,
                                               0, // timeout
                                               &req,
                                               sizeof(req),
                                               NULL,
                                               0,
                                               NULL);
        return Py_BuildValue("i", result);

    }

}


static PyMethodDef methods[] = {

    /* libhk.h */
    {"request_beacons", pyhk_request_beacons, METH_VARARGS, ""},
    /* sentinel */
    {NULL, NULL, 0, NULL}
};

#ifdef IS_PY3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "libgshk_client_py3",
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
PyMODINIT_FUNC PyInit_libgshk_client_py3(void) {
#else
PyMODINIT_FUNC initlibgshk_client_py2(void) {
#endif

#ifdef IS_PY3
    PyObject* m = PyModule_Create(&moduledef);
#else
    Py_InitModule("libgshk_client_py2", methods);
#endif

#ifdef IS_PY3
    return m;
#endif
}
