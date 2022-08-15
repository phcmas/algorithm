/** 2352. Equal Row and Column Pairs */
/** Given a 0-indexed n x n integer matrix grid, return the number of pairs (Ri, Cj)
 *  such that row Ri and column Cj are equal.
 *  A row and column pair is considered equal if they contain the same elements in the same order
 *  (i.e. an equal array).
 *
 *  Example 1:
 *  Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
 *  Output: 1
 *  Explanation: There is 1 equal row and column pair:
 *  - (Row 2, Column 1): [2,7,7]
 *
 *  Example 2:
 *  Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
 *  Output: 3
 *  Explanation: There are 3 equal row and column pairs:
 *  - (Row 0, Column 0): [3,1,2,2]
 *  - (Row 2, Column 2): [2,4,2,2]
 *  - (Row 3, Column 2): [2,4,2,2]
 *
 *  Constraints:
 *  n == grid.length == grid[i].length
 *  1 <= n <= 200
 *  1 <= grid[i][j] <= 10^5 */

function getHash(arr: number[]) {
  return arr.join(",");
}

function getColumn(grid: number[][], index: number) {
  return grid.map((row) => row[index]);
}

function equalPairs(grid: number[][]): number {
  const rowCounts: Record<string, number> = {};
  let equalCount = 0;

  for (const row of grid) {
    const hash = getHash(row);
    rowCounts[hash] = (rowCounts[hash] || 0) + 1;
  }

  for (let index = 0; index < grid.length; ++index) {
    const column = getColumn(grid, index);
    const hash = getHash(column);

    if (rowCounts[hash]) equalCount += rowCounts[hash];
  }

  return equalCount;
}

export { equalPairs };
