/** 524. Longest Word in Dictionary through Deleting */
/** Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by 
 *  deleting some of the given string characters. If there is more than one possible result, return the longest word 
 *  with the smallest lexicographical order. If there is no possible result, return the empty string.
 * 
 *  Example 1:
 *  Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 *  Output: "apple"
 * 
 *  Example 2:
 *  Input: s = "abpcplea", dictionary = ["a","b","c"]
 *  Output: "a"
 * 
 *  Constraints:
 *  1 <= s.length <= 1000
 *  1 <= dictionary.length <= 1000
 *  1 <= dictionary[i].length <= 1000
 *  s and dictionary[i] consist of lowercase English letters. **/

import java.util.List;
import java.util.Collections;

public class LongestWordInDictionaryThroughDeleting {

    // check whether s1 can be formed by deleting characters from s0
    private boolean canBeFormed(String s0, String s1) {
        int index0 = 0;
        int index1 = 0;

        while (index0 < s0.length() && index1 < s1.length()) {
            if (s0.charAt(index0) == s1.charAt(index1)) index1++;
            index0++;
        }

        return index1 == s1.length();
    }

    public String findLongestWord(String s, List<String> dictionary) {
        String answer = "";
        int maxLength = 0;

        Collections.sort(dictionary);
        for (String iter : dictionary) {
            if (canBeFormed(s, iter) && iter.length() > maxLength) {
                maxLength = iter.length();
                answer = iter;
            }
        }

        return answer;
    }
}

