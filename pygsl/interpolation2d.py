"""
Wrapper for the 2D interpolation

References to the arrays are kept within the interp2d (swig) class next to the
accelerator objects.
"""
from . import interpolation2d_wrap
from . import errors
_m = interpolation2d_wrap
interp2d  = _m.interp2d
_bilinear = _m.gsl_interp2d_bilinear
_bicubic  = _m.gsl_interp2d_bicubic

class bilinear(interp2d):
    def __init__(self, x_size, y_size):
        interp2d.__init__(self, _bilinear, x_size, y_size)

class bicubic(interp2d):
    def __init__(self, x_size, y_size):
        interp2d.__init__(self, _bicubic, x_size, y_size)

