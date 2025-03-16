compiler = meson.get_compiler('c')

symbols = [
    'gsl_eigen_francis_workspace',
    'gsl_eigen_nonsymm_params',
]
d = {}
foreach symbol: symbols
    d += {symbol.underscorify().to_upper() : false}
endforeach
eigen_config = configuration_data(d)

foreach symbol: symbols
    eigen_config.set(
        '_PYGSL_GSL_HAS_' + symbol.underscorify().to_upper(),
        compiler.has_header_symbol('gsl/gsl_eigen.h', symbol,  dependencies: [gsl_dep])
    )
endforeach
configure_file(output : 'pygsl_eigen_config.h',
    configuration : eigen_config
)

symbols = [
    'gsl_permutation_linear_to_canonical',
    'gsl_permutation_canonical_to_linear',
    'gsl_permutation_inversions',
    'gsl_permutation_canonical_cycles',
    'gsl_permutation_linear_cycles'
]
d = {}
foreach symbol: symbols
    d += {symbol.underscorify().to_upper() : false}
endforeach
permutation_config = configuration_data(d)
foreach symbol: symbols
    permutation_config.set(
        '_PYGSL_GSL_HAS_' + symbol.underscorify().to_upper(),
        compiler.has_header_symbol('gsl/gsl_permutation.h', symbol, dependencies: [gsl_dep])
    )
endforeach

permutation_config = configure_file(output : 'pygsl_permutation_config.h',
    configuration : permutation_config,
    install : true,
    install_dir:py.get_install_dir() / 'Include' / 'pygsl'
)



symbols = [
    'gsl_linalg_complex_householder_mh',
    'gsl_linalg_hessenberg',
    'gsl_linalg_hessenberg_decomp',
    'gsl_linalg_hessenberg_unpack',
    'gsl_linalg_hessenberg_unpack_accum',
    'gsl_linalg_hessenberg_set_zero',
    'gsl_linalg_hessenberg_submatrix',
    'gsl_linalg_hesstri_decomp',
    'gsl_linalg_SV_leverage',
    'gsl_linalg_QR_QTmat',
    'gsl_linalg_cholesky_invert',
    'gsl_linalg_complex_cholesky_decomp',
    'gsl_linalg_complex_cholesky_solve',
    'gsl_linalg_complex_cholesky_svx',
    'gsl_linalg_complex_cholesky_invert',
    'gsl_linalg_balance_matrix',
    'gsl_linalg_balance_accum',
]
foreach symbol: symbols
    d += {symbol.underscorify().to_upper() : false}
endforeach
linalg_config = configuration_data(d)
foreach symbol: symbols
    linalg_config.set(
        '_PYGSL_GSL_HAS_' + symbol.underscorify().to_upper(),
        compiler.has_header_symbol('gsl/gsl_linalg.h', symbol,  dependencies: [gsl_dep])
    )
endforeach

configure_file(output : 'pygsl_linalg_config.h',
    configuration: linalg_config
)
swig_mods += [
    {'inc_dir': include_directories('.'), 'src': files('gsl_gslwrap.i')[0], 'tgt': 'gslwrap'},
    {'inc_dir': include_directories('.'), 'src': files('interpolation2d.i')[0], 'tgt': 'interpolation2d_wrap'},
]
