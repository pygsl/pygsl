#!/usr/bin/env python
# Author : Pierre Schnizer 
"""
Wrapper for the ode solver of gsl. This solver wraps all features as descirbed
in Chapter 25 of the gsl documentation.

The _odeiv file provides the low level wrapper. Direct usage at your special
own risk.

Here is the pythonic version of the example from the gsl documentation.

import odeiv
mu = 10.0
def func(t, y):
    f = Numeric.zeros((2,), Numeric.Float) * 1.0
    f[0] = y[1]
    f[1] = -y[0] - mu * y[1] * (y[0] ** 2 -1);
    return f

def jac(t, y):
    dfdy = Numeric.zeros((2,2), Numeric.Float) 
    dfdy[0, 0] = 0.0
    dfdy[0, 1] = 1.0
    dfdy[1, 0] = -2.0 * mu * y[0] * y[1] - 1.0
    dfdy[1, 1] = -mu * (y[0]**2 - 1.0)
    dfdt = Numeric.zeros((2,))
    return dfdy, dfdt


dimension = 2
step = odeiv.step_gear1(dimension, func, jac)
control = odeiv.control_y_new(step, 1e-6, 1e-6)
evolve  = odeiv.evolve(step, control, dimension)
h = 1
t = 0.0
t1 = 100.0
y = (1.0, 0.0)
while t<t1:
    t, h, y = evolve.apply(t, t1, h, y)
    print t, y[0], y[1] 

"""
#
# Copyright (c) 2002 by Pierre Schnizer
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#
#
##
# author: Pierre Schnizer
# created: December 2002
# file: pygsl/src/odeiv/odeiv.py

import _callback

class __step:
    """    
    The lowest  level components  are the stepping  functions which  advance a
    solution  from time t  to t+h  for a  fixed step-size  h and  estimate the
    resulting local error.


    Pure virtual class. Use a derived Object instead.
    These objects are:
        step_rk2
        step_rk4
        step_rkf45
        step_rkck
        step_rk8pd
        step_rk2imp
        step_rk4imp
        step_bsimp
        step_gear1
        step_gear2
    """
    def __init__(self, dims, func, jac=None, args=None):
        """        
        dimension ... the dimension of the system
        func      ... the system descirbing the function
        jac       ... the jacobian matrix. optional
        args      ... additional arguments to pass to the function. optional
        """
        self.ptr = None
        if not hasattr(self, 'type'):
            raise TypeError, """You can not use step directly. You should use
            one of the derived classes!"""
        self.ptr = _callback.gsl_odeiv_step_alloc(self.type, dims)
        self.func = func
        if jac == None:
            if self.need_jacobian >= 1:
                raise ValueError, """This step object must use an jacobian
                matrix!"""
            self.jac = None
        else:
            self.jac = jac
        self.args = args
        
    def __del__(self):
        if hasattr(self, 'ptr'):
            if self.ptr != None:
                _callback.gsl_odeiv_step_free(self.ptr)

    def reset(self):
        _callback.gsl_odeiv_step_reset(self.ptr)
        
    def apply(self, t, h, y_in, dydt):
        """
        Input t, h, y_in, dydt, func, jac:
             t    ... start time t
             h    ... step size
             y_in ... start vector
             dydt ... derivatives of the system at t. If not known supply None
             
        Output:
             y, yerr, dydt:
             y_out ... vector at t+h
             yerr  ... the estimate of the absolute errors
             dydt  ... the derivatives of the system at t
             
        This method applies  the stepping function to the  system of equations
        defined by func  and jac, using the step size h  to advance the system
        from time t  and state y to time  t+h. The new state of  the system is
        stored in y_out  on output, with an estimate of  the absolute error in
        each component stored in yerr. If  the argument dydt_in is not None it
        should provide an  array containing the derivatives for  the system at
        time t on input. This is  optional as the derivatives will be computed
        internally if they are not  provided, but allows the reuse of existing
        derivative information. On output the new derivatives of the system at
        time t+h will be stored in given in.        
        """
        
        return _callback.gsl_odeiv_step_apply(self.ptr, t, h, y_in, dydt,
                                           self.func, self.jac, self.args)

    def order(self):
        """
        This method returns the order of the stepping function on the previous
        step. This order can vary if the stepping function itself is adaptive.
        """
        return _callback.gsl_odeiv_step_order(self.ptr)
    
    def name(self):
        """
        This function returns the name of the stepping function.
        """
        return _callback.gsl_odeiv_step_name(self.ptr)

    def _get_ptr(self):
        return self.ptr

    def _get_func(self):
        return self.func

    def _get_jac(self):
        return self.jac

    def _get_args(self):
        return self.args
    
class step_rk2(__step):
    """
    Embedded 2nd order Runge-Kutta with 3rd order error estimate.    
    """
    type = _callback.cvar.gsl_odeiv_step_rk2
    need_jacobian = 0
    
