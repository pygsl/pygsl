#!/usr/bin/env python
"""
The example from the GSL Reference Document

"""
import sys
sys.stdout = sys.stderr
import Numeric
import pygsl
pygsl.set_debug_level(0)
import pygsl.testing.multimin as multimin

def f(x, params):
    a = params[0]
    b = params[1]

    tmp =   10 * (x[0] - a)**2 + 20 * (x[1] - b)**2 + 30
    #print x, tmp
    return  tmp

def df(x, params):
    a = params[0]
    b = params[1]
    tmp = (20 * (x[0] - a), 40 * (x[1] - b))
    #print x, tmp
    return tmp

def fdf(x, params):
    myf = f(x, params)
    mydf = df(x, params)
    return myf, mydf

m = multimin.nmsimplex(2)
#m = multimin.conjugate_fr(2)
#m = multimin.conjugate_pr(2)
#m = multimin.steepest_descent(2)
#m = multimin.vector_bfgs(2)

par   = [1.0, 2.0]
x     = [7., 5.]
steps = [1, 1.]

print m.type()
if m.type() == 'F-MultiMinimizer':
    #m.set(f, x, par, steps)
    # You can also specify them as keyword arguments.
    print "par %x" % (id(par),)
    m.set(f=f, x0=x, args=par, steps=steps)
else:    
    m.set(f, df, fdf, x,  par, 0.01, 1e-4)
    # Step defaults to 0.01 and tolerance to 1e-4
    #m.set(f, df, fdf, x, par)
    # You can also specify them as keyword arguments.
    #m.set(f=f, df=df, fdf=fdf, x0=x, args=par)

fmt = "%5d %.5f %.5f %10.5f"

run = 1
print "Testing minimizer ", m.name()
for i in range(200):   
    m.iterate()
    if m.type() == 'F-MultiMinimizer':
        flag =  m.test_size(1e-3)
    else:
        flag =  m.test_gradient(1e-3)
    if flag == 0:
        print "Found minimum!"
    x = m.x()
    r = m.minimum()
    print fmt % (i, x[0], x[1], r)
    if flag == 0:
        break
    
else:
    raise ValueError, "Iteration exceeded! "


print "Summary:"
print "Iterator        ", m.name()
print "Solution        ", m.x()
print "value at minimum", m.minimum()
if m.type() == 'F-MultiMinimizer':
    print "Size            ", m.size() 
else:
    print "Gradient        ", m.gradient()
    print "dx              ", m.dx()
    m.restart()
