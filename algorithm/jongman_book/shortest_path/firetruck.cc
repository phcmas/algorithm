#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>

using namespace std;

const int MAX_N = 1001;
int number_of_test_case;
int v;
int e;
int n;
int m;
vector<int> fire_stations;
vector<int> fire_places;
vector<pair<int,int>> adj[MAX_N];

vector<int> dijkstra(int src) {
    vector<int> dist (v+1, INT_MAX);
    priority_queue<pair<int,int>> pq;
    dist[src] = 0;
    pq.push(make_pair(0,src));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextDist = cost+adj[here][i].second;

            if (nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }

    return dist;
}

int main() {
    int answer;
    int a,b,c;

    cin >> number_of_test_case;

    for (int i = 0; i < number_of_test_case; ++i) {
        cin >> v >> e >> n >> m;
        fire_places.clear();
        fire_stations.clear();
        answer = 0;

        for (int j = 0; j < MAX_N; ++j) {
            adj[j].clear();
        }
        
        for (int j = 0; j < e; ++j) {
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }
        
        for (int j = 0; j < n; ++j) {
            cin >> a;
            fire_places.push_back(a);
        }

        for (int j = 0; j < m; ++j) {
            cin >> a;
            fire_stations.push_back(a);
            adj[a].push_back(make_pair(0,0));
            adj[0].push_back(make_pair(a,0));
        }

        vector<int> dist = dijkstra(0);
        
        for (int j = 0; j < n; ++j) {
            answer += dist[fire_places[j]];
        }

        cout << answer << endl;
    }

    return 0;
}