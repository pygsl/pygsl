"""
Simple Mathematical functions

fcmp(a, b, epsilon) -> -1, 0, 1
"""
import pygsl._gslwrap
log1p = pygsl._gslwrap.gsl_log1p
expm1 = pygsl._gslwrap.gsl_expm1
hypot = pygsl._gslwrap.gsl_hypot
acosh = pygsl._gslwrap.gsl_acosh
asinh = pygsl._gslwrap.gsl_asinh
atanh = pygsl._gslwrap.gsl_atanh
ldexp = pygsl._gslwrap.gsl_ldexp
frexp = pygsl._gslwrap.gsl_frexp
fcmp  = pygsl._gslwrap.gsl_fcmp
