from typing import List
from collections import Counter


def reverse(num: int):
    result, digits = 0, []

    while num > 0:
        remainder = num % 10
        num = num // 10
        digits.append(remainder)

    for idx, digit in enumerate(digits):
        result += digit * pow(10, len(digits) - 1 - idx)

    return result


def solution(nums: List[int]):
    relations = []

    for num in nums:
        relations.append(num - reverse(num))

    counter = Counter(relations)
    return sum(value - 1 for value in counter.values())


nums0 = [1, 13, 24, 42, 76, 97]
result0 = solution(nums0)

print(result0)
