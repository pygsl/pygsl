# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _gslwrap

def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name) or (name == "thisown"):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types


GSL_LINALG_MOD_NONE = _gslwrap.GSL_LINALG_MOD_NONE
GSL_LINALG_MOD_TRANSPOSE = _gslwrap.GSL_LINALG_MOD_TRANSPOSE
GSL_LINALG_MOD_CONJUGATE = _gslwrap.GSL_LINALG_MOD_CONJUGATE

gsl_linalg_matmult = _gslwrap.gsl_linalg_matmult

gsl_linalg_matmult_mod = _gslwrap.gsl_linalg_matmult_mod

gsl_linalg_exponential_ss = _gslwrap.gsl_linalg_exponential_ss

gsl_linalg_householder_transform = _gslwrap.gsl_linalg_householder_transform

gsl_linalg_complex_householder_transform = _gslwrap.gsl_linalg_complex_householder_transform

gsl_linalg_householder_hm = _gslwrap.gsl_linalg_householder_hm

gsl_linalg_householder_mh = _gslwrap.gsl_linalg_householder_mh

gsl_linalg_householder_hv = _gslwrap.gsl_linalg_householder_hv

gsl_linalg_householder_hm1 = _gslwrap.gsl_linalg_householder_hm1

gsl_linalg_complex_householder_hm = _gslwrap.gsl_linalg_complex_householder_hm

gsl_linalg_complex_householder_hv = _gslwrap.gsl_linalg_complex_householder_hv

gsl_linalg_SV_decomp = _gslwrap.gsl_linalg_SV_decomp

gsl_linalg_SV_decomp_mod = _gslwrap.gsl_linalg_SV_decomp_mod

gsl_linalg_SV_decomp_jacobi = _gslwrap.gsl_linalg_SV_decomp_jacobi

gsl_linalg_SV_solve = _gslwrap.gsl_linalg_SV_solve

gsl_linalg_LU_decomp = _gslwrap.gsl_linalg_LU_decomp

gsl_linalg_LU_solve = _gslwrap.gsl_linalg_LU_solve

gsl_linalg_LU_svx = _gslwrap.gsl_linalg_LU_svx

gsl_linalg_LU_refine = _gslwrap.gsl_linalg_LU_refine

gsl_linalg_LU_invert = _gslwrap.gsl_linalg_LU_invert

gsl_linalg_LU_det = _gslwrap.gsl_linalg_LU_det

gsl_linalg_LU_lndet = _gslwrap.gsl_linalg_LU_lndet

gsl_linalg_LU_sgndet = _gslwrap.gsl_linalg_LU_sgndet

gsl_linalg_complex_LU_decomp = _gslwrap.gsl_linalg_complex_LU_decomp

gsl_linalg_complex_LU_solve = _gslwrap.gsl_linalg_complex_LU_solve

gsl_linalg_complex_LU_svx = _gslwrap.gsl_linalg_complex_LU_svx

gsl_linalg_complex_LU_refine = _gslwrap.gsl_linalg_complex_LU_refine

gsl_linalg_complex_LU_invert = _gslwrap.gsl_linalg_complex_LU_invert

gsl_linalg_complex_LU_det = _gslwrap.gsl_linalg_complex_LU_det

gsl_linalg_complex_LU_lndet = _gslwrap.gsl_linalg_complex_LU_lndet

gsl_linalg_complex_LU_sgndet = _gslwrap.gsl_linalg_complex_LU_sgndet

gsl_linalg_QR_decomp = _gslwrap.gsl_linalg_QR_decomp

gsl_linalg_QR_solve = _gslwrap.gsl_linalg_QR_solve

gsl_linalg_QR_svx = _gslwrap.gsl_linalg_QR_svx

gsl_linalg_QR_lssolve = _gslwrap.gsl_linalg_QR_lssolve

gsl_linalg_QR_QRsolve = _gslwrap.gsl_linalg_QR_QRsolve

gsl_linalg_QR_Rsolve = _gslwrap.gsl_linalg_QR_Rsolve

gsl_linalg_QR_Rsvx = _gslwrap.gsl_linalg_QR_Rsvx

gsl_linalg_QR_update = _gslwrap.gsl_linalg_QR_update

gsl_linalg_QR_QTvec = _gslwrap.gsl_linalg_QR_QTvec

gsl_linalg_QR_Qvec = _gslwrap.gsl_linalg_QR_Qvec

gsl_linalg_QR_unpack = _gslwrap.gsl_linalg_QR_unpack

gsl_linalg_R_solve = _gslwrap.gsl_linalg_R_solve

gsl_linalg_QRPT_decomp = _gslwrap.gsl_linalg_QRPT_decomp

gsl_linalg_QRPT_decomp2 = _gslwrap.gsl_linalg_QRPT_decomp2

gsl_linalg_QRPT_solve = _gslwrap.gsl_linalg_QRPT_solve

gsl_linalg_QRPT_svx = _gslwrap.gsl_linalg_QRPT_svx

gsl_linalg_QRPT_QRsolve = _gslwrap.gsl_linalg_QRPT_QRsolve

gsl_linalg_QRPT_Rsolve = _gslwrap.gsl_linalg_QRPT_Rsolve

gsl_linalg_QRPT_Rsvx = _gslwrap.gsl_linalg_QRPT_Rsvx

gsl_linalg_QRPT_update = _gslwrap.gsl_linalg_QRPT_update

gsl_linalg_cholesky_decomp = _gslwrap.gsl_linalg_cholesky_decomp

gsl_linalg_cholesky_solve = _gslwrap.gsl_linalg_cholesky_solve

gsl_linalg_cholesky_svx = _gslwrap.gsl_linalg_cholesky_svx

gsl_linalg_symmtd_decomp = _gslwrap.gsl_linalg_symmtd_decomp

gsl_linalg_symmtd_unpack = _gslwrap.gsl_linalg_symmtd_unpack

gsl_linalg_symmtd_unpack_T = _gslwrap.gsl_linalg_symmtd_unpack_T

gsl_linalg_hermtd_decomp = _gslwrap.gsl_linalg_hermtd_decomp

gsl_linalg_hermtd_unpack = _gslwrap.gsl_linalg_hermtd_unpack

gsl_linalg_hermtd_unpack_T = _gslwrap.gsl_linalg_hermtd_unpack_T

gsl_linalg_HH_solve = _gslwrap.gsl_linalg_HH_solve

gsl_linalg_HH_svx = _gslwrap.gsl_linalg_HH_svx

gsl_linalg_solve_symm_tridiag = _gslwrap.gsl_linalg_solve_symm_tridiag

gsl_linalg_solve_tridiag = _gslwrap.gsl_linalg_solve_tridiag

gsl_linalg_solve_symm_cyc_tridiag = _gslwrap.gsl_linalg_solve_symm_cyc_tridiag

gsl_linalg_solve_cyc_tridiag = _gslwrap.gsl_linalg_solve_cyc_tridiag

gsl_linalg_bidiag_decomp = _gslwrap.gsl_linalg_bidiag_decomp

gsl_linalg_bidiag_unpack = _gslwrap.gsl_linalg_bidiag_unpack

gsl_linalg_bidiag_unpack2 = _gslwrap.gsl_linalg_bidiag_unpack2

gsl_linalg_bidiag_unpack_B = _gslwrap.gsl_linalg_bidiag_unpack_B

gsl_linalg_balance_columns = _gslwrap.gsl_linalg_balance_columns
class Permutation(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Permutation, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Permutation, name)
    def __repr__(self):
        return "<%s.%s; proxy of C gsl_permutation_struct instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    __swig_getmethods__["size"] = _gslwrap.Permutation_size_get
    if _newclass:size = property(_gslwrap.Permutation_size_get)
    __swig_getmethods__["data"] = _gslwrap.Permutation_data_get
    if _newclass:data = property(_gslwrap.Permutation_data_get)
    def __init__(self, *args, **kwargs):
        _swig_setattr(self, Permutation, 'this', _gslwrap.new_Permutation(*args, **kwargs))
        _swig_setattr(self, Permutation, 'thisown', 1)
    def __del__(self, destroy=_gslwrap.delete_Permutation):
        try:
            if self.thisown: destroy(self)
        except: pass

    def _linear_to_canonical(*args, **kwargs): return _gslwrap.Permutation__linear_to_canonical(*args, **kwargs)
    def _canonical_to_linear(*args, **kwargs): return _gslwrap.Permutation__canonical_to_linear(*args, **kwargs)
    def _mul(*args, **kwargs): return _gslwrap.Permutation__mul(*args, **kwargs)
    def inversions(*args, **kwargs): return _gslwrap.Permutation_inversions(*args, **kwargs)
    def linear_cycles(*args, **kwargs): return _gslwrap.Permutation_linear_cycles(*args, **kwargs)
    def canonical_cycles(*args, **kwargs): return _gslwrap.Permutation_canonical_cycles(*args, **kwargs)
    def _inverse(*args, **kwargs): return _gslwrap.Permutation__inverse(*args, **kwargs)
    def __getitem__(*args, **kwargs): return _gslwrap.Permutation___getitem__(*args, **kwargs)
    def swap(*args, **kwargs): return _gslwrap.Permutation_swap(*args, **kwargs)
    def __len__(*args, **kwargs): return _gslwrap.Permutation___len__(*args, **kwargs)
    def valid(*args, **kwargs): return _gslwrap.Permutation_valid(*args, **kwargs)
    def reverse(*args, **kwargs): return _gslwrap.Permutation_reverse(*args, **kwargs)
    def next(*args, **kwargs): return _gslwrap.Permutation_next(*args, **kwargs)
    def prev(*args, **kwargs): return _gslwrap.Permutation_prev(*args, **kwargs)
    def __str__(*args, **kwargs): return _gslwrap.Permutation___str__(*args, **kwargs)
    def tolist(*args, **kwargs): return _gslwrap.Permutation_tolist(*args, **kwargs)
    def toarray(*args, **kwargs): return _gslwrap.Permutation_toarray(*args, **kwargs)

