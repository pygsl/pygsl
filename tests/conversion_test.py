import pygsl.inittest as inittest
import pytest


def test_complex_conversion_none_fails():
    with pytest.raises(TypeError):
        inittest.complex_conversion(None)


def test_complex_conversion_simple_value():
    v = 1 + 2j
    c = inittest.complex_conversion(v)
    assert c.real == pytest.approx(v.real, abs=1e-6)
    assert c.imag == pytest.approx(v.imag, abs=1e-6)


def test_complex_conversion_float():
    c = inittest.complex_conversion(42)
    assert c.real == pytest.approx(42, abs=1e-6)
    assert c.imag == pytest.approx(0, abs=1e-6)
