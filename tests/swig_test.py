# test that swig behaves as expected
# motivated by swig 4.3

from pygsl import errors, swig_test
import pytest


def test10_error_drop_success():
    r = swig_test.pygsl_swig_test_return_errno(0)
    assert r is None


def test10_error_drop_continue():
    r = swig_test.pygsl_swig_test_return_errno(-1)
    assert r is None


def test20_error_drop_to_domain_error():
    with pytest.raises(errors.gsl_DomainError):
        swig_test.pygsl_swig_test_return_errno(1)


def test30_error_drop_called_with_double():
    with pytest.raises(errors.gsl_DomainError):
        swig_test.pygsl_swig_test_return_errno_with_double(1.0)


def test31_error_drop_called_with_double_to_domain_error():
    r = swig_test.pygsl_swig_test_return_errno_with_double(0.0)
    assert r is None


@pytest.fixture
def swig_test_st():
    return swig_test.swig_test_st()


def test40_get_dval(swig_test_st):
    d = swig_test_st.get_dval()
    assert d == pytest.approx(113, abs=1e-7)


def test41_get_ival(swig_test_st):
    i = swig_test_st.get_ival()
    assert i == 355


def test50_get_ival_status(swig_test_st):
    """should only return i, not status"""
    i = swig_test_st.get_ival_status(0)
    assert i == 355


def test51_get_ival_status(swig_test_st):
    """should raise"""
    with pytest.raises(errors.gsl_DomainError):
        i = swig_test_st.get_ival_status(1)
