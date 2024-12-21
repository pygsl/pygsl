swig = find_program('swig')
swig_gen = generator(
    swig,
    output: ['@BASENAME@.c'],
    arguments: ['-python', '-py3', '-o', './@OUTPUT@',
                '-outdir', '.', '-I../src', '-MMD',
                '@INPUT@'],
    depfile: '@BASENAME@.d',
)