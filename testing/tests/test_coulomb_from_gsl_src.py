#!/usr/bin/env python
# WARNING: Automatically generated file: do not edit!
#          Edited the generated source instead.
#
# Tests converted from GSL Source directory.
# Original license:
# /* specfunc/test_coulomb.c
# /* specfunc/test_coulomb.c
#  * 
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
    _t_func = sf.hydrogenicR_1_e
except AttributeError:
    print("Not including tests for hydrogenicR_1_e")
    
if _t_func != None:
    class test_sf_automatic_hydrogenicR_1_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hydrogenicR_1_e, (3.0, 2.0, &r),  0.025759948256148471036,  TEST_TOL0, GSL_SUCCESS)'            
            self._test((3.0, 2.0), ('0.025759948256148471036', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hydrogenicR_1_e, (3.0, 10.0, &r), 9.724727052062819704e-13, TEST_TOL1, GSL_SUCCESS)'            
            self._test((3.0, 10.0), ('9.724727052062819704e-13', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.hydrogenicR_e
except AttributeError:
    print("Not including tests for hydrogenicR_e")
    
if _t_func != None:
    class test_sf_automatic_hydrogenicR_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_hydrogenicR_e, (4, 1, 3.0, 0.0, &r),  0.0,  TEST_TOL0, GSL_SUCCESS)'            
            self._test((4, 1, 3.0, 0.0), ('0.0', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_hydrogenicR_e, (4, 0, 3.0, 2.0, &r), -0.03623182256981820062,  TEST_TOL2, GSL_SUCCESS)'            
            self._test((4, 0, 3.0, 2.0), ('-0.03623182256981820062', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_hydrogenicR_e, (4, 1, 3.0, 2.0, &r), -0.028065049083129581005, TEST_TOL2, GSL_SUCCESS)'            
            self._test((4, 1, 3.0, 2.0), ('-0.028065049083129581005', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_hydrogenicR_e, (4, 2, 3.0, 2.0, &r),  0.14583027278668431009,  TEST_TOL0, GSL_SUCCESS)'            
            self._test((4, 2, 3.0, 2.0), ('0.14583027278668431009', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_hydrogenicR_e, (100,  0, 3.0, 2.0, &r), -0.00007938950980052281367, TEST_TOL3, GSL_SUCCESS)'            
            self._test((100, 0, 3.0, 2.0), ('-0.00007938950980052281367', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_hydrogenicR_e, (100, 10, 3.0, 2.0, &r),  7.112823375353605977e-12,  TEST_TOL2, GSL_SUCCESS)'            
            self._test((100, 10, 3.0, 2.0), ('7.112823375353605977e-12', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_hydrogenicR_e, (100, 90, 3.0, 2.0, &r),  5.845231751418131548e-245, TEST_TOL2, GSL_SUCCESS)'            
            self._test((100, 90, 3.0, 2.0), ('5.845231751418131548e-245', 'TEST_TOL2'), GSL_SUCCESS)


if __name__ == '__main__':
    unittest.main()
