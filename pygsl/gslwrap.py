# This file was created automatically by SWIG 1.3.29.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _gslwrap
import new
new_instancemethod = new.instancemethod
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'PySwigObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

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
gsl_linalg_complex_householder_mh = _gslwrap.gsl_linalg_complex_householder_mh
gsl_linalg_complex_householder_hv = _gslwrap.gsl_linalg_complex_householder_hv
gsl_linalg_hessenberg_decomp = _gslwrap.gsl_linalg_hessenberg_decomp
gsl_linalg_hessenberg_unpack = _gslwrap.gsl_linalg_hessenberg_unpack
gsl_linalg_hessenberg_unpack_accum = _gslwrap.gsl_linalg_hessenberg_unpack_accum
gsl_linalg_hessenberg_set_zero = _gslwrap.gsl_linalg_hessenberg_set_zero
gsl_linalg_hessenberg_submatrix = _gslwrap.gsl_linalg_hessenberg_submatrix
gsl_linalg_hesstri_decomp = _gslwrap.gsl_linalg_hesstri_decomp
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
gsl_linalg_QR_QTmat = _gslwrap.gsl_linalg_QR_QTmat
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
gsl_linalg_LQ_decomp = _gslwrap.gsl_linalg_LQ_decomp
gsl_linalg_LQ_solve_T = _gslwrap.gsl_linalg_LQ_solve_T
gsl_linalg_LQ_svx_T = _gslwrap.gsl_linalg_LQ_svx_T
gsl_linalg_LQ_lssolve_T = _gslwrap.gsl_linalg_LQ_lssolve_T
gsl_linalg_LQ_Lsolve_T = _gslwrap.gsl_linalg_LQ_Lsolve_T
gsl_linalg_LQ_Lsvx_T = _gslwrap.gsl_linalg_LQ_Lsvx_T
gsl_linalg_L_solve_T = _gslwrap.gsl_linalg_L_solve_T
gsl_linalg_LQ_vecQ = _gslwrap.gsl_linalg_LQ_vecQ
gsl_linalg_LQ_vecQT = _gslwrap.gsl_linalg_LQ_vecQT
gsl_linalg_LQ_unpack = _gslwrap.gsl_linalg_LQ_unpack
gsl_linalg_LQ_update = _gslwrap.gsl_linalg_LQ_update
gsl_linalg_LQ_LQsolve = _gslwrap.gsl_linalg_LQ_LQsolve
gsl_linalg_PTLQ_decomp = _gslwrap.gsl_linalg_PTLQ_decomp
gsl_linalg_PTLQ_decomp2 = _gslwrap.gsl_linalg_PTLQ_decomp2
gsl_linalg_PTLQ_solve_T = _gslwrap.gsl_linalg_PTLQ_solve_T
gsl_linalg_PTLQ_svx_T = _gslwrap.gsl_linalg_PTLQ_svx_T
gsl_linalg_PTLQ_LQsolve_T = _gslwrap.gsl_linalg_PTLQ_LQsolve_T
gsl_linalg_PTLQ_Lsolve_T = _gslwrap.gsl_linalg_PTLQ_Lsolve_T
gsl_linalg_PTLQ_Lsvx_T = _gslwrap.gsl_linalg_PTLQ_Lsvx_T
gsl_linalg_PTLQ_update = _gslwrap.gsl_linalg_PTLQ_update
gsl_linalg_cholesky_decomp = _gslwrap.gsl_linalg_cholesky_decomp
gsl_linalg_cholesky_solve = _gslwrap.gsl_linalg_cholesky_solve
gsl_linalg_cholesky_svx = _gslwrap.gsl_linalg_cholesky_svx
gsl_linalg_cholesky_decomp_unit = _gslwrap.gsl_linalg_cholesky_decomp_unit
gsl_linalg_complex_cholesky_decomp = _gslwrap.gsl_linalg_complex_cholesky_decomp
gsl_linalg_complex_cholesky_solve = _gslwrap.gsl_linalg_complex_cholesky_solve
gsl_linalg_complex_cholesky_svx = _gslwrap.gsl_linalg_complex_cholesky_svx
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
gsl_linalg_balance_matrix = _gslwrap.gsl_linalg_balance_matrix
gsl_linalg_balance_accum = _gslwrap.gsl_linalg_balance_accum
gsl_linalg_balance_columns = _gslwrap.gsl_linalg_balance_columns
class Permutation(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Permutation, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Permutation, name)
    __repr__ = _swig_repr
    __swig_getmethods__["size"] = _gslwrap.Permutation_size_get
    if _newclass:size = property(_gslwrap.Permutation_size_get)
    __swig_getmethods__["data"] = _gslwrap.Permutation_data_get
    if _newclass:data = property(_gslwrap.Permutation_data_get)
    def __init__(self, *args, **kwargs): 
        this = _gslwrap.new_Permutation(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
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
    __swig_destroy__ = _gslwrap.delete_Permutation
    __del__ = lambda self : None;
Permutation_swigregister = _gslwrap.Permutation_swigregister
Permutation_swigregister(Permutation)

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
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """bla blamore blah blah"""
        this = _gslwrap.new_Combination(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_Combination
    __del__ = lambda self : None;
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

Combination_swigregister = _gslwrap.Combination_swigregister
Combination_swigregister(Combination)

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

def gsl_hypot3(*args, **kwargs):
  """gsl_hypot3(double x, double y, double z) -> double"""
  return _gslwrap.gsl_hypot3(*args, **kwargs)

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

def gsl_nan(*args):
  """gsl_nan() -> double"""
  return _gslwrap.gsl_nan(*args)

def gsl_posinf(*args):
  """gsl_posinf() -> double"""
  return _gslwrap.gsl_posinf(*args)

def gsl_neginf(*args):
  """gsl_neginf() -> double"""
  return _gslwrap.gsl_neginf(*args)

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
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, size_t n) -> gsl_eigen_symm_workspace"""
        this = _gslwrap.new_gsl_eigen_symm_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_symm_workspace
    __del__ = lambda self : None;
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_symm_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_symm_workspace_size_get)
    __swig_getmethods__["d"] = _gslwrap.gsl_eigen_symm_workspace_d_get
    if _newclass:d = property(_gslwrap.gsl_eigen_symm_workspace_d_get)
    __swig_getmethods__["sd"] = _gslwrap.gsl_eigen_symm_workspace_sd_get
    if _newclass:sd = property(_gslwrap.gsl_eigen_symm_workspace_sd_get)
gsl_eigen_symm_workspace_swigregister = _gslwrap.gsl_eigen_symm_workspace_swigregister
gsl_eigen_symm_workspace_swigregister(gsl_eigen_symm_workspace)


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
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, size_t n) -> gsl_eigen_symmv_workspace"""
        this = _gslwrap.new_gsl_eigen_symmv_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_symmv_workspace
    __del__ = lambda self : None;
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
gsl_eigen_symmv_workspace_swigregister = _gslwrap.gsl_eigen_symmv_workspace_swigregister
gsl_eigen_symmv_workspace_swigregister(gsl_eigen_symmv_workspace)


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
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, size_t n) -> gsl_eigen_herm_workspace"""
        this = _gslwrap.new_gsl_eigen_herm_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_herm_workspace
    __del__ = lambda self : None;
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_herm_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_herm_workspace_size_get)
    __swig_getmethods__["d"] = _gslwrap.gsl_eigen_herm_workspace_d_get
    if _newclass:d = property(_gslwrap.gsl_eigen_herm_workspace_d_get)
    __swig_getmethods__["sd"] = _gslwrap.gsl_eigen_herm_workspace_sd_get
    if _newclass:sd = property(_gslwrap.gsl_eigen_herm_workspace_sd_get)
    __swig_getmethods__["tau"] = _gslwrap.gsl_eigen_herm_workspace_tau_get
    if _newclass:tau = property(_gslwrap.gsl_eigen_herm_workspace_tau_get)
gsl_eigen_herm_workspace_swigregister = _gslwrap.gsl_eigen_herm_workspace_swigregister
gsl_eigen_herm_workspace_swigregister(gsl_eigen_herm_workspace)


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
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, size_t n) -> gsl_eigen_hermv_workspace"""
        this = _gslwrap.new_gsl_eigen_hermv_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_hermv_workspace
    __del__ = lambda self : None;
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
gsl_eigen_hermv_workspace_swigregister = _gslwrap.gsl_eigen_hermv_workspace_swigregister
gsl_eigen_hermv_workspace_swigregister(gsl_eigen_hermv_workspace)


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
class gsl_eigen_francis_workspace(_object):
    """Proxy of C gsl_eigen_francis_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_francis_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_francis_workspace, name)
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, void ?) -> gsl_eigen_francis_workspace"""
        this = _gslwrap.new_gsl_eigen_francis_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_francis_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_francis_workspace_size_get)
    __swig_getmethods__["max_iterations"] = _gslwrap.gsl_eigen_francis_workspace_max_iterations_get
    if _newclass:max_iterations = property(_gslwrap.gsl_eigen_francis_workspace_max_iterations_get)
    __swig_getmethods__["n_iter"] = _gslwrap.gsl_eigen_francis_workspace_n_iter_get
    if _newclass:n_iter = property(_gslwrap.gsl_eigen_francis_workspace_n_iter_get)
    __swig_getmethods__["n_evals"] = _gslwrap.gsl_eigen_francis_workspace_n_evals_get
    if _newclass:n_evals = property(_gslwrap.gsl_eigen_francis_workspace_n_evals_get)
    __swig_getmethods__["compute_t"] = _gslwrap.gsl_eigen_francis_workspace_compute_t_get
    if _newclass:compute_t = property(_gslwrap.gsl_eigen_francis_workspace_compute_t_get)
    __swig_getmethods__["H"] = _gslwrap.gsl_eigen_francis_workspace_H_get
    if _newclass:H = property(_gslwrap.gsl_eigen_francis_workspace_H_get)
    __swig_getmethods__["Z"] = _gslwrap.gsl_eigen_francis_workspace_Z_get
    if _newclass:Z = property(_gslwrap.gsl_eigen_francis_workspace_Z_get)
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_francis_workspace
    __del__ = lambda self : None;
