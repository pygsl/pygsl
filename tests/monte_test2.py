#!/usr/bin/env python
import pygsl._numobj as Numeric
import pygsl.monte as monte
import pygsl.rng

import unittest

def g(k, params):
    return k[0]

sys =  monte.gsl_monte_function(g, None, 1)
r = pygsl.rng.mt19937_1999()
xl = [ 0, ]
xu = [ 1, ]
exact = 0.5
accepted_error = 0.2
s = monte.Plain(1)
s.init()
calls = 100
status, res, err = s.integrate(sys, xl, xu, calls, r)
assert(Numeric.absolute(res - exact) < accepted_error)


