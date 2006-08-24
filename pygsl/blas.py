# Author : Fabian Jakobs
r"""
BLAS - Basic Linear Algebra Subprograms

GSL provides dense vector and matrix objects, based on the relevant built-in
types. The library provides an interface to the BLAS operations which apply to
these objects.

PyGSL only provides the functions working on "native" Python datatypes, i.e.
double and complex_double.

Functions with the postfix "_cr" are functions that support call by reference.
This is faster than the original version but may confuse real Python
programmers. Use this, if speed matters!!

Functions that are naturally done using functions of the underlying numerical
package are left out here.
"""

import _gslwrap
import pygsl._numobj as Numeric
import copy
from pygsl import array_typed_copy, get_typecode, Float, Complex
#
# constants
#

CblasRowMajor = _gslwrap.CblasRowMajor
CblasColMajor = _gslwrap.CblasColMajor
CblasNoTrans = _gslwrap.CblasNoTrans
CblasTrans = _gslwrap.CblasTrans
CblasConjTrans = _gslwrap.CblasConjTrans
CblasUpper = _gslwrap.CblasUpper
CblasLower = _gslwrap.CblasLower
CblasNonUnit = _gslwrap.CblasNonUnit
CblasUnit = _gslwrap.CblasUnit
CblasLeft = _gslwrap.CblasLeft
CblasRight = _gslwrap.CblasRight
gsl_blas_sdsdot = _gslwrap.gsl_blas_sdsdot

#
# Level 1
#

def ddot(x, y):
    """
    This function computes the scalar product \M{x^T y} for the vectors x and y,
    returning the result. 
    """
    return _gslwrap.gsl_blas_ddot(x, y)#[1]


def zdotu(x, y):
    """
    This function computes the complex scalar product \M{x^T y} for the
    vectors x and y, returning the result.
    """
    return _gslwrap.gsl_blas_zdotu(x, y, 1j)#[1]


def zdotc(x, y):
    """
    This function computes the complex conjugate scalar product \M{x^H y} for the
    vectors x and y, returning the result. 
    """
    return _gslwrap.gsl_blas_zdotc(x, y, 1j)#[1]


def dnrm2(x):
    """
    This function computes the Euclidean norm \M{||x||_2 = \sqrt {\sum x_i^2}}
    of the vector x. 
    """
    return _gslwrap.gsl_blas_dnrm2(x)


def dznrm2(x):
    """
    This function computes the Euclidean norm of the complex vector x,
    \M{||x||_2 = \sqrt {\sum (\Re(x_i)^2 + \Im(x_i)^2)}}.

    """
    return _gslwrap.gsl_blas_dznrm2(x)


def dasum(x):
    """
    This function computes the absolute sum \M{\sum |x_i|} of the elements
    of the vector x. 
    """
    return _gslwrap.gsl_blas_dasum(x)


def dzasum(x):
    """
    This function computes the absolute sum \M{\sum |\Re(x_i)| + |\Im(x_i)|}
    of the elements of the vector x. 
    """
    return _gslwrap.gsl_blas_dzasum(x)


def idamax(x):
    """
    This function returns the index of the largest element of the vector x.
    The largest element is determined by its absolute magnitude. If the
    largest value occurs several times then the index of the first occurrence
    is returned.
    """
    return _gslwrap.gsl_blas_idamax(x)


def izamax(x):
    """
    This function returns the index of the largest element of the vector x.
    The largest element is determined by the sum of the magnitudes of the
    real and imaginary parts \M{|\Re(x_i)| + |\Im(x_i)|}. If the largest value
    occurs several times then the index of the first occurrence is returned. 
    """
    return _gslwrap.gsl_blas_izamax(x)


def daxpy(alpha, x, y):
    """
    This function computes the sum \M{y = S{alpha} x + y} for the vectors x and y.
    """
    yn = array_typed_copy(y, Float)
    _gslwrap.gsl_blas_daxpy(alpha, x, yn)
    return yn


