/** 167. Two Sum II - Input array is sorted */
/** Given an array of integers numbers that is already sorted in ascending order, 
 *  find two numbers such that they add up to a specific target number.
 * 
 *  Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, 
 *  where 1 <= answer[0] < answer[1] <= numbers.length.
 *  You may assume that each input would have exactly one solution and you may not use the same element twice.
 * 
 *  Example 1:
 *  Input: numbers = [2,7,11,15], target = 9
 *  Output: [1,2]
 *  Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 *  Example 2:
 *  Input: numbers = [2,3,4], target = 6
 *  Output: [1,3]
 * 
 *  Example 3:
 *  Input: numbers = [-1,0], target = -1
 *  Output: [1,2]
 * 
 *  Constraints:
 *  2 <= numbers.length <= 3 * 10^4
 *  -1000 <= numbers[i] <= 1000
 *  numbers is sorted in increasing order.
 *  -1000 <= target <= 1000
 *  Only one valid answer exists. */


public class TwoSumIIInputArrayIsSorted {
    private int nextLeft(int[] numbers, int target, int iLeft, int iRight) {
        int left = iLeft;
        int right = iRight;

        while (left <= right) {
            int middle = (left + right) / 2;

            if (numbers[iRight] + numbers[middle] >= target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return left;
    }

    private int nextRight(int[] numbers, int target, int iLeft, int iRight) {
        int left = iLeft;
        int right = iRight;

        while (left <= right) {
            int middle = (left + right) / 2;

            if (numbers[iLeft] + numbers[middle] <= target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return right;
    }

    public int[] twoSum(int[] numbers, int target) {
        int[] answer = new int[2];
        int left = 0;
        int right = numbers.length - 1;

        while (true) {
            right = nextRight(numbers, target, left, right);
            left = nextLeft(numbers, target, left, right);
            if (numbers[left] + numbers[right] == target) break;
        }
        
        answer[0] = left + 1;
        answer[1] = right + 1;

        return answer;
    }
}

