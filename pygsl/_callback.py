# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.
import __callback
def _swig_setattr(self,class_type,name,value):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    self.__dict__[name] = value

def _swig_getattr(self,class_type,name):
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


gsl_function_init = __callback.gsl_function_init

gsl_function_init_fdf = __callback.gsl_function_init_fdf

gsl_function_free = __callback.gsl_function_free

gsl_function_free_fdf = __callback.gsl_function_free_fdf

gsl_root_fsolver_alloc = __callback.gsl_root_fsolver_alloc

gsl_root_fsolver_free = __callback.gsl_root_fsolver_free

gsl_root_fdfsolver_alloc = __callback.gsl_root_fdfsolver_alloc

gsl_root_fdfsolver_free = __callback.gsl_root_fdfsolver_free

gsl_root_fsolver_set = __callback.gsl_root_fsolver_set

gsl_root_fdfsolver_set = __callback.gsl_root_fdfsolver_set

gsl_root_fsolver_name = __callback.gsl_root_fsolver_name

gsl_root_fdfsolver_name = __callback.gsl_root_fdfsolver_name

gsl_root_fsolver_iterate = __callback.gsl_root_fsolver_iterate

gsl_root_fdfsolver_iterate = __callback.gsl_root_fdfsolver_iterate

gsl_root_fsolver_root = __callback.gsl_root_fsolver_root

gsl_root_fdfsolver_root = __callback.gsl_root_fdfsolver_root

gsl_root_fsolver_x_lower = __callback.gsl_root_fsolver_x_lower

gsl_root_fsolver_x_upper = __callback.gsl_root_fsolver_x_upper

gsl_root_test_interval = __callback.gsl_root_test_interval

gsl_root_test_delta = __callback.gsl_root_test_delta

gsl_root_test_residual = __callback.gsl_root_test_residual

gsl_min_fminimizer_alloc = __callback.gsl_min_fminimizer_alloc

gsl_min_fminimizer_set = __callback.gsl_min_fminimizer_set

gsl_min_fminimizer_set_with_values = __callback.gsl_min_fminimizer_set_with_values

gsl_min_fminimizer_free = __callback.gsl_min_fminimizer_free

gsl_min_fminimizer_name = __callback.gsl_min_fminimizer_name

gsl_min_fminimizer_iterate = __callback.gsl_min_fminimizer_iterate

gsl_min_fminimizer_minimum = __callback.gsl_min_fminimizer_minimum

gsl_min_fminimizer_x_upper = __callback.gsl_min_fminimizer_x_upper

gsl_min_fminimizer_x_lower = __callback.gsl_min_fminimizer_x_lower

gsl_min_test_interval = __callback.gsl_min_test_interval

gsl_multiroot_function_init = __callback.gsl_multiroot_function_init

gsl_multiroot_function_init_fdf = __callback.gsl_multiroot_function_init_fdf

gsl_multiroot_function_getf = __callback.gsl_multiroot_function_getf

gsl_multiroot_function_fdf_getf = __callback.gsl_multiroot_function_fdf_getf

gsl_multiroot_function_getx = __callback.gsl_multiroot_function_getx

gsl_multiroot_function_fdf_getx = __callback.gsl_multiroot_function_fdf_getx

gsl_multiroot_function_free = __callback.gsl_multiroot_function_free

gsl_multiroot_function_free_fdf = __callback.gsl_multiroot_function_free_fdf

gsl_multiroot_fsolver_alloc = __callback.gsl_multiroot_fsolver_alloc

gsl_multiroot_fsolver_free = __callback.gsl_multiroot_fsolver_free

gsl_multiroot_fsolver_set = __callback.gsl_multiroot_fsolver_set

gsl_multiroot_fsolver_iterate = __callback.gsl_multiroot_fsolver_iterate

gsl_multiroot_fsolver_name = __callback.gsl_multiroot_fsolver_name

gsl_multiroot_fsolver_root = __callback.gsl_multiroot_fsolver_root

gsl_multiroot_fdfsolver_alloc = __callback.gsl_multiroot_fdfsolver_alloc

gsl_multiroot_fdfsolver_set = __callback.gsl_multiroot_fdfsolver_set

gsl_multiroot_fdfsolver_iterate = __callback.gsl_multiroot_fdfsolver_iterate

gsl_multiroot_fdfsolver_free = __callback.gsl_multiroot_fdfsolver_free

gsl_multiroot_fdfsolver_name = __callback.gsl_multiroot_fdfsolver_name

gsl_multiroot_fdfsolver_root = __callback.gsl_multiroot_fdfsolver_root

gsl_multiroot_test_delta = __callback.gsl_multiroot_test_delta

