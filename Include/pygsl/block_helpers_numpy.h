#ifndef PYGSL_BLOCK_HELPERS_NUMARRAY_H
#define PYGSL_BLOCK_HELPERS_NUMARRAY_H 1
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

#include <pygsl/transition.h>
#ifndef CONTIGUOUS
#define CONTIGUOUS NPY_ARRAY_C_CONTIGUOUS
#endif

#define PyGSL_PY_ARRAY_GET_REFCNT(a_tmp_array) Py_REFCNT(a_tmp_array)


#ifndef _PyGSL_API_MODULE

#endif /* _PyGSL_API_MODULE */
__END_DECLS
#endif  /* PYGSL_BLOCK_HELPERS_NUMARRAY_H */
