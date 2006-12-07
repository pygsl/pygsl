# Author : Pierre Schnizer
"""
The python equivalent of the C example found in the GSL Reference document.

The function run_fsolver shows how to use the fsolvers (e.g. brent) and the
function run_fdfsolver explains the usage of the fdfsolvers (e.g. newton).
"""
from pygsl import  roots, errno
import pygsl._numobj as numx

def quadratic(x, params):
    a = params[0]
    b = params[1]
    c = params[2]
    tmp =  a * x ** 2 + b * x + c 
    return tmp

def quadratic_deriv(x, params):
    a = params[0]
    b = params[1]
    c = params[2]
    dy= 2.0 * a * x + b
    return dy

def quadratic_fdf(x, params):
    y = quadratic(x, params)
    dy = quadratic_deriv(x, params)
    return y , dy



def run_fsolver():
    a = 1.0
    b = 0.0
    c = -5.0
    mysys = roots.gsl_function(quadratic, (a,b,c))
    solver = roots.brent(mysys)
    #solver = roots.bisection(mysys)
    #solver = roots.falsepos(mysys)
    
    solver.set(0.0, 5.0)
    iter = 0
    r_expected = numx.sqrt(5.0)
    print "# Using solver ", solver.name() 
    print "# %5s [%9s %9s]  %9s  %10s %9s" % ("iter", "upper", "lower", "root",
                                              "err", "err(est)")
    for iter in range(100):           
        status = solver.iterate()
        x_lo = solver.x_lower()
        x_up = solver.x_upper()
        status = roots.test_interval(x_lo, x_up, 0, 0.001)
        r = solver.root()
        if status == errno.GSL_SUCCESS:
            print "#  Convereged :"
        print "  %5d [%.7f %.7f]  %.7f  % .6f % .6f" %(iter, x_lo, x_up, r,
                                                       r -r_expected,
                                                       x_up - x_lo)
        if status == errno.GSL_SUCCESS:
            break
    else:
        raise ValueError, "Exeeded maximum number of iterations!"

def run_fdfsolver():    
    a = 1.0
    b = 0.0
    c = -5.0
    mysys = roots.gsl_function_fdf(quadratic, quadratic_deriv, quadratic_fdf,
                                 numx.array((a,b,c)))

    solver = roots.newton(mysys)    
    #solver = roots.secant(mysys)
    #solver = roots.steffenson(mysys)

    x = 5.0
    solver.set(x)
    r_expected = numx.sqrt(5.0)
    print "# Using solver ", solver.name() 
    print "# %5s %9s  %10s %9s" % ("iter", "root", "err", "err(est)")
    ok = 1
    for iter in range(10):
        status = solver.iterate()
        x0 = x
        x = solver.root()
        status = roots.test_delta(x, x0, 0.0, 1e-3)
        r = solver.root()
        if status == errno.GSL_SUCCESS:
            print "#  Convereged :"
        print "%5d  %.7f  % .6f % .6f" %(iter, r, r -r_expected, x - x0)
        if status == errno.GSL_SUCCESS:
                break
    else:
        raise ValueError, "Exeeded maximum number of iterations!"

if __name__ == '__main__':
    run_fsolver()
    run_fdfsolver()
