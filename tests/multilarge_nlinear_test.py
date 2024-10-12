from dataclasses import dataclass
from typing import Sequence, Tuple, Union

from pygsl import multilarge_nlinear, blas, errors, set_debug_level
import numpy as np
import pytest


def test_matrix_copy_lower_triangle():
    fill_value = -42
    tmp = np.empty([5, 5])
    tmp.fill(fill_value)
    tril = np.tril(tmp)
    inp = np.where(tril > 0, tril, fill_value)
    r = multilarge_nlinear.pygsl_matrix_copy_lower_triangle(inp, fill_value)
    assert (r - inp) == pytest.approx(expected=0, abs=1e-12)


def test_matrix_copy_lower_triangle_upper_triangle_untouched():
    fill_value = -42
    mark_value = 23
    inp = np.empty([5, 5])

    inp.fill(fill_value)
    ref = np.empty([5, 5])
    ref.fill(mark_value)
    chk = ref.copy()
    multilarge_nlinear._pygsl_matrix_copy_lower_triangle(inp, chk)

    # these should be untouched
    tru = np.triu(np.ones([5, 5]), 1)
    test = np.where(tru > 0, mark_value, fill_value)
    assert (chk - test) == pytest.approx(expected=0, abs=1e-12)

def test_copy_matrix_lower_triangle_not_matching_sizes():

    inp = np.empty([5, 5])
    out = np.empty([5, 6])
    with pytest.raises(errors.gsl_BadLength):
        multilarge_nlinear._pygsl_matrix_copy_lower_triangle(inp, out)

    inp = np.empty([3, 3])
    out = np.empty([2, 3])
    with pytest.raises(errors.gsl_BadLength):
        multilarge_nlinear._pygsl_matrix_copy_lower_triangle(inp, out)

    inp = np.empty([3, 3])
    out = np.empty([2, 2])
    with pytest.raises(errors.gsl_BadLength):
        multilarge_nlinear._pygsl_matrix_copy_lower_triangle(inp, out)


def test_copy_matrix_lower_triangle_not_square():
    """Currently only testing that it does not crash

    No use case yet, so just to avoid a crash in the system
    Please do not hesitate to send a pull request if your are
    in need of this functionality
    """
    inp = np.empty([3, 6])
    out = np.empty([3, 6])
    multilarge_nlinear._pygsl_matrix_copy_lower_triangle(inp, out)

    inp = np.empty([7, 2])
    out = np.empty([7, 2])
    multilarge_nlinear._pygsl_matrix_copy_lower_triangle(inp, out)

N = 10
x0 = 3
y0 = 4
x_scale = 0.5
y_scale = 7

@dataclass
class Parameters:
    x0: float
    y0: float
    x_scale: float
    y_scale: float

    def indeps(self):
        return self.x0, self.y0, self.x_scale, self.y_scale


@dataclass
class Data:
    x: Sequence[float]
    y: Sequence[float]
    z: Sequence[float]
    pars: Parameters


def function(X, data: Data):
    r"""

    .. math::

        x_s \cdot (x - x0)**2 + y_s \cdot(y - y0)**3
    """
    print("function X", X)
    x0, y0, x_scale, y_scale = X
    dx = np.asarray(data.x) - x0
    dy = np.asarray(data.y) - y0

    return x_scale * dx**2 + y_scale * dy**3


def f_func(X, data):
    return function(X, data) - data.z


def f_jac(X, data):
    print("jac X", X)
    x0, y0, xs, ys = X
    x = np.asarray(data.x)
    y = np.asarray(data.y)
    dx = x - x0
    dy = y - y0
    return np.vstack([
        - 2 * xs * dx,
        - 3 * ys * dy**2,
        dx**2,
        dy**3
    ]).T


def df_func(
        trans_j: int, X: Sequence[float], u: Sequence[float], data: Data, uses_jtj: bool
) -> Tuple[Sequence[float], Union[Sequence[Sequence[float]]], None]:

    jac = f_jac(X, data)
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
    if uses_jtj:
        JTJ = jac.T @ jac
    print("df2, u", u)
    print("df2, v", v)
    print("df2, JTJ", JTJ)
    return v, JTJ


def func_fvv(X: Sequence[float], v: Sequence[float], data: Data) -> Sequence[float]:
    x0, y0, xs, ys = X
    vx0, vy0, vxs, vys = v
    x = np.asarray(data.x)
    y = np.asarray(data.y)
    dx = x - x0
    dy = y - y0
    Dx0x0 = 2 * xs
    Dx0xs = -2 * dx
    Dy0y0 = 6 * ys * dy
    Dy0ys = -3 * dy**2

    fvv = (
            Dx0x0 * vx0 + 2 * Dx0xs * vx0 * vxs
            + Dy0y0 * vy0 **2 + 2 * Dy0ys * vy0 * vys
    )
    return fvv

def callback(iter_, params, w):
    x0, y0, x_scale, y_scale = w.position()
    print(f"iter {iter_:3d} {x0:.3f}, {y0:.3f}, {x_scale:.3f} {y_scale:.3f}")



def get_data() -> Data:
    data = Data(
        x = np.linspace(-3, 3, num=20),
        y = np.linspace(-2, 2, num=20),
        z = [],
        pars=Parameters(x0=5, y0=-1./11., x_scale=23, y_scale=1./3.)
    )
    data.z = function([data.pars.x0, data.pars.y0, data.pars.x_scale, data.pars.y_scale], data)
    return data


def test_run_df():
    """A simple test to see that functions are evaulated
    """
    data = get_data()
    n = len(data.x)
    p = 4
    parameters = multilarge_nlinear.parameters()
    parameters.set_trs(multilarge_nlinear.trs_lm)
    parameters.set_trs(multilarge_nlinear.trs_lmaccel)
    # parameters.set_trs(multilarge_nlinear.trs_cgst)
    fdf = multilarge_nlinear.fdf(
        f=f_func,
        df=df_func,
        #df= None,
        fvv = None,
        # fvv=func_fvv,
        args=data,
        n=n,
        p=p)

    workspace = multilarge_nlinear.workspace(multilarge_nlinear.trust, parameters, n, p)
    x_init = [1, .2, 1, 1]

    set_debug_level(0)
    workspace.init(x_init,  fdf)
    f = workspace.residual()

    chisq0 = np.dot(f, f)

    set_debug_level(0)

    try:
        info = multilarge_nlinear.driver(
            maxiter=10000,
            xtol=1e-12,
            gtol=1e-12,
            ftol=1e-12,
            # callback=None,
            callback=callback,
            args=data,
            workspace_o=workspace,
        )
    except errors.gsl_MaximumIterationError as ex:
        print(ex)

    x = workspace.position()
    for f, v in zip(x, data.pars.indeps()):
        print(f, v)




def test_callback_fails():
    """see if setjmp/longjmp is correctly implemented
    """
    def callback(iter_, params, w):
        raise AssertionError("should be caught")


if __name__ == "__main__":
    test_run_df()
