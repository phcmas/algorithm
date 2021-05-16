/** 3. Longest Substring Without Repeating Characters */
/** Given a string s, find the length of the longest substring without repeating characters.
 * 
 *  Example 1:
 *  Input: s = "abcabcbb"
 *  Output: 3
 *  Explanation: The answer is "abc", with the length of 3.
 * 
 *  Example 2:
 *  Input: s = "bbbbb"
 *  Output: 1
 *  Explanation: The answer is "b", with the length of 1.
 * 
 *  Example 3:
 *  Input: s = "pwwkew"
 *  Output: 3
 *  Explanation: The answer is "wke", with the length of 3.
 *  Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 *  Example 4:
 *  Input: s = ""
 *  Output: 0
 * 
 *  Constraints:
 *  0 <= s.length <= 5 * 10^4
 *  s consists of English letters, digits, symbols and spaces. */

import java.util.HashSet;

public class LongestSubstringWithoutRepeatingCharacters {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> hashSet = new HashSet<>();
        int start = 0;
        int end = 0;
        int answer = 0;

        while (end < s.length()) {
            if (hashSet.contains(s.charAt(end))) {
                answer = Math.max(answer, end-start);
                hashSet.remove(s.charAt(start++));
            } else {
                hashSet.add(s.charAt(end++));
            }
        }

        answer = Math.max(answer, end-start);
        return answer;
    }
}
