from __future__ import print_function
import ufunc_arg
import common
import copy

_bcls = ufunc_arg._UFuncArgumentWithMinor
class _GSLSfResultBasis(_bcls):
    """
    These are not classical UFunc argumets: These need more than
    one UFunc array for their data.

    assuming currently that these are only out arguments
    """
    __slots__ = ["_sub_types", ]
    _cls_s = None
    def __init__(self):
        assert(self._cls_s != None)
        _bcls.__init__(self)

        sub_types = map(lambda x: x(), self._cls_s)
        sub_types = tuple(sub_types)

        ids = map(lambda x: id(x), sub_types)
        s = set(ids)
        assert(len(s) == len(sub_types))
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
        c_type = self.GetCalledFunctionCType()
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
        #assert(self.IsOutputArgument())
        #if not self.IsOutputArgument():            
        #    return 0
        
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

class _GSLSfResultFloatArgumentInfo:
    _c_type = "gsl_sf_result_float"
    _type_letter = "rf"
    _value_for_failed = "_PyGSL_NAN"
    _numpy_type_code = "NPY_FLOAT"

    def GetTypeLetter(self):
        return "f"

    #def GetNumpyTypeCode(self):
    #    return "NPY_FLOAT"

    def GetCType(self):
        return "float"

    def GetValueForFailedVariable(self):
        return "_PyGSL_NAN"

class _GSLSfResult(_GSLSfResultBasis):

    def GetNumpyTypeCode(self):
        assert(self._numpy_type_code != None)
        return [self._numpy_type_code] * 2

    def GetOutputTmpVariablesAssignment(self):
        pos = self.GetPyUFuncPosNumber()
        label = self.GetTmpVariableLabel()

        t_type0 = self._sub_types[0].GetCType()
        t_type1 = self._sub_types[1].GetCType()

        fmt = "*((%s *) op%d) = (%s) tmp%s%d.val;"
        val = fmt % (t_type0, pos, t_type0,  label,  pos)
        fmt = "*((%s *) op%d) = (%s) tmp%s%d.err;"
        err = fmt % (t_type1, pos+1, t_type1, label, pos)

        return [val, err]

    def GetOutputVariablesSetOnError(self):
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


    def GetStrideVariable(self):
        label = self.GetTmpVariableLabel()
        pos = self.GetPyUFuncPosNumber()
        
        fmt = "%ss%%d" %(label,)
        code = [
            fmt %(pos, ),
            fmt %(pos +1 ),
        ]
        return code

    def GetArrayPointerVariables(self):
        label = self.GetTmpVariableLabel()
        pos = self.GetPyUFuncPosNumber()
        
        fmt = "%sp%%d" %(label,)
        code = [
            fmt %(pos, ),
            fmt %(pos +1 ),
        ]
        return code


    def GetPyVariableNames(self):
        name = self.GetName()
        items = self._struct_items
        result = map(lambda entry:  name + entry, items)
        return result

    def GetPyVariableNamesDecl(self):
        names = self.GetPyVariableNames()
        pos = self.GetPyUFuncPosNumber()

        struct_items = self._struct_items
        
        names = tuple(names)
        if len(names) == 1:
            names = names * len(struct_items)
            
        r = []
        arg_desc = ":param %s %s: positional argument %d"
        for cnt in range(len(struct_items)):
            item = self._struct_items[cnt]
            sub_type = self._sub_types[cnt]
            t_name = names[cnt]
            t_pos = pos + cnt

            # Requires fix!
            # t_pos = sub_type.GetPyUFuncPosNumber()            
            arg_type = sub_type.GetCType()

            des = arg_desc % (arg_type, t_name, t_pos,)
            r.append(des)
        r = tuple(r)
        return r

    
class _GSLSfFloatArgumentAsMinor( _GSLSfResultFloatArgumentInfo, _GSLSfResult):
    _cls_s = (ufunc_arg._FloatArgumentAsMinor,) * 2
    def GetCalledFunctionCType(self):
        return "gsl_sf_result"

         
class GSLSfResult(_GSLSfResult):
    _c_type = "gsl_sf_result"
    _type_letter = "rd"
    _numpy_type_code = "NPY_DOUBLE"
    _value_for_failed = ["_PyGSL_NAN", "_PyGSL_NAN"]

    _cls_s = (ufunc_arg.DoubleArgument,) * 2
    _minor = _GSLSfFloatArgumentAsMinor
    _struct_items = (".val", ".err")


        
