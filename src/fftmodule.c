/*
 * Author : Pierre Schnizer
 * Date   : April 2004
 *
 */
#define PyGSL_FFT_USAGE  "\n See module doc string for function call description."
#include <gsl/gsl_fft.h>
#include <gsl/gsl_fft_complex.h>
#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_fft_halfcomplex.h>
              
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>

enum pygsl_fft_space_type{
	COMPLEX_WORKSPACE = 0,
	REAL_WORKSPACE = 1,
	COMPLEX_WAVETABLE = 2,
	REAL_WAVETABLE = 3,
	HALFCOMPLEX_WAVETABLE = 4
};

union pygsl_fft_space_t{
	gsl_fft_complex_workspace     *cws;
	gsl_fft_complex_wavetable     *cwt;
	gsl_fft_real_workspace        *rws;
	gsl_fft_real_wavetable        *rwt;
	gsl_fft_halfcomplex_wavetable *hcwt;
	void                          *v;
};

typedef struct {
	PyObject_HEAD
	union pygsl_fft_space_t space;
	int type;
} PyGSL_fft_space;

static PyObject *module = NULL;
static const char filename[] = __FILE__;

static const char  PyGSL_fft_space_type_doc[] = "\
A catch all of the various space types of the fft module. Call the method\n\
'get_type' to find what object is wrapped underneath!\n\
";
static void
PyGSL_fft_space_dealloc(PyGSL_fft_space * self);

static PyObject*
PyGSL_fft_space_getattr(PyGSL_fft_space * self, char * name);

#define PyGSL_fft_space_check(op) ((op)->ob_type == &PyGSL_fft_space_pytype)
#define PyGSL_complex_fft_work_space_check(op) (PyGSL_fft_space_check(op) && ((PyGSL_fft_space *)op)->type == COMPLEX_WORKSPACE)
#define PyGSL_complex_fft_wave_table_check(op) (PyGSL_fft_space_check(op) && ((PyGSL_fft_space *)op)->type == COMPLEX_WAVETABLE)
#define PyGSL_halfcomplex_fft_wave_table_check(op) (PyGSL_fft_space_check(op) && ((PyGSL_fft_space *)op)->type == HALFCOMPLEX_WAVETABLE)
#define PyGSL_real_fft_work_space_check(op) (PyGSL_fft_space_check(op) && ((PyGSL_fft_space *)op)->type == REAL_WORKSPACE)
#define PyGSL_real_fft_wave_table_check(op) (PyGSL_fft_space_check(op) && ((PyGSL_fft_space *)op)->type == REAL_WAVETABLE)

PyTypeObject PyGSL_fft_space_pytype = {
  PyObject_HEAD_INIT(NULL)	 /* fix up the type slot in initcrng */
  0,				 /* ob_size */
  "PyGSL_fft_space",		 /* tp_name */
  sizeof(PyGSL_fft_space),	 /* tp_basicsize */
  0,				 /* tp_itemsize */

  /* standard methods */
  (destructor)  PyGSL_fft_space_dealloc, /* tp_dealloc  ref-count==0  */
  (printfunc)   0,		         /* tp_print    "print x"     */
  (getattrfunc) PyGSL_fft_space_getattr,  /* tp_getattr  "x.attr"      */
  (setattrfunc) 0,		 /* tp_setattr  "x.attr=v"    */
  (cmpfunc)     0,		   /* tp_compare  "x > y"       */
  (reprfunc)    0,                 /* tp_repr     `x`, print x  */

  /* type categories */
  0,				/* tp_as_number   +,-,*,/,%,&,>>,pow...*/
  0,				/* tp_as_sequence +,[i],[i:j],len, ...*/
  0,				/* tp_as_mapping  [key], len, ...*/

  /* more methods */
  (hashfunc)     0,		/* tp_hash    "dict[x]" */
  (ternaryfunc)  0,      /* tp_call    "x()"     */
  (reprfunc)     0,             /* tp_str     "str(x)"  */
  (getattrofunc) 0,		/* tp_getattro */
  (setattrofunc) 0,		/* tp_setattro */
  0,				/* tp_as_buffer */
  0L,				/* tp_flags */
  (char *) PyGSL_fft_space_type_doc		/* tp_doc */
};

