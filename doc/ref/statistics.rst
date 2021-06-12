
Statistics functions
====================

    This chapter describes the statistical functions in the library. The
    basic statistical functions include routines to compute the mean,
    variance and standard deviation. More advanced functions allow you
    to calculate absolute deviations, skewness, and kurtosis as well as
    the median and arbitrary percentiles.

The algorithms provided here use recurrence relations to compute average
quantities in a stable way, without large intermediate values that might
overflow. All functions work on any Python sequence (of appropriate
data-type), but see section [sec:stat:speed-considerations] for
advantages and drawbacks of different kinds of input data.

For details on the underlying implementation of these functions please
consult the GNU Scientific Library reference manual.

Organization of the module
--------------------------

Individual parts of the GSL functions names, providing artificial
namespaces in C, are mapped to modules and submodules in PyGSL. That is,
can be found as and as .

The functions in the module are available in versions for datasets in
the standard and NumPy floating-point and integer types. The generic
versions available in the module are using the generic GSL versions. The
submodules use GSL functions according to the submodule name, e.g. long
for .

Implemented submodules are , , , , , , and . The latter one also serves
as default and is used whenever you don’t expclicitely state a different
datatype. In most cases it is appropriate to simply use the default
implementation as it covers the widest range of the real space, offers
high precision, and as such is simple to use. If you have a sequence of
all integer values it is straightforward to use functions as these use
an implementation corresponding to Pythons -type. These implemented
submodules represent all numeric datatypes available in Python (, )
besides which has no representation in standard C, as well as all
numeric datatypes available in NumPy that have corresponding
implementations in GSL (on 32 bit systems these are: Character,
UnsigendInt8, Int16, Int32, Int, Float32, Float).

Available functions
-------------------

Mean, Standard Deviation, and Variance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

meanx Arithmetic mean (*sample mean*) of :

.. math:: \hat\mu = \frac{1}{N} \sum x_i

variancex Estimated (*sample*) variance of :

.. math:: \hat\sigma^2 = \frac{1}{N-1} \sum (x_i - \hat\mu)^2

 This function computes the mean via a call to . If you have already
computed the mean then you can pass it directly to .

variance\_mx, mean Estimated (*sample*) variance of relative to :

.. math:: \hat\sigma^2 = \frac{1}{N-1} \sum (x_i - mean)^2

sdx

sd\_mx, mean The standard deviation is defined as the square root of the
variance of . These functions returns the square root of the respective
variance-functions above.

variance\_with\_fixed\_meanx, mean Compute an unbiased estimate of the
variance of when the population mean of the underlying distribution is
known *a priori*. In this case the estimator for the variance uses the
factor :math:`1/N` and the sample mean :math:`\hat\mu` is replaced by
the known population mean :math:`\mu`:

.. math:: \hat\sigma^2 = \frac{1}{N} \sum (x_i - \mu)^2

Absolute deviation
~~~~~~~~~~~~~~~~~~

absdevdata Compute the absolute deviation from the mean of The absolute
deviation from the mean is defined as

.. math:: absdev  = (1/N) \sum |x_i - \hat\mu|

 where :math:`x_i` are the elements of the dataset . The absolute
deviation from the mean provides a more robust measure of the width of a
distribution than the variance. This function computes the mean of via a
call to .

absdev\_mdata, mean Compute the absolute deviation of the dataset
relative to the given value of

.. math:: absdev  = (1/N) \sum |x_i - mean|

 This function is useful if you have already computed the mean of (and
want to avoid recomputing it), or wish to calculate the absolute
deviation relative to another value (such as zero, or the median).

Higher moments (skewness and kurtosis)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

skewdata Compute the skewness of . The skewness is defined as

.. math:: skew = (1/N) \sum ((x_i - \hat\mu)/\hat\sigma)^3

 where :math:`x_i` are the elements of the dataset . The skewness
measures the asymmetry of the tails of a distribution.

The function computes the mean and estimated standard deviation of via
calls to and .

skew\_m\_sddata, mean, sd Compute the skewness of the dataset using the
given values of the mean and standard deviation varsd

.. math:: skew = (1/N) \sum ((x_i - mean)/sd)^3

 These functions are useful if you have already computed the mean and
standard deviation of and want to avoid recomputing them.

kurtosisdata Compute the kurtosis of . The kurtosis is defined as

