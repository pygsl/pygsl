# Original Author : Fabian Jakobs
# Author: Pierre Schnizer
# Changes: Added nonsmmv April 2022
r"""

This module  provides functions for computing eigenvalues  and eigenvectors of
matrices using the gsl.

There  are routines  for real  symmetric and  complex hermitian  matrices, and
eigenvalues can be computed with  or without eigenvectors. The algorithms used
are symmetric bidiagonalization followed by QR reduction.

These routines  are intended for  "small" systems where simple  algorithms are
acceptable. Anyone  interested finding  eigenvalues and eigenvectors  of large
matrices  will want to  use the  sophisticated routines  found in  LAPACK. The
Fortran version  of LAPACK is recommended  as the standard  package for linear
algebra.

"""
import pygsl
from . import _gslwrap
from . import gslwrap
import numpy as np
import typing

get_typecode = pygsl.get_typecode
array_typed_copy = pygsl.array_typed_copy

eigen_symm_workspace = gslwrap.gsl_eigen_symm_workspace
eigen_symmv_workspace = gslwrap.gsl_eigen_symmv_workspace
eigen_herm_workspace = gslwrap.gsl_eigen_symm_workspace
eigen_hermv_workspace = gslwrap.gsl_eigen_symmv_workspace
eigen_nonsymm_workspace = gslwrap.gsl_eigen_nonsymm_workspace


def eigenvalues(a, ws=None):
    """eigenvalues(a, ws=None) -> array

    This function computes the eigenvalues of the real symmetric matrix a.
    The eigenvalues are returned as NumPy array and are unordered.
    """
    n = a.shape[1]
    code = get_typecode(a)
    an = array_typed_copy(a, code)
    eval = np.zeros((n,), code)
    if ws is None:
        ws = gslwrap.gsl_eigen_symm_workspace(n)
    _gslwrap.gsl_eigen_symm(an, eval, ws)
    return eval


def eigenvectors(a, ws=None):
    """eigenvectors(a, ws=None) -> (eval, evec)

    This function computes the eigenvalues and eigenvectors of the real
    symmetric matrix a. The eigenvalues are stored in the vector eval
    and are unordered. The corresponding eigenvectors are stored in the
    columns of the matrix evec. For example, the eigenvector in the first
    column corresponds to the first eigenvalue. The eigenvectors are

    guaranteed to be mutually orthogonal and normalised to unit magnitude.
    """
    n = a.shape[1]
    code = get_typecode(a)
    an = array_typed_copy(a, code)
    eval = np.zeros((n,), code)
    evec = np.zeros((n, n), code)
    if ws is None:
        ws = gslwrap.gsl_eigen_symmv_workspace(n)
    _gslwrap.gsl_eigen_symmv(an, eval, evec, ws)
    return (eval, evec)


def eigenvectors_nonsymm(
    a: np.ndarray,
    compute_t=False,
    balance=False,
    schur=False,
    ws: eigen_nonsymm_workspace = None,
):
    """computes eigenvectors for a non symmetic array a

    Args:
         a:          the non symmetric matrix
         compute_t : compute full Schurr form (defaults to false)
         balance   : balance matix (defaults to false)
         schur     : compute additionally Schur from (useful if balanced is used)
         ws        : the workspace (default None).
    Returns:
         n_evals, t_eval, evec

    Returns number of eigen vectors, the result stored in matrix (a) and
    the eigen values.

    `compute_t` and `balance` will only be used if `ws = None`
    """
    if ws is None:
        n = a.shape[1]
        ws = eigen_nonsymm_workspace(n)
        ws.params(compute_t, balance)
    if schur:
        t_eval, evec, Z = ws.non_symm_int(a, True)
    else:
        t_eval, evec = ws.non_symm_int(a, False)
    n_evals = ws.n_evals
    res = n_evals, t_eval, evec
    if schur:
        res += (Z,)
    return res


def Heigenvalues(a, ws=None):
    """Heigenvalues(a, ws=None) -> eval

    This function computes the eigenvalues of the complex hermitian matrix a.
    The imaginary parts of the diagonal are assumed to be zero and are not
    referenced. The eigenvalues are stored in the vector eval and are
    unordered.
    """
    n = a.shape[1]
    an = a.astype(np.complex)
    eval = np.zeros((n,), np.float)
    if ws is None:
        ws = gslwrap.gsl_eigen_herm_workspace(n)
    _gslwrap.gsl_eigen_herm(an, eval, ws)
    return eval


def Heigenvectors(a, ws=None):
    """Heigenvectors(a, ws=None) -> (eval, evec)

    This function computes the eigenvalues and eigenvectors of the complex
    hermitian matrix A.The imaginary parts of the diagonal are assumed to be
    zero and are not referenced. The eigenvalues are stored in the vector
    eval and are unordered. The corresponding complex eigenvectors are
    stored in the columns of the matrix evec. For example, the eigenvector
    in the first column corresponds to the first eigenvalue. The
    eigenvectors are guaranteed to be mutually orthogonal and normalised to
    unit magnitude.
    """
    n = a.shape[0]
    an = a.astype(np.complex)
    eval = np.zeros((n,), np.float)
    evec = np.zeros((n, n), np.complex)
    if ws is None:
        ws = gslwrap.gsl_eigen_hermv_workspace(n)
    _gslwrap.gsl_eigen_hermv(an, eval, evec, ws)
    return (eval, evec)
