#ifndef _PyGSL_SWIG_INIT_H_
#define _PyGSL_SWIG_INIT_H_ 1


#if SWIG_VERSION >= 0x040400 // SWIG >= 4.4.0
#define swig_init_pygsl() init_pygsl1(-1)
#define swig_import_pygsl_rng() import_pygsl_rng1(-1)
#define swig_init_test_fail() do{ return -1; }while(0)
#else
#define swig_init_pygsl() init_pygsl()
#define swig_import_pygsl_rng() import_pygsl_rng()
#define swig_init_test_fail() do{ return NULL; }while(0)
#endif

#endif /**/