gsl_eigen_francis_workspace_swigregister = _gslwrap.gsl_eigen_francis_workspace_swigregister
gsl_eigen_francis_workspace_swigregister(gsl_eigen_francis_workspace)


def gsl_eigen_francis_alloc(*args):
  """gsl_eigen_francis_alloc() -> gsl_eigen_francis_workspace"""
  return _gslwrap.gsl_eigen_francis_alloc(*args)

def gsl_eigen_francis_free(*args, **kwargs):
  """gsl_eigen_francis_free(gsl_eigen_francis_workspace w)"""
  return _gslwrap.gsl_eigen_francis_free(*args, **kwargs)

def gsl_eigen_francis_T(*args, **kwargs):
  """gsl_eigen_francis_T(int compute_t, gsl_eigen_francis_workspace w)"""
  return _gslwrap.gsl_eigen_francis_T(*args, **kwargs)

def gsl_eigen_francis(*args, **kwargs):
  """gsl_eigen_francis(gsl_matrix H, gsl_vector_complex eval, gsl_eigen_francis_workspace w) -> int"""
  return _gslwrap.gsl_eigen_francis(*args, **kwargs)

def gsl_eigen_francis_Z(*args, **kwargs):
  """
    gsl_eigen_francis_Z(gsl_matrix H, gsl_vector_complex eval, gsl_matrix Z, 
        gsl_eigen_francis_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_francis_Z(*args, **kwargs)
class gsl_eigen_nonsymm_workspace(_object):
    """Proxy of C gsl_eigen_nonsymm_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_nonsymm_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_nonsymm_workspace, name)
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, size_t n) -> gsl_eigen_nonsymm_workspace"""
        this = _gslwrap.new_gsl_eigen_nonsymm_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_nonsymm_workspace
    __del__ = lambda self : None;
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_nonsymm_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_nonsymm_workspace_size_get)
    __swig_getmethods__["diag"] = _gslwrap.gsl_eigen_nonsymm_workspace_diag_get
    if _newclass:diag = property(_gslwrap.gsl_eigen_nonsymm_workspace_diag_get)
    __swig_getmethods__["tau"] = _gslwrap.gsl_eigen_nonsymm_workspace_tau_get
    if _newclass:tau = property(_gslwrap.gsl_eigen_nonsymm_workspace_tau_get)
    __swig_getmethods__["Z"] = _gslwrap.gsl_eigen_nonsymm_workspace_Z_get
    if _newclass:Z = property(_gslwrap.gsl_eigen_nonsymm_workspace_Z_get)
    __swig_getmethods__["do_balance"] = _gslwrap.gsl_eigen_nonsymm_workspace_do_balance_get
    if _newclass:do_balance = property(_gslwrap.gsl_eigen_nonsymm_workspace_do_balance_get)
    __swig_getmethods__["n_evals"] = _gslwrap.gsl_eigen_nonsymm_workspace_n_evals_get
    if _newclass:n_evals = property(_gslwrap.gsl_eigen_nonsymm_workspace_n_evals_get)
    __swig_getmethods__["francis_workspace_p"] = _gslwrap.gsl_eigen_nonsymm_workspace_francis_workspace_p_get
    if _newclass:francis_workspace_p = property(_gslwrap.gsl_eigen_nonsymm_workspace_francis_workspace_p_get)
gsl_eigen_nonsymm_workspace_swigregister = _gslwrap.gsl_eigen_nonsymm_workspace_swigregister
gsl_eigen_nonsymm_workspace_swigregister(gsl_eigen_nonsymm_workspace)


def gsl_eigen_nonsymm_alloc(*args, **kwargs):
  """gsl_eigen_nonsymm_alloc(size_t n) -> gsl_eigen_nonsymm_workspace"""
  return _gslwrap.gsl_eigen_nonsymm_alloc(*args, **kwargs)

def gsl_eigen_nonsymm_free(*args, **kwargs):
  """gsl_eigen_nonsymm_free(gsl_eigen_nonsymm_workspace w)"""
  return _gslwrap.gsl_eigen_nonsymm_free(*args, **kwargs)

def gsl_eigen_nonsymm_params(*args, **kwargs):
  """gsl_eigen_nonsymm_params(int compute_t, int balance, gsl_eigen_nonsymm_workspace w)"""
  return _gslwrap.gsl_eigen_nonsymm_params(*args, **kwargs)

def gsl_eigen_nonsymm(*args, **kwargs):
  """gsl_eigen_nonsymm(gsl_matrix A, gsl_vector_complex eval, gsl_eigen_nonsymm_workspace w) -> int"""
  return _gslwrap.gsl_eigen_nonsymm(*args, **kwargs)

def gsl_eigen_nonsymm_Z(*args, **kwargs):
  """
    gsl_eigen_nonsymm_Z(gsl_matrix A, gsl_vector_complex eval, gsl_matrix Z, 
        gsl_eigen_nonsymm_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_nonsymm_Z(*args, **kwargs)
class gsl_eigen_nonsymmv_workspace(_object):
    """Proxy of C gsl_eigen_nonsymmv_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_nonsymmv_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_nonsymmv_workspace, name)
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, size_t n) -> gsl_eigen_nonsymmv_workspace"""
        this = _gslwrap.new_gsl_eigen_nonsymmv_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_nonsymmv_workspace
    __del__ = lambda self : None;
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_nonsymmv_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_nonsymmv_workspace_size_get)
    __swig_getmethods__["work"] = _gslwrap.gsl_eigen_nonsymmv_workspace_work_get
    if _newclass:work = property(_gslwrap.gsl_eigen_nonsymmv_workspace_work_get)
    __swig_getmethods__["work2"] = _gslwrap.gsl_eigen_nonsymmv_workspace_work2_get
    if _newclass:work2 = property(_gslwrap.gsl_eigen_nonsymmv_workspace_work2_get)
    __swig_getmethods__["work3"] = _gslwrap.gsl_eigen_nonsymmv_workspace_work3_get
    if _newclass:work3 = property(_gslwrap.gsl_eigen_nonsymmv_workspace_work3_get)
    __swig_getmethods__["Z"] = _gslwrap.gsl_eigen_nonsymmv_workspace_Z_get
    if _newclass:Z = property(_gslwrap.gsl_eigen_nonsymmv_workspace_Z_get)
    __swig_getmethods__["nonsymm_workspace_p"] = _gslwrap.gsl_eigen_nonsymmv_workspace_nonsymm_workspace_p_get
    if _newclass:nonsymm_workspace_p = property(_gslwrap.gsl_eigen_nonsymmv_workspace_nonsymm_workspace_p_get)
