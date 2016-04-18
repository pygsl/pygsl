#!/usr/bin/env python
# Author: Pierre Schnizer <schnizer@users.sourceforge.net> 2016
# $Id$
"""
Wrapper for ufunc arguments.

Provides converters from each ufunc pointer type to the appropriate C types
Gives the code for the appropriate temporary variables.
"""

class BasisClass(Exception):
    pass

class NoMinor(Exception):
    pass

class _UFuncPosNum:
    "The position of this argument within the UFunc"
    def __init__(self):
        # For the first argument which position number shall it use ...
	self._py_ufunc_pos_number = None

    def SetPyUFuncPosNumber(self, num):
	self._py_ufunc_pos_number = int(num)

	t = self.GetPyUFuncPosNumber()
	      
    def GetPyUFuncPosNumber(self):
	num = self._py_ufunc_pos_number
	if num == None:
	    msg = "%s: Getting PyUFunc pos number to %s" %(self.__class__.__name__, num)
	    raise ValueError(msg)

	return num

    
class _UFuncArgument(_UFuncPosNum):
    """
    The basis class of the ufunc

    The derived classses shall specifiy the standard c types and numpy type 
    codes (see below)
    
    Then the code given within this class will provide the appropriate 
    converters for the standard cases.
    """
    # The C type that is wrapped
    _c_type = None
    # its assosicated numpy code.
    _numpy_type_code = None
    # The standard letter for it 
    _type_letter = None
    # What value it should be set to if in fail mode
    _value_for_failed = None
    # sometimes a c sub type is needed:
    # e.g. a complex value is built up from double values
    _c_sub_type = None
    
    def __init__(self):
	_UFuncPosNum.__init__(self)

	self._input_argument = None
	self._output_argument = None
	self._return_argument = None
	
    def _CheckMemberNotNone(self, member_name):        
        member = getattr(self, member_name)
        if member == None:
            args = (self.__class__.__name__, member_name)
            raise ValueError("%s.%s == None" % args)
        return member
        
    def GetCType(self):
        "The C type associated with this UFunc argument"
        return self._CheckMemberNotNone("_c_type")

    def GetCSubType(self):
        """The C sub type of this UFunc.
        e.g. a complex is made of two doubles
        """
        return self._CheckMemberNotNone("_c_sub_type")
    
    def GetNumpyTypeCode(self):
        "The numpy type code: e.g. for a 'double' value it is NPY_DOUBLE"
        return self._CheckMemberNotNone("_numpy_type_code")

    def GetTypeLetter(self):
        "The type code letter typically used for this type: double 'd' "
        return self._CheckMemberNotNone("_type_letter")

    def GetValueForFailedVariable(self):
        "The value the variable shall be set to: e.g. for double _PyGSL_NAN"
        return self._CheckMemberNotNone("_value_for_failed")

    def GetMinorInstance(self):
        msg = "no minor declared for an instance of cls '%s'"
        raise NoMinor(msg, self.__class__.__name__)
    
    def SetInputArgument(self):
        "This argument is an input argument"
	self._input_argument = True

    def SetOutputArgument(self):
        "This argument is an output argument"
	self._output_argument = True

    def SetReturnArgument(self):
        "This argument is an return argument"
	self._return_argument = True

    def GetTmpVariableLabel(self):
	if self._input_argument:
	    label = "i"
	elif self._output_argument:
	    label = "o"
	elif self._return_argument:
	    label = "r"
	else:
	    raise ValueError("Don't know if I am input, output or return variable")

	return label
        
    def _GetTmpVariableName(self):
        "Create a temporary variable name"
        pos = self.GetPyUFuncPosNumber()
        label = self.GetTmpVariableLabel()
        letter = self.GetTypeLetter()

	name = "tmp%s%d" % (label, pos)
	return name
	
        
    def NeedFailLabel(self):
        return False

    def GetTmpVariables(self):
        "Code for declaring temporary assignments"
        return [""]

    def GetInputTmpVariablesAssignment(self):
        "Setting temporary variables from input"
        return [""]   

    def GetOutputTmpVariablesAssignment(self):
        "Setting output from temporary variables"
        return [""]

    def GetReturnTmpVariablesAssignment(self):
        "Setting output from temporary variables"
        return [""]

    def GetInputCallArgument(self):
        "Function call: input arguments"
	pos = self.GetPyUFuncPosNumber()
        code = ["(*((%s *) ip%d))" %(self.GetCType(), pos)]
        return code
    

    def GetOutputCallArgument(self):
        "Function call: output arguments"
	pos = self.GetPyUFuncPosNumber()
	ct = self.GetCType()
	code = ["((%s *) op%d)" % (ct, pos)]
	return code
   

    def GetFunctionReturnCast(self):
        "Function: cast of return to return variable"
        return [""]
    
	mi = self._minor_ins
	if mi:
	    ct = mi.GetCType()
	    code = ["%s" % (ct,)]
	    return code
	else:
	    pass
	
    def GetReturnCallArgument(self):
	"""
        Return variable
	"""
	pos = self.GetPyUFuncPosNumber()
	ct = self.GetCType()
	code = [
            "*((%s *) op%d)" % (ct, pos)
	]
	return code

    def GetInputConversion(self):
        return ["/* no input conversion for type  '%s' */" %(self.__class__.__name__,)]

    def GetOutputConversion(self):
        t_type = self.GetCType()
        pos = self.GetPyUFuncPosNumber()
        code = "*((%s *) op%d)" % (t_type, pos)
        return code


    def GetOutVarsSetOnError(self):
        """
        If an error occurs set the error
        """
	code = self.GetOutputConversion()
	val = self.GetValueForFailedVariable()
	code = "%s = %s;" %(code, val)
	return [code]

