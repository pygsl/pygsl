# author: Pierre Schnizer
# created: March 2016
# file: pygsl/gsl_dist/gsl_Config.py
# $Id$
#
"""
Python supports GNU autoconf style detection of available features. This module
now determines which features the installed GSL library provides. These are
then included during the build process.

See gsl_Config for further details
"""
from __future__ import print_function
import sys
import os.path
import string
import copy
import logging
import setuptools.command.build_ext

logger = logging.getLogger("setup.py")
# Add the gsldist path

# Setuptools does currently not provide a config command
#from setuptools.command import config
from distutils.command import config


def add_build_flags_to_config(argv):

    # Not prepared for that...
    # If user asks for an explicit config step lets have the user full
    # control
    assert("config" not in argv)

    spoof_argv = copy.copy(argv)
    logger.debug("Start stealing compiler arguments from build for config'%s'" %(spoof_argv,))
    r = []

    # Todo: not yet prepared if there is only an install command ....
    while True:
        try:
            arg = spoof_argv.pop(0)
        except IndexError:
            # No build argument .... nothing to do here
            return r

        logger.debug("arg %s" %(arg,))
        # Lets look for the build command
        if arg in ("build", "build_ext"):
            # but be careful. could a install command trigger a build?
            # but do I need to worry? In this case there are no compiler flags which are
            # passed around
            #
            # Todo: what about config file options?
            break
        r.append(arg)

    build_arg = arg

    # The following flags have to be repeated
    cached = []

    # Now let's check the options for compiler linker options etc ... currently
    # take everthing after the command
    #
    # cache it as it has to be inserted in between config and build
    while True:
        try:
            arg = spoof_argv.pop(0)
        except IndexError:
            # No more arguments to process
            break

        if (len(arg) == 2 and arg[0] == '-') or arg[:2] == "--":
            # I prefer to break out of the loop but leave the rest
            # straight ahead
            pass
        else:
            # All other cases not handeled
            msg = "Stopping stealing build compiler argurments at %s"
            logger.debug(msg % (arg,))
            break

        # copy long and short options up to the next command
        cached.append(arg)

    result = r + ["config"] + cached + [build_arg] + cached + spoof_argv
    # Now rebuild argument vector
    return result




import gsl_Location





