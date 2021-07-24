/** 611 Valid Triangle Number */
/** Given an integer array nums, return the number of triplets chosen from the array 
 *  that can make triangles if we take them as side lengths of a triangle.
 * 
 *  Example 1:
 *  Input: nums = [2,2,3,4]
 *  Output: 3
 *  Explanation: Valid combinations are: 
 *  2,3,4 (using the first 2)
 *  2,3,4 (using the second 2)
 *  2,2,3
 * 
 *  Example 2:
 *  Input: nums = [4,2,3,4]
 *  Output: 4
 * 
 *  Constraints:
 *  1 <= nums.length <= 1000
 *  0 <= nums[i] <= 1000 */

import java.util.Arrays;

class ValidTriangleNumber {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int max = nums[nums.length-1];
        int[] counts = new int[max];
        int count = nums.length-1;
        int answer = 0;

        for (int i = nums.length-1; i >= 1; ++i) {
            for (int j = nums[i-1]+1; j < nums[i]; ++j) {
                counts[j] = count;
            }
            count--;
        }

        for (int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                if (nums[i] + nums[j] > max) {
                    answer += nums.length-2;
                } else if (nums[i] + nums[j] <= max) {
                    answer += counts[nums[i]+nums[j]]-2;
                }
            }
        }

        return answer;
    }
}

