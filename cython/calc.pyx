cdef extern from "calc_c.hpp":    #使いたい関数を含むC++のヘッダーを指定する
    cdef int add_c(int x, int y)  #使いたい関数を宣言する

#C++の関数を型情報をつけて呼び出すラッパー関数
def add(int x, int y):
    cdef int ans
    ans = add_c(x, y)
    return ans