static PyObject *
PyGSL_fft_space_get_factors(PyGSL_fft_space *self, PyGSL_fft_space *args)
{

       int nf, i;                                                           
       long *data=NULL;
       size_t *cp_data=NULL;
       PyArrayObject * a_array = NULL;					    
									    
       assert(PyGSL_fft_space_check(self));

       DEBUG_MESS(2, "Type = %d", self->type);
       switch(self->type){
       case COMPLEX_WAVETABLE:     nf = self->space.cwt ->nf; cp_data = self->space.cwt ->factor; break;
       case REAL_WAVETABLE:	   nf = self->space.rwt ->nf; cp_data = self->space.rwt ->factor; break;
       case HALFCOMPLEX_WAVETABLE: nf = self->space.hcwt->nf; cp_data = self->space.hcwt->factor; break;	       
       default: gsl_error("Got unknown switch", filename, __LINE__, GSL_ESANITY); return NULL; break;
       }

       assert(nf < 64);
       a_array = (PyArrayObject *) PyArray_FromDims(1, &nf, PyArray_LONG);
       if(a_array == NULL)
	       return NULL;
       data = (long *) a_array->data;

       
       for(i=0; i<nf; i++){
	    data[i] = (long) cp_data[i];
       }
       return (PyObject *) a_array;

}
static const char PyGSL_fft_space_get_factors_doc[] = " Get the factors ...";
static const char PyGSL_fft_space_get_type_doc[] = " Get the type of this space";

static PyObject *
PyGSL_fft_space_get_type(PyGSL_fft_space *self, PyObject *notused)
{
	char *p = NULL;

	switch(self->type){
	case COMPLEX_WORKSPACE:     p = "COMPLEX_WORKSPACE";     break;
	case REAL_WORKSPACE:	    p = "REAL_WORKSPACE";	 break;
	case COMPLEX_WAVETABLE:     p = "COMPLEX_WAVETABLE";	 break;
	case REAL_WAVETABLE:	    p = "REAL_WAVETABLE";	 break;
	case HALFCOMPLEX_WAVETABLE: p = "HALFCOMPLEX_WAVETABLE"; break;
	default: gsl_error("Got unknown switch", filename, __LINE__, GSL_ESANITY); return NULL;
	}
	return PyString_FromString(p);
}

static PyMethodDef PyGSL_fft_wavetable_methods[] = {
	{"get_factors",  (PyCFunction)PyGSL_fft_space_get_factors, METH_NOARGS,  (char *)PyGSL_fft_space_get_factors_doc},
	{"get_type",     (PyCFunction)PyGSL_fft_space_get_type, METH_NOARGS,  (char *)PyGSL_fft_space_get_type_doc},
	{NULL, NULL, 0, NULL}           /* sentinel */
};

static PyMethodDef PyGSL_fft_space_methods[] = {
	{"get_type",     (PyCFunction)PyGSL_fft_space_get_type, METH_NOARGS,  (char *)PyGSL_fft_space_get_type_doc},
	{NULL, NULL, 0, NULL}           /* sentinel */
};

static PyObject*
PyGSL_fft_space_getattr(PyGSL_fft_space *self, char *name)
{

     PyObject *tmp = NULL;


     FUNC_MESS_BEGIN();
     assert(PyGSL_fft_space_check(self));     
     if(self->type == COMPLEX_WORKSPACE || self->type == REAL_WORKSPACE){
	     tmp = Py_FindMethod(PyGSL_fft_space_methods, (PyObject *) self, name);
     } else {
	     tmp = Py_FindMethod(PyGSL_fft_wavetable_methods, (PyObject *) self, name);
     }
     FUNC_MESS_END();
     return tmp;
}

