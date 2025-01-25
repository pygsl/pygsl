sum_swig = custom_target('_poly',
    output: [
        'sum_wrap.c',
        'sum.py',
    ],
    input: 'gsl_sum.i',
    command: [swig, '-python', '-I../typemaps']  + [
              '-o', '@OUTPUT0@', '-outdir', '@OUTDIR@', '@INPUT@'],
    install: true,
    install_dir: py.get_install_dir() / 'pygsl',
    install_tag: 'python-runtime',
)

py.extension_module(
  '_sum',
  sum_swig[0],
  dependencies : [gsl_dep],
  include_directories : inc_dirs,
  install: true,
  subdir: 'pygsl',
 )
