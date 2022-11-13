"""
494. Target Sum

You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before
each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and
concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1

Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

"""


from typing import List

MAX = 1000


class Solution:
    def __init__(self) -> None:
        self.cache = [[0 for i in range(20001)] for j in range(21)]

    def backtracking(self, nums: List[int], index: int, prev: int, target: int) -> int:
        if index == len(nums) - 1:
            count = 0
            if prev + nums[index] == target:
                count += 1
            if prev - nums[index] == target:
                count += 1

            return count

        result = 0
        result += self.backtracking(nums, index + 1, prev + nums[index], target)
        result += self.backtracking(nums, index + 1, prev - nums[index], target)

        return result

    def save(self, index: int, target: int, value: int):
        self.cache[index + 1][target + MAX] = value

    def load(self, index: int, target: int):
        return self.cache[index + 1][target + MAX]

    def find_target_sum_ways(self, nums: List[int], target: int) -> int:
        self.save(-1, 0, 1)

        for i, num in enumerate(nums):
            subsum = sum(nums[: i + 1])

            for j in range(-subsum, subsum + 1):
                a = self.load(i - 1, j - num)
                b = self.load(i - 1, j + num)
                self.save(i, j, a + b)

        return self.load(len(nums) - 1, target)


def main():
    nums0 = [1, 1, 1, 1, 1]
    nums1 = [1]
    nums2 = [1, 0]
    nums3 = [0, 0, 0, 0, 0, 0, 0, 0, 1]
    nums4 = [1, 999]

    target0 = 3
    target1 = 1
    target2 = 1
    target3 = 1
    target4 = 998

    solution0 = Solution()
    solution1 = Solution()
    solution2 = Solution()
    solution3 = Solution()
    solution4 = Solution()

    result0 = solution0.find_target_sum_ways(nums0, target0)
    result1 = solution1.find_target_sum_ways(nums1, target1)
    result2 = solution2.find_target_sum_ways(nums2, target2)
    result3 = solution3.find_target_sum_ways(nums3, target3)
    result4 = solution4.find_target_sum_ways(nums4, target4)

    print(result0)
    print(result1)
    print(result2)
    print(result3)
    print(result4)


main()
