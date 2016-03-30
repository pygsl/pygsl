
%{
%}

%{
#include <gsl/gsl_interp2d.h>
#include <gsl/gsl_spline2d.h>

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
	size_t x_size;
	size_t y_size;
};
typedef struct _pygsl_interp2d pygsl_interp2d;


typedef int (pygsl_interp2d_eval_e_t)(const gsl_interp2d * interp, const double xarr[],
				       const double yarr[], const double zarr[],
				       const double x, const double y, gsl_interp_accel* xa,
				       gsl_interp_accel* ya, double * z);

typedef double (pygsl_interp2d_eval_t)(const gsl_interp2d * interp, const double xarr[],
					const double yarr[], const double zarr[],
					const double x, const double y, gsl_interp_accel* xa,
					gsl_interp_accel* ya);


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

static PyObject *
	pygsl_interp2d_eval_e_vector_func(pygsl_interp2d *self, PyObject *x_o, PyObject *y_o, pygsl_interp2d_eval_e_t *eval)
{

	PyArrayObject *x_a = NULL, *y_a = NULL, *z_a = NULL, *e_a = NULL;
	PyObject *result = NULL;
	double *x_d = NULL, *y_d = NULL, *z_d = NULL; 
	PyGSL_array_index_t cnt, n_elements;
	int line = __LINE__, flag = GSL_SUCCESS, is_vector = 0, *e_i = NULL;

	x_a = PyGSL_vector_check(x_o, -1, PyGSL_DARRAY_INPUT(2), NULL, NULL);
	if(x_a == NULL){
		line = __LINE__ - 1;
		goto fail;
	}
	n_elements = PyArray_DIM(x_a, 0);

	y_a = PyGSL_vector_check(y_o, n_elements, PyGSL_DARRAY_INPUT(3), NULL, NULL);
	if(y_a == NULL){
		line = __LINE__ - 1;
		goto fail;
	}

	z_a = PyGSL_New_Array(1, &n_elements, NPY_DOUBLE);
	if(z_a == NULL){
		line = __LINE__ - 1;
		goto fail;
	}

	e_a = PyGSL_New_Array(1, &n_elements, NPY_DOUBLE);
	if(e_a == NULL){
		line = __LINE__ - 1;
		goto fail;
	}

	
	for(cnt = 0; cnt < n_elements; ++cnt){
		x_d = (double *) PyArray_GETPTR1(x_a, cnt);
		y_d = (double *) PyArray_GETPTR1(y_a, cnt);
		z_d = (double *) PyArray_GETPTR1(z_a, cnt);
		e_i = (int *) PyArray_GETPTR1(e_a, cnt);
		flag = eval(self->interp, self->x_a, self->y_a, self->z_a, *x_d, *y_d, self->x_acc, self->y_acc, z_d);
		*e_i = flag;
	}
	
	Py_XDECREF(x_a);
	Py_XDECREF(y_a);

	result = PyTuple_New(2);
	if(result == NULL){
		line = __LINE__ - 1;
		goto fail;
	}
	PyTuple_SET_ITEM(result, 0, z_a);
	z_a = NULL;
	PyTuple_SET_ITEM(result, 1, e_a);
	e_a = NULL;

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

static PyObject *
	pygsl_interp2d_eval_vector_func(pygsl_interp2d *self, PyObject *x, PyObject *y, pygsl_interp2d_eval_t *eval)
{

	PyArrayObject *x_a = NULL, *y_a = NULL, *z_a = NULL;
	double *x_d = NULL, *y_d = NULL, *z_d = NULL; 
	PyGSL_array_index_t cnt, n_elements;
	int line = __LINE__, flag = GSL_SUCCESS, is_vector = 0;

	x_a = PyGSL_vector_check(x, -1, PyGSL_DARRAY_INPUT(2), NULL, NULL);
	if(x_a == NULL){
		line = __LINE__ - 1;
		goto fail;
	}
	n_elements = PyArray_DIM(x_a, 0);

	y_a = PyGSL_vector_check(y, n_elements, PyGSL_DARRAY_INPUT(3), NULL, NULL);
	if(y_a == NULL){
		line = __LINE__ - 1;
		goto fail;
	}

	z_a = PyGSL_New_Array(1, &n_elements, NPY_DOUBLE);
	if(z_a == NULL){
		line = __LINE__ - 1;
		goto fail;
	}

	
	for(cnt = 0; cnt < n_elements; ++cnt){
		x_d = (double *) PyArray_GETPTR1(x_a, cnt);
		y_d = (double *) PyArray_GETPTR1(y_a, cnt);
		z_d = (double *) PyArray_GETPTR1(z_a, cnt);
		*z_d = eval(self->interp, self->x_a, self->y_a, self->z_a, *x_d, *y_d, self->x_acc, self->y_acc);
	}
	
	Py_XDECREF(x_a);
	Py_XDECREF(y_a);

	return (PyObject *) z_a;

  fail:
	Py_XDECREF(x_a);
	Py_XDECREF(y_a);
	Py_XDECREF(z_a);
	PyGSL_add_traceback(module, __FILE__, __FUNCTION__, line);
	return NULL;
}



%}

typedef struct
{     
     %immutable;     
}pygsl_interp2d;

%apply double *OUTPUT {double *z};

