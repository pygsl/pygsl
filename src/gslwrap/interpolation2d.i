/*
 * Author: Pierre Schnizer <schnizer@users.sourceforge.net> 2016
 * Date:   March 2016, 2025
 * $Id$
 */
%module interpolation2d_wrap
%feature ("autodoc", "3");
%include pygsl_compat.i

%rename(interp2d) pygsl_interp2d;
%rename(spline2d) pygsl_spline2d;

 /* numpy needs to be imported directly for the iterator */
%{
#include <pygsl/numpy_api_version.h>
//#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#include <numpy/arrayobject.h>

#include <gsl/gsl_interp2d.h>
#include <gsl/gsl_spline2d.h>
#include <pygsl/error_helpers.h>
#include <pygsl/block_helpers.h>

static PyObject *module = NULL;
%}

%init {
  // TODO: pygsl should return -1 on failure here
  init_pygsl();
  // swig uses a function here ...
  import_array1(-1);
  module = m;
}

%apply double *OUTPUT {double *z};

%include typemaps.i
%include gsl_error_typemap.i
%include gsl_block_typemaps.i

 /*
  * Python can manage memory: so lets keep references to the "registered array"
  * Thus for the user there is no difference in usage for the interpolation and
  * the spline object.
  *
  * The spline object keeps local copies of the arrays. Thus the interpolation
  * object can be more advantageous if large arrays are used.
  */
