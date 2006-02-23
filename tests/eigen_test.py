# Author : Fabian Jakobs 
import unittest
import pygsl._numobj as Numeric
from gsl_test import *
from pygsl.eigen import *
import pygsl.blas

class EigenTestCase(GSLTestCase):
    def testEigenvectors(self):
        a = self.symm
        (eval, evec) = eigenvectors(a)
        evec = transpose(evec)
        result = 1
        for i in range(eval.shape[0]):
            res = dot(self.symm, evec[i])- evec[i]*eval[i]
            res = reshape(res, (-1,))
            result = result and arrayIsZero(res)
        self.failUnless(result)

    def testEigenvalues(self):
        a = self.symm
        eval1 = eigenvectors(a)[0]
        eval2 = eigenvalues(a)
        self.failUnless(arrayIsZero(eval1-eval2))

    def testHeigenvectors(self):
        a = self.herm
        (eval, evec) = Heigenvectors(a)
        evec = transpose(evec)
        result = 1
        for i in range(eval.shape[0]):
            res = dot(self.symm, evec[i])- evec[i]*eval[i]
            res = reshape(res, (-1,))
            result = result and arrayIsZero(res)
        self.failUnless(result)

    def testHeigenvalues(self):
        a = self.herm
        eval1 = Heigenvectors(a)[0]
        eval2 = Heigenvalues(a)
        self.failUnless(arrayIsZero(eval1-eval2))
    
            
if __name__ == '__main__':
    unittest.main()