.. math:: kurtosis = ((1/N) \sum ((x_i - \hat\mu)/\hat\sigma)^4) - 3

 The kurtosis measures how sharply peaked a distribution is, relative to
its width. The kurtosis is normalized to zero for a gaussian
distribution.

kurtosis\_m\_sddata, mean, sd This function computes the kurtosis of the
dataset using the given values of the mean and standard deviation

.. math:: kurtosis = ((1/N) \sum ((x_i - mean)/sd)^4) - 3

 This function is useful if you have already computed the mean and
standard deviation of and want to avoid recomputing them.

Autocorrelation
~~~~~~~~~~~~~~~

lag1\_autocorrelationx Computes the lag-1 autocorrelation of the dataset

.. math::

   a_1 = \frac{\sum^{n}_{i = 1} (x_{i} - \hat\mu) (x_{i-1} - \hat\mu)}{
            \sum^{n}_{i = 1} (x_{i} - \hat\mu) (x_{i} - \hat\mu)}

lag1\_autocorrelation\_mx, mean Computes the lag-1 autocorrelation of
the dataset using the given value of the mean .

.. math::

   a_1 = \frac{\sum_{i = 1}^{n} (x_{i} - \var{mean}) (x_{i-1} - \var{mean})}{
            \sum^{n}_{i = 1} (x_{i} - \var{mean}) (x_{i} - \var{mean})}

Covariance
~~~~~~~~~~

covariancex, y Computes the covariance of the datasets and which must be
of same length.

.. math:: c = \frac{1}{n-1} \sum^{n}_{i=1} (x_i - \hat x) (y_i - \hat y)

lag1\_autocorrelation\_mx, y, mean\_x, mean\_y Computes the covariance
of the datasets and using the given values of the means and . The
datasets and must be of equal length.

.. math::

   c = \frac{1}{n-1} \sum^{n}_{i=1} (x_i - \var{mean\_x}) (y_i -
         \var{mean\_y})

Maximum and Minimum values
~~~~~~~~~~~~~~~~~~~~~~~~~~

maxdata This function returns the maximum value in . The maximum value
is defined as the value of the element :math:`x_i` which satisfies
:math:`x_i \ge x_j` for all :math:`j`.

If you want instead to find the element with the largest absolute
magnitude you will need to apply ‘fabs’ or ‘abs’ to your data before
calling this function.

mindata This function returns the minimum value in . The maximum value
is defined as the value of the element :math:`x_i` which satisfies
:math:`x_i \le x_j` for all :math:`j`.

If you want instead to find the element with the smallest absolute
magnitude you will need to apply ‘fabs’ or ‘abs’ to your data before
calling this function.

minmaxdata This function returns both the minimum and maximum values of
, determined in a single pass.

max\_indexdata This function returns the index of the maximum value in .
The maximum value is defined as the value of the element :math:`x_i`
which satisfies :math:`x_i \ge x_j` for all :math:`j`. When there are
several equal maximum elements then the first one is chosen.

min\_indexdata This function returns the index of the minimum value in .
The minimum value is defined as the value of the element :math:`x_i`
which satisfies :math:`x_i \le x_j` for all :math:`j`. When there are
several equal minimum elements then the first one is chosen.

minmax\_indexdata This function returns the indexes of the minimum and
maximum values of , determined in a single pass.

Median and Percentiles
~~~~~~~~~~~~~~~~~~~~~~

The median and percentile functions described in this section operate on
sorted data. For convenience we use “quantiles”, measured on a scale of
0 to 1, instead of percentiles (which use a scale of 0 to 100).

median\_from\_sorted\_datadata This function returns the median value of
. The elements of the array must be in ascending numerical order. There
are no checks to see whether the data are sorted, so the function should
always be used first.

When the dataset has an odd number of elements the median is the value
of element (n-1)/2. When the dataset has an even number of elements the
median is the mean of the two nearest middle values, elements (n-1)/2
and n/2. Since the algorithm for computing the median involves
interpolation this function always returns a floating-point number, even
for integer data types.

quantile\_from\_sorted\_datadata, F This function returns a quantile
value of . The elements of the array must be in ascending numerical
order. The quantile is determined by the , a fraction between 0 and 1.
For example, to compute the value of the 75th percentile should have the
value 0.75.

There are no checks to see whether the data are sorted, so the function
should always be used first.

The quantile is found by interpolation, using the formula

