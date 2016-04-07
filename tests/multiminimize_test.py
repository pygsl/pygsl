import unittest
from pygsl import multiminimize, errno
import pygsl._numobj as numx

def my_f(v, params):
    x = v[0]
    y = v[1]
    
    dp = params
    t1  = (x - dp[0])
    t2  = (y - dp[1])
    f = 10.0 * t1 * t1 + 20.0 * t2 * t2 + 30.0
    return f 

def my_df(v, params):
    x = v[0]
    y = v[1]
    df = numx.zeros(v.shape, ) * 1.
    dp = params
    df[0] = 20. * (x - dp[0])
    df[1] = 40. * (y - dp[1])
    return df

def my_fdf(v, params):
    f = my_f(v, params)
    df = my_df(v,params)
    return f, df


class _multiminminimize_tests(unittest.TestCase):
    """
    """
    _t_type = None

    _start_point = numx.array((5., 7.), )
    _initial_steps = numx.array((0.1, 0.1), )

    def _assertIsNotNone(self, val):
        self.assertNotEqual(val, None)

    def _checkPos(self, pos):
        x  = pos[0]
        y  = pos[1]
        self.assertAlmostEqual(x, 1, places = 1)
        self.assertAlmostEqual(y, 2, places = 1)

    def _checkF(self, f):
        self.assertAlmostEqual(f, 30, places = 1)


class _multiminminimize_f_solver_tests(_multiminminimize_tests):

    def setUp(self):
        self._assertIsNotNone(self._t_type)
        tmp = numx.array((1., 2.), )
        self._dim = 2
        self._sys = multiminimize.gsl_multimin_function(my_f, tmp, self._dim)
        self._solver = self._t_type(self._sys, self._dim)
        
    def _getMaxIter(self):
        return 35

    def _setStartPoint(self):
        self._solver.set(self._start_point, self._initial_steps)
        
    def test10Set(self):
        self._setStartPoint()

    def test20Run(self):
        maxiter = self._getMaxIter()

        self._setStartPoint()

        for cnt in range(maxiter):
            status = self._solver.iterate()            
            if status != errno.GSL_SUCCESS:
                break
            ssval = self._solver.size()
            rval = multiminimize.test_size (ssval, 1e-2);

            if rval == 0:
                break

        self.assertNotEqual(maxiter - 1, cnt)
        
        fval = self._solver.getf()
        x = self._solver.getx()
        self._checkPos(x)
        self._checkF(fval)


class _multiminminimize_fdf_solver_tests(_multiminminimize_tests):

    def setUp(self):
        self._assertIsNotNone(self._t_type)

        self._dim = 2        
        params = numx.array((1., 2.), )        
        self._sys = multiminimize.gsl_multimin_function_fdf(my_f, my_df, my_fdf, params, self._dim)
        self._solver = self._t_type(self._sys, self._dim)
        
    def _getMaxIter(self):
        return 14

    def _setStartPoint(self):
        self._solver.set(self._start_point, 0.01, 1e-4)
        
    def test10Set(self):
        self._setStartPoint()

    def test20Run(self):
        maxiter = self._getMaxIter()
        self._setStartPoint()
        
        for cnt in range(maxiter):
            status = self._solver.iterate()
            gradient = self._solver.gradient()
            status = multiminimize.test_gradient(gradient, 1e-3)
            if status == errno.GSL_SUCCESS:
                break
        self.assertNotEqual(maxiter - 1, cnt)

        x    = self._solver.getx()
        fval = self._solver.getf()

        self._checkPos(x)
        self._checkF(fval)

class vector_bfgs(_multiminminimize_fdf_solver_tests):
    _t_type = multiminimize.vector_bfgs
    
class conjugate_pr(_multiminminimize_fdf_solver_tests):
    _t_type = multiminimize.conjugate_pr

class conjugate_fr(_multiminminimize_fdf_solver_tests):
    _t_type = multiminimize.conjugate_fr

#class steepest_descent(_multiminminimize_fdf_solver_tests):
#    _t_type = multiminimize.steepest_descent
#    def _getMaxIter(self):
#        return 200
    
for name in ("vector_bfgs2",):
    try:
        _solver_type = getattr(multiminimize, name)
    except AttributeError:
        print("Solver %s not available for your installation" %(name,))
        continue
    
    t_test ="class %s(_multiminminimize_fdf_solver_tests): _t_type = _solver_type"
    t_test = t_test %(name,)
    exec(t_test)
    
for name in ("nmsimplex", "nmsimplex2", "nmsimplex2rand"):
    try:
        _solver_type = getattr(multiminimize, name)
    except AttributeError:
        print("Solver %s not available for your installation" %(name,))
        continue
    
    t_test ="class %s(_multiminminimize_f_solver_tests): _t_type = _solver_type"
    t_test = t_test %(name,)
    exec(t_test)

del _solver_type

del _multiminminimize_tests
del _multiminminimize_f_solver_tests
del _multiminminimize_fdf_solver_tests

    
def fdf_solver():
    #solver = multiminimize.conjugate_pr(sys, 2)
    #solver = multiminimize.conjugate_fr(sys, 2)
    #solver = multiminimize.vector_bfgs(sys, 2)
    #solver = multiminimize.vector_bfgs2(sys, 2)
    solver = multiminimize.steepest_descent(sys, 2)
    start = numx.array((5., 7.), )
    solver.set(start, 0.01, 1e-4)
    print( "Using solver ", solver.name() )
    print( "%5s %9s %9s  %9s %9s %9s" % ("iter", "x", "y", "f", "dx", "dy"))
    for iter in range(200):
        status = solver.iterate()
        gradient = solver.gradient()
        x = solver.getx()
        f = solver.getf()
        status = multiminimize.test_gradient(gradient, 1e-3)
        if status == errno.GSL_SUCCESS:
            print( "Converged ")
        print( "%5d % .7f % .7f  % .7f % .7f % .7f" %(iter, x[0], x[1], f, gradient[0], gradient[1]))
        if status == errno.GSL_SUCCESS:
            break

    else:
        raise ValueError("Number of Iterations exceeded!")

if __name__ == '__main__':
    unittest.main()
