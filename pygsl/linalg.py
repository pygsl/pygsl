# Author : Fabian Jakobs
"""
Functions for solving linear systems.

The library provides simple linear algebra operations which operate
directly on the gsl_vector and gsl_matrix objects. These are intended
for use with "small" systems where simple algorithms are acceptable.

Anyone interested in large systems will want to use the sophisticated
routines found in LAPACK. The Fortran version of LAPACK is recommended
as the standard package for linear algebra. It supports blocked algorithms,
specialized data representations and other optimizations.
"""
import pygsl
import _gslwrap
from permutation import Permutation
import pygsl._numobj as numx
zeros = numx.zeros
array = numx.array
get_typecode = pygsl.get_typecode
array_typed_copy = pygsl.array_typed_copy
Float = pygsl.Float
Complex = pygsl.Complex
#
# LU Decomposition
#

def LU_decomp(A):
    """
    returns (LU, P, signum)
    
    This function factorizes the square matrix A into the LU decomposition
    PA = LU. On output the diagonal and upper triangular part of the return
    matrix contain the matrix U. The lower triangular part of the input matrix
    (excluding the diagonal) contains L. The diagonal elements of L are unity,
    and are not stored.
    
    The permutation matrix P is encoded in the permutation p. The j-th column
su
of the matrix P is given by the k-th column of the identity matrix, where
    k = p_j the j-th element of the permutation vector. The sign of the
    permutation is given by signum. It has the value (-1)^n, where n is the
    number of interchanges in the permutation.
    
    The algorithm used in the decomposition is Gaussian Elimination with
    partial pivoting (Golub & Van Loan, Matrix Computations, Algorithm 3.4.1).
    """
    
    p = Permutation(A.shape[1])
    code = get_typecode(A)
    An = array_typed_copy(A)
    if code == Complex:
        # Now all error flags are turned into python exceptions. So no
        # unpack necessary any longer.
        signum = _gslwrap.gsl_linalg_complex_LU_decomp(An, p)
    elif code == Float:
        signum = _gslwrap.gsl_linalg_LU_decomp(An, p)
    else:
        print code, Float, Complex
        raise TypeError, "LU must be of type Float or Complex"
    return (An, p, signum)


def LU_unpack(LU):
    """
    returns (L,U)
    
    This function splits the matrix LU into the the upper matrix U and
    the lower matrix L. The diagonal of L is the identity.
    """
    code = get_typecode(LU)
    u = zeros(LU.shape, code)
    l = numx.identity(LU.shape[0], code)
    for i in  range(LU.shape[0]):
        u[i, i: ] = LU[i, i:]
        l[i, 0:i] = LU[i, :i]
    return (l, u)

        
def LU_solve(LU, p, b):
    """
    This function solves the system A x = b using the LU decomposition of A
    into (LU, p) given by LU_decomp.
    """
    code = get_typecode(LU)
    x = zeros(LU.shape[1], code)
    if code == Complex:
        _gslwrap.gsl_linalg_complex_LU_solve(LU, p, b, x)
    elif code == Float:
        _gslwrap.gsl_linalg_LU_solve(LU, p, b, x)
    else:
        raise TypeError, "LU must be of type Float or Complex"
    return x


def LU_refine(A, LU, p, b, x):
    """
    returns (x, residual)

    This functions applies an iterative improvement to x, the solution
    of A x = b, using the LU decomposition of A into (LU,p). The initial
    residual r = A x - b is also computed and stored in residual. 
    """
    code = get_typecode(LU)
    raise NotImplementedError, "This function is not (yet implemented)"
#    if code == Numeric.Complex:
#        _gslwrap.gsl_linalg_complex_LU_refine(A, LU, p, b, x, residual)
#    elif code == Numeric.Float:
#        _gslwrap.gsl_linalg_LU_refine
#    else:
#        raise TypeError, "LU must be of type Float or Complex"
    

def LU_invert(LU, p):
    """
    returns inverse

    This function computes the inverse of a matrix A from its LU
    decomposition (LU,p), storing the result in the matrix inverse.
    The inverse is computed by solving the system A x = b for each column of
    the identity matrix. It is preferable to avoid direct computation of the
    inverse whenever possible.
    """
    code = get_typecode(LU)
    inverse = zeros(LU.shape, code)
    if code == Complex:
        _gslwrap.gls_linalg_complex_LU_invert(LU, p, inverse)
    elif code == Float:
        _gslwrap.gsl_linalg_LU_invert(LU, p, inverse)
    else:
        raise TypeError, "LU must be of type Float or Complex"
    return inverse


