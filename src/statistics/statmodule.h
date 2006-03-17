#ifndef PYGSL_STATMODULE_H
#define PYGSL_STATMODULE_H 1

#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>
#include <gsl/gsl_statistics.h>
#include <Python.h>

/*
 * This api will be only exported to the various  statistics
 * modules.
 */
static void **PyGSL_STATISTICS_API = NULL;



#define PyGSL_STATISTICS_d_A_NUM    0
#define PyGSL_STATISTICS_l_A_NUM    1 
#define PyGSL_STATISTICS_d_Ad_NUM   2
#define PyGSL_STATISTICS_d_AA_NUM   3 
#define PyGSL_STATISTICS_d_AAd_NUM  4
#define PyGSL_STATISTICS_d_AAdd_NUM 5
#define PyGSL_STATISTICS_d_Add_NUM  6
#define PyGSL_STATISTICS_ll_A_NUM   7





#define PyGSL_STATISTICS_d_A_PROTO  (PyObject *self, PyObject *args, \
		     double (*pointer)(const void *, size_t, size_t),\
		     int array_type, int basis_type_size) 

#define PyGSL_STATISTICS_l_A_PROTO   (PyObject *self, PyObject *args, \
		      size_t (*pointer)(const void *, size_t, size_t), \
		      int array_type, int basis_type_size)

#define PyGSL_STATISTICS_d_Ad_PROTO  (PyObject *self, PyObject *args, \
		       double (*pointer)(const void *, size_t, size_t, double), \
		       int array_type, int basis_type_size)

#define PyGSL_STATISTICS_d_AA_PROTO  (PyObject *self, PyObject *args, \
		      double (*pointer)(const void  *, size_t,const void *, size_t, size_t), \
		      int array_type, int basis_type_size)

#define PyGSL_STATISTICS_d_AAd_PROTO (PyObject *self, PyObject *args, \
		       double (*pointer)(const void *, size_t,const void *, size_t, size_t, double), \
		       int array_type, int basis_type_size)


#define PyGSL_STATISTICS_d_AAdd_PROTO (PyObject *self, PyObject *args, \
			double (*pointer)(const void *, size_t,const void *, size_t, size_t, double, double), \
			int array_type, int basis_type_size)

#define PyGSL_STATISTICS_d_Add_PROTO (PyObject *self, PyObject *args, \
		       double (*pointer)(const void *, size_t, size_t, double, double), \
		       int array_type, int basis_type_size)

#define PyGSL_STATISTICS_ll_A_PROTO  (PyObject *self, PyObject *args, \
		      void (*pointer)(size_t *, size_t *, const void *, size_t, size_t), \
		      int array_type, int basis_type_size)


#if defined(PyGSL_STATISTICS_IMPORT_API)                   
extern PyObject *  PyGSL_statistics_d_A    PyGSL_STATISTICS_d_A_PROTO;
extern PyObject *  PyGSL_statistics_l_A    PyGSL_STATISTICS_l_A_PROTO;
extern PyObject *  PyGSL_statistics_d_Ad   PyGSL_STATISTICS_d_Ad_PROTO;  
extern PyObject *  PyGSL_statistics_d_AA   PyGSL_STATISTICS_d_AA_PROTO;  
extern PyObject *  PyGSL_statistics_d_AAd  PyGSL_STATISTICS_d_AAd_PROTO; 
extern PyObject *  PyGSL_statistics_d_AAdd PyGSL_STATISTICS_d_AAdd_PROTO;
extern PyObject *  PyGSL_statistics_d_Add  PyGSL_STATISTICS_d_Add_PROTO; 
extern PyObject *  PyGSL_statistics_ll_A   PyGSL_STATISTICS_ll_A_PROTO;  

#define PyGSL_statistics_d_A    (*(PyObject* (*) PyGSL_STATISTICS_d_A_PROTO)    PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_A_NUM])
#define PyGSL_statistics_l_A    (*(PyObject* (*) PyGSL_STATISTICS_l_A_PROTO)    PyGSL_STATISTICS_API[PyGSL_STATISTICS_l_A_NUM])
#define PyGSL_statistics_d_Ad   (*(PyObject* (*) PyGSL_STATISTICS_d_Ad_PROTO)   PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_Ad_NUM])
#define PyGSL_statistics_d_AA   (*(PyObject* (*) PyGSL_STATISTICS_d_AA_PROTO)   PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_AA_NUM])
#define PyGSL_statistics_d_AAd  (*(PyObject* (*) PyGSL_STATISTICS_d_AAd_PROTO)  PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_AAd_NUM])
#define PyGSL_statistics_d_AAdd (*(PyObject* (*) PyGSL_STATISTICS_d_AAdd_PROTO) PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_AAdd_NUM])
#define PyGSL_statistics_d_Add  (*(PyObject* (*) PyGSL_STATISTICS_d_Add_PROTO)  PyGSL_STATISTICS_API[PyGSL_STATISTICS_d_Add_NUM])
#define PyGSL_statistics_ll_A   (*(PyObject* (*) PyGSL_STATISTICS_ll_A_PROTO)   PyGSL_STATISTICS_API[PyGSL_STATISTICS_ll_A_NUM])

#else 
static PyObject *  PyGSL_statistics_d_A    PyGSL_STATISTICS_d_A_PROTO;
static PyObject *  PyGSL_statistics_l_A    PyGSL_STATISTICS_l_A_PROTO;
static PyObject *  PyGSL_statistics_d_Ad   PyGSL_STATISTICS_d_Ad_PROTO;  
static PyObject *  PyGSL_statistics_d_AA   PyGSL_STATISTICS_d_AA_PROTO;  
static PyObject *  PyGSL_statistics_d_AAd  PyGSL_STATISTICS_d_AAd_PROTO; 
static PyObject *  PyGSL_statistics_d_AAdd PyGSL_STATISTICS_d_AAdd_PROTO;
static PyObject *  PyGSL_statistics_d_Add  PyGSL_STATISTICS_d_Add_PROTO; 
static PyObject *  PyGSL_statistics_ll_A   PyGSL_STATISTICS_ll_A_PROTO;  

#endif 
#define import_pygsl_stats() \
{ \
   PyObject *pygsl = NULL, *c_api = NULL, *md = NULL; \
   if ( \
      (pygsl = PyImport_ImportModule("pygsl.statistics._stat"))   != NULL && \
      (md = PyModule_GetDict(pygsl))                              != NULL && \
      (c_api = PyDict_GetItemString(md, "_PYGSL_STATISTICS_API")) != NULL && \
      (PyCObject_Check(c_api))                                        \
     ) { \
	 PyGSL_STATISTICS_API = (void **)PyCObject_AsVoidPtr(c_api); \
   } else { \
        fprintf(stderr, "Could not init pygsl.statistics._stat!\n"); \
        PyGSL_STATISTICS_API = NULL; \
   } \
   DEBUG_MESS(2, "PyGSL_API points to %p and PyGSL_STATISTICS_API points to %p\n", (void *) PyGSL_API, (void *) PyGSL_STATISTICS_API);  \
}

#endif /* PYGSL_STATMODULE_H */
