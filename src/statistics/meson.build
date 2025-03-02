py.extension_module(
  '_stat',
  '_statmodule.c',
  dependencies : [gsl_dep],
  include_directories : inc_dirs,
  install: true,
  subdir: 'pygsl' / 'statistics',
 )

type_modules = [
 'char',
 'uchar',
 'short',
 'int',
 'long',
 'float',
 'double',
]

foreach tm: type_modules
 py.extension_module(
    tm,
    tm + 'module.c',
    dependencies : [gsl_dep],
    include_directories : inc_dirs,
    install: true,
    subdir: 'pygsl' / 'statistics',
 )
endforeach
