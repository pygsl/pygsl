# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.
import _gslwrap
def _swig_setattr(self,class_type,name,value):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    self.__dict__[name] = value

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

forward = _gslwrap.forward
backward = _gslwrap.backward
gsl_fft_complex_radix2_forward = _gslwrap.gsl_fft_complex_radix2_forward

gsl_fft_complex_radix2_backward = _gslwrap.gsl_fft_complex_radix2_backward

gsl_fft_complex_radix2_inverse = _gslwrap.gsl_fft_complex_radix2_inverse

gsl_fft_complex_radix2_transform = _gslwrap.gsl_fft_complex_radix2_transform

gsl_fft_complex_radix2_dif_forward = _gslwrap.gsl_fft_complex_radix2_dif_forward

gsl_fft_complex_radix2_dif_backward = _gslwrap.gsl_fft_complex_radix2_dif_backward

gsl_fft_complex_radix2_dif_inverse = _gslwrap.gsl_fft_complex_radix2_dif_inverse

gsl_fft_complex_radix2_dif_transform = _gslwrap.gsl_fft_complex_radix2_dif_transform

class gsl_fft_complex_wavetable(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_fft_complex_wavetable, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_fft_complex_wavetable, name)
    def __init__(self,*args,**kwargs):
        self.this = apply(_gslwrap.new_gsl_fft_complex_wavetable,args,kwargs)
        self.thisown = 1
    def __del__(self, destroy= _gslwrap.delete_gsl_fft_complex_wavetable):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_setmethods__["n"] = _gslwrap.gsl_fft_complex_wavetable_n_set
    __swig_getmethods__["n"] = _gslwrap.gsl_fft_complex_wavetable_n_get
    if _newclass:n = property(_gslwrap.gsl_fft_complex_wavetable_n_get,_gslwrap.gsl_fft_complex_wavetable_n_set)
    __swig_setmethods__["nf"] = _gslwrap.gsl_fft_complex_wavetable_nf_set
    __swig_getmethods__["nf"] = _gslwrap.gsl_fft_complex_wavetable_nf_get
    if _newclass:nf = property(_gslwrap.gsl_fft_complex_wavetable_nf_get,_gslwrap.gsl_fft_complex_wavetable_nf_set)
    __swig_setmethods__["factor"] = _gslwrap.gsl_fft_complex_wavetable_factor_set
    __swig_getmethods__["factor"] = _gslwrap.gsl_fft_complex_wavetable_factor_get
    if _newclass:factor = property(_gslwrap.gsl_fft_complex_wavetable_factor_get,_gslwrap.gsl_fft_complex_wavetable_factor_set)
    __swig_setmethods__["twiddle"] = _gslwrap.gsl_fft_complex_wavetable_twiddle_set
    __swig_getmethods__["twiddle"] = _gslwrap.gsl_fft_complex_wavetable_twiddle_get
    if _newclass:twiddle = property(_gslwrap.gsl_fft_complex_wavetable_twiddle_get,_gslwrap.gsl_fft_complex_wavetable_twiddle_set)
    __swig_setmethods__["trig"] = _gslwrap.gsl_fft_complex_wavetable_trig_set
    __swig_getmethods__["trig"] = _gslwrap.gsl_fft_complex_wavetable_trig_get
    if _newclass:trig = property(_gslwrap.gsl_fft_complex_wavetable_trig_get,_gslwrap.gsl_fft_complex_wavetable_trig_set)
    def __repr__(self):
        return "<C gsl_fft_complex_wavetable instance at %s>" % (self.this,)

class gsl_fft_complex_wavetablePtr(gsl_fft_complex_wavetable):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = gsl_fft_complex_wavetable
_gslwrap.gsl_fft_complex_wavetable_swigregister(gsl_fft_complex_wavetablePtr)

