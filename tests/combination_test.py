#!/usr/bin/env python

import unittest
import pygsl.combination as combination

class CTest(unittest.TestCase):
    def setUp(self):
        self.n = 20
        self.k = 9
        self.p = combination.Combination(self.n, self.k)

    def test_previous(self):
        self.p.prev()

    def test_next(self):
        self.p.next()

    def test_init_first(self):
        self.p.init_first()

    def test_init_last(self):
        self.p.init_last()
    
    #def test_valid(self):
    #    self.p.valid()

    def test_array(self):
        self.p.toarray()

    def test_list(self):
        self.p.tolist()
    
if __name__ == '__main__':
    unittest.main()
