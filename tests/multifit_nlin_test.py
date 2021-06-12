#!/usr/bin/env python
# Author : Pierre Schnizer
# $Id$

from __future__ import print_function
import sys
import unittest
import pygsl._numobj as Numeric
import random
import pygsl
from pygsl import Float
from pygsl import multifit_nlin
import copy

exp = Numeric.exp
_eps = 1e-7

def examplefunc(t, A = 1., _lambda = .1, b=.5):
        return  A * exp(- _lambda * t) + b

def exp_f(x, params):
    A       = x[0]
    lambda_ = x[1]
    b       = x[2]
    
    t       = params[0]
    yi      = params[1]
    sigma   = params[2]
    
    Yi = examplefunc(t, A, lambda_, b)
    f = (Yi -yi) / sigma
    return f

def exp_df(x, params):
    A       = x[0]
    lambda_ = x[1]
    b       = x[2]
    
    t       = params[0]
    yi      = params[1]
    sigma   = params[2]

    e = exp(-lambda_ * t)
    e_s = e/sigma
    df = Numeric.array((e_s, -t * A * e_s, 1/sigma))
    df = Numeric.transpose(df)
    return df

def exp_fdf(x, params):
    f = exp_f(x, params)
    df = exp_df(x, params)
    return f, df

    
class DefaultCase(unittest.TestCase):
    A       = 1.
    lambda_ = .1
    b       = .5
    
    def _getn(self):
        return 40

    def _getp(self):
        return 3
    
    
    def setUp(self):
        t = Numeric.arange(self._getn());
        y = examplefunc(t, self.A, self.lambda_, self.b)
        sigma = Numeric.ones(self._getn()) * 0.1
        self.data = Numeric.array((t,y,sigma), Float)
        self.sys = multifit_nlin.gsl_multifit_function_fdf(exp_f, exp_df,
                                                           exp_fdf, self.data,
                                                           self._getn(),
                                                           self._getp())

    def _run(self, solver):
        x = Numeric.array((1.0, 0.0, 0.0))
        solver.set(x)
        for iter in range(20):
            status = solver.iterate()
            assert(status == 0 or status == -2)
            x  = solver.getx()
            dx = solver.getdx()
            f  = solver.getf()
            J  = solver.getJ()
            tdx = multifit_nlin.gradient(J, f)
            status = multifit_nlin.test_delta(dx, x, 1e-8, 1e-8)
            fn = Numeric.sqrt(Numeric.sum(f*f))
            if status == 0:
                break
        else:
            raise ValueError("Number of Iterations exceeded!")
        assert(Numeric.absolute(x[0] - self.A) < _eps)
        assert(Numeric.absolute(x[1] - self.lambda_) < _eps)
        assert(Numeric.absolute(x[2] - self.b) < _eps)
        covar =  multifit_nlin.covar(solver.getJ(), 0.0)
        
    def test_lmsder(self):
        solver = multifit_nlin.lmsder(self.sys, self._getn(), self._getp())
        self._run(solver)

    def test_lmder(self):
        solver = multifit_nlin.lmder(self.sys, self._getn(), self._getp())
        self._run(solver)
	
    def test_lmniel(self):
        try:
             _type = multifit_nlin.lmniel
        except AttributeError:
             print("Solver lmniel not available for your GSL version")

        solver = _type(self.sys, self._getn(), self._getp())
        self._run(solver)


if __name__ == '__main__':
    unittest.main()
