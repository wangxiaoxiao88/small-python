# ifndef Py_DICTOBJECT_H
# define Py_DICTOBJECT_H

#include "object.h"
#include <map>
using namespace std;

#define DICT_LEN 27

typedef struct{
    PyObject_HEAD;
    map<long,PyObject*> dict;
}PyDictObject;

PyObject* PyDict_Create();

PyObject* PyDict_GetItem(PyDictObject* target, PyObject* key);

int PyDict_SetItem(PyDictObject* target, PyObject* key, PyObject* value);

void PyDict_Print(PyObject* object);

#endif
