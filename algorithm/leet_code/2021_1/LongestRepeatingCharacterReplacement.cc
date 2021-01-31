/* 424. Longest Repeating Character Replacement */
/** Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.
 *  In one operation, you can choose any character of the string and change it to any other uppercase English character.
 *  Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.
 * 
 *  Note: Both the string's length and k will not exceed 10^4.
 * 
 *  Example 1:
 *  Input:
 *  s = "ABAB", k = 2
 *  Output : 4
 *  Explanation : Replace the two 'A's with two 'B's or vice versa.
 * 
 *  Example 2:
 *  Input : s = "AABABBA", k = 1
 *  Output : 4
 * 
 *  Explanation:
 *  Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 *  The substring "BBBB" has the longest repeating letters, which is 4. **/

#include <queue>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int characterReplacement(string s, int k) {
    queue<int> indices;
    int count[26];
    int start = 0;
    int end = 1;
    int answer = 0;
    int curLength = 1;

    if (s.length() <= 1) return s.length();
    memset(count, 0, sizeof(count));

    while (end < s.length()) {
        if (s[start] == s[end]) {
            curLength++;
            end++;
        } else if (indices.size() < k) {
            indices.push(end);
            count[s[end]-'A']++;
            curLength++;
            end++;
        } else {
            
        }
    }

}

int main() {
    string s0 = "ABAB";
    int k0 = 2;
    int ans0 = characterReplacement(s0, k0);

    string s1 = "AABABBA";
    int k1 = 1;
    int ans1 = characterReplacement(s1, k1);

    cout << ans0 << endl; // 4
    cout << ans1 << endl; // 4

    return 0;
}
