import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.february.meeting_rooms_ii as meeting_rooms_ii
import year_twenty_five.february.daily_temperatures as daily_temperatures


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


def test_daily_temperatures():
    solution = daily_temperatures.Solution()

    temperatures0 = [73, 74, 75, 71, 69, 72, 76, 73]
    temperatures1 = [30, 40, 50, 60]
    temperatures2 = [30, 60, 90]

    result0 = solution.daily_temperatures(temperatures0)
    result1 = solution.daily_temperatures(temperatures1)
    result2 = solution.daily_temperatures(temperatures2)

    assert result0 == [1, 1, 4, 2, 1, 1, 0, 0]
    assert result1 == [1, 1, 1, 0]
    assert result2 == [1, 1, 0]
