import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_four.december.diagonal_traverse_ii as diagonal_traverse_ii
import year_twenty_four.december.maximum_distance_in_arrays as maximum_distance_in_arrays
import year_twenty_four.december.zero_array_transformation as zero_array_transformation
import year_twenty_four.december.find_first_and_last_position_of_element_in_sorted_array as find_first_and_last


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


def test_zero_array_transformation():
    solution = zero_array_transformation.Solution()

    nums0 = [1, 0, 1]
    queries0 = [[0, 2]]

    nums1 = [4, 3, 2, 1]
    queries1 = [[1, 3], [0, 2]]

    result0 = solution.is_zero_array(nums0, queries0)
    result1 = solution.is_zero_array(nums1, queries1)

    assert result0 is True
    assert result1 is False


def test_first_and_last():
    solution = find_first_and_last.Solution()

    nums0 = [5, 7, 7, 8, 8, 10]
    target0 = 8

    nums1 = [5, 7, 7, 8, 8, 10]
    target1 = 6

    nums2 = []
    target2 = 0

    result0 = solution.search_range(nums0, target0)
    result1 = solution.search_range(nums1, target1)
    result2 = solution.search_range(nums2, target2)

    assert result0 == [3, 4]
    assert result1 == [-1, -1]
    assert result2 == [-1, -1]
