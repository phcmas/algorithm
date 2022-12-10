from typing import List


def is_same_array_ignoring_order(arr0: List[int], arr1: List[int]):
    sorted0 = sorted(arr0)
    sorted1 = sorted(arr1)

    return sorted0 == sorted1
