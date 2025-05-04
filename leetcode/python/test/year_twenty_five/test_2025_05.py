import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.may.lru_cache as lru_cache


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
