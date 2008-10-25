#!/usr/bin/env python
import sys
sys.stdout = sys.stderr
import unittest
import Numeric
import pygsl.testing.sf as sf

#class PolarToRectangle(unittest.TestCase):
#    def test0(self):
#        return
#        print "rect->polar"
#        value = Numeric.exp(1j * (2 * Numeric.pi / 4 * Numeric.arange(5)))
#        print sf.rect_to_polar(value)
#        
#    def test1(self):
#        print "polar->rect"
#        angle = Numeric.arange(10)
#        radius = 1.0
#        print sf.polar_to_rect(radius, angle)

class EDOMTest(unittest.TestCase):
    def test0(self):
        sf.psi(0)
        
if __name__ == '__main__':
    unittest.main()
