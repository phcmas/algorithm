"""
357. Count Numbers with Unique Digits
Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10^n

Example 1:
Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

Example 2:
Input: n = 0
Output: 1

Constraints:
0 <= n <= 8
"""


class Solution:
    def count_numbers_with_unique_digits(self, n: int) -> int:
        if n == 0:
            return 1

        result, current = 10, 9

        for m in range(2, n + 1):
            current *= 11 - m
            result += current

        return result
