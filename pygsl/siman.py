#!/usr/bin/env python
"""
Wrapper for the Simulated Annealing Solver provided by GSL.

The  simulated annealing  algorithm  takes random  walks  through the  problem
space,  looking for  points  with low  energies;  in these  random walks,  the
probability of taking a step is determined by the Boltzmann distribution,

     p = e^{-(E_{i+1} - E_i)/(kT)}

if E_{i+1} > E_i, and p = 1 when E_{i+1} <= E_i.

   In other words, a  step will occur if the new energy  is lower.  If the new
energy  is higher,  the  transition can  still  occur, and  its likelihood  is
proportional to  the temperature  T and inversely  proportional to  the energy
difference E_{i+1} - E_i.

   The temperature T  is initially set to  a high value, and a  random walk is
carried  out  at that  temperature.   Then  the  temperature is  lowered  very
slightly according  to a  "cooling schedule", for  example: T ->  T/mu_T where
\mu_T is slightly greater than 1.

   The slight  probability of taking a  step that gives higher  energy is what
allows simulated annealing to frequently get out of local minima.


This wrapper does not follow the GSL interface as closely as the other wrappers
in this package. Instead it expects an object describing the problem with the
required methods. NumericEnsemble illustrates the necessary methods.

The function solve does the real job.

Have a look in the examples directory for the pythonic version of the simple
problem as described in the GSL reference document.
"""
# Author: Pierre Schnizer
# Date  : 2003

import copy

import _siman

# The real solver
solve = _siman.solve

class NumericEnsemble:
    """
    A base class implementation to support the use of numeric arrays as
    configurations. You must overload the following functions
    
                   EFunc
                   Step
                   Metric
                   Clone
                   
    in a derived class.

    If you want, that the solver prints it status to the stdout add a
    Print method.    
    """
    def __init__(self):
        self._data = None

    def SetData(self, data):
        self._data = data

    def GetData(self):
        return self._data

    def EFunc(self):
        """
        Calculate the energy of the current status.

        Output:
              energy .... a Python float of the current energy
        """
        return energy

    def Step(self, rng, step_size):
        """
        Take a step
        
        Input:
             rng       ... a pygsl.rng instance
             step_size ... a python float for the step size to be taken
        """
        return None
    

    def Metric(self, other):
        """
        Calculate the distance between this object and the other.
        
        Input:
            other ... a instance of the same type

        Output:
            length ... a python float for the distance between this instance
            and the other.
        """
        return length

    def Clone(self):
        """
        Make a clone of the current object. Please be careful how you step and
        clone so that your objects are different!
        
        Output:
            clone ... a identical clone of this object.
        """
        clone = self.__class__()
        clone.SetData(copy.copy(self._data))
        return clone

    def Print(self):
        """
        Print the current state of the ensemble        
        """
        
    def __del__(self):
        # Not necessary, just illustration
        del self._data