_build_ext = setuptools.command.build_ext.build_ext
class BuildWithConfig(_build_ext):
    """Execute config if required.

    The config step tests for the available modules. Then :mod:`build_ext`

    Appetite comes with eating.

    Warning:
        Do not use gsl-version-in-build-path (yet). This will break the complete
        build process.
    """

    # pygsl supports different versions of GSL. Therefore  a separate build
    # directory should be used for the different GSL versions.
    #
    # Todo: put gsl_features there too
    # user_options = _build_ext.user_options + [("gsl-version-in-build-path", "V",
    # "add GSL version to the build temporary path") ]

    boolean_options = _build_ext.boolean_options + ["gsl-version-in-build-path"]

    def initialize_options(self):
        _build_ext.initialize_options(self)
        #self.define = None
        self.gsl_version_in_build_path = False
        self._gsl_location = None

    def finalize_options(self):
        _build_ext.finalize_options(self)
        if self.define is not None:
            # 'define' option is a list of (name,value) tuples
            for (name, value) in self.define:
                self.compiler.define_macro(name, value)


        if self.gsl_version_in_build_path:
            import gsl_version
            # Does the name need mangling?
            version_txt = "gsl_" + gsl_version.version
            self.build_temp = os.path.join(self.build_temp, version_txt)
            self.build_lib  = os.path.join(self.build_lib, version_txt)
            fmt = "Build temp path %s  and lib path %s now contains gsl version"
            logger.info(fmt %(self.build_temp, self.build_lib))

    def _checkConfig(self):
        """see if a configuration tool was already there
        """
        has_gsl_config = 0
        try:
            import gsl_features
            has_gsl_config = 1
            logger.info("import gsl_features succeeded: config already run")
        except ImportError:
            logger.info("No configuration step run before")

        if has_gsl_config:
            # Then gsl_version must exist too
            import gsl_version
            # And these attributes
            gsl_version.version


            # gsl-1.13 does not provide that
            # gsl_version.gsl_major_minor

        return has_gsl_config

    def _executeConfigIfRequired(self):
        if not self._checkConfig():
            logger.debug("Running config")
            self.run_command("config")

            # Now the import must work
            import gsl_features
            # and the gsl version must be defined
            import gsl_version

    def run(self):
        """

        Todo:
           how to exclude packages that were not configured?
        """
        self._executeConfigIfRequired()
        _build_ext.run(self)

    def _runSourceGenerator(self, ext):
        """Run swig if the extension requires it
        """

        ext.runSourceGenerator()

    def _LoadGSLLocation(self):
        if self._gsl_location is None:
            self._gsl_location = gsl_Location.gsl_Location_File()
        assert(self._gsl_location is not None)

    @property
    def gsl_location(self):
        self._LoadGSLLocation()
        return self._gsl_location

    def _feature_available(self, module_name):
        """Is this module available for this GSL version

        The wrapper
        """
        import gsl_features

        flag = None
        if  module_name is not None:
            try:
                flag =  getattr(gsl_features, module_name)
            except AttributeError:
                logger.warn("Config process did not set gsl module %s" %(module_name,))
                return
        else:
            # A module which should always be built: it is not configurable
            flag = True
        return flag


    def build_extension(self, ext):
        """build extension unless configuration found that it does not exist
        """
        assert(self.build_temp is not None)
        #assert(self.lib_temp is not None)

        conf_mod = ext.gsl_configurable_module
        flag = self._feature_available(conf_mod)
        fmt = "extension %s module configurable %s? available %s?"
        logger.debug(fmt %(ext.name, conf_mod, flag))
        if not flag:
            return

        ext.gsl_location = self.gsl_location
        self._runSourceGenerator(ext)

        # Module should exist
        ext.include_dirs += self.gsl_location.get_gsl_include_dirs()
        ext.library_dirs += self.gsl_location.get_gsl_library_dirs()
        ext.libraries += self.gsl_location.get_gsl_lib_list()
        _build_ext.build_extension(self, ext)


    def copy_extensions_to_source(self):
        """Copy only the available modules

        Removes temporary the extensions which do not exist in this version

        Todo:
            Fix the hack
        """
        extensions_save = self.extensions

        # Only the extensions that really exist
        extensions  = []
        for ext in self.extensions:
            module_name = ext.gsl_configurable_module
            if self._feature_available(module_name):
                extensions.append(ext)

        self.extensions = extensions
        try:
            r = _build_ext.copy_extensions_to_source(self)
        finally:
            self.extensions = extensions_save

        return r

conf = config.config

