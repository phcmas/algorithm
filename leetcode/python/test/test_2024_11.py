import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_four.november.decoded_string_at_index as decode_at_index
import year_twenty_four.november.different_ways_to_add_parentheses as diff_ways_to_compute
import year_twenty_four.november.kth_largest_sum_in_a_binary_tree as kth_lagest_level_sum
import year_twenty_four.november.merge_k_sorted_lists as merge_k_sorted_lists
import year_twenty_four.november.top_k_frequent_words as top_k_frequent_words
from common.list_node import ListNode
from common.tree_node import TreeNode
from util import is_same_arrays_ignoring_order, is_same_list_nodes


def test_diff_ways_to_compute():
    solution = diff_ways_to_compute.Solution()

    exp0 = "2-1-1"
    exp1 = "2*3-4*5"

    result0 = solution.diff_ways_to_compute(exp0)
    result1 = solution.diff_ways_to_compute(exp1)

    assert is_same_arrays_ignoring_order(result0, [0, 2])
    assert is_same_arrays_ignoring_order(result1, [-34, -14, -10, -10, 10])


def test_decode_at_index():
    solution = decode_at_index.Solution()

    s0, k0 = "leet2code3", 10
    s1, k1 = "ha22", 5
    s2, k2 = "a2345678999999999999999", 1
    s3, k3 = "vk6u5xhq9v", 554

    result0 = solution.decode_at_index(s0, k0)
    result1 = solution.decode_at_index(s1, k1)
    result2 = solution.decode_at_index(s2, k2)
    result3 = solution.decode_at_index(s3, k3)

    assert result0 == "o"
    assert result1 == "h"
    assert result2 == "a"
    assert result3 == "k"


def test_kth_largest_level_sum():
    solution = kth_lagest_level_sum.Solution()

    root0 = TreeNode.make([5, 8, 9, 2, 1, 3, 7, 4, 6])
    root1 = TreeNode.make([1, 2, None, 3])
    root2 = TreeNode.make([5, 8, 9, 2, 1, 3, 7])

    k0 = 2
    k1 = 1
    k2 = 4

    result0 = solution.kth_largest_level_sum(root0, k0)
    result1 = solution.kth_largest_level_sum(root1, k1)
    result2 = solution.kth_largest_level_sum(root2, k2)

    assert result0 == 13
    assert result1 == 3
    assert result2 == -1


def test_merge_k_lists():
    solution = merge_k_sorted_lists.Solution()

    lists0 = [ListNode.make([1, 4, 5]), ListNode.make([1, 3, 4]), ListNode.make([2, 6])]
    lists1 = []
    lists2 = [None]

    result0 = solution.merge_k_lists(lists0)
    result1 = solution.merge_k_lists(lists1)
    result2 = solution.merge_k_lists(lists2)

    answer0 = ListNode.make([1, 1, 2, 3, 4, 4, 5, 6])

    assert is_same_list_nodes(result0, answer0)
    assert result1 is None
    assert result2 is None


def test_top_k_frequent():
    solution = top_k_frequent_words.Solution()

    words0 = ["i", "love", "leetcode", "i", "love", "coding"]
    words1 = ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"]
    words2 = ["i", "love", "leetcode", "i", "love", "coding"]

    k0, k1, k2 = 2, 4, 1

    result0 = solution.top_k_frequent(words0, k0)
    result1 = solution.top_k_frequent(words1, k1)
    result2 = solution.top_k_frequent(words2, k2)

    assert result0 == ["i", "love"]
    assert result1 == ["the", "is", "sunny", "day"]
    assert result2 == ["i"]
