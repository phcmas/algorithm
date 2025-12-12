"""
1590. Make Sum Divisible by P
Given an array of positive integers nums, remove the smallest subarray (possibly empty)
such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.
Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
A subarray is defined as a contiguous block of elements in the array.

Example 1:
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6.
We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.

Example 2:
Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9.
The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.

Example 3:
Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= p <= 10^9
"""

import math
from collections import defaultdict


class Solution:
    def min_subarray(self, nums: list[int], p: int) -> int:
        total = sum(nums)

        if total % p == 0:
            return 0

        prefix_sums = defaultdict(list[int])
        cur, answer = 0, math.inf

        for i, num in enumerate(nums):
            cur += num
            prefix_sums[cur % p].append(i)

        for rem, idxs0 in prefix_sums.items():
            if rem == total % p and idxs0[0] < len(nums) - 1:
                answer = min(answer, idxs0[0] + 1)

            if (rem + total % p) % p not in prefix_sums:
                continue

            idxs1 = prefix_sums[(rem + total % p) % p]
            left, right = 0, 0

            while left < len(idxs0):
                if idxs0[left] > idxs1[right]:
                    if right == len(idxs1) - 1:
                        break

                    right += 1

                else:
                    answer = min(answer, idxs1[right] - idxs0[left])
                    left += 1

        return -1 if answer == math.inf else answer
