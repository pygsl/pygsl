/*
 * Python type encapsulating all the different workspaces and wavetables.
 */
typedef struct {
	PyObject_HEAD
	union pygsl_transform_space_t space;
	enum pygsl_transform_space_type type;
} PyGSL_transform_space;

static void
PyGSL_transform_space_dealloc(PyGSL_transform_space * self);

static PyObject*
PyGSL_transform_space_getattr(PyGSL_transform_space * self, char * name);

#define PyGSL_transform_space_check(op) ((op)->ob_type == &PyGSL_transform_space_pytype)
#define PyGSL_complex_fft_work_space_check(op) \
         (PyGSL_transform_space_check(op) && ((PyGSL_transform_space *)op)->type == COMPLEX_WORKSPACE)
#define PyGSL_complex_fft_wave_table_check(op) \
         (PyGSL_transform_space_check(op) && ((PyGSL_transform_space *)op)->type == COMPLEX_WAVETABLE)
#define PyGSL_halfcomplex_fft_wave_table_check(op) \
         (PyGSL_transform_space_check(op) && ((PyGSL_transform_space *)op)->type == HALFCOMPLEX_WAVETABLE)
#define PyGSL_real_fft_work_space_check(op) \
         (PyGSL_transform_space_check(op) && ((PyGSL_transform_space *)op)->type == REAL_WORKSPACE)
#define PyGSL_real_fft_wave_table_check(op) \
         (PyGSL_transform_space_check(op) && ((PyGSL_transform_space *)op)->type == REAL_WAVETABLE)

#define PyGSL_complex_fft_work_space_float_check(op) \
         (PyGSL_transform_space_check(op) && ((PyGSL_transform_space *)op)->type == COMPLEX_WORKSPACE_FLOAT)
#define PyGSL_complex_fft_wave_table_float_check(op) \
         (PyGSL_transform_space_check(op) && ((PyGSL_transform_space *)op)->type == COMPLEX_WAVETABLE_FLOAT)
#define PyGSL_halfcomplex_fft_wave_table_float_check(op) \
         (PyGSL_transform_space_check(op) && ((PyGSL_transform_space *)op)->type == HALFCOMPLEX_WAVETABLE_FLOAT)
#define PyGSL_real_fft_work_space_float_check(op) \
         (PyGSL_transform_space_check(op) && ((PyGSL_transform_space *)op)->type == REAL_WORKSPACE_FLOAT)
#define PyGSL_real_fft_wave_table_float_check(op) \
         (PyGSL_transform_space_check(op) && ((PyGSL_transform_space *)op)->type == REAL_WAVETABLE_FLOAT)




PyTypeObject PyGSL_transform_space_pytype = {
  PyObject_HEAD_INIT(NULL)	 /* fix up the type slot in init */
  0,				 /* ob_size */
  "PyGSL_transform_space",		 /* tp_name */
  sizeof(PyGSL_transform_space),	 /* tp_basicsize */
  0,				 /* tp_itemsize */

  /* standard methods */
  (destructor)  PyGSL_transform_space_dealloc, /* tp_dealloc  ref-count==0  */
  (printfunc)   0,		         /* tp_print    "print x"     */
  (getattrfunc) PyGSL_transform_space_getattr,  /* tp_getattr  "x.attr"      */
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
  (char *) PyGSL_transform_space_type_doc		/* tp_doc */
};


/*
 * Get the size of the work space. Also used in C code. Thus split up
 * and a separate function, returning a PyInt.
 */
