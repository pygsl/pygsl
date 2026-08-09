# Author : Fabian Jakobs
import unittest
import pygsl._numobj as Numeric
from gsl_test import *
from pygsl.eigen import *
import pygsl.blas

class EigenTestCase(GSLTestCase):
    def testEigenvectorsNonSymm(self):
        a = self.symm
        (n_evals, eval, evec, Z) = eigenvectors_nonsymm(a, balance=True, compute_t=True, schur=True)
        # eigen_nonsmmv_sort(eval, evec, SortType.abs_asc)
        print(eigen_nonsymmv_sort.__doc__)
        print(eval)
        print(Z)
        Z = transpose(Z)
        eval, Z = eigen_nonsymmv_sort(eval, Z, SortType.abs_asc)
        # print("nonsymmv", res)
        print("nonsymm", n_evals)
        print(eval)
        print(Z)
        result = 1
        for i in range(eval.shape[0]):
            res = dot(self.symm, Z[i])- Z[i]*eval[i]
            res = reshape(res, (-1,))
            print("iszero?", res)
            result = result and arrayIsZero(res)
        self.assertTrue(result)

    def testEigenvectors(self):
        a = self.symm
        (eval, evec) = eigenvectors(a)
        evec = transpose(evec)
        print("symm", eval, evec)
        result = 1
        for i in range(eval.shape[0]):
            res = dot(self.symm, evec[i])- evec[i]*eval[i]
            res = reshape(res, (-1,))
            print("iszero?", res)
            result = result and arrayIsZero(res)
        self.assertTrue(result)
        self.assertTrue(False)

    def testEigenvalues(self):
        a = self.symm
        eval1 = eigenvectors(a)[0]
        eval2 = eigenvalues(a)
        self.assertTrue(arrayIsZero(eval1-eval2))

    def testHeigenvectors(self):
        a = self.herm
        (eval, evec) = Heigenvectors(a)
        evec = transpose(evec)
        result = 1
        for i in range(eval.shape[0]):
            res = dot(self.symm, evec[i])- evec[i]*eval[i]
            res = reshape(res, (-1,))
            result = result and arrayIsZero(res)
        self.assertTrue(result)

    def testHeigenvalues(self):
        a = self.herm
        eval1 = Heigenvectors(a)[0]
        eval2 = Heigenvalues(a)
        self.assertTrue(arrayIsZero(eval1-eval2))


if __name__ == '__main__':
    unittest.main()
