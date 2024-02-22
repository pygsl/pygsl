"""
Example of how to use the rng module

Here the usage of the multinomoial distribution and its probability function
is shown.
"""
from pygsl import rng
import numpy as np

r = rng.mt19937_1998()
phi = (0.2,0.2,0.2,0.4)  # probability distribution over possible events
                         # (is normalized internally if necessary)

k = 5  # number of trials, that means
       # sum over each row in the samples in 'n'

# sampling 10 data points from the multinomial distribution parametrized
# by 'phi' and 'k'
n = r.multinomial(10, phi)
print("n = ", n, type(n))

# returns an array containing the pdf for each row in 'n'
ar =  rng.multinomial_pdf(phi, np.atleast_2d(n))
print("ar = ", ar, type(ar))


r = rng.mt19937_1998()
a = (1,2,3,4,5)
N = 10
n = r.multinomial(10, a)
print("n = ", n)
print(rng.multinomial_lnpdf(a, np.atleast_2d(n)))
