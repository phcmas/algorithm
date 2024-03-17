/** 462. Minimum Moves to Equal Array Elements II */
/** Given an integer array nums of size n, return the minimum number of
 *  moves required to make all array elements equal.
 *  In one move, you can increment or decrement an element of the array by 1.
 *  Test cases are designed so that the answer will fit in a 32-bit integer.
 *
 *  Example 1:
 *  Input: nums = [1,2,3]
 *  Output: 2
 *  Explanation:
 *  Only two moves are needed (remember each move increments or decrements one element):
 *  [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 *  Example 2:
 *  Input: nums = [1,10,2,9]
 *  Output: 16
 *
 *  Constraints:
 *  n == nums.length
 *  1 <= nums.length <= 10^5
 *  -10^9 <= nums[i] <= 10^9 */

function minMoves2(nums: number[]): number {
  const nums_sorted = nums.sort((a, b) => a - b);
  const medium = nums_sorted[Math.floor(nums_sorted.length / 2)];
  const moves = nums_sorted.reduce(
    (result, num) => result + Math.abs(medium - num),
    0
  );

  return moves;
}

export { minMoves2 };
