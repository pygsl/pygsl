Special Functions as UFuncs
---------------------------

This chapter provides mainly NumPy UFuncs over the special functions.
This means that all input variable can be arrays, and the UFunc will
evaluate the gsl function for all its inputs. It is meant to replace the
sf module later; please use it and find out if it is useful for you.
Only the python specific part is described here. For a general
description of the function please see the GSL Reference document.

UFuncs
------

These UFuncs allow to evaluate an array of doubles or an array of floats
typically. Note that the return values of the functions ending with an
\_e are not turned to exceptions. Instead the error codes are returned
as an separate array. So if you are interested in them you have to do
check the error code yourself.

Chi...

Number of Input Arguments: 1 Number of Output Arguments: 1

Chi\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

Ci...

Number of Input Arguments: 1 Number of Output Arguments: 1

Ci\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

Shi...

Number of Input Arguments: 1 Number of Output Arguments: 1

Shi\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

Si...

Number of Input Arguments: 1 Number of Output Arguments: 1

Si\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

airy\_Ai...

Number of Input Arguments: 2 Number of Output Arguments: 1

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

airy\_Ai\_deriv...

Number of Input Arguments: 2 Number of Output Arguments: 1

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

airy\_Ai\_deriv\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 2
of the C argument list

airy\_Ai\_deriv\_scaled...

Number of Input Arguments: 2 Number of Output Arguments: 1

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

airy\_Ai\_deriv\_scaled\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 2
of the C argument list

airy\_Ai\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 2
of the C argument list

airy\_Ai\_scaled...

Number of Input Arguments: 2 Number of Output Arguments: 1

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

airy\_Ai\_scaled\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 2
of the C argument list

airy\_Bi...

Number of Input Arguments: 2 Number of Output Arguments: 1

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

airy\_Bi\_deriv...

Number of Input Arguments: 2 Number of Output Arguments: 1

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

airy\_Bi\_deriv\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 2
of the C argument list

airy\_Bi\_deriv\_scaled...

Number of Input Arguments: 2 Number of Output Arguments: 1

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

airy\_Bi\_deriv\_scaled\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 2
of the C argument list

airy\_Bi\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 2
of the C argument list

airy\_Bi\_scaled...

Number of Input Arguments: 2 Number of Output Arguments: 1

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

airy\_Bi\_scaled\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 2
of the C argument list

airy\_zero\_Ai...

Number of Input Arguments: 1 Number of Output Arguments: 1

airy\_zero\_Ai\_deriv...

Number of Input Arguments: 1 Number of Output Arguments: 1

airy\_zero\_Ai\_deriv\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

airy\_zero\_Ai\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

airy\_zero\_Bi...

Number of Input Arguments: 1 Number of Output Arguments: 1

airy\_zero\_Bi\_deriv...

Number of Input Arguments: 1 Number of Output Arguments: 1

airy\_zero\_Bi\_deriv\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

airy\_zero\_Bi\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

angle\_restrict\_pos...

Number of Input Arguments: 1 Number of Output Arguments: 1

angle\_restrict\_pos\_err\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

angle\_restrict\_symm...

Number of Input Arguments: 1 Number of Output Arguments: 1

angle\_restrict\_symm\_err\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

atanint...

Number of Input Arguments: 1 Number of Output Arguments: 1

atanint\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_I0...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_I0\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_I0\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_I0\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_I1...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_I1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_I1\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_I1\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_In...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_In\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_In\_scaled...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_In\_scaled\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_Inu...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_Inu\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_Inu\_scaled...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_Inu\_scaled\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_J0...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_J0\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_J1...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_J1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_Jn...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_Jn\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_Jnu...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_Jnu\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_K0...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_K0\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_K0\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_K0\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_K1...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_K1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_K1\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_K1\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_Kn...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_Kn\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_Kn\_scaled...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_Kn\_scaled\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_Knu...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_Knu\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_Knu\_scaled...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_Knu\_scaled\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_Y0...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_Y0\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_Y1...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_Y1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_Yn...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_Yn\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_Ynu...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_Ynu\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_i0\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_i0\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_i1\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_i1\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_i2\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_i2\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_il\_scaled...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_il\_scaled\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_j0...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_j0\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_j1...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_j1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_j2...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_j2\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_jl...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_jl\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_k0\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_k0\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_k1\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_k1\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_k2\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_k2\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_kl\_scaled...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_kl\_scaled\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_lnKnu...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_lnKnu\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_y0...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_y0\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_y1...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_y1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_y2...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_y2\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_yl...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_yl\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