static int
PyGSL_transform_space_get_n(PyGSL_transform_space *self)
{
	int n=0;
	FUNC_MESS_BEGIN();
	assert(PyGSL_transform_space_check(self));
	assert(self->space.v);
	switch(self->type) {
	case COMPLEX_WORKSPACE:           n = self->space.cws ->n;   break;
	case REAL_WORKSPACE:              n = self->space.rws ->n;   break;
	case COMPLEX_WAVETABLE:           n = self->space.cwt ->n;   break;
	case REAL_WAVETABLE:	          n = self->space.rwt ->n;   break;
	case HALFCOMPLEX_WAVETABLE:       n = self->space.hcwt->n;   break;	       
	case COMPLEX_WORKSPACE_FLOAT:     n = self->space.cwsf ->n;  break;
	case REAL_WORKSPACE_FLOAT:        n = self->space.rwsf ->n;  break;
	case COMPLEX_WAVETABLE_FLOAT:     n = self->space.cwtf ->n;  break;
	case REAL_WAVETABLE_FLOAT:        n = self->space.rwtf ->n;  break;
	case HALFCOMPLEX_WAVETABLE_FLOAT: n = self->space.hcwtf->n;  break;
#ifdef _PYGSL_GSL_HAS_WAVELET
	case WAVELET_WORKSPACE:           n = self->space.wws->n;    break;
#endif
	default:
		pygsl_error("Got unknown switch", filename, __LINE__, GSL_ESANITY);
		return -1;
	}
	FUNC_MESS_END();
	return n;
}
static PyObject *
PyGSL_transform_space_get_n_py(PyGSL_transform_space *self)
{
	return PyInt_FromLong((long) PyGSL_transform_space_get_n(self));
}

/*
 * Get the factors of FFT wavetables....
 */
static PyObject *
PyGSL_transform_space_get_factors(PyGSL_transform_space *self, PyGSL_transform_space *args)
{

       PyGSL_array_index_t nf, i;                                                           
       long *data=NULL;
       size_t *cp_data=NULL;
       PyArrayObject * a_array = NULL;					    
       int lineno;

       FUNC_MESS_BEGIN();
       assert(PyGSL_transform_space_check(self));
       assert(self->space.v);
       DEBUG_MESS(2, "Type = %d", self->type);
       switch(self->type){
       case COMPLEX_WAVETABLE:           nf = self->space.cwt ->nf;  cp_data = self->space.cwt ->factor;  break;
       case REAL_WAVETABLE:	         nf = self->space.rwt ->nf;  cp_data = self->space.rwt ->factor;  break;
       case HALFCOMPLEX_WAVETABLE:       nf = self->space.hcwt->nf;  cp_data = self->space.hcwt->factor;  break;	       
       case COMPLEX_WAVETABLE_FLOAT:     nf = self->space.cwtf ->nf; cp_data = self->space.cwtf ->factor; break;
       case REAL_WAVETABLE_FLOAT:        nf = self->space.rwtf ->nf; cp_data = self->space.rwtf ->factor; break;
       case HALFCOMPLEX_WAVETABLE_FLOAT: nf = self->space.hcwtf->nf; cp_data = self->space.hcwtf->factor; break;	       
       default: 
	    lineno = __LINE__ - 1;
	    pygsl_error("Got unknown switch", filename, lineno, GSL_ESANITY); 
	    goto fail; 
	    break;
       }

       a_array = (PyArrayObject *) PyGSL_New_Array(1, &nf, PyArray_LONG);
       if(a_array == NULL){
	    lineno = __LINE__ - 1;
	    goto fail;
       }

       data = (long *) a_array->data;

       
       for(i=0; i<nf; i++){
	    data[i] = (long) cp_data[i];
       }
       FUNC_MESS_END();
       return (PyObject *) a_array;

 fail:
       PyGSL_add_traceback(module, filename, __FUNCTION__, lineno);
       return NULL;

}
static const char PyGSL_transform_space_get_factors_doc[] = " Get the factors ...";
static const char PyGSL_transform_space_get_type_doc[] = " Get the type of this space";

/* Allows the user to find out what is encapsulated over the method get_type */
static PyObject *
PyGSL_transform_space_get_type(PyGSL_transform_space *self, PyObject *notused)
{
	char *p = NULL;

	FUNC_MESS_BEGIN();
	assert(PyGSL_transform_space_check(self));
	switch(self->type){
	case COMPLEX_WORKSPACE:           p = "COMPLEX_WORKSPACE";           break;
	case REAL_WORKSPACE:	          p = "REAL_WORKSPACE";	             break;
	case COMPLEX_WAVETABLE:           p = "COMPLEX_WAVETABLE";	     break;
	case REAL_WAVETABLE:	          p = "REAL_WAVETABLE";	             break;
	case HALFCOMPLEX_WAVETABLE:       p = "HALFCOMPLEX_WAVETABLE";       break;
	case COMPLEX_WORKSPACE_FLOAT:     p = "COMPLEX_WORKSPACE_FLOAT";     break;
	case REAL_WORKSPACE_FLOAT:	  p = "REAL_WORKSPACE_FLOAT";	     break;
	case COMPLEX_WAVETABLE_FLOAT:     p = "COMPLEX_WAVETABLE_FLOAT";     break;
	case REAL_WAVETABLE_FLOAT:	  p = "REAL_WAVETABLE_FLOAT";	     break;
	case HALFCOMPLEX_WAVETABLE_FLOAT: p = "HALFCOMPLEX_WAVETABLE_FLOAT"; break;
#ifdef _PYGSL_GSL_HAS_WAVELET
	case WAVELET_WORKSPACE:           p = "WAVELET_WORKSPACE";           break;
#endif
	default: pygsl_error("Got unknown switch", filename, __LINE__, GSL_ESANITY); return NULL;
	}
	FUNC_MESS_END();
	return PyString_FromString(p);
}

