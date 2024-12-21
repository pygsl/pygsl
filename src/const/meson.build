const_config = configuration_data({
  '_PYGSL_GSL_HAS_CONST_CGS'  : false,
  '_PYGSL_GSL_HAS_CONST_CGSM' : false,
  '_PYGSL_GSL_HAS_CONST_MKS'  : false,
  '_PYGSL_GSL_HAS_CONST_MKSA' : false,
})

compiler = meson.get_compiler('c')
if compiler.has_header('gsl/gsl_const_mksa.h')
  const_config.set('_PYGSL_GSL_HAS_CONST_MKSA', true)
endif
if compiler.has_header('gsl/gsl_const_cgsm.h')
  const_config.set('_PYGSL_GSL_HAS_CONST_CGSM', true)
endif
if compiler.has_header('gsl/gsl_const_mks.h')
  const_config.set('_PYGSL_GSL_HAS_CONST_MKS', true)
endif
if compiler.has_header('gsl/gsl_const_cgs.h')
  const_config.set('_PYGSL_GSL_HAS_CONST_CGS', true)
endif

configure_file(output : 'pygsl_const_config.h',
  configuration : const_config,
)

py.extension_module(
  'constmodule',
  'constmodule.c',
  install: true,
  include_directories : inc_dirs,
  subdir: 'pygsl',
 )