"""pythonic version of the gsl reference manual with matplotlib plot
"""
import sys
import matplotlib.pyplot as plt

import pygsl
from pygsl import multifit_nlinear, rng, errors, blas, errno
import numpy as np

def func(x, t):
    A, lambda_, b = x
    Y = A * np.exp(- lambda_ * t) + b
    return Y

def expb_f(x, args):
    y = args
    t = np.arange(len(y) )
    Y = func(x, t)

    f = Y - y
    return f

def expb_df(x, args):
    A, lambda_, b = x
    y = args
    t = np.arange(len(y) )

    e = np.exp(- lambda_ * t)
    l = len(t)
    J = np.ones([l, 3], np.float_)
    J[:,0] = e
    J[:,1] = -t * A * e
    return J

def callback(w, t_iter, *args):
    f = w.residual()
    x = w.position()
    rcond = w.rcond()

    norm = blas.dnrm2(f)
    fmt = "iter %2d: A = %.4f, lambda = % 8.4f, b = % 8.4f, cond(J) = %14.4f, |f(x)| = %8.4f"
    print(fmt %(t_iter, x[0], x[1], x[2], 1.0/rcond, norm))
    
def run():

    x_init = np.array([1.0, 1.0, 0.0])
    xtol = 1e-8
    gtol = 1e-8
    ftol = 0

    p = 3
    n = 40

    rng.env_setup()
    r = rng.rng()
    t = np.arange(n)
    x_final =  5., .1 , 1
    y = func(x_final, t)
    s = 0.1 * y
    dy = np.array(list(map(r.gaussian, s)))
    y = y + dy
    weights = 1./((0.1 * y)**2)

    T = multifit_nlinear.cvar.trust
    pygsl.add_c_traceback_frames(True)
    pygsl.set_debug_level(0)
    params = multifit_nlinear.default_parameters()
    w = multifit_nlinear.workspace(T, params, n, p)

    # What a hack 
    w.set_pyobject(w)
    
    w.winit(x_init, weights, df= expb_df, f=expb_f, fvv = None, args=y)

    f  = w.residual()
    chisq0 = np.dot(f, f)

    #plt.ion()
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.clear()
    ax.errorbar(t, y, yerr=dy)
    Y = func(x_init, t)
    line, = ax.plot(t, Y, '-')
    plt.show(False)
    plt.draw()
    
    max_iter = 200
    #status, info  = w.driver(200, xtol, gtol, ftol, callback)

    for step in range(max_iter):
        x = w.position()
        print("x = %s" %(x,))
        #x = w.x()
        Y = func(x, t)
        line.set_data(t, Y)

        w.iterate()
        status, info = w.test(xtol, gtol, ftol)
        fig.canvas.draw()
        plt.pause(0.5)
        #ax.figure.clf()
        if status == errno.GSL_SUCCESS:
            break
        elif status == errno.GSL_CONTINUE:
            continue
        else:
            raise ValueError("Unexpected status %d" %(status,))
    else:
        raise ValueError("Did not finish within %d steps" %(max_iter,))


    covar = w.covar(0.0)
    f  = w.residual()
    chisq = np.dot(f, f)

    dof = n - p
    c = max(1,  np.sqrt(chisq / dof))

    reasons = ("small gradient", "small step size")
    status, info = w.test(xtol, gtol, ftol)

    print("Summary from method %s/%s" %(w.name(), w.trs_name()) )
    print("  number of iterations %d" %(w.niter(),) )
    print("  function evaluations %d" %(w.params.fdf.nevalf,))
    print("  jacobian evaluations %d" %(w.params.fdf.nevaldf,))
    print("  reason for stopping  %s" %(reasons[info],))
    print("  initial |f(x)|     = %f" %(np.sqrt(chisq0),) )
    print("  final   |f(x)|     = %f" %(np.sqrt(chisq),) )
    print("  chisq / dof          %g" %(chisq / dof) )

    x = w.position()
    x = w.x()
    print("  A     = %.5f +/- %.5f" %  ( x[0], c * covar[0,0]) )
    print("  lamba = %.5f +/- %.5f" %  ( x[1], c * covar[1,1]) )
    print("  b     = %.5f +/- %.5f" %  ( x[2], c * covar[2,2]) )

    plt.show()
    
if __name__ == '__main__':
    run()
 
