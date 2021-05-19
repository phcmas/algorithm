/** 842. Split Array into Fibonacci Sequence */
/** Given a string num of digits, such as num = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].
 *  Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:
 *  
 *  0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
 *  F.length >= 3;
 *  and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
 *  Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
 *  
 *  Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.
 * 
 *  Example 1:
 *  Input: num = "123456579"
 *  Output: [123,456,579]
 * 
 *  Example 2:
 *  Input: num = "11235813"
 *  Output: [1,1,2,3,5,8,13]
 * 
 *  Example 3:
 *  Input: num = "112358130"
 *  Output: []
 *  Explanation: The task is impossible.
 * 
 *  Example 4:
 *  Input: num = "0123"
 *  Output: []
 *  Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
 * 
 *  Example 5:
 *  Input: num = "1101111"
 *  Output: [110, 1, 111]
 *  Explanation: The output [11, 0, 11, 11] would also be accepted.
 * 
 *  Note:
 *  1 <= num.length <= 200
 *  num contains only digits. */

import java.util.List;
import java.util.ArrayList;

public class SplitArrayIntoFibonacciSequence {

    private boolean checkFibonacci(String num, int index, String second, String third, List<Integer> nums) {
        int thirdNum = Integer.parseInt(third);
        int secondNum = Integer.parseInt(second);
        String diff = String.valueOf(thirdNum-secondNum);
        
        if (index >= diff.length()-1) return false;
        if (index < 0) return true;

        String first = num.substring(index-diff.length()+1, index);

        if (first.equals(diff)) {
            nums.add(thirdNum-secondNum);
            return checkFibonacci(num, index-diff.length(), first, second, nums);
        }

        return false;
    }

    public List<Integer> splitIntoFibonacci(String num) {

        for (int i = num.length()-1; i >= 0; --i) {
            List<Integer> nums = new ArrayList<>();
            String third = num.substring(i);

            for (int j = 1; j <= third.length(); ++i) {
                String second = num.substring(i-j, i);
                if (checkFibonacci(num, i-j-1, second, third, nums)) {
                    return nums;
                }
            }
        }

        return null;
    }
}
