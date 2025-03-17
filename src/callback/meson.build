compiler = meson.get_compiler('c')

symbols = [
  'gsl_multimin_fsolver',
  'gsl_multimin_fminimizer_nmsimplex',
  'gsl_multimin_fminimizer_nmsimplex2',
  'gsl_multimin_fminimizer_nmsimplex2rand',
  'gsl_multimin_fminimizer_vector_bfgs2',
]

d = {}
foreach symbol: symbols
    d += {symbol.underscorify().to_upper() : false}
endforeach
multimin_config = configuration_data(d)
foreach symbol: symbols
    multimin_config.set(
        '_PYGSL_GSL_HAS_' + symbol.underscorify().to_upper(),
        compiler.has_header_symbol('gsl/gsl_multimin.h', symbol, dependencies: [gsl_dep])
    )
endforeach

configure_file(output : 'pygsl_multimin_config.h',
    configuration : multimin_config
)

multifit_nlin_config = configuration_data({
    '_PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_JAC' : false,
    '_PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_STRUCT_MEMBER_J' : false
})

if compiler.has_header_symbol('gsl/gsl_multifit_nlin.h', 'gsl_multifit_fdfsolver_jac',  dependencies: [gsl_dep])
    multifit_nlin_config.set('_PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_JAC', true)
else
    compiler.has_member('gsl_multifit_fdfsolver', 'J', prefix: '#include <gsl/gsl_multifit_nlin.h>', required: true,  dependencies: [gsl_dep])
    multifit_nlin_config.set('_PYGSL_GSL_HAS_MULTFIT_NLIN_FDFSOLVER_STRUCT_MEMBER_J', true)
endif

configure_file(output : 'pygsl_multifit_nlin_config.h',
    configuration : multifit_nlin_config
)

multifit_config = configuration_data({
   '_PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_NMAX_PMAX' : false,
   '_PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_N_P' : false
})

if compiler.has_member('gsl_multifit_linear_workspace', 'nmax', dependencies: [gsl_dep], prefix: '#include <gsl/gsl_multifit.h>')
    compiler.has_member('gsl_multifit_linear_workspace', 'pmax', dependencies: [gsl_dep], prefix: '#include <gsl/gsl_multifit.h>', required: true)
    multifit_config.set('_PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_NMAX_PMAX', true)
else
# warning ... if nmax exists n,p correspond to SVD matrix size
    compiler.has_member('gsl_multifit_linear_workspace', 'n', dependencies: [gsl_dep], prefix: '#include <gsl/gsl_multifit.h>', required: true)
    compiler.has_member('gsl_multifit_linear_workspace', 'p', dependencies: [gsl_dep], prefix: '#include <gsl/gsl_multifit.h>', required: true)
    multifit_config.set('_PYGSL_GSL_HAS_MULTFIT_LINEAR_WORKSPACE_STRUCT_MEMBER_N_P', true)
endif

configure_file(output : 'pygsl_multifit_config.h',
    configuration : multifit_config
)


swig_mods += [{ 'inc_dir' : include_directories('.'), 'src' : files('gsl_callback.i'), 'tgt' : '_callback'}]
cb_mods = ['multifit_robust', 'multilarge_nlinear',  'odeiv2']
foreach mod : cb_mods
    swig_mods += [{ 'inc_dir' : include_directories('.'), 'src' :  files('gsl_' + mod + '.i')[0], 'tgt' : mod}]
endforeach
