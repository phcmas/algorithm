/** 463. Island Perimeter */
/** You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
 *  Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, 
 *  and there is exactly one island (i.e., one or more connected land cells).
 *  
 *  The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. 
 *  One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
 *  Determine the perimeter of the island.
 * 
 *  Example 1:
 *  Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 *  Output: 16
 *  Explanation: The perimeter is the 16 yellow stripes in the image above.
 * 
 *  Example 2:
 *  Input: grid = [[1]]
 *  Output: 4
 * 
 *  Example 3:
 *  Input: grid = [[1,0]]
 *  Output: 4
 * 
 *  Constraints:
 *  row == grid.length
 *  col == grid[i].length
 *  1 <= row, col <= 100
 *  grid[i][j] is 0 or 1. */

/**
 * @param {number[][]} grid
 * @return {number}
 */

// up, right, down, left
var dr = [-1, 0, 1, 0];
var dc = [0, 1, 0, -1];

var init = function(visited) {
    for (let r = 0; r < visited.length; ++r) {
        for (let c= 0; c < visited[0].length; ++c) {
            visited[r][c] = false;
        }
    }
}

var dfs = function(visited, grid, row, col, count) {
    visited[row][col] = true;
    count[0]++;
    
    for (let i = 0; i < 4; ++i) {
        let nextRow = row + dr[i];
        let nextCol = col + dc[i];
        
        if (nextRow < 0 || nextRow >= grid.length || nextCol < 0 || nextCol >= grid[0].length) continue;
        if (grid[nextRow][nextCol] == 1) count[1]++;
        if (visited[nextRow][nextCol] || grid[nextRow][nextCol] == 0) continue;
        
        dfs(visited, grid, nextRow, nextCol, count);
    }
    
}

var islandPerimeter = function(grid) {
    var answer = 0;
    var visited = Array.from(Array(grid.length), () => new Array(grid[0].length));
    
    init(visited);
    
    for (let r = 0; r < grid.length; ++r) {
        for (let c = 0; c < grid[0].length; ++c) {
            if (grid[r][c] == 1 && !visited[r][c]) {
                var count = [0, 0];
                dfs(visited, grid, r, c, count);
                answer = Math.max(answer, 4 * count[0] - count[1]);
            }
        }
    }
    
    return answer;
};

var dfs2 = function(grid, row, col) {
    var count = 0;
    grid[row][col] = -1;

    for (let i = 0; i < 4; ++i) {
        let nextRow = row + dr[i];
        let nextCol = col + dc[i];
            
        if (nextRow < 0 || nextRow >= grid.length || nextCol < 0 || nextCol >= grid[0].length || grid[nextRow][nextCol] == 0) {
            count++;
            continue;
        }
            
        if (grid[nextRow][nextCol] == -1) continue;
        count += dfs2(grid, nextRow, nextCol);
    }

    return count;
};

var islandPerimeter2 = function(grid) {
    for (let r = 0; r < grid.length; ++r) {
        for (let c = 0; c < grid[0].length; ++c) {
            if (grid[r][c] == 1) return dfs2(grid, r, c);
        }
    }

    return 0;
};


var grid0 = [[0,1,0,0], [1,1,1,0], [0,1,0,0], [1,1,0,0]];
var grid1 = [[1]];
var grid2 = [[1,0]];
var grid3 = [[1,1],[1,1]];

var ans0 = islandPerimeter2(grid0);
var ans1 = islandPerimeter2(grid1);
var ans2 = islandPerimeter2(grid2);
var ans3 = islandPerimeter2(grid3);

console.log(ans0); // 16
console.log(ans1); // 4
console.log(ans2); // 4
console.log(ans3); // 8

