# Author : Fabian Jakobs
import unittest
import pygsl
from pygsl.linalg import *
from gsl_test import *
import pygsl._numobj as numx

class LinalgTestCase(GSLTestCase):
    def testLU_decomp(self):
        (lu, p, s) = LU_decomp(self.m1_4)
        (l,u) = LU_unpack(lu)
        dot = numx.dot(l,u)
        result = zeros((4,4), Float)
        for i in range(len(p)):
            result[p[i]] = dot[i]
        result =  reshape(result-self.m1_4, (-1,))
        res = 1
        for i in result:
            res = res and abs(i) < 0.000000001
        self.failUnless(res)

    def testLU_solve(self):
        A = array([[1,2], [1,3]], Float)
        b = array([3,4], Float)
        (lu, p, s) = LU_decomp(A)
        x = LU_solve(lu, p, b)
        self.failUnless(x[0] == 1 and x[1] == 1)

    def testLU_solve_complex(self):
        A = array([[1,2], [1,3]], Complex)
        b = array([3,4], Complex)
        (lu, p, s) = LU_decomp(A)
        x = LU_solve(lu, p, b)
        self.failUnless(x[0] == 1 and x[1] == 1)

    def testLU_invert(self):
        (lu, p, s) = LU_decomp(self.m1_4)
        invert = LU_invert(lu,p)
        result = reshape(dot(self.m1_4, invert)-identity(4), (-1,))
        res = 1
        for i in result:
            res = res and abs(i) < 0.0000000001
        self.failUnless(res)

    def testLU_det(self):
        (lu, p, s) = LU_decomp(self.m1_4)
        det = LU_det(lu,s)
        result = fpcompare(det, 15.744, 3)
        self.failUnless(result)

    def testLU_lndet(self):
        (lu, p, s) = LU_decomp(self.m1_4)
        lndet = LU_lndet(lu)
        result = fpcompare(lndet, numx.log(15.744), 3)
        self.failUnless(result)
        
    def testLU_sgndet(self):
        (lu, p, s) = LU_decomp(self.m1_4)
        det = LU_sgndet(lu,s)
        self.failUnless(det == 1)

    def testSV_decomp(self):
        (u, v, s) = SV_decomp(self.m1_4)
        result =  dot(dot(u, identity(4)*s), transpose(v))-self.m1_4
        result = reshape(result, (-1,))
        res = 1
        for i in result:
            res = res and abs(i) < 0.000000001
        self.failUnless(res)

    def testSV_decomp_mod(self):
        (u, v, s) = SV_decomp_mod(self.m1_4)
        result =  dot(dot(u, identity(4)*s), transpose(v))-self.m1_4
        result = reshape(result, (-1,))
        res = 1
        for i in result:
            res = res and abs(i) < 0.000000001
        self.failUnless(res)

    def testSV_decomp_jacobi(self):
        (u, v, s) = SV_decomp_jacobi(self.m1_4)
        result =  dot(dot(u, identity(4)*s), transpose(v))-self.m1_4
        result = reshape(result, (-1,))
        res = 1
        for i in result:
            res = res and abs(i) < 0.000000001
        self.failUnless(res)

    def testSV_solve(self):
        A = array([[1,2], [1,3]], Float)
        b = array([3,4], Float)
        (u,v,s) = SV_decomp(A)
        x = SV_solve(u, v, s, b)
        result = arrayCompare(x, [1,1], 8)
        self.failUnless(result)

    def testCholesky_decomp(self):
        posdef = array([[5,1,1], [1,1,1], [1,1,2]], Float)
        L = cholesky_decomp(posdef)
        (l,lt) = cholesky_unpack(L)
        result = reshape(dot(l, lt)-posdef, (-1,))
        res = 1
        for i in result:
            res = res and abs(i) < 0.000000001
        self.failUnless(res)

    def testCholesky_solve(self):
        posdef = array([[5,1,1], [1,1,1], [1,1,2]], Float)
        b = array([6,2,1], Float)
        L = cholesky_decomp(posdef)
        x = cholesky_solve(L, b)
        result = arrayCompare(x, [1,2,-1], 8)
        self.failUnless(result)

    def testQR_decomp(self):
        (QR, tau) = QR_decomp(self.m1_4)
        (q,r) = QR_unpack(QR, tau)
        result = reshape(dot(q,r) - self.m1_4, (-1,))
        res = 1
        for i in result:
            res = res and abs(i) < 0.000000001
        self.failUnless(res)

    def testQR_solve(self):
        A = array([[1,2], [1,3]], Float)
        b = array([3,4], Float)
        (qr,tau) = QR_decomp(A)
        x = QR_solve(qr, tau, b)
        result = arrayCompare(x, [1,1], 8)
        self.failUnless(result)

    def testQR_lssolve(self):
        A = array([[1,2],[1,3],[3,4],[2,5]], Float)
        b = array([1,1,1,1], Float)
        (qr,tau) = QR_decomp(A)
        (x, res) = QR_lssolve(qr, tau, b)
        assert(numx.absolute(x[0]) < 1e-7)
        assert(numx.absolute(x[1] - 0.25925) < 1e-4)        
        res2 = arrayCompare(res, [0.48148, 0.2222, -0.037037037, -0.296296], 4)
        self.failUnless(res2)

    def testQR_QTvec(self):
        (qr, tau) = QR_decomp(self.m1_4)
        v = array([1,2,3,4], Float)
        v1 = QR_QTvec(qr, tau, v)
        (q,r) = QR_unpack(qr, tau)
        v2 = dot(transpose(q), v)
        result = reshape(v1-v2, [-1,])
        res = 1
        for i in result:
            res = res and abs(i) < 0.0000001
        self.failUnless(res)
        
    def testQR_Qvec(self):
        (qr, tau) = QR_decomp(self.m1_4)
        v = array([1,2,3,4], Float)
        v1 = QR_Qvec(qr, tau, v)
        (q,r) = QR_unpack(qr, tau)
        v2 = dot(q, v)
        result = reshape(v1-v2, [-1,])
        res = 1
        for i in result:
            res = res and abs(i) < 0.0000001
        self.failUnless(res)

    def testQR_QRsolve(self):
        A = array([[1,2], [1,3]], Float)
        b = array([3,4], Float)
        (qr, tau) = QR_decomp(A)
        (q,r) = QR_unpack(qr, tau)
        x = QR_QRsolve(q, r, b)
        result = arrayCompare(x, [1,1], 8)
        self.failUnless(result)

