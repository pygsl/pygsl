"""Sparse matrix lapack support
"""
import pygsl
from . import sparse_wrapper

#: the solver :c:any:`gsl_splinalg_itersolve_gmres`
gmres = sparse_wrapper.cvar.gsl_splinalg_itersolve_gmres

# the iterative solver
itersolver =  sparse_wrapper.gsl_splinalg_itersolve

class GMRES(itersolver):
    def __init__(self, n, m):
        super().__init__(gmres, n, m)
