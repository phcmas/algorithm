import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.november.sparse_matrix_multiplication as sparse_matrix_multiplication
import year_twenty_five.november.maximum_value_at_a_given_index_in_a_bounded_array as max_value


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


def test_max_value():
    solution = max_value.Solution()

    n0, index0, max_sum0 = 4, 2, 6
    n1, index1, max_sum1 = 6, 1, 10
    n2, index2, max_sum2 = 8, 7, 14
    n3, index3, max_sum3 = 4, 0, 4

    ret0 = solution.max_value(n0, index0, max_sum0)
    ret1 = solution.max_value(n1, index1, max_sum1)
    ret2 = solution.max_value(n2, index2, max_sum2)
    ret3 = solution.max_value(n3, index3, max_sum3)

    assert ret0 == 2
    assert ret1 == 3
    assert ret2 == 4
    assert ret3 == 1
