#! /usr/bin/env python2
#
# author: Achim Gaedke, Pierre Schnizer
# created: May 2001
# modified: over the years, 2017
# file: pygsl/setup.py
# $Id$
#
# setup script for building and installing pygsl


# Use SWIG to generate the approbriate wrapper files. This is only necessary
# if you modified any interface file as the wrapper files are included in the
# distribution
USE_SWIG = 1

# Some modules have been reimplemented. These modules will be installed in
# pygsl.testing...
# Set to one if you want them built
BUILD_TESTING = 1

# Some modules are not considered to be used in future
BUILD_DEPRECATED = 0

#
# If you want to use the PyGSL API in other projects ...
# Well, I do
#
INSTALL_HEADERS = 1
#
# SWIG 2.1? or above generates faster wrappers ... requires python 2.5 or greater
#'-builtin',
# Currently testing if it works for all modules
SWIG_USE_BUILTIN = 1
#

## Which gsl error handler to install?
# set the error handler to off: only the integer return value will be available
# This is the safest version. But then information useful to the user could be
# lost.
GSL_ERROR_HANDLER = 0
# Use the store version of the error handler: when GSL calls the error handler
# the information passed (which file, at which line, which reason) are stored
# at a static location. This information is then used for functions which
# return a status. When a non success status is turned in a python exception
# the stored information is used to add this to the exception.
# If more than one thread is running it could happen that the wrong information
# is returned. Only the type of exception is then correct.
GSL_ERROR_HANDLER = 1

#####
# PyGSL comes with a lot of debug information. This can be either disabled
# setting DEBUG_LEVEL to 0 at compile time, swtiched on and off at run time
# using pygsl.set_debug_level(level) setting DEBUG_LEVEL to 0 or set to some
# value during compile time using a level bigger than 1 (the heigher the value
# is the more verbose the output gets. Please note that pygsl needs to be
# completly rebuild if you hcange this parameter
# No debug information
#DEBUG_LEVEL = 0
# dynamic debug information
DEBUG_LEVEL = 1
# Compile time set debug level
#DEBUG_LEVEL = 10
#####
#------------------------------------------------------------------------------
# As long as you are not taking part in the development process, I hope that 
# you do not need to modify anything here.



import sys
import time
import string
import glob

# Add the gsldist path
import os
pygsldir = os.path.dirname("__name__")

# Get the version information
versionfile = open(os.path.join(pygsldir, "pygsl", "_version.py"))
versiontext = versionfile.read()
exec(versiontext)
versionfile.close()
del versionfile
del versiontext

# Make sure that we use the new one ...
gsldist_path = os.path.join(pygsldir, "gsl_dist")
sys.path.insert(0, gsldist_path)

from wheel.bdist_wheel import bdist_wheel as _bdist_wheel

import setuptools
import setuptools.command
import setuptools.command.install
import setuptools.command.bdist_egg
from setuptools import setup, Extension

from gsl_Extension import gsl_Extension
from swig_extension import SWIG_Extension as _SWIG_Extension
from swig_extension import SWIG_Extension_Nop as _SWIG_Extension_Nop

from distutils import sysconfig


if USE_SWIG == 0:
    _SWIG_Extension = _SWIG_Extension_Nop


def SWIG_Extension(*args, **kws):
    kws["py_dir"] = "pygsl"
    kws["c_dir"] = "swig_src"
    return _SWIG_Extension(*args, **kws)

if SWIG_USE_BUILTIN:
    swig_flags = ["-builtin", "-O", "-Wall"]
else:
    swig_flags = []


macros = [
    ('SWIG_COBJECT_TYPES', 1),
    ('DEBUG', DEBUG_LEVEL)
    ]

if GSL_ERROR_HANDLER == 0:
    # If the macro below is not set the error handler will be set to off.
    pass
elif GSL_ERROR_HANDLER == 1:
    macros += [("PyGSL_SET_GSL_ERROR_HANDLER", 1),]
else:
    raise ValueError("Expected a value of 0|1 but got '%s'" %(GSL_ERROR_HANDLER))

macros = macros + []
check_macros = [('GSL_DISABLE_DEPRECATED', 1)]

import gsl_CodeGenerator
import gsl_Config
# config has to be run before any other "build" or "install" commmand
# perhaps not required for sdist?
_has_gsl_config = 0
try:
    import gsl_features
    _has_gsl_config = 1
