# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import __block

def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name) or (name == "thisown"):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types



gsl_vector_set_zero = __block.gsl_vector_set_zero

gsl_vector_set_all = __block.gsl_vector_set_all

gsl_vector_set_basis = __block.gsl_vector_set_basis

gsl_vector_fread = __block.gsl_vector_fread

gsl_vector_fwrite = __block.gsl_vector_fwrite

gsl_vector_fscanf = __block.gsl_vector_fscanf

gsl_vector_fprintf = __block.gsl_vector_fprintf

gsl_vector_reverse = __block.gsl_vector_reverse

gsl_vector_swap = __block.gsl_vector_swap

gsl_vector_swap_elements = __block.gsl_vector_swap_elements

gsl_vector_max = __block.gsl_vector_max

gsl_vector_min = __block.gsl_vector_min

gsl_vector_minmax = __block.gsl_vector_minmax

gsl_vector_max_index = __block.gsl_vector_max_index

gsl_vector_min_index = __block.gsl_vector_min_index

gsl_vector_minmax_index = __block.gsl_vector_minmax_index

gsl_vector_isnull = __block.gsl_vector_isnull

gsl_matrix_set_zero = __block.gsl_matrix_set_zero

gsl_matrix_set_all = __block.gsl_matrix_set_all

gsl_matrix_set_identity = __block.gsl_matrix_set_identity

gsl_matrix_fread = __block.gsl_matrix_fread

gsl_matrix_fwrite = __block.gsl_matrix_fwrite

gsl_matrix_fscanf = __block.gsl_matrix_fscanf

gsl_matrix_fprintf = __block.gsl_matrix_fprintf

gsl_matrix_swap = __block.gsl_matrix_swap

gsl_matrix_swap_rows = __block.gsl_matrix_swap_rows

gsl_matrix_swap_columns = __block.gsl_matrix_swap_columns

gsl_matrix_swap_rowcol = __block.gsl_matrix_swap_rowcol

gsl_matrix_transpose = __block.gsl_matrix_transpose

gsl_matrix_max = __block.gsl_matrix_max

gsl_matrix_min = __block.gsl_matrix_min

gsl_matrix_minmax = __block.gsl_matrix_minmax

gsl_matrix_max_index = __block.gsl_matrix_max_index

gsl_matrix_min_index = __block.gsl_matrix_min_index

gsl_matrix_minmax_index = __block.gsl_matrix_minmax_index

gsl_matrix_isnull = __block.gsl_matrix_isnull

gsl_matrix_diagonal = __block.gsl_matrix_diagonal

gsl_matrix_subdiagonal = __block.gsl_matrix_subdiagonal

gsl_matrix_superdiagonal = __block.gsl_matrix_superdiagonal

gsl_vector_float_set_zero = __block.gsl_vector_float_set_zero

gsl_vector_float_set_all = __block.gsl_vector_float_set_all

gsl_vector_float_set_basis = __block.gsl_vector_float_set_basis

gsl_vector_float_fread = __block.gsl_vector_float_fread

gsl_vector_float_fwrite = __block.gsl_vector_float_fwrite

gsl_vector_float_fscanf = __block.gsl_vector_float_fscanf

gsl_vector_float_fprintf = __block.gsl_vector_float_fprintf

gsl_vector_float_reverse = __block.gsl_vector_float_reverse

gsl_vector_float_swap = __block.gsl_vector_float_swap

gsl_vector_float_swap_elements = __block.gsl_vector_float_swap_elements

gsl_vector_float_max = __block.gsl_vector_float_max

gsl_vector_float_min = __block.gsl_vector_float_min

gsl_vector_float_minmax = __block.gsl_vector_float_minmax

gsl_vector_float_max_index = __block.gsl_vector_float_max_index

gsl_vector_float_min_index = __block.gsl_vector_float_min_index

gsl_vector_float_minmax_index = __block.gsl_vector_float_minmax_index

gsl_vector_float_isnull = __block.gsl_vector_float_isnull

gsl_matrix_float_set_zero = __block.gsl_matrix_float_set_zero

gsl_matrix_float_set_all = __block.gsl_matrix_float_set_all

gsl_matrix_float_set_identity = __block.gsl_matrix_float_set_identity

gsl_matrix_float_fread = __block.gsl_matrix_float_fread

gsl_matrix_float_fwrite = __block.gsl_matrix_float_fwrite

gsl_matrix_float_fscanf = __block.gsl_matrix_float_fscanf

gsl_matrix_float_fprintf = __block.gsl_matrix_float_fprintf

