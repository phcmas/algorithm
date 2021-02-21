/* 131. Palindrome Partitioning */
/** Given a string s, partition s such that every substring of the partition is a palindrome. 
 *  Return all possible palindrome partitioning of s.
 *  A palindrome string is a string that reads the same backward as forward.
 * 
 *  Example 1:
 *  Input: s = "aab"
 *  Output: [["a","a","b"],["aa","b"]]
 * 
 *  Example 2:
 *  Input: s = "a"
 *  Output: [["a"]]
 * 
 *  Constraints:
 *  1 <= s.length <= 16
 *  s contains only lowercase English letters. **/

package leet_code.java_2021_1;
import java.util.ArrayList;
import java.util.List;

public class PalindromePartitioning {
    List<List<String>> answer = new ArrayList<>();

    public boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length()-1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) return false;
            left++;
            right--;
        }

        return true;
    }

    public void backTracking(String s, int start, List<String> partitions) {
        if (start > s.length()-1) {
            List<String> copy = new ArrayList<>(partitions);
            answer.add(copy);
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            String substr = s.substring(start, i+1);
            if (isPalindrome(substr)) {
                partitions.add(substr);
                backTracking(s, i+1, partitions);
                partitions.remove(partitions.size()-1);
            }
        }

    }

    public List<List<String>> partition(String s) {
        List<String> partitions = new ArrayList<>();
        backTracking(s, 0, partitions);

        return answer;
    }
}




