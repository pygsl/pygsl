#!/usr/bin/env python
import unittest
import Numeric
import sys
sys.stdout = sys.stderr
print "Importing sf ...",
import pygsl.testing.sf as sf
print "done"

class _basis_f(unittest.TestCase):
    def _makearray(self, j):
        j = j+1
        return   Numeric.arange(100) / (1. * j) + .1
    
    def testone(self):
        a = 1
        self._func(a)

    def testarray(self):
        for j in range(1000):
            self._func(self._makearray(j))

class _basis_fm(_basis_f):
    def testone(self):
        a = 1
        self._func(a, sf.PREC_DOUBLE)

    def testarray(self):
        for j in range(100):
            self._func(self._makearray(j), sf.PREC_SINGLE)


class Chi(_basis_f):
    _func = sf.Chi

class Airy(_basis_fm):
    _func = sf.airy_Ai

del _basis_f
del _basis_fm

if __name__ == '__main__':
    unittest.main()
