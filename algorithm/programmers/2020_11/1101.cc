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
            dfs (neighbor[i], direction);
        }
    }
}

int solution(int n, vector<vector<int> > results) {
    int answer = 0;
    bool canDecide = true;
    adj.resize(n+1);

    for (int i = 0; i < n; ++i) {
        adj[results[i][0]].push_back(results[i][1]);
        adj[results[i][1]].push_back(-results[i][0]);
    }

    for (int i = 1; i <= n; ++i) {
        memset (visited, -1, sizeof(visited));
        dfs (i, 1);
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
    vector<int> adj1;
    vector<int> adj2;
    vector<int> adj3;
    vector<int> adj4;
    vector<int> adj5;
    adj1.push_back(4);
    adj1.push_back(3);
    adj2.push_back(4);
    adj2.push_back(2);
    adj3.push_back(3);
    adj3.push_back(2);
    adj4.push_back(1);
    adj4.push_back(2);
    adj5.push_back(2);
    adj5.push_back(5);
    results.push_back(adj1);
    results.push_back(adj2);
    results.push_back(adj3);
    results.push_back(adj4);
    results.push_back(adj5);

    int answer = solution(5, results);

    cout << answer << endl;

    return 0;
}




