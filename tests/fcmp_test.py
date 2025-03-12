from pygsl.math import fcmp

def test_fcmp():
    r = fcmp(1, 1, 1e-12)
    assert r == 0

    r = fcmp(1, -1, 1e-12)
    assert r == 1

    r = fcmp(-1, 1, 1e-12)
    assert r == -1

    r = fcmp(1, 1+ 1e-14, 1e-12)
    assert r == 0
