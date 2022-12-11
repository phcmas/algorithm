from typing import List, Optional

from common.list_node import ListNode


def is_same_arrays_ignoring_order(arr0: List[int], arr1: List[int]):
    sorted0 = sorted(arr0)
    sorted1 = sorted(arr1)

    return sorted0 == sorted1


def is_same_list_nodes(head0: Optional[ListNode], head1: Optional[ListNode]):
    node0 = head0
    node1 = head1

    while node0 is not None:
        if node1 is None:
            return False

        if node0.val != node1.val:
            return False

        node0 = node0.next
        node1 = node1.next

    return node1 is None
