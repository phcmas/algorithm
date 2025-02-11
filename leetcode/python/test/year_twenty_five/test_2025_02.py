import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.february.meeting_rooms_ii as meeting_rooms_ii
import year_twenty_five.february.daily_temperatures as daily_temperatures
import year_twenty_five.february.continuous_subarray_sum as check_subarray_sum
import year_twenty_five.february.zigzag_conversion as zigzag_conversion
import year_twenty_five.february.buildings_with_an_ocean_view as buildings_with_an_ocean_view


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


def test_check_subarray_sum():
    solution = check_subarray_sum.Solution()

    nums0, k0 = [23, 2, 4, 6, 7], 6
    nums1, k1 = [23, 2, 6, 4, 7], 6
    nums2, k2 = [23, 2, 6, 4, 7], 13
    nums3, k3 = [0], 3
    nums4, k4 = [5, 0, 0, 0], 3

    result0 = solution.check_subarray_sum(nums0, k0)
    result1 = solution.check_subarray_sum(nums1, k1)
    result2 = solution.check_subarray_sum(nums2, k2)
    result3 = solution.check_subarray_sum(nums3, k3)
    result4 = solution.check_subarray_sum(nums4, k4)

    assert result0 is True
    assert result1 is True
    assert result2 is False
    assert result3 is False
    assert result4 is True


def test_zigzag_conversion():
    solution = zigzag_conversion.Solution()

    s0, num_rows0 = "PAYPALISHIRING", 3
    s1, num_rows1 = "PAYPALISHIRING", 4
    s2, num_rows2 = "A", 1
    s3, num_rows3 = "ABC", 1

    result0 = solution.convert(s0, num_rows0)
    result1 = solution.convert(s1, num_rows1)
    result2 = solution.convert(s2, num_rows2)
    result3 = solution.convert(s3, num_rows3)

    assert result0 == "PAHNAPLSIIGYIR"
    assert result1 == "PINALSIGYAHRPI"
    assert result2 == "A"
    assert result3 == "ABC"


def test_buildings_with_an_ocean_view():
    solution = buildings_with_an_ocean_view.Solution()

    heights0 = [4, 2, 3, 1]
    heights1 = [4, 3, 2, 1]
    heights2 = [1, 3, 2, 4]

    result0 = solution.find_buildings(heights0)
    result1 = solution.find_buildings(heights1)
    result2 = solution.find_buildings(heights2)

    assert result0 == [0, 2, 3]
    assert result1 == [0, 1, 2, 3]
    assert result2 == [3]
