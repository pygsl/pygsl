#ifdef _PYGSL_GSL_HAS_WAVELET
#include "wavelet.h"
#endif
/*
 * Checks existing objects if they are of proper type, and if so check that 
 * they are big enough. If not allocate space of approbriate size.
 */
static int 
PyGSL_transform_helpers_alloc(PyObject *s_o, PyObject *t_o, struct _pygsl_transform_help_rf_s * h, int n)
{
	int check;

	FUNC_MESS_BEGIN();

	/* Set everything to zero first! */
	h->free_space = 0;
	h->free_table = 0;
	h->table = NULL;
	h->space = NULL;


	if(h->func == 0)
		PyGSL_ERROR("Functions not set!", GSL_EFAULT);
	if(n <= 0)
		PyGSL_ERROR("n<=0!", GSL_ESANITY);

	DEBUG_MESS(3, "Allocating/Checking space for %d elements", n);
	if(h->func->space_type != NOSPACE && s_o){
		if(PyGSL_transform_space_check(s_o) && ((PyGSL_transform_space * )s_o)->type == h->func->space_type){
			check = PyGSL_transform_space_get_n((PyGSL_transform_space * )s_o);
			if(check == -1 || check < n)
				PyGSL_ERROR("Work Space not big enough!", GSL_EINVAL);
			h->space = ((PyGSL_transform_space * )s_o) ->space.v;
		} else {
			PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 4);
			PyGSL_ERROR("Need a pygsl  transform space of proper type!", GSL_EINVAL);
		}
	}

	if(h->func->space_type != NOSPACE && t_o){
		if(PyGSL_transform_space_check(t_o) && ((PyGSL_transform_space * )t_o)->type == h->func->table_type){
			check = PyGSL_transform_space_get_n((PyGSL_transform_space * )s_o);
			if(check == -1 || check < n)
				PyGSL_ERROR("Wave table not big enough!", GSL_EINVAL);
			h->table = ((PyGSL_transform_space * )t_o) ->space.v;
		} else {
			PyGSL_add_traceback(module, filename, __FUNCTION__, __LINE__ - 4);
			PyGSL_ERROR("Need a pygsl transform wave table of proper type!", GSL_EINVAL);
		}
	}
	/* Check for the approbriate type and initialise it!*/
	if((h->space) == NULL || (h->table) == NULL){
		DEBUG_MESS(3, "func %p alloc table %p alloc space %p, space %p, table %p",
			   h->func, (void *) h->func->table_alloc, 
			   (void *) h->func->space_alloc, h->space, h->table);

		/* Store if I need to free these arrays */
		if((h->space) == NULL && h->func->space_type != NOSPACE){
			h->space = h->func->space_alloc(n);
			h->free_space = 1;
		}
		if((h->table) == NULL && h->func->table_type != NOSPACE){
			h->table = h->func->table_alloc(n);
			h->free_table = 1;
		}
		if((h->space == NULL && h->func->space_type != NOSPACE) || 
		   (h->table == NULL && h->func->table_type != NOSPACE)){
			return GSL_ENOMEM;
		}
		DEBUG_MESS(3, "Allocated space @ %p table @ %p", h->space, h->table);
	}
	FUNC_MESS_END();
	return GSL_SUCCESS;

}

#define PyGSL_TRANSFORM_HELPERS_FREE(helpers) \
        ((helpers != NULL) && ((helpers->free_table != 0) &&  (helpers->free_space != 0)) ? \
        PyGSL_transform_helpers_free(helpers) : 0)

static void
PyGSL_transform_helpers_free(struct _pygsl_transform_help_rf_s * h)
{
	FUNC_MESS_BEGIN();
	assert(h->func);
	DEBUG_MESS(3, "func @ %p", h->func);
	if( (h->free_table == 1) && (h->table != NULL)){ 
		assert(h->table);
		DEBUG_MESS(3, "Free Table %p with func %p", h->table, 
			   (void *) h->func->table_free);
		h->func->table_free(h->table); 
		h->table = NULL;
		h->free_table = 0;
	}
	if((h->free_space == 1) && (h->space != NULL)){
		assert(h->space);
		DEBUG_MESS(3, "Free Space %p with func %p", h->space, 
			   (void *) h->func->space_free);
		h->func->space_free(h->space);  
		h->space = NULL;
		h->free_space = 0;
	}
	FUNC_MESS_END();
}

