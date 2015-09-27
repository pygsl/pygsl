#ifndef _PYGSL_ERRNO_H_
#define _PYGSL_ERRNO_H_ 1
/*
 * Author: Pierre Schnizer
 *
 * $Id:
 */
#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

/*
 * PyGSL needs also to flag errors which do not match to one of the errors of
 * GSL.
 */
enum{
     PyGSL_ESTRIDE = 64, /* 
			  *  Can not convert the stride from a Python array
			  *  object to a GSL Vector/Matrix stride 
			  */
     PyGSL_EUNIMPL = 65,
};

__END_DECLS
#endif/*  _PYGSL_ERRNO_H_ */
