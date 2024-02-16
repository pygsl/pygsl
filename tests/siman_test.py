"""
"""
from pygsl import siman, rng
import numpy as np


class MySiman(siman.NumericEnsemble):
    def EFunc(self):
        x = self._data
        t = x-1.0
        t2 = t*t
        tmp = np.exp(-t**2)
        return tmp*np.sin(8*x)

    def Metric(self, outer):
        return np.absolute(self._data - outher.GetData())

    def Step(self, rng, step_size):
        old_x = self._data

        u = rng.uniform();
        new_x = u * 2 * step_size - step_size + old_x;
        self._data = new_x


    def Print(self):
        print("%12g" % self._data)


def test_siman():
    """basically a simple run test
    """
    m = MySiman()
    m.SetData(15.5)
    siman.solve(rng.rng(), m, do_print=0).GetData()
