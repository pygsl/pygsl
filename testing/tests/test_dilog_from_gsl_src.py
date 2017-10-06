#!/usr/bin/env python
# WARNING: Automatically generated file: do not edit!
#          Edited the generated source instead.
#
# Tests converted from GSL Source directory.
# Original license:
# /* specfunc/test_dilog.c
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
    _t_func = sf.complex_dilog_e
except AttributeError:
    print("Not including tests for complex_dilog_e")
    
if _t_func != None:
    class test_sf_automatic_complex_dilog_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.99999, M_PI/2.0, &r1, &r2),-0.20561329262779687646, TEST_TOL0,0.91595774018131512060, TEST_TOL0,GSL_SUCCESS)'            
            self._test2((0.99999, 'M_PI/2.0'), ('-0.20561329262779687646', 'TEST_TOL0'), ('0.91595774018131512060', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.991, M_PI/2.0, &r1, &r2),-0.20250384721077806127, TEST_TOL0,0.90888544355846447810, TEST_TOL0,GSL_SUCCESS)'            
            self._test2((0.991, 'M_PI/2.0'), ('-0.20250384721077806127', 'TEST_TOL0'), ('0.90888544355846447810', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.98, M_PI/2.0, &r1, &r2),-0.19871638377785918403, TEST_TOL2,0.90020045882981847610, TEST_TOL2,GSL_SUCCESS)'            
            self._test2((0.98, 'M_PI/2.0'), ('-0.19871638377785918403', 'TEST_TOL2'), ('0.90020045882981847610', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args3_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.98, -M_PI/2.0, &r1, &r2),-0.19871638377785918403, TEST_TOL2,-0.90020045882981847610, TEST_TOL2,GSL_SUCCESS)'            
            self._test2((0.98, '-M_PI/2.0'), ('-0.19871638377785918403', 'TEST_TOL2'), ('-0.90020045882981847610', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args4_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.95, M_PI/2.0, &r1, &r2),-0.18848636456893572091, TEST_TOL1,0.87633754133420277830, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.95, 'M_PI/2.0'), ('-0.18848636456893572091', 'TEST_TOL1'), ('0.87633754133420277830', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.8, M_PI/2.0, &r1, &r2),-0.13980800855429037810, TEST_TOL0,0.75310609092419884460, TEST_TOL0,GSL_SUCCESS)'            
            self._test2((0.8, 'M_PI/2.0'), ('-0.13980800855429037810', 'TEST_TOL0'), ('0.75310609092419884460', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.8, -M_PI/2.0, &r1, &r2),-0.13980800855429037810, TEST_TOL0,-0.75310609092419884460, TEST_TOL0,GSL_SUCCESS)'            
            self._test2((0.8, '-M_PI/2.0'), ('-0.13980800855429037810', 'TEST_TOL0'), ('-0.75310609092419884460', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.5, M_PI/2.0, &r1, &r2),-0.05897507442156586346, TEST_TOL1,0.48722235829452235710, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.5, 'M_PI/2.0'), ('-0.05897507442156586346', 'TEST_TOL1'), ('0.48722235829452235710', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args8_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.5, -M_PI/2.0, &r1, &r2),-0.05897507442156586346, TEST_TOL1,-0.48722235829452235710, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.5, '-M_PI/2.0'), ('-0.05897507442156586346', 'TEST_TOL1'), ('-0.48722235829452235710', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args9_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.01, M_PI/2.0, &r1, &r2),-0.000024999375027776215378, TEST_TOL3,0.009999888892888684820, TEST_TOL3,GSL_SUCCESS)'            
            self._test2((0.01, 'M_PI/2.0'), ('-0.000024999375027776215378', 'TEST_TOL3'), ('0.009999888892888684820', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args10_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.01, -M_PI/2.0, &r1, &r2),-0.000024999375027776215378, TEST_TOL3,-0.009999888892888684820, TEST_TOL3,GSL_SUCCESS)'            
            self._test2((0.01, '-M_PI/2.0'), ('-0.000024999375027776215378', 'TEST_TOL3'), ('-0.009999888892888684820', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args11_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.99, M_PI/4.0, &r1, &r2),0.56273366219795547757, TEST_TOL3,0.97009284079274560384, TEST_TOL3,GSL_SUCCESS)'            
            self._test2((0.99, 'M_PI/4.0'), ('0.56273366219795547757', 'TEST_TOL3'), ('0.97009284079274560384', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args12_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.99, -M_PI/4.0, &r1, &r2),0.56273366219795547757, TEST_TOL3,-0.97009284079274560384, TEST_TOL3,GSL_SUCCESS)'            
            self._test2((0.99, '-M_PI/4.0'), ('0.56273366219795547757', 'TEST_TOL3'), ('-0.97009284079274560384', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args13_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.99, 3.0*M_PI/4.0, &r1, &r2),-0.66210902664245926235, TEST_TOL1,0.51995305609998319025, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.99, '3.0*M_PI/4.0'), ('-0.66210902664245926235', 'TEST_TOL1'), ('0.51995305609998319025', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args14_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.99, 5.0*M_PI/4.0, &r1, &r2),-0.66210902664245926235, TEST_TOL1,-0.51995305609998319025, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.99, '5.0*M_PI/4.0'), ('-0.66210902664245926235', 'TEST_TOL1'), ('-0.51995305609998319025', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args15_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.99, 3.0*M_PI/2.0, &r1, &r2),-0.20215874509123277909, TEST_TOL1,-0.90809733095648731408, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.99, '3.0*M_PI/2.0'), ('-0.20215874509123277909', 'TEST_TOL1'), ('-0.90809733095648731408', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args16_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.25, 3.0*M_PI/2.0, &r1, &r2),-0.01538741178141053563, TEST_TOL1,-0.24830175098230686908, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.25, '3.0*M_PI/2.0'), ('-0.01538741178141053563', 'TEST_TOL1'), ('-0.24830175098230686908', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args17_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.25, 15.0/8.0*M_PI, &r1, &r2),0.24266162342377302235, TEST_TOL1,-0.10860883369274445067, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.25, '15.0/8.0*M_PI'), ('0.24266162342377302235', 'TEST_TOL1'), ('-0.10860883369274445067', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args18_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.99, M_PI/8.0, &r1, &r2),1.0571539648820244720, TEST_TOL0,0.7469145254610851318, TEST_TOL0,GSL_SUCCESS)'            
            self._test2((0.99, 'M_PI/8.0'), ('1.0571539648820244720', 'TEST_TOL0'), ('0.7469145254610851318', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args19_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.99, M_PI/64.0, &r1, &r2),1.5381800285902999666, TEST_TOL0,0.1825271634987756651, TEST_TOL0,GSL_SUCCESS)'            
            self._test2((0.99, 'M_PI/64.0'), ('1.5381800285902999666', 'TEST_TOL0'), ('0.1825271634987756651', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args20_2(self):
            '(s, gsl_sf_complex_dilog_e, (0.99, -M_PI/8.0, &r1, &r2),1.05715396488202447202, TEST_TOL1,-0.74691452546108513176, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.99, '-M_PI/8.0'), ('1.05715396488202447202', 'TEST_TOL1'), ('-0.74691452546108513176', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args21_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.00001, M_PI/2.0, &r1, &r2),-0.20562022409960237363, TEST_TOL1,0.91597344814458309320, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.00001, 'M_PI/2.0'), ('-0.20562022409960237363', 'TEST_TOL1'), ('0.91597344814458309320', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args22_2(self):
            '(s, gsl_sf_complex_dilog_e, (10.0, M_PI/2.0, &r1, &r2),-3.0596887943287347304, TEST_TOL0,3.7167814930680685900, TEST_TOL0,GSL_SUCCESS)'            
            self._test2((10.0, 'M_PI/2.0'), ('-3.0596887943287347304', 'TEST_TOL0'), ('3.7167814930680685900', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args23_2(self):
            '(s, gsl_sf_complex_dilog_e, (100.0, M_PI/2.0, &r1, &r2),-11.015004738293824854, TEST_TOL0,7.2437843013083534970, TEST_TOL0,GSL_SUCCESS)'            
            self._test2((100.0, 'M_PI/2.0'), ('-11.015004738293824854', 'TEST_TOL0'), ('7.2437843013083534970', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args24_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.1, -M_PI/2.0, &r1, &r2),-0.24099184177382733037, TEST_TOL1,-0.99309132538137822631, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.1, '-M_PI/2.0'), ('-0.24099184177382733037', 'TEST_TOL1'), ('-0.99309132538137822631', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args25_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.1, 3.0*M_PI/2.0, &r1, &r2),-0.24099184177382733037, TEST_TOL1,-0.99309132538137822631, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.1, '3.0*M_PI/2.0'), ('-0.24099184177382733037', 'TEST_TOL1'), ('-0.99309132538137822631', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args26_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.1, -3.0*M_PI/2.0, &r1, &r2),-0.24099184177382733037, TEST_TOL1,0.99309132538137822631, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.1, '-3.0*M_PI/2.0'), ('-0.24099184177382733037', 'TEST_TOL1'), ('0.99309132538137822631', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args27_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.1, -M_PI - 0.25*M_PI, &r1, &r2),-0.72908565537087935118, TEST_TOL1,0.56225783937234862649, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.1, '-M_PI - 0.25*M_PI'), ('-0.72908565537087935118', 'TEST_TOL1'), ('0.56225783937234862649', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args28_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.1, M_PI + 0.25*M_PI, &r1, &r2),-0.72908565537087935118, TEST_TOL1,-0.56225783937234862649, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.1, 'M_PI + 0.25*M_PI'), ('-0.72908565537087935118', 'TEST_TOL1'), ('-0.56225783937234862649', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args29_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.1, -M_PI/128.0, &r1, &r2),1.8881719454909716580, TEST_TOL1,-0.3556738764969238976, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.1, '-M_PI/128.0'), ('1.8881719454909716580', 'TEST_TOL1'), ('-0.3556738764969238976', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args30_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.1,  M_PI/128.0, &r1, &r2),1.8881719454909716580, TEST_TOL1,0.3556738764969238976, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.1, 'M_PI/128.0'), ('1.8881719454909716580', 'TEST_TOL1'), ('0.3556738764969238976', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args31_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.5,  M_PI/8.0, &r1, &r2),1.3498525763442498343, TEST_TOL1,1.4976532712229749493, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.5, 'M_PI/8.0'), ('1.3498525763442498343', 'TEST_TOL1'), ('1.4976532712229749493', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args32_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.5, -M_PI/8.0, &r1, &r2),1.3498525763442498343, TEST_TOL1,-1.4976532712229749493, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.5, '-M_PI/8.0'), ('1.3498525763442498343', 'TEST_TOL1'), ('-1.4976532712229749493', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args33_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.5, 2.0*M_PI + M_PI/8.0, &r1, &r2),1.3498525763442498343, TEST_TOL1,1.4976532712229749493, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.5, '2.0*M_PI + M_PI/8.0'), ('1.3498525763442498343', 'TEST_TOL1'), ('1.4976532712229749493', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args34_2(self):
            '(s, gsl_sf_complex_dilog_e, (1.5, 2.0*M_PI - M_PI/8.0, &r1, &r2),1.3498525763442498343, TEST_TOL1,-1.4976532712229749493, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.5, '2.0*M_PI - M_PI/8.0'), ('1.3498525763442498343', 'TEST_TOL1'), ('-1.4976532712229749493', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.complex_dilog_xy_e
except AttributeError:
    print("Not including tests for complex_dilog_xy_e")
    
if _t_func != None:
    class test_sf_automatic_complex_dilog_xy_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_2(self):
            '(s, gsl_sf_complex_dilog_xy_e, (0.0,  0.5, &r1, &r2),-0.05897507442156586346, TEST_TOL1,0.48722235829452235710, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.0, 0.5), ('-0.05897507442156586346', 'TEST_TOL1'), ('0.48722235829452235710', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_2(self):
            '(s, gsl_sf_complex_dilog_xy_e, (0.0, -0.5, &r1, &r2),-0.05897507442156586346, TEST_TOL1,-0.48722235829452235710, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.0, -0.5), ('-0.05897507442156586346', 'TEST_TOL1'), ('-0.48722235829452235710', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_2(self):
            '(s, gsl_sf_complex_dilog_xy_e, (0.91464073718617389108,  0.37885659804143889673, &r1, &r2),1.0571539648820244720, TEST_TOL0,0.7469145254610851318, TEST_TOL0,GSL_SUCCESS)'            
            self._test2((0.9146407371861739, 0.3788565980414389), ('1.0571539648820244720', 'TEST_TOL0'), ('0.7469145254610851318', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_2(self):
            '(s, gsl_sf_complex_dilog_xy_e, (0.91464073718617389108, -0.37885659804143889673, &r1, &r2),1.05715396488202447202, TEST_TOL1,-0.74691452546108513176, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.9146407371861739, -0.3788565980414389), ('1.05715396488202447202', 'TEST_TOL1'), ('-0.74691452546108513176', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args4_2(self):
            '(s, gsl_sf_complex_dilog_xy_e, (-1.5, 0.0, &r1, &r2),-1.1473806603755707541, TEST_TOL1,0.0, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((-1.5, 0.0), ('-1.1473806603755707541', 'TEST_TOL1'), ('0.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_2(self):
            '(s, gsl_sf_complex_dilog_xy_e, (0.5, 0.0, &r1, &r2),0.58224052646501250590, TEST_TOL1,0.0, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.5, 0.0), ('0.58224052646501250590', 'TEST_TOL1'), ('0.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args6_2(self):
            '(s, gsl_sf_complex_dilog_xy_e, (1.5, 0.0, &r1, &r2),2.3743952702724802007, TEST_TOL1,-1.2738062049196005309, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.5, 0.0), ('2.3743952702724802007', 'TEST_TOL1'), ('-1.2738062049196005309', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.complex_spence_xy_e
except AttributeError:
    print("Not including tests for complex_spence_xy_e")
    
if _t_func != None:
    class test_sf_automatic_complex_spence_xy_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_2(self):
            '(s, gsl_sf_complex_spence_xy_e, (1.5, 0.0, &r1, &r2),-0.44841420692364620244, TEST_TOL1,0.0, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((1.5, 0.0), ('-0.44841420692364620244', 'TEST_TOL1'), ('0.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args1_2(self):
            '(s, gsl_sf_complex_spence_xy_e, (0.5, 0.0, &r1, &r2),0.58224052646501250590, TEST_TOL1,0.0, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.5, 0.0), ('0.58224052646501250590', 'TEST_TOL1'), ('0.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args2_2(self):
            '(s, gsl_sf_complex_spence_xy_e, (0.0, 0.0, &r1, &r2),1.6449340668482264365, TEST_TOL1,0.0, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((0.0, 0.0), ('1.6449340668482264365', 'TEST_TOL1'), ('0.0', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args3_2(self):
            '(s, gsl_sf_complex_spence_xy_e, (-0.5, 0.0, &r1, &r2),2.3743952702724802007, TEST_TOL1,-1.2738062049196005309, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((-0.5, 0.0), ('2.3743952702724802007', 'TEST_TOL1'), ('-1.2738062049196005309', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args4_2(self):
            '(s, gsl_sf_complex_spence_xy_e, (-0.5, 1.0/1024.0, &r1, &r2),2.3723507455234125018, TEST_TOL1,-1.2742581376517839070, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((-0.5, '1.0/1024.0'), ('2.3723507455234125018', 'TEST_TOL1'), ('-1.2742581376517839070', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args5_2(self):
            '(s, gsl_sf_complex_spence_xy_e, (-0.5, -1.0/1024.0, &r1, &r2),2.3723507455234125018, TEST_TOL1,1.2742581376517839070, TEST_TOL1,GSL_SUCCESS)'            
            self._test2((-0.5, '-1.0/1024.0'), ('2.3723507455234125018', 'TEST_TOL1'), ('1.2742581376517839070', 'TEST_TOL1'), GSL_SUCCESS)

_t_func = None
try:    
    _t_func = sf.dilog_e
except AttributeError:
    print("Not including tests for dilog_e")
    
if _t_func != None:
    class test_sf_automatic_dilog_e(_test_sf_automatic):
        _func = _t_func

        def test_args0_1(self):
            '(s, gsl_sf_dilog_e, (-3.0, &r),   -1.9393754207667089531,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((-3.0,), ('-1.9393754207667089531', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args1_1(self):
            '(s, gsl_sf_dilog_e, (-0.5, &r),   -0.4484142069236462024,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.5,), ('-0.4484142069236462024', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args2_1(self):
            '(s, gsl_sf_dilog_e, (-0.001, &r), -0.0009997501110486510834,  TEST_TOL0, GSL_SUCCESS)'            
            self._test((-0.001,), ('-0.0009997501110486510834', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args3_1(self):
            '(s, gsl_sf_dilog_e, (0.1, &r),     0.1026177910993911,        TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.1,), ('0.1026177910993911', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args4_1(self):
            '(s, gsl_sf_dilog_e, (0.7, &r),     0.8893776242860387386,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((0.7,), ('0.8893776242860387386', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args5_1(self):
            '(s, gsl_sf_dilog_e, (1.0, &r),     1.6449340668482260,        TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.0,), ('1.6449340668482260', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args6_1(self):
            '(s, gsl_sf_dilog_e, (1.5, &r),     2.3743952702724802007,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((1.5,), ('2.3743952702724802007', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args7_1(self):
            '(s, gsl_sf_dilog_e, (2.0, &r),     2.4674011002723397,        TEST_TOL0, GSL_SUCCESS)'            
            self._test((2.0,), ('2.4674011002723397', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args8_1(self):
            '(s, gsl_sf_dilog_e, ( 5.0, &r),    1.7837191612666306277,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((5.0,), ('1.7837191612666306277', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args9_1(self):
            '(s, gsl_sf_dilog_e, ( 11.0, &r),   0.3218540439999117111,     TEST_TOL1, GSL_SUCCESS)'            
            self._test((11.0,), ('0.3218540439999117111', 'TEST_TOL1'), GSL_SUCCESS)


        def test_args10_1(self):
            '(s, gsl_sf_dilog_e, (12.59, &r),   0.0010060918167266208634,  TEST_TOL3, GSL_SUCCESS)'            
            self._test((12.59,), ('0.0010060918167266208634', 'TEST_TOL3'), GSL_SUCCESS)


        def test_args11_1(self):
            '(s, gsl_sf_dilog_e, (12.595, &r),  0.00003314826006436236810, TEST_TOL5, GSL_SUCCESS)'            
            self._test((12.595,), ('0.00003314826006436236810', 'TEST_TOL5'), GSL_SUCCESS)


        def test_args12_1(self):
            '(s, gsl_sf_dilog_e, (13.0, &r),   -0.07806971248458575855,    TEST_TOL2, GSL_SUCCESS)'            
            self._test((13.0,), ('-0.07806971248458575855', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args13_1(self):
            '(s, gsl_sf_dilog_e, (20.0, &r),   -1.2479770861745251168,     TEST_TOL2, GSL_SUCCESS)'            
            self._test((20.0,), ('-1.2479770861745251168', 'TEST_TOL2'), GSL_SUCCESS)


        def test_args14_1(self):
            '(s, gsl_sf_dilog_e, (150.0, &r),  -9.270042702348657270,      TEST_TOL0, GSL_SUCCESS)'            
            self._test((150.0,), ('-9.270042702348657270', 'TEST_TOL0'), GSL_SUCCESS)


        def test_args15_1(self):
            '(s, gsl_sf_dilog_e, (1100.0, &r), -21.232504073931749553,     TEST_TOL0, GSL_SUCCESS)'            
            self._test((1100.0,), ('-21.232504073931749553', 'TEST_TOL0'), GSL_SUCCESS)


if __name__ == '__main__':
    unittest.main()