static void
PyGSL_fft_space_dealloc(PyGSL_fft_space * self)
{
     FUNC_MESS_BEGIN();
     assert(PyGSL_fft_space_check(self));     
     switch(self->type){
     case COMPLEX_WORKSPACE:     gsl_fft_complex_workspace_free(self->space.cws);      break;
     case COMPLEX_WAVETABLE:     gsl_fft_complex_wavetable_free(self->space.cwt);      break;
     case REAL_WORKSPACE:        gsl_fft_real_workspace_free(self->space.rws);         break;
     case REAL_WAVETABLE:	 gsl_fft_real_wavetable_free(self->space.rwt);         break;
     case HALFCOMPLEX_WAVETABLE: gsl_fft_halfcomplex_wavetable_free(self->space.hcwt); break;
     default: gsl_error("Got unknown switch", filename, __LINE__, GSL_ESANITY); break;
     }
     FUNC_MESS_END();
}

static PyObject* 
PyGSL_fft_space_init(PyObject *self, PyObject *args, int type)
{
	PyGSL_fft_space *o=NULL;
	size_t n;
	o =  (PyGSL_fft_space *) PyObject_NEW(PyGSL_fft_space, &PyGSL_fft_space_pytype);
	if(o == NULL){
		return NULL;
	}

	if (0==PyArg_ParseTuple(args,"l", &n))
		return NULL;


	if (n<=0) {
		PyErr_SetString(PyExc_RuntimeError, "dimension must be >0");
		return NULL;
	}
	o->type = type;
	switch(type){
	case COMPLEX_WORKSPACE:     o->space.cws  = gsl_fft_complex_workspace_alloc(n);     break;
	case COMPLEX_WAVETABLE:     o->space.cwt  = gsl_fft_complex_wavetable_alloc(n);     break;
	case REAL_WORKSPACE:        o->space.rws  = gsl_fft_real_workspace_alloc(n);        break;
	case REAL_WAVETABLE:	    o->space.rwt  = gsl_fft_real_wavetable_alloc(n);        break;
	case HALFCOMPLEX_WAVETABLE: o->space.hcwt = gsl_fft_halfcomplex_wavetable_alloc(n); break;
	default: gsl_error("Got unknown switch", filename, __LINE__, GSL_ESANITY); return NULL; break;
	}
	return (PyObject *) o;
}



#define PyGSL_SPACE_ALLOC(TYPE)                               \
static PyObject *                                             \
PyGSL_fft_space_init_ ## TYPE (PyObject *self, PyObject *args)\
{                                                             \
     return PyGSL_fft_space_init(self, args, TYPE);           \
}                                                             
PyGSL_SPACE_ALLOC(COMPLEX_WORKSPACE)
PyGSL_SPACE_ALLOC(COMPLEX_WAVETABLE)
PyGSL_SPACE_ALLOC(REAL_WORKSPACE)      
PyGSL_SPACE_ALLOC(REAL_WAVETABLE)
PyGSL_SPACE_ALLOC(HALFCOMPLEX_WAVETABLE)


/*
typedef int (complex_transform)(gsl_complex_packed_array
          DATA, size_t STRIDE, size_t N, const
          gsl_fft_complex_wavetable * WAVETABLE,
          gsl_fft_complex_workspace * WORK);
*/
typedef int transform(double * data, size_t stride, size_t N, const void *, void *);

typedef void * pygsl_fft_helpn_t(int);
typedef void * pygsl_fft_help_t(void *);

struct pygsl_fft_help_s {
	pygsl_fft_helpn_t  * space_alloc;
	pygsl_fft_help_t  * space_free;
	pygsl_fft_helpn_t  * table_alloc;
	pygsl_fft_help_t  * table_free;
};
static const struct 
pygsl_fft_help_s complex_helpers = {(pygsl_fft_helpn_t *) gsl_fft_complex_workspace_alloc, 
				    (pygsl_fft_help_t *)  gsl_fft_complex_workspace_free, 
				    (pygsl_fft_helpn_t *) gsl_fft_complex_wavetable_alloc, 
				    (pygsl_fft_help_t *)  gsl_fft_complex_wavetable_free};