class _GSLSfResultE(_GSLSfResultBasis):
    _struct_items = (".val", ".err", ".e10")

    def NeedFailLabel(self):
        """Does not require one

        The last subtype is an int ... but that is an output so it does not need
        to be set as fail
        """
        return False
    
    def GetOutputTmpVariablesAssignment(self):
        pos = self.GetPyUFuncPosNumber()
        label = self.GetTmpVariableLabel()

        t_type0 = self._sub_types[0].GetCType()
        t_type1 = self._sub_types[1].GetCType()
        t_type2 = self._sub_types[2].GetCType()

        fmt = "*((%s *) op%d) = (%s) tmp%s%d.val;"
        val = fmt % (t_type0, pos, t_type0, label,  pos)
        
        fmt = "*((%s *) op%d) = (%s) tmp%s%d.err;"
        err = fmt % (t_type1, pos+1, t_type1, label,  pos)
        
        fmt = "*((%s *) op%d) = (%s) tmp%s%d.e10;"
        e10 = fmt % (t_type2, pos+2, t_type2, label,  pos)

        return [val, err, e10]


    
            

    def GetOutputVariablesSetOnError(self):
        pos = self.GetPyUFuncPosNumber()
        t_type0 = self._sub_types[0].GetCType()
        t_type1 = self._sub_types[1].GetCType()
        t_type2 = self._sub_types[2].GetCType()

        fmt  = "*((%s *) op%d) = _PyGSL_NAN;"
        fmt2 = "*((%s *) op%d) = INT_MIN;"
        code = [
            fmt %(t_type0, pos, ),
            fmt %(t_type1, pos +1 ),
            fmt2 %(t_type2, pos +2)
        ]
        return code
    
    def GetArrayPointerVariables(self):
        label = self.GetTmpVariableLabel()
        pos = self.GetPyUFuncPosNumber()
        
        fmt = "%sp%%d" %(label,)
        code = [
            fmt %(pos, ),
            fmt %(pos +1 ),
            fmt %(pos +2 ),
        ]
        return code

    def GetNumpyTypeCode(self):
        l = []
        for t in self._sub_types:
            tmp = t.GetNumpyTypeCode()
            l.extend(tmp)
        return l
    
class GSLSfResultE(_GSLSfResultE):
    _c_type = "gsl_sf_result_e10"
    _type_letter = "erd"
    _value_for_failed = ["_PyGSL_NAN", "_PyGSL_NAN", "INT_MIN"]

    _cls_s = (ufunc_arg.DoubleArgument,) * 2 + (ufunc_arg.IntArgument,)


