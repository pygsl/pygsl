#!/usr/bin/env python
#
#  Author: Pierre Schnizer		
# 

import sys

vector_dic = {
"complex_long_double"  :   ("PyArray_NOTYPE  ","gsl_complex_long_double" ,"long_double" ),
"complex_double"       :   ("PyArray_CDOUBLE ","gsl_complex"             ,"double"      ),
"complex_float"        :   ("PyArray_CFLOAT  ","gsl_complex_float"       ,"float"       ),
"complex"              :   ("PyArray_CDOUBLE ","gsl_complex"             ,"double"      ),
                                                                                                    
"long_double"          :   ("PyArray_NOTYPE  ","long double"             ,"long double" ),
"double"               :   ("PyArray_DOUBLE  ","double"                  ,"double"      ),
"float"                :   ("PyArray_FLOAT   ","float"                   ,"float"       ),
""                      :  ("PyArray_DOUBLE  ","double"                  ,"double"      ),
                                                                                        
"ulong"                :   ("PyArray_NOTYPE  ","ulong"                   ,"ulong"       ),
"long"                 :   ("PyArray_LONG    ","long"                    ,"long"        ),
                                                                                        
"uint"                 :   ("PyArray_NOTYPE  ","uint"                    ,"uint"        ),
"int"                  :   ("PyArray_INT     ","int"                     ,"int"         ),
                                                                                        
"ushort"               :   ("PyArray_NOTYPE  ","ushort"                  ,"ushort"      ),
"short"                :   ("PyArray_SHORT   ","short"                   ,"short"       ),
                                                                                        
"uchar"                :   ("PyArray_NOTYPE  ","uchar"                   ,"uchar"       ),
"char"                 :   ("PyArray_CHAR    ","char"                    ,"char"        ),
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
        print  """/* -*- C -*- */
/* Automatically generated file
 * Do not edit directly.
 * Edit c.py instead!!!
 */
         """
        return
    
    def _footer(self):
        print """
/* EOF */
        """
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
        print "#define TO_PyArray_TYPE_%-35s  %s" % (vec, pya)
        return
    
    def Convert_TO_TYPE_VIEW(self, des):
        """
        provide a define to convert from gsl_vector_ to the approbriate
        gsl_vector_ _view.
        """

        vec = des.gsl_vector()
        vec1 = des.gsl_vector()
        print "#define TYPE_VIEW_%-35s         %s_view" % (vec, vec1) 
        return

    def Convert_TO_TYPE_VIEW_ARRAY(self, des):
        """
        provide a define to convert from gsl_vector_ to the approbriate
        gsl_vector_ _view_array.
        """

        vec = des.gsl_vector()
        vec1 = des.gsl_vector_basis()
        print "#define TYPE_VIEW_ARRAY_%-35s         %s_view_array" % (vec, vec1) 
        return

    def Convert_TO_TYPE_VIEW_ARRAY_STRIDES(self, des):
        """
        provide a define to convert from gsl_vector_ to the approbriate
        gsl_vector_ _view_array_with_strides.
        """

        vec = des.gsl_vector()
        vec1 = des.gsl_vector_basis()
        print "#define TYPE_VIEW_ARRAY_STRIDES_%-35s         %s_view_array_with_stride" % (vec, vec1) 
        return

    def Convert_TO_BASIS_TYPE(self, des):
        vec = des.gsl_vector()
        basis = des.gsl_base_type()
        print "#define BASIS_TYPE_%-35s        %s" % (vec, basis) 
        return

    def Convert_TO_BASIS_TYPE_C(self, des):
        vec = des.gsl_vector()
        basis = des.c_base_type()
        print "#define BASIS_TYPE_C_%-35s        %s" % (vec, basis) 
        return

    def Convert_TO_GET(self, des):
        vec = des.gsl_vector()
        vec1 = des.gsl_vector_basis()
        print "#define GET_%-35s        %s_get" % (vec, vec1) 
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
                for k in ("", "view"):
                    for i in vector_tuple:
                        des = Description(i, vector_dic[i], j, k)
                        l(des)
                    print
                print
            print    
def run():
    for j in ("gsl_vector", "gsl_matrix"):
      #k = ""
      for k in ("", "_view"):
        for i in ('test'):  
            if i == "":
                tmp = j
            else:
                tmp = j+"_"+i            
            print "#define TO_PyArray_TYPE_%-35s  %s" % (tmp+k, vector_dic[i][0])
        print " "
        for i in vector_tuple:
            if i == "":
                tmp = j
            else:
                tmp = j+"_"+i            

            print "#define TYPE_VIEW_%-35s         %s_view" % (tmp+k, tmp) 
        print " "
        for i in vector_tuple:
            if i == "":
                tmp = j
            else:
                tmp = j+"_"+i            
            print "#define TYPE_VIEW_ARRAY_%-35s   %s_view_array" % (tmp+k, tmp)
        print ""    
        for i in vector_tuple:
            if i == "":
                tmp = j
            else:
                tmp = j+"_"+i            
            print "#define TYPE_VIEW_ARRAY_STRIDES_%-35s   %s_view_array_with_stride" % (tmp+k, tmp)
        print ""    
        for i in vector_tuple:
            if i == "":
                tmp = j
            else:
                tmp = j+"_"+i            
            print "#define BASIS_TYPE_%-35s        %s" % (tmp+k, vector_dic[i][1])
        print ""    
        for i in vector_tuple:
            if i == "":
                tmp = j
            else:
                tmp = j+"_"+i            
            print "#define BASIS_TYPE_C_%-35s        %s" % (tmp+k, vector_dic[i][2])
        print ""    
        for i in vector_tuple:
            tmp1 = j
            if tmp1[-5:] == "_view":
                tmp1 = tmp1[:-5]
            if i == "":
                tmp2 = tmp1
                tmp = j
            else:
                tmp2 = tmp1+"_"+i
                tmp  = j + "_" + i
            print "#define GET_%-35s                 %s_get" % (tmp+k, tmp2) 
        print ""      
if __name__ == '__main__':
    w = WriteConversion()
    w('convert_block_description.h')
