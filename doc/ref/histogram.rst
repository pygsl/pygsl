
Histogram Types
===============

This chapter is about the and type that are contained in .

 — 1-dimensional histograms
---------------------------

histogram\ ``long`` size h This type implements all methods on .

alloc\ ``long`` length allocate necessary space, returns ``None``

set\_ranges\_uniform\ ``float`` upper, ``float`` lower set the ranges to
uniform distance, returns ``None``

reset sets all bin values to 0, returns ``None``

increment\ ``float`` x increments corresponding bin, returns ``None``

accumulate\ ``float`` x, ``float`` weight adds the weight to
corresponding bin, returns ``None``

max returns upper range, as ``float``

min returns lower range, as ``float``

bins returns number of bins, as ``long``

get\ ``long`` n gets value of indexed bin, returns ``float``

get\_range\ ``long`` n gets upper and lower range of indexed bin,
returns ``(float,float)``

find\ ``float`` x finds index of corresponding bin, returns ``long``

max\_val returns maximal bin value, as ``float``

max\_bin returns bin index with maximal value, as ``long``

min\_val returns minimal bin value, as ``float``

min\_bin returns bin index with minimal value, as ``long``

mean returns mean of histogram, as ``float``

sigma returns std deviation of histogram, as ``float``

sum returns sum of bin values, as ``float``

set\_ranges\ ``sequence`` ranges sets range according given sequence,
returns ``None``

shift\ ``float`` offset shifts the contents of the bins by the given
offset, returns ``None``

scale\ ``float`` scale multiplies the contents of the bins by the given
scale, returns ``None``

equal\_bins\_p true if the all of the individual bin ranges are
identical, returns ``int``

add\ ``histogram`` h adds the contents of the bins, returns ``None``

sub\ ``histogram`` h substracts the contents of the bins, returns
``None``

mul\ ``histogram`` h multiplicates the contents of the bins, returns
``None``

div\ ``histogram`` h divides the contents of the bins, returns ``None``

clone\ ``histogram`` h returns a new copy of this histogram, returns new
``histogram``

copy\ ``histogram`` h copies the given histogram to myself, returns
``None``

read\ ``file`` input reads histogram binary data from file, returns
``None``

write\ ``file`` output writes histogram binary data to file, returns
``None``

scanf\ ``file`` input reads histogram data from file using scanf,
returns ``None``

printf\ ``file`` output writes histogram data to file using printf,
returns ``None``

Some mapping operations are supported, too:

l\|ltextttMapping syntaxEffect

For the special meaning and details please consult the GNU Scientific
Library reference.

 — 2-dimensional histograms
---------------------------

histogram2d\ ``long`` size x, ``long`` size y h This class holds a 2d
array and 2 sets of ranges for x and y coordinates for a two paramter
statistical event. It can be constructed by size parameters or as a copy
from another histogram. Most of the methods are the same as of .

set\_ranges\_uniform\ ``float`` xmin, ``float`` xmax, ``float`` ymin,
``float`` ymax set the ranges to uniform distance, returns ``None``

alloc\ ``long`` nx, ``long`` ny allocate necessary space, returns
``None``

reset sets all bin values to 0, returns ``None``

increment\ ``float`` x, ``float`` y increments corresponding bin,
returns ``None``

accumulate\ ``float`` x, ``float`` y, ``float`` weight adds the weight
to corresponding bin, returns ``None``

xmax returns upper x range as ``float``

xmin returns lower x range as ``float``

ymax returns upper y range as ``float``

ymin returns lower y range as ``float``

nx returns number of x bins as ``long``

ny returns number of y bins as ``long``

get\ ``long`` i, ``long`` j gets value of indexed bin,returns ``float``

get\_xrange\ ``long`` i gets upper and lower x range of indexed bin,
returns ``(float , float )``

get\_yrange\ ``long`` j gets upper and lower y range of indexed bin,
returns ``(float , float )``

find\ ``float`` x, ``float`` y finds index pair of corresponding value
pair, returns (``long``,\ ``long``)

max\_val returns maximal bin value as ``float``

max\_bin returns bin index with maximal value as ``long``

min\_val returns minimal bin value as ``float``

min\_bin returns bin index with minimal value as ``long``

sum returns sum of bin values as ``float``

xmean returns x mean of histogram as ``float``

xsigma returns x std deviation of histogram as ``float``

ymean returns y mean of histogram as\ ``float``

ysigma returns y std deviation of histogram as ``float``

cov returns covariance of histogram as ``float``

set\_rangessequence xranges, sequence yranges set the ranges according
to given sequences, returns ``None``

shift\ ``float`` offset shifts the contents of the bins by the given
offset, returns ``None``

scale\ ``float`` scale multiplies the contents of the bins by the given
scale, returns ``None``

equal\_bins\_p true if the all of the individual bin ranges are
identical, returns ``int``

add h adds the contents of the bins, returns ``None``

sub h substracts the contents of the bins, returns ``None``

mul h multiplicates the contents of the bins, returns ``None``

div h divides the contents of the bins, returns ``None``

clone returns a copy instance of

copy h copies the given histogram to myself, returns ``None``

readfile input reads histogram binary data from file, returns ``None``

writewfile output writes histogram binary data to file, returns ``None``

scanffile input reads histogram data from file using scanf, returns
``None``

printffile input writes histogram data to file using printf, returns
``None``

Some mapping operations are supported, too:

l\|lcodeMapping syntaxEffect

For the special meaning and details please consult the GNU Scientific
Library reference.

 and 
-----

To be implemented…
