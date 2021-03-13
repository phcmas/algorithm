/** 395. Longest Substring with At Least K Repeating Characters */
/** Given a string s and an integer k, return the length of the longest substring of s 
 *  such that the frequency of each character in this substring is greater than or equal to k.
 * 
 *  Example 1:
 *  Input: s = "aaabb", k = 3
 *  Output: 3
 *  Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 *  Example 2:
 *  Input: s = "ababbc", k = 2
 *  Output: 5
 *  Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 * 
 *  Constraints:
 *  1 <= s.length <= 10^4
 *  s consists of only lowercase English letters.
 *  1 <= k <= 10^5 */

import java.util.HashMap;

public class LongestSubstringWithAtLeastKRepeatingCharacters {
    public int longestSubstring(String s, int k) {
        HashMap<Character, Integer> hashMap = new HashMap<>();
        int[] count = new int[26];
        int index = -1;

        for (int i = 0; i < s.length(); ++i) {
            count[s.charAt(i)-'a']++;
            if (!hashMap.containsKey(s.charAt(i))) hashMap.put(s.charAt(i), i);
        }

        for (int i = 0; i < 26; ++i) {
            if (count[i] < k && hashMap.containsKey((char)(i + 'a'))) index = hashMap.get((char)(i + 'a'));
        }

        if (index == -1) return s.length();
        
        int cand1 = longestSubstring(s.substring(0, index), k);
        int cand2 = longestSubstring(s.substring(index+1), k);
        
        return Math.max(cand1, cand2);
    }
}
