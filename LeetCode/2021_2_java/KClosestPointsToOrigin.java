/* 973. K Closest Points to Origin */
/** We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
 *  (Here, the distance between two points on a plane is the Euclidean distance.)
 *  You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
 * 
 *  Example 1:
 *  Input: points = [[1,3],[-2,2]], K = 1
 *  Output: [[-2,2]]
 *  Explanation: 
 *  The distance between (1, 3) and the origin is sqrt(10).
 *  The distance between (-2, 2) and the origin is sqrt(8).
 *  Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 *  We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
 * 
 *  Example 2:
 *  Input: points = [[3,3],[5,-1],[-2,4]], K = 2
 *  Output: [[3,3],[-2,4]]
 *  (The answer [[-2,4],[3,3]] would also be accepted.)
 * 
 *  Note:
 *  1 <= K <= points.length <= 10000
 *  -10000 < points[i][0] < 10000
 *  -10000 < points[i][1] < 10000 */

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class KClosestPointsToOrigin {
    class Point {
        public int x;
        public int y;
        public Point(int xCoord, int yCoord) {
            x = xCoord;
            y = yCoord;
        }
        public double distanceFromOrigin() {
            return Math.sqrt(x * x + y * y);
        }
    }

    class PointComparator implements Comparator<Point> {
        public int compare(Point p1, Point p2) {
            if (p1.distanceFromOrigin() > p2.distanceFromOrigin()) {
                return 1;
            } else if (p1.distanceFromOrigin() < p2.distanceFromOrigin()) {
                return -1;
            }
    
            return 0;
        }
    }

    public int[][] kClosest(int[][] points, int K) {
        int[][] answer = new int[K][2];
        Queue<Point> pq = new PriorityQueue<>(points.length, new PointComparator());

        for (int[] iter : points) {
            pq.add(new Point(iter[0], iter[1]));
        }

        for (int i = 0; i < K ; ++i) {
            Point p = pq.poll();
            answer[i][0] = p.x;
            answer[i][1] = p.y;
        }

        return answer;
    }
}


