/* 네트워크 (level 3) */

#include <string>
#include <vector>
#include <iostream>

using namespace std;


void dfs (vector<vector<int>> &computers, vector<bool> &visited, int start, int n) {
    vector<int> adj = computers[start];
    if (visited[start]) return;

    visited[start] = true;

    for (int i = 0; i < n; ++i) {
        if (adj[i]) {
            dfs(computers, visited, i, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited (n, false);
    int answer = 0;

    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        dfs(computers, visited, i, n);
        answer++;
    }

    return answer; 
}

int main() {
    vector<vector<int>> computers;
    vector<int> first {1,1,0};
    vector<int> second {1,1,1};
    vector<int> third {0,1,1};
    computers.push_back(first);
    computers.push_back(second);
    computers.push_back(third);
    
    int n = computers.size();

    int answer = solution (n, computers);

    cout << answer << endl;

    return 0;
}

