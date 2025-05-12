/* Copyright (c) 2013-2018 GomSpace A/S. All rights reserved. */
#include <gs/rgosh/rgosh.h>
#include <Python.h>
#include <time.h>
#include <stdio.h>
#if PY_MAJOR_VERSION == 3
#define IS_PY3
#endif


typedef struct python_cmd_context {
    PyObject* results;
    char* std_out;
} python_cmd_context_t;

static void rgosh_run_cmd_result(void * context, const char * group, const char * key, const char * value)
{
    python_cmd_context_t *ctx = (python_cmd_context_t*)context;

    PyObject* gp = PyDict_GetItemString(ctx->results, group);
    if (gp == NULL) {
        gp = PyDict_New();
        PyDict_SetItemString(ctx->results, group, gp);
    }
    PyDict_SetItemString(gp, key, Py_BuildValue("s", value));
}

static void rgosh_run_cmd_stdout(void * context, const char * out)
{
    python_cmd_context_t *ctx = (python_cmd_context_t*)context;
    char *std_out = ctx->std_out;
    strcpy(std_out, out);
}

static const gs_rgosh_run_if_t rgosh_run_if = {
    .result_cb = rgosh_run_cmd_result,
    .stdout_cb = rgosh_run_cmd_stdout
};

static PyObject* pyrgosh_run_command(PyObject* self, PyObject *args)
{
    uint8_t node;
    uint8_t port;
    char* command;
    uint32_t timeout_ms = 5000;

    if (!PyArg_ParseTuple(args, "BBs|I", &node, &port, &command, &timeout_ms))
    {
        Py_RETURN_NONE;
    }
    gs_error_t error;
    gs_error_t ret_code;
    char std_out[512];
    memset(std_out, 0, sizeof(std_out));

    python_cmd_context_t ctx = {.results = PyDict_New(), .std_out = std_out};

    error = gs_rgosh_run_command(node, port, command, timeout_ms, &ret_code, &rgosh_run_if, &ctx);
    if (error == GS_OK) {
        error = ret_code;
    }

    return Py_BuildValue("isO", error, ctx.std_out, ctx.results);
}

static PyMethodDef methods[] = {
        {"run_command", pyrgosh_run_command, METH_VARARGS, ""},
        /* sentinel */
        {NULL, NULL, 0, NULL}
};


#ifdef IS_PY3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "pyrgosh_client_py3",
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
PyMODINIT_FUNC PyInit_libgsrgosh_client_py3(void) {
#else
PyMODINIT_FUNC initlibgsrgosh_client_py2(void) {
#endif

#ifdef IS_PY3
    PyObject* m = PyModule_Create(&moduledef);
#else
    Py_InitModule("libgsrgosh_client_py2", methods);
#endif

#ifdef IS_PY3
    return m;
#endif
}
