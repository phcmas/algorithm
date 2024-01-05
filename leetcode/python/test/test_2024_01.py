import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0411,C0413,R0402,E0401
import year_twenty_four.january.count_the_number_of_good_subarrays as count_the_number


def test_maximum_the_confusion():
    solution0 = count_the_number.Solution()
    solution1 = count_the_number.Solution()

    nums0, k0 = [1, 1, 1, 1, 1], 10
    nums1, k1 = [3, 1, 4, 3, 2, 2, 4], 2

    result0 = solution0.count_good(nums0, k0)
    result1 = solution1.count_good(nums1, k1)

    assert result0 == 1
    assert result1 == 4
