/*
 * Author: Pierre Schnizer <schnizer@users.sourceforge.net>
 *
 * $Id:
 */
#ifndef _PyGSL_TRANSITION_H_
#define _PyGSL_TRANSITION_H_ 1
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

__END_DECLS
#endif /* _PyGSL_TRANSITION_H_ */
