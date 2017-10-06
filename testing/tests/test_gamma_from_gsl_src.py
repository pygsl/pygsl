#!/usr/bin/env python
# WARNING: Automatically generated file: do not edit!
#          Edited the generated source instead.
#
# Tests converted from GSL Source directory.
# Original license:
# /* specfunc/test_gamma.c
# /* specfunc/test_gamma.c
#  * 
#  * Copyright (C) 2007 Brian Gough
#  * Copyright (C) 1996, 1997, 1998, 1999, 2000 Gerard Jungman
#  * 
#  * This program is free software; you can redistribute it and/or modify
#  * it under the terms of the GNU General Public License as published by
#  * the Free Software Foundation; either version 3 of the License, or (at
#  * your option) any later version.
#  * 
#  * This program is distributed in the hope that it will be useful, but
#  * WITHOUT ANY WARRANTY; without even the implied warranty of
#  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  * General Public License for more details.
#  * 
#  * You should have received a copy of the GNU General Public License
#  * along with this program; if not, write to the Free Software
#  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#  */

import unittest
import pygsl.testing.sf as sf

import sf_test_basis
from sf_test_basis import *
_test_sf_automatic = sf_test_basis._test_sf_automatic
_t_func = None
try:    
    _t_func = sf.beta_e
except AttributeError:
    print("Not including tests for beta_e")
    
