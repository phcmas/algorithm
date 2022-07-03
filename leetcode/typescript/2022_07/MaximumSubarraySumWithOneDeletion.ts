/** 1186. Maximum Subarray Sum with One Deletion */
/** Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion.
 *  In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element
 *  left and the sum of the remaining elements is maximum possible.
 *
 *  Note that the subarray needs to be non-empty after deleting one element.
 *
 *  Example 1:
 *  Input: arr = [1,-2,0,3]
 *  Output: 4
 *  Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
 *
 *  Example 2:
 *  Input: arr = [1,-2,-2,3]
 *  Output: 3
 *  Explanation: We just choose [3] and it's the maximum sum.
 *
 *  Example 3:
 *  Input: arr = [-1,-1,-1,-1]
 *  Output: -1
 *  Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it,
 *  then get an empty subarray to make the sum equals to 0.
 *
 *  Constraints:
 *  1 <= arr.length <= 10^5
 *  -10^4 <= arr[i] <= 10^4 */

function maximumSum(arr: number[]): number {
  const length = arr.length;
  const deleted = new Array(length).fill(0);
  const notDeleted = new Array(length).fill(0);

  deleted[0] = arr[0];
  notDeleted[0] = arr[0];

  for (let i = 1; i < arr.length; ++i) {
    deleted[i] = Math.max(deleted[i - 1] + arr[i], notDeleted[i - 1]);
    notDeleted[i] = Math.max(notDeleted[i - 1] + arr[i], arr[i]);
  }

  return Math.max(...deleted, ...notDeleted);
}

export { maximumSum };