def LU_det(LU, signum):
    """
    returns determinant

    This function computes the determinant of a matrix A from its LU
    decomposition, LU. The determinant is computed as the product of
    the diagonal elements of U and the sign of the row permutation signum.
    """
    code = get_typecode(LU)
    if code == Complex:
        return _gslwrap.gls_linalg_complex_LU_det(LU, signum)
    elif code == Float:
        return _gslwrap.gsl_linalg_LU_det(LU, signum)
    else:
        raise TypeError, "LU must be of type Float or Complex"


def LU_lndet(LU):
    """
    This function computes the logarithm of the absolute value of the
    determinant of a matrix A, \ln|det(A)|, from its LU decomposition, LU.
    This function may be useful if the direct computation of the determinant
    would overflow or underflow.
    """
    code = get_typecode(LU)
    if code == Complex:
        return _gslwrap.gls_linalg_complex_LU_lndet(LU)
    elif code == Float:
        return _gslwrap.gsl_linalg_LU_lndet(LU)
    else:
        raise TypeError, "LU must be of type Float or Complex"


def LU_sgndet(LU, signum):
    """
    This function computes the sign or phase factor of the determinant of a
    matrix A, det(A)/|det(A)|, from its LU decomposition, LU.
    """
    code = get_typecode(LU)
    if code == Complex:
        return _gslwrap.gls_linalg_complex_LU_sgndet(LU, signum)
    elif code == Float:
        return _gslwrap.gsl_linalg_LU_sgndet(LU, signum)
    else:
        raise TypeError, "LU must be of type Float or Complex"
    

#
# QR Decomposition
#

def QR_decomp(A):
    """
    returns (QR, tau)
    
    Function: int gsl_linalg_QR_decomp (gsl_matrix * A, gsl_vector * tau)
    This function factorizes the M-by-N matrix A into the QR
    decomposition A = Q R. On output the diagonal and upper triangular
    part of the input matrix contain the matrix R. The vector tau and the
    columns of the lower triangular part of the matrix QR contain the
    Householder coefficients and Householder vectors which encode the
    orthogonal matrix Q. The vector tau must be of length k=\min(M,N).
    The matrix Q is related to these components by, Q = Q_k ... Q_2 Q_1
    where Q_i = I - \tau_i v_i v_i^T and v_i is the Householder vector
    v_i = (0,...,1,A(i+1,i),A(i+2,i),...,A(m,i)).
    This is the same storage scheme as used by LAPACK.

    The algorithm used to perform the decomposition is Householder QR
    (Golub & Van Loan, Matrix Computations, Algorithm 5.2.1).
    """
    code = get_typecode(A)
    qr = array_typed_copy(A, code)
    tau = zeros((min(A.shape),), code)
    _gslwrap.gsl_linalg_QR_decomp(qr, tau)
    return (qr, tau)


def QR_solve(QR, tau, b):
    """
    returns x
    
    This function solves the system A x = b using the QR decomposition of
    A into (QR, tau) given by gsl_linalg_QR_decomp.
    """
    code = get_typecode(b)
    x = zeros(QR.shape[1], code)
    _gslwrap.gsl_linalg_QR_solve(QR, tau, b, x)
    return x


def QR_lssolve(QR, tau, b):
    """
    returns (x, residual)
    
    This function finds the least squares solution to the overdetermined
    system A x = b where the matrix A has more rows than columns. The least
    squares solution minimizes the Euclidean norm of the residual, ||Ax - b||.
    The routine uses the QR decomposition of A into (QR, tau) given by
    gsl_linalg_QR_decomp. The solution is returned in x. The residual is
    computed as a by-product and stored in residual.
    """
    code = get_typecode(QR)
    x = zeros(QR.shape[1], code)
    residual = zeros(QR.shape[0], code)
    _gslwrap.gsl_linalg_QR_lssolve(QR, tau, b, x, residual)
    return (x, residual)


def QR_QTvec(QR, tau, v):
    """
    returns v'

    This function applies the matrix Q^T encoded in the decomposition
    (QR,tau) to the vector v, storing the result Q^T v in v'. The matrix
    multiplication is carried out directly using the encoding of the
    Householder vectors without needing to form the full matrix Q^T.
    """
    vn = array_typed_copy(v)
    _gslwrap.gsl_linalg_QR_QTvec(QR,tau,vn)
    return vn