static const char get_type[] = "get_type";
static const char get_n[] = "get_n";

static PyMethodDef PyGSL_transform_wavetable_methods[] = {
	{"get_factors",    (PyCFunction)PyGSL_transform_space_get_factors, METH_NOARGS,  (char *)PyGSL_transform_space_get_factors_doc},
	{(char *)get_type, (PyCFunction)PyGSL_transform_space_get_type,    METH_NOARGS,  (char *)PyGSL_transform_space_get_type_doc},
	{(char *)get_n,    (PyCFunction)PyGSL_transform_space_get_n_py,    METH_NOARGS,  NULL},
	{NULL, NULL, 0, NULL}           /* sentinel */
};

static PyMethodDef PyGSL_transform_space_methods[] = {
	{(char *)get_type, (PyCFunction)PyGSL_transform_space_get_type, METH_NOARGS,  (char *)PyGSL_transform_space_get_type_doc},
	{(char *)get_n,    (PyCFunction)PyGSL_transform_space_get_n_py, METH_NOARGS,  NULL},
	{NULL, NULL, 0, NULL}           /* sentinel */
};

static PyObject*
PyGSL_transform_space_getattr(PyGSL_transform_space *self, char *name)
{
     PyObject *tmp = NULL;
     FUNC_MESS_BEGIN();
     assert(PyGSL_transform_space_check(self));     
     switch(self->type){
     case  COMPLEX_WORKSPACE:
     case  REAL_WORKSPACE:    
     case  COMPLEX_WORKSPACE_FLOAT:
     case  REAL_WORKSPACE_FLOAT:
	     tmp = Py_FindMethod(PyGSL_transform_space_methods, (PyObject *) self, name);
     default:
	     tmp = Py_FindMethod(PyGSL_transform_wavetable_methods, (PyObject *) self, name);
     }
     FUNC_MESS_END();
     return tmp;
}

static void
PyGSL_transform_space_dealloc(PyGSL_transform_space * self)
{
     FUNC_MESS_BEGIN();
     assert(PyGSL_transform_space_check(self));     
     assert(self->space.v);
     switch(self->type){
     case COMPLEX_WORKSPACE:           gsl_fft_complex_workspace_free(self->space.cws);       break;
     case COMPLEX_WAVETABLE:           gsl_fft_complex_wavetable_free(self->space.cwt);       break;
     case REAL_WORKSPACE:              gsl_fft_real_workspace_free(self->space.rws);          break;
     case REAL_WAVETABLE:	       gsl_fft_real_wavetable_free(self->space.rwt);          break;
     case HALFCOMPLEX_WAVETABLE:       gsl_fft_halfcomplex_wavetable_free(self->space.hcwt);  break;
     case COMPLEX_WORKSPACE_FLOAT:     gsl_fft_complex_workspace_float_free(self->space.cwsf);      break;
     case COMPLEX_WAVETABLE_FLOAT:     gsl_fft_complex_wavetable_float_free(self->space.cwtf);      break;
     case REAL_WORKSPACE_FLOAT:        gsl_fft_real_workspace_float_free(self->space.rwsf);         break;
     case REAL_WAVETABLE_FLOAT:	       gsl_fft_real_wavetable_float_free(self->space.rwtf);         break;
     case HALFCOMPLEX_WAVETABLE_FLOAT: gsl_fft_halfcomplex_wavetable_float_free(self->space.hcwtf); break;
#ifdef _PYGSL_GSL_HAS_WAVELET
     case WAVELET_WORKSPACE          : gsl_wavelet_workspace_free(self->space.wws);                 break;
#endif
     default: pygsl_error("Got unknown switch", filename, __LINE__, GSL_ESANITY); break;
     }
     self->space.v = NULL;
     FUNC_MESS_END();
}

