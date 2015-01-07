#include "dictobject.h"


PyTypeObject PyDict_Type = {
    PyObject_HEAD_INIT(&PyType_Type),
    "dict",
    PyDict_Print,
    NULL,
    NULL,
};

PyObject* PyDict_Create(){
    PyDictObject* ob_dict = (PyDictObject*)malloc(sizeof(PyDictObject));
    if(ob_dict == NULL){
        printf("no enough memory");
        return NULL;
    }

    ob_dict->ob_refcnt = 1;
    ob_dict->ob_type = &PyDict_Type;

    return (PyObject*)ob_dict;
}

PyObject* PyDict_GetItem(PyDictObject* target, PyObject* key){
    long keyHashValue = (key->ob_type)->py_hash(key);
    map<long,PyObject*> &dict = target->dict;
    map<long,PyObject*>::iterator it = dict.find(keyHashValue);
    map<long,PyObject*>::iterator end = dict.end();
    if(it == end){
        return NULL;
    }

    return it->second;
}

int PyDict_SetItem(PyDictObject* target, PyObject* key, PyObject* value){
    long keyHashValue = (key->ob_type)->py_hash(key);
    (target->dict)[keyHashValue] = value;
    return 0;
}

void PyDict_Print(PyObject* object){
    PyDictObject* dictObject = (PyDictObject*) object;
    printf("(");
    map<long,PyObject*>::iterator it = (dictObject->dict).begin();
    map<long,PyObject*>::iterator end = (dictObject->dict).end();

    for(;it != end;it++){
        printf("%ld :",it->first);
        PyObject* value = it->second;
        value->ob_type->py_print(value);
        printf(",");
    }
    printf(")\n");
}

