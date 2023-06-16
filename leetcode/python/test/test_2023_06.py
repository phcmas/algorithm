import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0413,R0402
import year_twenty_three.june.maximum_number_of_occurrences_of_a_substring as max_frequency
import year_twenty_three.june.smallest_subsequence_of_distinct_characters as smallest_subsequence


def test_maximum_number_of_occurences_of_a_substring():
    solution0 = max_frequency.Solution()
    solution1 = max_frequency.Solution()
    solution2 = max_frequency.Solution()

    s0 = "aababcaab"
    max_letters0, min_size0, max_size0 = 2, 3, 4

    s1 = "aaaa"
    max_letters1, min_size1, max_size1 = 1, 3, 3

    s2 = "abcde"
    max_letters2, min_size2, max_size2 = 2, 3, 3

    answer0 = 2
    answer1 = 2
    answer2 = 0

    result0 = solution0.max_freq(s0, max_letters0, min_size0, max_size0)
    result1 = solution1.max_freq(s1, max_letters1, min_size1, max_size1)
    result2 = solution2.max_freq(s2, max_letters2, min_size2, max_size2)

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2


def test_smallest_subsequence():
    solution0 = smallest_subsequence.Solution()
    solution1 = smallest_subsequence.Solution()

    s0 = "bcabc"
    s1 = "cbacdcbc"

    answer0 = "abc"
    answer1 = "acdb"

    result0 = solution0.smallest_subsequence(s0)
    result1 = solution1.smallest_subsequence(s1)

    assert result0 == answer0
    assert result1 == answer1
