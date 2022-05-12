/** 647. Palindromic Substrings */
/** Given a string, your task is to count how many palindromic substrings in this string.
 *  The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 * 
 *  Example 1:
 *  Input: "abc"
 *  Output: 3
 *  Explanation: Three palindromic strings: "a", "b", "c".
 * 
 *  Example 2:
 *  Input: "aaa"
 *  Output: 6
 *  Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 *  Note: The input string length won't exceed 1000. */

public class PalindromicSubstrings {
    private boolean[][] isPalindromic;

    public int countSubstrings(String s) {
        int count = 0;
        isPalindromic = new boolean[s.length()+1][s.length()+1];

        if (s.isEmpty()) return 0;

        for (int i = 0; i < s.length(); ++i) {
            char elem = s.charAt(i);
            for (int j = 0; j <= i; ++j) {
                if (s.charAt(j) != elem) continue;
                if (i-j <= 1 || isPalindromic[j+1][i-1]) {
                    isPalindromic[j][i] = true;
                    count++;
                }
            }
        }
        
        return count;
    }
 }
