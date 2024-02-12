from typing import List
import sys


def minimal_cover(coords: List[int]):
    first, second, y_max = [], [], -1
    coords.sort(key=lambda s: [s[0], -s[1]])

    for coord in coords:
        if coord[1] > y_max:
            first.append(coord)
            y_max = coord[1]

    for idx, coord in enumerate(first):
        if idx == 0 or idx == len(first) - 1 or first[idx + 1][0] > first[idx - 1][1]:
            second.append(coord)

    return second


def merge(coords: List[int]):
    if len(coords) == 0:
        return []

    x_min, y_max, result = coords[0][0], coords[0][1], []
    coords.sort(key=lambda s: s[0])

    for coord in coords:
        if coord[0] > y_max:
            result.append((x_min, y_max))
            x_min, y_max = coord[0], coord[1]
        else:
            y_max = max(y_max, coord[1])

    result.append((x_min, y_max))
    return result


intervals0 = [(1, 3), (5, 8), (4, 10), (20, 25)]
result0 = merge(intervals0)
assert result0 == [(1, 3), (4, 10), (20, 25)]

intervals1 = [(1, 3), (5, 8), (4, 10), (20, 25), (22, 27)]
result1 = merge(intervals1)
assert result1 == [(1, 3), (4, 10), (20, 27)]
