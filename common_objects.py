from distutils import sysconfig
from gsl_Extension import gsl_Location
import os.path
# Shares objects needed by setup.py and setup_testing.py
gsl_inc_path =  os.path.join(gsl_Location.get_gsl_prefix(), "include")


libpygsl = ('pygsl', {'sources' : [#'Lib/general_helpers.c',
                                   #'Lib/complex_helpers.c',
                                   #'Lib/block_helpers.c',
                                   #'Lib/function_helpers.c',
                                   #'Lib/error_helpers.c',
                                   #'Lib/rng_helpers.c',
                                   'Lib/profile.c',
                                   'Lib/chars.c',
                                   ],
                      'include_dirs' : ['Include',
                                        sysconfig.get_python_inc(),
                                        gsl_inc_path],	
                      'shared' : 1,
                      }
            )


