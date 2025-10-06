import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.october.connecting_cities_with_minimum_cost as minumum_cost
import year_twenty_five.october.find_the_safest_path_in_a_grid as maximum_safeness_factor


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


def test_maximum_safeness_factor():
    solution = maximum_safeness_factor.Solution()

    grid0 = [[1, 0, 0], [0, 0, 0], [0, 0, 1]]
    grid1 = [[0, 0, 1], [0, 0, 0], [0, 0, 0]]
    grid2 = [[0, 0, 0, 1], [0, 0, 0, 0], [0, 0, 0, 0], [1, 0, 0, 0]]
    grid3 = [[1, 1, 1], [0, 1, 1], [0, 0, 0]]

    ret0 = solution.maximum_safeness_factor(grid0)
    ret1 = solution.maximum_safeness_factor(grid1)
    ret2 = solution.maximum_safeness_factor(grid2)
    ret3 = solution.maximum_safeness_factor(grid3)

    assert ret0 == 0
    assert ret1 == 2
    assert ret2 == 2
    assert ret3 == 0