class gsl_fft_complex_workspace(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_fft_complex_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_fft_complex_workspace, name)
    def __init__(self,*args,**kwargs):
        self.this = apply(_gslwrap.new_gsl_fft_complex_workspace,args,kwargs)
        self.thisown = 1
    def __del__(self, destroy= _gslwrap.delete_gsl_fft_complex_workspace):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_setmethods__["n"] = _gslwrap.gsl_fft_complex_workspace_n_set
    __swig_getmethods__["n"] = _gslwrap.gsl_fft_complex_workspace_n_get
    if _newclass:n = property(_gslwrap.gsl_fft_complex_workspace_n_get,_gslwrap.gsl_fft_complex_workspace_n_set)
    __swig_setmethods__["scratch"] = _gslwrap.gsl_fft_complex_workspace_scratch_set
    __swig_getmethods__["scratch"] = _gslwrap.gsl_fft_complex_workspace_scratch_get
    if _newclass:scratch = property(_gslwrap.gsl_fft_complex_workspace_scratch_get,_gslwrap.gsl_fft_complex_workspace_scratch_set)
    def __repr__(self):
        return "<C gsl_fft_complex_workspace instance at %s>" % (self.this,)

class gsl_fft_complex_workspacePtr(gsl_fft_complex_workspace):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = gsl_fft_complex_workspace
_gslwrap.gsl_fft_complex_workspace_swigregister(gsl_fft_complex_workspacePtr)

gsl_fft_complex_wavetable_alloc = _gslwrap.gsl_fft_complex_wavetable_alloc

gsl_fft_complex_wavetable_free = _gslwrap.gsl_fft_complex_wavetable_free

gsl_fft_complex_workspace_alloc = _gslwrap.gsl_fft_complex_workspace_alloc

gsl_fft_complex_workspace_free = _gslwrap.gsl_fft_complex_workspace_free

gsl_fft_complex_memcpy = _gslwrap.gsl_fft_complex_memcpy

gsl_fft_complex_forward = _gslwrap.gsl_fft_complex_forward

gsl_fft_complex_backward = _gslwrap.gsl_fft_complex_backward

gsl_fft_complex_inverse = _gslwrap.gsl_fft_complex_inverse

gsl_fft_complex_transform = _gslwrap.gsl_fft_complex_transform

gsl_fft_real_radix2_transform = _gslwrap.gsl_fft_real_radix2_transform

class gsl_fft_real_wavetable(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_fft_real_wavetable, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_fft_real_wavetable, name)
    def __init__(self,*args,**kwargs):
        self.this = apply(_gslwrap.new_gsl_fft_real_wavetable,args,kwargs)
        self.thisown = 1
    def __del__(self, destroy= _gslwrap.delete_gsl_fft_real_wavetable):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_setmethods__["n"] = _gslwrap.gsl_fft_real_wavetable_n_set
    __swig_getmethods__["n"] = _gslwrap.gsl_fft_real_wavetable_n_get
    if _newclass:n = property(_gslwrap.gsl_fft_real_wavetable_n_get,_gslwrap.gsl_fft_real_wavetable_n_set)
    __swig_setmethods__["nf"] = _gslwrap.gsl_fft_real_wavetable_nf_set
    __swig_getmethods__["nf"] = _gslwrap.gsl_fft_real_wavetable_nf_get
    if _newclass:nf = property(_gslwrap.gsl_fft_real_wavetable_nf_get,_gslwrap.gsl_fft_real_wavetable_nf_set)
    __swig_setmethods__["factor"] = _gslwrap.gsl_fft_real_wavetable_factor_set
    __swig_getmethods__["factor"] = _gslwrap.gsl_fft_real_wavetable_factor_get
    if _newclass:factor = property(_gslwrap.gsl_fft_real_wavetable_factor_get,_gslwrap.gsl_fft_real_wavetable_factor_set)
    __swig_setmethods__["twiddle"] = _gslwrap.gsl_fft_real_wavetable_twiddle_set
    __swig_getmethods__["twiddle"] = _gslwrap.gsl_fft_real_wavetable_twiddle_get
    if _newclass:twiddle = property(_gslwrap.gsl_fft_real_wavetable_twiddle_get,_gslwrap.gsl_fft_real_wavetable_twiddle_set)
    __swig_setmethods__["trig"] = _gslwrap.gsl_fft_real_wavetable_trig_set
    __swig_getmethods__["trig"] = _gslwrap.gsl_fft_real_wavetable_trig_get
    if _newclass:trig = property(_gslwrap.gsl_fft_real_wavetable_trig_get,_gslwrap.gsl_fft_real_wavetable_trig_set)
    def __repr__(self):
        return "<C gsl_fft_real_wavetable instance at %s>" % (self.this,)

