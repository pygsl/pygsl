"""Example demonstrating interface

Its main emphasis is to describe the callback interface.

Here annotation is used for describing it
"""
from pygsl import multilarge_nlinear, blas, set_debug_level
import numpy as np
from dataclasses import dataclass
from typing import Sequence, Tuple, Union


@dataclass
class Parameters:
    x0: float
    y0: float
    x_scale: float
    y_scale: float


@dataclass
class Data:
    x: Sequence[float]
    y: Sequence[float]
    z: Sequence[float]
    pars: Parameters


def function(X, data: Data):
    r"""
    just a simple test function

    .. math::

        x_s \cdot (x - x0)**2 + y_s \cdot(y - y0)**3
    """
    x0, y0, x_scale, y_scale = X
    dx = np.asarray(data.x) - x0
    dy = np.asarray(data.y) - y0

    return x_scale * dx ** 2 + y_scale * dy ** 3


def f_func(X, args: object):
    """offset of forecast from data

    Args:
        X: position
        args: user arguments
    *NB*: I think scipy swaps these two
    """
    return function(X, args) - args.z


def f_jac(X, args: object):
    """The Jacobian of the function

    Here just used to illustrate the callback "df2"
    see below.
    """
    x0, y0, xs, ys = X
    x = np.asarray(args.x)
    y = np.asarray(args.y)
    dx = x - x0
    dy = y - y0

    # fmt: off
    return np.vstack([
        - 2 * xs * dx,
        - 3 * ys * dy**2,
        dx**2,
        dy**3
    ]).T
    # fmt: on


def df_func(
    trans_j: Union[blas.CblasNoTrans, blas.CblasTrans],
    X: Sequence[float],
    u: Sequence[float],
    args: object,
    compute_jtj: bool,
) -> Tuple[Sequence[float], Union[Sequence[Sequence[float]]], None]:
    """computes v and JTJ if requested

    Args:
        trans_j:     if the Jacobian or the transposed Jacobian
                     shall be used to compute v
        X:           position to use
        u:           derivatives
        args:        user arguments
        compute_jtj: if the matrix JTJ shall be computed too

    Returns:
        v, JTJ

    *NB* This function *must* always return 2 arguments. If
    `compute_jtj` is set to False, the second argument *must* be `None`
    """
    jac = f_jac(X, args)
    if trans_j == blas.CblasNoTrans:
        v = jac @ u
    elif trans_j == blas.CblasTrans:
        v = jac.T @ u
    else:
        raise AssertionError(
            f"{trans_j= } unexpected value:"
            f" expected {blas.CblasNoTrans=} or {blas.CblasTrans=}"
        )

    JTJ = None
    if compute_jtj:
        JTJ = jac.T @ jac
    return v, JTJ


def func_fvv(X: Sequence[float], v: Sequence[float], args: object) -> Sequence[float]:
    """Compute Hessian and then fvv

    Args:
        X: position
        v: `velocity' (of solution)
    """
    x0, y0, xs, ys = X
    vx0, vy0, vxs, vys = v
    x = np.asarray(args.x)
    y = np.asarray(args.y)
    dx = x - x0
    dy = y - y0

    # The non zero elements of the Hessian ``H
    Dx0x0 = 2 * xs
    Dx0xs = -2 * dx
    Dy0y0 = 6 * ys * dy
    Dy0ys = -3 * dy ** 2

    # And now the sum
    fvv = (
        Dx0x0 * vx0 ** 2
        + 2 * Dx0xs * vx0 * vxs
        + Dy0y0 * vy0 ** 2
        + 2 * Dy0ys * vy0 * vys
    )
    return fvv


def callback(iter_: int, args: object, w: multilarge_nlinear.workspace) -> None:
    """User callback for driver

    Typically used to watch progress of solver
    """
    x0, y0, x_scale, y_scale = w.position()
    print(f"iter {iter_:3d} {x0:.3f}, {y0:.3f}, {x_scale:.3f} {y_scale:.3f}")


data = Data(
    x=np.linspace(-3, 3, num=20),
    y=np.linspace(-2, 2, num=20),
    z=[],
    pars=Parameters(x0=5, y0=-1.0 / 11.0, x_scale=23, y_scale=1.0 / 3.0),
)
data.z = function(
    [data.pars.x0, data.pars.y0, data.pars.x_scale, data.pars.y_scale], data
)

n = len(data.x)
p = 4
parameters = multilarge_nlinear.parameters()
parameters.set_trs(multilarge_nlinear.trs_lm)
parameters.set_trs(multilarge_nlinear.trs_lmaccel)
# This does not seem to converge that fast
# parameters.set_trs(multilarge_nlinear.trs_dogleg)
# parameters.set_trs(multilarge_nlinear.trs_subspace2D)
parameters.set_trs(multilarge_nlinear.trs_cgst)

# The system to solve
# Set functions to None if it should compute it internally.
# NB: it can be that solver expects e.g. df. If not supplied it
# can crash the interpreter. Please test this in a simple script
# first
fdf = multilarge_nlinear.fdf(
    f=f_func,
    df=df_func,
    # df= None,
    # fvv=None,
    fvv=func_fvv,
    args=data,
    n=n,
    p=p,
)

# The workspace
workspace = multilarge_nlinear.workspace(multilarge_nlinear.trust, parameters, n, p)
x_init = [1, 0.2, 1, 1]

# This init will call at least f and most probably df. If a not
# understandable exception is raised or the interpreter crashes
# it can be useful to set the debug level to e.g. 2 or higher
# Then debug prints are made on stderr which will give hints
# what went wrong.
set_debug_level(0)
workspace.init(x_init, fdf)
# you can it set back again if not required any more
set_debug_level(0)

f = workspace.residual()
chisq0 = np.dot(f, f)

info = multilarge_nlinear.driver(
    maxiter=100,
    xtol=1e-12,
    gtol=1e-12,
    ftol=1e-12,
    # callback=None,
    callback=callback,
    args=data,
    workspace_o=workspace,
)

x0, y0, xs, ys = workspace.position()
txt = f"""
summary from method   {workspace.name()} / {workspace.trs_name()}
number of iterations  {workspace.niter():d}
function evaluations  {fdf.nevalf()}
Jacobian evaluations  {fdf.nevaldf2()}
fvv      evaluations  {fdf.nevalfvv()}
reason for stopping   {multilarge_nlinear.strinfo(info)}

Solutions               found         expected
x0                    {x0: 10.6f}    {data.pars.x0: 10.6f}
y0                    {y0: 10.6f}    {data.pars.y0: 10.6f}
xs                    {xs: 10.6f}    {data.pars.x_scale: 10.6f}
ys                    {ys: 10.6f}    {data.pars.y_scale: 10.6f}
"""
print(txt)
