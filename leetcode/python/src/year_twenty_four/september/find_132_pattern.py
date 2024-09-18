"""
456. 132 Pattern
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k]
such that i < j < k and nums[i] < nums[k] < nums[j].
Return true if there is a 132 pattern in nums, otherwise, return false.

Example 1:
Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.

Example 2:
Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Example 3:
Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


Constraints:
n == nums.length
1 <= n <= 2 * 10^5
-10^9 <= nums[i] <= 10^9
"""

import sys
from typing import List


class Solution:
    def find_132_pattern(self, nums: List[int]) -> bool:
        stack, min_num = [], sys.maxsize

        for num in nums:
            min_num = min(min_num, num)

            while stack and stack[-1][1] <= num:
                stack.pop()

            if stack and stack[-1][0] < num:
                return True

            if len(stack) == 0 or stack[-1][0] > min_num:
                stack.append([min_num, num])

        return False
