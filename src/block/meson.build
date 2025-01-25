block_swig = custom_target('block',
    output: [
        'block_wrap.c',
        '_block.py',
    ],
    input: 'gsl_block.i',
    command: [swig, '-I../typemaps']  + swig_flags + [
            '-o', '@OUTPUT0@', '-outdir', '@OUTDIR@', '@INPUT@'],
    install: true,
    install_dir: py.get_install_dir() / 'pygsl',
    install_tag: 'python-runtime'
)
 py.extension_module(
    '__block',
    block_swig[0],
    dependencies : [gsl_dep],
    include_directories : inc_dirs,
    install: true,
    subdir: 'pygsl',
)