class gsl_fft_real_wavetablePtr(gsl_fft_real_wavetable):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = gsl_fft_real_wavetable
_gslwrap.gsl_fft_real_wavetable_swigregister(gsl_fft_real_wavetablePtr)

class gsl_fft_real_workspace(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_fft_real_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_fft_real_workspace, name)
    def __init__(self,*args,**kwargs):
        self.this = apply(_gslwrap.new_gsl_fft_real_workspace,args,kwargs)
        self.thisown = 1
    def __del__(self, destroy= _gslwrap.delete_gsl_fft_real_workspace):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_setmethods__["n"] = _gslwrap.gsl_fft_real_workspace_n_set
    __swig_getmethods__["n"] = _gslwrap.gsl_fft_real_workspace_n_get
    if _newclass:n = property(_gslwrap.gsl_fft_real_workspace_n_get,_gslwrap.gsl_fft_real_workspace_n_set)
    __swig_setmethods__["scratch"] = _gslwrap.gsl_fft_real_workspace_scratch_set
    __swig_getmethods__["scratch"] = _gslwrap.gsl_fft_real_workspace_scratch_get
    if _newclass:scratch = property(_gslwrap.gsl_fft_real_workspace_scratch_get,_gslwrap.gsl_fft_real_workspace_scratch_set)
    def __repr__(self):
        return "<C gsl_fft_real_workspace instance at %s>" % (self.this,)

class gsl_fft_real_workspacePtr(gsl_fft_real_workspace):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = gsl_fft_real_workspace
_gslwrap.gsl_fft_real_workspace_swigregister(gsl_fft_real_workspacePtr)

gsl_fft_real_wavetable_alloc = _gslwrap.gsl_fft_real_wavetable_alloc

gsl_fft_real_wavetable_free = _gslwrap.gsl_fft_real_wavetable_free

gsl_fft_real_workspace_alloc = _gslwrap.gsl_fft_real_workspace_alloc

gsl_fft_real_workspace_free = _gslwrap.gsl_fft_real_workspace_free

gsl_fft_real_transform = _gslwrap.gsl_fft_real_transform

gsl_fft_real_unpack = _gslwrap.gsl_fft_real_unpack

class Permutation(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Permutation, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Permutation, name)
    __swig_setmethods__["size"] = _gslwrap.Permutation_size_set
    __swig_getmethods__["size"] = _gslwrap.Permutation_size_get
    if _newclass:size = property(_gslwrap.Permutation_size_get,_gslwrap.Permutation_size_set)
    __swig_setmethods__["data"] = _gslwrap.Permutation_data_set
    __swig_getmethods__["data"] = _gslwrap.Permutation_data_get
    if _newclass:data = property(_gslwrap.Permutation_data_get,_gslwrap.Permutation_data_set)
    def __init__(self,*args,**kwargs):
        self.this = apply(_gslwrap.new_Permutation,args,kwargs)
        self.thisown = 1
    def __del__(self, destroy= _gslwrap.delete_Permutation):
        try:
            if self.thisown: destroy(self)
        except: pass
    def __getitem__(*args, **kwargs): return apply(_gslwrap.Permutation___getitem__,args, kwargs)
    def swap(*args, **kwargs): return apply(_gslwrap.Permutation_swap,args, kwargs)
    def __len__(*args, **kwargs): return apply(_gslwrap.Permutation___len__,args, kwargs)
    def valid(*args, **kwargs): return apply(_gslwrap.Permutation_valid,args, kwargs)
    def reverse(*args, **kwargs): return apply(_gslwrap.Permutation_reverse,args, kwargs)
    def next(*args, **kwargs): return apply(_gslwrap.Permutation_next,args, kwargs)
    def prev(*args, **kwargs): return apply(_gslwrap.Permutation_prev,args, kwargs)
    def __str__(*args, **kwargs): return apply(_gslwrap.Permutation___str__,args, kwargs)
    def __repr__(self):
        return "<C Permutation instance at %s>" % (self.this,)

