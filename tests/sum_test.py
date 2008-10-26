# Author : Michael Forbes 
import math
import unittest
import pygsl
import pygsl.sum

def fn1(n):
    """Terms for the zeta function."""
    return 1./n/n

class SumTest(unittest.TestCase):
    def setUp(self):
        self.zeta_2 = math.pi**2/6.0
        self.terms = [fn1(n) for n in range(1,21)]
    def test_levin_u(self):
        """Test the computation of zeta(2) = pi**2/6."""
        info_dict = {}
        (ans, err_est) = pygsl.sum.levin_sum(self.terms, 
                                             truncate=False,
                                             info_dict=info_dict)
        err = abs(ans - self.zeta_2)
        assert(err < err_est)
        assert(err < 1e-8)
        assert(abs(info_dict['sum_plain'] 
                   - sum(self.terms[:info_dict['terms_used']+1]))
               < 1e-11)
        

    def test_levin_utrunk(self):
        """Test the computation of zeta(2) = pi**2/6 using the
        truncated algorithm."""
        info_dict = {}
        (ans, err_est) = pygsl.sum.levin_sum(self.terms, 
                                             truncate=True,
                                             info_dict=info_dict)
        err = abs(ans - self.zeta_2)
        assert(err < err_est)
        assert(err < 1e-8)
        assert(abs(info_dict['sum_plain'] 
                   - sum(self.terms[:info_dict['terms_used']+1])) 
               < 1e-11)

def run():
    unittest.main()

if __name__ == '__main__':
    run()
