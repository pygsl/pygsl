# Author : Fabian Jakobs
"""
   This chapter describes functions for creating and manipulating
permutations. A permutation p is represented by an array of n integers
in the range 0 .. n-1, where each value p_i occurs once and only once.
The application of a permutation p to a vector v yields a new vector v'
where v'_i = v_{p_i}.  For example, the array (0,1,3,2) represents a
permutation which exchanges the last two elements of a four element
vector.  The corresponding identity permutation is (0,1,2,3).
"""

import gslwrap

class Permutation(gslwrap.Permutation):
    def linear_to_canonical(self):
        """
        Computes the canonical form of the current permutation and returns it
        in a new permutation
        """
        q = Permutation(len(self))
        self._linear_to_canonical(q)
        return q
    
    def canonical_to_linear(self):
        """
        Computes the linear form of the current permutation and returns it
        in a new permutation
        """
        q = Permutation(len(self))
        self._canonical_to_linear(q)
        return q
            
    def inverse(self):
        """
        Computes the inverse form of the current permutation and returns it
        in a new permutation.
        """
        inv = Permutation(len(self))
        self._inverse(inv)
        return inv

    def mul(self, b):
        """
        Mutliplies this permutation with an other permutation and returns the
        result in a new permutation.
        """

        mul = Permutation(len(self))
        self._mul(mul, b)
        return mul


    def __str__(self):
        return self.tolist().__str__()
