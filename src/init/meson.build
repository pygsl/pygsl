py.extension_module(
  'errno',
  'errorno.c',
  install: true,
  include_directories : inc_dirs,
  subdir: 'pygsl',
 )

 py.extension_module(
  'init',
  'initmodule.c',
   install: true,
   include_directories : inc_dirs,
   dependencies : [gsl_dep],
   subdir: 'pygsl',
 )

 py.extension_module(
  'inittest',
  'inittestmodule.c',
  install: true,
  include_directories : inc_dirs,
  dependencies : [gsl_dep],
  subdir: 'pygsl',
 )