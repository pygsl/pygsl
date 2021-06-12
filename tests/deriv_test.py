#!/usr/bin/env python

from __future__ import print_function
import unittest
import pygsl.deriv

def one_arg(x, args):
    assert(args is None)
    return x**3

ltwo = lambda x, y: x**3
lthree = lambda x, y: x**3 * y
lfour = lambda x, y: (x**3, y)

def lfive(x, args):
    return x**3, 1

class _TestDiff(unittest.TestCase):
    func = None
    eps  = None

    def test0(self):
        '''Test that missing eps is reported
        '''
        self.assertRaises(TypeError, self.func, one_arg, 1)

    def test1(self):
        '''Test function taking one argument
        '''
        y, y_err = self.func(one_arg, 1, self.eps)
        #self.assertRaises(TypeError, )

    def test2(self):
        '''Test if function accepts two arguments
        '''
        tmp = self.func(ltwo, 1, self.eps)
        self.assertAlmostEqual(tmp[0], 3, delta=tmp[1])
        self.assertAlmostEqual(tmp[1], 0, places=4)

    def test3(self):
        '''Check if correct value is returned
        '''
        tmp = self.func(lthree, 1, self.eps, 2)
        self.assertAlmostEqual(tmp[0], 6, delta=tmp[1])
        self.assertAlmostEqual(tmp[1], 0, places=4)

    def test4(self):
        """Check if it flags an error if not a float is returned

        Why is it put to float, and not the number of arguments are checked?XF
        """
        self.assertRaises(TypeError, self.func, lfour, self.eps, 1)

    def test5(self):
        """Check if it flags an error if more than a float is returned
        """
        self.assertRaises(TypeError, self.func, lfour, self.eps, 1)

class TestCentral(_TestDiff):
    eps = 1e-3
    func = pygsl.deriv.central

class TestForward(_TestDiff):
    eps = 1e-3
    func = pygsl.deriv.forward

class TestBackward(_TestDiff):
    eps = 1e-3
    func = pygsl.deriv.backward

del _TestDiff

if __name__ == '__main__':
    unittest.main()
