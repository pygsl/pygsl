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

"""
C:\OpenSource\Devel\pygsl-git>c:\OpenSource\Devel\gsl-2.4\doc\examples\nlfit4.exe
Method                    NITER NFEV NJUEV NJTJEV NAEV Init Cost  Final cost cond(J) Final |x|^2 Time (s)
levenberg-marquardt       25    31   26    26     0    7.1218e+018 1.9555e-002 447.50  2.5044e-001 105.55
levenberg-marquardt+accel 22    23   45    23     22   7.1218e+018 1.9555e-002 447.64  2.5044e-001 77.40
dogleg                    37    87   36    36     0    7.1218e+018 1.9555e-002 447.59  2.5044e-001 128.16
double-dogleg             35    88   34    34     0    7.1218e+018 1.9555e-002 447.62  2.5044e-001 119.91
2D-subspace               37    88   36    36     0    7.1218e+018 1.9555e-002 447.71  2.5044e-001 126.19
steihaug-toint            35    88   345   0      0    7.1218e+018 1.9555e-002 1.#J    2.5044e-001 0.09

Method                    NITER NFEV NJUEV NJTJEV NAEV Init Cost  Final cost cond(J) Final |x|^2 Time (s)
levenberg-marquardt       25    31   26    26     0    7.1218e+18 1.9555e-02 447.50  2.5044e-01  107.95
levenberg-marquardt+accel 22    23   45    23     22   7.1218e+18 1.9555e-02 447.64  2.5044e-01  82.35
dogleg                    37    88   36    36     0    7.1218e+18 1.9555e-02 447.55  2.5044e-01  130.19
double-dogleg             38    91   37    37     0    7.1218e+18 1.9555e-02 447.52  2.5044e-01  135.52
2D-subspace               35    88   34    34     0    7.1218e+18 1.9555e-02 447.55  2.5044e-01  127.26
steihaug-toint            35    88   345   0      0    7.1218e+18 1.9555e-02 999999999999999.88 2.5044e-01  0.42
"""

stream = sys.stderr
def penalty_f(x, args):
    #stream.write("f..")
    alpha, J = args
    del J

    sqrt_alpha = np.sqrt(alpha)
    dim, = x.shape
    f = np.zeros((dim + 1,), np.float_)
    f[:-1] = sqrt_alpha * (x - 1.0)

    t_sum = np.sum(x**2)
    f[-1] = t_sum - 0.25
    
    #print("x.shape %s f.shape %s dim = %s" %(x.shape, f.shape, dim))
    #stream.write("f ")
    #stream.flush()
    return errno.GSL_SUCCESS, f

def penalty_df(TransJ, x, u, v, JTJ, args):
    #stream.write("df..")

    alpha, J = args
    dim, = x.shape
    p = dim

    if 1 == 1:
        indices = np.zeros((p, 2), np.longlong)
        indices[:,0] = p
        indices[:,1] = range(p)
        J.set_from_triplet(indices, 2 * x)
    else:
        for j in range(p):
            J.set(p, j, 2.0 * x[j]);

    nv = None
    nJTJ = None
    if v is not None:
        #pygsl.set_debug_level(4)
        nv = dgemv(TransJ, 1.0, J, u, 0.0, v)

    # You could also edit the array directly
    if JTJ is not None:
        #nJTJ = copy.copy(JTJ)
        #nJTJ = sc_blas.dsyr(4.0, x, a=JTJ, lower=True, overwrite_a = False)
        dims = JTJ.shape
        assert(len(dims) == 2)
        assert(dims[0] == dims[1])
        assert(dims[0] == p)

        JTJ[:,:] = 0.0
        nJTJ = blas.dsyr(4.0, x, JTJ, Uplo=blas.CblasLower)
        
        diag =  nJTJ.diagonal()
        if 1 == 1:
            idx = np.diag_indices(p)
            nJTJ[idx] = diag + alpha
        else:
            for j in range(dims[0]):
                nJTJ[j,j] =  diag[j] + alpha

    #stream.write("df\n")
    #stream.flush()
    return errno.GSL_SUCCESS, nv, nJTJ

def penalty_fvv(x, v, args):
    #stream.write("fvv..")

    alpha, J = args

    normv = blas.dnrm2(v)
    fvv = np.zeros((v.shape[0] + 1), np.float_)
    fvv[-1] = 2.0 * normv * normv
    #stream.write("fvv\n")
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
    assert(status == errno.GSL_SUCCESS)
    #print("Info", info)
    tac = datetime.datetime.now()

    f = w.residual()
    chisq = np.dot(f,f)
    x = w.position()
    xsq = np.dot(x,x)
    rcond = w.rcond()
    if rcond == 0.0:
        rcond = 1e-15
    
    dt = tac - tic
    fmt = "%-25s %-5u %-4u %-5u %-6u %-4u %-10.4e %-10.4e %-7.2f %-11.4e %.2f"
    tup = (w.trs_name(), w.niter(),
           w.params.fdf.nevalf, w.params.fdf.nevaldfu,
           w.params.fdf.nevaldf2, w.params.fdf.nevalfvv,
           chisq0, chisq, 1.0 / rcond, xsq, dt.total_seconds())
    print(fmt % tup)
    #pygsl.set_debug_level(4)
    
def run():

    p = 200
    p = 2000
    n = p + 1
    
    x0 = np.arange(p) + 1
    alpha = 1.0e-5
    J = sp_matrix.sparse_matrix(n, p, 2 *p, sp_matrix.Form.TRIPLET)
    params = multilarge_nlinear.default_parameters()
    args = (alpha, J)

    P = np.arange(p, dtype=np.longlong)
    P2 = np.zeros((p,2), dtype=np.longlong)
    P2[:,:] = P[:, np.newaxis]
    sq_alpha = np.zeros((p,), dtype=np.float_)
    sq_alpha[:] = np.sqrt(alpha)
    #P2 =  * np.ones((2,),  dtype=np.longlong)[np.newaxis, :]
    J.set_from_triplet(P2, sq_alpha)
    
    #for i in range(p):
    #    J.set(i, i, sq_alpha)

    
    params.scale = multilarge_nlinear.scale_levenberg;

    fmt = "%-25s %-4s %-4s %-5s %-6s %-4s %-10s %-10s %-7s %-11s %-10s"
    tup = ("Method", "NITER", "NFEV", "NJUEV", "NJTJEV", "NAEV", "Init Cost",
          "Final cost", "cond(J)", "Final |x|^2", "Time (s)")
    print(fmt %tup)

    for trs in (
            multilarge_nlinear.trs_lm,
            multilarge_nlinear.trs_lmaccel,
            multilarge_nlinear.trs_dogleg,
            multilarge_nlinear.trs_ddogleg,
            multilarge_nlinear.trs_subspace2D,
            multilarge_nlinear.trs_cgst,
    ):
        params.trs = trs
        x = copy.copy(x0)
        solve_system(x, params, (n,p), args)
    
if __name__ == '__main__':
    run()


