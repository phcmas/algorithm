/** 516. Longest Palindromic Subsequence */
/** Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
 *  Example 1:
 *  Input: "bbbab"
 *  Output: 4
 *  One possible longest palindromic subsequence is "bbbb".
 * 
 *  Example 2:
 *  Input: "cbbd"
 *  Output: 2
 *  One possible longest palindromic subsequence is "bb".
 * 
 *  Constraints:
 *  1 <= s.length <= 1000
 *  s consists only of lowercase English letters. **/


public class LongestPalindromicSubsequence {
    public int longestPalindromeSubseq(String s) {
        int answer = 1;
        int cache[][] = new int[s.length()][s.length()];
        // cache[j][i] = length of longest subsequence of substring started from s.charAt(j), ended at s.charAt(i)

        for (int i = 0; i < s.length(); ++i) {
            cache[i][i] = 1;
            
            for (int j = i-1; j >= 0; --j) {
                if (s.charAt(j) == s.charAt(i)) {
                    cache[j][i] = 2 + cache[j+1][i-1];
                } else {
                    cache[j][i] = Math.max(cache[j][i-1], cache[j+1][i]);
                }

                answer = Math.max(answer, cache[j][i]);
            }
        }

        return answer;
    }
}
