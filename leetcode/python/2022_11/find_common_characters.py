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
from collections import Counter


class Solution:
    def common_chars(self, words: List[str]) -> List[str]:
        intersection = Counter(words[0])

        for word in words[1:]:
            intersection &= Counter(word)

        return list(intersection.elements())


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
