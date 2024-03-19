"""first geodesic example as found in the documentation
"""
from pygsl import multifit_nlinear
from pygsl.blas import ddot
from typing import Sequence
import numpy as np


def f(x, args):
    x1, x2 = x
    f1 = 100 * (x2 - x1 ** 2)
    f2 = 1.0 - x1
    return f1, f2


def df(x, args):
    x1, _ = x
    J = np.zeros((2, 2), float)
    J[0, 0] = -200 * x1
    J[0, 1] = 100
    J[1, 0] = -1
    J[1, 1] = 0
    return J


def fvv(x, v, args):
    v1, _ = v
    fvv1 = -200 * v1 ** 2
    fvv2 = 0.0
    return fvv1, fvv2


def callback(iter_, data, w):
    x1, x2 = w.position()
    print(f"iter = {iter_:2d} x1 = {x1:f} x2 = {x2:f}")


def solve_system(
    x0: Sequence[float],
    fdf: multifit_nlinear.fdf,
    parameters: multifit_nlinear.parameters,
):

    max_iter = 200
    gtol = ftol = xtol = 1e-8
    solver = multifit_nlinear.workspace(
        multifit_nlinear.trust, parameters, fdf.get_n(), fdf.get_p()
    )

    solver.init(x0, fdf)
    f = solver.residual()
    chisq0 = np.dot(f, f)
    info = multifit_nlinear.driver(
        maxiter=max_iter,
        xtol=xtol,
        ftol=ftol,
        gtol=gtol,
        callback=callback,
        args=None,
        workspace=solver,
    )
    f = solver.residual()
    x1, x2 = solver.position()
    chisq = ddot(f, f)
    rcond = solver.rcond()
    cond = 1.0 / rcond

    txt = f"""
n iter : {solver.niter()}
number of iterations  {solver.niter():d}
function evaluations  {fdf.nevalf()}
Jacobian evaluations  {fdf.nevaldf()}
fvv      evaluations  {fdf.nevalfvv()}
reason for stopping   {multifit_nlinear.strinfo(info)}

chisq
initial cost          {chisq0:.12e}
final   cost          {chisq:.12e}

final   x             ({x1:.12e}, {x2:.12e})
final   cond(J)       {cond:.12e}
"""
    print(txt, "\n\n")


n = 2
p = 2


fdf = multifit_nlinear.fdf(f=f, df=df, fvv=fvv, args=None, n=n, p=p)
# sets to default at init
parameters = multifit_nlinear.parameters()
x0 = -0.5, 1.75

parameters.set_trs(multifit_nlinear.trs_lm)
solve_system(x0, fdf, parameters)

parameters.set_trs(multifit_nlinear.trs_lmaccel)
solve_system(x0, fdf, parameters)
