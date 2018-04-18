"""Sparse matrix blas support
"""
import pygsl
from . import sparse_wrapper

#: dgemm
dgemm = sparse_wrapper.pygsl_spblas_dgemm
#: dgemv
dgemv = sparse_wrapper.pygsl_spblas_dgemv
