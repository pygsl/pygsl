project(
    'purelib-and-platlib',
    'c',
    default_options: [
    ],
)

py = import('python').find_installation(pure: false)

# - GSL Library --------------------------------------
# default directories
gsl_include_info = run_command('gsl-config',
   [ '--cflags'],
   check : true,
   capture : true,
).stdout().strip()

gsl_include = []
foreach token : gsl_include_info.split()
    if token.startswith('-I')
        gsl_include += token.replace('-I', '')
    endif
endforeach

gsl_lib_info = run_command('gsl-config',
   [ '--libs'],
   check : true,
   capture : true,
).stdout().strip()

gsl_ldpath = []
gsl_libs = []
foreach token : gsl_lib_info.split()
    if token.startswith('-L')
        gsl_ldpath += token.replace('-L', '')
    endif
    if token.startswith('-l')
        gsl_libs += token.replace('-l', '')
    endif
endforeach

message('gsl: include path(s)', gsl_include)
message('gsl: ld path(s)', gsl_ldpath)
message('gsl: libs', gsl_libs)
# - END GSL Library ------------------------------------
swig_typemaps_dir = include_directories('typemaps')
swig = 'swig4.0'
swig_flags = ['-python', '-builtin', '-O', '-Wall']
# fix this hack ...
swig_flags += ['-I' + gsl_include[0] ]
# - END swig-------- ------------------------------------

# - more elegant manner for dealing with numpy path ?----
numpy_include = run_command(py,
  ['-c', 'import os; os.chdir(".."); import numpy; print(numpy.get_include())'],
  check : true
).stdout().strip()

#--------------------------------------------------------
inc_dirs = include_directories(
    gsl_include,
    numpy_include,
    'Include',
    # some need headers from typemaps and include it over
    # <typemape/>
    '.',
 )
# for config
gsl_inc_dir = include_directories(gsl_include)

# need to build the proto generated files before
# I can build the cython extension
subdir('src')
# subdir('pygsl')