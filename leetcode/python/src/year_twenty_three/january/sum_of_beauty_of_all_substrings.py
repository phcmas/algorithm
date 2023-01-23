""" 1781. Sum of Beauty of All Substrings """
""" 
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

Example 1:
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

Example 2:
Input: s = "aabcbaa"
Output: 17

Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters. 
"""
from collections import defaultdict


class Solution:
    def beauty_sum(self, s: str) -> int:
        beauty = 0

        for i in range(len(s) - 2):
            freq = {}

            for j in range(i, len(s)):
                freq.setdefault(s[j], 0)
                freq[s[j]] += 1
                beauty += max(freq.values()) - min(freq.values())

        return beauty