class PermutationPtr(Permutation):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = Permutation
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
gsl_max = _gslwrap.gsl_max

gsl_min = _gslwrap.gsl_min

GSL_NEGZERO = _gslwrap.GSL_NEGZERO
gsl_log1p = _gslwrap.gsl_log1p

gsl_expm1 = _gslwrap.gsl_expm1

gsl_hypot = _gslwrap.gsl_hypot

gsl_acosh = _gslwrap.gsl_acosh

gsl_asinh = _gslwrap.gsl_asinh

gsl_atanh = _gslwrap.gsl_atanh

gsl_isnan = _gslwrap.gsl_isnan

gsl_isinf = _gslwrap.gsl_isinf

gsl_finite = _gslwrap.gsl_finite

gsl_nan = _gslwrap.gsl_nan

gsl_posinf = _gslwrap.gsl_posinf

gsl_neginf = _gslwrap.gsl_neginf

gsl_fdiv = _gslwrap.gsl_fdiv

gsl_coerce_double = _gslwrap.gsl_coerce_double

gsl_coerce_float = _gslwrap.gsl_coerce_float

gsl_coerce_long_double = _gslwrap.gsl_coerce_long_double

gsl_ldexp = _gslwrap.gsl_ldexp

gsl_frexp = _gslwrap.gsl_frexp

gsl_fcmp = _gslwrap.gsl_fcmp

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

gsl_blas_dsdot = _gslwrap.gsl_blas_dsdot

gsl_blas_sdot = _gslwrap.gsl_blas_sdot

gsl_blas_ddot = _gslwrap.gsl_blas_ddot

gsl_blas_cdotu = _gslwrap.gsl_blas_cdotu

gsl_blas_cdotc = _gslwrap.gsl_blas_cdotc

gsl_blas_zdotu = _gslwrap.gsl_blas_zdotu

gsl_blas_zdotc = _gslwrap.gsl_blas_zdotc

gsl_blas_snrm2 = _gslwrap.gsl_blas_snrm2

gsl_blas_sasum = _gslwrap.gsl_blas_sasum

gsl_blas_dnrm2 = _gslwrap.gsl_blas_dnrm2

gsl_blas_dasum = _gslwrap.gsl_blas_dasum

gsl_blas_scnrm2 = _gslwrap.gsl_blas_scnrm2

gsl_blas_scasum = _gslwrap.gsl_blas_scasum

gsl_blas_dznrm2 = _gslwrap.gsl_blas_dznrm2

gsl_blas_dzasum = _gslwrap.gsl_blas_dzasum

gsl_blas_isamax = _gslwrap.gsl_blas_isamax

gsl_blas_idamax = _gslwrap.gsl_blas_idamax

gsl_blas_icamax = _gslwrap.gsl_blas_icamax

gsl_blas_izamax = _gslwrap.gsl_blas_izamax

gsl_blas_sswap = _gslwrap.gsl_blas_sswap

gsl_blas_scopy = _gslwrap.gsl_blas_scopy

gsl_blas_saxpy = _gslwrap.gsl_blas_saxpy

gsl_blas_dswap = _gslwrap.gsl_blas_dswap

gsl_blas_dcopy = _gslwrap.gsl_blas_dcopy

gsl_blas_daxpy = _gslwrap.gsl_blas_daxpy

gsl_blas_cswap = _gslwrap.gsl_blas_cswap

gsl_blas_ccopy = _gslwrap.gsl_blas_ccopy

gsl_blas_caxpy = _gslwrap.gsl_blas_caxpy

gsl_blas_zswap = _gslwrap.gsl_blas_zswap

gsl_blas_zcopy = _gslwrap.gsl_blas_zcopy

gsl_blas_zaxpy = _gslwrap.gsl_blas_zaxpy

gsl_blas_srotg = _gslwrap.gsl_blas_srotg

gsl_blas_srotmg = _gslwrap.gsl_blas_srotmg

gsl_blas_srot = _gslwrap.gsl_blas_srot

gsl_blas_srotm = _gslwrap.gsl_blas_srotm

gsl_blas_drotg = _gslwrap.gsl_blas_drotg

