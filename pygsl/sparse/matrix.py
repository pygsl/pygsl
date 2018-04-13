"""Wrapper for the sparse matrix

Most of the c-style methods were directly translated to a pythonic interface.

Warning:

    The following methods behave differently:

        * copies are made using the method :meth:`sparse_matrix.memcpy`

        * :meth:`sparse_matrix.tranpose` returns a new transposed object. It uses 
          :c:func`gsl_spmatrix_transpose_memcpy` internally. The new array is
          created by internally by this method.

        * :meth:`sparse_matrix.tranpose_internal` will transpose the internal 
          object representation.  It will call 
          :c:func:`gsl_spmatrix_transpose` or :c:func:`gsl_spmatrix_transpose2`
          depending on which one is approbriate
          You can call them directly using 
          :meth:`sparse_matrix.gsl_transpose_inplace` or 
          :meth:`sparse_matrix.gsl_transpose_inplace2` to access the gsl 
          functions directly
"""
import enum
import pygsl
from . import sparse_wrapper

class Form(enum.IntEnum):
    #: TRIPLET
    TRIPLET = sparse_wrapper.TRIPLET
    #: CCS
    CCS = sparse_wrapper.CCS
    #: CRS
    CRS = sparse_wrapper.CRS

#: all the details
sparse_matrix = sparse_wrapper.sparse_matrix

#: Generates a new matrix reading from a file where ite was written to using
#: :meth:`sparse_matrix.fprintf`
fscanf = sparse_wrapper.pygsl_spmatrix_fscanf

#: add(c, a, b):
#:
#: Wraps :c:func:`gsl_spmatrix_add`
#:
#: Args:
#:    c: sparse matrix with the result c = a + b
#:    a: sparse input matrix
#:    b: sparse input matrix
#:
#: All matrices must be of the same shape.
#: 
add = sparse_wrapper.pygsl_spmatrix_add