gsl_eigen_nonsymmv_workspace_swigregister = _gslwrap.gsl_eigen_nonsymmv_workspace_swigregister
gsl_eigen_nonsymmv_workspace_swigregister(gsl_eigen_nonsymmv_workspace)


def gsl_eigen_nonsymmv_alloc(*args, **kwargs):
  """gsl_eigen_nonsymmv_alloc(size_t n) -> gsl_eigen_nonsymmv_workspace"""
  return _gslwrap.gsl_eigen_nonsymmv_alloc(*args, **kwargs)

def gsl_eigen_nonsymmv_free(*args, **kwargs):
  """gsl_eigen_nonsymmv_free(gsl_eigen_nonsymmv_workspace w)"""
  return _gslwrap.gsl_eigen_nonsymmv_free(*args, **kwargs)

def gsl_eigen_nonsymmv(*args, **kwargs):
  """
    gsl_eigen_nonsymmv(gsl_matrix A, gsl_vector_complex eval, gsl_matrix_complex evec, 
        gsl_eigen_nonsymmv_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_nonsymmv(*args, **kwargs)

def gsl_eigen_nonsymmv_Z(*args, **kwargs):
  """
    gsl_eigen_nonsymmv_Z(gsl_matrix A, gsl_vector_complex eval, gsl_matrix_complex evec, 
        gsl_matrix Z, gsl_eigen_nonsymmv_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_nonsymmv_Z(*args, **kwargs)
class gsl_eigen_gensymm_workspace(_object):
    """Proxy of C gsl_eigen_gensymm_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_gensymm_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_gensymm_workspace, name)
    __repr__ = _swig_repr
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_gensymm_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_gensymm_workspace_size_get)
    __swig_getmethods__["symm_workspace_p"] = _gslwrap.gsl_eigen_gensymm_workspace_symm_workspace_p_get
    if _newclass:symm_workspace_p = property(_gslwrap.gsl_eigen_gensymm_workspace_symm_workspace_p_get)
    def __init__(self, *args, **kwargs): 
        """__init__(self) -> gsl_eigen_gensymm_workspace"""
        this = _gslwrap.new_gsl_eigen_gensymm_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_gensymm_workspace
    __del__ = lambda self : None;
gsl_eigen_gensymm_workspace_swigregister = _gslwrap.gsl_eigen_gensymm_workspace_swigregister
gsl_eigen_gensymm_workspace_swigregister(gsl_eigen_gensymm_workspace)


def gsl_eigen_gensymm_alloc(*args, **kwargs):
  """gsl_eigen_gensymm_alloc(size_t n) -> gsl_eigen_gensymm_workspace"""
  return _gslwrap.gsl_eigen_gensymm_alloc(*args, **kwargs)

def gsl_eigen_gensymm_free(*args, **kwargs):
  """gsl_eigen_gensymm_free(gsl_eigen_gensymm_workspace w)"""
  return _gslwrap.gsl_eigen_gensymm_free(*args, **kwargs)

def gsl_eigen_gensymm(*args, **kwargs):
  """gsl_eigen_gensymm(gsl_matrix A, gsl_matrix B, gsl_vector eval, gsl_eigen_gensymm_workspace w) -> int"""
  return _gslwrap.gsl_eigen_gensymm(*args, **kwargs)

def gsl_eigen_gensymm_standardize(*args, **kwargs):
  """gsl_eigen_gensymm_standardize(gsl_matrix A, gsl_matrix B) -> int"""
  return _gslwrap.gsl_eigen_gensymm_standardize(*args, **kwargs)
class gsl_eigen_gensymmv_workspace(_object):
    """Proxy of C gsl_eigen_gensymmv_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_gensymmv_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_gensymmv_workspace, name)
    __repr__ = _swig_repr
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_gensymmv_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_gensymmv_workspace_size_get)
    __swig_getmethods__["symmv_workspace_p"] = _gslwrap.gsl_eigen_gensymmv_workspace_symmv_workspace_p_get
    if _newclass:symmv_workspace_p = property(_gslwrap.gsl_eigen_gensymmv_workspace_symmv_workspace_p_get)
    def __init__(self, *args, **kwargs): 
        """__init__(self) -> gsl_eigen_gensymmv_workspace"""
        this = _gslwrap.new_gsl_eigen_gensymmv_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_gensymmv_workspace
    __del__ = lambda self : None;
