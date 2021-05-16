import java.util.Arrays;

/** 1027. Longest Arithmetic Subsequence */
/** Given an array A of integers, return the length of the longest arithmetic subsequence in A.
 *  Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, 
 *  and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).
 * 
 *  Example 1:
 *  Input: A = [3,6,9,12]
 *  Output: 4
 *  Explanation: 
 *  The whole array is an arithmetic sequence with steps of length = 3.
 * 
 *  Example 2:
 *  Input: A = [9,4,7,2,10]
 *  Output: 3
 *  Explanation: 
 *  The longest arithmetic subsequence is [4,7,10].
 * 
 *  Example 3:
 *  Input: A = [20,1,15,3,10,5,8]
 *  Output: 4
 *  Explanation: 
 *  The longest arithmetic subsequence is [20,15,10,5].
 * 
 *  Constraints:
 *  2 <= A.length <= 1000
 *  0 <= A[i] <= 500 */


public class LongestArithmeticSubsequence {
    private int[][] cache;

    private int getIndex(int difference) {
        if (difference < 0) return (difference * -1) + 500;
        return difference;
    }

    public int longestArithSeqLength(int[] A) {
        int max = 0;
        cache = new int[1000][1001];

        for (int i = 0; i < 1000; ++i) {
            for (int j = 0; j < 1001; ++j) {
                cache[i][j] = 1;
            }
        }

        for (int i = A.length-1; i >= 0; --i) {
            for (int j = i+1; j <= A.length-1; ++j) {
                int index = getIndex(A[i]-A[j]);
                cache[i][index] = Math.max(cache[i][index], cache[j][index]+1);
                max = Math.max(cache[i][index], max);
            }
        }

        return max;
    }
}

