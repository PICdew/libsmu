#include"libsmu.hpp"
#include <vector>
#include <Python.h>

Session* session;

void cpp_initSession();
int cpp_checkAvailable();

extern "C" {
    static PyObject* initSession(PyObject * self, PyObject * args){
        Session* x = new Session();
        //cpp_initSession();
        //int good = cpp_checkAvailable();
        PyObject* ret;
       // if (good == 0){
       //     ret = PyInt_FromLong(42l);
       // }
       // else{
       //     ret = PyInt_FromLong(67l);
       // }
       // return ret;
        ret = PyInt_FromLong(67l);
        return ret;
    }
    static PyMethodDef HelloMethods[] = {
        { "libsmu", initSession, METH_VARARGS, "Say hello"  },
        { NULL, NULL, 0, NULL  }
    };

    DL_EXPORT(void) initlibsmu(void)
    {
        Py_InitModule("libsmu", HelloMethods);
    }
};

void cpp_initSession(){
	session = new Session();
}
int cpp_checkAvailable(){
    return session->update_available_devices();
}