def daxpy_cr(alpha, x, y_CR):
    """
    This function computes the sum \M{y = S{alpha} x + y} for the vectors x and y.
    """
    _gslwrap.gsl_blas_daxpy(alpha, x, y_CR)
    

def zaxpy(alpha, x, y):
    """
    This function computes the sum \M{y = S{alpha} x + y} for the vectors x and y.
    """
    yn = array_typed_copy(y, Complex)
    _gslwrap.gsl_blas_zaxpy(alpha, x, yn)
    return yn


def zaxpy_cr(alpha, x, y_CR):
    """
    This function computes the sum \M{y = S{alpha} x + y} for the vectors x and y.
    """
    _gslwrap.gsl_blas_zaxpy(alpha, x, y_CR)
 

def drot(x, y, c, s):
    """
    This function applies a Givens rotation \M{(x', y') = (c x + s y, -s x + c y)}
    to the vectors x, y.
    """
    xn = array_typed_copy(x, Float)
    yn = array_typed_copy(y, Float)
    _gslwrap.gsl_blas_drot(xn, yn, c, s)
    return (xn, yn)


def drot_cr(x_CR, y_CR, c, s):
    """
    This function applies a Givens rotation \M{(x', y') = (c x + s y, -s x + c y)}
    to the vectors x, y.
    """
    _gslwrap.gsl_blas_drot(x_CR, y_CR, c, s)


#
# Level 2
#

def dgemv(alpha, a, x, beta, y, TransA=CblasNoTrans):
    """
    This function computes the matrix-vector product and
    sum \M{y = S{alpha} op(A) x + S{beta} y}, where op(A) = \M{A, A^T, A^H} for
    TransA = CblasNoTrans, CblasTrans, CblasConjTrans.
    """
    yn = array_typed_copy(y, Float)
    _gslwrap.gsl_blas_dgemv(TransA, alpha, a, x, beta, yn)
    return yn
    

def zgemv(alpha, a, x, beta, y, TransA=CblasNoTrans):
    """
    This function computes the matrix-vector product and
    sum \M{y = S{alpha} op(A) x + S{beta} y}, where \M{op(A) = A, A^T, A^H} for
    TransA = CblasNoTrans, CblasTrans, CblasConjTrans.
    """
    yn = array_typed_copy(y, Complex)
    _gslwrap.gsl_blas_zgemv(TransA, alpha, a, x, beta, yn)
    return yn


def dtrmv(A,
          x,
          Uplo=CblasLower,
          TransA=CblasNoTrans,
          Diag=CblasNonUnit):
    """
    returns x'
    
    This function computes the matrix-vector product and
    x' = op(A) x for the triangular
    matrix A, where op(A) = A, A^T, A^H for TransA = CblasNoTrans,
    CblasTrans, CblasConjTrans. When Uplo is CblasUpper then the upper
    triangle of A is used, and when Uplo is CblasLower then the lower
    triangle of A is used. If Diag is CblasNonUnit then the diagonal of
    the matrix is used, but if Diag is CblasUnit then the diagonal
    elements of the matrix A are taken as unity and are not referenced. 
    """
    xn = array_typed_copy(x, Float)

    _gslwrap.gsl_blas_dtrmv(Uplo, TransA, Diag, A, xn)
    return xn
    

def ztrmv(A,
          x,
          Uplo=CblasLower,
          TransA=CblasNoTrans,
          Diag=CblasNonUnit):
    """
    returns x'
    
    This function computes the matrix-vector product and
    x' = op(A) x for the triangular
    matrix A, where op(A) = A, A^T, A^H for TransA = CblasNoTrans,
    CblasTrans, CblasConjTrans. When Uplo is CblasUpper then the upper
    triangle of A is used, and when Uplo is CblasLower then the lower
    triangle of A is used. If Diag is CblasNonUnit then the diagonal of
    the matrix is used, but if Diag is CblasUnit then the diagonal
    elements of the matrix A are taken as unity and are not referenced. 
    """
    xn = array_typed_copy(x)
    _gslwrap.gsl_blas_ztrmv(Uplo, TransA, Diag, A, xn)
    return xn


