compiler = meson.get_compiler('c')
rng_config = configuration_data({
    '_PYGSL_GSL_HAS_RNG_KNUTHRAN2002': false
})
if compiler.has_header_symbol('gsl/gsl_rng.h', 'gsl_rng_knuthran2002', dependencies: [gsl_dep])
    rng_config.set('_PYGSL_GSL_HAS_RNG_KNUTHRAN2002', true)
endif
configure_file(output: 'pygsl_rng_config.h',
    configuration : rng_config
)

py.extension_module(
  'rng',
  'rngmodule.c',
  dependencies : [gsl_dep],
  include_directories : inc_dirs,
  install: true,
  subdir: 'pygsl',
 )