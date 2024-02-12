from math import floor
from typing import Dict, List, Optional
from collections import Counter
import sys


test = ["d", "d", "e"]

test.remove("d")

print(test)


def pickingNumbers(nums: List[int]):
    counter = Counter(nums)
    keys_sorted = sorted(counter.elements())
    result = 0

    for key in keys_sorted:
        if key + 1 in counter:
            result = max(result, counter[key] + counter[key + 1])

    return result


def getRoot(x: int, n: int):
    result = 1

    for i in range(1, x + 1):
        if i**n > x:
            break

        result = i

    return result


def powerSum(x: int, n: int):
    ways = [[0] * (x + 1) for _ in range(x + 1)]

    for i in range(1, x + 1):
        root = getRoot(i, n)

        for j in range(1, root + 1):
            for k in range(j + 1, i - j**n + 1):
                ways[i][j] += ways[i - j**n][k]

        ways[i][j] += 1 if root**n == i else 0

    return sum(ways[x][i] for i in range(1, x + 1))


def make_graph(n: int, roads: List[List[int]]):
    graph = {}

    for i in range(n + 1):
        graph[i] = []

    for road in roads:
        graph[road[0]].append(road[1])
        graph[road[1]].append(road[0])

    return graph


def travel(n: int, destination: int, graph: Dict[int, List[int]]) -> List[int]:
    distance, distances = -1, [-1] * (n + 1)
    regions, seen = [destination], set([destination])

    while len(regions) > 0:
        length = len(regions)
        distance += 1

        for _ in range(length):
            region = regions.pop(0)
            neighbors = graph[region]
            distances[region] = distance

            for neighbor in neighbors:
                if neighbor not in seen:
                    regions.append(neighbor)

            seen.update(neighbors)

    return distances


def solution(n: int, roads: List[List[int]], sources: List[int], destination: int):
    result = []
    graph = make_graph(n, roads)
    distances = travel(n, destination, graph)

    for source in sources:
        result.append(distances[source])

    return result


directions = ["d", "l", "r", "u"]
opposites = {"d": "u", "l": "r", "r": "l", "u": "d"}
coords = [[1, 0], [0, -1], [0, 1], [-1, 0]]


def get_essentials(x: int, y: int, r: int, c: int):
    row_direction = "d" if r >= x else "u"
    col_direction = "r" if c >= y else "l"

    return [row_direction] * abs(r - x) + [col_direction] * abs(c - y)


def is_out_of_boundary(row: int, col: int, n: int, m: int):
    return row <= 0 or row > n or col <= 0 or col > m


def escape_maze(n: int, m: int, x: int, y: int, r: int, c: int, k: int):
    result, row, col = "", x, y
    essentials = get_essentials(x, y, r, c)

    while len(result) < k:
        for idx, direction in enumerate(directions):
            next_row = row + coords[idx][0]
            next_col = col + coords[idx][1]
            is_essential = direction in essentials
            must_be_essential = len(result) == k - len(essentials)

            if is_out_of_boundary(next_row, next_col, n, m):
                continue

            if not is_essential and must_be_essential:
                continue

            if is_essential:
                result += direction
                essentials.remove(direction)
            else:
                result += direction
                essentials.append(opposites[direction])

            row, col = next_row, next_col
            break

    return "impossible" if len(essentials) > 0 else result


MAX_POWER = 51


def to_binary_string(number: int):
    result = "{0:b}".format(number)

    for i in range(1, MAX_POWER):
        difference = pow(2, i) - 1 - len(result)

        if difference >= 0:
            result = "0" * difference + result
            break

    return result


def is_binary_tree(binary: str, parent: Optional[str]):
    if parent == "0":
        return "1" not in binary

    if len(binary) == 1:
        return True

    middle = int((len(binary) - 1) / 2)
    left, right = binary[:middle], binary[middle + 1 :]
    left_result = is_binary_tree(left, binary[middle])
    right_result = is_binary_tree(right, binary[middle])

    return left_result and right_result


def expressible_binary_tree(numbers: List[int]):
    result = []

    for number in numbers:
        binary = to_binary_string(number)
        result.append(is_binary_tree(binary, None))

    return result


def getWays(n: int, c: List[int]):
    m = len(c)
    ways = [[0] * (m + 1) for _ in range(n + 1)]
    c.sort()

    for j in range(m + 1):
        ways[0][j] = 1

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if i >= c[m - j]:
                ways[i][j] = ways[i - c[m - j]][j] + ways[i][j - 1]

    return ways[n][m]


def unboundedKnapsack(k: int, arr: List[int]):
    arr.sort()

    m = len(arr)

    maximals = [[0] * (m + 1) for _ in range(k + 1)]

    for i in range(1, k + 1):
        for j in range(1, m + 1):
            if i >= arr[m - j]:
                maximals[i][j] = max(maximals[i - arr[m - j]][j] + arr[m - j], maximals[i][j - 1])

    return maximals[k][m]


