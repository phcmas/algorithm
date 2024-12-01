import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_four.december.diagonal_traverse_ii as diagonal_traverse_ii
import year_twenty_four.december.maximum_distance_in_arrays as maximum_distance_in_arrays


def test_diagonal_traverse_ii():
    solution = diagonal_traverse_ii.Solution()

    nums0 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    nums1 = [[1, 2, 3, 4, 5], [6, 7], [8], [9, 10, 11], [12, 13, 14, 15, 16]]

    result0 = solution.find_diagonal_order(nums0)
    result1 = solution.find_diagonal_order(nums1)

    assert result0 == [1, 4, 2, 7, 5, 3, 8, 6, 9]
    assert result1 == [1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16]


def test_maximum_distance_in_arrays():
    solution = maximum_distance_in_arrays.Solution()

    arrays0 = [[1, 2, 3], [4, 5], [1, 2, 3]]
    arrays1 = [[1], [1]]

    result0 = solution.max_distance(arrays0)
    result1 = solution.max_distance(arrays1)

    assert result0 == 4
    assert result1 == 0
