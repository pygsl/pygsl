# check that the correct import flag is used
import pytest


def test_swig_init_returns_correct_flag():
    """This import will fail if swig init is taking the expected return flag
    """
    with pytest.raises(AssertionError):
        from pygsl import swig_fail_on_init
