#!/usr/bin/env python
from pygsl import hankel
from pygsl import _numobj as numx

a = numx.arange(1000)

h = hankel.DiscreteHankelTransform(100)
h.init(10,10)
h.apply(a[:100])
#print "Finished!"
