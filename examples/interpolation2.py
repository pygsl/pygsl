#!/usr/bin/env python
#------------------------------------------------------------------------------
# Original Author: Julien
# Author: Pierre Schnizer <schnizer@users.sourceforge.net>
# Date : August, 2008
#
# Illustrates how much time is required if the interpolation vectors
# have to be converted all the time.
#------------------------------------------------------------------------------
import time
import pygsl
# pygsl can be compiled 
numx = pygsl._numobj
# The intepolation module. This tries to use the data in the vectors directly
import pygsl.interpolation as intp
# This module makes an internal copy and stores the data internally
#import pygsl.spline as intp
#------------------------------------------------------------------------------
time_ = time.time
t_initial = time_()

a = numx.arange(0,10000000)
b = numx.arange(10000000,20000000)
# Comment the following lines and see the difference in speed.
a = a.astype(numx.float_)
b = b.astype(numx.float_)

c = intp.linear(len(a))
c.init(a, b)

# pygsl tries to count if it has to make a type transformation internally
save_cnt = pygsl.init.vector_transform_counter()

t_start = time_()
print "->"
for i in range(0,50):
    c.eval(50000)
    print ".",
print " done"
t_final = time_()
end_cnt = pygsl.init.vector_transform_counter()

print "Total time =", t_final-t_initial
print "Time for evaluation =", t_final-t_start
print "Required %d vector type transformations" %(end_cnt - save_cnt,)

# The spline module also has a eval_vector function, That gives an obvious
# speed up..
#vec = numx.ones(50) * 50000
#t_start = time_()
#c.eval_vector(vec)
#t_final = time_()
#print "passed_time=", t_final-t_start
