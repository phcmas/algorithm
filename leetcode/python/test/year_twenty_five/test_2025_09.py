import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.september.campus_bikes_ii as assign_bikes
import year_twenty_five.september.can_i_win as can_i_win


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
