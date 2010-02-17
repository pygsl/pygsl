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
from pygsl import spline, errors
from pygsl import _numobj as numx

print "#m=0,S=2"
n = 10
a = numx.arange(n)
x = a + 0.5 * numx.sin(a)
y = a + numx.cos(a**2)
for i in a:
    print x[i], y[i]

print "#m=1,S=0"
# Generation of the spline object ...  Acceleration is handled internally
myspline = spline.cspline(n)
myspline = spline.linear(n)
acc = myspline._object.get_accel_object()
#print "Accel object", dir(acc)
# initalise with the vector of the independent and the dependent
myspline.init(x,y)
x1 = numx.arange(n * 20) / 20.
for xi in x1:
    #print xi, myspline.eval(xi)
    pass

# Faster: eval_vector
myspline.eval_vector(x1)
# Faster: eval_vector but use gsl_spline_eval_e to get errors back
# This should fail with gsl_DomainError
xtest = 10.5
try:
    myspline.eval_e_vector((xtest,))
except errors.gsl_DomainError, msg:
    print "Failed with gsl_DomainError as expected!"
    
try:
    myspline.eval_e_vector(x1)
except errors.gsl_DomainError, msg:
    print "Failed with gsl_DomainError as expected!"
