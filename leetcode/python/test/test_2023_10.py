import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0413,R0402
from util import is_same_arrays_ignoring_order

import year_twenty_three.october.largest_divisible_subset_v1 as largest_divisible_subset_v1
import year_twenty_three.october.largest_divisible_subset_v2 as largest_divisible_subset_v2


def test_largest_divisible_subset_v1():
    solution0 = largest_divisible_subset_v1.Solution()
    solution1 = largest_divisible_subset_v1.Solution()
    solution2 = largest_divisible_subset_v1.Solution()

    nums0 = [1, 3, 2]
    nums1 = [1, 2, 4, 8]
    nums2 = [1, 2, 3, 12, 15, 30]

    result0 = solution0.largest_divisible_subset(nums0)
    result1 = solution1.largest_divisible_subset(nums1)
    result2 = solution2.largest_divisible_subset(nums2)

    answer0 = [1, 2]
    answer1 = [1, 2, 4, 8]
    answer2 = [1, 3, 15, 30]

    compare0 = is_same_arrays_ignoring_order(result0, answer0)
    compare1 = is_same_arrays_ignoring_order(result1, answer1)
    compare2 = is_same_arrays_ignoring_order(result2, answer2)

    assert compare0 is True
    assert compare1 is True
    assert compare2 is True


def test_largest_divisible_subset_v2():
    solution0 = largest_divisible_subset_v2.Solution()
    solution1 = largest_divisible_subset_v2.Solution()
    solution2 = largest_divisible_subset_v2.Solution()

    nums0 = [1, 3, 2]
    nums1 = [1, 2, 4, 8]
    nums2 = [1, 2, 3, 12, 15, 30]

    result0 = solution0.largest_divisible_subset(nums0)
    result1 = solution1.largest_divisible_subset(nums1)
    result2 = solution2.largest_divisible_subset(nums2)

    answer0 = [1, 2]
    answer1 = [1, 2, 4, 8]
    answer2 = [1, 3, 15, 30]

    compare0 = is_same_arrays_ignoring_order(result0, answer0)
    compare1 = is_same_arrays_ignoring_order(result1, answer1)
    compare2 = is_same_arrays_ignoring_order(result2, answer2)

    assert compare0 is True
    assert compare1 is True
    assert compare2 is True
