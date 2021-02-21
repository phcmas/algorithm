#include <iostream>
#include <vector>

using namespace std;

int number_of_test_cases;
int number_of_galleries;
int number_of_hallways;
const int MAX_V = 1000;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
vector<int> adj[MAX_V];
vector<bool> visited;
int installed;

void initialize() {
    installed = 0;
    visited.clear();
    for (int i=0; i < number_of_galleries; ++i) {
        adj[i].clear();
        visited.push_back(false);
    }
}

int dfs (int here) {
    visited[here] = true;
    vector<int> children = {0,0,0};

    for (int i=0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        if (!visited[there]) {
            ++children[dfs(there)];
        }
    }

    if (children[UNWATCHED]) {
        ++installed;
        return INSTALLED;    
    }

    if (children[INSTALLED]){
        return WATCHED;
    }

    return UNWATCHED;
}

void installCamera() {
    for (int i=0; i < number_of_galleries; ++i) {
        if (!visited[i] && dfs(i) == UNWATCHED) {
            ++installed;
        }
    }
}

int main() {

    cin >> number_of_test_cases;

    for (int i=0; i< number_of_test_cases; ++i) {
        cin >> number_of_galleries >> number_of_hallways;
        initialize();

        for (int j=0 ; j< number_of_hallways; ++j) {
            int k,l;
            cin >> k >>l;
            adj[k].push_back(l);
            adj[l].push_back(k);
        }
        installCamera();
        cout << installed << endl;
    }

    return 0;
}