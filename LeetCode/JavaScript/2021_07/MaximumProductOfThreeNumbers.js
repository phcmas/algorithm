/** 628. Maximum Product of Three Numbers */
/** Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3]
 *  Output: 6
 * 
 *  Example 2:
 *  Input: nums = [1,2,3,4]
 *  Output: 24
 * 
 *  Example 3:
 *  Input: nums = [-1,-2,-3]
 *  Output: -6
 * 
 *  Constraints:
 *  3 <= nums.length <= 10^4
 *  -1000 <= nums[i] <= 1000 */

var maximumProduct = function(nums) {
    var sorted = nums.sort((a,b) => a-b);
    var last = nums.length-1;
    
    var cand1 = sorted[last] * sorted[last-1] * sorted[last-2];
    var cand2 = sorted[0] * sorted[1] * sorted[last];
    
    return Math.max(cand1, cand2);
};

var nums0 = [1,2,3];
var ans0 = maximumProduct(nums0);

var nums1 = [-4,-3,-2,0,1,5];
var ans1 = maximumProduct(nums1);


console.log(ans0);
console.log(ans1);
