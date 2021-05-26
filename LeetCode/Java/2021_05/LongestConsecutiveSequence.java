/** 128. Longest Consecutive Sequence */
/** Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 *  You must write an algorithm that runs in O(n) time.
 * 
 *  Example 1:
 *  Input: nums = [100,4,200,1,3,2]
 *  Output: 4
 *  Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 * 
 *  Example 2:
 *  Input: nums = [0,3,7,2,5,8,4,6,0,1]
 *  Output: 9
 * 
 *  Constraints:
 *  0 <= nums.length <= 10^5
 *  -10^9 <= nums[i] <= 10^9 **/

public class LongestConsecutiveSequence {

    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        
        int min = nums[0];
        int max = nums[0];

        for (int i = 0; i < nums.length; ++i) {
            min = Math.min(min, nums[i]);
            max = Math.max(max, nums[i]);
        }

        // union find 로 할 수 있을 듯 내일 꼭 푼다

    }
}