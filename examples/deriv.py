import pygsl.deriv
# pygsl.init.set_debug_level(3)
# pygsl.init.add_c_traceback_frames(True)

def f(x, args):
    return x**3

r = pygsl.deriv.central(f, 1, 1e-10)
print(r)


r = pygsl.deriv.central(f, 1, 1e-10, 2)
print(r)

def f(x, args):
    offset, scale = args
    return scale * x**3 + offset


r = pygsl.deriv.central(f, 1, 1e-10, [2, 3])
print(r)
