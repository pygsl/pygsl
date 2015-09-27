#ifndef PYGSL_UTIL_H
#define PYGSL_UTIL_H
/*
 * Author: Pierre Schnizer <schnizer@users.sourceforge.net>
 *
 * $Id:
 */
#include <pygsl/compilers.h>
#include <pygsl/intern.h>
#include <stdio.h>

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

/* Uncomment the following block to get DEBUG information */
/*
#ifndef DEBUG
#define DEBUG 10
#endif
*/
#define PyGSL_DEBUG_MAX 15
#if DEBUG > 0
#if DEBUG >  PyGSL_DEBUG_MAX 
#error "Do not support a DEBUG level over" PyGSL_DEBUG_MAX 
#endif

#define FUNC_MESS(mess)                                                \
        ((PyGSL_DEBUG_LEVEL()))  ?                                  \
                        fprintf(stderr,                             \
                                "%s %s In File %s at line %d\n",    \
                                mess,                               \
                                __FUNCTION__, __FILE__, __LINE__)   \
       :                                                            \
         0  

#define DEBUG_MESS(level, mess, args...)                                 \
     ((PyGSL_DEBUG_LEVEL()) > level)  ?                              \
fprintf(stderr,                                                      \
	"In Function %s from File %s at line %d "  mess      "\n" ,  \
        __FUNCTION__, __FILE__, __LINE__, args)               \
: \
      0 
#else /* DEBUG > 0 */
#define FUNC_MESS(mess)
#define DEBUG_MESS(level, mess,  args...)
#endif /* DEBUG */

#define FUNC_MESS_BEGIN()  FUNC_MESS("BEGIN ")
#define FUNC_MESS_END()    FUNC_MESS("END   ")
#define FUNC_MESS_FAILED() FUNC_MESS("FAILED")
#ifndef DEBUG
#define DEBUG 0
#endif

__END_DECLS

#endif /* PYGSL_UTIL_H */
