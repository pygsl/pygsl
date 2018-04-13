"""pythonic version of the gsl reference manual
"""
import sys
import pygsl
from pygsl import multifit_nlinear, rng, errors, blas, errno
import numpy as np

#for val in dir(multifit_nlinear):
#    print("module", val)
#for val in dir(multifit_nlinear.cvar):
#    print("cvar", val)
#print(repr(multifit_nlinear.cvar))
#print(multifit_nlinear.CTR

GSL_SUCCESS = errno.GSL_SUCCESS

def expb_f(x, args):
    # print("x", x)
    # print("args", args)
    A, lambda_, b = x
    y = args
    #print("f: y.shape %s" % (y.shape,) )

    t = np.arange(len(y) )
    Y = A * np.exp(- lambda_ * t) + b

    f = Y - y
    return GSL_SUCCESS, f

def expb_df(x, args):
    A, lambda_, b = x
    y = args
    #print("df: y.shape %s" % (y.shape,) )
    
    l = len(y)
    t = np.arange(l)
    e = np.exp(- lambda_ * t)

    J = np.ones([l, 3], np.float_)
    J[:,0] = e
    J[:,1] = -t * A * e
    #print("J.shape = %s\n" %(J.shape,))
    stream = sys.stderr
    #stream.write("J.shape = %s\n" %(J.shape,))
    #stream.flush()
    return GSL_SUCCESS, J

def callback(w, t_iter, *args):
    #print("cb w", w)
    #print("cb t_iter", t_iter)
    #print("args", *args )
    f = w.residual()
    x = w.position()
    rcond = w.rcond()

    norm = blas.dnrm2(f)
    fmt = "iter %2d: A = %.4f, lambda = % 8.4f, b = % 8.4f, cond(J) = %14.4f, |f(x)| = %8.4f"
    print(fmt %(t_iter, x[0], x[1], x[2], 1.0/rcond, norm))

    #pygsl.set_debug_level(4)
    if t_iter > 0:
        pass

def run():

    x_init = np.array([1.0, 1.0, 0.0])
    xtol = 1e-8
    gtol = 1e-8
    ftol = 0

    fdf = (expb_f, expb_df)
    p = 3
    n = 40

    r = rng.rng()
    t = np.arange(n)
    y = 1.0 + 5 * np.exp(-0.1 * t)
    dy = r.gaussian(n)
    y += dy
    weights = 1./((0.1 * y)**2)

    T = multifit_nlinear.cvar.trust
    pygsl.add_c_traceback_frames(True)
    pygsl.set_debug_level(0)
    params = multifit_nlinear.default_parameters()
    w = multifit_nlinear.workspace(T, params, n, p)
    w.set_pyobject(w)
    # w.params.fdf.p = p
    # w.params.fdf.n = n
    args = y
    #print(w.init.__doc__)
    
    print("params factor: up %s down %s" %(params.factor_up,
                                           params.factor_down, ))
    errors.error_safe_state.reset()
    pygsl.set_debug_level(0)
    # w.init(x_init, df= expb_df, f=expb_f, fvv=None, args=args)
    w.init(x_init, df= None, f=expb_f, fvv=None, args=args)
    pygsl.set_debug_level(0)

    f  = w.residual()
    chisq0 = np.dot(f, f)
    pygsl.set_debug_level(0)
    status, info  = w.driver(200, xtol, gtol, ftol, callback)
    pygsl.set_debug_level(0)

    J = w.jac()
    covar = multifit_nlinear.covar(J, 0.0, p)
    J = w.jac()
    covar = w.covar(0.0)

    f  = w.residual()
    chisq = np.dot(f, f)

    dof = n - p
    c = max(1,  np.sqrt(chisq / dof))

    reasons = ("small step size", "small gradient")

    print("Summary from method %s/%s" %(w.name(), w.trs_name()) )
    print("  number of iterations %d" %(w.niter(),) )
    print("  function evaluations %d" %(w.params.fdf.nevalf,))
    print("  jacobian evaluations %d" %(w.params.fdf.nevaldf,))
    print("  reason for stopping  %s" %(reasons[info]))

    print("  chisq / dof          %g" %(chisq / dof) )

    x = w.position()
    x = w.x()
    print("  A     = %.5f +/- %.5f" %  ( x[0], c * covar[0,0]) )
    print("  lamba = %.5f +/- %.5f" %  ( x[1], c * covar[1,1]) )
    print("  b     = %.5f +/- %.5f" %  ( x[2], c * covar[2,2]) )
    
if __name__ == '__main__':
    run()
 
