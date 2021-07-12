/** 67. Valid Perfect Square */
/** Given a positive integer num, write a function which returns True if num is a perfect square else False.
 *  Follow up: Do not use any built-in library function such as sqrt.
 * 
 *  Example 1:
 *  Input: num = 16
 *  Output: true
 * 
 *  Example 2:
 *  Input: num = 14
 *  Output: false
 * 
 *  Constraints: 1 <= num <= 2^31 - 1 */

var isPerfectSquare = function(num) {
    var left = 0;
    var right = num;
    
    while (left <= right) {
        var middle = Math.floor(left + (right - left) / 2);
        
        if (middle * middle == num) {
            return true;
        } else if (middle * middle > num) {
            right = middle - 1;
        } else if (middle * middle < num) {
            left = middle + 1;
        }
    }
    
    return false;
};

var ans0 = isPerfectSquare(16);
var ans1 = isPerfectSquare(14);

console.log(ans0); // true
console.log(ans1); // false