static PyObject* 
PyGSL_transform_space_init(PyObject *self, PyObject *args, const enum pygsl_transform_space_type type)
{
	PyGSL_transform_space *o=NULL;
	size_t n;
	FUNC_MESS_BEGIN();
	o =  (PyGSL_transform_space *) PyObject_NEW(PyGSL_transform_space, &PyGSL_transform_space_pytype);
	if(o == NULL){
		return NULL;
	}

	if (0==PyArg_ParseTuple(args,"l", &n))
		return NULL;


	if (n<=0) {
	     pygsl_error("dimension must be >0", filename, __LINE__, GSL_EINVAL);
	     return NULL;
	}
	o->type = type;
	switch(type){
	case COMPLEX_WORKSPACE:           o->space.cws  = gsl_fft_complex_workspace_alloc(n);            break;
	case COMPLEX_WAVETABLE:           o->space.cwt  = gsl_fft_complex_wavetable_alloc(n);            break;
	case REAL_WORKSPACE:              o->space.rws  = gsl_fft_real_workspace_alloc(n);               break;
	case REAL_WAVETABLE:	          o->space.rwt  = gsl_fft_real_wavetable_alloc(n);               break;
	case HALFCOMPLEX_WAVETABLE:       o->space.hcwt = gsl_fft_halfcomplex_wavetable_alloc(n);        break;
	case COMPLEX_WORKSPACE_FLOAT:     o->space.cwsf  = gsl_fft_complex_workspace_float_alloc(n);     break;
	case COMPLEX_WAVETABLE_FLOAT:     o->space.cwtf  = gsl_fft_complex_wavetable_float_alloc(n);     break;
	case REAL_WORKSPACE_FLOAT:        o->space.rwsf  = gsl_fft_real_workspace_float_alloc(n);        break;
	case REAL_WAVETABLE_FLOAT:	  o->space.rwtf  = gsl_fft_real_wavetable_float_alloc(n);        break;
	case HALFCOMPLEX_WAVETABLE_FLOAT: o->space.hcwtf = gsl_fft_halfcomplex_wavetable_float_alloc(n); break;
#ifdef _PYGSL_GSL_HAS_WAVELET
	case WAVELET_WORKSPACE          : o->space.wws   = gsl_wavelet_workspace_alloc(n);               break;
#endif
	default: pygsl_error("Got unknown switch", filename, __LINE__, GSL_ESANITY); return NULL; break;
	}
	assert(o->space.v);
	FUNC_MESS_END();
	return (PyObject *) o;
}



#define PyGSL_SPACE_ALLOC(TYPE)                               \
static PyObject *                                             \
PyGSL_transform_space_init_ ## TYPE (PyObject *self, PyObject *args)\
{                                                             \
     return PyGSL_transform_space_init(self, args, TYPE);           \
}                                                             
PyGSL_SPACE_ALLOC(COMPLEX_WORKSPACE)
PyGSL_SPACE_ALLOC(COMPLEX_WAVETABLE)
PyGSL_SPACE_ALLOC(REAL_WORKSPACE)      
PyGSL_SPACE_ALLOC(REAL_WAVETABLE)
PyGSL_SPACE_ALLOC(HALFCOMPLEX_WAVETABLE)

PyGSL_SPACE_ALLOC(COMPLEX_WORKSPACE_FLOAT)
PyGSL_SPACE_ALLOC(COMPLEX_WAVETABLE_FLOAT)
PyGSL_SPACE_ALLOC(REAL_WORKSPACE_FLOAT)      
PyGSL_SPACE_ALLOC(REAL_WAVETABLE_FLOAT)
PyGSL_SPACE_ALLOC(HALFCOMPLEX_WAVETABLE_FLOAT)

#ifdef _PYGSL_GSL_HAS_WAVELET
PyGSL_SPACE_ALLOC(WAVELET_WORKSPACE)
#endif