bessel\_zero\_J0...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_zero\_J0\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_zero\_J1...

Number of Input Arguments: 1 Number of Output Arguments: 1

bessel\_zero\_J1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

bessel\_zero\_Jnu...

Number of Input Arguments: 2 Number of Output Arguments: 1

bessel\_zero\_Jnu\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

beta...

Number of Input Arguments: 2 Number of Output Arguments: 1

beta\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

beta\_inc...

Number of Input Arguments: 3 Number of Output Arguments: 1

beta\_inc\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

choose...

Number of Input Arguments: 2 Number of Output Arguments: 1

choose\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

clausen...

Number of Input Arguments: 1 Number of Output Arguments: 1

clausen\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

conicalP\_0...

Number of Input Arguments: 2 Number of Output Arguments: 1

conicalP\_0\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

conicalP\_1...

Number of Input Arguments: 2 Number of Output Arguments: 1

conicalP\_1\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

conicalP\_cyl\_reg...

Number of Input Arguments: 3 Number of Output Arguments: 1

conicalP\_cyl\_reg\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

conicalP\_half...

Number of Input Arguments: 2 Number of Output Arguments: 1

conicalP\_half\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

conicalP\_mhalf...

Number of Input Arguments: 2 Number of Output Arguments: 1

conicalP\_mhalf\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

conicalP\_sph\_reg...

Number of Input Arguments: 3 Number of Output Arguments: 1

conicalP\_sph\_reg\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

cos...

Number of Input Arguments: 1 Number of Output Arguments: 1

cos\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

cos\_err\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

coulomb\_CL\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

coulomb\_wave\_FG\_e...

Number of Input Arguments: 4 Number of Output Arguments: 10

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 4 of the C argument list Return
Arguments 3 and 4 resemble a gsl\_result argument, which is argument 5
of the C argument list Return Arguments 5 and 6 resemble a gsl\_result
argument, which is argument 6 of the C argument list Return Arguments 7
and 8 resemble a gsl\_result argument, which is argument 7 of the C
argument list

coupling\_3j...

Number of Input Arguments: 6 Number of Output Arguments: 1

coupling\_3j\_e...

Number of Input Arguments: 6 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 6 of the C argument list

coupling\_6j...

Number of Input Arguments: 6 Number of Output Arguments: 1

coupling\_6j\_e...

Number of Input Arguments: 6 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 6 of the C argument list

coupling\_9j...

Number of Input Arguments: 9 Number of Output Arguments: 1

coupling\_9j\_e...

Number of Input Arguments: 9 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 9 of the C argument list

coupling\_RacahW...

Number of Input Arguments: 6 Number of Output Arguments: 1

coupling\_RacahW\_e...

Number of Input Arguments: 6 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 6 of the C argument list

dawson...

Number of Input Arguments: 1 Number of Output Arguments: 1

dawson\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

debye\_1...

Number of Input Arguments: 1 Number of Output Arguments: 1

debye\_1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

debye\_2...

Number of Input Arguments: 1 Number of Output Arguments: 1

debye\_2\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

debye\_3...

Number of Input Arguments: 1 Number of Output Arguments: 1

debye\_3\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

debye\_4...

Number of Input Arguments: 1 Number of Output Arguments: 1

debye\_4\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

dilog...

Number of Input Arguments: 1 Number of Output Arguments: 1

dilog\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

doublefact...

Number of Input Arguments: 1 Number of Output Arguments: 1

