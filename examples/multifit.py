import Numeric
import pygsl
import pygsl.rng
import pygsl.multifit

def calculate(x, y, sigma):
    n = len(x)
    X = Numeric.ones((n,3), Numeric.Float)
    X[:,0] = 1.0
    X[:,1] = x
    X[:,2] = x ** 2
    w = 1.0 / sigma ** 2
    work = pygsl.multifit.linear_workspace(n,3)
    flag, c, cov, chisq = pygsl.multifit.wlinear(X, w, y, work)
    #flag, c, cov, chisq = pygsl.multifit.linear(X, y, work)
    assert(flag == 0)
    
    print "# best fit: Y = %g + %g * X + %g * X ** 2" % tuple(c)
    print "# covariance matrix #"
    print "[[ %+.5e, %+.5e, %+.5e ] " % tuple(cov[0,:])
    print " [ %+.5e, %+.5e, %+.5e ] " % tuple(cov[1,:])
    print " [ %+.5e, %+.5e, %+.5e ]]" % tuple(cov[2,:])
    print "# chisq  = %g " % chisq
    return c, cov, chisq

def generate_data():
    r = pygsl.rng.rng_mt19937()
    a = Numeric.arange(20) / 10.# + .1
    y0 = Numeric.exp(a)
    sigma = 0.1 * y0
    dy = Numeric.array(map(r.gaussian, sigma))
    return a, y0+dy,  sigma
     
if __name__ == '__main__':
    x, y, sigma = generate_data()
    c, cov , chisq = calculate(x, y, sigma)
    import Gnuplot
    g = Gnuplot.Gnuplot()
    xref = Numeric.arange(100) / 50.
    yref = c[0] + c[1] * xref + c[2] * xref **2
    t1 = Gnuplot.Data(x,y, with='points')
    t2 = Gnuplot.Data(xref, yref, with='line')
    g.plot(t1,t2)
    print "Press return !"
    raw_input()

