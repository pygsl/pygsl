#!/usr/bin/env python
# Author : Pierre Schnizer
"""
The geometric function is described using a chebyshev series with 6 terms.
It will print the results to stdout.

I have to find the paper descirbing this application.
"""
import Numeric
from  pygsl import chebyshev

def run():
    func = lambda x,y  : 1 / (1 + x)
    mysys = chebyshev.gsl_function(func, None)
    series = chebyshev.cheb_series(1000)
    series.init(mysys, 0, 2)
    for i in range(100):
        x = i / 50. + 0 
        print x, series.eval_n(6, x)
if __name__ == '__main__':
    run()
