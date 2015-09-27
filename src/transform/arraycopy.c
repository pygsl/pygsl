static int
PyGSL_debug_mess_array(PyArrayObject * a, const char * name)
{
     int mode, i;
     float *fv;
     double *dv;
     void * av;

     mode = PyArray_TYPE(a);
     for(i=0; i<PyArray_DIM(a, 0); ++i){
       av   = PyArray_GETPTR1(a, i);
	  switch(mode){
	  case  NPY_CDOUBLE:
	       dv = (double *) av;
	       fprintf(stderr, "%s [%d] = %e + %e j\n", name, i, dv[0], dv[1]);
	       break;
	  case NPY_CFLOAT:
	       fv = (float *) av;
	       fprintf(stderr, "%s [%d] = %e + %e j\n", name, i, fv[0], fv[1]);
	       break;
	  }
     }
     return GSL_SUCCESS;
}

/* 
 * Copies real data to complex in the special way that it will be passed to the
 * transform with an offset of one! 
 */
static int
PyGSL_copy_real_to_complex(PyArrayObject *dst, PyArrayObject *src, enum pygsl_transform_mode mode)
{
	int i, n, n_check, n_2, modulo=0;
	void *srcv, *dstv;
	double *srcd=NULL, *dstd=NULL;			
	float  *srcf=NULL, *dstf=NULL;

	FUNC_MESS_BEGIN();
	n = PyArray_DIM(src, 0);
	n_check = PyArray_DIM(dst, 0);
	
	assert(src);
	assert(dst);
	assert(PyArray_TYPE(src) == PyGSL_TRANSFORM_MODE_SWITCH(mode, NPY_DOUBLE, NPY_FLOAT));
	assert(PyArray_TYPE(dst) == PyGSL_TRANSFORM_MODE_SWITCH(mode, NPY_CDOUBLE, NPY_CFLOAT));

	/* Iterate over the source array and copy to the destination array. */
	for(i = 0; i < n; ++i){
		srcv   = PyArray_GETPTR1(src, i);
		n_2 = (i+1)/2;

		/* complex array, only iterate every second */
		dstv  = PyArray_GETPTR1(dst, n_2);
		modulo = (i+1)%2;

		if(n_2 >= n_check)
			PyGSL_ERROR("Complex array too small!", GSL_ESANITY);

		if(mode == MODE_DOUBLE){
			srcd = (double *) srcv;
			dstd = (double *) dstv;
			dstd[modulo] = *srcd;
			DEBUG_MESS(5, "R -> C [%d] srcd %e\t dstd %e + %ej", i, *srcd, dstd[0], dstd[1]);
		}else if(mode == MODE_FLOAT){
			srcf = (float *) srcv;
			dstf = (float *) dstv;
			dstf[modulo] = *srcf;			
			DEBUG_MESS(5, "R -> C [%d] srcd %e\t dstd %e + %ej", i, *srcf, dstf[0], dstf[1]);
		}
	}
	FUNC_MESS_END();
	DEBUG_MESS(3, "Last modulo was %d", modulo);

	/* odd length, last was set ... */
	modulo = (n)%2;
	if(modulo == 1)
	     return GSL_SUCCESS;

	/* even length, last must be set ... */	     
	DEBUG_MESS(4, "Setting the last to zero n=%d", n);
	dstv  = (PyArray_GETPTR1(dst, n/2));
	switch(mode){
	     case MODE_DOUBLE:
		  dstd = (double *) dstv;
		  dstd[1] = 0.0;
		  break;
	     case MODE_FLOAT:
		  dstf = (float *) dstv;
		  dstf[1] = 0.0;
		  break;
	}
		  
	return GSL_SUCCESS;
	
}

/* Assumes special halfcomplex arrangement to be made and used ! */
static int
PyGSL_copy_halfcomplex_to_real(PyArrayObject *dst, PyArrayObject *src, double eps, 
			       enum pygsl_transform_mode mode)
{
	int n, n_check, i, n_2;
	double *srcd=NULL, *dstd=NULL;
	float *srcf=NULL, *dstf=NULL;
	void *srcv=NULL, *dstv=NULL;

