import re
import string
import os.path
from ufunc import PyUFunc



class prototype_collector:
    """
    collects special function prototypes from headers
    """

    # Check if the name indicates a ufunc wrapping around a function using
    # doubles.
    fake_test = re.compile("as")
    def __init__(self,prefix=None):
        self.prefix=prefix
        self.exclude_list = []

    def set_exclude_list(self, list):
        self.exclude_list = list
        
    def determine_headers(self,prefix=None):
        """
        determines the header files
        """

        #prepare file names
        general_include_dir_name=self.prefix
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
            tmp = sf_prototype(match)
            if tmp.get_name() not in self.exclude_list:
                prototype_list.append(tmp)
        return prototype_list

    def make_wrapper_and_index_file(self,filename):

        prototypes=self.get_prototypes()
        index_file = file(filename+"_index.c","w")
        data_file = file(filename+"_data.c","w")
        objects_file = file(filename+"_objects.c","w")
        ufuncs_list =  file(filename+"_ufuncs.txt","w")
        evaluators = file(filename + "_evals.c", "w")
        ufunc_names_dic = {}
        for p in  prototypes[:]:
            if p.name in self.exclude_list:
                continue
            index_entry=p.make_function_entry()
            if index_entry is not None:
                try:
                    a_py_ufunc =  p.make_wrapper_function()
                    data_file.write(a_py_ufunc.WriteStaticData()+"\n")
                    #objects_file.write("{\n")
                    objects_file.write(a_py_ufunc.WriteUFuncObject()+"\n")
                    #objects_file.write("}\n")
                    index_file.write(index_entry+",\n")
                except RuntimeError, message:
                    print message
                ufunc_names = a_py_ufunc.GetPyUFuncEvaluatorNames()    
                for name in ufunc_names:
                    if not ufunc_names_dic.has_key(name):
                        ufunc_names_dic[name] = []
                    ufunc_names_dic[name].append(a_py_ufunc)                  


        index_file.close()
        names = ufunc_names_dic.keys()
        names.sort()
        for i in names:
            ufuncs_list.write(i + ": ");
            l = map(lambda x: x.GetName(), ufunc_names_dic[i])
            l.sort()
            ufuncs_list.write(string.join(l, ", "))
            ufuncs_list.write("\n")
            
        for methods in ((objects_file, lambda x: x.WriteUFuncObjectHelpersArrayData(),),
                        (data_file, lambda x: x.WriteUFuncObjectHelpers(),),                        
                        (evaluators, lambda x: x.GetTypeDef(), lambda x: x.GetEvaluator())):
            for i in names:
                fake = self.fake_test.search(i)
                obj = ufunc_names_dic[i][0]
                if not fake:        
                    #evaluators.write("\n/* obj name = ->%s<-, name = ->%s<- */\n" % (obj.GetName(), i))
                    for m in methods[1:]:
                        methods[0].write(m(obj) + "\n")
                        
        objects_file.close()
        evaluators.close()
        data_file.close()
        
class sf_prototype:
    """
    contains all necessary informations about this prototype
    and can contain code for it
    """

    def __init__(self,characters, use_return_value = 0):
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

        self.use_return_value = 0

    def get_name(self):
        return self.name
    
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

        # First test if this function uses a flag to return error.
        matched_name_stem=re.match("gsl_sf_(.+?_e)$",self.name)
        if matched_name_stem is None:
            matched_name_stem=re.match("gsl_sf_(.+?)$",self.name)
            self.use_return_value = 1
        if  matched_name_stem is None:
            return None
        name_stem=matched_name_stem.group(1)
        return "{\"%s\",%s_wrap,METH_VARARGS}"%(name_stem,self.name)
        

    def make_wrapper_function(self):
        """
        define function for gsl wrapper library
        """


        a_pyufunc = PyUFunc()
        a_pyufunc.ReturnIsErrorFlag(not self.use_return_value)
        a_pyufunc.SetName(self.name)
        
        argument_type_pattern=re.compile("((?P<qualifier>const)\s+)?(?P<type>(unsigned\s+)?\w+)\s*(?P<operator>\*|&)?\s*(?P<name>\w+)")

        parameter_string=""         # the parameter list for gsl function
        arg_parse_type=""           # the argument pattern for PyArg_ParseTuple
        arg_parse_name=""           # the argument list for PyArg_ParseTuple 
        arg_decl=""                 # declaration section
        arg_control=""              # code parts for parameter check
        result_arg=""               # is the argument list of Py_BuildValue 
        result_format=""            # is the formatstring of Py_BuildValue


        
        a_pyufunc.ReturnParam("return", self.return_value, "")
            
        for p in self.parameters:
            arg_match=argument_type_pattern.match(p)
            if arg_match is None:
                raise RuntimeError,"%s: can not interpret parameter %s"%(self.name, p)
            arg_type=arg_match.group('type')
            arg_name=arg_match.group('name')
            arg_qualifier=arg_match.group('qualifier')
            arg_operator=arg_match.group('operator')
            if arg_operator == "*":
                a_pyufunc.AddOutParams(arg_name, arg_type, arg_operator)
            else:
                a_pyufunc.AddInParams(arg_name, arg_type, arg_operator)
            
        func="/* wrapper for "+self.original_declaration()+"  return = "+ self.return_value + " */\n" 

        
        return a_pyufunc
