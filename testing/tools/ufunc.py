"""
Classes to represent UFuncs and their Arguments

"""
import sys
import types
import pprint
import string
from cStringIO import StringIO

class Argument:
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

    def GetNumberInArgs(self):
        """
        returns how many input arguments are needed for the represented type
        """
        return 1
    
    def GetNumberOutArgs(self):
        """
        returns how many output  arguments are needed for the represented type
        """
        if self._type == "gsl_sf_result_e10":
            return 3
        if self._type == "gsl_sf_result":
            return 2
        return 1

    def IsComlex(self):
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
    
    def GetTypeLetter(self, minor):
        if self._type == "double":
            if minor == 1:
                return "f"
            return "d"

        if self._type == "gsl_complex":
            #if minor == 1:
            #    return "F"
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

        raise ValueError, "Not Type defined"
        
    def GetArrayType(self, argumentnumber, minor):
        """
        Get the type for the approbriate argument number.
        """
        if self._type == "double":
            if minor == 1:
                return "PyArray_FLOAT"
            return "PyArray_DOUBLE"

        if self._type == "float":
            return "PyArray_FLOAT"

        if self._type == "gsl_mode_t":
            return "PyArray_INT"

        if self._type == "unsigned int":
            return "PyArray_UINT"

        if self._type == "int":
            return "PyArray_INT"

        if self._type == "gsl_complex":
            #if minor == 1:
            #    return "PyArray_CFLOAT"
            return "PyArray_CDOUBLE"
        
        if self._type == "gsl_sf_result":
            if minor == 1:
                return "PyArray_FLOAT"
            return "PyArray_DOUBLE"
        
        if self._type == "gsl_sf_result_e10":
            if argumentnumber == 2:
                return "PyArray_INT"
            if minor == 1:
                return "PyArray_FLOAT"
            return "PyArray_DOUBLE"
        raise ValueError, "Unknown type -->%s<-- for variable -->%s<-- " % (self._type, self._name)
        
        
    def __repr__(self):
        return "variable : %s\n   type : %s\n    op : %s\n" %(self._name, self._type, self._operator)

def indent_lists(lists, indent):
    """
    treat the list as text and intend int according to the text indent. The
    user has to take care that indent is really empty text.
    """
    o = []
    myindent = ""
    for l in lists:
        for item in l:
            o.append(myindent + item)
            if myindent != "":
                myindent = ""
        myindent = "\n" + indent    
    return string.join(o, ", ")    
        
