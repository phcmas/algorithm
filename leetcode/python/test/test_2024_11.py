import sys
from os.path import abspath, dirname, join


SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# ruff: noqa
from util import is_same_arrays_ignoring_order
import year_twenty_four.november.different_ways_to_add_parentheses as diff_ways_to_compute


def test_diff_ways_to_compute():
    solution = diff_ways_to_compute.Solution()

    exp0 = "2-1-1"
    exp1 = "2*3-4*5"

    result0 = solution.diff_ways_to_compute(exp0)
    result1 = solution.diff_ways_to_compute(exp1)

    assert is_same_arrays_ignoring_order(result0, [0, 2])
    assert is_same_arrays_ignoring_order(result1, [-34, -14, -10, -10, 10])
