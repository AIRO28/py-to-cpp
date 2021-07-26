# Name

**py-to-cpp**

# Overview

PythonからC/C++で実装されたソースコードを呼び出すための手法についてまとめたリポジトリ。
いずれの手法も、C/C++のソースコードをダイナミックリンクライブラリ(.so)ファイルにコンパイルしてから、Pythonでimportして使用するような方法を取る。

## ディレクトリ構成

```bash
.
├── README.md
├── boost_python
│   ├── py_test.cpp
│   └── run_method.py
├── cython
│   ├── calc.pyx
│   ├── calc_c.cpp
│   ├── calc_c.hpp
│   ├── run_method.py
│   └── setup.py
└── python_c_API
    ├── run_method.py	(実際にPythonで動作させるためのコード)
    ├── setup.py		(コンパイル時の設定)
    ├── test.py			(テストスイート)
    └── test_c_mod.c	(Pythonモジュール化したいC/C++関数)
```

# Demo

## Python C API

pythonに標準で実装されているPython C APIを使って行う方法。

### コンパイルを実行する

```bash
$ cd python_c_API
# コンパイルする("./build"以下に.soファイルが生成される)
$ python3 setup.py build
```

### コンパイルしてpipの管理化にインストールする

```bash
$ cd python_c_API

# コンパイルしてpipの管理に追加する
$ python3 setup.py install
# 確認
$ pip freeze
```

### コンパイル時にテストを実行する

```bash
$ cd python_c_API
# コンパイルしてライブラリのテストを実行する
$ python3 setup.py test
```

## Cython

Cythonライブラリを使用して行う方法。

### ライブラリのインストール

```bash
$ pip install cython
```

### コンパイルを実行する

```bash
$ cd cython
# コンパイルする("./build"以下に.soファイルが生成される)
$ python3 setup.py build_ext
```

## Boost/Python

Boost/Pythonのライブラリを使用して行う方法。
Pythonでラッパーとなる処理を記述しなくて良いぶん楽だが、環境周りがネック。

### ライブラリのインストール

```bash
$ sudo apt install -y libboost-dev
```

### コンパイルを実行する

```bash
$ cd boost_python
# Boost/pythonライブラリ名を調べる
$ ldconfig -p | grep "boost_python3"

# コンパイルする("./"以下に.soファイルが生成される)
$ g++ -shared -DPIC -fPIC -lboost_python38 -I/usr/local/include -L/usr/local/lib $(python3-config --includes) -o py_test.so py_test.cpp
```

# Author

- AIRO
- "https://twitter.com/AIRO28_"

