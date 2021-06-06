
Floating Point Unit Support
===========================

This chapter lists features to configure the “Floating Point Unit” of
your machine. The exact behaviour of your Floating Point Unit can’t be
discussed here in general — its just machine type dependent.

set\_modeint precision, int rounding, int exception\_mask the mode has
effect on the behaviour during calcualtion, e.g. division by zero or
rounding.

The following constants are used as precision argument:

l\|lconstantmode valuedefinition via gsl

Possible round arguments are:

l\|lconstantmode valuedefinition via gsl

These exception arguments can be added. is the sum of all 5 constants.

l\|lconstantmode valuedefinition via gsl

env\_setup sets the ieee mode from . This is not called any more
automatically when importing the .

bin\_reprfloat value returns the binary representation as tuple with the
following contents: These values are used as in :

l\|lconstanttype valuedefinition via gsl

isnanfloat value determines if the argument is not a valid number

nan generates a “not-a-number” value. This is implemented as function,
because of the potential exception generation by your floating-point
unit.

isinffloat value returns -1 if the argument represents a negative
infinite value and +1 if positive, 0 otherwise

posinf gives you the representation of “positive infinity”

neginf the same as posinf, but negative

finitefloat value results in 1 if the value is finite, 0 if it is not a
number or infinite
