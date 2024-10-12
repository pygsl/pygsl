from dataclasses import dataclass
from typing import Sequence, Union
import numpy as np
from pygsl.blas import dnrm2

# from numpy.typing import ArrayLike
from pygsl import multifit_nlinear, rng, set_debug_level


@dataclass
class Data:
    t: Sequence[float]
    y: Sequence[float]


def gaussian(a: float, b: float, c: float, t: Union[float | Sequence[float]]) -> float:
    r"""gaussian bell function

    model function :math:` a \cdot exp( \frac {-1/2} \cdot [ (t - b) / c ]^2 )`
    """
    z = (t - b) / c
    return a * np.exp(-0.5 * z ** 2)


def f(x: Sequence[float], args: Data) -> Sequence[float]:
    a, b, c = x
    y = gaussian(a, b, c, np.asarray(args.t))
    dy = np.asarray(args.y) - y
    return dy


def df(x: Sequence[float], args: Data):
    a, b, c = x

    t = np.asarray(args.t)
    z = (t - b) / c
    e = np.exp(-0.5 * z ** 2)

    return np.vstack(
        [
            -e,
            -(a / c) * e * z,
            -(a / c) * e * z ** 2,
        ]
    ).T


def fvv(x: Sequence[float], v: Sequence[float], args: Data):
    a, b, c = x
    va, vb, vc = v

    t = np.asarray(args.t)
    z = (t - b) / c
    e = np.exp(-0.5 * z ** 2)

    # fmt: off
    Dab =    -z    * e / c
    Dac =    -z**2 * e / c
    Dbb = a        * e / c**2 * (1 - z**2)
    Dbc = a * z    * e / c**2 * (2 - z**2)
    Dcc = a * z**2 * e / c**2 * (3 - z**2)
    # fmt: on

    # fmt: off
    fvv = (
            2.0 * va * vb * Dab +
            2.0 * va * vc * Dac +
                  vb * vb * Dbb +
            2.0 * vb * vc * Dbc +
                  vc * vc * Dcc
    )
    # fmt: on
    return fvv


def callback(iter_: int, args: Data, w: multifit_nlinear.workspace):
    a, b, c = w.position()
    f = w.residual()
    avratio = w.avratio()
    rcond = w.rcond()
    if np.absolute(rcond) < 1e-200:
        rcond = 1e-200 * np.sign(rcond)
    cond = 1.0 / rcond

    txt = (
        f"iter {iter_:2d}: a = {a:.4f} b = {b:.4f} c = {c:.4f}"
        f" |a|/|v| = {avratio:.4f} cond = {cond:8.4f} |f(x)| {dnrm2(f):.4f}"
    )


def solve_system(
    x0: Sequence[float],
    fdf: multifit_nlinear.fdf,
    parameters: multifit_nlinear.parameters,
    args: Data,
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
        args=args,
        workspace=solver,
    )
    f = solver.residual()
    a, b, c = solver.position()
    chisq = np.dot(f, f)
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

final   x             ({a:.12e}, {b:.12e}, {c:.12e})
final   cond(J)       {cond:.12e}
"""
    print(txt, "\n\n")
    return solver.position()


n = 300
p = 3

a = 5
b = 0.4
c = 0.15

t = np.linspace(0, 1, num=n)
r = rng.rng()
y0 = gaussian(a, b, c, t)
dy = np.array([r.gaussian(0.1 * yi) for yi in y0])
y = y0 + dy
data = Data(t=t, y=y)
x0 = [1, 0, 1]
fdf = multifit_nlinear.fdf(f=f, df=df, fvv=fvv, args=data, n=n, p=p)
# sets to default at init
parameters = multifit_nlinear.parameters()
parameters.set_trs(multifit_nlinear.trs_lm)
solve_system(x0, fdf, parameters, data)

parameters.set_trs(multifit_nlinear.trs_lmaccel)
x = solve_system(x0, fdf, parameters, data)


if True:
    import matplotlib.pyplot as plt

    plt.plot(data.t, data.y, "b.")
    plt.plot(data.t, gaussian(*(list(x) + [data.t])), "r-")
    plt.show()
