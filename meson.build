project(
    'purelib-and-platlib',
    'c',
    default_options: [
    ],
    meson_version: '>=1.3.0'
)

compiler = meson.get_compiler('c')
swig = find_program('swig', required: true)

py = import('python').find_installation(pure: false)


# - GSL Library -----------------------------------------
gsl_dep = dependency('gsl')
gsl_includedir = gsl_dep.get_variable('includedir')
message('gsl: include path(s)', gsl_includedir)
# - END GSL Library -------------------------------------
swig_typemaps_dir = include_directories('typemaps')
swig_flags = ['-python', '-keyword', '-builtin', '-O', '-Wall']
swig_flags += ['-I' + gsl_includedir ]
# - END swig --------------------------------------------

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
    '.',
 )
# some need headers from typemaps and include it over
# <typemape/>

#--------------------------------------------------------
# install python modules
# function marked obsolete: need to find replacement
# subdir('pygsl')
install_subdir('pygsl', install_dir : py.get_install_dir())
foreach subdir : ['testing', 'statistics']
    install_subdir('pygsl' / subdir, install_dir : py.get_install_dir() / 'pygsl' / subdir)
endforeach
#--------------------------------------------------------
# to add swig specific stuff
swig_mods = []
#--------------------------------------------------------

subdir('Include')
subdir('src')
subdir('testing')

#--------------------------------------------------------
# build swig extension modules
# message('swig module', swig_mods)


foreach swig_mod: swig_mods
    message('building swig module', swig_mod.get('tgt'))
    swig_filename = swig_mod.get('src')
    c_src =  swig_mod.get('tgt') + '_swig_generated.c'
    py_tgt = swig_mod.get('tgt') + '.py'
    swig_created = custom_target(
        swig_mod.get('tgt'),
        output: [c_src, py_tgt],
        input: swig_filename,
        command: [swig, '-I../typemaps', '-Itypemaps']  + swig_flags + [
                 '-o', '@OUTPUT0@', '-outdir', '@OUTDIR@', '@INPUT@'],
        install: true,
        install_dir: [
            false, # py.get_install_dir() / 'pygsl' / 'generated' / 'swig_src',
            py.get_install_dir() / 'pygsl'
            ],
        install_tag: 'python-runtime',
    )
    py.extension_module(
        '_' + swig_mod.get('tgt'),
        swig_created[0],
        dependencies : [gsl_dep],
        include_directories : [inc_dirs, swig_mod.get('inc_dir'), include_directories('typemaps')],
        install: true,
        subdir: 'pygsl',
    )
endforeach
#--------------------------------------------------------
