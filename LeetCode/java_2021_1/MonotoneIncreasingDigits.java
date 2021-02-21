/* 738. Monotone Increasing Digits */
/** Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.
 *  (Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)
 *  
 *  Example 1:
 *  Input: N = 10
 *  Output: 9
 * 
 *  Example 2:
 *  Input: N = 1234
 *  Output: 1234
 *  
 *  Example 3:
 *  Input: N = 332
 *  Output: 299
 *  Note: N is an integer in the range [0, 10^9]. **/

package leet_code.java_2021_1;
import java.lang.Math;
import java.util.ArrayList;
import java.util.List;

public class MonotoneIncreasingDigits {
    public int monotoneIncreasingDigits2(int N) {
        char[] arr = String.valueOf(N).toCharArray();
        int end = arr.length-1;

        if (N <= 9) return N;

        for (int i = arr.length-1; i > 0; --i) {
            if (arr[i-1] > arr[i]) {
                end = i-1;
                arr[i-1]--;
            }
        }

        for (int i = end+1; i < arr.length; ++i) {
            arr[i] = '9';
        }

        return Integer.parseInt(new String(arr));
    }

    public int monotoneIncreasingDigits(int N) {
        int num = N;
        int numOfDigits = 0;
        int index = -1;
        List<Integer> digits = new ArrayList<>();

        while (num > 0) {
            digits.add(num % 10);
            num /= 10;
            numOfDigits++;
        }

        for (int i = numOfDigits-1; i >= 1; --i) {
            if (digits.get(i) < digits.get(i-1)) {
                index = -1;
            } else if (digits.get(i) >= digits.get(i-1) && index == -1) {
                index = i;
            }

            if (digits.get(i) > digits.get(i-1)) break;
        }

        if (index == -1) return N;

        for (int i = numOfDigits-1; i > index; --i) {
            num += digits.get(i) * (int)Math.pow(10, i);
        }

        num += digits.get(index) *(int)Math.pow(10, index)-1;

        return num;
    }
}

