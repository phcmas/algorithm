/* 392. Is Subsequence */
/** Given two strings s and t, check if s is a subsequence of t.
 *  A subsequence of a string is a new string that is formed from the original string by 
 *  deleting some (can be none) of the characters without disturbing the relative positions 
 *  of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 * 
 *  Example 1:
 *  Input: s = "abc", t = "ahbgdc"
 *  Output: true
 * 
 *  Example 2:
 *  Input: s = "axc", t = "ahbgdc"
 *  Output: false
 * 
 *  Constraints:
 *  0 <= s.length <= 100
 *  0 <= t.length <= 10^4
 *  s and t consist only of lowercase English letters.
 * 
 *  Follow up: If there are lots of incoming s, say s1, s2, ..., sk where k >= 10^9, 
 *  and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code? **/

public class IsSubsequence {
    public boolean isSubsequence(String s, String t) {
        int j = 0;

       if (s.length() > t.length()) return false;
       if (s.isEmpty()) return true;

       for (int i = 0; i < t.length(); ++i) {
           if (j < s.length() && t.charAt(i) == s.charAt(j)) j++;
       }

       return j == s.length();
   }
}
