%module swig_test
%{

#include <gsl/gsl_errno.h>
#include <pygsl/utils.h>

struct _swig_test_st {
    int ival;
    double dval;
};

typedef struct _swig_test_st swig_test_st;

static swig_test_st* swig_test_st_alloc(void) {
    swig_test_st *p =  NULL;
    p = (swig_test_st *) calloc(1, sizeof(swig_test_st));
    if(!p){ return p; }
    p->ival = 355;
    p->dval = 113.0;
    return p;
}

static void swig_test_st_free(swig_test_st* p) { free(p); }

static int swig_test_access_ival(swig_test_st* self, int *p)
{
    assert(p);
    *p = self->ival;
    return GSL_SUCCESS;
}

static int swig_test_access_dval(swig_test_st* self, double *p)
{
    assert(p);
    *p = self->dval;
    return GSL_SUCCESS;
}


static int swig_test_access_ival_status(swig_test_st* self, int status, int *p)
{
    assert(p);
    *p = self->ival;
    return status;
}


int
pygsl_swig_test_return_errno(const int t_errno)
{
    FUNC_MESS_BEGIN();
    DEBUG_MESS(2, "Passed errno = %d, should convert to exception if > 0", t_errno);
    FUNC_MESS_END();
    return t_errno;
}

int
pygsl_swig_test_return_errno_with_double(const double val)
{
    FUNC_MESS_BEGIN();
    FUNC_MESS_END();
    return (int) val;
}
#ifdef SWIG_BUILTIN
#undef SWIG_BUILTIN
#endif
#define SWIG_BUILTIN 1
%}

%include pygsl_compat.i
%include gsl_error_typemap.i
%include typemaps.i


%init %{
  init_pygsl();
  pygsl_module_for_error_treatment = m;

  fprintf(stderr, "PyGSL_API = 0x %p, debug level %d\n", (void *) PyGSL_API,  PyGSL_DEBUG_LEVEL());
  DEBUG_MESS(2, "testing debug level module at %p", (void *) m);
  fprintf(stderr, "done!! \n");
%}


typedef struct{} swig_test_st;

%extend swig_test_st{
    swig_test_st(void) { return swig_test_st_alloc(); }
    ~swig_test_st() { return swig_test_st_free(self); }

    gsl_error_flag_drop get_dval(double *OUTPUT){ return swig_test_access_dval(self, OUTPUT); }
    gsl_error_flag_drop get_ival(int *OUTPUT){ return swig_test_access_ival(self, OUTPUT); }
    gsl_error_flag_drop get_ival_status(int status, int *OUTPUT){ return swig_test_access_ival_status(self, status, OUTPUT); }
};

gsl_error_flag_drop
pygsl_swig_test_return_errno(const int t_errno);

gsl_error_flag_drop
pygsl_swig_test_return_errno_with_double(const double val);
