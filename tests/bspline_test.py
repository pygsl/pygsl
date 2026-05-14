"""Still the old bspline API

Todo:
    need to document when it was changed

"""

import numpy as np
from pygsl import bspline


def test_bspline_config():
    """Check that the attribute is available
    """
    from pygsl.cfg import bspline_config
    bool(bspline_config.bspline_workspace_has_attribute_n)


def test_bspline_instaniate():
    nbreak = 6
    bspline.bspline(4, nbreak)


def test_bspline_api():
    nbreak = 6
    bw = bspline.bspline(4, nbreak)

    bw.knots_uniform(0.0, 15.0)
    [bw.eval(x) for x in np.linspace(0, 15, num=4)]
