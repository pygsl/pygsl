# Author : Pierre Schnizer 
"""
The matrix module.

This module provides  mappings to some functions of  gsl vectors as descirbed
in  Chapter  8. of  the  gsl reference  document.  All  functions accept  one
dimensional Numeric arrays instead of gsl vectors, or return Numeric arrays.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   Warning: When translating alghorithms from C to Python, check if the
   functions do the same. Inplace change does not need to have effect here,
   some of  these functions make copies internally.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

All  functions from  Section 8.  take  an integer  as input  and return  an
approbriate Numeric array as output. The prefix gsl_matrix has been discarded.
These functions are:
     set_zero
     set_all
     set_identity

Functions to read write the matrix from a file are provided as well:
    fprintf
    fscanf
    fread
    fwrite

Some basic data operations are provided as well (See Section 8.):
    diagonal
    subdiagonal
    superdiagonal
    swap
    swap_columns
    swap_rowcol
    swap_rows
    transpose

And some functions from Section 8.
    max          
    min          
    minmax       
    isnull       
    max_index
    min_index
    minmax_index
"""
import _block
import block

# Classes allow derivation, contrary to modules. So I wrap the basic type in a
# generic class here, and use derived classes for the different types of
# arrays. 
class _generic(block._generic_block):
    _base = 'matrix'
    def __init__(self):
        block._generic_block.__init__(self)
        self.diagonal       = self._get_function('diagonal')
        self.subdiagonal    = self._get_function('subdiagonal')
        self.superdiagonal  = self._get_function('superdiagonal')
        self.set_identity   = self._get_function('set_identity')
        self.swap_columns   = self._get_function('swap_columns')
        self.swap_rows      = self._get_function('swap_rows')
        self.swap_rowcol    = self._get_function('swap_rowcol')
        self.transpose      = self._get_function('transpose')
        
class _complex(_generic):
    _type = 'complex'

class _complex_float(_generic):
    _type = 'complex_float'

class _float(_generic):
    _type = 'float'

class _double(_generic):
    _type = ''

class _long(_generic):
    _type = 'long'

class _int(_generic):
    _type = 'int'

class _short(_generic):
    _type = 'short'

class _char(_generic):
    _type = 'char'

# To allow the access vector.complex.set_all() and the like ...
complex       = _complex()
complex_float = _complex_float()
float         = _float() 
double        = _double()
long          = _long()
int           = _int()
short         = _short()
char          = _char()            

# Remove Helpers from the list
del block
del _block
del _generic
del _complex
del _complex_float
del _float     
del _double
del _long            
del _int             
del _short
del _char

# allow to access matrix.double.set_all as matrix.set_all
set_zero      = double.set_zero      
set_all       = double.set_all       
swap          = double.swap          
isnull        = double.isnull        
fread         = double._fread        
fwrite        = double._fwrite       
fscanf        = double._fscanf       
fprintf       = double._fprintf
max           = double.max         
max_index     = double.max_index   
min           = double.min         
min_index     = double.min_index   
minmax        = double.minmax      
minmax_index  = double.minmax_index
diagonal      = double.diagonal     
subdiagonal   = double.subdiagonal  
superdiagonal = double.superdiagonal
set_identity  = double.set_identity 
swap_columns  = double.swap_columns 
swap_rows     = double.swap_rows    
swap_rowcol   = double.swap_rowcol  
transpose     = double.transpose    
