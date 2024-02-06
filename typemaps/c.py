"""Write type conversion
"""
#!/usr/bin/env python
#
#  Author: Pierre Schnizer
#

import sys

# fmt:off
vector_dic = {
"complex_long_double"  :   ("NPY_CLONGDOUBLE","gsl_complex_long_double" ,"long double" ),
"complex_double"       :   ("NPY_CDOUBLE ","gsl_complex"             ,"double"      ),
"complex_float"        :   ("NPY_CFLOAT  ","gsl_complex_float"       ,"float"       ),
"complex"              :   ("NPY_CDOUBLE ","gsl_complex"             ,"double"      ),

"long_double"          :   ("NPY_LONGDOUBLE","long double"             ,"long double" ),
"double"               :   ("NPY_DOUBLE  ","double"                  ,"double"      ),
"float"                :   ("NPY_FLOAT   ","float"                   ,"float"       ),
""                      :  ("NPY_DOUBLE  ","double"                  ,"double"      ),

"ulong"                :   ("NPY_ULONG  ","unsigned long"           ,"unsigned long"),
"long"                 :   ("NPY_LONG    ","long"                    ,"long"        ),

"uint"                 :   ("NPY_UINT    ","unsigned int"            ,"unsigned int"),
"int"                  :   ("NPY_INT     ","int"                     ,"int"         ),

"ushort"               :   ("NPY_USHORT  ","unsigned short"          ,"unsigned short"),
"short"                :   ("NPY_SHORT   ","short"                   ,"short"       ),

"uchar"                :   ("NPY_UBYTE   ","unsigned char"           ,"unsigned char"),
"char"                 :   ("NPY_BYTE    ","char"                    ,"char"        ),
}
vector_tuple =(
"complex_long_double",
"complex_double"     ,
"complex_float"      ,
"complex"            ,

"long_double"        ,
"double"             ,
"float"              ,
""                   ,

"ulong"              ,
"long"               ,

"uint"               ,
"int"                ,

"ushort"             ,
"short"              ,

"uchar"              ,
"char"               ,
)
# fmt:on

class Description:
    def __init__(self, key, struct, matvec, view):
        self.key = key
        self.struct = struct
        self.matvec = matvec
        self.view = view

    def _Concat(self, b, a, string = '_'):
        if a == "":
            return b
        return  b + "_" + a

    def gsl_vector(self):
        return self._Concat(self._Concat(self.matvec, self.key), self.view)

    def gsl_vector_basis(self):
        return self._Concat(self.matvec, self.key)

    def pyarray(self):
        return self.struct[0]

    def gsl_base_type(self):
        return self.struct[1]

    def c_base_type(self):
        return self.struct[2]

class WriteConversion:

    def _header(self):
        print("""/* -*- C -*- */
/* Automatically generated file
 * Do not edit directly.
 * Edit c.py instead!!!
 */
         """)
        return

    def _footer(self):
        print("""
/* EOF */
        """)
        return

    def __call__(self, name):
        try:
            tmp = sys.stdout
            file = open(name, 'w')
            sys.stdout = file
            self._header()
            self._iterate()
            self._footer()
            file.close()

        finally:
            sys.stdout = tmp
        return



    def Convert_TO_PyArray_TYPE(self, des):
        """
        provide a define to convert from gsl_vector_ to the approbriate python
        array length. SO TO_PyArray_TYPE_gsl_vector_complex_double will
        translate to PyArray_CDOUBLE.
        """
        vec = des.gsl_vector()
        pya = des.pyarray()
        #print "#define TO_PyArray_TYPE_%-35s  %s" % (vec, pya)
        print("%-50s = %s," % (vec + "_py_array_type", pya))
        return

    def Convert_TO_TYPE_VIEW(self, des):
        """
        provide a define to convert from gsl_vector_ to the approbriate
        gsl_vector_ _view.
        """

        vec = des.gsl_vector()
        vec1 = des.gsl_vector()
        print("#define TYPE_VIEW_%-35s         %s_view" % (vec, vec1))
        return

    def Convert_TO_TYPE_VIEW_ARRAY(self, des):
        """
        provide a define to convert from gsl_vector_ to the approbriate
        gsl_vector_ _view_array.
        """

        vec = des.gsl_vector()
        vec1 = des.gsl_vector_basis()
        print("#define TYPE_VIEW_ARRAY_%-35s         %s_view_array" % (vec, vec1))
        return

    def Convert_TO_TYPE_VIEW_ARRAY_STRIDES(self, des):
        """
        provide a define to convert from gsl_vector_ to the approbriate
        gsl_vector_ _view_array_with_strides.
        """

        vec = des.gsl_vector()
        vec1 = des.gsl_vector_basis()
        print("#define TYPE_VIEW_ARRAY_STRIDES_%-35s         %s_view_array_with_stride" % (vec, vec1))
        return

    def Convert_TO_BASIS_TYPE(self, des):
        vec = des.gsl_vector()
        basis = des.gsl_base_type()
        #print "#define BASIS_TYPE_%-35s        %s" % (vec, basis)
        print("typedef %-35s %s_basis_type; " % (basis, vec))
        return

    def Convert_TO_BASIS_TYPE_C(self, des):
        vec = des.gsl_vector()
        basis = des.c_base_type()
        #print "#define BASIS_TYPE_C_%-35s        %s" % (vec, basis)
        print("typedef %-35s %s_basis_c_type; " % (basis, vec))
        return

    def Convert_TO_GET(self, des):
        vec = des.gsl_vector()
        vec1 = des.gsl_vector_basis()
        print("#define GET_%-35s        %s_get" % (vec, vec1))
        return

    def Convert_TO_BASIS(self, des):
        vec = des.gsl_vector()
        vec1 = des.gsl_vector_basis()
        print("#define BASIS_%-35s        %s" % (vec, vec1))
        return

    def _find_func(self):
        l = []
        teststr = 'Convert'
        mylen = len(teststr)
        for i in dir(self.__class__):
            if i[:mylen] == teststr:
                l.append(eval('self.' + i))
        return l

    def _iterate(self):
        for j in ("gsl_vector", "gsl_matrix"):
            for l in self._find_func():
                if l == self.Convert_TO_PyArray_TYPE:
                    print("enum {")
                for k in ("", "view"):
                    for i in vector_tuple:
                        des = Description(i, vector_dic[i], j, k)
                        l(des)
                    print()
                if l == self.Convert_TO_PyArray_TYPE:
                    print("};")
                print()
            print()

if __name__ == '__main__':
    w = WriteConversion()
    # w('test')
    w('convert_block_description.h')