class step_rk4(__step):
    """
    4th order (classical) Runge-Kutta.    
    """
    type = _callback.cvar.gsl_odeiv_step_rk4
    need_jacobian = 0
        
class step_rkf45(__step):
    """
    Embedded 4th order Runge-Kutta-Fehlberg method with 5th order error
    estimate. This method is a good general-purpose integrator.    
    """
    type = _callback.cvar.gsl_odeiv_step_rkf45
    need_jacobian = 0
    
class step_rkck(__step):
    """
    Embedded 4th order Runge-Kutta Cash-Karp method with 5th order error
    estimate.    
    """
    type = _callback.cvar.gsl_odeiv_step_rkck
    need_jacobian = 0
    
class step_rk8pd(__step):
    """
    Embedded 8th order Runge-Kutta Prince-Dormand method with 9th order error
    estimate.    
    """
    type = _callback.cvar.gsl_odeiv_step_rk8pd
    need_jacobian = 0
    
class step_rk2imp(__step):
    """
    Implicit 2nd order Runge-Kutta at Gaussian points    
    """
    type = _callback.cvar.gsl_odeiv_step_rk2imp
    need_jacobian = 0
    
class step_rk4imp(__step):
    """
    Implicit 4th order Runge-Kutta at Gaussian points    
    """
    type = _callback.cvar.gsl_odeiv_step_rk4imp
    need_jacobian = 0
    
class step_bsimp(__step):
    """
    Implicit Bulirsch-Stoer method of Bader and Deuflhard. This algorithm
    requires the Jacobian.    
    """
    type = _callback.cvar.gsl_odeiv_step_bsimp
    need_jacobian = 1
    
class step_gear1(__step):
    """
    M=1 implicit Gear method    
    """
    type = _callback.cvar.gsl_odeiv_step_gear1
    need_jacobian = 0
    
class step_gear2(__step):
    """
    M=2 implicit Gear method     
    """
    type = _callback.cvar.gsl_odeiv_step_gear2 
    need_jacobian = 0

HADJ_DEC = _callback.gsl_odeiv_hadj_dec
HADJ_INC = _callback.gsl_odeiv_hadj_inc
HADJ_NIL = _callback.gsl_odeiv_hadj_nil
            
class __control:
    """
    The control function examines the  proposed change to the solution and its
    error estimate produced  by a stepping function and  attempts to determine
    the optimal step-size for a user-specified level of error.
    
    Pure virtual class for the control.
    Use either control_standard_new or control_y_new or control_yp_new    
    """

    def __del__(self):
        if hasattr(self, 'ptr'):
            if self.ptr != None:
                _callback.gsl_odeiv_control_free(self.ptr)

    def hadjust(self, y, yerr, dydt, h):
        """
        input: y, yerr, dydt
            y     ... 
            yerr  ... the error estimate
            dydt  ...
            h     ... last step size
        output: h, msg
            h     ... new step size
            msg   ... HADJ_DEC or HADJ_INC  or HADJ_NIL. See text.
                       
        This method  adjusts the  step-size h using  the current values  of y,
        yerr and dydt.  If the error in  the y-values yerr is found  to be too
        large  then  the step-size  h  is  reduced  and the  function  returns
        HADJ_DEC. If the  error is sufficiently small then  h may be increased
        and  HADJ_INC  is  returned.  The  function returns  HADJ_NIL  if  the
        step-size is  unchanged. The goal of  the function is  to estimate the
        largest   step-size  which   satisfies  the   user-specified  accuracy
        requirements for the current point.        
        """
        step = self.step._get_ptr()
        h, msg = _callback.gsl_odeiv_control_hadjust(self.ptr, step, y, yerr,
                                                  dydt, h)
        return h, msg
    
    def name(self):
        return _callback.gsl_odeiv_control_name(self.ptr)

    def _get_ptr(self):
        return self.ptr

class  control_standard_new(__control):
    """  
    The standard control object is a four parameter
    heuristic based on  absolute and relative errors eps_abs  and eps_rel, and
    scaling factors a_y  and a_dydt for the system  state y(t) and derivatives
    y'(t) respectively.

    The step-size adjustment procedure for this method begins by computing the
    desired error level D_i for each component,

    D_i = eps_abs + eps_rel * (a_y |y_i| + a_dydt h |y'_i|)

    and comparing it  with the observed error E_i =  |yerr_i|. If the observed
    error  E exceeds  the  desired error  level D  by  more than  10% for  any
    component then the method reduces the step-size by an appropriate factor,

    h_new = h_old * S * (D/E)^(1/q)

    where q  is the consistency  order of method  (e.g. q=4 for  4(5) embedded
    RK), and  S is a safety  factor of 0.9. The  ratio D/E is taken  to be the
    maximum of the ratios D_i/E_i.

    If the observed error E is less  than 50% of the desired error level D for
    the  maximum ratio  D_i/E_i then  the algorithm  takes the  opportunity to
    increase the step-size to bring the error in line with the desired level,

    h_new = h_old * S * (E/D)^(1/(q+1))

    This   encompasses  all  the   standard  error   scaling  methods.
    """
    

    def __init__(self, step, eps_abs, eps_rel, a_y, a_dydt):
        """
        input : eps_abs, eps_rel, a_y, a_dydt

        See the docstring of this class for the meaning of the input.
        """
        self.step = step
        self.ptr = None
        self.ptr = _callback.gsl_odeiv_control_standard_new(eps_abs, eps_rel,
                                                         a_y, a_dydt)

