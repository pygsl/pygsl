project(
    'purelib-and-platlib',
    'c',
    default_options: [
    ],
)

compiler = meson.get_compiler('c')
swig = 'swig4.0'

py = import('python').find_installation(pure: false)


# - GSL Library -----------------------------------------
gsl_dep = dependency('gsl')
gsl_includedir = gsl_dep.get_variable('includedir')
message('gsl: include path(s)', gsl_includedir)
# - END GSL Library -------------------------------------
swig_typemaps_dir = include_directories('typemaps')
swig_flags = ['-python', '-keyword', '-builtin', '-O', '-Wall']
swig_flags += ['-I' + gsl_includedir ]
# - END swig-------- ------------------------------------

# - more elegant manner for dealing with numpy path ?----
# todo: current implementation does not permit
# non local wheels
numpy_include = run_command(py,
  ['-c', 'import os; os.chdir(".."); import numpy; print(numpy.get_include())'],
  check : true
).stdout().strip()

#--------------------------------------------------------
inc_dirs = include_directories(
    numpy_include,
    'Include',
    # some need headers from typemaps and include it over
    # <typemape/>
    '.',
 )
#--------------------------------------------------------

subdir('Include')
subdir('pygsl')
subdir('src')
subdir('testing')
