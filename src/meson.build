subdir('init')
subdir('swig_test')
subdir('callback')
subdir('gslwrap')
subdir('block')
subdir('const')
subdir('poly')
subdir('rng')
subdir('statistics')
subdir('sum')
subdir('transform')
subdir('bspline')

compiler = meson.get_compiler('c')
pygsl_config = configuration_data({
    '_PYGSL_GSL_HAS_DERIV' : false
})
if compiler.has_header('gsl/gsl_deriv.h', dependencies: [gsl_dep])
  pygsl_config.set('_PYGSL_GSL_HAS_DERIV', true)
endif
configure_file(output : 'pygsl_deriv_config.h',
  configuration : pygsl_config,
)

# Assuming that deriv exists ...
# will single out first time user complains that deriv is not
# available in gsl installation
mods = ['errortest', 'ieee', 'deriv']
foreach mod : mods
    py.extension_module(
        mod,
        mod + 'module.c',
        dependencies : [gsl_dep],
        include_directories : inc_dirs,
        install: true,
        subdir: 'pygsl',
    )
endforeach

mods = ['qrng', 'siman']
foreach mod : mods
    py.extension_module(
        '_' + mod,
        mod + 'module.c',
        dependencies : [gsl_dep],
        include_directories : inc_dirs,
        install: true,
        subdir: 'pygsl',
    )
endforeach
