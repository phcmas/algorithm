import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.april.take_k_of_each_character_from_left_and_right as take_characters


def test_take_characters():
    solution = take_characters.Solution()

    s0, k0 = "aabaaaacaabc", 2
    s1, k1 = "a", 1
    s2, k2 = "a", 0
    s3, k3 = "cbbac", 1

    result0 = solution.take_characters(s0, k0)
    result1 = solution.take_characters(s1, k1)
    result2 = solution.take_characters(s2, k2)
    result3 = solution.take_characters(s3, k3)

    assert result0 == 8
    assert result1 == -1
    assert result2 == 0
    assert result3 == 3
