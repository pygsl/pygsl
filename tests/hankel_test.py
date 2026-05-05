"""Just a simple test of the API

Proper tests highly appretiated
"""
from pygsl import hankel
import numpy as np


def test_hankel_initalisation():
    a = np.linspace(0, 10, num=21)

    h = hankel.DiscreteHankelTransform(21)
    h.init(10,10)
    h.apply(a)
