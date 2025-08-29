"""
1838. Frequency of the Most Frequent Element
The frequency of an element is the number of times it occurs in an array.
You are given an integer array nums and an integer k.
In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

Example 1:
Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.

Example 2:
Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.

Example 3:
Input: nums = [3,9,6], k = 2
Output: 1

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
1 <= k <= 10^5
"""


class Solution:
    def maxFrequency(self, nums: list[int], k: int) -> int:
        idx, lower, upper = 0, min(nums), max(nums) + k
        max_freq, min_upper_idxs = 0, {}
        nums.sort()

        for elem in range(lower, upper + 1):
            while idx < len(nums) - 1 and elem == nums[idx + 1]:
                idx += 1

            min_upper_idxs[elem] = idx

        for elem in range(lower, upper + 1):
            op, freq = 0, 0

            for i in range(min_upper_idxs[elem], -1, -1):
                op += elem - nums[i]

                if op > k:
                    break

                freq += 1

            max_freq = max(max_freq, freq)

        return max_freq
