/** 986. Interval List Intersections */
/** You are given two lists of closed intervals, firstList and secondList, 
 *  where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. 
 *  Each list of intervals is pairwise disjoint and in sorted order.
 *  
 *  Return the intersection of these two interval lists.
 *  A closed interval [a, b] (with a < b) denotes the set of real numbers x with a <= x <= b.
 *  The intersection of two closed intervals is a set of real numbers that are either empty or 
 *  represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].
 * 
 *  Example 1:
 *  Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
 *  Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * 
 *  Example 2:
 *  Input: firstList = [[1,3],[5,9]], secondList = []
 *  Output: []
 * 
 *  Example 3:
 *  Input: firstList = [], secondList = [[4,8],[10,12]]
 *  Output: []
 * 
 *  Example 4:
 *  Input: firstList = [[1,7]], secondList = [[3,10]]
 *  Output: [[3,7]]
 * 
 *  Constraints:
 *  0 <= firstList.length, secondList.length <= 1000
 *  firstList.length + secondList.length >= 1
 *  0 <= starti < endi <= 109
 *  endi < starti+1
 *  0 <= startj < endj <= 109
 *  endj < startj+1 **/

/** 아래는 잘못된 풀이이지만... comparable 의 사용법을 익힌 예시로 그냥 남겨두었다. */

import java.util.List;
import java.util.ArrayList;
import java.util.PriorityQueue;

class Point implements Comparable<Point> {
    public int number;
    public boolean isLeft;
    public boolean isFirst;

    public Point(int num, boolean left, boolean first) {
        number = num;
        isLeft = left;
        isFirst = first;
    }

    @Override
    public int compareTo(Point point) {
        if (this.number > point.number) {
            return 1;
        } else if (this.number < point.number) {
            return -1;
        } else if (!this.isLeft && point.isLeft) {
            return 1;
        } else if (this.isLeft && !point.isLeft) {
            return -1;
        }

        return 0;
    }
}

public class IntervalListIntersectionsFail {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        int left = -1;
        boolean isFirst = false;
        PriorityQueue<Point> priorityQueue = new PriorityQueue<>();
        List<int[]> result = new ArrayList<>();

        for (int i = 0; i < firstList.length; ++i) {
            priorityQueue.offer(new Point(firstList[i][0], true, true));
            priorityQueue.offer(new Point(firstList[i][1], false, true));
        }

        for (int i = 0; i < secondList.length; ++i) {
            priorityQueue.offer(new Point(secondList[i][0], true, false));
            priorityQueue.offer(new Point(secondList[i][1], false, false));
        }

        while (!priorityQueue.isEmpty()) {
            Point point = priorityQueue.poll();
            
            if (point.isLeft) {
                left = point.number;
                isFirst = point.isFirst;
            } else if (point.isFirst != isFirst) {
                int[] newInterval = {left, point.number};
                result.add(newInterval);
            }
        }

        return result.toArray(new int[result.size()][]);
    }

}