gsl_blas_drotmg = _gslwrap.gsl_blas_drotmg

gsl_blas_drot = _gslwrap.gsl_blas_drot

gsl_blas_drotm = _gslwrap.gsl_blas_drotm

gsl_blas_sscal = _gslwrap.gsl_blas_sscal

gsl_blas_dscal = _gslwrap.gsl_blas_dscal

gsl_blas_cscal = _gslwrap.gsl_blas_cscal

gsl_blas_zscal = _gslwrap.gsl_blas_zscal

gsl_blas_csscal = _gslwrap.gsl_blas_csscal

gsl_blas_zdscal = _gslwrap.gsl_blas_zdscal

gsl_blas_sgemv = _gslwrap.gsl_blas_sgemv

gsl_blas_strmv = _gslwrap.gsl_blas_strmv

gsl_blas_strsv = _gslwrap.gsl_blas_strsv

gsl_blas_dgemv = _gslwrap.gsl_blas_dgemv

gsl_blas_dtrmv = _gslwrap.gsl_blas_dtrmv

gsl_blas_dtrsv = _gslwrap.gsl_blas_dtrsv

gsl_blas_cgemv = _gslwrap.gsl_blas_cgemv

gsl_blas_ctrmv = _gslwrap.gsl_blas_ctrmv

gsl_blas_ctrsv = _gslwrap.gsl_blas_ctrsv

gsl_blas_zgemv = _gslwrap.gsl_blas_zgemv

gsl_blas_ztrmv = _gslwrap.gsl_blas_ztrmv

gsl_blas_ztrsv = _gslwrap.gsl_blas_ztrsv

gsl_blas_ssymv = _gslwrap.gsl_blas_ssymv

gsl_blas_sger = _gslwrap.gsl_blas_sger

gsl_blas_ssyr = _gslwrap.gsl_blas_ssyr

gsl_blas_ssyr2 = _gslwrap.gsl_blas_ssyr2

gsl_blas_dsymv = _gslwrap.gsl_blas_dsymv

gsl_blas_dger = _gslwrap.gsl_blas_dger

gsl_blas_dsyr = _gslwrap.gsl_blas_dsyr

gsl_blas_dsyr2 = _gslwrap.gsl_blas_dsyr2

gsl_blas_chemv = _gslwrap.gsl_blas_chemv

gsl_blas_cgeru = _gslwrap.gsl_blas_cgeru

gsl_blas_cgerc = _gslwrap.gsl_blas_cgerc

gsl_blas_cher = _gslwrap.gsl_blas_cher

gsl_blas_cher2 = _gslwrap.gsl_blas_cher2

gsl_blas_zhemv = _gslwrap.gsl_blas_zhemv

gsl_blas_zgeru = _gslwrap.gsl_blas_zgeru

gsl_blas_zgerc = _gslwrap.gsl_blas_zgerc

gsl_blas_zher = _gslwrap.gsl_blas_zher

gsl_blas_zher2 = _gslwrap.gsl_blas_zher2

gsl_blas_sgemm = _gslwrap.gsl_blas_sgemm

gsl_blas_ssymm = _gslwrap.gsl_blas_ssymm

gsl_blas_ssyrk = _gslwrap.gsl_blas_ssyrk

gsl_blas_ssyr2k = _gslwrap.gsl_blas_ssyr2k

gsl_blas_strmm = _gslwrap.gsl_blas_strmm

gsl_blas_strsm = _gslwrap.gsl_blas_strsm

gsl_blas_dgemm = _gslwrap.gsl_blas_dgemm

gsl_blas_dsymm = _gslwrap.gsl_blas_dsymm

gsl_blas_dsyrk = _gslwrap.gsl_blas_dsyrk

gsl_blas_dsyr2k = _gslwrap.gsl_blas_dsyr2k

gsl_blas_dtrmm = _gslwrap.gsl_blas_dtrmm

gsl_blas_dtrsm = _gslwrap.gsl_blas_dtrsm

gsl_blas_cgemm = _gslwrap.gsl_blas_cgemm

gsl_blas_csymm = _gslwrap.gsl_blas_csymm

gsl_blas_csyrk = _gslwrap.gsl_blas_csyrk

