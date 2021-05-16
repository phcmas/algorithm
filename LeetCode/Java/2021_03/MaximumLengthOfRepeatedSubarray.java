/** 718. Maximum Length of Repeated Subarray */
/** Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
 * 
 *  Example 1:
 *  Input:
 *  A: [1,2,3,2,1]
 *  B: [3,2,1,4,7]
 * 
 *  Output: 3
 *  Explanation: 
 *  The repeated subarray with maximum length is [3, 2, 1].
 *  Note:
 *  1 <= len(A), len(B) <= 1000
 *  0 <= A[i], B[i] < 100 */

public class MaximumLengthOfRepeatedSubarray {
    int[][] cache;

    // 처음은 dp를 이용해서 풀어보았다.
    public int findLength(int[] A, int[] B) {
        int answer = 0;
        cache = new int[A.length+1][B.length+1];

        for (int i = A.length - 1; i >= 0; --i) {
            for (int j = 0; j < B.length; ++j) {
                if (A[i] == B[j]) {
                    cache[i][j] = cache[i+1][j+1] + 1;
                    answer = Math.max(answer, cache[i][j]);
                }
            }
        }

        return answer;
    }    
}

