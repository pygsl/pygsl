"""

class prototype_collector generates code to wrap functions using only numerical
arguments as UFuncs. This involves the following steps:

    - searching for the header files and parsing them
    - generating code required for the different functions

    - writing the code for the different UFunc evaluators required for the
      different types.
      
"""
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

    def set_exclude_list(self, mylist):
        self.exclude_list = mylist

    def make_wrapper_and_index_file(self, filename, *search_patterns):
        """
        The main worker.
        
        Reads the header files using get_prototypes. This sets up a
        representation of the different prototypes as PyUFunc objects. 
        These objects are then used to write the different parts of the
        wrapper. The files for the different parts are listed below:
        
        _index.c    : entries for the PyMethodstable for the sf module
        _data.c     : static data for the different Ufunc evaluators
        _ufuncs.txt : lists which ufunc is used to evaluate which function
        _evals.c    : the different evaluators

        First it writes the (static) information for wrapping the different functions.

        Then it generates a list of the different required UFunc evaluation functions
        and generates the code for them. Each evaluator can be used for all the different
        functions with the same prototype.
        
        """
        prototypes=self.get_prototypes(*search_patterns)
        index_file = file(filename+"_index.c","w")
        data_file = file(filename+"_data.c","w")
        objects_file = file(filename+"_objects.c","w")
        ufuncs_list =  file(filename+"_ufuncs.txt","w")
        evaluators = file(filename + "_evals.c", "w")
        ufunc_names_dic = {}

        for p in  prototypes[:]:
            if p.get_name() in self.exclude_list:
                continue
            index_entry=p.make_function_entry()
            if index_entry is not None:
                try:
                    a_py_ufunc =  p.make_wrapper_function()
                    data_file.write(a_py_ufunc.WriteStaticData()+"\n")
                    #objects_file.write("{\n")
                    test = 0
                    try:
                        objects_file.write(a_py_ufunc.WriteUFuncObject()+"\n")
                        test = 1
                    finally:
                        if test == 0:
                            print "I was working on prototype", p.get_name()
                    #objects_file.write("}\n")
                    index_file.write(index_entry+",\n")
                except RuntimeError, message:
                    print message

                # Collect the various differnt  ufuncs objects. These will
                # iterate over the functions
                ufunc_names = a_py_ufunc.GetPyUFuncEvaluatorNames()    
                for name in ufunc_names:
                    print name
                    if not ufunc_names_dic.has_key(name):
                        ufunc_names_dic[name] = []
                    ufunc_names_dic[name].append(a_py_ufunc)                  
            else:
                print "No index entry for", p.get_name()
                    
        index_file.close()

        # List which evaluator handles which functions
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
        
        documentation_file = file(filename + "_doc.tex", "w")
        all_functions = {}
        for i in names:
            l = ufunc_names_dic[i]
            for uf in l:
                all_functions[uf.GetName()] = uf
        keys = all_functions.keys()
        keys.sort()
        for key in keys:
            uf = all_functions[key]
            doc = uf.WriteUFuncLatexDoc()
            documentation_file.write(doc)
        documentation_file.close()
        
    def get_prototypes(self, *patterns):
        """
        Get the function prototypes from the files
        """
        file_name_list=self.determine_headers(*patterns)
        all_prototypes=[]
        for file_name in file_name_list:
            print "Processing file %s" %(file_name, )
            new_prototypes=self.get_prototypes_from_file(file_name)
            all_prototypes.extend(new_prototypes)
        return all_prototypes
        
    def determine_headers(self, *patterns):
        """
        returns a list of header files of special functions.
        
        searches for the header file "<gsl/gsl_sf.h>" for the special functions
        of the GSL library and generates a list of all the gsl_sf_*.h files
        included there.
        """

        #prepare file names
        general_include_dir_name=self.prefix

        sf_header_list=[]
        for pattern in patterns:
            general_include_file_name=os.path.join(general_include_dir_name, "gsl", pattern)

            #test if exists
            if not os.path.isfile(general_include_file_name):
                raise Exception,"could not find general header file '%s'" % (general_include_file_name,)

            #parse file for includes
            general_include_file=file(general_include_file_name,"r")
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
            sf_header_list.append(general_include_file_name)
        return sf_header_list


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
            print "Found function prototype", tmp.get_name(), 
            if tmp.get_name() not in self.exclude_list:
                print "excluded"
                prototype_list.append(tmp)
            else:
                print
        return prototype_list
                
class sf_prototype:
    """
    contains all necessary informations about the prototype
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
        if matched_name_stem is None:
            # Try if it is a complex function
            matched_name_stem=re.match("gsl_complex_(.+?)$",self.name)
            self.use_return_value = 1            
        if  matched_name_stem is None:
            return None
        name_stem=matched_name_stem.group(1)
        return "{\"%s\",%s_wrap,METH_VARARGS}"%(name_stem,self.name)
        

    def make_wrapper_function(self):
        """
        define function for gsl wrapper library using PyUFunc objects
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
