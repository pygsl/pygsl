#!/usr/bin/env python


import unittest
import pygsl.diff

lone = lambda x: x**3
ltwo = lambda x, y: x**3
lthree = lambda x, y: x**3 * y
lfour = lambda x, y: (x**3, y)

def lfive(x, args):
    return x**3, 1

class _TestDiff(unittest.TestCase):
    func = None
    def test1(self):
	self.failUnlessRaises(TypeError, self.func, lone, 1)
	
    def test2(self):
        tmp = self.func(ltwo, 1)
        test = 0
        try:
            assert((tmp[0] - 3) < tmp[1]*5)
            test = 1
        finally:
            if test == 0:
                print "I recieved %s. But it should be (3, ??)" % (tmp,)

    def test3(self):
        tmp = self.func(lthree, 1, 2)
        test = 0
        try:
            assert((tmp[0] - 3*2) < tmp[1]*5)
            test = 1
        finally:
            if test == 0:
                print "I recieved %s. But it should be (3, ??)" % (tmp,)

    def test4(self):
        """
        Check if it flags an error if not a float is returned

        Why is it put to float, and not the number of arguments are checked?XF
        """
        self.failUnlessRaises(TypeError, self.func, lfour, 1) 

    def test5(self):
        """
        Check if it flags an error if more than a float is returned
        """
        self.failUnlessRaises(TypeError, self.func, lfour, 1) 
       
class TestCentral(_TestDiff):
    func = pygsl.diff.central

class TestForward(_TestDiff):
    func = pygsl.diff.forward

class TestBackward(_TestDiff):
    func = pygsl.diff.backward

del _TestDiff	
if __name__ == '__main__':
    unittest.main()
    print pygsl.diff.__doc__
