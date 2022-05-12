/** 1338. Reduce Array Size to The Half */
/** You are given an integer array arr. You can choose a set of integers and 
 *  remove all the occurrences of these integers in the array.
 * 
 *  Return the minimum size of the set so that at least half of the integers of the array are removed.
 * 
 *  Example 1:
 *  Input: arr = [3,3,3,3,5,5,5,2,2,7]
 *  Output: 2
 *  Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
 *  Possible sets of size 2 are {3,5},{3,2},{5,2}.
 *  Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.
 * 
 *  Example 2:
 *  Input: arr = [7,7,7,7,7,7]
 *  Output: 1
 *  Explanation: The only possible set you can choose is {7}. This will make the new array empty.
 * 
 *  Example 3:
 *  Input: arr = [1,9]
 *  Output: 1
 * 
 *  Example 4:
 *  Input: arr = [1000,1000,3,7]
 *  Output: 1
 * 
 *  Example 5:
 *  Input: arr = [1,2,3,4,5,6,7,8,9,10]
 *  Output: 5
 * 
 *  Constraints:
 *  1 <= arr.length <= 10^5
 *  arr.length is even.
 *  1 <= arr[i] <= 10^5 */

var minSetSize = function(arr) {
    let numToFreq = new Map();
    let length = arr.length;
    let sum = 0;
    let answer = 0;

    arr.forEach((num) => {
        if (numToFreq.has(num)) {
            numToFreq.set(num, numToFreq.get(num)+1);
        } else {
            numToFreq.set(num, 1);
        }
    });

    const sortedArr = [...numToFreq].sort((a,b) => b[1]-a[1]);

    for (let value of sortedArr) {
        if (sum >= length/2) return answer;
        sum += value[1];
        answer++;
    }

    return answer;
};


let arr0 = [3,3,3,3,5,5,5,2,2,7];
let arr1 = [7,7,7,7,7,7];
let arr2 = [1,9];
let arr3 = [1000,1000,3,7];
let arr4 = [1,2,3,4,5,6,7,8,9,10];

let ans0 = minSetSize(arr0);
let ans1 = minSetSize(arr1);
let ans2 = minSetSize(arr2);
let ans3 = minSetSize(arr3);
let ans4 = minSetSize(arr4);

console.log(ans0); // 2
console.log(ans1); // 1
console.log(ans2); // 1
console.log(ans3); // 1
console.log(ans4); // 5
