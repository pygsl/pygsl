from __future__ import print_function, division, absolute_import
import unittest
import numpy as np
import pygsl
pygsl.add_c_traceback_frames(True)
from pygsl.sparse import matrix as sparse_matrix
#pygsl.set_debug_level(4)
class TestSPMatrix_0(unittest.TestCase):
    size1 = 10
    size2 = 20

    def test0_StdAlloc(self):
        "Allocating using size1 and size2"
        sp = sparse_matrix.sparse_matrix(self.size1, self.size2)
        self.assertTrue(sp.thisown)

    def test1_StdAlloc(self):
        "Allocating using size1 and size2"
        sp = sparse_matrix.sparse_matrix(self.size1, self.size2, 50, 0)
        self.assertTrue(sp.thisown)

    def test2_StdAlloc(self):
        "Allocating using size1 and size2 with invalid type"
        self.assertRaises(SystemError, sparse_matrix.sparse_matrix, self.size1, self.size2, 50, 50)



class _TestSPMatrix_1(unittest.TestCase):
    """Standard case ... triplet matrix
    """
    size1 = 10
    size2 = 20
    def convertSparseMatrix(self):
        return

    def setUp(self):
        sp = sparse_matrix.sparse_matrix(self.size1, self.size2)
        self.sp = sp

        t_sets = (
            ( (0, 2), 3.1),
            ( (0, 2), 3.1),
            ( (0, 3), 4.6),
            ( (1, 0), 1.0),
            ( (1, 2), 7.2),
            ( (3, 0), 2.1),
            ( (3, 1), 2.9),
            ( (3, 3), 8.5),
            ( (4, 0), 4.1),
        )

        def f(arg):
            indices, val = arg
            i, j = indices
            sp.set(i, j, val)

        tmp = [f(a_elem) for a_elem in t_sets]

        val_dic = {}
        def f2(arg):
            val_dic[arg[0]] = arg[1]
        [f2(x) for x in t_sets]

        self.val_dic = val_dic

    def test0_OwnerShip(self):
        """Make sure swig set the owner ship correctly
        """
        self.assertTrue(self.sp.thisown)

    def checkSetValues(self, sparse_matrix):
        """Check that all set values are matching and that all other values are
        None
        """
        sp = sparse_matrix
        val_dic = self.val_dic
        for i in range(self.size1):
            for j in range(self.size2):
                tmp = (i, j)
                val = sp.get_val_or_none(*tmp)
                try:
                    ref_val = val_dic[tmp]
                except KeyError:
                    ref_val = None
                self.assertEqual(sp.get_val_or_none(i, j), ref_val)

    def checkSetValuesMatrix(self, mat):
        val_dic = self.val_dic
        for i in range(self.size1):
            for j in range(self.size2):
                tmp = (i, j)
                try:
                    ref_val = val_dic[tmp]
                except KeyError:
                    ref_val = 0.0
                self.assertAlmostEqual(mat[i, j], ref_val)

    def checkTransposedSetValues(self, sparse_matrix):
        """Check that all set values are matching the transposed matrix
        """
        sp = sparse_matrix
        val_dic = self.val_dic
        for i in range(self.size1):
            for j in range(self.size2):
                tmp = (j, i)
                val = sp.get_val_or_none(*tmp)
                try:
                    ref_val = val_dic[tmp]
                except KeyError:
                    ref_val = None
                self.assertEqual(sp.get_val_or_none(i, j), ref_val)

    def test01_Setting(self):
        """Testing set/get for some elements
        """
        self.checkSetValues(self.sp)

    def test03_set_zero(self):
        """Setting all elements to zeros: element value
        """
        sp = self.sp
        sp.set_zero()
        val_dic = self.val_dic

        for i in range(self.size1):
            for j in range(self.size2):
                tmp = (i, j)
                val = sp.get(*tmp)
                self.assertAlmostEqual(val, 0.0)
  
    def test04_Scale(self):
        """Testing scaling matrix
        """
        sp = self.sp

        t_scale = 42
        val_dic = self.val_dic

        sp.scale(t_scale)

        for i in range(self.size1):
            for j in range(self.size2):
                tmp = (i, j)
                val = sp.get_val_or_none(*tmp)
                try:
                    ref_val = val_dic[tmp]
                    ref_val *= t_scale
                except KeyError:
                    ref_val = None
                self.assertEqual(sp.get_val_or_none(i, j), ref_val)

    def test05_minmax(self):
        """Test minimum maximum values
        """
        t_min, t_max = self.sp.minmax()
        self.assertAlmostEqual(t_min, 1.0)
        self.assertAlmostEqual(t_max, 8.5)

        self.sp.set(self.size1 - 1, self.size2 -1 , 42)
        self.sp.set(self.size1 - 2, self.size2 -1 , -355.0/113.0)
        t_min, t_max = self.sp.minmax()
        self.assertAlmostEqual(t_max, 42)
        self.assertAlmostEqual(t_min, -np.pi, 5)

    def test06_shape_function(self):
        """Test the shape of the matrix: function
        """
        shape = self.sp.get_shape()
        self.assertEqual(self.size1, shape[0])
        self.assertEqual(self.size2, shape[1])

    def test07_shape_property(self):
        """Test the shape of the matrix: property
        """
        shape = self.sp.shape
        self.assertEqual(self.size1, shape[0])
        self.assertEqual(self.size2, shape[1])

    def test08_transpose_inplace(self):
        """Check transposed matrix"""

        sp = self.sp
        sp.transpose_inplace()
        self.checkTransposedSetValues(sp)

    def test09_memcpy(self):
        """Test memcpy
        """
        sparse_matrix = self.sp.memcpy()
        self.assertTrue(sparse_matrix.thisown)
        self.checkSetValues(sparse_matrix)

    def test10_transpose_memcpy(self):
        """Test transpose_memcpy
        """
        sparse_matrix = self.sp.transpose_memcpy()
        self.assertTrue(sparse_matrix.thisown)
        self.checkTransposedSetValues(sparse_matrix)

    def test11_equal(self):
        """Test equality using method
        """
        sparse_matrix = self.sp.memcpy()
        self.assertTrue(self.sp.equal(sparse_matrix))

    def test12_equal(self):
        """Test equality using __eq__
        """
        sparse_matrix = self.sp.memcpy()
        flag = self.sp == sparse_matrix
        self.assertTrue(flag)

    def test13_unequal(self):
        """Test not fitting equality
        """
        sparse_matrix = self.sp.memcpy()
        sparse_matrix.scale(2.0)
        self.assertFalse(self.sp.equal(sparse_matrix))

    def test14_unequal(self):
        """Test not fitting equality using __eq__
        """
        sparse_matrix = self.sp.memcpy()
        sparse_matrix.scale(2.0)
        self.assertFalse(sparse_matrix == self.sp)

    def test15_to_array(self):    
        mat = self.sp.sp2d()
        self.assertEqual(mat.shape, self.sp.shape)
        self.checkSetValuesMatrix(mat)

    def test16_from_array(self):
        mat = np.ones((self.size1, self.size2))
        self.sp.d2sp(mat)
        for i in range(self.size1):
            for j in range(self.size2):
                self.assertAlmostEqual(self.sp.get(i,j), 1.0)

        t_type = self.sp.type_code()
        self.assertEqual(t_type, sparse_matrix.Form.TRIPLET)

class TestSPMatrixTriplet(_TestSPMatrix_1):
    """Methods only working for triplets
    """
    type_code = sparse_matrix.Form.TRIPLET
    def test2_set_zero(self):
        """Setting all elements to zeros: ptr

        Triplets apparently clear the "tree"
        """
        sp = self.sp
        sp.set_zero()
        val_dic = self.val_dic

        for i in range(self.size1):
            for j in range(self.size2):
                tmp = (i, j)
                val = sp.get_val_or_none(*tmp)
                self.assertEqual(val, None)

class TestSPMatrixCCS_2(_TestSPMatrix_1):
    type_code = sparse_matrix.Form.CCS
    def convertSparseMatrix(self):
        sp = self.sp
        t_ccs = sp.ccs()
        self.sp = t_ccs

class TestSPMatrixCRS_3(_TestSPMatrix_1):
    type_code = sparse_matrix.Form.CRS
    def convertSparseMatrix(self):
        sp = self.sp
        t_ccs = sp.crs()
        self.sp = t_ccs


del _TestSPMatrix_1

if __name__ == '__main__':
    unittest.main()
