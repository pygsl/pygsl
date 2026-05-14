# test which interface it is
bspline_config = configuration_data({
   '_PYGSL_GSL_BSPLINE_WORKSPACE_HAS_N' : false,
})

if compiler.has_member('gsl_bspline_workspace', 'n', prefix: '#include <gsl/gsl_bspline.h>',  dependencies: [gsl_dep])
   bspline_config.set('_PYGSL_GSL_BSPLINE_WORKSPACE_HAS_N', true)
   swig_mods += [{'inc_dir': include_directories('.'), 'src': files('bspline.i')[0], 'tgt': 'bspline'}]
else
   swig_mods += [{'inc_dir': include_directories('.'), 'src': files('bspline.i')[0], 'tgt': 'bspline'}]
endif


bspline_config_output = configure_file(
    output : 'pgysl_bspline_config.h',
    configuration : bspline_config
)

# Todo: a better name for this configuration variable
bspline_config_output_py = configure_file(
   input : meson.current_source_dir() / 'bspline_config.py.in',
   output : 'bspline_config.py',
   configuration : configuration_data({
     'WORKSPACE_HAS_N' : bspline_config.get( '_PYGSL_GSL_BSPLINE_WORKSPACE_HAS_N') ? 'True' : 'False'
   })
)

install_data(bspline_config_output_py, install_dir:  py.get_install_dir() / 'pygsl' / 'cfg')