def QR_Qvec(QR, tau, v):
    """
    returns v'
    
    This function applies the matrix Q encoded in the decomposition
    (QR,tau) to the vector v, storing the result Q v in v'. The matrix
    multiplication is carried out directly using the encoding of the
    Householder vectors without needing to form the full matrix Q.
    """
    vn = array_typed_copy(v)
    _gslwrap.gsl_linalg_QR_Qvec(QR,tau,vn)
    return vn
    

def QR_Rsolve(QR, b):
    """
    returns x
    
    This function solves the triangular system R x = b for x.
    It may be useful if the product b' = Q^T b has already been computed
    using gsl.linalg.QR_QTvec.
    """
    x = zeros(QR.shape[1], get_typecode(b))
    _gslwrap.gsl_linalg_QR_Rsolve(QR, b, x)
    return x
    
    
def QR_unpack(QR, tau):
    """
    returns (Q, R)
    
    This function unpacks the encoded QR decomposition (QR,tau) into the
    matrices Q and R, where Q is M-by-M and R is M-by-N.
    """
    (m, n) = QR.shape
    code = get_typecode(QR)
    q = zeros([m,m], code)
    r = zeros([m,n], code)
    _gslwrap.gsl_linalg_QR_unpack(QR, tau, q, r)
    return (q,r)
    

def QR_QRsolve(Q, R, b):
    """
    returns x
    
    This function solves the system R x = Q^T b for x. It can be used when
    the QR decomposition of a matrix is available in unpacked form as (Q,R).
    """
    x = zeros(R.shape[1], get_typecode(R))
    _gslwrap.gsl_linalg_QR_QRsolve(Q, R, b, x)
    return x


def QR_update(Q, R, w, v):
    """
    This function performs a rank-1 update w v^T of the QR
    decomposition (Q, R). The update is given by Q'R' = Q R + w v^T
    where the output matrices Q' and R' are also orthogonal and right
    triangular. Note that Q and R are overwritten with Q' and R'!
    """
    raise NotImplementedError, "Please verify the output of this function!"
    wn = array_typed_copy(w)
    _gslwrap.gsl_linalg_QR_update(Q, R, wn, v)


def R_solve(R, b):
    """
    returns x
    
    This function solves the triangular system R x = b for the N-by-N
    matrix R.
    """
    x = zeros(R.shape[1], get_typecode(R))
    _gslwrap.gsl_linalg_QR_QRsolve(R, b, x)
    return x
    

#
# SVD Singular Value Decomposition
#
    
def SV_decomp(A):
    """
    returns (U, V, S)

    This function factorizes the M-by-N matrix A into the singular value
    decomposition A = U S V^T. The diagonal elements of the singular value
    matrix S are stored in the vector S. The singular values are non-negative
    and form a non-increasing sequence from S_1 to S_N. The matrix V
    contains the elements of V in untransposed form. To form the product
    U S V^T it is necessary to take the transpose of V. A workspace of
    length N is required in work.
    
    This routine uses the Golub-Reinsch SVD algorithm.
    """    
    code = get_typecode(A)
    n = A.shape[1]
    u = array_typed_copy(A, code)
    s = zeros(n, code)
    v = zeros((n, n), code)
    work = zeros(A.shape[1], code)
    _gslwrap.gsl_linalg_SV_decomp(u, v, s, work)
    return (u, v, s)
    

def SV_decomp_mod(A):
    """
    returns (u, v, s)
    
    This function computes the SVD using the modified Golub-Reinsch
    algorithm, which is faster for M>>N. It requires the vector work
    and the N-by-N matrix X as additional working space.
    """
    code = get_typecode(A)
    n = A.shape[1]
    u = array_typed_copy(A, code)
    s = zeros(n, code)
    v = zeros((n, n), code)
    x = zeros((n, n), code)
    work = zeros(A.shape[1], code)
    _gslwrap.gsl_linalg_SV_decomp_mod(u, x, v, s, work)
    return (u, v, s)
    

