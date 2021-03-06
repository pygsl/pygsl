from __future__ import print_function
import pygsl
import pygsl._numobj as numx
import pygsl.rng
import pygsl.multifit
import pygsl.init

def calculate(x, y, sigma):
    n = len(x)
    X = numx.ones((n,3),)*1.
    X[:,0] = 1.0
    X[:,1] = x
    X[:,2] = x ** 2
    w = 1.0 / sigma ** 2
    work = pygsl.multifit.linear_workspace(n,3)
   # pygsl.init.set_debug_level(3)
    print (X.shape, w.shape)
    #c, cov, chisq = pygsl.multifit.linear(X, y, work)
    #c, cov, chisq = pygsl.multifit.linear(X, y)
    pygsl.init.set_debug_level(3)
    c, cov, chisq = pygsl.multifit.wlinear(X, w, y, work)

    
    print ("# best fit: Y = %g + %g * X + %g * X ** 2" % tuple(c))
    print ("# covariance matrix #")
    print ("[[ %+.5e, %+.5e, %+.5e ] " % tuple(cov[0,:]))
    print (" [ %+.5e, %+.5e, %+.5e ] " % tuple(cov[1,:]))
    print (" [ %+.5e, %+.5e, %+.5e ]]" % tuple(cov[2,:]))
    print ("# chisq  = %g " % chisq)
    return c, cov, chisq

def generate_data():
    r = pygsl.rng.mt19937()
    a = numx.arange(20) / 10.# + .1
    y0 = numx.exp(a)
    sigma = 0.1 * y0
    tmp = tuple(map(r.gaussian, sigma))
    dy = numx.array(tmp)
    tmp = y0 + dy
    return a, tmp,  sigma
     
if __name__ == '__main__':
    x, y, sigma = generate_data()
    data = (x, y, sigma)
    data = numx.array(data).transpose()

    for tmp in data:
        print ("%e %e %e" % tuple(tmp))
        
    #c, cov , chisq = calculate(x, y, sigma)
    #import Gnuplot
    #g = Gnuplot.Gnuplot()
    #xref = numx.arange(100) / 50.
    #yref = c[0] + c[1] * xref + c[2] * xref **2
    #t1 = Gnuplot.Data(x,y, with='points')
    #t2 = Gnuplot.Data(xref, yref, with='line')
    #g.plot(t1,t2)
    #print "Press return !"
    #raw_input()

