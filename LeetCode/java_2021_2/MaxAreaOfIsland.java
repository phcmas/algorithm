/* 695. Max Area of Island */
/** Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's 
 *  (representing land) connected 4-directionally (horizontal or vertical.) 
 *  You may assume all four edges of the grid are surrounded by water.
 *  Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 * 
 *  Example 1:
 *  [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 *   [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *   [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *   [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *   [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *   [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *   [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *   [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *  Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
 *  
 *  Example 2:
 *  [[0,0,0,0,0,0,0,0]]
 *  Given the above grid, return 0.
 *  Note: The length of each dimension in the given grid does not exceed 50. */

package leet_code.java_2021_2;

public class MaxAreaOfIsland {
    int[] dr = {-1, 0, 1, 0}; // up, right, down, left
    int[] dc = {0, 1, 0, -1};
    boolean[][] visited;

    private int dfs(int[][] grid, int row, int col) {
        int count = 1;
        visited[row][col] = true;        

        for (int i = 0; i < 4; ++i) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];

            if (nextRow < 0 || nextRow > grid.length-1 || nextCol < 0 || nextCol > grid[0].length-1) continue;

            if (grid[nextRow][nextCol] == 1 && !visited[nextRow][nextCol]) {
                count += dfs(grid, nextRow, nextCol);
            }
        }

        return count;
    }

    public int maxAreaOfIsland(int[][] grid) {
        int answer = 0;
        if (grid.length == 0) return 0;
        visited = new boolean[grid.length][grid[0].length];

        for (int r = 0; r < grid.length; ++r) {
            for (int c = 0; c < grid[0].length; ++c) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    answer = Math.max(answer, dfs(grid, r, c));
                }
            }
        }

        return answer;
    }
}
