"""Pythonic version of the Geodesic Acceleration Example 1
"""
import pygsl
from pygsl import multifit_nlinear, rng, errors, blas, errno
import numpy as np



def func_f(x, params):
    x1, x2 = x
    tmp = x2 - x1**2
    f1 = 100.0 * tmp
    f2 =   1.0 - x1
    f = np.array([f1, f2])
    # print("x = %s f = %s" % (x,f))
    return errno.GSL_SUCCESS, f

def func_df(x, params):
    x1, x2 = x
    J = np.zeros([2, 2], np.float_)
    J[0,0] = -200.0 * x1
    J[0,1] =  100.0
    J[1,0] = -1.0;
    J[1,1] =  0.0
    tup = x1, J[0,0], J[0,1], J[1,0], J[1,1]
    # print("x1 %g\t J11 %g\t J12 %g\t J21 %g\t J22 %g" % tup)
    #print("x %g J1", J)
    return errno.GSL_SUCCESS, J

def func_fvv(x, v, params, *args):
    """The geodesic gradient acceleration function

    Returns: 
        status, fvv : the status and the evaluated vector

    Concerning the status: The status is evaluated by the GSL solver. If it is 
    not GSL_SUCCESS it will try to evaluate this function with slightly 
    different input parameters. 

    If the evaluation of the user function fails and you want to propagate it to
    the code calling your function raise an exception.
    """
    v1, v2 = v
    fvv = -200.0 * v1 * v1, 0.0
    fvv = np.array(fvv, np.float_)
    tup = (v1,) + tuple(fvv)
    print("v1 %g fvv %g %g" % tup)
    return errno.GSL_SUCCESS, fvv

def callback(w, t_iter, *args):
    x = w.position()
    print(" %f %f" % tuple(x) )

def solve_system(x0, params):

    xtol = gtol = ftol = 1e-12
    max_iter = 200
    n = p = 2
    T = multifit_nlinear.cvar.trust
    w = multifit_nlinear.workspace(T, params, n, p)
    
    # What a hack 
    w.set_pyobject(w)
    w.init(x0, f = func_f, df = func_df, fvv = func_fvv, args=None)
    #w.init(x0, f = func_f,  args=None)
    f = w.residual()
    chisq0 = np.dot(f, f)    

    pygsl.set_debug_level(0)
    
    w.driver(max_iter, xtol, gtol, ftol, callback = None, callback_params = None)
    
    f = w.residual()
    chisq = np.dot(f, f)    

    rcond = w.rcond()

    print("    NITER         = %d" % w.niter())
    print("    NFEV          = %d" % w.params.fdf.nevalf)
    print("    NJEV          = %d" % w.params.fdf.nevaldf)
    print("    NAEV          = %d" % w.params.fdf.nevalfvv)
    print("    initial cost  = %.12e"% chisq0)
    print("    final cost    = %.12e"% chisq)
    print("    final x       = (%.12e, %.12e)" % tuple(w.position()) )
    print("    final cond(J) = %.12e" % (1.0 / rcond,) )
    
def run():
    x0 = -0.5, 1.75
    params = multifit_nlinear.default_parameters()
    
    params.trs = multifit_nlinear.trs_lm
    print("=== Solving system without acceleration ===")
    solve_system(x0, params)
    
    params.trs = multifit_nlinear.trs_lmaccel
    print("=== Solving system with    acceleration ===")
    solve_system(x0, params)

if __name__ == "__main__":
    pygsl.add_c_traceback_frames(True)
    pygsl.set_debug_level(0)
    run()

    
