import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0411,C0413,R0402,E0401
import year_twenty_four.february.maximum_score_from_removing_stones as maximum_score


def test_maximum_the_confusion():
    solution0 = maximum_score.Solution()
    solution1 = maximum_score.Solution()
    solution2 = maximum_score.Solution()

    a0, b0, c0 = 2, 4, 6
    a1, b1, c1 = 4, 4, 6
    a2, b2, c2 = 1, 8, 8

    result0 = solution0.maximum_score(a0, b0, c0)
    result1 = solution1.maximum_score(a1, b1, c1)
    result2 = solution2.maximum_score(a2, b2, c2)

    assert result0 == 6
    assert result1 == 7
    assert result2 == 8
