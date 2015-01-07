#include "object.h"
#include "intobject.h"
#include "stringobject.h"
#include "dictobject.h"
#include <string>
#include <iostream>
using namespace std;

PyDictObject m_LocalEnvironment;

bool IsSourceDigit(string& source){
        string::size_type size = source.size();
        for(string::size_type i = 0;i<size;i++){
            if(source.at(i) < '0' || source.at(i) > '9'){
                return false;
            }
        }
    return true;
}

PyObject* GetObjectBySymbol(string symbol){
    PyObject* key = PyStr_Create(symbol.c_str());
    PyObject* value = PyDict_GetItem(&m_LocalEnvironment, key);
    if(value == NULL){
        cout << "can't find symbol = " + symbol << endl;
        return NULL;
    }
    return value;
}

void ExcutePrint(string symbol){
    PyObject* value = GetObjectBySymbol(symbol);
    if(value != NULL){
        (value->ob_type)->py_print(value);
    }    
}

void ExcuteAdd(string& target,string& source){
    string::size_type pos;
    PyObject* strValue = NULL;
    PyObject* resultValue = NULL;
    if(IsSourceDigit(source)){
        PyObject* intValue = PyInt_Create(atoi(source.c_str()));
        PyObject* key = PyStr_Create(target.c_str());
        PyDict_SetItem(&m_LocalEnvironment, key ,intValue);        
    } else if(source.find("\"") != string::npos){
        strValue = PyStr_Create(source.substr(1,source.size()-2).c_str());
        PyObject* key = PyStr_Create(target.c_str());
        PyDict_SetItem(&m_LocalEnvironment, key, strValue);
    } else if((pos = source.find("+")) != string::npos){
        PyObject* leftObject = GetObjectBySymbol(source.substr(0,pos));
        PyObject* rightObject = GetObjectBySymbol(source.substr(pos+1));

        if(leftObject != NULL && rightObject != NULL && leftObject->ob_type == rightObject->ob_type){
            resultValue = (leftObject->ob_type)->py_add(leftObject, rightObject);
            PyObject* key = PyStr_Create(target.c_str());
            PyDict_SetItem(&m_LocalEnvironment, key, resultValue);
        }
    }
}

void ExcuteCommand(string& command){
    string::size_type pos = 0;
    if((pos = command.find("print ") != string::npos)){
        ExcutePrint(command.substr(6));
    } else if((pos = command.find(" = ")) != string::npos){
        string target = command.substr(0,pos);
        string source = command.substr(pos+3);
        ExcuteAdd(target, source);
    }
}


int main(void){
    const char* prompt = ">>> ";
    cout<< prompt;
    
    string m_Command;
    while(getline(cin,m_Command)){
        if(m_Command.size() == 0){
            cout<<prompt;
            continue;
        } else if(m_Command == "exit"){
            return 0;
        } else {
            ExcuteCommand(m_Command);
        }
        cout << prompt;
    }
    return 0;
}
