import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.december.make_sum_divisible_by_p as min_subarray
import year_twenty_five.december.merge_sorted_array as merge_sorted_array
import year_twenty_five.december.remove_element as remove_element
import year_twenty_five.december.remove_duplicates_from_sorted_array as remove_duplicates_from_sorted_array


def test_min_subarray():
    solution = min_subarray.Solution()

    nums0, p0 = [3, 1, 4, 2], 6
    nums1, p1 = [6, 3, 5, 2], 9
    nums2, p2 = [1, 2, 3], 3
    nums3, p3 = [1, 2, 3], 7
    nums4, p4 = [3, 2, 2, 4, 6, 1, 6, 5], 7
    nums5, p5 = [1, 1, 1], 2

    ret0 = solution.min_subarray(nums0, p0)
    ret1 = solution.min_subarray(nums1, p1)
    ret2 = solution.min_subarray(nums2, p2)
    ret3 = solution.min_subarray(nums3, p3)
    ret4 = solution.min_subarray(nums4, p4)
    ret5 = solution.min_subarray(nums5, p5)

    assert ret0 == 1
    assert ret1 == 2
    assert ret2 == 0
    assert ret3 == -1
    assert ret4 == 1
    assert ret5 == 1


def test_merge_sorted_array():
    solution = merge_sorted_array.Solution()

    nums01, nums02, m0, n0 = [1, 2, 3, 0, 0, 0], [2, 5, 6], 3, 3
    nums11, nums12, m1, n1 = [1], [], 1, 0
    nums21, nums22, m2, n2 = [0], [1], 0, 1
    nums31, nums32, m3, n3 = [2, 0], [1], 1, 1

    solution.merge(nums01, m0, nums02, n0)
    solution.merge(nums11, m1, nums12, n1)
    solution.merge(nums21, m2, nums22, n2)
    solution.merge(nums31, m3, nums32, n3)

    assert nums01 == [1, 2, 2, 3, 5, 6]
    assert nums11 == [1]
    assert nums21 == [1]
    assert nums31 == [1, 2]


def test_remove_element():
    solution = remove_element.Solution()

    nums0, val0 = [3, 2, 2, 3], 3
    nums1, val1 = [0, 1, 2, 2, 3, 0, 4, 2], 2
    nums2, val2 = [2], 3
    nums3, val3 = [1], 1
    nums4, val4 = [4, 5], 4

    ret0 = solution.remove_element(nums0, val0)
    ret1 = solution.remove_element(nums1, val1)
    ret2 = solution.remove_element(nums2, val2)
    ret3 = solution.remove_element(nums3, val3)
    ret4 = solution.remove_element(nums4, val4)

    assert sorted(nums0[:ret0]) == [2, 2]
    assert sorted(nums1[:ret1]) == [0, 0, 1, 3, 4]
    assert sorted(nums2[:ret2]) == [2]
    assert sorted(nums3[:ret3]) == []
    assert sorted(nums4[:ret4]) == [5]


def test_remove_duplicates_from_sorted_array():
    solution = remove_duplicates_from_sorted_array.Solution()

    nums0 = [1, 1, 2]
    nums1 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

    ret0 = solution.remove_duplicates(nums0)
    ret1 = solution.remove_duplicates(nums1)

    assert sorted(nums0[:ret0]) == [1, 2]
    assert sorted(nums1[:ret1]) == [0, 1, 2, 3, 4]