if _t_func != None:
    class test_sf_automatic_beta_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_beta_e, (1.0,   1.0, &r), 1.0                   , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 1.0), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_beta_e, (1.0, 1.001, &r), 0.9990009990009990010 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 1.001), ('0.9990009990009990010', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_beta_e, (1.0,   5.0, &r), 0.2                   , TEST_TOL1, GSL_SUCCESS)'            
            self._test((1.0, 5.0), ('0.2', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_beta_e, (1.0,  100.0, &r), 0.01                  , TEST_TOL1, GSL_SUCCESS)'            
            self._test((1.0, 100.0), ('0.01', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_beta_e, (10.0, 100.0, &r), 2.3455339739604649879e-15 , TEST_TOL2, GSL_SUCCESS)'            
            self._test((10.0, 100.0), ('2.3455339739604649879e-15', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_beta_e, (2.5, -0.1, &r), -11.43621278354402041480, TEST_TOL2, GSL_SUCCESS)'            
            self._test((2.5, -0.1), ('-11.43621278354402041480', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_beta_e, (2.5, -1.1, &r), 14.555179906328753255202, TEST_TOL2, GSL_SUCCESS)'            
            self._test((2.5, -1.1), ('14.555179906328753255202', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_beta_e, (-0.25, -0.1, &r), -13.238937960945229110, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.25, -0.1), ('-13.238937960945229110', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_beta_e, (-1.25, -0.1, &r), -14.298052997820847439, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-1.25, -0.1), ('-14.298052997820847439', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_beta_e, (-100.1, -99.1, &r), -1.005181917797644630375787297e60, TEST_TOL3, GSL_SUCCESS)'            
            self._test((-100.1, -99.1), ('-1.005181917797644630375787297e60', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_beta_e, (-100.1, 99.3, &r), 0.0004474258199579694011200969001, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-100.1, 99.3), ('0.0004474258199579694011200969001', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_beta_e, (100.1, -99.3, &r), 1.328660939628876472028853747, TEST_TOL2, GSL_SUCCESS)'            
            self._test((100.1, -99.3), ('1.328660939628876472028853747', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_beta_e, (-100.1, 1.2, &r), 0.00365530364287960795444856281, TEST_TOL3, GSL_SUCCESS)'            
            self._test((-100.1, 1.2), ('0.00365530364287960795444856281', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_beta_e, (100.1, -1.2, &r), 1203.895236907821059270698160, TEST_TOL2, GSL_SUCCESS)'            
            self._test((100.1, -1.2), ('1203.895236907821059270698160', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_beta_e, (-100.1, -1.2, &r), -3236.073671884748847700283841, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-100.1, -1.2), ('-3236.073671884748847700283841', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_beta_e, (-100.001, 0.0099, &r), -853.946649365611147996495177, TEST_TOL4, GSL_SUCCESS)'            
            self._test((-100.001, 0.0099), ('-853.946649365611147996495177', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s,  gsl_sf_beta_e, (1e-32, 1.5, &r), 1e32, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1e-32, 1.5), ('1e32', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s,  gsl_sf_beta_e, (1e-6, 0.5, &r), 1000001.386293677092419390336, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1e-06, 0.5), ('1000001.386293677092419390336', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s,  gsl_sf_beta_e, (-1.5, 0.5, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-1.5, 0.5), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.beta_inc_e
except AttributeError:
    print("Not including tests for beta_inc_e")
    
if _t_func != None:
    class test_sf_automatic_beta_inc_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_beta_inc_e, (1.0, 1.0, 0.0, &r), 0.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1.0, 1.0, 0.0), ('0.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_beta_inc_e, (1.0, 1.0, 1.0, &r), 1.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1.0, 1.0, 1.0), ('1.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_beta_inc_e, (0.1, 0.1, 1.0, &r), 1.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((0.1, 0.1, 1.0), ('1.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_beta_inc_e, ( 1.0,  1.0, 0.5, &r), 0.5, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1.0, 1.0, 0.5), ('0.5', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_beta_inc_e, ( 0.1,  1.0, 0.5, &r), 0.9330329915368074160, TEST_TOL2, GSL_SUCCESS)'            
            self._test((0.1, 1.0, 0.5), ('0.9330329915368074160', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_beta_inc_e, (10.0,  1.0, 0.5, &r), 0.0009765625000000000000, TEST_TOL2, GSL_SUCCESS)'            
            self._test((10.0, 1.0, 0.5), ('0.0009765625000000000000', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_beta_inc_e, (50.0,  1.0, 0.5, &r), 8.881784197001252323e-16, TEST_TOL2, GSL_SUCCESS)'            
            self._test((50.0, 1.0, 0.5), ('8.881784197001252323e-16', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_beta_inc_e, ( 1.0,  0.1, 0.5, &r), 0.06696700846319258402, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1.0, 0.1, 0.5), ('0.06696700846319258402', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_beta_inc_e, ( 1.0, 10.0, 0.5, &r), 0.99902343750000000000, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1.0, 10.0, 0.5), ('0.99902343750000000000', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_beta_inc_e, ( 1.0, 50.0, 0.5, &r), 0.99999999999999911180, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1.0, 50.0, 0.5), ('0.99999999999999911180', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_beta_inc_e, ( 1.0,  1.0, 0.1, &r), 0.10, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1.0, 1.0, 0.1), ('0.10', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_beta_inc_e, ( 1.0,  2.0, 0.1, &r), 0.19, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1.0, 2.0, 0.1), ('0.19', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_beta_inc_e, ( 1.0,  2.0, 0.9, &r), 0.99, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1.0, 2.0, 0.9), ('0.99', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_beta_inc_e, (50.0, 60.0, 0.5, &r), 0.8309072939016694143, TEST_TOL2, GSL_SUCCESS)'            
            self._test((50.0, 60.0, 0.5), ('0.8309072939016694143', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_beta_inc_e, (90.0, 90.0, 0.5, &r), 0.5, TEST_TOL2, GSL_SUCCESS)'            
            self._test((90.0, 90.0, 0.5), ('0.5', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_beta_inc_e, ( 500.0,  500.0, 0.6, &r), 0.9999999999157549630, TEST_TOL2, GSL_SUCCESS)'            
            self._test((500.0, 500.0, 0.6), ('0.9999999999157549630', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s,  gsl_sf_beta_inc_e, (5000.0, 5000.0, 0.4, &r), 4.518543727260666383e-91, TEST_TOL5, GSL_SUCCESS)'            
            self._test((5000.0, 5000.0, 0.4), ('4.518543727260666383e-91', 'TEST_TOL5'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s,  gsl_sf_beta_inc_e, (5000.0, 5000.0, 0.6, &r), 1.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((5000.0, 5000.0, 0.6), ('1.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s,  gsl_sf_beta_inc_e, (5000.0, 2000.0, 0.6, &r), 8.445388773903332659e-89, TEST_TOL5, GSL_SUCCESS)'            
            self._test((5000.0, 2000.0, 0.6), ('8.445388773903332659e-89', 'TEST_TOL5'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s,  gsl_sf_beta_inc_e, (-0.1, -0.1, 1.0, &r), 1.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.1, -0.1, 1.0), ('1.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s,  gsl_sf_beta_inc_e, (-0.1, -0.2, 1.0, &r), 1.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.1, -0.2, 1.0), ('1.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s,  gsl_sf_beta_inc_e, (-0.2, -0.1, 1.0, &r), 1.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.2, -0.1, 1.0), ('1.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s,  gsl_sf_beta_inc_e, (-0.1, -0.2, 0.5, &r), 0.675252001958389971991335, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.1, -0.2, 0.5), ('0.675252001958389971991335', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s,  gsl_sf_beta_inc_e, (-0.2, -0.1, 0.5, &r), 0.324747998041610028008665, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.2, -0.1, 0.5), ('0.324747998041610028008665', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s,  gsl_sf_beta_inc_e, (-0.1, -0.1, 0.0, &r), 0.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.1, -0.1, 0.0), ('0.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s,  gsl_sf_beta_inc_e, (-0.1, -0.2, 0.0, &r), 0.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.1, -0.2, 0.0), ('0.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s,  gsl_sf_beta_inc_e, (-0.2, -0.1, 0.0, &r), 0.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.2, -0.1, 0.0), ('0.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s,  gsl_sf_beta_inc_e, (-0.1, -0.2, 0.3, &r), 0.7469186777964287252, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.1, -0.2, 0.3), ('0.7469186777964287252', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s,  gsl_sf_beta_inc_e, (-0.2, -0.1, 0.3, &r), 0.3995299653262016818, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-0.2, -0.1, 0.3), ('0.3995299653262016818', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s,  gsl_sf_beta_inc_e, (0.5, 101.5, 0.999457, &r), 1.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((0.5, 101.5, 0.999457), ('1.0', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.choose_e
except AttributeError:
    print("Not including tests for choose_e")
    
if _t_func != None:
    class test_sf_automatic_choose_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_choose_e, (7,3, &r), 35.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((7, 3), ('35.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_choose_e, (7,4, &r), 35.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((7, 4), ('35.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_choose_e, (5,2, &r), 10.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((5, 2), ('10.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_choose_e, (5,3, &r), 10.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((5, 3), ('10.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_choose_e, (500,495, &r), 255244687600.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((500, 495), ('255244687600.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_choose_e, (500,5, &r), 255244687600.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((500, 5), ('255244687600.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_choose_e, (500,200, &r), 5.054949849935532221e+144 , TEST_TOL5, GSL_SUCCESS)'            
            self._test((500, 200), ('5.054949849935532221e+144', 'TEST_TOL5'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_choose_e, (500,300, &r), 5.054949849935532221e+144 , TEST_TOL5, GSL_SUCCESS)'            
            self._test((500, 300), ('5.054949849935532221e+144', 'TEST_TOL5'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.doublefact_e
except AttributeError:
    print("Not including tests for doublefact_e")
    
if _t_func != None:
    class test_sf_automatic_doublefact_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,   gsl_sf_doublefact_e, (0, &r), 1.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((0,), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,   gsl_sf_doublefact_e, (1, &r), 1.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1,), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,   gsl_sf_doublefact_e, (7, &r), 105.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((7,), ('105.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_doublefact_e, (33, &r), 6.332659870762850625e+18 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((33,), ('6.332659870762850625e+18', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.fact_e
except AttributeError:
    print("Not including tests for fact_e")
    
if _t_func != None:
    class test_sf_automatic_fact_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,   gsl_sf_fact_e, (0, &r), 1.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((0,), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,   gsl_sf_fact_e, (1, &r), 1.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1,), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,   gsl_sf_fact_e, (7, &r), 5040.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((7,), ('5040.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_fact_e, (33, &r), 8.683317618811886496e+36 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((33,), ('8.683317618811886496e+36', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.gamma_e
except AttributeError:
    print("Not including tests for gamma_e")
    
if _t_func != None:
    class test_sf_automatic_gamma_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_gamma_e, (1.0 + 1.0/4096.0, &r), 0.9998591371459403421 , TEST_TOL0, GSL_SUCCESS)'            
            self._test(('1.0 + 1.0/4096.0',), ('0.9998591371459403421', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_gamma_e, (1.0 + 1.0/32.0, &r), 0.9829010992836269148 , TEST_TOL0, GSL_SUCCESS)'            
            self._test(('1.0 + 1.0/32.0',), ('0.9829010992836269148', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_gamma_e, (2.0 + 1.0/256.0, &r), 1.0016577903733583299 , TEST_TOL0, GSL_SUCCESS)'            
            self._test(('2.0 + 1.0/256.0',), ('1.0016577903733583299', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_gamma_e, (9.0, &r), 40320.0                   , TEST_TOL0, GSL_SUCCESS)'            
            self._test((9.0,), ('40320.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_gamma_e, (10.0, &r), 362880.0                  , TEST_TOL0, GSL_SUCCESS)'            
            self._test((10.0,), ('362880.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_gamma_e, (100.0, &r), 9.332621544394415268e+155 , TEST_TOL2, GSL_SUCCESS)'            
            self._test((100.0,), ('9.332621544394415268e+155', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_gamma_e, (170.0, &r), 4.269068009004705275e+304 , TEST_TOL2, GSL_SUCCESS)'            
            self._test((170.0,), ('4.269068009004705275e+304', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_gamma_e, (171.0, &r), 7.257415615307998967e+306 , TEST_TOL2, GSL_SUCCESS)'            
            self._test((171.0,), ('7.257415615307998967e+306', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_gamma_e, (-10.5, &r), -2.640121820547716316e-07  , TEST_TOL0, GSL_SUCCESS)'            
            self._test((-10.5,), ('-2.640121820547716316e-07', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_gamma_e, (-11.25, &r), 6.027393816261931672e-08  , TEST_TOL0, GSL_SUCCESS)'            
            self._test((-11.25,), ('6.027393816261931672e-08', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_gamma_e, (-1.0+1.0/65536.0, &r), -65536.42280587818970 , TEST_TOL0, GSL_SUCCESS)'            
            self._test(('-1.0+1.0/65536.0',), ('-65536.42280587818970', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.gamma_inc_P_e
except AttributeError:
    print("Not including tests for gamma_inc_P_e")
    
if _t_func != None:
    class test_sf_automatic_gamma_inc_P_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (1e-100, 0.001, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1e-100, 0.001), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (0.001, 0.001, &r), 0.9936876467088602902, TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.001, 0.001), ('0.9936876467088602902', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (0.001, 1.0, &r), 0.9997803916424144436, TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.001, 1.0), ('0.9997803916424144436', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (0.001, 10.0, &r), 0.9999999958306921828, TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.001, 10.0), ('0.9999999958306921828', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (1.0, 0.001, &r), 0.0009995001666250083319, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 0.001), ('0.0009995001666250083319', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (1.0, 1.01, &r), 0.6357810204284766802, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 1.01), ('0.6357810204284766802', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (1.0, 10.0, &r), 0.9999546000702375151, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 10.0), ('0.9999546000702375151', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (10.0, 10.01, &r), 0.5433207586693410570, TEST_TOL0, GSL_SUCCESS)'            
            self._test((10.0, 10.01), ('0.5433207586693410570', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (10.0, 20.0, &r), 0.9950045876916924128, TEST_TOL0, GSL_SUCCESS)'            
            self._test((10.0, 20.0), ('0.9950045876916924128', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (1000.0, 1000.1, &r), 0.5054666401440661753, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1000.0, 1000.1), ('0.5054666401440661753', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (1000.0, 2000.0, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1000.0, 2000.0), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (34.0, 32.0, &r), 0.3849626436463866776322932129, TEST_TOL2, GSL_SUCCESS)'            
            self._test((34.0, 32.0), ('0.3849626436463866776322932129', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (37.0, 3.499999999999999289e+01, &r), 0.3898035054195570860969333039, TEST_TOL2, GSL_SUCCESS)'            
            self._test((37.0, 34.99999999999999), ('0.3898035054195570860969333039', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (10, 1e-16, &r), 2.755731922398588814734648067e-167, TEST_TOL2, GSL_SUCCESS)'            
            self._test((10, 1e-16), ('2.755731922398588814734648067e-167', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (1263131.0, 1261282.3637, &r), 0.04994777516935182963821362168, TEST_TOL4, GSL_SUCCESS)'            
            self._test((1263131.0, 1261282.3637), ('0.04994777516935182963821362168', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (1263131.0, 1263131.0, &r), 0.500118321758657770672882362502514254, TEST_TOL4, GSL_SUCCESS)'            
            self._test((1263131.0, 1263131.0), ('0.500118321758657770672882362502514254', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (100,  99.0, &r), 0.4733043303994607, TEST_TOL2, GSL_SUCCESS)'            
            self._test((100, 99.0), ('0.4733043303994607', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (200, 199.0, &r), 0.4811585880878718, TEST_TOL2, GSL_SUCCESS)'            
            self._test((200, 199.0), ('0.4811585880878718', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s, gsl_sf_gamma_inc_P_e, (5670, 4574, &r),  3.063972328743934e-55, TEST_TOL2, GSL_SUCCESS)'            
            self._test((5670, 4574), ('3.063972328743934e-55', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.gamma_inc_Q_e
except AttributeError:
    print("Not including tests for gamma_inc_Q_e")
    
if _t_func != None:
    class test_sf_automatic_gamma_inc_Q_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (0.0, 0.001, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.0, 0.001), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (0.001, 0.001, &r), 0.006312353291139709793, TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.001, 0.001), ('0.006312353291139709793', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (0.001, 1.0, &r), 0.00021960835758555639171, TEST_TOL1, GSL_SUCCESS)'            
            self._test((0.001, 1.0), ('0.00021960835758555639171', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (0.001, 2.0, &r), 0.00004897691783098147880, TEST_TOL2, GSL_SUCCESS)'            
            self._test((0.001, 2.0), ('0.00004897691783098147880', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (0.001, 5.0, &r), 1.1509813397308608541e-06, TEST_TOL1, GSL_SUCCESS)'            
            self._test((0.001, 5.0), ('1.1509813397308608541e-06', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (1.0, 0.001, &r), 0.9990004998333749917, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 0.001), ('0.9990004998333749917', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (1.0, 1.01, &r), 0.3642189795715233198, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 1.01), ('0.3642189795715233198', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (1.0, 10.0, &r), 0.00004539992976248485154, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 10.0), ('0.00004539992976248485154', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (10.0, 10.01, &r), 0.4566792413306589430, TEST_TOL0, GSL_SUCCESS)'            
            self._test((10.0, 10.01), ('0.4566792413306589430', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (10.0, 100.0, &r), 1.1253473960842733885e-31, TEST_TOL2, GSL_SUCCESS)'            
            self._test((10.0, 100.0), ('1.1253473960842733885e-31', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (1000.0, 1000.1, &r), 0.4945333598559338247, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1000.0, 1000.1), ('0.4945333598559338247', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (1000.0, 2000.0, &r), 6.847349459614753180e-136, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1000.0, 2000.0), ('6.847349459614753180e-136', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (100,  99.0, &r), 0.5266956696005394, TEST_TOL2, GSL_SUCCESS)'            
            self._test((100, 99.0), ('0.5266956696005394', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (200, 199.0, &r), 0.5188414119121281, TEST_TOL2, GSL_SUCCESS)'            
            self._test((200, 199.0), ('0.5188414119121281', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (5670, 4574, &r), 1.0000000000000000, TEST_TOL2, GSL_SUCCESS)'            
            self._test((5670, 4574), ('1.0000000000000000', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (1.0e+06-1.0, 1.0e+06-2.0, &r), 0.50026596175224547004, TEST_TOL3, GSL_SUCCESS)'            
            self._test(('1.0e+06-1.0', '1.0e+06-2.0'), ('0.50026596175224547004', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (1.0e+06+2.0, 1.0e+06+1.0, &r), 0.50026596135330304336, TEST_TOL2, GSL_SUCCESS)'            
            self._test(('1.0e+06+2.0', '1.0e+06+1.0'), ('0.50026596135330304336', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (1.0e+06, 1.0e+06-2.0, &r), 0.50066490399940144811, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1000000.0, '1.0e+06-2.0'), ('0.50066490399940144811', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s, gsl_sf_gamma_inc_Q_e, (1.0e+07, 1.0e+07-2.0, &r), 0.50021026104978614908, TEST_TOL2, GSL_SUCCESS)'            
            self._test((10000000.0, '1.0e+07-2.0'), ('0.50021026104978614908', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.gamma_inc_e
except AttributeError:
    print("Not including tests for gamma_inc_e")
    
if _t_func != None:
    class test_sf_automatic_gamma_inc_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_gamma_inc_e, (-1.0/1048576.0, 1.0/1048576.0, &r), 13.285819596290624271, TEST_TOL0, GSL_SUCCESS)'            
            self._test(('-1.0/1048576.0', '1.0/1048576.0'), ('13.285819596290624271', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.001, 1.0/1048576.0, &r), 13.381275128625328858, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.001, '1.0/1048576.0'), ('13.381275128625328858', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_gamma_inc_e, (-1.0,   1.0/1048576.0, &r), 1.0485617142715768655e+06, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-1.0, '1.0/1048576.0'), ('1.0485617142715768655e+06', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.00001,0.001, &r), 6.3317681434563592142, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-1e-05, 0.001), ('6.3317681434563592142', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.0001,0.001, &r), 6.3338276439767189385, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.0001, 0.001), ('6.3338276439767189385', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.001, 0.001, &r), 6.3544709102510843793, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.001, 0.001), ('6.3544709102510843793', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.5,   0.001, &r), 59.763880515942196981, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.5, 0.001), ('59.763880515942196981', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_gamma_inc_e, (-1.0,   0.001, &r), 992.66896046923884234, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-1.0, 0.001), ('992.66896046923884234', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_gamma_inc_e, (-3.5,   0.001, &r), 9.0224404490639003706e+09, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-3.5, 0.001), ('9.0224404490639003706e+09', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_gamma_inc_e, (-10.5,  0.001, &r), 3.0083661558184815656e+30, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-10.5, 0.001), ('3.0083661558184815656e+30', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.001, 0.1,   &r), 1.8249109609418620068, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.001, 0.1), ('1.8249109609418620068', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.5,   0.1,   &r), 3.4017693366916154163, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.5, 0.1), ('3.4017693366916154163', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_gamma_inc_e, (-10.0,  0.1,   &r), 8.9490757483586989181e+08, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-10.0, 0.1), ('8.9490757483586989181e+08', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_gamma_inc_e, (-10.5,  0.1,   &r), 2.6967403834226421766e+09, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-10.5, 0.1), ('2.6967403834226421766e+09', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.001, 1.0,   &r), 0.21928612679072766340, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-0.001, 1.0), ('0.21928612679072766340', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.5,   1.0,   &r), 0.17814771178156069019, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-0.5, 1.0), ('0.17814771178156069019', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s, gsl_sf_gamma_inc_e, (-1.0,   1.0,   &r), 0.14849550677592204792, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-1.0, 1.0), ('0.14849550677592204792', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s, gsl_sf_gamma_inc_e, (-2.5,   1.0,   &r), 0.096556648631275160264, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-2.5, 1.0), ('0.096556648631275160264', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s, gsl_sf_gamma_inc_e, (-1.0,   10.0,  &r), 3.8302404656316087616e-07, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-1.0, 10.0), ('3.8302404656316087616e-07', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.001, 10.0,  &r), 4.1470562324807320961e-06, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-0.001, 10.0), ('4.1470562324807320961e-06', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s, gsl_sf_gamma_inc_e, (-0.5,   10.0,  &r), 1.2609042613241570681e-06, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.5, 10.0), ('1.2609042613241570681e-06', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s, gsl_sf_gamma_inc_e, (-1.0,   10.0,  &r), 3.8302404656316087616e-07, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-1.0, 10.0), ('3.8302404656316087616e-07', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s, gsl_sf_gamma_inc_e, (-10.5,  10.0,  &r), 6.8404927328441566785e-17, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-10.5, 10.0), ('6.8404927328441566785e-17', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s, gsl_sf_gamma_inc_e, (-100.0, 10.0,  &r), 4.1238327669858313997e-107, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-100.0, 10.0), ('4.1238327669858313997e-107', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s, gsl_sf_gamma_inc_e, (-200.0, 10.0,  &r), 2.1614091830529343423e-207, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-200.0, 10.0), ('2.1614091830529343423e-207', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s, gsl_sf_gamma_inc_e, (  0.0,     0.001, &r), 6.3315393641361493320, TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.0, 0.001), ('6.3315393641361493320', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s, gsl_sf_gamma_inc_e, (  0.001,   0.001, &r), 6.3087159394864007261, TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.001, 0.001), ('6.3087159394864007261', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s, gsl_sf_gamma_inc_e, (  1.0,     0.001, &r), 0.99900049983337499167, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 0.001), ('0.99900049983337499167', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s, gsl_sf_gamma_inc_e, ( 10.0,     0.001, &r), 362880.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((10.0, 0.001), ('362880.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s, gsl_sf_gamma_inc_e, (  0.0,     1.0,   &r), 0.21938393439552027368, TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.0, 1.0), ('0.21938393439552027368', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args30_1(self):
            '(s, gsl_sf_gamma_inc_e, (  0.001,   1.0,   &r), 0.21948181320730279613, TEST_TOL1, GSL_SUCCESS)'            
            self._test((0.001, 1.0), ('0.21948181320730279613', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args31_1(self):
            '(s, gsl_sf_gamma_inc_e, (  1.0,     1.0,   &r), 0.36787944117144232160, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 1.0), ('0.36787944117144232160', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args32_1(self):
            '(s, gsl_sf_gamma_inc_e, ( 10.0,     1.0,   &r), 362879.95956592242045, TEST_TOL0, GSL_SUCCESS)'            
            self._test((10.0, 1.0), ('362879.95956592242045', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args33_1(self):
            '(s, gsl_sf_gamma_inc_e, (100.0,     1.0,   &r), 9.3326215443944152682e+155, TEST_TOL0, GSL_SUCCESS)'            
            self._test((100.0, 1.0), ('9.3326215443944152682e+155', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args34_1(self):
            '(s, gsl_sf_gamma_inc_e, (  0.0,   100.0, &r), 3.6835977616820321802e-46, TEST_TOL2, GSL_SUCCESS)'            
            self._test((0.0, 100.0), ('3.6835977616820321802e-46', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args35_1(self):
            '(s, gsl_sf_gamma_inc_e, (  0.001, 100.0, &r), 3.7006367674063550631e-46, TEST_TOL2, GSL_SUCCESS)'            
            self._test((0.001, 100.0), ('3.7006367674063550631e-46', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args36_1(self):
            '(s, gsl_sf_gamma_inc_e, (  1.0,   100.0, &r), 3.7200759760208359630e-44, TEST_TOL2, GSL_SUCCESS)'            
            self._test((1.0, 100.0), ('3.7200759760208359630e-44', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args37_1(self):
            '(s, gsl_sf_gamma_inc_e, ( 10.0,   100.0, &r), 4.0836606309106112723e-26, TEST_TOL2, GSL_SUCCESS)'            
            self._test((10.0, 100.0), ('4.0836606309106112723e-26', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args38_1(self):
            '(s, gsl_sf_gamma_inc_e, (100.0,   100.0, &r), 4.5421981208626694294e+155, TEST_TOL1, GSL_SUCCESS)'            
            self._test((100.0, 100.0), ('4.5421981208626694294e+155', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.gammainv_e
except AttributeError:
    print("Not including tests for gammainv_e")
    
if _t_func != None:
    class test_sf_automatic_gammainv_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_gammainv_e, (1.0, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0,), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_gammainv_e, (2.0, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((2.0,), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_gammainv_e, (3.0, &r), 0.5, TEST_TOL0, GSL_SUCCESS)'            
            self._test((3.0,), ('0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_gammainv_e, (4.0, &r), 1.0/6.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((4.0,), ('1.0/6.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_gammainv_e, (10.0, &r), 1.0/362880.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((10.0,), ('1.0/362880.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_gammainv_e, (100.0, &r), 1.0715102881254669232e-156, TEST_TOL2, GSL_SUCCESS)'            
            self._test((100.0,), ('1.0715102881254669232e-156', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_gammainv_e, (0.0, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.0,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_gammainv_e, (-1.0, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-1.0,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_gammainv_e, (-2.0, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-2.0,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_gammainv_e, (-3.0, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-3.0,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_gammainv_e, (-4.0, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-4.0,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_gammainv_e, (-10.5, &r), -1.0/2.640121820547716316e-07, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-10.5,), ('-1.0/2.640121820547716316e-07', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_gammainv_e, (-11.25, &r), 1.0/6.027393816261931672e-08, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-11.25,), ('1.0/6.027393816261931672e-08', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_gammainv_e, (-1.0+1.0/65536.0, &r), -1.0/65536.42280587818970 , TEST_TOL1, GSL_SUCCESS)'            
            self._test(('-1.0+1.0/65536.0',), ('-1.0/65536.42280587818970', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.gammastar_e
except AttributeError:
    print("Not including tests for gammastar_e")
    
if _t_func != None:
    class test_sf_automatic_gammastar_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_gammastar_e, (1.0e-08, &r), 3989.423555759890865  , TEST_TOL1, GSL_SUCCESS)'            
            self._test((1e-08,), ('3989.423555759890865', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_gammastar_e, (1.0e-05, &r), 126.17168469882690233 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1e-05,), ('126.17168469882690233', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_gammastar_e, (0.001, &r), 12.708492464364073506 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.001,), ('12.708492464364073506', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_gammastar_e, (1.5, &r), 1.0563442442685598666 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.5,), ('1.0563442442685598666', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_gammastar_e, (3.0, &r), 1.0280645179187893045 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((3.0,), ('1.0280645179187893045', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_gammastar_e, (9.0, &r), 1.0092984264218189715 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((9.0,), ('1.0092984264218189715', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_gammastar_e, (11.0, &r), 1.0076024283104962850 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((11.0,), ('1.0076024283104962850', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_gammastar_e, (100.0, &r), 1.0008336778720121418 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((100.0,), ('1.0008336778720121418', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_gammastar_e, (1.0e+05, &r), 1.0000008333336805529 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((100000.0,), ('1.0000008333336805529', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_gammastar_e, (1.0e+20, &r), 1.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1e+20,), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.lnbeta_e
except AttributeError:
    print("Not including tests for lnbeta_e")
    
if _t_func != None:
    class test_sf_automatic_lnbeta_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_lnbeta_e, (1.0e-8, 1.0e-8, &r),  19.113827924512310617 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1e-08, 1e-08), ('19.113827924512310617', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_lnbeta_e, (1.0e-8, 0.01, &r),  18.420681743788563403 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1e-08, 0.01), ('18.420681743788563403', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_lnbeta_e, (1.0e-8, 1.0, &r),  18.420680743952365472 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1e-08, 1.0), ('18.420680743952365472', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_lnbeta_e, (1.0e-8, 10.0, &r),  18.420680715662683009 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1e-08, 10.0), ('18.420680715662683009', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_lnbeta_e, (1.0e-8, 1000.0, &r),  18.420680669107656949 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1e-08, 1000.0), ('18.420680669107656949', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_lnbeta_e, (0.1, 0.1, &r), 2.9813614810376273949 , TEST_TOL1, GSL_SUCCESS)'            
            self._test((0.1, 0.1), ('2.9813614810376273949', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_lnbeta_e, (0.1, 1.0, &r),  2.3025850929940456840 , TEST_TOL1, GSL_SUCCESS)'            
            self._test((0.1, 1.0), ('2.3025850929940456840', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_lnbeta_e, (0.1, 100.0, &r),  1.7926462324527931217 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.1, 100.0), ('1.7926462324527931217', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_lnbeta_e, (0.1, 1000, &r),  1.5619821298353164928 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.1, 1000), ('1.5619821298353164928', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_lnbeta_e, (1.0, 1.00025, &r),  -0.0002499687552073570, TEST_TOL4, GSL_SUCCESS)'            
            self._test((1.0, 1.00025), ('-0.0002499687552073570', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_lnbeta_e, (1.0, 1.01, &r),  -0.009950330853168082848 , TEST_TOL3, GSL_SUCCESS)'            
            self._test((1.0, 1.01), ('-0.009950330853168082848', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_lnbeta_e, (1.0, 1000.0, &r),  -6.907755278982137052 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0, 1000.0), ('-6.907755278982137052', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_lnbeta_e, (100.0, 100.0, &r),  -139.66525908670663927 , TEST_TOL2, GSL_SUCCESS)'            
            self._test((100.0, 100.0), ('-139.66525908670663927', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_lnbeta_e, (100.0, 1000.0, &r),  -336.4348576477366051 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((100.0, 1000.0), ('-336.4348576477366051', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_lnbeta_e, (100.0, 1.0e+8, &r),  -1482.9339185256447309 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((100.0, 100000000.0), ('-1482.9339185256447309', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.lnchoose_e
except AttributeError:
    print("Not including tests for lnchoose_e")
    
if _t_func != None:
    class test_sf_automatic_lnchoose_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_lnchoose_e, (7,3, &r), 3.555348061489413680 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((7, 3), ('3.555348061489413680', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_lnchoose_e, (5,2, &r), 2.302585092994045684 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((5, 2), ('2.302585092994045684', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.lndoublefact_e
except AttributeError:
    print("Not including tests for lndoublefact_e")
    
if _t_func != None:
    class test_sf_automatic_lndoublefact_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_lndoublefact_e, (0, &r), 0.0  , TEST_TOL0, GSL_SUCCESS)'            
            self._test((0,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_lndoublefact_e, (7, &r), 4.653960350157523371  , TEST_TOL0, GSL_SUCCESS)'            
            self._test((7,), ('4.653960350157523371', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_lndoublefact_e, (33, &r), 43.292252022541719660 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((33,), ('43.292252022541719660', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_lndoublefact_e, (34, &r), 45.288575519655959140 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((34,), ('45.288575519655959140', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_lndoublefact_e, (1034, &r), 3075.6383796271197707 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1034,), ('3075.6383796271197707', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_lndoublefact_e, (1035, &r), 3078.8839081731809169 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1035,), ('3078.8839081731809169', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.lnfact_e
except AttributeError:
    print("Not including tests for lnfact_e")
    
if _t_func != None:
    class test_sf_automatic_lnfact_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_lnfact_e, (0, &r), 0.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((0,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_lnfact_e, (1, &r), 0.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_lnfact_e, (7, &r), 8.525161361065414300 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((7,), ('8.525161361065414300', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_lnfact_e, (33, &r), 85.05446701758151741 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((33,), ('85.05446701758151741', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.lngamma_complex_e
except AttributeError:
    print("Not including tests for lngamma_complex_e")
    
if _t_func != None:
    class test_sf_automatic_lngamma_complex_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_2(self):
            '(s, gsl_sf_lngamma_complex_e, (5.0, 2.0, &r1, &r2),2.7487017561338026749, TEST_TOL0,3.0738434100497007915, TEST_TOL0,GSL_SUCCESS)'            
            self._test2((5.0, 2.0), ('2.7487017561338026749', 'TEST_TOL0'), ('3.0738434100497007915', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_2(self):
            '(s, gsl_sf_lngamma_complex_e, (100.0, 100.0, &r1, &r2),315.07804459949331323, TEST_TOL1,2.0821801804113110099, TEST_TOL3,GSL_SUCCESS)'            
            self._test2((100.0, 100.0), ('315.07804459949331323', 'TEST_TOL1'), ('2.0821801804113110099', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args2_2(self):
            '(s, gsl_sf_lngamma_complex_e, (100.0, -1000.0, &r1, &r2),-882.3920483010362817000, TEST_TOL1,-2.1169293725678813270, TEST_TOL3,GSL_SUCCESS)'            
            self._test2((100.0, -1000.0), ('-882.3920483010362817000', 'TEST_TOL1'), ('-2.1169293725678813270', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args3_2(self):
            '(s, gsl_sf_lngamma_complex_e, (-100.0, -1.0, &r1, &r2),-365.0362469529239516000, TEST_TOL1,-3.0393820262864361140, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((-100.0, -1.0), ('-365.0362469529239516000', 'TEST_TOL1'), ('-3.0393820262864361140', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.lngamma_e
except AttributeError:
    print("Not including tests for lngamma_e")
    
if _t_func != None:
    class test_sf_automatic_lngamma_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_lngamma_e, (-0.1, &r), 2.368961332728788655 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.1,), ('2.368961332728788655', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_lngamma_e, (-1.0/256.0, &r), 5.547444766967471595  , TEST_TOL0, GSL_SUCCESS)'            
            self._test(('-1.0/256.0',), ('5.547444766967471595', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_lngamma_e, (1.0e-08, &r), 18.420680738180208905 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((1e-08,), ('18.420680738180208905', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_lngamma_e, (0.1, &r), 2.252712651734205 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.1,), ('2.252712651734205', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_lngamma_e, (1.0 + 1.0/256.0, &r), -0.0022422226599611501448 , TEST_TOL0, GSL_SUCCESS)'            
            self._test(('1.0 + 1.0/256.0',), ('-0.0022422226599611501448', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_lngamma_e, (2.0 + 1.0/256.0, &r), 0.0016564177556961728692 , TEST_TOL0, GSL_SUCCESS)'            
            self._test(('2.0 + 1.0/256.0',), ('0.0016564177556961728692', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_lngamma_e, (100.0, &r), 359.1342053695753 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((100.0,), ('359.1342053695753', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_lngamma_e, (-1.0-1.0/65536.0, &r), 11.090348438090047844 , TEST_TOL0, GSL_SUCCESS)'            
            self._test(('-1.0-1.0/65536.0',), ('11.090348438090047844', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_lngamma_e, (-1.0-1.0/268435456.0, &r), 19.408121054103474300 , TEST_TOL0, GSL_SUCCESS)'            
            self._test(('-1.0-1.0/268435456.0',), ('19.408121054103474300', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_lngamma_e, (-100.5, &r), -364.9009683094273518 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((-100.5,), ('-364.9009683094273518', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_lngamma_e, (-100-1.0/65536.0, &r), -352.6490910117097874 , TEST_TOL0, GSL_SUCCESS)'            
            self._test(('-100-1.0/65536.0',), ('-352.6490910117097874', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.lnpoch_e
except AttributeError:
    print("Not including tests for lnpoch_e")
    
if _t_func != None:
    class test_sf_automatic_lnpoch_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_lnpoch_e, (5, 0.0, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((5, 0.0), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_lnpoch_e, (5, 1.0/65536.0, &r), 0.000022981557571259389129, TEST_TOL0, GSL_SUCCESS)'            
            self._test((5, '1.0/65536.0'), ('0.000022981557571259389129', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_lnpoch_e, (5, 1.0/256.0, &r),   0.005884960217985189004,    TEST_TOL2, GSL_SUCCESS)'            
            self._test((5, '1.0/256.0'), ('0.005884960217985189004', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_lnpoch_e, (7,3, &r), 6.222576268071368616, TEST_TOL0, GSL_SUCCESS)'            
            self._test((7, 3), ('6.222576268071368616', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_lnpoch_e, (5,2, &r), 3.401197381662155375, TEST_TOL0, GSL_SUCCESS)'            
            self._test((5, 2), ('3.401197381662155375', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.poch_e
except AttributeError:
    print("Not including tests for poch_e")
    
if _t_func != None:
    class test_sf_automatic_poch_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_poch_e, (5, 0.0, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((5, 0.0), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_poch_e, (7,3, &r), 504.0 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((7, 3), ('504.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_poch_e, (5,2, &r), 30.0  , TEST_TOL1, GSL_SUCCESS)'            
            self._test((5, 2), ('30.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_poch_e, (5,1.0/256.0, &r), 1.0059023106151364982 , TEST_TOL0, GSL_SUCCESS)'            
            self._test((5, '1.0/256.0'), ('1.0059023106151364982', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_poch_e, (-9.0, -4.0, &r), 1.0/17160.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-9.0, -4.0), ('1.0/17160.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_poch_e, (-9.0, -3.0, &r), -1.0/1320.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-9.0, -3.0), ('-1.0/1320.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_poch_e, (-9.0, -3.5, &r), 0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-9.0, -3.5), ('0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_poch_e, (-9.0, 4.0, &r), 3024.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-9.0, 4.0), ('3024.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_poch_e, (-9.0, 3.0, &r), -504.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-9.0, 3.0), ('-504.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_poch_e, (-9.0, 3.5, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-9.0, 3.5), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_poch_e, (-9.0, 0.0, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-9.0, 0.0), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_poch_e, (-8.0, -4.0, &r), 1.0/11880.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-8.0, -4.0), ('1.0/11880.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_poch_e, (-8.0, -3.0, &r), -1.0/990.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-8.0, -3.0), ('-1.0/990.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_poch_e, (-8.0, +4.0, &r), 1680.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-8.0, 4.0), ('1680.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_poch_e, (-8.0, +3.0, &r), -336.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-8.0, 3.0), ('-336.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_poch_e, (-3.0, +4.0, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-3.0, 4.0), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s,  gsl_sf_poch_e, (-3.0, +3.0, &r), -6.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-3.0, 3.0), ('-6.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s,  gsl_sf_poch_e, (-4.0, +4.0, &r), 24.0, TEST_TOL2, GSL_SUCCESS)'            
            self._test((-4.0, 4.0), ('24.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s,  gsl_sf_poch_e, (-3.0, +100.0, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-3.0, 100.0), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.pochrel_e
except AttributeError:
    print("Not including tests for pochrel_e")
    
if _t_func != None:
    class test_sf_automatic_pochrel_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_pochrel_e, (5,0, &r), 1.506117668431800472, TEST_TOL1, GSL_SUCCESS)'            
            self._test((5, 0), ('1.506117668431800472', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_pochrel_e, (7,3, &r), 503.0/3.0, TEST_TOL0, GSL_SUCCESS)'            
            self._test((7, 3), ('503.0/3.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_pochrel_e, (5,2, &r), 29.0/2.0, TEST_TOL1, GSL_SUCCESS)'            
            self._test((5, 2), ('29.0/2.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_pochrel_e, (5,0.01, &r), 1.5186393661368275330, TEST_TOL2, GSL_SUCCESS)'            
            self._test((5, 0.01), ('1.5186393661368275330', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_pochrel_e, (-5.5,0.01, &r), 1.8584945633829063516, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-5.5, 0.01), ('1.8584945633829063516', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_pochrel_e, (-5.5,-1.0/8.0, &r), 1.0883319303552135488, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-5.5, '-1.0/8.0'), ('1.0883319303552135488', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_pochrel_e, (-5.5,-1.0/256.0, &r), 1.7678268037726177453, TEST_TOL1, GSL_SUCCESS)'            
            self._test((-5.5, '-1.0/256.0'), ('1.7678268037726177453', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_pochrel_e, (-5.5,-11.0, &r), 0.09090909090939652475, TEST_TOL0, GSL_SUCCESS)'            
            self._test((-5.5, -11.0), ('0.09090909090939652475', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.taylorcoeff_e
except AttributeError:
    print("Not including tests for taylorcoeff_e")
    
if _t_func != None:
    class test_sf_automatic_taylorcoeff_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_taylorcoeff_e, (10,   1.0/1048576.0, &r), 1.7148961854776073928e-67  , TEST_TOL0, GSL_SUCCESS)'            
            self._test((10, '1.0/1048576.0'), ('1.7148961854776073928e-67', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_taylorcoeff_e, (10,   1.0/1024.0, &r), 2.1738891788497900281e-37  , TEST_TOL0, GSL_SUCCESS)'            
            self._test((10, '1.0/1024.0'), ('2.1738891788497900281e-37', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_taylorcoeff_e, (10,   1.0, &r), 2.7557319223985890653e-07  , TEST_TOL0, GSL_SUCCESS)'            
            self._test((10, 1.0), ('2.7557319223985890653e-07', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_taylorcoeff_e, (10,   5.0, &r), 2.6911444554673721340      , TEST_TOL0, GSL_SUCCESS)'            
            self._test((10, 5.0), ('2.6911444554673721340', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_taylorcoeff_e, (10,   500.0, &r), 2.6911444554673721340e+20  , TEST_TOL0, GSL_SUCCESS)'            
            self._test((10, 500.0), ('2.6911444554673721340e+20', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_taylorcoeff_e, (100,  100.0, &r), 1.0715102881254669232e+42  , TEST_TOL1, GSL_SUCCESS)'            
            self._test((100, 100.0), ('1.0715102881254669232e+42', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_taylorcoeff_e, (1000, 200.0, &r), 2.6628790558154746898e-267 , TEST_TOL1, GSL_SUCCESS)'            
            self._test((1000, 200.0), ('2.6628790558154746898e-267', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_taylorcoeff_e, (1000, 500.0, &r), 2.3193170139740855074e+131 , TEST_TOL1, GSL_SUCCESS)'            
            self._test((1000, 500.0), ('2.3193170139740855074e+131', 'TEST_TOL1'), GSL_SUCCESS)


if __name__ == '__main__':
    unittest.main()
