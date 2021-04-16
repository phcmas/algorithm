import java.util.Comparator;
import java.util.PriorityQueue;

/** 1029. Two City Scheduling */
/** A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], 
 *  the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
 *  Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
 * 
 *  Example 1:
 *  Input: costs = [[10,20],[30,200],[400,50],[30,20]]
 *  Output: 110
 *  Explanation: 
 *  The first person goes to city A for a cost of 10.
 *  The second person goes to city A for a cost of 30.
 *  The third person goes to city B for a cost of 50.
 *  The fourth person goes to city B for a cost of 20.
 *  The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 * 
 *  Example 2:
 *  Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
 *  Output: 1859
 * 
 *  Example 3:
 *  Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
 *  Output: 3086
 * 
 *  Constraints:
 *  2 * n == costs.length
 *  2 <= costs.length <= 100
 *  costs.length is even.
 *  1 <= aCosti, bCosti <= 1000 */


public class TwoCityScheduling {
    class CostComparator implements Comparator<Cost> {
        public int compare(Cost c1, Cost c2) {
            int diff1 = Math.abs(c1.aCity - c1.bCity);
            int diff2 = Math.abs(c2.aCity - c2.bCity);
            return diff2 - diff1;
        }
    }

    class Cost {
        public int aCity;
        public int bCity;
        public Cost(int aCity, int bCity) {
            this.aCity = aCity;
            this.bCity = bCity;
        }
    }

    public int twoCitySchedCost(int[][] costs) {
        int answer = 0;
        int aCount = 0;
        int bCount = 0;

        PriorityQueue<Cost> pq = new PriorityQueue<>(new CostComparator());
        for (int[] iter : costs) {
            pq.add(new Cost(iter[0], iter[1]));
        }

        while (!pq.isEmpty()) {
            Cost cost = pq.poll();

            if (aCount == costs.length / 2) {
                answer += cost.bCity;
                bCount++;
            } else if (bCount == costs.length / 2 || cost.aCity <= cost.bCity) {
                answer += cost.aCity;
                aCount++;
            } else if (cost.bCity < cost.aCity) {
                answer += cost.bCity;
                bCount++;
            }
        }

        return answer;
    }

}



