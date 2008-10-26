#!/usr/bin/env python
"""Simple example from GSL documentation computing zeta(2)"""
import math
import pygsl.sum 
print pygsl.sum

zeta_2 = math.pi**2/6.0

terms = [1./(n**2) for n in range(1,21)]
info_dict = {}
sum_accel, err = pygsl.sum.levin_sum(terms, info_dict=info_dict)

print("term-by-term sum = % .16f using %d terms"%
      (sum(terms), len(terms)))
print("term-by-term sum = % .16f using %d terms"%
      (info_dict['sum_plain'], info_dict['terms_used']))
print("exact value      = % .16f"%(zeta_2,))
print("accelerated sum  = % .16f using %d terms"%
      (sum_accel, info_dict['terms_used']))
print("estimated error  = % .16f"%(err,))
print("actual error     = % .16f"%(abs(sum_accel - zeta_2),))