def SV_decomp_jacobi(A):
    """
    returns (u, v, s)

    This function computes the SVD using one-sided Jacobi orthogonalization
    (see references for details). The Jacobi method can compute singular
    values to higher relative accuracy than Golub-Reinsch algorithms.
    """
    code = get_typecode(A)
    n = A.shape[1]
    u = array_typed_copy(A, code)
    s = zeros(n, code)
    v = zeros((n, n), code)
    _gslwrap.gsl_linalg_SV_decomp_jacobi(u, v, s)
    return (u, v, s)
    

def SV_solve(U, V, S, b):
    """
    returns x
    
    This function solves the system A x = b using the singular value
    decomposition (U, S, V) of A given by gsl_linalg_SV_decomp.

    Only non-zero singular values are used in computing the solution.
    The parts of the solution corresponding to singular values of zero
    are ignored. Other singular values can be edited out by setting them
    to zero before calling this function.

    In the over-determined case where A has more rows than columns the
    system is solved in the least squares sense, returning the solution x
    which minimizes ||A x - b||_2. 
    """
    x = zeros(U.shape[1], get_typecode(b))
    _gslwrap.gsl_linalg_SV_solve(U, V, S, b, x)
    return x


#
# Cholesky Decomposition
#

def cholesky_decomp(A):
    """
    Function: int gsl_linalg_cholesky_decomp (gsl_matrix * A)

    This function factorizes the positive-definite square matrix A into
    the Cholesky decomposition A = L L^T. On output the diagonal and
    lower triangular part of the input matrix A contain the matrix L.
    The upper triangular part of the input matrix contains L^T, the diagonal
    terms being identical for both L and L^T. If the matrix is not
    positive-definite then the decomposition will fail, returning the
    error code GSL_EDOM.
    """
    An = array_typed_copy(A)
    _gslwrap.gsl_linalg_cholesky_decomp(An)
    return An


def cholesky_unpack(L):
    """
    returns (L, L^T)
    
    This function splits the matrix L into the the upper matrix L^T and
    the lower matrix L. The diagonal of L is the identical for both.
    """
    lt = zeros(L.shape, get_typecode(L))
    l = zeros(L.shape, get_typecode(L))
    for i in  range(L.shape[0]):
        lt[i, i: ] = L[i, i:]
        l[i, 0:i+1] = L[i, :i+1]
    return (l, lt)


def cholesky_solve(cholesky, b):
    """
    returns x
    
    This function solves the system A x = b using the Cholesky decomposition
    of A into the matrix cholesky given by cholesky_decomp.
    """
    x = zeros(b.shape, get_typecode(b))
    _gslwrap.gsl_linalg_cholesky_solve(cholesky, b, x)
    return x


#
# Tridiagonal Decomposition of Real Symmetric Matrices
#
# A symmetric matrix A can be factorized by similarity transformations
# into the form,
#
# A = Q T Q^T
#
# where Q is an orthogonal matrix and T is a symmetric tridiagonal matrix.
#

def symmtd_decomp(A):
    """
    returns (QT, tau)
    
    This function factorizes the symmetric square matrix A into the
    symmetric tridiagonal decomposition Q T Q^T. On output the diagonal
    and subdiagonal part of the input matrix A contain the tridiagonal
    matrix T. The remaining lower triangular part of the input matrix
    contains the Householder vectors which, together with the Householder
    coefficients tau, encode the orthogonal matrix Q. This storage scheme
    is the same as used by LAPACK. The upper triangular part of A is not
    referenced.
    """
    code = get_typecode(A)
    QT = array_typed_copy(A, code)
    tau = zeros(A.shape[0]-1, code)
    _gslwrap.gsl_linalg_symmtd_decomp(QT, tau)
    return (QT, tau)


def symmtd_unpack(A, tau):
    """
    returns (Q, diag, subdiag)
    
    This function unpacks the encoded symmetric tridiagonal decomposition
    (A, tau) obtained from gsl_linalg_symmtd_decomp into the orthogonal
    matrix Q, the vector of diagonal elements diag and the vector of
    subdiagonal elements subdiag.
    """
    n = A.shape[0]
    code = get_typecode(A)
    Q = zeros([n,n], code)
    diag = zeros((n,), code)
    subdiag = zeros((n-1,), code)
    _gslwrap.gsl_linalg_symmtd_unpack(A, tau, Q, diag, subdiag)
    return (Q, diag, subdiag)

    
