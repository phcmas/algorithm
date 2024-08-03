import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# ruff: noqa
import year_twenty_four.august.minimum_length_of_string_after_deleting_similar_ends as minimum_length_of_string


def test_minimum_number_of_operations():
    solution = minimum_length_of_string.Solution()

    s0 = "ca"
    s1 = "cabaabac"
    s2 = "aabccabba"
    s3 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb"

    result0 = solution.minimum_length(s0)
    result1 = solution.minimum_length(s1)
    result2 = solution.minimum_length(s2)
    result3 = solution.minimum_length(s3)

    assert result0 == 2
    assert result1 == 0
    assert result2 == 3
    assert result3 == 1
