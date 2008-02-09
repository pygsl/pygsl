# Author : Pierre Schnizer 
import sys
import pygsl._numobj as numx
import pygsl
from pygsl import  odeiv, Float
sys.stdout = sys.stderr

mu = 10.0
def func(t, y, mu):
    #print "--> func", t, y
    f = numx.zeros((2,), Float) * 1.0
    f[0] = y[1]
    f[1] = -y[0] - mu * y[1] * (y[0] ** 2 -1);
    #print f
    return f

def jac(t, y, mu):
    #print "--> jac", t, y
    dfdy = numx.ones((2,2), Float) 
    dfdy[0, 0] = 0.0
    dfdy[0, 1] = 1.0
    dfdy[1, 0] = -2.0 * mu * y[0] * y[1] - 1.0
    dfdy[1, 1] = -mu * (y[0]**2 - 1.0)
    #print "dfdy[0, 0]", dfdy[0, 0]
    #print "dfdy[0, 1]", dfdy[0, 1]
    #print "dfdy[1, 0]", dfdy[1, 0]
    #print "dfdy[1, 1]", dfdy[1, 1] 
    dfdt = numx.zeros((2,))
    return dfdy, dfdt

def test_evolve_bsimp():
    dimension = 2
    step = odeiv.step_bsimp(dimension, func,jac, mu)
    control = odeiv.control_y_new(step, 1e-6, 1e-6)
    evolve  = odeiv.evolve(step, control, dimension)

    step1 = odeiv.step_rkf45(dimension, func,jac,mu)
    control1 = odeiv.control_y_new(step1, 1e-6, 1e-6)
    evolve1  = odeiv.evolve(step1, control1, dimension)
    
    h = 1
    t = 0.0
    t1 = 100.0
    y = numx.array((1.0, 0.0))

    while t<t1:
        t, h, y = evolve.apply(t, t1, h, y)



    sys.stdout = file
    h = 1
    t = 0.0
    t1 = 100.0
    y = (1.0, 0.0)
    while t<t1:
        t, h, y = evolve1.apply(t, t1, h, y)
    
def test_evolve():
    dimension = 2
    step = odeiv.step_bsimp(dimension, func, jac, mu)
    control = odeiv.control_y_new(step, 1e-6, 1e-6)
    evolve  = odeiv.evolve(step, control, dimension)
    h = 1
    t = 0.0
    t1 = 1.0
    y = numx.array([1.0, 0.0])
    print  step.name(), step.order()
    while t<t1:
        t, h, y = evolve.apply(t, t1, h, y)

	
    dimension = 2
    steps = (
             odeiv.step_rk2,
             odeiv.step_rk4,
             odeiv.step_rkf45,
             odeiv.step_rkck,
             odeiv.step_rk8pd,
             odeiv.step_rk2imp,
             odeiv.step_rk4imp,
             odeiv.step_gear1,
             odeiv.step_gear2)
    for s in steps:
        step = s(dimension, func, None, mu)
        print  step.name(), step.order()
        control = odeiv.control_y_new(step, 1e-6, 1e-6)
        print control.name()
        evolve  = odeiv.evolve(step, control, dimension)
        h = 1
        t = 0.0
        t1 = 1.0
        y = (1.0, 0.0)
        while t<t1/2.0:
            t, h, y = evolve.apply(t, t1, h, y)
            
        y, yerr, dydt = step.apply(t, h, y, None)
        h, msg = control.hadjust(y, yerr, dydt, h)
        assert(msg == odeiv.HADJ_DEC or
               msg == odeiv.HADJ_INC or
               msg == odeiv.HADJ_NIL
               )
        step.reset()
        evolve.reset()
        while t<t1:
            t, h, y = evolve.apply(t, t1, h, y)
	    y = y

        
def test_memory_usage():
    dimension = 2
    for i in range(1000):
        step1 = odeiv.step_bsimp(dimension, func,jac, mu)
        control1 = odeiv.control_y_new(step1, 1e-6, 1e-6)
        evolve1  = odeiv.evolve(step1, control1, dimension)
        h = 1
        t = 0.0
        t1 = 100.0
        y = (1.0, 0.0)
        y, yerr, dydt =  step1.apply(t, h, y)
        while t<t1:
            control1.hadjust(y, yerr, dydt, h)
            #t, h, y = evolve1.apply(t, t1, h, y)

    
    
def test():
    #test_memory_usage()
    test_evolve()
    test_evolve_bsimp()
    
if __name__ == '__main__':
    test()
