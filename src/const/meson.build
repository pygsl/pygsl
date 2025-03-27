headers = [
  'const_cgs',
  'const_cgsm',
  'const_mks',
  'const_mksa'
]
d = {}
foreach header: headers
    d += { '_PYGSL_GSL_HAS_'+ header.underscorify().to_upper() : false}
endforeach
const_config = configuration_data(d)

compiler = meson.get_compiler('c')

foreach header: headers
    const_config.set(
        '_PYGSL_GSL_HAS_' + header.underscorify().to_upper(),
        compiler.has_header('gsl/gsl_' + header + '.h', dependencies: [gsl_dep])
    )
endforeach

configure_file(output : 'pygsl_const_config.h',
  configuration : const_config,
)

py.extension_module(
  'const',
  'constmodule.c',
  dependencies : [gsl_dep],
  install: true,
  include_directories : inc_dirs,
  subdir: 'pygsl',
 )