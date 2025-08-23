import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))


import year_twenty_five.august.before_and_after_puzzle as before_and_after_puzzle


def test_before_and_after_puzzles():
    solution = before_and_after_puzzle.Solution()

    phrases0 = ["writing code", "code rocks"]
    phrases1 = [
        "mission statement",
        "a quick bite to eat",
        "a chip off the old block",
        "chocolate bar",
        "mission impossible",
        "a man on a mission",
        "block party",
        "eat my words",
        "bar of soap",
    ]
    phrases2 = ["a", "b", "a"]

    ret0 = solution.beforeAndAfterPuzzles(phrases0)
    ret1 = solution.beforeAndAfterPuzzles(phrases1)
    ret2 = solution.beforeAndAfterPuzzles(phrases2)

    assert ret0 == ["writing code rocks"]
    assert ret1 == [
        "a chip off the old block party",
        "a man on a mission impossible",
        "a man on a mission statement",
        "a quick bite to eat my words",
        "chocolate bar of soap",
    ]
    assert ret2 == ["a"]