class PermutationPtr(Permutation):
    def __init__(self, this):
        _swig_setattr(self, Permutation, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Permutation, 'thisown', 0)
        _swig_setattr(self, Permutation,self.__class__,Permutation)
_gslwrap.Permutation_swigregister(PermutationPtr)


gsl_permutation_alloc = _gslwrap.gsl_permutation_alloc

gsl_permutation_calloc = _gslwrap.gsl_permutation_calloc

gsl_permutation_init = _gslwrap.gsl_permutation_init

gsl_permutation_free = _gslwrap.gsl_permutation_free

gsl_permutation_memcpy = _gslwrap.gsl_permutation_memcpy

gsl_permutation_fread = _gslwrap.gsl_permutation_fread

gsl_permutation_fwrite = _gslwrap.gsl_permutation_fwrite

gsl_permutation_fscanf = _gslwrap.gsl_permutation_fscanf

gsl_permutation_fprintf = _gslwrap.gsl_permutation_fprintf

gsl_permutation_size = _gslwrap.gsl_permutation_size

gsl_permutation_data = _gslwrap.gsl_permutation_data

gsl_permutation_get = _gslwrap.gsl_permutation_get

gsl_permutation_swap = _gslwrap.gsl_permutation_swap

gsl_permutation_valid = _gslwrap.gsl_permutation_valid

gsl_permutation_reverse = _gslwrap.gsl_permutation_reverse

gsl_permutation_inverse = _gslwrap.gsl_permutation_inverse

gsl_permutation_next = _gslwrap.gsl_permutation_next

gsl_permutation_prev = _gslwrap.gsl_permutation_prev

gsl_permutation_mul = _gslwrap.gsl_permutation_mul

gsl_permutation_linear_to_canonical = _gslwrap.gsl_permutation_linear_to_canonical

gsl_permutation_canonical_to_linear = _gslwrap.gsl_permutation_canonical_to_linear

gsl_permutation_inversions = _gslwrap.gsl_permutation_inversions

gsl_permutation_linear_cycles = _gslwrap.gsl_permutation_linear_cycles

