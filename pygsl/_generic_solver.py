#!/usr/bin/env python
# Author : Pierre Schnizer 
import _callback

class _workspace:
    _alloc = None
    _free  = None
    def __init__(self, size):
        self._ptr = None
        assert(self._alloc != None)
        assert(self._free != None)
        self._ptr = self._alloc(size)
        
    def __del__(self):
        if hasattr(self, '_ptr'):
            if self._ptr != None:
                self._free(self._ptr)
    
class _generic_solver:
    _type  = None
    _set   = None
    _name  = None
    _iterate  = None
    def __init__(self, system):
        """
        Set the system to the solver
        """
        self._ptr = None
        assert(self._alloc != None)
        assert(self._set != None)
        assert(self._name != None)
        assert(self._iterate != None)
        assert(self._free != None)
        self._ptr = self._alloc(self.type)
        self._isset = 0
        self.system = system
        
    def __del__(self):
        if hasattr(self, '_ptr'):
            if self._ptr != None:
                self._free(self._ptr)



    def name(self):
        """
        Get the name of the solver
        """
        return self._name(self._ptr)

    def iterate(self):
        """
        Iterate the solver towards to the solution.
        """
        if (self._isset == 0):
            raise TypeError, "You must call the method set before you iterate!"
        return self._iterate(self._ptr)
    

