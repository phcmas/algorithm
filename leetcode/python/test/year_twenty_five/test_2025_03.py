import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.march.evaluate_reverse_polish_notation as eval_rpn


def test_eval_rpn():
    solution = eval_rpn.Solution()

    tokens0 = ["2", "1", "+", "3", "*"]
    tokens1 = ["4", "13", "5", "/", "+"]
    tokens2 = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]

    result0 = solution.eval_rpn(tokens0)
    result1 = solution.eval_rpn(tokens1)
    result2 = solution.eval_rpn(tokens2)

    assert result0 == 9
    assert result1 == 6
    assert result2 == 22
