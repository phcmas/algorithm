import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# ruff: noqa
import year_twenty_four.september.flower_planting_with_no_adjacent as flower_planting_with_no_adjacent
import year_twenty_four.september.count_numbers_with_unique_digits as count_numbers_with_unique_digits
import year_twenty_four.september.find_132_pattern as find_132_pattern


def test_garden_no_adj():
    solution = flower_planting_with_no_adjacent.Solution()

    n0, paths0 = 3, [[1, 2], [2, 3], [3, 1]]
    n1, paths1 = 4, [[1, 2], [3, 4]]
    n2, paths2 = 4, [[1, 2], [2, 3], [3, 4], [4, 1], [1, 3], [2, 4]]
    n3, paths3 = 1, []
    n4, paths4 = 8, [[7, 4], [3, 7], [1, 5], [5, 4], [7, 1], [3, 1], [4, 3], [6, 5]]

    result0 = solution.garden_no_adj(n0, paths0)
    result1 = solution.garden_no_adj(n1, paths1)
    result2 = solution.garden_no_adj(n2, paths2)
    result3 = solution.garden_no_adj(n3, paths3)
    result4 = solution.garden_no_adj(n4, paths4)

    assert result0 == [1, 2, 3]
    assert result1 == [1, 2, 1, 2]
    assert result2 == [1, 2, 3, 4]
    assert result3 == [1]
    assert result4 == [1, 1, 2, 1, 2, 1, 3, 1]


def test_count_numbers_with_unique_digits():
    solution = count_numbers_with_unique_digits.Solution()

    n0 = 2
    n1 = 0
    n2 = 3

    result0 = solution.count_numbers_with_unique_digits(n0)
    result1 = solution.count_numbers_with_unique_digits(n1)
    result2 = solution.count_numbers_with_unique_digits(n2)

    assert result0 == 91
    assert result1 == 1
    assert result2 == 739


def test_find_132_pattern():
    solution = find_132_pattern.Solution()

    nums0 = [1, 2, 3, 4]
    nums1 = [3, 1, 4, 2]
    nums2 = [-1, 3, 2, 0]
    nums3 = [3, 5, 0, 3, 4]
    nums4 = [1, 0, 1, -4, -3]
    nums5 = [1, 4, 0, -1, -2, -3, -1, -2]

    result0 = solution.find_132_pattern(nums0)
    result1 = solution.find_132_pattern(nums1)
    result2 = solution.find_132_pattern(nums2)
    result3 = solution.find_132_pattern(nums3)
    result4 = solution.find_132_pattern(nums4)
    result5 = solution.find_132_pattern(nums5)

    assert result0 is False
    assert result1 is True
    assert result2 is True
    assert result3 is True
    assert result4 is False
    assert result5 is True
