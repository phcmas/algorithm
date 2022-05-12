/** 128. Longest Consecutive Sequence */
/** Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 *  You must write an algorithm that runs in O(n) time.
 * 
 *  Example 1:
 *  Input: nums = [100,4,200,1,3,2]
 *  Output: 4
 *  Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 * 
 *  Example 2:
 *  Input: nums = [0,3,7,2,5,8,4,6,0,1]
 *  Output: 9
 * 
 *  Constraints:
 *  0 <= nums.length <= 10^5
 *  -10^9 <= nums[i] <= 10^9 **/

import java.util.Map;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;
import java.util.HashSet;

public class LongestConsecutiveSequence {
    int[] parent;
    int[] child;
    Map<Integer, Integer> numToIndex;

    private void initialize(int[] nums) {
        numToIndex = new HashMap<>();
        parent = new int[nums.length];
        child = new int[nums.length];

        for (int i = 0; i < nums.length; ++i) {
            parent[i] = i;
            child[i] = i;
            numToIndex.put(nums[i], i);
        }
    }

    private int lengthOfSequence(int[] child, int root) {
        int num = root;
        int length = 1;

        while (child[num] != num) {
            num = child[num];
            length++;
        }

        return length; 
    }

    // 아래는 내가 구현한 풀이
    public int longestConsecutive(int[] nums) {
        int answer = 0;

        if (nums.length == 0) return 0;
        initialize(nums);
        
        for (int i = 0; i < nums.length; ++i) {
            int childIndex = numToIndex.containsKey(nums[i]-1) ? numToIndex.get(nums[i]-1) : -1;
            int parentIndex = numToIndex.containsKey(nums[i]+1) ? numToIndex.get(nums[i]+1) : -1;

            if (childIndex != -1) child[i] = childIndex;
            if (parentIndex != -1) parent[i] = parentIndex;
        }

        for (int i = 0; i < nums.length; ++i) {
            if (parent[i] == i) {
                answer = Math.max(answer, lengthOfSequence(child, i));
            }
        }

        return answer;
    }

    // 아래는 Discussion 보고 구현. 간단하구만 와우
    public int longestConsecutive2(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int length = 0;

        for (int i = 0; i < nums.length; ++i) {
            set.add(nums[i]);
        }

        for (int i = 0; i < nums.length; ++i) {
            if (!set.contains(nums[i])) continue;
            
            int prev = nums[i]-1;
            int next = nums[i]+1;

            while (set.contains(prev)) set.remove(prev--);
            while (set.contains(next)) set.remove(next++);
            length = Math.max(length, next-prev-1);
        }

        return length;
    }

}
