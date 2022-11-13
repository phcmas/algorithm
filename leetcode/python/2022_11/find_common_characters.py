"""
1002. Find Common Characters

Given a string array words, return an array of all characters that show up in all strings
within the words (including duplicates). You may return the answer in any order.

Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: words = ["cool","lock","cook"]
Output: ["c","o"]

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.

"""

from typing import List


class Solution:
    def char_count(self, word: str) -> dict:
        result = {}

        for char in word:
            if char in result:
                result[char] += 1
            else:
                result[char] = 1

        return result

    def intersect(self, dict0: dict, dict1: dict) -> dict:
        result = {}

        for key in dict0.keys() & dict1.keys():
            result[key] = min(dict0[key], dict1[key])

        return result

    def common_chars(self, words: List[str]) -> List[str]:
        result = []
        intersection = self.char_count(words[0])

        for i in range(1, len(words)):
            count = self.char_count(words[i])
            intersection = self.intersect(intersection, count)

        for key, value in intersection.items():
            for i in range(value):
                result.append(key)

        return result


def main():
    words0 = ["bella", "label", "roller"]
    words1 = ["cool", "lock", "cook"]

    solution0 = Solution()
    solution1 = Solution()

    ret0 = solution0.common_chars(words0)
    ret1 = solution1.common_chars(words1)

    print(ret0)
    print(ret1)


main()
