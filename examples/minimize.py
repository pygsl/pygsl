#!/usr/bin/env python
# Author : Pierre Schnizer 
"""
The python equivalent of the C example found in the GSL Reference document.

The function run_fsolver shows how to use the fsolvers (e.g. brent).
"""

from pygsl import minimize, errno
from pygsl import _numobj as numx


def fn1(x, params):
    return numx.cos(x) + 1.0

def run_fsolver():
    mysys = minimize.gsl_function(fn1, None)
    m = 2.0
    a = 0.0
    b = 6.0
    m_expected = numx.pi

    
    minimizer = minimize.brent(mysys)
    #minimizer = minimize.goldensection(mysys)
    minimizer.set(m, a, b)
    
    print "# Using  minimizer ", minimizer.name()
    print "# %5s [%9s %9s]  %9s  %10s %9s" % ("iter", "upper", "lower", "min",
                                              "err", "err(est)")
    for iter in range(100):
        status = minimizer.iterate()
        a      = minimizer.x_lower()
        b      = minimizer.x_upper()
        m      = minimizer.minimum()
        status = minimize.test_interval(a, b, 0.001, 0)
        if status == errno.GSL_SUCCESS:
            print "# Converged: "
        print "  %5d [%.7f %.7f]  %.7f + % .6f % .6f" %(iter, a, b, m,
                                                      m -m_expected, b - a)
        if status == errno.GSL_SUCCESS:
            break
    else:
        raise ValueError, "Number of Iterations exceeded!"
        



if __name__ == '__main__':
    run_fsolver()
