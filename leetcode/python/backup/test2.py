from typing import List


def can_sorted_by_swap(arr_sorted: List[int], arr: List[int]):
    left, right = -1, -1

    for idx, nums in enumerate(zip(arr_sorted, arr)):
        if nums[0] != nums[1] and left == -1:
            left = idx
        elif nums[0] != nums[1] and right == -1:
            right = idx
        elif nums[0] != nums[1]:
            return False, -1, -1

    if left == -1 and right == -1:
        return False, -1, -1

    return True, left, right


def can_sorted_by_reverse(arr_sorted: List[int], arr: List[int]):
    left, right = -1, -1
    left_arr, right_arr = [], []

    for idx, nums in enumerate(zip(arr_sorted, arr)):
        if nums[0] != nums[1] and left == -1:
            left = idx
            left_arr.append(nums[0])
            right_arr.append(nums[1])
        elif nums[0] != nums[1]:
            right = idx
            left_arr.append(nums[0])
            right_arr.append(nums[1])

    if left_arr == right_arr[::-1]:
        return True, left, right

    return False, -1, -1


def almostSorted(arr: List[int]):
    arr_sorted = sorted(arr)

    if arr_sorted == arr:
        return "yes"

    result, left, right = can_sorted_by_swap(arr_sorted, arr)

    if result:
        return f"yes\nswap {left + 1} {right + 1}"

    result, left, right = can_sorted_by_reverse(arr_sorted, arr)

    if result:
        return f"yes\nreverse {left + 1} {right + 1}"

    return "no"


# pylint: disable=C0200
def selection_sort(arr: List[int]):
    for i in range(len(arr)):
        min = i

        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min]:
                min = j

        arr[i], arr[min] = arr[min], arr[i]


def insertion_sort(arr: List[int]):
    for i in range(1, len(arr)):
        key = arr[i]

        for j in range(i - 1, -1, -1):
            if arr[j] > key:
                arr[j + 1] = arr[j]
                arr[j] = key
            else:
                break


arr0 = [1, 5, 4, 3, 2, 6]
arr1 = [3, 1, 2]
arr2 = [43, 65, 1, 98, 99, 101]
arr3 = [4, 2]

# selection_sort(arr0)
# selection_sort(arr1)
# selection_sort(arr2)
# selection_sort(arr3)

test = "abcd"


num0 = 4
num1 = 12

num1.bit_count()

print(num0 & num1)

for idx, t in enumerate(test[::-1]):
    print(idx, t)


insertion_sort(arr0)
insertion_sort(arr1)
insertion_sort(arr2)
insertion_sort(arr3)
