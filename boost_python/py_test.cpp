#include <boost/python.hpp>

#include <boost/python.hpp>

// C/C++の関数を定義する
int c_multiplication(int a, int b) {
	return a * b;
}

void c_hello_method(void) {
	printf("HELLO TEST\n");
	return;
}

// Python側へ伝えるための定義
BOOST_PYTHON_MODULE(py_test) {  // モジュール名
	using namespace boost::python;
	// def("Pythonメソッド名", C側の関数名)
	def("c_multiplication", c_multiplication);
	def("c_hello", c_hello_method);
}