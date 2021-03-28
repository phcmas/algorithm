import java.util.SortedMap;
import java.util.TreeMap;

/** 846. Hand of Straights */
/** Alice has a hand of cards, given as an array of integers.
 *  Now she wants to rearrange the cards into groups so that each group is size W, 
 *  and consists of W consecutive cards.
 *  Return true if and only if she can.
 * 
 *  Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 * 
 *  Example 1:
 *  Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
 *  Output: true
 *  Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
 * 
 *  Example 2: 
 *  Input: hand = [1,2,3,4,5], W = 4 
 *  Output: false 
 *  Explanation: Alice's hand can't be rearranged into groups of 4.
 * 
 *  Constraints:
 *  1 <= hand.length <= 10000
 *  0 <= hand[i] <= 10^9
 *  1 <= W <= hand.length */

import java.util.Map;

 public class HandOfStraights {
     public boolean isNStraightHand(int[] hand, int W) {
         Map<Integer, Integer> frequencies = new TreeMap<>();
         int countOfGroup[];
         int firstEmptyGroup = 0;

         if (hand.length % W != 0) return false;
         countOfGroup = new int[hand.length / W];

         for (int iter : hand) {
             if (frequencies.containsKey(iter)) {
                 frequencies.replace(iter, frequencies.get(iter)+1);
             } else {
                 frequencies.put(iter, 1);
             }
         }

         for (Map.Entry<Integer,Integer> entry : frequencies.entrySet()) {
         }

         return true;
     }
 }