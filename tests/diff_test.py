#!/usr/bin/env python

import unittest
import pygsl.diff

lone = lambda x: x**3
ltwo = lambda x: x**3 * y

class _TestDiff(unittest.TestCase):
    func = None
    def test1(self):
	assert(self.func(lone, 1)[0] == 3)
	
    def test2(self):	
	assert(self.func(ltwo, 1)[0] == 3)
    
class TestCentral(_TestDiff):
    func = pygsl.diff.central
    
del _TestDiff	
if __name__ == '__main__':
    unittest.main()
