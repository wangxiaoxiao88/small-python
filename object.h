#ifndef Py_OBJECT_H
#define Py_OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PyObject_HEAD \
    int ob_refcnt; \
    struct _typeobject *ob_type;

#define PyObject_Var_HEAD \
    PyObject_HEAD         \
    int ob_size;

#define PyObject_HEAD_INIT(typeptr) \
    0,typeptr

typedef struct _object
{
    PyObject_HEAD
}PyObject;

typedef struct {
    PyObject_Var_HEAD
}PyVarObject;

typedef void (*printFunc)(PyObject* );
typedef PyObject* (*addFunc)(PyObject* ,PyObject*);
typedef long (*hashFunc)(PyObject*);

typedef struct _typeobject
{
    PyObject_HEAD
    const char *name;
    printFunc py_print;
    addFunc py_add;
    hashFunc py_hash;
}PyTypeObject;

static PyTypeObject PyType_Type = 
{
    PyObject_HEAD_INIT(&PyType_Type),
    "type",
    NULL,
    NULL,
    NULL,
};

#endif
