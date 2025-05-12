/* Copyright (c) 2013-2019 GomSpace A/S. All rights reserved. */
#include <Python.h>
#include <string.h>
#include <power_if.h>

#include <stdarg.h>


#if PY_MAJOR_VERSION == 3
#define IS_PY3
#endif

/* int power_if_cmd(uint8_t node, uint8_t port, uint32_t timeout, uint8_t cmd, void * ch_status); */
static PyObject* pypower_if_set(PyObject *self, PyObject *args) {
    uint8_t node;
    uint8_t port;
    uint32_t timeout;
    uint8_t mode;
    uint16_t on_cnt;
    uint16_t off_cnt;
    char* name;
    int namelen;
    int rc;
    if (!PyArg_ParseTuple(args, "BBIBHHs#", &node, &port, &timeout, &mode, &on_cnt, &off_cnt, &name, &namelen))
        return NULL;

    power_if_ch_status_t p;
    memset(&p, 0, sizeof(p));

    p.mode = mode;
    p.on_cnt = on_cnt;
    p.off_cnt = off_cnt;

    if (namelen < POWER_IF_NAME_LEN) {
        strncpy(p.name, name, (POWER_IF_NAME_LEN - 1));
        p.name[POWER_IF_NAME_LEN - 1] = 0;
        rc = p60_power_if_cmd(node, port, timeout, POWER_IF_SET, &p);
    } else {
        rc = -1;
    }
    PyObject* pyTuple = Py_BuildValue("iBBHHHHHhHs", rc,
                                                     p.ch_idx,
                                                     p.mode,
                                                     p.on_cnt,
                                                     p.off_cnt,
                                                     p.cur_lu_lim,
                                                     p.cur_lim,
                                                     p.voltage,
                                                     p.current,
                                                     p.latchup,
                                                     p.name);

    return pyTuple;
}

/* int power_if_cmd(uint8_t node, uint8_t port, uint32_t timeout, uint8_t cmd, void * ch_status); */
static PyObject* pypower_if_get(PyObject *self, PyObject *args) {
    uint8_t node;
    uint8_t port;
    uint32_t timeout;
    char* name;
    int namelen;
    int rc;
    if (!PyArg_ParseTuple(args, "BBIs#", &node, &port, &timeout, &name, &namelen))
        return NULL;

    power_if_ch_status_t p;
    memset(&p, 0, sizeof(p));

    if (namelen < POWER_IF_NAME_LEN) {
        strncpy(p.name, name, (POWER_IF_NAME_LEN - 1));
        p.name[POWER_IF_NAME_LEN - 1] = 0;
        rc = p60_power_if_cmd(node, port, timeout, POWER_IF_GET, &p);
    } else {
        rc = -1;
    }

    PyObject* pyTuple = Py_BuildValue("iBBHHHHHhHs", rc,
                                                     p.ch_idx,
                                                     p.mode,
                                                     p.on_cnt,
                                                     p.off_cnt,
                                                     p.cur_lu_lim,
                                                     p.cur_lim,
                                                     p.voltage,
                                                     p.current,
                                                     p.latchup,
                                                     p.name);

    return pyTuple;
}

/* int power_if_cmd(uint8_t node, uint8_t port, uint32_t timeout, uint8_t cmd, void * ch_status); */
static PyObject* pypower_if_list(PyObject *self, PyObject *args) {
    uint8_t node;
    uint8_t port;
    uint32_t timeout;
    if (!PyArg_ParseTuple(args, "BBI", &node, &port, &timeout))
        return NULL;

    power_if_cmd_list_response_t p;
    memset(&p, 0, sizeof(p));

    PyObject *pyList_Entries = (PyObject*) Py_BuildValue("[]");

    int rc = p60_power_if_cmd(node, port, timeout, POWER_IF_LIST, &p);

    if (rc == 0)
    {
        for (int i = 0; i < p.count; i++)
        {
            power_if_list_t *l = &p.list[i];
            PyList_Append(pyList_Entries, PyList_AsTuple(Py_BuildValue("[B,B,s]", l->ch_idx, l->mode, l->name)));
        }
    }

    PyObject *pyList = (PyObject*) Py_BuildValue("[]");
    PyList_Append(pyList, Py_BuildValue("i", rc));
    PyList_Append(pyList, pyList_Entries);
    return PyList_AsTuple(pyList);
}

static PyMethodDef methods[] = {
    /* power_if.h */
    {"power_if_set", pypower_if_set, METH_VARARGS, ""},
    {"power_if_get", pypower_if_get, METH_VARARGS, ""},
    {"power_if_list", pypower_if_list, METH_VARARGS, ""},

    /* sentinel */
    {NULL, NULL, 0, NULL}
};

#ifdef IS_PY3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "libgsp60_client_py3",
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
PyMODINIT_FUNC PyInit_libgsp60_client_py3(void) {
#else
PyMODINIT_FUNC initlibgsp60_client_py2(void) {
#endif

#ifdef IS_PY3
    PyObject* m = PyModule_Create(&moduledef);
#else
    Py_InitModule("libgsp60_client_py2", methods);
#endif

#ifdef IS_PY3
    return m;
#endif
}
