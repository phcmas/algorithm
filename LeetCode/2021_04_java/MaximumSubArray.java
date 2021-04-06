/** 53. Maximum Subarray */
/** Given an integer array nums, find the contiguous subarray (containing at least one number) 
 *  which has the largest sum and return its sum.
 * 
 *  Example 1:
 *  Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 *  Output: 6
 *  Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 *  Example 2:
 *  Input: nums = [1]
 *  Output: 1
 *  
 *  Example 3:
 *  Input: nums = [5,4,-1,7,8]
 *  Output: 23
 * 
 *  Constraints:
 *  1 <= nums.length <= 3 * 10^4
 *  -10^5 <= nums[i] <= 10^5
 *  Follow up: If you have figured out the O(n) solution, try coding another solution using the 
 *  divide and conquer approach, which is more subtle. */


class MaximumSubArray {
    private final int MIN = -100000;

    private int findMaxSum(int[] nums, int start, int end) {
        int middle = (start + end) / 2;
        int leftMax = MIN;
        int rightMax = MIN;
        int sum = 0;
        int candidate;

        if (start == end) return nums[start];

        candidate = Math.max(findMaxSum(nums, start, middle), findMaxSum(nums, middle+1, end));

        for (int i = middle; i >= start; --i) {
            sum += nums[i];
            leftMax = Math.max(leftMax, sum);
        }

        sum = 0;
        for (int i = middle+1; i <= end; ++i) {
            sum += nums[i];
            rightMax = Math.max(rightMax, sum);
        }

        return Math.max(candidate, leftMax + rightMax);
    }

    private int kadanesAlgorithm(int[] nums) {
        int answer = MIN;
        int currentSum = 0;
        
        for (int iter : nums) {
            currentSum += iter;
            answer = Math.max(currentSum, answer);
            if (currentSum < 0) currentSum = 0;
        }

        return answer;
    }

    public int maxSubArray(int[] nums) {
        //return findMaxSum(nums, 0, nums.length-1);
        return kadanesAlgorithm(nums);
    }
}





