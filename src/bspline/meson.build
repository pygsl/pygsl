# test which interface it is
bspline_config = configuration_data({
    '_PYGSL_GSL_BSPLINE_WORSPACE_HAS_N' : false,
})

if compiler.has_member('gsl_bspline_workspace', 'n', prefix: '#include <gsl/gsl_bspline.h>',  dependencies: [gsl_dep])
   bspline_config.set('_PYGSL_GSL_BSPLINE_WORSPACE_HAS_N', true)
   swig_mods += [{'inc_dir': include_directories('.'), 'src': files('bspline.i')[0], 'tgt': 'bspline'}]
endif

bspline_config_output = configure_file(
   output : 'bspline_config.py',
   configuration : bspline_config
)
install_data(bspline_config_output, install_dir:  py.get_install_dir() / 'pygsl' / 'cfg')
