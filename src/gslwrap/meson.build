compiler = meson.get_compiler('c')


eigen_config = configuration_data({
    '_PYGSL_GSL_HAS_GSL_EIGEN_FRANCIS_WORKSPACE' : false,
    '_PYGSL_GSL_HAS_GSL_EIGEN_NONSYMM_PARAMS' : false
})

if compiler.has_header_symbol('gsl/gsl_eigen.h', 'gsl_eigen_francis_workspace')
    eigen_config.set('_PYGSL_GSL_EIGEN_FRANCIS_WORKSPACE', true)
endif
if compiler.has_header_symbol('gsl/gsl_eigen.h', 'gsl_eigen_nonsymm_params')
    eigen_config.set('_PYGSL_GSL_EIGEN_NONSYM_PARAMS', true)
endif

configure_file(output : 'pygsl_eigen_config.h',
    configuration : eigen_config
)


permutation_config = configuration_data({
  '_PYGSL_GSL_HAS_GSL_PERMUTATION_LINEAR_TO_CANONICAL'  : false,
  '_PYGSL_GSL_HAS_GSL_PERMUTATION_CANONICAL_TO_LINEAR' : false,
  '_PYGSL_GSL_HAS_GSL_PERMUTATION_INVERSIONS'  : false,
  '_PYGSL_GSL_HAS_GSL_PERMUTATION_LINEAR_CYCLES' : false,
  '_PYGSL_GSL_HAS_GSL_PERMUTATION_CANONICAL_CYCLES' : false,
  '_PYGSL_GSL_HAS_GSL_PERMUTATION_MUL' : false,
})

if compiler.has_header_symbol('gsl/gsl_permutation.h', 'gsl_permutation_linear_to_canonical')
    permutation_config.set('_PYGSL_GSL_HAS_GSL_PERMUTATION_LINEAR_TO_CANONICAL', true)
endif
if compiler.has_header_symbol('gsl/gsl_permutation.h', 'gsl_permutation_canonical_to_linear')
    permutation_config.set('_PYGSL_GSL_HAS_GSL_PERMUTATION_CANONICAL_TO_LINEAR', true)
endif
if compiler.has_header_symbol('gsl/gsl_permutation.h', 'gsl_permutation_inversions')
    permutation_config.set('_PYGSL_GSL_HAS_GSL_PERMUTATION_INVERSIONS', true)
endif
if compiler.has_header_symbol('gsl/gsl_permutation.h', 'gsl_permutation_linear_cycles')
    permutation_config.set('_PYGSL_GSL_HAS_GSL_PERMUTATION_LINEAR_CYCLES', true)
endif
if compiler.has_header_symbol('gsl/gsl_permutation.h', 'gsl_permutation_canonical_cycles')
    permutation_config.set('_PYGSL_GSL_HAS_GSL_PERMUTATION_CANONICAL_CYCLES', true)
endif

permutation_config = configure_file(output : 'pygsl_permutation_config.h',
    configuration : permutation_config,
    install : true,
    install_dir:py.get_install_dir() / 'Include' / 'pygsl'
)


linalg_config = configuration_data({
    '_PYGSL_GSL_LINALG_COMPLEX_HOUSEHOLDER_MH' : false,
    '_PYGSL_GSL_LINALG_HESSENBERG_DECOMP'  : false,
    '_PYGSL_GSL_LINALG_HESSENBERG_UNPACK'  : false,
    '_PYGSL_GSL_LINALG_HESSENBERG_UNPACK_ACCUM'  : false,
    '_PYGSL_GSL_LINALG_HESSENBERG_SET_ZERO'  : false,
    '_PYGSL_GSL_LINALG_HESSENBERG_SUBMATRIX'  : false,
    '_PYGSL_GSL_LINALG_HESSENBERG'  : false,
    '_PYGSL_GSL_LINALG_HESSTRI_DECOMP'  : false,
    '_PYGSL_GSL_LINALG_SV_LEVERAGE'  : false,
    '_PYGSL_GSL_LINALG_QR_QTMAT'  : false,
    '_PYGSL_GSL_LINALG_QR_MATQ'  : false,
    '_PYGSL_GSL_LINALG_CHOLESKY_INVERT'  : false,
    '_PYGSL_GSL_LINALG_COMPLEX_CHOLESKY_DECOMP'  : false,
    '_PYGSL_GSL_LINALG_COMPLEX_CHOLESKY_SOLVE'  : false,
    '_PYGSL_GSL_LINALG_COMPLEX_CHOLESKY_SVX'  : false,
    '_PYGSL_GSL_LINALG_COMPLEX_CHOLESKY_INVERT'  : false,
    '_PYGSL_GSL_LINALG_BALANCE_MATRIX'  : false,
    '_PYGSL_GSL_LINALG_BALANCE_ACCUM'  : false,
})

