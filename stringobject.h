#ifndef Py_STRINGOBJECT_H
#define Py_STRINGOBJECT_H

#include "object.h"

typedef struct{
    PyObject_HEAD
    int str_len;
    long hash_value;
    char ob_sval[50];
}PyStrObject;

PyObject* PyStr_Create(const char* str);

void PyStr_Print(PyObject* str_object);

PyObject* PyStr_Add(PyObject* str_ob1, PyObject* str_ob2);

long PyStr_Hash(PyObject* str_object);

#endif
