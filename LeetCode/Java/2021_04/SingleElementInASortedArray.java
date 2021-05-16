/** 540. Single Element in a Sorted Array */
/** You are given a sorted array consisting of only integers where every element appears exactly twice, 
 *  except for one element which appears exactly once. Find this single element that appears only once.
 *  Follow up: Your solution should run in O(log n) time and O(1) space.
 *  Example 1:
 *  Input: nums = [1,1,2,3,3,4,4,8,8]
 *  Output: 2
 * 
 *  Example 2:
 *  Input: nums = [3,3,7,7,10,11,11]
 *  Output: 10
 * 
 *  Constraints:
 *  1 <= nums.length <= 10^5
 *  0 <= nums[i] <= 10^5 */

public class SingleElementInASortedArray {
    public int singleNonDuplicate(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int middle = (left + right) / 2;
            int remainder = (right - left + 1) % 4;

            if (nums[middle] != nums[middle-1] && nums[middle] != nums[middle+1]) {
                return nums[middle];
            } else if (remainder == 1) {
                if (nums[middle] != nums[middle+1]) right = middle;
                else left = middle;
            } else if (remainder == 3) {
                if (nums[middle] != nums[middle+1]) left = middle+1;
                else right = middle-1;
            }
        }

        return nums[left];
    }     
}
