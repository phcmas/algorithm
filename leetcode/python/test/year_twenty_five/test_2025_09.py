import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.september.campus_bikes_ii as assign_bikes
import year_twenty_five.september.can_i_win as can_i_win
import year_twenty_five.september.largest_unique_number as largest_unique_number
import year_twenty_five.september.number_of_matching_subsequences as num_matching_subseq
import year_twenty_five.september.maximum_distance_between_a_pair_of_values as max_distance


def test_assign_bikes():
    solution = assign_bikes.Solution()

    workers0 = [[0, 0], [2, 1]]
    workers1 = [[0, 0], [1, 1], [2, 0]]
    workers2 = [[0, 0], [1, 0], [2, 0], [3, 0], [4, 0]]

    bikes0 = [[1, 2], [3, 3]]
    bikes1 = [[1, 0], [2, 2], [2, 1]]
    bikes2 = [[0, 999], [1, 999], [2, 999], [3, 999], [4, 999]]

    ret0 = solution.assign_bikes(workers0, bikes0)
    ret1 = solution.assign_bikes(workers1, bikes1)
    ret2 = solution.assign_bikes(workers2, bikes2)

    assert ret0 == 6
    assert ret1 == 4
    assert ret2 == 4995


def test_can_i_win():
    solution = can_i_win.Solution()

    max_int0, total0 = 10, 11
    max_int1, total1 = 10, 0
    max_int2, total2 = 10, 1
    max_int3, total3 = 5, 50

    ret0 = solution.can_i_win(max_int0, total0)
    ret1 = solution.can_i_win(max_int1, total1)
    ret2 = solution.can_i_win(max_int2, total2)
    ret3 = solution.can_i_win(max_int3, total3)

    assert ret0 is False
    assert ret1 is True
    assert ret2 is True
    assert ret3 is False


def test_largest_unique_number():
    solution = largest_unique_number.Solution()

    nums0 = [5, 7, 3, 9, 4, 9, 8, 3, 1]
    nums1 = [9, 9, 8, 8]

    ret0 = solution.largest_unique_number(nums0)
    ret1 = solution.largest_unique_number(nums1)

    assert ret0 == 8
    assert ret1 == -1


def test_num_matching_subseq():
    solution = num_matching_subseq.Solution()

    s0, words0 = "abcde", ["a", "bb", "acd", "ace"]
    s1, words1 = "dsahjpjauf", ["ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"]

    ret0 = solution.num_matching_subseq(s0, words0)
    ret1 = solution.num_matching_subseq(s1, words1)

    assert ret0 == 3
    assert ret1 == 2


def test_max_distance():
    solution = max_distance.Solution()

    nums01, nums02 = [55, 30, 5, 4, 2], [100, 20, 10, 10, 5]
    nums11, nums12 = [2, 2, 2], [10, 10, 1]
    nums21, nums22 = [30, 29, 19, 5], [25, 25, 25, 25, 25]

    ret0 = solution.max_distance(nums01, nums02)
    ret1 = solution.max_distance(nums11, nums12)
    ret2 = solution.max_distance(nums21, nums22)

    assert ret0 == 2
    assert ret1 == 1
    assert ret2 == 2
