/* wrapper for int gsl_sf_airy_Ai_e(const double x, const gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_Ai_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dc", &x, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_airy_Ai_e(x, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_Bi_e(const double x, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_Bi_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dc", &x, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_airy_Bi_e(x, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_Ai_scaled_e(const double x, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_Ai_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dc", &x, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_airy_Ai_scaled_e(x, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_Bi_scaled_e(const double x, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_Bi_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dc", &x, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_airy_Bi_scaled_e(x, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_Ai_deriv_e(const double x, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_Ai_deriv_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dc", &x, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_airy_Ai_deriv_e(x, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_Bi_deriv_e(const double x, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_Bi_deriv_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dc", &x, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_airy_Bi_deriv_e(x, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_Ai_deriv_scaled_e(const double x, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_Ai_deriv_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dc", &x, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_airy_Ai_deriv_scaled_e(x, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_Bi_deriv_scaled_e(const double x, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_Bi_deriv_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dc", &x, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_airy_Bi_deriv_scaled_e(x, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_zero_Ai_e(unsigned int s, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_zero_Ai_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int s=0;
long s_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "l", &s_long)) {
  /* say a little bit more */
  return NULL;
}
if (s_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for s");
  return NULL;
}
s=(unsigned int)s_long;
int_result=gsl_sf_airy_zero_Ai_e(s, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_zero_Bi_e(unsigned int s, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_zero_Bi_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int s=0;
long s_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "l", &s_long)) {
  /* say a little bit more */
  return NULL;
}
if (s_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for s");
  return NULL;
}
s=(unsigned int)s_long;
int_result=gsl_sf_airy_zero_Bi_e(s, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_zero_Ai_deriv_e(unsigned int s, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_zero_Ai_deriv_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int s=0;
long s_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "l", &s_long)) {
  /* say a little bit more */
  return NULL;
}
if (s_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for s");
  return NULL;
}
s=(unsigned int)s_long;
int_result=gsl_sf_airy_zero_Ai_deriv_e(s, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_airy_zero_Bi_deriv_e(unsigned int s, gsl_sf_result * result); */
static PyObject* gsl_sf_airy_zero_Bi_deriv_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int s=0;
long s_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "l", &s_long)) {
  /* say a little bit more */
  return NULL;
}
if (s_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for s");
  return NULL;
}
s=(unsigned int)s_long;
int_result=gsl_sf_airy_zero_Bi_deriv_e(s, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_J0_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_J0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_J0_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_J1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_J1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_J1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Jn_e(int n, double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Jn_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Jn_e(n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Y0_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Y0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Y0_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Y1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Y1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Y1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Yn_e(int n, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Yn_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Yn_e(n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_I0_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_I0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_I0_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_I1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_I1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_I1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_In_e(const int n, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_In_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_In_e(n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_I0_scaled_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_I0_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_I0_scaled_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_I1_scaled_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_I1_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_I1_scaled_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_In_scaled_e(int n, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_In_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_In_scaled_e(n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_K0_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_K0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_K0_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_K1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_K1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_K1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Kn_e(const int n, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Kn_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Kn_e(n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_K0_scaled_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_K0_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_K0_scaled_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_K1_scaled_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_K1_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_K1_scaled_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Kn_scaled_e(int n, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Kn_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Kn_scaled_e(n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_j0_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_j0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_j0_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_j1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_j1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_j1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_j2_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_j2_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_j2_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_jl_e(const int l, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_jl_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int l=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &l, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_jl_e(l, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_y0_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_y0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_y0_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_y1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_y1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_y1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_y2_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_y2_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_y2_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_yl_e(int l, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_yl_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int l=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &l, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_yl_e(l, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_i0_scaled_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_i0_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_i0_scaled_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_i1_scaled_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_i1_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_i1_scaled_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_i2_scaled_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_i2_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_i2_scaled_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_il_scaled_e(const int l, double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_il_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int l=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &l, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_il_scaled_e(l, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_k0_scaled_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_k0_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_k0_scaled_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_k1_scaled_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_k1_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_k1_scaled_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_k2_scaled_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_k2_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_k2_scaled_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_kl_scaled_e(int l, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_kl_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int l=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &l, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_kl_scaled_e(l, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Jnu_e(const double nu, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Jnu_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double nu=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &nu, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Jnu_e(nu, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Ynu_e(double nu, double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Ynu_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double nu=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &nu, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Ynu_e(nu, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Inu_scaled_e(double nu, double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Inu_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double nu=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &nu, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Inu_scaled_e(nu, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Inu_e(double nu, double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Inu_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double nu=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &nu, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Inu_e(nu, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Knu_scaled_e(const double nu, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Knu_scaled_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double nu=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &nu, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Knu_scaled_e(nu, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_Knu_e(const double nu, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_Knu_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double nu=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &nu, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_Knu_e(nu, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_lnKnu_e(const double nu, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_lnKnu_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double nu=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &nu, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_bessel_lnKnu_e(nu, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_zero_J0_e(unsigned int s, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_zero_J0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int s=0;
long s_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "l", &s_long)) {
  /* say a little bit more */
  return NULL;
}
if (s_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for s");
  return NULL;
}
s=(unsigned int)s_long;
int_result=gsl_sf_bessel_zero_J0_e(s, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_zero_J1_e(unsigned int s, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_zero_J1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int s=0;
long s_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "l", &s_long)) {
  /* say a little bit more */
  return NULL;
}
if (s_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for s");
  return NULL;
}
s=(unsigned int)s_long;
int_result=gsl_sf_bessel_zero_J1_e(s, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_bessel_zero_Jnu_e(double nu, unsigned int s, gsl_sf_result * result); */
static PyObject* gsl_sf_bessel_zero_Jnu_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double nu=0.0;
unsigned int s=0;
long s_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dl", &nu, &s_long)) {
  /* say a little bit more */
  return NULL;
}
if (s_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for s");
  return NULL;
}
s=(unsigned int)s_long;
int_result=gsl_sf_bessel_zero_Jnu_e(nu, s, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_clausen_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_clausen_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_clausen_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_coupling_3j_e(int two_ja, int two_jb, int two_jc, int two_ma, int two_mb, int two_mc, gsl_sf_result * result); */
static PyObject* gsl_sf_coupling_3j_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int two_ja=0;
int two_jb=0;
int two_jc=0;
int two_ma=0;
int two_mb=0;
int two_mc=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "iiiiii", &two_ja, &two_jb, &two_jc, &two_ma, &two_mb, &two_mc)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_coupling_3j_e(two_ja, two_jb, two_jc, two_ma, two_mb, two_mc, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_coupling_6j_e(int two_ja, int two_jb, int two_jc, int two_jd, int two_je, int two_jf, gsl_sf_result * result); */
static PyObject* gsl_sf_coupling_6j_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int two_ja=0;
int two_jb=0;
int two_jc=0;
int two_jd=0;
int two_je=0;
int two_jf=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "iiiiii", &two_ja, &two_jb, &two_jc, &two_jd, &two_je, &two_jf)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_coupling_6j_e(two_ja, two_jb, two_jc, two_jd, two_je, two_jf, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_coupling_9j_e(int two_ja, int two_jb, int two_jc, int two_jd, int two_je, int two_jf, int two_jg, int two_jh, int two_ji, gsl_sf_result * result); */
static PyObject* gsl_sf_coupling_9j_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int two_ja=0;
int two_jb=0;
int two_jc=0;
int two_jd=0;
int two_je=0;
int two_jf=0;
int two_jg=0;
int two_jh=0;
int two_ji=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "iiiiiiiii", &two_ja, &two_jb, &two_jc, &two_jd, &two_je, &two_jf, &two_jg, &two_jh, &two_ji)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_coupling_9j_e(two_ja, two_jb, two_jc, two_jd, two_je, two_jf, two_jg, two_jh, two_ji, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hydrogenicR_1_e(const double Z, const double r, gsl_sf_result * result); */
static PyObject* gsl_sf_hydrogenicR_1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double Z=0.0;
double r=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &Z, &r)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hydrogenicR_1_e(Z, r, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hydrogenicR_e(const int n, const int l, const double Z, const double r, gsl_sf_result * result); */
static PyObject* gsl_sf_hydrogenicR_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
int l=0;
double Z=0.0;
double r=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "iidd", &n, &l, &Z, &r)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hydrogenicR_e(n, l, Z, r, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_coulomb_wave_FG_e(const double eta, const double x, const double lam_F, const int  k_lam_G, gsl_sf_result * F, gsl_sf_result * Fp, gsl_sf_result * G, gsl_sf_result * Gp, double * exp_F, double * exp_G); */
static PyObject* gsl_sf_coulomb_wave_FG_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double eta=0.0;
double x=0.0;
double lam_F=0.0;
int k_lam_G=0;
gsl_sf_result F;
gsl_sf_result Fp;
gsl_sf_result G;
gsl_sf_result Gp;
double exp_F;
double exp_G;

if (!PyArg_ParseTuple(args, "dddi", &eta, &x, &lam_F, &k_lam_G)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_coulomb_wave_FG_e(eta, x, lam_F, k_lam_G, &F, &Fp, &G, &Gp, &exp_F, &exp_G);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)(dd)(dd)(dd)dd",F.val, F.err, Fp.val, Fp.err, G.val, G.err, Gp.val, Gp.err, exp_F, exp_G);
return returned_object;
}

/* wrapper for int gsl_sf_coulomb_CL_e(double L, double eta, gsl_sf_result * result); */
static PyObject* gsl_sf_coulomb_CL_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double L=0.0;
double eta=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &L, &eta)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_coulomb_CL_e(L, eta, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_dawson_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_dawson_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_dawson_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_debye_1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_debye_1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_debye_1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_debye_2_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_debye_2_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_debye_2_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_debye_3_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_debye_3_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_debye_3_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_debye_4_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_debye_4_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_debye_4_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_dilog_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_dilog_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_dilog_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_complex_dilog_e(const double r, double theta, gsl_sf_result * result_re, gsl_sf_result * result_im); */
static PyObject* gsl_sf_complex_dilog_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double r=0.0;
double theta=0.0;
gsl_sf_result result_re;
gsl_sf_result result_im;

if (!PyArg_ParseTuple(args, "dd", &r, &theta)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_complex_dilog_e(r, theta, &result_re, &result_im);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)(dd)",result_re.val, result_re.err, result_im.val, result_im.err);
return returned_object;
}

/* wrapper for int gsl_sf_multiply_e(const double x, const double y, gsl_sf_result * result); */
static PyObject* gsl_sf_multiply_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
double y=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &x, &y)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_multiply_e(x, y, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_multiply_err_e(const double x, const double dx, const double y, const double dy, gsl_sf_result * result); */
static PyObject* gsl_sf_multiply_err_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
double dx=0.0;
double y=0.0;
double dy=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dddd", &x, &dx, &y, &dy)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_multiply_err_e(x, dx, y, dy, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_ellint_Kcomp_e(double k, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_ellint_Kcomp_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double k=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dc", &k, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_ellint_Kcomp_e(k, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_ellint_Ecomp_e(double k, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_ellint_Ecomp_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double k=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dc", &k, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_ellint_Ecomp_e(k, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_ellint_F_e(double phi, double k, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_ellint_F_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double phi=0.0;
double k=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "ddc", &phi, &k, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_ellint_F_e(phi, k, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_ellint_E_e(double phi, double k, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_ellint_E_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double phi=0.0;
double k=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "ddc", &phi, &k, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_ellint_E_e(phi, k, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_ellint_P_e(double phi, double k, double n, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_ellint_P_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double phi=0.0;
double k=0.0;
double n=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dddc", &phi, &k, &n, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_ellint_P_e(phi, k, n, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_ellint_D_e(double phi, double k, double n, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_ellint_D_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double phi=0.0;
double k=0.0;
double n=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dddc", &phi, &k, &n, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_ellint_D_e(phi, k, n, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_ellint_RC_e(double x, double y, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_ellint_RC_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
double y=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "ddc", &x, &y, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_ellint_RC_e(x, y, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_ellint_RD_e(double x, double y, double z, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_ellint_RD_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
double y=0.0;
double z=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dddc", &x, &y, &z, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_ellint_RD_e(x, y, z, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_ellint_RF_e(double x, double y, double z, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_ellint_RF_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
double y=0.0;
double z=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dddc", &x, &y, &z, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_ellint_RF_e(x, y, z, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_ellint_RJ_e(double x, double y, double z, double p, gsl_mode_t mode, gsl_sf_result * result); */
static PyObject* gsl_sf_ellint_RJ_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
double y=0.0;
double z=0.0;
double p=0.0;
gsl_mode_t mode=GSL_PREC_SINGLE;
char mode_char='s';
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "ddddc", &x, &y, &z, &p, &mode_char)) {
  /* say a little bit more */
  return NULL;
}
if (eval_gsl_mode_char(&mode,mode_char)) return NULL;
int_result=gsl_sf_ellint_RJ_e(x, y, z, p, mode, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_elljac_e(double u, double m, double * sn, double * cn, double * dn); */
static PyObject* gsl_sf_elljac_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double u=0.0;
double m=0.0;
double sn;
double cn;
double dn;

if (!PyArg_ParseTuple(args, "dd", &u, &m)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_elljac_e(u, m, &sn, &cn, &dn);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("ddd",sn, cn, dn);
return returned_object;
}

/* wrapper for int gsl_sf_erfc_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_erfc_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_erfc_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_log_erfc_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_log_erfc_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_log_erfc_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_erf_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_erf_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_erf_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_erf_Z_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_erf_Z_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_erf_Z_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_erf_Q_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_erf_Q_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_erf_Q_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_expint_E1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_expint_E1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_expint_E1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_expint_E2_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_expint_E2_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_expint_E2_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_expint_Ei_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_expint_Ei_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_expint_Ei_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_Shi_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_Shi_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_Shi_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_Chi_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_Chi_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_Chi_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_expint_3_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_expint_3_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_expint_3_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_Si_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_Si_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_Si_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_Ci_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_Ci_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_Ci_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_atanint_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_atanint_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_atanint_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_fermi_dirac_m1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_fermi_dirac_m1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_fermi_dirac_m1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_fermi_dirac_0_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_fermi_dirac_0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_fermi_dirac_0_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_fermi_dirac_1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_fermi_dirac_1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_fermi_dirac_1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_fermi_dirac_2_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_fermi_dirac_2_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_fermi_dirac_2_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_fermi_dirac_int_e(const int j, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_fermi_dirac_int_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int j=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &j, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_fermi_dirac_int_e(j, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_fermi_dirac_mhalf_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_fermi_dirac_mhalf_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_fermi_dirac_mhalf_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_fermi_dirac_half_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_fermi_dirac_half_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_fermi_dirac_half_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_fermi_dirac_3half_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_fermi_dirac_3half_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_fermi_dirac_3half_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_fermi_dirac_inc_0_e(const double x, const double b, gsl_sf_result * result); */
static PyObject* gsl_sf_fermi_dirac_inc_0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
double b=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &x, &b)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_fermi_dirac_inc_0_e(x, b, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lngamma_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_lngamma_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_lngamma_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lngamma_sgn_e(double x, gsl_sf_result * result_lg, double *sgn); */
static PyObject* gsl_sf_lngamma_sgn_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result_lg;
double sgn;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_lngamma_sgn_e(x, &result_lg, &sgn);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)d",result_lg.val, result_lg.err, sgn);
return returned_object;
}

/* wrapper for int gsl_sf_gamma_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_gamma_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_gamma_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_gammastar_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_gammastar_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_gammastar_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_gammainv_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_gammainv_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_gammainv_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lngamma_complex_e(double zr, double zi, gsl_sf_result * lnr, gsl_sf_result * arg); */
static PyObject* gsl_sf_lngamma_complex_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double zr=0.0;
double zi=0.0;
gsl_sf_result lnr;
gsl_sf_result arg;

if (!PyArg_ParseTuple(args, "dd", &zr, &zi)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_lngamma_complex_e(zr, zi, &lnr, &arg);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)(dd)",lnr.val, lnr.err, arg.val, arg.err);
return returned_object;
}

/* wrapper for int gsl_sf_taylorcoeff_e(const int n, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_taylorcoeff_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_taylorcoeff_e(n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_fact_e(const unsigned int n, gsl_sf_result * result); */
static PyObject* gsl_sf_fact_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int n=0;
long n_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "l", &n_long)) {
  /* say a little bit more */
  return NULL;
}
if (n_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for n");
  return NULL;
}
n=(unsigned int)n_long;
int_result=gsl_sf_fact_e(n, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_doublefact_e(const unsigned int n, gsl_sf_result * result); */
static PyObject* gsl_sf_doublefact_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int n=0;
long n_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "l", &n_long)) {
  /* say a little bit more */
  return NULL;
}
if (n_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for n");
  return NULL;
}
n=(unsigned int)n_long;
int_result=gsl_sf_doublefact_e(n, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lnfact_e(const unsigned int n, gsl_sf_result * result); */
static PyObject* gsl_sf_lnfact_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int n=0;
long n_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "l", &n_long)) {
  /* say a little bit more */
  return NULL;
}
if (n_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for n");
  return NULL;
}
n=(unsigned int)n_long;
int_result=gsl_sf_lnfact_e(n, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lndoublefact_e(const unsigned int n, gsl_sf_result * result); */
static PyObject* gsl_sf_lndoublefact_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int n=0;
long n_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "l", &n_long)) {
  /* say a little bit more */
  return NULL;
}
if (n_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for n");
  return NULL;
}
n=(unsigned int)n_long;
int_result=gsl_sf_lndoublefact_e(n, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lnchoose_e(unsigned int n, unsigned int m, gsl_sf_result * result); */
static PyObject* gsl_sf_lnchoose_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int n=0;
long n_long=0;
unsigned int m=0;
long m_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "ll", &n_long, &m_long)) {
  /* say a little bit more */
  return NULL;
}
if (n_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for n");
  return NULL;
}
n=(unsigned int)n_long;
if (m_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for m");
  return NULL;
}
m=(unsigned int)m_long;
int_result=gsl_sf_lnchoose_e(n, m, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_choose_e(unsigned int n, unsigned int m, gsl_sf_result * result); */
static PyObject* gsl_sf_choose_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
unsigned int n=0;
long n_long=0;
unsigned int m=0;
long m_long=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "ll", &n_long, &m_long)) {
  /* say a little bit more */
  return NULL;
}
if (n_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for n");
  return NULL;
}
n=(unsigned int)n_long;
if (m_long<0) {
  PyErr_SetString(gsl_module_error,"expected non negative value for m");
  return NULL;
}
m=(unsigned int)m_long;
int_result=gsl_sf_choose_e(n, m, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lnpoch_e(const double a, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_lnpoch_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &a, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_lnpoch_e(a, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lnpoch_sgn_e(const double a, const double x, gsl_sf_result * result, double * sgn); */
static PyObject* gsl_sf_lnpoch_sgn_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double x=0.0;
gsl_sf_result result;
double sgn;

if (!PyArg_ParseTuple(args, "dd", &a, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_lnpoch_sgn_e(a, x, &result, &sgn);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)d",result.val, result.err, sgn);
return returned_object;
}

/* wrapper for int gsl_sf_poch_e(const double a, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_poch_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &a, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_poch_e(a, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_pochrel_e(const double a, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_pochrel_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &a, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_pochrel_e(a, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_gamma_inc_Q_e(const double a, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_gamma_inc_Q_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &a, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_gamma_inc_Q_e(a, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_gamma_inc_P_e(const double a, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_gamma_inc_P_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &a, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_gamma_inc_P_e(a, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lnbeta_e(const double a, const double b, gsl_sf_result * result); */
static PyObject* gsl_sf_lnbeta_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double b=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_lnbeta_e(a, b, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_beta_e(const double a, const double b, gsl_sf_result * result); */
static PyObject* gsl_sf_beta_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double b=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_beta_e(a, b, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_beta_inc_e(const double a, const double b, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_beta_inc_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double b=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "ddd", &a, &b, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_beta_inc_e(a, b, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_gegenpoly_1_e(double lambda, double x, gsl_sf_result * result); */
static PyObject* gsl_sf_gegenpoly_1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double lambda=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &lambda, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_gegenpoly_1_e(lambda, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_gegenpoly_2_e(double lambda, double x, gsl_sf_result * result); */
static PyObject* gsl_sf_gegenpoly_2_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double lambda=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &lambda, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_gegenpoly_2_e(lambda, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_gegenpoly_3_e(double lambda, double x, gsl_sf_result * result); */
static PyObject* gsl_sf_gegenpoly_3_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double lambda=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &lambda, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_gegenpoly_3_e(lambda, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_gegenpoly_n_e(int n, double lambda, double x, gsl_sf_result * result); */
static PyObject* gsl_sf_gegenpoly_n_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
double lambda=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "idd", &n, &lambda, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_gegenpoly_n_e(n, lambda, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_0F1_e(double c, double x, gsl_sf_result * result); */
static PyObject* gsl_sf_hyperg_0F1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double c=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &c, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_0F1_e(c, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_1F1_int_e(const int m, const int n, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_hyperg_1F1_int_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int m=0;
int n=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "iid", &m, &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_1F1_int_e(m, n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_1F1_e(const double a, const double b, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_hyperg_1F1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double b=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "ddd", &a, &b, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_1F1_e(a, b, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_U_int_e(const int m, const int n, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_hyperg_U_int_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int m=0;
int n=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "iid", &m, &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_U_int_e(m, n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_U_int_e10_e(const int m, const int n, const double x, gsl_sf_result_e10 * result); */
static PyObject* gsl_sf_hyperg_U_int_e10_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int m=0;
int n=0;
double x=0.0;
gsl_sf_result_e10 result;

if (!PyArg_ParseTuple(args, "iid", &m, &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_U_int_e10_e(m, n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(ddi)",result.val, result.err, result.e10);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_U_e(const double a, const double b, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_hyperg_U_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double b=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "ddd", &a, &b, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_U_e(a, b, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_U_e10_e(const double a, const double b, const double x, gsl_sf_result_e10 * result); */
static PyObject* gsl_sf_hyperg_U_e10_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double b=0.0;
double x=0.0;
gsl_sf_result_e10 result;

if (!PyArg_ParseTuple(args, "ddd", &a, &b, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_U_e10_e(a, b, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(ddi)",result.val, result.err, result.e10);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_2F1_e(double a, double b, const double c, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_hyperg_2F1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double b=0.0;
double c=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dddd", &a, &b, &c, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_2F1_e(a, b, c, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_2F1_conj_e(const double aR, const double aI, const double c, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_hyperg_2F1_conj_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double aR=0.0;
double aI=0.0;
double c=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dddd", &aR, &aI, &c, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_2F1_conj_e(aR, aI, c, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_2F1_renorm_e(const double a, const double b, const double c, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_hyperg_2F1_renorm_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double b=0.0;
double c=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dddd", &a, &b, &c, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_2F1_renorm_e(a, b, c, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_2F1_conj_renorm_e(const double aR, const double aI, const double c, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_hyperg_2F1_conj_renorm_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double aR=0.0;
double aI=0.0;
double c=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dddd", &aR, &aI, &c, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_2F1_conj_renorm_e(aR, aI, c, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hyperg_2F0_e(const double a, const double b, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_hyperg_2F0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double b=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "ddd", &a, &b, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hyperg_2F0_e(a, b, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_laguerre_1_e(const double a, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_laguerre_1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &a, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_laguerre_1_e(a, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_laguerre_2_e(const double a, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_laguerre_2_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &a, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_laguerre_2_e(a, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_laguerre_3_e(const double a, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_laguerre_3_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double a=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &a, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_laguerre_3_e(a, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_laguerre_n_e(const int n, const double a, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_laguerre_n_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
double a=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "idd", &n, &a, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_laguerre_n_e(n, a, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lambert_W0_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_lambert_W0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_lambert_W0_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lambert_Wm1_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_lambert_Wm1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_lambert_Wm1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_Pl_e(const int l, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_Pl_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int l=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &l, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_Pl_e(l, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_P1_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_P1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_P1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_P2_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_P2_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_P2_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_P3_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_P3_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_P3_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_Q0_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_Q0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_Q0_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_Q1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_Q1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_Q1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_Ql_e(const int l, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_Ql_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int l=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &l, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_Ql_e(l, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_Plm_e(const int l, const int m, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_Plm_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int l=0;
int m=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "iid", &l, &m, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_Plm_e(l, m, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_sphPlm_e(const int l, int m, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_sphPlm_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int l=0;
int m=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "iid", &l, &m, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_sphPlm_e(l, m, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_conicalP_half_e(const double lambda, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_conicalP_half_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double lambda=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &lambda, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_conicalP_half_e(lambda, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_conicalP_mhalf_e(const double lambda, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_conicalP_mhalf_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double lambda=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &lambda, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_conicalP_mhalf_e(lambda, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_conicalP_0_e(const double lambda, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_conicalP_0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double lambda=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &lambda, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_conicalP_0_e(lambda, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_conicalP_1_e(const double lambda, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_conicalP_1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double lambda=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &lambda, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_conicalP_1_e(lambda, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_conicalP_sph_reg_e(const int l, const double lambda, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_conicalP_sph_reg_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int l=0;
double lambda=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "idd", &l, &lambda, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_conicalP_sph_reg_e(l, lambda, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_conicalP_cyl_reg_e(const int m, const double lambda, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_conicalP_cyl_reg_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int m=0;
double lambda=0.0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "idd", &m, &lambda, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_conicalP_cyl_reg_e(m, lambda, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_H3d_0_e(const double lambda, const double eta, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_H3d_0_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double lambda=0.0;
double eta=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &lambda, &eta)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_H3d_0_e(lambda, eta, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_H3d_1_e(const double lambda, const double eta, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_H3d_1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double lambda=0.0;
double eta=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &lambda, &eta)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_H3d_1_e(lambda, eta, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_legendre_H3d_e(const int l, const double lambda, const double eta, gsl_sf_result * result); */
static PyObject* gsl_sf_legendre_H3d_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int l=0;
double lambda=0.0;
double eta=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "idd", &l, &lambda, &eta)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_legendre_H3d_e(l, lambda, eta, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_log_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_log_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_log_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_log_abs_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_log_abs_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_log_abs_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_complex_log_e(const double zr, const double zi, gsl_sf_result * lnr, gsl_sf_result * theta); */
static PyObject* gsl_sf_complex_log_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double zr=0.0;
double zi=0.0;
gsl_sf_result lnr;
gsl_sf_result theta;

if (!PyArg_ParseTuple(args, "dd", &zr, &zi)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_complex_log_e(zr, zi, &lnr, &theta);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)(dd)",lnr.val, lnr.err, theta.val, theta.err);
return returned_object;
}

/* wrapper for int gsl_sf_log_1plusx_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_log_1plusx_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_log_1plusx_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_log_1plusx_mx_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_log_1plusx_mx_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_log_1plusx_mx_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_pow_int_e(double x, int n, gsl_sf_result * result); */
static PyObject* gsl_sf_pow_int_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
int n=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "di", &x, &n)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_pow_int_e(x, n, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_psi_int_e(const int n, gsl_sf_result * result); */
static PyObject* gsl_sf_psi_int_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "i", &n)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_psi_int_e(n, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_psi_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_psi_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_psi_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_psi_1piy_e(const double y, gsl_sf_result * result); */
static PyObject* gsl_sf_psi_1piy_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double y=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &y)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_psi_1piy_e(y, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_psi_1_int_e(const int n, gsl_sf_result * result); */
static PyObject* gsl_sf_psi_1_int_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "i", &n)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_psi_1_int_e(n, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_psi_n_e(const int n, const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_psi_n_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "id", &n, &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_psi_n_e(n, x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_synchrotron_1_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_synchrotron_1_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_synchrotron_1_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_synchrotron_2_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_synchrotron_2_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_synchrotron_2_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_transport_2_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_transport_2_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_transport_2_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_transport_3_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_transport_3_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_transport_3_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_transport_4_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_transport_4_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_transport_4_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_transport_5_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_transport_5_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_transport_5_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_sin_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_sin_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_sin_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_cos_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_cos_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_cos_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hypot_e(const double x, const double y, gsl_sf_result * result); */
static PyObject* gsl_sf_hypot_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
double y=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &x, &y)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hypot_e(x, y, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_complex_sin_e(const double zr, const double zi, gsl_sf_result * szr, gsl_sf_result * szi); */
static PyObject* gsl_sf_complex_sin_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double zr=0.0;
double zi=0.0;
gsl_sf_result szr;
gsl_sf_result szi;

if (!PyArg_ParseTuple(args, "dd", &zr, &zi)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_complex_sin_e(zr, zi, &szr, &szi);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)(dd)",szr.val, szr.err, szi.val, szi.err);
return returned_object;
}

/* wrapper for int gsl_sf_complex_cos_e(const double zr, const double zi, gsl_sf_result * czr, gsl_sf_result * czi); */
static PyObject* gsl_sf_complex_cos_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double zr=0.0;
double zi=0.0;
gsl_sf_result czr;
gsl_sf_result czi;

if (!PyArg_ParseTuple(args, "dd", &zr, &zi)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_complex_cos_e(zr, zi, &czr, &czi);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)(dd)",czr.val, czr.err, czi.val, czi.err);
return returned_object;
}

/* wrapper for int gsl_sf_complex_logsin_e(const double zr, const double zi, gsl_sf_result * lszr, gsl_sf_result * lszi); */
static PyObject* gsl_sf_complex_logsin_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double zr=0.0;
double zi=0.0;
gsl_sf_result lszr;
gsl_sf_result lszi;

if (!PyArg_ParseTuple(args, "dd", &zr, &zi)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_complex_logsin_e(zr, zi, &lszr, &lszi);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)(dd)",lszr.val, lszr.err, lszi.val, lszi.err);
return returned_object;
}

/* wrapper for int gsl_sf_sinc_e(double x, gsl_sf_result * result); */
static PyObject* gsl_sf_sinc_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_sinc_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lnsinh_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_lnsinh_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_lnsinh_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_lncosh_e(const double x, gsl_sf_result * result); */
static PyObject* gsl_sf_lncosh_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &x)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_lncosh_e(x, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_sin_err_e(const double x, const double dx, gsl_sf_result * result); */
static PyObject* gsl_sf_sin_err_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
double dx=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &x, &dx)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_sin_err_e(x, dx, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_cos_err_e(const double x, const double dx, gsl_sf_result * result); */
static PyObject* gsl_sf_cos_err_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double x=0.0;
double dx=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &x, &dx)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_cos_err_e(x, dx, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_angle_restrict_symm_err_e(const double theta, gsl_sf_result * result); */
static PyObject* gsl_sf_angle_restrict_symm_err_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double theta=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &theta)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_angle_restrict_symm_err_e(theta, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_angle_restrict_pos_err_e(const double theta, gsl_sf_result * result); */
static PyObject* gsl_sf_angle_restrict_pos_err_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double theta=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &theta)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_angle_restrict_pos_err_e(theta, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_zeta_int_e(const int n, gsl_sf_result * result); */
static PyObject* gsl_sf_zeta_int_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "i", &n)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_zeta_int_e(n, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_zeta_e(const double s, gsl_sf_result * result); */
static PyObject* gsl_sf_zeta_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double s=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &s)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_zeta_e(s, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_hzeta_e(const double s, const double q, gsl_sf_result * result); */
static PyObject* gsl_sf_hzeta_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double s=0.0;
double q=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "dd", &s, &q)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_hzeta_e(s, q, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_eta_int_e(int n, gsl_sf_result * result); */
static PyObject* gsl_sf_eta_int_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
int n=0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "i", &n)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_eta_int_e(n, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

/* wrapper for int gsl_sf_eta_e(const double s, gsl_sf_result * result); */
static PyObject* gsl_sf_eta_e_wrap(PyObject *self, PyObject *args) {
PyObject* returned_object;
int int_result;
double s=0.0;
gsl_sf_result result;

if (!PyArg_ParseTuple(args, "d", &s)) {
  /* say a little bit more */
  return NULL;
}
int_result=gsl_sf_eta_e(s, &result);

if (int_result!=GSL_SUCCESS) {
  const char* message;
  message=gsl_strerror(int_result);
  /* raise exception */
  PyErr_SetString(gsl_module_error,message);
  return NULL;
}
returned_object=Py_BuildValue("(dd)",result.val, result.err);
return returned_object;
}

