#!/usr/bin/env python
# Author : Pierre Schnizer 
import _block

class _generic:    
    """
    Generic block class. Handles common operation.
    """
    # Defines what basis type this class handles. To be defined in a derived
    # class. e.g. base = 'vector'
    _base = None
    def _get_function(self, suffix):
        """
        translate some prefix to the full qualified name of the block
        """
        if self._type == '':
            tmp = '_'
        else:
            tmp = '_' + self._type + '_'
        # base is matrix or vector or .....
        assert self._base != None, 'Use a derived class!'
        base =  self._base
        function = eval('_block.gsl_' + base + tmp + suffix)        
        return function

    def __init__(self):
        self._fread         = self._get_function('fread')
        self._fwrite        = self._get_function('fwrite')
        self._fscanf        = self._get_function('fscanf')
        self._fprintf       = self._get_function('fprintf')


    def fread(self, *args):
        """
        reads a binary stream of the vector from an open file.
        input:  file, size of the vector
        output: flag, the vector
        """
        return apply(self._fread, args)

    def fwrite(self, *args):
        """
        writes a binary stream of the vector to an open file.
        input:  file, vector
        output: flag if sucessful
        """
        return apply(self._fwrite  , args)

    def fscanf(self, *args):
        """
        scans the length of the vector from the file.
        input:   file, length of the vector to be read
        output:  flag, the vector
        """
        return apply(self._fscanf  , args)

    def fprintf(self, file, vector, format):
        """
        prints the vector to an open file.
        input: file, vector, format
               file   ... an file open for writing
               vector ... a vector of data
               format ... a "c" type format string. These are similar to the
                          python ones, but differences exist.
        """
        #Some checking if the file type is good ... should go in here.
        return  self._fprintf(file, vector, format)


class _generic_block(_generic):
    """
    Basis functions for vectors and matrices.
    """
    def __init__(self):
        _generic.__init__(self)
        self.set_zero       = self._get_function('set_zero')
        self.set_all        = self._get_function('set_all')
        self.swap           = self._get_function('swap')
        self.isnull         = self._get_function('isnull')
        if(self._type != 'complex' and self._type != 'complex_float'):
            self.max            = self._get_function('max')
            self.min            = self._get_function('min')
            self.minmax         = self._get_function('minmax')
            self.max_index      = self._get_function('max_index')
            self.min_index      = self._get_function('min_index')
            self.minmax_index   = self._get_function('minmax_index')






