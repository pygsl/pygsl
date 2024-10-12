from dataclasses import dataclass
from typing import Sequence

import numpy as np
from pygsl.multifit_nlinear import parameters, fdf, trust, workspace, driver
import pytest


@dataclass
class Data:
    t: Sequence[float]
    y: Sequence[float]

def linear(pars, data):
    a, b = pars
    f = a + b * data.t
    return (f - data.y)


def test_with_linear():
    pars = parameters()
    a = 2
    b = 5

    x_init = [0,0]
    t = np.arange(-2, 2)
    data = Data(t=t, y=a + b * t)
    solver = fdf(f=linear, df=None, fvv=None, args=data, n=len(t), p=2)
    #: todo find out how should it be named:
    ws = workspace(trust, pars, len(t), 2)
    ws.init(x_init, solver)
    info = driver(
        maxiter=10,
        xtol=1e-12,
        gtol=1e-12,
        ftol=1e-12,
        callback=None,
        args=data,
        workspace=ws,
    )

    a_e, b_e = ws.position()
    assert a_e == pytest.approx(a, 1e-12, 1e-12)
    assert b_e == pytest.approx(b, 1e-12, 1e-12)
    assert ws.niter() > 0