gsl_permutation_canonical_cycles = _gslwrap.gsl_permutation_canonical_cycles
class Combination(_object):
    """Proxy of C Combination struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Combination, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Combination, name)
    def __repr__(self):
        return "<%s.%s; proxy of C gsl_combination_struct instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args, **kwargs):
        """bla blamore blah blah"""
        _swig_setattr(self, Combination, 'this', _gslwrap.new_Combination(*args, **kwargs))
        _swig_setattr(self, Combination, 'thisown', 1)
    def __del__(self, destroy=_gslwrap.delete_Combination):
        """__del__(self)"""
        try:
            if self.thisown: destroy(self)
        except: pass

    def __getitem__(*args, **kwargs): 
        """__getitem__(self, size_t i) -> size_t"""
        return _gslwrap.Combination___getitem__(*args, **kwargs)

    def k(*args, **kwargs): 
        """k(self) -> size_t"""
        return _gslwrap.Combination_k(*args, **kwargs)

    def n(*args, **kwargs): 
        """n(self) -> size_t"""
        return _gslwrap.Combination_n(*args, **kwargs)

    def init_first(*args, **kwargs): 
        """init_first(self)"""
        return _gslwrap.Combination_init_first(*args, **kwargs)

    def init_last(*args, **kwargs): 
        """init_last(self)"""
        return _gslwrap.Combination_init_last(*args, **kwargs)

    def valid(*args, **kwargs): 
        """valid(self) -> int"""
        return _gslwrap.Combination_valid(*args, **kwargs)

    def next(*args, **kwargs): 
        """next(self) -> int"""
        return _gslwrap.Combination_next(*args, **kwargs)

    def prev(*args, **kwargs): 
        """prev(self) -> int"""
        return _gslwrap.Combination_prev(*args, **kwargs)

    def tolist(*args, **kwargs): 
        """tolist(self) -> PyObject"""
        return _gslwrap.Combination_tolist(*args, **kwargs)

    def toarray(*args, **kwargs): 
        """toarray(self) -> PyObject"""
        return _gslwrap.Combination_toarray(*args, **kwargs)


class CombinationPtr(Combination):
    def __init__(self, this):
        _swig_setattr(self, Combination, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Combination, 'thisown', 0)
        _swig_setattr(self, Combination,self.__class__,Combination)
_gslwrap.Combination_swigregister(CombinationPtr)

M_E = _gslwrap.M_E
M_LOG2E = _gslwrap.M_LOG2E
M_LOG10E = _gslwrap.M_LOG10E
M_SQRT2 = _gslwrap.M_SQRT2
M_SQRT1_2 = _gslwrap.M_SQRT1_2
M_SQRT3 = _gslwrap.M_SQRT3
M_PI = _gslwrap.M_PI
M_PI_2 = _gslwrap.M_PI_2
M_PI_4 = _gslwrap.M_PI_4
M_SQRTPI = _gslwrap.M_SQRTPI
M_2_SQRTPI = _gslwrap.M_2_SQRTPI
M_1_PI = _gslwrap.M_1_PI
M_2_PI = _gslwrap.M_2_PI
M_LN10 = _gslwrap.M_LN10
M_LN2 = _gslwrap.M_LN2
M_LNPI = _gslwrap.M_LNPI
M_EULER = _gslwrap.M_EULER

def gsl_max(*args, **kwargs):
    """gsl_max(double a, double b) -> double"""
    return _gslwrap.gsl_max(*args, **kwargs)

def gsl_min(*args, **kwargs):
    """gsl_min(double a, double b) -> double"""
    return _gslwrap.gsl_min(*args, **kwargs)
GSL_POSZERO = _gslwrap.GSL_POSZERO
GSL_NEGZERO = _gslwrap.GSL_NEGZERO

def gsl_log1p(*args, **kwargs):
    """gsl_log1p(double x) -> double"""
    return _gslwrap.gsl_log1p(*args, **kwargs)

def gsl_expm1(*args, **kwargs):
    """gsl_expm1(double x) -> double"""
    return _gslwrap.gsl_expm1(*args, **kwargs)

def gsl_hypot(*args, **kwargs):
    """gsl_hypot(double x, double y) -> double"""
    return _gslwrap.gsl_hypot(*args, **kwargs)

def gsl_acosh(*args, **kwargs):
    """gsl_acosh(double x) -> double"""
    return _gslwrap.gsl_acosh(*args, **kwargs)

def gsl_asinh(*args, **kwargs):
    """gsl_asinh(double x) -> double"""
    return _gslwrap.gsl_asinh(*args, **kwargs)

def gsl_atanh(*args, **kwargs):
    """gsl_atanh(double x) -> double"""
    return _gslwrap.gsl_atanh(*args, **kwargs)

def gsl_isnan(*args, **kwargs):
    """gsl_isnan(double x) -> int"""
    return _gslwrap.gsl_isnan(*args, **kwargs)

def gsl_isinf(*args, **kwargs):
    """gsl_isinf(double x) -> int"""
    return _gslwrap.gsl_isinf(*args, **kwargs)

def gsl_finite(*args, **kwargs):
    """gsl_finite(double x) -> int"""
    return _gslwrap.gsl_finite(*args, **kwargs)

def gsl_nan(*args, **kwargs):
    """gsl_nan() -> double"""
    return _gslwrap.gsl_nan(*args, **kwargs)

def gsl_posinf(*args, **kwargs):
    """gsl_posinf() -> double"""
    return _gslwrap.gsl_posinf(*args, **kwargs)

def gsl_neginf(*args, **kwargs):
    """gsl_neginf() -> double"""
    return _gslwrap.gsl_neginf(*args, **kwargs)

def gsl_fdiv(*args, **kwargs):
    """gsl_fdiv(double x, double y) -> double"""
    return _gslwrap.gsl_fdiv(*args, **kwargs)

def gsl_coerce_double(*args, **kwargs):
    """gsl_coerce_double(double x) -> double"""
    return _gslwrap.gsl_coerce_double(*args, **kwargs)

def gsl_coerce_float(*args, **kwargs):
    """gsl_coerce_float(float x) -> float"""
    return _gslwrap.gsl_coerce_float(*args, **kwargs)

def gsl_coerce_long_double(*args, **kwargs):
    """gsl_coerce_long_double(long double x) -> long double"""
    return _gslwrap.gsl_coerce_long_double(*args, **kwargs)

def gsl_ldexp(*args, **kwargs):
    """gsl_ldexp(double x, int e) -> double"""
    return _gslwrap.gsl_ldexp(*args, **kwargs)

def gsl_frexp(*args, **kwargs):
    """gsl_frexp(double x, int e) -> double"""
    return _gslwrap.gsl_frexp(*args, **kwargs)

def gsl_fcmp(*args, **kwargs):
    """gsl_fcmp(double x1, double x2, double epsilon) -> int"""
    return _gslwrap.gsl_fcmp(*args, **kwargs)
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

def gsl_blas_sdsdot(*args, **kwargs):
    """
    gsl_blas_sdsdot(float alpha, gsl_vector_float X, gsl_vector_float Y, 
        float result) -> int
    """
    return _gslwrap.gsl_blas_sdsdot(*args, **kwargs)

def gsl_blas_dsdot(*args, **kwargs):
    """gsl_blas_dsdot(gsl_vector_float X, gsl_vector_float Y, double result) -> int"""
    return _gslwrap.gsl_blas_dsdot(*args, **kwargs)

def gsl_blas_sdot(*args, **kwargs):
    """gsl_blas_sdot(gsl_vector_float X, gsl_vector_float Y, float result) -> int"""
    return _gslwrap.gsl_blas_sdot(*args, **kwargs)

def gsl_blas_ddot(*args, **kwargs):
    """gsl_blas_ddot(gsl_vector X, gsl_vector Y, double result) -> int"""
    return _gslwrap.gsl_blas_ddot(*args, **kwargs)

def gsl_blas_cdotu(*args, **kwargs):
    """
    gsl_blas_cdotu(gsl_vector_complex_float X, gsl_vector_complex_float Y, 
        gsl_complex_float dotu) -> int
    """
    return _gslwrap.gsl_blas_cdotu(*args, **kwargs)

def gsl_blas_cdotc(*args, **kwargs):
    """
    gsl_blas_cdotc(gsl_vector_complex_float X, gsl_vector_complex_float Y, 
        gsl_complex_float dotc) -> int
    """
    return _gslwrap.gsl_blas_cdotc(*args, **kwargs)

def gsl_blas_zdotu(*args, **kwargs):
    """gsl_blas_zdotu(gsl_vector_complex X, gsl_vector_complex Y, gsl_complex dotu) -> int"""
    return _gslwrap.gsl_blas_zdotu(*args, **kwargs)

def gsl_blas_zdotc(*args, **kwargs):
    """gsl_blas_zdotc(gsl_vector_complex X, gsl_vector_complex Y, gsl_complex dotc) -> int"""
    return _gslwrap.gsl_blas_zdotc(*args, **kwargs)

def gsl_blas_snrm2(*args, **kwargs):
    """gsl_blas_snrm2(gsl_vector_float X) -> float"""
    return _gslwrap.gsl_blas_snrm2(*args, **kwargs)

def gsl_blas_sasum(*args, **kwargs):
    """gsl_blas_sasum(gsl_vector_float X) -> float"""
    return _gslwrap.gsl_blas_sasum(*args, **kwargs)

def gsl_blas_dnrm2(*args, **kwargs):
    """gsl_blas_dnrm2(gsl_vector X) -> double"""
    return _gslwrap.gsl_blas_dnrm2(*args, **kwargs)

def gsl_blas_dasum(*args, **kwargs):
    """gsl_blas_dasum(gsl_vector X) -> double"""
    return _gslwrap.gsl_blas_dasum(*args, **kwargs)

def gsl_blas_scnrm2(*args, **kwargs):
    """gsl_blas_scnrm2(gsl_vector_complex_float X) -> float"""
    return _gslwrap.gsl_blas_scnrm2(*args, **kwargs)

def gsl_blas_scasum(*args, **kwargs):
    """gsl_blas_scasum(gsl_vector_complex_float X) -> float"""
    return _gslwrap.gsl_blas_scasum(*args, **kwargs)

def gsl_blas_dznrm2(*args, **kwargs):
    """gsl_blas_dznrm2(gsl_vector_complex X) -> double"""
    return _gslwrap.gsl_blas_dznrm2(*args, **kwargs)

def gsl_blas_dzasum(*args, **kwargs):
    """gsl_blas_dzasum(gsl_vector_complex X) -> double"""
    return _gslwrap.gsl_blas_dzasum(*args, **kwargs)

def gsl_blas_isamax(*args, **kwargs):
    """gsl_blas_isamax(gsl_vector_float X) -> CBLAS_INDEX_t"""
    return _gslwrap.gsl_blas_isamax(*args, **kwargs)

def gsl_blas_idamax(*args, **kwargs):
    """gsl_blas_idamax(gsl_vector X) -> CBLAS_INDEX_t"""
    return _gslwrap.gsl_blas_idamax(*args, **kwargs)

def gsl_blas_icamax(*args, **kwargs):
    """gsl_blas_icamax(gsl_vector_complex_float X) -> CBLAS_INDEX_t"""
    return _gslwrap.gsl_blas_icamax(*args, **kwargs)

def gsl_blas_izamax(*args, **kwargs):
    """gsl_blas_izamax(gsl_vector_complex X) -> CBLAS_INDEX_t"""
    return _gslwrap.gsl_blas_izamax(*args, **kwargs)

def gsl_blas_sswap(*args, **kwargs):
    """gsl_blas_sswap(gsl_vector_float X, gsl_vector_float Y) -> int"""
    return _gslwrap.gsl_blas_sswap(*args, **kwargs)

def gsl_blas_scopy(*args, **kwargs):
    """gsl_blas_scopy(gsl_vector_float X, gsl_vector_float Y) -> int"""
    return _gslwrap.gsl_blas_scopy(*args, **kwargs)

def gsl_blas_saxpy(*args, **kwargs):
    """gsl_blas_saxpy(float alpha, gsl_vector_float X, gsl_vector_float Y) -> int"""
    return _gslwrap.gsl_blas_saxpy(*args, **kwargs)

def gsl_blas_dswap(*args, **kwargs):
    """gsl_blas_dswap(gsl_vector X, gsl_vector Y) -> int"""
    return _gslwrap.gsl_blas_dswap(*args, **kwargs)

def gsl_blas_dcopy(*args, **kwargs):
    """gsl_blas_dcopy(gsl_vector X, gsl_vector Y) -> int"""
    return _gslwrap.gsl_blas_dcopy(*args, **kwargs)

def gsl_blas_daxpy(*args, **kwargs):
    """gsl_blas_daxpy(double alpha, gsl_vector X, gsl_vector Y) -> int"""
    return _gslwrap.gsl_blas_daxpy(*args, **kwargs)

def gsl_blas_cswap(*args, **kwargs):
    """gsl_blas_cswap(gsl_vector_complex_float X, gsl_vector_complex_float Y) -> int"""
    return _gslwrap.gsl_blas_cswap(*args, **kwargs)

def gsl_blas_ccopy(*args, **kwargs):
    """gsl_blas_ccopy(gsl_vector_complex_float X, gsl_vector_complex_float Y) -> int"""
    return _gslwrap.gsl_blas_ccopy(*args, **kwargs)

def gsl_blas_caxpy(*args, **kwargs):
    """
    gsl_blas_caxpy(gsl_complex_float alpha, gsl_vector_complex_float X, 
        gsl_vector_complex_float Y) -> int
    """
    return _gslwrap.gsl_blas_caxpy(*args, **kwargs)

def gsl_blas_zswap(*args, **kwargs):
    """gsl_blas_zswap(gsl_vector_complex X, gsl_vector_complex Y) -> int"""
    return _gslwrap.gsl_blas_zswap(*args, **kwargs)

def gsl_blas_zcopy(*args, **kwargs):
    """gsl_blas_zcopy(gsl_vector_complex X, gsl_vector_complex Y) -> int"""
    return _gslwrap.gsl_blas_zcopy(*args, **kwargs)

def gsl_blas_zaxpy(*args, **kwargs):
    """gsl_blas_zaxpy(gsl_complex alpha, gsl_vector_complex X, gsl_vector_complex Y) -> int"""
    return _gslwrap.gsl_blas_zaxpy(*args, **kwargs)

def gsl_blas_srotg(*args, **kwargs):
    """gsl_blas_srotg(float a, float b, float c, float s) -> int"""
    return _gslwrap.gsl_blas_srotg(*args, **kwargs)

def gsl_blas_srotmg(*args, **kwargs):
    """gsl_blas_srotmg(float d1, float d2, float b1, float b2, float P) -> int"""
    return _gslwrap.gsl_blas_srotmg(*args, **kwargs)

def gsl_blas_srot(*args, **kwargs):
    """gsl_blas_srot(gsl_vector_float X, gsl_vector_float Y, float c, float s) -> int"""
    return _gslwrap.gsl_blas_srot(*args, **kwargs)

def gsl_blas_srotm(*args, **kwargs):
    """gsl_blas_srotm(gsl_vector_float X, gsl_vector_float Y, float P) -> int"""
    return _gslwrap.gsl_blas_srotm(*args, **kwargs)

def gsl_blas_drotg(*args, **kwargs):
    """gsl_blas_drotg(double a, double b, double c, double s) -> int"""
    return _gslwrap.gsl_blas_drotg(*args, **kwargs)

def gsl_blas_drotmg(*args, **kwargs):
    """gsl_blas_drotmg(double d1, double d2, double b1, double b2, double P) -> int"""
    return _gslwrap.gsl_blas_drotmg(*args, **kwargs)

def gsl_blas_drot(*args, **kwargs):
    """gsl_blas_drot(gsl_vector X, gsl_vector Y, double c, double s) -> int"""
    return _gslwrap.gsl_blas_drot(*args, **kwargs)

def gsl_blas_drotm(*args, **kwargs):
    """gsl_blas_drotm(gsl_vector X, gsl_vector Y, double P) -> int"""
    return _gslwrap.gsl_blas_drotm(*args, **kwargs)

def gsl_blas_sscal(*args, **kwargs):
    """gsl_blas_sscal(float alpha, gsl_vector_float X)"""
    return _gslwrap.gsl_blas_sscal(*args, **kwargs)

def gsl_blas_dscal(*args, **kwargs):
    """gsl_blas_dscal(double alpha, gsl_vector X)"""
    return _gslwrap.gsl_blas_dscal(*args, **kwargs)

def gsl_blas_cscal(*args, **kwargs):
    """gsl_blas_cscal(gsl_complex_float alpha, gsl_vector_complex_float X)"""
    return _gslwrap.gsl_blas_cscal(*args, **kwargs)

def gsl_blas_zscal(*args, **kwargs):
    """gsl_blas_zscal(gsl_complex alpha, gsl_vector_complex X)"""
    return _gslwrap.gsl_blas_zscal(*args, **kwargs)

def gsl_blas_csscal(*args, **kwargs):
    """gsl_blas_csscal(float alpha, gsl_vector_complex_float X)"""
    return _gslwrap.gsl_blas_csscal(*args, **kwargs)

def gsl_blas_zdscal(*args, **kwargs):
    """gsl_blas_zdscal(double alpha, gsl_vector_complex X)"""
    return _gslwrap.gsl_blas_zdscal(*args, **kwargs)

def gsl_blas_sgemv(*args, **kwargs):
    """
    gsl_blas_sgemv(CBLAS_TRANSPOSE_t TransA, float alpha, gsl_matrix_float A, 
        gsl_vector_float X, float beta, gsl_vector_float Y) -> int
    """
    return _gslwrap.gsl_blas_sgemv(*args, **kwargs)

def gsl_blas_strmv(*args, **kwargs):
    """
    gsl_blas_strmv(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, 
        gsl_matrix_float A, gsl_vector_float X) -> int
    """
    return _gslwrap.gsl_blas_strmv(*args, **kwargs)

def gsl_blas_strsv(*args, **kwargs):
    """
    gsl_blas_strsv(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, 
        gsl_matrix_float A, gsl_vector_float X) -> int
    """
    return _gslwrap.gsl_blas_strsv(*args, **kwargs)

def gsl_blas_dgemv(*args, **kwargs):
    """
    gsl_blas_dgemv(CBLAS_TRANSPOSE_t TransA, double alpha, gsl_matrix A, 
        gsl_vector X, double beta, gsl_vector Y) -> int
    """
    return _gslwrap.gsl_blas_dgemv(*args, **kwargs)

def gsl_blas_dtrmv(*args, **kwargs):
    """
    gsl_blas_dtrmv(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, 
        gsl_matrix A, gsl_vector X) -> int
    """
    return _gslwrap.gsl_blas_dtrmv(*args, **kwargs)

def gsl_blas_dtrsv(*args, **kwargs):
    """
    gsl_blas_dtrsv(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, 
        gsl_matrix A, gsl_vector X) -> int
    """
    return _gslwrap.gsl_blas_dtrsv(*args, **kwargs)

def gsl_blas_cgemv(*args, **kwargs):
    """
    gsl_blas_cgemv(CBLAS_TRANSPOSE_t TransA, gsl_complex_float alpha, 
        gsl_matrix_complex_float A, gsl_vector_complex_float X, 
        gsl_complex_float beta, gsl_vector_complex_float Y) -> int
    """
    return _gslwrap.gsl_blas_cgemv(*args, **kwargs)

def gsl_blas_ctrmv(*args, **kwargs):
    """
    gsl_blas_ctrmv(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, 
        gsl_matrix_complex_float A, gsl_vector_complex_float X) -> int
    """
    return _gslwrap.gsl_blas_ctrmv(*args, **kwargs)

def gsl_blas_ctrsv(*args, **kwargs):
    """
    gsl_blas_ctrsv(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, 
        gsl_matrix_complex_float A, gsl_vector_complex_float X) -> int
    """
    return _gslwrap.gsl_blas_ctrsv(*args, **kwargs)

def gsl_blas_zgemv(*args, **kwargs):
    """
    gsl_blas_zgemv(CBLAS_TRANSPOSE_t TransA, gsl_complex alpha, gsl_matrix_complex A, 
        gsl_vector_complex X, gsl_complex beta, 
        gsl_vector_complex Y) -> int
    """
    return _gslwrap.gsl_blas_zgemv(*args, **kwargs)

def gsl_blas_ztrmv(*args, **kwargs):
    """
    gsl_blas_ztrmv(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, 
        gsl_matrix_complex A, gsl_vector_complex X) -> int
    """
    return _gslwrap.gsl_blas_ztrmv(*args, **kwargs)

def gsl_blas_ztrsv(*args, **kwargs):
    """
    gsl_blas_ztrsv(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, 
        gsl_matrix_complex A, gsl_vector_complex X) -> int
    """
    return _gslwrap.gsl_blas_ztrsv(*args, **kwargs)

def gsl_blas_ssymv(*args, **kwargs):
    """
    gsl_blas_ssymv(CBLAS_UPLO_t Uplo, float alpha, gsl_matrix_float A, 
        gsl_vector_float X, float beta, gsl_vector_float Y) -> int
    """
    return _gslwrap.gsl_blas_ssymv(*args, **kwargs)

def gsl_blas_sger(*args, **kwargs):
    """
    gsl_blas_sger(float alpha, gsl_vector_float X, gsl_vector_float Y, 
        gsl_matrix_float A) -> int
    """
    return _gslwrap.gsl_blas_sger(*args, **kwargs)

def gsl_blas_ssyr(*args, **kwargs):
    """
    gsl_blas_ssyr(CBLAS_UPLO_t Uplo, float alpha, gsl_vector_float X, 
        gsl_matrix_float A) -> int
    """
    return _gslwrap.gsl_blas_ssyr(*args, **kwargs)

def gsl_blas_ssyr2(*args, **kwargs):
    """
    gsl_blas_ssyr2(CBLAS_UPLO_t Uplo, float alpha, gsl_vector_float X, 
        gsl_vector_float Y, gsl_matrix_float A) -> int
    """
    return _gslwrap.gsl_blas_ssyr2(*args, **kwargs)

def gsl_blas_dsymv(*args, **kwargs):
    """
    gsl_blas_dsymv(CBLAS_UPLO_t Uplo, double alpha, gsl_matrix A, gsl_vector X, 
        double beta, gsl_vector Y) -> int
    """
    return _gslwrap.gsl_blas_dsymv(*args, **kwargs)

def gsl_blas_dger(*args, **kwargs):
    """gsl_blas_dger(double alpha, gsl_vector X, gsl_vector Y, gsl_matrix A) -> int"""
    return _gslwrap.gsl_blas_dger(*args, **kwargs)

def gsl_blas_dsyr(*args, **kwargs):
    """gsl_blas_dsyr(CBLAS_UPLO_t Uplo, double alpha, gsl_vector X, gsl_matrix A) -> int"""
    return _gslwrap.gsl_blas_dsyr(*args, **kwargs)

def gsl_blas_dsyr2(*args, **kwargs):
    """
    gsl_blas_dsyr2(CBLAS_UPLO_t Uplo, double alpha, gsl_vector X, gsl_vector Y, 
        gsl_matrix A) -> int
    """
    return _gslwrap.gsl_blas_dsyr2(*args, **kwargs)

def gsl_blas_chemv(*args, **kwargs):
    """
    gsl_blas_chemv(CBLAS_UPLO_t Uplo, gsl_complex_float alpha, gsl_matrix_complex_float A, 
        gsl_vector_complex_float X, 
        gsl_complex_float beta, gsl_vector_complex_float Y) -> int
    """
    return _gslwrap.gsl_blas_chemv(*args, **kwargs)

def gsl_blas_cgeru(*args, **kwargs):
    """
    gsl_blas_cgeru(gsl_complex_float alpha, gsl_vector_complex_float X, 
        gsl_vector_complex_float Y, gsl_matrix_complex_float A) -> int
    """
    return _gslwrap.gsl_blas_cgeru(*args, **kwargs)

def gsl_blas_cgerc(*args, **kwargs):
    """
    gsl_blas_cgerc(gsl_complex_float alpha, gsl_vector_complex_float X, 
        gsl_vector_complex_float Y, gsl_matrix_complex_float A) -> int
    """
    return _gslwrap.gsl_blas_cgerc(*args, **kwargs)

def gsl_blas_cher(*args, **kwargs):
    """
    gsl_blas_cher(CBLAS_UPLO_t Uplo, float alpha, gsl_vector_complex_float X, 
        gsl_matrix_complex_float A) -> int
    """
    return _gslwrap.gsl_blas_cher(*args, **kwargs)

def gsl_blas_cher2(*args, **kwargs):
    """
    gsl_blas_cher2(CBLAS_UPLO_t Uplo, gsl_complex_float alpha, gsl_vector_complex_float X, 
        gsl_vector_complex_float Y, 
        gsl_matrix_complex_float A) -> int
    """
    return _gslwrap.gsl_blas_cher2(*args, **kwargs)

def gsl_blas_zhemv(*args, **kwargs):
    """
    gsl_blas_zhemv(CBLAS_UPLO_t Uplo, gsl_complex alpha, gsl_matrix_complex A, 
        gsl_vector_complex X, gsl_complex beta, 
        gsl_vector_complex Y) -> int
    """
    return _gslwrap.gsl_blas_zhemv(*args, **kwargs)

def gsl_blas_zgeru(*args, **kwargs):
    """
    gsl_blas_zgeru(gsl_complex alpha, gsl_vector_complex X, gsl_vector_complex Y, 
        gsl_matrix_complex A) -> int
    """
    return _gslwrap.gsl_blas_zgeru(*args, **kwargs)

def gsl_blas_zgerc(*args, **kwargs):
    """
    gsl_blas_zgerc(gsl_complex alpha, gsl_vector_complex X, gsl_vector_complex Y, 
        gsl_matrix_complex A) -> int
    """
    return _gslwrap.gsl_blas_zgerc(*args, **kwargs)

def gsl_blas_zher(*args, **kwargs):
    """
    gsl_blas_zher(CBLAS_UPLO_t Uplo, double alpha, gsl_vector_complex X, 
        gsl_matrix_complex A) -> int
    """
    return _gslwrap.gsl_blas_zher(*args, **kwargs)

def gsl_blas_zher2(*args, **kwargs):
    """
    gsl_blas_zher2(CBLAS_UPLO_t Uplo, gsl_complex alpha, gsl_vector_complex X, 
        gsl_vector_complex Y, gsl_matrix_complex A) -> int
    """
    return _gslwrap.gsl_blas_zher2(*args, **kwargs)

def gsl_blas_sgemm(*args, **kwargs):
    """
    gsl_blas_sgemm(CBLAS_TRANSPOSE_t TransA, CBLAS_TRANSPOSE_t TransB, 
        float alpha, gsl_matrix_float A, gsl_matrix_float B, 
        float beta, gsl_matrix_float C) -> int
    """
    return _gslwrap.gsl_blas_sgemm(*args, **kwargs)

def gsl_blas_ssymm(*args, **kwargs):
    """
    gsl_blas_ssymm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, float alpha, 
        gsl_matrix_float A, gsl_matrix_float B, float beta, 
        gsl_matrix_float C) -> int
    """
    return _gslwrap.gsl_blas_ssymm(*args, **kwargs)

def gsl_blas_ssyrk(*args, **kwargs):
    """
    gsl_blas_ssyrk(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, float alpha, 
        gsl_matrix_float A, float beta, gsl_matrix_float C) -> int
    """
    return _gslwrap.gsl_blas_ssyrk(*args, **kwargs)

def gsl_blas_ssyr2k(*args, **kwargs):
    """
    gsl_blas_ssyr2k(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, float alpha, 
        gsl_matrix_float A, gsl_matrix_float B, 
        float beta, gsl_matrix_float C) -> int
    """
    return _gslwrap.gsl_blas_ssyr2k(*args, **kwargs)

def gsl_blas_strmm(*args, **kwargs):
    """
    gsl_blas_strmm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, 
        CBLAS_DIAG_t Diag, float alpha, 
        gsl_matrix_float A, gsl_matrix_float B) -> int
    """
    return _gslwrap.gsl_blas_strmm(*args, **kwargs)

def gsl_blas_strsm(*args, **kwargs):
    """
    gsl_blas_strsm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, 
        CBLAS_DIAG_t Diag, float alpha, 
        gsl_matrix_float A, gsl_matrix_float B) -> int
    """
    return _gslwrap.gsl_blas_strsm(*args, **kwargs)

def gsl_blas_dgemm(*args, **kwargs):
    """
    gsl_blas_dgemm(CBLAS_TRANSPOSE_t TransA, CBLAS_TRANSPOSE_t TransB, 
        double alpha, gsl_matrix A, gsl_matrix B, double beta, 
        gsl_matrix C) -> int
    """
    return _gslwrap.gsl_blas_dgemm(*args, **kwargs)

def gsl_blas_dsymm(*args, **kwargs):
    """
    gsl_blas_dsymm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, double alpha, 
        gsl_matrix A, gsl_matrix B, double beta, gsl_matrix C) -> int
    """
    return _gslwrap.gsl_blas_dsymm(*args, **kwargs)

def gsl_blas_dsyrk(*args, **kwargs):
    """
    gsl_blas_dsyrk(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, double alpha, 
        gsl_matrix A, double beta, gsl_matrix C) -> int
    """
    return _gslwrap.gsl_blas_dsyrk(*args, **kwargs)

def gsl_blas_dsyr2k(*args, **kwargs):
    """
    gsl_blas_dsyr2k(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, double alpha, 
        gsl_matrix A, gsl_matrix B, double beta, 
        gsl_matrix C) -> int
    """
    return _gslwrap.gsl_blas_dsyr2k(*args, **kwargs)

def gsl_blas_dtrmm(*args, **kwargs):
    """
    gsl_blas_dtrmm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, 
        CBLAS_DIAG_t Diag, double alpha, 
        gsl_matrix A, gsl_matrix B) -> int
    """
    return _gslwrap.gsl_blas_dtrmm(*args, **kwargs)

def gsl_blas_dtrsm(*args, **kwargs):
    """
    gsl_blas_dtrsm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, 
        CBLAS_DIAG_t Diag, double alpha, 
        gsl_matrix A, gsl_matrix B) -> int
    """
    return _gslwrap.gsl_blas_dtrsm(*args, **kwargs)

def gsl_blas_cgemm(*args, **kwargs):
    """
    gsl_blas_cgemm(CBLAS_TRANSPOSE_t TransA, CBLAS_TRANSPOSE_t TransB, 
        gsl_complex_float alpha, gsl_matrix_complex_float A, 
        gsl_matrix_complex_float B, gsl_complex_float beta, 
        gsl_matrix_complex_float C) -> int
    """
    return _gslwrap.gsl_blas_cgemm(*args, **kwargs)

def gsl_blas_csymm(*args, **kwargs):
    """
    gsl_blas_csymm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, gsl_complex_float alpha, 
        gsl_matrix_complex_float A, gsl_matrix_complex_float B, 
        gsl_complex_float beta, 
        gsl_matrix_complex_float C) -> int
    """
    return _gslwrap.gsl_blas_csymm(*args, **kwargs)

def gsl_blas_csyrk(*args, **kwargs):
    """
    gsl_blas_csyrk(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, gsl_complex_float alpha, 
        gsl_matrix_complex_float A, 
        gsl_complex_float beta, gsl_matrix_complex_float C) -> int
    """
    return _gslwrap.gsl_blas_csyrk(*args, **kwargs)

def gsl_blas_csyr2k(*args, **kwargs):
    """
    gsl_blas_csyr2k(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, gsl_complex_float alpha, 
        gsl_matrix_complex_float A, 
        gsl_matrix_complex_float B, gsl_complex_float beta, 
        gsl_matrix_complex_float C) -> int
    """
    return _gslwrap.gsl_blas_csyr2k(*args, **kwargs)

def gsl_blas_ctrmm(*args, **kwargs):
    """
    gsl_blas_ctrmm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, 
        CBLAS_DIAG_t Diag, gsl_complex_float alpha, 
        gsl_matrix_complex_float A, gsl_matrix_complex_float B) -> int
    """
    return _gslwrap.gsl_blas_ctrmm(*args, **kwargs)

def gsl_blas_ctrsm(*args, **kwargs):
    """
    gsl_blas_ctrsm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, 
        CBLAS_DIAG_t Diag, gsl_complex_float alpha, 
        gsl_matrix_complex_float A, gsl_matrix_complex_float B) -> int
    """
    return _gslwrap.gsl_blas_ctrsm(*args, **kwargs)

def gsl_blas_zgemm(*args, **kwargs):
    """
    gsl_blas_zgemm(CBLAS_TRANSPOSE_t TransA, CBLAS_TRANSPOSE_t TransB, 
        gsl_complex alpha, gsl_matrix_complex A, gsl_matrix_complex B, 
        gsl_complex beta, gsl_matrix_complex C) -> int
    """
    return _gslwrap.gsl_blas_zgemm(*args, **kwargs)

def gsl_blas_zsymm(*args, **kwargs):
    """
    gsl_blas_zsymm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, gsl_complex alpha, 
        gsl_matrix_complex A, gsl_matrix_complex B, 
        gsl_complex beta, gsl_matrix_complex C) -> int
    """
    return _gslwrap.gsl_blas_zsymm(*args, **kwargs)

def gsl_blas_zsyrk(*args, **kwargs):
    """
    gsl_blas_zsyrk(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, gsl_complex alpha, 
        gsl_matrix_complex A, gsl_complex beta, 
        gsl_matrix_complex C) -> int
    """
    return _gslwrap.gsl_blas_zsyrk(*args, **kwargs)

def gsl_blas_zsyr2k(*args, **kwargs):
    """
    gsl_blas_zsyr2k(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, gsl_complex alpha, 
        gsl_matrix_complex A, gsl_matrix_complex B, 
        gsl_complex beta, gsl_matrix_complex C) -> int
    """
    return _gslwrap.gsl_blas_zsyr2k(*args, **kwargs)

def gsl_blas_ztrmm(*args, **kwargs):
    """
    gsl_blas_ztrmm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, 
        CBLAS_DIAG_t Diag, gsl_complex alpha, 
        gsl_matrix_complex A, gsl_matrix_complex B) -> int
    """
    return _gslwrap.gsl_blas_ztrmm(*args, **kwargs)

def gsl_blas_ztrsm(*args, **kwargs):
    """
    gsl_blas_ztrsm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, 
        CBLAS_DIAG_t Diag, gsl_complex alpha, 
        gsl_matrix_complex A, gsl_matrix_complex B) -> int
    """
    return _gslwrap.gsl_blas_ztrsm(*args, **kwargs)

def gsl_blas_chemm(*args, **kwargs):
    """
    gsl_blas_chemm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, gsl_complex_float alpha, 
        gsl_matrix_complex_float A, gsl_matrix_complex_float B, 
        gsl_complex_float beta, 
        gsl_matrix_complex_float C) -> int
    """
    return _gslwrap.gsl_blas_chemm(*args, **kwargs)

def gsl_blas_cherk(*args, **kwargs):
    """
    gsl_blas_cherk(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, float alpha, 
        gsl_matrix_complex_float A, float beta, 
        gsl_matrix_complex_float C) -> int
    """
    return _gslwrap.gsl_blas_cherk(*args, **kwargs)

def gsl_blas_cher2k(*args, **kwargs):
    """
    gsl_blas_cher2k(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, gsl_complex_float alpha, 
        gsl_matrix_complex_float A, 
        gsl_matrix_complex_float B, float beta, gsl_matrix_complex_float C) -> int
    """
    return _gslwrap.gsl_blas_cher2k(*args, **kwargs)

def gsl_blas_zhemm(*args, **kwargs):
    """
    gsl_blas_zhemm(CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, gsl_complex alpha, 
        gsl_matrix_complex A, gsl_matrix_complex B, 
        gsl_complex beta, gsl_matrix_complex C) -> int
    """
    return _gslwrap.gsl_blas_zhemm(*args, **kwargs)

def gsl_blas_zherk(*args, **kwargs):
    """
    gsl_blas_zherk(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, double alpha, 
        gsl_matrix_complex A, double beta, gsl_matrix_complex C) -> int
    """
    return _gslwrap.gsl_blas_zherk(*args, **kwargs)

def gsl_blas_zher2k(*args, **kwargs):
    """
    gsl_blas_zher2k(CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, gsl_complex alpha, 
        gsl_matrix_complex A, gsl_matrix_complex B, 
        double beta, gsl_matrix_complex C) -> int
    """
    return _gslwrap.gsl_blas_zher2k(*args, **kwargs)
class gsl_eigen_symm_workspace(_object):
    """Proxy of C gsl_eigen_symm_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_symm_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_symm_workspace, name)
    def __repr__(self):
        return "<%s.%s; proxy of C gsl_eigen_symm_workspace instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args, **kwargs):
        """__init__(self, size_t n) -> gsl_eigen_symm_workspace"""
        _swig_setattr(self, gsl_eigen_symm_workspace, 'this', _gslwrap.new_gsl_eigen_symm_workspace(*args, **kwargs))
        _swig_setattr(self, gsl_eigen_symm_workspace, 'thisown', 1)
    def __del__(self, destroy=_gslwrap.delete_gsl_eigen_symm_workspace):
        """__del__(self)"""
        try:
            if self.thisown: destroy(self)
        except: pass

    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_symm_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_symm_workspace_size_get)
    __swig_getmethods__["d"] = _gslwrap.gsl_eigen_symm_workspace_d_get
    if _newclass:d = property(_gslwrap.gsl_eigen_symm_workspace_d_get)
    __swig_getmethods__["sd"] = _gslwrap.gsl_eigen_symm_workspace_sd_get
    if _newclass:sd = property(_gslwrap.gsl_eigen_symm_workspace_sd_get)

