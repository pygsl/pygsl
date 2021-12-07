"""Use the swig generated xml file to get the descriptions of the different
functions

To generate the interface use
.. code-block:: bash
    python setup.py gsl_wrappers

Or eecute it by hand
* call first swig with:
  swig -xml -I<Include path of gsl> sf.i

* Then call
  extract_ufunc_swig.py 

"""
from __future__ import print_function
import copy
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
    al_l = list(par_n)
    assert(len(al_l) == 1)
    
    al = al_l[0]
    assert(al.tag == "attributelist")

    ch = list(al)
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

# Functions to exclude from the whole list.
exclude_list = ['gsl_sf_angle_restrict_pos_e', # use a double * for input and output. not properly recognized.
                'gsl_sf_angle_restrict_symm_e',
                # use gsl_sf_angle_restricted_pos_err_e complies to the usual interface
                'gsl_sf_result_smash_e', # the only one to use a const pointer as input. Not recognized by the tool.
                # Complex Functions are wrapped manually.
                'gsl_sf_complex_dilog_e',   # polar to rect
                'gsl_sf_lngamma_complex_e', # rect to polar
                'gsl_sf_complex_log_e',     # rect to polar
                'gsl_sf_complex_sin_e',     # rect to rect
                'gsl_sf_complex_cos_e',     # rect to rect
                'gsl_sf_complex_logsin_e',
                #Deprecated functions
                'gsl_sf_coupling_6j_INCORRECT_e',
                'gsl_sf_coupling_6j_INCORRECT',
                # Not a direct map
                'gsl_sf_polar_to_rect',
                'gsl_sf_rect_to_polar',
                # Functions returning arrays are not mapped currently.
                'gsl_sf_bessel_sequence_Jnu_e',
                'gsl_sf_bessel_Jn_array',
                'gsl_sf_bessel_Yn_array',
                'gsl_sf_bessel_In_array',
                'gsl_sf_bessel_In_scaled_array',
                'gsl_sf_bessel_Kn_array',
                'gsl_sf_bessel_Kn_scaled_array',
                'gsl_sf_bessel_jl_array',
                'gsl_sf_bessel_jl_steed_array',
                'gsl_sf_bessel_yl_array',
                'gsl_sf_bessel_il_scaled_array',
                'gsl_sf_bessel_kl_scaled_array',
                'gsl_sf_coulomb_wave_F_array',
                'gsl_sf_coulomb_wave_FG_array',
                'gsl_sf_coulomb_wave_FGp_array',
                'gsl_sf_coulomb_wave_sphF_array',
                'gsl_sf_coulomb_CL_array',
                'gsl_sf_gegenpoly_array',
                'gsl_sf_legendre_Pl_array',
                'gsl_sf_legendre_Pl_deriv_array',
                'gsl_sf_legendre_Plm_array',
                'gsl_sf_legendre_Plm_deriv_array',
                'gsl_sf_legendre_sphPlm_array',
                'gsl_sf_legendre_sphPlm_deriv_array',
                'gsl_sf_legendre_array_size',
                'gsl_sf_legendre_H3d_array',
               'gsl_sf_legendre_array',
               'gsl_sf_legendre_array_e',
               'gsl_sf_legendre_deriv_array_e',
               'gsl_sf_legendre_deriv_array',
               'gsl_sf_legendre_deriv_alt_array',
               'gsl_sf_legendre_deriv_alt_array_e',
               'gsl_sf_legendre_deriv2_array',
               'gsl_sf_legendre_deriv2_array_e',
               'gsl_sf_legendre_deriv2_alt_array',
               'gsl_sf_legendre_deriv2_alt_array_e',
               'gsl_sf_legendre_array_n',
               'gsl_sf_legendre_array_index',
                'gsl_sf_legendre_nlm',
               'gsl_sf_mathieu_ce_array',
               'gsl_sf_mathieu_se_array',
               'gsl_sf_mathieu_Mc_array',
               'gsl_sf_mathieu_Ms_array',
                'gsl_sf_mathieu_a_array',
                'gsl_sf_mathieu_b_array',
                'gsl_sf_mathieu_workspace',
                'gsl_sf_mathieu_alloc',
                'gsl_sf_mathieu_free',
                "gsl_sf_mathieu_a_coeff",
                "gsl_sf_mathieu_b_coeff",
                ]

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
    for par_n in list(parl_n):
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

    children = list(cdecl)
    l = len(children)
    assert(l == 1)

    al = children[0]    
    assert(al.tag == "attributelist")

    cl = list(al)
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
    
    for child in list(top):
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
    for child in list(top):
        sf = handle_nodes(child, level=1, verbose = verbose)
        sf_s.extend(sf)
    return sf_s

    

def build_ufunc_files(file_name = None, output_dir = None, prefix = None, doc_dir = None):

    assert(file_name is not None)
    assert(output_dir is not None)
    assert(prefix is not None)
    assert(doc_dir is not None)

    output_prefix = prefix
    
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
    cbf = open(cb_name, "at")
    of = open(obj_name, "wt")
    try:
        for sf in sf_valid:
            emit_code.emit_callbacks(sf, cbf)
            emit_code.emit_object(sf, of)
            emit_code.emit_doc_variable(sf, cbf)
    finally:
        cbf.close()
        del cbf
        of.close()
        del of

    emit_sf_doc(sf_valid, doc_dir = doc_dir, output_prefix = prefix)

    