def symmtd_unpack_T(A):
    """
    returns (diag, subdiag)

    This function unpacks the diagonal and subdiagonal of the encoded
    symmetric tridiagonal decomposition (A, tau) obtained from
    gsl_linalg_symmtd_decomp into the vectors diag and subdiag.
    """
    n = A.shape[0]
    code = get_typecode(A)
    diag = zeros((n,), code)
    subdiag = zeros((n-1,), code)
    _gslwrap.gsl_linalg_symmtd_unpack_T(A, diag, subdiag)
    return (diag, subdiag)


def symmtd_unpack_diag(diag, subdiag):
    """
    returns T

    This functions unpacks the tridiagonal matrix T of the diagonal
    and subdiagonal obtained from gsl_linalg_symmtd_unpack[_T]
    """
    n = diag.shape[0]
    T = numx.identity(n)*diag
    sub = numx.identity(n-1)*subdiag
    sub1 = numx.concatenate(
        (zeros((1,n)), numx.concatenate((sub, zeros((n-1,1))), 1)))
    sub2 = numx.concatenate(
        (numx.concatenate((zeros([n-1,1]),sub), 1), zeros([1,n])))
    T = sub1 + sub2 + T
    return T


#
# Tridiagonal Decomposition of Hermitian Matrices
#
# A hermitian matrix A can be factorized by similarity transformations
# into the form,
#
# A = U T U^T
#
# where U is an unitary matrix and T is a real symmetric tridiagonal matrix.
#


def hermtd_decomp(A):
    """
    returns (QT, tau)
    
    This function factorizes the hermitian matrix A into the symmetric
    tridiagonal decomposition U T U^T. On output the real parts of the
    diagonal and subdiagonal part of the input matrix A contain the
    tridiagonal matrix T. The remaining lower triangular part of the input
    matrix contains the Householder vectors which, together with the
    Householder coefficients tau, encode the orthogonal matrix Q. This
    storage scheme is the same as used by LAPACK. The upper triangular
    part of A and imaginary parts of the diagonal are not referenced.
    """
    code = get_typecode(A)
    QT = array_typed_copy(A, code)
    tau = zeros(A.shape[0]-1, code)
    _gslwrap.gsl_linalg_hermtd_decomp(QT, tau)
    return (QT, tau)


def hermtd_unpack(A, tau):
    """
    returns (Q, diag, subdiag)
    
    This function unpacks the encoded tridiagonal decomposition (A, tau)
    obtained from gsl_linalg_hermtd_decomp into the unitary matrix U, the
    real vector of diagonal elements diag and the real vector of subdiagonal
    elements subdiag.
    """
    n = A.shape[0]
    code = get_typecode(A)
    Q = zeros([n,n], code)
    diag = zeros((n,), Float)
    subdiag = zeros((n-1,), Float)
    _gslwrap.gsl_linalg_hermtd_unpack(A, tau, Q, diag, subdiag)
    return (Q, diag, subdiag)

    
def symmtd_unpack_T(A):
    """
    returns (diag, subdiag)

    This function unpacks the diagonal and subdiagonal of the encoded
    tridiagonal decomposition (A, tau) obtained from
    gsl_linalg_hermtd_decomp into the real vectors diag and subdiag.
    """
    n = A.shape[0]
    diag = zeros((n,), Float)
    subdiag = zeros((n-1,), Float)
    _gslwrap.gsl_linalg_hermtd_unpack_T(A, diag, subdiag)
    return (diag, subdiag)


def hermtd_unpack_diag(diag, subdiag):
    """
    returns T

    This functions unpacks the tridiagonal matrix T of the diagonal
    and subdiagonal obtained from gsl_linalg_hermtd_unpack[_T]
    """
    return symmtd_unpack_diag(diag, subdiag)


#
# Bidiagonalization
#
# A general matrix A can be factorized by similarity transformations into
# the form,
#
# A = U B V^T
#
# where U and V are orthogonal matrices and B is a N-by-N bidiagonal
# matrix with non-zero entries only on the diagonal and superdiagonal.
# The size of U is M-by-N and the size of V is N-by-N.
#

def bidiag_decomp(A):
    """
    returns (BUV, tau_U, tau_V)

    This function factorizes the M-by-N matrix A into bidiagonal
    form U B V^T. The diagonal and superdiagonal of the matrix B are
    stored in the diagonal and superdiagonal of BUV. The orthogonal matrices
    U and V are stored as compressed Householder vectors in the remaining
    elements of BUV. The Householder coefficients are stored in the vectors
    tau_U and tau_V. The length of tau_U must equal the number of elements
    in the diagonal of A and the length of tau_V should be one element shorter.
    """
    n = min(A.shape)
    code = get_typecode(A)
    BUV = array_typed_copy(A, code)
    tau_U = zeros(n, code)
    tau_V = zeros(n-1, code)
    _gslwrap.gsl_linalg_bidiag_decomp(BUV, tau_U, tau_V)
    return (BUV, tau_U, tau_V)


