import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.november.sparse_matrix_multiplication as sparse_matrix_multiplication


def test_multiply():
    solution = sparse_matrix_multiplication.Solution()

    mat01, mat02 = [[1, 0, 0], [-1, 0, 3]], [[7, 0, 0], [0, 0, 0], [0, 0, 1]]
    mat11, mat12 = [[0]], [[0]]
    mat21, mat22 = [[1, -5]], [[12], [-1]]

    ret0 = solution.multiply(mat01, mat02)
    ret1 = solution.multiply(mat11, mat12)
    ret2 = solution.multiply(mat21, mat22)

    assert ret0 == [[7, 0, 0], [-7, 0, 3]]
    assert ret1 == [[0]]
    assert ret2 == [[17]]