gsl_blas_csyr2k = _gslwrap.gsl_blas_csyr2k

gsl_blas_ctrmm = _gslwrap.gsl_blas_ctrmm

gsl_blas_ctrsm = _gslwrap.gsl_blas_ctrsm

gsl_blas_zgemm = _gslwrap.gsl_blas_zgemm

gsl_blas_zsymm = _gslwrap.gsl_blas_zsymm

gsl_blas_zsyrk = _gslwrap.gsl_blas_zsyrk

gsl_blas_zsyr2k = _gslwrap.gsl_blas_zsyr2k

gsl_blas_ztrmm = _gslwrap.gsl_blas_ztrmm

gsl_blas_ztrsm = _gslwrap.gsl_blas_ztrsm

gsl_blas_chemm = _gslwrap.gsl_blas_chemm

gsl_blas_cherk = _gslwrap.gsl_blas_cherk

gsl_blas_cher2k = _gslwrap.gsl_blas_cher2k

gsl_blas_zhemm = _gslwrap.gsl_blas_zhemm

gsl_blas_zherk = _gslwrap.gsl_blas_zherk

gsl_blas_zher2k = _gslwrap.gsl_blas_zher2k

class gsl_eigen_symm_workspace(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_symm_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_symm_workspace, name)
    def __init__(self,*args,**kwargs):
        self.this = apply(_gslwrap.new_gsl_eigen_symm_workspace,args,kwargs)
        self.thisown = 1
    def __del__(self, destroy= _gslwrap.delete_gsl_eigen_symm_workspace):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_setmethods__["size"] = _gslwrap.gsl_eigen_symm_workspace_size_set
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_symm_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_symm_workspace_size_get,_gslwrap.gsl_eigen_symm_workspace_size_set)
    __swig_setmethods__["d"] = _gslwrap.gsl_eigen_symm_workspace_d_set
    __swig_getmethods__["d"] = _gslwrap.gsl_eigen_symm_workspace_d_get
    if _newclass:d = property(_gslwrap.gsl_eigen_symm_workspace_d_get,_gslwrap.gsl_eigen_symm_workspace_d_set)
    __swig_setmethods__["sd"] = _gslwrap.gsl_eigen_symm_workspace_sd_set
    __swig_getmethods__["sd"] = _gslwrap.gsl_eigen_symm_workspace_sd_get
    if _newclass:sd = property(_gslwrap.gsl_eigen_symm_workspace_sd_get,_gslwrap.gsl_eigen_symm_workspace_sd_set)
    def __repr__(self):
        return "<C gsl_eigen_symm_workspace instance at %s>" % (self.this,)

class gsl_eigen_symm_workspacePtr(gsl_eigen_symm_workspace):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = gsl_eigen_symm_workspace
_gslwrap.gsl_eigen_symm_workspace_swigregister(gsl_eigen_symm_workspacePtr)
cvar = _gslwrap.cvar

gsl_eigen_symm_alloc = _gslwrap.gsl_eigen_symm_alloc

gsl_eigen_symm_free = _gslwrap.gsl_eigen_symm_free

gsl_eigen_symm = _gslwrap.gsl_eigen_symm

