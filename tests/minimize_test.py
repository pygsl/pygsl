# Author : Pierre Schnizer 
import sys
import unittest
import pygsl._numobj as Numeric
import pygsl
from pygsl import minimize



def fn1(x, params):
    return Numeric.cos(x) + 1.0

class MinTest(unittest.TestCase):
    def setUp(self):
        self.sys = minimize.gsl_function(fn1, None)

    def _run(self, minimizer):
        m = 2.0
        a = 0.0
        b = 6.0
        m_expected = Numeric.pi
        minimizer.set(m, a, b)
        t1 = fn1(a, None)
        t2 = fn1(b, None)
        minimizer.set_with_values(m, fn1(m, None), a, t1, b, t2)
        #print "Testing minimizer ", minimizer.name()
        #print "%5s [%9s %9s]  %9s  %10s %9s" % ("iter", "upper", "lower", "min", "err", "err(est)")
        for iter in range(100):
            status = minimizer.iterate()
            a      = minimizer.x_lower()
            b      = minimizer.x_upper()
            m      = minimizer.minimum()
            status = minimize.test_interval(a, b, 0.001, 0)
            #if status == 0:
                #print "Converged: "
            #print "%5d [%.7f %.7f]  %.7f + % .6f % .6f" %(iter, a, b, m, m -m_expected, b - a)
            if status == 0:
                break
        else:
            raise ValueError, "Number of Iterations exceeded!"
        assert(Numeric.absolute(m - m_expected)<0.001)
        
    def test_brent(self):
        minimizer = minimize.brent(self.sys)
        self._run(minimizer)

    def test_golden(self):
        minimizer = minimize.goldensection(self.sys)
        self._run(minimizer)

def run():
    unittest.main()

if __name__ == '__main__':
    run()