gsl_eigen_gensymmv_workspace_swigregister = _gslwrap.gsl_eigen_gensymmv_workspace_swigregister
gsl_eigen_gensymmv_workspace_swigregister(gsl_eigen_gensymmv_workspace)


def gsl_eigen_gensymmv_alloc(*args, **kwargs):
  """gsl_eigen_gensymmv_alloc(size_t n) -> gsl_eigen_gensymmv_workspace"""
  return _gslwrap.gsl_eigen_gensymmv_alloc(*args, **kwargs)

def gsl_eigen_gensymmv_free(*args, **kwargs):
  """gsl_eigen_gensymmv_free(gsl_eigen_gensymmv_workspace w)"""
  return _gslwrap.gsl_eigen_gensymmv_free(*args, **kwargs)

def gsl_eigen_gensymmv(*args, **kwargs):
  """
    gsl_eigen_gensymmv(gsl_matrix A, gsl_matrix B, gsl_vector eval, gsl_matrix evec, 
        gsl_eigen_gensymmv_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_gensymmv(*args, **kwargs)
class gsl_eigen_genherm_workspace(_object):
    """Proxy of C gsl_eigen_genherm_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_genherm_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_genherm_workspace, name)
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, size_t n) -> gsl_eigen_genherm_workspace"""
        this = _gslwrap.new_gsl_eigen_genherm_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_genherm_workspace
    __del__ = lambda self : None;
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_genherm_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_genherm_workspace_size_get)
    __swig_getmethods__["herm_workspace_p"] = _gslwrap.gsl_eigen_genherm_workspace_herm_workspace_p_get
    if _newclass:herm_workspace_p = property(_gslwrap.gsl_eigen_genherm_workspace_herm_workspace_p_get)
gsl_eigen_genherm_workspace_swigregister = _gslwrap.gsl_eigen_genherm_workspace_swigregister
gsl_eigen_genherm_workspace_swigregister(gsl_eigen_genherm_workspace)


def gsl_eigen_genherm_alloc(*args, **kwargs):
  """gsl_eigen_genherm_alloc(size_t n) -> gsl_eigen_genherm_workspace"""
  return _gslwrap.gsl_eigen_genherm_alloc(*args, **kwargs)

def gsl_eigen_genherm_free(*args, **kwargs):
  """gsl_eigen_genherm_free(gsl_eigen_genherm_workspace w)"""
  return _gslwrap.gsl_eigen_genherm_free(*args, **kwargs)

def gsl_eigen_genherm(*args, **kwargs):
  """
    gsl_eigen_genherm(gsl_matrix_complex A, gsl_matrix_complex B, gsl_vector eval, 
        gsl_eigen_genherm_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_genherm(*args, **kwargs)

def gsl_eigen_genherm_standardize(*args, **kwargs):
  """gsl_eigen_genherm_standardize(gsl_matrix_complex A, gsl_matrix_complex B) -> int"""
  return _gslwrap.gsl_eigen_genherm_standardize(*args, **kwargs)
class gsl_eigen_genhermv_workspace(_object):
    """Proxy of C gsl_eigen_genhermv_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_genhermv_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_genhermv_workspace, name)
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, size_t n) -> gsl_eigen_genhermv_workspace"""
        this = _gslwrap.new_gsl_eigen_genhermv_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_genhermv_workspace
    __del__ = lambda self : None;
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_genhermv_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_genhermv_workspace_size_get)
    __swig_getmethods__["hermv_workspace_p"] = _gslwrap.gsl_eigen_genhermv_workspace_hermv_workspace_p_get
    if _newclass:hermv_workspace_p = property(_gslwrap.gsl_eigen_genhermv_workspace_hermv_workspace_p_get)
