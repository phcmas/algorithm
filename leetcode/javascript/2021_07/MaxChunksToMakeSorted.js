/** 769. Max Chunks To Make Sorted */
/** You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
 *  We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. 
 *  After concatenating them, the result should equal the sorted array.
 * 
 *  Return the largest number of chunks we can make to sort the array.
 * 
 *  Example 1:
 *  Input: arr = [4,3,2,1,0]
 *  Output: 1
 *  Explanation:
 *  Splitting into two or more chunks will not return the required result.
 *  For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
 * 
 *  Example 2:
 *  Input: arr = [1,0,2,3,4]
 *  Output: 4
 *  Explanation:
 *  We can split into two chunks, such as [1, 0], [2, 3, 4].
 *  However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
 * 
 *  Constraints:
 *  n == arr.length
 *  1 <= n <= 10
 *  0 <= arr[i] < n
 *  All the elements of arr are unique. */

var maxChunksToSorted = function(arr) {
    var appeared = new Array(arr.length).fill(false);
    var count = 0;
    var size = 0;
    var answer = 0;
    var next = 0;

    for (let num of arr) {
        appeared[num] = true;
        count++;

        if (num != next) continue;

        size = next + count
        for (let i = next; i < next+count; ++i) {
            if (!appeared[i]) break;
            if (i == size-1) answer++;
            count--;
            next++;
        }
    }

    return answer;
};

var arr0 = [4,3,2,1,0];
var arr1 = [1,0,2,3,4];
var arr2 = [2,0,1,4,3,5];

var ans0 = maxChunksToSorted(arr0);
var ans1 = maxChunksToSorted(arr1);
var ans2 = maxChunksToSorted(arr2);

console.log(ans0); // 1
console.log(ans1); // 4
console.log(ans2); // 3



