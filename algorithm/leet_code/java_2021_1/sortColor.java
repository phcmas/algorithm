/* Sort Colors */
/** Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
 *  with the colors in the order red, white, and blue.
 *  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * 
 *  Follow up:
 *  Could you solve this problem without using the library's sort function?
 *  Could you come up with a one-pass algorithm using only O(1) constant space?
 * 
 *  Example 1:
 *  Input: nums = [2,0,2,1,1,0]
 *  Output: [0,0,1,1,2,2]
 * 
 *  Example 2:
 *  Input: nums = [2,0,1]
 *  Output: [0,1,2]
 * 
 *  Example 3:
 *  Input: nums = [0]
 *  Output: [0]
 * 
 *  Example 4:
 *  Input: nums = [1]
 *  Output: [1]
 * 
 *  Constraints:
 *  n == nums.length
 *  1 <= n <= 300
 *  nums[i] is 0, 1, or 2. **/

package leet_code.java_2021_1;

public class sortColor {
    public void swap(int[] nums, int idx0, int idx1) {
        int temp = nums[idx0];
        nums[idx0] = nums[idx1];
        nums[idx1] = temp;
    }

    public void sortColor(int[] nums) {
        int nextRedIndex = 0;
        int nextBlueIndex = nums.length-1;
        int cur = 0;

        while (cur < nums.length) {
            if (nums[cur] == 2 && cur < nextBlueIndex) {
                swap(nums, cur, nextBlueIndex);
                nextBlueIndex--;
            } else if (nums[cur] == 0 && cur > nextRedIndex) {
                swap(nums, cur, nextRedIndex);
                nextRedIndex++;
            } else {
                cur++;
            }
        }
    }
    
}

