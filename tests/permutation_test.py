#!/usr/bin/env python
import unittest
import types
import pygsl.permutation as permutation

class P(unittest.TestCase):
    def setUp(self):
        self.mylen = 9
        self.p = permutation.Permutation(self.mylen)

    def testlen(self):
        assert(type(len(self.p)) == types.IntType)
        assert(len(self.p) == self.mylen)

    def testinversions(self):
        self.p.inversions()

    def testlinearcycles(self):
        self.p.linear_cycles()

    def testcanonical_cycles(self):
        self.p.canonical_cycles()

    def test_previous(self):
        self.p.prev()

    def test_next(self):
        self.p.next()

    def test_valid(self):
        self.p.valid()

    def test_inverse(self):
        self.p.inverse()

    def test_l2c(self):
        self.p.linear_to_canonical()

    def test_c2l(self):
        self.p.canonical_to_linear()

    def test_reverse(self):
        self.p.reverse()

    def test_swap(self):
        self.p.swap(2,3)

    def test_array(self):
        self.p.toarray()

    def test_list(self):
        self.p.tolist()

if __name__ == '__main__':
    unittest.main()
