#! /usr/bin/env python2
#
# author: Achim Gaedke
# created: May 2001
# file: pygsl/test.py
# $Id$
#
# script to start pygsl tests from distribution root dir.

import sys
import os.path
import distutils.sysconfig
import distutils.util
import unittest

my_path=os.path.dirname(os.path.abspath(sys.argv[0]))
my_version=distutils.sysconfig.get_config_var('VERSION')
build_lib_path=os.path.join(my_path,"build","lib.%s-%s"%(distutils.util.get_platform(),my_version))
test_path=os.path.join(my_path,"tests")

sys.path.insert(-1,build_lib_path)
sys.path.insert(-1,test_path)

from histogram_test import *
from rng_test import *
from const_test import *
from statistics_test import *

if __name__ == "__main__":
    unittest.main()