def bidiag_unpack(A, tau_U, tau_V):
    """
    returns (U, V, diag, superdiag)
    
    This function unpacks the bidiagonal decomposition of A given by
    gsl.linalg.bidiag_decomp, (A, tau_U, tau_V) into the separate
    orthogonal matrices U, V and the diagonal vector diag and
    superdiagonal superdiag.
    """
    (m,n) = A.shape
    code = get_typecode(A)
    U = zeros([m,n], code)
    V = zeros([n,n], code)
    diag = zeros(n, code)
    superdiag = zeros(n-1, code)
    _gslwrap.gsl_linalg_bidiag_unpack(A, tau_U, U, tau_V, V, diag, superdiag)
    return (U, V, diag, superdiag)


def bidiag_unpack_B(A):
    """
    returns (diag, superdiag)
    
    This function unpacks the diagonal and superdiagonal of the bidiagonal
    decomposition of A given by gsl_linalg_bidiag_decomp, into the diagonal
    vector diag and superdiagonal vector superdiag.
    """
    raise NotImplementedError, "the GSL function for this is buggy!"    
    n = n = A.shape[1]
    code = get_typecode(A)
    diag = zeros(n, code)
    superdiag = zeros(n-1, code)
    _gslwrap.gsl_linalg_bidiag_unpack_B(A, diag, superdiag)
    return (diag, superdiag)


def bidiag_unpack_diag(diag, superdiag):
    """
    returns B

    This functions unpacks the bidiagonal matrix T of the diagonal
    and superdiagonal obtained from gsl_linalg_bidiag_unpack[_B]
    """
    n = diag.shape[0]
    B = numx.identity(n)*diag
    sub = numx.identity(n-1)*superdiag
    sub2 = numx.concatenate(
        (numx.concatenate((zeros([n-1,1]),sub), 1), zeros([1,n])))
    B = sub2 + B
    return B


#
# Householder solver for linear systems
#

def HH_solve(A,b):
    """
    returns x
    
    This function solves the system A x = b directly using Householder
    transformations. On output the solution is stored in x and b is not
    modified.
    """
    code = get_typecode(A)
    x = zeros(A.shape[1], code)
    An = array_typed_copy(A, code)
    _gslwrap.gsl_linalg_HH_solve(An, b, x)
    return x


#
# Tridiagonal Systems
#
 
def solve_tridiag(diag, e, f, b):
    """
    returns x

    This function solves the general N-by-N system A x = b where A is
    tridiagonal. The form of A for the 4-by-4 case is shown below,

    A = ( d_0 e_0         )
        ( f_0 d_1 e_1     )
        (     f_1 d_2 e_2 )
        (         f_2 d_3 )
    """
    x = zeros(diag.shape, get_typecode(diag))
    _gslwrap.gsl_linalg_solve_tridiag(diag, e, f, b, x)
    return x

def solve_symm_tridiag(diag, e, b):
    """
    returns x

    This function solves the general N-by-N system A x = b where A is
    symmetric tridiagonal. The form of A for the 4-by-4 case is shown below,

    A = ( d_0 e_0         )
        ( e_0 d_1 e_1     )
        (     e_1 d_2 e_2 )
        (         e_2 d_3 )
    """
    x = zeros(diag.shape, get_typecode(diag))
    _gslwrap.gsl_linalg_solve_symm_tridiag(diag, e, b, x)
    return x


def solve_symm_cyc_tridiag(diag, e, b):
    """
    returns x
    
    This function solves the general N-by-N system A x = b where A is
    symmetric cyclic tridiagonal. The form of A for the 4-by-4 case is
    shown below,

    A = ( d_0 e_0     e_3 )
        ( e_0 d_1 e_1     )
        (     e_1 d_2 e_2 )
        ( e_3     e_2 d_3 )
    """
    x = zeros(diag.shape, get_typecode(diag))
    _gslwrap.gsl_linalg_solve_symm_cyc_tridiag(diag, e, b, x)
    return x
    
