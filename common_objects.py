from distutils import sysconfig
# Shares objects needed by setup.py and setup_testing.py
libpygsl = ('pygsl', {'sources' : ['Lib/general_helpers.c',
                                   'Lib/complex_helpers.c',
                                   'Lib/block_helpers.c',
                                   'Lib/function_helpers.c',
                                   'Lib/error_helpers.c',
                                   'Lib/rng_helpers.c',
                                   'Lib/profile.c',
                                   'Lib/chars.c',
                                   ],
                      'include_dirs' : ['Include',
                                        sysconfig.get_python_inc()],
                      'shared' : 1,
                      }
            )