class _NeedsTemporaryVariables(_UFuncArgument):
    """
    A ufunc that needs temporary variables for the call
    """
    def GetTmpVariables(self):
	name = self._GetTmpVariableName()	
        code = "%s %s;" %(self.GetCType(), name)
        return [code]

    def GetInputConversion(self):
        t_type = self.GetCType()
        pos = self.GetPyUFuncPosNumber()
        code = "*((%s *) ip%d)" % (t_type, pos)
        return code

    def GetReturnArgumentConversion(self):
	name = self._GetTmpVariableName()	            
        return [""]


    def GetInputTmpVariablesAssignment(self):
	name = self._GetTmpVariableName()	    
	pos = self.GetPyUFuncPosNumber()
        code = "%s = *((%s *) ip%d);" %(name, self.GetCType(), pos)
        return [code]

    def GetReturnTmpVariablesAssignment(self):
        "Setting return from temporary variables to Ufunc arrays"
	name = self._GetTmpVariableName()	    
	pos = self.GetPyUFuncPosNumber()
	code = ["(*((%s *) op%d)) = %s" %(self.GetCType(), pos, name)]
	return code

    def GetOutputTmpVariablesAssignment(self):
	name = self._GetTmpVariableName()	    
	pos = self.GetPyUFuncPosNumber()
        loc = self.GetOutputConversion(self)
	code = ["loc = %s" %(loc, name)]
	return code

    def GetInputCallArgument(self):    
	name = self._GetTmpVariableName()	    
        code = [name]
	return code

    def GetOutputCallArgument(self):
	name = self._GetTmpVariableName()	            
        code = ["&%s" %(name,)]
        return code

    def GetReturnCallArgument(self):
	"""
	Create cast to return type	
	"""
	name = self._GetTmpVariableName()	            
	code = [name]
	return code

    
    #def GetFunctionReturnCast(self):
    #    "Function: cast of return to return variable"
    #    return [""]

    def GetOutVarsSetOnError(self):
	code = self.GetOutputConversion()
	val = self.GetValueForFailedVariable()
	code = "%s = %s;" %(code, val)
	return [code]
    
class _UFuncArgumentWithMinor(_UFuncArgument):
    """
    This can be used as a minor
    """
    _minor = None
    def __init__(self):
	_UFuncArgument.__init__(self)

	self._minor_ins = None
	if self._minor != None:
	    self._minor_ins = self._minor()

    def GetMinorInstance(self):
	minor = self._minor_ins
	if minor != None:
	    return minor

        msg = "no minor found for an instance of cls '%s'"
        raise NoMinor(msg, self.__class__.__name__)

    def SetPyUFuncPosNumber(self, num):
	_UFuncPosNum.SetPyUFuncPosNumber(self, num)
	if self._minor_ins != None:
	    self._minor_ins.SetPyUFuncPosNumber(num)

    
class _LongArgument(_UFuncArgument):
    """
    py3 integers are longs. Thus a number of integer values should handle
    NPY_LONG as input.

    But these need macros to convert the values. A negative unsigned int or a
    too large long should not be passed to the gsl function
    """
    _c_type = "long"
    _type_letter = "l"
    _numpy_type_code = "NPY_LONG"
    _value_for_failed = "LONG_MIN"
    _input_conversion_macro = None
    
    def _GetInputConversionMacro(self):
        return self._CheckMemberNotNone("_input_conversion_macro")

    def GetTmpVariables(self):
        pos = self.GetPyUFuncPosNumber()
        t_type = self.GetCType()

	name = self._GetTmpVariableName()
        #"long lval%s%d;" %(label, pos),
        code = [
		"%s %s;" %(t_type, name)
		]
        return code

    def NeedFailLabel(self):
        return True

    def GetInputTmpVariablesAssignment(self):
        label = self.GetTmpVariableLabel()
	macro = self._GetInputConversionMacro()
	
	pos = self.GetPyUFuncPosNumber()
	name = self._GetTmpVariableName()
	code = [
                 "if( (%s(*((long *) ip%d), &%s)) != GSL_SUCCESS){goto fail;}" %(macro, pos, name),
		]
	return code
    
