# Author : Pierre Schnizer
from __future__ import print_function
import unittest

import sys
import pygsl._numobj as numx
import pygsl
from pygsl import errno, errors, odeiv2, Float


mu = 10.0
def func(t, y, mu):
    f = numx.zeros((2,), Float) * 1.0
    f[0] = y[1]
    f[1] = -y[0] - mu * y[1] * (y[0] ** 2 -1);
    return f

def jac(t, y, mu):
    dfdy = numx.ones((2,2), Float)
    dfdy[0, 0] = 0.0
    dfdy[0, 1] = 1.0
    dfdy[1, 0] = -2.0 * mu * y[0] * y[1] - 1.0
    dfdy[1, 1] = -mu * (y[0]**2 - 1.0)
    dfdt = numx.zeros((2,))
    return dfdy, dfdt


_adjustments = odeiv2.hadj_dec, odeiv2.hadj_nil, odeiv2.hadj_inc

class _OdeivTestBasis(unittest.TestCase):
    '''Finally implemented as test class

    Todo:
        Implement checks for results
    '''
    def createStep(self):
        return odeiv2.pygsl_odeiv2_step(self.stepper, self.dimension)

    def createControl(self):
        a_y = 1
        a_dydt = 0
        return odeiv2.pygsl_odeiv2_control(1e-6, 1e-6, a_y, a_dydt, None)

    def createEvolve(self):
        evolve  = odeiv2.pygsl_odeiv2_evolve(self.dimension)
        return evolve

    def createDriver(self):
        a_y = 1
        a_dydt = 0
        eps_abs = 1e-6
        eps_rel = 1e-6
        hstart = .1
        sys = self.createSystem()
        driver = odeiv2.pygsl_odeiv2_driver
        return driver(sys, self.stepper, hstart, eps_abs, eps_rel, a_y, a_dydt, None)

    def test01_step(self):
        '''Stepper name
        '''
        step = self.createStep()
        name = step.name()
        self.assertEqual(type(name), type(''))

    def test10_control(self):
        control = self.createControl()
        name = control.name()
        self.assertEqual(type(name), type(''))

    def test11_control(self):
        '''Basic control functionality
        '''
        control = self.createControl()
        step = self.createStep()
        y = numx.array((1.0, 0.0))
        yerr = numx.array((.1, 0.0))
        dydt = numx.array((.01, 0.0))
        h = 0.1
        msg, h = control.hadjust(step, y, yerr, dydt, h)

        self.assertIn(msg, _adjustments)
        self.assertEqual(msg, odeiv2.hadj_dec)

    def test20_evolve(self):
        evolve = self.createEvolve()

    def test31_driver(self):
        driver = self.createDriver()
        driver.set_hmin(1.0)

    def test32_driver(self):
        driver = self.createDriver()
        driver.set_hmin(0.0)

    def test33_driver(self):
        driver = self.createDriver()
        driver.set_hmin(1.0)
        driver.set_hmax(0.0)

    def test33_driver(self):
        driver = self.createDriver()
        driver.set_hmin(1.0)
        driver.set_hmax(0.0)

    def test34_driver(self):
        '''Maximum number of steps: 10 steps

        '''
        driver = self.createDriver()
        driver.set_nmax(10)

    def test35_driver(self):
        '''Maximum number of steps: 0=infinite steps

        '''
        driver = self.createDriver()
        driver.set_nmax(0)

    def test36_driver(self):
        '''Maximum number of steps: 0=infinite steps

        '''
        driver = self.createDriver()
        self.assertRaises(OverflowError, driver.set_nmax, -1)


class _TestDriver(_OdeivTestBasis):
    def test40_driver(self):
        '''Execute driver
        '''
        driver = self.createDriver()
        y = numx.array((1.0, 0.0))
        t = 0
        t1 = 0.1
        t, y  = driver.apply(t, t1, y)

class _TestAll(_TestDriver):
    def test02_step(self):
        '''Basic stepper functionality
        '''
        sys = self.createSystem()
        step = self.createStep()

        t = 0.
        h = .1
        y = numx.array([1.0, 0.0])
        y, yerr, dydt = step.apply(t, h, y, None, None, sys)

    def test21_evolve(self):
        sys = self.createSystem()
        step = self.createStep()
        control = self.createControl()
        evolve = self.createEvolve()

        h = 1
        t = 0.0
        t1 = 1.0
        y = (1.0, 0.0)
        while t<t1:
            status, t, h, y = evolve.apply(control, step, sys, t, t1, h, y)
            self.assertEqual(status, errno.GSL_SUCCESS)
            pass


class _FuncJac:
    dimension = 2

    def createSystem(self):
        return odeiv2.system(func, jac, self.dimension, mu)

class _Func:
    dimension = 2

    def createSystem(self):
        return odeiv2.system(func, None, self.dimension, mu)


