import unittest
import math
import pygsl.histogram
import warnings
import exceptions
import pygsl.errors
import tempfile
import os
import os.path
from pygsl.multimin import *

class multimin_tests(unittest.TestCase):
    """
    """
    
    def test_alloc(self):

        func=lambda x,y,z:x**2+y**2+z**2
        m=multimin(nmsimplex,3)
        m.set(func,[],(1,1,1),(0.1,0.1,0.1))
        m.iterate()
        m=None
