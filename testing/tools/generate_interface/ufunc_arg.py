#!/usr/bin/env python
# Author: Pierre Schnizer <schnizer@users.sourceforge.net> 2016
# $Id$
"""
Wrapper for ufunc arguments.

Provides converters from each ufunc pointer type to the appropriate C types
Gives the code for the appropriate temporary variables.
"""

class NotImplementedMethod(Exception):
    pass

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

    The code given in this base class shall not cover the array pointer 
    conversions. These are defined in the derived classes
        * _NoTemporaryVariables : for all types that do not need temporary 
                                  variables
        * _NeedsTemporaryVariables : for all types that need a single temporary
                                  variable of some "atomic" type
    """
    
    # The C type that is wrapped, i.e the type the called function expects
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
	self._verbose = True
        
    def _CheckMemberNotNone(self, member_name):        
        member = getattr(self, member_name)
        if member == None:
            args = (self.__class__.__name__, member_name)
            raise ValueError("%s.%s == None" % args)
        return member

    def Verbose(self):
        " will emit extra description comments in the code"
        self._verbose = True
        
    def NoVerbose(self):
        self._verbose = False
        
        
    def GetTmpVariableLabel(self):
	if self._input_argument:
	    label = "i"
	elif self._output_argument:
	    label = "o"
	elif self._return_argument:
	    label = "r"
	else:
            msg = "%s: Don't know if I am input, output or return variable"
            msg = msg %(self.__class__.__name__)
	    raise ValueError(msg)

	return label
        
    def _GetTmpVariableName(self):
        "Create a temporary variable name"
        
        pos = self.GetPyUFuncPosNumber()
        label = self.GetTmpVariableLabel()
        letter = self.GetTypeLetter()

	name = "tmp%s%d" % (label, pos)
	return name

    def _NoCodeForMethod(self, msg):
        if self._verbose:
            name = self._GetTmpVariableName()
            return ["/* %s %s: no code for %s */ " %(self.__class__.__name__,  name, msg)]
        return [""]

    
    def GetCType(self):
        "The C type associated with this UFunc argument"
        return self._CheckMemberNotNone("_c_type")

    def GetCSubType(self):
        """The C sub type of this UFunc.
        e.g. a complex is made of two doubles
        """
        return self._CheckMemberNotNone("_c_sub_type")

    def NeedFailLabel(self):
        return False

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

    def GetFunctionReturnCast(self):
        """
        Function: cast of return to return variable

        Warning: must return only valid C code!
        """
        return [""]
	
    def GetInputConversion(self):
        raise NotImplementedMethod
        
        return self._NoCodeForMethod("input conversion ")

    def GetOutputConversion(self):

        t_type = self.GetCType()
        pos = self.GetPyUFuncPosNumber()
        code = "*((%s *) op%d)" % (t_type, pos)
        if self._verbose:
            code += " /**/"
        return code


    def GetOutVarsSetOnError(self):
        """
        If an error occurs set the error
        """
	code = self.GetOutputConversion()
	val = self.GetValueForFailedVariable()
	code = "%s = %s;" %(code, val)
	return [code]

class _NoTemporaryVariables(_UFuncArgument):
    """
    An UFunc which only needs to cast the array pointers
    """
    
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

    def GetReturnCallArgument(self):
	"""
        Return variable
	"""
	pos = self.GetPyUFuncPosNumber()
	ct = self.GetCType()
	code = "*((%s *) op%d)" % (ct, pos)
	if self._verbose:
            code = "/* %s: return variable */ %s" %(self.__class__.__name__, code)
	return [code]

    def GetTmpVariables(self):
        "Code for declaring temporary assignments"
        return self._NoCodeForMethod("get tmp var")

    def GetInputTmpVariablesAssignment(self):
        "Setting temporary variables from input"
        return self._NoCodeForMethod("input tmp var")

    def GetOutputTmpVariablesAssignment(self):
        "Setting output from temporary variables"
        return self._NoCodeForMethod("output tmp var")

    def GetReturnTmpVariablesAssignment(self):
        "Setting output from temporary variables"
        return self._NoCodeForMethod("return tmp var")

class _NeedsTemporaryVariables(_UFuncArgument):
    """
    A ufunc that needs temporary variables for the call
    """
    def _GetCTypeForUFunc(self):
        "For this class it is the same"
        return self.GetCtype()
    
    def GetTmpVariables(self):
	name = self._GetTmpVariableName()	
        code = "%s %s;" %(self.GetCType(), name)
        if self._verbose:
            args = (self.__class__.__name__, self._c_type)
            code += " /* %s: _c_type %s */" % args

        return [code]

    def GetInputConversion(self):
        raise NotImplementedMethod

        t_type = self.GetCTypeForUFunc()
        pos = self.GetPyUFuncPosNumber()
        code = "/*in conv*/ *((%s *) ip%d)" % (t_type, pos)
        return code

    def GetReturnArgumentConversion(self):
	name = self._GetTmpVariableName()	            
        return self._NoCodeForMethod("Return Argument Conversion")

    def GetInputTmpVariablesAssignment(self):
	name = self._GetTmpVariableName()	    
	pos = self.GetPyUFuncPosNumber()
        t_type = self.GetCTypeForUFunc()
        code = "%s = *((%s *) ip%d);" %(name, t_type, pos)
        return [code]

    def GetReturnTmpVariablesAssignment(self):
        "Setting return from temporary variables to Ufunc arrays"
	name = self._GetTmpVariableName()	    
	pos = self.GetPyUFuncPosNumber()
        t_type = self.GetCTypeForUFunc()
	code = "(*((%s *) op%d)) = %s;" %(t_type, pos, name)
        if self._verbose:
            code += " /* %s: return assignment */" % (self.__class__.__name__,)
	return [code]

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
    #    c_type = self._GetCType()
    #    return ["(%s)" %(c_type,)]

    def GetOutVarsSetOnError(self):
	code = self.GetOutputConversion()
	val = self.GetValueForFailedVariable()
	code = "%s = %s;" %(code, val)
	return [code]

class _UFuncArgumentToCast(_NeedsTemporaryVariables):
    """
    this type is a minor to a major type ...
    """
    _c_type_of_ufunc = None

    def GetCTypeForUFunc(self):
        "The C type the ufunc has ...."
        return self._CheckMemberNotNone("_c_type_of_ufunc")
    
    
class _UFuncArgumentWithMinor(_UFuncArgument):
    """
    Used to define a minor type. 

    Be aware that any subclass must/should also subclass 
    _NoTemporaryVariables
    _NeedsTemporaryVariables
    """
    _minor = None

    def __init__(self):
	_UFuncArgument.__init__(self)

	self._minor_ins = None
	if self._minor != None:
	    self._minor_ins = self._minor()

    def _AssertMinorInstance(self):
        if self._minor_ins == None:
            msg = "%s: Should have a minor instance, but it was not created!"
            msg = msg % (self.__class__.__name__)
            raise NoMinor(msg)
        
    def GetMinorInstance(self):
        self._AssertMinorInstance()
        return self._minor_ins

    def SetPyUFuncPosNumber(self, num):
        self._AssertMinorInstance()        
        self._minor_ins.SetPyUFuncPosNumber(num)
	_UFuncPosNum.SetPyUFuncPosNumber(self, num)        
    
    def SetInputArgument(self):
        self._AssertMinorInstance()        
        _UFuncArgument.SetInputArgument(self)
        self._minor_ins.SetInputArgument()
        
    def SetOutputArgument(self):
        self._AssertMinorInstance()        
        _UFuncArgument.SetOutputArgument(self)
        self._minor_ins.SetOutputArgument()
        
    def SetReturnArgument(self):
        self._AssertMinorInstance()        
        _UFuncArgument.SetReturnArgument(self)
        self._minor_ins.SetReturnArgument()
    
#del _UFuncArgument
    
class _LongArgument(_UFuncArgumentToCast):
    """
    py3 integers are longs. Thus a number of integer values should handle
    NPY_LONG as input.

    But these need macros to convert the values. A negative unsigned int or a
    too large long should not be passed to the gsl function
    """
    _c_type_of_ufunc = "long"
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

class _FloatArgumentAsMinor( _FloatArgumentInfo, _UFuncArgumentToCast):
    _c_type = "double"
    _c_type_of_ufunc = "float"
    
class DoubleArgument(_UFuncArgumentWithMinor, _NoTemporaryVariables):
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


class _GSLComplexTmpVarAssignment:
    " Just to save code dublication "
    def GetInputTmpVariablesAssignment(self):
        name = self._GetTmpVariableName()
	pos = self.GetPyUFuncPosNumber()
	t_vars = (name, self.GetCSubType(), pos)
	code = [
	    "%s.dat[0] = *  ((%s *) ip%d);"      % t_vars,
	    "%s.dat[1] = *( ((%s *) ip%d) + 1);" % t_vars
	    ]
	return code

    def _GetOutReturnVariablesAssignment(self):
        name = self._GetTmpVariableName()
	pos = self.GetPyUFuncPosNumber()
        c_type = self.GetCSubType()
	t_vars = (c_type,  pos, name)
	code = [
	     "*  ((%s *) op%d)      = %s.dat[0];" % t_vars,
	     "*( ((%s *) op%d) + 1) = %s.dat[1];" % t_vars
	    ]
	return code
    
    def GetReturnTmpVariablesAssignment(self):
        return self._GetOutReturnVariablesAssignment()
    
    def GetOutputTmpVariablesAssignment(self):
        return self._GetOutReturnVariablesAssignment()

    def GetReturnTmpVariablesAssignment(self):
        return self._GetOutReturnVariablesAssignment()
    
    def GetOutputTmpVariablesAssignment(self):
        return self._GetOutReturnVariablesAssignment()
    
    def GetReturnCallArgument(self):
	name = self._GetTmpVariableName()
	code = [name]
	return code
    
class GSLComplexFloatArgumentAsMinor(_GSLComplexTmpVarAssignment, _GSLComplexFloatArgumentInfo,  _UFuncArgumentToCast):
    _c_type = "gsl_complex"
    _c_type_of_ufunc = "gsl_complex_float"
    
    
class GSLComplexArgument(_GSLComplexTmpVarAssignment, _UFuncArgumentWithMinor, _NeedsTemporaryVariables):
    _minor = GSLComplexFloatArgumentAsMinor

    _c_type = "gsl_complex"
    _type_letter = "D"
    _value_for_failed = ["_PyGSL_NAN", "_PyGSL_NAN"]
    _numpy_type_code = "NPY_CDOUBLE"
    _c_sub_type = "double"

    def __init__(self, *args, **kws):
        _UFuncArgumentWithMinor.__init__(self, *args, **kws)
        assert(self._minor_ins != None)
        
