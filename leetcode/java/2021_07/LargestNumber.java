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

public class LargestNumber {
    class Triple implements Comparable<Triple> {
        public int origLength;
        public int value;
        public int index;
        
        public Triple(int origLength, int value, int index) {
            this.origLength = origLength;
            this.value = value;
            this.index = index;
        }
        
        @Override
        public int compareTo(Triple o) {
            if (o.value == value) {
                if (o.origLength == origLength) return 0;
                if (o.origLength > origLength) {
                    return value / (int)Math.pow(10, o.origLength-origLength) - o.value % (int)Math.pow(10, origLength);
                } else {
                    return value % (int)Math.pow(10, o.origLength) - o.value / (int)Math.pow(10, origLength - o.origLength);
                }
            }

            return o.value - value;   
        }
    };

    public void setTriples(int[] nums, int maxLength, PriorityQueue<Triple> pq) {
        for (int i = 0; i < nums.length; ++i) {
            String str1 = Integer.toString(nums[i]);
            int origLength = str1.length();
            int index = 0;

            for (int j = 0; j < maxLength - origLength; ++j) {
                str1 += str1.charAt(index);
                index = (index + 1) % origLength;
            }

            pq.add(new Triple(origLength, Integer.valueOf(str1), i));
        }
    }
    
    public String largestNumber(int[] nums) {
        String answer = "";
        int maxLength = 0;
        int start = 0;
        PriorityQueue<Triple> pq = new PriorityQueue<>();

        for (int i = 0; i < nums.length; ++i) {
            maxLength = Math.max(maxLength, Integer.toString(nums[i]).length());
        }

        setTriples(nums, maxLength, pq);

        while (!pq.isEmpty()) {
            answer += Integer.toString(nums[pq.poll().index]);
        }

        for (int i = 0; i < answer.length(); ++i) {
            if (answer.charAt(i) != '0') break;
            start++;
        }

        if (start == answer.length()) start--;
        return answer.substring(start);
    }
}


