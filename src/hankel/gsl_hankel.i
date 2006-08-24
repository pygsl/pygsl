/* -*- C -*- */
%module hankel;
%{
#include <gsl/gsl_dht.h>
#include <pygsl/block_helpers.h>
%}

%feature("test") {
     {
	  /*test feature*/
	  $action
     } 
    {
	 /*handling ?*/
	 fprintf(stderr, "Handling feature!");
    }
}


%init {
  init_pygsl();
}
typedef unsigned int size_t;

%include typemaps.i
%include gsl_error_typemap.i
%typemap (out) int = gsl_error_flag_drop;



%rename(DiscreteHankelTransform) gsl_dht_struct;

struct gsl_dht_struct
{
     %immutable;     
/*  size_t n;
  size_t k;
  size_t *data; */
};

%extend gsl_dht_struct{
  %rename(__getitem__) get_item;
  gsl_dht_struct(const size_t n) {
    return gsl_dht_alloc(n);
  }

  ~gsl_dht_struct() {
    gsl_dht_free(self);
  }

  int init(double nu, double xmax){
       return gsl_dht_init(self, nu, xmax);
  }

  double x_sample(int n){
       return gsl_dht_x_sample(self, n); 
  }

  double k_sample(int n){
       return gsl_dht_k_sample(self, n); 
  }

  size_t get_size(){
       return self->size;
  }
  
  PyObject * apply(PyObject *in){
       PyArrayObject *a_in = NULL, *a_out = NULL;
       PyObject *resultobj = NULL, *returnobj = NULL;
       PyGSL_array_index_t size = -1;
       int result;

       size = (int) self->size;

       a_in = PyGSL_vector_check(in, size, PyGSL_DARRAY_CINPUT(1), NULL, NULL);
       if (a_in == NULL)        
	    goto fail;

       a_out = (PyArrayObject *) PyGSL_New_Array(1, &size, PyArray_DOUBLE);
       if (a_out == NULL)
	    goto fail;
       

       result = gsl_dht_apply(self, (double *)a_in->data, (double *)a_out->data);
       Py_DECREF(a_in);
       a_in = NULL;

       resultobj = PyGSL_ERROR_FLAG_TO_PYINT(result);
       if (resultobj == NULL) 
	    goto fail;
       
       returnobj = PyTuple_New(2);
       if (returnobj == NULL)
	    goto fail;

       PyTuple_SetItem(returnobj, 0,  resultobj);
       PyTuple_SetItem(returnobj, 1, (PyObject *) a_out);

       return returnobj;

  fail:
       Py_XDECREF(a_in);
       Py_XDECREF(a_out);
       Py_XDECREF(resultobj);
       Py_XDECREF(returnobj);
       return NULL;
  }
};

