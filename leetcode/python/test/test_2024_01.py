import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0411,C0413,R0402,E0401
import year_twenty_four.january.count_the_number_of_good_subarrays as count_the_number
import year_twenty_four.january.edit_distance as edit_distance
import year_twenty_four.january.remove_duplicates_from_sorted_array as remove_duplicates


def test_maximum_the_confusion():
    solution0 = count_the_number.Solution()
    solution1 = count_the_number.Solution()

    nums0, k0 = [1, 1, 1, 1, 1], 10
    nums1, k1 = [3, 1, 4, 3, 2, 2, 4], 2

    result0 = solution0.count_good(nums0, k0)
    result1 = solution1.count_good(nums1, k1)

    assert result0 == 1
    assert result1 == 4


def test_min_distance():
    solution0 = edit_distance.Solution()
    solution1 = edit_distance.Solution()

    word01, word02 = "horse", "ros"
    word11, word12 = "intention", "execution"

    result0 = solution0.min_distance(word01, word02)
    result1 = solution1.min_distance(word11, word12)

    assert result0 == 3
    assert result1 == 5


def test_remove_duplicates():
    solution0 = remove_duplicates.Solution()
    solution1 = remove_duplicates.Solution()

    nums0 = [1, 1, 2]
    nums1 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

    result0 = solution0.remove_duplicates(nums0)
    result1 = solution1.remove_duplicates(nums1)

    answer0 = 2
    answer1 = 5

    assert result0 == answer0
    assert result1 == answer1
