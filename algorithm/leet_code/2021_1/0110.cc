/* Network Delay Time */
/** There are N network nodes, labelled 1 to N.
 *  Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, 
 *  v is the target node, and w is the time it takes for a signal to travel from source to target.
 *  Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.
 * 
 *  Example 1:
 *  Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 *  Output: 2
 * 
 *  Note:
 *  N will be in the range [1, 100].
 *  K will be in the range [1, N].
 *  The length of times will be in the range [1, 6000].
 *  All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100 **/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> adj[101];
int minTime[101];

int networkDelayTime(vector<vector<int>> &times, int N, int K) {
    int answer = 0;
    queue<pair<int,int>> queue;
    vector<bool> received;

    if (times.empty()) return 0;

    received.resize(N+1, false);

    for (int i = 0; i < times.size(); ++i) {
        adj[times[i][0]].push_back({times[i][1], times[i][2]});
    }

    queue.push({K,0});

    while (!queue.empty()) {
        int here = queue.front().first;
        int time = queue.front().second;
        queue.pop();

        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextTime = time + adj[here][i].second;

            if (nextTime < minTime[there]) {
                minTime[there] = nextTime;
                queue.push({there, nextTime});
            } else {
                answer = nextTime;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> row00 {2,1,1};
    vector<int> row01 {2,3,1};
    vector<int> row02 {3,4,1};
    vector<vector<int>> times0 {row00, row01, row02};

    int ans0 = networkDelayTime(times0, 4, 2);

    cout << ans0 << endl; // 2

    return 0;
}
