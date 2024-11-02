"""
880. Decoded String at Index
You are given an encoded string s. To decode the string to a tape, the encoded string is read
one character at a time and the following steps are taken:
If the character read is a letter, that letter is written onto the tape.
If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
Given an integer k, return the kth letter (1-indexed) in the decoded string.

Example 1:
Input: s = "leet2code3", k = 10
Output: "o"
Explanation: The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".

Example 2:
Input: s = "ha22", k = 5
Output: "h"
Explanation: The decoded string is "hahahaha".
The 5th letter is "h".

Example 3:
Input: s = "a2345678999999999999999", k = 1
Output: "a"
Explanation: The decoded string is "a" repeated 8301530446056247680 times.
The 1st letter is "a".

Constraints:
2 <= s.length <= 100
s consists of lowercase English letters and digits 2 through 9.
s starts with a letter.
1 <= k <= 10^9
It is guaranteed that k is less than or equal to the length of the decoded string.
The decoded string is guaranteed to have less than 263 letters.
"""


class Solution:
    def _make_lens(self, s: str) -> list[int]:
        len, lens = 0, []

        for char in s:
            len = len * int(char) if char.isdigit() else len + 1
            lens.append(len)

        return lens

    def _find_char(self, s: str, k: int, lens: list[int]) -> str:
        k = k % lens[-1]

        if k == 0:
            return next((c for c in reversed(s) if c.isalpha()), None)

        for i, len in enumerate(lens):
            if len <= k < lens[i + 1]:
                return self._find_char(s[: i + 1], k, lens[: i + 1])

    def decode_at_index(self, s: str, k: int) -> str:
        lens = self._make_lens(s)
        return self._find_char(s, k, lens)
