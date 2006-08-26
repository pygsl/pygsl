# Author : Fabian Jakobs
import unittest
from gsl_test import *
from pygsl._numobj import *
from pygsl.errors import gsl_Error
from pygsl.blas import *
from pygsl import  _gslwrap, Float, Complex
import pygsl.blas
#print pygsl.blas
#print pygsl.blas._gslwrap

class BlasTestCase(GSLTestCase):
    def testDdot(self):
        result = fpcompare(ddot(self.v1_4, self.v2_4), -105.957, 3)
        self.failUnless(result)

    def testZdotu(self):
        comp = zdotu(self.vz1_4, self.vz2_4)
        result = fpcompare(comp, -105.957+24.550j, 3)
        self.failUnless(result)

    def testZdotc(self):
        comp = zdotc(self.vz1_4, self.vz2_4)
        result = fpcompare(comp, -105.957+39.850j, 3)
        self.failUnless(result)

    def testDnrm2(self):
        result = fpcompare(dnrm2(self.v1_4), 26.832862, 6)
        self.failUnless(result)
    
    def testDznrm2(self):
        comp = dznrm2(self.vz1_4)
        result = fpcompare(comp, 27.000046, 6)
        self.failUnless(result)
    
    def testDasum(self):
        comp = dasum(self.v1_4)
        result = fpcompare(comp, 42.45, 2)
        self.failUnless(result)

    def testDzasum(self):
        comp = dzasum(self.vz1_4)
        result = fpcompare(comp, 45.45, 2)
        self.failUnless(result)
    
    def testIdamax(self):
        comp = idamax(self.v1_4)        
        self.failUnless(comp == 3)
    
    def testIzamax(self):
        comp = izamax(self.vz1_4)        
        self.failUnless(comp == 3)

    def testDaxpy(self):
        comp = daxpy(12.5, self.v1_4, self.v2_4)
        result = arrayCompare(comp, (-120.5, 28.075, 51, 306.73), 3)
        self.failUnless(result)

    def testDaxpy_cr(self):
        daxpy_cr(12.5, self.v1_4, self.v2_4)
        result = arrayCompare(self.v2_4, (-120.5, 28.075, 51, 306.73), 3)
        self.failUnless(result)

    def testZaxpy(self):
        comp = zaxpy(12.5-1.33j, self.vz1_4, self.vz2_4)
        result = arrayCompare(comp,
                              (-120.5+17.29j, 32.065+34.2415j,
                               51-5.32j, 306.73-29.19j),
                              3)
        self.failUnless(result)

    def testZaxpy_cr(self):
        zaxpy_cr(12.5-1.33j, self.vz1_4, self.vz2_4)
        result = arrayCompare(self.vz2_4,
                              (-120.5+17.29j, 32.065+34.2415j,
                               51-5.32j, 306.73-29.19j),
                              3)
        self.failUnless(result)

    def testZdrot(self):
        (comp1, comp2) = drot(self.v1_4, self.v2_4, 1.3, -23.1)
        res1 = arrayCompare(comp1, (-987.1, 62.09, -17.9, -414.313), 3)
        res2 = arrayCompare(comp2, (-245.7, 53.28, 93.7, 556.299), 3)
        self.failUnless(res1 and res2)

    def testZdrot_cr(self):
        drot_cr(self.v1_4, self.v2_4, 1.3, -23.1)
        res1 = arrayCompare(self.v1_4, (-987.1, 62.09, -17.9, -414.313), 3)
        res2 = arrayCompare(self.v2_4, (-245.7, 53.28, 93.7, 556.299), 3)
        self.failUnless(res1 and res2)

    def testDgemv(self):
        comp = dgemv(12.5, self.m1_4, self.v1_4, -22, self.v2_4)
        result = arrayCompare(comp, (254.763, 2077.35, 2821.75, -5956.81), 3)
        self.failUnless(result)
        
    def testZgemv(self):
        comp = zgemv(12.5-1.33j, self.mz1_4, self.vz1_4,
                     12.5-1.33j, self.vz2_4)
        result = arrayCompare(comp,
                              (1711.7425-106.28j,
                               1961.445-474.169j,
                               2830.714-543.905j,
                               -5235.653+1105.715j),
                              3)
        self.failUnless(result)

    def testDtrmv(self):
        A = array([[1.0,2,0,0],
                   [2,1,2,0],
                   [0,2,1,2],
                   [0,0,2,1]])
        b = array([1,2,3,4.0])
        x = dtrmv(A, b)
        res = arrayCompare(x, [1,4,7,10], 8)
        x = dtrmv(A, b, Uplo=_gslwrap.CblasUpper)
        res = res and arrayCompare(x, [5,8,11,4], 8)
        A[2,2] = 22
        x = dtrmv(A, b, Diag=_gslwrap.CblasUnit)
        res = res and arrayCompare(x, [1,4,7,10], 8)
        self.failUnless(res)

    def testZtrmv(self):
        A = array([[1.0+3j,2,0,0],
                   [2,1,2,0],
                   [0,2,1,2],
                   [0,0,2,1]])
        b = array([1,2,3,4.0], Complex)
        x = ztrmv(A, b)
        res = arrayCompare(x, [1+3j,4,7,10], 8)
        x = ztrmv(A, b, Uplo=_gslwrap.CblasUpper)
        res = res and arrayCompare(x, [5+3j,8,11,4], 8)
        A[2,2] = 22
        x = ztrmv(A, b, Diag=_gslwrap.CblasUnit)
        res = res and arrayCompare(x, [1,4,7,10], 8)
        self.failUnless(res)

    def testDtrsv(self):
        x = dtrsv(self.m1_4, self.v1_4)
        result = arrayCompare(x, [-11.5761, 10.0551, 0.694008, -1.39425], 4)
        self.failUnless(result)

    def testZtrsv(self):
        x = ztrsv(self.mz1_4, self.vz1_4)
        result = arrayCompare(x, [-11.5761+0j,
                                  10.0551+6.28807j,
                                  3.14888-2.19541j,
                                  0.907185+3.44386j
                                  ],
                              4)
        self.failUnless(result)

    def testDsymv(self):
        y = dsymv(2.1, self.m1_4, self.v1_4, 1, self.v2_4)
        result = arrayCompare(y, [740.567, 652.02, 623.65, -910.44], 3)
        self.failUnless(result)
        
    def testZhemv(self):
        c = 12.5 - 1.33j
        y = zhemv(c, self.mz1_4, self.vz1_4, c, self.vz2_4)
        result = arrayCompare(y, [4805.81-414.631j,
                                  3836.45-673.669j,
                                  3758.65-20.675j,
                                  -5235.65+1105.72j],
                              2)
        self.failUnless(result)

    def testDger(self):
        A = dger(1.22, self.v1_4, self.v2_4, self.m1_4)
        cc = [ -664.997, 42.443, -12.86, -300.988,
               130.538, -1.62195, 9.989, 65.4785,
               213.96, -2.444, 15.88, 105.842,
               1191.52, -57.553, 43.06, 523.594]
        result = arrayCompare(reshape(A, (-1,)), cc, 3)
        self.failUnless(result)

    def testZgeru(self):
        A = zgeru(12.5-1.33j, self.vz1_4, self.vz2_4, self.mz1_4)
        cc = [-6823.877+726.18j, 416.375-44.0895j, -159.5+17.29j,
              -3145.08+104.987j, 1458.83+1441.14j, -82.2682-87.3158j,
              41.615+34.2415j, 625.708+706.925j, 2109-223.44j,
              -117.5+13.566j,  61-17.62j, 980.948-32.3036j,
              12088-1284.78j, -719.125+78.0045j, 302.5-30.59j,
              5555.451-185.7457j]
        result = arrayCompare(reshape(A, (-1,)), cc, 1)
        self.failUnless(result)

    def testZgerc(self):
        A = zgerc(12.5-1.33j, self.vz1_4, self.vz2_4, self.mz1_4)
        cc = [-6823.88+726.18j, 416.375-44.0895j, -159.5+17.29j,
              -3096.67+559.987j, 1458.83+1441.14j,-82.2682-87.3158j,
              41.615+34.2415j, 721.585+610.003j, 2109-223.44j,
              -117.5+13.566j, 61-17.62j, 966.052-172.304j,
              12088-1284.78j, -719.125+78.0045j, 302.5-30.59j,
              5469.8-990.746j]
        result = arrayCompare(reshape(A, (-1,)), cc, 1)
        self.failUnless(result)

    def testDsyr(self):
        A = dsyr(1.22, self.v1_4, self.m1_4)
        cc = [207.303, 2, 3, 4,
              -33.857, 13.3231, 7, 8,
              -54.44, 21.956, 30.52, 12,
              -351.78, 82.747, 127.24, 629.38]
        result = arrayCompare(reshape(A, (-1,)), cc, 1)
        self.failUnless(result)

    def testZher(self):
        A = zher(1.22, self.vz1_4, self.mz1_4)
        cc = [207.303+0j, 2+0j, 3+0j, 4+0j,
              -33.857-44.58j, 24.3031+0j, 7+0j, 8+0j,
              -54.44+0j, 21.956-14.64j, 30.52+0j, 12+0j,
              -351.78+0j, 82.747-84.18j, 127.24+0j, 629.38+0j]
        result = arrayCompare(reshape(A, (-1,)), cc, 1)
        self.failUnless(result)

    def testDsyr2(self):
        A = dsyr2(1.22, self.v1_4, self.v2_4, self.m1_4)
        cc = [-1331.12, 2, 3, 4,
              170.981, -9.2439, 7, 8,
              198.1, 0.545, 20.76, 12,
              886.532, -0.07453, 136.902, 1063.19]
        result = arrayCompare(reshape(A, (-1,)), cc, 1)
        self.failUnless(result)

    def testZher2(self):
        A = zher2(12.5-1.33j, self.vz1_4, self.vz2_4, self.mz1_4)
        cc = [-13648.9+0j, 2+0j, 3+0j, 4+0j,
              1873.21+1485.23j, -170.536+0j, 7+0j, 8+0j,
              1946.5-240.73j, -82.885-20.6755j, 111+0j, 12+0j,
              8987.33-1844.77j, -5.54045+-531.999j, 1256.55+141.714j,
              10955.6+0j ]
        result = arrayCompare(reshape(A, (-1,)), cc, 1)
        self.failUnless(result)

    def testDgemm(self):
        C = dgemm(1.22, self.m1_4, self.m2_4, 1, self.m1_4)
        res  = (1.22*dot(self.m1_4, self.m2_4) + self.m1_4) - C
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testZgemm(self):
        C = zgemm(12.5-1.33j, self.mz1_4, self.mz2_4, 1+0j, self.mz1_4)
        res  = ((12.5-1.33j)*dot(self.mz1_4, self.mz2_4) + self.mz1_4) - C
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testDsymm(self):
        C = dsymm(1.22, self.symm, self.m1_4, 2, self.m2_4)
        res = (1.22*dot(self.symm, self.m1_4) + 2*self.m2_4)-C
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testZsymm(self):
        C = zsymm(1.22+2j, self.herm, self.mz1_4, 2+0j, self.mz2_4)
        res = ((1.22+2j)*dot(self.herm, self.mz1_4) + 2*self.mz2_4)-C
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testZhemm(self):
        C = zhemm(1.22+2j, self.herm, self.mz1_4, 2+0j, self.mz2_4)
        res = ((1.22+2j)*dot(self.herm, self.mz1_4) + 2*self.mz2_4)-C
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testDtrmm(self):
        B = dtrmm(1.22, self.triang, self.m2_4)
        res = 1.22*dot(self.triang, self.m2_4)-B
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testZtrmm(self):
        B = ztrmm(1.22+2j, self.triangz, self.mz2_4)
        res = (1.22+2j)*dot(self.triangz, self.mz2_4)-B
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testDtrsm(self):
        I = dtrsm(1, self.triang, self.triang)
        result = arrayIsZero(reshape(I - identity(4, Float), (-1,)))
        self.failUnless(result)

    def testZtrsm(self):
        I = ztrsm(1+0j, self.triangz, self.triangz)
        result = arrayIsZero(reshape(I - identity(4, Complex), (-1,)))
        self.failUnless(result)

    def testDsyrk(self):
        C = dsyrk(-1.2, self.triang, 1.4, self.symm)
        res = -1.2*dot(self.triang, transpose(self.triang)) +1.4* self.symm
        res = res - triang2symm(C)
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testZsyrk(self):
        C = zsyrk(-1.2+2j, self.triangz, 1.4+0j, self.symmz)
        res = ((-1.2+2j)*dot(self.triangz, transpose(self.triangz))
               +1.4* self.symmz)
        res = res - triang2symm(C)
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testZherk(self):
        C = zherk(1, self.mz1_4, 1.44, self.herm)
        res = (dot(self.mz1_4, herm(self.mz1_4))
               +1.44* self.herm)
        res = res - triang2herm(C)
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testDsyr2k(self):
        C = dsyr2k(1.44, self.m1_4, self.m2_4, 1, self.symm)
        res = (1.44* dot(self.m1_4, transpose(self.m2_4)) +
               1.44*dot(self.m2_4, transpose(self.m1_4)) +
               self.symm)
        res = res - triang2symm(C)
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))
        
    def testZsyr2k(self):
        C = zsyr2k(1.44+0j, self.mz1_4, self.mz2_4, 1+0j, self.symmz)
        res = (1.44* dot(self.mz1_4, transpose(self.mz2_4)) +
               1.44*dot(self.mz2_4, transpose(self.mz1_4)) +
               self.symmz)
        res = res - triang2symm(C)
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res))

    def testZher2k(self):
        C = zher2k(1.44+0j, self.mz1_4, self.mz2_4, 1, self.herm)
        res = (1.44* dot(self.mz1_4, herm(self.mz2_4)) +
               1.44*dot(self.mz2_4, herm(self.mz1_4)) +
               self.herm)
        res = res - triang2herm(C)
        res = reshape(res, (-1,))
        self.failUnless(arrayIsZero(res)) 

    def testErrorHandler(self):
        a = arange(10)
        try:
            ddot(a,a[:3])
        except gsl_Error:            
            pass
        
        
if __name__ == '__main__':
    unittest.main()
