#ifndef _PYGSL_ERRNO_H_
#define _PYGSL_ERRNO_H_ 1
/*
 * PyGSL needs also to flag errors which do not match to one of the errors of
 * GSL.
 */
enum{
     PyGSL_ESTRIDE = 64, /* 
			  *  Can not convert the stride from a Python array
			  *  object to a GSL Vector/Matrix stride 
			  */
};
#endif/*  _PYGSL_ERRNO_H_ */
