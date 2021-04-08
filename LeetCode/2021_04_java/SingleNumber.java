import java.util.Arrays;

/** 136. Single Number */
/** Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 *  Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?
 * 
 *  Example 1:
 *  Input: nums = [2,2,1]
 *  Output: 1
 *  
 *  Example 2:
 *  Input: nums = [4,1,2,1,2]
 *  Output: 4
 * 
 *  Example 3:
 *  Input: nums = [1]
 *  Output: 1
 * 
 *  Constraints:
 *  1 <= nums.length <= 3 * 10^4
 *  -3 * 104 <= nums[i] <= 3 * 10^4
 *  Each element in the array appears twice except for one element which appears only once. */

 class SingleNumber {
     public int singleNumber(int[] nums) {
         Arrays.sort(nums);
         int count = 1;
         int prev = nums[0];

         for (int i = 1; i < nums.length; ++i) {
             if (prev != nums[i]) {
                 if (count == 1) return prev;
                 prev = nums[i];
                 count = 1;
             } else {
                count++;
             }
         }

         return prev;
     }
 }