##     def testQR_update(self):
##         (qr, tau) = QR_decomp(self.m1_4)
##         (q,r) = QR_unpack(qr, tau)
##         w = array([1,2,3,4], Float)
##         v = array([1,1,1,2], Float)
##         QR_update(q,r,w,v)
##         res1 =  matrixmultiply(q,r)
##         w.shape = [4,1]
##         v.shape = [1,4]
##         res2 = self.m1_4 + matrixmultiply(w,v)
##         print res1 -res2

    def testSymmtd(self):
        (A, tau) = symmtd_decomp(self.symm)
        (Q, diag, subdiag) = symmtd_unpack(A, tau)
        T = symmtd_unpack_diag(diag, subdiag)
        result = reshape(dot(dot(Q,T), transpose(Q)) - self.symm, (-1,))
        self.failUnless(arrayIsZero(result))

    def testSymmtd_decomp(self):
        (A, tau) = symmtd_decomp(self.symm)
        (Q, diag1, subdiag1) = symmtd_unpack(A, tau)
        (diag2, subdiag2) = symmtd_unpack_T(A)
        result = arrayIsZero(diag2-diag1) and arrayIsZero(subdiag1-subdiag2)
        self.failUnless(result)
        
    def testHermtd(self):
        (A, tau) = hermtd_decomp(self.herm)
        (Q, diag, subdiag) = hermtd_unpack(A, tau)
        T = hermtd_unpack_diag(diag, subdiag)
        result = reshape(dot(dot(Q,T), transpose(Q)) - self.symm, (-1,))
        self.failUnless(arrayIsZero(result))

    def testHermtd_decomp(self):
        (A, tau) = hermtd_decomp(self.herm)
        (Q, diag1, subdiag1) = hermtd_unpack(A, tau)
        (diag2, subdiag2) = symmtd_unpack_T(A)
        result = arrayIsZero(diag2-diag1) and arrayIsZero(subdiag1-subdiag2)
        self.failUnless(result)

    def testBidiag(self):
        Ain = resize(self.m1_4, [3,2])
        (A, tau_U, tau_V) = bidiag_decomp(Ain)
        (U, V, diag, superdiag) = bidiag_unpack(A, tau_U, tau_V)
        B = bidiag_unpack_diag(diag, superdiag)
        result = reshape(dot(dot(U,B), transpose(V)) - Ain, (-1,))
        self.failUnless(arrayIsZero(result))

##     def testHermtd_decomp(self):
##         Ain = resize(self.m1_4, [3,2])
##         (A, tau_U, tau_V) = bidiag_decomp(Ain)
##         (U, V, diag1, superdiag1) = bidiag_unpack(A, tau_U, tau_V)
##         (diag2, superdiag2) = bidiag_unpack_B(A)
##         result = (arrayIsZero(diag2-diag1) and
##                   arrayIsZero(superdiag1-superdiag2))
##         self.failUnless(result)

    def testHHsolve(self):
        A = array([[1,2], [1,3]], Float)
        b = array([3,4], Float)
        x = HH_solve(A, b)
        result = arrayCompare(x, [1.0,1.0], 5)
        self.failUnless(result)

    def testSolve_symm_tridiag(self):
        diag = array([1.0,1,1,1])
        e = array([2.0,2,2])
        b = array([5,6,9,4.0])
        x = solve_symm_tridiag(diag, e, b)
        result = arrayCompare(x, [1,2,1,2.0], 7)
        self.failUnless(result)

    def testSolve_symm_cyc_tridiag(self):
        diag = array([1,1,1,1], Float)
        e = array([2,2,2,2], Float)
        b = array([9,6,9,6], Float)
        x = solve_symm_cyc_tridiag(diag, e, b)
        result = arrayCompare(x, [1,2,1,2.0], 7)
        self.failUnless(result)

if __name__ == '__main__':
    unittest.main()