if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_complex_householder_mh')
    linalg_config.set('_PYGSL_GSL_LINALG_COMPLEX_HOUSEHOLDER_MH', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_hessenberg')
    linalg_config.set('_PYGSL_GSL_LINALG_HESSENBERG', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_hessenberg_decomp')
    linalg_config.set('_PYGSL_GSL_LINALG_HESSENBERG_DECOMP', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_hessenberg_unpack')
    linalg_config.set('_PYGSL_GSL_LINALG_HESSENBERG_UNPACK', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_hessenberg_unpack_accum')
    linalg_config.set('_PYGSL_GSL_LINALG_HESSENBERG_UNPACK_ACCUM', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_hessenberg_set_zero')
    linalg_config.set('_PYGSL_GSL_LINALG_HESSENBERG_SET_ZERO', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_hessenberg_submatrix')
    linalg_config.set('_PYGSL_GSL_LINALG_HESSENBERG_SUBMATRIX', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_hesstri_decomp')
    linalg_config.set('_PYGSL_GSL_LINALG_HESSTRI_DECOMP', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_SV_leverage')
    linalg_config.set('_PYGSL_GSL_LINALG_SV_LEVERAGE', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_QR_QTmat')
    linalg_config.set('_PYGSL_GSL_LINALG_QR_QTMAT', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_QR_matQ')
    linalg_config.set('_PYGSL_GSL_LINALG_QR_MATQ', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_cholesky_invert')
    linalg_config.set('_PYGSL_GSL_LINALG_CHOLESKY_INVERT', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_complex_cholesky_decomp')
    linalg_config.set('_PYGSL_GSL_LINALG_COMPLEX_CHOLESKY_DECOMP', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_complex_cholesky_solve')
    linalg_config.set('_PYGSL_GSL_LINALG_COMPLEX_CHOLESKY_SOLVE', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_complex_cholesky_svx')
    linalg_config.set('_PYGSL_GSL_LINALG_COMPLEX_CHOLESKY_svx', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_complex_cholesky_invert')
    linalg_config.set('_PYGSL_GSL_LINALG_COMPLEX_CHOLESKY_INVERT', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_balance_matrix')
    linalg_config.set('_PYGSL_GSL_LINALG_BALANCE_MATRIX', true)
endif
if compiler.has_header_symbol('gsl/gsl_linalg.h', 'gsl_linalg_balance_accum')
    linalg_config.set('_PYGSL_GSL_LINALG_BALANCE_ACCUM', true)
endif

configure_file(output : 'pygsl_linalg_config.h',
    configuration: linalg_config
)

gslwrap_swig = custom_target('_gslwrap',
    output: [
        'gslwrap_wrap.c',
        'gslwrap.py',
    ],
    input: 'gsl_gslwrap.i',
    command: [swig, '-I../typemaps']  + swig_flags + [
              '-o', '@OUTPUT0@', '-outdir', '@OUTDIR@', '@INPUT@'],
    install: true,
    install_dir: py.get_install_dir() / 'pygsl',
    install_tag: 'python-runtime',
)

 py.extension_module(
  '_gslwrap',
  gslwrap_swig[0],
  dependencies : [gsl_dep],
  include_directories : inc_dirs,
  install: true,
  subdir: 'pygsl',
 )

 interp2d_swig = custom_target('interpolation2d',
    output: [
        'interpolation2d_wrap.c',
        'interpolation2d_wrap.py',
    ],
    input: 'interpolation2d.i',
    command: [swig, '-I../typemaps']  + swig_flags + [
              '-o', '@OUTPUT0@', '-outdir', '@OUTDIR@', '@INPUT@'],
    install: true,
    install_dir: py.get_install_dir() / 'pygsl',
    install_tag: 'python-runtime',
)

 py.extension_module(
  'interpolation2d_wrap',
  interp2d_swig[0],
  dependencies : [gsl_dep],
  include_directories : inc_dirs,
  install: true,
  subdir: 'pygsl',
 )