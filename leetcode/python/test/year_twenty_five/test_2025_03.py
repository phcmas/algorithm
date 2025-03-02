import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.march.evaluate_reverse_polish_notation as eval_rpn
import year_twenty_five.march.simplify_path as simplify_path


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


def test_simplify_path():
    solution = simplify_path.Solution()

    path0 = "/home/"
    path1 = "/home//foo/"
    path2 = "/home/user/Documents/../Pictures"
    path3 = "/../"
    path4 = "/.../a/../b/c/../d/./"

    result0 = solution.simplify_path(path0)
    result1 = solution.simplify_path(path1)
    result2 = solution.simplify_path(path2)
    result3 = solution.simplify_path(path3)
    result4 = solution.simplify_path(path4)

    assert result0 == "/home"
    assert result1 == "/home/foo"
    assert result2 == "/home/user/Pictures"
    assert result3 == "/"
    assert result4 == "/.../b/d"
