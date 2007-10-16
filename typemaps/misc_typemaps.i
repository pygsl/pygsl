/* -*- C -*- */
/**
 * Author: Pierre Schnizer		
 */
%typemap(arginit) size_t * OUTPUT %{
     size_t _size_t_temp$argnum;
%}
%typemap(in, numinputs=0) size_t * OUTPUT %{
     {
	  _size_t_temp$argnum = 0;
	  $1 = &_size_t_temp$argnum;
     }
%}
%typemap(argout) size_t * OUTPUT{
    PyObject *o;
    o = PyInt_FromLong((long) (*$1));
    $result = SWIG_Python_AppendOutput($result, o);
}
%typemap(in, numinputs=0) size_t * OUT = size_t * OUTPUT;
%typemap(argout) size_t * OUT = size_t * OUTPUT;
