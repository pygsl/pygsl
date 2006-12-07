#!/usr/bin/env python
"""
The pythonic version of the qrng example found in the gsl reference document.
"""
import pygsl.qrng as qrng

def run():
    q = qrng.sobol(2)
    for i in q(1024):
        print i[0], i[1]

if __name__ == '__main__':
    run()
