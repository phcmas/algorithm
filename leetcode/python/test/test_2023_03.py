import sys
from os.path import dirname, abspath, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_three.march.maximum_product_of_the_length_of_two_palindromic_subsequences as max_product
import year_twenty_three.march.predict_the_winner as predict_the_winner
import year_twenty_three.march.break_a_palindrome as break_a_palindrome


# def test_max_product():
#    solution0 = max_product.Solution()
#    solution1 = max_product.Solution()
#    solution2 = max_product.Solution()
#
#    s0 = "leetcodecom"
#    s1 = "bb"
#    s2 = "accbcaxxcxx"
#
#    result0 = solution0.max_product(s0)
#    result1 = solution1.max_product(s1)
#    result2 = solution2.max_product(s2)
#
#    answer0 = 9
#    answer1 = 1
#    answer2 = 25
#
#    assert result0 == answer0
#    assert result1 == answer1
#    assert result2 == answer2


def test_predict_the_winner():
    solution0 = predict_the_winner.Solution()
    solution1 = predict_the_winner.Solution()

    nums0 = [1, 5, 2]
    nums1 = [1, 5, 233, 7]

    result0 = solution0.predict_the_winner(nums0)
    result1 = solution1.predict_the_winner(nums1)

    answer0 = False
    answer1 = True

    assert result0 == answer0
    assert result1 == answer1


def test_break_palindrome():
    solution0 = break_a_palindrome.Solution()
    solution1 = break_a_palindrome.Solution()
    solution2 = break_a_palindrome.Solution()
    solution3 = break_a_palindrome.Solution()
    solution4 = break_a_palindrome.Solution()

    palindrome0 = "abccba"
    palindrome1 = "a"
    palindrome2 = "bccaccb"
    palindrome3 = "aa"
    palindrome4 = "aba"

    result0 = solution0.break_palindrome(palindrome0)
    result1 = solution1.break_palindrome(palindrome1)
    result2 = solution2.break_palindrome(palindrome2)
    result3 = solution3.break_palindrome(palindrome3)
    result4 = solution4.break_palindrome(palindrome4)

    answer0 = "aaccba"
    answer1 = ""
    answer2 = "accaccb"
    answer3 = "ab"
    answer4 = "abb"

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2
    assert result3 == answer3
    assert result4 == answer4
