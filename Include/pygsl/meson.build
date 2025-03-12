#--------------------------------------------------------
# todo: how to handle global config
pygsl_config = configuration_data({
  'PyGSL_SET_GSL_ERROR_HANDLER' : false,
  'GSL_DISABLE_DEPRECATED' : true,
  'DEBUG' : 1
})

pygsl_config = configure_file(output : 'pygsl_config.h',
    configuration : pygsl_config,
    install : true,
    install_dir:py.get_install_dir() / 'Include' / 'pygsl'
)
