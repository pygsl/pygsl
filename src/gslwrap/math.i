/* -*- C -*- */
/**
 * Author : Fabian Jakobs	
 */
%{
#include <gsl/gsl_math.h>
%}

%ignore gsl_function_struct;
%ignore gsl_function_fdf_struct;
%ignore gsl_function_vec_struct;

#pragma SWIG nowarn=305
%include gsl/gsl_math.h
%include gsl/gsl_nan.h
%include gsl/gsl_sys.h
#pregma SWIG nowarn=+305
