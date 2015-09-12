#ifndef _PyGSL_TRANSITION_H_
#define _PyGSL_TRANSITION_H_ 1


#ifndef PY_MAJOR_VERSION
#error " PY_MAJOR_VERSION" not defined!
#endif  /* PY_MAJOR_VERSION */

#if (PY_MAJOR_VERSION == 3)
#define PyGSL_PY3K 1
#else
/* #error "Now only compiling for python 3.1!" */
#endif /* PY_MAJOR_VERSION == 3 */
#ifndef DL_EXPORT
#define DL_EXPORT(arg) arg
#endif /* DL_EXPORT undefined */


#ifdef PyGSL_PY3K
#else /* PyGSL_PY3K */
#endif /* PyGSL_PY3K */

#endif /* _PyGSL_TRANSITION_H_ */