class gsl_Config(conf):
    """Check the available features.

    C defines are stored in a header file. See method _write_header_config_file
    for details.

    A class has to be drived from this class which defines the member _pygsl_dir
    with the path of the pygsl_dir
    """
    _pygsl_dir = None

    user_options = conf.user_options
    user_options += [("gsl-prefix=", "P",
                      "gsl prefix path")]


    def __init__(self, *args, **kws):
        conf.__init__(self, *args, **kws)

        self._header_variables_dict = {}
        self._found_modules_dict = {}

        self._gsl_config_version_info = None
        self._gsl_location = None
        self.gsl_prefix = None
        self.noisy = False
        self.dump_source = False

    def check_header(self, *args, **kws):
        """
        headers need to include gsl header directory
        """
        kws = self._handle_include_dir_kw(kws)
        return conf.check_header(self, *args, **kws)

    def check_func(self, *args, **kws):

        kws = self._handle_include_dir_kw(kws)
        kws = self._handle_library_dir_kw(kws)
        kws = self._handle_libraries_kw(kws)

        return conf.check_func(self, *args, **kws)

    def initialize_options(self):
        conf.initialize_options(self)
        self.define = None

        # Let's default to not noisy ... config did not make too much trouble for me
        # yet
        # but it has no effect yet?
        self.noisy = 0
        # but it has no effect yet?
        self.dump_source = 0

    def finalize_options(self):
        conf.finalize_options(self)
        if self.define is not None:
            # 'define' option is a list of (name,value) tuples
            for (name, value) in self.define:
                self.compiler.define_macro(name, value)

    @property
    def gsl_location(self):
        if self._gsl_location is None:
            self._gsl_location = gsl_Location.gsl_Location_for_config(gsl_prefix_option=self.gsl_prefix)
        assert(self._gsl_location is not None)
        return self._gsl_location

    def _get_gsl_include_dirs(self):
        dirs = self.gsl_location.get_gsl_include_dirs()
        return dirs

    def _get_gsl_lib_dirs(self):
        dirs = self.gsl_location.get_gsl_library_dirs()
        return dirs

    def _get_gsl_lib_list(self):
        return self.gsl_location.get_gsl_lib_list()

    def _handle_include_dir_kw(self, kws):
        include_dirs = "include_dirs"
        dirs = kws.pop(include_dirs, None)
        if dirs == None:
            dirs = []
        else:
            dirs = list(dirs)

        gsl_dirs = self._get_gsl_include_dirs()
        dirs.extend(gsl_dirs)
        kws[include_dirs] = dirs
        return kws

    def _handle_libraries_kw(self, kws):
        key = "libraries"
        dirs = kws.pop(key, None)
        if dirs == None:
            dirs = []
        else:
            dirs = list(dirs)

        gsl_dirs = self._get_gsl_lib_list()
        dirs.extend(gsl_dirs)
        kws[key] = dirs
        return kws

    def _handle_library_dir_kw(self, kws):
        library_dirs = "library_dirs"
        dirs = kws.pop(library_dirs, None)
        if dirs == None:
            dirs = []
        else:
            dirs = list(dirs)

        gsl_dirs = self._get_gsl_lib_dirs()
        dirs.extend(gsl_dirs)
        kws[library_dirs] = dirs
        return kws


    def set_pygsl_dir(self, dir):
        self._pygsl_dir = dir

    def _add_header_variables_dict(self, name, val):
        t_dict = self._header_variables_dict
        t_dict[name] = val

    def _add_found_module(self, name, val):
        t_dict = self._found_modules_dict
        t_dict[name] = val

    def _write_module_config_file_intern(self, stream):
        t_dict = self._found_modules_dict

        msg = """
# !!! Warning: Autmotically detected modules: Do not modify this file !!!
#              Modify '%s' instead!
'''
Automatically detected modules

This file contains variables which reflect which modules were found in GSL when
the config process was run.
'''
        """
        stream.write(msg % __name__)

        keys = t_dict.keys()
        keys = list(keys)
        keys.sort()
        keys = tuple(keys)

        # Writting python code ... watch indentation
        stream.write("\n")
        for key in keys:
            val = t_dict[key]
            stream.write("%s = %s\n" %(key, val) )

    def _write_module_config_file(self):
        file_name = "gsl_features.py"

        #print("member pygsl dir = '%s'" %(self._pygsl_dir,))
        assert(self._pygsl_dir != None)

        path = os.path.join(self._pygsl_dir, "gsl_dist", file_name)

        stream = open(path, "wt")
        try:
            self._write_module_config_file_intern(stream)
        finally:
            stream.close()
            del stream

    def _write_header_config_file_intern(self, stream):
        t_dict = self._header_variables_dict

        header = "_PyGSL_FEATURES_CONFIG_H_"

        msg="""#ifndef %s
#define %s 1

/*
 * WARNING: Automatically generated file: do not edit by hand.
 *          edit 'setup_try' instead!
 */
"""
        stream.write(msg % (header,header))

        msg ="""
#ifdef %s
#warning The name %s
#warning is used as preprocessor directive which is automatically defined during
#warning the config process. The variable given here could be overwritten by the
#warning definitions below.
#endif /* %s */
"""
        stream.write("/* check that no config variables are predefined */\n")
        keys = t_dict.keys()
        keys = list(keys)
        keys.sort()
        keys = tuple(keys)

        for key in keys:
            val = t_dict[key]
            stream.write(msg %(key,key,key))
        stream.write("/* end check that no config variables are predefined */\n\n")

        stream.write("/* definition of config variables */\n")
        for key in keys:
            val = t_dict[key]
            if val != 0:
                if val == True:
                    val = 1
                stream.write("#define %s %s\n" %(key, val) )
        stream.write("/* end definition of config variables */\n\n")

        stream.write("\n#endif /* %s */\n" % (header,))

    def _write_header_config_file(self):
        pygsl_dir = self._pygsl_dir
        assert(pygsl_dir != None)

        path = os.path.join(pygsl_dir, 'Include', 'pygsl', 'pygsl_features_config.h')
        stream = open(path, "wt")

        try:
            self._write_header_config_file_intern(stream)
        finally:
            stream.close()
            del stream

    def _check_module_abs(self):
        return self.check_func("abs", headers=("stdlib.h",))

    def _handle_found_module(self, mod_name, flag):
        c_prefix = "_PYGSL_GSL_HAS_"
        c_define = c_prefix + mod_name.upper()
        self._add_header_variables_dict(c_define, flag)
        self._add_found_module(mod_name, flag)

    def _check_module_mksa(self):
        flag = self.check_header("gsl/gsl_const_mksa.h")
        self._handle_found_module("const_mksa", flag)

    def _check_module_cgsm(self):
        flag = self.check_header("gsl/gsl_const_cgsm.h")
        self._handle_found_module("const_cgsm", flag)

    def _check_module_mks(self):
        flag = self.check_header("gsl/gsl_const_mks.h")
        self._handle_found_module("const_mks", flag)

    def _check_module_cgs(self):
        flag = self.check_header("gsl/gsl_const_cgs.h")
        self._handle_found_module("const_cgs", flag)

    def _check_module_deriv(self):
        flag = self.check_func("gsl_deriv_central", headers=("gsl/gsl_deriv.h",))
        self._handle_found_module("deriv", flag)

    def _check_module_multifit_robust(self):
        flag = self.check_func("gsl_multifit_robust_type", headers=("gsl/gsl_multifit.h",))
        self._handle_found_module("multifit_robust", flag)

    def _check_module_bspline(self):
        flag = self.check_header("gsl/gsl_bspline.h")
        self._handle_found_module("bspline", flag)

    def _check_module_odeiv2(self):

        header = "gsl/gsl_odeiv2.h"
        flag = self.check_header(header)
        self._handle_found_module("odeiv2", flag)

        flag = self.check_func("gsl_odeiv2_driver_reset_hstart", headers = [header])
        self._add_header_variables_dict("_PYGSL_GSL_HAS_ODEIV2_DRIVER_RESET_HSTART", flag)


    def _check_sparse(self):
        flag = self.check_header("gsl/gsl_spmatrix.h")
        self._handle_found_module("spmatrix", flag)

    def _check_module_wavelet(self):
        flag = self.check_header("gsl/gsl_wavelet.h")
        self._handle_found_module("wavelet", flag)

    def _check_module_interp2d(self):
        logger.debug("Checking for interpolation 2d ....")
        # At least on msys the missing header is not detected that way ...
        #flag = self.check_header("gsl/gsl_interp2d.h")
        flag = self.check_func("gsl_interp2d_type", headers=("gsl/gsl_interp2d.h",))
        logger.debug("interpolation 2d  available? " + (flag and "Yes" or "No"))
        self._handle_found_module("interp2d", flag)

    def _check_multimin_solvers(self):
        headers = ["gsl/gsl_multimin.h"]

        flag = self.check_func("gsl_multimin_fsolver",      headers = headers)
        self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIMIN_FSOLVER", flag)

        flag = self.check_func("gsl_multimin_fminimizer_nmsimplex",      headers = headers)
        self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIMIN_FMINIMIZER_NMSIMPLEX", flag)

        flag = self.check_func("gsl_multimin_fminimizer_nmsimplex2",     headers = headers)
        self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIMIN_FMINIMIZER_NMSIMPLEX2", flag)

        flag = self.check_func("gsl_multimin_fminimizer_nmsimplex2rand", headers = headers)
        self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIMIN_FMINIMIZER_NMSIMPLEX2RAND", flag)

        flag = self.check_func("gsl_multimin_fdfminimizer_vector_bfgs2", headers = headers)
        self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIMIN_FDFMINIMIZER_VECTOR_BFGS2", flag)

        # XXX Check if it has not been removed by later versions
        #flag = self.check_func("gsl_multimin_fdfminimizer_vector_steepest_descent", headers = headers)
        #self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIMIN_FDFMINIMIZER_STEEPEST_DESCENT", flag)

    def _check_multifit_nlin_lmniel(self):
        flag = self.check_func("gsl_multifit_fdfsolver_lmniel", headers=["gsl/gsl_multifit_nlin.h",] )
        self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIFIT_FDFSOLVER_LMNIEL", flag)

    def _check_multifit_nlin_jacobian(self):
        """
        GSL 1. had a jacobian in the type struct
        since version 2 a separate function is provided.

        PyGSL always provided a method, thus no interface change for pygsl is
        required
        """
        headers = ["gsl/gsl_multifit_nlin.h"]

        flag = self.check_func("gsl_multifit_fdfsolver_jac", headers = headers)
        self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIFIT_NLIN_FDFSOLVER_JAC", flag)

        flag = self.check_func("((gsl_multifit_fdfsolver *) 0)->J", headers = headers)
        self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIFIT_NLIN_FDFSOLVER_STRUCT_MEMBER_J", flag)

    def _check_multifit_linear_workspace(self):
        """
        GSL 2.0 changed the workspace struct members
        """
        headers = ["gsl/gsl_multifit.h"]

        flag_nmax = self.check_func("((gsl_multifit_linear_workspace *) 0)->nmax", headers = headers)
        flag_pmax = self.check_func("((gsl_multifit_linear_workspace *) 0)->pmax", headers = headers)

        flag = False
        if flag_nmax:
            # Should be that way
            assert(flag_pmax)
            flag = True

        self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_NMAX_PMAX", flag)
        del flag, flag_nmax, flag_pmax

        flag = False
        flag_n = self.check_func("((gsl_multifit_linear_workspace *) 0)->n", headers = headers)
        flag_p = self.check_func("((gsl_multifit_linear_workspace *) 0)->p", headers = headers)
        if flag_n:
            # Should be that way
            assert(flag_p)
            flag = True

        self._add_header_variables_dict("_PYGSL_GSL_HAS_MULTIFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_N_P", flag)
        del flag, flag_n, flag_p

    def _check_and_flag_method(self, method_name, headers):
        cpp_define = "_PYGSL_GSL_HAS_"
        cpp_define += method_name.upper()

        flag = self.check_func(method_name, headers)
        self._add_header_variables_dict(cpp_define, flag)

    def _check_permutation(self):
        headers = ["gsl/gsl_permutation.h"]

        methods = (
            "linear_to_canonical",
            "canonical_to_linear",
            "inversions",
            "canonical_cycles",
            "linear_cycles",
            "mul",
            )

        for method in methods:
            name = "gsl_permutation_" + method
            self._check_and_flag_method(name, headers)

    def _check_linalg(self):
        headers = ["gsl/gsl_linalg.h"]

        funcs =(
            "complex_householder_mh",
            "hessenberg_decomp",
            "hessenberg_unpack",
            "hessenberg_unpack_accum",
            "hessenberg_set_zero",
            "hessenberg_submatrix",
            "hessenberg",
            "hesstri_decomp",
            "SV_leverage",
            "QR_QTmat",
            "QR_matQ",
            "cholesky_invert",
            "complex_cholesky_decomp",
            "complex_cholesky_solve",
            "complex_cholesky_svx",
            "complex_cholesky_invert",
            "balance_matrix",
            "balance_accum",
            )

        for func in funcs:
            name = "gsl_linalg_" + func
            self._check_and_flag_method(name, headers)

    def _check_eigen(self):
        headers = ["gsl/gsl_eigen.h"]

        funcs =(
            "francis_workspace",
            "nonsymm_params",
            )
        for func in funcs:
            name = "gsl_eigen_" + func
            self._check_and_flag_method(name, headers)

    def _check_rngs(self):
        flag = self.check_func("gsl_rng_knuthran2002", headers=("gsl/gsl_rng.h",))
        self._add_header_variables_dict("_PYGSL_GSL_HAS_RNG_KNUTHRAN2002", flag)

    def _check_sf(self):

        headers = ["gsl/gsl_sf.h",]
        funcs = (
            "legendre_Plm_array",
            "legendre_sphPlm_array",
            )

        # Defined in the header files but does not necessarly exist
        # thus we have to link ....
        # for func in funcs:
        #    name = "gsl_sf_" + func
        #    self._check_and_flag_method(name, headers)
        # qreturn

        for func in funcs:
            method_name = "gsl_sf_" + func
            cpp_define = "_PYGSL_GSL_HAS_LINK_"
            cpp_define += method_name.upper()

            method_name += "(0, 0, 0.0, NULL)"
            flag = self.check_func(method_name, headers)
            self._add_header_variables_dict(cpp_define, flag)


    def dump_gsl_config(self):

        header = """#
# -----------------------------------------------------------------------------
# Warning! Automatically generated file
# Edit %s instead!
# -----------------------------------------------------------------------------
""" % (__file__,)
        dirname = os.path.dirname(__file__)
        version = os.path.join(dirname, "gsl_version.py")
        info = self.gsl_location.dump_info()
        with open(version, "wt") as fp:
            fp.write(header)
            fp.write(info)


    def _gsl_location_get_gsl_version(self):
        info = self._gsl_config_version_info
        if info != None:
            return info

        tmp = self.gsl_location.get_gsl_version()
        assert(len(tmp) == 2)

        self._gsl_config_version_info = tmp
        return self._gsl_config_version_info


    def _check_gsl_major_minor_definition2(self):
        """Write GSL Major and minor definitions from preprocessor to file

        This way it can be ensured that the build process will use the  version
        information from the header files.

        There can be always a mismatch...

        Warning:
            Will not work if the current directory is not in $PATH. Thus it is
            not used by default.

        Todo:
            Seems to work on windows. perhaps to use it there
        """

        config_file = os.path.join(self._pygsl_dir, "gsl_dist", "gsl_version_from_c_header.py")
        config_file = os.path.abspath(config_file)
        logger.info("GSL version config file at %s" %(config_file,))

        body = r"""
        int main(int argc, char * argv[])
        {
            FILE *fp = NULL;
            const char config_file[] = "%s";


            printf("Writing GSL Versions from <gsl/gsl_version.h> to %%s\n", config_file);
            fp = fopen(config_file, "wt");
            if(fp == NULL){
                perror("Failed to open config file:");
                exit(1);
            }
            fprintf(fp, "gsl_version = \"%%s\"\n", GSL_VERSION);
            #ifdef GSL_MAJOR_VERSION
                fprintf(fp, "gsl_major_minor =  %%d, %%d\n", GSL_MAJOR_VERSION, GSL_MINOR_VERSION);
            #endif /* GSL_MAJOR_VERSION */
            fflush(fp);
            fclose(fp);
            printf("Wrote gsl_verskon %%s to config file %%s\n", GSL_VERSION, config_file);
            return 0;
        }
        """ % (config_file.replace('\\', '\\\\'),)

        kws = {}
        kws = self._handle_include_dir_kw(kws)
        kws = self._handle_library_dir_kw(kws)
        kws = self._handle_libraries_kw(kws)

        self.try_run(headers = ["stdio.h", "gsl/gsl_version.h"], body=body, **kws)

    def _check_gsl_major_minor_definition(self):
        """Returns the version gsl as typically found from gsl_config

        Todo:
            On windows the user is asked to set this version in
            gsl_dist/gsl_site.py by hand. THus it would be more
            advisable to use the preprocessor info available which
            is stored in gsl_dist/gsl_version.py?
        """
        headers = ["gsl/gsl_version.h"]

        major = "GSL_MAJOR_VERSION"
        minor = "GSL_MINOR_VERSION"

        major_minor_available = 0

        info = self.gsl_location.get_gsl_version()

        flag = self.check_func(major, headers=headers)
        if flag:
            self._add_header_variables_dict("PYGSL_" + major, major)
            major_minor_available = 1
        else:
            self._add_header_variables_dict("PYGSL_" + major, info[0])

        flag = self.check_func(minor, headers=headers)
        if flag:
            if not major_minor_available:
                print("WARNINIG: GSL_MAJOR_VERSION not defined but GSL_MINOR VERSION defined?")
            self._add_header_variables_dict("PYGSL_" + minor, minor)
        else:
            self._add_header_variables_dict("PYGSL_" + minor, info[1])

        # Sometimes gsl_config is run (e.g. it is found in /usr/bin), but there
        # could be a second version installed (e.g. in /usr/local/) and the
        # compiler includes then /usr/local/include/ before /usr/include
        # So lets store the version information in the header file: could help
        # to track done some wired issues
        val = self.gsl_location.get_gsl_config_version()
        val = val.strip()
        self._add_header_variables_dict("PYGSL_GSL_CONFIG_GSL_VERSION", '"%s"' %(val,))

    def _check_swig(self):
        # Check for -builtin
        pass

    def _run_checks(self):
        self.dump_gsl_config()
        self._check_swig()

        self._check_gsl_major_minor_definition()
        self._check_gsl_major_minor_definition2()

        self._check_module_interp2d()
        self._check_module_multifit_robust()
        self._check_module_odeiv2()

        self._check_module_mksa()
        self._check_module_cgsm()
        self._check_module_mks()
        self._check_module_cgs()

        self._check_rngs()

        self._check_module_deriv()

        self._check_multifit_nlin_lmniel()
        self._check_multifit_nlin_jacobian()
        self._check_multifit_linear_workspace()
        self._check_multimin_solvers()

        self._check_module_wavelet()

        self._check_module_bspline()

        self._check_permutation()
        self._check_linalg()
        self._check_eigen()

        self._check_sf()
        self._check_sparse()

    def run(self):
        logger.info("Running config!")
        self._run_checks()
        self._write_module_config_file()
        self._write_header_config_file()
