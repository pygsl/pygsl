#!/usr/bin/env python
# Author : Pierre Schnizer
"""
The python equivalent of the C example found in the GSL Reference document.

The function run_fsolver shows how to use the fdfsolvers (e.g. lsmder).
"""

import random
import pygsl
from pygsl import multifit_nlin, errno
from pygsl import _numobj as numx
import copy


exp = numx.exp

def testfunc(t, A = 1., lambda_ = .1, b=.5):
        return  A * exp(- lambda_ * t) + b

def exp_f(x, params):
    A       = x[0]
    lambda_ = x[1]
    b       = x[2]
    
    t       = params[0]
    yi      = params[1]
    sigma   = params[2]
    
    Yi = testfunc(t, A, lambda_, b)
    f = (Yi -yi) / sigma
    return f

def exp_df(x, params):
    A       = x[0]
    lambda_ = x[1]
    b       = x[2]
    
    t       = params[0]
    yi      = params[1]
    sigma   = params[2]

    e = exp(-lambda_ * t)
    e_s = e/sigma
    df = numx.array((e_s, -t * A * e_s, 1/sigma))
    df = numx.transpose(df)
    return df

def exp_fdf(x, params):
    f = exp_f(x, params)
    df = exp_df(x, params)
    return f, df

    
def run_fdfsolver():
    A       = 1.
    lambda_ = .1
    b       = .5

    n = 40
    p = 3

    t = numx.arange(n);
    y = testfunc(t, A, lambda_, b)
    sigma = numx.ones(n) * 0.1
    data = numx.array((t,y,sigma),)
    mysys = multifit_nlin.gsl_multifit_function_fdf(exp_f, exp_df, exp_fdf,
						       data, n,p)
    solver = multifit_nlin.lmsder(mysys, n, p)    
    #solver = multifit_nlin.lmder(mysys, n, p)


    x = numx.array((1.0, 0.0, 0.0))
    solver.set(x)
    print "# Testing solver ", solver.name() 
    print "# %5s %9s %9s  %9s  %10s" % ("iter", "A", "lambda", "b", "|f(x)|")
    for iter in range(20):	    
        status = solver.iterate()
	x  = solver.getx()
	dx = solver.getdx()
	f  = solver.getf()
	J  = solver.getJ()
	tdx = multifit_nlin.gradient(J, f)
	status = multifit_nlin.test_delta(dx, x, 1e-8, 1e-8)
	fn = numx.sqrt(numx.sum(f*f))
	if status == errno.GSL_SUCCESS:
		print "# Convereged :"
	if status == errno.GSL_SUCCESS:
                break
        print "  %5d % .7f % .7f  % .7f  % .7f" %(iter, x[0], x[1], x[2], fn)
    else:
	raise ValueError, "Number of Iterations exceeded!"

    J = solver.getJ()
    covar =  multifit_nlin.covar(solver.getJ(), 0.0)
    print "# A      = % .5f +/- % .5f" % (x[0], covar[0,0])
    print "# lambda = % .5f +/- % .5f" % (x[1], covar[1,1])
    print "# b      = % .5f +/- % .5f" % (x[2], covar[2,2])



if __name__ == '__main__':
    run_fdfsolver()