gsl_multiroot_test_residual = __callback.gsl_multiroot_test_residual

gsl_multimin_function_init_fdf = __callback.gsl_multimin_function_init_fdf

gsl_multimin_function_free_fdf = __callback.gsl_multimin_function_free_fdf

gsl_multimin_fdfminimizer_alloc = __callback.gsl_multimin_fdfminimizer_alloc

gsl_multimin_fdfminimizer_set = __callback.gsl_multimin_fdfminimizer_set

gsl_multimin_fdfminimizer_free = __callback.gsl_multimin_fdfminimizer_free

gsl_multimin_fdfminimizer_name = __callback.gsl_multimin_fdfminimizer_name

gsl_multimin_fdfminimizer_iterate = __callback.gsl_multimin_fdfminimizer_iterate

gsl_multimin_fdfminimizer_restart = __callback.gsl_multimin_fdfminimizer_restart

gsl_multimin_test_gradient = __callback.gsl_multimin_test_gradient

gsl_multimin_fdfminimizer_f = __callback.gsl_multimin_fdfminimizer_f

gsl_multimin_fdfminimizer_x = __callback.gsl_multimin_fdfminimizer_x

gsl_multimin_fdfminimizer_dx = __callback.gsl_multimin_fdfminimizer_dx

gsl_multimin_fdfminimizer_gradient = __callback.gsl_multimin_fdfminimizer_gradient

gsl_multimin_fdfminimizer_minimum = __callback.gsl_multimin_fdfminimizer_minimum

gsl_multifit_function_init = __callback.gsl_multifit_function_init

gsl_multifit_function_init_fdf = __callback.gsl_multifit_function_init_fdf

gsl_multifit_fsolver_getdx = __callback.gsl_multifit_fsolver_getdx

gsl_multifit_fsolver_getx = __callback.gsl_multifit_fsolver_getx

gsl_multifit_fsolver_getf = __callback.gsl_multifit_fsolver_getf

gsl_multifit_fdfsolver_getdx = __callback.gsl_multifit_fdfsolver_getdx

gsl_multifit_fdfsolver_getx = __callback.gsl_multifit_fdfsolver_getx

gsl_multifit_fdfsolver_getf = __callback.gsl_multifit_fdfsolver_getf

gsl_multifit_fdfsolver_getJ = __callback.gsl_multifit_fdfsolver_getJ

gsl_multifit_function_free = __callback.gsl_multifit_function_free

gsl_multifit_function_free_fdf = __callback.gsl_multifit_function_free_fdf

gsl_multifit_fsolver_alloc = __callback.gsl_multifit_fsolver_alloc

gsl_multifit_fsolver_free = __callback.gsl_multifit_fsolver_free

gsl_multifit_fsolver_set = __callback.gsl_multifit_fsolver_set

gsl_multifit_fsolver_iterate = __callback.gsl_multifit_fsolver_iterate

gsl_multifit_fsolver_name = __callback.gsl_multifit_fsolver_name

gsl_multifit_fsolver_position = __callback.gsl_multifit_fsolver_position

gsl_multifit_fdfsolver_alloc = __callback.gsl_multifit_fdfsolver_alloc

gsl_multifit_fdfsolver_set = __callback.gsl_multifit_fdfsolver_set

gsl_multifit_fdfsolver_iterate = __callback.gsl_multifit_fdfsolver_iterate

gsl_multifit_fdfsolver_free = __callback.gsl_multifit_fdfsolver_free

gsl_multifit_fdfsolver_name = __callback.gsl_multifit_fdfsolver_name

gsl_multifit_fdfsolver_position = __callback.gsl_multifit_fdfsolver_position

gsl_multifit_test_delta = __callback.gsl_multifit_test_delta

gsl_multifit_test_gradient = __callback.gsl_multifit_test_gradient

gsl_integration_workspace_alloc = __callback.gsl_integration_workspace_alloc

gsl_integration_workspace_free = __callback.gsl_integration_workspace_free

gsl_integration_workspace_get_size = __callback.gsl_integration_workspace_get_size

gsl_integration_qaws_table_alloc = __callback.gsl_integration_qaws_table_alloc

gsl_integration_qaws_table_set = __callback.gsl_integration_qaws_table_set

gsl_integration_qaws_table_free = __callback.gsl_integration_qaws_table_free

GSL_INTEG_COSINE = __callback.GSL_INTEG_COSINE
GSL_INTEG_SINE = __callback.GSL_INTEG_SINE
gsl_integration_qawo_table_alloc = __callback.gsl_integration_qawo_table_alloc

gsl_integration_qawo_table_set = __callback.gsl_integration_qawo_table_set

gsl_integration_qawo_table_set_length = __callback.gsl_integration_qawo_table_set_length

