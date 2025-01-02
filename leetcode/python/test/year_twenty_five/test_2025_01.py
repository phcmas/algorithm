import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.january.check_if_n_and_its_double_exist as check_if_exist


def test_check_if_exist():
    solution = check_if_exist.Solution()

    arr0 = [10, 2, 5, 3]
    arr1 = [3, 1, 7, 11]
    arr2 = [-2, 0, 10, -19, 4, 6, -8]

    result0 = solution.check_if_exist(arr0)
    result1 = solution.check_if_exist(arr1)
    result2 = solution.check_if_exist(arr2)

    assert result0 is True
    assert result1 is False
    assert result2 is False
