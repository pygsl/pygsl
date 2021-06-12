import pygsl.deriv

def f(x, args):
    '''If user does not supply arguments args will be None
    '''

    return x**3

r = pygsl.deriv.central(f, 1, 1e-10)


def f(x, args):
    offset, scale = args
    return scale * x**3 + offset


print('Deriv result')
y, y_err = pygsl.deriv.forward(f, 1, 1e-10, [2, 3])
print('             forward  : y = {:20.15f} +/- {:1.10f}'.format(y, y_err))
y, y_err = pygsl.deriv.central(f, 1, 1e-10, [2, 3])
print('             central  : y = {:20.15f} +/- {:1.15f}'.format(y, y_err))
y, y_err = pygsl.deriv.backward(f, 1, 1e-10, [2, 3])
print('             backward : y = {:20.15f} +/- {:1.15f}'.format(y, y_err))