def dtrsv(A,
          x,
          Uplo=CblasLower,
          TransA=CblasNoTrans,
          Diag=CblasNonUnit):
    """
    returns x'

    This function computes inv(op(A)) x for x, where op(A) = A, A^T, A^H
    for TransA = CblasNoTrans, CblasTrans, CblasConjTrans. When Uplo is
    CblasUpper then the upper triangle of A is used, and when Uplo is
    CblasLower then the lower triangle of A is used. If Diag is
    CblasNonUnit then the diagonal of the matrix is used, but if Diag
    is CblasUnit then the diagonal elements of the matrix A are taken
    as unity and are not referenced. 
    """
    xn = array_typed_copy(x)
    _gslwrap.gsl_blas_dtrsv(Uplo, TransA, Diag, A, xn)
    return xn
    

def ztrsv(A,
          x,
          Uplo=CblasLower,
          TransA=CblasNoTrans,
          Diag=CblasNonUnit):
    """
    returns x'

    This function computes inv(op(A)) x for x, where op(A) = A, A^T, A^H
    for TransA = CblasNoTrans, CblasTrans, CblasConjTrans. When Uplo is
    CblasUpper then the upper triangle of A is used, and when Uplo is
    CblasLower then the lower triangle of A is used. If Diag is
    CblasNonUnit then the diagonal of the matrix is used, but if Diag
    is CblasUnit then the diagonal elements of the matrix A are taken
    as unity and are not referenced. 
    """
    xn = array_typed_copy(x)
    _gslwrap.gsl_blas_ztrsv(Uplo, TransA, Diag, A, xn)
    return xn


def dsymv(alpha, A, X, beta, Y, Uplo=CblasLower):
    """
    returns y'

    This function computes the matrix-vector product and
    sum \M{y' = S{alpha} A x + S{beta} y} for the symmetric matrix A. Since the
    matrix A is symmetric only its upper half or lower half need to be
    stored. When Uplo is CblasUpper then the upper triangle and diagonal
    of A are used, and when Uplo is CblasLower then the lower triangle
    and diagonal of A are used. 
    """
    yn = array_typed_copy(Y, Float)
    _gslwrap.gsl_blas_dsymv(Uplo, alpha, A, X, beta, yn)
    return yn


def zhemv(alpha, A, X, beta, Y, Uplo=CblasLower):
    """
    returns y'
    
    This function computes the matrix-vector product and
    sum \M{y' = S{alpha} A x + S{beta} y} for the hermitian matrix A. Since the
    matrix A is hermitian only its upper half or lower half need to be
    stored. When Uplo is CblasUpper then the upper triangle and diagonal
    of A are used, and when Uplo is CblasLower then the lower triangle
    and diagonal of A are used. The imaginary elements of the diagonal
    are automatically assumed to be zero and are not referenced. 
    """
    yn = array_typed_copy(Y, get_typecode(A))
    _gslwrap.gsl_blas_zhemv(Uplo, alpha, A, X, beta, yn)
    return yn


def dger(alpha, X, Y, A):
    """
    returns A'

    This function computes the rank-1 update \M{A' = S{alpha} x y^T + A} of
    the matrix A. 
    """
    an = array_typed_copy(A)
    _gslwrap.gsl_blas_dger(alpha, X, Y, an)
    return an


def zgeru(alpha, X, Y, A):
    """
    returns A'

    This function computes the rank-1 update \M{A' = S{alpha} x y^T + A} of
    the matrix A. 
    """
    an = array_typed_copy(A)
    _gslwrap.gsl_blas_zgeru(alpha, X, Y, an)
    return an


def zgerc(alpha, X, Y, A):
    """
    returns A'

    This function computes the conjugate rank-1 update
    \M{A = S{alpha} x y^H + A} of the matrix A.
    """
    an = array_typed_copy(A)
    _gslwrap.gsl_blas_zgerc(alpha, X, Y, an)
    return an


