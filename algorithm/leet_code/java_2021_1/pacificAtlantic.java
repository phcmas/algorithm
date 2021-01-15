/* 417. Pacific Atlantic Water Flow */
/** Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, 
 *  the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
 *  Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
 *  Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
 * 
 *  Note:
 *  The order of returned grid coordinates does not matter.
 *  Both m and n are less than 150 
 *  
 *  Example:
 *  Given the following 5x5 matrix:
 *  Pacific ~   ~   ~   ~   ~ 
         ~  1   2   2   3  (5) *
         ~  3   2   3  (4) (4) *
         ~  2   4  (5)  3   1  *
         ~ (6) (7)  1   4   5  *
         ~ (5)  1   1   2   4  *
            *   *   *   *   * Atlantic
 *  Return:
 *  [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix) **/

package leet_code.java_2021_1;
import java.util.List;
import java.util.ArrayList;

public class pacificAtlantic {
    int[] dr = {0, 1, 0, -1}; // right, down, left, up
    int[] dc = {1, 0, -1, 0};
    int[][] ground;

    public boolean isOutOfBoudary(int row, int col) {
        return row < 0 || col < 0 || row >= ground.length || col >= ground[0].length;
    }

    public void dfs(boolean[][] visited, int row, int col) {
        visited[row][col] = true;

        for (int i = 0; i < 4; ++i) {
            int nextRow = row+dr[i];
            int nextCol = col+dc[i];

            if (isOutOfBoudary(nextRow, nextCol) 
               || visited[nextRow][nextCol] || ground[nextRow][nextCol] < ground[row][col])
                continue;
                
            dfs(visited, nextRow, nextCol);
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>> answer = new ArrayList<>();
        boolean[][] pacificVisited;
        boolean[][] atlanticVisited;

        if (matrix.length == 0) return answer;

        ground = matrix;
        pacificVisited = new boolean[matrix.length][matrix[0].length];
        atlanticVisited = new boolean[matrix.length][matrix[0].length];

        for (int col = 0; col < matrix[0].length; ++col) {
            dfs(pacificVisited, 0, col);
        }

        for (int row = 0; row < matrix.length; ++row) {
            dfs(pacificVisited, row, 0);
        }

        for (int col = matrix[0].length - 1; col >= 0; --col) {
            dfs(atlanticVisited, matrix.length - 1, col);
        }

        for (int row = matrix.length - 1; row >= 0; --row) {
            dfs(atlanticVisited, row, matrix[0].length - 1);
        }

        for (int i = 0; i < matrix.length; ++i) {
            for (int j = 0; j < matrix[0].length; ++j) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    List<Integer> coord = new ArrayList<>();
                    coord.add(i);
                    coord.add(j);
                    answer.add(coord);
                }
            }
        }

        return answer;
    }
}


