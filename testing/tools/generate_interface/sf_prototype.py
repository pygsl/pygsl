import copy

def get_py_ufunc_name(sf_prototype, minor = False):
    """Derive a semi standard name from the function signature
    """
    in_args = sf_prototype.GetInArguments()
    out_args = sf_prototype.GetOutArguments()
    #print("out_args:", out_args)
    ret_arg = sf_prototype.GetReturnArgument()

    def join_letters(iter):
        t_minor = False
        tmp = map(lambda x: x.GetTypeLetter(t_minor), iter)
        letters = "_".join(tmp)
        return letters
    
    in_letters = join_letters(in_args)
    out_letters = join_letters(out_args)

    
    assert(in_letters is not None)
    assert(out_letters is not None)
    
    return_letter = ret_arg.GetTypeLetter(False)
    name = "PyGSL_sf_ufunc_I%s__R%s__O%s" %(in_letters, return_letter, out_letters)

    if minor:
        name += "_as_minor"
    return name

class sf_prototype(object):
    """contains all necessary informations about the prototype
    and can contain code for it

    The prototype only needs to provide these arguments.

    The arguments must provide the ufunc_arg._UFuncArgument
    """
    __slots__ = ("_in_args", "_out_args", "_return_arg", "_parameters") 

    def GetFunctionPointerDeclaration(self):
        code = []
        for par in self.GetInArguments():            
            code.append(par.GetGSLType())

        for par in self.GetOutArguments():
            code.append("%s *" %(par.GetGSLType(),))
            
        call_types = ", ".join(code)
        ret_arg = self.GetReturnArgument()
        ret_type = par.GetGSLType()

        ret_arg_c = ret_arg.GetGSLType()
        code = "%s (*)(%s)" %(ret_arg_c, call_types)
        return code
    
    def GetInArguments(self):
        return self._in_args

    def GetOutArguments(self):
        return self._out_args

    def GetReturnArgument(self):
        return self._return_arg

    def GetParameters(self):
        return self._parameters

