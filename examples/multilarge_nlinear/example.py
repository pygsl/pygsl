"""pythonic version of the example found in the GSL reference documentation
"""
import copy
import sys
import datetime
import pygsl
pygsl.add_c_traceback_frames(True)
from pygsl.sparse.blas import dgemv
from pygsl.sparse import matrix as sp_matrix
from pygsl import _gslwrap
from pygsl import multilarge_nlinear, errors, blas, errno
import numpy as np

from scipy.linalg import blas as sc_blas

stream = sys.stderr
def penalty_f(x, args):
    stream.write("f..")
    alpha, J = args
    del J

    sqrt_alpha = np.sqrt(alpha)
    dim, = x.shape
    t_sum = np.sum(x**2)
    f = np.zeros((dim + 1,), np.float_)
    f[:-1] = sqrt_alpha * (x - 1.0)
    f[-1] = t_sum - 0.25
    #print("x.shape %s f.shape %s dim = %s" %(x.shape, f.shape, dim))
    stream.write("f ")
    #stream.flush()
    return errno.GSL_SUCCESS, f

def penalty_df(TransJ, x, u, v, JTJ, args):
    stream.write("df..")

    alpha, J = args
    dim, = x.shape
    p = dim

    for j in range(p):
        xj = 2.0 * x[j];
        J.set(p, j, xj);

    nv = None
    nJTJ = None
    if v is not None:
        #pygsl.set_debug_level(4)
        nv = dgemv(TransJ, 1.0, J, u, 0.0, v)

    # You could also edit the array directly
    if JTJ is not None:
        #nJTJ = copy.copy(JTJ)
        nJTJ = sc_blas.dsyr(4.0, x, a=JTJ, lower=True, overwrite_a = False)
        #nJTJ = blas.dsyr(4.0, x, JTJ, Uplo=blas.CblasLower)
        idx = np.diag_indices(p)

        nJTJ[idx] = nJTJ.diagonal() + alpha

    stream.write("df\n")
    #stream.flush()
    return errno.GSL_SUCCESS, nv, nJTJ

def penalty_fvv(x, v, args):
    stream.write("fvv..")

    alpha, J = args

    normv = blas.dnrm2(v)
    fvv = np.zeros((v.shape[0] + 1), np.float_)
    fvv[-1] = 2.0 * normv * normv
    stream.write("fvv\n")
    #stream.flush()
    return errno.GSL_SUCCESS, fvv

def solve_system(x0, fdf_params, dims, args):

    n,p = dims
    T = multilarge_nlinear.trust
    max_iter = 200
    xtol = 1e-8
    gtol = 1e-8
    ftol = 1e-8

    w = multilarge_nlinear.workspace(T, fdf_params, n=n, p=p)

    fdf = (penalty_f, penalty_df, penalty_fvv)

    w.init(x0, f=penalty_f, df=penalty_df, fvv = penalty_fvv, args = args)

    f0 = w.residual()
    x = w.position()
    chisq0 = np.dot(f0,f0)

    tic = datetime.datetime.now()
    #w.iterate()
    #pygsl.set_debug_level(8)
    status, info = w.driver(max_iter, xtol, gtol, ftol)
    tac = datetime.datetime.now()

    f = w.residual()
    chisq = np.dot(f,f)
    xsq = np.dot(x,x)
    rcond = w.rcond()
    if rcond == 0.0:
        rcond = 1e-15
    
    dt = tac - tic
    fmt = "%-25s %-5u %-4u %-5u %-6u %-4u %-10.4e %-10.4e %-7.2f %-11.4e %.2f\n"
    tup = (w.trs_name(), w.niter(),
           w.params.fdf.nevalf, w.params.fdf.nevaldfu,
           w.params.fdf.nevaldf2, w.params.fdf.nevalfvv,
           chisq0, chisq, 1.0 / rcond, xsq, dt.total_seconds())
    print(fmt % tup)

def run():

    p = 20
    p = 2000
    n = p + 1
    
    x0 = np.arange(p) + 1
    alpha = 1.0e-5
    J = sp_matrix.sparse_matrix(n, p, 2 *p, sp_matrix.Form.TRIPLET)
    params = multilarge_nlinear.default_parameters()
    args = (alpha, J)

    sq_alpha = np.sqrt(alpha)
    for i in range(p):
        J.set(i, i, alpha)

    params.scale = multilarge_nlinear.scale_levenberg;
    params.trs   = multilarge_nlinear.trs_lm;
    x = copy.copy(x0)
    solve_system(x, params, (n,p), args)
    return

    params.trs   = multilarge_nlinear.trs_lmaccel;
    x = copy.copy(x0)
    solve_system(x, params, (n,p), args)

    params.trs   = multilarge_nlinear.trs_dogleg;
    x = copy.copy(x0)
    #solve_system(x, params, (n,p), args)

    params.trs   = multilarge_nlinear.trs_ddogleg;
    x = copy.copy(x0)
    solve_system(x, params, (n,p), args)

    params.trs   = multilarge_nlinear.gsl_multilarge_nlinear_trs_subspace2D;
    x = copy.copy(x0)
    solve_system(x, params, (n,p), args)
    
    params.trs   = multilarge_nlinear.gsl_multilarge_nlinear_trs_cgst;
    x = copy.copy(x0)
    solve_system(x, params, (n,p), args)
    
if __name__ == '__main__':
    run()


