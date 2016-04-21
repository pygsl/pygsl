from __future__ import print_function
import copy
import ufunc_arg

_bcls = ufunc_arg._NeedsTemporaryVariables
class _GSLSfResult(_bcls):
    """
    These are not classical UFunc argumets: These need more than
    one UFunc array for their data.

    assuming currently that these are only out arguments
    """
    _cls_s = None
    def __init__(self):
        assert(self._cls_s != None)
        _bcls.__init__(self)

        sub_types = map(lambda x: x(), self._cls_s)
        sub_types = tuple(sub_types)
        self._sub_types = sub_types


    def GetArrayType(self, argumentnumber, minor = None):
        s = self._sub_types[argumentnumber]

        if minor:
            try:
                s = s.GetMinorInstance()
            except ufunc_arg.NoMinor:
                pass

        result = s.GetNumpyTypeCode()
        return result

    def GetTmpVariables(self):
        pos = self.GetPyUFuncPosNumber()
	label = self.GetTmpVariableLabel()
        c_type = self.GetCType()
        code = [
            "%s tmp%s%d;" %(c_type, label, pos)
        ]
        return code

    def GetOutputCallArgument(self):
        pos = self.GetPyUFuncPosNumber()
	label = self.GetTmpVariableLabel()
        code = ["&tmp%s%d" %(label, pos)]
        return code
    
    def GetNumberOutArgs(self):
        self._CheckMemberNotNone("_output_argument")        
        l = len(self._sub_types)
        return l

    def GetInputConversion(self):
        raise ValueError("not implemented")
        
    def GetInputCallArgument(self):
        raise ValueError("not implemented")

    def GetReturnCallArgument(self):
        raise ValueError("not implemented")

    def GetInputTmpVariablesAssignment(self):
        raise ValueError("not implemented")

         
class GSLSfResult(_GSLSfResult):
    _c_type = "gsl_sf_result"
    _type_letter = "rd"
    _value_for_failed = ["_PyGSL_NAN", "_PyGSL_NAN"]

    _cls_s = (ufunc_arg.DoubleArgument,) * 2


    def GetOutputTmpVariablesAssignment(self):
        pos = self.GetPyUFuncPosNumber()
        label = self.GetTmpVariableLabel()

        t_type0 = self._sub_types[0].GetCType()
        t_type1 = self._sub_types[1].GetCType()

        fmt = "*((%s *) op%d) = tmp%s%d.val;"
        val = fmt % (t_type0, pos, label, pos)
        fmt = "*((%s *) op%d) = tmp%s%d.err;"
        err = fmt % (t_type1, pos+1, label, pos)

        return [val, err]

    def GetOutVarsSetOnError(self):
        pos = self.GetPyUFuncPosNumber()
        t_type0 = self._sub_types[0].GetCType()
        t_type1 = self._sub_types[1].GetCType()

        fmt = "*((%s *) op%d) = _PyGSL_NAN;"
        code = [
            fmt %(t_type0, pos, ),
            fmt %(t_type1, pos +1 ),
        ]
        return code
    


    def GetValueForFailedVariable(self):
        return "{_PyGSL_NAN,_PyGSL_NAN}"



    
class GSLSfResultE(_GSLSfResult):
    _c_type = "gsl_sf_result_e"
    _type_letter = "erd"
    _value_for_failed = ["_PyGSL_NAN", "_PyGSL_NAN"]

    _cls_s = (ufunc_arg.DoubleArgument,) * 2 + (ufunc_arg.IntArgument,)

    def GetOutputTmpVariablesAssignment(self):
        pos = self.GetPyUFuncPosNumber()
        label = self.GetTmpVariableLabel()

        t_type0 = self._sub_types[0].GetCType()
        t_type1 = self._sub_types[1].GetCType()
        t_type2 = self._sub_types[2].GetCType()

        fmt = "*((%s *) op%d) = tmp%s%d.val;"
        val = fmt % (t_type0, pos, label, pos)
        
        fmt = "*((%s *) op%d) = tmp%s%d.err;"
        err = fmt % (t_type1, pos+1, label, pos)
        
        fmt = "*((%s *) op%d) = tmp%s%d.e10;"
        e10 = fmt % (t_type2, pos+2, label, pos)

        return [val, err, e10]

    def GetOutVarsSetOnError(self):
        pos = self.GetPyUFuncPosNumber()
        t_type0 = self._sub_types[0].GetCType()
        t_type1 = self._sub_types[1].GetCType()
        t_type2 = self._sub_types[2].GetCType()

        fmt  = "*((%s *) op%d) = _PyGSL_NAN;"
        fmt2 = "*((%s *) op%d) = INT_MIN;"
        code = [
            fmt %(t_type0, pos, ),
            fmt %(t_type1, pos +1 ),
            fmt %(t_type2, pos +2)
        ]
        return code
    
    def GetNumpyTypeCode(self):        
        return [
            self._sub_types[0].GetNumpyTypeCode(),
            self._sub_types[1].GetNumpyTypeCode(),
            self._sub_types[2].GetNumpyTypeCode()
        ]