#ifdef _PYGSL_GSL_HAS_WAVELET
/*
 * The two D function. Currently only supports wavelet2d_matrix...
 */
static PyObject *
PyGSL_transform_2d_(PyObject *self, PyObject *args, pygsl_transform_help_s *helps)
{
        PyObject *ret = NULL, *data=NULL, *s_o = NULL;
	PyArrayObject *m=NULL;
	PyGSL_wavelet *wavelet = NULL;
	gsl_matrix_view mv;
	const enum radix_mode  radix2 = helps->info->radix2;
	const enum PyArray_TYPES  input_array_type=helps->info->input_array_type;	     
	/* const int sizeoftype = sizeof(double) */;
	int call_n, line=-1;

	switch(radix2){
	case WAVELET:
	     if(!PyGSL_WAVELET_CHECK(self)){
		  pygsl_error("Should be a wavelet method!", filename, line, GSL_ESANITY);
		  line = __LINE__ - 1;
		  goto fail;
	     }
	     wavelet = (PyGSL_wavelet *) self;
	     break;
	default: 
		line = __LINE__;
	     pygsl_error("Unknown switch!", filename, line, GSL_ESANITY);
	     goto fail;
	}
	/* Currently only implemented for wavelet 2d transform */
	if(!PyArg_ParseTuple(args, "O|OO", &data, &s_o, &ret)){
	     line = __LINE__ - 1;
	     goto fail;
	}
	m = PyGSL_matrix_check(data, -1, -1, 
			       PyGSL_BUILD_ARRAY_INFO(PyGSL_CONTIGUOUS | PyGSL_INPUT_ARRAY, input_array_type, 1, 2), 
			       NULL, NULL, NULL);
	if(m == NULL)
	     goto fail;

	mv = gsl_matrix_view_array((double *)m->data, m->dimensions[0], m->dimensions[1]);
	
	call_n = m->dimensions[0] + m->dimensions[1];
	if (PyGSL_transform_helpers_alloc(s_o, NULL, helps->helpers, call_n) != GSL_SUCCESS){
	     line = __LINE__ -1;
	     goto fail;
	}

	if(PyGSL_ERROR_FLAG(helps->transform.wavelet2d(wavelet->wavelet, &mv.matrix, helps->helpers->space)) != GSL_SUCCESS){
	     line = __LINE__ -1;
	     goto fail;
	}

     
	PyGSL_TRANSFORM_HELPERS_FREE(helps->helpers);
	ret = (PyObject *) m;
	return ret;

 fail:
	FUNC_MESS("Fail");
	PyGSL_add_traceback(module, filename, __FUNCTION__, line);
	PyGSL_TRANSFORM_HELPERS_FREE(helps->helpers);
	Py_XDECREF(m);     m = NULL;
	FUNC_MESS("Fail End");
	return NULL;
}
#endif /*  _PYGSL_GSL_HAS_WAVELET */

/*
 * Catch all for all one dimensional functions.
 */
