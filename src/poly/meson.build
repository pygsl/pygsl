swig = 'swig4.0'

poly_swig = custom_target('_poly',
    output: [
        'poly_wrap.c',
        '_poly.py',
    ],
    input: 'gsl_poly.i',
    command: [swig, '-python', '-I../typemaps']  + [
              '-o', '@OUTPUT0@', '-outdir', '@OUTDIR@', '@INPUT@'],
    install: true,
    install_dir: py.get_install_dir() / 'pygsl',  # need to install _poly.py
    install_tag: 'python-runtime',
)

 py.extension_module(
  '_poly',
  poly_swig[0],
  install: true,
  include_directories : inc_dirs,
  subdir: 'pygsl',
 )