class  control_y_new(__control):
    """    
    Creates a new control object which  will keep the local error on each step
    within an  absolute error  of eps_abs and  relative error of  eps_rel with
    respect to the solution y_i(t). This is equivalent to the standard control
    object with a_y=1 and a_dydt=0.

    See also the documentation of the control_standard_new class    
    """
    def __init__(self, step, eps_abs, eps_rel):
        """
        input : eps_abs, eps_rel

        See the docstring of this class for the meaning of the input.
        """
        self.step = step
        self.ptr = None
        self.ptr = _callback.gsl_odeiv_control_y_new(eps_abs, eps_rel)
        
class control_yp_new(__control):
    """
    This function creates a new control object which will keep the local error
    on each step within an absolute error of eps_abs and relative error of
    eps_rel with respect to the derivatives of the solution y'_i(t) . This is
    equivalent to the standard control object with a_y=0 and a_dydt=1.    
    """
    def __init__  (self, step, eps_abs, eps_rel):
        """
        input : eps_abs, eps_rel

        See the docstring of this class for the meaning of the input.
        """
        self.step = step
        self.ptr = None
        self.ptr = _callback.gsl_odeiv_control_yp_new(eps_abs, eps_rel)

class evolve:
    """
    The highest level  of the system is the  evolution function which combines
    the  results of  a  stepping  function and  control  function to  reliably
    advance the solution  forward over an interval (t_0,  t_1). If the control
    function  signals that  the step-size  should be  decreased  the evolution
    function  backs out of  the current  step and  tries the  proposed smaller
    step-size. This is  process is continued until an  acceptable step-size is
    found.
    """
    def __init__(self, step, control, dimension):
        """

        input: step, control, dimension
            step      ...   a step object
            control   ...   a control object
            dimension ...   dimension of the problem

        """
        # Keep a reference to the objects so that its pointers are valid
        self.step = step
        self.control = control
        
        self.ptr = None
        self.ptr = _callback.gsl_odeiv_evolve_alloc(dimension)
        self.func = self.step._get_func()
        self.jac  = self.step._get_jac()
        self.args = self.step._get_args()
        tmp =  self.step._get_ptr(), self.control._get_ptr(), self.ptr
        self._solvers_tuple = tuple(tmp)

        
    def __del__(self):
        if hasattr(self, 'ptr'):
            if self.ptr != None:
                _callback.gsl_odeiv_evolve_free(self.ptr)
            
    def reset(self):
        """
        No input. No output
        
        This method resets the evolution. It should be used whenever
        the next use will not be a continuation of a previous step.
        """
        _callback.gsl_odeiv_evolve_reset(self.ptr)

    def apply(self, t, t1, h, y):        
        """
        input : t, t1, h, y
            t  ... start time
            t1 ... end time
            h  ... initial step size
            y  ... start vector
            
        output :
            t  ... reached time in the calculation
            h  ... reached step size
            y  ... end vector

            
        This method advances  the system from time t and  position y using the
        stepping function step. The new time  and position are stored in t and
        y on  output. The initial  step-size is taken  as h, but this  will be
        modified  to achieve  the appropriate  error bound  if  necessary. The
        routine  may  make  several calls  to  the  step  object in  order  to
        determine the optimum step-size. If the step-size has been changed the
        value  of  h will  be  modified  on output.  The  maximum  time t1  is
        guaranteed  not  to  be  exceeded  by the  time-step.   On  the  final
        time-step the value of t will be set to t1 exactly.

        """
        tmp =  _callback.gsl_odeiv_evolve_apply(self._solvers_tuple,
                                                self.func, self.jac, t, t1, h,
                                                y, self.args)

        return tmp


    def apply_vector(self, t, t1, h, y, nsteps=1, hmax=None):
        res = (nsteps,)
        if hmax != None:
            res = nsteps, hmax
            
        tmp =  _callback.gsl_odeiv_evolve_apply_vector(self._solvers_tuple,
                                                self.func, self.jac, t, t1, h,
                                                y, self.args, *res)

        return tmp
