import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))


import year_twenty_six.january.isomorphic_strings as isomorphic_strings


def test_isomorphic_strings():
    solution = isomorphic_strings.Solution()

    s0, t0 = "egg", "add"
    s1, t1 = "foo", "bar"
    s2, t2 = "paper", "title"
    s3, t3 = "badc", "baba"

    ret0 = solution.is_isomorphic(s0, t0)
    ret1 = solution.is_isomorphic(s1, t1)
    ret2 = solution.is_isomorphic(s2, t2)
    ret3 = solution.is_isomorphic(s3, t3)

    assert ret0 is True
    assert ret1 is False
    assert ret2 is True
    assert ret3 is False
