/**
 * Author: Fabian Jakobs
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

%include gsl/gsl_eigen.h
