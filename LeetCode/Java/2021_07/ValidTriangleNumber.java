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
        int[] counts = new int[max+2];
        int start = 0;
        int count = nums.length-1;
        int answer = 0;
        
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == 0) {
                start++;
            } else {
                break;
            }
        }

        if (nums.length - start < 3) return 0;

        counts[max+1] = nums.length;
        for (int i = nums.length-1; i >= start+1; --i) {
            for (int j = nums[i-1]+1; j <= nums[i]; ++j) {
                counts[j] = count;
            }
            count--;
        }

        for (int i = start; i < nums.length-2; ++i) {
            for (int j = i+1; j < nums.length-1; ++j) {
                answer += counts[Math.min(max+1, nums[i]+nums[j])] - (j+1);
            }
        }

        return answer;
    }
}

