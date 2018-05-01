#!/usr/bin/env python
"""Regularisation fit example 

Source: doc/example/figreg.c
"""
from __future__ import print_function, division

import pygsl
from pygsl import rng
from pygsl import multifit2 as multifit
import numpy as np

    
def run(gsl_example = True):
    n = 1000
    p = 2

    # Input data
    #rng.env_setup()
    r = rng.rng()

    # Initalising the data ... the call sequence to the random generator
    # influences the result.
    # Well a really ill conditioned example
    if gsl_example:
        # Initalise it GSL' style. The random generator is called
        # sequentially for each vector. 
        X = np.zeros((n,p), np.float_)
        y = np.zeros((n,), np.float_)
        for i in range(n):
            ui = 5 * r.gaussian(1.0)
            vi = ui + r.gaussian(0.001)
            yi = ui + vi + r.gaussian(1.0)
            X[i,0] = ui
            X[i,1] = vi
            y[i] = yi
    else:
        # That's a more pythonic style. Call it sequentially for one vector
        # and then for the next. The results are then slightly different from
        # the example. But regularisation gives suprisiningly good results
        u = 5 * r.gaussian(1.0, n)
        v = u + r.gaussian(0.001, n)
        y = u + v + r.gaussian(1.0, n)
        X = np.array((u,v), order="F").transpose()

    # Fit
    w = multifit.multifit(n, p)
    w.svd(X)
    rcond = w.rcond()
    print("marix condition number %e" %(1.0/rcond,) )

    c, rnorm, snorm = w.solve(0.0, X, y)
    chisq = rnorm**2

    print("=== Unregularized fit ===")
    print("best fit: y = %g u + %g v" % tuple(c))
    print("residual norm = %g" %(rnorm,));
    print("solution norm = %g" %(snorm,));
    print("chisq/dof = %g" %( chisq / (n - p),));


    # Reqularisation lcurve
    n_points = 200
    reg_param, rho, eta = w.lcurve(y, n_points)
    reg_idx = multifit.lcorner(rho, eta)
    lambda_l = reg_param[reg_idx]

    c_lcurve, rnorm, snorm = w.solve(lambda_l, X, y)
    chisq = rnorm**2 + (lambda_l * snorm)**2
    print("\n=== Regularized fit (L-curve) ===")
    print("optimal lambda: %g" %(lambda_l,))
    print("best fit: y = %g u + %g v" % tuple(c_lcurve))
    print("residual norm = %g" %(rnorm,));
    print("solution norm = %g" %(snorm,));
    print("chisq/dof = %g" %( chisq / (n - p),));

    # GCV
    G, lambda_gcv, G_gcv = w.gcv(y, reg_param)
    c_gcv, rnorm, snorm = w.solve(lambda_gcv, X, y)
    chisq = rnorm**2 + (lambda_gcv * snorm)**2
    print("\n=== Regularized fit (GCV) ===")
    print("optimal lambda: %g" %(lambda_gcv,))
    print("best fit: y = %g u + %g v" % tuple(c_gcv))
    print("residual norm = %g" %(rnorm,));
    print("solution norm = %g" %(snorm,));
    print("chisq/dof = %g" %( chisq / (n - p),));

    return reg_param, rho, eta, G, reg_idx, lambda_gcv, G_gcv
    pass

def plot(reg_param, rho, eta, G, reg_idx, lambda_gcv, G_gcv):
    import matplotlib.pyplot as plt

    #plt.plot(reg_param)
    plt.figure(1, [16,6])
    ax = plt.subplot(121)
    ax.clear()
    ax.loglog(rho, eta, '.-')
    ax.loglog((rho[reg_idx],), (eta[reg_idx],), 'ok')
    ax.axis([1e1, 1e3, 1e-1, 1e2])

    ax = plt.subplot(122)
    ax.clear()
    ax.loglog(reg_param, G,  '.-')
    ax.loglog((lambda_gcv,), (G_gcv,), 'ok')
    ax.axis([1e-2, 1e3, 1e-4, 1e-1])
    plt.show()

if __name__ == '__main__':    
    tmp = run(gsl_example = True)
    plot(*tmp)
