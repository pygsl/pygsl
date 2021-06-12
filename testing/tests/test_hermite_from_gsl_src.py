#!/usr/bin/env python
# WARNING: Automatically generated file: do not edit!
#          Edited the generated source instead.
#
# Tests converted from GSL Source directory.
# Original license:
# /* specfunc/test_hermite.c
# /* specfunc/test_hermite.c
#  * 
#  * Copyright (C) 2011, 2012, 2013, 2014 Konrad Griessinger
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
    _t_func = sf.hermite_func_der_e
except AttributeError:
    print("Not including tests for hermite_func_der_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_func_der_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_func_der_e, (0, n, x, &r),  0.235262808086212406493191404,  TEST_TOL0, GSL_SUCCESS)'            
            self._test((0, 'n', 'x'), ('0.235262808086212406493191404', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hermite_func_der_e, (m, n, x, &r),  4035.32788513029308540826835,  TEST_TOL1, GSL_SUCCESS)'            
            self._test(('m', 'n', 'x'), ('4035.32788513029308540826835', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hermite_func_e
except AttributeError:
    print("Not including tests for hermite_func_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_func_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_func_e, (n, 0, &r),  0.290371943657199641200016132937,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 0), ('0.290371943657199641200016132937', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hermite_func_e, (n, x, &r),  0.23526280808621240649319140441,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('0.23526280808621240649319140441', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_hermite_func_e, (n, x, &r),  -0.02903467369856961147236598086,  TEST_TOL4, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('-0.02903467369856961147236598086', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_hermite_func_e, (n, x, &r),  -0.05301278920004176459797680403,  TEST_TOL4, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('-0.05301278920004176459797680403', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_hermite_func_e, (n, x, &r),  0.06992968509693993526829596970,  TEST_TOL3, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('0.06992968509693993526829596970', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_hermite_func_e, (n, x, &r),  0.08049000991742150521366671021,  TEST_TOL4, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('0.08049000991742150521366671021', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_hermite_func_e, (n, x, &r),  0.08048800667512084252723933250,  TEST_TOL4, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('0.08048800667512084252723933250', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_hermite_func_e, (n, x, &r),  7.97206830806663013555068100e-6,  TEST_TOL4, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('7.97206830806663013555068100e-6', 'TEST_TOL4'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_hermite_func_e, (n, x, &r),  7.97188517397786729928465829e-6,  TEST_TOL4, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('7.97188517397786729928465829e-6', 'TEST_TOL4'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hermite_func_series_e
except AttributeError:
    print("Not including tests for hermite_func_series_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_func_series_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_func_series_e, (n, x, res, &r),  0.81717103529960997134154552556,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x', 'res'), ('0.81717103529960997134154552556', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hermite_phys_der_e
except AttributeError:
    print("Not including tests for hermite_phys_der_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_phys_der_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_phys_der_e, (m, n, x, &r),  0.,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('m', 'n', 'x'), ('0.', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hermite_phys_der_e, (m, n, x, &r),  2.89461215568095657569833e132,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('m', 'n', 'x'), ('2.89461215568095657569833e132', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hermite_phys_e
except AttributeError:
    print("Not including tests for hermite_phys_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_phys_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_phys_e, (0, 0.75, &r),  1.,  TEST_TOL0, GSL_SUCCESS)'            
            self._test((0, 0.75), ('1.', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hermite_phys_e, (1, 0.75, &r),  2.*x,  TEST_TOL0, GSL_SUCCESS)'            
            self._test((1, 0.75), ('2.*x', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_hermite_phys_e, (n, 0., &r),  0.,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 0.0), ('0.', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_hermite_phys_e, (n, 0., &r),  3497296636753920000,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 0.0), ('3497296636753920000', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_hermite_phys_e, (n, 0.75, &r),  -9.7029819451106077507781088352e15,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 0.75), ('-9.7029819451106077507781088352e15', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_hermite_phys_e, (n, 0.75, &r),  3.7538457078067672096408339776e18,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 0.75), ('3.7538457078067672096408339776e18', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_hermite_phys_e, (n, x, &r),  -2.7074282783315424535693575770e20470,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('-2.7074282783315424535693575770e20470', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_hermite_phys_e, (n, x, &r),  -1.7392214893577690864150561850e20477,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('-1.7392214893577690864150561850e20477', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_hermite_phys_e, (n, x, &r),  3.3847852473526979744366379542e23752,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('3.3847852473526979744366379542e23752', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_hermite_phys_e, (n, x, &r),  1.9355145738418079256435712027e23760,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('1.9355145738418079256435712027e23760', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_hermite_phys_e, (n, x, &r),  6.053663953512337293393128307e23782,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('6.053663953512337293393128307e23782', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_hermite_phys_e, (n, x, &r),  3.487782358276961096026268141e23790,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('3.487782358276961096026268141e23790', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hermite_phys_series_e
except AttributeError:
    print("Not including tests for hermite_phys_series_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_phys_series_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_phys_series_e, (n, x, res, &r),  1.07772223811696567390619566842e88,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x', 'res'), ('1.07772223811696567390619566842e88', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hermite_phys_zero_e
except AttributeError:
    print("Not including tests for hermite_phys_zero_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_phys_zero_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_phys_zero_e, (n, m, &r),  H17z[m-1],  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'm'), ('H17z[m-1]', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hermite_phys_zero_e, (n, m, &r),  H18z[m-1],  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'm'), ('H18z[m-1]', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_hermite_phys_zero_e, (n, m, &r),  H23z[m-1],  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'm'), ('H23z[m-1]', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_hermite_phys_zero_e, (n, m, &r),  H24z[m-1],  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'm'), ('H24z[m-1]', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hermite_prob_der_e
except AttributeError:
    print("Not including tests for hermite_prob_der_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_prob_der_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_prob_der_e, (m, n, x, &r),  0.,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('m', 'n', 'x'), ('0.', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hermite_prob_der_e, (m, n, x, &r),  -3.0288278964712702882066404e112,  TEST_TOL1, GSL_SUCCESS)'            
            self._test(('m', 'n', 'x'), ('-3.0288278964712702882066404e112', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hermite_prob_e
except AttributeError:
    print("Not including tests for hermite_prob_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_prob_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_prob_e, (0, 0.75, &r),  1.,  TEST_TOL0, GSL_SUCCESS)'            
            self._test((0, 0.75), ('1.', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hermite_prob_e, (1, 0.75, &r),  x,  TEST_TOL0, GSL_SUCCESS)'            
            self._test((1, 0.75), ('x', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_hermite_prob_e, (n, 0., &r),  0.,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 0.0), ('0.', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_hermite_prob_e, (n, 0., &r),  213458046676875,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 0.0), ('213458046676875', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_hermite_prob_e, (n, 0.75, &r),  -1.08128685847680748265939328423e12,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 0.75), ('-1.08128685847680748265939328423e12', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_hermite_prob_e, (n, 0.75, &r),  -1.60620252094658918105511125135e14,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 0.75), ('-1.60620252094658918105511125135e14', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_hermite_prob_e, (n, x, &r),  -3.3090527852387782540121569578e18961,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('-3.3090527852387782540121569578e18961', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_hermite_prob_e, (n, x, &r),  -7.515478445930242044360704363e18967,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('-7.515478445930242044360704363e18967', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_hermite_prob_e, (n, x, &r),  4.1369269649092456235914193753e22243,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('4.1369269649092456235914193753e22243', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_hermite_prob_e, (n, x, &r),  8.363694992558646923734666303e22250,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('8.363694992558646923734666303e22250', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_hermite_prob_e, (n, x, &r),  7.398863979737363164340057757e22273,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('7.398863979737363164340057757e22273', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_hermite_prob_e, (n, x, &r),  1.507131397474022356488976968e22281,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x'), ('1.507131397474022356488976968e22281', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hermite_prob_series_e
except AttributeError:
    print("Not including tests for hermite_prob_series_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_prob_series_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_prob_series_e, (n, x, res, &r),  -4.0451066556993485405907339548e68,  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'x', 'res'), ('-4.0451066556993485405907339548e68', 'TEST_TOL0'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hermite_prob_zero_e
except AttributeError:
    print("Not including tests for hermite_prob_zero_e")
    
if _t_func != None:
    class test_sf_automatic_hermite_prob_zero_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hermite_prob_zero_e, (n, m, &r),  He17z[m-1],  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'm'), ('He17z[m-1]', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hermite_prob_zero_e, (n, m, &r),  He18z[m-1],  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'm'), ('He18z[m-1]', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_hermite_prob_zero_e, (n, m, &r),  He23z[m-1],  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'm'), ('He23z[m-1]', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_hermite_prob_zero_e, (n, m, &r),  He24z[m-1],  TEST_TOL0, GSL_SUCCESS)'            
            self._test(('n', 'm'), ('He24z[m-1]', 'TEST_TOL0'), GSL_SUCCESS)


if __name__ == '__main__':
    unittest.main()
