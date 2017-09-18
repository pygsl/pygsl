"""Use the swig generated xml file to get the descriptions of the different
functions

To generate the interface
* call first swig with:
  swig -xml -I<Include path of gsl> sf.i

* Then call
  extract_ufunc_swig.py

"""
from __future__ import print_function
import sys
import os
import xml.etree.ElementTree as ElementTree
import gsl_arg
import sf_prototype
import emit_code

class ExtractError(Exception):
    pass

class FunctionFormatError(Exception):
    pass

class FunctionParameterTypeError(FunctionFormatError):
    pass

def get_indent(level):
    """Used for printing the tree
    """
    return "".join(("    ",) * level)


def extract_name_value(element):
    """Extract name and value pairs of the element
    """
    attr = element.attrib

    name = attr["name"]
    value = attr["value"]

    return name, value


def extract_value(element, name):
    """Check that the attr["name"] matches the name and return the content of the
    "value" attribute    
    """
    n, v = extract_name_value(element)
    if name != n:
        raise ExtractError("Expected attr name '%s' != '%s'!" %(name, n))

    return v

def check_name_value(element, name, value):
    """Check that the name and value attributes match the content of name and value
    """    
    v = extract_value(element, name)
    if value != v:
        raise ExtractError("Expected attr name '%s' != '%s'!" %(value,  v))        

    
def extract_func_parameter(par_n, level = None):
    """Extract one function parameter
    """
    al_l = par_n.getchildren()
    assert(len(al_l) == 1)
    
    al = al_l[0]
    assert(al.tag == "attributelist")

    ch = al.getchildren()    
    assert(len(ch) >= 2)
    var_name = extract_value(ch[0], "name")
    var_type = extract_value(ch[1], "type")

    return var_type, var_name


    
def create_arg(var_type, var_name):
    """convert a var_type as named by swig to a name gsl_arg.Argument understands

    * all const quality is considered as input
    * all pointer quality is considered as output
    """

    tmp = var_type.split('.')
    l = len(tmp)

    is_input = False
    is_output = False
    
    quality = None

    arg = gsl_arg.Argument()

    if l == 2:
        quality = tmp[0]
        t_type = tmp[1]
        if quality == "q(const)":
            is_input = True
        elif quality == "p":
            is_output = True
        else:
            msg = "var_type quality check len('%s') = %d: quality '%s' not known"
            raise FunctionParameterTypeError(msg %(var_type, l, quality))

    elif l == 1:
        t_type = tmp[0]
        if t_type in arg.GetArgumentTypes():
            is_input = True
        else:
            raise FunctionParameterTypeError("var_type '%s': t_type '%s' not known" %(var_type, t_type))

    else:             
        raise FunctionParameterTypeError("var_type '%s: len('%s') != 1|2" %(var_type, l))

    # Reimplement Argument as a dispatcher
    arg.SetName(var_name)
    arg.SetType(t_type)
    arg.SetOperator(quality)

    if is_input:
        arg.SetInputArgument()
    elif is_output:
        arg.SetOutputArgument()                        
    else:            
        raise FunctionParameterTypeError("var_type '%s': quality '%s' not known" %(var_type, quality))

    return arg

def create_sf_prototype(f_name, f_params, ret_type):
    """Create a sf prototype instance from the function name, the function parameters and the return type
    """
    args = []
    for var_type, var_name in f_params:
        test = 0
        try:
            arg  = create_arg(var_type, var_name)
            test = 1
        finally:
            if test == 0:
                print(f_name)
        args.append(arg)
    args = tuple(args)
        
    # The return type
    ret_arg = gsl_arg.Argument()
    ret_arg.SetName("ret")
    ret_arg.SetType(ret_type)
    #ret_arg.UnsetOutputArgument()
    ret_arg.SetReturnArgument()
    
    sf = sf_prototype.sf_prototype_build(name = f_name, ret = ret_arg, params = args)
    return sf

    pass


exclude_list = []
def extract_func(attr_l, level=None, verbose = None):
    """Get a node and try to build the pattern

    Needs documentation
    """
    indent = get_indent(level)

    # Thats how swig stores a function ... as I guessed it 
    f_name = extract_value(attr_l[0], "sym_name")
    f_name_check = extract_value(attr_l[1], "name")

    if f_name in exclude_list:
        return
    
    f_decl = extract_value(attr_l[2], "decl")

    # Now see if it is really a function
    kind_n = attr_l[4]
    kind = extract_value(kind_n, "kind")
    if kind == "typedef":
        return None

    if kind != "function":
        raise FunctionFormatError("Not a function: %s: '%s' " % (kind_n.tag, kind_n.attrib))
    
    # The paramters are a a parmlist
    parl_n = attr_l[3]
    tag = parl_n.tag
    if  tag != "parmlist":
        raise FunctionFormatError("Expected parmlist but found tag: '%s'" %(tag))

    f_params = []
    args = []
    cnt = 0
    for par_n in parl_n.getchildren():
        # The parameter of each variable        
        assert(par_n.tag == "parm")        
        var_type, var_name = extract_func_parameter(par_n, level = level+1)    
        f_params.append((var_type, var_name))

    ret_type = extract_value(attr_l[5], "type")

    args_str = map(lambda x: " ".join(x), f_params)
    args_str = ", ".join(args_str)

    if verbose:
        print( "Function: %s%s %s(%s) = %s" %(indent, ret_type, f_name,  args_str, f_decl))

    
    sf = create_sf_prototype(f_name, f_params, ret_type) 
    
    return sf
        
    

