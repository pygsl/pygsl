
%{
#include <string>
#include <iostream>
#include <sstream>
#include <gsl/gsl_errno.h>

using namespace std;

// global variable indicating if an error occured
static int err;

void gsl_error_handler(const char * reason, 
		       const char * file, 
		       int line, 
		       int gsl_errno) {
  ostringstream msg;
  msg << "GSL Error: " << file << ":" << line << ": " << reason; 
  PyErr_SetString(PyExc_ArithmeticError, msg.str().c_str());
  err = gsl_errno;
}
%}

%init {
  // set up error handling
  err = 0;
  gsl_set_error_handler(&gsl_error_handler);
}

%exception {
  $action;
  if (err != 0) {
    err = 0;
    return NULL;
  }
}