gsl_eigen_genhermv_workspace_swigregister = _gslwrap.gsl_eigen_genhermv_workspace_swigregister
gsl_eigen_genhermv_workspace_swigregister(gsl_eigen_genhermv_workspace)


def gsl_eigen_genhermv_alloc(*args, **kwargs):
  """gsl_eigen_genhermv_alloc(size_t n) -> gsl_eigen_genhermv_workspace"""
  return _gslwrap.gsl_eigen_genhermv_alloc(*args, **kwargs)

def gsl_eigen_genhermv_free(*args, **kwargs):
  """gsl_eigen_genhermv_free(gsl_eigen_genhermv_workspace w)"""
  return _gslwrap.gsl_eigen_genhermv_free(*args, **kwargs)

def gsl_eigen_genhermv(*args, **kwargs):
  """
    gsl_eigen_genhermv(gsl_matrix_complex A, gsl_matrix_complex B, gsl_vector eval, 
        gsl_matrix_complex evec, gsl_eigen_genhermv_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_genhermv(*args, **kwargs)
class gsl_eigen_gen_workspace(_object):
    """Proxy of C gsl_eigen_gen_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_gen_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_gen_workspace, name)
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, size_t n) -> gsl_eigen_gen_workspace"""
        this = _gslwrap.new_gsl_eigen_gen_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_gen_workspace
    __del__ = lambda self : None;
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_gen_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_gen_workspace_size_get)
    __swig_getmethods__["work"] = _gslwrap.gsl_eigen_gen_workspace_work_get
    if _newclass:work = property(_gslwrap.gsl_eigen_gen_workspace_work_get)
    __swig_getmethods__["n_evals"] = _gslwrap.gsl_eigen_gen_workspace_n_evals_get
    if _newclass:n_evals = property(_gslwrap.gsl_eigen_gen_workspace_n_evals_get)
    __swig_getmethods__["max_iterations"] = _gslwrap.gsl_eigen_gen_workspace_max_iterations_get
    if _newclass:max_iterations = property(_gslwrap.gsl_eigen_gen_workspace_max_iterations_get)
    __swig_getmethods__["n_iter"] = _gslwrap.gsl_eigen_gen_workspace_n_iter_get
    if _newclass:n_iter = property(_gslwrap.gsl_eigen_gen_workspace_n_iter_get)
    __swig_getmethods__["eshift"] = _gslwrap.gsl_eigen_gen_workspace_eshift_get
    if _newclass:eshift = property(_gslwrap.gsl_eigen_gen_workspace_eshift_get)
    __swig_getmethods__["needtop"] = _gslwrap.gsl_eigen_gen_workspace_needtop_get
    if _newclass:needtop = property(_gslwrap.gsl_eigen_gen_workspace_needtop_get)
    __swig_getmethods__["atol"] = _gslwrap.gsl_eigen_gen_workspace_atol_get
    if _newclass:atol = property(_gslwrap.gsl_eigen_gen_workspace_atol_get)
    __swig_getmethods__["btol"] = _gslwrap.gsl_eigen_gen_workspace_btol_get
    if _newclass:btol = property(_gslwrap.gsl_eigen_gen_workspace_btol_get)
    __swig_getmethods__["ascale"] = _gslwrap.gsl_eigen_gen_workspace_ascale_get
    if _newclass:ascale = property(_gslwrap.gsl_eigen_gen_workspace_ascale_get)
    __swig_getmethods__["bscale"] = _gslwrap.gsl_eigen_gen_workspace_bscale_get
    if _newclass:bscale = property(_gslwrap.gsl_eigen_gen_workspace_bscale_get)
    __swig_getmethods__["H"] = _gslwrap.gsl_eigen_gen_workspace_H_get
    if _newclass:H = property(_gslwrap.gsl_eigen_gen_workspace_H_get)
    __swig_getmethods__["R"] = _gslwrap.gsl_eigen_gen_workspace_R_get
    if _newclass:R = property(_gslwrap.gsl_eigen_gen_workspace_R_get)
    __swig_getmethods__["compute_s"] = _gslwrap.gsl_eigen_gen_workspace_compute_s_get
    if _newclass:compute_s = property(_gslwrap.gsl_eigen_gen_workspace_compute_s_get)
    __swig_getmethods__["compute_t"] = _gslwrap.gsl_eigen_gen_workspace_compute_t_get
    if _newclass:compute_t = property(_gslwrap.gsl_eigen_gen_workspace_compute_t_get)
    __swig_getmethods__["Q"] = _gslwrap.gsl_eigen_gen_workspace_Q_get
    if _newclass:Q = property(_gslwrap.gsl_eigen_gen_workspace_Q_get)
    __swig_getmethods__["Z"] = _gslwrap.gsl_eigen_gen_workspace_Z_get
    if _newclass:Z = property(_gslwrap.gsl_eigen_gen_workspace_Z_get)
gsl_eigen_gen_workspace_swigregister = _gslwrap.gsl_eigen_gen_workspace_swigregister
gsl_eigen_gen_workspace_swigregister(gsl_eigen_gen_workspace)


def gsl_eigen_gen_alloc(*args, **kwargs):
  """gsl_eigen_gen_alloc(size_t n) -> gsl_eigen_gen_workspace"""
  return _gslwrap.gsl_eigen_gen_alloc(*args, **kwargs)

def gsl_eigen_gen_free(*args, **kwargs):
  """gsl_eigen_gen_free(gsl_eigen_gen_workspace w)"""
  return _gslwrap.gsl_eigen_gen_free(*args, **kwargs)

def gsl_eigen_gen_params(*args, **kwargs):
  """gsl_eigen_gen_params(int compute_s, int compute_t, int balance, gsl_eigen_gen_workspace w)"""
  return _gslwrap.gsl_eigen_gen_params(*args, **kwargs)

def gsl_eigen_gen(*args, **kwargs):
  """
    gsl_eigen_gen(gsl_matrix A, gsl_matrix B, gsl_vector_complex alpha, 
        gsl_vector beta, gsl_eigen_gen_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_gen(*args, **kwargs)

def gsl_eigen_gen_QZ(*args, **kwargs):
  """
    gsl_eigen_gen_QZ(gsl_matrix A, gsl_matrix B, gsl_vector_complex alpha, 
        gsl_vector beta, gsl_matrix Q, gsl_matrix Z, 
        gsl_eigen_gen_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_gen_QZ(*args, **kwargs)
class gsl_eigen_genv_workspace(_object):
    """Proxy of C gsl_eigen_genv_workspace struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_genv_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_genv_workspace, name)
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        """__init__(self, size_t n) -> gsl_eigen_genv_workspace"""
        this = _gslwrap.new_gsl_eigen_genv_workspace(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_eigen_genv_workspace
    __del__ = lambda self : None;
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_genv_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_genv_workspace_size_get)
    __swig_getmethods__["work1"] = _gslwrap.gsl_eigen_genv_workspace_work1_get
    if _newclass:work1 = property(_gslwrap.gsl_eigen_genv_workspace_work1_get)
    __swig_getmethods__["work2"] = _gslwrap.gsl_eigen_genv_workspace_work2_get
    if _newclass:work2 = property(_gslwrap.gsl_eigen_genv_workspace_work2_get)
    __swig_getmethods__["work3"] = _gslwrap.gsl_eigen_genv_workspace_work3_get
    if _newclass:work3 = property(_gslwrap.gsl_eigen_genv_workspace_work3_get)
    __swig_getmethods__["work4"] = _gslwrap.gsl_eigen_genv_workspace_work4_get
    if _newclass:work4 = property(_gslwrap.gsl_eigen_genv_workspace_work4_get)
    __swig_getmethods__["work5"] = _gslwrap.gsl_eigen_genv_workspace_work5_get
    if _newclass:work5 = property(_gslwrap.gsl_eigen_genv_workspace_work5_get)
    __swig_getmethods__["work6"] = _gslwrap.gsl_eigen_genv_workspace_work6_get
    if _newclass:work6 = property(_gslwrap.gsl_eigen_genv_workspace_work6_get)
    __swig_getmethods__["Q"] = _gslwrap.gsl_eigen_genv_workspace_Q_get
    if _newclass:Q = property(_gslwrap.gsl_eigen_genv_workspace_Q_get)
    __swig_getmethods__["Z"] = _gslwrap.gsl_eigen_genv_workspace_Z_get
    if _newclass:Z = property(_gslwrap.gsl_eigen_genv_workspace_Z_get)
    __swig_getmethods__["gen_workspace_p"] = _gslwrap.gsl_eigen_genv_workspace_gen_workspace_p_get
    if _newclass:gen_workspace_p = property(_gslwrap.gsl_eigen_genv_workspace_gen_workspace_p_get)
