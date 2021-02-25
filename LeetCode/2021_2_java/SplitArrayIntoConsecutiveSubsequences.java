/* 659. Split Array into Consecutive Subsequences */
/** Given an integer array nums that is sorted in ascending order, 
 *  return true if and only if you can split it into one or more subsequences such that 
 *  each subsequence consists of consecutive integers and has a length of at least 3.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3,3,4,5]
 *  Output: true
 *  Explanation:
 *  You can split them into two consecutive subsequences : 
 *  1, 2, 3     3, 4, 5
 * 
 *  Example 2:
 *  Input: nums = [1,2,3,3,4,4,5,5]
 *  Output: true
 *  Explanation:
 *  You can split them into two consecutive subsequences : 
 *  1, 2, 3, 4, 5    3, 4, 5
 * 
 *  Example 3:
 *  Input: nums = [1,2,3,4,4,5]
 *  Output: false
 * 
 *  Constraints:
 *  1 <= nums.length <= 10^4
 *  -1000 <= nums[i] <= 1000
 *  nums is sorted in an ascending order. **/

import java.util.PriorityQueue;
import java.util.Queue;
import java.util.HashMap;

public class SplitArrayIntoConsecutiveSubsequences {
    public boolean isPossible(int[] nums) {
        HashMap<Integer, Integer> counts = new HashMap<>();
        HashMap<Integer, Integer> tails = new HashMap<>();

        for (int iter : nums) counts.put(iter, counts.getOrDefault(iter, 0)+1);

        for (int iter : nums) {
            if (counts.get(iter) == 0) {
                continue;
            } else if (tails.getOrDefault(iter, 0) > 0) {
                tails.put(iter, tails.getOrDefault(iter, 0)-1);
                tails.put(iter+1, tails.getOrDefault(iter+1, 0)+1);
            } else if (counts.getOrDefault(iter+1, 0) > 0 && counts.getOrDefault(iter+2, 0) > 0) {
                counts.put(iter+1, counts.getOrDefault(iter+1, 0)-1);
                counts.put(iter+2, counts.getOrDefault(iter+2, 0)-1);
                tails.put(iter+3, tails.getOrDefault(iter+3, 0)+1);
            } else return false;

            counts.put(iter, counts.getOrDefault(iter, 0)-1);
        }

        return true;
    }
}

