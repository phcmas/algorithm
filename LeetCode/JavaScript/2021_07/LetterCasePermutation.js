/** 784. Letter Case Permutation */
/** Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.
 *  Return a list of all possible strings we could create. You can return the output in any order.
 * 
 *  Example 1:
 *  Input: s = "a1b2"
 *  Output: ["a1b2","a1B2","A1b2","A1B2"]
 * 
 *  Example 2:
 *  Input: s = "3z4"
 *  Output: ["3z4","3Z4"]
 * 
 *  Example 3:
 *  Input: s = "12345"
 *  Output: ["12345"]
 * 
 *  Example 4: 
 *  Input: s = "0" 
 *  Output: ["0"]
 * 
 *  Constraints:
 *  s will be a string with length between 1 and 12.
 *  s will consist only of letters or digits. */

var backTracking = function(s, index, permutaion) {
    if (index == s.length) {
        permutaion.push(s);
        return;
    }

    var word = s[index];
    var str = "";

    if (word.charCodeAt(0) >= 97 && word.charCodeAt(0) <= 122) {
        str = s.slice(0, index) + word.toUpperCase() + s.slice(index+1);
        backTracking(str, index+1, permutaion);
    } else if (word.charCodeAt(0) >= 65 && word.charCodeAt(0) <= 90) {
        str = s.slice(0, index) + word.toLowerCase() + s.slice(index+1);
        backTracking(str, index+1, permutaion);
    }

    backTracking(s, index+1, permutaion);
};

var letterCasePermutation = function(s) {
    var permutaion = [];
    backTracking(s, 0, permutaion);

    return permutaion;
};

var s0 = "a1b2";
var s1 = "3z3";
var s2 = "12345";
var s3 = "0";
var s4 = "c";

var ans0 = letterCasePermutation(s0);
var ans1 = letterCasePermutation(s1);
var ans2 = letterCasePermutation(s2);
var ans3 = letterCasePermutation(s3);
var ans4 = letterCasePermutation(s4);

console.log(ans0); // ["a1b2","a1B2","A1b2","A1B2"]
console.log(ans1); // ["3z4","3Z4"]
console.log(ans2); // ["12345"]
console.log(ans3); // ["0"]
console.log(ans4); // ["0"]

