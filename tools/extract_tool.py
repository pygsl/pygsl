import re
import string
import os.path

class constant_collector:
    """
    collect constants from headers
    """
    def __init__(self,prefix=None):
        self.prefix=prefix

    def get_all_constants(self):
        constants=[]
        for file_name in ["gsl_const_cgs.h","gsl_const_mks.h","gsl_const_num.h","gsl_math.h"]:
            constants.extend(self.get_constants_from_file(file_name))
        return constants

    def get_constants_from_file(self,include_file):
        #prepare file names
        const_include_file_name=os.path.join(self.prefix,"include","gsl",include_file)
        if not os.path.isfile(const_include_file_name):
            raise Exception,"could not find const header file %s"%const_include_file_name

        const_include_file=file(const_include_file_name, "r")
        constants=[]
        constants_pattern=re.compile("#\s*define\s+\w+\s+\S+")
        line=const_include_file.readline()
        while line!="":
            if constants_pattern.match(line):
                try:
                    constants.append(gsl_constant(line))
                except Exception,message:
                    print message
            line=const_include_file.readline()

        const_include_file.close()
        return constants

class gsl_constant:
    """
    keeps constant name and value
    """
    def __init__(self, line):
        constants_pattern=re.compile("#\s*define\s+(?P<name>\w+)\s+(?P<definition>.+?)(?:$|/\*\s*(?P<comment>.*?)\s*\*/)")
        constants_match=constants_pattern.match(line)
        if constants_match:
            self.name=constants_match.group('name')
            self.definition=constants_match.group('definition')
            self.comment=constants_match.group('comment')
        else:
            raise Exception,"could not parse %s"%line

    def make_cpp_definition(self):
        if self.comment:
            return "#define %s %s /* %s */"%(self.name,self.definition,self.comment)
        else:
            return "#define %s %s"%(self.name,self.definition)

    def make_module_definition(self):
        new_name=""
        if self.name[:2]=="M_":
            new_name='_'.join(map(string.lower,self.name.split('_')[1:]))
        elif self.name[:10]=="GSL_CONST_":
            new_name='_'.join(map(string.lower,self.name.split('_')[3:]))
        else:
            return None
        return "PyModule_AddObject(m,\"%s\",PyFloat_FromDouble(%s))"%(new_name,self.name)
        
    def make_array_entry(self):
        """
        string of type {"achims_constant",ACHIM_ACHIMS_CONSTANT,"achims bug density"}
        """
        new_name=""
        if self.name[:2]=="M_":
            new_name='_'.join(map(string.lower,self.name.split('_')[1:]))
        elif self.name[:10]=="GSL_CONST_":
            new_name='_'.join(map(string.lower,self.name.split('_')[3:]))
        else:
            return None
        return "{\"%s\",%s,\"%s\"}"%(new_name,self.name,self.comment.strip())