def get_no_incentives(scores: List[int]):
    no_incentives, supremum, y_max = set(), {}, {}
    x_coords = sorted([score[0] for score in scores])
    current = x_coords[0]

    for x in x_coords:
        if current < x and x in supremum:
            supremum[current] = min(x, supremum[x])
            current = x
        elif current < x and x not in supremum:
            supremum[current] = x
            current = x

    for score in scores:
        if score[0] not in y_max:
            y_max[score[0]] = score[1]
        else:
            y_max[score[0]] = max(y_max[score[0]], score[1])

    for idx, score in enumerate(scores):
        x, y = score[0], score[1]

        while x in supremum:
            if y < y_max[supremum[x]]:
                no_incentives.add(idx)

            x = supremum[x]

    return no_incentives


def get_rank(scores: List[int]):
    answer, score_sums = 1, []
    no_incentives = get_no_incentives(scores)

    if 0 in no_incentives:
        return -1

    for idx, score in enumerate(scores):
        if idx in no_incentives:
            score_sums.append(-1)
        else:
            score_sums.append(score[0] + score[1])

    first_sum = score_sums[0]

    for idx, score_sum in enumerate(score_sums):
        if score_sum > first_sum:
            answer += 1

    return answer


def find_sub_sequences(sequence: List[int], k: int):
    result, start, end, last_added, total = [], 0, 0, -1, 0

    while end < len(sequence) and start <= end:
        if last_added < end:
            total += sequence[end]
            last_added = end

        if total < k:
            end += 1
        elif total == k:
            result.append([sequence[start : end + 1], [start, end]])
            total -= sequence[start]
            start += 1
        else:
            total -= sequence[start]
            start += 1

        if start > end:
            end = start

    return result


def sum_of_sub_sequence(sequence: List[int], k: int):
    info = find_sub_sequences(sequence, k)
    info.sort(key=lambda s: [len(s[0]), s[0][0]])

    return info[0][1]


PRICE = 100
RATE = 0.1


def sell_toothbrush(enrolls: List[str], referrals: List[str], sellers: List[str], amounts: List[int]):
    parents = dict(zip(enrolls, referrals))
    profits = {enroll: 0 for enroll in enrolls}

    for seller, amount in zip(sellers, amounts):
        member, earned = seller, amount * PRICE
        distributed = int(floor(earned * RATE))
        profits[member] += earned - distributed
        member, earned = parents[member], distributed

        while member in parents:
            distributed = int(floor(earned * RATE))
            profits[member] += earned - distributed
            member, earned = parents[member], distributed

    return list(profits.values())


INF = 100001


def create_table():
    table = [[i for i in range(1, 21)], []]
    nxt = set()

    for i in range(1, 21):
        for j in range(2, 4):
            if i * j > 20:
                nxt.add(i * j)

    table[0].append(50)
    table[1] = list(nxt)
    return table


def count_down(target: int):
    table = create_table()
    dp = [[INF, 0] for _ in range(target + 1)]
    dp[0][0] = 0

    for i in range(1, target + 1):
        for j in range(2):
            for k in range(len(table)):
                ret = i - table[j][k]

                if ret < 0:
                    continue

                total, valid = dp[ret][0] + 1, dp[ret][1] + 1 - j

                if total < dp[i][0]:
                    dp[i] = [total, valid]
                elif total == dp[i][0]:
                    dp[i] = [dp[i][0], max(valid, dp[i][1])]

    return dp[target]


def findAnagrams(s: str, l: int):
    substr = s[:l]
    frequencies = {"".join(sorted(substr)): 1}

    for i in range(1, len(s) - l + 1):
        substr = substr[1 : len(substr)] + s[i + l - 1]
        substr_sorted = "".join(sorted(substr))

        if substr_sorted in frequencies:
            frequencies[substr_sorted] += 1
        else:
            frequencies[substr_sorted] = 1

    return sum(int((value - 1) * value / 2) for value in frequencies.values())


def sherlockAndAnagrams(s: str):
    return sum(findAnagrams(s, l) for l in range(1, len(s) + 1))


tired = [[1, 1, 1], [5, 1, 1], [25, 5, 1]]
match = {"diamond": 0, "iron": 1, "stone": 2}


