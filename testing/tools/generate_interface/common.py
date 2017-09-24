"""Some parts
"""
from __future__ import print_function, absolute_import, division

class _ArgumentType(object):
    """Type of argument

    Arguments can be either:
        * input
        * return
        * output

    Provides methods for setting the type. It will check that the type has not
    been set before
    """
    __slots__ = ["_input_argument", "_output_argument", "_return_argument"]

    def __init__(self):
        self._input_argument = None
        self._output_argument = None
        self._return_argument = None

    def _CheckArgumentTypeIntern(self):

        _false = (None, False)
        if self._input_argument:
            assert(self._output_argument in _false)
            assert(self._return_argument in _false)

        if self._output_argument:
            assert(self._input_argument in _false)
            assert(self._return_argument in _false)

        if self._return_argument:
            assert(self._input_argument in _false)
            assert(self._output_argument in _false)

    def _CheckArgumentType(self):
        """
        Check that only one of the argument types is set
        """
        test = 0
        try:
            self._CheckArgumentTypeIntern()
            test = 1
        finally:
            if test == 0:
                print("In %s, Ret: %s, Out %s" %
                      (
                          self._input_argument,
                          self._return_argument,
                          self._output_argument,
                          )
                      )
                
    def IsReturnArgument(self):
        self._CheckArgumentType()
        return self._return_argument
            
    def IsInputArgument(self):
        self._CheckArgumentType()
        return self._input_argument

    def IsOutputArgument(self):
        self._CheckArgumentType()
        return self._output_argument

    def SetInputArgument(self):
        "This argument is an input argument"
        self._CheckArgumentType()
        self._input_argument = True
        self._CheckArgumentType()

    def SetOutputArgument(self):
        "This argument is an output argument"
        self._CheckArgumentType()
        self._output_argument = True
        self._CheckArgumentType()

    def UnsetOutputArgument(self):        
        self._CheckArgumentType()
        self._output_argument = False
        self._CheckArgumentType()

    def SetReturnArgument(self):
        "This argument is an return argument"
        self._CheckArgumentType()
        self._return_argument = True
        self._CheckArgumentType()
