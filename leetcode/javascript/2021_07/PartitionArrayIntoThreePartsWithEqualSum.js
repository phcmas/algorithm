/** 1013. Partition Array Into Three Parts With Equal Sum */
/** Given an array of integers arr, return true if we can partition the array into three non-empty parts with equal sums.
 *  Formally, we can partition the array if we can find indexes i + 1 < j with 
 *  (arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1])
 * 
 *  Example 1:
 *  Input: arr = [0,2,1,-6,6,-7,9,1,2,0,1]
 *  Output: true
 *  Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
 * 
 *  Example 2:
 *  Input: arr = [0,2,1,-6,6,7,9,-1,2,0,1]
 *  Output: false
 * 
 *  Example 3:
 *  Input: arr = [3,3,6,5,-2,2,5,1,-9,4]
 *  Output: true
 *  Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 * 
 *  Constraints:
 *  3 <= arr.length <= 5 * 10^4
 *  -10^4 <= arr[i] <= 10^4 */


var canThreePartsEqualSum = function(arr) {
    let total = 0;
    let partition = 0;
    let firstExist = false;
    let sum = 0;
    
    for (let i = 0; i < arr.length; ++i) {
        total += arr[i];
    }
    
    if (total % 3 != 0) return false;
    partition = total / 3;
    
    for (let i = 0; i < arr.length; ++i) {
        sum += arr[i];
        
        if (sum == partition * 2 && firstExist && i < arr.length-1) {
            return true;
        } else if (sum == partition) {
            firstExist = true;
        }
    }
    
    return false;
};


var arr0 = [0,2,1,-6,6,-7,9,1,2,0,1];
var arr1 = [0,2,1,-6,6,7,9,-1,2,0,1];
var arr2 = [3,3,6,5,-2,2,5,1,-9,4];

var ans0 = canThreePartsEqualSum(arr0);
var ans1 = canThreePartsEqualSum(arr1);
var ans2 = canThreePartsEqualSum(arr2);

console.log(ans0); // true
console.log(ans1); // false
console.log(ans2); // true
