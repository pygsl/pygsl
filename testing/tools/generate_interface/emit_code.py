import sys
import sf_prototype

def add_indent(lines, indent):
    result = []
    for line in lines:
        result.append(indent + line)
    return result

def emit_doc(sf, stream):
    """
    """
    name = sf.GetFunctionName()
    UFuncName =  sf_prototype.get_py_ufunc_name(sf)

    full_name = sf.GetFunctionName()
    name = sf.GetPyFunctionName()
    comment = sf.GetComment()

    in_args = sf.GetInArguments()
    in_args = tuple(in_args)
    # Build up python func signature ... not functional yet
    l = []
    for arg in in_args:
        tmp = arg.GetPyVariableNames()
        l.extend(tmp)

    func_signature = ", ".join(l)

    ret_arg = sf.GetReturnArgument()
    out_args = sf.GetOutArguments()
    out_args = tuple(out_args)

    l = []
    for arg in (ret_arg,) +  out_args:
        tmp = arg.GetPyVariableNames()
        l.extend(tmp)
    tmp = ", ".join(l)

    func_signature += " [, %s]" %(tmp,)

    func_decl = sf.GetFunctionDeclaration()
    doc=r'''.. py:function:: %s(%s)

    Wrapper for :c:func:`%s`
    c code signature: %s
    Wrapped by ufunc :class:`%s`
    
'''
    txt = doc %(name, func_signature, full_name,  func_decl, UFuncName)
    stream.write(txt)

    # Definition of arguments
    fmt = "    :param %s %s: %s\n"
    all_args = in_args +(ret_arg,) + out_args
    for arg in all_args:
        decl = arg.GetPyVariableNamesDecl()
        txt = "\n    ".join(decl)
        stream.write("    " + txt + "\n")

    # Return tuple .... 
    if out_args == None or len(out_args) == 0:
        arg_type = ret_arg.GetGSLType()
        stream.write("    :rtype:  %s \n" %(arg_type,) )
        stream.write("    :return: result \n")
        pass
    
    else:
        l = []
        for arg in (ret_arg,) +  out_args:
            decl = arg.GetPyVariableNamesDecl()
            l.extend(decl)
        tmp = ", ".join(l)
        stream.write("    :rtype:  tuple(%s) \n" %(tmp,) )
        stream.write("    :return: result \n")
        
    stream.write("\n")
        
