#!/usr/bin/env python
# Author : Pierre Schnizer
"""
Integration of sin(x)/x from -infinity to + infinity.

Here the combined usage if qawf and qagp is shown. Qagp is used to integrate
the "numerical singularity" (please could someone change it to the approbriate
expression?) x = 0. qawf is used to integrate towards infinity.

"""
from  pygsl import integrate
from  pygsl import _numobj as numx

def run():
    def f2(x,y):
        return numx.sin(x) / x
    sys2 = integrate.gsl_function(f2, None)
    
    def f1(x,y):
        return 1 / x        
    sys1 = integrate.gsl_function(f1, None)
    
    def f3(x,y):
        return 1 / -x
    
    sys3 = integrate.gsl_function(f3, None)

    w = integrate.workspace(1000000)
    cyclew = integrate.workspace(1000000)
    
    table1 = integrate.qawo_table(1, 100, integrate.SINE, 100)
    table2 = integrate.qawo_table(-1, 100, integrate.SINE, 100)

    # Borders and singualrity for gagp
    pts = numx.array((-numx.pi, 0, numx.pi))
    
    flag, result1, error = integrate.qagp(sys2, pts, 1e-8, 1e-8, 100000, w)
    flag, result2, error = integrate.qawf(sys1, numx.pi, 1e-8,  100, w,
                                          cyclew, table1)
    flag, result3, error = integrate.qawf(sys3, numx.pi, 1e-8,  100, w,
                                          cyclew, table2)
    
    print "Result of integration is :", result1 + result2 + result3

if __name__ == '__main__':
    run()