static PyObject *
PyGSL_transform_(PyObject *self, PyObject *args, pygsl_transform_help_s *helps)
{
	PyObject *ret = NULL, *s_o = NULL, *t_o = NULL, *data = NULL;
	PyArrayObject *result = NULL, *a=NULL, *r=NULL;
#ifdef _PYGSL_GSL_HAS_WAVELET
	PyGSL_wavelet *wavelet = NULL;
#endif
	double eps=1e-6;
	int line = -1;
	int length=-1;
	/* 
	 *  how will it be called and what array length will I need.
	 *  In the HalfComplexReal and the reversed case, an array of double
	 *  data is provided. But the real array is of CDOUBLE. This takes the 
	 *  computation in place into account and minimizes the necessary
	 *  copies.
	 */
	PyGSL_array_index_t n=0, call_n=0, return_n=0, strides=0;
	const enum PyArray_TYPES  input_array_type=helps->info->input_array_type, 
	     output_array_type=helps->info->output_array_type;

	const enum transform_mode mode = helps->info->mode;
	const enum radix_mode  radix2 = helps->info->radix2;
	/*
	 *  Helper for STRIDE recalculation.  numpy/numarray use strides as
	 *  multiples of char. But GSL uses the basis as common denominator.
	 *  Only complex transforms use complex numbers, so only for them
	 *  n_type will be two, and it will be one for all others.
	 */
	const enum pygsl_packed_type n_type = helps->info->packed;
	/*
	 * Double mode or float mode?
	 * complex double or complex float ?
	 */
	const int datatype = helps->info->datatype;
	/* and its size */
	const int sizeoftype = (datatype == MODE_DOUBLE) ? sizeof(double) : sizeof(float);	
	/*
	 * Normaly the element 0 of the return array is passed. In exceptional
	 * cases, e.g. RealHalfComplex for RADIX_FREE an offset is needed!
	 */
	const int call_offset= helps->info->data_offset;
	void * vdata;
	FUNC_MESS_BEGIN();
	assert(args);

	/*
	 * I never know when I will call the _free function. So better to define
	 * them here already as any jump can go to fail and will start to free 
	 * the tables.
	 */
	if(helps->helpers){
		helps->helpers->free_table=0;
		helps->helpers->free_space=0;
		helps->helpers->table=NULL;
		helps->helpers->space=NULL;
	}
	assert(mode>0);
	assert(radix2>0);
	assert(datatype>0);
	/*
	 *  Parse the arguments. Depends on the type how many arguments we are going
	 *  to support.
	 */
	switch(radix2){
#ifdef _PYGSL_GSL_HAS_WAVELET
	case WAVELET:
		FUNC_MESS("Wavelet");
		/* 
		 *  Yes thats a method here.... UiUi not sure if it is not too
		 *  much in one function 
		 */
		if(!PyGSL_WAVELET_CHECK(self)){
			pygsl_error("Should be a wavelet method!", filename, line, GSL_ESANITY);
			line = __LINE__ - 1;
			goto fail;
		}
		wavelet = (PyGSL_wavelet *) self;
		if(!PyArg_ParseTuple(args, "O|OO", &data, &s_o, &ret)){
			line = __LINE__ - 1;
			goto fail;
		}
		break;
#endif
	case RADIX_FREE:
		FUNC_MESS("Radix_Free");
		assert(helps->helpers);
		switch(mode){
		case ComplexComplex : 
			FUNC_MESS("ComplexComplex");
			if(!PyArg_ParseTuple(args, "O|OOO", &data, &s_o, &t_o, &ret)){
				line = __LINE__ - 1;
				goto fail;
			}
			break;
		case RealHalfcomplex:
			FUNC_MESS("Real");
			if(!PyArg_ParseTuple(args, "O|OO",&data, &s_o, &t_o)){
				line = __LINE__ - 1;
				goto fail;
			}
			break;
		case HalfComplexReal:
			FUNC_MESS("Halfcomplex");
			if(!PyArg_ParseTuple(args, "O|iOOd",&data, &length, &s_o, &t_o, &eps)){
				line = __LINE__ - 1;
				goto fail;
			}
			break;
		default:
			line = __LINE__;
			pygsl_error("Unknown mode!", filename, line, GSL_ESANITY);
			goto fail;
		} /* mode */
		break;
	case RADIX_TWO:
		FUNC_MESS("Radix_TWO");
		assert(helps->helpers==NULL);
		switch(mode){
		case ComplexComplex : 
			FUNC_MESS("ComplexComplex");
			if(!PyArg_ParseTuple(args, "O|O", &data, &ret)){
				line = __LINE__ - 1;
				goto fail;
			}
			break;
		case RealHalfcomplex:
		case HalfComplexReal:
			FUNC_MESS("Real-Halfcomplex");
			if(!PyArg_ParseTuple(args, "O",&data)){
				line = __LINE__ - 1;
				goto fail;
			}
			break;
		default:
			line = __LINE__;
			pygsl_error("Unknown mode!", filename, line, GSL_ESANITY);
			goto fail;
		} /* mode */
		break;
	default:
		line = __LINE__;
		DEBUG_MESS(3, "Radix2 was %d, wavelet = %d", (int) radix2, (int) WAVELET); 
		pygsl_error("Unknown radix!", filename, line, GSL_ESANITY);
		goto fail;
	}/* radix2 */
	FUNC_MESS("mode");
	assert(input_array_type >0);
	assert(output_array_type >0);
	assert(n_type >0);
	assert(sizeoftype >0);
	DEBUG_MESS(3, "Double?Float %d IN Array Type = %d OUT Array Type = %d", datatype, input_array_type, output_array_type);
	DEBUG_MESS(3, "n_type = %d sizeofbasis = %d", n_type, sizeoftype);
	{
		const int io_type = ((ret == NULL) ? PyGSL_INPUT_ARRAY : PyGSL_IO_ARRAY) | PyGSL_NON_CONTIGUOUS;
		a = PyGSL_vector_check(data, -1, PyGSL_BUILD_ARRAY_INFO(io_type, input_array_type, 1, 1), NULL, NULL);
		if(a == NULL){
			line = __LINE__ - 1;
			goto fail;
		}
	}
	n = a->dimensions[0];

	/* 
	 * Calculate  the size of the return array and the call array
	 * Generate the return array
	 */
	FUNC_MESS("Return Array");
	switch(radix2){
#ifdef _PYGSL_GSL_HAS_WAVELET
	case WAVELET:
		return_n = n;
		call_n = n; 
		if((r = PyGSL_Shadow_array((PyObject *) ret, (PyObject *) a, datatype)) == NULL){
			line = __LINE__ -1;
			goto fail;
		}
		break;		
#endif
	case RADIX_FREE:
		FUNC_MESS("Radix Free");
		switch(mode){
		case ComplexComplex:
			FUNC_MESS("ComplexComplex");
			return_n = n;
			call_n = n; 
			if((r = PyGSL_Shadow_array((PyObject *) ret, (PyObject *) a, datatype)) == NULL){
				line = __LINE__ -1;
				goto fail;
			}
			break;
		case RealHalfcomplex:
			FUNC_MESS("RealHalfcomplex");
			return_n = n / 2 + 1;
			call_n = n; 
			if(((r = (PyArrayObject *) PyGSL_New_Array(1, &return_n, output_array_type)) == NULL) ||
			   (PyGSL_copy_real_to_complex(r, a, datatype) != GSL_SUCCESS)){
				line = __LINE__ -2;
				goto fail;
			}
			break;
		case HalfComplexReal:
			FUNC_MESS("HalfcomplexReal");
			call_n = PyGSL_guess_halfcomplex_length(a, length, eps, datatype);
			return_n = call_n;
			if(((r = (PyArrayObject *) PyGSL_New_Array(1, &return_n, output_array_type)) == NULL) ||
			   (PyGSL_ERROR_FLAG(PyGSL_copy_halfcomplex_to_real(r, a, eps, datatype)) != GSL_SUCCESS)){
				line = __LINE__ - 2;
				goto fail;
			}
			break;		
		default:
			line = __LINE__ -1;
			goto fail;
		}/* mode */		
		break;
	case RADIX_TWO:
		FUNC_MESS("Radix TWO");
		return_n = n;
		call_n = n;
		if((r = (PyArrayObject *) PyGSL_Copy_Array(a)) == NULL){
			line = __LINE__ -1;
			goto fail;
		}
		break;
	default:
		line = __LINE__ -1;
		goto fail;
	} /* radix2 */		
	Py_DECREF(a);
	a = NULL;
	/* make sure that the ntype was set */
	assert(n_type > 0);
	DEBUG_MESS(2, "Type(r) = %d, r->nd = %d, r->dimensions[0] = %d, Strides r->strides[0] %d", 
		   r->descr->type_num, r->nd, r->dimensions[0], r->strides[0]);
	if(PyGSL_STRIDE_RECALC(r->strides[0], n_type * sizeoftype, &strides) != GSL_SUCCESS){
		line = __LINE__ -1;
		goto fail;
	}
	DEBUG_MESS(2, "Strides r->strides[0] %ld strides = %ld", (long)r->strides[0], (long)strides);
	/* build the helpers if necessary */
	switch(radix2){
#ifdef _PYGSL_GSL_HAS_WAVELET
	case WAVELET:
#endif
	case RADIX_FREE:
		FUNC_MESS("Build Helpers");
		if (PyGSL_transform_helpers_alloc(s_o, t_o, helps->helpers, call_n) != GSL_SUCCESS){
			line = __LINE__ -1;
			goto fail;
		}
		break;
	default:
		/* No helpers needed! */ ;
	}/* radix2 */

#if DEBUG > 0	
	if(PyGSL_Check_Array_Length(r, call_n, datatype, n_type) != GSL_SUCCESS){
		line = __LINE__ -1;
		goto fail;
	}
#endif 
	vdata = (void *) r->data;
	if(call_offset!=0){
		switch(datatype){
		case MODE_DOUBLE: vdata = (void *) (((double *) r->data) + call_offset); break;
		case MODE_FLOAT:  vdata = (void *) (((float  *) r->data) + call_offset); break;
		}
		DEBUG_MESS(3, "Original Pointer at %p new pointer at %p", r->data, vdata);
	}
	/* call the function */
	switch(radix2){
	case RADIX_FREE:
		FUNC_MESS("Transform free length");
		assert(helps->helpers->table);
		assert(helps->helpers->space);
		DEBUG_MESS(3, "vdata = %f, strides = %ld, call_n = %ld", 
			   *((double *)(vdata)), (long) strides, (long) call_n);	
		if(PyGSL_ERROR_FLAG(helps->transform.free(vdata, strides, call_n,
							  helps->helpers->table, 
							  helps->helpers->space)) != GSL_SUCCESS){
			line = __LINE__ -1;
			goto fail;
		}
		DEBUG_MESS(3, "Transformed: r->data[0] = %f, strides = %ld, call_n = %ld", 
			   *((double *)(r->data)), (long)strides, (long)call_n);
		break;
	case RADIX_TWO:
		FUNC_MESS("Tranform radix2");
		if(PyGSL_ERROR_FLAG(helps->transform.radix2(vdata, strides, call_n)) != GSL_SUCCESS){
			line = __LINE__ -1;
			goto fail;
		}
		break;
#ifdef _PYGSL_GSL_HAS_WAVELET
	case WAVELET:	
		FUNC_MESS("Tranform wavelet");
		assert(wavelet);
		assert(helps->helpers->space);
		if(PyGSL_ERROR_FLAG(helps->transform.wavelet(wavelet->wavelet, (double *)vdata, strides, call_n,
							     helps->helpers->space)) != GSL_SUCCESS){
			line = __LINE__ -1;
			goto fail;
		}
		break;
#endif
	default:
		line = __LINE__ -1;
		goto fail;
	}
	/*  restore the array */	
	switch(radix2){
	case RADIX_FREE:
		switch(mode){
		case RealHalfcomplex:
			FUNC_MESS("halfcomplex unpack");
			if(PyGSL_fft_halfcomplex_unpack(r, call_n, datatype) != GSL_SUCCESS){
				line = __LINE__ -1;
				goto fail;
			}
			break;
		case RealReal:	
		case HalfComplexReal:
		case ComplexComplex: break;
		}
		break;
	default:
		/* No helpers needed! */ ;		
	}

	PyGSL_TRANSFORM_HELPERS_FREE(helps->helpers);
	result = r;
	FUNC_MESS_END();
	return (PyObject *) result;

  fail:
	FUNC_MESS("Fail");
	PyGSL_add_traceback(module, filename, __FUNCTION__, line);
	PyGSL_TRANSFORM_HELPERS_FREE(helps->helpers);
	Py_XDECREF(r);     r = NULL;
	FUNC_MESS("Fail End");
	return NULL;
}
/*
 * Local Variables:
 * mode: C
 * c-file-style: "python"
 * End:
 */
