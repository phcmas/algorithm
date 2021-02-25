/* 200 Number of Islands */
/** Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.
 *  An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 *  You may assume all four edges of the grid are all surrounded by water.
 * 
 *  Example 1:
 *  Input: grid = [
 *  ["1","1","1","1","0"],
 *  ["1","1","0","1","0"],
 *  ["1","1","0","0","0"],
 *  ["0","0","0","0","0"]]
 *  Output: 1
 * 
 *  Example 2:
 *  Input: grid = [
 *  ["1","1","0","0","0"],
 *  ["1","1","0","0","0"],
 *  ["0","0","1","0","0"],
 *  ["0","0","0","1","1"]]
 *  Output: 3
 * 
 *  Constraints:
 *  m == grid.length
 *  n == grid[i].length
 *  1 <= m, n <= 300
 *  grid[i][j] is '0' or '1'. **/


public class NumberOfIslands {
    boolean[][] visited;
    int dr[] = {-1, 0, 1, 0}; // up, right, down, left
    int dc[] = {0, 1, 0, -1};

    private int dfs(char[][] grid, int row, int col) {
        if (visited[row][col] || grid[row][col] == '0') return 0;
        visited[row][col] = true;

        for (int i = 0; i < 4; ++i) {
            int next_row = row + dr[i];
            int next_col = col + dc[i];

            if (next_row < 0 || next_row > grid.length-1 || next_col < 0 || next_col > grid[0].length-1) continue;
            if (visited[next_row][next_col] || grid[next_row][next_col] == '0') continue;
            dfs(grid, next_row, next_col);
        }

        return 1;
    }

    public int numIslands(char[][] grid) {
        int answer = 0;
        int rowCount = grid.length;
        int colCount = grid[0].length;

        visited = new boolean[rowCount][colCount];

        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j) {
                answer += dfs(grid, i, j);
            }
        }

        return answer;
    }
}