def dsyr(alpha, X, A, Uplo=CblasLower):
    """
    returns A'

    This function computes the symmetric rank-1 update
    \M{A' = S{alpha} x x^T + A} of the symmetric matrix A. Since the matrix A
    is symmetric only its upper half or lower half need to be stored.
    When Uplo is CblasUpper then the upper triangle and diagonal of A
    are used, and when Uplo is CblasLower then the lower triangle and
    diagonal of A are used.
    """
    an = array_typed_copy(A)
    _gslwrap.gsl_blas_dsyr(Uplo, alpha, X, an)
    return an


def zher(alpha, X, A, Uplo=CblasLower):
    """
    returns A'

    This function computes the hermitian rank-1 update
    \M{A' = S{alpha} x x^H + A} of the hermitian matrix A. Since the matrix A
    is hermitian only its upper half or lower half need to be stored.
    When Uplo is CblasUpper then the upper triangle and diagonal of A are
    used, and when Uplo is CblasLower then the lower triangle and diagonal
    of A are used. The imaginary elements of the diagonal are automatically
    set to zero. 
    """
    an = array_typed_copy(A)        
    _gslwrap.gsl_blas_zher(Uplo, alpha, X, an)
    return an


def dsyr2(alpha, X, Y, A, Uplo=CblasLower):
    """
    returns A'

    This function computes the symmetric rank-2 update
    \M{A' = S{alpha} x y^T + S{alpha} y x^T + A} of the symmetric matrix A.
    Since the matrix A is symmetric only its upper half or lower half
    need to be stored. When Uplo is CblasUpper then the upper triangle
    and diagonal of A are used, and when Uplo is CblasLower then the
    lower triangle and diagonal of A are used. 
    """
    an = array_typed_copy(A)        
    _gslwrap.gsl_blas_dsyr2(Uplo, alpha, X, Y, an)
    return an


def zher2(alpha, X, Y, A, Uplo=CblasLower):
    """
    returns A'

    This function computes the hermitian rank-2 update
    \M{A' = S{alpha} x y^H + S{alpha}^* y x^H A} of the hermitian matrix A.
    Since the matrix A is hermitian only its upper half or lower half
    need to be stored. When Uplo is CblasUpper then the upper triangle
    and diagonal of A are used, and when Uplo is CblasLower then the
    lower triangle and diagonal of A are used. The imaginary elements
    of the diagonal are automatically set to zero. 
    """
    an = array_typed_copy(A)
    _gslwrap.gsl_blas_zher2(Uplo, alpha, X, Y, an)
    return an


#
# Level 3
#

