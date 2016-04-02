#!/usr/bin/env python
from __future__ import print_function
import pygsl
from pygsl import interpolation2d, spline2d
np = pygsl._numobj

x_a = np.array([0,1])
y_a = np.array([0,1])
z_a = np.array([(1,  2),
                (1.5,2)])
x_size = len(x_a)
y_size = len(y_a)

intp = interpolation2d.bilinear(x_size, y_size)
intp.init(x_a, y_a, z_a)

N = 100
N = 5

assert(N > 1)
X = np.arange(N) / (N - 1)
Y = np.arange(N) / (N - 1)

# Example of evaluating the interpolation over a matrix ... but only evaluating
# an array internally....

# 
t_shape = (len(X), len(Y))
X_all = X[:,np.newaxis]
Y_all = Y[np.newaxis,:]

print("Using interpolation 2d")
Z_all = intp.eval_array(X_all, Y_all)

z = intp.eval(X[1], Y[1])
        
print("Using spline 2d")
sp = spline2d.bilinear(x_size, y_size)
sp.init(x_a, y_a, z_a)

Z_all = sp.eval_array(X_all, Y_all)
z = sp.eval(X[1], Y[1])

xp = .5
yp = .5

msg = "sp x = %e, y = %e: f = %e, df/dx = %e df/dy = %e\n"
msg += "    d^2f/dx^2 = %e d^2f/dxdy = %e d^2f/dydy = %e "
print(msg %
      (
          xp, yp,
          sp.eval(xp, yp),
          sp.eval_deriv_x(xp, yp),
          sp.eval_deriv_y(xp, yp),
          sp.eval_deriv_xx(xp, yp),
          sp.eval_deriv_xy(xp, yp),
          sp.eval_deriv_yy(xp, yp)
      )
)

print(msg %
      (
          xp, yp,
          sp.eval_e(xp, yp),
          sp.eval_deriv_x_e(xp, yp),
          sp.eval_deriv_y_e(xp, yp),
          sp.eval_deriv_xx_e(xp, yp),
          sp.eval_deriv_xy_e(xp, yp),
          sp.eval_deriv_yy_e(xp, yp)
      )
)

print("intp: extract", intp.eval_extrap(1.5, .5))
print("intp: extract", intp.eval_e_extrap(1.5, .5))

