/** 45. Jump Game II */
/** Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
 *  Each element in the array represents your maximum jump length at that position.
 *  Your goal is to reach the last index in the minimum number of jumps.
 *  You can assume that you can always reach the last index.
 * 
 *  Example 1:
 *  Input: nums = [2,3,1,1,4]
 *  Output: 2
 *  Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 *  Example 2:
 *  Input: nums = [2,3,0,1,4]
 *  Output: 2
 * 
 *  Constraints:
 *  1 <= nums.length <= 10^4
 *  0 <= nums[i] <= 1000 */


public class JumpGameII {
    public int jump(int[] nums) {
        int lastIndex = nums.length-1;
        int nextIndex = nums.length-1;
        int count = 0;
        
        while (lastIndex > 0) {
            for (int i = lastIndex-1; i >= 0; --i) {
                if (nums[i] >= lastIndex-i) {
                    nextIndex = i;
                }
            }
            
            lastIndex = nextIndex;
            count++;
        }
        
        return count;
    }    
}