class IntArgument(_LongArgument):
    _c_type = "int"
    _type_letter = "i"
    _value_for_failed = "INT_MIN"
    _input_conversion_macro = "_PyGSL_SF_L_TO_I"
    

class UnsignedIntArgument(_LongArgument):
    _c_type = "unsigned int"
    _type_letter = "ui"
    _value_for_failed = "INT_MIN"
    _input_conversion_macro = "_PyGSL_SF_L_TO_U"

class GSLModeTArgument(_LongArgument):
    _c_type = "gsl_mode_t"
    _type_letter = "m"
    _value_for_failed = "UINT_MIN"
    _input_conversion_macro = "_PyGSL_SF_L_TO_U"    

class _FloatArgumentInfo:
    _c_type = "float"
    _type_letter = "f"
    _value_for_failed = "_PyGSL_NAN"
    _numpy_type_code = "NPY_FLOAT"
    
    def GetTypeLetter(self):
        return "f"

    def GetNumpyTypeCode(self):
        return "NPY_FLOAT"
    
    def GetCType(self):
        return "float"

    def GetValueForFailedVariable(self):
        return "_PyGSL_NAN"

class _FloatArgumentAsMinor( _FloatArgumentInfo, _NeedsTemporaryVariables):
    pass
    
class DoubleArgument(_UFuncArgumentWithMinor):
    _c_type = "double"
    _type_letter = "d"
    _value_for_failed = "_PyGSL_NAN"
    _numpy_type_code = "NPY_DOUBLE"

    _minor = _FloatArgumentAsMinor
    
    def GetTypeLetter(self):
        return "d"

    def GetNumpyTypeCode(self):
        return "NPY_DOUBLE"
    
    def GetCType(self):
        return "double"

    def GetValueForFailedVariable(self):
        return "_PyGSL_NAN"

class _GSLComplexFloatArgumentInfo:
    _c_type = "gsl_complex_float"
    _type_letter = "F"
    _value_for_failed = ["_PyGSL_NAN", "_PyGSL_NAN"]
    _numpy_type_code = "NPY_CFLOAT"
    _c_sub_type = "float"



class GSLComplexFloatArgumentAsMinor( _GSLComplexFloatArgumentInfo, _NeedsTemporaryVariables):
    def GetInputTmpVariablesAssignment(self):
        name = self.GetTmpVariableName()
	pos = self.GetPyUFuncPosNumber()
	t_vars = (name, mi.GetCSubType(), self.GetCSubType(), pos)
	code = [
	    "%s.dat[0] = (%s) (* (%s *) ip%d);"      % t_vars,
	    "%s.dat[1] = (%s) (*((%s *) ip%d) + 1);" % t_vars
	    ]
	return code

    def GetOutputTmpVariablesAssignment(self):
        name = self.GetTmpVariableName()
	pos = self.GetPyUFuncPosNumber()
	t_vars = (mi.GetCSubType(), name, pos)
	code = [
	     "(* (%s *) op%d)      = %s.dat[0];" % t_vars,
	     "(*((%s *) op%d) + 1) = %s.dat[1];" % t_vars
	    ]
	return code

    def GetReturnCallArgument(self):
	label = self.GetTmpVariableName()
	code = [name]
	return code
    
class GSLComplexArgument(_NeedsTemporaryVariables, _UFuncArgumentWithMinor):
    _minor = GSLComplexFloatArgumentAsMinor

    _c_type = "gsl_complex"
    _type_letter = "D"
    _value_for_failed = ["_PyGSL_NAN", "_PyGSL_NAN"]
    _numpy_type_code = "NPY_CDOUBLE"
    _c_sub_type = "double"
    
    def GetReturnTmpVariablesAssignment(self):
        "Setting return from temporary variables to Ufunc arrays"
	name = self._GetTmpVariableName()	    
	pos = self.GetPyUFuncPosNumber()
        c_type = self.GetCSubType()
	code = [
            "*(( (%s *) op%d)    ) = %s.dat[0];" %(c_type, pos, name),
            "*(( (%s *) op%d) + 1) = %s.dat[1];" %(c_type, pos, name),
        ]
	return code
