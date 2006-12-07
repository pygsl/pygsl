#!/usr/bin/env python
"""
Computation of the integral,

I = int (dx dy dz)/(2pi)^3  1/(1-cos(x)cos(y)cos(z))

over (-pi,-pi,-pi) to (+pi, +pi, +pi).  The exact answer
is Gamma(1/4)^4/(4 pi^3).  This example is taken from
C.Itzykson, J.M.Drouffe, "Statistical Field Theory -
Volume 1", Section 1.1, p21, which cites the original
paper M.L.Glasser, I.J.Zucker, Proc.Natl.Acad.Sci.USA 74
1800 (1977)
     
For simplicity we compute the integral over the region
(0,0,0) -> (pi,pi,pi) and multiply by 8
""" 
import exceptions
import sys
sys.stdout = sys.stderr

import pygsl._numobj as numx
import pygsl
import pygsl.rng
import pygsl.monte as monte

exact = 1.3932039296856768591842462603255
calls = 50000
r = pygsl.rng.mt19937_1999()

xl = [ 0, 0, 0 ]
M_PI = numx.pi
xu = [ M_PI, M_PI, M_PI ]


A = 1.0 / numx.pi**3

def g(k, params):    
    numx.cos(k,k)    
    return A / (1.0 - numx.multiply.reduce(k))

G =  monte.gsl_monte_function(g, None, 3)

def display_results (title, result, error):
    print "%s ==================" %  title
    print "result = % .6f" % result
    print "sigma  = % .6f" % error
    print "exact  = % .6f" % exact
    t = (result - exact, numx.absolute(result - exact) / error)
    print "error  = % .6f = %.1g sigma" % t


def run_plain():
    s = monte.plain(3)
    s.init()
    res, err = s.integrate(G, xl, xu, calls, r)
    display_results ("plain", res, err)    

def run_miser():
    s = monte.miser(3)
    s.init()
    res, err = s.integrate(G, xl, xu, calls, r)
    display_results ("miser", res, err)    

def run_vegas():
    s = monte.vegas(3)
    s.init()

    res, err = s.integrate(G, xl, xu, 10000, r)
    display_results ("vegas warm-up", res, err)

    print "converging..."
    while 1:
        res, err = s.integrate(G, xl, xu, calls/5, r)
        chisq = s.get_chisq()
        print "result = % .6f sigma = % .6f chisq/dof = %.1f" % (res, err, chisq);
        if (numx.absolute(chisq - 1.0) <= 0.5):    
            display_results("vegas final", res, err)
            break

def run():
    run_plain()
    run_miser()
    run_vegas()
    
if __name__ == '__main__':
    run()
