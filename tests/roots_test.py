# Author : Pierre Schnizer 
import sys
from pygsl import  roots
import unittest
#import unittestgui
import pygsl._numobj as Numeric
import pygsl
sys.stdout = sys.stderr

_eps = 1e-3
def quadratic(x, params):
    #sys.stderr.write(str(params))
    a = params[0]
    b = params[1]
    c = params[2]
    tmp =  a * x ** 2 + b * x + c 
    #sys.stderr.write("\ta %f b %f c %f x %30.25f  y %30.25f\n" % (a, b, c, x, tmp))
    return tmp

def quadratic_deriv(x, params):
    a = params[0]
    b = params[1]
    c = params[2]
    dy= 2.0 * a * x + b
    #sys.stderr.write("\ta %f b %f c %f x %30.25f dy %30.25f\n" % (a, b, c, x, dy))
    return dy

def quadratic_fdf(x, params):
    y = quadratic(x, params)
    dy = quadratic_deriv(x, params)
    return y , dy

class DefaultTest(unittest.TestCase):

    def _run(self, solver):
        solver.set(0.0, 5.0)
        iter = 0
        r_expected = Numeric.sqrt(5.0)
        #print "Testing solver ", solver.name() 
        #print "%5s [%9s %9s]  %9s  %10s %9s" % ("iter", "upper", "lower", "root", "err", "err(est)")
        for iter in range(100):           
            status = solver.iterate()
            x_lo = solver.x_lower()
            x_up = solver.x_upper()
            status = roots.test_interval(x_lo, x_up, 0, 0.001)
            r = solver.root()
            if status == 0:
                break
        else:
            raise ValueError, "Exeeded maximum number of iterations!"
        assert(Numeric.absolute(r-r_expected) < _eps)
            #print "%5d [%.7f %.7f]  %.7f  % .6f % .6f" %(iter, x_lo, x_up, r, r -r_expected, x_up - x_lo)
        #print "Convereged :"    
        #print "%5d [%.7f %.7f]  %.7f  % .6f % .6f" %(iter, x_lo, x_up, r, r -r_expected, x_up - x_lo)

class FTest(DefaultTest):        
    def setUp(self):
        a = 1.0
        b = 0.0
        c = -5.0
        quadratic(0, (a,b,c))
        self.sys = roots.gsl_function(quadratic, (a,b,c))

    def test_brent(self):
        solver = roots.brent(self.sys)
        self._run(solver)

    def test_bisection(self):
        solver = roots.bisection(self.sys)
        self._run(solver)

    def test_falsepos(self):
        solver = roots.falsepos(self.sys)
        self._run(solver)


class FdFTest(DefaultTest):        
    def setUp(self):
        a = 1.0
        b = 0.0
        c = -5.0
        self.sys = roots.gsl_function_fdf(quadratic, quadratic_deriv, quadratic_fdf, Numeric.array((a,b,c)))

    def _run(self, solver):
        x = 5.0
        solver.set(x)
        r_expected = Numeric.sqrt(5.0)
        #print "Testing solver ", solver.name() 
        #print "%5s %9s  %10s %9s" % ("iter", "root", "err", "err(est)")
        ok = 1
        for iter in range(10):
            status = solver.iterate()
            x0 = x
            x = solver.root()
            status = roots.test_delta(x, x0, 0.0, 1e-3)
            r = solver.root()
            if status == 0:
                #print "Convereged :"
                ok = 0
            #print "%5d  %.7f  % .6f % .6f" %(iter, r, r -r_expected, x - x0)
            if ok == 0:
                break
        else:
            raise ValueError, "Exeeded maximum number of iterations!"
        assert(Numeric.absolute(r-r_expected) < _eps)
        
    def test_newton(self):
        solver = roots.newton(self.sys)
        self._run(solver)

    def test_secant(self):
        solver = roots.secant(self.sys)
        self._run(solver)

    def test_steffenson(self):
        solver = roots.steffenson(self.sys)
        self._run(solver)

def fn1(x, params):
    return Numeric.cos(x) + 1.0


def suite():
    suite = unittest.TestSuite()
    suite.addTest(FdFTest("test_secant"))
    suite.addTest(FdFTest("test_steffenson"))
    suite.addTest(FdFTest("test_newton"))
    suite.addTest(FTest("test_bisection"))
    suite.addTest(FTest("test_brent"))
    suite.addTest(FTest("test_falsepos"))
    return suite

def run():
    runner = unittest.TextTestRunner()
    runner.run(suite())
    
if __name__ == '__main__':
    run()
