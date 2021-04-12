import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

/** 406. Queue Reconstruction by Height */
/** You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). 
 *  Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front 
 *  who have a height greater than or equal to hi.
 * 
 *  Reconstruct and return the queue that is represented by the input array people. 
 *  The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of 
 *  the jth person in the queue (queue[0] is the person at the front of the queue).
 * 
 *  Example 1:
 *  Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
 *  Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
 *  Explanation:
 *  Person 0 has height 5 with no other people taller or the same height in front.
 *  Person 1 has height 7 with no other people taller or the same height in front.
 *  Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
 *  Person 3 has height 6 with one person taller or the same height in front, which is person 1.
 *  Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
 *  Person 5 has height 7 with one person taller or the same height in front, which is person 1.
 *  Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
 * 
 *  Example 2:
 *  Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
 *  Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 * 
 *  Constraints:
 *  1 <= people.length <= 2000
 *  0 <= hi <= 10^6
 *  0 <= ki < people.length
 *  It is guaranteed that the queue can be reconstructed. **/

import java.util.List;
import java.util.ArrayList;

class QueueReconstructionByHeight {
    class Comparator1 implements Comparator<int[]> {
        public int compare(int[] t1, int[] t2) {
            if (t1[0] == t2[0]) return t1[1]-t2[1];
            return t1[0]-t2[0];
        }
    }
    class Comparator2 implements Comparator<int[]> {
        public int compare(int[] t1, int[] t2) {
            if (t1[0] == t2[0]) return t1[1]-t2[1];
            return t2[0]-t1[0];
        }
    }

    // 아래는 내가 처음 구현한 풀이.
    public int[][] reconstructQueue1(int[][] people) {
        int[][] answer = new int[people.length][2];

        for (int i = 0; i < answer.length; ++i) {
            answer[i][0] = Integer.MAX_VALUE;
        }

        Arrays.sort(people, new Comparator1());

        for (int i = 0; i < people.length; ++i) {
            int count = 0;
            for (int j = 0; j < people.length; ++j) {
                if (answer[j][0] == Integer.MAX_VALUE && count == people[i][1]) {
                    answer[j] = people[i];
                    break;
                } else if (answer[j][0] >= people[i][0]) {
                    count++;
                }
            }
        }

        return answer;
    }

    // 아래는 Discussion에서 보고 구현한 풀이
    public int[][] reconstructQueue2(int[][] people) {
        Arrays.sort(people, new Comparator2());
        List<int[]> list = new ArrayList<>();

        for (int[] iter : people) {
            list.add(iter[1], iter);
        }

        return list.toArray(new int[people.length][2]);
    }

}