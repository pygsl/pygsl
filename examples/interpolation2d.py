#!/usr/bin/env python
import pygsl
from pygsl import interpolation2d
np = pygsl._numobj

x_a = np.array([0,1])
y_a = np.array([0,1])
z_a = np.array([(1,2),
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

for x in X:
    for y in Y:
        test = 0
        try:
            z = intp.eval(x, y)
            test = 1
        finally:
            if test == 0:
                print("Failure evaluating: x = %f y = %f" % (x, y))

        print("%f %f %f" %(x,y,z))
