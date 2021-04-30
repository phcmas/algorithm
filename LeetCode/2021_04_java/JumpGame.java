import java.util.Arrays;

/** 55. Jump Game */
/** Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
 *  Each element in the array represents your maximum jump length at that position.
 *  Determine if you are able to reach the last index.
 * 
 *  Example 1:
 *  Input: nums = [2,3,1,1,4]
 *  Output: true
 *  Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 *  Example 2:
 *  Input: nums = [3,2,1,0,4]
 *  Output: false
 *  Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 * 
 *  Constraints:
 *  1 <= nums.length <= 3 * 10^4
 *  0 <= nums[i] <= 10^5 */


public class JumpGame {
    // 처음에 DP를 이용하여 풀었으나(canJump2) Time Limit Exceeded 발생
    int[] cache = new int[30000];

    public JumpGame() {}

    private int canJumpInternal(int[] nums, int index) {
        int result = 0;
        
        if (cache[index] != -1) return cache[index];
        if (index < nums.length-1 && nums[index] == 0) return 0;
        if (index >= nums.length-1 || nums[index]+index >= nums.length-1) return 1;

        for (int i = 1; i <= nums[index]; ++i) {
            result |= canJumpInternal(nums, index+i);
        }

        return result;
    }

    public boolean canJump2(int[] nums) {
        Arrays.fill(cache, -1);
        int result = canJumpInternal(nums, 0);
        return result == 1 ? true : false;
    }

    public boolean canJump(int[] nums) {
        boolean result = true;
        int zeroIndex = -1;

        if (nums.length == 1) return true;

        for (int i = nums.length-2; i >= 0; --i) {
            if (nums[i] == 0) {
                if (result == false) continue;
                zeroIndex = i;
                result = false;
            } else if (nums[i] > zeroIndex-i) {
                result = true;
            }
        }

        return result;
    }

}