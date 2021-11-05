from setuptools import setup, Extension
from torch.utils import cpp_extension

setup(name='parser_patch',
      ext_modules=[cpp_extension.CppExtension('parser_patch', ['parser_patch.cpp'])],
      cmdclass={'build_ext': cpp_extension.BuildExtension})
