from collections import deque
import sys
from typing import List, Set


op = {0: 1, 1: 0, 2: 3, 3: 2}


def traverse(n: int, m: int, r: int, c: int, opposite: List[int], idx: int):
    if r < 0 or r >= n or c < 0 or c >= m:
        return 0

    if idx == len(opposite):
        return 1

    result = 0

    if opposite[idx][0] in (0, 1):
        sign = -1 if opposite[idx][0] == 0 else 1
        abs = opposite[idx][1]

        for i in range(abs + 1):
            if (c == 0 and sign > 0) or (c == m - 1 and sign < 0) or i == abs:
                result += traverse(n, m, r, c + sign * i, opposite, idx + 1)

    elif opposite[idx][0] in (2, 3):
        sign = -1 if opposite[idx][0] == 2 else 1
        abs = opposite[idx][1]

        for i in range(abs + 1):
            if (r == 0 and sign > 0) or (r == n - 1 and sign < 0) or i == abs:
                result += traverse(n, m, r + sign * i, c, opposite, idx + 1)

    return result


def get_opposite(queries: List[int]):
    opposite = []

    for query in queries[::-1]:
        opposite.append([op[query[0]], query[1]])

    return opposite


# def solution(n: int, m: int, x: int, y: int, queries: List[int]):
#     opposite = get_opposite(queries)
#     return traverse(n, m, x, y, opposite, 0)


# from typing import List


# def solution(elements: List[int]):
#     results, length = set(), len(elements)
#     sum = [0] * length
#     sum[0] = elements[0]

#     for i in range(1, length):
#         sum[i] = sum[i - 1] + elements[i]

#     for l in range(1, length + 1):
#         end, current = l - 1, sum[l - 1]

#         for start in range(length):
#             results.add(current)
#             current -= elements[start]
#             end = (end + 1) % length
#             current += elements[end]

#     return len(results)


# def solution(numbers: List[int]):
#     results = [-1] * len(numbers)

#     for i, number in enumerate(numbers):
#         for j, result in enumerate(results[:i]):
#             if result == -1 and number > result:
#                 results[j] = number

#     return results

# s0 = "ababcdcdababcdcd"
# print(s0)


# def dfs(k: int, cur_idx: int, dungeons: List[int], visited: List[bool]):
#     if visited[cur_idx] or dungeons[cur_idx][0] > k:
#         return 0

#     result = 1
#     visited[cur_idx] = True
#     k = k - dungeons[cur_idx][1]

#     for idx in range(len(dungeons)):
#         result = max(result, 1 + dfs(k, idx, dungeons, visited))

#     visited[cur_idx] = False
#     return result


# def solution(k: int, dungeons: List[int]):
#     visited = [False] * len(dungeons)
#     result = 0

#     for idx in range(len(dungeons)):
#         result = max(result, dfs(k, idx, dungeons, visited))

#     return result


# directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]


# def is_out_of_rectangle(x1: int, y1: int, x2: int, y2: int, r: int, c: int):
#     return r < x1 or c < y1 or r > x2 or c > y2


# def rotate(query: List[int], matrix: List[List[int]]):
#     x1, y1 = query[0] - 1, query[1] - 1
#     x2, y2 = query[2] - 1, query[3] - 1
#     cur_r, cur_c, prev = x1, y1, matrix[x1 + 1][y1]
#     minimum, idx = sys.maxsize, 0

#     while idx < 4:
#         next_r = cur_r + directions[idx][0]
#         next_c = cur_c + directions[idx][1]

#         if is_out_of_rectangle(x1, y1, x2, y2, next_r, next_c):
#             idx += 1
#             continue

#         minimum = min(minimum, matrix[cur_r][cur_c])
#         prev, matrix[cur_r][cur_c] = matrix[cur_r][cur_c], prev
#         cur_r, cur_c = next_r, next_c

#     return minimum


# def solution(rows: int, columns: int, queries: List[List[int]]):
#     matrix = [[i * columns + j for j in range(1, columns + 1)] for i in range(rows)]
#     return [rotate(query, matrix) for query in queries]


# k0 = 80
# dungeons0 = [[80, 20], [50, 40], [30, 10]]
# result0 = solution(k0, dungeons0)

# print(result0)


def solution_old(gems: List[str]):
    dist_gems = set(gems)
    result, length, start, end = [], sys.maxsize, 0, 0
    count = {gem: 0 for gem in dist_gems}
    count[gems[0]] = 1

    while True:
        contain_all_gems = True

        for gem in dist_gems:
            if count[gem] == 0:
                contain_all_gems = False
                break

        if contain_all_gems:
            if end - start + 1 < length:
                length = end - start + 1
                result = [start + 1, end + 1]

            if count[gems[start]] > 1:
                count[gems[start]] -= 1
                start += 1
            elif end < len(gems) - 1:
                end += 1
                count[gems[end]] += 1
            elif end == len(gems) - 1:
                break
        else:
            end += 1
            count[gems[end]] += 1

    return result


def solution(gems: List[str]):
    dist_gems = set(gems)
    result, length, start, end = [], sys.maxsize, 0, 0
    count = {}

    while True:
        if gems[end] in count:
            count[gems[end]] += 1
        else:
            count[gems[end]] = 1

        if len(count.keys()) == len(dist_gems):
            break

        end += 1

    while True:
        if end - start + 1 < length:
            length = end - start + 1
            result = [start + 1, end + 1]

        if count[gems[start]] > 1:
            count[gems[start]] -= 1
            start += 1
        elif end < len(gems) - 1:
            end += 1
            count[gems[end]] += 1
        elif end == len(gems) - 1:
            break

    return result


gems0 = ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]
gems1 = ["AA", "AB", "AC", "AA", "AC"]
gems2 = ["XYZ", "XYZ", "XYZ"]
gems3 = ["ZZZ", "YYY", "NNNN", "YYY", "BBB"]

result0 = solution(gems0)
result1 = solution(gems1)
result2 = solution(gems2)
result3 = solution(gems3)

print(result0)
print(result1)
print(result2)
print(result3)
