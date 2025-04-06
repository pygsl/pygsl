import pygsl.eigen as eigen
import numpy as np

# set_debug_level(3)

data = np.array([
  -1.0,  1.0, -1.0, 1.0,
  -8.0,  4.0, -2.0, 1.0,
  27.0,  9.0,  3.0, 1.0,
  64.0, 16.0,  4.0, 1.0
])
m = data.reshape(4, 4)

t_eval, evec, A = eigen.eigenvectors_nonsymmv(
    m, #compute_t=True, balance=True, schur=True
)
print(t_eval)
print(evec)
print(A)
print(A.diagonal())
# Be aware: this function works in place
eigen.eigen_nonsymmv_sort(t_eval, evec, eigen.SortType.abs_desc)

for e_val, e_v in zip(t_eval, evec):
    print("Eigen value", e_val)
    print("Eigen vector", e_v)
