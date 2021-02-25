/* 215. Kth Largest Element in an Array */
/** Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, 
 *  not the kth distinct element.
 * 
 *  Example 1:
 *  Input: [3,2,1,5,6,4] and k = 2
 *  Output: 5
 * 
 *  Example 2:
 *  Input: [3,2,3,1,2,4,5,5,6] and k = 4
 *  Output: 4
 *  Note: You may assume k is always valid, 1 ≤ k ≤ array's length. */

 /* findKthLargest는 내가 처음 생각한 풀이, findKthLargerst2는 Discussion 참고(quick select) */

import java.util.PriorityQueue;
import java.util.Queue;

public class KthLargestElementInAnArray {
    private void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

    private int partition(int[] nums, int left, int right, int k) {
        if (left > right) return 0;

        int pivot = nums[right];
        int index = left;

        for (int i = left; i < right; ++i) {
            if (nums[i] <= pivot) {
                swap(nums, i, index++);
            }
        }
        swap(nums, index, right);

        if (index == k) return nums[index];
        else if (index > k) return partition(nums, left, index-1, k);
        else return partition(nums, index+1, right, k);
    }

    public int findKthLargest(int[] nums, int k) {
        Queue<Integer> pq = new PriorityQueue<>((x,y)->Integer.compare(y, x));

        for (int i = 0; i < nums.length; ++i) {
            pq.add(nums[i]);
        }

        for (int i = 0; i < k-1; ++i) {
            pq.poll();
        }

        return pq.poll();
    }

    public int findKthLargest2(int[] nums, int k) {
        if (nums == null || nums.length == 0) return 0;
        return partition(nums, 0, nums.length-1, nums.length-k);
    }

}


