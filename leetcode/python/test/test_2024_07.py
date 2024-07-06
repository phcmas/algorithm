import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_four.july.minimum_number_of_operations_to_sort_a_binary_tree_by_level as minimum_number_of_operations
from common.tree_node import TreeNode


def test_minimum_number_of_operations():
    solution = minimum_number_of_operations.Solution()

    root0 = TreeNode.make([1, 4, 3, 7, 6, 8, 5, None, None, None, None, 9, None, 10])
    root1 = TreeNode.make([1, 3, 2, 7, 6, 5, 4])
    root2 = TreeNode.make([1, 2, 3, 4, 5, 6])

    result0 = solution.minimum_operations(root0)
    result1 = solution.minimum_operations(root1)
    result2 = solution.minimum_operations(root2)

    assert result0 == 3
    assert result1 == 3
    assert result2 == 0