	FUNC_MESS_BEGIN();
	assert(src);
	assert(dst);
	assert(PyArray_TYPE(src) == PyGSL_TRANSFORM_MODE_SWITCH(mode, NPY_DOUBLE, NPY_FLOAT));
	assert(PyArray_TYPE(dst) == PyGSL_TRANSFORM_MODE_SWITCH(mode, NPY_CDOUBLE, NPY_CFLOAT));

	n_check = PyArray_DIM(src, 0);
	n = PyArray_DIM(dst, 0);

	/* The first element is a bit special */
	if(mode == MODE_DOUBLE){
		srcd = (double *)PyArray_DATA(src);	
		dstd = (double *)PyArray_DATA(dst);
	} else {
		srcf = (float *)PyArray_DATA(src);	
		dstf = (float *)PyArray_DATA(dst);
	}
	/* Should be zero ... */
	if(gsl_fcmp(PyGSL_TRANSFORM_MODE_SWITCH(mode, srcd[1], srcf[1]), 0,  eps) != 0)
	        PyGSL_ERROR("The complex part of the nyquist freqency was not" 
			  "zero as it ought to be!", GSL_EINVAL);
	*dstd = *srcd;

	for(i = 1; i < n; ++i){
		n_2 = (i+1)/2;
		if(n_2 >= n_check){
			PyGSL_ERROR("Sizes of the complex array too small!", GSL_ESANITY);
		}
		
		srcv = PyArray_GETPTR1(src, n_2);
		dstv = PyArray_GETPTR1(dst, i);
		if(mode == MODE_DOUBLE){
			srcd = (double *)(srcv);
			dstd = (double *)(dstv);
			*dstd = srcd[(i+1)%2];
			DEBUG_MESS(5, "C -> R [%d] srcd %e + %ej\t dstd %e", i, srcd[0], srcd[1], *dstd);
		} else {
			srcf = (float *)(srcv);
			dstf = (float *)(dstv);
			*dstf = srcf[(i+1)%2];
			DEBUG_MESS(5, "C -> R [%d] srcf %e + %ej\t dstf %e", i, srcf[0], srcf[1], *dstf);
		}
	}
	FUNC_MESS_END();
	return GSL_SUCCESS;
}

static int
PyGSL_copy_array_to_array(PyArrayObject *dst, PyArrayObject *src,  enum pygsl_transform_mode mode)
{
	int n, n_check,  size, flag, iscomplex=0;
	PyGSL_array_index_t stride1, stride2;
	gsl_vector_view d1, d2;
	gsl_vector_float_view f1, f2;
	gsl_vector_complex_view z1, z2;
	gsl_vector_complex_float_view c1, c2;
	void *srcv=NULL, *dstv=NULL;
	const enum NPY_TYPES array_type = (enum NPY_TYPES) PyArray_TYPE(src);

	FUNC_MESS_BEGIN();
	assert(src);
	assert(dst);
	assert(PyArray_TYPE(src) == PyArray_TYPE(dst));

	n = PyArray_DIM(dst, 0);
	n_check = PyArray_DIM(src, 0);
	if(n_check != n){
		PyGSL_ERROR("Sizes of the arrays did not match!", GSL_ESANITY);
	}
	
	size = PyGSL_TRANSFORM_MODE_SWITCH(mode, sizeof(double), sizeof(float));

	if(array_type == NPY_CDOUBLE || array_type == NPY_CFLOAT){
	     size *= 2; /* Complex are two basis numbers */
	     iscomplex=1;
	}else{
	     iscomplex=0;
	}

	if((flag = PyGSL_STRIDE_RECALC(PyArray_STRIDE(src, 0), size, &stride1) != GSL_SUCCESS) || 
	   (flag = PyGSL_STRIDE_RECALC(PyArray_STRIDE(dst, 0), size, &stride2) != GSL_SUCCESS))
		return flag;

	srcv = PyArray_DATA(src);
	dstv = PyArray_DATA(dst);
	if(iscomplex){
	     switch(mode){
	     case MODE_DOUBLE:  		
		  z1 = gsl_vector_complex_view_array_with_stride((double *)dstv, stride2, n);
		  z2 = gsl_vector_complex_view_array_with_stride((double *)srcv, stride1, n);
		  return gsl_blas_zcopy(&z2.vector, &z1.vector);
		  break;
	     case MODE_FLOAT:   
		  c1 = gsl_vector_complex_float_view_array_with_stride((float *)dstv, stride2, n);
		  c2 = gsl_vector_complex_float_view_array_with_stride((float *)srcv, stride1, n);
		  return gsl_blas_zcopy(&z2.vector, &z1.vector);
		  break;
	     }
	}else{
	     switch(mode){
	     case MODE_DOUBLE:  		
		  d1 = gsl_vector_view_array_with_stride((double *)dstv, stride2, n);
		  d2 = gsl_vector_view_array_with_stride((double *)srcv, stride1, n);
		  return gsl_blas_dcopy(&d2.vector, &d1.vector);
		  break;
	     case MODE_FLOAT:   
		  f1 = gsl_vector_float_view_array_with_stride((float *)dstv, stride2, n);
		  f2 = gsl_vector_float_view_array_with_stride((float *)srcv, stride1, n);
		  return gsl_blas_scopy(&f2.vector, &f1.vector);
		  break;
	     }
	}
	FUNC_MESS_END();
	return GSL_SUCCESS;
}