class gsl_eigen_symm_workspacePtr(gsl_eigen_symm_workspace):
    def __init__(self, this):
        _swig_setattr(self, gsl_eigen_symm_workspace, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, gsl_eigen_symm_workspace, 'thisown', 0)
        _swig_setattr(self, gsl_eigen_symm_workspace,self.__class__,gsl_eigen_symm_workspace)
_gslwrap.gsl_eigen_symm_workspace_swigregister(gsl_eigen_symm_workspacePtr)


def gsl_eigen_symm_alloc(*args, **kwargs):
    """gsl_eigen_symm_alloc(size_t n) -> gsl_eigen_symm_workspace"""
    return _gslwrap.gsl_eigen_symm_alloc(*args, **kwargs)

def gsl_eigen_symm_free(*args, **kwargs):
    """gsl_eigen_symm_free(gsl_eigen_symm_workspace w)"""
    return _gslwrap.gsl_eigen_symm_free(*args, **kwargs)

def gsl_eigen_symm(*args, **kwargs):
    """gsl_eigen_symm(gsl_matrix A, gsl_vector eval, gsl_eigen_symm_workspace w) -> int"""
    return _gslwrap.gsl_eigen_symm(*args, **kwargs)
class gsl_eigen_symmv_workspace(_object):
    """Proxy of C gsl_eigen_symmv_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_symmv_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_symmv_workspace, name)
    def __repr__(self):
        return "<%s.%s; proxy of C gsl_eigen_symmv_workspace instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args, **kwargs):
        """__init__(self, size_t n) -> gsl_eigen_symmv_workspace"""
        _swig_setattr(self, gsl_eigen_symmv_workspace, 'this', _gslwrap.new_gsl_eigen_symmv_workspace(*args, **kwargs))
        _swig_setattr(self, gsl_eigen_symmv_workspace, 'thisown', 1)
    def __del__(self, destroy=_gslwrap.delete_gsl_eigen_symmv_workspace):
        """__del__(self)"""
        try:
            if self.thisown: destroy(self)
        except: pass

    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_symmv_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_symmv_workspace_size_get)
    __swig_getmethods__["d"] = _gslwrap.gsl_eigen_symmv_workspace_d_get
    if _newclass:d = property(_gslwrap.gsl_eigen_symmv_workspace_d_get)
    __swig_getmethods__["sd"] = _gslwrap.gsl_eigen_symmv_workspace_sd_get
    if _newclass:sd = property(_gslwrap.gsl_eigen_symmv_workspace_sd_get)
    __swig_getmethods__["gc"] = _gslwrap.gsl_eigen_symmv_workspace_gc_get
    if _newclass:gc = property(_gslwrap.gsl_eigen_symmv_workspace_gc_get)
    __swig_getmethods__["gs"] = _gslwrap.gsl_eigen_symmv_workspace_gs_get
    if _newclass:gs = property(_gslwrap.gsl_eigen_symmv_workspace_gs_get)

class gsl_eigen_symmv_workspacePtr(gsl_eigen_symmv_workspace):
    def __init__(self, this):
        _swig_setattr(self, gsl_eigen_symmv_workspace, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, gsl_eigen_symmv_workspace, 'thisown', 0)
        _swig_setattr(self, gsl_eigen_symmv_workspace,self.__class__,gsl_eigen_symmv_workspace)
_gslwrap.gsl_eigen_symmv_workspace_swigregister(gsl_eigen_symmv_workspacePtr)


def gsl_eigen_symmv_alloc(*args, **kwargs):
    """gsl_eigen_symmv_alloc(size_t n) -> gsl_eigen_symmv_workspace"""
    return _gslwrap.gsl_eigen_symmv_alloc(*args, **kwargs)

def gsl_eigen_symmv_free(*args, **kwargs):
    """gsl_eigen_symmv_free(gsl_eigen_symmv_workspace w)"""
    return _gslwrap.gsl_eigen_symmv_free(*args, **kwargs)

def gsl_eigen_symmv(*args, **kwargs):
    """gsl_eigen_symmv(gsl_matrix A, gsl_vector eval, gsl_matrix evec, gsl_eigen_symmv_workspace w) -> int"""
    return _gslwrap.gsl_eigen_symmv(*args, **kwargs)
class gsl_eigen_herm_workspace(_object):
    """Proxy of C gsl_eigen_herm_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_herm_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_herm_workspace, name)
    def __repr__(self):
        return "<%s.%s; proxy of C gsl_eigen_herm_workspace instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args, **kwargs):
        """__init__(self, size_t n) -> gsl_eigen_herm_workspace"""
        _swig_setattr(self, gsl_eigen_herm_workspace, 'this', _gslwrap.new_gsl_eigen_herm_workspace(*args, **kwargs))
        _swig_setattr(self, gsl_eigen_herm_workspace, 'thisown', 1)
    def __del__(self, destroy=_gslwrap.delete_gsl_eigen_herm_workspace):
        """__del__(self)"""
        try:
            if self.thisown: destroy(self)
        except: pass

    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_herm_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_herm_workspace_size_get)
    __swig_getmethods__["d"] = _gslwrap.gsl_eigen_herm_workspace_d_get
    if _newclass:d = property(_gslwrap.gsl_eigen_herm_workspace_d_get)
    __swig_getmethods__["sd"] = _gslwrap.gsl_eigen_herm_workspace_sd_get
    if _newclass:sd = property(_gslwrap.gsl_eigen_herm_workspace_sd_get)
    __swig_getmethods__["tau"] = _gslwrap.gsl_eigen_herm_workspace_tau_get
    if _newclass:tau = property(_gslwrap.gsl_eigen_herm_workspace_tau_get)

