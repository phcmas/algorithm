/** 179. Largest Number */
/** Given a list of non-negative integers nums, arrange them such that they form the largest number.
 *  Note: The result may be very large, so you need to return a string instead of an integer.
 * 
 *  Example 1:
 *  Input: nums = [10,2]
 *  Output: "210"
 * 
 *  Example 2:
 *  Input: nums = [3,30,34,5,9]
 *  Output: "9534330"
 * 
 *  Example 3:
 *  Input: nums = [1]
 *  Output: "1"
 * 
 *  Example 4:
 *  Input: nums = [10]
 *  Output: "10"
 *  
 *  Constraints:
 *  1 <= nums.length <= 100
 *  0 <= nums[i] <= 10^9 */

import java.util.*;
import java.util.Arrays;

public class LargestNumber2 {
    private class newComparator implements Comparator<String> {
        @Override
        public int compare(String a, String b) {
            String cand1 = a + b;
            String cand2 = b + a;
            return cand1.compareTo(cand2);
        }
    }

    public String largestNumber(int[] nums) {
        String[] asStrs = new String[nums.length];
        String answer = "";
        
        for (int i = 0; i < nums.length; ++i) {
            asStrs[i] = String.valueOf(nums[i]);
        }

        Arrays.sort(asStrs, new newComparator());

        for (int i = nums.length-1; i >= 0; --i) {
            answer += asStrs[i];
        }

        if (answer.charAt(0) == '0') return "0";
        return answer;
    }
}


