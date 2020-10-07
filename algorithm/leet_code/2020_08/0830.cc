#include <vector>
#include <math.h>
#include <iostream>

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

int gcd (int a, int b) {
    int bigger = max (a,b);
    int smaller = min (a,b);
    int remainder = bigger % smaller;

    if (remainder == 0) {
        return smaller;
    }

    return gcd (smaller, remainder);
}

void makeGraph(vector<int> &A) {
    int size = A.size();
    adj.resize(size, std::vector<int>());
    visited.resize(size, false);

    for (int i=0; i < size; ++i) {
        for (int j=i+1; j < size; ++j) {
            if (gcd (A[i], A[j]) > 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

void dfs (int index, int &length) {
    if (visited[index]) return;

    int next;
    visited[index] = true;
    length++;

    for (int i=0; i < adj[index].size(); ++i) {
        next = adj[index][i];
        if (!visited[next]) dfs(next, length);
    }
}

int largestComponentSize(vector<int>& A) {
    int answer = 0;
    makeGraph(A);

    for (int i=0; i < adj.size(); ++i) {
        int length =0;
        dfs (i, length);
        answer = max (answer, length);
    }

    return answer;
}

int main() {
    vector<int> A {2,3,6,7,4,12,21,39};
    int answer = largestComponentSize(A);
    cout << answer << endl;

    return 0;
}







