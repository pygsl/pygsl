from __future__ import print_function
import pygsl
import pygsl.init
import pygsl.errno as errno
import pygsl._numobj as numx
import pygsl.odeiv2 as odeiv2

step = odeiv2.pygsl_odeiv2_step
_control = odeiv2.pygsl_odeiv2_control

class control_standard_scaled_new(_control):
    def __init__(self, eps_abs, eps_rel, a_y, a_dydt, scale):
        _control.__init__(self, eps_abs, eps_rel, a_y, a_dydt, scale)

class control_standard_new(_control):
    def __init__(self, eps_abs, eps_rel, a_y, a_dydt):
        _control.__init__(self, eps_abs, eps_rel, a_y, a_dydt, None)

class control_y_new(_control):
    def __init__(self, eps_abs, eps_rel):
        a_y = 1
        a_dydt = 0
        _control.__init__(self, eps_abs, eps_rel, a_y, a_dydt, None)

class control_yp_new(_control):
    def __init__(self, eps_abs, eps_rel):
        a_y = 0
        a_dydt = 1
        _control.__init__(self, eps_abs, eps_rel, a_y, a_dydt, None)

evolve = odeiv2.pygsl_odeiv2_evolve

_driver = odeiv2.pygsl_odeiv2_driver
class driver_standard_scaled_new(_driver):
    def __init__(self, sys, type, hstart, eps_abs, eps_rel, a_y, a_dydt, scale):
        _driver.__init__(self, sys, type, hstart, eps_abs, eps_rel, a_y, a_dydt, scale)

class driver_standard_new(_driver):
    def __init__(self, sys, type, hstart, eps_abs, eps_rel, a_y, a_dydt):
        _driver.__init__(self, sys, type, hstart, eps_abs, eps_rel, a_y, a_dydt, None)

class driver_y_new(_driver):
    def __init__(self, sys, type, hstart, eps_abs, eps_rel):
        a_y = 1
        a_dydt = 0
        _driver.__init__(self, sys, type, hstart, eps_abs, eps_rel, a_y, a_dydt, None)

class driver_yp_new(_driver):
    def __init__(self, sys, type, hstart, eps_abs, eps_rel):
        a_y = 0
        a_dydt = 1
        _driver.__init__(self, sys, type, hstart, eps_abs, eps_rel, a_y, a_dydt, None)

        
def func(t, y, args):
    mu = args
    f = numx.zeros(y.shape, numx.float_)
    y0 = y[0]
    y1 = y[1]
    f[0] = y1;
    f[1] = -y0 - mu*y1*(y0**2 - 1);
    return f

def jac(t, y, args):
    mu = args

    y0 = y[0]
    y1 = y[1]

    l = len(y)
    dfdy = numx.zeros((l,l), numx.float_)
    dfdy[0,0] = 0.0
    dfdy[0,1] = 1.0 
    dfdy[1,0] =  - 2.0 * mu * y0 * y1 - 1.0
    dfdy[1,1] =  - mu * (y0**2 - 1.0)
    
    dfdt = numx.zeros((l,), numx.float_)
    dfdt[0] = 0
    dfdt[1] = 0

    return dfdy, dfdt


def run_driver():
    mu = 10
    sys = odeiv2.system(func, jac, 2, mu)
    #sys = odeiv2.system(func, None, 2, mu)

    T = odeiv2.step_rk8pd
    pygsl.set_debug_level(0)
    d = driver_y_new(sys, T, 1e-6, 1e-6, 0.0);
    d.reset()
    d.reset_hstart(2)
    d.set_hmin(0.0)
    d.set_hmax(1.0)
    d.set_nmax(2)
    d.set_nmax(0)
    d.set_hmax(1e-6)
    d.set_hmin(2e-6)
    y = numx.array([1.0, 0.0])
    N = 100
    t = 0.0
    t1 = N * 1.
    ti = (numx.arange(N) +1) / float(N)

    pygsl.set_debug_level(0)

    for tnext in ti:
        #pygsl.set_debug_level(3)
        t, y  = d.apply(t, tnext, y)
        print(t, y)


def run_driver_fixed_step():
    mu = 10
    sys = odeiv2.system(func, jac, 2, mu)

    T = odeiv2.step_rk8pd
    d = driver_y_new(sys, T, 1e-6, 1e-6, 0.0);
    d.reset()
    y = numx.array([1.0, 0.0])
    N = 100
    pygsl.set_debug_level(0)

    t = 0
    for cnt in range(N):
        t, y  = d.apply_fixed_step(t, 1e-3, 1000, y)
        print(t, y)

def run_evolve():        
    mu = 10
    sys = odeiv2.system(func, jac, 2, mu)

    T = odeiv2.step_rk8pd
    s = step(T, 2)
    c = control_y_new(1e-6, 1e-6)
    e = evolve(2)

    t = 0
    t1 = 100
    h = 1e-6
    y = 1, 0
    while t < t1:
        status, t, h, y = e.apply(c, s, sys, t, t1, h, y)
        if status != errno.GSL_SUCCESS:
            print("break status", status)
            break
        e.get_yerr()
        #print ("%.5e %.5e %.5e" %(t, y[0], y[1]));
    print(status, errno.GSL_SUCCESS)
    print("status = %d, t = %e" %(status,t))
    
if __name__ == "__main__":
    #run_driver()
    #run_driver_fixed_step()
    run_evolve()
    #help(odeiv2)