class sf_prototype_build(sf_prototype):
    """Collects the information of the prototype
    """

    __slots__ = ("_return_value", "_name",  "_use_return_value", "_all_parameters_handled", "_comment")
    def __init__(self, comment = None, name = None, ret = None, params = None, use_return_value = 0):

        self._comment = None
        
        # save return value
        self._return_value = ret

        # save function name
        self._name= name

        # split and save parameters
        self._parameters = params

        self._use_return_value = use_return_value

        self._in_args = None
        self._out_args = None
        self._return_arg = None
        self._all_parameters_handled = False

        self._AllParametersHandled()

    def _AllParametersHandled(self):
        """
        """

        assert(self._all_parameters_handled == False)

        # Check that the relevant methods are available
        for par in self._parameters:
            #assert(callable(par.GetTypeLetter))
            pass
        
        assert(self._in_args is None)
        assert(self._out_args is None)
        assert(self._return_arg is None)

        self._in_args = []
        self._out_args = []

        cnt = 0

        parameters = list(copy.copy(self._parameters))
        verbose = False
        if verbose:
            print("Parameters", parameters)
        
        left_overs = []
        while 1:
            try:
                arg = parameters.pop(0)
            except IndexError:
                break
            
            #print("par -->%s: %s input: %s<--" %(arg.__class__.__name__, repr(arg), arg.IsInputArgument()) )
            if not arg.IsInputArgument():
                left_overs.append(arg)
                continue
            
            self._in_args.append(arg)
            tmp = arg.GetNumberInArgs()
            arg.SetPyUFuncPosNumber(cnt)
            arg.SetInputArgument()
            cnt += tmp


        # out args: cnt 0 -> return value
        self._return_arg = self._return_value
        self._return_arg.SetPyUFuncPosNumber(cnt)
        self._return_arg.SetReturnArgument()
        cntinc = self._return_arg.GetNumberReturnArgs()
        assert(cntinc >= 1)
        cnt += cntinc

        check = []
        while 1:
            try:
                arg = left_overs.pop()
            except IndexError:
                break
            
            #print("par -->%s: %s input: %s output: %s<--" %(arg.__class__.__name__, repr(arg), arg.IsInputArgument(), arg.IsOutputArgument()) )            
            if not arg.IsOutputArgument():
                check.append(arg)
                continue

            self._out_args.append(arg)
                
            arg.SetPyUFuncPosNumber(cnt)
            arg.SetOutputArgument()
            tmp = arg.GetNumberOutArgs()    
            cnt += tmp

        assert(len(check) == 0)
        self._CheckArgumentsConsistency()
        self._all_parameters_handled = True

    def _CheckArgumentsConsistency(self):
        """Go over all parameters and see that their properties are unique 
        """

        args = self._in_args + [self._return_arg, ] + self._out_args

        # Check that all parameters are handled
        for arg in self._parameters:
            if arg not in args:
                msg = "arg '%s' not found in in_args, return arg or out_args"
                raise ValueError(msg % (arg,) )
        
        # Check that the numpy call position is unique

        check = []
        check2 = []
        
        in_args = self._in_args
        in_args = self.GetInArguments()
        
        for arg in in_args:
            assert(arg.IsInputArgument())
            num = arg.GetPyUFuncPosNumber()
            if num is None:
                msg = "python positional argument number not defined for arg %s. func: %s"
                raise ValueError(msg % (repr(arg), str(self)))
            
            assert(num is not None)
            tmp = arg.GetNumberInArgs()            
            assert(tmp is not None)
            assert(tmp > 0)
            
            test = range(num, num + tmp)
            test = list(test)
            check2 = check2 + test
            for t in test:
                if t in check:
                    msg = "in arg '%s' uses an already attributed python positional argument number %d"
                    raise ValueError(msg % (arg, t) )

            check = check + test

        arg = self._return_arg
        arg = self.GetReturnArgument()
        assert(arg.IsReturnArgument())
        num = arg.GetPyUFuncPosNumber()
        assert(num is not None)
        
        tmp = arg.GetNumberReturnArgs()
        assert(tmp is not None)
        assert(tmp == 1)
        if num in check:
            msg = "return arg '%s' uses the  already attributed python positional argument number %d"
            raise ValueError(msg % (arg, num) )
        check = check + [num]
        check2 = check2 + [num]

        out_args = self._out_args
        out_args = self.GetOutArguments()

        for arg in out_args:
            assert(arg.IsOutputArgument())
            num = arg.GetPyUFuncPosNumber()            
            assert(num is not None)
            tmp = arg.GetNumberOutArgs()
            assert(tmp is not None)
            assert(tmp > 0)
            
            test = range(num, num + tmp)
            test = list(test)
            check2 = check2 + test
            for t in test:
                if t in check:
                    msg = "out arg '%s' uses an already attributed python positional argument number %d"
                    raise ValueError(msg % (arg, t) )

            check = check + test

        # Test the code
        l = len(check2)
        t_set= set(check2)
        if len(t_set) != len(check2):
            raise ValueError("check2 '%s' seems to have doubled entries" %(check2,))
        
    def GetFunctionDeclaration(self):
        code = []
        ret_arg = None
        assert(len(self._parameters) > 0)
        for par in self._parameters:
            if par.IsReturnArgument():
                ret_arg = par
                continue
            
            op = par.GetOperator()
            if op == "p":
                fmt = "%s* %s"
                code.append(fmt %(par.GetGSLType(), par.GetName()) )
            else:
                if op == "q(const)":
                    op = "const"

                fmt = "%s %s %s"
                code.append(fmt %(op, par.GetGSLType(), par.GetName()) )

        #assert(ret_arg is not None)
        if ret_arg is None:
            ret_arg = self._return_arg
        ret_arg_c = ret_arg.GetGSLType()
        name = self._name
        call_types = ", ".join(code)
        result = "%s %s(%s)" %(ret_arg_c, name, call_types)
        return result

    def GetUFuncNInArgs(self):
        assert(self._all_parameters_handled == True)
        n = 0
        for arg in self._in_args:
            tmp = arg.GetNumberInArgs()
            n += tmp
        return n

    def GetUFuncNOutArgs(self):
        assert(self._all_parameters_handled == True)
        n = 0
        arg = self._return_arg
        tmp = arg.GetNumberReturnArgs()
        n += tmp
        for arg in self._out_args:
            tmp = arg.GetNumberOutArgs()
            n += tmp
        return n
                    
    def GetFunctionName(self):
        return self._name

    def GetPyFunctionName(self):
        "The name to be used when the object is exported to python "
        name = self.GetFunctionName()
        if name[:4] == "gsl_":
            name = name[4:]
        return name

    def GetComment(self):
        return self._comment
    
    def __str__(self):
        #print("return argument", repr(self._return_args))
        py_ufunc_name =  get_py_ufunc_name(self)
        t_str = "%s: %s" %(self.__class__.__name__, py_ufunc_name)
        t_str += " %s = %s (" % (self._return_arg
                                , self._name)

        io_type = "I."
        for cnt in range(len(self._parameters)):
            if cnt > 0:
                t_str += ", "
            par = self._parameters[cnt]            
            if par.IsOutputArgument():
                io_type = "O."
            t_str += "%s%s" % (io_type, par)
        t_str += ")"
        return t_str