def emit_sf_doc(sf_valid, doc_dir = None, output_prefix = None):
    sf_valid_doc = copy.copy(sf_valid)
    sf_dic = {}
    for sf in sf_valid_doc:
        name = sf.GetFunctionName()
        sf_dic[name] = sf

    names = sf_dic.keys()
    sf_sections = (
        'airy',
        'bessel',
        'clausen',
        'coulomb',
        'hydrogenic',
        'clausen',
        'coupling',
        'dawson',
        'debye',
        'ellint',
        'elljac',
        'fermi_dirac',
        'poch',
        'gegenpoly',
        'hermite',
        'hyperg',
        'laguerre',
        'lambert',
        'mathieu',
        'pow',
        'psi',
        'synchrotron',
        'transport',
        'gsl_complex',
    #        'sf_complex',
    #   'complex',
     )        

    names = list(names)
    names.sort()
    names_test = copy.copy(names)
    names = set(names)
    # names are unique
    assert(len(names) == len(names_test))

    
    #doc_name = os.path.join(output_dir, output_prefix + "_doc.rst")
    #with open(doc_name, "wt") as doc_f:
    #    for name in names_test:
    #        sf = sf_dic[name]
    #        emit_code.emit_doc(sf, doc_f)
    #return
    # Sort the names into sections?
    def sort_sf_to_file(sf_dic, names, sec, doc_f):
        to_remove = []
        for name in names:
            if sec in name:
                print("Sorting %s in sec %s" %(name, sec))
                sf = sf_dic[name]
                emit_code.emit_doc(sf, doc_f)
                to_remove.append(name)
        to_remove = set(to_remove)
        names.difference_update(to_remove)
        
    for sec in sf_sections:
        doc_name = os.path.join(doc_dir, output_prefix + "_" + sec + "_doc.rst")
        with open(doc_name, "wt") as doc_f:
            sort_sf_to_file(sf_dic, names, sec, doc_f)
                            
    sf_sec_dic = {
        'legendre' : ('legendre', 'conical',),
        'trig' : ('gsl_sf_sin', 'gsl_sf_sin', 'gsl_sf_cos', 'gsl_sf_cos',
                  'sf_hypot', 'sf_sinc',
                  'sf_complex_sin',
                  'sf_complex_cos',
                  'sf_complex_logsin',
                  'sf_lnsinh',
                  'sf_lncosh',
                  'gsl_acosh', 'gsl_asinh', 'gsl_atanh', 'sf_lncosh',
                  'sf_polar',
                  'sf_rect_to_polar',
                  'sf_angle_rest',
                  ),
         'log' : ('sf_log', ),
         'erf' : ('sf_erf', 'sf_hazard'),
        'dilog': ('sf_dilog', 'sf_spence', 'sf_complex_dilog', 'sf_complex_spence'),
        'exp'  : ('sf_exp', 'sf_Shi', 'sf_Chi', 'sf_Ci', 'sf_Si', 'sf_atan'),
        'gamma' :  ('sf_gamma', 'sf_lngamma', 'sf_fact', 'sf_doublefact', 'sf_lnfact', 'sf_lndoublefact',
                    'sf_choose', 'sf_lnchoose', 'sf_taylorcoeff', 'sf_poch', 'sf_lnpoch',
                     'sf_beta', 'sf_lnbeta'),
        'zeta' : ('sf_zeta', 'sf_hzeta', 'sf_eta'),
        'elementary' : ('sf_multiply',),
        'math' : ('fcmp', 'fdiv', 'isinf', 'hypot', 'finite', 'isnan', 'frexp', 'ldexp', 'expm1', 'log1p', 'coerce_double'),
    }
    keys = sf_sec_dic.keys()
    for key in keys:
        doc_name = os.path.join(doc_dir, output_prefix + "_" + key + "_doc.rst")
        with open(doc_name, "wt") as doc_f:
            l = list(sf_sec_dic[key])
            l.sort()
            for sec in l:
                sort_sf_to_file(sf_dic, names, sec, doc_f)

    # the names left over
    print("Not sorted in different sections: %d items" %(len(names)) )
    doc_name = os.path.join(doc_dir, output_prefix + "_" + "misc" + "_doc.rst")
    with open(doc_name, "wt") as doc_f:
        for name in names:
            sf = sf_dic[name]
            print(name)
            emit_code.emit_doc(sf, doc_f)

                
def run():
    import os.path
    #file_name = "sf.xml"
    file_name = "sf_wrap.xml"

    dirname = os.path.dirname(__file__)
    full_name = os.path.join(dirname, file_name)
    build_ufunc_files(full_name, out_dir, "sf_")
    
if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(description = "UFunc generator")
    parser.add_argument("--input",  help = "swig xml parser tree")
    parser.add_argument("--output-dir", help = "directory where to put the wrapper c-files")
    parser.add_argument("--prefix",  help = "perfix of the c wrapper file")
    parser.add_argument("--doc-dir", help = "directory where to put the documentation files to")
    args = parser.parse_args()
    print(args)
    print (dir(args))
    print (args.input)
    #print (parser.())
    build_ufunc_files(file_name = args.input, output_dir = args.output_dir,
                      prefix = args.prefix, doc_dir = args.doc_dir)