static const struct 
pygsl_fft_help_s halfcomplex_helpers = {(pygsl_fft_helpn_t *) gsl_fft_real_workspace_alloc, 
					(pygsl_fft_help_t *)  gsl_fft_real_workspace_free, 
					(pygsl_fft_helpn_t *) gsl_fft_halfcomplex_wavetable_alloc, 
					(pygsl_fft_help_t *)  gsl_fft_halfcomplex_wavetable_free};

static const struct 
pygsl_fft_help_s real_helpers = {(pygsl_fft_helpn_t *) gsl_fft_real_workspace_alloc, 
				 (pygsl_fft_help_t *)  gsl_fft_real_workspace_free, 
				 (pygsl_fft_helpn_t *) gsl_fft_real_wavetable_alloc, 
				 (pygsl_fft_help_t *)  gsl_fft_real_wavetable_free};

static int
PyGSL_copy_complex_real(PyArrayObject *dst, PyArrayObject *src)
{
	int in_type, out_type, i, n=0, n_check;
	double *srcd, *dstd;

	in_type  = src->descr->type_num;
	out_type = dst->descr->type_num;

	if(out_type == PyArray_CDOUBLE && in_type == PyArray_CDOUBLE){
		n = dst->dimensions[0];
		n_check = src->dimensions[0];
		if(n_check != n)
			return GSL_EBADLEN;
		for(i = 0; i < n; i ++){
			DEBUG_MESS(5, "Copying element [%d]", i);
			srcd = (double *)(src->data + src->strides[0] * i);
			dstd = (double *)(dst->data + dst->strides[0] * i);
			dstd[0] = srcd[0];
			dstd[1] = srcd[1];
		}
	} else 	if(out_type == PyArray_DOUBLE && in_type == PyArray_CDOUBLE){
		n = src->dimensions[0];
		n_check = dst->dimensions[0];
		if(n_check != n *2)
			return GSL_EBADLEN;

		for(i = 0; i < n; i ++){
			DEBUG_MESS(5, "Copying element [%d]", i);
			srcd = (double *)(src->data + src->strides[0] * i);
			dstd = (double *)(dst->data + dst->strides[0] * i * 2);
			dstd[0] = srcd[0];
			dstd = (double *)(dst->data + dst->strides[0] * (i*2 + 1));
			dstd[0] = srcd[1];
		}
	} else if(out_type == PyArray_CDOUBLE && in_type == PyArray_DOUBLE){
		n = dst->dimensions[0];
		n_check = src->dimensions[0];
		if(n_check != n *2)
			return GSL_EBADLEN;

		for(i = 0; i < n; i ++){
			DEBUG_MESS(5, "Copying element [%d]", i);
			srcd = (double *)(src->data + src->strides[0] * (i*2));
			dstd = (double *)(dst->data + dst->strides[0] * i);
			dstd[0] = srcd[0];
			srcd = (double *)(dst->data + dst->strides[0] * (i + 1));
			dstd[1] = srcd[0];
		}
	} else
		return GSL_ESANITY;
	return GSL_SUCCESS;
}

/*
 * As described in the GSL Reference Manual.
 * I skip the second half ...
 */
static int
PyGSL_fft_halfcomplex_unpack(PyArrayObject *a)
{

	int i, n, odd_even, last;
	double *data, hc_real, hc_imag;

	FUNC_MESS_BEGIN();

	n = a->dimensions[0] - 1;
	DEBUG_MESS(2, "Unpacking a half complex array of size %d, storage size = %d", 
		   n, a->dimensions[0]);
	
          
	/*
	 * All the arithmetic here will be only possible if the array is
	 * continguous.
	 */
	if(a->strides[0] == sizeof(double) *2)
		;
	else
		GSL_ERROR("Can only unpack continuous halfcomplex arrays!", GSL_ESANITY);

	data = (double *) a->data;
	
	odd_even = n%2;
	last     = n/2 + odd_even;

	/*
	 * The GSL documentation starts at zero. As I am performing this task in place,
	 * I must start from the last element and proceed to the first.
	 */
	/* even length */
	if (!odd_even)
	{
		data[n]     = data[n-1]; 
		data[n + 1] = 0.0;
	}

	/*
	 * Shift all data by one back. GSL saves the space for the one known
	 * array item.
	 */
	DEBUG_MESS(2, "Last = %d", last);
	for (i = last; i > 1; --i)
	{
		
		assert(2*i+1<n);
		hc_real = data[2 * i -1];
		hc_imag = data[2 * i];
		
		data[2 * i]    = hc_real;
		data[2 * i+1]  = hc_imag;
	}

	/* No copy necessary already in place ... */
	a->data[0] = a->data[0];
	/* 
	 *  Set the imaginary part of the nyquist frequency to zero
	 *  moved to the end, not to distrub the copy.
	 */
	a->data[1] = 0.0;
	FUNC_MESS_END();
	return GSL_SUCCESS;

}
/*
 * A catch all of the various type handling routines. Perhaps too much in one function!
 */
