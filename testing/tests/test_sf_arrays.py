from pygsl.testing import _ufuncs


def test_available():
    funcs = [name for name in dir(_ufuncs) if "array" in name]
    assert len(funcs)