class prototype_collector:
    """
    collects special function prototypes from headers
    """

    def __init__(self,prefix=None):
        self.prefix=prefix

    def determine_headers(self,prefix=None):
        """
        determines the header files
        """

        #prepare file names
        general_include_dir_name=os.path.join(self.prefix,"include")
        general_include_file_name=os.path.join(general_include_dir_name,"gsl","gsl_sf.h")

        #test if exists
        if not os.path.isfile(general_include_file_name):
            raise Exception,"could not find general header file"

        #parse file for includes
        general_include_file=file(general_include_file_name,"r")
        sf_header_list=[]
        include_pattern=re.compile("#\s*include\s+[\"<](.+)[\">].*")
        a_line=general_include_file.readline()
        while a_line:
            # if line is matching
            include_match=include_pattern.match(a_line)
            if include_match:
                new_header_name=os.path.join(general_include_dir_name,include_match.group(1))
                if os.path.isfile(new_header_name):
                    sf_header_list.append(new_header_name)
                else:
                    print ("could not find header %s",new_header_name)
            
            a_line=general_include_file.readline()
        general_include_file.close()

        return sf_header_list

    def get_prototypes(self):
        """
        """
        file_name_list=self.determine_headers(self.prefix)
        all_prototypes=[]
        for file_name in file_name_list:
            new_prototypes=self.get_prototypes_from_file(file_name)
            all_prototypes.extend(new_prototypes)
        return all_prototypes

    def get_prototypes_from_file(self, include_file_name):
        """
        searches for prototypes from a given file and creates a list of prototype objects
        """

        # read file
        include_file=file(include_file_name,"r")
        contents=include_file.read()
        include_file.close()

        # skip begin and end
        decl_only_pattern=re.compile(".*__BEGIN_DECLS(.*)__END_DECLS.*",re.MULTILINE+re.DOTALL)
        decls_match=decl_only_pattern.match(contents,re.MULTILINE+re.DOTALL)
        contents=None # forget whole contents
        if not decls_match:
            return []

        # find declarations section
        declaration_contents=decls_match.group(1)
        # find declaration and preceeding comment
        function_pattern=re.compile("(?:/\*.*?\*/\s*)?\w+\s+\w+\s*\([^\)]*\)\s*;",
                                    re.MULTILINE+re.DOTALL)
        match_list=function_pattern.findall(declaration_contents,
                                            re.MULTILINE+re.DOTALL)
        #parse all declarations
        prototype_list=[]
        for match in match_list:
            prototype_list.append(sf_prototype(match))
        return prototype_list

    def make_wrapper_and_index_file(self,filename):

        exclude_list=["gsl_sf_bessel_jl_steed_array","gsl_sf_bessel_sequence_Jnu_e","gsl_sf_coulomb_wave_F_array"]
        prototypes=self.get_prototypes()
        function_file=file(filename+"_functions.c","w")
        index_file=file(filename+"_index.c","w")
        for p in  prototypes:
            if p.name in exclude_list:
                continue
            index_entry=p.make_function_entry()
            if index_entry is not None:
                try:
                    function_file.write(p.make_wrapper_function()+"\n")
                    index_file.write(index_entry+",\n")
                except RuntimeError, message:
                    print message
        function_file.close()
        index_file.close()

