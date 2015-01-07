#include <string.h>
#include <stdlib.h>

#include "stringobject.h"


PyTypeObject PyStr_Type = {
    PyObject_HEAD_INIT(&PyType_Type),
    "string",
    PyStr_Print,
    PyStr_Add,
    PyStr_Hash,
};

PyObject* PyStr_Create(const char* str){
    int len;
    if((len = strlen(str)) > 49){
        printf("string is too long, must less than 49 charactors!");
        return NULL;
    }
    PyStrObject* str_obj = (PyStrObject*)malloc(sizeof(PyStrObject));
    if(str_obj == NULL){
        printf("no enough memory");
        return NULL;
    }
    str_obj->ob_refcnt = 1;
    str_obj->ob_type = &PyStr_Type;
    str_obj->str_len = len;
    str_obj->hash_value = -1;
    memset(str_obj->ob_sval,0,50);
    strcpy(str_obj->ob_sval,str);
    
    return (PyObject*)str_obj;
}

void PyStr_Print(PyObject* str_object){
    PyStrObject* ob = (PyStrObject*)str_object;
    printf("%s\n",ob->ob_sval);
}

PyObject* PyStr_Add(PyObject* str_ob1, PyObject* str_ob2){
    PyStrObject* str_result = (PyStrObject*)PyStr_Create("");
    if(str_result == NULL){
        printf("no enough memory");
        return NULL;
    }
    PyStrObject* ob1 = (PyStrObject*)str_ob1;
    PyStrObject* ob2 = (PyStrObject*)str_ob2;
    strcat(str_result->ob_sval,ob1->ob_sval);
    strcat(str_result->ob_sval,ob2->ob_sval);
    return (PyObject*)str_result;
}

//BKDR Hash Function
long PyStr_Hash(PyObject* str_object){
    PyStrObject* strObject = (PyStrObject*) str_object;
    
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    char* str = (char*)strObject->ob_sval;
    while (*str)
    {
        hash = hash * seed + (*str++);
    }

    long x = (hash & 0x7FFFFFFF);
    strObject->hash_value = x;
    return x;
}

