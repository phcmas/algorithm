import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0413,R0402
from util import is_same_tree
from common.tree_node import TreeNode

import year_twenty_three.may.binary_tree_pruning as binary_tree_pruning


def test_binary_tree_pruning():
    solution0 = binary_tree_pruning.Solution()
    solution1 = binary_tree_pruning.Solution()
    solution2 = binary_tree_pruning.Solution()
    solution3 = binary_tree_pruning.Solution()

    root0 = TreeNode.make([1, None, 0, 0, 1])
    root1 = TreeNode.make([1, 0, 1, 0, 0, 0, 1])
    root2 = TreeNode.make([1, 1, 0, 1, 1, 0, 1, 0])
    root3 = TreeNode.make([0, None, 0, 0, 0])

    answer0 = TreeNode.make([1, None, 0, None, 1])
    answer1 = TreeNode.make([1, None, 1, None, 1])
    answer2 = TreeNode.make([1, 1, 0, 1, 1, None, 1])
    answer3 = TreeNode.make([])

    result0 = solution0.prune_tree(root0)
    result1 = solution1.prune_tree(root1)
    result2 = solution2.prune_tree(root2)
    result3 = solution3.prune_tree(root3)

    compare0 = is_same_tree(result0, answer0)
    compare1 = is_same_tree(result1, answer1)
    compare2 = is_same_tree(result2, answer2)
    compare3 = is_same_tree(result3, answer3)

    assert compare0 is True
    assert compare1 is True
    assert compare2 is True
    assert compare3 is True
