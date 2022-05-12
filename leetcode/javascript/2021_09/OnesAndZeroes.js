/* 474. Ones and Zeroes */
/** You are given an array of binary strings strs and two integers m and n.
 *  Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
 *  A set x is a subset of a set y if all elements of x are also elements of y
 * 
 *  Example 1:
 *  Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
 *  Output: 4
 *  Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
 *  Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
 *  {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
 * 
 *  Example 2:
 *  Input: strs = ["10","0","1"], m = 1, n = 1
 *  Output: 2
 *  Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 * 
 *  Constraints:
 *  1 <= strs.length <= 600
 *  1 <= strs[i].length <= 100
 *  strs[i] consists only of digits '0' and '1'.
 *  1 <= m, n <= 100 **/

const getCounts = (str) => {
    let count = 0;

    [...str].forEach((char) => {
        if (char === '0') count++;
    });

    return [count, str.length-count];
};

var findMaxForm = function(strs, m, n) {
    const s = strs.length;
    const cache = new Array(s+1).fill(
        new Array(m+1).fill(
            new Array(n+1).fill(0)
        )
    );

    for (let i = s-1; i >= 0; --i) {
        const counts = getCounts(strs[i]);

        for (let j = 0; j <= m; ++j) {
            for (let k = 0; k <= n; ++k) {
                if (counts[0] > j || counts[1] > k) {
                    cache[i][j][k] = 0;
                } else {
                    cache[i][j][k] = Math.max(1 + cache[i+1][j-counts[0]][k-counts[1]], cache[i+1][j][k]);
                } 
            }
    }
    }

    return cache[0][m][n];
};

var strs1 = ["10","0","1"];
var ans1 = findMaxForm(strs1, 1, 1);

var strs0 = ["10","0001","111001","1","0"];
var ans0 = findMaxForm(strs0, 5, 3);

console.log(ans0); // 4
console.log(ans1); // 2