%extend pygsl_interp2d{
	pygsl_interp2d(const gsl_interp2d_type * T, const size_t x_size, 
		      const size_t y_size){
		pygsl_interp2d *p  = NULL;
		gsl_interp_accel *x_acc = NULL, *y_acc = NULL;

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
		p->x_size = x_size;
		p->y_size = y_size;
		return p;

	  fail:		
		if(p->interp){
			gsl_interp2d_free(p->interp);
		}
		if(p->x_acc){
			gsl_interp_accel_free(p->x_acc);
		}
		if(p->y_acc){
			gsl_interp_accel_free(p->y_acc);
		}
		if(p){
			free(p);
		}	
		
		return NULL;
	}

	~pygsl_interp2d(){
		if(self->interp != NULL){
			gsl_interp2d_free(self->interp);
		}
		self->interp = NULL;
		pygsl_interp2d_free_array_objects(self);

		free(self);
	}

	gsl_error_flag_drop reset(void){
		int flag = GSL_EFAILED, line = __LINE__;

		flag = gsl_interp_accel_reset(self->x_acc);
		if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
			goto fail;
		}

		flag = gsl_interp_accel_reset(self->y_acc);
		if(PyGSL_ERROR_FLAG(flag) != GSL_SUCCESS){
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
		int flag = GSL_EFAILED, line = __LINE__;

		/* dispose references to old arrays */
		pygsl_interp2d_free_array_objects(self);
		
		x_size = self->x_size;
		y_size = self->y_size;

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

		self->x_a = PyArray_DATA(self->xa_obj);
		if(self->x_a == NULL){ 
			line = __LINE__ - 1;
			goto fail; 
		}
		self->y_a = PyArray_DATA(self->ya_obj);
		if(self->y_a == NULL){ 
			line = __LINE__ - 1;
			goto fail; 
		}
		self->z_a = PyArray_DATA(self->za_obj);
		if(self->z_a == NULL){ 
			line = __LINE__ - 1;
			goto fail; 
		}

		flag = gsl_interp2d_init(self->interp, self->x_a, self->y_a, self->z_a, self->x_size, self->y_size);
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

	double get(const size_t i, const size_t j){
		return gsl_interp2d_get(self->interp, self->z_a, i, j);
	}

	/* don't implement set ... arrays are used as read only ! */

	double eval(const double x, const double y){
		return gsl_interp2d_eval(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc);
	}
	double eval_extrap(const double x, const double y){
		return gsl_interp2d_eval_extrap(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc);
	}
	double eval_deriv_x(const double x, const double y){
		return gsl_interp2d_eval_deriv_x(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc);
	}
	double eval_deriv_y(const double x, const double y){
		return gsl_interp2d_eval_deriv_y(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc);
	}
	double eval_deriv_xx(const double x, const double y){
		return gsl_interp2d_eval_deriv_xx(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc);
	}
	double eval_deriv_xy(const double x, const double y){
		return gsl_interp2d_eval_deriv_xy(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc);
	}
	double eval_deriv_yy(const double x, const double y){
		return gsl_interp2d_eval_deriv_yy(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc);
	}
	gsl_error_flag_drop eval_e(const double x, const double y, double *z){
		return gsl_interp2d_eval_e(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc,  z);
	}
	gsl_error_flag_drop eval_e_extrap(const double x, const double y, double *z){
		return gsl_interp2d_eval_e_extrap(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc,  z);
	}
	gsl_error_flag_drop eval_deriv_x_e(const double x, const double y, double *z){
		return gsl_interp2d_eval_deriv_x_e(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc,  z);
	}
	gsl_error_flag_drop eval_deriv_y_e(const double x, const double y, double *z){
		return gsl_interp2d_eval_deriv_y_e(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc,  z);
	}
	gsl_error_flag_drop eval_deriv_xx_e(const double x, const double y, double *z){
		return gsl_interp2d_eval_deriv_xx_e(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc,  z);
	}
	gsl_error_flag_drop eval_deriv_xy_e(const double x, const double y, double *z){
		return gsl_interp2d_eval_deriv_xy_e(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc,  z);
	}
	gsl_error_flag_drop eval_deriv_yy_e(const double x, const double y, double *z){
		return gsl_interp2d_eval_deriv_yy_e(self->interp, self->x_a, self->y_a, self->z_a, x, y, self->x_acc, self->y_acc,  z);
	}
	
	PyObject* eval_vector(PyObject * x, PyObject * y){
		return pygsl_interp2d_eval_vector_func(self, x, y, gsl_interp2d_eval);
	}

	PyObject* eval_extrap_vector(PyObject * x, PyObject * y){
		return pygsl_interp2d_eval_vector_func(self, x, y, gsl_interp2d_eval_extrap);
	}

	PyObject* eval_deriv_x_vector(PyObject * x, PyObject * y){
		return pygsl_interp2d_eval_vector_func(self, x, y, gsl_interp2d_eval_deriv_x);
	}

	PyObject* eval_deriv_y_vector(PyObject * x, PyObject * y){
		return pygsl_interp2d_eval_vector_func(self, x, y, gsl_interp2d_eval_deriv_y);
	}

	PyObject* eval_deriv_xx_vector(PyObject * x, PyObject * y){
		return pygsl_interp2d_eval_vector_func(self, x, y, gsl_interp2d_eval_deriv_xx);
	}

	PyObject* eval_deriv_xy_vector(PyObject * x, PyObject * y){
		return pygsl_interp2d_eval_vector_func(self, x, y, gsl_interp2d_eval_deriv_xy);
	}
	PyObject* eval_deriv_yy_vector(PyObject * x, PyObject * y){
		return pygsl_interp2d_eval_vector_func(self, x, y, gsl_interp2d_eval_deriv_yy);
	}
};

%rename(interp2d) pygsl_interp2d;
const gsl_interp2d_type * gsl_interp2d_bilinear;
const gsl_interp2d_type * gsl_interp2d_bicubic;
