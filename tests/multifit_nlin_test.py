#!/usr/bin/env python
# Author : Pierre Schnizer 
import sys
import unittest
import pygsl._numobj as Numeric
import random
import pygsl
from pygsl import Float
from pygsl import multifit_nlin
import copy
#import Gnuplot

exp = Numeric.exp
#g = Gnuplot.Gnuplot()
_eps = 1e-7

def testfunc(t, A = 1., _lambda = .1, b=.5):
        return  A * exp(- _lambda * t) + b

def exp_f(x, params):
    A       = x[0]
    lambda_ = x[1]
    b       = x[2]
    
    t       = params[0]
    yi      = params[1]
    sigma   = params[2]
    
    Yi = testfunc(t, A, lambda_, b)
    f = (Yi -yi) / sigma
    return f

def exp_df(x, params):
    A       = x[0]
    lambda_ = x[1]
    b       = x[2]
    
    t       = params[0]
    yi      = params[1]
    sigma   = params[2]

    e = exp(-lambda_ * t)
    e_s = e/sigma
    df = Numeric.array((e_s, -t * A * e_s, 1/sigma))
    df = Numeric.transpose(df)
    return df

def exp_fdf(x, params):
    f = exp_f(x, params)
    df = exp_df(x, params)
    return f, df

    
class DefaultCase(unittest.TestCase):
    A       = 1.
    lambda_ = .1
    b       = .5
    
    def _getn(self):
        return 40

    def _getp(self):
        return 3
    
    
    def setUp(self):
        t = Numeric.arange(self._getn());
        y = testfunc(t, self.A, self.lambda_, self.b)
        sigma = Numeric.ones(self._getn()) * 0.1
        self.data = Numeric.array((t,y,sigma), Float)
        self.sys = multifit_nlin.gsl_multifit_function_fdf(exp_f, exp_df,
                                                           exp_fdf, self.data,
                                                           self._getn(),
                                                           self._getp())

    def _run(self, solver):
        #x = Numeric.array((1.0, .4, .1))
        x = Numeric.array((1.0, 0.0, 0.0))
        solver.set(x)
        #g.title('Start')
        #g.plot(Gnuplot.Data(self.data[0], self.data[1]),
        #       Gnuplot.Data(self.data[0], testfunc(self.data[0]),
        #                    with = 'line'),
        #       )
        #raw_input()
        #print "Testing solver ", solver.name() 
        #print "%5s %9s %9s  %9s  %10s" % ("iter", "A", "lambda", "b", "|f(x)|")
        for iter in range(20):
            status = solver.iterate()
            assert(status == 0 or status == -2)
            x  = solver.getx()
            dx = solver.getdx()
            f  = solver.getf()
            J  = solver.getJ()
            tdx = multifit_nlin.gradient(J, f)
            status = multifit_nlin.test_delta(dx, x, 1e-8, 1e-8)
            #status = multifit_nlin.test_gradient(dx, 1e-4)
            fn = Numeric.sqrt(Numeric.sum(f*f))
            #g.title('Iteration')
            if status == 0:
                break
            #print "%5d % .7f % .7f  % .7f  % .7f" %(iter, x[0], x[1], x[2], fn)
            #g.plot(Gnuplot.Data(self.data[0], self.data[1]),
            #       Gnuplot.Data(self.data[0],
            #                    testfunc(self.data[0], x[0], x[1], x[2]),
            #                    with = 'line', title='iteration ' + str(iter)),
            #       )
            #raw_input()
        else:
            raise ValueError, "Number of Iterations exceeded!"
        #print "Convereged :"        
        #print "%5d % .7f % .7f  %.7f  % .7f" %(iter, x[0], x[1], x[2], fn)
        assert(Numeric.absolute(x[0] - self.A) < _eps)
        assert(Numeric.absolute(x[1] - self.lambda_) < _eps)
        assert(Numeric.absolute(x[2] - self.b) < _eps)
        #J = solver.getJ()
        #print "shape = ", J.shape
        covar =  multifit_nlin.covar(solver.getJ(), 0.0)
        #print J
        #print covar       
        #print "A      = % .5f +/- % .5f" % (x[0], covar[0,0])
        #print "lambda = % .5f +/- % .5f" % (x[1], covar[1,1])
        #print "b      = % .5f +/- % .5f" % (x[2], covar[2,2])
        #g.title('Converged!')
        #g.plot(Gnuplot.Data(self.data[0], self.data[1]),
        #       Gnuplot.Data(self.data[0],
        #                    testfunc(self.data[0], x[0], x[1], x[2]),
        #                    with = 'line', title='iteration ' + str(iter)),
        #       )
        #raw_input()
        
    def test_lmsder(self):
        solver = multifit_nlin.lmsder(self.sys, self._getn(), self._getp())
        self._run(solver)

    def test_lmder(self):
        solver = multifit_nlin.lmder(self.sys, self._getn(), self._getp())
        self._run(solver)

if __name__ == '__main__':
    unittest.main()
