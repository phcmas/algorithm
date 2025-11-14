import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.november.maximum_number_of_eaten_apples as eaten_apples
import year_twenty_five.november.maximum_value_at_a_given_index_in_a_bounded_array as max_value
import year_twenty_five.november.remove_duplicates_from_an_unsorted_linked_list as delete_duplicates_unsorted
import year_twenty_five.november.sparse_matrix_multiplication as sparse_matrix_multiplication
import year_twenty_five.november.two_sum_iii as two_sum_iii

from common.list_node import ListNode
from common.util import is_same_list_nodes


def test_multiply():
    solution = sparse_matrix_multiplication.Solution()

    mat01, mat02 = [[1, 0, 0], [-1, 0, 3]], [[7, 0, 0], [0, 0, 0], [0, 0, 1]]
    mat11, mat12 = [[0]], [[0]]
    mat21, mat22 = [[1, -5]], [[12], [-1]]

    ret0 = solution.multiply(mat01, mat02)
    ret1 = solution.multiply(mat11, mat12)
    ret2 = solution.multiply(mat21, mat22)

    assert ret0 == [[7, 0, 0], [-7, 0, 3]]
    assert ret1 == [[0]]
    assert ret2 == [[17]]


def test_max_value():
    solution = max_value.Solution()

    n0, index0, max_sum0 = 4, 2, 6
    n1, index1, max_sum1 = 6, 1, 10
    n2, index2, max_sum2 = 8, 7, 14
    n3, index3, max_sum3 = 4, 0, 4

    ret0 = solution.max_value(n0, index0, max_sum0)
    ret1 = solution.max_value(n1, index1, max_sum1)
    ret2 = solution.max_value(n2, index2, max_sum2)
    ret3 = solution.max_value(n3, index3, max_sum3)

    assert ret0 == 2
    assert ret1 == 3
    assert ret2 == 4
    assert ret3 == 1


def test_delete_duplicates_unsorted():
    solution = delete_duplicates_unsorted.Solution()

    head0 = ListNode.make([1, 2, 3, 2])
    head1 = ListNode.make([2, 1, 1, 2])
    head2 = ListNode.make([3, 2, 2, 1, 3, 2, 4])

    ret0 = solution.delete_duplicates_unsorted(head0)
    ret1 = solution.delete_duplicates_unsorted(head1)
    ret2 = solution.delete_duplicates_unsorted(head2)

    answer0 = ListNode.make([1, 3])
    answer1 = ListNode.make([])
    answer2 = ListNode.make([1, 4])

    assert is_same_list_nodes(ret0, answer0)
    assert is_same_list_nodes(ret1, answer1)
    assert is_same_list_nodes(ret2, answer2)


def test_eaten_apples():
    solution = eaten_apples.Solution()

    apples0 = [1, 2, 3, 5, 2]
    days0 = [3, 2, 1, 4, 2]

    apples1 = [3, 0, 0, 0, 0, 2]
    days1 = [3, 0, 0, 0, 0, 2]

    ret0 = solution.eaten_apples(apples0, days0)
    ret1 = solution.eaten_apples(apples1, days1)

    assert ret0 == 7
    assert ret1 == 5


def test_two_sum_iii():
    two_sum0 = two_sum_iii.TwoSum2()

    two_sum0.add(3)
    two_sum0.add(1)
    two_sum0.add(5)

    ret0 = two_sum0.find(4)
    ret1 = two_sum0.find(7)

    two_sum1 = two_sum_iii.TwoSum2()

    two_sum1.add(3)
    two_sum1.add(2)
    two_sum1.add(1)

    ret2 = two_sum1.find(2)
    ret3 = two_sum1.find(3)
    ret4 = two_sum1.find(4)
    ret5 = two_sum1.find(5)
    ret6 = two_sum1.find(6)

    assert ret0 is True
    assert ret1 is False

    assert ret2 is False
    assert ret3 is True
    assert ret4 is True
    assert ret5 is True
    assert ret6 is False
