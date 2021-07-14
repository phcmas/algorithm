/** 697. Degree of an Array */
/** Given a non-empty array of non-negative integers nums, the degree of this array 
 *  is defined as the maximum frequency of any one of its elements.
 * 
 *  Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
 * 
 *  Example 1:
 *  Input: nums = [1,2,2,3,1]
 *  Output: 2
 *  Explanation: 
 *  The input array has a degree of 2 because both elements 1 and 2 appear twice.
 *  Of the subarrays that have the same degree:
 *  [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 *  The shortest length is 2. So return 2.
 * 
 *  Example 2:
 *  Input: nums = [1,2,2,3,1,4,2]
 *  Output: 6
 *  Explanation: 
 *  The degree is 3 because the element 2 is repeated 3 times.
 *  So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 * 
 *  Constraints:
 *  nums.length will be between 1 and 50,000.
 *  nums[i] will be an integer between 0 and 49,999. */

// 처음에 내가 구현한 풀이. 더 좋은 풀이는 2에서 구현함

var getDegree = function(nums, mostAppeared) {
    let numToCount = new Map();
    let max = 0;

    for (let i = 0; i < nums.length; ++i) {
        if (numToCount.has(nums[i])) {
            numToCount.set(nums[i], numToCount.get(nums[i])+1);
        } else {
            numToCount.set(nums[i], 1);
        }

        max = Math.max(max, numToCount.get(nums[i]));
    }

    for (let [key, value] of numToCount) {
        if (value == max) mostAppeared.push(key);
    }
}

var findShortestSubArray = function(nums) {
    let mostAppeared = [];
    let answer = 50000;

    getDegree(nums, mostAppeared);

    for (let num of mostAppeared) {
        let end = -1;
        let start = -1;

        for (let i = nums.length-1; i >= 0; --i) {
            if (nums[i] == num && end == -1) {
                end = i;
                start = i;
            } else if (nums[i] == num) {
                start = i;
            }
        }

        answer = Math.min(answer, end-start+1);
    }

    return answer;
};


var nums0 = [1,2,2,3,1];
var nums1 = [1,2,2,3,1,4,2];
var nums2 = [1];

var ans0 = findShortestSubArray(nums0);
var ans1 = findShortestSubArray(nums1);
var ans2 = findShortestSubArray(nums2);

console.log(ans0); // 2
console.log(ans1); // 6 
console.log(ans2); // 1