/*
 * Only shift the last one. Assumes that it was passed to the GSL function with
 * an offset of one. Further assumes an contingous array.
 */
static int
PyGSL_fft_halfcomplex_unpack(PyArrayObject *a, int n_orig,  enum pygsl_transform_mode mode)
{
	double *d;
	float *f;
	void * v =NULL;
	
	FUNC_MESS_BEGIN();
	assert(a);
	assert(PyArray_TYPE(a) == PyGSL_TRANSFORM_MODE_SWITCH(mode, NPY_CDOUBLE, NPY_CFLOAT));

	v = PyArray_DATA(a);
	if(mode == MODE_DOUBLE){
		d = (double *)v;
		d[0] = d[1];
		d[1] = 0.0;
		/* Set the last imaginary to zero for even length as it ought to be */
		if(n_orig%2){
		     DEBUG_MESS(3, "Setting %d to zero", n_orig);
			d[n_orig] = 0.0; 
		}
	}else{
		f = (float *) v;
		f[0] = f[1];
		f[1] = 0.0;
		/* Set the last imaginary to zero for even length as it ought to be */
		if(n_orig%2){
		     DEBUG_MESS(3, "Setting %d to zero", n_orig);
		     f[n_orig] = 0.0;
		}

	}
	if(PyGSL_DEBUG_LEVEL() > 5)
	     PyGSL_debug_mess_array(a, "unpacked array");	
	FUNC_MESS_END();
	return GSL_SUCCESS;
}

/*
 * I only need to reorder the imaginary data?
 * I have to do it inplace thus I can not use the gsl function ...
 */
