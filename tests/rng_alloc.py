# test if rng can be allocated

from pygsl.rng import gsl_rng

my=gsl_rng()
rn_list=[]
for i in range(10):
    rn_list.append(my.get())

print rn_list
