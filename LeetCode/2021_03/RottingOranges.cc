/* 994. Rotting Oranges */
/** You are given an m x n grid where each cell can have one of three values:
 * 
 *  0 representing an empty cell,
 *  1 representing a fresh orange, or
 *  2 representing a rotten orange.
 *  Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
 *  Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 * 
 *  Example 1:
 *  Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 *  Output: 4
 * 
 *  Example 2:
 *  Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 *  Output: -1
 *  Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
 * 
 *  Example 3:
 *  Input: grid = [[0,2]]
 *  Output: 0
 *  Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 * 
 *  Constraints:
 *  m == grid.length
 *  n == grid[i].length
 *  1 <= m, n <= 10
 *  grid[i][j] is 0, 1, or 2. **/

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    queue<int> queue;
    int rottenCount = 0;
    

}

int main() {
    vector<int> row00 {2,1,1};
    vector<int> row01 {1,1,0};
    vector<int> row02 {0,1,1};
    vector<vector<int>> grid0 {row00, row01, row02};

    vector<int> row10 {2,1,1};
    vector<int> row11 {0,1,1};
    vector<int> row12 {1,0,1};
    vector<vector<int>> grid1 {row10, row11, row12};

    vector<int> row20 {0,2};
    vector<vector<int>> grid2 {row20};

    int ans0 = orangesRotting(grid0);
    int ans1 = orangesRotting(grid1);
    int ans2 = orangesRotting(grid2);

    cout << ans0 << endl; // 4
    cout << ans1 << endl; // -1
    cout << ans2 << endl; // 0

    return 0;
}