%{
struct _pygsl_interp2d{
	gsl_interp2d *interp;
	gsl_interp_accel * x_acc;
	gsl_interp_accel * y_acc;
	/* and to the appropriate data pointers */
	const double  * x_a;
	const double  * y_a;
	const double  * z_a;
	/* keep references to the object ... for memory managment */
	PyArrayObject * xa_obj;
	PyArrayObject * ya_obj;
	PyArrayObject * za_obj;
};
typedef struct _pygsl_interp2d pygsl_interp2d;

struct _pygsl_spline2d{
	gsl_spline2d *spline;
	gsl_interp_accel * x_acc;
	gsl_interp_accel * y_acc;
};
typedef struct _pygsl_spline2d pygsl_spline2d;

/*
 * The evaluations can be made using array objects as inputs. This function is
 * a bit longer, thus it is defined once and function pointers are provided,
 * which are then evaluated.
 *
 * First a structure is defined which combines the pointers to the data
 * structures, the call back, and a enum storing the information which kind of
 * callback is to be used.
 *
 * The function can handle  _eval and _eval_e "methods"
 */
 enum _pygsl_interp_spline_2d_type{
		PyGSL_INTERP2D_EVAL = 0,
		PyGSL_INTERP2D_EVAL_E,
		PyGSL_SPLINE2D_EVAL,
		PyGSL_SPLINE2D_EVAL_E
 };
struct _pygsl_interp_spline_2d{
	union{
		const pygsl_interp2d * py_interp;
		const pygsl_spline2d * py_spline;
	}str;
	union{
		int (*fint_e)(const gsl_interp2d * interp, const double xarr[],
			   const double yarr[], const double zarr[],
			   const double x, const double y, gsl_interp_accel* xa,
			   gsl_interp_accel* ya, double * z);

		double (*fint)(const gsl_interp2d * interp, const double xarr[],
			      const double yarr[], const double zarr[],
			      const double x, const double y, gsl_interp_accel* xa,
			      gsl_interp_accel* ya);

		int (*fsp_e)(const gsl_spline2d * sp,
			    const double x, const double y, gsl_interp_accel* xa,
			    gsl_interp_accel* ya, double * z);

		double (*fsp)(const gsl_spline2d * sp,
			     const double x, const double y, gsl_interp_accel* xa,
			     gsl_interp_accel* ya);
	}func;
  enum _pygsl_interp_spline_2d_type type;
};

typedef struct _pygsl_interp_spline_2d pygsl_interp_spline_2d_t;


/* Uses numpy iterator to evaluate the arrays */
static PyObject *
pygsl_interp2d_eval_array_func(const pygsl_interp_spline_2d_t obj, PyObject *x_o, PyObject *y_o)
{

	PyArrayObject *op[4] = {NULL, NULL, NULL, NULL};
	PyArrayObject *x_a = NULL, *y_a = NULL, *z_a = NULL, *e_a = NULL;
	PyArray_Descr* op_dtypes[4] = {NULL, NULL, NULL, NULL};
	PyObject *result = NULL;

	NpyIter *iter = NULL;
	NpyIter_IterNextFunc *iternext = NULL;
	npy_intp *inner_size, *strides;
	char **data_array;
	npy_uint32 flags;
	npy_uint32 op_flags[4] = {0,0,0,0};
	NPY_ORDER order = NPY_KEEPORDER;

	int line = __LINE__, with_flags = 0, nd = 0,  requires = 0;


	FUNC_MESS_BEGIN();

	op_flags[0] = NPY_ITER_READONLY;
	op_flags[1] = NPY_ITER_READONLY;
	op_flags[2] = NPY_ITER_WRITEONLY | NPY_ITER_ALLOCATE;
	op_flags[3] = NPY_ITER_WRITEONLY | NPY_ITER_ALLOCATE;

	op_dtypes[0] = NULL;
	op_dtypes[1] = NULL;
	op_dtypes[2] = PyArray_DescrFromType(NPY_DOUBLE);
	op_dtypes[3] = PyArray_DescrFromType(NPY_INT);

	/* most inner loop given below */
	flags = NPY_ITER_EXTERNAL_LOOP;

	/* which type of evaluation are we heading to ? */
	switch(obj.type){
	case PyGSL_INTERP2D_EVAL:
	case PyGSL_SPLINE2D_EVAL:
		with_flags = 0;
		break;

	case PyGSL_INTERP2D_EVAL_E:
	case PyGSL_SPLINE2D_EVAL_E:
		with_flags = 1;
		break;

	default:
		DEBUG_MESS(2, "eval type %d unknown", obj.type);
		line = __LINE__;
		pygsl_error("Unknown eval type", __FILE__, line, GSL_ESANITY);
		goto fail;
	}

	nd = 0;
	requires = 0;
	x_a = (PyArrayObject * ) PyArray_FromAny(x_o, PyArray_DescrFromType(NPY_DOUBLE), nd, nd, requires, NULL);
	if(x_a == NULL){
		line = __LINE__ - 2;
		goto fail;
	}

	nd = PyArray_NDIM(x_a);
	y_a = (PyArrayObject * ) PyArray_FromAny(y_o, PyArray_DescrFromType(NPY_DOUBLE), nd, nd, requires, NULL);
	if(y_a == NULL){
		line = __LINE__ - 2;
		goto fail;
	}

	op[0] = x_a;
	op[1] = y_a;
	op[2] = NULL;
	op[3] = NULL;

	/* methods  with "_e" return a flag depending on the data */
	iter = NpyIter_MultiNew(with_flags == 0 ? 3 : 4,
				op, flags, order, NPY_NO_CASTING, op_flags, op_dtypes);
	if (iter == NULL) {
		line = __LINE__ - 2 ;
		goto fail;
	}

	iternext = NpyIter_GetIterNext(iter, NULL);
	if(iternext == NULL){
		line = __LINE__ - 2;
		goto fail;
	}

	strides = NpyIter_GetInnerStrideArray(iter);
	if(strides == NULL){
		line = __LINE__ - 2;
		goto fail;
	}

	inner_size = NpyIter_GetInnerLoopSizePtr(iter);
	data_array = NpyIter_GetDataPtrArray(iter);

	do{
		npy_intp i, size = *inner_size;
		npy_intp x_stride, y_stride, z_stride, e_stride = 0;
		char * x_p, *y_p, *z_p, *e_p = NULL;

		x_p = data_array[0];
		y_p = data_array[1];
		z_p = data_array[2];
		e_p = (with_flags == 0) ? NULL: data_array[3];

		x_stride = strides[0];
		y_stride = strides[1];
		z_stride = strides[2];
		e_stride = (with_flags == 0) ? 0 : strides[3];

		/* inner loop */
		for(i = 0; i < size; ++i, x_p += x_stride, y_p += y_stride, z_p += z_stride, e_p += e_stride){
			double * x_d = (double *) x_p;
			double * y_d = (double *) y_p;
			double * z_d = (double *) z_p;
			int    * e_i = (int *) e_p;
			const pygsl_interp2d *intp = NULL;
			const pygsl_spline2d *sp = NULL;

			switch(obj.type){
			case PyGSL_INTERP2D_EVAL:
				intp = obj.str.py_interp;
				*z_d = obj.func.fint(intp->interp, intp->x_a, intp->y_a, intp->z_a, *x_d, *y_d, intp->x_acc, intp->y_acc);
				break;

			case PyGSL_SPLINE2D_EVAL:
				sp = obj.str.py_spline;
				*z_d = obj.func.fsp(sp->spline, *x_d, *y_d, sp->x_acc, sp->y_acc);
				break;

			case PyGSL_INTERP2D_EVAL_E:
				intp = obj.str.py_interp;
				*e_i =  obj.func.fint_e(intp->interp, intp->x_a, intp->y_a, intp->z_a, *x_d, *y_d, intp->x_acc, intp->y_acc, z_d);
				break;

			case PyGSL_SPLINE2D_EVAL_E:
				sp = obj.str.py_spline;
				*e_i = obj.func.fsp_e(sp->spline, *x_d, *y_d, sp->x_acc, sp->y_acc, z_d);
				break;
			}
		}
	}while(iternext(iter));

	Py_DECREF(x_a);
	Py_DECREF(y_a);

	z_a = NpyIter_GetOperandArray(iter)[2];
	Py_INCREF(z_a);

	if(with_flags == 0){
		result = (PyObject *)z_a;
	}else{
		e_a = NpyIter_GetOperandArray(iter)[3];
		Py_INCREF(e_a);
		result = PyTuple_New(2);
		if(result == NULL){
			line = __LINE__ - 1;
			goto fail;
		}
		PyTuple_SET_ITEM(result, 0, (PyObject *)z_a);
		z_a = NULL;
		PyTuple_SET_ITEM(result, 1,  (PyObject *)e_a);
		e_a = NULL;
	}

	return (PyObject *) result;

  fail:
	Py_XDECREF(x_a);
	Py_XDECREF(y_a);
	Py_XDECREF(z_a);
	Py_XDECREF(e_a);
	Py_XDECREF(result);
	PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
	return NULL;
}

/* required at clean up and for any call to init */
void pygsl_interp2d_free_array_objects(pygsl_interp2d *self)
{
	if(self == NULL){
		DEBUG_MESS(2, "self: %p == NULL: could not free arrays as expected!"
			   "potential memory leak", (void *) self);
		return;
	}
	self->x_a = NULL;
	self->y_a = NULL;
	self->z_a = NULL;

	/* give back the references */
	Py_XDECREF(self->xa_obj);
	Py_XDECREF(self->ya_obj);
	Py_XDECREF(self->za_obj);


	self->xa_obj = NULL;
	self->ya_obj = NULL;
	self->za_obj = NULL;

}

void
pygsl_interp2d_free_all(pygsl_interp2d *self)
{
	if(self == NULL){
		return;
	}
	if(self->interp != NULL){
		gsl_interp2d_free(self->interp);
	}
	self->interp = NULL;
	pygsl_interp2d_free_array_objects(self);

	if(self->x_acc){
		gsl_interp_accel_free(self->x_acc);
	}
	if(self->y_acc){
		gsl_interp_accel_free(self->y_acc);
	}
	free(self);
}

void
pygsl_spline2d_free_all(pygsl_spline2d *self)
{
	if(self == NULL){
		return;
	}
	if(self->spline != NULL){
		gsl_spline2d_free(self->spline);
	}
	self->spline = NULL;
	if(self->x_acc){
		gsl_interp_accel_free(self->x_acc);
	}
	if(self->y_acc){
		gsl_interp_accel_free(self->y_acc);
	}
	free(self);
}
%}

