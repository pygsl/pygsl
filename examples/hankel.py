#!/usr/bin/env python
import Numeric
from pygsl import hankel

a = Numeric.arange(1000)

h = hankel.DiscreteHankelTransform(100)
h.init(10,10)
h.apply(a[:100])
#print "Finished!"
