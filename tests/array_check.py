from __future__ import print_function
import pygsl
import pygsl._numobj
import pygsl.errors as errors
nummodule = pygsl._numobj
ArrayType = pygsl.ArrayType
get_typecode = pygsl.get_typecode

def myord_numeric(obj):
    return ord(obj)

def myord_numpy(obj):
    if obj == "":
        return 0
    if len(obj) == 0:
        raise ValueError("Object length 0")

    return ord(obj)


def myord_default(obj):
    """
    Numarray stores character arrays as integers.
    So to avoid switching I put it here
    """
    return obj

def myorda_default(obj):
    return myord(obj)


def myorda_numeric(obj):
    return myord(obj[0])

if nummodule.nummodule == "Numeric":
    myord = myord_numeric
    myorda = myorda_numeric
elif nummodule.nummodule == "numpy":
    myord = myord_numpy
    myorda = myorda_default
else:
    myord = myord_default
    myorda = myorda_default
    
def array_check(array, arraytype=None, thesize=None):
    """
    Check if the array is as expected
    """
    test = 0
    myshape = None

    try:
        dtype = array.dtype
        if arraytype != None:
            assert(dtype == arraytype)

        if thesize != None:
            myshape = array.shape
            lsize = len(thesize)
            assert(len(myshape) == lsize)
            srange = tuple(range(lsize))
            for cnt in srange:
                dim_target = thesize[cnt]
                dim_found  = myshape[cnt]
                if dim_target == dim_found:
                    continue

                msg = "cnt %d, lsize '%s' type:%s srange: '%s' type:%s dims %s; dim_target = %s, dim_found =%s"
                msg = msg % (cnt, lsize, type(lsize), srange, type(srange), myshape, dim_target, dim_found)
                raise errors.gsl_BadLength(msg)
                    
                
        test = 1        
    finally:            
        if test == 0:
            print("Got an array of type '%s' with type '%s' and shape '%s'"
                  % (dtype, get_typecode(array), myshape))
            print("Expected an array of '%s' with type '%s' and shape '%s'"
                  % (ArrayType, arraytype, thesize))


    
