import sys
from os.path import dirname, abspath, join

SRC_DIR = join(dirname(__file__), "../src")
TEST_DIR = join(dirname(__file__), "../test")

sys.path.insert(1, abspath(SRC_DIR))
sys.path.insert(1, abspath(TEST_DIR))

from util import is_same_array_ignoring_order
import year_twenty_two.december.maximum_split_of_positive_even_integer as maximum_split


def test_maximum_split_of_positive_even_integers():
    final_sum0 = 12
    final_sum1 = 7
    final_sum2 = 28

    solution0 = maximum_split.Solution()
    solution1 = maximum_split.Solution()
    solution2 = maximum_split.Solution()

    result0 = solution0.maximum_even_split(final_sum0)
    result1 = solution1.maximum_even_split(final_sum1)
    result2 = solution2.maximum_even_split(final_sum2)

    answer0 = [2, 4, 6]
    answer1 = []
    answer2 = [2, 4, 6, 16]

    compare0 = is_same_array_ignoring_order(result0, answer0)
    compare1 = is_same_array_ignoring_order(result1, answer1)
    compare2 = is_same_array_ignoring_order(result2, answer2)

    assert compare0 == True
    assert compare1 == True
    assert compare2 == True