def emit_evaluator(sf, minor = None, stream = sys.stdout, verbose = False):
    """Emit the code for the evaluator loop

    Args:
        sf:      a :class:`sf_prototype` instance
        stream:  output stream to write to

    emits the code of the inner loop
    """
    UFuncName =  sf_prototype.get_py_ufunc_name(sf, minor)
    #print(UFuncName)
    if minor in (None, False, 0):
        def convert(arg):
            return arg
    else:
        def convert(arg):
            min_arg = arg.AsMinor()
            return min_arg
        
    in_args = sf.GetInArguments()
    in_args = map(convert, in_args)
    in_args = tuple(in_args)
    
    out_args = sf.GetOutArguments()    
    out_args = map(convert, out_args)
    out_args = tuple(out_args)
    
    ret_arg = sf.GetReturnArgument()
    ret_arg = convert(ret_arg)


    print("/* operating on '%s' '%s'*/" %(str(sf), repr(sf)) )
    fp_decl = sf.GetFunctionPointerDeclaration()
    del sf

    lines = []

    func_decl = """
void %s (char **args, PyGSL_array_index_t *dimensions, PyGSL_array_index_t *steps, void *func)
{"""
    lines.append(func_decl % (UFuncName,))

    all_args = in_args + (ret_arg,) + out_args

    if verbose:
        lines.append("\t/* ------------------------------ variable declarations ------------------------------ */")
        lines.append("\t/* pointer to arrays */")
    steps = []
    for arg in all_args:
        steps.extend(arg.GetArrayPointerDeclaration())
    steps = ", ".join(steps);
    lines.append("\tchar %s;" % (steps,));

    if verbose:
        lines.append("\t/* steppers */")
    steps = []
    for arg in all_args:
        steps.extend(arg.GetStrideDeclaration())
    steps = ", ".join(steps);
    lines.append("\tPyGSL_array_index_t i, %s;" % (steps,));

    # Temporary variables
    if verbose:
        lines.append("\t/* Temporary variables */")
    for arg in all_args:
        #lines.append("\t/* operating on  arg '%s'*/" %(str(arg), ) )
        tmp_var = arg.GetTmpVariables()
        desc = " /* arg '%s'*/" %(str(arg), )
        if verbose: tmp_var[0] += desc
        lines.extend(add_indent(tmp_var, "\t"))
    if verbose:
        lines.append("\t/* ------------------------------ end variable declarations -------------------------- */")

    lines.append("\tFUNC_MESS_BEGIN();\n")
    # Start of for loop: which steps to take ...
    all_pointer_increases = []
    for arg in all_args:
        tmp = arg.GetArrayPointerStepping()
        all_pointer_increases.extend(tmp)
    all_pointer_inc_txt = ", ".join(all_pointer_increases)    
    lines.append("\t for(i = 0; i < dimensions[0]; ++i, %s){\n" %(all_pointer_inc_txt,))
    if verbose:
        lines.append("\t\t/* In args assignment */")
    for arg in in_args:
        #lines.append("\t\t/* operating on  arg '%s'*/" %(str(arg), ) )
        tmp_var = arg.GetInputTmpVariablesAssignment()
        desc = " /* arg '%s'*/" %(str(arg), )
        tmp_var[0] += desc        
        lines.extend(add_indent(tmp_var, "\t\t"))

    
    if verbose:
        lines.append("\t\t/* function call */")
    # Can there be more than one return argument?
    ret_txt, = ret_arg.GetReturnCallArgument()
    func_cast, = ret_arg.GetFunctionReturnCast()
    #if func_cast:
    #    func_cast = "(/* func cast */ '%s')" % (func_cast,)
    tmp = (ret_txt, func_cast, fp_decl)
    if verbose: 
        func_call = "/* ret call */ %s =  %s ((/* func decl */ %s) func)(" % tmp
    else:
        func_call = "%s =  %s ((%s) func)(" % tmp
    arg_txt = []
    #for arg in sf.GetParameters():

    # XXX 
    # Add function parameters .... first in then out ...
    # That's the signature of gsl functions but does not need to be    
    for arg in all_args:
        if arg.IsInputArgument():
            t_vars = arg.GetInputCallArgument()
        if arg.IsReturnArgument():
            continue
        if arg.IsOutputArgument():
            t_vars = arg.GetOutputCallArgument()
            
        one_arg = "/* %s */ %s" %(arg, ",".join(t_vars))
        arg_txt.append(one_arg)

        
    all_args_txt = ", ".join(arg_txt)
    func_call += all_args_txt + ");"
    lines.append("\t\t%s" %(func_call) )

    
    arg = ret_arg
    if verbose:
        lines.append("\t\t/* operating on return arg '%s'*/" %(str(arg), ) )
    tmp_var = arg.GetReturnTmpVariablesAssignment()
    lines.extend(add_indent(tmp_var, "\t\t"))

    if verbose:
        lines.append("\t\t/* out args assignment */")
    for arg in out_args:
        if verbose:
            lines.append("\t\t/* operating on  arg '%s'*/" %(str(arg), ) )
        tmp_var = arg.GetOutputTmpVariablesAssignment()
        lines.extend(add_indent(tmp_var, "\t\t"))

    lines.append("\t\tcontinue;")

    need_fail = False
    for arg in all_args:
        if arg.NeedFailLabel():
            need_fail = True
            break
    if need_fail:
        lines.append("")
        lines.append("\t    fail:")
        lines.append('\tFUNC_MESS("FAIL");\n')
        lines.append('\tDEBUG_MESS(3, "Failed in loop %ld", (long) i);\n')
        for arg in (ret_arg,) + out_args:
            if verbose:
                lines.append("\t\t/* operating on  arg '%s'*/" %(str(arg), ) )
            tmp_var = arg.GetOutputVariablesSetOnError()
            lines.extend(add_indent(tmp_var, "\t\t"))
    lines.append("\t}")
        
    lines.append("\tFUNC_MESS_END();\n")
    lines.append("} /* %s */ \n" % (UFuncName,) )
    
    txt = "\n".join(lines)
    stream.write(txt)
    
    