gsl_matrix_float_swap = __block.gsl_matrix_float_swap

gsl_matrix_float_swap_rows = __block.gsl_matrix_float_swap_rows

gsl_matrix_float_swap_columns = __block.gsl_matrix_float_swap_columns

gsl_matrix_float_swap_rowcol = __block.gsl_matrix_float_swap_rowcol

gsl_matrix_float_transpose = __block.gsl_matrix_float_transpose

gsl_matrix_float_max = __block.gsl_matrix_float_max

gsl_matrix_float_min = __block.gsl_matrix_float_min

gsl_matrix_float_minmax = __block.gsl_matrix_float_minmax

gsl_matrix_float_max_index = __block.gsl_matrix_float_max_index

gsl_matrix_float_min_index = __block.gsl_matrix_float_min_index

gsl_matrix_float_minmax_index = __block.gsl_matrix_float_minmax_index

gsl_matrix_float_isnull = __block.gsl_matrix_float_isnull

gsl_matrix_float_diagonal = __block.gsl_matrix_float_diagonal

gsl_matrix_float_subdiagonal = __block.gsl_matrix_float_subdiagonal

gsl_matrix_float_superdiagonal = __block.gsl_matrix_float_superdiagonal

gsl_vector_long_set_zero = __block.gsl_vector_long_set_zero

gsl_vector_long_set_all = __block.gsl_vector_long_set_all

gsl_vector_long_set_basis = __block.gsl_vector_long_set_basis

gsl_vector_long_fread = __block.gsl_vector_long_fread

gsl_vector_long_fwrite = __block.gsl_vector_long_fwrite

gsl_vector_long_fscanf = __block.gsl_vector_long_fscanf

gsl_vector_long_fprintf = __block.gsl_vector_long_fprintf

gsl_vector_long_reverse = __block.gsl_vector_long_reverse

gsl_vector_long_swap = __block.gsl_vector_long_swap

gsl_vector_long_swap_elements = __block.gsl_vector_long_swap_elements

gsl_vector_long_max = __block.gsl_vector_long_max

gsl_vector_long_min = __block.gsl_vector_long_min

gsl_vector_long_minmax = __block.gsl_vector_long_minmax

gsl_vector_long_max_index = __block.gsl_vector_long_max_index

gsl_vector_long_min_index = __block.gsl_vector_long_min_index

gsl_vector_long_minmax_index = __block.gsl_vector_long_minmax_index

gsl_vector_long_isnull = __block.gsl_vector_long_isnull

gsl_matrix_long_set_zero = __block.gsl_matrix_long_set_zero

gsl_matrix_long_set_all = __block.gsl_matrix_long_set_all

gsl_matrix_long_set_identity = __block.gsl_matrix_long_set_identity

gsl_matrix_long_fread = __block.gsl_matrix_long_fread

gsl_matrix_long_fwrite = __block.gsl_matrix_long_fwrite

gsl_matrix_long_fscanf = __block.gsl_matrix_long_fscanf

gsl_matrix_long_fprintf = __block.gsl_matrix_long_fprintf

gsl_matrix_long_swap = __block.gsl_matrix_long_swap

gsl_matrix_long_swap_rows = __block.gsl_matrix_long_swap_rows

gsl_matrix_long_swap_columns = __block.gsl_matrix_long_swap_columns

gsl_matrix_long_swap_rowcol = __block.gsl_matrix_long_swap_rowcol

gsl_matrix_long_transpose = __block.gsl_matrix_long_transpose

gsl_matrix_long_max = __block.gsl_matrix_long_max

gsl_matrix_long_min = __block.gsl_matrix_long_min

gsl_matrix_long_minmax = __block.gsl_matrix_long_minmax

gsl_matrix_long_max_index = __block.gsl_matrix_long_max_index

gsl_matrix_long_min_index = __block.gsl_matrix_long_min_index

gsl_matrix_long_minmax_index = __block.gsl_matrix_long_minmax_index

gsl_matrix_long_isnull = __block.gsl_matrix_long_isnull

gsl_matrix_long_diagonal = __block.gsl_matrix_long_diagonal

gsl_matrix_long_subdiagonal = __block.gsl_matrix_long_subdiagonal

gsl_matrix_long_superdiagonal = __block.gsl_matrix_long_superdiagonal

gsl_vector_int_set_zero = __block.gsl_vector_int_set_zero

gsl_vector_int_set_all = __block.gsl_vector_int_set_all

gsl_vector_int_set_basis = __block.gsl_vector_int_set_basis

gsl_vector_int_fread = __block.gsl_vector_int_fread

