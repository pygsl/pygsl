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


    b = bspline(10, nbreak)
    b.knots_uniform(x[0], x[-1])
    X = numx.zeros((N, ncoeffs))
    X = b.eval_vector(x)
    c, cov, chisq = multifit.linear(X, y)


    res_x = x[::N/64]
    X = b.eval_vector(res_x)
    res_y, res_y_err = multifit.linear_est_matrix(X, c, cov)

    pylab.plot(x,y, '-')
    pylab.errorbar(res_x, res_y, fmt='g-', xerr=res_y_err)    

if __name__ == '__main__':
    run()
