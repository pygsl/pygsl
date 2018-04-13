import numpy as np
import pygsl
from pygsl import errno
from pygsl.sparse import matrix, blas, linalg

def run():
    N = 100
    n = N - 2
    A = matrix.sparse_matrix(n, n)

    h = 1.0 / ( N - 1.0)

    # first row
    A.set(0, 0, -2.0)
    A.set(0, 1, 1.0)

    # rows [1:n-2]
    for i in range(1, n - 1):
        A.set(i, i + 1,  1.0)
        A.set(i, i,     -2.0)
        A.set(i, i - 1,  1.0)

    # last row
    A.set(n - 1, n -1, -2.0)
    A.set(n - 1, n -2,  1.0)

    A.scale(1.0 / h**2)

    cnt = (np.arange(n))
    x = (cnt + 1) * h
    f = - np.pi**2  * np.sin(np.pi * x)

    C = A.ccs()

    tol = 1.0e-6
    max_iter = 10

    work = linalg.GMRES(n, 0)
    u = np.zeros(len(x), np.float_)

    for t_iter in range(max_iter):
        pygsl.set_debug_level(0)
        #status, u = work.iterate(C, f, tol)
        status, u = work.iterate(C, f, tol, u)
        pygsl.set_debug_level(0)
        residual = work.normr()
        print("iter %d residual = %.12e" %(t_iter, residual))

        if status == errno.GSL_SUCCESS:
            break
    else:
        raise ValueError("Exceed maximum number of iterations")

    return x, u

def plot():
    import matplotlib.pyplot as plt

    x, u = run()
    u_ref = np.sin(np.pi * x)
    
    fig = plt.figure(1)
    ax = fig.add_subplot(211)
    ax.clear()
    eps = 1e-2
    ax.plot(x, u, 'r-', x, u_ref + eps, 'b-')
    ax.set_xlabel("x")
    ax.set_ylabel("u (x)")
    ax.set_title("1D Poisson solution offset deliberatly added to GSL solution")

    ax2 = fig.add_subplot(212)
    ax2.clear()
    diff = u - u_ref
    ax2.plot(x, diff * 1e6, 'g-')
    ax2.set_xlabel("x")
    ax2.set_ylabel(r"u (x) $\cdot 10^6$")
    fig.legend([r"GSL + $\varepsilon$", "Analytic", "GSL - Analytic"], loc = 0)
    
if __name__ == '__main__':
    #run()
    plot()
