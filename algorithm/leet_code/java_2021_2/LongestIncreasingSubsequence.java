/* 300. Longest Increasing Subsequence */
/** Given an integer array nums, return the length of the longest strictly increasing subsequence.
 *  A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 
 *  For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 * 
 *  Example 1 :
 *  Input : nums = [10,9,2,5,3,7,101,18]
 *  Output : 4
 *  Explanation : The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 * 
 *  Example 2 :
 *  Input : nums = [0,1,0,3,2,3]
 *  Output : 4
 * 
 *  Example 3 :
 *  Input : nums = [7,7,7,7,7,7,7]
 *  Output : 1
 * 
 *  Constraints :
 *  1 <= nums.length <= 2500
 *  -10000 <= nums[i] <= 10000
 * 
 *  Follow up :
 *  Could you come up with the O(n^2) solution?
 *  Could you improve it to O(n log(n)) time complexity? */


package leet_code.java_2021_2;

import java.util.Arrays;

public class LongestIncreasingSubsequence {
    private int[] cache;
    public int lengthOfLIS(int[] nums) {
        /* 아래는 O(n^2) 풀이 */
        int answer = 0;
        
        if (nums.length == 0) return 0;

        cache = new int[nums.length];
        Arrays.fill(cache, 1);
        answer = 1;

        for (int i = nums.length - 1; i >= 0; --i) {
            for (int j = i+1; j < nums.length; ++j) {
                if (nums[j] > nums[i]) {
                    cache[i] = Math.max(cache[i], cache[j]+1);
                    answer = Math.max(answer, cache[i]);
                }
            }
        }

        return answer;
    }

    public int lengthOfLIS2(int[] nums) {
        /* 좀 더 생각해서 nlog(n) 으로 풀 수 있다 */
        int answer = 0;
        return answer;
    }
}