class _OdeivTestErrorReported(_OdeivTestBasis):
    exception = None
    dimension = 2

    def test02_step(self):
        '''Basic stepper functionality
        '''
        sys = self.createSystem()
        step = self.createStep()

        t = 0.
        h = .1
        y = numx.array([1.0, 0.0])
        args =  t, h, y, None, None, sys
        self.assertRaises(self.exception, step.apply, *args)

    def test21_evolve(self):
        sys = self.createSystem()
        step = self.createStep()
        control = self.createControl()
        evolve = self.createEvolve()

        t = t1 = h = 0
        y = [0, 0]
        args = control, step, sys, t, t1, h, y
        self.assertRaises(self.exception, evolve.apply, *args)

class _OdeivTestRequiresJac(_OdeivTestErrorReported):
    exception = errors.gsl_InvalidArgumentError

class _OdeivTestRequiresDriver(_OdeivTestErrorReported):
    exception = errors.gsl_PointerError


# Test if missing driver / jacobian is reported appropriatly
# and does not result in a crash

# these would crash if not checked by pygsl that no jacobian is available
class OdeivTestStepBsimpWithoutJac(_OdeivTestRequiresJac, _Func):
    stepper = odeiv2.step_bsimp

class OdeivTestStepMsBdfF(_OdeivTestRequiresJac, _Func):
    stepper = odeiv2.step_msbdf

class OdeivTestStepRK1IMPF(_OdeivTestRequiresJac, _Func):
    stepper = odeiv2.step_rk1imp

class OdeivTestStepRK2IMPF(_OdeivTestRequiresJac, _Func):
    stepper = odeiv2.step_rk2imp

class OdeivTestStepRK4IMPF(_OdeivTestRequiresJac, _Func):
    stepper = odeiv2.step_rk4imp


class OdeivTestStepMsAdamsWithoutDriver(_OdeivTestRequiresDriver, _FuncJac):
    stepper = odeiv2.step_msadams

class OdeivTestStepMsBdfWithoutDriver(_OdeivTestRequiresDriver, _FuncJac):
    stepper = odeiv2.step_msbdf

class OdeivTestStepRk1ImpWithoutDriver(_OdeivTestRequiresDriver, _FuncJac):
     stepper = odeiv2.step_rk1imp

class OdeivTestStepRk2ImpWithoutDriver(_OdeivTestRequiresDriver,  _FuncJac):
     stepper = odeiv2.step_rk2imp

class OdeivTestStepRk4impWithoutDriver(_OdeivTestRequiresDriver, _FuncJac):
     stepper = odeiv2.step_rk4imp


## Just standard functional tests below
# with jacobian

class OdeivTestStepBsimpWJ(_TestAll, _FuncJac):
    stepper = odeiv2.step_bsimp

class OdeivTestStepRk2WJ(_TestAll, _FuncJac):
     stepper = odeiv2.step_rk2

class OdeivTestStepRk4WJ(_TestAll, _FuncJac):
     stepper = odeiv2.step_rk4

class OdeivTestStepRkF45WJ(_TestAll, _FuncJac):
    stepper = odeiv2.step_rkf45

class OdeivTestStepRKCkWJ(_TestAll, _FuncJac):
    stepper = odeiv2.step_rkck

class OdeivTestStepRK8PdWJ(_TestAll, _FuncJac):
    stepper = odeiv2.step_rk8pd

class OdeivTestStepMsAdamsWJ(_TestDriver, _FuncJac):
    stepper = odeiv2.step_msadams

class OdeivTestStepMsBdfWJ(_TestDriver, _FuncJac):
    stepper = odeiv2.step_msbdf

class OdeivTestStepRK1IMPWJ(_TestDriver, _FuncJac):
    stepper = odeiv2.step_rk1imp

class OdeivTestStepRK1IMPWJ(_TestDriver, _FuncJac):
    stepper = odeiv2.step_rk2imp

class OdeivTestStepRK1IMPWJ(_TestDriver, _FuncJac):
    stepper = odeiv2.step_rk4imp

# without jacobian

class OdeivTestStepRK2(_TestAll, _Func):
       stepper = odeiv2.step_rk2

class OdeivTestStepRK4(_TestAll, _Func):
       stepper = odeiv2.step_rk4

class OdeivTestStepRkF45(_TestAll, _Func):
    stepper = odeiv2.step_rkf45

class OdeivTestStepRKCk(_TestAll, _Func):
     stepper = odeiv2.step_rkck

class OdeivTestStepRK8Pd(_TestAll, _Func):
    stepper = odeiv2.step_rk8pd

class OdeivTestStepMsAdamsF(_TestDriver, _Func):
    stepper = odeiv2.step_msadams

# pygsl.init.set_debug_level(3)

del _Func, _FuncJac
# del _OdeivTestWithJac, _OdeivTestWithoutJac
del _TestDriver, _TestAll
del _OdeivTestBasis
del _OdeivTestRequiresJac, _OdeivTestRequiresDriver
del _OdeivTestErrorReported
# del _OdeivTestBasisFunctionalStepper, _OdeivTestBasis,


if __name__ == '__main__':
    unittest.main()
