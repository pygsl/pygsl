# Author : Pierre Schnizer 
"""
The python equivalent of the C example found in the GSL Reference document.

The function run_fsolver shows how to use the fsolvers (e.g. dnewton) and the
function run_fdfsolver explains the usage of the fdfsolvers (e.g. gnewton).
"""
import pygsl._numobj as numx
from pygsl  import multiroots, errno
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
    df = numx.zeros((x.shape[0], x.shape[0])) * 1.
    df[0,0] = -a
    df[0,1] = 0
    df[1,0] = -2 * b * x[0]
    df[1,1] = b
    return df

def rosenbrock_fdf(x, params):
    f = rosenbrock_f(x, params)
    df = rosenbrock_df(x, params)
    return f, df

def run_fsolver():
    params = numx.array((1., 10.)) * 1.
    mysys = multiroots.gsl_multiroot_function(rosenbrock_f, params, 2)
    
    #solver = multiroots.hybrids(mysys, 2)
    solver = multiroots.dnewton(mysys, 2)
    #solver = multiroots.broyden(mysys, 2)
    #solver = multiroots.hybrid(mysys, 2)
    
    tmp = numx.array((-10., -5.),)
    solver.set(tmp)
    print "# Testing solver ", solver.name() 
    print "# %5s %9s %9s  %9s  %10s" % ("iter", "x[0]", "x[1]", "f[0]", "f[1]")
    for iter in range(100):
        status = solver.iterate()
        r = solver.root()
        x = solver.getx()
        f = solver.getf()
        status = multiroots.test_residual(f, 1e-7)
        if status == errno.GSL_SUCCESS:
            print "# Converged :"
        print "  %5d % .7f % .7f  % .7f  % .7f" %(iter, x[0], x[1], f[0], f[1])
        if status == errno.GSL_SUCCESS:
            break
    else:
        raise ValueError, "Number of Iterations exceeded!"

def run_fdfsolver():
    params = numx.array((1., 10.),)
    mysys = multiroots.gsl_multiroot_function_fdf(rosenbrock_f, rosenbrock_df,
                                                  rosenbrock_fdf, params, 2)
    
    #solver = multiroots.newton(mysys, 2)
    solver = multiroots.gnewton(mysys, 2)
    #solver = multiroots.hybridj(mysys, 2)
    #solver = multiroots.hybridsj(mysys, 2)
    
    tmp = numx.array((-10., -5.), )
    solver.set(tmp)
    print "# Testing solver ", solver.name() 
    print "# %5s %9s %9s  %9s  %10s" % ("iter", "x[0]", "x[1]", "f[0]", "f[1]")
    for iter in range(100):
        status = solver.iterate()
        r = solver.root()
        x = solver.getx()
        f = solver.getf()
        status = multiroots.test_residual(f, 1e-7)
        if status == errno.GSL_SUCCESS:
            print "# Converged :"
        print "  %5d % .7f % .7f  % .7f  % .7f" %(iter, x[0], x[1], f[0], f[1])
        if status == errno.GSL_SUCCESS:
            break
    else:
        raise ValueError, "Number of Iterations exceeded!"

if __name__ == '__main__':
    run_fsolver()
    run_fdfsolver()
