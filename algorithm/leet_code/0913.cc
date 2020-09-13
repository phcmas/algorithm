/** Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *  You may assume that the intervals were initially sorted according to their start times.
 * 
 *  Example 1
 *  Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 *  Output: [[1,5],[6,9]]
 * 
 *  Example 2
 *  Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 *  Output: [[1,2],[3,10],[12,16]
 * 
 *  Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10]
 *  input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 *  **/

#include <vector>
#include <math.h>

using namespace std;

int isIn (int point, vector<int> &interval) {
    int start = interval.front();
    int end = interval.back();

    if (point < start) {
        return -1;
    } else if (point >= start && point <= end) {
        return 0;
    } else {
        return 1;
    }
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int start = newInterval.front();
    int end = newInterval.back();
    int overlapStart = -1;
    int overlapEnd = -1;
    int newStart;
    int newEnd;

    for (int i=0; i < intervals.size(); ++i) {
        int discriStart = isIn (start, intervals[i]);
        if (discriStart == -1 || discriStart ==0) {
            overlapStart = i;
            newStart = min (intervals[i].front(), start);
            break;
        }
    }

    for (int i=overlapStart; i < intervals.size(); ++i) {
        int discriEnd = isIn (end, intervals[i]);
        if (discriEnd == 0 || discriEnd == 1) {
            
        }
    }


}

int main() {

    return 0;
}