typedef struct
{
     %immutable;
}pygsl_interp2d;

typedef struct
{
     %immutable;
}pygsl_spline2d;


/*
 * The evaluation methods are defined twice:
 * 1. as a simple call.
 * 2. with an suffix _array: these take as arguments arrays and use a numpy
 *    iterator to evaluate it. Starting an iterator for a single call could
 *    be to costly, thus both methods are implemented. To be bench marked
 */
#define _PyGSL_SWIG_EVAL_ARRAY(fname)                           \
	double fname(const double x, const double y){		\
		return gsl_interp2d_ ## fname(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc); \
	}                                                       \
        PyObject* fname ## _array(PyObject * x, PyObject * y){	\
		pygsl_interp_spline_2d_t obj;			\
		obj.str.py_interp = self;			\
		obj.type = PyGSL_INTERP2D_EVAL;		        \
		obj.func.fint = gsl_interp2d_ ## fname;		\
		return pygsl_interp2d_eval_array_func(obj, x, y);\
	}

#define _PyGSL_SWIG_EVAL_E_ARRAY(fname)                         \
	gsl_error_flag_drop fname(const double x, const double y, double *z){ \
		return gsl_interp2d_ ## fname (self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc, z); \
	}                                                       \
        PyObject* fname ## _array(PyObject * x, PyObject * y){	\
		pygsl_interp_spline_2d_t obj;			\
		obj.str.py_interp = self;			\
		obj.type = PyGSL_INTERP2D_EVAL_E;	        \
		obj.func.fint_e = gsl_interp2d_ ## fname;	\
		return pygsl_interp2d_eval_array_func(obj, x, y);\
	}