class gsl_eigen_herm_workspacePtr(gsl_eigen_herm_workspace):
    def __init__(self, this):
        _swig_setattr(self, gsl_eigen_herm_workspace, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, gsl_eigen_herm_workspace, 'thisown', 0)
        _swig_setattr(self, gsl_eigen_herm_workspace,self.__class__,gsl_eigen_herm_workspace)
_gslwrap.gsl_eigen_herm_workspace_swigregister(gsl_eigen_herm_workspacePtr)


def gsl_eigen_herm_alloc(*args, **kwargs):
    """gsl_eigen_herm_alloc(size_t n) -> gsl_eigen_herm_workspace"""
    return _gslwrap.gsl_eigen_herm_alloc(*args, **kwargs)

def gsl_eigen_herm_free(*args, **kwargs):
    """gsl_eigen_herm_free(gsl_eigen_herm_workspace w)"""
    return _gslwrap.gsl_eigen_herm_free(*args, **kwargs)

def gsl_eigen_herm(*args, **kwargs):
    """gsl_eigen_herm(gsl_matrix_complex A, gsl_vector eval, gsl_eigen_herm_workspace w) -> int"""
    return _gslwrap.gsl_eigen_herm(*args, **kwargs)
class gsl_eigen_hermv_workspace(_object):
    """Proxy of C gsl_eigen_hermv_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_hermv_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_hermv_workspace, name)
    def __repr__(self):
        return "<%s.%s; proxy of C gsl_eigen_hermv_workspace instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args, **kwargs):
        """__init__(self, size_t n) -> gsl_eigen_hermv_workspace"""
        _swig_setattr(self, gsl_eigen_hermv_workspace, 'this', _gslwrap.new_gsl_eigen_hermv_workspace(*args, **kwargs))
        _swig_setattr(self, gsl_eigen_hermv_workspace, 'thisown', 1)
    def __del__(self, destroy=_gslwrap.delete_gsl_eigen_hermv_workspace):
        """__del__(self)"""
        try:
            if self.thisown: destroy(self)
        except: pass

    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_hermv_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_hermv_workspace_size_get)
    __swig_getmethods__["d"] = _gslwrap.gsl_eigen_hermv_workspace_d_get
    if _newclass:d = property(_gslwrap.gsl_eigen_hermv_workspace_d_get)
    __swig_getmethods__["sd"] = _gslwrap.gsl_eigen_hermv_workspace_sd_get
    if _newclass:sd = property(_gslwrap.gsl_eigen_hermv_workspace_sd_get)
    __swig_getmethods__["tau"] = _gslwrap.gsl_eigen_hermv_workspace_tau_get
    if _newclass:tau = property(_gslwrap.gsl_eigen_hermv_workspace_tau_get)
    __swig_getmethods__["gc"] = _gslwrap.gsl_eigen_hermv_workspace_gc_get
    if _newclass:gc = property(_gslwrap.gsl_eigen_hermv_workspace_gc_get)
    __swig_getmethods__["gs"] = _gslwrap.gsl_eigen_hermv_workspace_gs_get
    if _newclass:gs = property(_gslwrap.gsl_eigen_hermv_workspace_gs_get)

class gsl_eigen_hermv_workspacePtr(gsl_eigen_hermv_workspace):
    def __init__(self, this):
        _swig_setattr(self, gsl_eigen_hermv_workspace, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, gsl_eigen_hermv_workspace, 'thisown', 0)
        _swig_setattr(self, gsl_eigen_hermv_workspace,self.__class__,gsl_eigen_hermv_workspace)
_gslwrap.gsl_eigen_hermv_workspace_swigregister(gsl_eigen_hermv_workspacePtr)


def gsl_eigen_hermv_alloc(*args, **kwargs):
    """gsl_eigen_hermv_alloc(size_t n) -> gsl_eigen_hermv_workspace"""
    return _gslwrap.gsl_eigen_hermv_alloc(*args, **kwargs)

def gsl_eigen_hermv_free(*args, **kwargs):
    """gsl_eigen_hermv_free(gsl_eigen_hermv_workspace w)"""
    return _gslwrap.gsl_eigen_hermv_free(*args, **kwargs)

def gsl_eigen_hermv(*args, **kwargs):
    """
    gsl_eigen_hermv(gsl_matrix_complex A, gsl_vector eval, gsl_matrix_complex evec, 
        gsl_eigen_hermv_workspace w) -> int
    """
    return _gslwrap.gsl_eigen_hermv(*args, **kwargs)
GSL_EIGEN_SORT_VAL_ASC = _gslwrap.GSL_EIGEN_SORT_VAL_ASC
GSL_EIGEN_SORT_VAL_DESC = _gslwrap.GSL_EIGEN_SORT_VAL_DESC
GSL_EIGEN_SORT_ABS_ASC = _gslwrap.GSL_EIGEN_SORT_ABS_ASC
GSL_EIGEN_SORT_ABS_DESC = _gslwrap.GSL_EIGEN_SORT_ABS_DESC

def gsl_eigen_symmv_sort(*args, **kwargs):
    """gsl_eigen_symmv_sort(gsl_vector eval, gsl_matrix evec, gsl_eigen_sort_t sort_type) -> int"""
    return _gslwrap.gsl_eigen_symmv_sort(*args, **kwargs)

def gsl_eigen_hermv_sort(*args, **kwargs):
    """gsl_eigen_hermv_sort(gsl_vector eval, gsl_matrix_complex evec, gsl_eigen_sort_t sort_type) -> int"""
    return _gslwrap.gsl_eigen_hermv_sort(*args, **kwargs)

def gsl_eigen_jacobi(*args, **kwargs):
    """
    gsl_eigen_jacobi(gsl_matrix matrix, gsl_vector eval, gsl_matrix evec, 
        unsigned int max_rot, unsigned int nrot) -> int
    """
    return _gslwrap.gsl_eigen_jacobi(*args, **kwargs)

def gsl_eigen_invert_jacobi(*args, **kwargs):
    """gsl_eigen_invert_jacobi(gsl_matrix matrix, gsl_matrix ainv, unsigned int max_rot) -> int"""
    return _gslwrap.gsl_eigen_invert_jacobi(*args, **kwargs)

def gsl_spline_alloc(*args, **kwargs):
    """gsl_spline_alloc(gsl_interp_type T, size_t n) -> gsl_spline"""
    return _gslwrap.gsl_spline_alloc(*args, **kwargs)

def gsl_spline_init(*args, **kwargs):
    """gsl_spline_init(gsl_spline spline, double xa) -> gsl_error_flag_drop"""
    return _gslwrap.gsl_spline_init(*args, **kwargs)

def gsl_spline_eval_e(*args, **kwargs):
    """gsl_spline_eval_e(gsl_spline spline, double x, gsl_interp_accel a, double OUTPUT) -> gsl_error_flag_drop"""
    return _gslwrap.gsl_spline_eval_e(*args, **kwargs)

def gsl_spline_eval(*args, **kwargs):
    """gsl_spline_eval(gsl_spline spline, double x, gsl_interp_accel a) -> double"""
    return _gslwrap.gsl_spline_eval(*args, **kwargs)

def gsl_spline_eval_deriv_e(*args, **kwargs):
    """gsl_spline_eval_deriv_e(gsl_spline spline, double x, gsl_interp_accel a, double OUTPUT) -> gsl_error_flag_drop"""
    return _gslwrap.gsl_spline_eval_deriv_e(*args, **kwargs)

def gsl_spline_eval_deriv(*args, **kwargs):
    """gsl_spline_eval_deriv(gsl_spline spline, double x, gsl_interp_accel a) -> double"""
    return _gslwrap.gsl_spline_eval_deriv(*args, **kwargs)

def gsl_spline_eval_deriv2_e(*args, **kwargs):
    """gsl_spline_eval_deriv2_e(gsl_spline spline, double x, gsl_interp_accel a, double OUTPUT) -> gsl_error_flag_drop"""
    return _gslwrap.gsl_spline_eval_deriv2_e(*args, **kwargs)

def gsl_spline_eval_deriv2(*args, **kwargs):
    """gsl_spline_eval_deriv2(gsl_spline spline, double x, gsl_interp_accel a) -> double"""
    return _gslwrap.gsl_spline_eval_deriv2(*args, **kwargs)

def gsl_spline_eval_integ_e(*args, **kwargs):
    """
    gsl_spline_eval_integ_e(gsl_spline spline, double a, double b, gsl_interp_accel acc, 
        double OUTPUT) -> gsl_error_flag_drop
    """
    return _gslwrap.gsl_spline_eval_integ_e(*args, **kwargs)

def gsl_spline_eval_integ(*args, **kwargs):
    """gsl_spline_eval_integ(gsl_spline spline, double a, double b, gsl_interp_accel acc) -> double"""
    return _gslwrap.gsl_spline_eval_integ(*args, **kwargs)

def gsl_spline_free(*args, **kwargs):
    """gsl_spline_free(gsl_spline spline)"""
    return _gslwrap.gsl_spline_free(*args, **kwargs)

def gsl_interp_accel_alloc(*args, **kwargs):
    """gsl_interp_accel_alloc() -> gsl_interp_accel"""
    return _gslwrap.gsl_interp_accel_alloc(*args, **kwargs)

def gsl_interp_accel_find(*args, **kwargs):
    """gsl_interp_accel_find(gsl_interp_accel a, double x_array, double x) -> size_t"""
    return _gslwrap.gsl_interp_accel_find(*args, **kwargs)

def gsl_interp_accel_reset(*args, **kwargs):
    """gsl_interp_accel_reset(gsl_interp_accel a) -> gsl_error_flag_drop"""
    return _gslwrap.gsl_interp_accel_reset(*args, **kwargs)

def gsl_interp_accel_free(*args, **kwargs):
    """gsl_interp_accel_free(gsl_interp_accel a)"""
    return _gslwrap.gsl_interp_accel_free(*args, **kwargs)

def gsl_interp_alloc(*args, **kwargs):
    """gsl_interp_alloc(gsl_interp_type T, size_t n) -> gsl_interp"""
    return _gslwrap.gsl_interp_alloc(*args, **kwargs)

def gsl_interp_init(*args, **kwargs):
    """gsl_interp_init(gsl_interp obj, double xa) -> gsl_error_flag_drop"""
    return _gslwrap.gsl_interp_init(*args, **kwargs)

def gsl_interp_name(*args, **kwargs):
    """gsl_interp_name(gsl_interp interp) -> char"""
    return _gslwrap.gsl_interp_name(*args, **kwargs)

def gsl_interp_min_size(*args, **kwargs):
    """gsl_interp_min_size(gsl_interp interp) -> unsigned int"""
    return _gslwrap.gsl_interp_min_size(*args, **kwargs)

def gsl_interp_eval_e(*args, **kwargs):
    """
    gsl_interp_eval_e(gsl_interp IN, double xa, double ya, double x, gsl_interp_accel a, 
        double OUTPUT) -> gsl_error_flag_drop
    """
    return _gslwrap.gsl_interp_eval_e(*args, **kwargs)

def gsl_interp_eval(*args, **kwargs):
    """gsl_interp_eval(gsl_interp IN, double xa, double ya, double x, gsl_interp_accel a) -> double"""
    return _gslwrap.gsl_interp_eval(*args, **kwargs)

def gsl_interp_eval_deriv_e(*args, **kwargs):
    """
    gsl_interp_eval_deriv_e(gsl_interp IN, double xa, double ya, double x, gsl_interp_accel a, 
        double OUTPUT) -> gsl_error_flag_drop
    """
    return _gslwrap.gsl_interp_eval_deriv_e(*args, **kwargs)

def gsl_interp_eval_deriv(*args, **kwargs):
    """gsl_interp_eval_deriv(gsl_interp IN, double xa, double ya, double x, gsl_interp_accel a) -> double"""
    return _gslwrap.gsl_interp_eval_deriv(*args, **kwargs)

def gsl_interp_eval_deriv2_e(*args, **kwargs):
    """
    gsl_interp_eval_deriv2_e(gsl_interp IN, double xa, double ya, double x, gsl_interp_accel a, 
        double OUTPUT) -> gsl_error_flag_drop
    """
    return _gslwrap.gsl_interp_eval_deriv2_e(*args, **kwargs)

def gsl_interp_eval_deriv2(*args, **kwargs):
    """gsl_interp_eval_deriv2(gsl_interp IN, double xa, double ya, double x, gsl_interp_accel a) -> double"""
    return _gslwrap.gsl_interp_eval_deriv2(*args, **kwargs)

def gsl_interp_eval_integ_e(*args, **kwargs):
    """
    gsl_interp_eval_integ_e(gsl_interp IN, double xa, double ya, double a, double b, 
        gsl_interp_accel acc, double OUTPUT) -> gsl_error_flag_drop
    """
    return _gslwrap.gsl_interp_eval_integ_e(*args, **kwargs)

def gsl_interp_eval_integ(*args, **kwargs):
    """
    gsl_interp_eval_integ(gsl_interp IN, double xa, double ya, double a, double b, 
        gsl_interp_accel acc) -> double
    """
    return _gslwrap.gsl_interp_eval_integ(*args, **kwargs)

def gsl_interp_free(*args, **kwargs):
    """gsl_interp_free(gsl_interp interp)"""
    return _gslwrap.gsl_interp_free(*args, **kwargs)

def gsl_interp_bsearch(*args, **kwargs):
    """gsl_interp_bsearch(double x_array, double x, size_t index_lo, size_t index_hi) -> size_t"""
    return _gslwrap.gsl_interp_bsearch(*args, **kwargs)
cvar = _gslwrap.cvar
gsl_interp_linear = cvar.gsl_interp_linear
gsl_interp_polynomial = cvar.gsl_interp_polynomial
gsl_interp_cspline = cvar.gsl_interp_cspline
gsl_interp_cspline_periodic = cvar.gsl_interp_cspline_periodic
gsl_interp_akima = cvar.gsl_interp_akima
gsl_interp_akima_periodic = cvar.gsl_interp_akima_periodic

