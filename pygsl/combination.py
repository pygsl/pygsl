# Author Pierre Schnizer
# Date 8. October 2003
"""
Wrapper for the combination.

Usage:

    Initalisation:
        c = Combination(n, k)

    Testing for validness:
        c.valid()
    returns 0 = GSL_SUCCESS if ok. Raises a gsl_DomainError if
    invalid.

    The gsl_combination_get is wrapped by:
       c.tolist() and c.toarray()
    Both will return the actual combination.   
       
    Stepping between the various combinations:
       c.prev()
       c.next()
    Both return 0 in case of success and -1 in case of failure.   
"""
import gslwrap
Combination = gslwrap.Combination
