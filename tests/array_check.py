import pygsl
import pygsl._numobj
nummodule = pygsl._numobj
ArrayType = pygsl.ArrayType
get_typecode = pygsl.get_typecode

def myord_numeric(obj):
    return ord(obj)

def myord_numpy(obj):
    if obj == "":
        return 0
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
    shape = None
    #assert(type(array) == ArrayType)
    try:
        tmp = array.dtype
        if arraytype != None:
            assert(tmp == arraytype)

        if thesize != None:
            myshape = array.shape
            lsize = len(thesize)
            assert(len(myshape) == lsize)
            srange = list(range(lsize))
            test = 0
            try:
                for myi in srange:
                    assert(thesize[myi] == myshape[myi])
                test = 1
            finally:
                if test == 0:
                    print "lsize -->%s<-- type:%s srange -->%s<-- type:%s" %(lsize, type(lsize), srange, type(srange))
                    
                
        test = 1        
    finally:            
        if test == 0:
            print 
            print "Got an array of type", tmp,
            print "With type '%s' and shape '%s'" % (get_typecode(array), shape)
            print "Expected an array of ", ArrayType,
            print "With type '%s' and shape '%s'" % (arraytype, thesize)


    
