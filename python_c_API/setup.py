try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension

module = Extension(
    "myModule2",
    sources=['test_c_mod.c']
)

setup(name= 'myModule2', version= '1.0.0', 
    ext_modules= [module],
    test_suite= 'test.suite')