except ImportError:
    # Config is required ... no need to proceed any further
    if "config" not in sys.argv:
        # Spoof it like you mean it
        sys.argv = sys.argv[0:1] + ["config"] + sys.argv[1:]
        print("Spoofing argument: config")

exts = []
extsOnly2 = []


if _has_gsl_config == 0:
    # Presumably running config
    pass
else:
    assert(_has_gsl_config)
    #Just checking that the module is there
    gsl_features

    # now gsl_packages can be loaded. Using gsl_features only the available ones
    # will be added to the to be built extensions
    a_file_name =  "gsl_packages.py"
    t_file =  open(os.path.join(pygsldir, a_file_name))
    text = t_file.read()
    exec(text, globals(), locals())
    del text
    t_file.close()
    del t_file


class CustomInstallCommand(setuptools.command.install.install):
    def run(self):
        # first re-generate GSL wrappers using SWIG
        self.run_command('gsl_wrappers')
        # then configure
        self.run_command('config')
        # then install
        setuptools.command.install.install.run(self)
        #super().run()

class CustomBdistWheelCommand(_bdist_wheel):
    def run(self):
        # first re-generate GSL wrappers using SWIG
        self.run_command('gsl_wrappers')
        # then configure
        self.run_command('config')
        # then install
        _bdist_wheel.run(self)
        #super().run()

py_module_names = ['errors',
                   'statistics.__init__',
		   '_numobj',
		   #'_mlab',
                   '_block',
                   '_callback',
                   '_generic_solver',
                   '_poly',
                   'blas',
                   'block',
                   'chebyshev',
                   'combination',
                   'eigen',
                   'fft',
                   'fit',
                   'gsl_function',
                   'gslwrap',
                   'hankel',
                   'integrate',
                   'interpolation',
                   'linalg',
                   'matrix_pierre',
                   'minimize',
                   'monte',
                   'multifit',
                   'multifit_nlin',
                   'multiroots',
                   'odeiv',
                   'permutation',
                   'poly',
                   'qrng',
                   'roots',
                   'siman',
                   'sum',
                   'spline',
                   'testing.__init__',
                   'vector',
                   'math'
                   ]

gsldist = []
headers = None
if INSTALL_HEADERS == 1:
    headers = glob.glob("Include/pygsl/*.h")
    gsldist = ['gsl_dist.' + os.path.basename(x)[:-3] for x in glob.glob("gsl_dist/*.py")]

py_modules = ['pygsl.' + x for x in py_module_names] + gsldist

if sys.version_info[0] <= 2:
    exts = exts + extsOnly2
    sys.stdout.write("Bulding for '%s'\n" %(sys.version,))


class gsl_Config_Path(gsl_Config.gsl_Config):
    """
    Only required here to set the pygsl directory
    """
    _pygsl_dir = pygsldir


print("#%d extension modules" %(len(exts),))

proj_name ="pygsl"
setup (name = proj_name,
       version = version,
       #version = "snapshot_" + string.join(map(str, time.gmtime()[:3]), '_'),
       description = "GNU Scientific Library Interface",
       long_description = "This project provides a python interface for the GNU scientific library (gsl)",
       license = "GPL",
       author = "Achim Gaedke, Pierre Schnizer",
       author_email = "AchimGaedke@users.sourceforge.net, schnizer@users.sourceforge.net",
       url = "https://github.com/pygsl/pygsl",
       package_dir = {'pygsl' : 'pygsl', 'pygsl.gsl_dist' : 'gsl_dist'},
       packages = ['pygsl', 'pygsl.testing', 'pygsl.statistics', 'pygsl.gsl_dist'],
       ext_package = 'pygsl',
       ext_modules = exts,
       headers = headers,
       cmdclass = {'bdist_wheel': CustomBdistWheelCommand,
                   'config' : gsl_Config_Path,
                   'gsl_wrappers': gsl_CodeGenerator.gsl_CodeGenerator,
                   'install': CustomInstallCommand,
                   #'build_sphinx': BuildDoc
                   },
       install_requires = ['numpy'],
       command_options = {
           'build_sphinx': {
               'project': ('setup.py', proj_name),
               'version': ('setup.py', version),
               }
            },
       package_data={"pygsl": ["testing/src/sf/sf.i"]}
       )
