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
import enum


# I am not sure yet if that works for all versions of numpy directly
_np_complex_t = complex
_np_float_t = float

get_typecode = pygsl.get_typecode
array_typed_copy = pygsl.array_typed_copy

eigen_symm_workspace = gslwrap.gsl_eigen_symm_workspace
eigen_symmv_workspace = gslwrap.gsl_eigen_symmv_workspace
eigen_herm_workspace = gslwrap.gsl_eigen_symm_workspace
eigen_hermv_workspace = gslwrap.gsl_eigen_symmv_workspace
eigen_nonsymm_workspace = gslwrap.gsl_eigen_nonsymm_workspace
eigen_nonsymmv_workspace = gslwrap.gsl_eigen_nonsymmv_workspace

#: sort non symmetric eigen values. see `SortType` for applicable sort strategy
eigen_nonsymmv_sort = gslwrap.gsl_eigen_nonsymmv_sort
#: sort symmetric eigen values. see `SortType` for applicable sort strategy
eigensymm_sort = gslwrap.gsl_eigen_symmv_sort
eigensymmv_sort = gslwrap.gsl_eigen_symmv_sort


class SortType(enum.IntEnum):
    val_asc = gslwrap.GSL_EIGEN_SORT_VAL_ASC
    val_desc = gslwrap.GSL_EIGEN_SORT_VAL_DESC
    abs_asc = gslwrap.GSL_EIGEN_SORT_ABS_ASC
    abs_desc = gslwrap.GSL_EIGEN_SORT_ABS_DESC


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
    compute_t: bool = False,
    balance: bool = False,
    schur: bool = False,
    ws: eigen_nonsymm_workspace = None,
) -> (int, np.ndarray, np.ndarray):
    """computes eigenvectors for a non symmetic array a

    Args:
         a:          the non symmetric matrix
         compute_t : compute full Schurr form (defaults to false)
         balance   : balance matix (defaults to false)
         schur     : compute additionally Schur from (useful if balanced is used)
         ws        : the workspace (default None).

    Returns:
         n_evals, t_eval, evec if (schur is false).

    Returns number of eigen vectors, the result stored in matrix (a)
    and the eigen values. In case schur is true, additionally the
    vector Z is returned.

    `compute_t` and `balance` will only be used if `ws = None`. In case
    you provide a workspace, use :meth:`eigen_nonsymm_workspace.params`
    to set the required parameters.

    Note:
        annotation is made for the case that shur is false.
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


def eigenvectors_nonsymmv(
    a: np.ndarray,
    balance: bool = False,
    schur: bool = False,
    ws: eigen_nonsymmv_workspace = None,
) -> (np.ndarray, np.ndarray, np.ndarray):
    """computes right eigenvectors for a non symmetic array a

    Args:
         a:          the non symmetric matrix
         balance   : balance matix (defaults to false)
         schur     : compute additionally Schur from
         ws        : the workspace (default None).

    Returns:
        A, eval, evec (if schur is `False`).

    In case schur is `True` additionally the matrix Z is returned.

    Note:
        annotation is made for the case that schur is false.
    """
    if ws is None:
        n = a.shape[1]
        ws = eigen_nonsymmv_workspace(n)
        ws.params(balance)
    if schur:
        A, t_eval, evec, Z = ws.non_symmv_int(a, True)
    else:
        A, t_eval, evec = ws.non_symmv_int(a, False)
    res = A, t_eval, evec
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
    an = a.astype(_np_complex_t)
    eval = np.zeros((n,), _np_float_t)
    if ws is None:
        ws = gslwrap.gsl_eigen_herm_workspace(n)
    _gslwrap.gsl_eigen_herm(an, eval, ws)
    return eval


def Heigenvectors(a, ws=None):
    """Heigenvectors(a, ws=None) -> (eval, evec)

    This function computes the eigenvalues and eigenvectors of the complex
    hermitian matrix A. The imaginary parts of the diagonal are assumed to be
    zero and are not referenced. The eigenvalues are stored in the vector
    eval and are unordered. The corresponding complex eigenvectors are
    stored in the columns of the matrix evec. For example, the eigenvector
    in the first column corresponds to the first eigenvalue. The
    eigenvectors are guaranteed to be mutually orthogonal and normalised to
    unit magnitude.
    """
    n = a.shape[0]
    an = a.astype(_np_complex_t)
    eval = np.zeros((n,), _np_float_t)
    evec = np.zeros((n, n), _np_complex_t)
    if ws is None:
        ws = gslwrap.gsl_eigen_hermv_workspace(n)
    _gslwrap.gsl_eigen_hermv(an, eval, evec, ws)
    return (eval, evec)