class _Argument:
    """
    Descirbes one argument.

    Also handles the different type casts. e.g a function handling doubles can
    be also evaluated with arrays of floats.
    
    letter nomenclatura
    f   ... float
    d   ... double
    c   ... gsl_complex
    r*  ... gsl_sf_result
    er* ... gsl_sf_result_e10
    i   ... integer
    m   ... gsl_mode_t
    ui  ... unsigned int
    l   ... long
    p   ... use return value as normal return to user(parameter)
    q   ... use return as error flag to print warning or raise error
            ("quality" :-)
    """
    def __init__(self):
        self._type = None
        self._operator = None
        self._name = None

        # Can I use a direct C subtype
	self._sub_types = None
        
        # or shall it be a GSL subtype
	self._gsl_sub_types = None
        
        self._py_ufunc_pos_number = None
	self._gsl_pos_number = None

        self._input_argument = None
        self._output_argument = None
        self._return_argument = None
        

    def GetGSLPosNumber(self):
	num = self._gsl_pos_number
	assert(num != None)
	return num

    def GetGSLType(self):
        return self._type

        
    def GetPyUFuncPosNumber(self):
	num = self._py_ufunc_pos_number
        if num == None:
            msg = "%s: Getting PyUFunc pos number to %s" %(self.__class__.__name__, num)
	    raise ValueError(msg)

	return num
        
    def _CheckMemberNotNone(self, member_name):        
        member = getattr(self, member_name)
        if member == None:
            args = (self.__class__.__name__, member_name)
            raise ValueError("%s.%s == None" % args)
        return member

        
    def _GetSubTypesToUse(self):
        if self._gsl_sub_types == None:
            if self._sub_types == None:
                msg = "Either sub types or gsl sub types must be defined!"
                raise ValueError(msg)            

        if self._gsl_sub_types != None:
            sub_types = self._gsl_sub_types
        else:
            sub_types = self._sub_types

        assert(sub_types != None)
        return sub_types
                

    
    def _CollectCode(self, method_name):

        # Number not needed here ... but see if it was already set for the
        # sub types
        self.GetPyUFuncPosNumber()


        sub_types = self._GetSubTypesToUse()
        code = []
        for s in sub_types:
            method = getattr(s, method_name)
            tmp = method()
            if tmp:
                code.extend(tmp)
        return code


    def NeedFailLabel(self):
        need = 0
        sub_types = self._GetSubTypesToUse()
        for s in sub_types:
            if s.NeedFailLabel():
                need = 1
                break
        return need

    def GetTmpVariables(self):
        return self._CollectCode("GetTmpVariables")

    def GetOutVarsSetOnError(self):
        return self._CollectCode("GetOutVarsSetOnError")


    def GetInputCallArgument(self):
        self._CheckMemberNotNone("_input_argument")
        return self._CollectCode("GetInputCallArgument")

    def GetOutputCallArgument(self):
        self._CheckMemberNotNone("_output_argument")
        return self._CollectCode("GetOutputCallArgument")

    def GetFunctionReturnCast(self):
        """
        Currently I see that only a single function cast makes sense
        """
        self._CheckMemberNotNone("_return_argument")
        result =  self._CollectCode("GetFunctionReturnCast")
        l = len(result)
        assert(l == 1)
        return result
    
    def GetReturnCallArgument(self):
        self._CheckMemberNotNone("_return_argument")
        
        result = self._CollectCode("GetReturnCallArgument")
        l = len(result)
        assert(l == 1)
        return result

    def GetTmpVariables(self):
        return self._CollectCode("GetTmpVariables")
    
    def GetInputTmpVariablesAssignment(self):
        self._CheckMemberNotNone("_input_argument")
        return self._CollectCode("GetInputTmpVariablesAssignment")

    def GetReturnTmpVariablesAssignment(self):
        self._CheckMemberNotNone("_return_argument")
        return self._CollectCode("GetReturnTmpVariablesAssignment")

    def GetOutputTmpVariablesAssignment(self):
        self._CheckMemberNotNone("_output_argument")
        return self._CollectCode("GetOutputTmpVariablesAssignment")
    
    def GetNumberInArgs(self):
        """
        returns how many input arguments are needed for the represented type
        """
        l = len(self._sub_types)
        assert(l == 1)
        return 1
    
    def GetNumberOutArgs(self):
        """
        returns how many output  arguments are needed for the represented type
        """

        if self._gsl_sub_types != None:
            assert(len(self._gsl_sub_types) == 1)
            s = self._gsl_sub_types[0]
            return s.GetNumberOutArgs()
        
        l = len(self._sub_types)
        assert(l == 1)        
        return 1

    def IsComplex(self):
        return self._type == "gsl_complex"
    
    def IsResult(self):
        return self._type == "gsl_sf_result"

    def IsGSLMode(self):
        return self._type == "gsl_mode_t"
    
    def IsResulte10(self):
        return self._type == "gsl_sf_result_e10"

    def GetFakeType(self, argnumber, minor):
        """
        Currently I only fake float as double .... 
        """
        if minor and self._type == 'double':
            return 'float'
        #if minor and self._type == 'gsl_complex':
        #    return 'gsl_complex_float'
        return None

    
    def GetBasisType(self):        
        if self._operator:
            return  self._type + ' ' +  self._operator
        return self._type

    
    def GetType(self, minor, argnum):
        if self._type == "gsl_sf_result":
            if minor == 1:
                return "float"
            else:
                return "double"

        if self._type == "gsl_sf_result_e10":
            if argnum == 2:
                return "int"
            else:
                if minor == 1:            
                    return "float"
                else:
                    return "double"

        return self._type

    #def GetErrorValueAssignment(self, minor, argnum):
    #    num = self.GetPyUFuncPosNumber()
    #
    #    if self._type == "gsl_sf_result":
    #        t_type = self.GetType(minor, argnum)
    #        code = ""
    #        code = ""
    #
    #    if self._type == "gsl_sf_result_e10":
    #        if argnum == 2:
    #            return "int"
    #        else:
    #            if minor == 1:            
    #                return "float"
    #            else:
    #                return "double"
    #
    #    return self._type
	
    def GetTypeLetter(self, minor):            
        if self._type == "double":
            if minor == 1:
                return "f"
            return "d"

        if self._type == "gsl_complex":
            if minor == 1:
                return "F"
            return "D"

        #if self._type == "gsl_complex_float":
        #    return "F"

        if self._type == "float":
            return "f"

        if self._type == "gsl_mode_t":
            return "m"

        if self._type == "unsigned int":
            return "ui"

        if self._type == "int":
            return "i"

        if self._type == "gsl_sf_result":
            if minor == 1:
                return "rf"
            return "rd"
        
        if self._type == "gsl_sf_result_e10":
            if minor == 1:
                return "erf"
            return "erd"

        raise ValueError("No known Type defined")
        
    def GetArrayType(self, argumentnumber, minor=None):
        """
        Get the type for the approbriate argument number.
        """

        if self._gsl_sub_types != None:
            l = len(self._gsl_sub_types)
            assert(l == 1)            
            s = self._gsl_sub_types[0]
            return s.GetArrayType(argumentnumber, minor = minor)
            
        l = len(self._sub_types)
        assert(l == 1)

        if argumentnumber != 0:
            raise ValueError("argumentnumber = %d != 0" %(argumentnumber,))
        
        t_type = self._sub_types[argumentnumber]
        if minor:
            try:
                t_type = t_type.GetMinorInstance()
            except ufunc_arg.NoMinor:
                pass
            
        return t_type.GetNumpyTypeCode()

        ## Old code ... before refacturing
        #if self._type == "double":
        #    if minor == 1:
        #        return "NPY_FLOAT"
        #    return "NPY_DOUBLE"
        #
        #if self._type == "float":
        #    return "NPY_FLOAT"
        #
        ## Next three ... standard pyton ints are mapped to C longs 
        #if self._type == "gsl_mode_t":
        #    #return "NPY_INT"
        #    return "NPY_LONG"
        #
        #if self._type == "unsigned int":
        #    #return "NPY_UINT"
        #    return "NPY_LONG"
        #
        #if self._type == "int":
        #    #return "NPY_INT"
        #    return "NPY_LONG"
        #
        #if self._type == "gsl_complex":
        #    #if minor == 1:
        #    #    return "NPY_CFLOAT"
        #    return "NPY_CDOUBLE"
        #
        #if self._type == "gsl_sf_result":
        #    if minor == 1:
        #        return "NPY_FLOAT"
        #    return "NPY_DOUBLE"
        #
        #if self._type == "gsl_sf_result_e10":
        #    if argumentnumber == 2:
        #        return "NPY_INT"
        #    if minor == 1:
        #        return "NPY_FLOAT"
        #    return "NPY_DOUBLE"
        #raise ValueError("Unknown type -->%s<-- for variable -->%s<-- " % (self._type, self._name))
        
        
    def __repr__(self):
        return "variable : %s\n   type : %s\n    op : %s\n" %(self._name, self._type, self._operator)


