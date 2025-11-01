"""Check that swig_pygsl_init returns the flag which triggers an import error on failure
"""
import pytest


def test_swig_init_returns_correct_flag():
    """
    Before version 4.4 it would check that a pointer is returned. So
    error was signaled with NULL. Since 4.4 this means success, and -1
    needs to be returned to signal failure

    Please write me a email (or even better open a pull request)
    if this assumption is wrong
    """
    with pytest.raises(AssertionError):
        from pygsl import _swig_fail_on_init
        from pygsl import swig_fail_on_init