gsl_eigen_genv_workspace_swigregister = _gslwrap.gsl_eigen_genv_workspace_swigregister
gsl_eigen_genv_workspace_swigregister(gsl_eigen_genv_workspace)


def gsl_eigen_genv_alloc(*args, **kwargs):
  """gsl_eigen_genv_alloc(size_t n) -> gsl_eigen_genv_workspace"""
  return _gslwrap.gsl_eigen_genv_alloc(*args, **kwargs)

def gsl_eigen_genv_free(*args, **kwargs):
  """gsl_eigen_genv_free(gsl_eigen_genv_workspace w)"""
  return _gslwrap.gsl_eigen_genv_free(*args, **kwargs)

def gsl_eigen_genv(*args, **kwargs):
  """
    gsl_eigen_genv(gsl_matrix A, gsl_matrix B, gsl_vector_complex alpha, 
        gsl_vector beta, gsl_matrix_complex evec, 
        gsl_eigen_genv_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_genv(*args, **kwargs)

def gsl_eigen_genv_QZ(*args, **kwargs):
  """
    gsl_eigen_genv_QZ(gsl_matrix A, gsl_matrix B, gsl_vector_complex alpha, 
        gsl_vector beta, gsl_matrix_complex evec, 
        gsl_matrix Q, gsl_matrix Z, gsl_eigen_genv_workspace w) -> int
    """
  return _gslwrap.gsl_eigen_genv_QZ(*args, **kwargs)
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

def gsl_eigen_nonsymmv_sort(*args, **kwargs):
  """gsl_eigen_nonsymmv_sort(gsl_vector_complex eval, gsl_matrix_complex evec, gsl_eigen_sort_t sort_type) -> int"""
  return _gslwrap.gsl_eigen_nonsymmv_sort(*args, **kwargs)

def gsl_eigen_gensymmv_sort(*args, **kwargs):
  """gsl_eigen_gensymmv_sort(gsl_vector eval, gsl_matrix evec, gsl_eigen_sort_t sort_type) -> int"""
  return _gslwrap.gsl_eigen_gensymmv_sort(*args, **kwargs)

def gsl_eigen_genhermv_sort(*args, **kwargs):
  """gsl_eigen_genhermv_sort(gsl_vector eval, gsl_matrix_complex evec, gsl_eigen_sort_t sort_type) -> int"""
  return _gslwrap.gsl_eigen_genhermv_sort(*args, **kwargs)

def gsl_eigen_genv_sort(*args, **kwargs):
  """
    gsl_eigen_genv_sort(gsl_vector_complex alpha, gsl_vector beta, gsl_matrix_complex evec, 
        gsl_eigen_sort_t sort_type) -> int
    """
  return _gslwrap.gsl_eigen_genv_sort(*args, **kwargs)

def gsl_schur_gen_eigvals(*args, **kwargs):
  """
    gsl_schur_gen_eigvals(gsl_matrix A, gsl_matrix B, double wr1, double wr2, 
        double wi, double scale1, double scale2) -> int
    """
  return _gslwrap.gsl_schur_gen_eigvals(*args, **kwargs)

def gsl_schur_solve_equation(*args, **kwargs):
  """
    gsl_schur_solve_equation(double ca, gsl_matrix A, double z, double d1, double d2, 
        gsl_vector b, gsl_vector x, double s, double xnorm, 
        double smin) -> int
    """
  return _gslwrap.gsl_schur_solve_equation(*args, **kwargs)

def gsl_schur_solve_equation_z(*args, **kwargs):
  """
    gsl_schur_solve_equation_z(double ca, gsl_matrix A, gsl_complex z, double d1, 
        double d2, gsl_vector_complex b, gsl_vector_complex x, 
        double s, double xnorm, double smin) -> int
    """
  return _gslwrap.gsl_schur_solve_equation_z(*args, **kwargs)

def gsl_eigen_jacobi(*args, **kwargs):
  """
    gsl_eigen_jacobi(gsl_matrix matrix, gsl_vector eval, gsl_matrix evec, 
        unsigned int max_rot, unsigned int nrot) -> int
    """
  return _gslwrap.gsl_eigen_jacobi(*args, **kwargs)

def gsl_eigen_invert_jacobi(*args, **kwargs):
  """gsl_eigen_invert_jacobi(gsl_matrix matrix, gsl_matrix ainv, unsigned int max_rot) -> int"""
  return _gslwrap.gsl_eigen_invert_jacobi(*args, **kwargs)
class gsl_interp_accel(_object):
    """Proxy of C gsl_interp_accel struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_interp_accel, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_interp_accel, name)
    __repr__ = _swig_repr
    def tocobject(*args, **kwargs):
        """tocobject(self) -> PyObject"""
        return _gslwrap.gsl_interp_accel_tocobject(*args, **kwargs)

    def __init__(self, *args, **kwargs): 
        """__init__(self) -> gsl_interp_accel"""
        this = _gslwrap.new_gsl_interp_accel(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_interp_accel
    __del__ = lambda self : None;
gsl_interp_accel_swigregister = _gslwrap.gsl_interp_accel_swigregister
gsl_interp_accel_swigregister(gsl_interp_accel)

class gsl_spline(_object):
    """Proxy of C gsl_spline struct"""
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_spline, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_spline, name)
    __repr__ = _swig_repr
    def tocobject(*args, **kwargs):
        """tocobject(self) -> PyObject"""
        return _gslwrap.gsl_spline_tocobject(*args, **kwargs)

    def __init__(self, *args, **kwargs): 
        """__init__(self) -> gsl_spline"""
        this = _gslwrap.new_gsl_spline(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _gslwrap.delete_gsl_spline
    __del__ = lambda self : None;
gsl_spline_swigregister = _gslwrap.gsl_spline_swigregister
gsl_spline_swigregister(gsl_spline)


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

def gsl_spline_eval_vector(*args, **kwargs):
  """gsl_spline_eval_vector(gsl_spline spline, gsl_vector IN, gsl_interp_accel a) -> PyObject"""
  return _gslwrap.gsl_spline_eval_vector(*args, **kwargs)

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

def gsl_interp_accel_alloc(*args):
  """gsl_interp_accel_alloc() -> gsl_interp_accel"""
  return _gslwrap.gsl_interp_accel_alloc(*args)

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

