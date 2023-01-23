import sys
from os.path import dirname, abspath, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_three.january.number_of_arithmetic_triplets as arithmetic_triplets
import year_twenty_three.january.sum_of_beauty_of_all_substrings as beauty_sum


def test_arithmetic_triplets():
    solution0 = arithmetic_triplets.Solution()
    solution1 = arithmetic_triplets.Solution()
    solution2 = arithmetic_triplets.Solution()
    solution3 = arithmetic_triplets.Solution()

    nums0 = [0, 1, 4, 6, 7, 10]
    nums1 = [4, 5, 6, 7, 8, 9]
    nums2 = [1, 2, 3, 6, 11, 15, 16]
    nums3 = [2, 6, 8]

    diff0 = 3
    diff1 = 2
    diff2 = 5
    diff3 = 1

    result0 = solution0.arithmetic_triplets(nums0, diff0)
    result1 = solution1.arithmetic_triplets(nums1, diff1)
    result2 = solution2.arithmetic_triplets(nums2, diff2)
    result3 = solution3.arithmetic_triplets(nums3, diff3)

    answer0 = 2
    answer1 = 2
    answer2 = 2
    answer3 = 0

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2
    assert result3 == answer3


def test_beauty_sum():
    solution0 = beauty_sum.Solution()
    solution1 = beauty_sum.Solution()

    s0 = "aabcb"
    s1 = "aabcbaa"

    result0 = solution0.beauty_sum(s0)
    result1 = solution1.beauty_sum(s1)

    answer0 = 5
    answer1 = 17

    assert result0 == answer0
    assert result1 == answer1
