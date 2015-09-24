#!/usr/bin/env python
"""
The pythonic version of the qrng example found in the gsl reference document.
"""
from __future__ import print_function
import pygsl
import pygsl.qrng as qrng

def run():
    q = qrng.sobol(2)
    #q = qrng.niederreiter_base_2(2)
    for i in q(12):
        print (i[0], i[1])

if __name__ == '__main__':
    run()
