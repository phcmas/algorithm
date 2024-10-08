import sys
from os.path import abspath, dirname, join


SRC_DIR = join(dirname(__file__), "../src")
sys.path.insert(1, abspath(SRC_DIR))

# ruff: noqa
import year_twenty_four.october.distant_barcodes as distant_barcodes


def test_distant_barcodes():
    solution = distant_barcodes.Solution()

    barcodes0 = [1, 1, 1, 2, 2, 2]
    barcodes1 = [1, 1, 1, 1, 2, 2, 3, 3]

    result0 = solution.rearrange_barcodes(barcodes0)
    result1 = solution.rearrange_barcodes(barcodes1)

    assert result0 == [1, 2, 1, 2, 1, 2]
    assert result1 == [1, 2, 1, 3, 1, 2, 1, 3]
