import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.may.lru_cache as lru_cache
import year_twenty_five.may.insert_delete_get_random_o1 as insert_delete_get_random_o1
import year_twenty_five.may.count_good_numbers as count_good_numbers


def test_lru_cache():
    cache = lru_cache.LRUCache(2)

    cache.put(1, 1)
    cache.put(2, 2)

    result0 = cache.get(1)
    assert result0 == 1

    cache.put(3, 3)

    result1 = cache.get(2)
    assert result1 == -1

    cache.put(4, 4)

    result2 = cache.get(1)
    result3 = cache.get(3)
    result4 = cache.get(4)

    assert result2 == -1
    assert result3 == 3
    assert result4 == 4

    cache = lru_cache.LRUCache(2)
    result0 = cache.get(2)
    assert result0 == -1

    cache.put(2, 6)

    result1 = cache.get(1)
    assert result1 == -1

    cache.put(1, 5)

    cache.put(1, 2)

    result2 = cache.get(1)
    assert result2 == 2

    result3 = cache.get(2)
    assert result3 == 6

    cache = lru_cache.LRUCache(1)
    cache.put(2, 1)

    result0 = cache.get(2)
    assert result0 == 1

    cache.put(3, 2)
    result1 = cache.get(2)
    assert result1 == -1

    result2 = cache.get(3)
    assert result2 == 2


def test_insert_delete_random_o1():
    solution = insert_delete_get_random_o1.RandomizedSet()

    result0 = solution.insert(0)
    result1 = solution.insert(1)
    result2 = solution.insert(1)

    result3 = solution.remove(0)
    result4 = solution.insert(2)
    result5 = solution.remove(1)
    result6 = solution.remove(1)

    result7 = solution.get_random()

    assert result0 is True
    assert result1 is True
    assert result2 is False

    assert result3 is True
    assert result4 is True
    assert result5 is True
    assert result6 is False

    assert result7 == 2


def test_count_good_numbers():
    solution = count_good_numbers.Solution()

    result0 = solution.count_good_numbers(1)
    result1 = solution.count_good_numbers(4)
    result2 = solution.count_good_numbers(50)

    assert result0 == 5
    assert result1 == 400
    assert result2 == 564908303