class Argument(_Argument):
    """
    Subclass as Minor instance 
    """
    def __init__(self):
        _Argument.__init__(self)
        self.__minor_ins = None

    def _CreateArgumentCopy(self):
        cp = _Argument()
        cp._type                = self._type               
        cp._operator            = self._operator           
        cp._name                = self._name
        
	cp._gsl_pos_number      = self._gsl_pos_number     
	cp._sub_types           = self._sub_types          
	cp._gsl_sub_types       = self._gsl_sub_types      
        cp._py_ufunc_pos_number = self._py_ufunc_pos_number

        cp._input_argument      = self._input_argument     
        cp._output_argument     = self._output_argument    
        cp._return_argument     = self._return_argument    
        return cp
    
    def _CreateMinorInstance(self):
        """
        """
        sub_arg = self._CreateArgumentCopy()
        sub_types = self._GetSubTypesToUse()

        result = []
        for t in sub_types:
            gsl_type = t.GetCType()
            try:
                tmp = t.GetMinorInstance()
            except ufunc_arg.NoMinor as nm:
                if gsl_type in ("double", "gsl_complex"):
                    raise nm
                
                tmp = t
                
            result.append(tmp)            
        result = tuple(result)

        if self._gsl_sub_types != None:
            sub_arg._gsl_sub_types = result
        else:            
            sub_arg._sub_types = result

        self.__minor_ins = sub_arg
        
    def GetMinorInstance(self):
        """
        """
        if self.__minor_ins == None:
            self._CreateMinorInstance()

        assert(self.__minor_ins)
        return self.__minor_ins

    def GetMinorInstanceNoFail(self):
        return self.GetMinorInstance()

    # Minor instance shall not be settable
    def SetPyUFuncPosNumber(self, num):
	self._py_ufunc_pos_number = int(num)
        
        if self._gsl_sub_types != None:
            cnt = 0
            for s in self._gsl_sub_types:
                s.SetPyUFuncPosNumber(num)
                cnt += 1
            assert(cnt == 1)
            return
        
                
        l = len(self._sub_types)

        test = self.GetNumberOutArgs()
        assert(test == l)
        
        for cnt in range(l):
            st = self._sub_types[cnt]
            #print("%s setting to %s" %( self.__class__.__name__, st.__class__.__name__))
            i = num + cnt
            st.SetPyUFuncPosNumber(i)
            
    def SetGSLPosNumber(self, num):
	self._gsl_pos_number = int(num)
	
    def SetName(self, name):
        """
        The name of the argument.
        """
        self._name = name

    def SetOperator(self, operator):
        """
        XXX ??? Perhaps a qualifier ???
        """
        self._operator = operator

    
    def SetType(self, mytype):
        """
        The type of the argument
        """
        self._type = mytype

	sub_types = []
	gsl_sub_types = []
        
	if self._type == "int":
	    sub_types.append(ufunc_arg.IntArgument())
            
        elif self._type == "unsigned int":
	    sub_types.append(ufunc_arg.UnsignedIntArgument())
            
        elif self._type == "double":
	    sub_types.append(ufunc_arg.DoubleArgument())
            
        elif self._type == "gsl_complex":
	    sub_types.append(ufunc_arg.GSLComplexArgument())
            
        elif self._type == "gsl_mode_t":
	    sub_types.append(ufunc_arg.GSLModeTArgument())
            
        elif self._type == "gsl_sf_result":
            gsl_sub_types.append(GSLSfResult())

        elif self._type == "gsl_sf_result_e10":
            gsl_sub_types.append(GSLSfResultE())
            
        else:
            raise ValueError("type '%s' not known" %(mytype,))

        if len(sub_types) == 0:
            self._sub_types = None            
        else:
            self._sub_types = sub_types

        if len(gsl_sub_types) == 0:
            self._gsl_sub_types = None            
        else:
            self._gsl_sub_types = gsl_sub_types

            
        if self._sub_types == None:
            assert(self._gsl_sub_types != None)
            
        if self._gsl_sub_types == None:
            assert(self._sub_types != None)


    def _SetArgumentType(self, method_name):
        if self._gsl_sub_types != None:
            for s in self._gsl_sub_types:
                method = getattr(s, method_name)
                method()
            return
        
        for s in self._sub_types:
            method = getattr(s, method_name)
            method()
        
    def SetInputArgument(self):
        "Argument is an input argument"
        self._SetArgumentType("SetInputArgument")

        self._input_argument = True

    def SetOutputArgument(self):
        "Argument is an input argument"
        self._SetArgumentType("SetOutputArgument")

        self._output_argument = True

    def SetReturnArgument(self):
        "Argument is an input argument"
        self._SetArgumentType("SetReturnArgument")

        self._return_argument = True
    
