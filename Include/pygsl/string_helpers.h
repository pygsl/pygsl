#ifndef _PYGSL_STRING_HELPERS_H_
#define _PYGSL_STRING_HELPERS_H_ 1
#include <pygsl/intern.h>

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

#define PyGSL_string_from_string PyUnicode_FromString
#define PyGSL_string_check       PyUnicode_Check

char * 
PyGSL_string_as_string(PyObject *);

#ifndef _PyGSL_API_MODULE
/* uses PyBytes_AsString */
#define PyGSL_string_as_string  (*(PyObject (*)(PyObject *)) PyGSL_API[PyGSL_string_as_string_NUM])
#endif  /* _PyGSL_API_MODULE */

__END_DECLS
#endif /* _PYGSL_STRING_HELPERS_H_ */
