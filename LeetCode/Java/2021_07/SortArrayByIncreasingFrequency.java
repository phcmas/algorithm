/** 1636. Sort Array by Increasing Frequency */
/** Given an array of integers nums, sort the array in increasing order based on the frequency of the values. 
 *  If multiple values have the same frequency, sort them in decreasing order.
 * 
 *  Return the sorted array.
 * 
 *  Example 1:
 *  Input: nums = [1,1,2,2,2,3]
 *  Output: [3,1,1,2,2,2]
 *  Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
 * 
 *  Example 2:
 *  Input: nums = [2,3,1,3,2]
 *  Output: [1,3,3,2,2]
 *  Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
 * 
 *  Example 3:
 *  Input: nums = [-1,1,-6,4,5,-6,1,4,1]
 *  Output: [5,-1,4,4,-6,-6,1,1,1]
 * 
 *  Constraints:
 *  1 <= nums.length <= 100
 *  -100 <= nums[i] <= 100 */

import java.util.*;

class SortArrayByIncreasingFrequency {

    class Pair implements Comparable<Pair> {
        public int value;
        public int freq;

        public Pair(int value, int freq) {
            this.value = value;
            this.freq = freq;
        }

        @Override
        public int compareTo(SortArrayByIncreasingFrequency.Pair o) {
            if (freq == o.freq) return o.value - value;
            return freq - o.freq;
        }
    };

    public int[] frequencySort(int[] nums) {
        int index = 0;
        int[] answer = new int[nums.length];
        HashMap<Integer, Integer> numToFreq = new HashMap<>();
        PriorityQueue<Pair> pq = new PriorityQueue<>();

        for (int i = 0; i < nums.length; ++i) {
            if (numToFreq.containsKey(nums[i])) {
                numToFreq.put(nums[i], numToFreq.get(nums[i])+1);
            } else {
                numToFreq.put(nums[i], 1);
            }
        }

        for (Map.Entry iter : numToFreq.entrySet()) {
            pq.add(new Pair((int)iter.getKey(), (int)iter.getValue()));
        }

        while (!pq.isEmpty()) {
            int value = pq.peek().value;
            int freq = pq.peek().freq;
            pq.poll();

            for (int i = 0; i < freq; ++i) {
                answer[index++] = value;
            }
        }

        return answer;
    };

};