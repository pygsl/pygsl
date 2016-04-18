#!/usr/bin/env python
# WARNING: Automatically generated file: do not edit!
#          Edited the generated source instead.
#
# Tests converted from GSL Source directory.
# Original license:
# /* specfunc/test_dilog.c
#  * 
#  * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2004 Gerard Jungman
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
    _t_func = sf.dilog_e
except AttributeError:
    print("Not including tests for dilog_e")
    
if _t_func != None:
    class test_sf_automatic_dilog_e(_test_sf_automatic):
        _func = _t_func

        def test_args0(self):
            '(s, gsl_sf_dilog_e, (-3.0, &r),   -1.9393754207667089531,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((-3.0,), -1.9393754207667089531, TEST_TOL0, GSL_SUCCESS)


        def test_args1(self):
            '(s, gsl_sf_dilog_e, (-0.5, &r),   -0.4484142069236462024,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.5,), -0.4484142069236462024, TEST_TOL0, GSL_SUCCESS)


        def test_args2(self):
            '(s, gsl_sf_dilog_e, (-0.001, &r), -0.0009997501110486510834,  TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.001,), -0.0009997501110486510834, TEST_TOL0, GSL_SUCCESS)


        def test_args3(self):
            '(s, gsl_sf_dilog_e, (0.1, &r),     0.1026177910993911,        TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.1,), 0.1026177910993911, TEST_TOL0, GSL_SUCCESS)


        def test_args4(self):
            '(s, gsl_sf_dilog_e, (0.7, &r),     0.8893776242860387386,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.7,), 0.8893776242860387386, TEST_TOL0, GSL_SUCCESS)


        def test_args5(self):
            '(s, gsl_sf_dilog_e, (1.0, &r),     1.6449340668482260,        TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0,), 1.6449340668482260, TEST_TOL0, GSL_SUCCESS)


        def test_args6(self):
            '(s, gsl_sf_dilog_e, (1.5, &r),     2.3743952702724802007,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.5,), 2.3743952702724802007, TEST_TOL0, GSL_SUCCESS)


        def test_args7(self):
            '(s, gsl_sf_dilog_e, (2.0, &r),     2.4674011002723397,        TEST_TOL0, GSL_SUCCESS)'            
            self._test((2.0,), 2.4674011002723397, TEST_TOL0, GSL_SUCCESS)


        def test_args8(self):
            '(s, gsl_sf_dilog_e, ( 5.0, &r),    1.7837191612666306277,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((5.0,), 1.7837191612666306277, TEST_TOL0, GSL_SUCCESS)


        def test_args9(self):
            '(s, gsl_sf_dilog_e, ( 11.0, &r),   0.3218540439999117111,     TEST_TOL1, GSL_SUCCESS)'            
            self._test((11.0,), 0.3218540439999117111, TEST_TOL1, GSL_SUCCESS)


        def test_args10(self):
            '(s, gsl_sf_dilog_e, (12.59, &r),   0.0010060918167266208634,  TEST_TOL3, GSL_SUCCESS)'            
            self._test((12.59,), 0.0010060918167266208634, TEST_TOL3, GSL_SUCCESS)


        def test_args11(self):
            '(s, gsl_sf_dilog_e, (12.595, &r),  0.00003314826006436236810, TEST_TOL5, GSL_SUCCESS)'            
            self._test((12.595,), 0.00003314826006436236810, TEST_TOL5, GSL_SUCCESS)


        def test_args12(self):
            '(s, gsl_sf_dilog_e, (13.0, &r),   -0.07806971248458575855,    TEST_TOL2, GSL_SUCCESS)'            
            self._test((13.0,), -0.07806971248458575855, TEST_TOL2, GSL_SUCCESS)


        def test_args13(self):
            '(s, gsl_sf_dilog_e, (20.0, &r),   -1.2479770861745251168,     TEST_TOL2, GSL_SUCCESS)'            
            self._test((20.0,), -1.2479770861745251168, TEST_TOL2, GSL_SUCCESS)


        def test_args14(self):
            '(s, gsl_sf_dilog_e, (150.0, &r),  -9.270042702348657270,      TEST_TOL0, GSL_SUCCESS)'            
            self._test((150.0,), -9.270042702348657270, TEST_TOL0, GSL_SUCCESS)


        def test_args15(self):
            '(s, gsl_sf_dilog_e, (1100.0, &r), -21.232504073931749553,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((1100.0,), -21.232504073931749553, TEST_TOL0, GSL_SUCCESS)


if __name__ == '__main__':
    unittest.main()