static PyObject *
_PyGSL_fft_halfcomplex_radix2_unpack(PyObject *self, PyObject *args, enum pygsl_transform_mode mode)
{

	PyObject *a_o=NULL;
	PyArrayObject *a=NULL, *r=NULL;
	double *ddata, *dreal, *dimag;
        float *fdata, *freal, *fimag;
	void *adata, *rdata, *vdata, *vreal, *vimag;
	PyGSL_array_info_t dinfo, finfo;
	PyGSL_array_index_t n, rn, i;
	FUNC_MESS_BEGIN();
	if(!PyArg_ParseTuple(args, "O",&a_o))
		return NULL;
	
	dinfo = PyGSL_BUILD_ARRAY_INFO(PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY,
				       NPY_DOUBLE, sizeof(double), 1);
	finfo = PyGSL_BUILD_ARRAY_INFO(PyGSL_NON_CONTIGUOUS | PyGSL_INPUT_ARRAY,
				       NPY_FLOAT, sizeof(float), 1);
	
	a = PyGSL_vector_check(a_o, -1, PyGSL_TRANSFORM_MODE_SWITCH(mode, dinfo, finfo), NULL, NULL);
	if(a == NULL)
		goto fail;
	n = PyArray_DIM(a, 0);
	if(n%2 != 0){
		pygsl_error("The length of the vector must be a multiple of two!",
			  __FILE__, __LINE__, GSL_EDOM);		goto fail;
	}
	rn = n / 2 + 1;
	if((r = (PyArrayObject *) PyGSL_New_Array(1, &rn, PyGSL_TRANSFORM_MODE_SWITCH(mode, NPY_CDOUBLE, NPY_CFLOAT))) == NULL)
		goto fail;
	assert(PyArray_DIM(r, 0) == rn);


	/* first one special */
	rdata = PyArray_DATA(r);
	adata = PyArray_DATA(a);
	switch(mode){
	  case MODE_DOUBLE: 
		  ddata = (double *) rdata;
		  ddata[0] = ((double *) adata)[0];
		  ddata[1] = 0.0;
		  break;
	  case MODE_FLOAT: 
		  fdata = (float *) rdata;
		  fdata[0] = ((float *) adata)[0];
		  fdata[1] = 0.0;
		  break;
	}
	for(i = 1; i < rn - 1; ++i){
		assert(i>0 && i < n);
		vdata = PyArray_GETPTR1(r, i);
		vreal = PyArray_GETPTR1(a, i);
		vimag = PyArray_GETPTR1(a, (n-i));
		switch(mode){
		case MODE_DOUBLE: 
			ddata    = (double *)vdata;
			dreal    = (double *)vreal;
			dimag    = (double *)vimag;
			ddata[0] = *dreal;
			ddata[1] = *dimag;
			break;
		case MODE_FLOAT: 
			fdata    = (float *)vdata;
			freal    = (float *)vreal;
			fimag    = (float *)vimag;
			fdata[0] = *freal;
			fdata[1] = *fimag;
			break;
		}
	}

	vdata = PyArray_GETPTR1(r, rn-1);
	vreal = PyArray_GETPTR1(a, n/2);
	switch(mode){
	case MODE_DOUBLE: 
		ddata    =   (double *)vdata;
		ddata[0] = *((double *)vreal);
		ddata[1] = 0.0;
		break;
	case MODE_FLOAT: 
		fdata    =   (float *)vdata;
		fdata[0] = *((float *)vreal);
		fdata[1] = 0.0;
		break;
	}
	/* data[n_orig] = 0.0; */
	Py_DECREF(a); a = NULL;
        FUNC_MESS_END();
	return (PyObject *) r;
  fail:
	Py_XDECREF(a);
	Py_XDECREF(r);
	return NULL;
}

static PyObject *
PyGSL_fft_halfcomplex_radix2_unpack(PyObject *self, PyObject *args)
{
	PyObject *tmp;
	FUNC_MESS_BEGIN();
	tmp = _PyGSL_fft_halfcomplex_radix2_unpack(self, args, MODE_DOUBLE);
	FUNC_MESS_END();
	return tmp;
}

static PyObject *
PyGSL_fft_halfcomplex_radix2_unpack_float(PyObject *self, PyObject *args)
{
	PyObject *tmp;
	FUNC_MESS_BEGIN();
	tmp = _PyGSL_fft_halfcomplex_radix2_unpack(self, args, MODE_FLOAT);
	FUNC_MESS_END();
	return tmp;
}

/*
 * Copy an input array in an output array if necessary
 */
