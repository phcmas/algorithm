/** 118. Pascal's Triangle */
/** Given an integer numRows, return the first numRows of Pascal's triangle.
 *  In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * 
 *  Example 1:
 *  Input: numRows = 5
 *  Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 *  Example 2:
 *  Input: numRows = 1
 *  Output: [[1]]
 * 
 *  Constraints: 1 <= numRows <= 30 */

var generate = function(numRows) {
    var answer = [[1]];
    
    for (var i = 1; i < numRows; ++i) {
        answer[i] = [];
        answer[i][0] = answer[i][i] = 1;
        
        for (var j = 1; j < i; ++j) {
            answer[i][j] = answer[i-1][j-1] + answer[i-1][j];
        }
    }
    
    return answer;
};

var ans0 = generate(5);
var ans1 = generate(1);

for (let i = 0; i < ans0.length; ++i) {
    var str = "";
    for (let j = 0; j < ans0[i].length; ++j) {
        str += ans0[i][j] + " ";
    }

    console.log(str);
}

console.log();

for (let i = 0; i < ans1.length; ++i) {
    var str = "";
    for (let j = 0; j < ans1[i].length; ++j) {
        str += ans1[i][j] + " ";
    }

    console.log(str);
}
