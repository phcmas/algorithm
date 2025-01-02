import sys
from os.path import abspath, dirname, join

from common.util import is_same_list_nodes

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

from common.list_node import ListNode
import year_twenty_five.january.check_if_n_and_its_double_exist as check_if_exist
import year_twenty_five.january.remove_nth_node_from_end_of_list as remove_nth_from_end


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
