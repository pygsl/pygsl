#!/usr/bin/env python
# Author : Pierre Schnizer 
"""
The vector module.

This module provides  mappings to some functions of  gsl vectors as descirebed
in  Chapter  8.3 of  the  gsl reference  document.  All  functions accept  one
dimensional Numeric arrays instead of gsl vectors, or return Numeric arrays.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   Warning: When translating alghorithms from C to Python, check if the
   functions do the same. Inplace change does not need to have effect here,
   some of  these functions make copies internally.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

All  functions from  Section 8.3.3  take  an integer  as input  and return  an
approbriate Numeric array as output. The prefix gsl_vector has been discarded.
These functions are:
     set_zero
     set_all
     set_basis

Functions to read write the vector from a file are provided as well:
    fprintf
    fscanf
    fread
    fwrite

Some basic data operations are provided as well (See Section 8.3.7):
    reverse      
    swap         
    swap_elements

And some functions from Section 8.3.9    
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

class _generic(block._generic_block):
    _base = 'vector'
    def __init__(self):
        block._generic_block.__init__(self)
        self.reverse        = self._get_function('reverse')
        self.swap_elements  = self._get_function('swap_elements')
        self.set_basis      = self._get_function('set_basis')
        
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

complex       = _complex()
complex_float = _complex_float()
float         = _float() 
double        = _double()
long          = _long()
int           = _int()
short         = _short()
char          = _char()

del  _complex
del  _complex_float
del  _float     
del  _double
del  _long            
del  _int             
del  _short
del  _char            

set_zero      = double.set_zero      
set_all       = double.set_all       
set_basis     = double.set_basis     
reverse       = double.reverse       
swap          = double.swap          
swap_elements = double.swap_elements 
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

