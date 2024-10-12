"""first example as found in the documentation
"""
from pygsl import multifit_nlinear, rng, set_debug_level
from pygsl.blas import dnrm2
import numpy as np
from dataclasses import dataclass
from typing import Sequence
import sys


@dataclass
class Data:
    t: Sequence[float]
    y: Sequence[float]


def expb_f(x, data):
    A, lambda_, b = x
    f = A * np.exp(-lambda_ * data.t) + b
    return f - y


def expb_df(x, data):
    A, lambda_, _ = x
    e = np.exp(-lambda_ * data.t)
    return np.vstack([e, -t * A * e, np.ones(len(e), np.double)]).T


def callback(iter_, data, w):
    f = w.residual()
    A, lambda_, b = w.position()
    rcond = w.rcond()
    if rcond == 0:
        return
    cond = 1 / rcond
    nrm = dnrm2(f)
    print(
        f"iter = {iter_:2d} A = {A:4f} lambda = {lambda_:4f} b = {b:4f}"
        f" cond(J) = {cond:8.4f} |f(x)| = {nrm:4f}"
    )


n = 100
p = 3
t_max = 3.0

r = rng.rng()
xtol = 1e-8
gtol = 1e-8
ftol = 0.0
x_init = [1.0] * 2 + [0.0]

t = np.arange(n) * t_max / (n - 1.0)
y = 1 + 5 * np.exp(-1.5 * t)
s = 0.1 * y
dy = [r.gaussian(si) for si in s]
data = Data(t=t, y=y + dy)
weights = 1.0 / (s ** 2)

# sets all parameters to default at init
parameters = multifit_nlinear.parameters()
fdf = multifit_nlinear.fdf(f=expb_f, df=expb_df, fvv=None, args=data, n=n, p=p)
#: todo find out how should it be named:
workspace = multifit_nlinear.workspace(multifit_nlinear.trust, parameters, n, p)
# set_debug_level(3)
workspace.winit(x_init, weights, fdf)
f = workspace.residual()
chisq0 = np.dot(f, f)

set_debug_level(0)
info = multifit_nlinear.driver(
    maxiter=100,
    xtol=xtol,
    gtol=gtol,
    ftol=ftol,
    callback=callback,
    args=data,
    workspace=workspace,
)

J = workspace.jac()
covar = multifit_nlinear.covar(J, 0.0)
f = workspace.residual()
A_final, lambda_final, b_final = workspace.position()
chisq = np.dot(f, f)
dof = n - p
c = max(1, np.sqrt(chisq / dof))

txt = f"""
summary from method   {workspace.name()} / {workspace.trs_name()}
number of iterations  {workspace.niter():d}
function evaluations  {fdf.nevalf()}
Jacobian evaluations  {fdf.nevaldf()}
fvv      evaluations  {fdf.nevalfvv()}
reason for stopping   {multifit_nlinear.strinfo(info)}

chisq
initial       |f(x)|  {chisq0:f}
final         |f(x)|  {chisq :f}
chisq / dof           {chisq / dof :g}
A                     {A_final:.5f} +/- {c * covar[0, 0]:.5f}
lambda                {lambda_final:.5f} +/- {c * covar[1, 1]:.5f}
b                     {b_final:.5f} +/- {c * covar[1, 1]:.5f}
"""
print(txt)

if True:
    import matplotlib.pyplot as plt

    plt.errorbar(data.t, data.y, yerr=s, color="b", linestyle="")
    plt.plot(data.t, A_final * np.exp(-lambda_final * data.t) + b_final, "r-")
    plt.show()