class sf_prototype:
    """
    contains all necessary informations about this prototype
    and can contain code for it
    """

    def __init__(self,characters):
        #parse all declarations
        declaration_pattern=re.compile("(?P<comment>/\*.*?\*/\s*)?\s*(?P<return_value>\w+\s+)(?P<name>\w+\s*)\((?P<parameters>[^\)]*)\)\s*;")
        declaration_match=declaration_pattern.search(characters)
        if declaration_match is None:
            raise Exception, "could not evaluate definition"

        # prepare comment for __doc__
        comment=declaration_match.group('comment')
        # todo
        self.comment=comment
        
        # save return value
        self.return_value=string.strip(declaration_match.group('return_value'))

        # save function name
        self.name=string.strip(declaration_match.group('name'))

        # split and save parameters
        func_parameters=string.strip(declaration_match.group('parameters'))
        self.parameters=re.split("\s*,\s*",func_parameters)

    def to_string(self):
        """
        prints this object
        """
        return self.original_declaration()

    def original_declaration(self):
        """
        representation as declaration without comment
        """
        outstring=self.return_value+" "+self.name+"("
        if self.parameters:
            for p in self.parameters[:-1]:
                outstring+=p+", "
            outstring+=self.parameters[-1]
        return outstring+");"

    def make_function_entry(self):
        """
        returns the entry for the function index {name, function_name, argument method}
        """
        matched_name_stem=re.match("gsl_sf_(.+?)_e$",self.name)
        if  matched_name_stem is None:
            return None
        name_stem=matched_name_stem.group(1)
        return "{\"%s\",%s_wrap,METH_VARARGS}"%(name_stem,self.name)
        

    def make_wrapper_function(self):
        """
        define function for gsl wrapper library
        """

        # is this function type supported?
        # guess by name
        if re.match("gsl_sf_.+?_e$",self.name) is None:
            raise RuntimeError,"%s: not the expected function naming scheme"%(self.name)

        # check parameters and build stub
        argument_type_pattern=re.compile("((?P<qualifier>const)\s+)?(?P<type>(unsigned\s+)?\w+)\s*(?P<operator>\*|&)?\s*(?P<name>\w+)")

        parameter_string=""         # the parameter list for gsl function
        arg_parse_type=""           # the argument pattern for PyArg_ParseTuple
        arg_parse_name=""           # the argument list for PyArg_ParseTuple 
        arg_decl=""                 # declaration section
        arg_control=""              # code parts for parameter check
        result_arg=""               # is the argument list of Py_BuildValue 
        result_format=""            # is the formatstring of Py_BuildValue
        for p in self.parameters:
            arg_match=argument_type_pattern.match(p)
            if arg_match is None:
                raise RuntimeError,"%s: can not interprete parameter %s"%(self.name, p)
            arg_type=arg_match.group('type')
            arg_name=arg_match.group('name')
            arg_qualifier=arg_match.group('qualifier')
            arg_operator=arg_match.group('operator')
            
            if arg_type=="int" and arg_operator is None:
                arg_decl+="int %s=0;\n"%arg_name
                arg_parse_type+="i"
                arg_parse_name+="&%s, "%arg_name
                parameter_string+="%s, "%arg_name
            elif arg_type=="unsigned int" and arg_operator is None:
                arg_decl+="unsigned int %s=0;\nlong %s_long=0;\n"%(arg_name,arg_name)
                arg_parse_type+="l"
                arg_parse_name+="&%s, "%arg_name
                parameter_string+="%s, "%arg_name
                arg_control+="""if (%s_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for %s");
  return NULL;
}
%s=(unsigned int)%s_long;
"""%(arg_name,arg_name,arg_name,arg_name)
            elif arg_type=="double" and arg_operator is None:
                arg_decl+="double %s=0.0;\n"%arg_name
                arg_parse_type+="d"
                arg_parse_name+="&%s, "%arg_name
                parameter_string+="%s, "%arg_name
            elif arg_type=="gsl_mode_t" and arg_operator is None:
                arg_decl+="gsl_mode_t %s=GSL_PREC_SINGLE;\nchar %s_char='s';\n"%(arg_name,arg_name)
                arg_parse_type+="c"
                arg_parse_name+="&%s_char, "%arg_name
                arg_control+="if (eval_gsl_mode_char(&%s,%s_char)) return NULL;\n"%(arg_name,arg_name)
                parameter_string+="%s, "%arg_name
            elif arg_operator is not None and arg_operator=="*" and arg_type=="gsl_sf_result":
                # a result parameter
                arg_decl+="gsl_sf_result %s;\n"%arg_name
                parameter_string+="&%s, "%arg_name
                result_arg+="%s.val, %s.err, "%(arg_name,arg_name)
                result_format+="(dd)"
            elif arg_operator is not None and arg_operator=="*" and arg_type=="gsl_sf_result_e10":
                # a result parameter
                arg_decl+="gsl_sf_result_e10 %s;\n"%arg_name
                parameter_string+="&%s, "%arg_name
                result_arg+="%s.val, %s.err, %s.e10, "%(arg_name,arg_name,arg_name)
                result_format+="(ddi)"
            elif arg_operator is not None and arg_operator=="*" and arg_type=="double":
                # a result parameter
                arg_decl+="double %s;\n"%arg_name
                parameter_string+="&%s, "%arg_name
                result_arg+="%s, "%arg_name
                result_format+="d"
            else:
                raise RuntimeError, "%s: unsupported parameter type %s"%(self.name,p)

        #strip comma from arg_parse_* and parameter_string
        parameter_string=string.strip(parameter_string)[:-1]
        result_arg=string.strip(result_arg)[:-1]
        arg_parse_name=string.strip(arg_parse_name)[:-1]

        if arg_parse_type=="":
            raise RuntimeError, "%s: expected parameters in argument list"%(self.name)
        if result_format=="":
            raise RuntimeError, "%s: expected result type in argument list"%(self.name)

        # more ...

        # check return value
        if not self.return_value=="int":
            raise RuntimeError, "%s: expected int as return value"%(self.name)

        func="/* wrapper for "+self.original_declaration()+" */\n"

        # make definition
        func+="static PyObject* %s_wrap(PyObject *self, PyObject *args) {\n"%self.name

        # declarations
        func+="PyObject* returned_object;\n"
        func+="int int_result;\n"
        func+=arg_decl+"\n"

        # get parameters from python argument list
        func+="""if (!PyArg_ParseTuple(args, \"%s\", %s)) {
  /* say a little bit more */
  return NULL;
}\n"""%(arg_parse_type,arg_parse_name)

        #control the arguments
        func+=arg_control

         # call function
        func+="int_result=%s(%s);\n"%(self.name, parameter_string)

        # clean up arguments

        # check for errors
        func+="""
if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
"""
        # build return value
        func+="returned_object=Py_BuildValue(\"%s\",%s);\n"%(result_format,result_arg)

        # return it
        func+="return returned_object;\n"

        #close function
        func+="}\n"
        return func

