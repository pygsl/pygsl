#!/usr/bin/env python
import pygsl
from pygsl.sparse import matrix

A = matrix.sparse_matrix(5, 4)
A.set(0, 2, 3.1);
A.set(0, 3, 4.6);
A.set(1, 0, 1.0);
A.set(1, 2, 7.2);
A.set(3, 0, 2.1);
A.set(3, 1, 2.9);
A.set(3, 3, 8.5);
A.set(4, 0, 4.1);

print("printing all matrix elements:\n");
for i in range(5):
    for j in range(4):
        val = A.get(i,j)
        val2 = A.get_val_or_none(i,j)
        print("A[%d, %d] = %g %s" % (i, j, val, val2) )

print(dir(matrix))
print(dir(matrix.sparse_matrix))
print(dir(A))
print(A.get_shape())
print(A.shape)

pygsl.set_debug_level(5)
A.sp2d()
#print(A == A)
B = A.memcpy()
print("A == B", A == B)
B.scale(2)
print("A == 2*B", A == B)

#: Minimum maximum of the matrix
A.minmax()

#: compact row type
A.crs()

#: compact column type
A.ccs()

#: change the layout and return a new array
C = B.transpose_memcpy()

#: change the layout in place
B.transpose_inplace()

#: compare the arrays
C.equal(B)
