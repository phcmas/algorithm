import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.december.make_sum_divisible_by_p as min_subarray


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
