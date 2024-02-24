"""
Example of how to use the rng module

Here the usage of the multinomoial distribution and its probability function
is shown.
"""
from pygsl import rng, set_debug_level
import numpy as np
import sys

r = rng.mt19937_1998()

# multinomial distribution
phi = (0.2,0.2,0.2,0.4)  # probability distribution over possible events
                         # (is normalized internally if necessary)

k = 5  # number of trials, that means
       # sum over each row in the samples in 'n'

# sampling 10 data points from the multinomial distribution parametrized
# by 'phi' and 'k'
n = r.multinomial(10, phi, 10)
print("n = ", n, type(n), n.dtype, n.shape)
n = r.multinomial(3, phi)
print("n = ", n, type(n), n.dtype, n.shape)

# returns an array containing the pdf for each row in 'n'

pdf =  rng.multinomial_pdf(phi, n)
print("pdf = ", pdf)


N = 10
n = r.multinomial(10, phi)
print("n = ", n)
print(rng.multinomial_lnpdf(phi, n))
