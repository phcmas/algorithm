/* 트리 트리오 중간값 */

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <cstring>

using namespace std;

vector<int> dist;
vector<bool> visited;
vector<vector<int>> adj;

void initialize() {
    for (int i=0; i < dist.size(); ++i) {
        dist[i] = 0;
        visited[i] = false;
    }
}

list<int> distDFS (int now) {
    list<int> ret {now};
    visited[now] = true;

    for (int next : adj[now]) {
        if (!visited[next]) {
            list<int> next_ret = distDFS(next);
            if (dist[next]+1 > dist[now]) {
                dist[now] = dist[next]+1;
                ret = next_ret;
            } else if (dist[next]+1 == dist[now]) {
                ret.splice(ret.end(), next_ret);
            }
        }
    }

    return ret;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    int maxDist = -1;
    int start = 1;
    bool twoOrMore = false;
    list<int> v;

    if (n == 0) return 0;

    adj.resize(n+1, vector<int>());
    dist.resize(n+1, 0);
    visited.resize(n+1, false);

    for (int i=0; i < n-1; ++i) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    v = distDFS(start);
    start = v.front();
    initialize();
    v = distDFS(start);
    
    if (v.size() >= 2) {
        twoOrMore = true;
        maxDist = dist[start];
    } else {
        start = v.front();
        initialize();
        v = distDFS(start);
        twoOrMore = v.size() >= 2;
        maxDist = dist[start];
    }

    return twoOrMore ? maxDist : maxDist-1;
}

int main() {
    list<int> ss {1,2,3};
    list<int> tt {4,5};

    ss.splice(ss.end(), tt);

    int n = 4;
    vector<vector<int>> edges;
    vector<int> a {1,2};
    vector<int> b {2,3};
    vector<int> c {3,4};
    //vector<int> a {1,5};
    //vector<int> b {2,5};
    //vector<int> c {3,5};
    //vector<int> d {4,5};

    edges.push_back(a);
    edges.push_back(b);
    edges.push_back(c);
    //edges.push_back(d);

    int answer = solution (n, edges);

    cout << answer << endl;
    return 0;
}









