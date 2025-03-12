#ifndef PYGSL_TYPEMAPS_PYGSL_COMPAT_I
#define PYGSL_TYPEMAPS_PYGSL_COMPAT_I 1

/*
 * pygsl (allmost) never returns None. None is used for gsl_error_drop
 * thus instead of returning the integer, drop it. This behaviour is
 * given by swig < 4.3.
 *
 * Here I add an hack so that the original behaviour is restored even
 * for swig > 4.3.
 *
 * One has to see how long that hack will be sustainable.
 * The alternative could be to wrap all the functions that return an
 * status inside a void function. Then one still needs to check if in
 * that case an exception would be raised in Python
 */
%{
#ifndef PYGSL_TYPEMAPS_PYGSL_COMPAT_INC
#define PYGSL_TYPEMAPS_PYGSL_COMPAT_INC
#if SWIG_VERSION >= 0x040300
#ifdef SWIG_AppendOutput
#undef SWIG_AppendOutput
#endif
#define SWIG_AppendOutput(res, o) SWIG_Python_AppendOutput(res, o, 1)
/*
 * hack it to get it back to the original behaviour ...
 * need to reconsider if that's a good idea?
 * Do I need 2 macros or is one enough?
 */
#define PyGSL_SWIG_Wrap_Python_AppendOutput(res, o, is_void) SWIG_Python_AppendOutput(res, o, 1)
#define SWIG_Python_AppendOutput(res, o, is_void) PyGSL_SWIG_Wrap_Python_AppendOutput(res, o, is_void)
#endif /* SWIG_VERSION < 0x040300 */
#endif /* PYGSL_TYPEMAPS_PYGSL_COMPAT_INC */
%}

#if SWIG_VERSION < 0x040300
#define PyGSL_SWIG_Python_AppendOutput(res, o) SWIG_Python_AppendOutput(res, o)
#else /* SWIG_VERSION < 0x040300  */
#define PyGSL_SWIG_Python_AppendOutput(res, o) SWIG_Python_AppendOutput(res, o, 1)
#endif /* SWIG_VERSION < 0x040300 */

#endif /* PYGSL_TYPEMAPS_PYGSL_COMPAT_I */