#define _PyGSL_SWIG_SPLINE_EVAL_ARRAY(fname)                    \
	double fname(const double x, const double y){		\
		return gsl_spline2d_ ## fname(self->spline, x, y, self->x_acc, self->y_acc); \
	}                                                       \
        PyObject* fname ## _array(PyObject * x, PyObject * y){	\
		pygsl_interp_spline_2d_t obj;			\
		obj.str.py_spline = self;			\
		obj.type = PyGSL_SPLINE2D_EVAL;		        \
		obj.func.fsp = gsl_spline2d_ ## fname;		\
		return pygsl_interp2d_eval_array_func(obj, x, y);\
	}

#define _PyGSL_SWIG_SPLINE_EVAL_E_ARRAY(fname)                  \
	gsl_error_flag_drop fname(const double x, const double y, double *z){ \
		return gsl_spline2d_ ## fname (self->spline, x, y, self->x_acc, self->y_acc, z); \
	}                                                       \
        PyObject* fname ## _array(PyObject * x, PyObject * y){	\
		pygsl_interp_spline_2d_t obj;			\
		obj.str.py_spline = self;			\
		obj.type = PyGSL_SPLINE2D_EVAL_E;		\
		obj.func.fsp_e = gsl_spline2d_ ## fname;	\
		return pygsl_interp2d_eval_array_func(obj, x, y);\
	}


