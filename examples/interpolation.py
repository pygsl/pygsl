#!/usr/bin/env python
"""
The pythonic version of the example program as given in the GSL Reference
Document.

The output of this script is designed to be displayed by the GNU plotutils
'graph' program. e.g

     $ python ./interpolation.py > interp.dat
     $ graph -T ps < interp.dat > interp.ps

The result shows a smooth interpolation of the original points.  The
interpolation method can changed simply by varing spline. .

"""
import Numeric
from pygsl import spline

print "#m=0,S=2"
n = 10
a = Numeric.arange(n)
x = a + 0.5 * Numeric.sin(a)
y = a + Numeric.cos(a**2)
for i in a:
    print x[i], y[i]

print "#m=1,S=0"
# Acceleration is handled internally
myspline = spline.cspline(n)
myspline.init(x,y)
myspline.eval_e(1)
myspline.eval_deriv2_e(1)
x1 = Numeric.arange(n * 20) / 20.
for xi in x1:
    print xi, myspline.eval(xi)