static PyObject *
PyGSL_complex_fft_(PyObject *self, PyObject *args, transform * transform, const struct pygsl_fft_help_s *helpers)
{
	PyObject *data = NULL, *s_o= NULL, *t_o = NULL, *ret=NULL;
	PyArrayObject *a = NULL, *r=NULL;
	
	void  *space=NULL;
	void  *table=NULL;
	int strides=0, n=0;
	int free_space = 0, free_table=0, flag, helpers_flag, in_array_type, out_array_type, call_n, return_n;


	FUNC_MESS_BEGIN();



	if(helpers == &complex_helpers){
		in_array_type  = PyArray_CDOUBLE;
		out_array_type = PyArray_CDOUBLE;
		helpers_flag = COMPLEX_WAVETABLE;	
	}else if(helpers == &halfcomplex_helpers){
		in_array_type  = PyArray_CDOUBLE;
		out_array_type = PyArray_DOUBLE;
		helpers_flag = HALFCOMPLEX_WAVETABLE;
	}else if(helpers == &real_helpers){
		in_array_type = PyArray_DOUBLE;
		out_array_type  = PyArray_CDOUBLE;
		helpers_flag = REAL_WAVETABLE;
	}else{
		gsl_error("Unknwon Helper", filename, __LINE__, GSL_ESANITY); return NULL;
	}


	if(! PyArg_ParseTuple(args, "O|OOO", &data, &s_o, &t_o, &ret)){
		return NULL;
	}
	
	a = PyGSL_PyArray_PREPARE_gsl_vector_view(data, in_array_type, 0, -1, 1, NULL);
	if(a == NULL)
		return NULL;
	n = a->dimensions[0];
	call_n = n;
	return_n = n;

	/* I do not handle the case that the Real value is an odd number!!! */
	/* XXX What exactly should be done in that case ? */
	/* As it is now it will ignore the last element!! */
	switch(helpers_flag){
	case HALFCOMPLEX_WAVETABLE:  return_n = n*2, call_n = n*2; break;
	case REAL_WAVETABLE:         return_n = n/2+1; call_n = n;break;
	case COMPLEX_WAVETABLE: break;	
	default: gsl_error("Unknwon Helper", filename, __LINE__, GSL_ESANITY); goto fail;
	}

	/* 
	 *  Return n is used to allocate an array, while call_n is the length passed on.
	 *  This is necessary as the halfcomplex transform needs space to store the nyquist 
	 *  frequency.
	 *
	 *  The following assert is protecting against surprises of missing space.
	 */
	/*
	if(call_n > return_n){
		fprintf(stderr, "In %s at Line %d call_n = %d, return_n = %d",
			filename, __LINE__, call_n, return_n);
		gsl_error("call_n larger than return_n!", filename, __LINE__ - 2, GSL_ESANITY); goto fail;
	}
	*/
	if(s_o){
		switch(helpers_flag){
		case COMPLEX_WAVETABLE:     flag = PyGSL_complex_fft_work_space_check(s_o); break;
		case HALFCOMPLEX_WAVETABLE:
		case REAL_WAVETABLE:        flag = PyGSL_real_fft_work_space_check(s_o); break;
		default: gsl_error("Unknwon Helper", filename, __LINE__, GSL_ESANITY); goto fail;
		}
		if(flag){
			space = ((PyGSL_fft_space * )s_o) ->space.v;
		} else {
			gsl_error("Need a pygsl fft space!", __FILE__, __LINE__, GSL_EINVAL);
			PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 4);
			return NULL;
		}
	}

	if(t_o){
		switch(helpers_flag){
		case COMPLEX_WAVETABLE:     flag = PyGSL_complex_fft_wave_table_check(s_o); break;
		case HALFCOMPLEX_WAVETABLE: flag = PyGSL_halfcomplex_fft_wave_table_check(s_o); break;
		case REAL_WAVETABLE:        flag = PyGSL_real_fft_wave_table_check(s_o); break;
		default: gsl_error("Unknwon Helper", filename, __LINE__, GSL_ESANITY); goto fail;
		}
		if(flag){
			table = ((PyGSL_fft_space * )t_o) ->space.v;
		} else {
			gsl_error("Need a pygsl fft table!", filename, __LINE__, GSL_EINVAL);
			PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 4);
			return NULL;
		}
	}
	
	/* Check for the approbriate type and initialise it!*/
	if(space == NULL || table == NULL){
		/* Store if I need to free these arrays */
		free_space = (space == NULL) ? 1 : 0;
		free_table = (table == NULL) ? 1 : 0;
		if(!space) space = helpers->space_alloc(call_n);
		if(!table) table = helpers->table_alloc(call_n);
	}
	
	/* Check if I got a return array */
	if(ret == NULL || (in_array_type != out_array_type)){
		FUNC_MESS("Generating an output array");
		if(in_array_type == out_array_type){
			r = (PyArrayObject *) PyArray_CopyFromObject((PyObject *) a, in_array_type, 1, 1);
		} else {
			r = (PyArrayObject *) PyArray_FromDims(1, &return_n, out_array_type);			
			if(r == NULL)
				goto fail;
			if(PyGSL_ERROR_FLAG(PyGSL_copy_complex_real(r, a) != GSL_SUCCESS))
				goto fail;			
		}
		if(r == NULL)
			goto fail;
	} else {		
		/* Only possible for complex data ... */
		if ((in_array_type == out_array_type) && (ret == (PyObject *) a)) {
			FUNC_MESS("Input and ouput array identical");
			r = (PyArrayObject *) ret;
			Py_INCREF(r);
		}else{	
			FUNC_MESS("Copying input to output array");
			/* Check if it is an array of the approboriate size */
			if(PyArray_Check((ret)) && ( ((PyArrayObject *) (ret))->nd == 1 ) 
			     && (((PyArrayObject *) (ret))->descr->type_num == (out_array_type)) 
			     && ((PyArrayObject *) (ret))->dimensions[0] == n){
				r = (PyArrayObject *) ret;
			} else {
				/* a message here */
				gsl_error("The return array must be of approbriate size and type!", 
					  filename, __LINE__, GSL_EINVAL);
				goto fail;
			}
			r = (PyArrayObject *) ret;
			DEBUG_MESS(2, "a->strides =%d\t r->strides = %d\n a->n %d, r->n %d", 
				   a->strides[0], r->strides[0], a->dimensions[0], r->dimensions[0]);
			if(PyGSL_ERROR_FLAG(PyGSL_copy_complex_real(r, a) != GSL_SUCCESS))
				goto fail;			
		}
	}
	/*
	  if(PyGSL_STRIDES_RECALC(r->strides[0], sizeof(double)*2, &strides) != GSL_SUCCESS){
	  goto fail;
	  }
	*/
	switch(helpers_flag){
	case COMPLEX_WAVETABLE:     flag = PyGSL_STRIDE_RECALC(r->strides[0], sizeof(double) * 2, &strides); break;
	case HALFCOMPLEX_WAVETABLE: flag = PyGSL_STRIDE_RECALC(r->strides[0], sizeof(double),     &strides); break;
	case REAL_WAVETABLE:        flag = PyGSL_STRIDE_RECALC(r->strides[0], sizeof(double) * 2, &strides); break;
	default: gsl_error("Unknown Helper", filename, __LINE__, GSL_ESANITY); goto fail;
	}
	if(flag != GSL_SUCCESS){
		goto fail;
	}

	DEBUG_MESS(2, "Array is at %p data at %p strides = %d length = %d", (void *) r, (void *) r->data, 
		   r->strides[0], r->dimensions[0]);
	DEBUG_MESS(2, "Starting a transform with an array of a size of %d and a stride of %d", call_n, strides);
	DEBUG_MESS(2, "Wave table size = %d, space size = %d", ((gsl_fft_real_wavetable *) table)->n,
		   ((gsl_fft_real_workspace *) table)->n);
	flag = transform((double *) r->data, strides, call_n, table, space);
	if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
		goto fail;
	}
	/* Rearange data if half complex */
	if(helpers_flag == REAL_WAVETABLE){
		if(PyGSL_fft_halfcomplex_unpack(r) != GSL_SUCCESS)
			goto fail;
	}
	if(free_space == 1 && space != NULL) helpers->space_free(space);
	if(free_table == 1 && table != NULL) helpers->table_free(table);
	Py_DECREF(a);
	FUNC_MESS_END();
	return (PyObject *) r;

  fail:
	FUNC_MESS("Fail");
	Py_XDECREF(a);
	Py_XDECREF(r);
	if(free_space == 1 && space != NULL) helpers->space_free(space);
	if(free_table == 1 && table != NULL) helpers->table_free(table);
	return NULL;
}

