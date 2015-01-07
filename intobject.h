#ifndef Py_INTOBJECT_H
#define Py_INTOBJECT_H

#include "object.h"

typedef struct {
    PyObject_HEAD
    int ob_ival; 
} PyIntObject; 

PyObject* PyInt_Create(int value);

void PyInt_Print(PyObject* num);

PyObject* PyInt_Add(PyObject* num1, PyObject* num2);

long PyInt_Hash(PyObject* O);


#endif
