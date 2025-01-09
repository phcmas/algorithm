"""
325. Maximum Size Subarray Sum Equals k
Given an integer array nums and an integer k, return the maximum length of a subarray
that sums to k. If there is not one, return 0 instead.

Example 1:
Input: nums = [1,-1,5,-2,3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.

Example 2:
Input: nums = [-2,-1,2,1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.

Constraints:
1 <= nums.length <= 2 * 10^5
-10^4 <= nums[i] <= 10^4
-10^9 <= k <= 10^9
"""


class Solution:
    def max_sub_array_len(self, nums: list[int], k: int) -> int:
        psum, max_len = 0, 0
        psum_to_idx = {0: -1}  # sum to index

        for idx, num in enumerate(nums):
            psum += num

            if psum not in psum_to_idx:
                psum_to_idx[psum] = idx

            if psum - k in psum_to_idx:
                max_len = max(idx - psum_to_idx[psum - k], max_len)

        return max_len