/*
 int gsl_fft_real_transform (double DATA[], size_t STRIDE,
          size_t N, const gsl_fft_real_wavetable * WAVETABLE,
          gsl_fft_real_workspace * WORK)
 int gsl_fft_halfcomplex_transform (double DATA[], size_t
          STRIDE, size_t N, const gsl_fft_halfcomplex_wavetable *
          WAVETABLE, gsl_fft_real_workspace * WORK)
*/

#define PyGSL_COMPLEX(direction) \
        static PyObject * \
	PyGSL_complex_fft_ ## direction(PyObject *self, PyObject *args){\
        PyObject *r;\
        FUNC_MESS_BEGIN();\
	r = PyGSL_complex_fft_(self, args, (transform * )gsl_fft_complex_ ## direction, &complex_helpers); \
        FUNC_MESS_END();\
	return r;\
        }

PyGSL_COMPLEX(forward)
PyGSL_COMPLEX(backward)
PyGSL_COMPLEX(inverse)

#define PyGSL_REAL(direction) \
        static PyObject * \
	PyGSL_real_fft_ ## direction(PyObject *self, PyObject *args){\
        PyObject *r;\
        FUNC_MESS_BEGIN();\
	r = PyGSL_complex_fft_(self, args, (transform * )gsl_fft_real_ ## direction, &real_helpers); \
        FUNC_MESS_END();\
	return r;\
        }

