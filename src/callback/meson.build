compiler = meson.get_compiler('c')

multimin_config = configuration_data({
  '_PYGSL_GSL_HAS_MULTIMIN_FSOLVER'  : false,
  '_PYGSL_GSL_HAS_MULTIMIN_FMINIMIZER_NMSIMPLEX' : false,
  '_PYGSL_GSL_HAS_MULTIMIN_FMINIMIZER_NMSIMPLEX2'  : false,
  '_PYGSL_GSL_HAS_MULTIMIN_FMINIMIZER_NMSIMPLEX2RAND' : false,
  '_PYGSL_GSL_HAS_MULTIMIN_FMINIMIZER_VECTOR_BFGS2' : false,
})

if compiler.has_header_symbol('gsl/gsl_multimin.h', 'gsl_multimin_fsolver')
    multimin_config.set('_PYGSL_GSL_HAS_MULTIMIN_FSOLVER', true)
endif

if compiler.has_header_symbol('gsl/gsl_multimin.h', 'gsl_multimin_fminimizer_nmsimplex')
    multimin_config.set('_PYGSL_GSL_HAS_MULTIMIN_NMSIMPLEX', true)
endif

if compiler.has_header_symbol('gsl/gsl_multimin.h', 'gsl_multimin_fminimizer_nmsimplex2')
    multimin_config.set('_PYGSL_GSL_HAS_MULTIMIN_NMSIMPLEX2', true)
endif

if compiler.has_header_symbol('gsl/gsl_multimin.h', 'gsl_multimin_fminimizer_nmsimplex2rand')
    multimin_config.set('_PYGSL_GSL_HAS_MULTIMIN_NMSIMPLEX2RAND', true)
endif

if compiler.has_header_symbol('gsl/gsl_multimin.h', 'gsl_multimin_fdfminimizer_vector_bfgs2')
    multimin_config.set('_PYGSL_GSL_HAS_MULTIMIN_VECTOR_BFGS2', true)
endif

configure_file(output : 'pygsl_multimin_config.h',
    configuration : multimin_config
)

multifit_nlin_config = configuration_data({
    '_PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_JAC' : false,
    '_PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_STRUCT_MEMBER_J' : false
})

if compiler.has_header_symbol('gsl/gsl_multifit_nlin.h', 'gsl_multifit_fdfsolver_jac')
    multifit_nlin_config.set('_PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_JAC', true)
else
    compiler.has_member('gsl_multifit_fdfsolver', 'J', include_directories: [gsl_inc_dir], prefix: '#include <gsl/gsl_multifit_nlin.h>', required: true)
    multifit_nlin_config.set('_PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_STRUCT_MEMBER_J', true)
endif

configure_file(output : 'pygsl_multifit_nlin_config.h',
    configuration : multifit_nlin_config
)

multifit_config = configuration_data({
   '_PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_NMAX_PMAX' : false,
   '_PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_N_P' : false
})

if compiler.has_member('gsl_multifit_linear_workspace', 'nmax', include_directories: [gsl_inc_dir], prefix: '#include <gsl/gsl_multifit.h>')
    compiler.has_member('gsl_multifit_linear_workspace', 'pmax', include_directories: [gsl_inc_dir], prefix: '#include <gsl/gsl_multifit.h>', required: true)
    multifit_config.set('_PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_NMAX_PMAX', true)
else
# warning ... if nmax exists n,p correspond to SVD matrix size
    compiler.has_member('gsl_multifit_linear_workspace', 'n', include_directories: [gsl_inc_dir], prefix: '#include <gsl/gsl_multifit.h>', required: true)
    compiler.has_member('gsl_multifit_linear_workspace', 'p', include_directories: [gsl_inc_dir], prefix: '#include <gsl/gsl_multifit.h>', required: true)
    multifit_config.set('_PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_N_P', true)
endif

configure_file(output : 'pygsl_multifit_config.h',
    configuration : multifit_config
)


callback_swig = custom_target('_callback',
    output: [
        'callback_wrap.c',
        '_callback.py',
    ],
    input: 'gsl_callback.i',
    command: [swig, '-I../typemaps']  + swig_flags + [
              '-o', '@OUTPUT0@', '-outdir', '@OUTDIR@', '@INPUT@'],
    install: true,
    install_dir: py.get_install_dir() / 'pygsl',
    install_tag: 'python-runtime',
)

 py.extension_module(
  '_callback',
  callback_swig[0],
  install: true,
  include_directories : inc_dirs,
  subdir: 'pygsl',
 )