class PyUFunc:
    """
    Collects the all the information for one function to wrap and returns the
    approbriate wrapper code if requested.
    """
    def __init__(self):
        self.a_function_data = []
        self.a_function_types = []
        self.in_args = []
        self.out_args = []
        self.return_arg = None
        self.return_is_error_flag = 0
        self.name = self.__class__.__name__
        self.evaluator_mode = 0
        
    def SetName(self, name):
        """
        The name of the function
        """
        self.name = name

    def AddInParams(self, name, type, operator):
        """
        add an argument to the function of type Argument

        Note that the first argument has to be registered as the first one,
        the second as the second one
        """
        arg = Argument()
        arg.SetName(name)
        arg.SetOperator(operator)
        arg.SetType(type)
        self.in_args.append(arg)


    def ReturnParam(self, name, type, operator):
        """
        The return argument of the function
        """
        arg = Argument()
        arg.SetName(name)
        arg.SetOperator(operator)
        arg.SetType(type)

        self.return_arg = arg


    def AddOutParams(self, name, type, operator):
        """
        add an argument to the function of type Argument

        Note that the first argument has to be registered as the first one ...
        """

        arg = Argument()
        arg.SetName(name)
        arg.SetOperator(operator)
        arg.SetType(type)

        self.out_args.append(arg)

    def ReturnIsErrorFlag(self, flag):
        """
        Is the return value a error flag or a full argument?

        Typically functions named_e return errors
        """
        self.return_is_error_flag = flag


    def _GetFuncNameFromLetters(self):
        """
        Generate the name of the evaluator from the function names.
        """
        letters = ""
        minorletters = ""
        return_letter = self.return_arg.GetTypeLetter(0)
        minor_return_letter = self.return_arg.GetTypeLetter(1)
        for i in self.in_args:
            letters += i.GetTypeLetter(0)
            minorletters += i.GetTypeLetter(1)
        letters += '_'
        minorletters += '_'    
        for i in self.out_args:
            letters += i.GetTypeLetter(0)
            minorletters += i.GetTypeLetter(1)

        # letter nomenclatura
        # f   ... float
        # d   ... double
        # r*  ... gsl_sf_result
        # er* ... gsl_sf_result_e10
        # i   ... integer
        # m   ... gsl_mode_t
        # ui  ... unsigned int
        # l   ... long
        # p   ... use return value as normal return to user(parameter)
        # q   ... use return as error flag to print warning or raise error
        #         ("quality" :-)
        # use return as normal value to return to the user    
        returntype = 'p'
        if self.return_is_error_flag:
            returntype = 'q'
        returntype +=   return_letter  
        return letters, minorletters, returntype
    
    def GetPyUFuncEvaluatorOne(self):
        """
        Return one common unique name for the different UFUncs.
        """
        letters, minorletters, returntype = self._GetFuncNameFromLetters()
        return "PyGSL_sf_ufunc_%s_%s_one" % (returntype, letters)
        
    def GetPyUFuncEvaluatorNames(self):
        """
        Return the names of the Required UFunc evaluators.
        """
        letters, minorletters, returntype = self._GetFuncNameFromLetters()
        return (("PyGSL_sf_ufunc_%s_%s_as_%s" % (returntype, minorletters, letters,)) ,
                ("PyGSL_sf_ufunc_%s_%s" % (returntype, letters)))
        
    def WriteUFuncObjectHelpersArrayData(self):
        """
        Set the function pointers for the approbriate evaluators!
        """
        c = StringIO()
        save = sys.stdout
        sys.stdout = c
        typecast = "PyUFuncGenericFunction"
        try:
            name = self.GetPyUFuncEvaluatorOne() + '_data'
            tmp  = self.GetPyUFuncEvaluatorNames()
            
            print "%s[0] = (%s) %s;" % (name, typecast, tmp[0])
            print "%s[1] = (%s) %s;" % (name, typecast, tmp[1])
            c.seek(0)
            return c.read()
        finally:
            sys.stdout = save

    def __WriteExtraInfo(self, argument, argnumber, c_argnumber, additional = ""):
        """
        Generate description for __doc__ string  for special arguments
        """
        extrainfo = ""
        i = argument
        if i.IsGSLMode():
            tmp = ('"%s Argument %d is a gsl_mode_t, valid parameters are:' +
                   '\\n\tsf.PREC_DOUBLE or sf.PREC_SINGLE or sf.PREC_APPROX\\n"\n')
            extrainfo += tmp % (additional, argnumber)
        if i.IsResult():
            tmp =  ('"%s Arguments %d and %d resemble a gsl_result argument,\\n'+
                    '\\twhich is  argument %d of the C argument list\\n"\n')
            extrainfo += tmp % (additional, argnumber - 1, argnumber, c_argnumber + 1)
        if i.IsResulte10():
            tmp = ('"%s Arguments %d - %d resemble a gsl_result_e10 argument,\\n'+
                   '\\twhich is argument %d of the C argument list\\n"\n')
            extrainfo += tmp % (additional, argnumber - 2, argnumber, c_argnumber + 1)
        return extrainfo

    
    def WriteUFuncLatexDoc(self):
        """
        Write information for the pygsl reference document.
        """
        inargs = 0
        outargs = 0
        extrainfo = ""
        intypes = ""
        outtypes = ""
        for n in range(len(self.in_args)):
            i = self.in_args[n]
            inargs += i.GetNumberInArgs()
            intypes += i.GetTypeLetter(0)
            extrainfo += self.__WriteExtraInfo(i, inargs, n)
        if not self.return_is_error_flag:
            outargs += 1
            outtypes += i.GetTypeLetter(0)
        else:
            extrainfo += '"The error flag is discarded.\\n"\n'
        for n in range(len(self.out_args)):
            i = self.out_args[n]
            outargs += i.GetNumberOutArgs()
            outtypes += i.GetTypeLetter(0)
            extrainfo += self.__WriteExtraInfo(i, outargs, len(self.in_args) + n, "Return")

        if extrainfo:
            extrainfo = '"\n"\\n\\n"\n' + extrainfo + '"'

        name = self.GetPyUFuncEvaluatorOne() + "_doc"

        ret ="""
\begin{funcdesc}{%s}{%s}
"    returns %2d variables :  %s %s\\n";
\end{funcdesc}        
"""  % (name, intypes, outargs, outtypes, extrainfo)
        return ret

    def WriteUFuncObjectDoc(self):
        """
        Generate __doc__ string for the ufunc object.
        """
        inargs = 0
        outargs = 0
        extrainfo = ""
        intypes = ""
        outtypes = ""
        for n in range(len(self.in_args)):
            i = self.in_args[n]
            inargs += i.GetNumberInArgs()
            intypes += i.GetTypeLetter(0)
            extrainfo += self.__WriteExtraInfo(i, inargs, n)
        if not self.return_is_error_flag:
            outargs += 1
            outtypes += i.GetTypeLetter(0)
        else:
            extrainfo += '"The error flag is discarded.\\n"\n'
        for n in range(len(self.out_args)):
            i = self.out_args[n]
            outargs += i.GetNumberOutArgs()
            outtypes += i.GetTypeLetter(0)
            extrainfo += self.__WriteExtraInfo(i, outargs, len(self.in_args) + n, "Return")

        if extrainfo:
            extrainfo = '"\n"\\n\\n"\n' + extrainfo + '"'

        name = self.GetPyUFuncEvaluatorOne() + "_doc"

        ret ="""
static  char * %s =
"\\n"
"    %2d input  args :  %s\\n"
"    %2d output args :  %s %s\\n";
"""  % (name, inargs, intypes, outargs, outtypes, extrainfo)
        return ret
        
    def WriteUFuncObjectHelpers(self):
        """
        Generate the static information required to set up a UFunc.

        This is:
               -- space for registering/writting the  approbriate callbacks
               -- the doc strings.
        """
        c = StringIO()
        save = sys.stdout
        sys.stdout = c
        try:
            name = self.GetPyUFuncEvaluatorOne()
            print "static PyUFuncGenericFunction %s_data[] = {NULL, NULL};" % name
            print ""

            print self.WriteUFuncObjectDoc()
            print ""
            
            tmp = "static char %s_types [] = {" % name
            indent = ' ' * (len(tmp))
            print tmp,
            # float == 1, double = 0
            types = []
            test = 0
            try:
                for mode in (1, 0):
                    t = []
                    for i in self.in_args:
                        for j in range(i.GetNumberInArgs()):
                            t.append(i.GetArrayType(j, mode))
                    if not self.return_is_error_flag:
                        t.append(self.return_arg.GetArrayType(0, mode))
                    for i in self.out_args:
                        for j in range(i.GetNumberOutArgs()):
                            t.append(i.GetArrayType(j, mode))
                    types.append(t)
                test = 1                                    
            finally:
                if test == 0:
                    print "->>I was working on :", self.GetName()
            print indent_lists(types, indent),
            print "};"
            c.seek(0)
            return c.read()
        finally:
            sys.stdout = save

    def WriteUFuncObject(self):
        """
        Generates the code setting up the UFunc Object.

        This basically the following code:
          f = PyUFunc_FromFuncAndData(special_test_functions,
                                      a_function_data, 
                                      a_function_types, 
                                      ntypes, /* number of supported types*/ 
                                      nin, /* number of input arguments */
                                      nout, /* number of output arguments */
                                      PyUFunc_None, # Constant for all
                                      a_function_name, 
                                      a_function_doc, 
                                      0 /*check return ?*/ # Constant for all
                                      );
        
        """
        test = 0
        c = StringIO()
        save = sys.stdout
        sys.stdout = c
        try:
            evaluator_name = self.GetPyUFuncEvaluatorOne()
            pythonname = self.GetPythonName()
            docname = evaluator_name + "_doc"
            tmp = "f = PyUFunc_FromFuncAndData("
            indent = " " * len(tmp)
            print tmp,  "%s_data" %evaluator_name, ","
            print indent, "%s_data," % pythonname
            print indent, "%s_types,"% evaluator_name
            print indent, "%d, /* number of supported types */"% 2 # Have to fix it to a check how many arguments really.....
            
            n = 0
            for i in self.in_args:
                n += i.GetNumberInArgs()                
            print indent, "%d, /* in args */" % n
            n = 0
            if not self.return_is_error_flag:
                n += 1
            for i in self.out_args:
                n += i.GetNumberOutArgs()                
            print indent, "%d, /* out args */" % n
            print indent, "PyUFunc_None,"
            print indent, '"%s",' % pythonname
            print indent, docname, ","
            print indent, "0 /*check return*/); "
            print 'PyDict_SetItemString(sf_dict, "%s", f);' % pythonname
            print '/* Py_DECREF(f) */;'
            c.seek(0)
            test = 1
            return c.read()
        finally:
            sys.stdout = save
            if test == 0:
                print "I was working on %s" % repr(self)
            
    def WriteStaticData(self):
        """
        write out the data containing the names of the functions to evaluate
        e.g:
            static void * a_function_data [] = {(void *) a_function_name_for_float,
                                                (void *) a_function_name_for_double};

        and the types of the different arguments
        e. g:
            static char a_function_types[] = {PyArray_FLOAT,   PyArray_UINT,  PyArray_FLOAT,  PyArray_FLOAT,
                                              PyArray_DOUBLE,  PyArray_UINT,  PyArray_DOUBLE, PyArray_DOUBLE};
        """
        c = StringIO()
        save = sys.stdout
        sys.stdout = c
        test = 0                    
        try:
            pythonname =  self.GetPythonName()
            name = self.GetName()
            print "static void * %s_data [] = {" % pythonname,
            data = []
            for i in range(2):            
                data.append(("(void *) %s" % name))
            print string.join(data, ", "),
            print "};"


            test = 1
            c.seek(0)
            return c.read()
        finally:
            sys.stdout = save
            if test == 0:
                print "I was working on %s" % repr(self)

    def GetTypeDef(self):
        """
        Get the typedef required for the different functions to evaluate.
        """
        t = []
        for i in self.in_args:
            t.append(i.GetBasisType())
        ret = self.return_arg.GetBasisType()
        for i in self.out_args:
            t.append(i.GetBasisType())
        name = self.GetPyUFuncEvaluatorOne()
        return "typedef %s %s(%s);" % (ret, name, string.join(t, ', '))
                    
    def __repr__(self):
        l = []
        l.append("/*")
        c = StringIO()
        c.write("in args\n")
        pprint.pprint(self.in_args, c)
        c.write("out args\n")
        pprint.pprint(self.out_args, c)
        c.seek(0)
        l.extend(c.readlines())
        l.append("*/")
        return string.join(l, '\n')

    def GetName(self):
        """
        Get the name of the function
        """
        return self.name

    def GetPythonName(self):
        """
        Get the Python name of the function.

        Strip the name gsl_ and gsl_sf if possible...
        """
        teststr_gsl = "gsl_"

        # I now need _sf so that I can sort out which function should go where
        #teststr_gsl_sf = "gsl_sf_"

        common = 0
        for teststr in (teststr_gsl,):
            # Make sure that one can skip the extra string. So only gsl_sf is abbrivated.
            l = len(teststr)
            if self.name[:l] == teststr:
                common = l
                continue
            else:
                break
        tmp = self.name[common:]
        assert(len(tmp) > 0)
        assert(type(tmp) == types.StringType)
        print "/*Using %s as pyton name*/" %(tmp,)
        return tmp
    
    def add_in_types(self):
        """
        
        """
        counter = 0
        for i in self.in_args:
            for j in range(i.GetNumberInArgs()):
                if counter > 0:
                    print ",",
                test = 0    
                try:
                    fake = i.GetFakeType(j, self.evaluator_mode)
                    if fake:
                        print "(%s)*((%s *)ip%d)" % (i.GetType(j, self.evaluator_mode), fake, counter),
                    else:
                        print "*((%s *)ip%d)" % (i.GetType(j,  self.evaluator_mode),counter),
                    test = 1
                finally:
                    if test == 0:
                        sys.stderr.write("self.funccast = %s\n" % self.funccast)
                counter += 1
        return counter        
        
    def function_call_with_flag(self):
        """
        """
        print "\t\t{"
        print "\t\tint flag;"
        counter = 0

        # need temporary variables
        for i in self.out_args:
            if i.IsResult():
                print "\t\tgsl_sf_result r%d;" % counter
            elif i.IsResulte10():
                print "\t\tgsl_sf_result_e10 r%d;" % counter
            elif i.GetFakeType(0, self.evaluator_mode):
                print "\t\t%s tmp%d;" % (i.GetType(0, self.evaluator_mode), counter)                
            counter += 1;
            
        print "\t\tflag = ((%s *) func)(" % (self.funccast),

        # function call
        if self.add_in_types():
            print ",",

        # Add out arguments    
        counter = 0
        out_counter = 0
        for i in self.out_args:
            if counter > 0 or out_counter >0:
                print ",",
            test = 0    
            try:
                if i.IsResult():
                    print "&r%d" % counter,
                    counter += 1
                elif i.IsResulte10():
                    print "&r%d" % counter,
                    counter += 1
                elif i.GetFakeType(0, self.evaluator_mode):
                    print "&tmp%d" % counter,
                    counter += 1
                else:    
                    print "(%s *)op%d" % (i.GetType(0,  self.evaluator_mode), out_counter),
                test = 1
            finally:
                if test == 0:
                    sys.stderr.write("self.funccast = %s\n" % self.funccast)
            out_counter += 1
        print ");"
        print "\t\tif (flag != GSL_SUCCESS){"
        out_counter = 0;
        for i in self.out_args:
            for j in range(i.GetNumberOutArgs()):
                print "\t\t\t*(%s *) op%d = (%s) gsl_nan();" %(i.GetType(self.evaluator_mode, j), out_counter,
                                                            i.GetType(self.evaluator_mode, j))
                out_counter += 1
        print "\t\t}else{"
        # readout
        counter = 0
        out_counter = 0
        for i in self.out_args:
            test = 0    
            try:
                if i.IsResult() or i.IsResulte10():
                    if i.GetFakeType(0, self.evaluator_mode):
                        print "\t\t\t*(%s *) op%d = (%s) r%d.val;" % (i.GetType(self.evaluator_mode, 0), out_counter,
                                                                      i.GetType(self.evaluator_mode, 0),  counter)
                        print "\t\t\t*(%s *) op%d = (%s) r%d.err;" % (i.GetType(self.evaluator_mode, 1), out_counter+1,
                                                                      i.GetType(self.evaluator_mode, 1),  counter)
                    else:
                        print "\t\t\t*(%s *) op%d = r%d.val;" % (i.GetType(self.evaluator_mode, 0), out_counter, counter)
                        print "\t\t\t*(%s *) op%d = r%d.err;" % (i.GetType(self.evaluator_mode, 1), out_counter+1, counter)
                    counter += 1
                    out_counter +=1
                    if i.IsResulte10():
                        out_counter +=1
                        print "\t\t\t*(int *) op%d = r%d.e10;" % (out_counter, counter-1)
                elif i.GetFakeType(0, self.evaluator_mode):
                    print "\t\t\t/* casting fake out_counter = %d, counter = %d */" % (out_counter, counter)
                    print "\t\t\t*(%s *) op%d = (%s) tmp%d;" %(i.GetFakeType(0, self.evaluator_mode), out_counter,
                                                             i.GetFakeType(0, self.evaluator_mode), counter)
                    counter += 1
                    #out_counter += 1

                test = 1
                
            finally:
                if test == 0:
                    sys.stderr.write("self.funccast = %s\n" % self.funccast)
            out_counter += 1        
        print "\t\t}"
        print "\t\t}"


    def function_call_without_flag(self):
        """
        """
        mytype = self.return_arg.GetType(0, 0)
        fake = self.return_arg.GetFakeType(0, self.evaluator_mode)
        if fake:
            print "\t\t*(%s *)op0 = (%s)((%s *) func)(" %  (fake, fake, self.funccast),
        else:
            print "\t\t*(%s *)op0 = ((%s *) func)(" % (mytype, self.funccast),
        self.add_in_types()
        print ");"

        
    def GetEvaluator(self):    
        self.evaluator_mode = 0
        self.funccast =  self.GetPyUFuncEvaluatorOne()
        stream = StringIO()
        save = sys.stdout
        sys.stdout = stream
        try:
            self.evaluator_mode = 0 # minor, i.e. casting double to float
            self._WriteEvaluator()
            self.evaluator_mode = 1
            self._WriteEvaluator()
            stream.seek(0)            
            return stream.read()        
        finally:
            sys.stdout = save
            
    def _WriteEvaluator(self):
        counter = 0
        in_counter = 0
        out_counter = 0

        if  self.evaluator_mode == 0:
            index = 1
        else:
            index = 0
        name =  self.GetPyUFuncEvaluatorNames()[index]
        print "void %s (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func){" % name
        #print "void %s (char **args, int *dimensions, int *steps, void *func){" % name
        print "\tPyGSL_array_index_t i, ",
        for i in self.in_args:
            for j in range(i.GetNumberInArgs()):
                if counter > 0:
                    print ",",
                print "is%d=steps[%d]" % (in_counter,counter),
                counter += 1
                in_counter +=1

        if self.return_is_error_flag:
            self.wrapped_out_args = self.out_args
        else:
            self.wrapped_out_args = [self.return_arg] + self.out_args
        for i in self.wrapped_out_args:
            for j in range(i.GetNumberOutArgs()):
                if counter > 0:
                    print ",",
                print "os%d=steps[%d]" % (out_counter,counter),
                counter += 1
                out_counter +=1
        print ";"        

        counter = 0
        in_counter = 0
        out_counter = 0

        print "\tchar  ",
        for i in self.in_args:
            for j in range(i.GetNumberInArgs()):
                if counter > 0:
                    print ",",
                print "*ip%d=args[%d]" % (in_counter,counter),
                counter += 1
                in_counter +=1

        for i in self.wrapped_out_args:
            for j in range(i.GetNumberOutArgs()):
                if counter > 0:
                    print ",",
                print "*op%d=args[%d]" % (out_counter,counter),
                counter += 1
                out_counter +=1
        print ";"

        #print '\tfprintf(stderr, "In function %s line %d is0 = %d, is1 = %d, os0 = %d\\n", '
        #print '\t\t__FUNCTION__, __LINE__, is0, is1, os0);'

        print "\tfor(i = 0; i<dimensions[0]; i++", 
        

        counter = 0
        in_counter = 0
        out_counter = 0

        for i in self.in_args:
            for j in range(i.GetNumberInArgs()):
                print ",ip%d+=is%d" % (in_counter,in_counter),
                counter += 1
                in_counter +=1

        for i in self.wrapped_out_args:
            for j in range(i.GetNumberOutArgs()):
                print ",op%d+=os%d" % (out_counter,out_counter),
                counter += 1
                out_counter +=1

        print "){"
        print '\t\tDEBUG_MESS(2, "Evaluating element %ld", (long)i);'
        #print "x = (float*)ip1;"
        #print "mode = (int *) ip2;"
        funccast =  self.funccast
        use_error_flag = 0
        if self.return_is_error_flag:
            use_error_flag = 1
            self.function_call_with_flag()
        else:
            test = 0
            if len(self.out_args) != 0:
                sys.stderr.write("Not wrapping %s!\n" % funccast)
            else:
                self.function_call_without_flag()
        print "\t}"        
            # uses gsl_sf_result or gsl_sf_result_e10_
        #print "flag = ((PyGSL_DOUBLE_FUNC_di_dd *)func)((double)*x, (gsl_mode_t) *mode, &result);"

        # Use some heuristics to guess the out type.

        #if (flag == GSL_SUCCESS){
        #    *(float *)op1 = (float)result.val;
        #    *(float *)op2 = (float)result.err;
        #    } else {             
        #    *(float *)op1 = (float)gsl_nan();
        #    *(float *)op2 = (float)gsl_nan();
        #    invoke_error_handler(__FILE__, __FUNCTION__, i, flag);
        #    }
        #}

        print "}"
