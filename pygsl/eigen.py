# Author : Fabian Jakobs
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
import _gslwrap
import gslwrap
import pygsl._numobj as numx
_float   = pygsl.Float
_complex = pygsl.Complex
get_typecode = pygsl.get_typecode
array_typed_copy = pygsl.array_typed_copy

eigen_symm_workspace = gslwrap.gsl_eigen_symm_workspace
eigen_symmv_workspace = gslwrap.gsl_eigen_symmv_workspace
eigen_herm_workspace = gslwrap.gsl_eigen_symm_workspace
eigen_hermv_workspace = gslwrap.gsl_eigen_symmv_workspace


def eigenvalues(a, ws=None):
    """eigenvalues(a, ws=None) -> array
    
    This function computes the eigenvalues of the real symmetric matrix a.
    The eigenvalues are returned as NumPy array and are unordered. 
    """
    n = a.shape[1]
    code = get_typecode(a)
    an = array_typed_copy(a, code)
    eval = numx.zeros((n,), code)
    if ws == None:
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
    eval = numx.zeros((n,), code)
    evec = numx.zeros((n,n), code)
    if ws == None:
        ws = gslwrap.gsl_eigen_symmv_workspace(n)
    _gslwrap.gsl_eigen_symmv(an, eval, evec, ws)
    return (eval, evec)

def Heigenvalues(a, ws=None):
    """Heigenvalues(a, ws=None) -> eval

    This function computes the eigenvalues of the complex hermitian matrix a.
    The imaginary parts of the diagonal are assumed to be zero and are not
    referenced. The eigenvalues are stored in the vector eval and are
    unordered. 
    """
    n = a.shape[1]
    an = a.astype(_complex)
    eval = numx.zeros((n,), _float)
    if ws == None:
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
    an = a.astype(_complex)
    eval = numx.zeros((n,), _float)
    evec = numx.zeros((n,n), _complex)
    if ws == None:
        ws = gslwrap.gsl_eigen_hermv_workspace(n)
    _gslwrap.gsl_eigen_hermv(an, eval, evec, ws)
    return (eval, evec)
