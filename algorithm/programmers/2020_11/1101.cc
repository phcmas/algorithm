/* 순위 */

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool visited[101];
vector<vector<int> > adj;

void dfs(int start, int direction) {
    if (visited[start]) return;
    visited[start] = true;
    vector<int> neighbor = adj[start];

    for (int i = 0; i < neighbor.size(); ++i) {
        if (neighbor[i] * direction > 0) {
            dfs (abs(neighbor[i]), direction);
        }
    }
}

int solution(int n, vector<vector<int> > results) {
    int answer = 0;
    bool canDecide = true;
    adj.resize(n+1);

    for (int i = 0; i < results.size(); ++i) {
        adj[results[i][0]].push_back(results[i][1]);
        adj[results[i][1]].push_back(-results[i][0]);
    }

    for (int i = 1; i <= n; ++i) {
        canDecide = true;
        memset (visited, false, sizeof(visited));
        dfs (i, 1);
        visited[i] = false;
        dfs (i, -1);

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                canDecide = false;
                break;
            }
        }

        if (canDecide) answer++;
    }

    return answer;
}

int main() {
    vector<vector<int> > results;
    int n = 8;
    vector<int> adj1 {1,2};
    vector<int> adj2 {2,3};
    vector<int> adj3 {3,4};
    vector<int> adj4 {5,6};
    vector<int> adj5 {6,7};
    vector<int> adj6 {7,8};

    results.push_back(adj1);
    results.push_back(adj2);
    results.push_back(adj3);
    results.push_back(adj4);
    results.push_back(adj5);
    results.push_back(adj6);

    int answer = solution(n, results);

    cout << answer << endl;

    return 0;
}




