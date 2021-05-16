import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;

/** 740. Delete and Earn */
/** Given an array nums of integers, you can perform operations on the array.
 *  In each operation, you pick any nums[i] and delete it to earn nums[i] points. 
 *  After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
 *  You start with 0 points. Return the maximum number of points you can earn by applying such operations.
 * 
 *  Example 1:
 *  Input: nums = [3,4,2]
 *  Output: 6
 *  Explanation: Delete 4 to earn 4 points, consequently 3 is also deleted.
 *  Then, delete 2 to earn 2 points.
 *  6 total points are earned.
 * 
 *  Example 2:
 *  Input: nums = [2,2,3,3,3,4]
 *  Output: 9
 *  Explanation: Delete 3 to earn 3 points, deleting both 2's and the 4.
 *  Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
 *  9 total points are earned.
 * 
 *  Constraints:
 *  1 <= nums.length <= 2 * 10^4
 *  1 <= nums[i] <= 10^4 **/

import java.util.List;

public class DeleteAndEarn {
    int[] cache;

    private int dp(List<Integer> numbers, List<Integer> counts) {
        int lastIndex = numbers.size()-1;
        cache = new int[numbers.size()+1];
        cache[lastIndex+1] = 0;
        cache[lastIndex] = numbers.get(lastIndex) * counts.get(lastIndex);

        for (int i = numbers.size()-2; i >= 0; --i) {
            int curSum = numbers.get(i) * counts.get(i);
            if (numbers.get(i+1) - numbers.get(i) == 1) {
                cache[i] = Integer.max(cache[i+1], cache[i+2] + curSum);
            } else {
                cache[i] = cache[i+1] + curSum;
            }
        }

        return cache[0];
    }

    public int deleteAndEarn(int[] nums) {
        Arrays.sort(nums);

        int cur = nums[0];
        int count = 1;
        List<Integer> numbers = new ArrayList<>();
        List<Integer> counts = new ArrayList<>();
        
        for (int i = 1; i < nums.length; ++i) {
            if (cur != nums[i]) {
                numbers.add(cur);
                counts.add(count);
                cur = nums[i];
                count = 1;
            } else {
                count++;
            }
        }

        numbers.add(cur);
        counts.add(count);
        return dp(numbers, counts);
    }
}
