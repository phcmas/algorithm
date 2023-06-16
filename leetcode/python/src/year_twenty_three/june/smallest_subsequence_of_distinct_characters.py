"""
1081. Smallest Subsequence of Distinct Characters
Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
"""


class Solution:
    def smallest_subsequence(self, s: str) -> str:
        result = ""

        for char in s:
            index = result.find(char)

            if index == -1:
                result += char
            elif index < len(result) - 1 and char >= result[index + 1]:
                result = result[:index] + result[index + 1 :] + char

        return result