.. math:: quantile = (1 - \delta) x_i + \delta x_{i+1}

 where :math:`i` is :math:`floor((n - 1)f)` and :math:`\delta` is
:math:`(n-1)f - i`.

Thus the minimum value of the array () is given by equal to zero, the
maximum value () is given by equal to one and the median value is given
by equal to 0.5. Since the algorithm for computing quantiles involves
interpolation this function always returns a floating-point number, even
for integer data types.

Weighted Samples
~~~~~~~~~~~~~~~~

The functions described in this section allow the computation of
statistics for weighted samples. The functions accept an array of
samples, :math:`x_i`, with associated weights, :math:`w_i`. Each sample
:math:`x_i` is considered as having been drawn from a Gaussian
distribution with variance :math:`\sigma_i^2`. The sample weight
:math:`w_i` is defined as the reciprocal of this variance, :math:`w_i =
1/\sigma_i^2`. Setting a weight to zero corresponds to removing a sample
from a dataset.

wmeanw, data This function returns the weighted mean of the dataset
using the set of weights . The weighted mean is defined as

.. math:: \hat\mu = (\sum w_i x_i) / (\sum w_i)

wvariance w, data This function returns the estimated variance of the
dataset , using the set of weights . The estimated variance of a
weighted dataset is defined as

.. math:: \hat\sigma^2 = ((\sum w_i)/((\sum w_i)^2 - \sum (w_i^2))) \sum w_i (x_i - \hat\mu)^2

 Note that this expression reduces to an unweighted variance with the
familiar :math:`1/(N-1)` factor when there are :math:`N` equal non-zero
weights.

wvariance\_mw, data, wmean This function returns the estimated variance
of the weighted dataset using the given weighted mean .

wsdw, data The standard deviation is defined as the square root of the
variance. This function returns the square root of the corresponding
variance function above.

wsd\_mw, data, wmean This function returns the square root of the
corresponding variance function above.

wvariance\_with\_fixed\_meanw, data, mean This function computes an
unbiased estimate of the variance of weighted dataset when the
population mean of the underlying distribution is known \_a priori\_. In
this case the estimator for the variance replaces the sample mean
:math:`\hat\mu` by the known population mean :math:`\mu`,

.. math:: \hat\sigma^2 = (\sum w_i (x_i - \mu)^2) / (\sum w_i)

wsd\_with\_fixed\_meanw, data, mean The standard deviation is defined as
the square root of the variance. This function returns the square root
of the corresponding variance function above.

wabsdevw, data This function computes the weighted absolute deviation
from the weighted mean of . The absolute deviation from the mean is
defined as

.. math:: absdev = (\sum w_i |x_i - \hat\mu|) / (\sum w_i)

wabsdev\_mw, data, wmean This function computes the absolute deviation
of the weighted dataset DATA about the given weighted mean WMEAN.

wskeww, data This function computes the weighted skewness of the dataset
DATA.

.. math:: skew = (\sum w_i ((x_i - xbar)/\sigma)^3) / (\sum w_i)

wskew\_m\_sdw, data, mean, wsd This function computes the weighted
skewness of the dataset using the given values of the weighted mean and
weighted standard deviation, and .

wkurtosisw, data This function computes the weighted kurtosis of the
dataset . The kurtosis is defined as

.. math:: kurtosis = ((\sum w_i ((x_i - xbar)/sigma)^4) / (\sum w_i)) - 3

wkurtosis\_m\_sdw, data, mean, wsd This function computes the weighted
kurtosis of the dataset using the given values of the weighted mean and
weighted standard deviation, and .

Further Reading
---------------

See the GSL reference manual for a description of all available
functions and the calculations they perform.

The standard reference for almost any topic in statistics is the
multi-volume *Advanced Theory of Statistics* by Kendall and Stuart. Many
statistical concepts can be more easily understood by a Bayesian
approach. The book by Gelman, Carlin, Stern and Rubin gives a
comprehensive coverage of the subject. For physicists the Particle Data
Group provides useful reviews of Probability and Statistics in the
“Mathematical Tools” section of its Annual Review of Particle Physics.

Modules in Testing
==================

Modules in this package are often reimplementations of an original
package with significant change to the original. The current rng
implementation, for example, started its life here. The sf module
implemented here will supersede the sf package in one of the next
releases. Concerning the other modules the usage is encouraged for tests
to see if they work, but use them with caution in your production code!
