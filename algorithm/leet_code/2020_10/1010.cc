/*  Minimum Number of Arrows to Burst Balloons */
/** There are some spherical balloons spread in two-dimensional space. 
 *  For each balloon, provided input is the start and end coordinates of the horizontal diameter. 
 *  Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. 
 *  The start is always smaller than the end.
 * 
 *  An arrow can be shot up exactly vertically from different points along the x-axis. 
 *  A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. 
 *  There is no limit to the number of arrows that can be shot. 
 *  An arrow once shot keeps traveling up infinitely.
 * 
 *  Given an array points where points[i] = [xstart, xend], 
 *  return the minimum number of arrows that must be shot to burst all balloons.
 *  Example 1
 *  Input: points = [[10,16],[2,8],[1,6],[7,12]]
 *  Output: 
 *  Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) 
 *  and another arrow at x = 11 (bursting the other two balloons).
 *  
 *  Example 2:
 *  Input: points = [[1,2],[3,4],[5,6],[7,8]]
 *  Output: 4
 * 
 *  Example 3:
 *  Input: points = [[1,2],[2,3],[3,4],[4,5]]
 *  Output: 2
 * 
 *  Example 4:
 *  Input: points = [[1,2]]
 *  Output: 1
 * 
 *  Example 5:
 *  Input: points = [[2,3],[2,3]]
 *  Output: 1
 *  
 *  Constraints:
 *  0 <= points.length <= 104
 *  points.length == 2
 *  -231 <= xstart < xend <= 231 - 1 **/

#include <vector>
#include <set>
#include <iostream>
using namespace std;

bool notContains (vector<int> &point, int x) {
    if (point[0] <= x && x <= point[1]) return false;
    return true;
}

int minArrowShots (vector<vector<int> >& points, int index) {
    if (points.empty() || index >= points.size()) return 0;
    if (index == points.size()-1) return 1;

    int minEnd = points[index][1];
    int nextIndex = points.size();
    cout << "minEnd: " << index << endl;

    for (int i=index+1; i< points.size(); ++i) {
        if (minEnd < points[index][0]) {
            nextIndex = i;
            break;
        }

        minEnd = min (points[index][1], minEnd);
    }

    cout << "index: " << index << endl;
    cout << "minEnd: " << index << endl;
    cout << "nextIndex: " << index << endl;
    
    return 1+minArrowShots(points, nextIndex);
}

int findMinArrowShots(vector<vector<int> >& points) {
    sort (points.begin(), points.end());
    return minArrowShots (points, 0);
}

int main() {
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    vector<vector<int> > points;

    a.push_back(10);
    a.push_back(16);
    b.push_back(2);
    b.push_back(8);
    c.push_back(1);
    c.push_back(6);
    d.push_back(7);
    d.push_back(12);

    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    points.push_back(d);

    sort(points.begin(), points.end());

    for (int i=0; i<points.size(); ++i) {
        cout << points[i][0] << ", " << points[i][1] << endl;
    }

    int answer = findMinArrowShots(points);

    cout << answer << endl;

    return 0;
}

