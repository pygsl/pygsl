import pygsl
from pygsl import bspline, multifit
import pygsl._numobj as numx
import pylab

bspline = bspline.bspline

ncoeffs = 8
nbreak  = ncoeffs - 2
def run():
    N = 1024
    x = numx.arange(N) * (numx.pi * 2 / N)
    y = numx.sin(x)


    b = bspline(4, nbreak)
    k = b.get_internal_knots()
    pygsl.set_debug_level(10)
    b.knots(k) 
    X = b.eval_vector(x)
    c, cov, chisq = multifit.linear(X, y)

    b.set_coefficients_and_covariance_matrix(c, cov)
    
    res_x = x[::N/64]
    res_y, res_y_err = b.eval_dep_yerr_vector(res_x)
    #res_y = b.eval_dep_vector(res_x)

    print res_y
    pylab.plot(x,y, '-')
    pylab.errorbar(res_x, res_y, fmt='g-', xerr=res_y_err)    

if __name__ == '__main__':
    run()