class gsl_eigen_symmv_workspace(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_symmv_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_symmv_workspace, name)
    def __init__(self,*args,**kwargs):
        self.this = apply(_gslwrap.new_gsl_eigen_symmv_workspace,args,kwargs)
        self.thisown = 1
    def __del__(self, destroy= _gslwrap.delete_gsl_eigen_symmv_workspace):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_setmethods__["size"] = _gslwrap.gsl_eigen_symmv_workspace_size_set
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_symmv_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_symmv_workspace_size_get,_gslwrap.gsl_eigen_symmv_workspace_size_set)
    __swig_setmethods__["d"] = _gslwrap.gsl_eigen_symmv_workspace_d_set
    __swig_getmethods__["d"] = _gslwrap.gsl_eigen_symmv_workspace_d_get
    if _newclass:d = property(_gslwrap.gsl_eigen_symmv_workspace_d_get,_gslwrap.gsl_eigen_symmv_workspace_d_set)
    __swig_setmethods__["sd"] = _gslwrap.gsl_eigen_symmv_workspace_sd_set
    __swig_getmethods__["sd"] = _gslwrap.gsl_eigen_symmv_workspace_sd_get
    if _newclass:sd = property(_gslwrap.gsl_eigen_symmv_workspace_sd_get,_gslwrap.gsl_eigen_symmv_workspace_sd_set)
    __swig_setmethods__["gc"] = _gslwrap.gsl_eigen_symmv_workspace_gc_set
    __swig_getmethods__["gc"] = _gslwrap.gsl_eigen_symmv_workspace_gc_get
    if _newclass:gc = property(_gslwrap.gsl_eigen_symmv_workspace_gc_get,_gslwrap.gsl_eigen_symmv_workspace_gc_set)
    __swig_setmethods__["gs"] = _gslwrap.gsl_eigen_symmv_workspace_gs_set
    __swig_getmethods__["gs"] = _gslwrap.gsl_eigen_symmv_workspace_gs_get
    if _newclass:gs = property(_gslwrap.gsl_eigen_symmv_workspace_gs_get,_gslwrap.gsl_eigen_symmv_workspace_gs_set)
    def __repr__(self):
        return "<C gsl_eigen_symmv_workspace instance at %s>" % (self.this,)

class gsl_eigen_symmv_workspacePtr(gsl_eigen_symmv_workspace):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = gsl_eigen_symmv_workspace
_gslwrap.gsl_eigen_symmv_workspace_swigregister(gsl_eigen_symmv_workspacePtr)

gsl_eigen_symmv_alloc = _gslwrap.gsl_eigen_symmv_alloc

gsl_eigen_symmv_free = _gslwrap.gsl_eigen_symmv_free

gsl_eigen_symmv = _gslwrap.gsl_eigen_symmv

class gsl_eigen_herm_workspace(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_herm_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_herm_workspace, name)
    def __init__(self,*args,**kwargs):
        self.this = apply(_gslwrap.new_gsl_eigen_herm_workspace,args,kwargs)
        self.thisown = 1
    def __del__(self, destroy= _gslwrap.delete_gsl_eigen_herm_workspace):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_setmethods__["size"] = _gslwrap.gsl_eigen_herm_workspace_size_set
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_herm_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_herm_workspace_size_get,_gslwrap.gsl_eigen_herm_workspace_size_set)
    __swig_setmethods__["d"] = _gslwrap.gsl_eigen_herm_workspace_d_set
    __swig_getmethods__["d"] = _gslwrap.gsl_eigen_herm_workspace_d_get
    if _newclass:d = property(_gslwrap.gsl_eigen_herm_workspace_d_get,_gslwrap.gsl_eigen_herm_workspace_d_set)
    __swig_setmethods__["sd"] = _gslwrap.gsl_eigen_herm_workspace_sd_set
    __swig_getmethods__["sd"] = _gslwrap.gsl_eigen_herm_workspace_sd_get
    if _newclass:sd = property(_gslwrap.gsl_eigen_herm_workspace_sd_get,_gslwrap.gsl_eigen_herm_workspace_sd_set)
    __swig_setmethods__["tau"] = _gslwrap.gsl_eigen_herm_workspace_tau_set
    __swig_getmethods__["tau"] = _gslwrap.gsl_eigen_herm_workspace_tau_get
    if _newclass:tau = property(_gslwrap.gsl_eigen_herm_workspace_tau_get,_gslwrap.gsl_eigen_herm_workspace_tau_set)
    def __repr__(self):
        return "<C gsl_eigen_herm_workspace instance at %s>" % (self.this,)

class gsl_eigen_herm_workspacePtr(gsl_eigen_herm_workspace):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = gsl_eigen_herm_workspace
_gslwrap.gsl_eigen_herm_workspace_swigregister(gsl_eigen_herm_workspacePtr)

gsl_eigen_herm_alloc = _gslwrap.gsl_eigen_herm_alloc

gsl_eigen_herm_free = _gslwrap.gsl_eigen_herm_free

gsl_eigen_herm = _gslwrap.gsl_eigen_herm

