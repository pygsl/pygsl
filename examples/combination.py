#!/usr/bin/env python
import pygsl.combination as combination

print "All subsets of {0,1,2,3} by size:"
for i in range(4):    
    c = combination.Combination(4, i);
    while 1:
        print c.tolist()
        if c.next() != 0:
            break

