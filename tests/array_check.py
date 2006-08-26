import pygsl
import pygsl._numobj
nummodule = pygsl._numobj
ArrayType = pygsl.ArrayType
    
get_typecode = pygsl.get_typecode

def myord_numeric(obj):
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
else:
    myord = myord_default
    myorda = myorda_default
    
def array_check(array, arraytype=None, size=None):
    test = 0
    shape = None
    assert(type(array) == ArrayType)
    try:
        if arraytype:
            assert(get_typecode(array) == arraytype)

        if size:
            shape = array.shape
            assert(len(shape) == len(size))
            for i in range(len(size)):
                assert(size[i] == shape[i])
                
        test = 1        
    finally:            
        if test == 0:
            print "Got an array of type", type(array)
            print "With type '%s' and shape '%s'" % (get_typecode(array), shape)
            print "Expected an array of ", ArrayType,
            print "With type '%s' and shape '%s'" % (arraytype, size)


    
