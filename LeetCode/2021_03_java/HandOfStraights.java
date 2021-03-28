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
import java.util.TreeMap;
import java.util.ArrayList;
import java.util.Arrays;

 public class HandOfStraights { 
    // 아래는 Solution을 보고 구현한 풀이.
    public boolean isNStraightHand2(int[] hand, int W) {
    }

    
    // 아래는 내가 생각한 풀이. Accepted 받음.
    public boolean isNStraightHand(int[] hand, int W) {
        int notFull = 0;
        boolean inserted = false;

        if (hand.length % W != 0) return false;

        ArrayList<Integer>[] groups = new ArrayList[hand.length / W];
        Arrays.sort(hand);
         
        for (int i = 0; i < groups.length; i++) {
            groups[i] = new ArrayList<>();
        }

        for (int iter : hand) {
            inserted = false;
            for (int j = notFull; j < groups.length; ++j) {
                if (groups[j].isEmpty() || groups[j].get(groups[j].size()-1) + 1 == iter) {
                    groups[j].add(iter);
                    inserted = true;
                    break;
                } else if (groups[j].get(groups[j].size()-1) + 1 < iter) {
                    return false;
                }
            }

            if (!inserted) return false;
            if (groups[notFull].size() == W) notFull++;
        }

        return true;
    }
}