PyGSL_REAL(transform)

#define PyGSL_HALFCOMPLEX(direction) \
        static PyObject * \
	PyGSL_halfcomplex_fft_ ## direction(PyObject *self, PyObject *args){\
	return PyGSL_complex_fft_(self, args, (transform * )gsl_fft_halfcomplex_ ## direction, &halfcomplex_helpers); \
        }

PyGSL_HALFCOMPLEX(transform)
PyGSL_HALFCOMPLEX(inverse)

static const char fft_module_doc[] = "\
Wrapper for the FFT Module of the GSL Library\n\
\n\
";
static const char cws_doc[] = "\
Complex Workspace\n\
\n\
Needed as working space for mixed radix routines.\n\
\n\
Input:\n\
    n ... Length of the data to transform\n\
";
static const char cwt_doc[] = "\
Complex Wavetable\n\
\n\
   Stores the precomputed trigonometric functions\n\
Input:\n\
    n ... Length of the data to transform\n\
";
static const char rws_doc[] = "\
Real Workspace\n\
\n\
Needed as working space for mixed radix routines.\n\
\n\
Input:\n\
    n ... Length of the data to transform\n\
";
static const char rwt_doc[] = "\
Real Wavetable\n\
\n\
   Stores the precomputed trigonometric functions\n\
Input:\n\
    n ... Length of the data to transform\n\
";