def emit_data_types(sf, stream):
    """Emit the code with the type of the different array which are acceptable

    needs the type 
    """
    lines = []
    UFuncName =  sf_prototype.get_py_ufunc_name(sf)

    definition = "static char %s_types[] = {" % (UFuncName,)
    lines.append(definition)

    in_args = sf.GetInArguments()
    in_args = tuple(in_args)

    ret_arg = sf.GetReturnArgument()
    
    out_args = sf.GetOutArguments()    
    out_args = tuple(out_args)
    
    args = in_args + (ret_arg,) + out_args

    defs = []
    for minor in False, True:
        t_types = []
        for arg in args:
            if minor:
                t_arg = arg.AsMinor()
            else:
                t_arg = arg
            tmp = t_arg.GetNumpyTypeCode()
            desc = str(t_arg)
            test = 0
            try:
                codes = ",".join(tmp)
                test = 1
            finally:
                if test == 0:
                    print("Processing", t_arg)
            t_decl = "/*%s*/% 10s" %(desc, codes)
            t_types.append(t_decl)
        defs.append("\t" + ", ".join(t_types))
    defs = ",\n".join(defs)
    lines.append(defs)
    lines.append("};\n")
    txt = "\n".join(lines)
    stream.write(txt + "\n")


def emit_data(sf, stream):
    """Data arrays

    What are these for?
    """
    UFuncName =  sf_prototype.get_py_ufunc_name(sf)
    decl = ("NULL",) * 2
    decl = ", ".join(decl)
    txt = "static PyUFuncGenericFunction %s_data[] = {%s};\n" %(UFuncName, decl)
    stream.write(txt)
    #sys.stdout.write(txt)
    
def emit_callbacks(sf, stream):
    """Callbacks

    Currently assuming:
       1. normal mode
       2. minor mode: e.g. floats instead of double
    """
    lines=[]
    
    func = sf.GetFunctionName()
    decl = ["(void *) %s" %(func,)] * 2
    tmp = ", ".join(decl)
    a_line = "static void * %s_data[] = {%s};" % (func, tmp)
    lines.append(a_line)
    
    txt = "\n".join(lines)
    stream.write(txt + "\n")


def emit_doc_variable(sf, stream):
    """The code that goes into .__doc__    
    """
    name = sf.GetFunctionName()
    UFuncName =  sf_prototype.get_py_ufunc_name(sf)
    
    lines = []
    lines.append('static const char %s_doc[] =' %(name,))
    doc=r'''"Wrapper for :c:func:`%s`\n"
"\n"
"Wrapped by ufunc :class:`%s`\n"
"Args:\n"    
    '''      
    tmp = doc %(name, UFuncName)
    lines.append(tmp)

    in_args = sf.GetInArguments()
    for arg in in_args:
        #desc = arg.GetDocDescription()
        #lines.append("    %s: ")
        pass

    
    txt = "\n".join(lines)
    stream.write(txt + ";\n")
    

def emit_object(sf, stream):

    UFuncName =  sf_prototype.get_py_ufunc_name(sf)
    UFuncNameMinor =  sf_prototype.get_py_ufunc_name(sf, 1)
    
    n_in  = sf.GetUFuncNInArgs()
    n_out = sf.GetUFuncNOutArgs()
    full_name = sf.GetFunctionName()
    name = sf.GetPyFunctionName()
    
    lines = []
    lines.append("%s_data[0] = (PyUFuncGenericFunction) %s;" %(UFuncName, UFuncName))
    lines.append("%s_data[1] = (PyUFuncGenericFunction) %s;" %(UFuncName, UFuncNameMinor))
    
    obj_decl = """
/*Object declaration for '%s'*/
f = PyUFunc_FromFuncAndData( %s, /* NULL ptr data */
                             %s, /* call backs */
                             %s, /* types */ 
                             2, /* number of supported types */
                             %d, /* in args */
                             %d, /* out args */
                             PyUFunc_None,
                             "%s", /* name of py object */
                             %s, /* doc variable */ 
                             0 /*check return*/); 
PyDict_SetItemString(sf_dict,"%s" /* name of py object */, f);
"""
    NULL = "NULL"
    data = UFuncName + "_data"
    types = UFuncName + "_types"
    callbacks = full_name + "_data"
    doc = full_name + "_doc"
    args = (sf, data, callbacks, types, n_in, n_out, name, doc, name)
    #print(args)
    tmp = obj_decl % args
    lines.append(tmp)
    txt = "\n".join(lines)
    stream.write(txt + "\n")
    
def emit_code(a_sf_prototype, stream):
    """Emits the code for one sf_prototype

    Requires to be split up:
    * for the evaluator
    * for the data object
    * for the init part
    """
