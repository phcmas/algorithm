import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.february.meeting_rooms_ii as meeting_rooms_ii


def test_check_if_exist():
    solution = meeting_rooms_ii.Solution()

    intervals0 = [[0, 30], [5, 10], [15, 20]]
    intervals1 = [[7, 10], [2, 4]]
    intervals2 = [[1, 4], [7, 9], [0, 6], [2, 3], [5, 8]]
    intervals3 = [[13, 15], [1, 13]]

    result0 = solution.min_meeting_rooms(intervals0)
    result1 = solution.min_meeting_rooms(intervals1)
    result2 = solution.min_meeting_rooms(intervals2)
    result3 = solution.min_meeting_rooms(intervals3)

    assert result0 == 2
    assert result1 == 1
    assert result2 == 3
    assert result3 == 1
