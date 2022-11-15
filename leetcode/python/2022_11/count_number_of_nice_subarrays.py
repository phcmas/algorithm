"""
1248. Count Number of Nice Subarrays

Given an array of integers nums and an integer k.
A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.

Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

Constraints:
1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length

"""
from typing import List


class Solution:
    def number_of_subarrays(self, nums: List[int], k: int) -> int:
        return 0


def main():
    nums0 = [1, 1, 2, 1, 1]
    nums1 = [2, 4, 6]
    nums2 = [2, 2, 2, 1, 2, 2, 1, 2, 2, 2]

    k0 = 3
    k1 = 1
    k2 = 2

    solution0 = Solution()
    solution1 = Solution()
    solution2 = Solution()

    result0 = solution0.number_of_subarrays(nums0, k0)
    result1 = solution1.number_of_subarrays(nums1, k1)
    result2 = solution2.number_of_subarrays(nums2, k2)

    print(result0)
    print(result1)
    print(result2)


main()
