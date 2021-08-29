/** 1351. Count Negative Numbers in a Sorted Matrix **/
/** Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise,
 *  return the number of negative numbers in grid.
 * 
 *  Example 1:
 *  Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
 *  Output: 8
 *  Explanation: There are 8 negatives number in the matrix.
 * 
 *  Example 2:
 *  Input: grid = [[3,2],[1,0]]
 *  Output: 0
 * 
 *  Example 3:
 *  Input: grid = [[1,-1],[-1,-1]]
 *  Output: 3
 * 
 *  Example 4:
 *  Input: grid = [[-1]]
 *  Output: 1
 * 
 *  Constraints:
 *  m == grid.length
 *  n == grid[i].length
 *  1 <= m, n <= 100
 *  -100 <= grid[i][j] <= 100
 *   
 *  Follow up: Could you find an O(n + m) solution? **/

var minusCount = function(row) {
    let left = 0;
    let right = row.length-1;
    let middle;

    while (left <= right) {
        middle = Math.floor(left + (right - left) / 2);

        if (row[middle] >= 0) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return row.length - left;
};

var countNegatives = function(grid) {
    let answer = 0;

    grid.forEach((row) => {
        answer += minusCount(row);
    });

    return answer;
};

let grid0 = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]];
let grid1 = [[3,2],[1,0]];
let grid2 = [[1,-1],[-1,-1]];
let grid3 = [[-1]];

let ans0 = countNegatives(grid0);
let ans1 = countNegatives(grid1);
let ans2 = countNegatives(grid2);
let ans3 = countNegatives(grid3);

console.log(ans0); // 8
console.log(ans1); // 0 
console.log(ans2); // 3 
console.log(ans3); // 1

