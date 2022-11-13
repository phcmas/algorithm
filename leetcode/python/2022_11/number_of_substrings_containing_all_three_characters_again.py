"""
1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence
of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b
and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again)

Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c
are "aaacb", "aacb" and "acb"

Example 3:
Input: s = "abc"
Output: 1

Constraints:
3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
"""


class Solution:
    def number_of_substrings(self, string: str) -> int:
        result, start = 0, 0
        count = {c: 0 for c in "abc"}

        for char in string:
            count[char] += 1

            while all(count.values()):
                count[string[start]] -= 1
                start += 1

            result += start

        return result


def main():
    string0 = "abcabc"
    string1 = "aaacb"
    string2 = "abc"
    string3 = "ababbbc"

    solution0 = Solution()
    solution1 = Solution()
    solution2 = Solution()
    solution3 = Solution()

    answer0 = solution0.number_of_substrings(string0)
    answer1 = solution1.number_of_substrings(string1)
    answer2 = solution2.number_of_substrings(string2)
    answer3 = solution3.number_of_substrings(string3)

    print(answer0)
    print(answer1)
    print(answer2)
    print(answer3)


main()
