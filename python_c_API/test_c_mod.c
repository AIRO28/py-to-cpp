#define PY_SSIZE_T_CLEAN
#include <Python.h>
// #include "/home/otake/.pyenv/versions/3.6.8/include/python3.6m/Python.h"
// #include "/usr/include/python3.8/Python.h"

static PyObject* c_helloworld(PyObject* self, PyObject* args) {
    printf("Hello world!\n");
    return Py_None;
}

int c_add(int a, int b) {
    return a + b;
}

// c_addのラッパーを定義
static PyObject* pyadd(PyObject* self, PyObject* args) {
    int a, b, c;
    // 型を決定する
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    c = c_add(a, b);
    return Py_BuildValue("i", c);

}

// 関数定義
static PyMethodDef myMethods[] = {
    // {"Pythonで使用する際のメソッド名", C側の関数名, 引数の指定フラグ, "関数詳細説明"}
    {"helloworld", c_helloworld, METH_NOARGS, "HelloWorlds"},
    {"c_add", pyadd, METH_VARARGS, "Add a + b"},
    {NULL, NULL, 0, NULL},
};

// 構造体定義
static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "myModule2",
    "Python3 C API Module",
    -1,
    myMethods
};

// 関数の初期化
PyMODINIT_FUNC PyInit_myModule2(void){
    return PyModule_Create(&myModule);
}