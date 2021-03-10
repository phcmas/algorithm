/** 78. Subsets */
/** Given an integer array nums of unique elements, return all possible subsets (the power set).
 *  The solution set must not contain duplicate subsets. Return the solution in any order.
 *  
 *  Example 1:
 *  Input: nums = [1,2,3]
 *  Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 *  Example 2:
 *  Input: nums = [0]
 *  Output: [[],[0]]
 * 
 *  Constraints:
 *  1 <= nums.length <= 10
 *  -10 <= nums[i] <= 10
 *  All the numbers of nums are unique. **/

import java.util.List;
import java.util.ArrayList;

public class Subsets {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> answer = new ArrayList<>();
        int bit = (1 << nums.length) - 1;

        for (int subbit = bit; subbit >= 0; subbit = subbit-1) {
            List<Integer> subset = new ArrayList<>();

            for (int i = 0; i < nums.length; ++i) {
                if (((1 << i) & subbit) > 0) subset.add(nums[i]);
            }

            answer.add(subset);
        }

        return answer;
    }
}
