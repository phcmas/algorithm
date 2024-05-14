import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0411,C0413,R0402,E0401
import year_twenty_four.may.find_the_distance_value_between_two_arrays as find_the_distance
import year_twenty_four.may.fair_candy_swap as find_candy_swap
import year_twenty_four.may.find_the_k_beauty_of_a_number as find_the_k_beauty
import year_twenty_four.may.binary_trees_with_factors as binary_trees_with_factors
import year_twenty_four.may.rabbits_in_forest as rabbits_in_forest


def test_find_the_distance_value():
    solution0 = find_the_distance.Solution()
    solution1 = find_the_distance.Solution()
    solution2 = find_the_distance.Solution()

    arr01, arr02, d0 = [4, 5, 8], [10, 9, 1, 8], 2
    arr11, arr12, d1 = [1, 4, 2, 3], [-4, -3, 6, 10, 20, 30], 3
    arr21, arr22, d2 = [2, 1, 100, 3], [-5, -2, 10, -3, 7], 6

    result0 = solution0.find_the_distance_value(arr01, arr02, d0)
    result1 = solution1.find_the_distance_value(arr11, arr12, d1)
    result2 = solution2.find_the_distance_value(arr21, arr22, d2)

    assert result0 == 2
    assert result1 == 2
    assert result2 == 1


def test_find_candy_swap():
    soluion0 = find_candy_swap.Solution()
    soluion1 = find_candy_swap.Solution()
    soluion2 = find_candy_swap.Solution()

    aliceSizes0, bobSizes0 = [1, 1], [2, 2]
    aliceSizes1, bobSizes1 = [1, 2], [2, 3]
    aliceSizes2, bobSizes2 = [2], [1, 3]

    result0 = soluion0.fair_candy_swap(aliceSizes0, bobSizes0)
    result1 = soluion1.fair_candy_swap(aliceSizes1, bobSizes1)
    result2 = soluion2.fair_candy_swap(aliceSizes2, bobSizes2)

    assert result0 == [1, 2]
    assert result1 == [1, 2]
    assert result2 == [2, 3]


def test_find_the_k_beauty():
    solution0 = find_the_k_beauty.Solution()
    solution1 = find_the_k_beauty.Solution()

    num0, k0 = 240, 2
    num1, k1 = 430043, 2

    result0 = solution0.divisor_substrings(num0, k0)
    result1 = solution1.divisor_substrings(num1, k1)

    assert result0 == 2
    assert result1 == 2


def test_binary_trees_with_factors():
    solution0 = binary_trees_with_factors.Solution()
    solution1 = binary_trees_with_factors.Solution()
    solution2 = binary_trees_with_factors.Solution()

    arr0 = [2, 4]
    arr1 = [2, 4, 5, 10]
    arr2 = [18, 3, 6, 2]

    result0 = solution0.num_factored_binary_trees(arr0)
    result1 = solution1.num_factored_binary_trees(arr1)
    result2 = solution2.num_factored_binary_trees(arr2)

    assert result0 == 3
    assert result1 == 7
    assert result2 == 12


def test_rabbits_in_forest():
    solution0 = rabbits_in_forest.Solution()
    solution1 = rabbits_in_forest.Solution()

    answers0 = [1, 1, 2]
    answers1 = [10, 10, 10]

    result0 = solution0.num_rabbits(answers0)
    result1 = solution1.num_rabbits(answers1)

    assert result0 == 5
    assert result1 == 11