class gsl_eigen_hermv_workspace(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, gsl_eigen_hermv_workspace, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, gsl_eigen_hermv_workspace, name)
    def __init__(self,*args,**kwargs):
        self.this = apply(_gslwrap.new_gsl_eigen_hermv_workspace,args,kwargs)
        self.thisown = 1
    def __del__(self, destroy= _gslwrap.delete_gsl_eigen_hermv_workspace):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_setmethods__["size"] = _gslwrap.gsl_eigen_hermv_workspace_size_set
    __swig_getmethods__["size"] = _gslwrap.gsl_eigen_hermv_workspace_size_get
    if _newclass:size = property(_gslwrap.gsl_eigen_hermv_workspace_size_get,_gslwrap.gsl_eigen_hermv_workspace_size_set)
    __swig_setmethods__["d"] = _gslwrap.gsl_eigen_hermv_workspace_d_set
    __swig_getmethods__["d"] = _gslwrap.gsl_eigen_hermv_workspace_d_get
    if _newclass:d = property(_gslwrap.gsl_eigen_hermv_workspace_d_get,_gslwrap.gsl_eigen_hermv_workspace_d_set)
    __swig_setmethods__["sd"] = _gslwrap.gsl_eigen_hermv_workspace_sd_set
    __swig_getmethods__["sd"] = _gslwrap.gsl_eigen_hermv_workspace_sd_get
    if _newclass:sd = property(_gslwrap.gsl_eigen_hermv_workspace_sd_get,_gslwrap.gsl_eigen_hermv_workspace_sd_set)
    __swig_setmethods__["tau"] = _gslwrap.gsl_eigen_hermv_workspace_tau_set
    __swig_getmethods__["tau"] = _gslwrap.gsl_eigen_hermv_workspace_tau_get
    if _newclass:tau = property(_gslwrap.gsl_eigen_hermv_workspace_tau_get,_gslwrap.gsl_eigen_hermv_workspace_tau_set)
    __swig_setmethods__["gc"] = _gslwrap.gsl_eigen_hermv_workspace_gc_set
    __swig_getmethods__["gc"] = _gslwrap.gsl_eigen_hermv_workspace_gc_get
    if _newclass:gc = property(_gslwrap.gsl_eigen_hermv_workspace_gc_get,_gslwrap.gsl_eigen_hermv_workspace_gc_set)
    __swig_setmethods__["gs"] = _gslwrap.gsl_eigen_hermv_workspace_gs_set
    __swig_getmethods__["gs"] = _gslwrap.gsl_eigen_hermv_workspace_gs_get
    if _newclass:gs = property(_gslwrap.gsl_eigen_hermv_workspace_gs_get,_gslwrap.gsl_eigen_hermv_workspace_gs_set)
    def __repr__(self):
        return "<C gsl_eigen_hermv_workspace instance at %s>" % (self.this,)

class gsl_eigen_hermv_workspacePtr(gsl_eigen_hermv_workspace):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = gsl_eigen_hermv_workspace
_gslwrap.gsl_eigen_hermv_workspace_swigregister(gsl_eigen_hermv_workspacePtr)

gsl_eigen_hermv_alloc = _gslwrap.gsl_eigen_hermv_alloc

gsl_eigen_hermv_free = _gslwrap.gsl_eigen_hermv_free

gsl_eigen_hermv = _gslwrap.gsl_eigen_hermv

GSL_EIGEN_SORT_VAL_ASC = _gslwrap.GSL_EIGEN_SORT_VAL_ASC
GSL_EIGEN_SORT_VAL_DESC = _gslwrap.GSL_EIGEN_SORT_VAL_DESC
GSL_EIGEN_SORT_ABS_ASC = _gslwrap.GSL_EIGEN_SORT_ABS_ASC
GSL_EIGEN_SORT_ABS_DESC = _gslwrap.GSL_EIGEN_SORT_ABS_DESC
gsl_eigen_symmv_sort = _gslwrap.gsl_eigen_symmv_sort

gsl_eigen_hermv_sort = _gslwrap.gsl_eigen_hermv_sort

gsl_eigen_jacobi = _gslwrap.gsl_eigen_jacobi

gsl_eigen_invert_jacobi = _gslwrap.gsl_eigen_invert_jacobi


