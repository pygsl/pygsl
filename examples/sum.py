#!/usr/bin/env python
import Numeric
import pygsl.sum as sum
print sum
N = 20
M_PI = Numeric.pi
w = sum.gsl_sum_levin_u_workspace(N)
zeta_2 = M_PI * M_PI / 6.0;

np1 = Numeric.arange(N) + 1
t = 1.0 / (np1 * np1)
sum = Numeric.add.reduce(t)
sum_accel, err = w.accel(t)     
print "term-by-term sum = % .16f using %d terms" % (sum, N)     
#print "term-by-term sum = % .16f using %d terms" % (w->sum_plain, w->terms_used)
print "exact value      = % .16f" % zeta_2
#print "accelerated sum  = % .16f using %d terms\n" % (sum_accel, w->terms_used);     
print "estimated error  = % .16f\n" % err
print "actual error     = % .16f\n" % (sum_accel - zeta_2)