gsl_vector_int_fwrite = __block.gsl_vector_int_fwrite

gsl_vector_int_fscanf = __block.gsl_vector_int_fscanf

gsl_vector_int_fprintf = __block.gsl_vector_int_fprintf

gsl_vector_int_reverse = __block.gsl_vector_int_reverse

gsl_vector_int_swap = __block.gsl_vector_int_swap

gsl_vector_int_swap_elements = __block.gsl_vector_int_swap_elements

gsl_vector_int_max = __block.gsl_vector_int_max

gsl_vector_int_min = __block.gsl_vector_int_min

gsl_vector_int_minmax = __block.gsl_vector_int_minmax

gsl_vector_int_max_index = __block.gsl_vector_int_max_index

gsl_vector_int_min_index = __block.gsl_vector_int_min_index

gsl_vector_int_minmax_index = __block.gsl_vector_int_minmax_index

gsl_vector_int_isnull = __block.gsl_vector_int_isnull

gsl_matrix_int_set_zero = __block.gsl_matrix_int_set_zero

gsl_matrix_int_set_all = __block.gsl_matrix_int_set_all

gsl_matrix_int_set_identity = __block.gsl_matrix_int_set_identity

gsl_matrix_int_fread = __block.gsl_matrix_int_fread

gsl_matrix_int_fwrite = __block.gsl_matrix_int_fwrite

gsl_matrix_int_fscanf = __block.gsl_matrix_int_fscanf

gsl_matrix_int_fprintf = __block.gsl_matrix_int_fprintf

gsl_matrix_int_swap = __block.gsl_matrix_int_swap

gsl_matrix_int_swap_rows = __block.gsl_matrix_int_swap_rows

gsl_matrix_int_swap_columns = __block.gsl_matrix_int_swap_columns

gsl_matrix_int_swap_rowcol = __block.gsl_matrix_int_swap_rowcol

gsl_matrix_int_transpose = __block.gsl_matrix_int_transpose

gsl_matrix_int_max = __block.gsl_matrix_int_max

gsl_matrix_int_min = __block.gsl_matrix_int_min

gsl_matrix_int_minmax = __block.gsl_matrix_int_minmax

gsl_matrix_int_max_index = __block.gsl_matrix_int_max_index

gsl_matrix_int_min_index = __block.gsl_matrix_int_min_index

gsl_matrix_int_minmax_index = __block.gsl_matrix_int_minmax_index

gsl_matrix_int_isnull = __block.gsl_matrix_int_isnull

gsl_matrix_int_diagonal = __block.gsl_matrix_int_diagonal

gsl_matrix_int_subdiagonal = __block.gsl_matrix_int_subdiagonal

gsl_matrix_int_superdiagonal = __block.gsl_matrix_int_superdiagonal

gsl_vector_short_set_zero = __block.gsl_vector_short_set_zero

gsl_vector_short_set_all = __block.gsl_vector_short_set_all

gsl_vector_short_set_basis = __block.gsl_vector_short_set_basis

gsl_vector_short_fread = __block.gsl_vector_short_fread

gsl_vector_short_fwrite = __block.gsl_vector_short_fwrite

gsl_vector_short_fscanf = __block.gsl_vector_short_fscanf

gsl_vector_short_fprintf = __block.gsl_vector_short_fprintf

gsl_vector_short_reverse = __block.gsl_vector_short_reverse

gsl_vector_short_swap = __block.gsl_vector_short_swap

gsl_vector_short_swap_elements = __block.gsl_vector_short_swap_elements

gsl_vector_short_max = __block.gsl_vector_short_max

gsl_vector_short_min = __block.gsl_vector_short_min

gsl_vector_short_minmax = __block.gsl_vector_short_minmax

gsl_vector_short_max_index = __block.gsl_vector_short_max_index

gsl_vector_short_min_index = __block.gsl_vector_short_min_index

gsl_vector_short_minmax_index = __block.gsl_vector_short_minmax_index

gsl_vector_short_isnull = __block.gsl_vector_short_isnull

gsl_matrix_short_set_zero = __block.gsl_matrix_short_set_zero

gsl_matrix_short_set_all = __block.gsl_matrix_short_set_all

gsl_matrix_short_set_identity = __block.gsl_matrix_short_set_identity

gsl_matrix_short_fread = __block.gsl_matrix_short_fread

gsl_matrix_short_fwrite = __block.gsl_matrix_short_fwrite

gsl_matrix_short_fscanf = __block.gsl_matrix_short_fscanf

gsl_matrix_short_fprintf = __block.gsl_matrix_short_fprintf

