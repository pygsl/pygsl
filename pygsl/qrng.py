#!/usr/bin/env python
"""    
A quasi-random sequence progressively covers a d-dimensional space with a
set of points that are uniformly distributed.  Quasi-random sequences are
also  known  as  low-discrepancy  sequences.  The  quasi-random  sequence
generators use an  interface that is similar to  the interface for random
number generators.

Currently two implementations are available: sobol and niederreiter_base_2.

The generators provide the following methods:
    __init__(dim)    ... intalizes the random generator to dim dimensions.
    __call__(sample) ... returns a two dimensional array with the shape
                         (sample, dim).
    init()           ... initalizes the random generator to the original state.
    name()           ... get the name of the used generator
    __copy___()      ... returns an identical copy of the current generator.
"""
import pygsl._qrng as _qrng

def sobol(dimension):
    """
    This generator uses the Sobol sequence described in Antonov,
    Saleev, `USSR Comput. Maths. Math. Phys.' 19, 252 (1980). It is
    valid up to 40 dimensions.
    """
    return _qrng.qrng(_qrng.sobol, dimension)


def niederreiter_base_2(dimension):
    """
    This generator uses the algorithm described in Bratley, Fox,
    Niederreiter, `ACM Trans. Model. Comp. Sim.' 2, 195 (1992). It is
    valid up to 12 dimensions.
    """
    return _qrng.qrng(_qrng.niederreiter_base_2, dimension)
