import sys
from os.path import abspath, dirname, join


SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# ruff: noqa
from util import is_same_arrays_ignoring_order
import year_twenty_four.november.different_ways_to_add_parentheses as diff_ways_to_compute
import year_twenty_four.november.decoded_string_at_index as decode_at_index


def test_diff_ways_to_compute():
    solution = diff_ways_to_compute.Solution()

    exp0 = "2-1-1"
    exp1 = "2*3-4*5"

    result0 = solution.diff_ways_to_compute(exp0)
    result1 = solution.diff_ways_to_compute(exp1)

    assert is_same_arrays_ignoring_order(result0, [0, 2])
    assert is_same_arrays_ignoring_order(result1, [-34, -14, -10, -10, 10])


def test_decode_at_index():
    solution = decode_at_index.Solution()

    s0, k0 = "leet2code3", 10
    s1, k1 = "ha22", 5
    s2, k2 = "a2345678999999999999999", 1
    s3, k3 = "vk6u5xhq9v", 554

    result0 = solution.decode_at_index(s0, k0)
    result1 = solution.decode_at_index(s1, k1)
    result2 = solution.decode_at_index(s2, k2)
    result3 = solution.decode_at_index(s3, k3)

    assert result0 == "o"
    assert result1 == "h"
    assert result2 == "a"
    assert result3 == "k"