doublefact\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

ellint\_D...

Number of Input Arguments: 4 Number of Output Arguments: 1

Argument 4 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

ellint\_D\_e...

Number of Input Arguments: 4 Number of Output Arguments: 2

Argument 4 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 4
of the C argument list

ellint\_E...

Number of Input Arguments: 3 Number of Output Arguments: 1

Argument 3 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

ellint\_E\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

Argument 3 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 3
of the C argument list

ellint\_Ecomp...

Number of Input Arguments: 2 Number of Output Arguments: 1

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

ellint\_Ecomp\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 2
of the C argument list

ellint\_F...

Number of Input Arguments: 3 Number of Output Arguments: 1

Argument 3 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

ellint\_F\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

Argument 3 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 3
of the C argument list

ellint\_Kcomp...

Number of Input Arguments: 2 Number of Output Arguments: 1

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

ellint\_Kcomp\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

Argument 2 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 2
of the C argument list

ellint\_P...

Number of Input Arguments: 4 Number of Output Arguments: 1

Argument 4 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

ellint\_P\_e...

Number of Input Arguments: 4 Number of Output Arguments: 2

Argument 4 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 4
of the C argument list

ellint\_RC...

Number of Input Arguments: 3 Number of Output Arguments: 1

Argument 3 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

ellint\_RC\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

Argument 3 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 3
of the C argument list

ellint\_RD...

Number of Input Arguments: 4 Number of Output Arguments: 1

Argument 4 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

ellint\_RD\_e...

Number of Input Arguments: 4 Number of Output Arguments: 2

Argument 4 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 4
of the C argument list

ellint\_RF...

Number of Input Arguments: 4 Number of Output Arguments: 1

Argument 4 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

ellint\_RF\_e...

Number of Input Arguments: 4 Number of Output Arguments: 2

Argument 4 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 4
of the C argument list

ellint\_RJ...

Number of Input Arguments: 5 Number of Output Arguments: 1

Argument 5 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX

ellint\_RJ\_e...

Number of Input Arguments: 5 Number of Output Arguments: 2

Argument 5 is a gsl\_mode\_t, valid parameters are: sf.PREC\_DOUBLE or
sf.PREC\_SINGLE or sf.PREC\_APPROX The error flag is discarded. Return
Arguments 1 and 2 resemble a gsl\_result argument, which is argument 5
of the C argument list

elljac\_e...

Number of Input Arguments: 2 Number of Output Arguments: 3

The error flag is discarded.

erf...

Number of Input Arguments: 1 Number of Output Arguments: 1

erf\_Q...

Number of Input Arguments: 1 Number of Output Arguments: 1

erf\_Q\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

erf\_Z...

Number of Input Arguments: 1 Number of Output Arguments: 1

erf\_Z\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

erf\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

erfc...

Number of Input Arguments: 1 Number of Output Arguments: 1

erfc\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

eta...

Number of Input Arguments: 1 Number of Output Arguments: 1

eta\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

eta\_int...

Number of Input Arguments: 1 Number of Output Arguments: 1

eta\_int\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

expint\_3...

Number of Input Arguments: 1 Number of Output Arguments: 1

expint\_3\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

expint\_E1...

Number of Input Arguments: 1 Number of Output Arguments: 1

expint\_E1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

expint\_E1\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

expint\_E1\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

expint\_E2...

Number of Input Arguments: 1 Number of Output Arguments: 1

expint\_E2\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

expint\_E2\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

expint\_E2\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

expint\_Ei...

Number of Input Arguments: 1 Number of Output Arguments: 1

expint\_Ei\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

expint\_Ei\_scaled...

Number of Input Arguments: 1 Number of Output Arguments: 1

expint\_Ei\_scaled\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

fact...

Number of Input Arguments: 1 Number of Output Arguments: 1

fact\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

fermi\_dirac\_0...

Number of Input Arguments: 1 Number of Output Arguments: 1

fermi\_dirac\_0\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