def mining(picks: List[int], minerals: List[str]):
    result = 0
    picks_count = sum(pick for pick in picks)
    minerals = [match[mineral] for mineral in minerals[: picks_count * 5]]
    chunks = [minerals[i * 5 : i * 5 + 5] for i in range(len(minerals) // 5 + 1)]
    chunks.sort(key=lambda s: [s.count(0), s.count(1), s.count(2)], reverse=True)

    chunk_idx = 0
    for idx, pick in enumerate(picks):
        while pick > 0 and chunk_idx < len(chunks):
            for mineral in chunks[chunk_idx]:
                result += tired[idx][mineral]

            pick -= 1
            chunk_idx += 1

    return result


# pylint: disable=C0200
def rotate(destination: int, target: int, nums: List[int]):
    result = False

    for idx in range(len(nums)):
        if target != nums[idx]:
            continue

        if idx == destination:
            result = idx
            break

        if idx >= 2 and nums[idx] < nums[idx - 1] and nums[idx] < nums[idx - 2]:
            nums[idx - 2], nums[idx] = nums[idx], nums[idx - 2]
            nums[idx - 1], nums[idx] = nums[idx], nums[idx - 1]
            result = idx - 2
            break

        if idx >= 1 and nums[idx] < nums[idx - 1] and nums[idx] < nums[idx + 1]:
            nums[idx - 1], nums[idx] = nums[idx], nums[idx - 1]
            nums[idx], nums[idx + 1] = nums[idx + 1], nums[idx]
            result = idx - 1
            break

    return result


def larrysArray(nums: List[int]):
    nums_sorted = sorted(nums)

    for idx, num in enumerate(nums_sorted[:-2]):
        result = sys.maxsize

        while result > idx:
            result = rotate(idx, num, nums)

    return nums[-2] <= nums[-1]


nums0 = [1, 6, 5, 2, 4, 3]
result0 = larrysArray(nums0)

nums1 = [9, 6, 8, 12, 3, 7, 1, 11, 10, 2, 5, 4]
result1 = larrysArray(nums1)


picks0 = [1, 3, 2]
minerals0 = ["diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"]


nums = [1, 2, 3, 4, 5]
test = nums[:-2]

for idx, num in enumerate(nums[:-2]):
    print(idx, num)

picks1 = [0, 1, 1]
minerals1 = [
    "diamond",
    "diamond",
    "diamond",
    "diamond",
    "diamond",
    "iron",
    "iron",
    "iron",
    "iron",
    "iron",
    "diamond",
]

result0 = mining(picks0, minerals0)
result1 = mining(picks1, minerals1)


# result0 = sherlockAndAnagrams("abba")
# result1 = sherlockAndAnagrams("abcd")
# result2 = sherlockAndAnagrams("ifailuhkqq")
# result3 = sherlockAndAnagrams("kkkk")

# print(result0)
# print(result1)
# print(result2)
# print(result3)

# dict0 = {"a": 0, "b": 1}
# dict1 = {"a": 0, "b": 1}
# dict2 = {"a": 0, "c": 1}


# counter0 = Counter("ab")
# counter1 = Counter("ba")

# print(counter0 == counter1)

# print(dict0 == dict1)
# print(dict0 == dict2)


# enrolls0 = ["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"]
# referrals0 = ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"]
# sellers0 = ["young", "john", "tod", "emily", "mary"]
# amounts0 = [12, 4, 2, 5, 10]
# result0 = sell_toothbrush(enrolls0, referrals0, sellers0, amounts0)
# answer0 = [360, 958, 108, 0, 450, 18, 180, 1080]

# result0 = count_down(21)
# result1 = count_down(58)

# print(result0)
# print(result1)


# scores0 = [[2, 2], [1, 4], [3, 2], [3, 2], [2, 1]]
# scores1 = [[4, 2], [1, 2], [3, 7], [1, 6], [7, 1]]
# scores2 = [[1, 2], [1, 6], [4, 8], [4, 2], [7, 1]]
# scores2.sort(key=lambda s: (-s[0], s[1]))

# rank1 = get_rank(scores1)

# sequence0, k0 = [1, 2, 3, 4, 5], 7
# sequence1, k1 = [1, 1, 1, 2, 3, 4, 5], 5
# sequence2, k2 = [2, 2, 2, 2, 2], 6


# test = {key: value for key, value in zip(sequence0, sequence1)}
# test = dict(zip(sequence0, sequence1))

# tesult0 = sum_of_sub_sequence(sequence0, k0)
# result1 = sum_of_sub_sequence(sequence1, k1)
# result2 = sum_of_sub_sequence(sequence2, k2)

# print(test)


# numbers0 = [7, 42, 5]
# numbers1 = [63, 111, 95]

# result0 = expressible_binary_tree(numbers0)
# result1 = expressible_binary_tree(numbers1)

# test = ord("a")
# test = ord("b")
# print(test)

# n0, m0, x0, y0, r0, c0, k0 = 3, 4, 2, 3, 3, 1, 5
# result0 = escape_maze(n0, m0, x0, y0, r0, c0, k0)

# print(result0)
