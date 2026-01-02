import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))


import year_twenty_six.january.isomorphic_strings as isomorphic_strings
import year_twenty_six.january.valid_sudoku as is_valid_sudoku


def test_isomorphic_strings():
    solution = isomorphic_strings.Solution()

    s0, t0 = "egg", "add"
    s1, t1 = "foo", "bar"
    s2, t2 = "paper", "title"
    s3, t3 = "badc", "baba"

    ret0 = solution.is_isomorphic(s0, t0)
    ret1 = solution.is_isomorphic(s1, t1)
    ret2 = solution.is_isomorphic(s2, t2)
    ret3 = solution.is_isomorphic(s3, t3)

    assert ret0 is True
    assert ret1 is False
    assert ret2 is True
    assert ret3 is False


def test_is_valid_sudoku():
    solution = is_valid_sudoku.Solution()
    board0 = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    board1 = [
        ["8", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    board2 = [
        [".", ".", ".", ".", "5", ".", ".", "1", "."],
        [".", "4", ".", "3", ".", ".", ".", ".", "."],
        [".", ".", ".", ".", ".", "3", ".", ".", "1"],
        ["8", ".", ".", ".", ".", ".", ".", "2", "."],
        [".", ".", "2", ".", "7", ".", ".", ".", "."],
        [".", "1", "5", ".", ".", ".", ".", ".", "."],
        [".", ".", ".", ".", ".", "2", ".", ".", "."],
        [".", "2", ".", "9", ".", ".", ".", ".", "."],
        [".", ".", "4", ".", ".", ".", ".", ".", "."],
    ]

    ret0 = solution.is_valid_sudoku(board0)
    ret1 = solution.is_valid_sudoku(board1)
    ret2 = solution.is_valid_sudoku(board2)

    assert ret0 is True
    assert ret1 is False
    assert ret2 is False
