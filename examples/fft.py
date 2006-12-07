#!/usr/bin/env python
"""

"""
import pygsl._numobj as numx
import pygsl.fft as fft
print fft
def complex_example_simple():
    n = 16
    data = numx.arange(n) * (2 * numx.pi / n)
    data = numx.cos(data) +0j
    space = fft.complex_workspace(n)
    wavetable = fft.complex_wavetable(n)

    print data
    #data[:11] = 1.0
    #data[11:] = 1.0
    tmp = fft.complex_backward(data, space, wavetable)
    print "tmp", tmp
    #print data
    #fft.complex_backward(data)
    #fft.complex_inverse(data)

def complex_example():
    n = 630
    space = fft.complex_workspace(n)
    wavetable = fft.complex_wavetable(n)
    print space.get_type()
    print wavetable.get_type()
    print wavetable.get_factors()
    data = numx.zeros((630,), numx.Complex)
    data[:11] = 1.0
    data[11:] = 1.0
    d = data[:]
    fft.complex_forward(data, space, wavetable)


def real_example_simple1():
    n = 32
    data = numx.cos(1*(numx.arange(n) * (2 * numx.pi / n))).astype(numx.Float32)
    print data
    result =  fft.real_transform_float(data)
    print result
    #result =  fft.halfcomplex_unpack_float(result)
    #print result
    
def real_example_simple():
    n = 1024*1024
    data = numx.zeros((n,), numx.Int)
    data[n/3:2*n/3] = 1
    result =  fft.real_transform(data)
    #print "Nyqusit ->", result[0]
    result[11:] = 0
    final = fft.halfcomplex_inverse(result, n)    
    #print final
    return
    import Gnuplot
    g = Gnuplot.Gnuplot()
    g.plot(Gnuplot.Data(data, with='line'),
           Gnuplot.Data(final, with='linespoints'),)
    raw_input()

def halfcomplex_radix2_unpack():
    n = 32   
    a = numx.arange(n)
    c = numx.zeros((n,))
    c[1:n/2+1]=a[1::2]
    c[n/2+1:]=a[-2:1:-2]    
    print c
    print fft.halfcomplex_radix2_unpack(c)
    
def doc():
    help(fft)
    
if __name__ == '__main__':
    import pygsl
    pygsl.set_debug_level(0)
    complex_example_simple()
    complex_example()
    real_example_simple()
    real_example_simple1()
    halfcomplex_radix2_unpack()
    #doc()
