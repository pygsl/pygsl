#ifndef PYGSL_BLOCK_HELPERS_NUMARRAY_H
#define PYGSL_BLOCK_HELPERS_NUMARRAY_H 1
#include <pygsl/transition.h>
#ifndef CONTIGUOUS
#define CONTIGUOUS NPY_CONTIGUOUS
#endif

#ifdef PyGSL_PY3K
#define PyGSL_PY_ARRAY_GET_REFCNT(a_tmp_array) ((a_tmp_array)->ob_base.ob_refcnt)
#else /* PyGSL_PY3K */
#define PyGSL_PY_ARRAY_GET_REFCNT(a_tmp_array) ((a_tmp_array)->ob_refcnt)
#endif /* PyGSL_PY3K */


#ifndef _PyGSL_API_MODULE

#endif /* _PyGSL_API_MODULE */

#endif  /* PYGSL_BLOCK_HELPERS_NUMARRAY_H */