fermi\_dirac\_1...

Number of Input Arguments: 1 Number of Output Arguments: 1

fermi\_dirac\_1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

fermi\_dirac\_2...

Number of Input Arguments: 1 Number of Output Arguments: 1

fermi\_dirac\_2\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

fermi\_dirac\_3half...

Number of Input Arguments: 1 Number of Output Arguments: 1

fermi\_dirac\_3half\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

fermi\_dirac\_half...

Number of Input Arguments: 1 Number of Output Arguments: 1

fermi\_dirac\_half\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

fermi\_dirac\_inc\_0...

Number of Input Arguments: 2 Number of Output Arguments: 1

fermi\_dirac\_inc\_0\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

fermi\_dirac\_int...

Number of Input Arguments: 2 Number of Output Arguments: 1

fermi\_dirac\_int\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

fermi\_dirac\_m1...

Number of Input Arguments: 1 Number of Output Arguments: 1

fermi\_dirac\_m1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

fermi\_dirac\_mhalf...

Number of Input Arguments: 1 Number of Output Arguments: 1

fermi\_dirac\_mhalf\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

gamma...

Number of Input Arguments: 1 Number of Output Arguments: 1

gamma\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

gamma\_inc\_P...

Number of Input Arguments: 2 Number of Output Arguments: 1

gamma\_inc\_P\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

gamma\_inc\_Q...

Number of Input Arguments: 2 Number of Output Arguments: 1

gamma\_inc\_Q\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

gammainv...

Number of Input Arguments: 1 Number of Output Arguments: 1

gammainv\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

gammastar...

Number of Input Arguments: 1 Number of Output Arguments: 1

gammastar\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

gegenpoly\_1...

Number of Input Arguments: 2 Number of Output Arguments: 1

gegenpoly\_1\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

gegenpoly\_2...

Number of Input Arguments: 2 Number of Output Arguments: 1

gegenpoly\_2\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

gegenpoly\_3...

Number of Input Arguments: 2 Number of Output Arguments: 1

gegenpoly\_3\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

gegenpoly\_n...

Number of Input Arguments: 3 Number of Output Arguments: 1

gegenpoly\_n\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

hydrogenicR...

Number of Input Arguments: 4 Number of Output Arguments: 1

hydrogenicR\_1...

Number of Input Arguments: 2 Number of Output Arguments: 1

hydrogenicR\_1\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

hydrogenicR\_e...

Number of Input Arguments: 4 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 4 of the C argument list

hyperg\_0F1...

Number of Input Arguments: 2 Number of Output Arguments: 1

hyperg\_0F1\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

hyperg\_1F1...

Number of Input Arguments: 3 Number of Output Arguments: 1

hyperg\_1F1\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

hyperg\_1F1\_int...

Number of Input Arguments: 3 Number of Output Arguments: 1

hyperg\_1F1\_int\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

hyperg\_2F0...

Number of Input Arguments: 3 Number of Output Arguments: 1

hyperg\_2F0\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

hyperg\_2F1...

Number of Input Arguments: 4 Number of Output Arguments: 1

hyperg\_2F1\_conj...

Number of Input Arguments: 4 Number of Output Arguments: 1

hyperg\_2F1\_conj\_e...

Number of Input Arguments: 4 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 4 of the C argument list

hyperg\_2F1\_conj\_renorm...

Number of Input Arguments: 4 Number of Output Arguments: 1

hyperg\_2F1\_conj\_renorm\_e...

Number of Input Arguments: 4 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 4 of the C argument list

hyperg\_2F1\_e...

Number of Input Arguments: 4 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 4 of the C argument list

hyperg\_2F1\_renorm...

Number of Input Arguments: 4 Number of Output Arguments: 1

hyperg\_2F1\_renorm\_e...

Number of Input Arguments: 4 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 4 of the C argument list

hyperg\_U...

Number of Input Arguments: 3 Number of Output Arguments: 1

hyperg\_U\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

hyperg\_U\_e10\_e...

