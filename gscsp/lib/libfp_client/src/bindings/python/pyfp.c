/* Copyright (c) 2013-2020 GomSpace A/S. All rights reserved. */

#include <Python.h>
#include <gs/fp/fp_client.h>

#if PY_MAJOR_VERSION == 3
#define IS_PY3
#endif

/*
  gs_error_t fp_client_host(uint8_t node)
 */
static PyObject* pyfp_server(PyObject* self, PyObject* args)
{
    uint8_t host;
    if (!PyArg_ParseTuple(args,
                          "b",
                          &host))
    {
        return NULL;
    }

    int rc = fp_client_host(host);
    return Py_BuildValue("i", rc);
}

/*
  gs_error_t fp_client_fp_flush(void)
 */
static PyObject* pyfp_flush(PyObject* self, PyObject* args)
{
    int rc = fp_client_fp_flush();
    return Py_BuildValue("i", rc);
}

/*
  gs_error_t fp_client_fp_store(const char * filename)
 */
static PyObject* pyfp_store(PyObject* self, PyObject* args)
{
    const char *path;
    if (!PyArg_ParseTuple(args,
                          "s",
                          &path))
    {
        return NULL;
    }

    int rc = fp_client_fp_store(path);
    return Py_BuildValue("i", rc);
}

/*
  gs_error_t fp_client_fp_load(const char * filename, bool fast_load_with_unique_keys)
 */
static PyObject* pyfp_load(PyObject* self, PyObject* args)
{
    const char *path;
    uint8_t fast_load_with_unique_keys = 0;

    if (!PyArg_ParseTuple(args,
                          "s|B",
                          &path, &fast_load_with_unique_keys))
    {
        return NULL;
    }

    int rc = fp_client_fp_load(path, fast_load_with_unique_keys);
    return Py_BuildValue("i", rc);
}

/*
  gs_error_t fp_client_timer_create(const char * key, const char * cmd, fp_timer_basis_t basis, fp_timer_state_t state, gs_timestamp_t *when, uint16_t repeat)
 */
static PyObject* pyfp_create(PyObject* self, PyObject* args)
{
    const char *key;
    const char *cmd;
    uint8_t basis;
    uint8_t state;
    unsigned long when;
    unsigned int repeat;
    if (!PyArg_ParseTuple(args,
                          "ssbbII",
                          &key,
                          &cmd,
                          &basis,
                          &state,
                          &when,
                          &repeat))
    {
        return NULL;
    }

    gs_timestamp_t t;
    t.tv_sec = when;
    t.tv_nsec = 0;
    int rc = fp_client_timer_create(key, cmd, basis, state, &t, repeat);
    return Py_BuildValue("i", rc);
}

/*
  gs_error_t fp_client_timer_delete(const char * key)
 */
static PyObject* pyfp_delete(PyObject* self, PyObject* args)
{
    const char *key;
    if (!PyArg_ParseTuple(args,
                          "s",
                          &key))
    {
        return NULL;
    }

    int rc = fp_client_timer_delete(key);
    return Py_BuildValue("i", rc);
}

/*
  gs_error_t fp_client_timer_set_active(const char * key)
 */
static PyObject* pyfp_active(PyObject* self, PyObject* args)
{
    const char *key;
    if (!PyArg_ParseTuple(args,
                          "s",
                          &key))
    {
        return NULL;
    }

    int rc = fp_client_timer_set_active(key);
    return Py_BuildValue("i", rc);
}

/*
  gs_error_t fp_client_timer_set_dormant(const char * key)
 */
static PyObject* pyfp_dormant(PyObject* self, PyObject* args)
{
    const char *key;
    if (!PyArg_ParseTuple(args,
                          "s",
                          &key))
    {
        return NULL;
    }

    int rc = fp_client_timer_set_dormant(key);
    return Py_BuildValue("i", rc);
}

/*
  gs_error_t fp_client_timer_set_repeat(const char * key, uint16_t count)
 */
static PyObject* pyfp_repeat(PyObject* self, PyObject* args)
{
    const char *key;
    unsigned int repeat;
    if (!PyArg_ParseTuple(args,
                          "sI",
                          &key,
                          &repeat))
    {
        return NULL;
    }

    int rc = fp_client_timer_set_repeat(key, repeat);
    return Py_BuildValue("i", rc);
}

/*
  gs_error_t fp_client_timer_set_time(const char * key, fp_timer_basis_t basis, const gs_timestamp_t * when)
 */
static PyObject* pyfp_time(PyObject* self, PyObject* args)
{
    const char *key;
    uint8_t basis;
    unsigned long when;
    if (!PyArg_ParseTuple(args,
                          "sbI",
                          &key,
                          &basis,
                          &when))
    {
        return NULL;
    }

    gs_timestamp_t t;
    t.tv_sec = when;
    t.tv_nsec = 0;
    int rc = fp_client_timer_set_time(key, basis, &t);
    return Py_BuildValue("i", rc);
}

/*
  gs_error_t fp_client_timer_set_all_active(void)
 */
static PyObject* pyfp_allactive(PyObject* self, PyObject* args)
{
    int rc = fp_client_timer_set_all_active();
    return Py_BuildValue("i", rc);
}


static PyMethodDef methods[] = {
    {"fp_server", pyfp_server, METH_VARARGS, ""},
    {"fp_flush", pyfp_flush, METH_NOARGS, ""},
    {"fp_store", pyfp_store, METH_VARARGS, ""},
    {"fp_load", pyfp_load, METH_VARARGS, ""},
    {"fp_create", pyfp_create, METH_VARARGS, ""},
    {"fp_delete", pyfp_delete, METH_VARARGS, ""},
    {"fp_active", pyfp_active, METH_VARARGS, ""},
    {"fp_dormant", pyfp_dormant, METH_VARARGS, ""},
    {"fp_repeat", pyfp_repeat, METH_VARARGS, ""},
    {"fp_time", pyfp_time, METH_VARARGS, ""},
    {"fp_allactive", pyfp_allactive, METH_NOARGS, ""},

    /* sentinel */
    {NULL, NULL, 0, NULL}
};

#ifdef IS_PY3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "libgsfp_client_py3",
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
PyMODINIT_FUNC PyInit_libgsfp_client_py3(void) {
#else
    PyMODINIT_FUNC initlibgsfp_client_py2(void) {
#endif

#ifdef IS_PY3
        PyObject* m = PyModule_Create(&moduledef);
#else
        Py_InitModule("libgsfp_client_py2", methods);
#endif

#ifdef IS_PY3
        return m;
#endif
    }
