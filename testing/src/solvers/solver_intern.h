#ifndef _PYGSL_SOLVER_INTERN_H_
#define _PYGSL_SOLVER_INTERN_H_ 1

#define _PyGSL_SOLVER_API_MODULE 1
#include <pygsl/solver.h>
#undef _PyGSL_SOLVER_API_MODULE

#include <pygsl/general_helpers.h>
#include <pygsl/block_helpers.h>
#include <pygsl/function_helpers.h>
#include <setjmp.h>
#include <gsl/gsl_math.h>

/*
 * Collect all element accessor methods which just need a pointer to the struct
 * and return a value.
 */
struct _ElementAccessor{
     int_m_t method;
     const char * name;
};


static PyTypeObject PyGSL_solver_pytype;
#define PyGSL_solver_check(ob) ((ob)->ob_type == &PyGSL_solver_pytype)
#define _PyGSL_solver_n_init PyGSL_solver_n_init


static PyGSL_solver* 
_PyGSL_solver_init(const struct _SolverStatic *mstatic);



static int
PyGSL_solver_set_called(PyGSL_solver *self);

#define PyGSL_SOLVER_SET_CALLED(ob) \
        (((ob)->set_called == 1) ? GSL_SUCCESS: PyGSL_solver_set_called((ob)))

static int
PyGSL_solver_func_set(PyGSL_solver *self, PyObject *args, PyObject *f,
		       PyObject *df, PyObject *fdf);


#if 0
static PyObject *
_PyGSL_solver_np_init(PyObject *self, PyObject *args, const solver_alloc_struct * alloc);

static PyObject *
_PyGSL_solver_i_vvdd(PyObject * self, PyObject * args, int_f_vvdd_t func);

#endif
#endif /* _PYGSL_SOLVER_INTERN_H_ */