%extend pygsl_spline2d{
	pygsl_spline2d(const gsl_interp2d_type * T, const size_t x_size,
		      const size_t y_size){
		pygsl_spline2d *p  = NULL;

		FUNC_MESS_BEGIN();
		p = (pygsl_spline2d *) calloc(1, sizeof(pygsl_interp2d));
		if(p == NULL)
			goto fail;

		p->x_acc = NULL;
		p->y_acc = NULL;
		p->spline = NULL;

		p->spline = gsl_spline2d_alloc(T, x_size, y_size);
		if(p->spline == NULL){
			pygsl_error("Failed to allocate acceleration memory for gsl_spline2d",
			   __FILE__, __LINE__, GSL_EFAILED);
			goto fail;
		}

		p->x_acc = gsl_interp_accel_alloc();
		if(p->x_acc == NULL){
			goto fail;
		}
		p->y_acc = gsl_interp_accel_alloc();
		if(p->y_acc == NULL){
			goto fail;
		}

		FUNC_MESS_END();
		return p;

	  fail:
		pygsl_spline2d_free_all(p);
		return NULL;
	}

	~pygsl_spline2d(void){
		pygsl_spline2d_free_all(self);
	}

	gsl_error_flag_drop reset(void){
		int flag = GSL_EFAILED, line = __LINE__;

		flag = gsl_interp_accel_reset(self->x_acc);
		if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
			line = __LINE__ - 2;
			goto fail;
		}

		flag = gsl_interp_accel_reset(self->y_acc);
		if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
			line = __LINE__ - 2;
			goto fail;
		}
		return GSL_SUCCESS;

	  fail:
		PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
		return flag;

	}

	const char * name(void){
		return gsl_spline2d_name(self->spline);
	}

	size_t min_size(void){
		return gsl_spline2d_min_size(self->spline);
	}

        gsl_error_flag_drop init(PyObject *x_o, PyObject * y_o, PyObject * z_o){
		PyGSL_array_index_t x_size, y_size;
		PyArrayObject *x_a = NULL, *y_a = NULL, *z_a = NULL;
		double *x_d = NULL, *y_d = NULL, *z_d = NULL;
		size_t xt_size, yt_size;
		int flag = GSL_EFAILED, line = __LINE__;


		xt_size = self->spline->interp_object.xsize;
		yt_size = self->spline->interp_object.ysize;
		x_size = xt_size;
		y_size = yt_size;
		/* signed x_size */
		if(x_size < 0){
			line = __LINE__ - 1;
			pygsl_error("x_size <0", __FILE__, line, GSL_ESANITY);
			goto fail;
		}
		if(y_size < 0){
			line = __LINE__ - 1;
			pygsl_error("y_size <0", __FILE__, line, GSL_ESANITY);
			goto fail;
		}

		x_a = PyGSL_vector_check(x_o, x_size, PyGSL_DARRAY_CINPUT(1), NULL, NULL);
		if(x_a == NULL){
			line = __LINE__ - 1;
			goto fail;
		}
		y_a = PyGSL_vector_check(y_o, y_size, PyGSL_DARRAY_CINPUT(2), NULL, NULL);
		if(y_a == NULL){
			line = __LINE__ - 1;
			goto fail;
		}
		z_a = PyGSL_matrix_check(z_o, x_size, y_size, PyGSL_DARRAY_CINPUT(3), NULL, NULL, NULL);
		if(z_a == NULL){
			line = __LINE__ - 1;
			goto fail;
		}

		x_d = (double *) PyArray_DATA(x_a);
		y_d = (double *) PyArray_DATA(y_a);
		z_d = (double *) PyArray_DATA(z_a);

		flag = gsl_spline2d_init(self->spline, x_d, y_d, z_d, xt_size, yt_size);
		if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
			goto fail;
		}
		Py_DECREF(x_a);
		Py_DECREF(y_a);
		Py_DECREF(z_a);
		return GSL_SUCCESS;

	  fail:
		Py_XDECREF(x_a);
		Py_XDECREF(y_a);
		Py_XDECREF(z_a);
		PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
		return flag;
	}

	/* in my opinion spline2d get and set should use z_arr */
	double get(const size_t i, const size_t j){
		return gsl_spline2d_get(self->spline, self->spline->zarr, i, j);
	}

	gsl_error_flag_drop set(const size_t i, const size_t j, double z){
		return gsl_spline2d_set(self->spline, self->spline->zarr, i, j, z);
	}

	_PyGSL_SWIG_SPLINE_EVAL_ARRAY(eval)
	_PyGSL_SWIG_SPLINE_EVAL_ARRAY(eval_deriv_x)
	_PyGSL_SWIG_SPLINE_EVAL_ARRAY(eval_deriv_y)
	_PyGSL_SWIG_SPLINE_EVAL_ARRAY(eval_deriv_xx)
	_PyGSL_SWIG_SPLINE_EVAL_ARRAY(eval_deriv_xy)
	_PyGSL_SWIG_SPLINE_EVAL_ARRAY(eval_deriv_yy)

	_PyGSL_SWIG_SPLINE_EVAL_E_ARRAY(eval_e)
	_PyGSL_SWIG_SPLINE_EVAL_E_ARRAY(eval_deriv_x_e)
	_PyGSL_SWIG_SPLINE_EVAL_E_ARRAY(eval_deriv_y_e)
	_PyGSL_SWIG_SPLINE_EVAL_E_ARRAY(eval_deriv_xx_e)
	_PyGSL_SWIG_SPLINE_EVAL_E_ARRAY(eval_deriv_xy_e)
	_PyGSL_SWIG_SPLINE_EVAL_E_ARRAY(eval_deriv_yy_e)

}

