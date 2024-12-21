subdir('init')
subdir('callback')
subdir('gslwrap')
subdir('const')
subdir('poly')
subdir('rng')
subdir('statistics')
subdir('transform')

py.extension_module(
  'errortest',
  'errortestmodule.c',
  install: true,
  include_directories : inc_dirs,
  subdir: 'pygsl',
 )

 py.extension_module(
  'ieee',
  'ieeemodule.c',
  install: true,
  include_directories : inc_dirs,
  subdir: 'pygsl',
 )

compiler = meson.get_compiler('c')
pygsl_config = configuration_data({
    '_PYGSL_GSL_HAS_DERIV' : false
})
if compiler.has_header('gsl/gsl_deriv.h')
  pygsl_config.set('_PYGSL_GSL_HAS_DERIV', true)
endif
configure_file(output : 'pygsl_deriv_config.h',
  configuration : pygsl_config,
)

py.extension_module(
  'deriv',
  'derivmodule.c',
  install: true,
  include_directories : inc_dirs,
  subdir: 'pygsl',
 )

py.extension_module(
  '_qrng',
  'qrng_module.c',
  install: true,
  include_directories : inc_dirs,
  subdir: 'pygsl',
 )

 py.extension_module(
  'siman',
  'simanmodule.c',
  install: true,
  include_directories : inc_dirs,
  subdir: 'pygsl',
 )