Number of Input Arguments: 3 Number of Output Arguments: 3

The error flag is discarded. Return Arguments 1 - 3 resemble a
gsl\_result\_e10 argument, which is argument 3 of the C argument list

hyperg\_U\_int...

Number of Input Arguments: 3 Number of Output Arguments: 1

hyperg\_U\_int\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

hyperg\_U\_int\_e10\_e...

Number of Input Arguments: 3 Number of Output Arguments: 3

The error flag is discarded. Return Arguments 1 - 3 resemble a
gsl\_result\_e10 argument, which is argument 3 of the C argument list

hypot...

Number of Input Arguments: 2 Number of Output Arguments: 1

hypot\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

hzeta...

Number of Input Arguments: 2 Number of Output Arguments: 1

hzeta\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

laguerre\_1...

Number of Input Arguments: 2 Number of Output Arguments: 1

laguerre\_1\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

laguerre\_2...

Number of Input Arguments: 2 Number of Output Arguments: 1

laguerre\_2\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

laguerre\_3...

Number of Input Arguments: 2 Number of Output Arguments: 1

laguerre\_3\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

laguerre\_n...

Number of Input Arguments: 3 Number of Output Arguments: 1

laguerre\_n\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

lambert\_W0...

Number of Input Arguments: 1 Number of Output Arguments: 1

lambert\_W0\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

lambert\_Wm1...

Number of Input Arguments: 1 Number of Output Arguments: 1

lambert\_Wm1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

legendre\_H3d...

Number of Input Arguments: 3 Number of Output Arguments: 1

legendre\_H3d\_0...

Number of Input Arguments: 2 Number of Output Arguments: 1

legendre\_H3d\_0\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

legendre\_H3d\_1...

Number of Input Arguments: 2 Number of Output Arguments: 1

legendre\_H3d\_1\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

legendre\_H3d\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

legendre\_P1...

Number of Input Arguments: 1 Number of Output Arguments: 1

legendre\_P1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

legendre\_P2...

Number of Input Arguments: 1 Number of Output Arguments: 1

legendre\_P2\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

legendre\_P3...

Number of Input Arguments: 1 Number of Output Arguments: 1

legendre\_P3\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

legendre\_Pl...

Number of Input Arguments: 2 Number of Output Arguments: 1

legendre\_Pl\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

legendre\_Plm...

Number of Input Arguments: 3 Number of Output Arguments: 1

legendre\_Plm\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

legendre\_Q0...

Number of Input Arguments: 1 Number of Output Arguments: 1

legendre\_Q0\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

legendre\_Q1...

Number of Input Arguments: 1 Number of Output Arguments: 1

legendre\_Q1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

legendre\_Ql...

Number of Input Arguments: 2 Number of Output Arguments: 1

legendre\_Ql\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

legendre\_sphPlm...

Number of Input Arguments: 3 Number of Output Arguments: 1

legendre\_sphPlm\_e...

Number of Input Arguments: 3 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 3 of the C argument list

lnbeta...

Number of Input Arguments: 2 Number of Output Arguments: 1

lnbeta\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

lnchoose...

Number of Input Arguments: 2 Number of Output Arguments: 1

lnchoose\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

lncosh...

Number of Input Arguments: 1 Number of Output Arguments: 1

lncosh\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

lndoublefact...

Number of Input Arguments: 1 Number of Output Arguments: 1

lndoublefact\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

lnfact...

Number of Input Arguments: 1 Number of Output Arguments: 1

lnfact\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

lngamma...

Number of Input Arguments: 1 Number of Output Arguments: 1

lngamma\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

lngamma\_sgn\_e...

Number of Input Arguments: 1 Number of Output Arguments: 3

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

lnpoch...

Number of Input Arguments: 2 Number of Output Arguments: 1

lnpoch\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

lnpoch\_sgn\_e...

Number of Input Arguments: 2 Number of Output Arguments: 3

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

lnsinh...

Number of Input Arguments: 1 Number of Output Arguments: 1

lnsinh\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

