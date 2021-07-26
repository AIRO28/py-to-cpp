from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

#コンパイルするソースファイルをリストで指定
source = [
    'calc_c.cpp',
    './calc.pyx'
    ]

setup(
    cmdclass = {"build_ext": build_ext},
    ext_modules = [
        Extension(
            'calc',             #この名前でimportできるようになる
            source,
            language='c++',     #C++でコンパイルするために必要
        )
    ]
)