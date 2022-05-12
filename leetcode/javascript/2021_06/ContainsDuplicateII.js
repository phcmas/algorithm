/** 219. Contains Duplicate II */
/** Given an integer array nums and an integer k, return true if there are two distinct indices 
 *  i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3,1], k = 3
 *  Output: true
 * 
 *  Example 2:
 *  Input: nums = [1,0,1,1], k = 1
 *  Output: true
 * 
 *  Example 3:
 *  Input: nums = [1,2,3,1,2,3], k = 2
 *  Output: false
 * 
 *  Constraints:
 *  1 <= nums.length <= 10^5
 *  -10^9 <= nums[i] <= 10^9
 *  0 <= k <= 10^5 */

var containsNearbyDuplicate = function(nums, k) {
    var start = 0;
    var end = 1;
    var appeared = new Set();
    
    if (nums.length == 1 || k == 0) return false;
    
    appeared.add(nums[start]);
    
    while (end < nums.length) {
        if (appeared.has(nums[end])) return true;
        
        if (end-start == k) {
            appeared.delete(nums[start]);
            start++;
        } else {
            appeared.add(nums[end]);
            end++;
        }
    }
    
    return false;
};

var containsNearbyDuplicate2 = function(nums, k) {
    var ind = {};

    for (var i = 0; i < nums.length; ++i) {
        if (nums[i] in ind && i - ind[nums[i]] <= k) return true;
        ind[nums[i]] = i;
    }

    return false;
};


var nums0 = [1,2,3,1];
var k0 = 3;

var nums1 = [1,0,1,1];
var k1 = 1;

var nums2 = [1,2,3,1,2,3];
var k2 = 2;

var ans0 = containsNearbyDuplicate2(nums0, k0);
var ans1 = containsNearbyDuplicate2(nums1, k1);
var ans2 = containsNearbyDuplicate2(nums2, k2);

console.log(ans0); // true
console.log(ans1); // true
console.log(ans2); // false