static const char hcwt_doc[] = "\
Half Complex Wavetable\n\
\n\
   Stores the precomputed trigonometric functions\n\
Input:\n\
    n ... Length of the data to transform\n\
";
#define TRANSFORM_INPUT "\
Input:\n\
      data ... an array with matching length\n\
\n\
Optional Input:\n\
      If these objects are not provided, they will be generated by the\n\
      function automatically.\n\
\n\
      space  ... a workspace of approbriate type and size\n\
      table  ... a wavetable of approbriate type and size\n\
      output ... array to store the output into. GSL computes the FFT\n\
                 in place. So if this array is provided, the wrapper\n\
                 will use this array as output array. If the input and\n\
                 output array are identical no internal copy will be\n\
                 made. \n\
                 XXX This works only for ....\n"

static const char cf_doc[] = "\
Complex forward transform\n\
" TRANSFORM_INPUT;

static const char cb_doc[] = "\
Complex backward transform\n\
\n\
The output is not scaled!\n\
" TRANSFORM_INPUT;

static const char ci_doc[] = "\
Complex inverse transform\n\
\n\
The output is to scale.\n\
" TRANSFORM_INPUT;

static const char rt_doc[] = "\
Real transform\n\
" TRANSFORM_INPUT;

static const char hc_doc[] = "\
Half complex transform\n\
" TRANSFORM_INPUT;

static const char hi_doc[] = "\
Half complex inverse\n\
" TRANSFORM_INPUT;

static PyMethodDef fftMethods[] = {
	{"complex_workspace",     PyGSL_fft_space_init_COMPLEX_WORKSPACE,     METH_VARARGS, (char*)cws_doc},
	{"complex_wavetable",     PyGSL_fft_space_init_COMPLEX_WAVETABLE,     METH_VARARGS, (char*)cwt_doc},
	{"real_workspace",        PyGSL_fft_space_init_REAL_WORKSPACE,        METH_VARARGS, (char*)rws_doc},
	{"real_wavetable",        PyGSL_fft_space_init_REAL_WAVETABLE,        METH_VARARGS, (char*)rwt_doc},
	{"halfcomplex_wavetable", PyGSL_fft_space_init_HALFCOMPLEX_WAVETABLE, METH_VARARGS, (char*)hcwt_doc},
	/*
	{"backward", fft_backward, METH_VARARGS, NULL},	
	*/
	{"complex_forward",  PyGSL_complex_fft_forward,  METH_VARARGS, (char*)cf_doc},	
	{"complex_backward", PyGSL_complex_fft_backward, METH_VARARGS, (char*)cb_doc},	
	{"complex_inverse",  PyGSL_complex_fft_inverse,  METH_VARARGS, (char*)ci_doc},	
	{"real_transform",   PyGSL_real_fft_transform,   METH_VARARGS, (char*)rt_doc},	
	{"halfcomplex_transform", PyGSL_halfcomplex_fft_transform, METH_VARARGS, (char*)hc_doc},
	{"halfcomplex_inverse",   PyGSL_halfcomplex_fft_inverse,   METH_VARARGS, (char*)hi_doc},
	{NULL, NULL} /* Sentinel */
};

DL_EXPORT(void) initfft(void)
{
     	PyObject *m = NULL, *dict = NULL, *item = NULL;
	
	PyGSL_fft_space_pytype.ob_type = &PyType_Type;

	m = Py_InitModule("fft", fftMethods);
	module = m;
	import_array();
	init_pygsl();
	if (m == NULL)
		return;

	dict = PyModule_GetDict(m);
	if (dict == NULL)
		return;
	
	if (!(item = PyString_FromString(fft_module_doc))){
		PyErr_SetString(PyExc_ImportError, 
				"I could not generate module doc string!");
		return;
	}
	if (PyDict_SetItemString(dict, "__doc__", item) != 0){
		PyErr_SetString(PyExc_ImportError, 
				"I could not init doc string!");
		return;
	}

	return;
}


/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
