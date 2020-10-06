#include <vector>
#include <iostream>
#include <queue>
#include <limits.h>
#include <float.h>

using namespace std;

const int MAX_V = 10000;
const double INF = DBL_MAX;
vector<pair<int,double>> adj[MAX_V];
int number_of_test_case;
int number_of_computers;
int number_of_circuits;


vector<double> dijkstra (int src) {
    vector<double> dist (number_of_computers, INF);
    dist[src] = 1;
    priority_queue<pair<double, int>> pq;
    pq.push(make_pair(-1,src));

    while (!pq.empty()) {
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i=0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            double nextDist = cost * adj[here][i].second;
            
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }

    return dist;
}

int main() {
    cin >> number_of_test_case;

    for (int i=0; i < number_of_test_case; ++i) {
        cin >> number_of_computers >> number_of_circuits;

        for (int j=0; j < number_of_computers; ++j) {
            adj[j].clear();
        }

        for (int j=0; j < number_of_circuits; ++j) {
            int com1, com2;
            double noise;
            cin >> com1 >> com2 >> noise;
            adj[com1].push_back(make_pair(com2, noise));
            adj[com2].push_back(make_pair(com1, noise));
        }

        vector<double> answer = dijkstra (0);
        cout << answer.back() << endl;
    }


    return 0;
}

