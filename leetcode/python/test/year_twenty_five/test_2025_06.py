import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.june.remove_stones_to_minimize_the_total as min_stone_sum


def test_min_stone_sum():
    solution = min_stone_sum.Solution()

    piles0, k0 = [5, 4, 9], 2
    piles1, k1 = [4, 3, 6, 7], 3

    result0 = solution.min_stone_sum(piles0, k0)
    result1 = solution.min_stone_sum(piles1, k1)

    assert result0 == 12
    assert result1 == 12
