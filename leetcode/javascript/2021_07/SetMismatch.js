/** 645. Set Mismatch */
/** You have a set of integers s, which originally contains all the numbers from 1 to n. 
 *  Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
 *  which results in repetition of one number and loss of another number.
 * 
 *  You are given an integer array nums representing the data status of this set after the error.
 *  Find the number that occurs twice and the number that is missing and return them in the form of an array.
 * 
 *  Example 1:
 *  Input: nums = [1,2,2,4]
 *  Output: [2,3]
 * 
 *  Example 2:
 *  Input: nums = [1,1]
 *  Output: [1,2]
 * 
 *  Constraints:
 *  2 <= nums.length <= 10^4
 *  1 <= nums[i] <= 10^4 */

 var findErrorNums = function(nums) {
    var answer = [];
    var next = 1;
    var duplicated;
    var loss;
    
    nums.sort((a,b) => a-b);
    for (let i = 0; i < nums.length; ++i) {
        if (next != nums[i]) {
            loss = next;
            next = nums[i];
        }
        
        if (i < nums.length-1 && nums[i] == nums[i+1]) {
            duplicated = nums[i];
        } else {
            next++;
        }
    }
    
    if (next <= nums.length) loss = nums.length;
    
    answer.push(duplicated);
    answer.push(loss);
    return answer;
    
};


var nums0 = [37,62,43,27,12,66,36,18,39,54,61,65,47,32,23,2,46,8,4,24,29,38,63,39,25,11,45,28,44,52,15,30,21,7,57,49,1,59,58,14,9,40,3,42,56,31,20,41,22,50,13,33,6,10,16,64,53,51,19,17,48,26,34,60,35,5];
var ans0 = findErrorNums(nums0);

console.log(ans0);
