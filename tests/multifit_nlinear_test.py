#!/usr/bin/env python
import unittest
import numpy as np
import pygsl
from pygsl import multifit_nlinear, errors


class TestNotWorkingCallback(unittest.TestCase):
    def test_returns(self):
        def f(x, args):
            a, b = x
            y = a * x + b
            Y = args
            dy = Y - y
            return dy

        def df(x, args):
            a, b = x
            da = a
            db = 0
            Y = args
            l = len(Y)
            df = np.zeros((l, 2), np.float_)
            df[:,0] = da
            return df

        def fvv(x, args):
            msg = "Testing if returned to calling function"
            raise errors.gsl_InvalidArgumentError(msg)
    
