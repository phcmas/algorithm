import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.october.connecting_cities_with_minimum_cost as minumum_cost


def test_minimum_cost():
    solution = minumum_cost.Solution()

    n0 = 3
    connections0 = [[1, 2, 5], [1, 3, 6], [2, 3, 1]]

    n1 = 4
    connections1 = [[1, 2, 3], [3, 4, 4]]

    ret0 = solution.minimum_cost(n0, connections0)
    ret1 = solution.minimum_cost(n1, connections1)

    assert ret0 == 6
    assert ret1 == -1