def dgemm(alpha,
          A, B,
          beta, C,
          TransA=CblasNoTrans,
          TransB=CblasNoTrans):
    """
    returns C'
    
    This function computes the matrix-matrix product and sum
    \M{C' = S{alpha} op(A) op(B) + S{beta} C} where op(A) = A, A^T, A^H for
    TransA = CblasNoTrans, CblasTrans, CblasConjTrans and similarly
    for the parameter TransB.
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_dgemm(TransA, TransB, alpha, A, B, beta, cn)
    return cn


def zgemm(alpha,
          A, B,
          beta, C,
          TransA=CblasNoTrans,
          TransB=CblasNoTrans):
    """
    returns C'
    
    This function computes the matrix-matrix product and sum
    \M{C' = S{alpha} op(A) op(B) + S{beta} C} where op(A) = A, A^T, A^H for
    TransA = CblasNoTrans, CblasTrans, CblasConjTrans and similarly
    for the parameter TransB.
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_zgemm(TransA, TransB, alpha, A, B, beta, cn)
    return cn


def dsymm(alpha, A, B, beta, C,
          Side=CblasLeft,
          Uplo=CblasLower):
    """
    returns C'
    
    This function computes the matrix-matrix product and
    sum \M{C' = S{alpha} A B + S{beta} C} for Side is CblasLeft and
    \M{C' = S{alpha} B A + S{beta} C} for Side is CblasRight, where the matrix A
    is symmetric. When Uplo is CblasUpper then the upper triangle and
    diagonal of A are used, and when Uplo is CblasLower then the lower
    triangle and diagonal of A are used.
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_dsymm(Side, Uplo, alpha, A, B, beta, cn)
    return cn


def zsymm(alpha, A, B, beta, C,
          Side=CblasLeft,
          Uplo=CblasLower):
    """
    returns C'
    
    This function computes the matrix-matrix product and
    sum \M{C' = S{alpha} A B + S{beta} C} for Side is CblasLeft and
    \M{C' = S{alpha} B A + S{beta} C} for Side is CblasRight, where the matrix A
    is symmetric. When Uplo is CblasUpper then the upper triangle and
    diagonal of A are used, and when Uplo is CblasLower then the lower
    triangle and diagonal of A are used.
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_zsymm(Side, Uplo, alpha, A, B, beta, cn)
    return cn


def zhemm(alpha, A, B, beta, C,
          Side=CblasLeft,
          Uplo=CblasLower):
    """
    returns C'
    
    This function computes the matrix-matrix product and
    sum \M{C' = S{alpha} A B + S{beta} C} for Side is CblasLeft and
    \M{C' = S{alpha} B A + S{beta} C} for Side is CblasRight, where the matrix A
    is hermitian. When Uplo is CblasUpper then the upper triangle and
    diagonal of A are used, and when Uplo is CblasLower then the lower
    triangle and diagonal of A are used. The imaginary elements of the
    diagonal are automatically set to zero.
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_zhemm(Side, Uplo, alpha, A, B, beta, cn)
    return cn


def dtrmm(alpha, A, B,
          Side=CblasLeft,
          Uplo=CblasLower,
          TransA=CblasNoTrans,
          Diag=CblasNonUnit):
    """
    returns B'

    This function computes the matrix-matrix product
    \M{B' = S{alpha} op(A) B} for Side is CblasLeft and
    \M{B' = S{alpha} B op(A)} for Side is CblasRight. The matrix A is
    triangular and op(A) = A, A^T, A^H for TransA = CblasNoTrans,
    CblasTrans, CblasConjTrans When Uplo is CblasUpper then the upper
    triangle of A is used, and when Uplo is CblasLower then the lower
    triangle of A is used. If Diag is CblasNonUnit then the diagonal
    of A is used, but if Diag is CblasUnit then the diagonal elements
    of the matrix A are taken as unity and are not referenced.
    """
    bn = array_typed_copy(B)
    _gslwrap.gsl_blas_dtrmm(Side, Uplo, TransA, Diag, alpha, A, bn)
    return bn


def ztrmm(alpha, A, B,
          Side=CblasLeft,
          Uplo=CblasLower,
          TransA=CblasNoTrans,
          Diag=CblasNonUnit):
    """
    returns B'

    This function computes the matrix-matrix product
    \M{B' = S{alpha} op(A) B} for Side is CblasLeft and
    \M{B' = S{alpha} B op(A)} for Side is CblasRight. The matrix A is
    triangular and op(A) = A, A^T, A^H for TransA = CblasNoTrans,
    CblasTrans, CblasConjTrans When Uplo is CblasUpper then the upper
    triangle of A is used, and when Uplo is CblasLower then the lower
    triangle of A is used. If Diag is CblasNonUnit then the diagonal
    of A is used, but if Diag is CblasUnit then the diagonal elements
    of the matrix A are taken as unity and are not referenced.
    """
    bn = array_typed_copy(B)
    _gslwrap.gsl_blas_ztrmm(Side, Uplo, TransA, Diag, alpha, A, bn)
    return bn


def dtrsm(alpha, A, B,
          Side=CblasLeft,
          Uplo=CblasLower,
          TransA=CblasNoTrans,
          Diag=CblasNonUnit):
    """
    returns B'
    
    This function computes the matrix-matrix product
    \M{B' = S{alpha} op(inv(A)) B} for Side is CblasLeft and
    \M{B' = S{alpha} B op(inv(A))} for Side is CblasRight. The matrix A is
    triangular and op(A) = A, A^T, A^H for TransA = CblasNoTrans,
    CblasTrans, CblasConjTrans When Uplo is CblasUpper then the upper
    triangle of A is used, and when Uplo is CblasLower then the lower
    triangle of A is used. If Diag is CblasNonUnit then the diagonal
    of A is used, but if Diag is CblasUnit then the diagonal elements
    of the matrix A are taken as unity and are not referenced.
    """
    bn = array_typed_copy(B)
    _gslwrap.gsl_blas_dtrsm(Side, Uplo, TransA, Diag, alpha, A, bn)
    return bn


def ztrsm(alpha, A, B,
         Side=CblasLeft,
         Uplo=CblasLower,
         TransA=CblasNoTrans,
         Diag=CblasNonUnit):
    """
    returns B'
    
    This function computes the matrix-matrix product
    \M{B' = S{alpha} op(inv(A)) B} for Side is CblasLeft and
   \M{ B' = S{alpha} B op(inv(A))} for Side is CblasRight. The matrix A is
    triangular and op(A) = A, A^T, A^H for TransA = CblasNoTrans,
    CblasTrans, CblasConjTrans When Uplo is CblasUpper then the upper
    triangle of A is used, and when Uplo is CblasLower then the lower
    triangle of A is used. If Diag is CblasNonUnit then the diagonal
    of A is used, but if Diag is CblasUnit then the diagonal elements
    of the matrix A are taken as unity and are not referenced.
    """
    bn = array_typed_copy(B)
    _gslwrap.gsl_blas_ztrsm(Side, Uplo, TransA, Diag, alpha, A, bn)
    return bn


def dsyrk(alpha, A, beta, C,
         Uplo=CblasLower,
         Trans=CblasNoTrans):
    """
    returns C'
    
    This function computes a rank-k update of the symmetric matrix C,
    \M{C' = S{alpha} A A^T + S{beta} C} when Trans is CblasNoTrans and
    \M{C' = S{alpha} A^T A + S{beta} C} when Trans is CblasTrans. Since the matrix
    C is symmetric only its upper half or lower half need to be stored.
    When Uplo is CblasUpper then the upper triangle and diagonal of C are
    used, and when Uplo is CblasLower then the lower triangle and diagonal
    of C are used.
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_dsyrk(Uplo, Trans, alpha, A, beta, cn)
    return cn


def zsyrk(alpha, A, beta, C,
         Uplo=CblasLower,
         Trans=CblasNoTrans):
    """
    returns C'
    
    This function computes a rank-k update of the symmetric matrix C,
    \M{C' = S{alpha} A A^T + S{beta} C} when Trans is CblasNoTrans and
    \M{C' = S{alpha} A^T A + S{beta} C} when Trans is CblasTrans. Since the matrix
    C is symmetric only its upper half or lower half need to be stored.
    When Uplo is CblasUpper then the upper triangle and diagonal of C are
    used, and when Uplo is CblasLower then the lower triangle and diagonal
    of C are used.
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_zsyrk(Uplo, Trans, alpha, A, beta, cn)
    return cn


def triang2symm(A,
             Uplo=CblasLower,
             Diag=CblasNonUnit):
    """
    returns A'

    This function creates an symmetric matrix from a triangular matrix.
    When Uplo is CblasUpper then the upper triangle and diagonal of A
    are used, and when Uplo is CblasLower then the lower triangle and
    diagonal of A are used. If Diag is CblasNonUnit then the diagonal
    of A is used, but if Diag is CblasUnit then the diagonal elements
    of the matrix A are taken as unity and are not referenced.
    """
    an = array_typed_copy(A)
    if Uplo == CblasLower:
        for i in range(A.shape[0]):
            an[:i+1,i] =  A[i,:i+1]
    else:
        for i in range(A.shape[0]):
            an[i:,i] = A[i,i:]
    if Diag == CblasUnit:
        for i in range(an.shape[0]):
            an[i,i] = 1
    return an


def triang2herm(A,
             Uplo=CblasLower,
             Diag=CblasNonUnit):
    """
    returns A'

    This function creates an hermitian matrix from a triangular matrix.
    When Uplo is CblasUpper then the upper triangle and diagonal of A
    are used, and when Uplo is CblasLower then the lower triangle and
    diagonal of A are used. If Diag is CblasNonUnit then the diagonal
    of A is used, but if Diag is CblasUnit then the diagonal elements
    of the matrix A are taken as unity and are not referenced.
    """
    an = array_typed_copy(A)
    if Uplo == CblasLower:
        for i in range(A.shape[0]):
            an[:i+1,i] = Numeric.conjugate(A[i,:i+1])
    else:
        for i in range(A.shape[0]):
            an[i:,i] = Numeric.conjugate(A[i,i:])
    if Diag == CblasUnit:
        for i in range(an.shape[0]):
            an[i,i] = 1
    return an


def zherk(alpha, A, beta, C,
          Uplo=CblasLower,
          Trans=CblasNoTrans):          
    """
    returns C'
    
    This function computes a rank-k update of the hermitian matrix C,
    \M{C' = S{alpha} A A^H + S{beta} C} when Trans is CblasNoTrans and
    \M{C' = S{alpha} A^H A + S{beta} C} when Trans is CblasTrans. Since
    the matrix C is hermitian only its upper half or lower half need to
    be stored. When Uplo is CblasUpper then the upper triangle and diagonal
    of C are used, and when Uplo is CblasLower then the lower triangle and
    diagonal of C are used. The imaginary elements of the diagonal are
    automatically set to zero.
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_zherk(Uplo, Trans, alpha, A, beta, cn)
    return cn


def dsyr2k(alpha, A, B, beta, C,
          Uplo=CblasLower,
          Trans=CblasNoTrans):                     
    """
    returns C'
    
    This function computes a rank-2k update of the symmetric
    matrix C, \M{C' = S{alpha} A B^T + S{alpha} B A^T + S{beta} C} when Trans
    is CblasNoTrans and \M{C' = S{alpha} A^T B + S{alpha} B^T A + S{beta} C} when
    Trans is CblasTrans. Since the matrix C is symmetric only its upper
    half or lower half need to be stored. When Uplo is CblasUpper then
    the upper triangle and diagonal of C are used, and when Uplo is
    CblasLower then the lower triangle and diagonal of C are used.
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_dsyr2k(Uplo, Trans, alpha, A, B, beta, cn)
    return cn


def zsyr2k(alpha, A, B, beta, C,
          Uplo=CblasLower,
          Trans=CblasNoTrans):                     
    """
    returns C'
    
    This function computes a rank-2k update of the symmetric
    matrix C, \M{C' = S{alpha} A B^T + S{alpha} B A^T + S{beta} C} when Trans
    is CblasNoTrans and \M{C' = S{alpha} A^T B + S{alpha} B^T A + S{beta} C} when
    Trans is CblasTrans. Since the matrix C is symmetric only its upper
    half or lower half need to be stored. When Uplo is CblasUpper then
    the upper triangle and diagonal of C are used, and when Uplo is
    CblasLower then the lower triangle and diagonal of C are used.
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_zsyr2k(Uplo, Trans, alpha, A, B, beta, cn)
    return cn


def zher2k(alpha, A, B, beta, C,
          Uplo=CblasLower,
          Trans=CblasNoTrans):                     
    """
    returns C'
    
    This function computes a rank-2k update of the hermitian matrix C,
    \M{C' = S{alpha} A B^H + S{alpha}^* B A^H + S{beta} C} when Trans is
    CblasNoTrans and \M{C' = S{alpha} A^H B + S{alpha}^* B^H A + S{beta} C} when
    Trans is CblasTrans. Since the matrix C is hermitian only its upper
    half or lower half need to be stored. When Uplo is CblasUpper then
    the upper triangle and diagonal of C are used, and when Uplo is
    CblasLower then the lower triangle and diagonal of C are used.
    The imaginary elements of the diagonal are automatically set to zero. 
    """
    cn = array_typed_copy(C)
    _gslwrap.gsl_blas_zher2k(Uplo, Trans, alpha, A, B, beta, cn)
    return cn
