from pygsl import histogram, rng
import pygsl
import sys
from time import clock
from matplotlib import pylab

pygsl.set_debug_level(0)
n = 2000
m = 5000
h =histogram.histogram(n)
h.set_ranges_uniform(-8,8.)
r = rng.rng()

t0 = clock()
h.increment(r.gaussian(1,n*m))
t1 = clock()
print "Needed %d seconds" % (t1 - t0)
x, d = h.plot_data()
x = (x[:,0]+x[:,1])/2
pylab.plot(x,d)
pylab.show()
