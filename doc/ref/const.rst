Mathematical and scientific constants
=====================================

In this module some usefull constants are defined. There are four groups
of constants:

-  mathematical,

-  physical in mks unit system,

-  physical in cgs unit system and

-  physical number constants (e.g. fine structure)

The other modules are created during the initialisation of . For
convenience the mathematical, physical mks constants and number
constants also are available in the namespace of . If the used GSL
version is before gsl1.4, see

::

    pygsl.compiled_gsl_version

than the module names are cgs and mks. Form gsl1.5 these modules have
been renamed to cgsm and mksa. So to use cgs constants one has to write

::

    import pygsl.const
    import pygsl.const.cgs
    print pygsl.const.cgs.speed_of_light/pygsl.const.speed_of_light

for gsl :math:`<` 1.5 and

::

    import pygsl.const
    import pygsl.const.cgsm
    print pygsl.const.cgsm.speed_of_light/pygsl.const.speed_of_light

. Of course the result is . Short examples are given at top of each
section.

The actual values are taken form the GSL headers. The GNU Scientific
Library reference provides a more detailed description of these
constants.

Mathematical constants
----------------------

::

    from pygsl.const.m import *
    print sqrt2*sqrt2

| 
| Prints .
| Here comes the list:

l\|l\|lconstantNameGSL Namevalue

Scientific constants in mksa units
----------------------------------

::

    from pygsl.const import cgsm
    print "a teaspoon contains %g m^3"%mks.teaspoon

These are the provided constants:

l\|l\|lconstantNamegsl Nameunit

Scientific constants in cgsm units
----------------------------------

::

    from pygsl.const import cgsm
    print "a teaspoon contains %g ml"%cgs.teaspoon

You can access the following constants:

l\|l\|lconstantNamegsl Nameunit or value

Scientific number constants
---------------------------

::

    from pygsl.const import *
    # an alternative to
    # from pygsl.const.num import *
    print "fine structure is 1/137 with an error of %g%%"%(abs(1.0/137.0/fine_structure-1.0)*100.0)

Only two constants are available:

l\|l\|lconstantNamegsl Nameunit
