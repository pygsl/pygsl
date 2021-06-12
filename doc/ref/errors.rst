Exception Classes
-----------------

:class:`gsl\_Error` derived from :class:`Exception`, can be constructed with any object as
parameter. It is baseclass to all other GSL Exceptions

These classes are translations of ``gsl/gsl_errno.h``  to python exceptions.

:class:`gsl\_ArithmeticError` derived from  :class:`Exception` and  :class:`exceptions.ArithmeticError`,
       base of all common arithmetic exceptions

:class:`gsl\_OverflowError` derived from  :class:`gsl\_Error` and :class:`exceptions.OverflowError`

:class:`gsl\_ZeroDivisionError` derived from :class:`gsl\_Error` and :class:`exceptions.ZeroDivisionError`

:class:`gsl\_FloatingPointError` derived from :class:`gsl\_Error` and :class:`exceptions.FloatingPointError`

:class:`gsl\_ArithmeticError` is derived from :class:`gsl\_Error` and from  :class:`exceptions.ArithmeticError`.
This exception is the base of all common arithmetic exceptions.

:class:`gsl\_AccuracyLossError` is derived from :class:`gsl\_ArithmeticError`. This exception is raised if the
algorithm failed to reach the specified tolerance.

:class:`gsl\_BadFuncError` is derived from :class:`gsl\_Error`. This exception is raised if problem
with a user-supplied function occur.

:class:`gsl\_BadLength` is derived from :class:`gsl\_Error`. This exception is raised if matrix or
vector lengths are not conformant.

:class:`gsl\_BadToleranceError` is derived from :class:`gsl\_Error`. This exception is raised if
user specified an tolerance which can not be reached.

:class:`gsl\_CacheLimitError` is derived from :class:`gsl\_Error`. This exception is raised if the
cache limit is exceeded.

:class:`gsl\_DivergeError` is derived from . This exception is raised if an
integral or series is divergent.

:class:`gsl\_DomainError` is derived from :class:`gsl\_Error`. This exception is raised if domain
errors occure. e.g. sqrt(-1).

:class:`gsl\_EOFError` is derived from :class:`gsl\_Error` and from :class:`EOFError`.
       This exception is raised if end of file is reached.

:class:`gsl\_FactorizationError` is derived from  :class:`gsl\_Error`. This exception is raised if
factorization failed.

:class:`gsl\_FloatingPointError` is derived from  :class:`gsl\_Error` and from   :class:`FloatingPointError`.

:class:`gsl\_GenericError` is derived from  :class:`gsl\_Error`.

:class:`gsl\_InvalidArgumentError` is derived from  :class:`gsl\_Error`. This exception is raised if
an invalid argument is supplied by the user.

:class:`gsl\_JacobianEvaluationError` is derived from  :class:`gsl\_ArtithmetricError`. This exception is raised
if jacobian evaluations are not improving the solution.

:class:`gsl\_MatrixNotSquare` is derived from  :class:`gsl\_Error`. This exception is raised if the
given matrix is not square.

:class:`gsl\_MaximumIterationError` is derived from   :class:`gsl\_ArtithmetricError`. This exception is raised if
the maximum number of iterations is exceeded.

:class:`gsl\_NoHardwareSupportError` is derived from  :class:`gsl\_Error`. This exception is raised
if the requested feature is not supported by the hardware.

:class:`gsl\_NoProgressError` is derived from   :class:`gsl\_ArtithmetricError`. This exception is raised if the
iteration is not making progress towards solution.

:class:`gsl\_NotImplementedError` is derived from and from . This exception is
raised if a requested feature is not (yet) implemented .

:class:`gsl\_OverflowError` is derived from  :class:`gsl\_Error` and from  :class:`OverflowError`.

:class:`gsl\_PointerError` is derived from  :class:`gsl\_Error`. This exception is raised if an
invalid pointer is found by the C wrapper code or by the GSL library.

:class:`gsl\_RangeError` is derived from   :class:`gsl\_ArtithmetricError`. This exception is raised if output
would be out or range, e.g. exp(1e100) .

:class:`gsl\_RoundOffError` is derived from   :class:`gsl\_ArtithmetricError`. This exception is raised if
arithmetic failed because of roundoff error.

:class:`gsl\_RunAwayError` is derived from   :class:`gsl\_ArtithmetricError`. This exception is raised if
iterative process is out of control.

:class:`gsl\_SanityCheckError` is derived from  :class:`gsl\_Error`. This exception is raised if a
sanity check failed - shouldn’t happen.

:class:`gsl\_SingularityError` is derived from   :class:`gsl\_ArtithmetricError`. This exception is raised if an
apparent singularity is detected.

:class:`gsl\_TableLimitError` is derived from  :class:`gsl\_Error`. This exception is raised if the
table limit is exceeded.

:class:`gsl\_ToleranceError` is derived from   :class:`gsl\_ArtithmetricError`. This exception is raised if the
alghorithm failed to reach the specified tolerance.

:class:`gsl\_ToleranceFError` is derived from   :class:`gsl\_ArtithmetricError`. This exception is raised if the
alghorithm cannot reach the specified tolerance in F (typically the
variation of the evaluated function).

:class:`gsl\_ToleranceGradientError` is derived from   :class:`gsl\_ArtithmetricError`. This exception is raised
if cannot reach the specified tolerance for the gradient.

:class:`gsl\_ToleranceXError` is derived from   :class:`gsl\_ArtithmetricError`. This exception is raised if
cannot reach the specified tolerance in X (typically a search result).

:class:`gsl\_UnderflowError` is derived from  :class:`gsl\_Error` and from :class:`Overflowwerror`.

:class:`gsl\_ZeroDivisionError` is derived from  :class:`gsl\_Error` and from  :class:`ZeroDivisionError`.

All the above errors are just translations of the errno to python
exceptions.

The following two are specific to pygsl:

:class:`pygsl.errors.pygsl\_NotImplementedError` is derived from and from . This
exception is raised if a feature is requested but not implemented.
Currently only used if a module requests the debugging enviroment of the
init module, but the init module was not compiled with

:class:`pygsl.errors.pygsl\_StrideError` is derived from . GSL uses as strides
multiples of the basis type; for a vector or doubles, one means from one
double to the next. Numpy or numarray count the stride in multiples of
the size of a char. Therefore the stride has to be recalculated before
the approbriate GSL function can be called. If that fails this exception
is raised.

Warning Classes
---------------

:class:`gsl\_Warning` The dedicated warning class for GSL has as base class.

:class:`gsl\_DomainWarning` derived from , used by some functions
