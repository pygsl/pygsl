#!/usr/bin/env python
"""Currently no control when SWIG will be run.
"""
from gsl_Extension import gsl_Extension#, gsl_Location
from distutils.util import spawn
from distutils.dep_util import newer_group
from distutils.file_util import copy_file

import os.path
import sys
import re
import string
remove_underscore=re.compile("_*(.*)")

swig_flags_default = ['-python', '-keyword', '-shadow', '-Itypemaps', 
                      # faster wrappers ... requires python 2.5 or greater
                      #'-builtin', 
                      #'-cpperraswarn',
                      ]

class SWIG_Extension(gsl_Extension):
    def __init__(self, name, sources,
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
                 swig_include_dirs=[],
                 swig_dependencies=[],
                 swig_flags=None,
                 swig_extra_flags = None,
                 c_dir=None,
                 py_dir=None,
                 gsl_configurable_module=None,
                 ):


        # Make the target of the swig wrapper out of the name and the c_dir
        target = name + "_wrap.c"
        
        # In the old makefile the leading underscore was not taken into account.
        # I will stick to that.
        
        m = remove_underscore.match(target)
        if len(m.groups()) >= 1:
            target = m.groups()[0]
        if c_dir:
            target = c_dir + "/" + target

        self.swig_include_dirs = swig_include_dirs
        if swig_flags is None:
            swig_flags = swig_flags_default

        if swig_extra_flags:
            swig_flags = swig_flags + swig_extra_flags
            
        self.swig_flags = swig_flags
        self._run_swig_args = sources, swig_dependencies, target,  swig_flags, py_dir, c_dir, name 

        #spawn(cmd, search_path, verbose, dry_run)
        # SWIG generates two files. A py proxy file and a .so. The so appends a _ to the module name.
        t_dirs, t_name = self._split_name_to_file_and_dir(name)
        t_name = '_' + t_name
        t_path = '.'.join(t_dirs)
        if t_path == '':
            t_path = t_name
        else:
            t_path = t_path + '.' + t_name
        #fmt = "c_dir %s c_target %s name %s -> (%s,%s) target %s"
        #print(fmt %(c_dir, target, name, t_dirs, t_name, t_path))
        del name

        gsl_Extension.__init__(self, t_path, [target,],
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
                               gsl_configurable_module=gsl_configurable_module,
            )
        return

    def _split_name_to_file_and_dir(self, name):
        """Addaption to build swig generated extensions not in the root directory
        """
        t_dirs = []
        if "." in name:
            tmp = name.split('.')
            t_dirs = tmp[:-1]
            t_name = tmp[-1]
        else:
            t_name = name
        return t_dirs, t_name

    def _run_swig(self, sources, swig_dependencies, target, swig_flags, py_dir, c_dir, name):
        """

        Todo:
            check if numpy or setuptools provide facilities for storing swig files
        """
        if newer_group(sources + swig_dependencies, target):


            includes = []
            for i in self.swig_include_dirs:
                includes.append('-I' + i)

            for i in self.gsl_location.get_gsl_include_dirs():
                includes.append('-I' + i)
                
            t_swig_flags = self.swig_flags
            cmd = [self.gsl_location.get_swig(),] + t_swig_flags + includes
            cmd.extend(['-o', target] + sources)
            sys.stderr.write(" ".join(cmd) + "\n")
            spawn(cmd, 1, 1)
            t_dirs, t_name = self._split_name_to_file_and_dir(name)
            del name

            src = t_name + '.py'
            if c_dir:
                src = c_dir + "/" + src
            #dst = '/'.join(t_dirs) + '/' + t_name
            dst = "."
            if py_dir:
                dst = py_dir + "/" +"/".join(t_dirs) + "/"
            dst_name, was_copied = copy_file(src, dst)
            # print("Copied file '%s' to '%s' ? %s dst was %s" %(src, dst_name, was_copied, dst))
            assert(was_copied == True)

    def runSourceGenerator(self):
        self._run_swig(*self._run_swig_args)


class SWIG_Extension_Nop(SWIG_Extension):
    """
    Do not build swig
    """
    def _run_swig(self, sources, swig_dependencies, target, swig_include_dirs, py_dir, c_dir, name):
        pass



