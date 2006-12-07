#!/usr/bin/env python
# Author : Pierre Schnizer
"""
The geometric function is described using a chebyshev series with 6 terms.
It will print the results to stdout.

I have to find the paper describing this application.
"""

from pygsl import chebyshev
from pygsl import _numobj as numx


def run():
    # The geometric function
    func = lambda x,y  : 1 / (1 + x)
    mysys = chebyshev.gsl_function(func, None)
    # The series
    series = chebyshev.cheb_series(6)

    series.init(mysys, 0, 2)
    # and its coefficients

    # Make a new series object. 
    series1 = chebyshev.cheb_series(6)
    #series1.init(mysys, 0, 2)
    series1.set_a(series.get_a())
    series1.set_b(series.get_b())
    series1.set_coefficients(series.get_coefficients()*2)

    # Two items of the gsl_cheb_struct the documentation does not mention.
    series1.set_order_sp(series.get_order_sp())
    series1.set_f(series.get_f())


    x = numx.arange(100) / 50.
    y = map(lambda x, s=series: s.eval_n(6, x), x)
    y1 = map(lambda x, s=series1: s.eval_n(6, x), x)
    #print "#     x      \t      y      \t      z"
    #for i in numx.arange(x.shape[0]):
    #    print "% 10.7f\t % 10.7f\t % 10.7f" % (x[i],  y[i], y1[i])
if __name__ == '__main__':
    run()