static PyArrayObject *
PyGSL_Shadow_array(PyObject *shadow, PyObject *master,  enum pygsl_transform_mode mode)
{
	PyArrayObject * ret = NULL, *s=NULL, *m=NULL;
	int line = -1;
	const int type1 = PyGSL_TRANSFORM_MODE_SWITCH(mode, NPY_CDOUBLE, NPY_CFLOAT);
	const int type2 = PyGSL_TRANSFORM_MODE_SWITCH(mode, NPY_DOUBLE, NPY_FLOAT);
	FUNC_MESS_BEGIN();
	/* Check if I got a return array */
	if(!PyGSL_array_check(master)){
		line = __LINE__ - 1;
		goto fail;
	}

	m = (PyArrayObject *) master;
	assert(m);
	assert(PyArray_TYPE(m) == type1 || PyArray_TYPE(m) == type2);

	if(shadow == NULL){
		FUNC_MESS("Generating an output array");
		ret =  (PyArrayObject *) PyGSL_Copy_Array(m);
		if(ret == NULL){
			line = __LINE__ -2;
			goto fail;
		}
	} else {		
		if (shadow ==  master) {
			Py_INCREF(shadow);
			ret = m;
		}else{	
			FUNC_MESS("Copying input to output array");
			/* Check if it is an array of the approbriate size */
			s = (PyArrayObject *) shadow;
			if((PyGSL_array_check((PyObject *) s)) && (PyArray_NDIM(s) == 1) 
			   && (PyArray_TYPE(s) == PyArray_TYPE(m)) 
			   && (PyArray_DIM(s, 0) == PyArray_DIM(m, 0))){
				Py_INCREF(s);
				ret = (PyArrayObject *) s;
			} else {
				pygsl_error("The return array must be of approbriate size and type!", 
					  filename, __LINE__, GSL_EINVAL);
				line = __LINE__ -7;
				goto fail;
			}
			if(PyGSL_ERROR_FLAG(PyGSL_copy_array_to_array(s, m, mode)) != GSL_SUCCESS){
				line = __LINE__ -1;
				goto fail;			
			}
		}
	}
	FUNC_MESS_END();
	return ret;
  fail:
	FUNC_MESS("Fail");
	PyGSL_add_traceback(module, filename, __FUNCTION__, line);
	return NULL;
}

static int
PyGSL_guess_halfcomplex_length(PyArrayObject *a, int length, double eps,  enum pygsl_transform_mode mode)
{
	int n, call_n = -1;
	void *v;

	FUNC_MESS_BEGIN();

	assert(a);
	assert(PyArray_TYPE(a) == PyGSL_TRANSFORM_MODE_SWITCH(mode, NPY_CDOUBLE, NPY_CFLOAT));

	n = PyArray_DIM(a, 0);
	if(length == -1){
		/* length was not given, try to guess */
		v = PyArray_GETPTR1(a, n - 1);
		if(gsl_fcmp(PyGSL_TRANSFORM_MODE_SWITCH(mode, ((double *)v)[1], ((float *)v)[1]), 0,  eps) == 0){
			call_n = n*2-2;
		}else{
			/* 
			 * The last element was close to zero, thus I assume
			 *  that I got  original data of even length.
			 */
			call_n = n*2-1;
		}			
	}else if(length < -1){
		pygsl_error("The given length must be a positive number!",
			  __FILE__, __LINE__, GSL_EINVAL);
		return length;
	}else{
		call_n = length;
	}
	DEBUG_MESS(5, "Using a length of %d", call_n);
	FUNC_MESS_END();
	return call_n;

}

static int
PyGSL_Check_Array_Length(PyArrayObject *a, int call_n, int datamode, int n_type)
{
	int n_check = PyArray_DIM(a, 0);

	if (PyGSL_DEBUG_LEVEL()> 1)
	{
		int i, nd=0;
		
		nd = PyArray_NDIM(a);
		DEBUG_MESS(4, "Array nd = %d", nd);
		for(i = 0; i < nd; ++i){
			DEBUG_MESS(5, "Array dim[i] = %ld", PyArray_DIM(a, i));
		}
	}

	DEBUG_MESS(3, "Call Length %d, Array Length %d n_type %d", call_n, n_check, n_type);
	if(call_n > n_check * n_type)
		PyGSL_ERROR("Array size was not big enough!", GSL_ESANITY);


	DEBUG_MESS(3, "Check array type %d", PyArray_TYPE(a));
	switch(datamode){
	case MODE_DOUBLE:		
		if(PyArray_TYPE(a) != NPY_CDOUBLE &&  PyArray_TYPE(a) != NPY_DOUBLE)
			PyGSL_ERROR("Type not of (C)DOUBLE!", GSL_ESANITY);
		break;
	case MODE_FLOAT:
		if(PyArray_TYPE(a) != NPY_CFLOAT &&  PyArray_TYPE(a) != NPY_FLOAT)
			PyGSL_ERROR("Type not of (C)FLOAT!", GSL_ESANITY);
		break;
		PyGSL_ERROR("Unknown mode!", GSL_ESANITY);
	}
	return GSL_SUCCESS;
}
