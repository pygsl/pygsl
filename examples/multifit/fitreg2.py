"""
Source: doc/example/figreg.c
"""
from __future__ import print_function, division

import pygsl
from pygsl import rng
from pygsl import multifit2 as multifit
import numpy as np

def hilbert(i, j):
    return 1.0 / (i + j + 1.0)

def run():

    n = 10
    p = 8
    # hilbert matrix 
    X = np.fromfunction(hilbert, (n, p), dtype=np.float_)

    assert(n%2 == 0)
    y = (1, -1) * (n//2)
    y = np.array(y, dtype=np.float_)

    npoints = 200


    w = multifit.multifit(n, p)
    w.svd(X)
    rcond = w.rcond()
    print("marix condition number %e" %(1.0/rcond,) )

    c, rnorm, snorm = w.solve(0.0, X, y)
    chisq = rnorm**2

    print("=== Unregularized fit ===")
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
    print("residual norm = %g" %(rnorm,));
    print("solution norm = %g" %(snorm,));
    print("chisq/dof = %g" %( chisq / (n - p),));

    # GCV
    G, lambda_gcv, G_gcv = w.gcv(y, reg_param)
    c_gcv, rnorm, snorm = w.solve(lambda_gcv, X, y)
    chisq = rnorm**2 + (lambda_gcv * snorm)**2
    print("\n=== Regularized fit (GCV) ===")
    print("optimal lambda: %g" %(lambda_gcv,))
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
    ax.axis([2, 4, 1e-1, 2e9])
    #ax.axis([20, 40, 1e-1, 2e9])

    ax = plt.subplot(122)
    ax.clear()
    ax.loglog(reg_param, G,  '.-')
    ax.loglog((lambda_gcv,), (G_gcv,), 'ok')
    ax.axis([1e-10, 1e1, 1e-1, 1e0])
    plt.show()

if __name__ == '__main__':    
    tmp = run()
    plot(*tmp)
