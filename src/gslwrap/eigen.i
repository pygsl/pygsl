/* -*- C -*- */
/**
 * Author: Fabian Jakobs
 *
 * Modified by: 26. November 2007 
 *          P. Schnizer <schnizer@users.sourceforge.net>
 *          added francis workspace
 */     
%{
#include <gsl/gsl_eigen.h>
%}



%extend gsl_eigen_symm_workspace {
  gsl_eigen_symm_workspace(const size_t n) {
    return gsl_eigen_symm_alloc(n);
  }
  ~gsl_eigen_symm_workspace() {
    gsl_eigen_symm_free(self);
  }
};

%extend gsl_eigen_symmv_workspace {
  gsl_eigen_symmv_workspace(const size_t n) {
    return gsl_eigen_symmv_alloc(n);
  }
  ~gsl_eigen_symmv_workspace() {
    gsl_eigen_symmv_free(self);
  }
};

%extend gsl_eigen_herm_workspace {
  gsl_eigen_herm_workspace(const size_t n) {
    return gsl_eigen_herm_alloc(n);
  }
  ~gsl_eigen_herm_workspace() {
    gsl_eigen_herm_free(self);
  }
};

%extend gsl_eigen_hermv_workspace {
  gsl_eigen_hermv_workspace(const size_t n) {
    return gsl_eigen_hermv_alloc(n);
  }
  ~gsl_eigen_hermv_workspace() {
    gsl_eigen_hermv_free(self);
  }
};

%extend gsl_eigen_genherm_workspace {
  gsl_eigen_genherm_workspace(const size_t n) {
    return gsl_eigen_genherm_alloc(n);
  }
  ~gsl_eigen_genherm_workspace() {
    gsl_eigen_genherm_free(self);
  }
};


%extend gsl_eigen_genhermv_workspace {
  gsl_eigen_genhermv_workspace(const size_t n) {
    return gsl_eigen_genhermv_alloc(n);
  }
  ~gsl_eigen_genhermv_workspace() {
    gsl_eigen_genhermv_free(self);
  }
};





%extend gsl_eigen_francis_workspace{
     gsl_eigen_francis_workspace (void){
	  return gsl_eigen_francis_alloc();
     }
     ~gsl_eigen_francis_workspace (void){
	  gsl_eigen_francis_free(self);
     }
}

%ignore gsl_eigen_nonsymmv_params;
%{
  static int
  pygsl_eigen_nonsymm_params (const int t, const int balance, gsl_eigen_nonsymm_workspace * self)
  {
#ifdef _PYGSL_GSL_HAS_GSL_EIGEN_NONSYMM_PARAMS
  gsl_eigen_nonsymm_params (t, balance, self);
  return GSL_SUCCESS;
#else
	 PyGSL_ERROR_UNIMPL
#endif 
	   }
%}
%extend gsl_eigen_nonsymm_workspace {
  gsl_eigen_nonsymm_workspace(const size_t n) {
    return gsl_eigen_nonsymm_alloc(n);
  }
  ~gsl_eigen_nonsymm_workspace() {
    gsl_eigen_nonsymm_free(self);
  }

  gsl_error_flag_drop
    params(const int compute_t, const int balance)
    {
      return pygsl_eigen_nonsymm_params (compute_t, balance, self);      
    }
};


%extend gsl_eigen_gen_workspace {
  gsl_eigen_gen_workspace(const size_t n) {
    return gsl_eigen_gen_alloc(n);
  }
  ~gsl_eigen_gen_workspace() {
    gsl_eigen_gen_free(self);
  }
};


%extend gsl_eigen_genv_workspace {
  gsl_eigen_genv_workspace(const size_t n) {
    return gsl_eigen_genv_alloc(n);
  }
  ~gsl_eigen_genv_workspace() {
    gsl_eigen_genv_free(self);
  }
};


%include gsl/gsl_eigen.h
