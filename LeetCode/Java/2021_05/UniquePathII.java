/** 63. Unique Paths II */
/** A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *  The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right 
 *  corner of the grid (marked 'Finish' in the diagram below).
 * 
 *  Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *  An obstacle and space is marked as 1 and 0 respectively in the grid.
 * 
 *  Example 1:
 *  Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 *  Output: 2
 *  Explanation: There is one obstacle in the middle of the 3x3 grid above.
 *  There are two ways to reach the bottom-right corner:
 *  1. Right -> Right -> Down -> Down
 *  2. Down -> Down -> Right -> Right
 * 
 *  Example 2:
 *  Input: obstacleGrid = [[0,1],[0,0]]
 *  Output: 1
 * 
 *  Constraints:
 *  m == obstacleGrid.length
 *  n == obstacleGrid[i].length
 *  1 <= m, n <= 100
 *  obstacleGrid[i][j] is 0 or 1. */

public class UniquePathII {
    int[][] cache;

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int rowSize = obstacleGrid.length;
        int colSize = obstacleGrid[0].length;

        cache = new int[rowSize+1][colSize+1];
        cache[rowSize][colSize-1] = 1;

        for (int r = rowSize-1; r >= 0; --r) {
            for (int c = colSize-1; c >= 0; --c) {
                if (obstacleGrid[r][c] == 1){
                    cache[r][c] = 0;
                } else {
                    cache[r][c] = cache[r+1][c] + cache[r][c+1];
                }   
            }
        }

        return cache[0][0];
    }
}