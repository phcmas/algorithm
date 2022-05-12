/** 503. Next Greater Element II */
/** Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
 *  return the next greater number for every element in nums.
 *  The next greater number of a number x is the first greater number to its traversing-order next in the array, 
 *  which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
 * 
 *  Example 1:
 *  Input: nums = [1,2,1]
 *  Output: [2,-1,2]
 *  Explanation: The first 1's next greater number is 2; 
 *  The number 2 can't find next greater number. 
 *  The second 1's next greater number needs to search circularly, which is also 2.
 * 
 *  Example 2:
 *  Input: nums = [1,2,3,4,3]
 *  Output: [2,3,4,-1,4]
 *  
 *  Constraints:
 *  1 <= nums.length <= 10^4
 *  -10^9 <= nums[i] <= 10^9 */

import java.util.Arrays;
import java.util.Stack;

public class NextGreaterElementII {
    public int[] nextGreaterElements(int[] nums) {
        int[] answer = new int[nums.length];
        boolean[] inserted = new boolean[nums.length];
        Stack<Integer> stack = new Stack<>();

        Arrays.fill(answer, -1);
        
        for (int i = 0; i < 2 * nums.length -1; ++i) {
            int curIndex = i % nums.length;

            while (!stack.isEmpty() && nums[stack.peek()] < nums[curIndex]) {
                answer[stack.peek()] = nums[curIndex];
                stack.pop();
            }

            if (!inserted[curIndex]) {
                stack.push(curIndex);
                inserted[curIndex] = true;
            }
        }

        return answer;
    }
}