class _Argument(common._ArgumentType):
    """Descirbes one argument to the prototype

    Also handles the different type casts. e.g a function handling doubles can
    be also evaluated with arrays of floats.
    """

    __slots__ = ['_type', '_operator', '_name', '_gsl_pos_number', '_sub_types', '_gsl_sub_types', '_py_ufunc_pos_number',
                 '_is_prepared_for_emitting_code', '_as_minor'
                 ]

    _type_dic = None
    # XXX why to destinquish ... perhaps a clear up candidate
    _gsl_type_dic = None
    
    def __init__(self):
        super().__init__()
        self._type = None
        self._operator = None
        self._name = None

        self._gsl_pos_number = None
        
        # Can I use a direct C subtype
        self._sub_types = None
        
        # or shall it be a GSL subtype
        self._gsl_sub_types = None
        
        self._py_ufunc_pos_number = None

        self._is_prepared_for_emitting_code = False

        self._as_minor = False

    def AsMinor(self):

        def get_minor(obj):
            try:
                ins = obj.GetMinorInstance()
            except ufunc_arg.NoMinor:
                return obj
            return ins
        
        cpy = copy.copy(self)
        if cpy._sub_types is None:
            pass
        else:
            n_sub_types = map(get_minor, cpy._sub_types)
            cpy._sub_types = tuple(n_sub_types)

        if cpy._gsl_sub_types is None:
            pass
        else:
            n_gsl_sub_types = map(get_minor, cpy._gsl_sub_types)
            cpy._gsl_sub_types = tuple(n_gsl_sub_types)
        return cpy

    def SetGSLPosNumber(self, num):
        self._gsl_pos_number = int(num)

    def GetGSLPosNumber(self):
        num = self._gsl_pos_number
        assert(num != None)
        return num

    def GetGSLType(self):
        return self._type

    def SetPyUFuncPosNumber(self, num):
        """Pass this position number on to the arguments

        What is that doing?
        
        """
        self._py_ufunc_pos_number = int(num)
        
        assert(self._sub_types != None or self._gsl_sub_types != None)
        
        if self._gsl_sub_types != None:
            cnt = 0
            for s in self._gsl_sub_types:
                s.SetPyUFuncPosNumber(num)
                cnt += 1
            assert(cnt == 1)
            return        
                
        l = len(self._sub_types)
        if self.IsInputArgument():
            test = self.GetNumberInArgs()
        elif self.IsOutputArgument():
            test = self.GetNumberOutArgs()
        elif self.IsReturnArgument():
            test = self.GetNumberReturnArgs()

            
        else:
            raise ValueError("Should not end up here")
            
            
        if l == test:
            pass
        else:
            raise ValueError("n outargs expected to be '%s' but is '%s'" %(l, test))
        assert(test == l)
        
        for cnt in range(l):
            st = self._sub_types[cnt]
            #print("%s setting to %s" %( self.__class__.__name__, st.__class__.__name__))
            i = num + cnt
            st.SetPyUFuncPosNumber(i)
        
    def GetPyUFuncPosNumber(self):
        "Which call argument position will it be when the user calls it from python"
        num = self._py_ufunc_pos_number
        if num == None:
            msg = "%s: Getting PyUFunc pos number to %s" %(self.__class__.__name__, num)
            raise ValueError(msg)

        return num
	
    def SetName(self, name):
        """The name of the argument.
        """
        self._name = name

    def GetName(self):
        return self._name

    def GetOperator(self):
        op = self._operator
        if op == None:
            return ""
        return op
    
    def SetOperator(self, operator):
        """
        XXX ??? Perhaps a qualifier ???
        """
        self._operator = operator

    
    def SetType(self, mytype):
        """Set the argument type

        Determines the appropriate subtype for representing the variable
        """
        self._type = mytype

        sub_types = []
        gsl_sub_types = []


        assert(self._type_dic is not None)

        standard_type = False
        try:
            a_type = self._type_dic[self._type]
            standard_type = True
        except KeyError:
            pass

        if standard_type == True:
            assert(a_type is not None)
            tmp = a_type()
            sub_types.append(tmp)            
        else:
            assert(self._gsl_type_dic is not None)
            a_type = self._gsl_type_dic[self._type]
            tmp = a_type()
            gsl_sub_types.append(tmp)
        
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



    def _GetSubTypesToUse(self):
        if self._gsl_sub_types != None:
            sub_types = self._gsl_sub_types
        else:
            sub_types = self._sub_types

        assert(sub_types != None)
        return sub_types

    def _CollectCode(self, method_name):
        """Iterate over the subtypes and collect the returned code

        Args:
             method_name : the name of the method
        """
        if not self._is_prepared_for_emitting_code:
            self.PrepareForEmittingCode()
            
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

    def GetVariableNames(self):
        return self._CollectCode("GetVariableNames")
    
    def GetTmpVariables(self):
        return self._CollectCode("GetTmpVariables")

    def GetOutVarsSetOnError(self):
        return self._CollectCode("GetOutVarsSetOnError")

    def GetStrideVariable(self):
        return self._CollectCode("GetStrideVariable")

    def GetStrideDeclaration(self):
        return self._CollectCode("GetStrideDeclaration")

    def GetStrideAssignment(self):
        return self._CollectCode("GetStrideAssignment")

    def GetArrayPointerDeclaration(self):
        return self._CollectCode("GetArrayPointerDeclaration")

    def GetNumpyTypeCode(self):
        return self._CollectCode("GetNumpyTypeCode")

    def GetArrayPointerStepping(self):
        return self._CollectCode("GetArrayPointerStepping")
    
    def GetInputCallArgument(self):
        assert(self.IsInputArgument())
        return self._CollectCode("GetInputCallArgument")

    def GetOutputCallArgument(self):
        assert(self.IsOutputArgument())
        return self._CollectCode("GetOutputCallArgument")

    def GetFunctionReturnCast(self):
        """
        Currently I see that only a single function cast makes sense
        """
        assert(self.IsReturnArgument())

        result =  self._CollectCode("GetFunctionReturnCast")
        l = len(result)
        assert(l == 1)
        return result

    def GetReturnCallArgument(self):
        assert(self.IsReturnArgument())

        result = self._CollectCode("GetReturnCallArgument")
        l = len(result)
        assert(l == 1)
        return result

    def GetPyVariableNames(self):
        return self._CollectCode("GetPyVariableNames")

    def GetInputTmpVariablesAssignment(self):
        assert(self.IsInputArgument())
        return self._CollectCode("GetInputTmpVariablesAssignment")

    def GetReturnTmpVariablesAssignment(self):
        assert(self.IsReturnArgument())
        return self._CollectCode("GetReturnTmpVariablesAssignment")

    def GetOutputTmpVariablesAssignment(self):
        assert(self.IsOutputArgument())
        return self._CollectCode("GetOutputTmpVariablesAssignment")

    def GetOutputVariablesSetOnError(self):
        return self._CollectCode("GetOutputVariablesSetOnError")

    def GetPyVariableNamesDecl(self):
        return self._CollectCode("GetPyVariableNamesDecl")

    def GetNumberInArgs(self):
        """returns how many input arguments are needed for the represented type
        """
        if not self.IsInputArgument():
            return 0
        
        l = len(self._sub_types)
        assert(l == 1)
        return 1

    def GetNumberReturnArgs(self):
        if not self.IsReturnArgument():
            return 0

        l = len(self._sub_types)
        assert(l == 1)
        return 1
        
    def GetNumberOutArgs(self):
        """returns how many output  arguments are needed for the represented type
        """
        if not self.IsOutputArgument():
            return 0

        if self._gsl_sub_types != None:
            assert(len(self._gsl_sub_types) == 1)
            s = self._gsl_sub_types[0]
            return s.GetNumberOutArgs()

        l = len(self._sub_types)
        assert(l == 1)        
        return 1

    def PrepareForEmittingCode(self):
        """Tell everthing to get ready to emit code

        or to put it differently .. the variable has been set up
        """
        # Inform subtypes on code type
        
        if self._sub_types is None:
            assert(self._gsl_sub_types is not None)
            sub_types = self._gsl_sub_types
        else:
            sub_types = self._sub_types

        if self.IsInputArgument():
            for t in sub_types:
                t.SetInputArgument()
                
        if self.IsOutputArgument():
            for t in sub_types:
                t.SetOutputArgument()
                
        if self.IsReturnArgument():
            for t in sub_types:
                t.SetReturnArgument()

        name = self.GetName()
        for t in sub_types:
            t.SetName(name)
            
        self._is_prepared_for_emitting_code = True

    def GetTypeLetter(self, minor=None):
    
        if self._gsl_sub_types is None:
            types =  self._sub_types 
        else:
            types =  self._gsl_sub_types 
    
        assert(len(types) == 1)
        obj = types[0]
        if minor:
            obj = self.GetMinor()
        return obj.GetTypeLetter()

    def __str__(self):
        op = self._operator
        t_type = self._type
        name = self._name
        
        if op is None:
            rep = "%s %s" %(t_type, name)
        else:
            rep = "%s %s %s" %(t_type, op, name)
        return rep
        
    def __repr__(self):
        fmt = "%s:%s variable: %s; type: %s; op: %s;"
        args = (__file__, self.__class__.__name__,self._name, self._type, self._operator)
        return fmt % args

    def GetArgumentTypes(self):
        r1 = self._type_dic.keys()
        r1 = tuple(r1)
        r2 = self._gsl_type_dic.keys()
        r2 = tuple(r2)

        result = r1 + r2
        return result

class Argument(_Argument):
    """Arguments for GSL math/complex special functions
    
    letter nomenclatura
        *  f   : float
        *  d   : double
        *  c   : gsl_complex
        *  r*  : gsl_sf_result
        *  er* : gsl_sf_result_e10
        *  i   : integer
        *  m   : gsl_mode_t
        *  ui  : unsigned int
        *  l   : long
        *  p   : use return value as normal return to user(parameter)
        *  q   : use return as error flag to print warning or raise error
                   ("quality" :-)
    """
    #: Can be translated directly to numpy types
    _type_dic = {
        "int":          ufunc_arg.LongArgumentAsMajor,        
        "unsigned int": ufunc_arg.UnsignedIntArgument,
        "size_t":       ufunc_arg.SizeTArgument,
        "double":       ufunc_arg.DoubleArgument,
        "gsl_complex":  ufunc_arg.GSLComplexArgument,
        "gsl_mode_t":   ufunc_arg.GSLModeTArgument,
        }

    #: Combined types
    _gsl_type_dic = {
        "gsl_sf_result":     GSLSfResult,
        "gsl_sf_result_e10": GSLSfResultE,
        }

