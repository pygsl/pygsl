from pygsl import set_debug_level
import pygsl.eigen as eigen
import numpy as np
import sys

# set_debug_level(3)

data = np.array([
 1.0  , 1/2.0, 1/3.0, 1/4.0,
 1/2.0, 1/3.0, 1/4.0, 1/5.0,
 1/3.0, 1/4.0, 1/5.0, 1/6.0,
 1/4.0, 1/5.0, 1/6.0, 1/7.0])

m = data.reshape(4, 4)

n_evals, vec, A, Z = eigen.eigenvectors_nonsymm(
    m, compute_t=True, balance=True, schur=True
)
# Be aware: this function works in place
eigen.eigen_nonsymmv_sort(vec, A, eigen.SortType.abs_desc)

txt = f"""Eigen decomposition result

number of eigen vectors {n_evals}
Eigen values   {vec.real}
Eigen vectors
{A}

Schur representation
{Z}
"""
print(txt)
