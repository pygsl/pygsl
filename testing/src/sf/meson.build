

sf_config = configuration_data({
 ' _PYGSL_GSL_HAS_SF_MATHIEU' : false,
 })

if compiler.has_header_symbol('gsl/gsl_sf_mathieu.h', 'gsl_sf_mathieu_ce')
    sf_config.set(' _PYGSL_GSL_HAS_SF_MATHIEU', true)
endif


configure_file(output : 'pygsl_sf_config.h',
    configuration : sf_config
)

sf_funcs_xml_fom_swig = custom_target('_sf_funcs_xml_from_swig',
    output: [
        '_sf_funcs_xml_from_swig.xml',
    ],
    input: 'sf.i',
    # todo: proper gsl_include
    command: [swig, '-xml', '-I../typemaps', '-I.','-I' + gsl_includedir ,
              '-o', '@OUTPUT0@',  '@INPUT@'],
)

#    	'sf__arrays.c'
sf_ufunc_wrappers = custom_target('_sf_ufuncs_wrappers',
    output: [
    	'sf__data.h',
    	'sf__evals.h',
#    	'sf__index.h',
    	'sf__objects.h'
    ],
    input: sf_funcs_xml_fom_swig[0],
    command: [py, '@CURRENT_SOURCE_DIR@' / '..' / '..' / 'tools' / 'generate_interface' / 'extract_ufunc_swig.py',
                  '--input', '@INPUT@',
		  '--output-dir', '@OUTDIR@',
		  '--prefix', 'sf_',
		  # todo: proper doc dir
		  '--doc-dir', '@OUTDIR@',
    ],
    install: true,
    install_dir: py.get_install_dir() / 'pygsl'/ 'sf' / 'src',
    install_tag: 'devel',
)

#


py.extension_module('_ufuncs',
     'sfmodule_testing.c',
      sf_ufunc_wrappers,
      dependencies : [gsl_dep],
      include_directories : inc_dirs,
     install: true,
     subdir: 'pygsl' / 'testing',
)