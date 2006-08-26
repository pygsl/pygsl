# Author : Pierre Schnizer 
import sys
import unittest
import pygsl._numobj as Numeric
from pygsl import Float
import pygsl
#print pygsl
#multiroots = pygsl.roots.multiroots
from pygsl  import multiroots
import copy

def rosenbrock_f(x, params):
    a = params[0]
    b = params[1]
    y = copy.copy(x)
    y[0] = a * (1 - x[0])
    y[1] = b * (x[1] - x[0] * x[0])
    return y

def rosenbrock_df(x, params):
    a = params[0]
    b = params[1]
    df = Numeric.zeros((x.shape[0], x.shape[0]), Float)
    df[0,0] = -a
    df[0,1] = 0
    df[1,0] = -2 * b * x[0]
    df[1,1] = b
    return df

def rosenbrock_fdf(x, params):
    f = rosenbrock_f(x, params)
    df = rosenbrock_df(x, params)
    return f, df

class DefaultCase(unittest.TestCase):

    def _getsize(self):
        return 2
    
    def _run(self, solver):
        tmp = Numeric.array((-10., -5.), Float)
        solver.set(tmp)
        for iter in range(100):
            status = solver.iterate()
            r = solver.root()
            x = solver.getx()
            f = solver.getf()
            status = multiroots.test_residual(f, 1e-7)
            if status == 0:
                break
        else:
            raise ValueError, "Number of Iterations exceeded!"
    
        assert(Numeric.absolute(x[0] - 1)<1e-6)
        assert(Numeric.absolute(x[1] - 1)<1e-6)
        assert(Numeric.absolute(f[0])<1e-6)
        assert(Numeric.absolute(f[1])<1e-6)

class FTest(DefaultCase):
    def setUp(self):
        tmp = Numeric.array((1., 10.), Float)
        self.sys = multiroots.gsl_multiroot_function(rosenbrock_f, tmp,
                                                     self._getsize())

    def test_hybrids(self):
        solver = multiroots.hybrids(self.sys, self._getsize())
        self._run(solver)
        
    def test_dnewton(self):
        solver = multiroots.dnewton(self.sys, self._getsize())
        self._run(solver)

    def test_broyden(self):
        solver = multiroots.broyden(self.sys, self._getsize())
        self._run(solver)

    def test_hybrid(self):
        solver = multiroots.hybrid(self.sys, self._getsize())
        self._run(solver)

class FDFTest(DefaultCase):
    def setUp(self):
        tmp = Numeric.array((1., 10.), Float)
        self.sys = multiroots.gsl_multiroot_function_fdf(rosenbrock_f, rosenbrock_df, rosenbrock_fdf, tmp, self._getsize())

    def test_newton(self):
        solver = multiroots.newton(self.sys, self._getsize())
        self._run(solver)
        
    def test_gnewton(self):
        solver = multiroots.gnewton(self.sys, self._getsize())
        self._run(solver)

    def test_hybridj(self):
        solver = multiroots.hybridj(self.sys, self._getsize())
        self._run(solver)

    def test_hybridsj(self):
        solver = multiroots.hybridsj(self.sys, self._getsize())
        self._run(solver)

if __name__ == '__main__':
    unittest.main()
