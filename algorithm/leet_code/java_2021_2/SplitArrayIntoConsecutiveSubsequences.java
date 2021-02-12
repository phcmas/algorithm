/* 659. Split Array into Consecutive Subsequences */
/** Given an integer array nums that is sorted in ascending order, 
 *  return true if and only if you can split it into one or more subsequences such that 
 *  each subsequence consists of consecutive integers and has a length of at least 3.
 * 
 *  Example 1:
 *  Input: nums = [1,2,3,3,4,5]
 *  Output: true
 *  Explanation:
 *  You can split them into two consecutive subsequences : 
 *  1, 2, 3     3, 4, 5
 * 
 *  Example 2:
 *  Input: nums = [1,2,3,3,4,4,5,5]
 *  Output: true
 *  Explanation:
 *  You can split them into two consecutive subsequences : 
 *  1, 2, 3, 4, 5    3, 4, 5
 * 
 *  Example 3:
 *  Input: nums = [1,2,3,4,4,5]
 *  Output: false
 * 
 *  Constraints:
 *  1 <= nums.length <= 10^4
 *  -1000 <= nums[i] <= 1000
 *  nums is sorted in an ascending order. **/

package leet_code.java_2021_2;

import java.util.PriorityQueue;
import java.util.Queue;

public class SplitArrayIntoConsecutiveSubsequences {

    private boolean checkQueue(Queue<Integer> pq) {
        for (int i = 0; i < pq.size(); ++i) {
            if (pq.poll() < 3) return false;
        }

        return true;
    }

    private boolean addNumber(Queue<Integer> pq, int size) {
        int[] temp = new int[size];

        for (int i = 0; i < size; ++i) {
            if (pq.isEmpty()) {
                temp[i] = 1;
            } else {
                temp[i] = pq.poll()+1;
            }
        }
        
        if (!checkQueue(pq)) return false;
        
        for (int i = 0; i < size; ++i) {
            pq.add(temp[i]);
        }

        return true;
    }

    public boolean isPossible(int[] nums) {
        int prev, cur;
        int size = 0;;
        Queue<Integer> pq1 = new PriorityQueue<>((y,x)->Integer.compare(x, y));
        Queue<Integer> pq2 = new PriorityQueue<>();

        if (nums.length < 3) return false;

        for (int iter : nums) {
            pq1.add(iter);
        }

        prev = pq1.peek();
        while (!pq1.isEmpty()) {
            cur = pq1.poll();

            if (prev == cur) {
                size++;
            } else if (cur == prev-1) {
                if (!addNumber(pq2, size)) return false;
                prev = cur;
                size = 1;
            } else {
                if (!checkQueue(pq2)) return false;
                prev = cur;
                size = 1;
            }
        }

        return true;
    }

}

