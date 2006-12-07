#!/usr/bin/env python
"""
Simulated Annealing

The pythonic version of the simple example from the gsl reference document.
"""
# Author: Pierre Schnizer
# Date  : December 2003
import pygsl._numobj as numx
import pygsl.siman as siman
import pygsl.rng   as rng

# how many points do we try before stepping
N_TRIES = 200             
     
# how many iterations for each T? 
ITERS_FIXED_T = 10        
     
# max step size in random walk 
STEP_SIZE = 10            

# Boltzmann constant
K = 1.0                   
     
# initial temperature
T_INITIAL = 0.002         

# damping factor for temperature 
MU_T = 1.005              
T_MIN = 2.0e-6
     

class MySiman(siman.NumericEnsemble):       
    def EFunc(self):
        x = self._data
        t = x-1.0
        t2 = t*t
        # Necessary as my python does not handle the exp of big numbers
        # correctly
        if t2 > 700:
            tmp = 0
        else:
            tmp = numx.exp(-t2)
        return tmp*numx.sin(8*x)
     
    def Metric(self, outer):     
        return numx.absolute(self._data - outher.GetData())

    def Step(self, rng, step_size):
        old_x = self._data
        
        u = rng.uniform();
        new_x = u * 2 * step_size - step_size + old_x;
        self._data = new_x


    def Print(self):
        print "%12g" % self._data,

m = MySiman()
m.SetData(15.5)

r = rng.rng()

result = siman.solve(r, m, do_print=0)
#result = siman.solve(r, m, do_print=1, n_tries=N_TRIES, iters_fixed_T=ITERS_FIXED_T,
#                     step_size=STEP_SIZE, k=K, t_initial=T_INITIAL, mu_t = MU_T,
#                     t_min=T_MIN)
print "# Found minimum at %f" % result.GetData()