gsl_matrix_short_swap = __block.gsl_matrix_short_swap

gsl_matrix_short_swap_rows = __block.gsl_matrix_short_swap_rows

gsl_matrix_short_swap_columns = __block.gsl_matrix_short_swap_columns

gsl_matrix_short_swap_rowcol = __block.gsl_matrix_short_swap_rowcol

gsl_matrix_short_transpose = __block.gsl_matrix_short_transpose

gsl_matrix_short_max = __block.gsl_matrix_short_max

gsl_matrix_short_min = __block.gsl_matrix_short_min

gsl_matrix_short_minmax = __block.gsl_matrix_short_minmax

gsl_matrix_short_max_index = __block.gsl_matrix_short_max_index

gsl_matrix_short_min_index = __block.gsl_matrix_short_min_index

gsl_matrix_short_minmax_index = __block.gsl_matrix_short_minmax_index

gsl_matrix_short_isnull = __block.gsl_matrix_short_isnull

gsl_matrix_short_diagonal = __block.gsl_matrix_short_diagonal

gsl_matrix_short_subdiagonal = __block.gsl_matrix_short_subdiagonal

gsl_matrix_short_superdiagonal = __block.gsl_matrix_short_superdiagonal

gsl_vector_char_set_zero = __block.gsl_vector_char_set_zero

gsl_vector_char_set_all = __block.gsl_vector_char_set_all

gsl_vector_char_set_basis = __block.gsl_vector_char_set_basis

gsl_vector_char_fread = __block.gsl_vector_char_fread

gsl_vector_char_fwrite = __block.gsl_vector_char_fwrite

gsl_vector_char_fscanf = __block.gsl_vector_char_fscanf

gsl_vector_char_fprintf = __block.gsl_vector_char_fprintf

gsl_vector_char_reverse = __block.gsl_vector_char_reverse

gsl_vector_char_swap = __block.gsl_vector_char_swap

gsl_vector_char_swap_elements = __block.gsl_vector_char_swap_elements

gsl_vector_char_max = __block.gsl_vector_char_max

gsl_vector_char_min = __block.gsl_vector_char_min

gsl_vector_char_minmax = __block.gsl_vector_char_minmax

gsl_vector_char_max_index = __block.gsl_vector_char_max_index

gsl_vector_char_min_index = __block.gsl_vector_char_min_index

gsl_vector_char_minmax_index = __block.gsl_vector_char_minmax_index

gsl_vector_char_isnull = __block.gsl_vector_char_isnull

gsl_matrix_char_set_zero = __block.gsl_matrix_char_set_zero

gsl_matrix_char_set_all = __block.gsl_matrix_char_set_all

gsl_matrix_char_set_identity = __block.gsl_matrix_char_set_identity

gsl_matrix_char_fread = __block.gsl_matrix_char_fread

gsl_matrix_char_fwrite = __block.gsl_matrix_char_fwrite

gsl_matrix_char_fscanf = __block.gsl_matrix_char_fscanf

gsl_matrix_char_fprintf = __block.gsl_matrix_char_fprintf

gsl_matrix_char_swap = __block.gsl_matrix_char_swap

gsl_matrix_char_swap_rows = __block.gsl_matrix_char_swap_rows

gsl_matrix_char_swap_columns = __block.gsl_matrix_char_swap_columns

gsl_matrix_char_swap_rowcol = __block.gsl_matrix_char_swap_rowcol

gsl_matrix_char_transpose = __block.gsl_matrix_char_transpose

gsl_matrix_char_max = __block.gsl_matrix_char_max

gsl_matrix_char_min = __block.gsl_matrix_char_min

gsl_matrix_char_minmax = __block.gsl_matrix_char_minmax

gsl_matrix_char_max_index = __block.gsl_matrix_char_max_index

gsl_matrix_char_min_index = __block.gsl_matrix_char_min_index

gsl_matrix_char_minmax_index = __block.gsl_matrix_char_minmax_index

gsl_matrix_char_isnull = __block.gsl_matrix_char_isnull

gsl_matrix_char_diagonal = __block.gsl_matrix_char_diagonal

gsl_matrix_char_subdiagonal = __block.gsl_matrix_char_subdiagonal

gsl_matrix_char_superdiagonal = __block.gsl_matrix_char_superdiagonal

gsl_vector_complex_set_zero = __block.gsl_vector_complex_set_zero

gsl_vector_complex_set_all = __block.gsl_vector_complex_set_all

gsl_vector_complex_set_basis = __block.gsl_vector_complex_set_basis

gsl_vector_complex_fread = __block.gsl_vector_complex_fread

