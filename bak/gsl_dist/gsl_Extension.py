#
# author: Achim Gaedke, Pierre Schnizer
# created: May 2001
# modified: Sep 2017
# file: pygsl/gsl_dist/gsl_extension.py
# $Id$
#
# module for gsl extensions compilation

from setuptools import Extension
from distutils.errors import DistutilsExecError

import os
import os.path
from sys import version_info
import numpy as np

from gsl_Location import gsl_Location

array_include_dirs = [np.get_include()]


class gsl_Extension(Extension):
    """
    for gsl needs
    """

    def __init__(
        self,
        name,
        sources,
        include_dirs=None,
        define_macros=None,
        undef_macros=None,
        library_dirs=None,
        libraries=None,
        runtime_library_dirs=None,
        extra_objects=None,
        extra_compile_args=None,
        extra_link_args=None,
        export_symbols=None,
        gsl_prefix=None,
        gsl_min_version=None,
        python_min_version=None,
        depends=None,
        **kws
    ):

        # get real prefix
        self.gsl_prefix = self.get_gsl_prefix()

        gsl_major_version, gsl_minor_version = self.get_gsl_version()
        # check gsl version
        if gsl_min_version is not None and not self.check_gsl_version(gsl_min_version):
            raise DistutilsExecError(
                "min gsl version %s required" % repr(gsl_min_version)
            )

        # check python version
        if python_min_version is not None and not self.check_python_version(
            python_min_version
        ):
            raise DistutilsExecError(
                "min python version %s required" % repr(python_min_version)
            )

        # prepend include directory
        if include_dirs is None:
            include_dirs = []
        include_dirs.append("Include")
        include_dirs.append(".")
        include_dirs = gsl_Location.get_gsl_include_dirs() + include_dirs
        include_dirs = include_dirs + array_include_dirs

        # prepend library directory
        if library_dirs is None:
            library_dirs = []
        library_dirs = library_dirs + gsl_Location.get_gsl_library_dirs()

        # Testing linking to non standard location if standard location is available
        # runtime_library_dirs = gsl_Location.get_gsl_library_dirs()
        if libraries is None:
            libraries = []
        # libraries.append('pygsl')
        libraries.extend(gsl_Location.get_gsl_lib_list())

        # test if Numeric module is available
        if define_macros is None:
            define_macros = []

        if undef_macros == None:
            undef_macros = []
        if "NDEBUG" not in undef_macros:
            undef_macros.append("NDEBUG")

        Extension.__init__(
            self,
            name,
            sources,
            include_dirs,
            define_macros,
            undef_macros,
            library_dirs,
            libraries,
            runtime_library_dirs,
            extra_objects,
            extra_compile_args,
            extra_link_args,
            export_symbols,
            depends=depends,
            **kws
        )

    def check_version(self, required_version, this_version):
        this_version = tuple(this_version)
        # print("req '%s' this '%s'" %(required_version, this_version))
        min_length = min(len(required_version), len(this_version))
        for pos in range(min_length):
            t_val = this_version[pos]
            test_val = required_version[pos]
            # print("\t %d: req '%s' this '%s'" %( pos, test_val, t_val))

            this_type = type(t_val)
            if this_type == type(" "):
                t_val = int(t_val)

            if type(test_val) == type(" "):
                test_val = int(test_val)

            if t_val > test_val:
                # already larger
                return 1
            elif t_val == test_val:
                continue
            elif t_val < test_val:
                return 0
            else:
                raise DistutilsExecError("incorrect version specification")
        # problematic: 0.9 < 0.9.0, but assures that 0.9.1 > 0.9
        if len(required_version) > len(this_version):
            return 0
        return 1

    def check_gsl_version(self, version_array):
        return self.check_version(version_array, self.get_gsl_version())

    def check_python_version(self, version_array):
        return self.check_version(version_array, version_info)

    # get gsl-prefix option
    def get_gsl_info(self, arguments):
        """
        executes gsl-config with given arguments
        """
        gsl_command = os.popen(self.gsl_config_tool + " " + arguments)
        gsl_output = gsl_command.readline()
        gsl_command.close()
        if not gsl_output:
            raise DistutilsExecError("could not start %s" % self.gsl_config_tool)
        return gsl_output

    def get_gsl_prefix(
        self,
    ):
        return gsl_Location.get_gsl_prefix()

    def get_gsl_cflags(self):
        return gsl_Location.get_gsl_cflags()

    def get_gsl_libs(self):
        return gsl_Location.get_gsl_libs()

    def get_gsl_version(self):
        return gsl_Location.get_gsl_version()
