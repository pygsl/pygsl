from __future__ import print_function
import copy
import common
import ufunc_arg

class _c_structure:
    pass

class _proxy_store:
    """Store a proxy for later evaluation
    
    Should that not be a generator?
    """
    __slots__ = ["_proxy_to", "_the_method", "_the_args"]
  

    def __init__(self, proxy_to, the_method):
        assert(proxy_to is not None)
        self._proxy_to = proxy_to
        
        assert(the_method is not None)
        self._the_method = the_method

        self._the_args  = None
        
    def __call__(self, *args, **kws):
        if self._the_args is None:
            self._the_args = map(getattr(x, self._the_method), self._proxy_to)

        assert(self._the_args is not None)
        
        result = map(lambda x: x(*args, **kws), self._the_args)
        return result
        
class _proxy_methods:
    """proxy methods to subtypes and collect the results
    
    Needs :cls:`_proxy_store`
    """
    _methods = None

    __slots__ = ["_proxy_to",]

    def SetSequenceToProxyTo(self, seq):
        self._proxy_to = seq
        
    def __getattr__(self, attr):
        #-------------------------------------------------------
        # relay it to subtypes
        if attr in self._methods:
            p = _proxy_store(self._proxy_to, attr)
            return p
        return KeyError("Do not proxy methods '%s'" %(attr))


_methods_to_proxy = (
    "GetNumpyTypeCode",
    
)        

class _structure_arg:
    """A structure to be accessed by numpy ufunc

    Numpy ufuncs provide [internally] access to the different C types.
    A structure needs thus
         * to take the different variables and put the values into the 
           structure (for input)
         * to provide a empty structure and put the values into the appropriate
           memory locations provided by the input buffer

    """

    #: The c structure 
    _structure = None

    # : The subtypes
    __slots__ = ["_sub_types",  "_proxy"]

    def __init__(self):
        self._proxy = _proxy_methods()
        self._CheckMemberVariables()
        self._CheckMethodsToSubclass()
        
    def _CheckMemberVariables():
        assert(self._structure is not None)

    def _CheckMethodsToSubclass():
        "Don't know how to do that .... "

    def SetSubtypes(self, types):
        self._sub_types = types
        self._proxy.SetSequenceToProxyTo(self._sub_types)




class gsl_sf_result(_c_structure):
    
    pass
class GSLSFResult(_structure_arg):

    _structure = gsl_sf_result()
    
        result = map(lambda x: self._subtypes)
    
    