gsl_vector_complex_fwrite = __block.gsl_vector_complex_fwrite

gsl_vector_complex_fscanf = __block.gsl_vector_complex_fscanf

gsl_vector_complex_fprintf = __block.gsl_vector_complex_fprintf

gsl_vector_complex_reverse = __block.gsl_vector_complex_reverse

gsl_vector_complex_swap = __block.gsl_vector_complex_swap

gsl_vector_complex_swap_elements = __block.gsl_vector_complex_swap_elements

gsl_vector_complex_isnull = __block.gsl_vector_complex_isnull

gsl_matrix_complex_set_zero = __block.gsl_matrix_complex_set_zero

gsl_matrix_complex_set_all = __block.gsl_matrix_complex_set_all

gsl_matrix_complex_set_identity = __block.gsl_matrix_complex_set_identity

gsl_matrix_complex_fread = __block.gsl_matrix_complex_fread

gsl_matrix_complex_fwrite = __block.gsl_matrix_complex_fwrite

gsl_matrix_complex_fscanf = __block.gsl_matrix_complex_fscanf

gsl_matrix_complex_fprintf = __block.gsl_matrix_complex_fprintf

gsl_matrix_complex_swap = __block.gsl_matrix_complex_swap

gsl_matrix_complex_swap_rows = __block.gsl_matrix_complex_swap_rows

gsl_matrix_complex_swap_columns = __block.gsl_matrix_complex_swap_columns

gsl_matrix_complex_swap_rowcol = __block.gsl_matrix_complex_swap_rowcol

gsl_matrix_complex_transpose = __block.gsl_matrix_complex_transpose

gsl_matrix_complex_isnull = __block.gsl_matrix_complex_isnull

gsl_matrix_complex_diagonal = __block.gsl_matrix_complex_diagonal

gsl_matrix_complex_subdiagonal = __block.gsl_matrix_complex_subdiagonal

gsl_matrix_complex_superdiagonal = __block.gsl_matrix_complex_superdiagonal

gsl_vector_complex_float_set_zero = __block.gsl_vector_complex_float_set_zero

gsl_vector_complex_float_set_all = __block.gsl_vector_complex_float_set_all

gsl_vector_complex_float_set_basis = __block.gsl_vector_complex_float_set_basis

gsl_vector_complex_float_fread = __block.gsl_vector_complex_float_fread

gsl_vector_complex_float_fwrite = __block.gsl_vector_complex_float_fwrite

gsl_vector_complex_float_fscanf = __block.gsl_vector_complex_float_fscanf

gsl_vector_complex_float_fprintf = __block.gsl_vector_complex_float_fprintf

gsl_vector_complex_float_reverse = __block.gsl_vector_complex_float_reverse

gsl_vector_complex_float_swap = __block.gsl_vector_complex_float_swap

gsl_vector_complex_float_swap_elements = __block.gsl_vector_complex_float_swap_elements

gsl_vector_complex_float_isnull = __block.gsl_vector_complex_float_isnull

gsl_matrix_complex_float_set_zero = __block.gsl_matrix_complex_float_set_zero

gsl_matrix_complex_float_set_all = __block.gsl_matrix_complex_float_set_all

gsl_matrix_complex_float_set_identity = __block.gsl_matrix_complex_float_set_identity

gsl_matrix_complex_float_fread = __block.gsl_matrix_complex_float_fread

gsl_matrix_complex_float_fwrite = __block.gsl_matrix_complex_float_fwrite

gsl_matrix_complex_float_fscanf = __block.gsl_matrix_complex_float_fscanf

gsl_matrix_complex_float_fprintf = __block.gsl_matrix_complex_float_fprintf

gsl_matrix_complex_float_swap = __block.gsl_matrix_complex_float_swap

gsl_matrix_complex_float_swap_rows = __block.gsl_matrix_complex_float_swap_rows

gsl_matrix_complex_float_swap_columns = __block.gsl_matrix_complex_float_swap_columns

gsl_matrix_complex_float_swap_rowcol = __block.gsl_matrix_complex_float_swap_rowcol

gsl_matrix_complex_float_transpose = __block.gsl_matrix_complex_float_transpose

gsl_matrix_complex_float_isnull = __block.gsl_matrix_complex_float_isnull

gsl_matrix_complex_float_diagonal = __block.gsl_matrix_complex_float_diagonal

gsl_matrix_complex_float_subdiagonal = __block.gsl_matrix_complex_float_subdiagonal

gsl_matrix_complex_float_superdiagonal = __block.gsl_matrix_complex_float_superdiagonal

