#ifndef PyGSL_COMPILERS_H
#define PyGSL_COMPILERS_H 1

/*
 * Solaris C compiler does not support the __FUNCTION__ macro
 */

#ifdef __SUNPRO_C
#define __FUNCTION__ "Unknown Function"
#endif

#endif /* PyGSL_COMPILERS_H */