log...

Number of Input Arguments: 1 Number of Output Arguments: 1

log\_1plusx...

Number of Input Arguments: 1 Number of Output Arguments: 1

log\_1plusx\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

log\_1plusx\_mx...

Number of Input Arguments: 1 Number of Output Arguments: 1

log\_1plusx\_mx\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

log\_abs...

Number of Input Arguments: 1 Number of Output Arguments: 1

log\_abs\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

log\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

log\_erfc...

Number of Input Arguments: 1 Number of Output Arguments: 1

log\_erfc\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

multiply...

Number of Input Arguments: 2 Number of Output Arguments: 1

multiply\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

multiply\_err\_e...

Number of Input Arguments: 4 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 4 of the C argument list

poch...

Number of Input Arguments: 2 Number of Output Arguments: 1

poch\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

pochrel...

Number of Input Arguments: 2 Number of Output Arguments: 1

pochrel\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

polar\_to\_rect...

pow\_int...

Number of Input Arguments: 2 Number of Output Arguments: 1

pow\_int\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

psi...

Number of Input Arguments: 1 Number of Output Arguments: 1

psi\_1\_int...

Number of Input Arguments: 1 Number of Output Arguments: 1

psi\_1\_int\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

psi\_1piy...

Number of Input Arguments: 1 Number of Output Arguments: 1

psi\_1piy\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

psi\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

psi\_int...

Number of Input Arguments: 1 Number of Output Arguments: 1

psi\_int\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

psi\_n...

Number of Input Arguments: 2 Number of Output Arguments: 1

psi\_n\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

rect\_to\_polar...

sin...

Number of Input Arguments: 1 Number of Output Arguments: 1

sin\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

sin\_err\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

sinc...

Number of Input Arguments: 1 Number of Output Arguments: 1

sinc\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

synchrotron\_1...

Number of Input Arguments: 1 Number of Output Arguments: 1

synchrotron\_1\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

synchrotron\_2...

Number of Input Arguments: 1 Number of Output Arguments: 1

synchrotron\_2\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

taylorcoeff...

Number of Input Arguments: 2 Number of Output Arguments: 1

taylorcoeff\_e...

Number of Input Arguments: 2 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 2 of the C argument list

transport\_2...

Number of Input Arguments: 1 Number of Output Arguments: 1

transport\_2\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

transport\_3...

Number of Input Arguments: 1 Number of Output Arguments: 1

transport\_3\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

transport\_4...

Number of Input Arguments: 1 Number of Output Arguments: 1

transport\_4\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

transport\_5...

Number of Input Arguments: 1 Number of Output Arguments: 1

transport\_5\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

zeta...

Number of Input Arguments: 1 Number of Output Arguments: 1

zeta\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

zeta\_int...

Number of Input Arguments: 1 Number of Output Arguments: 1

zeta\_int\_e...

Number of Input Arguments: 1 Number of Output Arguments: 2

The error flag is discarded. Return Arguments 1 and 2 resemble a
gsl\_result argument, which is argument 1 of the C argument list

Ordinary Functions
------------------

The following array functions have been wrapped. These are supposingly
faster than the equivalent functions from above.

bessel\_In\_array...

bessel\_Jn\_array...

bessel\_Kn\_array...

bessel\_Kn\_scaled\_array...

bessel\_Yn\_array...

bessel\_il\_scaled\_array...

bessel\_jl\_array...

bessel\_jl\_steed\_array...

bessel\_kl\_scaled\_array...

bessel\_yl\_array...

Ordinary Functions
------------------

The following array functions have been wrapped. These are supposingly
faster than the equivalent functions from above.

bessel\_In\_array...

bessel\_Jn\_array...

bessel\_Kn\_array...

bessel\_Kn\_scaled\_array...

bessel\_Yn\_array...

bessel\_il\_scaled\_array...

bessel\_jl\_array...

bessel\_jl\_steed\_array...

bessel\_kl\_scaled\_array...

bessel\_yl\_array...
