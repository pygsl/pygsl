#!/usr/bin/env python
# WARNING: Automatically generated file: do not edit!
#          Edited the generated source instead.
#
# Tests converted from GSL Source directory.
# Original license:
# /* specfunc/test_sf.c
# /* specfunc/test_sf.c
#  *
#  * Copyright (C) 2007 Brian Gough
#  * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2004 Gerard Jungman
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
import pytest
import pygsl.testing.sf as sf

import sf_test_basis
from sf_test_basis import *
_test_sf_automatic = sf_test_basis._test_sf_automatic
_t_func = None
try:
    _t_func = sf.Chi_e
except AttributeError:
    print("Not including tests for Chi_e")

if _t_func != None:
    class test_sf_automatic_Chi_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_Chi_e, (-1.0, &r), 0.8378669409802082409, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.8378669409802082409', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_Chi_e, (1.0/4294967296.0, &r), -21.603494113016717041, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/4294967296.0',), ('-21.603494113016717041', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_Chi_e, (1.0/65536.0, &r), -10.513139223999384429, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/65536.0',), ('-10.513139223999384429', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_Chi_e, (1.0/8.0, &r), -1.4983170827635760646, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/8.0',), ('-1.4983170827635760646', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_Chi_e, (1.0, &r), 0.8378669409802082409, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.8378669409802082409', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_Chi_e, (10.0, &r), 1246.1144860424544147, TEST_TOL1, GSL_SUCCESS)'
            self._test((10.0,), ('1246.1144860424544147', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_Chi_e, (50.0, &r), 5.292818448565845482e+19, TEST_TOL2, GSL_SUCCESS)'
            self._test((50.0,), ('5.292818448565845482e+19', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_Chi_e, (300.0, &r), 3.248241254044332895e+127, TEST_TOL2, GSL_SUCCESS)'
            self._test((300.0,), ('3.248241254044332895e+127', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.Ci_e
except AttributeError:
    print("Not including tests for Ci_e")

if _t_func != None:
    class test_sf_automatic_Ci_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_Ci_e, (1.0/4294967296.0, &r), -21.603494113016717041, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/4294967296.0',), ('-21.603494113016717041', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_Ci_e, (1.0/65536.0, &r), -10.513139224115799751, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/65536.0',), ('-10.513139224115799751', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_Ci_e, (1.0/8.0, &r), -1.5061295845296396649, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/8.0',), ('-1.5061295845296396649', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_Ci_e, (1.0, &r), 0.3374039229009681347, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.3374039229009681347', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_Ci_e, (10.0, &r), -0.04545643300445537263, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('-0.04545643300445537263', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_Ci_e, (50.0, &r), -0.005628386324116305440, TEST_TOL0, GSL_SUCCESS)'
            self._test((50.0,), ('-0.005628386324116305440', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_Ci_e, (300.0, &r), -0.003332199918592111780, TEST_TOL0, GSL_SUCCESS)'
            self._test((300.0,), ('-0.003332199918592111780', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_Ci_e, (65536.0, &r), 0.000010560248837656279453, TEST_TOL0, GSL_SUCCESS)'
            self._test((65536.0,), ('0.000010560248837656279453', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_Ci_e, (4294967296.0, &r), -1.0756463261957757485e-10, TEST_SQRT_TOL0, GSL_SUCCESS)'
            self._test((4294967296.0,), ('-1.0756463261957757485e-10', 'TEST_SQRT_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_Ci_e, (1099511627776.0, &r), -3.689865584710764214e-13, 1024.0*TEST_SQRT_TOL0, GSL_SUCCESS)'
            self._test((1099511627776.0,), ('-3.689865584710764214e-13', '1024.0*TEST_SQRT_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.Shi_e
except AttributeError:
    print("Not including tests for Shi_e")

if _t_func != None:
    class test_sf_automatic_Shi_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_Shi_e, (-1.0, &r), -1.0572508753757285146, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('-1.0572508753757285146', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_Shi_e, (1.0/4294967296.0, &r), 2.3283064365386962891e-10, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/4294967296.0',), ('2.3283064365386962891e-10', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_Shi_e, (1.0/65536.0, &r), 0.00001525878906269737298, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/65536.0',), ('0.00001525878906269737298', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_Shi_e, (0.1, &r), 0.1000555722250569955, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.1000555722250569955', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_Shi_e, (1.0, &r), 1.0572508753757285146, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('1.0572508753757285146', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_Shi_e, (10.0, &r), 1246.1144901994233444, TEST_TOL1, GSL_SUCCESS)'
            self._test((10.0,), ('1246.1144901994233444', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_Shi_e, (50.0, &r), 5.292818448565845482e+19, TEST_TOL2, GSL_SUCCESS)'
            self._test((50.0,), ('5.292818448565845482e+19', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_Shi_e, (300.0, &r), 3.248241254044332895e+127, TEST_TOL2, GSL_SUCCESS)'
            self._test((300.0,), ('3.248241254044332895e+127', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.Si_e
except AttributeError:
    print("Not including tests for Si_e")

if _t_func != None:
    class test_sf_automatic_Si_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_Si_e, (-1.0, &r), -0.9460830703671830149, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('-0.9460830703671830149', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_Si_e, (1.0e-10, &r), 1.0e-10, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('1.0e-10', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_Si_e, (1.0e-05, &r), 9.999999999944444444e-06, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-05,), ('9.999999999944444444e-06', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_Si_e, (0.1, &r), 0.09994446110827695016, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.09994446110827695016', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_Si_e, (1.0, &r), 0.9460830703671830149, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.9460830703671830149', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_Si_e, (10.0, &r), 1.6583475942188740493, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('1.6583475942188740493', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_Si_e, (50.0, &r), 1.5516170724859358947, TEST_TOL0, GSL_SUCCESS)'
            self._test((50.0,), ('1.5516170724859358947', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_Si_e, (300.0, &r), 1.5708810882137495193, TEST_TOL0, GSL_SUCCESS)'
            self._test((300.0,), ('1.5708810882137495193', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.angle_restrict_pos_err_e
except AttributeError:
    print("Not including tests for angle_restrict_pos_err_e")

if _t_func != None:
    class test_sf_automatic_angle_restrict_pos_err_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_angle_restrict_pos_err_e, (2.0*M_PI, &r), 2*M_PI, TEST_TOL1, GSL_SUCCESS)'
            self._test(('2.0*M_PI',), ('2*M_PI', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_angle_restrict_pos_err_e, (-2.0*M_PI, &r), 2*DELTA, TEST_TOL1, GSL_SUCCESS)'
            self._test(('-2.0*M_PI',), ('2*DELTA', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_angle_restrict_pos_err_e, (1e9, &r), 0.5773954235013851694, TEST_TOL1, GSL_SUCCESS)'
            self._test((1000000000.0,), ('0.5773954235013851694', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_angle_restrict_pos_err_e, (1e12, &r), 5.625560548042800009446, TEST_SNGL, GSL_SUCCESS)'
            self._test((1000000000000.0,), ('5.625560548042800009446', 'TEST_SNGL'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_angle_restrict_pos_err_e, (-1e9, &r), 5.7057898836782013075, TEST_TOL1, GSL_SUCCESS)'
            self._test((-1000000000.0,), ('5.7057898836782013075', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_angle_restrict_pos_err_e, (-1e12, &r), 0.6576247591367864674792517289, 100*TEST_SNGL, GSL_SUCCESS)'
            self._test((-1000000000000.0,), ('0.6576247591367864674792517289', '100*TEST_SNGL'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_angle_restrict_pos_err_e, (1e15, &r), GSL_NAN, TEST_TOL1, GSL_ELOSS)'
            self._test((1000000000000000.0,), ('GSL_NAN', 'TEST_TOL1'), GSL_ELOSS)


        def test_args7_1(self):
            '(s, gsl_sf_angle_restrict_pos_err_e, (-1e15, &r), GSL_NAN, TEST_TOL1, GSL_ELOSS)'
            self._test((-1000000000000000.0,), ('GSL_NAN', 'TEST_TOL1'), GSL_ELOSS)

_t_func = None
try:
    _t_func = sf.angle_restrict_symm_err_e
except AttributeError:
    print("Not including tests for angle_restrict_symm_err_e")

if _t_func != None:
    class test_sf_automatic_angle_restrict_symm_err_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_angle_restrict_symm_err_e, (2.0*M_PI, &r), -2*DELTA, TEST_TOL1, GSL_SUCCESS)'
            self._test(('2.0*M_PI',), ('-2*DELTA', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_angle_restrict_symm_err_e, (-2.0*M_PI, &r), 2*DELTA, TEST_TOL1, GSL_SUCCESS)'
            self._test(('-2.0*M_PI',), ('2*DELTA', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_angle_restrict_symm_err_e, (1e9, &r), 0.5773954235013851694, TEST_TOL1, GSL_SUCCESS)'
            self._test((1000000000.0,), ('0.5773954235013851694', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_angle_restrict_symm_err_e, (1e12, &r), -0.6576247591367864674792517289, 100*TEST_SNGL, GSL_SUCCESS)'
            self._test((1000000000000.0,), ('-0.6576247591367864674792517289', '100*TEST_SNGL'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_angle_restrict_symm_err_e, (-1e9, &r), -0.5773954235013851694, TEST_TOL1, GSL_SUCCESS)'
            self._test((-1000000000.0,), ('-0.5773954235013851694', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_angle_restrict_symm_err_e, (-1e12, &r), 0.6576247591367864674792517289, 100*TEST_SNGL, GSL_SUCCESS)'
            self._test((-1000000000000.0,), ('0.6576247591367864674792517289', '100*TEST_SNGL'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_angle_restrict_symm_err_e, (1e15, &r), GSL_NAN, TEST_TOL1, GSL_ELOSS)'
            self._test((1000000000000000.0,), ('GSL_NAN', 'TEST_TOL1'), GSL_ELOSS)


        def test_args7_1(self):
            '(s, gsl_sf_angle_restrict_symm_err_e, (-1e15, &r), GSL_NAN, TEST_TOL1, GSL_ELOSS)'
            self._test((-1000000000000000.0,), ('GSL_NAN', 'TEST_TOL1'), GSL_ELOSS)

_t_func = None
try:
    _t_func = sf.atanint_e
except AttributeError:
    print("Not including tests for atanint_e")

if _t_func != None:
    class test_sf_automatic_atanint_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_atanint_e, (1.0e-10, &r), 1.0e-10, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('1.0e-10', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_atanint_e, (1.0e-05, &r), 9.99999999988888888889e-06, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-05,), ('9.99999999988888888889e-06', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_atanint_e, (0.1, &r), 0.09988928686033618404, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.09988928686033618404', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_atanint_e, (1.0, &r), 0.91596559417721901505, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.91596559417721901505', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_atanint_e, (2.0, &r), 1.57601540344632342236, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.0,), ('1.57601540344632342236', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_atanint_e, (10.0, &r), 3.71678149306806859029, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('3.71678149306806859029', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_atanint_e, (50.0, &r), 6.16499047850274874222, TEST_TOL0, GSL_SUCCESS)'
            self._test((50.0,), ('6.16499047850274874222', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_atanint_e, (300.0, &r), 8.96281388924518959990, TEST_TOL0, GSL_SUCCESS)'
            self._test((300.0,), ('8.96281388924518959990', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_atanint_e, (1.0e+5, &r), 18.084471031038661920, TEST_TOL0, GSL_SUCCESS)'
            self._test((100000.0,), ('18.084471031038661920', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_atanint_e, (1.0e+9, &r), 32.552029856869591656, TEST_TOL0, GSL_SUCCESS)'
            self._test((1000000000.0,), ('32.552029856869591656', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.clausen_e
except AttributeError:
    print("Not including tests for clausen_e")

if _t_func != None:
    class test_sf_automatic_clausen_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_clausen_e, (M_PI/20.0, &r), 0.4478882448133546, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/20.0',), ('0.4478882448133546', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_clausen_e, (M_PI/6.0, &r), 0.8643791310538927, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/6.0',), ('0.8643791310538927', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_clausen_e, (M_PI/3.0, &r), 1.0149416064096535, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/3.0',), ('1.0149416064096535', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_clausen_e, (  2.0*M_PI + M_PI/3.0, &r), 1.0149416064096535, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2.0*M_PI + M_PI/3.0',), ('1.0149416064096535', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_clausen_e, (100.0*M_PI + M_PI/3.0, &r), 1.0149416064096535, TEST_TOL0, GSL_SUCCESS)'
            self._test(('100.0*M_PI + M_PI/3.0',), ('1.0149416064096535', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.complex_cos_e
except AttributeError:
    print("Not including tests for complex_cos_e")

if _t_func != None:
    class test_sf_automatic_complex_cos_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_2(self):
            '(s, gsl_sf_complex_cos_e, (1.0, 5.0, &r1, &r2),40.09580630629882573, TEST_TOL0,-62.43984868079963017, TEST_TOL0,GSL_SUCCESS)'
            self._test2((1.0, 5.0), ('40.09580630629882573', 'TEST_TOL0'), ('-62.43984868079963017', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.complex_log_e
except AttributeError:
    print("Not including tests for complex_log_e")

if _t_func != None:
    class test_sf_automatic_complex_log_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_2(self):
            '(s, gsl_sf_complex_log_e, (1.0, 1.0, &r1, &r2),0.3465735902799726547, TEST_TOL0,0.7853981633974483096, TEST_TOL0,GSL_SUCCESS)'
            self._test2((1.0, 1.0), ('0.3465735902799726547', 'TEST_TOL0'), ('0.7853981633974483096', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_2(self):
            '(s, gsl_sf_complex_log_e, (1.0, -1.0, &r1, &r2),0.3465735902799726547, TEST_TOL0,-0.7853981633974483096, TEST_TOL0,GSL_SUCCESS)'
            self._test2((1.0, -1.0), ('0.3465735902799726547', 'TEST_TOL0'), ('-0.7853981633974483096', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_2(self):
            '(s, gsl_sf_complex_log_e, (1.0, 100.0, &r1, &r2),4.605220183488258022, TEST_TOL0,1.560796660108231381, TEST_TOL0,GSL_SUCCESS)'
            self._test2((1.0, 100.0), ('4.605220183488258022', 'TEST_TOL0'), ('1.560796660108231381', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_2(self):
            '(s, gsl_sf_complex_log_e, (-1000.0, -1.0, &r1, &r2),6.907755778981887052, TEST_TOL0,-3.1405926539231263718, TEST_TOL0,GSL_SUCCESS)'
            self._test2((-1000.0, -1.0), ('6.907755778981887052', 'TEST_TOL0'), ('-3.1405926539231263718', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_2(self):
            '(s, gsl_sf_complex_log_e, (-1.0, 0.0, &r1, &r2),0.0, TEST_TOL0,3.1415926535897932385, TEST_TOL0,GSL_SUCCESS)'
            self._test2((-1.0, 0.0), ('0.0', 'TEST_TOL0'), ('3.1415926535897932385', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.complex_logsin_e
except AttributeError:
    print("Not including tests for complex_logsin_e")

if _t_func != None:
    class test_sf_automatic_complex_logsin_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_2(self):
            '(s, gsl_sf_complex_logsin_e, (1.0, 100.0, &r1, &r2),99.3068528194400546900, TEST_TOL0,0.5707963267948966192, TEST_TOL0,GSL_SUCCESS)'
            self._test2((1.0, 100.0), ('99.3068528194400546900', 'TEST_TOL0'), ('0.5707963267948966192', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_2(self):
            '(s, gsl_sf_complex_logsin_e, (1.0, -100.0, &r1, &r2),99.3068528194400546900, TEST_TOL1,-0.5707963267948966192, TEST_TOL1,GSL_SUCCESS)'
            self._test2((1.0, -100.0), ('99.3068528194400546900', 'TEST_TOL1'), ('-0.5707963267948966192', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_2(self):
            '(s, gsl_sf_complex_logsin_e, (5.0, 5.0, &r1, &r2),4.3068909128079757420, TEST_TOL0,2.8540063315538773952, TEST_TOL0,GSL_SUCCESS)'
            self._test2((5.0, 5.0), ('4.3068909128079757420', 'TEST_TOL0'), ('2.8540063315538773952', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.complex_psi_e
except AttributeError:
    print("Not including tests for complex_psi_e")

if _t_func != None:
    class test_sf_automatic_complex_psi_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_2(self):
            '(s, gsl_sf_complex_psi_e, (1.0e+07, 1.0e+06, &r1, &r2),16.1230707668799525, TEST_TOL0,0.09966865744165720, TEST_TOL0,GSL_SUCCESS)'
            self._test2((10000000.0, 1000000.0), ('16.1230707668799525', 'TEST_TOL0'), ('0.09966865744165720', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_2(self):
            '(s, gsl_sf_complex_psi_e, (10.0, 50.0, &r1, &r2),3.92973987174863660, TEST_TOL0,1.38302847985210276, TEST_TOL0,GSL_SUCCESS)'
            self._test2((10.0, 50.0), ('3.92973987174863660', 'TEST_TOL0'), ('1.38302847985210276', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_2(self):
            '(s, gsl_sf_complex_psi_e, (2.0, 21.0, &r1, &r2),3.04697388853248195, TEST_TOL0,1.49947549076817824, TEST_TOL0,GSL_SUCCESS)'
            self._test2((2.0, 21.0), ('3.04697388853248195', 'TEST_TOL0'), ('1.49947549076817824', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_2(self):
            '(s, gsl_sf_complex_psi_e, (1.5, 0.0, &r1, &r2),0.0364899739785765206, TEST_TOL2,0.0, TEST_TOL1,GSL_SUCCESS)'
            self._test2((1.5, 0.0), ('0.0364899739785765206', 'TEST_TOL2'), ('0.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args4_2(self):
            '(s, gsl_sf_complex_psi_e, (1.0, 5.0, &r1, &r2),1.612784844615747, TEST_TOL1,1.470796326794968, TEST_TOL1,GSL_SUCCESS)'
            self._test2((1.0, 5.0), ('1.612784844615747', 'TEST_TOL1'), ('1.470796326794968', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_2(self):
            '(s, gsl_sf_complex_psi_e, (-1.5, 5.0, &r1, &r2),1.68260717336484070, TEST_TOL0,1.95230236730713338, TEST_TOL0,GSL_SUCCESS)'
            self._test2((-1.5, 5.0), ('1.68260717336484070', 'TEST_TOL0'), ('1.95230236730713338', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_2(self):
            '(s, gsl_sf_complex_psi_e, (-20.5, -20.5, &r1, &r2),3.37919358657933066, TEST_TOL0,-2.36829046481731091, TEST_TOL0,GSL_SUCCESS)'
            self._test2((-20.5, -20.5), ('3.37919358657933066', 'TEST_TOL0'), ('-2.36829046481731091', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.complex_sin_e
except AttributeError:
    print("Not including tests for complex_sin_e")

if _t_func != None:
    class test_sf_automatic_complex_sin_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_2(self):
            '(s, gsl_sf_complex_sin_e, (1.0, 5.0, &r1, &r2),62.44551846769653403, TEST_TOL0,40.09216577799840254, TEST_TOL0,GSL_SUCCESS)'
            self._test2((1.0, 5.0), ('62.44551846769653403', 'TEST_TOL0'), ('40.09216577799840254', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.cos_e
except AttributeError:
    print("Not including tests for cos_e")

if _t_func != None:
    class test_sf_automatic_cos_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_cos_e, (-10.0, &r),      -0.8390715290764524523,    TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('-0.8390715290764524523', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_cos_e, (1.0, &r),         0.5403023058681397174,    TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.5403023058681397174', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_cos_e, (1000.0, &r),      0.5623790762907029911,    TEST_TOL1, GSL_SUCCESS)'
            self._test((1000.0,), ('0.5623790762907029911', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_cos_e, (1048576.75, &r),  0.4652971620066351799,    TEST_TOL2, GSL_SUCCESS)'
            self._test((1048576.75,), ('0.4652971620066351799', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_cos_e, (62831853.75, &r), 0.7787006914966116436,    TEST_TOL2, GSL_SUCCESS)'
            self._test((62831853.75,), ('0.7787006914966116436', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_cos_e, (1073741822.5, &r),   -0.5601305436977716102,  TEST_SQRT_TOL0, GSL_SUCCESS)'
            self._test((1073741822.5,), ('-0.5601305436977716102', 'TEST_SQRT_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_cos_e, (1073741824.0, &r),    0.7867071229411881196,  TEST_SQRT_TOL0, GSL_SUCCESS)'
            self._test((1073741824.0,), ('0.7867071229411881196', 'TEST_SQRT_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.coupling_6j_e
except AttributeError:
    print("Not including tests for coupling_6j_e")

if _t_func != None:
    class test_sf_automatic_coupling_6j_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, 2, 4, 2, 2, 2, &r),  1.0/6.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 2, 4, 2, 2, 2), ('1.0/6.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_coupling_6j_e, (4, 4, 2, 4, 4, 4, &r), -1.0/10.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((4, 4, 2, 4, 4, 4), ('-1.0/10.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_coupling_6j_e, (4, 4, 2, 4, 4, 2, &r),  1.0/6.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((4, 4, 2, 4, 4, 2), ('1.0/6.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_coupling_6j_e, (4, 4, 2, 2, 2, 2, &r), -0.5/sqrt(5.0), TEST_TOL0, GSL_SUCCESS)'
            self._test((4, 4, 2, 2, 2, 2), ('-0.5/sqrt(5.0)', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_coupling_6j_e, (4, 4, 4, 2, 2, 2, &r),  sqrt(7.0/3.0)/10.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((4, 4, 4, 2, 2, 2), ('sqrt(7.0/3.0)/10.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_coupling_6j_e, (6, 6, 6, 4, 4, 4, &r), -sqrt(3.0/5.0)/14.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((6, 6, 6, 4, 4, 4), ('-sqrt(3.0/5.0)/14.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_coupling_6j_e, (6, 6, 6, 4, 4, 2, &r), -sqrt(3.0/5.0)/7.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((6, 6, 6, 4, 4, 2), ('-sqrt(3.0/5.0)/7.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_coupling_6j_e, (1, 0, 1, 0, 1, 0, &r), -sqrt(1.0/2.0), TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 0, 1, 0, 1, 0), ('-sqrt(1.0/2.0)', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_coupling_6j_e, (1, 0, 1, 1, 0, 1, &r), -1.0/2.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 0, 1, 1, 0, 1), ('-1.0/2.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_coupling_6j_e, (-2, 2, 4, 2, 2, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((-2, 2, 4, 2, 2, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args10_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, -2, 4, 2, 2, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((2, -2, 4, 2, 2, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args11_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, 2, -4, 2, 2, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((2, 2, -4, 2, 2, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args12_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, 2, 4, -2, 2, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((2, 2, 4, -2, 2, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args13_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, 2, 4, 2, -2, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((2, 2, 4, 2, -2, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args14_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, 2, 4, 2, 2, -2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((2, 2, 4, 2, 2, -2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args15_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, 2, 4, 2, 2, 7, &r), 0, 0, GSL_SUCCESS)'
            self._test((2, 2, 4, 2, 2, 7), ('0', '0'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, 2, 4, 2, 7, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((2, 2, 4, 2, 7, 2), ('0', '0'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, 2, 4, 7, 2, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((2, 2, 4, 7, 2, 2), ('0', '0'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, 2, 7, 2, 2, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((2, 2, 7, 2, 2, 2), ('0', '0'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s, gsl_sf_coupling_6j_e, (2, 7, 4, 2, 2, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((2, 7, 4, 2, 2, 2), ('0', '0'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s, gsl_sf_coupling_6j_e, (7, 2, 4, 2, 2, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((7, 2, 4, 2, 2, 2), ('0', '0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s, gsl_sf_coupling_6j_e, (0, 2, 2, 44, 43, 43, &r), 0, 0, GSL_SUCCESS)'
            self._test((0, 2, 2, 44, 43, 43), ('0', '0'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s, gsl_sf_coupling_6j_e, (1, 1, 1, 0, 1, 1, &r), 0, 0, GSL_SUCCESS)'
            self._test((1, 1, 1, 0, 1, 1), ('0', '0'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s, gsl_sf_coupling_6j_e, (1, 1, 1, 1, 0, 1, &r), 0, 0, GSL_SUCCESS)'
            self._test((1, 1, 1, 1, 0, 1), ('0', '0'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s, gsl_sf_coupling_6j_e, (1, 1, 1, 1, 1, 0, &r), 0, 0, GSL_SUCCESS)'
            self._test((1, 1, 1, 1, 1, 0), ('0', '0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.coupling_9j_e
except AttributeError:
    print("Not including tests for coupling_9j_e")

if _t_func != None:
    class test_sf_automatic_coupling_9j_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2,  4, 3, 3, 2, 1, 1, 2, &r), -sqrt(1.0/6.0)/10.0, TEST_TOL2, GSL_SUCCESS)'
            self._test((4, 2, 4, 3, 3, 2, 1, 1, 2), ('-sqrt(1.0/6.0)/10.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_coupling_9j_e, (8, 4, 10, 7, 3, 8, 1, 1, 2, &r),  sqrt(7.0/3.0)/60.0, TEST_TOL2, GSL_SUCCESS)'
            self._test((8, 4, 10, 7, 3, 8, 1, 1, 2), ('sqrt(7.0/3.0)/60.0', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_coupling_9j_e, (-4, 2, 4, 3, 3, 2, 1, 1, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((-4, 2, 4, 3, 3, 2, 1, 1, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args3_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, -2, 4, 3, 3, 2, 1, 1, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((4, -2, 4, 3, 3, 2, 1, 1, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args4_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, -4, 3, 3, 2, 1, 1, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((4, 2, -4, 3, 3, 2, 1, 1, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args5_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, -3, 3, 2, 1, 1, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((4, 2, 4, -3, 3, 2, 1, 1, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args6_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 3, -3, 2, 1, 1, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((4, 2, 4, 3, -3, 2, 1, 1, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args7_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 3, 3, -2, 1, 1, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((4, 2, 4, 3, 3, -2, 1, 1, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args8_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 3, 3, 2, -1, 1, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((4, 2, 4, 3, 3, 2, -1, 1, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args9_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 3, 3, 2, 1, -1, 2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((4, 2, 4, 3, 3, 2, 1, -1, 2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args10_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 3, 3, 2, 1, 1, -2, &r), GSL_NAN, GSL_NAN, GSL_EDOM)'
            self._test((4, 2, 4, 3, 3, 2, 1, 1, -2), ('GSL_NAN', 'GSL_NAN'), GSL_EDOM)


        def test_args11_1(self):
            '(s, gsl_sf_coupling_9j_e, (10, 2, 4, 3, 3, 2, 1, 1, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((10, 2, 4, 3, 3, 2, 1, 1, 2), ('0', '0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 10, 4, 3, 3, 2, 1, 1, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((4, 10, 4, 3, 3, 2, 1, 1, 2), ('0', '0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 10, 3, 3, 2, 1, 1, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((4, 2, 10, 3, 3, 2, 1, 1, 2), ('0', '0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 10, 3, 2, 1, 1, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((4, 2, 4, 10, 3, 2, 1, 1, 2), ('0', '0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 3, 10, 2, 1, 1, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((4, 2, 4, 3, 10, 2, 1, 1, 2), ('0', '0'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 3, 3, 10, 1, 1, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((4, 2, 4, 3, 3, 10, 1, 1, 2), ('0', '0'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 3, 3, 2, 10, 1, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((4, 2, 4, 3, 3, 2, 10, 1, 2), ('0', '0'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 3, 3, 2, 1, 10, 2, &r), 0, 0, GSL_SUCCESS)'
            self._test((4, 2, 4, 3, 3, 2, 1, 10, 2), ('0', '0'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s, gsl_sf_coupling_9j_e, (4, 2, 4, 3, 3, 2, 1, 1, 10, &r), 0, 0, GSL_SUCCESS)'
            self._test((4, 2, 4, 3, 3, 2, 1, 1, 10), ('0', '0'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s, gsl_sf_coupling_9j_e, (1, 1, 1, 1, 1, 1, 0, 0, 0, &r), 0, 0, GSL_SUCCESS)'
            self._test((1, 1, 1, 1, 1, 1, 0, 0, 0), ('0', '0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s, gsl_sf_coupling_9j_e, (1, 1, 0, 1, 1, 0, 1, 1, 0, &r), 0, 0, GSL_SUCCESS)'
            self._test((1, 1, 0, 1, 1, 0, 1, 1, 0), ('0', '0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.dawson_e
except AttributeError:
    print("Not including tests for dawson_e")

if _t_func != None:
    class test_sf_automatic_dawson_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_dawson_e, (1.0e-15, &r), 1.0e-15, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-15,), ('1.0e-15', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_dawson_e, (0.5, &r), 0.4244363835020222959, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5,), ('0.4244363835020222959', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_dawson_e, (2.0, &r), 0.30134038892379196603, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.0,), ('0.30134038892379196603', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_dawson_e, (1000.0, &r), 0.0005000002500003750009, TEST_TOL0, GSL_SUCCESS)'
            self._test((1000.0,), ('0.0005000002500003750009', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.debye_1_e
except AttributeError:
    print("Not including tests for debye_1_e")

if _t_func != None:
    class test_sf_automatic_debye_1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_debye_1_e, (0.1, &r),  0.975277750004723276, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.975277750004723276', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_debye_1_e, (1.0, &r),  0.777504634112248239, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.777504634112248239', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_debye_1_e, (10.0, &r), 0.164443465679946027, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('0.164443465679946027', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.debye_2_e
except AttributeError:
    print("Not including tests for debye_2_e")

if _t_func != None:
    class test_sf_automatic_debye_2_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_debye_2_e, (0.1, &r),  0.967083287045302664,  TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.967083287045302664', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_debye_2_e, (1.0, &r),  0.70787847562782924,   TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.70787847562782924', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_debye_2_e, (10.0, &r), 0.0479714980201218708, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('0.0479714980201218708', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.debye_3_e
except AttributeError:
    print("Not including tests for debye_3_e")

if _t_func != None:
    class test_sf_automatic_debye_3_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_debye_3_e, (0.1, &r),  0.962999940487211048,  TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.962999940487211048', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_debye_3_e, (1.0, &r),  0.674415564077814667,  TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.674415564077814667', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_debye_3_e, (10.0, &r), 0.0192957656903454886, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('0.0192957656903454886', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.debye_4_e
except AttributeError:
    print("Not including tests for debye_4_e")

if _t_func != None:
    class test_sf_automatic_debye_4_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_debye_4_e, (0.1, &r),  0.960555486124335944,   TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.960555486124335944', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_debye_4_e, (1.0, &r),  0.654874068886737049,   TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.654874068886737049', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_debye_4_e, (10.0, &r), 0.00967367556027115896, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('0.00967367556027115896', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.debye_5_e
except AttributeError:
    print("Not including tests for debye_5_e")

if _t_func != None:
    class test_sf_automatic_debye_5_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_debye_5_e, (0.1, &r),  0.95892849428310568745,  TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.95892849428310568745', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_debye_5_e, (1.0, &r),  0.6421002580217790246,   TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.6421002580217790246', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_debye_5_e, (10.0, &r), 0.005701535852992908538, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('0.005701535852992908538', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.debye_6_e
except AttributeError:
    print("Not including tests for debye_6_e")

if _t_func != None:
    class test_sf_automatic_debye_6_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_debye_6_e, (0.1, &r),  0.95776777382605465878,  TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.95776777382605465878', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_debye_6_e, (1.0, &r),  0.63311142583495107588,  TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.63311142583495107588', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_debye_6_e, (10.0, &r), 3.7938493294615955279e-3, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('3.7938493294615955279e-3', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.ellint_D_e
except AttributeError:
    print("Not including tests for ellint_D_e")

if _t_func != None:
    class test_sf_automatic_ellint_D_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_D_e, (M_PI/2.0, 0.99, mode, &r), 2.375395076351788975665323192, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('2.375395076351788975665323192', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_ellint_D_e, (M_PI/2.0, 0.50, mode, &r), 0.8731525818926755496456335628, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('0.8731525818926755496456335628', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_ellint_D_e, (M_PI/2.0, 0.01, mode, &r), 0.7854276176694868932799393751, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('0.7854276176694868932799393751', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_ellint_D_e, (2*M_PI/3.0, 0.99, mode, &r), 4.305885125424644860264320635, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('4.305885125424644860264320635', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_ellint_D_e, (2*M_PI/3.0, 0.50, mode, &r), 1.418324704155697579394036402, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('1.418324704155697579394036402', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_ellint_D_e, (2*M_PI/3.0, 0.01, mode, &r), 1.263755353901126149206022061, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('1.263755353901126149206022061', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_ellint_D_e, (M_PI, 0.99, mode, &r), 4.750790152703577951330646444, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('4.750790152703577951330646444', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_ellint_D_e, (M_PI, 0.50, mode, &r), 1.746305163785351099291267125, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('1.746305163785351099291267125', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_ellint_D_e, (M_PI, 0.01, mode, &r), 1.570855235338973786559878750, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('1.570855235338973786559878750', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_ellint_D_e, (4*M_PI/3, 0.99, mode, &r), 5.195695179982511042396972113, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('5.195695179982511042396972113', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_ellint_D_e, (4*M_PI/3, 0.50, mode, &r), 2.074285623415004619188497818, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('2.074285623415004619188497818', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_ellint_D_e, (4*M_PI/3, 0.01, mode, &r), 1.877955116776821423913735408, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('1.877955116776821423913735408', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_ellint_D_e, (3*M_PI/2.0, 0.99, mode, &r), 7.126185229055366926995969476, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('7.126185229055366926995969476', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_ellint_D_e, (3*M_PI/2.0, 0.50, mode, &r), 2.619457745678026648936900687, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('2.619457745678026648936900687', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_ellint_D_e, (3*M_PI/2.0, 0.01, mode, &r), 2.356282853008460679839818125, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('2.356282853008460679839818125', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_ellint_D_e, (5*M_PI/3, 0.99, mode, &r), 9.056675278128222811594967044, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('9.056675278128222811594967044', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s,  gsl_sf_ellint_D_e, (5*M_PI/3, 0.50, mode, &r), 3.164629867941048678685303509, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('3.164629867941048678685303509', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s,  gsl_sf_ellint_D_e, (5*M_PI/3, 0.01, mode, &r), 2.834610589240099935765900794, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('2.834610589240099935765900794', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s,  gsl_sf_ellint_D_e, (2*M_PI, 0.99, mode, &r), 9.501580305407155902661292832, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('9.501580305407155902661292832', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s,  gsl_sf_ellint_D_e, (2*M_PI, 0.50, mode, &r), 3.492610327570702198582534249, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('3.492610327570702198582534249', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s,  gsl_sf_ellint_D_e, (2*M_PI, 0.01, mode, &r), 3.141710470677947573119757500, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('3.141710470677947573119757500', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s,  gsl_sf_ellint_D_e, (7*M_PI/3.0, 0.99, mode, &r), 9.946485332686088993727618315, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('9.946485332686088993727618315', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s,  gsl_sf_ellint_D_e, (7*M_PI/3.0, 0.50, mode, &r), 3.820590787200355718479764901, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('3.820590787200355718479764901', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s,  gsl_sf_ellint_D_e, (7*M_PI/3.0, 0.01, mode, &r), 3.448810352115795210473614120, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('3.448810352115795210473614120', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s,  gsl_sf_ellint_D_e, (-M_PI/2.0, 0.99, mode, &r), -2.375395076351788975665323192, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('-2.375395076351788975665323192', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s,  gsl_sf_ellint_D_e, (-M_PI/2.0, 0.50, mode, &r), -0.8731525818926755496456335628, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('-0.8731525818926755496456335628', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s,  gsl_sf_ellint_D_e, (-M_PI/2.0, 0.01, mode, &r), -0.7854276176694868932799393751, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('-0.7854276176694868932799393751', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s,  gsl_sf_ellint_D_e, (-2*M_PI/3.0, 0.99, mode, &r), -4.305885125424644860264320635, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('-4.305885125424644860264320635', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s,  gsl_sf_ellint_D_e, (-2*M_PI/3.0, 0.50, mode, &r), -1.418324704155697579394036402, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('-1.418324704155697579394036402', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s,  gsl_sf_ellint_D_e, (-2*M_PI/3.0, 0.01, mode, &r), -1.263755353901126149206022061, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('-1.263755353901126149206022061', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args30_1(self):
            '(s,  gsl_sf_ellint_D_e, (-M_PI, 0.99, mode, &r), -4.750790152703577951330646444, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('-4.750790152703577951330646444', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args31_1(self):
            '(s,  gsl_sf_ellint_D_e, (-M_PI, 0.50, mode, &r), -1.746305163785351099291267125, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('-1.746305163785351099291267125', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args32_1(self):
            '(s,  gsl_sf_ellint_D_e, (-M_PI, 0.01, mode, &r), -1.570855235338973786559878750, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('-1.570855235338973786559878750', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args33_1(self):
            '(s,  gsl_sf_ellint_D_e, (-4*M_PI/3, 0.99, mode, &r), -5.195695179982511042396972113, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('-5.195695179982511042396972113', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args34_1(self):
            '(s,  gsl_sf_ellint_D_e, (-4*M_PI/3, 0.50, mode, &r), -2.074285623415004619188497818, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('-2.074285623415004619188497818', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args35_1(self):
            '(s,  gsl_sf_ellint_D_e, (-4*M_PI/3, 0.01, mode, &r), -1.877955116776821423913735408, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('-1.877955116776821423913735408', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args36_1(self):
            '(s,  gsl_sf_ellint_D_e, (-3*M_PI/2.0, 0.99, mode, &r), -7.126185229055366926995969476, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('-7.126185229055366926995969476', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args37_1(self):
            '(s,  gsl_sf_ellint_D_e, (-3*M_PI/2.0, 0.50, mode, &r), -2.619457745678026648936900687, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('-2.619457745678026648936900687', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args38_1(self):
            '(s,  gsl_sf_ellint_D_e, (-3*M_PI/2.0, 0.01, mode, &r), -2.356282853008460679839818125, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('-2.356282853008460679839818125', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args39_1(self):
            '(s,  gsl_sf_ellint_D_e, (-5*M_PI/3, 0.99, mode, &r), -9.056675278128222811594967044, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('-9.056675278128222811594967044', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args40_1(self):
            '(s,  gsl_sf_ellint_D_e, (-5*M_PI/3, 0.50, mode, &r), -3.164629867941048678685303509, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('-3.164629867941048678685303509', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args41_1(self):
            '(s,  gsl_sf_ellint_D_e, (-5*M_PI/3, 0.01, mode, &r), -2.834610589240099935765900794, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('-2.834610589240099935765900794', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args42_1(self):
            '(s,  gsl_sf_ellint_D_e, (-2*M_PI, 0.99, mode, &r), -9.501580305407155902661292832, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('-9.501580305407155902661292832', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args43_1(self):
            '(s,  gsl_sf_ellint_D_e, (-2*M_PI, 0.50, mode, &r), -3.492610327570702198582534249, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('-3.492610327570702198582534249', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args44_1(self):
            '(s,  gsl_sf_ellint_D_e, (-2*M_PI, 0.01, mode, &r), -3.141710470677947573119757500, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('-3.141710470677947573119757500', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args45_1(self):
            '(s,  gsl_sf_ellint_D_e, (-7*M_PI/3.0, 0.99, mode, &r), -9.946485332686088993727618315, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('-9.946485332686088993727618315', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args46_1(self):
            '(s,  gsl_sf_ellint_D_e, (-7*M_PI/3.0, 0.50, mode, &r), -3.820590787200355718479764901, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('-3.820590787200355718479764901', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args47_1(self):
            '(s,  gsl_sf_ellint_D_e, (-7*M_PI/3.0, 0.01, mode, &r), -3.448810352115795210473614120, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('-3.448810352115795210473614120', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.ellint_Dcomp_e
except AttributeError:
    print("Not including tests for ellint_Dcomp_e")

if _t_func != None:
    class test_sf_automatic_ellint_Dcomp_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_Dcomp_e, (0.99, mode, &r), 2.375395076351788975665323192, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.99, 'GSL_MODE_DEFAULT'), ('2.375395076351788975665323192', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_ellint_Dcomp_e, (0.50, mode, &r), 0.8731525818926755496456335628, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5, 'GSL_MODE_DEFAULT'), ('0.8731525818926755496456335628', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_ellint_Dcomp_e, (0.01, mode, &r), 0.7854276176694868932799393751, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.01, 'GSL_MODE_DEFAULT'), ('0.7854276176694868932799393751', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.ellint_E_e
except AttributeError:
    print("Not including tests for ellint_E_e")

if _t_func != None:
    class test_sf_automatic_ellint_E_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_E_e, (M_PI/3.0, 0.99, mode, &r), 0.8704819220377943536, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('0.8704819220377943536', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_ellint_E_e, (M_PI/3.0, 0.50, mode, &r), 1.0075555551444720293, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('1.0075555551444720293', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_ellint_E_e, (M_PI/3.0, 0.01, mode, &r), 1.0471821963889481104, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('1.0471821963889481104', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_ellint_E_e, (M_PI/2.0, 0.99, mode, &r), 1.02847580902880400098389, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('1.02847580902880400098389', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_ellint_E_e, (M_PI/2.0, 0.50, mode, &r), 1.46746220933942715545980, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('1.46746220933942715545980', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_ellint_E_e, (M_PI/2.0, 0.01, mode, &r), 1.57075705615038528733708, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('1.57075705615038528733708', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_ellint_E_e, (2*M_PI/3.0, 0.99, mode, &r), 1.18646969601981364833972, TEST_TOL1, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('1.18646969601981364833972', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_ellint_E_e, (2*M_PI/3.0, 0.50, mode, &r), 1.92736886353438228163734, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('1.92736886353438228163734', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_ellint_E_e, (2*M_PI/3.0, 0.01, mode, &r), 2.09433191591182246425715, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('2.09433191591182246425715', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_ellint_E_e, (M_PI, 0.99, mode, &r), 2.05695161805760800196777, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('2.05695161805760800196777', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_ellint_E_e, (M_PI, 0.50, mode, &r), 2.93492441867885431091959, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('2.93492441867885431091959', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_ellint_E_e, (M_PI, 0.01, mode, &r), 3.14151411230077057467416, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('3.14151411230077057467416', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_ellint_E_e, (4*M_PI/3, 0.99, mode, &r), 2.92743354009540235559582, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('2.92743354009540235559582', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_ellint_E_e, (4*M_PI/3, 0.50, mode, &r), 3.94247997382332634020184, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('3.94247997382332634020184', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_ellint_E_e, (4*M_PI/3, 0.01, mode, &r), 4.18869630868971868509117, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('4.18869630868971868509117', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_ellint_E_e, (3*M_PI/2.0, 0.99, mode, &r), 3.08542742708641200295166, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('3.08542742708641200295166', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s,  gsl_sf_ellint_E_e, (3*M_PI/2.0, 0.50, mode, &r), 4.40238662801828146637939, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('4.40238662801828146637939', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s,  gsl_sf_ellint_E_e, (3*M_PI/2.0, 0.01, mode, &r), 4.71227116845115586201123, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('4.71227116845115586201123', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s,  gsl_sf_ellint_E_e, (5*M_PI/3, 0.99, mode, &r), 3.24342131407742165030750, TEST_TOL1, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('3.24342131407742165030750', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s,  gsl_sf_ellint_E_e, (5*M_PI/3, 0.50, mode, &r), 4.86229328221323659255693, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('4.86229328221323659255693', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s,  gsl_sf_ellint_E_e, (5*M_PI/3, 0.01, mode, &r), 5.23584602821259303893130, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('5.23584602821259303893130', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s,  gsl_sf_ellint_E_e, (2*M_PI, 0.99, mode, &r), 4.11390323611521600393555, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('4.11390323611521600393555', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s,  gsl_sf_ellint_E_e, (2*M_PI, 0.50, mode, &r), 5.86984883735770862183918, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('5.86984883735770862183918', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s,  gsl_sf_ellint_E_e, (2*M_PI, 0.01, mode, &r), 6.28302822460154114934831, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('6.28302822460154114934831', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s,  gsl_sf_ellint_E_e, (7*M_PI/3.0, 0.99, mode, &r), 4.98438515815301035756360, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('4.98438515815301035756360', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s,  gsl_sf_ellint_E_e, (7*M_PI/3.0, 0.50, mode, &r), 6.87740439250218065112143, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('6.87740439250218065112143', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s,  gsl_sf_ellint_E_e, (7*M_PI/3.0, 0.01, mode, &r), 7.33021042099048925976532, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('7.33021042099048925976532', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s,  gsl_sf_ellint_E_e, (-M_PI/2.0, 0.99, mode, &r), -1.02847580902880400098389, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('-1.02847580902880400098389', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s,  gsl_sf_ellint_E_e, (-M_PI/2.0, 0.50, mode, &r), -1.46746220933942715545980, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('-1.46746220933942715545980', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s,  gsl_sf_ellint_E_e, (-M_PI/2.0, 0.01, mode, &r), -1.57075705615038528733708, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('-1.57075705615038528733708', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args30_1(self):
            '(s,  gsl_sf_ellint_E_e, (-2*M_PI/3.0, 0.99, mode, &r), -1.18646969601981364833972, TEST_TOL1, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('-1.18646969601981364833972', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args31_1(self):
            '(s,  gsl_sf_ellint_E_e, (-2*M_PI/3.0, 0.50, mode, &r), -1.92736886353438228163734, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('-1.92736886353438228163734', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args32_1(self):
            '(s,  gsl_sf_ellint_E_e, (-2*M_PI/3.0, 0.01, mode, &r), -2.09433191591182246425715, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('-2.09433191591182246425715', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args33_1(self):
            '(s,  gsl_sf_ellint_E_e, (-M_PI, 0.99, mode, &r), -2.05695161805760800196777, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('-2.05695161805760800196777', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args34_1(self):
            '(s,  gsl_sf_ellint_E_e, (-M_PI, 0.50, mode, &r), -2.93492441867885431091959, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('-2.93492441867885431091959', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args35_1(self):
            '(s,  gsl_sf_ellint_E_e, (-M_PI, 0.01, mode, &r), -3.14151411230077057467416, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('-3.14151411230077057467416', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args36_1(self):
            '(s,  gsl_sf_ellint_E_e, (-4*M_PI/3, 0.99, mode, &r), -2.92743354009540235559582, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('-2.92743354009540235559582', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args37_1(self):
            '(s,  gsl_sf_ellint_E_e, (-4*M_PI/3, 0.50, mode, &r), -3.94247997382332634020184, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('-3.94247997382332634020184', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args38_1(self):
            '(s,  gsl_sf_ellint_E_e, (-4*M_PI/3, 0.01, mode, &r), -4.18869630868971868509117, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('-4.18869630868971868509117', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args39_1(self):
            '(s,  gsl_sf_ellint_E_e, (-3*M_PI/2.0, 0.99, mode, &r), -3.08542742708641200295166, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('-3.08542742708641200295166', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args40_1(self):
            '(s,  gsl_sf_ellint_E_e, (-3*M_PI/2.0, 0.50, mode, &r), -4.40238662801828146637939, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('-4.40238662801828146637939', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args41_1(self):
            '(s,  gsl_sf_ellint_E_e, (-3*M_PI/2.0, 0.01, mode, &r), -4.71227116845115586201123, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('-4.71227116845115586201123', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args42_1(self):
            '(s,  gsl_sf_ellint_E_e, (-5*M_PI/3, 0.99, mode, &r), -3.24342131407742165030750, TEST_TOL1, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('-3.24342131407742165030750', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args43_1(self):
            '(s,  gsl_sf_ellint_E_e, (-5*M_PI/3, 0.50, mode, &r), -4.86229328221323659255693, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('-4.86229328221323659255693', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args44_1(self):
            '(s,  gsl_sf_ellint_E_e, (-5*M_PI/3, 0.01, mode, &r), -5.23584602821259303893130, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('-5.23584602821259303893130', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args45_1(self):
            '(s,  gsl_sf_ellint_E_e, (-2*M_PI, 0.99, mode, &r), -4.11390323611521600393555, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('-4.11390323611521600393555', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args46_1(self):
            '(s,  gsl_sf_ellint_E_e, (-2*M_PI, 0.50, mode, &r), -5.86984883735770862183918, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('-5.86984883735770862183918', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args47_1(self):
            '(s,  gsl_sf_ellint_E_e, (-2*M_PI, 0.01, mode, &r), -6.28302822460154114934831, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('-6.28302822460154114934831', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args48_1(self):
            '(s,  gsl_sf_ellint_E_e, (-7*M_PI/3.0, 0.99, mode, &r), -4.98438515815301035756360, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('-4.98438515815301035756360', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args49_1(self):
            '(s,  gsl_sf_ellint_E_e, (-7*M_PI/3.0, 0.50, mode, &r), -6.87740439250218065112143, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('-6.87740439250218065112143', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args50_1(self):
            '(s,  gsl_sf_ellint_E_e, (-7*M_PI/3.0, 0.01, mode, &r), -7.33021042099048925976532, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('-7.33021042099048925976532', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.ellint_Ecomp_e
except AttributeError:
    print("Not including tests for ellint_Ecomp_e")

if _t_func != None:
    class test_sf_automatic_ellint_Ecomp_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_Ecomp_e, (0.99, mode, &r), 1.0284758090288040010, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.99, 'GSL_MODE_DEFAULT'), ('1.0284758090288040010', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_ellint_Ecomp_e, (0.50, mode, &r), 1.4674622093394271555, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5, 'GSL_MODE_DEFAULT'), ('1.4674622093394271555', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_ellint_Ecomp_e, (0.01, mode, &r), 1.5707570561503852873, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.01, 'GSL_MODE_DEFAULT'), ('1.5707570561503852873', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_ellint_Ecomp_e, (GSL_NAN, mode, &r), GSL_NAN, GSL_NAN, GSL_EMAXITER)'
            self._test(('GSL_NAN', 'GSL_MODE_DEFAULT'), ('GSL_NAN', 'GSL_NAN'), GSL_EMAXITER)

_t_func = None
try:
    _t_func = sf.ellint_F_e
except AttributeError:
    print("Not including tests for ellint_F_e")

if _t_func != None:
    class test_sf_automatic_ellint_F_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_F_e, (M_PI/3.0, 0.99, mode, &r), 1.3065333392738766762, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('1.3065333392738766762', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_ellint_F_e, (M_PI/3.0, 0.50, mode, &r), 1.0895506700518854093, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('1.0895506700518854093', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_ellint_F_e, (M_PI/3.0, 0.01, mode, &r), 1.0472129063770918952, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('1.0472129063770918952', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_ellint_F_e, (M_PI/2.0, 0.99, mode, &r), 3.35660052336119237603347, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('3.35660052336119237603347', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_ellint_F_e, (M_PI/2.0, 0.50, mode, &r), 1.68575035481259604287120, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('1.68575035481259604287120', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_ellint_F_e, (M_PI/2.0, 0.01, mode, &r), 1.57083559891215223602641, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('1.57083559891215223602641', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_ellint_F_e, (2*M_PI/3.0, 0.99, mode, &r), 5.40666770744850807588478, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('5.40666770744850807588478', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_ellint_F_e, (2*M_PI/3.0, 0.50, mode, &r), 2.28195003957330667648585, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('2.28195003957330667648585', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_ellint_F_e, (2*M_PI/3.0, 0.01, mode, &r), 2.09445829144721257687207, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('2.09445829144721257687207', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_ellint_F_e, (M_PI, 0.99, mode, &r), 6.71320104672238475206694, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('6.71320104672238475206694', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_ellint_F_e, (M_PI, 0.50, mode, &r), 3.37150070962519208574241, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('3.37150070962519208574241', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_ellint_F_e, (M_PI, 0.01, mode, &r), 3.14167119782430447205281, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('3.14167119782430447205281', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_ellint_F_e, (4*M_PI/3, 0.99, mode, &r), 8.01973438599626142824910, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('8.01973438599626142824910', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_ellint_F_e, (4*M_PI/3, 0.50, mode, &r), 4.46105137967707749499897, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('4.46105137967707749499897', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_ellint_F_e, (4*M_PI/3, 0.01, mode, &r), 4.18888410420139636723356, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('4.18888410420139636723356', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_ellint_F_e, (3*M_PI/2.0, 0.99, mode, &r), 10.0698015700835771281004, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('10.0698015700835771281004', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s,  gsl_sf_ellint_F_e, (3*M_PI/2.0, 0.50, mode, &r), 5.05725106443778812861361, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('5.05725106443778812861361', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s,  gsl_sf_ellint_F_e, (3*M_PI/2.0, 0.01, mode, &r), 4.71250679673645670807922, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('4.71250679673645670807922', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s,  gsl_sf_ellint_F_e, (5*M_PI/3, 0.99, mode, &r), 12.1198687541708928279517, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('12.1198687541708928279517', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s,  gsl_sf_ellint_F_e, (5*M_PI/3, 0.50, mode, &r), 5.65345074919849876222825, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('5.65345074919849876222825', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s,  gsl_sf_ellint_F_e, (5*M_PI/3, 0.01, mode, &r), 5.23612948927151704892488, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('5.23612948927151704892488', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s,  gsl_sf_ellint_F_e, (2*M_PI, 0.99, mode, &r), 13.4264020934447695041339, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('13.4264020934447695041339', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s,  gsl_sf_ellint_F_e, (2*M_PI, 0.50, mode, &r), 6.74300141925038417148481, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('6.74300141925038417148481', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s,  gsl_sf_ellint_F_e, (2*M_PI, 0.01, mode, &r), 6.28334239564860894410562, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('6.28334239564860894410562', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s,  gsl_sf_ellint_F_e, (7*M_PI/3.0, 0.99, mode, &r), 14.7329354327186461803160, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('14.7329354327186461803160', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s,  gsl_sf_ellint_F_e, (7*M_PI/3.0, 0.50, mode, &r), 7.83255208930226958074138, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('7.83255208930226958074138', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s,  gsl_sf_ellint_F_e, (7*M_PI/3.0, 0.01, mode, &r), 7.33055530202570083928637, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('7.33055530202570083928637', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s,  gsl_sf_ellint_F_e, (-M_PI/2.0, 0.99, mode, &r), -3.35660052336119237603347, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('-3.35660052336119237603347', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s,  gsl_sf_ellint_F_e, (-M_PI/2.0, 0.50, mode, &r), -1.68575035481259604287120, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('-1.68575035481259604287120', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s,  gsl_sf_ellint_F_e, (-M_PI/2.0, 0.01, mode, &r), -1.57083559891215223602641, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('-1.57083559891215223602641', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args30_1(self):
            '(s,  gsl_sf_ellint_F_e, (-2*M_PI/3.0, 0.99, mode, &r), -5.40666770744850807588478, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('-5.40666770744850807588478', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args31_1(self):
            '(s,  gsl_sf_ellint_F_e, (-2*M_PI/3.0, 0.50, mode, &r), -2.28195003957330667648585, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('-2.28195003957330667648585', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args32_1(self):
            '(s,  gsl_sf_ellint_F_e, (-2*M_PI/3.0, 0.01, mode, &r), -2.09445829144721257687207, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('-2.09445829144721257687207', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args33_1(self):
            '(s,  gsl_sf_ellint_F_e, (-M_PI, 0.99, mode, &r), -6.71320104672238475206694, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('-6.71320104672238475206694', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args34_1(self):
            '(s,  gsl_sf_ellint_F_e, (-M_PI, 0.50, mode, &r), -3.37150070962519208574241, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('-3.37150070962519208574241', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args35_1(self):
            '(s,  gsl_sf_ellint_F_e, (-M_PI, 0.01, mode, &r), -3.14167119782430447205281, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('-3.14167119782430447205281', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args36_1(self):
            '(s,  gsl_sf_ellint_F_e, (-4*M_PI/3, 0.99, mode, &r), -8.01973438599626142824910, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('-8.01973438599626142824910', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args37_1(self):
            '(s,  gsl_sf_ellint_F_e, (-4*M_PI/3, 0.50, mode, &r), -4.46105137967707749499897, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('-4.46105137967707749499897', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args38_1(self):
            '(s,  gsl_sf_ellint_F_e, (-4*M_PI/3, 0.01, mode, &r), -4.18888410420139636723356, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('-4.18888410420139636723356', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args39_1(self):
            '(s,  gsl_sf_ellint_F_e, (-3*M_PI/2.0, 0.99, mode, &r), -10.0698015700835771281004, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.99, 'GSL_MODE_DEFAULT'), ('-10.0698015700835771281004', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args40_1(self):
            '(s,  gsl_sf_ellint_F_e, (-3*M_PI/2.0, 0.50, mode, &r), -5.05725106443778812861361, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.5, 'GSL_MODE_DEFAULT'), ('-5.05725106443778812861361', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args41_1(self):
            '(s,  gsl_sf_ellint_F_e, (-3*M_PI/2.0, 0.01, mode, &r), -4.71250679673645670807922, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.01, 'GSL_MODE_DEFAULT'), ('-4.71250679673645670807922', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args42_1(self):
            '(s,  gsl_sf_ellint_F_e, (-5*M_PI/3, 0.99, mode, &r), -12.1198687541708928279517, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.99, 'GSL_MODE_DEFAULT'), ('-12.1198687541708928279517', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args43_1(self):
            '(s,  gsl_sf_ellint_F_e, (-5*M_PI/3, 0.50, mode, &r), -5.65345074919849876222825, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.5, 'GSL_MODE_DEFAULT'), ('-5.65345074919849876222825', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args44_1(self):
            '(s,  gsl_sf_ellint_F_e, (-5*M_PI/3, 0.01, mode, &r), -5.23612948927151704892488, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.01, 'GSL_MODE_DEFAULT'), ('-5.23612948927151704892488', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args45_1(self):
            '(s,  gsl_sf_ellint_F_e, (-2*M_PI, 0.99, mode, &r), -13.4264020934447695041339, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.99, 'GSL_MODE_DEFAULT'), ('-13.4264020934447695041339', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args46_1(self):
            '(s,  gsl_sf_ellint_F_e, (-2*M_PI, 0.50, mode, &r), -6.74300141925038417148481, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.5, 'GSL_MODE_DEFAULT'), ('-6.74300141925038417148481', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args47_1(self):
            '(s,  gsl_sf_ellint_F_e, (-2*M_PI, 0.01, mode, &r), -6.28334239564860894410562, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.01, 'GSL_MODE_DEFAULT'), ('-6.28334239564860894410562', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args48_1(self):
            '(s,  gsl_sf_ellint_F_e, (-7*M_PI/3.0, 0.99, mode, &r), -14.7329354327186461803160, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.99, 'GSL_MODE_DEFAULT'), ('-14.7329354327186461803160', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args49_1(self):
            '(s,  gsl_sf_ellint_F_e, (-7*M_PI/3.0, 0.50, mode, &r), -7.83255208930226958074138, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.5, 'GSL_MODE_DEFAULT'), ('-7.83255208930226958074138', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args50_1(self):
            '(s,  gsl_sf_ellint_F_e, (-7*M_PI/3.0, 0.01, mode, &r), -7.33055530202570083928637, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.01, 'GSL_MODE_DEFAULT'), ('-7.33055530202570083928637', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.ellint_Kcomp_e
except AttributeError:
    print("Not including tests for ellint_Kcomp_e")

if _t_func != None:
    class test_sf_automatic_ellint_Kcomp_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_Kcomp_e, ( 0.99, mode, &r), 3.3566005233611923760, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.99, 'GSL_MODE_DEFAULT'), ('3.3566005233611923760', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_ellint_Kcomp_e, ( 0.50, mode, &r), 1.6857503548125960429, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5, 'GSL_MODE_DEFAULT'), ('1.6857503548125960429', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_ellint_Kcomp_e, (0.010, mode, &r), 1.5708355989121522360, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.01, 'GSL_MODE_DEFAULT'), ('1.5708355989121522360', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_ellint_Kcomp_e, ( 0.99999999906867742538, mode, &r), 11.4369284843320018031, TEST_SNGL, GSL_SUCCESS)'
            self._test((0.9999999990686774, 'GSL_MODE_DEFAULT'), ('11.4369284843320018031', 'TEST_SNGL'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_ellint_Kcomp_e, (GSL_NAN, mode, &r), GSL_NAN, GSL_NAN, GSL_EMAXITER)'
            self._test(('GSL_NAN', 'GSL_MODE_DEFAULT'), ('GSL_NAN', 'GSL_NAN'), GSL_EMAXITER)

_t_func = None
try:
    _t_func = sf.ellint_P_e
except AttributeError:
    print("Not including tests for ellint_P_e")

if _t_func != None:
    class test_sf_automatic_ellint_P_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_P_e, (M_PI/3.0, 0.99, 0.5, mode, &r), 1.1288726598764099882, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/3.0', 0.99, 0.5, 'GSL_MODE_DEFAULT'), ('1.1288726598764099882', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_ellint_P_e, (M_PI/3.0, 0.50, 0.5, mode, &r), 0.9570574331323584890, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/3.0', 0.5, 0.5, 'GSL_MODE_DEFAULT'), ('0.9570574331323584890', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_ellint_P_e, (M_PI/3.0, 0.01, 0.5, mode, &r), 0.9228868127118118465, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/3.0', 0.01, 0.5, 'GSL_MODE_DEFAULT'), ('0.9228868127118118465', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_ellint_P_e, (M_PI/2.0, 0.99, -0.1, mode, &r), 3.61678162163246646783050, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('3.61678162163246646783050', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_ellint_P_e, (M_PI/2.0, 0.50, -0.1, mode, &r), 1.78030349465454812629168, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('1.78030349465454812629168', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_ellint_P_e, (M_PI/2.0, 0.01, -0.1, mode, &r), 1.65580719756898353270922, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI/2.0', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('1.65580719756898353270922', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_ellint_P_e, (2*M_PI/3.0, 0.99, -0.1, mode, &r), 5.88008918207571119911983, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('5.88008918207571119911983', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_ellint_P_e, (2*M_PI/3.0, 0.50, -0.1, mode, &r), 2.43655207300356008717867, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('2.43655207300356008717867', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_ellint_P_e, (2*M_PI/3.0, 0.01, -0.1, mode, &r), 2.23211110528200554950903, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI/3.0', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('2.23211110528200554950903', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_ellint_P_e, (M_PI, 0.99, -0.1, mode, &r), 7.23356324326493293566099, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('7.23356324326493293566099', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_ellint_P_e, (M_PI, 0.50, -0.1, mode, &r), 3.56060698930909625258336, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('3.56060698930909625258336', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_ellint_P_e, (M_PI, 0.01, -0.1, mode, &r), 3.31161439513796706541844, TEST_TOL0, GSL_SUCCESS)'
            self._test(('M_PI', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('3.31161439513796706541844', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_ellint_P_e, (4*M_PI/3, 0.99, -0.1, mode, &r), 8.58703730445415467220216, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('8.58703730445415467220216', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_ellint_P_e, (4*M_PI/3, 0.50, -0.1, mode, &r), 4.68466190561463241798805, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('4.68466190561463241798805', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_ellint_P_e, (4*M_PI/3, 0.01, -0.1, mode, &r), 4.39111768499392858132786, TEST_TOL0, GSL_SUCCESS)'
            self._test(('4*M_PI/3', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('4.39111768499392858132786', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_ellint_P_e, (3*M_PI/2.0, 0.99, -0.1, mode, &r), 10.8503448648973994034915, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('10.8503448648973994034915', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s,  gsl_sf_ellint_P_e, (3*M_PI/2.0, 0.50, -0.1, mode, &r), 5.34091048396364437887504, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('5.34091048396364437887504', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s,  gsl_sf_ellint_P_e, (3*M_PI/2.0, 0.01, -0.1, mode, &r), 4.96742159270695059812767, TEST_TOL0, GSL_SUCCESS)'
            self._test(('3*M_PI/2.0', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('4.96742159270695059812767', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s,  gsl_sf_ellint_P_e, (5*M_PI/3, 0.99, -0.1, mode, &r), 13.1136524253406441347808, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('13.1136524253406441347808', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s,  gsl_sf_ellint_P_e, (5*M_PI/3, 0.50, -0.1, mode, &r), 5.99715906231265633976204, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('5.99715906231265633976204', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s,  gsl_sf_ellint_P_e, (5*M_PI/3, 0.01, -0.1, mode, &r), 5.54372550041997261492747, TEST_TOL0, GSL_SUCCESS)'
            self._test(('5*M_PI/3', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('5.54372550041997261492747', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s,  gsl_sf_ellint_P_e, (2*M_PI, 0.99, -0.1, mode, &r), 14.4671264865298658713220, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('14.4671264865298658713220', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s,  gsl_sf_ellint_P_e, (2*M_PI, 0.50, -0.1, mode, &r), 7.12121397861819250516672, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('7.12121397861819250516672', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s,  gsl_sf_ellint_P_e, (2*M_PI, 0.01, -0.1, mode, &r), 6.62322879027593413083689, TEST_TOL0, GSL_SUCCESS)'
            self._test(('2*M_PI', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('6.62322879027593413083689', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s,  gsl_sf_ellint_P_e, (7*M_PI/3.0, 0.99, -0.1, mode, &r), 15.8206005477190876078631, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('15.8206005477190876078631', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s,  gsl_sf_ellint_P_e, (7*M_PI/3.0, 0.50, -0.1, mode, &r), 8.24526889492372867057141, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('8.24526889492372867057141', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s,  gsl_sf_ellint_P_e, (7*M_PI/3.0, 0.01, -0.1, mode, &r), 7.70273208013189564674630, TEST_TOL0, GSL_SUCCESS)'
            self._test(('7*M_PI/3.0', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('7.70273208013189564674630', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s,  gsl_sf_ellint_P_e, (-M_PI/2.0, 0.99, -0.1, mode, &r), -3.61678162163246646783050, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('-3.61678162163246646783050', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s,  gsl_sf_ellint_P_e, (-M_PI/2.0, 0.50, -0.1, mode, &r), -1.78030349465454812629168, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('-1.78030349465454812629168', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s,  gsl_sf_ellint_P_e, (-M_PI/2.0, 0.01, -0.1, mode, &r), -1.65580719756898353270922, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI/2.0', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('-1.65580719756898353270922', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args30_1(self):
            '(s,  gsl_sf_ellint_P_e, (-2*M_PI/3.0, 0.99, -0.1, mode, &r), -5.88008918207571119911983, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('-5.88008918207571119911983', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args31_1(self):
            '(s,  gsl_sf_ellint_P_e, (-2*M_PI/3.0, 0.50, -0.1, mode, &r), -2.43655207300356008717867, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('-2.43655207300356008717867', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args32_1(self):
            '(s,  gsl_sf_ellint_P_e, (-2*M_PI/3.0, 0.01, -0.1, mode, &r), -2.23211110528200554950903, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI/3.0', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('-2.23211110528200554950903', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args33_1(self):
            '(s,  gsl_sf_ellint_P_e, (-M_PI, 0.99, -0.1, mode, &r), -7.23356324326493293566099, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('-7.23356324326493293566099', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args34_1(self):
            '(s,  gsl_sf_ellint_P_e, (-M_PI, 0.50, -0.1, mode, &r), -3.56060698930909625258336, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('-3.56060698930909625258336', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args35_1(self):
            '(s,  gsl_sf_ellint_P_e, (-M_PI, 0.01, -0.1, mode, &r), -3.31161439513796706541844, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-M_PI', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('-3.31161439513796706541844', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args36_1(self):
            '(s,  gsl_sf_ellint_P_e, (-4*M_PI/3, 0.99, -0.1, mode, &r), -8.58703730445415467220216, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('-8.58703730445415467220216', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args37_1(self):
            '(s,  gsl_sf_ellint_P_e, (-4*M_PI/3, 0.50, -0.1, mode, &r), -4.68466190561463241798805, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('-4.68466190561463241798805', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args38_1(self):
            '(s,  gsl_sf_ellint_P_e, (-4*M_PI/3, 0.01, -0.1, mode, &r), -4.39111768499392858132786, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-4*M_PI/3', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('-4.39111768499392858132786', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args39_1(self):
            '(s,  gsl_sf_ellint_P_e, (-3*M_PI/2.0, 0.99, -0.1, mode, &r), -10.8503448648973994034915, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('-10.8503448648973994034915', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args40_1(self):
            '(s,  gsl_sf_ellint_P_e, (-3*M_PI/2.0, 0.50, -0.1, mode, &r), -5.34091048396364437887504, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('-5.34091048396364437887504', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args41_1(self):
            '(s,  gsl_sf_ellint_P_e, (-3*M_PI/2.0, 0.01, -0.1, mode, &r), -4.96742159270695059812767, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-3*M_PI/2.0', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('-4.96742159270695059812767', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args42_1(self):
            '(s,  gsl_sf_ellint_P_e, (-5*M_PI/3, 0.99, -0.1, mode, &r), -13.1136524253406441347808, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('-13.1136524253406441347808', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args43_1(self):
            '(s,  gsl_sf_ellint_P_e, (-5*M_PI/3, 0.50, -0.1, mode, &r), -5.99715906231265633976204, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('-5.99715906231265633976204', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args44_1(self):
            '(s,  gsl_sf_ellint_P_e, (-5*M_PI/3, 0.01, -0.1, mode, &r), -5.54372550041997261492747, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-5*M_PI/3', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('-5.54372550041997261492747', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args45_1(self):
            '(s,  gsl_sf_ellint_P_e, (-2*M_PI, 0.99, -0.1, mode, &r), -14.4671264865298658713220, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('-14.4671264865298658713220', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args46_1(self):
            '(s,  gsl_sf_ellint_P_e, (-2*M_PI, 0.50, -0.1, mode, &r), -7.12121397861819250516672, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('-7.12121397861819250516672', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args47_1(self):
            '(s,  gsl_sf_ellint_P_e, (-2*M_PI, 0.01, -0.1, mode, &r), -6.62322879027593413083689, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-2*M_PI', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('-6.62322879027593413083689', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args48_1(self):
            '(s,  gsl_sf_ellint_P_e, (-7*M_PI/3.0, 0.99, -0.1, mode, &r), -15.8206005477190876078631, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.99, -0.1, 'GSL_MODE_DEFAULT'), ('-15.8206005477190876078631', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args49_1(self):
            '(s,  gsl_sf_ellint_P_e, (-7*M_PI/3.0, 0.50, -0.1, mode, &r), -8.24526889492372867057141, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.5, -0.1, 'GSL_MODE_DEFAULT'), ('-8.24526889492372867057141', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args50_1(self):
            '(s,  gsl_sf_ellint_P_e, (-7*M_PI/3.0, 0.01, -0.1, mode, &r), -7.70273208013189564674630, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-7*M_PI/3.0', 0.01, -0.1, 'GSL_MODE_DEFAULT'), ('-7.70273208013189564674630', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.ellint_Pcomp_e
except AttributeError:
    print("Not including tests for ellint_Pcomp_e")

if _t_func != None:
    class test_sf_automatic_ellint_Pcomp_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_Pcomp_e, (0.99, 0.1, mode, &r), 3.13792612351836506315593, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.99, 0.1, 'GSL_MODE_DEFAULT'), ('3.13792612351836506315593', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_ellint_Pcomp_e, (0.50, 0.1, mode, &r), 1.60455249360848890075108, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5, 0.1, 'GSL_MODE_DEFAULT'), ('1.60455249360848890075108', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_ellint_Pcomp_e, (0.01, 0.1, mode, &r), 1.49773208536003801277453, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.01, 0.1, 'GSL_MODE_DEFAULT'), ('1.49773208536003801277453', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.ellint_RC_e
except AttributeError:
    print("Not including tests for ellint_RC_e")

if _t_func != None:
    class test_sf_automatic_ellint_RC_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_RC_e, (1.0, 2.0, mode, &r), 0.7853981633974482, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 2.0, 'GSL_MODE_DEFAULT'), ('0.7853981633974482', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.ellint_RD_e
except AttributeError:
    print("Not including tests for ellint_RD_e")

if _t_func != None:
    class test_sf_automatic_ellint_RD_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_RD_e, (5.0e-11, 1.0e-10, 1.0, mode, &r), 34.0932594919337362, TEST_TOL0, GSL_SUCCESS)'
            self._test((5e-11, 1e-10, 1.0, 'GSL_MODE_DEFAULT'), ('34.0932594919337362', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_ellint_RD_e, (1.0, 2.0, 3.0, mode, &r), 0.2904602810289906, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 2.0, 3.0, 'GSL_MODE_DEFAULT'), ('0.2904602810289906', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.ellint_RF_e
except AttributeError:
    print("Not including tests for ellint_RF_e")

if _t_func != None:
    class test_sf_automatic_ellint_RF_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_RF_e, (5.0e-11, 1.0e-10, 1.0, mode, &r), 12.36441982979439, TEST_TOL0, GSL_SUCCESS)'
            self._test((5e-11, 1e-10, 1.0, 'GSL_MODE_DEFAULT'), ('12.36441982979439', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_ellint_RF_e, (1.0, 2.0, 3.0, mode, &r), 0.7269459354689082, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 2.0, 3.0, 'GSL_MODE_DEFAULT'), ('0.7269459354689082', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.ellint_RJ_e
except AttributeError:
    print("Not including tests for ellint_RJ_e")

if _t_func != None:
    class test_sf_automatic_ellint_RJ_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_ellint_RJ_e, (2.0, 3.0, 4.0, 5.0, mode, &r), 0.1429757966715675, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.0, 3.0, 4.0, 5.0, 'GSL_MODE_DEFAULT'), ('0.1429757966715675', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.erf_Q_e
except AttributeError:
    print("Not including tests for erf_Q_e")

if _t_func != None:
    class test_sf_automatic_erf_Q_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_erf_Q_e, (10.0, &r), 7.619853024160526066e-24, TEST_TOL2, GSL_SUCCESS)'
            self._test((10.0,), ('7.619853024160526066e-24', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.erf_Z_e
except AttributeError:
    print("Not including tests for erf_Z_e")

if _t_func != None:
    class test_sf_automatic_erf_Z_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_erf_Z_e, (1.0, &r),  0.24197072451914334980,   TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.24197072451914334980', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.erf_e
except AttributeError:
    print("Not including tests for erf_e")

if _t_func != None:
    class test_sf_automatic_erf_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_erf_e, (-10.0, &r), -1.0000000000000000000, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('-1.0000000000000000000', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_erf_e, (0.5, &r), 0.5204998778130465377, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5,), ('0.5204998778130465377', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_erf_e, (1.0, &r), 0.8427007929497148693, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.8427007929497148693', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_erf_e, (10.0, &r), 1.0000000000000000000, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('1.0000000000000000000', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.erfc_e
except AttributeError:
    print("Not including tests for erfc_e")

if _t_func != None:
    class test_sf_automatic_erfc_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_erfc_e, (-10.0, &r), 2.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('2.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_erfc_e, (-5.0000002, &r), 1.9999999999984625433, TEST_TOL0, GSL_SUCCESS)'
            self._test((-5.0000002,), ('1.9999999999984625433', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_erfc_e, (-5.0, &r), 1.9999999999984625402, TEST_TOL0, GSL_SUCCESS)'
            self._test((-5.0,), ('1.9999999999984625402', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_erfc_e, (-1.0, &r), 1.8427007929497148693, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('1.8427007929497148693', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_erfc_e, (-0.5, &r), 1.5204998778130465377, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.5,), ('1.5204998778130465377', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_erfc_e, (1.0, &r), 0.15729920705028513066, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.15729920705028513066', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_erfc_e, (3.0, &r), 0.000022090496998585441373, TEST_TOL1, GSL_SUCCESS)'
            self._test((3.0,), ('0.000022090496998585441373', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_erfc_e, (7.0, &r), 4.183825607779414399e-23, TEST_TOL2, GSL_SUCCESS)'
            self._test((7.0,), ('4.183825607779414399e-23', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_erfc_e, (10.0, &r), 2.0884875837625447570e-45, TEST_TOL2, GSL_SUCCESS)'
            self._test((10.0,), ('2.0884875837625447570e-45', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.eta_e
except AttributeError:
    print("Not including tests for eta_e")

if _t_func != None:
    class test_sf_automatic_eta_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_eta_e, (-51.5, &r), -1.2524184036924703656e+41, TEST_TOL2, GSL_SUCCESS)'
            self._test((-51.5,), ('-1.2524184036924703656e+41', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_eta_e, (-5, &r), 0.25, TEST_TOL0, GSL_SUCCESS)'
            self._test((-5,), ('0.25', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_eta_e, (0.5, &r), 0.6048986434216303702, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5,), ('0.6048986434216303702', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_eta_e, (0.999, &r), 0.6929872789683383574, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.999,), ('0.6929872789683383574', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_eta_e, (1.0, &r), 0.6931471805599453094, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.6931471805599453094', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_eta_e, (1.0+1.0e-10, &r), 0.6931471805759321998, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0+1.0e-10',), ('0.6931471805759321998', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_eta_e, ( 5, &r), 0.9721197704469093059, TEST_TOL0, GSL_SUCCESS)'
            self._test((5,), ('0.9721197704469093059', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_eta_e, ( 5.2, &r), 0.9755278712546684682, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.2,), ('0.9755278712546684682', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_eta_e, ( 6, &r), 0.9855510912974351041, TEST_TOL0, GSL_SUCCESS)'
            self._test((6,), ('0.9855510912974351041', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_eta_e, ( 20, &r), 0.9999990466115815221, TEST_TOL0, GSL_SUCCESS)'
            self._test((20,), ('0.9999990466115815221', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.eta_int_e
except AttributeError:
    print("Not including tests for eta_int_e")

if _t_func != None:
    class test_sf_automatic_eta_int_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_eta_int_e, (-91, &r), -4.945598888750002040e+94, TEST_TOL0, GSL_SUCCESS)'
            self._test((-91,), ('-4.945598888750002040e+94', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_eta_int_e, (-51, &r), -4.363969073121683116e+40, TEST_TOL0, GSL_SUCCESS)'
            self._test((-51,), ('-4.363969073121683116e+40', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_eta_int_e, (-5, &r), 0.25, TEST_TOL0, GSL_SUCCESS)'
            self._test((-5,), ('0.25', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_eta_int_e, (-1, &r), 0.25, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1,), ('0.25', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_eta_int_e, ( 0, &r), 0.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((0,), ('0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_eta_int_e, ( 5, &r), 0.9721197704469093059, TEST_TOL0, GSL_SUCCESS)'
            self._test((5,), ('0.9721197704469093059', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_eta_int_e, ( 6, &r), 0.9855510912974351041, TEST_TOL0, GSL_SUCCESS)'
            self._test((6,), ('0.9855510912974351041', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_eta_int_e, ( 20, &r), 0.9999990466115815221, TEST_TOL0, GSL_SUCCESS)'
            self._test((20,), ('0.9999990466115815221', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_eta_int_e, ( 1000, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((1000,), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.exp_e
except AttributeError:
    print("Not including tests for exp_e")

if _t_func != None:
    class test_sf_automatic_exp_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_exp_e, (-10.0, &r), exp(-10.0), TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('exp(-10.0)', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_exp_e, ( 10.0, &r), exp( 10.0), TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('exp( 10.0)', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.exp_err_e
except AttributeError:
    print("Not including tests for exp_err_e")

if _t_func != None:
    class test_sf_automatic_exp_err_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_exp_err_e, (-10.0, TEST_TOL1, &r), exp(-10.0), TEST_TOL1, GSL_SUCCESS)'
            self._test((-10.0, 'TEST_TOL1'), ('exp(-10.0)', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_exp_err_e, ( 10.0, TEST_TOL1, &r), exp( 10.0), TEST_TOL1, GSL_SUCCESS)'
            self._test((10.0, 'TEST_TOL1'), ('exp( 10.0)', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.expint_3_e
except AttributeError:
    print("Not including tests for expint_3_e")

if _t_func != None:
    class test_sf_automatic_expint_3_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_expint_3_e, (1.0e-10, &r), 1.0e-10, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('1.0e-10', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_expint_3_e, (1.0e-05, &r), 9.9999999999999975e-06, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-05,), ('9.9999999999999975e-06', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_expint_3_e, (0.1, &r), 0.09997500714119079665122, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.09997500714119079665122', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_expint_3_e, (0.5, &r), 0.48491714311363971332427, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5,), ('0.48491714311363971332427', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_expint_3_e, (1.0, &r), 0.80751118213967145285833, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.80751118213967145285833', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_expint_3_e, (2.0, &r), 0.89295351429387631138208, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.0,), ('0.89295351429387631138208', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_expint_3_e, (5.0, &r), 0.89297951156924921121856, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0,), ('0.89297951156924921121856', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_expint_3_e, (10.0, &r), 0.89297951156924921121856, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('0.89297951156924921121856', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_expint_3_e, (100.0, &r), 0.89297951156924921121856, TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0,), ('0.89297951156924921121856', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.expint_E1_e
except AttributeError:
    print("Not including tests for expint_E1_e")

if _t_func != None:
    class test_sf_automatic_expint_E1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_expint_E1_e, (-1.0, &r), -1.8951178163559367555, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('-1.8951178163559367555', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_expint_E1_e, (1.0e-10, &r), 22.448635265138923980, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('22.448635265138923980', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_expint_E1_e, (1.0e-05, &r), 10.935719800043695615, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-05,), ('10.935719800043695615', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_expint_E1_e, (0.1, &r), 1.82292395841939066610, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('1.82292395841939066610', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_expint_E1_e, (1.0, &r), 0.21938393439552027368, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.21938393439552027368', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_expint_E1_e, (10.0, &r), 4.156968929685324277e-06, TEST_TOL1, GSL_SUCCESS)'
            self._test((10.0,), ('4.156968929685324277e-06', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_expint_E1_e, (50.0, &r), 3.783264029550459019e-24, TEST_TOL2, GSL_SUCCESS)'
            self._test((50.0,), ('3.783264029550459019e-24', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_expint_E1_e, (300.0, &r), 1.710384276804510115e-133, TEST_TOL2, GSL_SUCCESS)'
            self._test((300.0,), ('1.710384276804510115e-133', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.expint_E1_scaled_e
except AttributeError:
    print("Not including tests for expint_E1_scaled_e")

if _t_func != None:
    class test_sf_automatic_expint_E1_scaled_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (-10000.0, &r), -0.00010001000200060024012, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10000.0,), ('-0.00010001000200060024012', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (-1000.0, &r), -0.0010010020060241207251, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1000.0,), ('-0.0010010020060241207251', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (-10.0, &r), -0.11314702047341077803, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('-0.11314702047341077803', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (-1.0, &r), -0.69717488323506606877, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('-0.69717488323506606877', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (1.0e-10, &r), 22.448635267383787506, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('22.448635267383787506', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (1.0e-05, &r), 10.935829157788483865, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-05,), ('10.935829157788483865', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (0.1, &r), 2.0146425447084516791, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('2.0146425447084516791', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (1.0, &r), 0.59634736232319407434, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.59634736232319407434', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (10.0, &r), 0.091563333939788081876, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('0.091563333939788081876', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (50.0, &r), 0.019615109930114870365, TEST_TOL0, GSL_SUCCESS)'
            self._test((50.0,), ('0.019615109930114870365', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (300.0, &r), 0.0033222955652707070644, TEST_TOL0, GSL_SUCCESS)'
            self._test((300.0,), ('0.0033222955652707070644', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (1000.0, &r), 0.00099900199402388071500, TEST_TOL0, GSL_SUCCESS)'
            self._test((1000.0,), ('0.00099900199402388071500', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_expint_E1_scaled_e, (10000.0, &r), 0.000099990001999400239880, TEST_TOL0, GSL_SUCCESS)'
            self._test((10000.0,), ('0.000099990001999400239880', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.expint_E2_e
except AttributeError:
    print("Not including tests for expint_E2_e")

if _t_func != None:
    class test_sf_automatic_expint_E2_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_expint_E2_e, (-1.0, &r), 0.8231640121031084799, TEST_TOL1, GSL_SUCCESS)'
            self._test((-1.0,), ('0.8231640121031084799', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_expint_E2_e, (0.0, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0,), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_expint_E2_e, (1.0/4294967296.0, &r), 0.9999999947372139168, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/4294967296.0',), ('0.9999999947372139168', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_expint_E2_e, (1.0/65536.0, &r), 0.9998243233207178845, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/65536.0',), ('0.9998243233207178845', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_expint_E2_e, (0.1, &r), 0.7225450221940205066, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.7225450221940205066', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_expint_E2_e, (1.0, &r), 0.14849550677592204792, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.14849550677592204792', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_expint_E2_e, (10.0, &r), 3.830240465631608762e-06, TEST_TOL1, GSL_SUCCESS)'
            self._test((10.0,), ('3.830240465631608762e-06', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_expint_E2_e, (50.0, &r), 3.711783318868827367e-24, TEST_TOL2, GSL_SUCCESS)'
            self._test((50.0,), ('3.711783318868827367e-24', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_expint_E2_e, (300.0, &r), 1.7047391998483433998e-133, TEST_TOL2, GSL_SUCCESS)'
            self._test((300.0,), ('1.7047391998483433998e-133', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.expint_E2_scaled_e
except AttributeError:
    print("Not including tests for expint_E2_scaled_e")

if _t_func != None:
    class test_sf_automatic_expint_E2_scaled_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (-10000.0, &r), -0.00010002000600240120072, TEST_TOL3, GSL_SUCCESS)'
            self._test((-10000.0,), ('-0.00010002000600240120072', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (-1000.0, &r), -0.0010020060241207250807, TEST_TOL3, GSL_SUCCESS)'
            self._test((-1000.0,), ('-0.0010020060241207250807', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (-10.0, &r), -0.13147020473410778034, TEST_TOL1, GSL_SUCCESS)'
            self._test((-10.0,), ('-0.13147020473410778034', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (-1.0, &r), 0.30282511676493393123, TEST_TOL1, GSL_SUCCESS)'
            self._test((-1.0,), ('0.30282511676493393123', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (0.0, &r), 1.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((0.0,), ('1.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (1.0/4294967296.0, &r), 0.99999999497004455927, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/4294967296.0',), ('0.99999999497004455927', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (1.0/65536.0, &r), 0.99983957954556245453, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/65536.0',), ('0.99983957954556245453', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (0.1, &r), 0.79853574552915483209, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.79853574552915483209', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (1.0, &r), 0.40365263767680592566, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.40365263767680592566', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (10.0, &r), 0.084366660602119181239, TEST_TOL1, GSL_SUCCESS)'
            self._test((10.0,), ('0.084366660602119181239', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (50.0, &r), 0.019244503494256481735, TEST_TOL2, GSL_SUCCESS)'
            self._test((50.0,), ('0.019244503494256481735', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (300.0, &r), 0.0033113304187878806691, TEST_TOL0, GSL_SUCCESS)'
            self._test((300.0,), ('0.0033113304187878806691', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (1000.0, &r), 0.00099800597611928500004, TEST_TOL0, GSL_SUCCESS)'
            self._test((1000.0,), ('0.00099800597611928500004', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_expint_E2_scaled_e, (10000.0, &r), 0.000099980005997601199281, TEST_TOL0, GSL_SUCCESS)'
            self._test((10000.0,), ('0.000099980005997601199281', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.expint_Ei_e
except AttributeError:
    print("Not including tests for expint_Ei_e")

if _t_func != None:
    class test_sf_automatic_expint_Ei_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_expint_Ei_e, (-1.0, &r), -0.21938393439552027368, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('-0.21938393439552027368', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_expint_Ei_e, (1.0/4294967296.0, &r), -21.603494112783886397, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/4294967296.0',), ('-21.603494112783886397', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_expint_Ei_e, (1.0, &r), 1.8951178163559367555, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('1.8951178163559367555', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.expint_Ei_scaled_e
except AttributeError:
    print("Not including tests for expint_Ei_scaled_e")

if _t_func != None:
    class test_sf_automatic_expint_Ei_scaled_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_expint_Ei_scaled_e, (-1000.0, &r), -0.00099900199402388071500, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1000.0,), ('-0.00099900199402388071500', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_expint_Ei_scaled_e, (-1.0, &r), -0.59634736232319407434, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('-0.59634736232319407434', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_expint_Ei_scaled_e, (1.0/4294967296.0, &r), -21.603494107753930958, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/4294967296.0',), ('-21.603494107753930958', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_expint_Ei_scaled_e, (1.0, &r), 0.69717488323506606877, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.69717488323506606877', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_expint_Ei_scaled_e, (1000.0, &r), 0.0010010020060241207251, TEST_TOL0, GSL_SUCCESS)'
            self._test((1000.0,), ('0.0010010020060241207251', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.expint_En_e
except AttributeError:
    print("Not including tests for expint_En_e")

if _t_func != None:
    class test_sf_automatic_expint_En_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_expint_En_e, (1,-1.0, &r), -1.8951178163559367555, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, -1.0), ('-1.8951178163559367555', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_expint_En_e, (1,1.0e-10, &r), 22.448635265138923980, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 1e-10), ('22.448635265138923980', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_expint_En_e, (1,1.0e-05, &r), 10.935719800043695615, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 1e-05), ('10.935719800043695615', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_expint_En_e, (1,0.1, &r), 1.82292395841939066610, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 0.1), ('1.82292395841939066610', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_expint_En_e, (1,1.0, &r), 0.21938393439552027368, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 1.0), ('0.21938393439552027368', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_expint_En_e, (1,10.0, &r), 4.156968929685324277e-06, TEST_TOL1, GSL_SUCCESS)'
            self._test((1, 10.0), ('4.156968929685324277e-06', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_expint_En_e, (1,50.0, &r), 3.783264029550459019e-24, TEST_TOL2, GSL_SUCCESS)'
            self._test((1, 50.0), ('3.783264029550459019e-24', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_expint_En_e, (1,300.0, &r), 1.710384276804510115e-133, TEST_TOL2, GSL_SUCCESS)'
            self._test((1, 300.0), ('1.710384276804510115e-133', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_expint_En_e, (2,-1.0, &r), 0.8231640121031084799, TEST_TOL1, GSL_SUCCESS)'
            self._test((2, -1.0), ('0.8231640121031084799', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_expint_En_e, (2,0.0, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 0.0), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_expint_En_e, (2,1.0/4294967296.0, &r), 0.9999999947372139168, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, '1.0/4294967296.0'), ('0.9999999947372139168', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_expint_En_e, (2,1.0/65536.0, &r), 0.9998243233207178845, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, '1.0/65536.0'), ('0.9998243233207178845', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_expint_En_e, (2,0.1, &r), 0.7225450221940205066, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 0.1), ('0.7225450221940205066', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_expint_En_e, (2,1.0, &r), 0.14849550677592204792, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 1.0), ('0.14849550677592204792', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_expint_En_e, (2,10.0, &r), 3.830240465631608762e-06, TEST_TOL1, GSL_SUCCESS)'
            self._test((2, 10.0), ('3.830240465631608762e-06', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_expint_En_e, (2,50.0, &r), 3.711783318868827367e-24, TEST_TOL2, GSL_SUCCESS)'
            self._test((2, 50.0), ('3.711783318868827367e-24', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s,  gsl_sf_expint_En_e, (2,300.0, &r), 1.7047391998483433998e-133, TEST_TOL2, GSL_SUCCESS)'
            self._test((2, 300.0), ('1.7047391998483433998e-133', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s,  gsl_sf_expint_En_e, (3,0.0, &r), 0.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 0.0), ('0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s,  gsl_sf_expint_En_e, (3,1.0/4294967296.0, &r), 0.499999999767169356972, TEST_TOL1, GSL_SUCCESS)'
            self._test((3, '1.0/4294967296.0'), ('0.499999999767169356972', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s,  gsl_sf_expint_En_e, (3,1.0/65536.0, &r), 0.4999847426094515610, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, '1.0/65536.0'), ('0.4999847426094515610', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s,  gsl_sf_expint_En_e, (3,0.1, &r), 0.4162914579082787612543, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 0.1), ('0.4162914579082787612543', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s,  gsl_sf_expint_En_e, (3,1.0, &r), 0.10969196719776013683858, TEST_TOL1, GSL_SUCCESS)'
            self._test((3, 1.0), ('0.10969196719776013683858', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s,  gsl_sf_expint_En_e, (3,10.0, &r),0.000003548762553084381959981, TEST_TOL1, GSL_SUCCESS)'
            self._test((3, 10.0), ('0.000003548762553084381959981', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s,  gsl_sf_expint_En_e, (3,50.0, &r), 3.6429094264752049812e-24, TEST_TOL2, GSL_SUCCESS)'
            self._test((3, 50.0), ('3.6429094264752049812e-24', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s,  gsl_sf_expint_En_e, (3,300.0, &r),1.699131143349179084e-133, TEST_TOL2, GSL_SUCCESS)'
            self._test((3, 300.0), ('1.699131143349179084e-133', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s,  gsl_sf_expint_En_e, (10,0.0, &r), 0.111111111111111111, TEST_TOL0, GSL_SUCCESS)'
            self._test((10, 0.0), ('0.111111111111111111', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s,  gsl_sf_expint_En_e, (10,1.0/4294967296.0, &r), 0.111111111082007280658, TEST_TOL2, GSL_SUCCESS)'
            self._test((10, '1.0/4294967296.0'), ('0.111111111082007280658', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s,  gsl_sf_expint_En_e, (10,1.0/65536.0, &r), 0.11110920377910896018606, TEST_TOL1, GSL_SUCCESS)'
            self._test((10, '1.0/65536.0'), ('0.11110920377910896018606', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s,  gsl_sf_expint_En_e, (10,0.1, &r), 0.099298432000896813567905, TEST_TOL1, GSL_SUCCESS)'
            self._test((10, 0.1), ('0.099298432000896813567905', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s,  gsl_sf_expint_En_e, (10,1.0, &r), 0.036393994031416401634164534, TEST_TOL1, GSL_SUCCESS)'
            self._test((10, 1.0), ('0.036393994031416401634164534', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args30_1(self):
            '(s,  gsl_sf_expint_En_e, (10,10.0, &r), 0.00000232530265702821081778968, TEST_TOL1, GSL_SUCCESS)'
            self._test((10, 10.0), ('0.00000232530265702821081778968', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args31_1(self):
            '(s,  gsl_sf_expint_En_e, (10,50.0, &r), 3.223296586749110919572e-24, TEST_TOL2, GSL_SUCCESS)'
            self._test((10, 50.0), ('3.223296586749110919572e-24', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args32_1(self):
            '(s,  gsl_sf_expint_En_e, (10,300.0, &r), 1.6608815083360041367294736e-133, TEST_TOL2, GSL_SUCCESS)'
            self._test((10, 300.0), ('1.6608815083360041367294736e-133', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.expint_En_scaled_e
except AttributeError:
    print("Not including tests for expint_En_scaled_e")

if _t_func != None:
    class test_sf_automatic_expint_En_scaled_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,-10000.0, &r), -0.00010001000200060024012, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, -10000.0), ('-0.00010001000200060024012', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,-1000.0, &r), -0.0010010020060241207251, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, -1000.0), ('-0.0010010020060241207251', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,-10.0, &r), -0.11314702047341077803, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, -10.0), ('-0.11314702047341077803', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,-1.0, &r), -0.69717488323506606877, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, -1.0), ('-0.69717488323506606877', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,1.0e-10, &r), 22.448635267383787506, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 1e-10), ('22.448635267383787506', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,1.0e-05, &r), 10.935829157788483865, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 1e-05), ('10.935829157788483865', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,0.1, &r), 2.0146425447084516791, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 0.1), ('2.0146425447084516791', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,1.0, &r), 0.59634736232319407434, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 1.0), ('0.59634736232319407434', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,10.0, &r), 0.091563333939788081876, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 10.0), ('0.091563333939788081876', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,50.0, &r), 0.019615109930114870365, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 50.0), ('0.019615109930114870365', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,300.0, &r), 0.0033222955652707070644, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 300.0), ('0.0033222955652707070644', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,1000.0, &r), 0.00099900199402388071500, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 1000.0), ('0.00099900199402388071500', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (1,10000.0, &r), 0.000099990001999400239880, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 10000.0), ('0.000099990001999400239880', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,-10000.0, &r), -0.00010002000600240120072, TEST_TOL3, GSL_SUCCESS)'
            self._test((2, -10000.0), ('-0.00010002000600240120072', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,-1000.0, &r), -0.0010020060241207250807, TEST_TOL3, GSL_SUCCESS)'
            self._test((2, -1000.0), ('-0.0010020060241207250807', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,-10.0, &r), -0.13147020473410778034, TEST_TOL1, GSL_SUCCESS)'
            self._test((2, -10.0), ('-0.13147020473410778034', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,-1.0, &r), 0.30282511676493393123, TEST_TOL1, GSL_SUCCESS)'
            self._test((2, -1.0), ('0.30282511676493393123', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,0.0, &r), 1.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((2, 0.0), ('1.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,1.0/4294967296.0, &r), 0.99999999497004455927, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, '1.0/4294967296.0'), ('0.99999999497004455927', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,1.0/65536.0, &r), 0.99983957954556245453, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, '1.0/65536.0'), ('0.99983957954556245453', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,0.1, &r), 0.79853574552915483209, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 0.1), ('0.79853574552915483209', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,1.0, &r), 0.40365263767680592566, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 1.0), ('0.40365263767680592566', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,10.0, &r), 0.084366660602119181239, TEST_TOL1, GSL_SUCCESS)'
            self._test((2, 10.0), ('0.084366660602119181239', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,50.0, &r), 0.019244503494256481735, TEST_TOL2, GSL_SUCCESS)'
            self._test((2, 50.0), ('0.019244503494256481735', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,300.0, &r), 0.0033113304187878806691, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 300.0), ('0.0033113304187878806691', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,1000.0, &r), 0.00099800597611928500004, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 1000.0), ('0.00099800597611928500004', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (2,10000.0, &r), 0.000099980005997601199281, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 10000.0), ('0.000099980005997601199281', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (3,0.0, &r), 0.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 0.0), ('0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (3,1.0/4294967296.0, &r), 0.4999999998835846787586, TEST_TOL1, GSL_SUCCESS)'
            self._test((3, '1.0/4294967296.0'), ('0.4999999998835846787586', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (3,1.0/65536.0, &r), 0.4999923718293796877864492, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, '1.0/65536.0'), ('0.4999923718293796877864492', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args30_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (3,0.1, &r), 0.4600732127235422583955, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 0.1), ('0.4600732127235422583955', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args31_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (3,1.0, &r), 0.298173681161597037170539, TEST_TOL1, GSL_SUCCESS)'
            self._test((3, 1.0), ('0.298173681161597037170539', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args32_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (3,10.0, &r), 0.07816669698940409380349, TEST_TOL1, GSL_SUCCESS)'
            self._test((3, 10.0), ('0.07816669698940409380349', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args33_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (3,50.0, &r), 0.0188874126435879566345, TEST_TOL2, GSL_SUCCESS)'
            self._test((3, 50.0), ('0.0188874126435879566345', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args34_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (3,300.0, &r), 0.00330043718181789963028657675, TEST_TOL2, GSL_SUCCESS)'
            self._test((3, 300.0), ('0.00330043718181789963028657675', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args35_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (10,0.0, &r), 0.111111111111111111, TEST_TOL0, GSL_SUCCESS)'
            self._test((10, 0.0), ('0.111111111111111111', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args36_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (10,1.0/4294967296.0, &r), 0.11111111110787735217158, TEST_TOL2, GSL_SUCCESS)'
            self._test((10, '1.0/4294967296.0'), ('0.11111111110787735217158', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args37_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (10,1.0/65536.0, &r), 0.1111108991839472074435, TEST_TOL1, GSL_SUCCESS)'
            self._test((10, '1.0/65536.0'), ('0.1111108991839472074435', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args38_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (10,0.1, &r), 0.1097417392579033988025, TEST_TOL1, GSL_SUCCESS)'
            self._test((10, 0.1), ('0.1097417392579033988025', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args39_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (10,1.0, &r), 0.09892913264064615521915, TEST_TOL1, GSL_SUCCESS)'
            self._test((10, 1.0), ('0.09892913264064615521915', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args40_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (10,10.0, &r), 0.0512181994376050593314159875, TEST_TOL1, GSL_SUCCESS)'
            self._test((10, 10.0), ('0.0512181994376050593314159875', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args41_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (10,50.0, &r), 0.0167118436335939556034579, TEST_TOL2, GSL_SUCCESS)'
            self._test((10, 50.0), ('0.0167118436335939556034579', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args42_1(self):
            '(s,  gsl_sf_expint_En_scaled_e, (10,300.0, &r), 0.0032261400811599644878615, TEST_TOL2, GSL_SUCCESS)'
            self._test((10, 300.0), ('0.0032261400811599644878615', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.expm1_e
except AttributeError:
    print("Not including tests for expm1_e")

if _t_func != None:
    class test_sf_automatic_expm1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_expm1_e, (-10.0, &r), exp(-10.0)-1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('exp(-10.0)-1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_expm1_e, (-0.001, &r), -0.00099950016662500845, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.001,), ('-0.00099950016662500845', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_expm1_e, (-1.0e-8, &r), -1.0e-08 + 0.5e-16, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1e-08,), ('-1.0e-08 + 0.5e-16', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_expm1_e, ( 1.0e-8, &r), 1.0e-08 + 0.5e-16, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-08,), ('1.0e-08 + 0.5e-16', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_expm1_e, ( 0.001, &r), 0.0010005001667083417, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.001,), ('0.0010005001667083417', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_expm1_e, ( 10.0, &r), exp(10.0)-1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('exp(10.0)-1.0', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.exprel_2_e
except AttributeError:
    print("Not including tests for exprel_2_e")

if _t_func != None:
    class test_sf_automatic_exprel_2_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_exprel_2_e, (-10.0, &r), 0.18000090799859524970, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('0.18000090799859524970', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_exprel_2_e, (-0.001, &r), 0.9996667499833361107, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.001,), ('0.9996667499833361107', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_exprel_2_e, (-1.0e-8, &r), 0.9999999966666666750, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1e-08,), ('0.9999999966666666750', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_exprel_2_e, ( 1.0e-8, &r), 1.0000000033333333417, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-08,), ('1.0000000033333333417', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_exprel_2_e, ( 0.001, &r), 1.0003334166833361115, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.001,), ('1.0003334166833361115', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_exprel_2_e, ( 10.0, &r), 440.3093158961343303, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('440.3093158961343303', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.exprel_e
except AttributeError:
    print("Not including tests for exprel_e")

if _t_func != None:
    class test_sf_automatic_exprel_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_exprel_e, (-10.0, &r), 0.0999954600070237515, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('0.0999954600070237515', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_exprel_e, (-0.001, &r), 0.9995001666250084, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.001,), ('0.9995001666250084', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_exprel_e, (-1.0e-8, &r), 1.0 - 0.5e-08, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1e-08,), ('1.0 - 0.5e-08', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_exprel_e, ( 1.0e-8, &r), 1.0 + 0.5e-08, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-08,), ('1.0 + 0.5e-08', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_exprel_e, ( 0.001, &r), 1.0005001667083417, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.001,), ('1.0005001667083417', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_exprel_e, ( 10.0, &r), 2202.5465794806716517, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('2202.5465794806716517', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.exprel_n_CF_e
except AttributeError:
    print("Not including tests for exprel_n_CF_e")

if _t_func != None:
    class test_sf_automatic_exprel_n_CF_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_exprel_n_CF_e, (6.315655e+05, 6.302583168053568806e+05, &r), 385.425369029433473098652465720, TEST_TOL4, GSL_SUCCESS)'
            self._test((631565.5, 630258.3168053569), ('385.425369029433473098652465720', 'TEST_TOL4'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.exprel_n_e
except AttributeError:
    print("Not including tests for exprel_n_e")

if _t_func != None:
    class test_sf_automatic_exprel_n_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_exprel_n_e, (3, -1000.0, &r), 0.00299400600000000000, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, -1000.0), ('0.00299400600000000000', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_exprel_n_e, (3, -100.0, &r), 0.02940600000000000000, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, -100.0), ('0.02940600000000000000', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_exprel_n_e, (3, -10.0, &r), 0.24599972760042142509, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, -10.0), ('0.24599972760042142509', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_exprel_n_e, (3, -3.0, &r), 0.5444917625849191238, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, -3.0), ('0.5444917625849191238', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_exprel_n_e, (3, -0.001, &r), 0.9997500499916678570, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, -0.001), ('0.9997500499916678570', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_exprel_n_e, (3, -1.0e-8, &r), 0.9999999975000000050, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, -1e-08), ('0.9999999975000000050', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_exprel_n_e, (3,  1.0e-8, &r), 1.0000000025000000050, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 1e-08), ('1.0000000025000000050', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_exprel_n_e, (3,  0.001, &r), 1.0002500500083345240, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 0.001), ('1.0002500500083345240', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_exprel_n_e, (3,  3.0, &r), 2.5745637607083706091, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 3.0), ('2.5745637607083706091', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_exprel_n_e, (3,  3.1, &r), 2.6772417068460206247, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 3.1), ('2.6772417068460206247', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_exprel_n_e, (3,  10.0, &r), 131.79279476884029910, TEST_TOL1, GSL_SUCCESS)'
            self._test((3, 10.0), ('131.79279476884029910', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_exprel_n_e, (3,  100.0, &r), 1.6128702850896812690e+38, TEST_TOL2, GSL_SUCCESS)'
            self._test((3, 100.0), ('1.6128702850896812690e+38', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_exprel_n_e, (50, -1000.0, &r), 0.04766231609253975959, TEST_TOL0, GSL_SUCCESS)'
            self._test((50, -1000.0), ('0.04766231609253975959', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_exprel_n_e, (50, -100.0, &r), 0.3348247572345889317, TEST_TOL0, GSL_SUCCESS)'
            self._test((50, -100.0), ('0.3348247572345889317', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_exprel_n_e, (50, -10.0, &r), 0.8356287051853286482, TEST_TOL0, GSL_SUCCESS)'
            self._test((50, -10.0), ('0.8356287051853286482', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_exprel_n_e, (50, -3.0, &r), 0.9443881609152163615, TEST_TOL0, GSL_SUCCESS)'
            self._test((50, -3.0), ('0.9443881609152163615', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s,  gsl_sf_exprel_n_e, (50, -1.0, &r), 0.980762245565660617, TEST_TOL0, GSL_SUCCESS)'
            self._test((50, -1.0), ('0.980762245565660617', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s,  gsl_sf_exprel_n_e, (50, -1.0e-8, &r), 1.0 -1.0e-8/51.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((50, -1e-08), ('1.0 -1.0e-8/51.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s,  gsl_sf_exprel_n_e, (50,  1.0e-8, &r), 1.0 +1.0e-8/51.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((50, 1e-08), ('1.0 +1.0e-8/51.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s,  gsl_sf_exprel_n_e, (50,  1.0, &r), 1.01999216583666790, TEST_TOL0, GSL_SUCCESS)'
            self._test((50, 1.0), ('1.01999216583666790', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s,  gsl_sf_exprel_n_e, (50,  3.0, &r), 1.0624205757460368307, TEST_TOL0, GSL_SUCCESS)'
            self._test((50, 3.0), ('1.0624205757460368307', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s,  gsl_sf_exprel_n_e, (50,  48.0, &r), 7.499573876877194416, TEST_TOL0, GSL_SUCCESS)'
            self._test((50, 48.0), ('7.499573876877194416', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s,  gsl_sf_exprel_n_e, (50,  50.1, &r), 9.311803306230992272, TEST_TOL4, GSL_SUCCESS)'
            self._test((50, 50.1), ('9.311803306230992272', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s,  gsl_sf_exprel_n_e, (50,  100.0, &r), 8.175664432485807634e+07, TEST_TOL4, GSL_SUCCESS)'
            self._test((50, 100.0), ('8.175664432485807634e+07', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s,  gsl_sf_exprel_n_e, (50,  500.0, &r), 4.806352370663185330e+146, TEST_TOL3, GSL_SUCCESS)'
            self._test((50, 500.0), ('4.806352370663185330e+146', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s,  gsl_sf_exprel_n_e, (500, -1000.0, &r), 0.3334815803127619256, TEST_TOL0, GSL_SUCCESS)'
            self._test((500, -1000.0), ('0.3334815803127619256', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s,  gsl_sf_exprel_n_e, (500, -100.0, &r), 0.8335646217536183909, TEST_TOL0, GSL_SUCCESS)'
            self._test((500, -100.0), ('0.8335646217536183909', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s,  gsl_sf_exprel_n_e, (500, -10.0, &r), 0.9804297803131823066, TEST_TOL0, GSL_SUCCESS)'
            self._test((500, -10.0), ('0.9804297803131823066', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s,  gsl_sf_exprel_n_e, (500, -3.0, &r), 0.9940475488850672997, TEST_TOL0, GSL_SUCCESS)'
            self._test((500, -3.0), ('0.9940475488850672997', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s,  gsl_sf_exprel_n_e, (500, -1.0, &r), 0.9980079602383488808, TEST_TOL0, GSL_SUCCESS)'
            self._test((500, -1.0), ('0.9980079602383488808', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args30_1(self):
            '(s,  gsl_sf_exprel_n_e, (500, -1.0e-8, &r), 1.0 -1.0e-8/501.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((500, -1e-08), ('1.0 -1.0e-8/501.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args31_1(self):
            '(s,  gsl_sf_exprel_n_e, (500,  1.0e-8, &r), 1.0 +1.0e-8/501.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((500, 1e-08), ('1.0 +1.0e-8/501.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args32_1(self):
            '(s,  gsl_sf_exprel_n_e, (500,  1.0, &r), 1.0019999920160634252, TEST_TOL0, GSL_SUCCESS)'
            self._test((500, 1.0), ('1.0019999920160634252', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args33_1(self):
            '(s,  gsl_sf_exprel_n_e, (500,  3.0, &r), 1.0060240236632444934, TEST_TOL0, GSL_SUCCESS)'
            self._test((500, 3.0), ('1.0060240236632444934', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args34_1(self):
            '(s,  gsl_sf_exprel_n_e, (500,  48.0, &r), 1.1059355517981272174, TEST_TOL0, GSL_SUCCESS)'
            self._test((500, 48.0), ('1.1059355517981272174', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args35_1(self):
            '(s,  gsl_sf_exprel_n_e, (500,  100.0, &r), 1.2492221464878287204, TEST_TOL1, GSL_SUCCESS)'
            self._test((500, 100.0), ('1.2492221464878287204', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args36_1(self):
            '(s,  gsl_sf_exprel_n_e, (500,  500.0, &r), 28.363019877927630858, TEST_TOL2, GSL_SUCCESS)'
            self._test((500, 500.0), ('28.363019877927630858', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args37_1(self):
            '(s,  gsl_sf_exprel_n_e, (500,  1000.0, &r), 2.4037563160335300322e+68, TEST_TOL4, GSL_SUCCESS)'
            self._test((500, 1000.0), ('2.4037563160335300322e+68', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args38_1(self):
            '(s,  gsl_sf_exprel_n_e, (500,  1600.0, &r), 7.899293535320607403e+226, TEST_TOL4, GSL_SUCCESS)'
            self._test((500, 1600.0), ('7.899293535320607403e+226', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args39_1(self):
            '(s,  gsl_sf_exprel_n_e, (1263131.0, 1261282.3637, &r), 545.0113107238425900305428360, TEST_TOL4, GSL_SUCCESS)'
            self._test((1263131, 1261282.3637), ('545.0113107238425900305428360', 'TEST_TOL4'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.fermi_dirac_0_e
except AttributeError:
    print("Not including tests for fermi_dirac_0_e")

if _t_func != None:
    class test_sf_automatic_fermi_dirac_0_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_fermi_dirac_0_e, (-10.0, &r), 0.00004539889921686464677, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('0.00004539889921686464677', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_fermi_dirac_0_e, ( -1.0, &r), 0.31326168751822283405, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.31326168751822283405', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_fermi_dirac_0_e, (  1.0, &r), 1.3132616875182228340, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('1.3132616875182228340', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_fermi_dirac_0_e, ( 10.0, &r), 10.000045398899216865, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('10.000045398899216865', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.fermi_dirac_1_e
except AttributeError:
    print("Not including tests for fermi_dirac_1_e")

if _t_func != None:
    class test_sf_automatic_fermi_dirac_1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, (-10.0, &r), 0.00004539941448447633524, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('0.00004539941448447633524', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, ( -2.0, &r), 0.13101248471442377127, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2.0,), ('0.13101248471442377127', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, ( -1.0, &r), 0.3386479964034521798, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.3386479964034521798', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, ( -0.4, &r), 0.5825520806897909028, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.4,), ('0.5825520806897909028', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, (  0.4, &r), 1.1423819861584355337, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.4,), ('1.1423819861584355337', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, (  1.0, &r), 1.8062860704447742567, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('1.8062860704447742567', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, (  1.5, &r), 2.5581520872227806402, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.5,), ('2.5581520872227806402', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, (  2.5, &r), 4.689474797599761667, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.5,), ('4.689474797599761667', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, ( 10.0, &r), 51.64488866743374196, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('51.64488866743374196', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, ( 12.0, &r), 73.64492792264531092, TEST_TOL0, GSL_SUCCESS)'
            self._test((12.0,), ('73.64492792264531092', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, ( 20.0, &r), 201.64493406478707282, TEST_TOL0, GSL_SUCCESS)'
            self._test((20.0,), ('201.64493406478707282', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_fermi_dirac_1_e, ( 50.0, &r), 1251.6449340668482264, TEST_TOL0, GSL_SUCCESS)'
            self._test((50.0,), ('1251.6449340668482264', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.fermi_dirac_2_e
except AttributeError:
    print("Not including tests for fermi_dirac_2_e")

if _t_func != None:
    class test_sf_automatic_fermi_dirac_2_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, (-10.0, &r), 0.00004539967212174776662, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('0.00004539967212174776662', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, ( -2.0, &r), 0.13313272938565030508, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2.0,), ('0.13313272938565030508', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, ( -1.0, &r), 0.3525648792978077590, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.3525648792978077590', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, ( -0.4, &r), 0.6229402647001272120, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.4,), ('0.6229402647001272120', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, (  0.4, &r), 1.2915805581060844533, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.4,), ('1.2915805581060844533', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, (  1.0, &r), 2.1641656128127008622, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('2.1641656128127008622', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, (  1.5, &r), 3.247184513920792475, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.5,), ('3.247184513920792475', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, (  2.5, &r), 6.797764392735056317, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.5,), ('6.797764392735056317', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, ( 10.0, &r), 183.11605273482105278, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('183.11605273482105278', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, ( 12.0, &r), 307.73921494638635166, TEST_TOL0, GSL_SUCCESS)'
            self._test((12.0,), ('307.73921494638635166', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, ( 20.0, &r), 1366.2320146723590157, TEST_TOL0, GSL_SUCCESS)'
            self._test((20.0,), ('1366.2320146723590157', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, ( 50.0, &r), 20915.580036675744655, TEST_TOL0, GSL_SUCCESS)'
            self._test((50.0,), ('20915.580036675744655', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_fermi_dirac_2_e, (200.0, &r), 1.3336623201467029786e+06, TEST_TOL0, GSL_SUCCESS)'
            self._test((200.0,), ('1.3336623201467029786e+06', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.fermi_dirac_3half_e
except AttributeError:
    print("Not including tests for fermi_dirac_3half_e")

if _t_func != None:
    class test_sf_automatic_fermi_dirac_3half_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, (-10.0, &r), 0.00004539956540456176333, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('0.00004539956540456176333', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, ( -2.0, &r), 0.13224678225177236685, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2.0,), ('0.13224678225177236685', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, ( -1.0, &r), 0.3466747947990574170, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.3466747947990574170', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, ( -0.4, &r), 0.6056120213305040910, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.4,), ('0.6056120213305040910', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, (  0.4, &r), 1.2258236403963668282, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.4,), ('1.2258236403963668282', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, (  1.0, &r), 2.0022581487784644573, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('2.0022581487784644573', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, (  1.5, &r), 2.9277494127932173068, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.5,), ('2.9277494127932173068', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, (  2.5, &r), 5.768879312210516582, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.5,), ('5.768879312210516582', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, ( 10.0, &r), 101.00510084332600020, TEST_TOL2, GSL_SUCCESS)'
            self._test((10.0,), ('101.00510084332600020', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, ( 12.0, &r), 156.51518642795728036, TEST_TOL1, GSL_SUCCESS)'
            self._test((12.0,), ('156.51518642795728036', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, ( 20.0, &r), 546.5630100657601959, TEST_TOL1, GSL_SUCCESS)'
            self._test((20.0,), ('546.5630100657601959', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_fermi_dirac_3half_e, ( 50.0, &r), 5332.353566687145552, TEST_TOL1, GSL_SUCCESS)'
            self._test((50.0,), ('5332.353566687145552', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.fermi_dirac_half_e
except AttributeError:
    print("Not including tests for fermi_dirac_half_e")

if _t_func != None:
    class test_sf_automatic_fermi_dirac_half_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, (-10.0, &r), 0.00004539920105264132755, TEST_TOL1, GSL_SUCCESS)'
            self._test((-10.0,), ('0.00004539920105264132755', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, ( -2.0, &r), 0.12929851332007559106, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2.0,), ('0.12929851332007559106', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, ( -1.0, &r), 0.3277951592607115477, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.3277951592607115477', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, ( -0.4, &r), 0.5522452153690688947, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.4,), ('0.5522452153690688947', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, (  0.4, &r), 1.0386797503389389277, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.4,), ('1.0386797503389389277', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, (  1.0, &r), 1.5756407761513002308, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('1.5756407761513002308', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, (  1.5, &r), 2.1448608775831140360, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.5,), ('2.1448608775831140360', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, (  2.5, &r), 3.606975377950373251, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.5,), ('3.606975377950373251', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, ( 10.0, &r), 24.084656964637653615, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('24.084656964637653615', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, ( 12.0, &r), 31.540203287044242593, TEST_TOL0, GSL_SUCCESS)'
            self._test((12.0,), ('31.540203287044242593', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, ( 20.0, &r), 67.49151222165892049, TEST_TOL0, GSL_SUCCESS)'
            self._test((20.0,), ('67.49151222165892049', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_fermi_dirac_half_e, ( 50.0, &r), 266.09281252136259343, TEST_TOL1, GSL_SUCCESS)'
            self._test((50.0,), ('266.09281252136259343', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.fermi_dirac_int_e
except AttributeError:
    print("Not including tests for fermi_dirac_int_e")

if _t_func != None:
    class test_sf_automatic_fermi_dirac_int_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (3,  -2.0, &r), 0.1342199155038680215, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, -2.0), ('0.1342199155038680215', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (3,   0.0, &r), 0.9470328294972459176, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 0.0), ('0.9470328294972459176', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (3,   0.1, &r), 1.0414170610956165759, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 0.1), ('1.0414170610956165759', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (3,   1.0, &r), 2.3982260822489407070, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 1.0), ('2.3982260822489407070', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (3,   3.0, &r), 12.621635313399690724, TEST_TOL1, GSL_SUCCESS)'
            self._test((3, 3.0), ('12.621635313399690724', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (3, 100.0, &r), 4.174893231066566793e+06, TEST_TOL1, GSL_SUCCESS)'
            self._test((3, 100.0), ('4.174893231066566793e+06', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (3, 500.0, &r), 2.604372285319088354e+09, TEST_TOL1, GSL_SUCCESS)'
            self._test((3, 500.0), ('2.604372285319088354e+09', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (5,  -2.0, &r), 0.13505242246823676478, TEST_TOL0, GSL_SUCCESS)'
            self._test((5, -2.0), ('0.13505242246823676478', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (5,   0.0, &r), 0.9855510912974351041, TEST_TOL0, GSL_SUCCESS)'
            self._test((5, 0.0), ('0.9855510912974351041', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (5,   0.1, &r), 1.0876519750101492782, TEST_TOL0, GSL_SUCCESS)'
            self._test((5, 0.1), ('1.0876519750101492782', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (5,   1.0, &r), 2.6222337848692390539, TEST_TOL0, GSL_SUCCESS)'
            self._test((5, 1.0), ('2.6222337848692390539', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (5,   3.0, &r), 17.008801618012113022, TEST_TOL1, GSL_SUCCESS)'
            self._test((5, 3.0), ('17.008801618012113022', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (5, 100.0, &r), 1.3957522531334869874e+09, TEST_TOL1, GSL_SUCCESS)'
            self._test((5, 100.0), ('1.3957522531334869874e+09', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (5, 500.0, &r), 2.1705672808114817955e+13, TEST_TOL2, GSL_SUCCESS)'
            self._test((5, 500.0), ('2.1705672808114817955e+13', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (7,  -2.0, &r), 0.1352641105671255851, TEST_TOL0, GSL_SUCCESS)'
            self._test((7, -2.0), ('0.1352641105671255851', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (7,   0.0, &r), 0.9962330018526478992, TEST_TOL0, GSL_SUCCESS)'
            self._test((7, 0.0), ('0.9962330018526478992', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (7,   0.1, &r), 1.1005861815180315485, TEST_TOL0, GSL_SUCCESS)'
            self._test((7, 0.1), ('1.1005861815180315485', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (7,   1.0, &r), 2.6918878172003129203, TEST_TOL0, GSL_SUCCESS)'
            self._test((7, 1.0), ('2.6918878172003129203', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (7,   3.0, &r), 19.033338976999367642, TEST_TOL2, GSL_SUCCESS)'
            self._test((7, 3.0), ('19.033338976999367642', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (7,  10.0, &r), 5654.530932873610014, TEST_TOL1, GSL_SUCCESS)'
            self._test((7, 10.0), ('5654.530932873610014', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (7,  50.0, &r), 1.005005069985066278e+09, TEST_TOL2, GSL_SUCCESS)'
            self._test((7, 50.0), ('1.005005069985066278e+09', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (7, 500.0, &r), 9.691690268341569514e+16, TEST_TOL3, GSL_SUCCESS)'
            self._test((7, 500.0), ('9.691690268341569514e+16', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (9,  -2.0, &r), 0.1353174385330242691, TEST_TOL0, GSL_SUCCESS)'
            self._test((9, -2.0), ('0.1353174385330242691', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (9,   0.0, &r), 0.9990395075982715656, TEST_TOL0, GSL_SUCCESS)'
            self._test((9, 0.0), ('0.9990395075982715656', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (9,   0.1, &r), 1.1039997234712941212, TEST_TOL0, GSL_SUCCESS)'
            self._test((9, 0.1), ('1.1039997234712941212', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (9,   1.0, &r), 2.7113648898129249947, TEST_TOL0, GSL_SUCCESS)'
            self._test((9, 1.0), ('2.7113648898129249947', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (9,   3.0, &r), 19.768544008138602223, TEST_TOL2, GSL_SUCCESS)'
            self._test((9, 3.0), ('19.768544008138602223', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (9,  10.0, &r), 10388.990167312912478, TEST_TOL2, GSL_SUCCESS)'
            self._test((9, 10.0), ('10388.990167312912478', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (9,  50.0, &r), 2.85466960802601649e+10, TEST_TOL1, GSL_SUCCESS)'
            self._test((9, 50.0), ('2.85466960802601649e+10', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (9, 500.0, &r), 2.69273849842695876e+20, 2*TEST_TOL1, GSL_SUCCESS)'
            self._test((9, 500.0), ('2.69273849842695876e+20', '2*TEST_TOL1'), GSL_SUCCESS)


        def test_args30_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (10,  -2.0, &r), 0.13532635396712288092, TEST_TOL0, GSL_SUCCESS)'
            self._test((10, -2.0), ('0.13532635396712288092', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args31_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (10,   0.0, &r), 0.9995171434980607541, TEST_TOL0, GSL_SUCCESS)'
            self._test((10, 0.0), ('0.9995171434980607541', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args32_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (10,   0.1, &r), 1.1045818238852612296, TEST_TOL0, GSL_SUCCESS)'
            self._test((10, 0.1), ('1.1045818238852612296', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args33_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (10,   1.0, &r), 2.7147765350346120647, TEST_TOL0, GSL_SUCCESS)'
            self._test((10, 1.0), ('2.7147765350346120647', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args34_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (10,   3.0, &r), 19.917151938411675171, TEST_TOL1, GSL_SUCCESS)'
            self._test((10, 3.0), ('19.917151938411675171', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args35_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (10,  10.0, &r), 12790.918595516495955, TEST_TOL2, GSL_SUCCESS)'
            self._test((10, 10.0), ('12790.918595516495955', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args36_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (10,  50.0, &r), 1.3147703201869657654e+11, TEST_TOL2, GSL_SUCCESS)'
            self._test((10, 50.0), ('1.3147703201869657654e+11', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args37_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (10, 500.0, &r), 1.2241331244469204398e+22, TEST_TOL2, GSL_SUCCESS)'
            self._test((10, 500.0), ('1.2241331244469204398e+22', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args38_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (11,  -2.0, &r), 0.1353308162894847149, TEST_TOL0, GSL_SUCCESS)'
            self._test((11, -2.0), ('0.1353308162894847149', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args39_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (11,   0.0, &r), 0.9997576851438581909, TEST_TOL0, GSL_SUCCESS)'
            self._test((11, 0.0), ('0.9997576851438581909', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args40_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (11,   0.1, &r), 1.1048751811565850418, TEST_TOL0, GSL_SUCCESS)'
            self._test((11, 0.1), ('1.1048751811565850418', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args41_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (11,   1.0, &r), 2.7165128749007313436, TEST_TOL0, GSL_SUCCESS)'
            self._test((11, 1.0), ('2.7165128749007313436', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args42_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (11,   3.0, &r), 19.997483022044603065, TEST_TOL2, GSL_SUCCESS)'
            self._test((11, 3.0), ('19.997483022044603065', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args43_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (11,  10.0, &r), 14987.996005901818036, TEST_TOL2, GSL_SUCCESS)'
            self._test((11, 10.0), ('14987.996005901818036', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args44_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (11,  50.0, &r), 5.558322924078990628e+11, TEST_TOL2, GSL_SUCCESS)'
            self._test((11, 50.0), ('5.558322924078990628e+11', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args45_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (11, 500.0, &r), 5.101293089606198280e+23, TEST_TOL2, GSL_SUCCESS)'
            self._test((11, 500.0), ('5.101293089606198280e+23', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args46_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (20,  -2.0, &r), 0.13533527450327238373, TEST_TOL0, GSL_SUCCESS)'
            self._test((20, -2.0), ('0.13533527450327238373', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args47_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (20,   0.0, &r), 0.9999995232582155428, TEST_TOL0, GSL_SUCCESS)'
            self._test((20, 0.0), ('0.9999995232582155428', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args48_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (20,   0.1, &r), 1.1051703357941368203, TEST_TOL0, GSL_SUCCESS)'
            self._test((20, 0.1), ('1.1051703357941368203', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args49_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (20,   1.0, &r), 2.7182783069905721654, TEST_TOL0, GSL_SUCCESS)'
            self._test((20, 1.0), ('2.7182783069905721654', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args50_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (20,   3.0, &r), 20.085345296028242734, TEST_TOL2, GSL_SUCCESS)'
            self._test((20, 3.0), ('20.085345296028242734', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args51_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (20,  10.0, &r), 21898.072920149606475, TEST_TOL2, GSL_SUCCESS)'
            self._test((20, 10.0), ('21898.072920149606475', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args52_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (20,  50.0, &r), 1.236873256595717618e+16, TEST_TOL2, GSL_SUCCESS)'
            self._test((20, 50.0), ('1.236873256595717618e+16', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args53_1(self):
            '(s, gsl_sf_fermi_dirac_int_e, (20, 500.0, &r), 9.358938204369557277e+36, TEST_TOL2, GSL_SUCCESS)'
            self._test((20, 500.0), ('9.358938204369557277e+36', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.fermi_dirac_m1_e
except AttributeError:
    print("Not including tests for fermi_dirac_m1_e")

if _t_func != None:
    class test_sf_automatic_fermi_dirac_m1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_fermi_dirac_m1_e, (-10.0, &r), 0.00004539786870243439450, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('0.00004539786870243439450', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_fermi_dirac_m1_e, ( -1.0, &r), 0.26894142136999512075, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.26894142136999512075', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_fermi_dirac_m1_e, (  1.0, &r), 0.7310585786300048793, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.7310585786300048793', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_fermi_dirac_m1_e, ( 10.0, &r), 0.9999546021312975656, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('0.9999546021312975656', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.fermi_dirac_mhalf_e
except AttributeError:
    print("Not including tests for fermi_dirac_mhalf_e")

if _t_func != None:
    class test_sf_automatic_fermi_dirac_mhalf_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, (-10.0, &r), 0.00004539847236080549532, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('0.00004539847236080549532', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, ( -2.0, &r), 0.12366562180120994266, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2.0,), ('0.12366562180120994266', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, ( -1.0, &r), 0.29402761761145122022, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.29402761761145122022', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, ( -0.4, &r), 0.4631755336886027800, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.4,), ('0.4631755336886027800', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, (  0.4, &r), 0.7654084737661656915, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.4,), ('0.7654084737661656915', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, (  1.0, &r), 1.0270571254743506890, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('1.0270571254743506890', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, (  1.5, &r), 1.2493233478527122008, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.5,), ('1.2493233478527122008', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, (  2.5, &r), 1.6663128834358313625, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.5,), ('1.6663128834358313625', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, ( 10.0, &r), 3.552779239536617160, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('3.552779239536617160', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, ( 12.0, &r), 3.897268231925439359, TEST_TOL0, GSL_SUCCESS)'
            self._test((12.0,), ('3.897268231925439359', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, ( 20.0, &r), 5.041018507535328603, TEST_TOL0, GSL_SUCCESS)'
            self._test((20.0,), ('5.041018507535328603', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_fermi_dirac_mhalf_e, ( 50.0, &r), 7.977530858581869960, TEST_TOL1, GSL_SUCCESS)'
            self._test((50.0,), ('7.977530858581869960', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.gegenpoly_1_e
except AttributeError:
    print("Not including tests for gegenpoly_1_e")

if _t_func != None:
    class test_sf_automatic_gegenpoly_1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_gegenpoly_1_e, (-0.2,   1.0, &r), -0.4, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.2, 1.0), ('-0.4', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_gegenpoly_1_e, ( 0.0,   1.0, &r), 2.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0, 1.0), ('2.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_gegenpoly_1_e, ( 1.0,   1.0, &r), 2.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 1.0), ('2.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_gegenpoly_1_e, ( 1.0,   0.5, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 0.5), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_gegenpoly_1_e, ( 5.0,   1.0, &r), 10.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0, 1.0), ('10.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_gegenpoly_1_e, ( 100.0, 0.5, &r), 100.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0, 0.5), ('100.0', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.gegenpoly_2_e
except AttributeError:
    print("Not including tests for gegenpoly_2_e")

if _t_func != None:
    class test_sf_automatic_gegenpoly_2_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_gegenpoly_2_e, (-0.2,   0.5, &r), 0.12, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.2, 0.5), ('0.12', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_gegenpoly_2_e, ( 0.0,   1.0, &r), 1.00, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0, 1.0), ('1.00', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_gegenpoly_2_e, ( 1.0,   1.0, &r), 3.00, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 1.0), ('3.00', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_gegenpoly_2_e, ( 1.0,   0.1, &r), -0.96, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 0.1), ('-0.96', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_gegenpoly_2_e, ( 5.0,   1.0, &r), 55.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0, 1.0), ('55.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_gegenpoly_2_e, ( 100.0, 0.5, &r), 4950.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0, 0.5), ('4950.0', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.gegenpoly_3_e
except AttributeError:
    print("Not including tests for gegenpoly_3_e")

if _t_func != None:
    class test_sf_automatic_gegenpoly_3_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_gegenpoly_3_e, (-0.2,   0.5, &r), 0.112, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.2, 0.5), ('0.112', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_gegenpoly_3_e, ( 0.0,   1.0, &r), -2.0/3.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0, 1.0), ('-2.0/3.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_gegenpoly_3_e, ( 1.0,   1.0, &r), 4.000, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 1.0), ('4.000', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_gegenpoly_3_e, ( 1.0,   0.1, &r), -0.392, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 0.1), ('-0.392', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_gegenpoly_3_e, ( 5.0,   1.0, &r), 220.000, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0, 1.0), ('220.000', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_gegenpoly_3_e, ( 100.0, 0.5, &r), 161600.000, TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0, 0.5), ('161600.000', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.gegenpoly_n_e
except AttributeError:
    print("Not including tests for gegenpoly_n_e")

if _t_func != None:
    class test_sf_automatic_gegenpoly_n_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_gegenpoly_n_e, (1,       1.0, 1.0, &r), 2.000              , TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 1.0, 1.0), ('2.000', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_gegenpoly_n_e, (10,      1.0, 1.0, &r), 11.000             , TEST_TOL0, GSL_SUCCESS)'
            self._test((10, 1.0, 1.0), ('11.000', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_gegenpoly_n_e, (10,      1.0, 0.1, &r), -0.4542309376      , TEST_TOL0, GSL_SUCCESS)'
            self._test((10, 1.0, 0.1), ('-0.4542309376', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_gegenpoly_n_e, (10,      5.0, 1.0, &r), 9.23780e+4         , TEST_TOL0, GSL_SUCCESS)'
            self._test((10, 5.0, 1.0), ('9.23780e+4', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_gegenpoly_n_e, (10,    100.0, 0.5, &r), 1.5729338392690000e+13, TEST_TOL0, GSL_SUCCESS)'
            self._test((10, 100.0, 0.5), ('1.5729338392690000e+13', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_gegenpoly_n_e, (1000,  100.0, 1.0, &r), 3.3353666135627322e+232, TEST_TOL1, GSL_SUCCESS)'
            self._test((1000, 100.0, 1.0), ('3.3353666135627322e+232', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_gegenpoly_n_e, (100,  2000.0, 1.0, &r), 5.8753432034937579e+202, TEST_TOL0, GSL_SUCCESS)'
            self._test((100, 2000.0, 1.0), ('5.8753432034937579e+202', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_gegenpoly_n_e, (103,   207.0, 2.0, &r), 1.4210272202235983e+145, TEST_TOL0, GSL_SUCCESS)'
            self._test((103, 207.0, 2.0), ('1.4210272202235983e+145', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_gegenpoly_n_e, (103,    -0.4, 0.3, &r), -1.64527498094522e-04, TEST_TOL1, GSL_SUCCESS)'
            self._test((103, -0.4, 0.3), ('-1.64527498094522e-04', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.hazard_e
except AttributeError:
    print("Not including tests for hazard_e")

if _t_func != None:
    class test_sf_automatic_hazard_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hazard_e, (-20.0, &r), 5.5209483621597631896e-88, TEST_TOL2, GSL_SUCCESS)'
            self._test((-20.0,), ('5.5209483621597631896e-88', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hazard_e, (-10.0, &r), 7.6945986267064193463e-23, TEST_TOL2, GSL_SUCCESS)'
            self._test((-10.0,), ('7.6945986267064193463e-23', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_hazard_e, (-1.0, &r), 0.28759997093917836123, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.28759997093917836123', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_hazard_e, ( 0.0, &r), 0.79788456080286535588, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0,), ('0.79788456080286535588', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_hazard_e, ( 1.0, &r), 1.5251352761609812091, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('1.5251352761609812091', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_hazard_e, (10.0, &r), 10.098093233962511963, TEST_TOL2, GSL_SUCCESS)'
            self._test((10.0,), ('10.098093233962511963', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_hazard_e, (20.0, &r), 20.049753068527850542, TEST_TOL2, GSL_SUCCESS)'
            self._test((20.0,), ('20.049753068527850542', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_hazard_e, (30.0, &r), 30.033259667433677037, TEST_TOL2, GSL_SUCCESS)'
            self._test((30.0,), ('30.033259667433677037', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_hazard_e, (50.0, &r), 50.019984031905639809, TEST_TOL0, GSL_SUCCESS)'
            self._test((50.0,), ('50.019984031905639809', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_hazard_e, (80.0, &r), 80.012496096798234468, TEST_TOL0, GSL_SUCCESS)'
            self._test((80.0,), ('80.012496096798234468', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_hazard_e, (150.0, &r), 150.00666607420571802, TEST_TOL0, GSL_SUCCESS)'
            self._test((150.0,), ('150.00666607420571802', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_hazard_e, (300.0, &r), 300.00333325926337415, TEST_TOL0, GSL_SUCCESS)'
            self._test((300.0,), ('300.00333325926337415', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_hazard_e, (900.0, &r), 900.00111110836764382, TEST_TOL0, GSL_SUCCESS)'
            self._test((900.0,), ('900.00111110836764382', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_hazard_e, (1001.0, &r), 1001.0009989990049990, TEST_TOL0, GSL_SUCCESS)'
            self._test((1001.0,), ('1001.0009989990049990', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_hazard_e, (2000.0, &r), 2000.0004999997500003, TEST_TOL0, GSL_SUCCESS)'
            self._test((2000.0,), ('2000.0004999997500003', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.hzeta_e
except AttributeError:
    print("Not including tests for hzeta_e")

if _t_func != None:
    class test_sf_automatic_hzeta_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hzeta_e, (2,  1.0, &r),  1.6449340668482264365, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 1.0), ('1.6449340668482264365', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hzeta_e, (2, 10.0, &r),  0.1051663356816857461, TEST_TOL0, GSL_SUCCESS)'
            self._test((2, 10.0), ('0.1051663356816857461', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_hzeta_e, (5,  1.0, &r),  1.0369277551433699263, TEST_TOL0, GSL_SUCCESS)'
            self._test((5, 1.0), ('1.0369277551433699263', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_hzeta_e, (5, 10.0, &r),  0.000030413798676470276, TEST_TOL0, GSL_SUCCESS)'
            self._test((5, 10.0), ('0.000030413798676470276', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_hzeta_e, (9,  0.1, &r),  1.0000000004253980e+09, TEST_TOL0, GSL_SUCCESS)'
            self._test((9, 0.1), ('1.0000000004253980e+09', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_hzeta_e, (30, 0.5, &r),  1.0737418240000053e+09, TEST_TOL0, GSL_SUCCESS)'
            self._test((30, 0.5), ('1.0737418240000053e+09', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_hzeta_e, (30, 0.9, &r),  2.3589824880264765e+01, TEST_TOL1, GSL_SUCCESS)'
            self._test((30, 0.9), ('2.3589824880264765e+01', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_hzeta_e, (75, 0.25, &r), 1.4272476927059599e+45, TEST_TOL1, GSL_SUCCESS)'
            self._test((75, 0.25), ('1.4272476927059599e+45', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.laguerre_1_e
except AttributeError:
    print("Not including tests for laguerre_1_e")

if _t_func != None:
    class test_sf_automatic_laguerre_1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_laguerre_1_e, (0.5, -1.0, &r), 2.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5, -1.0), ('2.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_laguerre_1_e, (0.5,  1.0, &r), 0.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5, 1.0), ('0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_laguerre_1_e, (1.0,  1.0, &r), 1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 1.0), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.laguerre_2_e
except AttributeError:
    print("Not including tests for laguerre_2_e")

if _t_func != None:
    class test_sf_automatic_laguerre_2_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_laguerre_2_e, ( 0.5, -1.0, &r), 4.875,  TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5, -1.0), ('4.875', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_laguerre_2_e, ( 0.5,  1.0, &r), -0.125, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5, 1.0), ('-0.125', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_laguerre_2_e, ( 1.0,  1.0, &r),  0.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0, 1.0), ('0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_laguerre_2_e, (-1.0,  1.0, &r), -0.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0, 1.0), ('-0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_laguerre_2_e, (-2.0,  1.0, &r),  0.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2.0, 1.0), ('0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_laguerre_2_e, (-3.0,  1.0, &r),  2.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((-3.0, 1.0), ('2.5', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.laguerre_3_e
except AttributeError:
    print("Not including tests for laguerre_3_e")

if _t_func != None:
    class test_sf_automatic_laguerre_3_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_laguerre_3_e, (0.5, -1.0, &r), 8.479166666666666667,    TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5, -1.0), ('8.479166666666666667', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_laguerre_3_e, (0.5,  1.0, &r), -0.6041666666666666667,  TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5, 1.0), ('-0.6041666666666666667', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_laguerre_3_e, (1.0,  1.0, &r), -0.16666666666666666667, TEST_TOL1, GSL_SUCCESS)'
            self._test((1.0, 1.0), ('-0.16666666666666666667', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_laguerre_3_e, ( 2.0,  1.0, &r), 2.3333333333333333333,  TEST_TOL0, GSL_SUCCESS)'
            self._test((2.0, 1.0), ('2.3333333333333333333', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_laguerre_3_e, (-2.0,  1.0, &r), 1.0/3.0,  TEST_TOL0, GSL_SUCCESS)'
            self._test((-2.0, 1.0), ('1.0/3.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_laguerre_3_e, (-3.0,  1.0, &r), -1.0/6.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-3.0, 1.0), ('-1.0/6.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_laguerre_3_e, (-4.0,  1.0, &r), -8.0/3.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-4.0, 1.0), ('-8.0/3.0', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.laguerre_n_e
except AttributeError:
    print("Not including tests for laguerre_n_e")

if _t_func != None:
    class test_sf_automatic_laguerre_n_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_laguerre_n_e, (1, 0.5, 1.0, &r), 0.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 0.5, 1.0), ('0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_laguerre_n_e, (2, 1.0, 1.0, &r), 0.5, TEST_TOL1, GSL_SUCCESS)'
            self._test((2, 1.0, 1.0), ('0.5', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_laguerre_n_e, (3, 2.0, 1.0, &r), 2.3333333333333333333,   TEST_TOL1, GSL_SUCCESS)'
            self._test((3, 2.0, 1.0), ('2.3333333333333333333', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_laguerre_n_e, (4, 2.0, 0.5, &r), 6.752604166666666667,    TEST_TOL1, GSL_SUCCESS)'
            self._test((4, 2.0, 0.5), ('6.752604166666666667', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_laguerre_n_e, (90, 2.0,  0.5, &r), -48.79047157201507897, TEST_TOL1, GSL_SUCCESS)'
            self._test((90, 2.0, 0.5), ('-48.79047157201507897', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_laguerre_n_e, (90, 2.0, -100.0, &r), 2.5295879275042410902e+63, TEST_TOL2, GSL_SUCCESS)'
            self._test((90, 2.0, -100.0), ('2.5295879275042410902e+63', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_laguerre_n_e, (90, 2.0,  100.0, &r), -2.0929042259546928670e+20, TEST_TOL1, GSL_SUCCESS)'
            self._test((90, 2.0, 100.0), ('-2.0929042259546928670e+20', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, 2.0, -0.5, &r), 2.2521795545919391405e+07,  TEST_TOL2, GSL_SUCCESS)'
            self._test((100, 2.0, -0.5), ('2.2521795545919391405e+07', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, 2.0,  0.5, &r), -28.764832945909097418,     TEST_TOL2, GSL_SUCCESS)'
            self._test((100, 2.0, 0.5), ('-28.764832945909097418', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_laguerre_n_e, (1000, 2.0, -0.5, &r), 2.4399915170947549589e+21, TEST_TOL3, GSL_SUCCESS)'
            self._test((1000, 2.0, -0.5), ('2.4399915170947549589e+21', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_laguerre_n_e, (1000, 2.0,  0.5, &r), -306.77440254315317525,    TEST_TOL2, GSL_SUCCESS)'
            self._test((1000, 2.0, 0.5), ('-306.77440254315317525', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_laguerre_n_e, (100000, 2.0, 1.0, &r), 5107.73491348319,         TEST_TOL4, GSL_SUCCESS)'
            self._test((100000, 2.0, 1.0), ('5107.73491348319', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_laguerre_n_e, (1e5, 2.5, 2.5, &r),   -0.41491680394598644969113795e5, TEST_TOL4, GSL_SUCCESS)'
            self._test((100000, 2.5, 2.5), ('-0.41491680394598644969113795e5', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_laguerre_n_e, (1e5+1, 2.5, 2.5, &r), -0.41629446949552321027514888e5, TEST_TOL4, GSL_SUCCESS)'
            self._test((100001, 2.5, 2.5), ('-0.41629446949552321027514888e5', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_laguerre_n_e, (1e6+1, 2.5, 2.5, &r), -0.48017961545391273151977118e6, TEST_TOL4, GSL_SUCCESS)'
            self._test((1000001, 2.5, 2.5), ('-0.48017961545391273151977118e6', 'TEST_TOL4'), GSL_SUCCESS)


        @pytest.mark.skip
        def test_args15_1(self):
            '(s, gsl_sf_laguerre_n_e, (5e6+1, 2.5, 2.5, &r), -0.15174037401611122446089494e7, TEST_TOL6, GSL_SUCCESS)'
            self._test((1000001, 2.5, 2.5), ('-0.15174037401611122446089494e7', 'TEST_TOL6'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s, gsl_sf_laguerre_n_e, (8e6+1, 2.5, 2.5, &r),  0.63251509472091810994286362e6, TEST_SNGL, GSL_SUCCESS)'
            self._test((8000001, 2.5, 2.5), ('0.63251509472091810994286362e6', 'TEST_SNGL'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s, gsl_sf_laguerre_n_e, (1e7+1, 2.5, 2.5, &r),  0.15299484685632983178033887e7, TEST_SNGL, GSL_SUCCESS)'
            self._test((10000001, 2.5, 2.5), ('0.15299484685632983178033887e7', 'TEST_SNGL'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s, gsl_sf_laguerre_n_e, (1e8+1, 2.5, 2.5, &r),  0.23645341644922756725290777e8, TEST_SNGL, GSL_SUCCESS)'
            self._test((100000001, 2.5, 2.5), ('0.23645341644922756725290777e8', 'TEST_SNGL'), GSL_SUCCESS)


        @pytest.mark.skip
        def test_args19_1(self):
            '(s, gsl_sf_laguerre_n_e, (1e9+1, 2.5, 2.5, &r), -0.17731002248958790286185878e8, 100*TEST_SNGL, GSL_SUCCESS)'
            self._test((100000001, 2.5, 2.5), ('-0.17731002248958790286185878e8', '100*TEST_SNGL'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s, gsl_sf_laguerre_n_e, (1, -2.0, 1.0, &r),  -2.0,     TEST_TOL0, GSL_SUCCESS)'
            self._test((1, -2.0, 1.0), ('-2.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args21_1(self):
            '(s, gsl_sf_laguerre_n_e, (2, -2.0, 1.0, &r),   0.5,     TEST_TOL0, GSL_SUCCESS)'
            self._test((2, -2.0, 1.0), ('0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args22_1(self):
            '(s, gsl_sf_laguerre_n_e, (3, -2.0, 1.0, &r),   1.0/3.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, -2.0, 1.0), ('1.0/3.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args23_1(self):
            '(s, gsl_sf_laguerre_n_e, (10, -2.0, 1.0, &r), -0.04654954805996472663,   TEST_TOL2, GSL_SUCCESS)'
            self._test((10, -2.0, 1.0), ('-0.04654954805996472663', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args24_1(self):
            '(s, gsl_sf_laguerre_n_e, (10, -5.0, 1.0, &r), -0.0031385030864197530864, TEST_TOL2, GSL_SUCCESS)'
            self._test((10, -5.0, 1.0), ('-0.0031385030864197530864', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args25_1(self):
            '(s, gsl_sf_laguerre_n_e, (10, -9.0, 1.0, &r), -2.480158730158730159e-06, TEST_TOL5, GSL_SUCCESS)'
            self._test((10, -9.0, 1.0), ('-2.480158730158730159e-06', 'TEST_TOL5'), GSL_SUCCESS)


        def test_args26_1(self):
            '(s, gsl_sf_laguerre_n_e, (10, -11.0,  1.0, &r), 2.7182818011463844797,    TEST_TOL2, GSL_SUCCESS)'
            self._test((10, -11.0, 1.0), ('2.7182818011463844797', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args27_1(self):
            '(s, gsl_sf_laguerre_n_e, (10, -11.0, -1.0, &r), 0.3678794642857142857,    TEST_TOL2, GSL_SUCCESS)'
            self._test((10, -11.0, -1.0), ('0.3678794642857142857', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args28_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -2.0,  1.0, &r),  -0.0027339992019526273866,  TEST_SQRT_TOL0, GSL_SUCCESS)'
            self._test((100, -2.0, 1.0), ('-0.0027339992019526273866', 'TEST_SQRT_TOL0'), GSL_SUCCESS)


        def test_args29_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -2.0, -1.0, &r),   229923.09193402028290,     TEST_TOL5, GSL_SUCCESS)'
            self._test((100, -2.0, -1.0), ('229923.09193402028290', 'TEST_TOL5'), GSL_SUCCESS)


        def test_args30_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -10.0,  1.0, &r),  3.25966665871244092e-11,   TEST_TOL6, GSL_SUCCESS)'
            self._test((100, -10.0, 1.0), ('3.25966665871244092e-11', 'TEST_TOL6'), GSL_SUCCESS)


        def test_args31_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -10.0, -1.0, &r),  0.00016484365618205810025, TEST_TOL6, GSL_SUCCESS)'
            self._test((100, -10.0, -1.0), ('0.00016484365618205810025', 'TEST_TOL6'), GSL_SUCCESS)


        def test_args32_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -20.0, 1.0, &r),  5.09567630343671251e-21,  TEST_TOL3, GSL_SUCCESS)'
            self._test((100, -20.0, 1.0), ('5.09567630343671251e-21', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args33_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -30.0, 1.0, &r),  3.46063150272466192e-34,  TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -30.0, 1.0), ('3.46063150272466192e-34', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args34_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -50.0,  1.0, &r),  1.20981872933162889e-65,  TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -50.0, 1.0), ('1.20981872933162889e-65', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args35_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -50.0, -1.0, &r),  8.60763477742332922e-65,  TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -50.0, -1.0), ('8.60763477742332922e-65', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args36_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -50.5,  1.0, &r),  4.84021010426688393e-31,  TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -50.5, 1.0), ('4.84021010426688393e-31', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args37_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -50.5, -1.0, &r),  8.49861345212160618e-33,  TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -50.5, -1.0), ('8.49861345212160618e-33', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args38_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -101.0,  1.0, &r), 2.7182818284590452354,    TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -101.0, 1.0), ('2.7182818284590452354', 'TEST_TOL1'), GSL_SUCCESS)

        @pytest.mark.skip
        def test_args39_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -101.0, -1.0, &r), 0.3678794411714423216,    TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -101.0, -1.0), ('0.3678794411714423216', 'TEST_TOL1'), GSL_SUCCESS)


        @pytest.mark.skip
        def test_args40_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -102.0,  1.0, &r), 271.8281828459045235,    TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -102.0, 1.0), ('271.8281828459045235', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args41_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -102.0, -1.0, &r), 37.52370299948711680,    TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -102.0, -1.0), ('37.52370299948711680', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args42_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -110.0,  1.0, &r), 1.0666955248998831554e+13, TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -110.0, 1.0), ('1.0666955248998831554e+13', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args43_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -110.0, -1.0, &r), 1.7028306108058225871e+12, TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -110.0, -1.0), ('1.7028306108058225871e+12', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args44_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -200.0,  1.0, &r), 7.47851889721356628e+58,  TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -200.0, 1.0), ('7.47851889721356628e+58', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args45_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -200.0, -1.0, &r), 2.73740299754732273e+58,  TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -200.0, -1.0), ('2.73740299754732273e+58', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args46_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -50.0,  10.0, &r), 4.504712811317745591e-21,  TEST_SQRT_TOL0, GSL_SUCCESS)'
            self._test((100, -50.0, 10.0), ('4.504712811317745591e-21', 'TEST_SQRT_TOL0'), GSL_SUCCESS)


        def test_args47_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, -50.0, -10.0, &r), 1.475165520610679937e-11,  TEST_TOL1, GSL_SUCCESS)'
            self._test((100, -50.0, -10.0), ('1.475165520610679937e-11', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args48_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, 0.0, 0.5, &r), 0.18682260367692278801, TEST_TOL2, GSL_SUCCESS)'
            self._test((100, 0.0, 0.5), ('0.18682260367692278801', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args49_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, 0.0, 10.5, &r), 9.1796907354050059874, TEST_TOL2, GSL_SUCCESS)'
            self._test((100, 0.0, 10.5), ('9.1796907354050059874', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args50_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, 0.0, -10.5, &r), 5.6329215744170606488e24, TEST_TOL2, GSL_SUCCESS)'
            self._test((100, 0.0, -10.5), ('5.6329215744170606488e24', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args51_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, 0.0, 100.5, &r), -3.9844782875811907525e20, TEST_TOL2, GSL_SUCCESS)'
            self._test((100, 0.0, 100.5), ('-3.9844782875811907525e20', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args52_1(self):
            '(s, gsl_sf_laguerre_n_e, (100, 0.0, 150, &r), -1.4463204337261709595e31, TEST_TOL2, GSL_SUCCESS)'
            self._test((100, 0.0, 150), ('-1.4463204337261709595e31', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.lncosh_e
except AttributeError:
    print("Not including tests for lncosh_e")

if _t_func != None:
    class test_sf_automatic_lncosh_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_lncosh_e, (0.125, &r), 0.007792239318898252791, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.125,), ('0.007792239318898252791', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_lncosh_e, (1.0, &r),   0.4337808304830271870,   TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.4337808304830271870', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_lncosh_e, (5.0, &r),   4.306898218339271555, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0,), ('4.306898218339271555', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_lncosh_e, (100.0, &r), 99.30685281944005469, TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0,), ('99.30685281944005469', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_lncosh_e, (1000.0, &r), 999.30685281944005469, TEST_TOL0, GSL_SUCCESS)'
            self._test((1000.0,), ('999.30685281944005469', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_lncosh_e, (-0.125, &r), 0.007792239318898252791, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.125,), ('0.007792239318898252791', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_lncosh_e, (-1.0, &r),   0.4337808304830271870,   TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.4337808304830271870', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_lncosh_e, (-5.0, &r),   4.306898218339271555, TEST_TOL0, GSL_SUCCESS)'
            self._test((-5.0,), ('4.306898218339271555', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_lncosh_e, (-100.0, &r), 99.30685281944005469, TEST_TOL0, GSL_SUCCESS)'
            self._test((-100.0,), ('99.30685281944005469', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_lncosh_e, (-1000.0, &r), 999.30685281944005469, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1000.0,), ('999.30685281944005469', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.lnsinh_e
except AttributeError:
    print("Not including tests for lnsinh_e")

if _t_func != None:
    class test_sf_automatic_lnsinh_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_lnsinh_e, (0.1, &r),  -2.3009189815304652235,  TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('-2.3009189815304652235', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_lnsinh_e, (1.0, &r),   0.16143936157119563361, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.16143936157119563361', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_lnsinh_e, (5.0, &r),   4.306807418479684201,   TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0,), ('4.306807418479684201', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_lnsinh_e, (100.0, &r), 99.30685281944005469,   TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0,), ('99.30685281944005469', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.log_1plusx_e
except AttributeError:
    print("Not including tests for log_1plusx_e")

if _t_func != None:
    class test_sf_automatic_log_1plusx_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_log_1plusx_e, (1.0e-10, &r), 9.999999999500000000e-11, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('9.999999999500000000e-11', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_log_1plusx_e, (1.0e-8, &r), 9.999999950000000333e-09, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-08,), ('9.999999950000000333e-09', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_log_1plusx_e, (1.0e-4, &r), 0.00009999500033330833533, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0001,), ('0.00009999500033330833533', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_log_1plusx_e, (0.1, &r), 0.09531017980432486004, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.09531017980432486004', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_log_1plusx_e, (0.49, &r), 0.3987761199573677730, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.49,), ('0.3987761199573677730', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_log_1plusx_e, (-0.49, &r), -0.6733445532637655964, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.49,), ('-0.6733445532637655964', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_log_1plusx_e, (1.0, &r), M_LN2, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('M_LN2', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_log_1plusx_e, (-0.99, &r), -4.605170185988091368, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.99,), ('-4.605170185988091368', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.log_1plusx_mx_e
except AttributeError:
    print("Not including tests for log_1plusx_mx_e")

if _t_func != None:
    class test_sf_automatic_log_1plusx_mx_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_log_1plusx_mx_e, (1.0e-10, &r), -4.999999999666666667e-21, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('-4.999999999666666667e-21', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_log_1plusx_mx_e, (1.0e-8, &r), -4.999999966666666917e-17, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-08,), ('-4.999999966666666917e-17', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_log_1plusx_mx_e, (1.0e-4, &r), -4.999666691664666833e-09, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0001,), ('-4.999666691664666833e-09', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_log_1plusx_mx_e, (0.1, &r), -0.004689820195675139956, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('-0.004689820195675139956', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_log_1plusx_mx_e, (0.49, &r), -0.09122388004263222704, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.49,), ('-0.09122388004263222704', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_log_1plusx_mx_e, (-0.49, &r), -0.18334455326376559639, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.49,), ('-0.18334455326376559639', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_log_1plusx_mx_e, (1.0, &r), M_LN2-1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('M_LN2-1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_log_1plusx_mx_e, (-0.99, &r), -3.615170185988091368, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.99,), ('-3.615170185988091368', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.log_abs_e
except AttributeError:
    print("Not including tests for log_abs_e")

if _t_func != None:
    class test_sf_automatic_log_abs_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_log_abs_e, (-0.1, &r), -2.3025850929940456840,  TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.1,), ('-2.3025850929940456840', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_log_abs_e, (-1.1, &r), 0.09531017980432486004,  TEST_TOL1, GSL_SUCCESS)'
            self._test((-1.1,), ('0.09531017980432486004', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_log_abs_e, (-1000.0, &r), 6.907755278982137052, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1000.0,), ('6.907755278982137052', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_log_abs_e, (0.1, &r), -2.3025850929940456840,  TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('-2.3025850929940456840', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_log_abs_e, (1.1, &r), 0.09531017980432486004,  TEST_TOL1, GSL_SUCCESS)'
            self._test((1.1,), ('0.09531017980432486004', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_log_abs_e, (1000.0, &r), 6.907755278982137052, TEST_TOL0, GSL_SUCCESS)'
            self._test((1000.0,), ('6.907755278982137052', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.log_e
except AttributeError:
    print("Not including tests for log_e")

if _t_func != None:
    class test_sf_automatic_log_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_log_e, (0.1, &r), -2.3025850929940456840,  TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('-2.3025850929940456840', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_log_e, (1.1, &r), 0.09531017980432486004,  TEST_TOL1, GSL_SUCCESS)'
            self._test((1.1,), ('0.09531017980432486004', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_log_e, (1000.0, &r), 6.907755278982137052, TEST_TOL0, GSL_SUCCESS)'
            self._test((1000.0,), ('6.907755278982137052', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.log_erfc_e
except AttributeError:
    print("Not including tests for log_erfc_e")

if _t_func != None:
    class test_sf_automatic_log_erfc_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_log_erfc_e, (-1.0, &r), log(1.842700792949714869), TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('log(1.842700792949714869)', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_log_erfc_e, (-0.1, &r), 0.106576400586522485015, TEST_TOL0, GSL_SUCCESS)'
            self._test((-0.1,), ('0.106576400586522485015', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_log_erfc_e, (-1e-10, &r),  1.1283791670318505967e-10, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1e-10,), ('1.1283791670318505967e-10', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_log_erfc_e, (0.0, &r), log(1.0), TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0,), ('log(1.0)', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_log_erfc_e, (1e-10, &r), -1.128379167159174551e-10, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('-1.128379167159174551e-10', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_log_erfc_e, (0.001, &r), -0.0011290158896213548027, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.001,), ('-0.0011290158896213548027', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_log_erfc_e, (0.1, &r), -0.119304973737395598329, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('-0.119304973737395598329', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_log_erfc_e, (1.0, &r), log(0.15729920705028513066), TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('log(0.15729920705028513066)', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_log_erfc_e, (10.0, &r), log(2.0884875837625447570e-45), TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('log(2.0884875837625447570e-45)', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.multiply_e
except AttributeError:
    print("Not including tests for multiply_e")

if _t_func != None:
    class test_sf_automatic_multiply_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_multiply_e, (-3.0,2.0, &r), -6.0,          TEST_TOL0, GSL_SUCCESS)'
            self._test((-3.0, 2.0), ('-6.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_multiply_e, (x, 1.0/x, &r),  1.0,          TEST_TOL0, GSL_SUCCESS)'
            self._test(('(0.2 * DBL_MAX)', '1.0/(0.2 * DBL_MAX)'), ('1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_multiply_e, (x, 0.2, &r),    0.04*DBL_MAX, TEST_TOL1, GSL_SUCCESS)'
            self._test(('(0.2 * DBL_MAX)', 0.2), ('0.04*DBL_MAX', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_multiply_e, (x, 4.0, &r),    0.8*DBL_MAX,  TEST_TOL1, GSL_SUCCESS)'
            self._test(('(0.2 * DBL_MAX)', 4.0), ('0.8*DBL_MAX', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.polar_to_rect
except AttributeError:
    print("Not including tests for polar_to_rect")

if _t_func != None:
    class test_sf_automatic_polar_to_rect(_test_sf_automatic):
        _func = _t_func

        def test_args0_2(self):
            '(s, gsl_sf_polar_to_rect, (10.0, M_PI/6.0, &r1, &r2),(10.0 * sqrt(3) / 2.0), TEST_TOL0,(10.0 * 0.5), TEST_TOL0,GSL_SUCCESS)'
            self._test2((10.0, 'M_PI/6.0'), ('(10.0 * sqrt(3) / 2.0)', 'TEST_TOL0'), ('(10.0 * 0.5)', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_2(self):
            '(s, gsl_sf_polar_to_rect, (10.0, -2.0/3.0*M_PI, &r1, &r2),(10.0 * (-0.5)), TEST_TOL1,(10.0 * (-sqrt(3.0)/2.0)), TEST_TOL1,GSL_SUCCESS)'
            self._test2((10.0, '-2.0/3.0*M_PI'), ('(10.0 * (-0.5))', 'TEST_TOL1'), ('(10.0 * (-sqrt(3.0)/2.0))', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.pow_int_e
except AttributeError:
    print("Not including tests for pow_int_e")

if _t_func != None:
    class test_sf_automatic_pow_int_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s,  gsl_sf_pow_int_e, (2.0, 3, &r), 8.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.0, 3), ('8.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s,  gsl_sf_pow_int_e, (-2.0, 3, &r), -8.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2.0, 3), ('-8.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s,  gsl_sf_pow_int_e, (2.0, -3, &r), 1.0/8.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((2.0, -3), ('1.0/8.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s,  gsl_sf_pow_int_e, (-2.0, -3, &r), -1.0/8.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2.0, -3), ('-1.0/8.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s,  gsl_sf_pow_int_e, (10.0, 4, &r), 1.0e+4, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0, 4), ('1.0e+4', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s,  gsl_sf_pow_int_e, (10.0, -4, &r), 1.0e-4, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0, -4), ('1.0e-4', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s,  gsl_sf_pow_int_e, (-10.0, 4, &r), 1.0e+4, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0, 4), ('1.0e+4', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s,  gsl_sf_pow_int_e, (-10.0, -4, &r), 1.0e-4, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0, -4), ('1.0e-4', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s,  gsl_sf_pow_int_e, (10.0, 40, &r), 1.0e+40, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0, 40), ('1.0e+40', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s,  gsl_sf_pow_int_e, (8.0, -40, &r), 7.523163845262640051e-37, TEST_TOL0, GSL_SUCCESS)'
            self._test((8.0, -40), ('7.523163845262640051e-37', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s,  gsl_sf_pow_int_e, (-10.0, 40, &r), 1.0e+40, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0, 40), ('1.0e+40', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s,  gsl_sf_pow_int_e, (-8.0, -40, &r), 7.523163845262640051e-37, TEST_TOL0, GSL_SUCCESS)'
            self._test((-8.0, -40), ('7.523163845262640051e-37', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s,  gsl_sf_pow_int_e, (10.0, 41, &r), 1.0e+41, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0, 41), ('1.0e+41', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s,  gsl_sf_pow_int_e, (8.0, -41, &r), 9.403954806578300064e-38, TEST_TOL0, GSL_SUCCESS)'
            self._test((8.0, -41), ('9.403954806578300064e-38', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s,  gsl_sf_pow_int_e, (-10.0, 41, &r), -1.0e+41, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0, 41), ('-1.0e+41', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s,  gsl_sf_pow_int_e, (-8.0, -41, &r), -9.403954806578300064e-38, TEST_TOL0, GSL_SUCCESS)'
            self._test((-8.0, -41), ('-9.403954806578300064e-38', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.psi_1_e
except AttributeError:
    print("Not including tests for psi_1_e")

if _t_func != None:
    class test_sf_automatic_psi_1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_psi_1_e, (1.0/32.0, &r), 1025.5728544782377089,  TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/32.0',), ('1025.5728544782377089', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_psi_1_e, (1.0, &r), 1.6449340668482264365,       TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('1.6449340668482264365', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_psi_1_e, (5.0, &r), 0.22132295573711532536,      TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0,), ('0.22132295573711532536', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_psi_1_e, (100.0, &r), 0.010050166663333571395,   TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0,), ('0.010050166663333571395', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_psi_1_e, (110.0, &r), 0.009132356622022545705,   TEST_TOL0, GSL_SUCCESS)'
            self._test((110.0,), ('0.009132356622022545705', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_psi_1_e, (500.0, &r), 0.0020020013333322666697,  TEST_TOL0, GSL_SUCCESS)'
            self._test((500.0,), ('0.0020020013333322666697', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_psi_1_e, (-1.0 - 1.0/128.0, &r), 16386.648472598746587, TEST_TOL0, GSL_SUCCESS)'
            self._test(('-1.0 - 1.0/128.0',), ('16386.648472598746587', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_psi_1_e, (-1.50, &r), 9.3792466449891237539, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.5,), ('9.3792466449891237539', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_psi_1_e, (-10.5, &r), 9.7787577398148123845, TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.5,), ('9.7787577398148123845', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_psi_1_e, (-15.5, &r), 9.8071247184113896201, TEST_TOL0, GSL_SUCCESS)'
            self._test((-15.5,), ('9.8071247184113896201', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_psi_1_e, (-50.5, &r), 9.8499971860824842274, TEST_TOL0, GSL_SUCCESS)'
            self._test((-50.5,), ('9.8499971860824842274', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_psi_1_e, (-1000.5, &r), 9.8686054001734414233, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1000.5,), ('9.8686054001734414233', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.psi_1_int_e
except AttributeError:
    print("Not including tests for psi_1_int_e")

if _t_func != None:
    class test_sf_automatic_psi_1_int_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_psi_1_int_e, (1, &r), 1.6449340668482264364,  TEST_TOL0, GSL_SUCCESS)'
            self._test((1,), ('1.6449340668482264364', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_psi_1_int_e, (2, &r), 0.64493406684822643647, TEST_TOL0, GSL_SUCCESS)'
            self._test((2,), ('0.64493406684822643647', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_psi_1_int_e, (3, &r), 0.39493406684822643647, TEST_TOL0, GSL_SUCCESS)'
            self._test((3,), ('0.39493406684822643647', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_psi_1_int_e, (4, &r), 0.28382295573711532536, TEST_TOL0, GSL_SUCCESS)'
            self._test((4,), ('0.28382295573711532536', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_psi_1_int_e, (1, &r), 1.6449340668482264365,      TEST_TOL0, GSL_SUCCESS)'
            self._test((1,), ('1.6449340668482264365', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_psi_1_int_e, (5, &r), 0.22132295573711532536,     TEST_TOL0, GSL_SUCCESS)'
            self._test((5,), ('0.22132295573711532536', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_psi_1_int_e, (100, &r), 0.010050166663333571395,  TEST_TOL0, GSL_SUCCESS)'
            self._test((100,), ('0.010050166663333571395', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_psi_1_int_e, (110, &r), 0.009132356622022545705,  TEST_TOL0, GSL_SUCCESS)'
            self._test((110,), ('0.009132356622022545705', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_psi_1_int_e, (500, &r), 0.0020020013333322666697, TEST_TOL0, GSL_SUCCESS)'
            self._test((500,), ('0.0020020013333322666697', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.psi_1piy_e
except AttributeError:
    print("Not including tests for psi_1piy_e")

if _t_func != None:
    class test_sf_automatic_psi_1piy_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_psi_1piy_e, (0.8, &r), -0.07088340212750589223, TEST_TOL1, GSL_SUCCESS)'
            self._test((0.8,), ('-0.07088340212750589223', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_psi_1piy_e, (1.0, &r),  0.09465032062247697727, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.09465032062247697727', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_psi_1piy_e, (5.0, &r),  1.6127848446157465854, TEST_TOL2, GSL_SUCCESS)'
            self._test((5.0,), ('1.6127848446157465854', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_psi_1piy_e, (100.0, &r),  4.605178519404762003, TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0,), ('4.605178519404762003', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_psi_1piy_e, (2000.0, &r), 7.600902480375416216, TEST_TOL0, GSL_SUCCESS)'
            self._test((2000.0,), ('7.600902480375416216', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_psi_1piy_e, (-0.8, &r), -0.07088340212750589223, TEST_TOL1, GSL_SUCCESS)'
            self._test((-0.8,), ('-0.07088340212750589223', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_psi_1piy_e, (-1.0, &r),  0.09465032062247697727, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1.0,), ('0.09465032062247697727', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_psi_1piy_e, (-5.0, &r),  1.6127848446157465854, TEST_TOL2, GSL_SUCCESS)'
            self._test((-5.0,), ('1.6127848446157465854', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_psi_1piy_e, (-100.0, &r),  4.605178519404762003, TEST_TOL0, GSL_SUCCESS)'
            self._test((-100.0,), ('4.605178519404762003', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_psi_1piy_e, (-2000.0, &r), 7.600902480375416216, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2000.0,), ('7.600902480375416216', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.psi_e
except AttributeError:
    print("Not including tests for psi_e")

if _t_func != None:
    class test_sf_automatic_psi_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_psi_e, (5000.0, &r), 8.517093188082904107, TEST_TOL0, GSL_SUCCESS)'
            self._test((5000.0,), ('8.517093188082904107', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_psi_e, (5.0, &r), 1.5061176684318004727, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0,), ('1.5061176684318004727', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_psi_e, (-10.5, &r),       2.3982391295357816134,  TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.5,), ('2.3982391295357816134', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_psi_e, (-100.5, &r),      4.615124601338064117,  TEST_TOL2, GSL_SUCCESS)'
            self._test((-100.5,), ('4.615124601338064117', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_psi_e, (-1.0e+5-0.5, &r), 11.512935464924395337, 4.0*TEST_TOL4, GSL_SUCCESS)'
            self._test(('-1.0e+5-0.5',), ('11.512935464924395337', '4.0*TEST_TOL4'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_psi_e, (-262144.0-0.5, &r), 12.476653064769611581, 4.0*TEST_TOL4, GSL_SUCCESS)'
            self._test(('-262144.0-0.5',), ('12.476653064769611581', '4.0*TEST_TOL4'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.psi_int_e
except AttributeError:
    print("Not including tests for psi_int_e")

if _t_func != None:
    class test_sf_automatic_psi_int_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_psi_int_e, (1, &r), -0.57721566490153286060, TEST_TOL0, GSL_SUCCESS)'
            self._test((1,), ('-0.57721566490153286060', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_psi_int_e, (2, &r), 0.42278433509846713939, TEST_TOL0, GSL_SUCCESS)'
            self._test((2,), ('0.42278433509846713939', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_psi_int_e, (3, &r), 0.92278433509846713939, TEST_TOL0, GSL_SUCCESS)'
            self._test((3,), ('0.92278433509846713939', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_psi_int_e, (4, &r), 1.2561176684318004727, TEST_TOL0, GSL_SUCCESS)'
            self._test((4,), ('1.2561176684318004727', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_psi_int_e, (5, &r), 1.5061176684318004727, TEST_TOL0, GSL_SUCCESS)'
            self._test((5,), ('1.5061176684318004727', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_psi_int_e, (100, &r), 4.600161852738087400, TEST_TOL0, GSL_SUCCESS)'
            self._test((100,), ('4.600161852738087400', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_psi_int_e, (110, &r), 4.695928024251535633, TEST_TOL0, GSL_SUCCESS)'
            self._test((110,), ('4.695928024251535633', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_psi_int_e, (5000, &r), 8.517093188082904107, TEST_TOL0, GSL_SUCCESS)'
            self._test((5000,), ('8.517093188082904107', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.psi_n_e
except AttributeError:
    print("Not including tests for psi_n_e")

if _t_func != None:
    class test_sf_automatic_psi_n_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_psi_n_e, (1, 1, &r), 1.6449340668482264364,   TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 1), ('1.6449340668482264364', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_psi_n_e, (1, 2, &r), 0.64493406684822643647,  TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 2), ('0.64493406684822643647', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_psi_n_e, (1, 3, &r), 0.39493406684822643647,  TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 3), ('0.39493406684822643647', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_psi_n_e, (1, 4, &r), 0.28382295573711532536,  TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 4), ('0.28382295573711532536', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_psi_n_e, (1, 5, &r), 0.22132295573711532536,     TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 5), ('0.22132295573711532536', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_psi_n_e, (1, 100, &r), 0.010050166663333571395,  TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 100), ('0.010050166663333571395', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_psi_n_e, (1, 110, &r), 0.009132356622022545705,  TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 110), ('0.009132356622022545705', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_psi_n_e, (1, 500, &r), 0.0020020013333322666697, TEST_TOL0, GSL_SUCCESS)'
            self._test((1, 500), ('0.0020020013333322666697', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_psi_n_e, (3, 5.0, &r), 0.021427828192755075022,     TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 5.0), ('0.021427828192755075022', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_psi_n_e, (3, 500.0, &r), 1.6048063999872000683e-08, TEST_TOL0, GSL_SUCCESS)'
            self._test((3, 500.0), ('1.6048063999872000683e-08', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_psi_n_e, (10, 5.0, &r), -0.08675107579196581317,    TEST_TOL1, GSL_SUCCESS)'
            self._test((10, 5.0), ('-0.08675107579196581317', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_psi_n_e, (10, 50.0, &r), -4.101091112731268288e-12, TEST_TOL0, GSL_SUCCESS)'
            self._test((10, 50.0), ('-4.101091112731268288e-12', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_psi_n_e, (0, -1.5, &r), 0.70315664064524318723,  TEST_TOL0, GSL_SUCCESS)'
            self._test((0, -1.5), ('0.70315664064524318723', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_psi_n_e, (1, -1.5, &r), 9.3792466449891237539,   TEST_TOL0, GSL_SUCCESS)'
            self._test((1, -1.5), ('9.3792466449891237539', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.sin_e
except AttributeError:
    print("Not including tests for sin_e")

if _t_func != None:
    class test_sf_automatic_sin_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_sin_e, (-10.0, &r),       0.5440211108893698134,    TEST_TOL0, GSL_SUCCESS)'
            self._test((-10.0,), ('0.5440211108893698134', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_sin_e, (1.0, &r),         0.8414709848078965067,    TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.8414709848078965067', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_sin_e, (1000.0, &r),      0.8268795405320025603,    TEST_TOL0, GSL_SUCCESS)'
            self._test((1000.0,), ('0.8268795405320025603', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_sin_e, (1048576.75, &r),  0.8851545351115651914,    TEST_TOL1, GSL_SUCCESS)'
            self._test((1048576.75,), ('0.8851545351115651914', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_sin_e, (62831853.75, &r), 0.6273955953485000827,    TEST_TOL3, GSL_SUCCESS)'
            self._test((62831853.75,), ('0.6273955953485000827', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_sin_e, (1073741822.5, &r), -0.8284043541754465988,  TEST_SQRT_TOL0, GSL_SUCCESS)'
            self._test((1073741822.5,), ('-0.8284043541754465988', 'TEST_SQRT_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_sin_e, (1073741824.0, &r), -0.6173264150460421708,  TEST_SQRT_TOL0, GSL_SUCCESS)'
            self._test((1073741824.0,), ('-0.6173264150460421708', 'TEST_SQRT_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_sin_e, (1073741825.5, &r),  0.7410684679436226926,  TEST_SQRT_TOL0, GSL_SUCCESS)'
            self._test((1073741825.5,), ('0.7410684679436226926', 'TEST_SQRT_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.sinc_e
except AttributeError:
    print("Not including tests for sinc_e")

if _t_func != None:
    class test_sf_automatic_sinc_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_sinc_e, (1.0/1024.0, &r), 0.9999984312693665404, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/1024.0',), ('0.9999984312693665404', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_sinc_e, (1.0/2.0,    &r), 2.0/M_PI,              TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0/2.0',), ('2.0/M_PI', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_sinc_e, (80.5,       &r), 0.0039541600768172754, TEST_TOL0, GSL_SUCCESS)'
            self._test((80.5,), ('0.0039541600768172754', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_sinc_e, (100.5,      &r), 0.0031672625490924445, TEST_TOL0, GSL_SUCCESS)'
            self._test((100.5,), ('0.0031672625490924445', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_sinc_e, (1.0e+06 + 0.5, &r), 3.18309727028927157e-07, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0e+06 + 0.5',), ('3.18309727028927157e-07', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.synchrotron_1_e
except AttributeError:
    print("Not including tests for synchrotron_1_e")

if _t_func != None:
    class test_sf_automatic_synchrotron_1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_synchrotron_1_e, (0.01, &r),  0.444972504114210632,    TEST_TOL0, GSL_SUCCESS)'
            self._test((0.01,), ('0.444972504114210632', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_synchrotron_1_e, (1.0, &r),   0.651422815355364504,    TEST_TOL1, GSL_SUCCESS)'
            self._test((1.0,), ('0.651422815355364504', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_synchrotron_1_e, (10.0, &r),  0.000192238264300868882, TEST_TOL1, GSL_SUCCESS)'
            self._test((10.0,), ('0.000192238264300868882', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_synchrotron_1_e, (100.0, &r), 4.69759366592220221e-43, TEST_TOL1, GSL_SUCCESS)'
            self._test((100.0,), ('4.69759366592220221e-43', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.synchrotron_2_e
except AttributeError:
    print("Not including tests for synchrotron_2_e")

if _t_func != None:
    class test_sf_automatic_synchrotron_2_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_synchrotron_2_e, (0.01, &r),  0.23098077342226277732, TEST_TOL2, GSL_SUCCESS)'
            self._test((0.01,), ('0.23098077342226277732', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_synchrotron_2_e, (1.0, &r),   0.4944750621042082670,  TEST_TOL1, GSL_SUCCESS)'
            self._test((1.0,), ('0.4944750621042082670', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_synchrotron_2_e, (10.0, &r),  0.00018161187569530204281,  TEST_TOL1, GSL_SUCCESS)'
            self._test((10.0,), ('0.00018161187569530204281', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_synchrotron_2_e, (256.0, &r), 1.3272635474353774058e-110, TEST_TOL4, GSL_SUCCESS)'
            self._test((256.0,), ('1.3272635474353774058e-110', 'TEST_TOL4'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.transport_2_e
except AttributeError:
    print("Not including tests for transport_2_e")

if _t_func != None:
    class test_sf_automatic_transport_2_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_transport_2_e, (1.0e-10, &r), 9.9999999999999999999e-11, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('9.9999999999999999999e-11', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_transport_2_e, (1.0, &r),     0.97303256135517012845, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.97303256135517012845', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_transport_2_e, (3.0, &r),     2.41105004901695346199, TEST_TOL0, GSL_SUCCESS)'
            self._test((3.0,), ('2.41105004901695346199', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_transport_2_e, (10.0, &r),    3.28432911449795173575, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('3.28432911449795173575', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_transport_2_e, (100.0, &r),   3.28986813369645287294, TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0,), ('3.28986813369645287294', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_transport_2_e, (1.0e+05, &r), 3.28986813369645287294, TEST_TOL0, GSL_SUCCESS)'
            self._test((100000.0,), ('3.28986813369645287294', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.transport_3_e
except AttributeError:
    print("Not including tests for transport_3_e")

if _t_func != None:
    class test_sf_automatic_transport_3_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_transport_3_e, (1.0e-10, &r), 4.999999999999999999997e-21, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('4.999999999999999999997e-21', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_transport_3_e, (1.0, &r),     0.479841006572417499939, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.479841006572417499939', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_transport_3_e, (3.0, &r),     3.210604662942246772338, TEST_TOL0, GSL_SUCCESS)'
            self._test((3.0,), ('3.210604662942246772338', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_transport_3_e, (5.0, &r),     5.614386613842273228585, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0,), ('5.614386613842273228585', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_transport_3_e, (10.0, &r),    7.150322712008592975030, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('7.150322712008592975030', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_transport_3_e, (30.0, &r),    7.212341416160946511930, TEST_TOL0, GSL_SUCCESS)'
            self._test((30.0,), ('7.212341416160946511930', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_transport_3_e, (100.0, &r),   7.212341418957565712398, TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0,), ('7.212341418957565712398', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_transport_3_e, (1.0e+05, &r), 7.212341418957565712398, TEST_TOL0, GSL_SUCCESS)'
            self._test((100000.0,), ('7.212341418957565712398', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.transport_4_e
except AttributeError:
    print("Not including tests for transport_4_e")

if _t_func != None:
    class test_sf_automatic_transport_4_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_transport_4_e, (1.0e-10, &r), 3.33333333333333333333e-31, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('3.33333333333333333333e-31', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_transport_4_e, (1.0e-07, &r), 3.33333333333333166666e-22, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-07,), ('3.33333333333333166666e-22', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_transport_4_e, (1.0e-04, &r), 3.33333333166666666726e-13, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0001,), ('3.33333333166666666726e-13', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_transport_4_e, (0.1, &r), 0.000333166726172109903824, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.000333166726172109903824', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_transport_4_e, (1.0, &r), 0.31724404523442648241, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.31724404523442648241', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_transport_4_e, (3.0, &r), 5.96482239737147652446, TEST_TOL0, GSL_SUCCESS)'
            self._test((3.0,), ('5.96482239737147652446', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_transport_4_e, (5.0, &r), 15.3597843168821829816, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0,), ('15.3597843168821829816', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_transport_4_e, (10.0, &r), 25.2736676770304417334, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('25.2736676770304417334', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_transport_4_e, (30.0, &r), 25.9757575220840937469, TEST_TOL0, GSL_SUCCESS)'
            self._test((30.0,), ('25.9757575220840937469', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_transport_4_e, (100.0, &r), 25.9757576090673165963, TEST_TOL1, GSL_SUCCESS)'
            self._test((100.0,), ('25.9757576090673165963', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_transport_4_e, (1.0e+05, &r), 25.9757576090673165963, TEST_TOL2, GSL_SUCCESS)'
            self._test((100000.0,), ('25.9757576090673165963', 'TEST_TOL2'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.transport_5_e
except AttributeError:
    print("Not including tests for transport_5_e")

if _t_func != None:
    class test_sf_automatic_transport_5_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_transport_5_e, (1.0e-10, &r), 2.49999999999999999999e-41, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('2.49999999999999999999e-41', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_transport_5_e, (1.0e-07, &r), 2.49999999999999861111e-29, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-07,), ('2.49999999999999861111e-29', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_transport_5_e, (1.0e-04, &r), 2.49999999861111111163e-17, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0001,), ('2.49999999861111111163e-17', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_transport_5_e, (0.1, &r), 0.000024986116317791487410, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.1,), ('0.000024986116317791487410', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_transport_5_e, (1.0, &r), 0.236615879239094789259153, TEST_TOL0, GSL_SUCCESS)'
            self._test((1.0,), ('0.236615879239094789259153', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_transport_5_e, (3.0, &r), 12.77055769104415951115760, TEST_TOL0, GSL_SUCCESS)'
            self._test((3.0,), ('12.77055769104415951115760', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_transport_5_e, (5.0, &r), 50.26309221817518778543615, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0,), ('50.26309221817518778543615', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_transport_5_e, (10.0, &r), 116.3807454024207107698556, TEST_TOL0, GSL_SUCCESS)'
            self._test((10.0,), ('116.3807454024207107698556', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_transport_5_e, (30.0, &r), 124.4313279083858954839911, TEST_TOL0, GSL_SUCCESS)'
            self._test((30.0,), ('124.4313279083858954839911', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_transport_5_e, (100.0, &r), 124.4313306172043911597639, TEST_TOL0, GSL_SUCCESS)'
            self._test((100.0,), ('124.4313306172043911597639', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_transport_5_e, (1.0e+05, &r), 124.43133061720439115976, TEST_TOL0, GSL_SUCCESS)'
            self._test((100000.0,), ('124.43133061720439115976', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.zeta_e
except AttributeError:
    print("Not including tests for zeta_e")

if _t_func != None:
    class test_sf_automatic_zeta_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_zeta_e, (-151, &r), 8.195215221831378294e+143, TEST_TOL2, GSL_SUCCESS)'
            self._test((-151,), ('8.195215221831378294e+143', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_zeta_e, (-51, &r), 9.68995788746359406565e+24, TEST_TOL1, GSL_SUCCESS)'
            self._test((-51,), ('9.68995788746359406565e+24', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_zeta_e, (-5, &r), -0.003968253968253968253968, TEST_TOL1, GSL_SUCCESS)'
            self._test((-5,), ('-0.003968253968253968253968', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_zeta_e, (-8, &r), 0.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-8,), ('0.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_zeta_e, (-6, &r), 0.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-6,), ('0.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_zeta_e, (-4, &r), 0.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-4,), ('0.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_zeta_e, (-3, &r), 1.0/120.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-3,), ('1.0/120.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_zeta_e, (-2, &r), 0.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-2,), ('0.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_zeta_e, (-1, &r), -1.0/12.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-1,), ('-1.0/12.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_zeta_e, (-0.5, &r), -0.207886224977354566017307, TEST_TOL1, GSL_SUCCESS)'
            self._test((-0.5,), ('-0.207886224977354566017307', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_zeta_e, (-1e-10, &r), -0.49999999990810614668948, TEST_TOL1, GSL_SUCCESS)'
            self._test((-1e-10,), ('-0.49999999990810614668948', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_zeta_e, (0.0, &r),    -0.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0,), ('-0.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_zeta_e, (1e-10, &r),  -0.50000000009189385333058, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('-0.50000000009189385333058', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_zeta_e, (0.5, &r), -1.460354508809586812889499, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5,), ('-1.460354508809586812889499', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_zeta_e, (1.0-1.0/1024.0, &r), -1023.4228554489429787, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0-1.0/1024.0',), ('-1023.4228554489429787', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s, gsl_sf_zeta_e, (1.0+1.0/1048576, &r), 1.0485765772157343441e+06, TEST_TOL0, GSL_SUCCESS)'
            self._test(('1.0+1.0/1048576',), ('1.0485765772157343441e+06', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s, gsl_sf_zeta_e, (5.0, &r), 1.036927755143369926331365, TEST_TOL0, GSL_SUCCESS)'
            self._test((5.0,), ('1.036927755143369926331365', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s, gsl_sf_zeta_e, (25.5, &r), 1.000000021074106110269959, TEST_TOL0, GSL_SUCCESS)'
            self._test((25.5,), ('1.000000021074106110269959', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.zeta_int_e
except AttributeError:
    print("Not including tests for zeta_int_e")

if _t_func != None:
    class test_sf_automatic_zeta_int_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_zeta_int_e, (-61.0, &r), -3.30660898765775767257e+34, TEST_TOL0, GSL_SUCCESS)'
            self._test((-61,), ('-3.30660898765775767257e+34', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_zeta_int_e, (-8, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-8,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_zeta_int_e, (-6, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-6,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_zeta_int_e, (-5.0, &r),  -0.003968253968253968253968, TEST_TOL0, GSL_SUCCESS)'
            self._test((-5,), ('-0.003968253968253968253968', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_zeta_int_e, (-4, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-4,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_zeta_int_e, (-3, &r), 1.0/120.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-3,), ('1.0/120.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_zeta_int_e, (-2, &r), 0.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2,), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_zeta_int_e, (-1, &r), -1.0/12.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1,), ('-1.0/12.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_zeta_int_e, ( 5.0, &r), 1.0369277551433699263313655, TEST_TOL0, GSL_SUCCESS)'
            self._test((5,), ('1.0369277551433699263313655', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_zeta_int_e, (31.0, &r), 1.0000000004656629065033784, TEST_TOL0, GSL_SUCCESS)'
            self._test((31,), ('1.0000000004656629065033784', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.zetam1_e
except AttributeError:
    print("Not including tests for zetam1_e")

if _t_func != None:
    class test_sf_automatic_zetam1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_zetam1_e, (-8, &r), -1.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-8,), ('-1.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_zetam1_e, (-6, &r), -1.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-6,), ('-1.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_zetam1_e, (-4, &r), -1.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-4,), ('-1.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_zetam1_e, (-3, &r), -119.0/120.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-3,), ('-119.0/120.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_zetam1_e, (-2, &r), -1.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-2,), ('-1.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_zetam1_e, (-1, &r), -13.0/12.0, TEST_TOL1, GSL_SUCCESS)'
            self._test((-1,), ('-13.0/12.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_zetam1_e, (-0.5, &r), -1.207886224977354566017307, TEST_TOL1, GSL_SUCCESS)'
            self._test((-0.5,), ('-1.207886224977354566017307', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_zetam1_e, (-1e-10, &r), -1.49999999990810614668948, TEST_TOL1, GSL_SUCCESS)'
            self._test((-1e-10,), ('-1.49999999990810614668948', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_zetam1_e, (0.0, &r),    -1.5, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.0,), ('-1.5', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_zetam1_e, (1e-10, &r),  -1.50000000009189385333058, TEST_TOL0, GSL_SUCCESS)'
            self._test((1e-10,), ('-1.50000000009189385333058', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_zetam1_e, (0.5, &r), -2.460354508809586812889499, TEST_TOL0, GSL_SUCCESS)'
            self._test((0.5,), ('-2.460354508809586812889499', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_zetam1_e, (2.0, &r),  0.64493406684822643647,     TEST_TOL1, GSL_SUCCESS)'
            self._test((2.0,), ('0.64493406684822643647', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_zetam1_e, (3.0, &r),  0.20205690315959428540,     TEST_TOL1, GSL_SUCCESS)'
            self._test((3.0,), ('0.20205690315959428540', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_zetam1_e, (5.0, &r),  0.0369277551433699263314,   TEST_TOL1, GSL_SUCCESS)'
            self._test((5.0,), ('0.0369277551433699263314', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_zetam1_e, (9.5, &r),  0.0014125906121736622712,   TEST_TOL1, GSL_SUCCESS)'
            self._test((9.5,), ('0.0014125906121736622712', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s, gsl_sf_zetam1_e, (10.5, &r), 0.000700842641736155219500, TEST_TOL1, GSL_SUCCESS)'
            self._test((10.5,), ('0.000700842641736155219500', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args16_1(self):
            '(s, gsl_sf_zetam1_e, (12.5, &r), 0.000173751733643178193390, TEST_TOL1, GSL_SUCCESS)'
            self._test((12.5,), ('0.000173751733643178193390', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args17_1(self):
            '(s, gsl_sf_zetam1_e, (13.5, &r), 0.000086686727462338155188, TEST_TOL1, GSL_SUCCESS)'
            self._test((13.5,), ('0.000086686727462338155188', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args18_1(self):
            '(s, gsl_sf_zetam1_e, (15.5, &r), 0.000021619904246069108133, TEST_TOL1, GSL_SUCCESS)'
            self._test((15.5,), ('0.000021619904246069108133', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args19_1(self):
            '(s, gsl_sf_zetam1_e, (16.5, &r), 0.000010803124900178547671, TEST_TOL0, GSL_SUCCESS)'
            self._test((16.5,), ('0.000010803124900178547671', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args20_1(self):
            '(s, gsl_sf_zetam1_e, (25.5, &r), 0.000000021074106110269959, TEST_TOL0, GSL_SUCCESS)'
            self._test((25.5,), ('0.000000021074106110269959', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:
    _t_func = sf.zetam1_int_e
except AttributeError:
    print("Not including tests for zetam1_int_e")

if _t_func != None:
    class test_sf_automatic_zetam1_int_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_zetam1_int_e, (-61.0, &r), -3.30660898765775767257e+34, TEST_TOL0, GSL_SUCCESS)'
            self._test((-61,), ('-3.30660898765775767257e+34', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_zetam1_int_e, (-5.0, &r),  -1.003968253968253968253968, TEST_TOL0, GSL_SUCCESS)'
            self._test((-5,), ('-1.003968253968253968253968', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_zetam1_int_e, (-8, &r), -1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-8,), ('-1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_zetam1_int_e, (-6, &r), -1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-6,), ('-1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_zetam1_int_e, (-4, &r), -1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-4,), ('-1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_zetam1_int_e, (-3, &r), -119.0/120.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-3,), ('-119.0/120.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_zetam1_int_e, (-2, &r), -1.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-2,), ('-1.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_zetam1_int_e, (-1, &r), -13.0/12.0, TEST_TOL0, GSL_SUCCESS)'
            self._test((-1,), ('-13.0/12.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_zetam1_int_e, ( 5.0, &r), 0.0369277551433699263313655, TEST_TOL0, GSL_SUCCESS)'
            self._test((5,), ('0.0369277551433699263313655', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_zetam1_int_e, (31.0, &r), 0.0000000004656629065033784, TEST_TOL0, GSL_SUCCESS)'
            self._test((31,), ('0.0000000004656629065033784', 'TEST_TOL0'), GSL_SUCCESS)


if __name__ == '__main__':
    unittest.main()
