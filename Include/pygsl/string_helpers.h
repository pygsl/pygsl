#ifndef _PYGSL_STRING_HELPERS_H_
#define _PYGSL_STRING_HELPERS_H_ 1
#include <pygsl/intern.h>
#define PyGSL_string_from_string PyUnicode_FromString
#define PyGSL_string_check       PyUnicode_Check

char * 
PyGSL_string_as_string(PyObject *);

#ifndef _PyGSL_API_MODULE
#define PyGSL_string_as_string  (*(PyObject (*)(PyObject *)) PyGSL_API[PyGSL_string_as_string_NUM]);
#endif  /* _PyGSL_API_MODULE */

#endif /* _PYGSL_STRING_HELPERS_H_ */
