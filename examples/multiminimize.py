#!/usr/bin/env python
"""
The pythonic version of the example found in the GSL reference document.
"""

from pygsl import _numobj as numx
from pygsl import multiminimize, errno

def my_f(v, params):
    x = v[0]
    y = v[1]
    
    dp = params
    t1  = (x - dp[0])
    t2  = (y - dp[1])
    f = 10.0 * t1 * t1 + 20.0 * t2 * t2 + 30.0
    #print "\t\tx,y ->f", x,y, f
    return f 

def my_df(v, params):
    x = v[0]
    y = v[1]
    df = numx.zeros(v.shape, ) * 1.
    dp = params
    df[0] = 20. * (x - dp[0])
    df[1] = 40. * (y - dp[1])
    #print "\t\tx,y ->df", x,y, df
    return df

def my_fdf(v, params):
    #print "\t\t-- fdf -- "
    f = my_f(v, params)
    df = my_df(v,params)
    #print "\t\t-- fdf -- "
    return f, df

def f_solver():
    tmp = numx.array((1., 2.), )
    sys = multiminimize.gsl_multimin_function(my_f, tmp, 2)
    solver = multiminimize.nmsimplex(sys, 2)

    start_point = numx.array((5., 7.), )
    initial_steps = numx.array((0.1, 0.1), )
    solver.set(start_point, initial_steps)

    print "Using solver ", solver.name() 
    for i in range(100):
        status = solver.iterate()            
        if status != errno.GSL_SUCCESS:
            break
        ssval = solver.size()
        rval = multiminimize.test_size (ssval, 1e-2);

        if rval == 0:
            print "converged to minimum at"
        fval = solver.getf()
        x = solver.getx()
        t = (i, x[0], x[1], fval, ssval)
        print "iter %3d x % 10.3e % 10.3e  f() = %-10.3f ssize = %.3f" % t
        if rval == 0:
            break
    else:
        raise ValueError, "Number of Iterations exceeded!"

def fdf_solver():
    params = numx.array((1., 2.), )
    sys = multiminimize.gsl_multimin_function_fdf(my_f, my_df, my_fdf, params, 2)
    #solver = multiminimize.conjugate_pr(sys, 2)
    #solver = multiminimize.conjugate_fr(sys, 2)
    solver = multiminimize.vector_bfgs(sys, 2)
    #solver = multiminimize.steepest_descent(sys, 2)
    start = numx.array((5., 7.), )
    solver.set(start, 0.01, 1e-4)
    print "Using solver ", solver.name() 
    print "%5s %9s %9s  %9s %9s %9s" % ("iter", "x", "y", "f", "dx", "dy")
    for iter in range(200):
        status = solver.iterate()
        gradient = solver.gradient()
        x = solver.getx()
        f = solver.getf()
        status = multiminimize.test_gradient(gradient, 1e-3)
        if status == errno.GSL_SUCCESS:
            print "Converged "
        print "%5d % .7f % .7f  % .7f % .7f % .7f" %(iter, x[0], x[1], f, gradient[0], gradient[1])
        if status == errno.GSL_SUCCESS:
            break

    else:
        raise ValueError, "Number of Iterations exceeded!"

if __name__ == '__main__':
    f_solver()
    fdf_solver()