gsl_integration_qawo_table_free = __callback.gsl_integration_qawo_table_free

GSL_INTEG_GAUSS15 = __callback.GSL_INTEG_GAUSS15
GSL_INTEG_GAUSS21 = __callback.GSL_INTEG_GAUSS21
GSL_INTEG_GAUSS31 = __callback.GSL_INTEG_GAUSS31
GSL_INTEG_GAUSS41 = __callback.GSL_INTEG_GAUSS41
GSL_INTEG_GAUSS51 = __callback.GSL_INTEG_GAUSS51
GSL_INTEG_GAUSS61 = __callback.GSL_INTEG_GAUSS61
gsl_integration_qng = __callback.gsl_integration_qng

gsl_integration_qag = __callback.gsl_integration_qag

gsl_integration_qagi = __callback.gsl_integration_qagi

gsl_integration_qagiu = __callback.gsl_integration_qagiu

gsl_integration_qagil = __callback.gsl_integration_qagil

gsl_integration_qags = __callback.gsl_integration_qags

gsl_integration_qagp = __callback.gsl_integration_qagp

gsl_integration_qawc = __callback.gsl_integration_qawc

gsl_integration_qaws = __callback.gsl_integration_qaws

gsl_integration_qawo = __callback.gsl_integration_qawo

gsl_integration_qawf = __callback.gsl_integration_qawf

gsl_cheb_alloc = __callback.gsl_cheb_alloc

gsl_cheb_free = __callback.gsl_cheb_free

gsl_cheb_init = __callback.gsl_cheb_init

gsl_cheb_eval = __callback.gsl_cheb_eval

gsl_cheb_eval_err = __callback.gsl_cheb_eval_err

gsl_cheb_eval_n = __callback.gsl_cheb_eval_n

gsl_cheb_eval_n_err = __callback.gsl_cheb_eval_n_err

gsl_cheb_calc_deriv = __callback.gsl_cheb_calc_deriv

gsl_cheb_calc_integ = __callback.gsl_cheb_calc_integ

gsl_odeiv_step_alloc = __callback.gsl_odeiv_step_alloc

gsl_odeiv_step_reset = __callback.gsl_odeiv_step_reset

gsl_odeiv_step_free = __callback.gsl_odeiv_step_free

gsl_odeiv_step_name = __callback.gsl_odeiv_step_name

gsl_odeiv_step_order = __callback.gsl_odeiv_step_order

gsl_odeiv_hadj_dec = __callback.gsl_odeiv_hadj_dec
gsl_odeiv_hadj_inc = __callback.gsl_odeiv_hadj_inc
gsl_odeiv_hadj_nil = __callback.gsl_odeiv_hadj_nil
gsl_odeiv_control_alloc = __callback.gsl_odeiv_control_alloc

gsl_odeiv_control_init = __callback.gsl_odeiv_control_init

gsl_odeiv_control_free = __callback.gsl_odeiv_control_free

gsl_odeiv_control_name = __callback.gsl_odeiv_control_name

gsl_odeiv_control_standard_new = __callback.gsl_odeiv_control_standard_new

gsl_odeiv_control_y_new = __callback.gsl_odeiv_control_y_new

gsl_odeiv_control_yp_new = __callback.gsl_odeiv_control_yp_new

gsl_odeiv_evolve_alloc = __callback.gsl_odeiv_evolve_alloc

gsl_odeiv_evolve_reset = __callback.gsl_odeiv_evolve_reset

gsl_odeiv_evolve_free = __callback.gsl_odeiv_evolve_free

gsl_multifit_linear_alloc = __callback.gsl_multifit_linear_alloc

gsl_multifit_linear_free = __callback.gsl_multifit_linear_free

gsl_multifit_linear = __callback.gsl_multifit_linear

gsl_multifit_wlinear = __callback.gsl_multifit_wlinear

gsl_fit_linear = __callback.gsl_fit_linear

gsl_fit_wlinear = __callback.gsl_fit_wlinear

gsl_fit_linear_est = __callback.gsl_fit_linear_est

gsl_fit_mul = __callback.gsl_fit_mul

gsl_fit_wmul = __callback.gsl_fit_wmul

gsl_fit_mul_est = __callback.gsl_fit_mul_est

cvar = __callback.cvar
gsl_multifit_gradient = __callback.gsl_multifit_gradient

gsl_multifit_covar = __callback.gsl_multifit_covar

gsl_odeiv_step_apply = __callback.gsl_odeiv_step_apply

gsl_odeiv_control_hadjust = __callback.gsl_odeiv_control_hadjust

gsl_odeiv_evolve_apply = __callback.gsl_odeiv_evolve_apply