%extend pygsl_interp2d{
	pygsl_interp2d(const gsl_interp2d_type * T, const size_t x_size,
		      const size_t y_size){
		pygsl_interp2d *p  = NULL;

		p = (pygsl_interp2d *) calloc(1, sizeof(pygsl_interp2d));
		if(p == NULL){
			pygsl_error("Failed to allocate acceleration memory for pygsl_interp struct",
			   __FILE__, __LINE__, GSL_EFAILED);
			return NULL;
		}

		p->x_a = NULL;
		p->y_a = NULL;
		p->z_a = NULL;

		p->xa_obj = NULL;
		p->ya_obj = NULL;
		p->za_obj = NULL;

		p->x_acc = NULL;
		p->y_acc = NULL;

		p->interp = NULL;

		p->x_acc = gsl_interp_accel_alloc();
		if(p->x_acc == NULL){
			goto fail;
		}
		p->y_acc = gsl_interp_accel_alloc();
		if(p->y_acc == NULL){
			goto fail;
		}

		p->interp = gsl_interp2d_alloc(T, x_size, y_size);
		if(p->interp == NULL){
			pygsl_error("Failed to allocate acceleration memory for gsl_interp2D",
			   __FILE__, __LINE__, GSL_EFAILED);
			goto fail;
		}
		return p;

	  fail:
		pygsl_interp2d_free_all(p);
		return NULL;
	}

	~pygsl_interp2d(){
		pygsl_interp2d_free_all(self);
	}

	gsl_error_flag_drop reset(void){
		int flag = GSL_EFAILED, line = __LINE__;

		flag = gsl_interp_accel_reset(self->x_acc);
		if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
			line = __LINE__ - 2;
			goto fail;
		}

		flag = gsl_interp_accel_reset(self->y_acc);
		if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
			line = __LINE__ - 2;
			goto fail;
		}
		return GSL_SUCCESS;

	  fail:
		PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
		return flag;

	}

	const char * name(void){
		return gsl_interp2d_name(self->interp);
	}

	size_t min_size(void){
		return gsl_interp2d_min_size(self->interp);
	}

        gsl_error_flag_drop init(PyObject *x_o, PyObject * y_o, PyObject * z_o){
		PyGSL_array_index_t x_size, y_size;
		size_t xt_size, yt_size;
		int flag = GSL_EFAILED, line = __LINE__;

		/* dispose references to old arrays */
		pygsl_interp2d_free_array_objects(self);

		xt_size = self->interp->xsize;
		yt_size = self->interp->ysize;
		x_size = xt_size;
		y_size = yt_size;

		/* signed x_size */
		if(x_size < 0){
			line = __LINE__ - 1;
			pygsl_error("x_size <0", __FILE__, line, GSL_ESANITY);
			goto fail;
		}
		if(y_size < 0){
			line = __LINE__ - 1;
			pygsl_error("y_size <0", __FILE__, line, GSL_ESANITY);
			goto fail;
		}

		self->xa_obj = PyGSL_vector_check(x_o, x_size, PyGSL_DARRAY_CINPUT(1), NULL, NULL);
		if(self->xa_obj == NULL){
			line = __LINE__ - 1;
			goto fail;
		}
		self->ya_obj = PyGSL_vector_check(y_o, y_size, PyGSL_DARRAY_CINPUT(2), NULL, NULL);
		if(self->ya_obj == NULL){
			line = __LINE__ - 1;
			goto fail;
		}
		self->za_obj = PyGSL_matrix_check(z_o, x_size, y_size, PyGSL_DARRAY_CINPUT(3), NULL, NULL, NULL);
		if(self->za_obj == NULL){
			line = __LINE__ - 1;
			goto fail;
		}

		self->x_a = (const double *) PyArray_DATA(self->xa_obj);
		self->y_a = (const double *) PyArray_DATA(self->ya_obj);
		self->z_a = (const double *) PyArray_DATA(self->za_obj);

		flag = gsl_interp2d_init(self->interp, self->x_a, self->y_a, self->z_a, xt_size, yt_size);
		if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
			goto fail;
		}
		return GSL_SUCCESS;

	  fail:
		PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
		pygsl_interp2d_free_array_objects(self);
		return flag;
	}

	size_t idx(const size_t i, const size_t j){
		return gsl_interp2d_idx(self->interp, i, j);
	}


	/* don't implement set ... the arrays are used as read only ! */
	double get(const size_t i, const size_t j){
		return gsl_interp2d_get(self->interp, self->z_a, i, j);
	}

	_PyGSL_SWIG_EVAL_ARRAY(eval)
	_PyGSL_SWIG_EVAL_ARRAY(eval_extrap)
	_PyGSL_SWIG_EVAL_ARRAY(eval_deriv_x)
	_PyGSL_SWIG_EVAL_ARRAY(eval_deriv_y)
	_PyGSL_SWIG_EVAL_ARRAY(eval_deriv_xx)
	_PyGSL_SWIG_EVAL_ARRAY(eval_deriv_xy)
	_PyGSL_SWIG_EVAL_ARRAY(eval_deriv_yy)

	_PyGSL_SWIG_EVAL_E_ARRAY(eval_e)
	_PyGSL_SWIG_EVAL_E_ARRAY(eval_e_extrap)
	_PyGSL_SWIG_EVAL_E_ARRAY(eval_deriv_x_e)
	_PyGSL_SWIG_EVAL_E_ARRAY(eval_deriv_y_e)
	_PyGSL_SWIG_EVAL_E_ARRAY(eval_deriv_xx_e)
	_PyGSL_SWIG_EVAL_E_ARRAY(eval_deriv_xy_e)
	_PyGSL_SWIG_EVAL_E_ARRAY(eval_deriv_yy_e)

};

const gsl_interp2d_type * gsl_interp2d_bilinear;
const gsl_interp2d_type * gsl_interp2d_bicubic;
