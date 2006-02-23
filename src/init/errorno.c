/*
 * This module must not depend on any other as it is needed during the startup
 * of pygsl.
 *
 * Thus no use of traceback or any error converting function!
 */
#include <Python.h>
#include <gsl/gsl_errno.h>
#include <pygsl/errorno.h>

struct gsl_errors{
     const char * name;
     int errorno;
};

static struct gsl_errors errors [] = {
     {"GSL_SUCCESS"  , GSL_SUCCESS  },
     {"GSL_FAILURE"  , GSL_FAILURE  },
     {"GSL_CONTINUE" , GSL_CONTINUE },
     {"GSL_EDOM"     , GSL_EDOM     },
     {"GSL_ERANGE"   , GSL_ERANGE   },
     {"GSL_EFAULT"   , GSL_EFAULT   },
     {"GSL_EINVAL"   , GSL_EINVAL   },
     {"GSL_EFAILED"  , GSL_EFAILED  },
     {"GSL_EFACTOR"  , GSL_EFACTOR  },
     {"GSL_ESANITY"  , GSL_ESANITY  },
     {"GSL_ENOMEM"   , GSL_ENOMEM   },
     {"GSL_EBADFUNC" , GSL_EBADFUNC },
     {"GSL_ERUNAWAY" , GSL_ERUNAWAY },
     {"GSL_EMAXITER" , GSL_EMAXITER },
     {"GSL_EZERODIV" , GSL_EZERODIV },
     {"GSL_EBADTOL"  , GSL_EBADTOL  },
     {"GSL_ETOL"     , GSL_ETOL     },
     {"GSL_EUNDRFLW" , GSL_EUNDRFLW },
     {"GSL_EOVRFLW"  , GSL_EOVRFLW  },
     {"GSL_ELOSS"    , GSL_ELOSS    },
     {"GSL_EROUND"   , GSL_EROUND   },
     {"GSL_EBADLEN"  , GSL_EBADLEN  },
     {"GSL_ENOTSQR"  , GSL_ENOTSQR  },
     {"GSL_ESING"    , GSL_ESING    },
     {"GSL_EDIVERGE" , GSL_EDIVERGE },
     {"GSL_EUNSUP"   , GSL_EUNSUP   },
     {"GSL_EUNIMPL"  , GSL_EUNIMPL  },
     {"GSL_ECACHE"   , GSL_ECACHE   },
     {"GSL_ETABLE"   , GSL_ETABLE   },
     {"GSL_ENOPROG"  , GSL_ENOPROG  },
     {"GSL_ENOPROGJ" , GSL_ENOPROGJ },
     {"GSL_ETOLF"    , GSL_ETOLF    },
     {"GSL_ETOLX"    , GSL_ETOLX    },
     {"GSL_ETOLG"    , GSL_ETOLG    },
     {"GSL_EOF"      , GSL_EOF      },
     {"PyGSL_ESTRIDE", PyGSL_ESTRIDE},
     {NULL, 0}
};


static int
PyGSL_add_errors(PyObject *dict, struct gsl_errors *errors)
{
     PyObject *item;
     struct gsl_errors *p;

     for(p = errors; p->name != NULL; ++p){
	  item = PyInt_FromLong(p->errorno);
	  if(item == NULL){
	       fprintf(stderr, "Failed to add error %d with name %s", 
		       p->errorno, p->name);
	       return GSL_ESANITY;
	  }
	  if(PyDict_SetItemString(dict, p->name, item) != 0){
	       fprintf(stderr, "Failed to add error item %p with error %d with name %s",
		       item, p->errorno, p->name);
	       return GSL_ESANITY;
	  }
     }
     return GSL_SUCCESS;
}

static PyMethodDef errornoMethods[] = {
     {NULL, NULL, 0, NULL}
};

DL_EXPORT(void) initerrno(void)
{
     PyObject *dict=NULL, *m=NULL;
     
     m = Py_InitModule("errno", errornoMethods);
     assert(m);

     dict = PyModule_GetDict(m);
     if(!dict)
	  goto fail;

     if(PyGSL_add_errors(dict, errors) != GSL_SUCCESS)
	  goto fail;
     return;
 fail:
     fprintf(stderr, "Initialisation of module errorno failed!\n");
     return;
}
