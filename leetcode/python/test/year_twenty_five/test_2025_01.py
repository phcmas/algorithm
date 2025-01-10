import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.january.check_completeness_of_a_binary_tree as is_complete_tree
import year_twenty_five.january.check_if_n_and_its_double_exist as check_if_exist
import year_twenty_five.january.linked_list_components as num_components
import year_twenty_five.january.maximum_size_subarray_sum_equals_k as max_sub_array_len
import year_twenty_five.january.remove_nth_node_from_end_of_list as remove_nth_from_end
import year_twenty_five.january.sliding_window_maximum as max_sliding_window
from common.list_node import ListNode
from common.tree_node import TreeNode
from common.util import is_same_list_nodes


def test_check_if_exist():
    solution = check_if_exist.Solution()

    arr0 = [10, 2, 5, 3]
    arr1 = [3, 1, 7, 11]
    arr2 = [-2, 0, 10, -19, 4, 6, -8]

    result0 = solution.check_if_exist(arr0)
    result1 = solution.check_if_exist(arr1)
    result2 = solution.check_if_exist(arr2)

    assert result0 is True
    assert result1 is False
    assert result2 is False


def test_remove_nth_from_end():
    solution = remove_nth_from_end.Solution()

    head0, n0 = ListNode.make([1, 2, 3, 4, 5]), 2
    head1, n1 = ListNode.make([1]), 1
    head2, n2 = ListNode.make([1, 2]), 1

    result0 = solution.remove_nth_from_end(head0, n0)
    result1 = solution.remove_nth_from_end(head1, n1)
    result2 = solution.remove_nth_from_end(head2, n2)

    assert is_same_list_nodes(result0, ListNode.make([1, 2, 3, 5]))
    assert is_same_list_nodes(result1, ListNode.make([]))
    assert is_same_list_nodes(result2, ListNode.make([1]))


def test_num_componentes():
    solution = num_components.Solution()

    head0, nums0 = ListNode.make([0, 1, 2, 3]), [0, 1, 3]
    head1, nums1 = ListNode.make([0, 1, 2, 3, 4]), [0, 3, 1, 4]

    result0 = solution.num_components(head0, nums0)
    result1 = solution.num_components(head1, nums1)

    assert result0 == 2
    assert result1 == 2


def test_max_sliding_window():
    solution = max_sliding_window.Solution()

    nums0, k0 = [1, 3, -1, -3, 5, 3, 6, 7], 3
    nums1, k1 = [1], 1
    nums2, k2 = [3, 3, -1, -3, 5, 7, 6, 7, 7], 3

    result0 = solution.max_sliding_window(nums0, k0)
    result1 = solution.max_sliding_window(nums1, k1)
    result2 = solution.max_sliding_window(nums2, k2)

    assert result0 == [3, 3, 5, 5, 6, 7]
    assert result1 == [1]
    assert result2 == [3, 3, 5, 7, 7, 7, 7]


def test_max_sub_array_len():
    solution = max_sub_array_len.Solution()

    nums0, k0 = [1, -1, 5, -2, 3], 3
    nums1, k1 = [-2, -1, 2, 1], 1

    result0 = solution.max_sub_array_len(nums0, k0)
    result1 = solution.max_sub_array_len(nums1, k1)

    assert result0 == 4
    assert result1 == 2


def test_is_complete_tree():
    solution = is_complete_tree.Solution()

    root0 = TreeNode.make([1, 2, 3, 4, 5, 6])
    root1 = TreeNode.make([1, 2, 3, 4, 5, None, 7])
    root2 = TreeNode.make([1, 2, 3, 5, None, 7, 8])
    root3 = TreeNode.make([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, None, None, 15])

    result0 = solution.is_complete_tree(root0)
    result1 = solution.is_complete_tree(root1)
    result2 = solution.is_complete_tree(root2)
    result3 = solution.is_complete_tree(root3)

    assert result0 is True
    assert result1 is False
    assert result2 is False
    assert result3 is False
