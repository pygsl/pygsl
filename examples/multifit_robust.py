"""
Pythonic version of the gsl multfit robust example

A plot function using matplotlib is provided, which shows the results.
"""
from __future__ import print_function, division
import pygsl
import pygsl.multifit_robust as fr
import pygsl.rng as rng
import pygsl._numobj as numx


def run():
    r = rng.rng()

    # slope
    a = 1.45
    # intercept
    b = 3.88


    # Generate the data
    n = 20
    i = numx.arange(n-3)
    dx = 10.0 / (n - 1.0)
    e = r.uniform(n)
    x = -5.0 +  i * dx
    y = a * x + b

    #outliers 
    xo = numx.array([4.1, 3.5, 4.7])
    yo = numx.array([-6.0, -6.7, -8.3])

    x = numx.concatenate((x, xo))
    y = numx.concatenate((y, yo))

    X = numx.array([x*0+1, x]).transpose()
    ws = fr.workspace(*((fr.ols,) + X.shape) )
    c_ols, cov_ols = ws.fit(X,y)
    ws = fr.workspace(*((fr.bisquare,) + X.shape) )
    c, cov = ws.fit(X,y)

    y_rob = numx.zeros(n, numx.float_)
    y_ols = numx.zeros(n, numx.float_)

    yerr_rob = numx.zeros(n, numx.float_)
    yerr_ols = numx.zeros(n, numx.float_)

    pygsl.set_debug_level(0)
    fr.est(X[0,:], c, cov)
    y_rob, yerr_rob = fr.est_vector(X, c, cov)
    pygsl.set_debug_level(0)
    y_ols, yerr_ols = fr.est_vector(X, c_ols, cov_ols)

    return x, y, (y_rob, yerr_rob), (y_ols, yerr_ols)

def plot(tmp):
    import matplotlib
    import matplotlib.pyplot as plt
    
    x, y, (y_rob, yerr_rob), (y_ols, yerr_ols) = tmp
    plt.figure(1)
    plt.hold(0)
    plt.plot(x,y,'ks')
    plt.hold(1)
    plt.errorbar(x, y_rob, fmt='b-+', yerr=yerr_rob)
    plt.errorbar(x, y_ols, fmt='g-x', yerr=yerr_ols)
    

if __name__ == '__main__':
    tmp = run()
    plot(tmp)