def handle_cdecl(cdecl, level=0, verbose = None):
    """swig declares function calls as a c declaration
    """
    assert(cdecl.tag == "cdecl")
    sf_s = []
    indent = get_indent(level)

    children = cdecl.getchildren()
    l = len(children)
    assert(l == 1)

    al = children[0]    
    assert(al.tag == "attributelist")

    cl = al.getchildren()
    l = len(cl)
    assert(l >= 1)

    func = cl[0]
    sub_nodes = 0
    if func.attrib["name"] == "sym_name":
        try:
            sf = extract_func(cl, level = level+1)
            sf_s.append(sf)
            sub_nodes = 1
        except ExtractError as ve:
            print("extract func failed with extract error : '%s'" %(ve,))
        #except FunctionFormatError as ffe:
        #    print("extract func failed with function format error: '%s'" %(ffe,))
        #    verbose = True

    if verbose:
        print("%s %s %s:%s" % ("CD", indent, cdecl.tag, cdecl.attrib) )
        print("%s %s %s:%s" % ("Func", indent, func.tag, func.attrib) )
        
        
    if sub_nodes  == 0:
        for child in cl:
            tmp = handle_nodes(child, level= level +1, only_node_name = (), mark = "NF", verbose = verbose)
            sf_s.extend(tmp)
    return sf_s

def handle_nodes(top, level = 0, mark = None, only_node_name = None, verbose = None):
    """handle the nodes of the tree top    
    """
    #if level > 6:
    #    return

    sf_s = []
    
    if only_node_name == None:
        only_node_name = ("include", "attributelist", "attribute")
    indent = get_indent(level)

    tag = top.tag

    try:
        top.attrib["code"]
        attr = ""
    except KeyError:
        attr = top.attrib

    if mark == None:
        t_mark = ""
    else:
        t_mark = mark

    if 1 == 0 and verbose:
        if tag in only_node_name:
            print("TAG %s %s %s:" % (t_mark, indent, top.tag) )
        else:
            print("NTAG %s %s %s: %s" % (t_mark, indent, top.tag, attr))
    
    for child in top.getchildren():
        names = only_node_name
        if child.tag == "cdecl":
            names = ()
            tmp = handle_cdecl(child, level = level +1)
            #print_nodes(child, level= level +1, only_node_name = names)
        else:
            tmp = handle_nodes(child, level= level +1, only_node_name = names, mark = mark, verbose = verbose)
        sf_s.extend(tmp)

        
    return sf_s
            
        
        
def traverse_tree(tree, verbose = None):
    """Build up sf_prototype instances for the different functions found
    """
    top = tree.getroot()
    if verbose:
        print(top, top.attrib)

    print("starting processing")
    sf_s = []
    for child in top.getchildren():
        sf = handle_nodes(child, level=1, verbose = verbose)
        sf_s.extend(sf)
    return sf_s

    

def build_ufunc_files(file_name, output_dir, output_prefix):
    tree = ElementTree.parse(file_name)
    sf_s = traverse_tree(tree, verbose= False)

    print("Found sf's ------")

    sf_valid = []
    for sf in sf_s:
        if sf is None:
            continue
        print(sf)
        sf_valid.append(sf)
        #break

    # UFunc ... different call signatures
    dic = {}
    for sf in sf_valid:
        UFuncName = sf_prototype.get_py_ufunc_name(sf)
        try:
            dic[UFuncName]
        except KeyError as des:
            dic[UFuncName] = sf

    eval_name = os.path.join(output_dir, output_prefix + "_evals.c")
    data_name = os.path.join(output_dir, output_prefix + "_data.c")
    #array_name = output_prefix + "_arrays.c"

    ef = open(eval_name, "wt")
    dtf = open(data_name, "wt")
    df = dtf
    #df = open(array_name, "wt")

    try:
        # UFunc for the  different call signatures
        for key in dic.keys():
            sf = dic[key]
            minor = False
            #print("Minor", minor)
            emit_code.emit_evaluator(sf, minor, ef)
            minor = True
            #print("Minor", minor)
            emit_code.emit_evaluator(sf, minor, ef)
            emit_code.emit_data_types(sf, dtf)
            emit_code.emit_data(sf, df)
    finally:
        ef.close()
        del ef
        dtf.close()
        del dtf
        df.close()
        del df

    cb_name = os.path.join(output_dir, output_prefix + "_data.c")
    obj_name = os.path.join(output_dir, output_prefix + "_objects.c")
    doc_name = os.path.join(output_dir, output_prefix + "_doc.rst")
    cbf = open(cb_name, "at")
    of = open(obj_name, "wt")
    doc_f = open(doc_name, "wt")
    try:
        for sf in sf_valid:
            emit_code.emit_callbacks(sf, cbf)
            emit_code.emit_object(sf, of)
            emit_code.emit_doc_variable(sf, cbf)
            emit_code.emit_doc(sf, doc_f)
    finally:
        cbf.close()
        del cbf
        of.close()
        del of
        doc_f.close()
        del doc_f
        
def run():
    import os.path
    #file_name = "sf.xml"
    file_name = "sf_wrap.xml"

    dirname = os.path.dirname(__file__)
    full_name = os.path.join(dirname, file_name)
    build_ufunc_files(full_name, out_dir, "sf_")
    
if __name__ == '__main__':
    import sys
    l = len(sys.argv)
    if l != 4:
        sys.stderr.write("Expected three arguments but got %d: %s!" % (l, sys.argv));
        sys.exit(-1)
    swig_xml_file = sys.argv[1]
    output_dir = sys.argv[2]
    output_prefix = sys.argv[3]
    build_ufunc_files(swig_xml_file, output_dir, output_prefix)
    #run()
