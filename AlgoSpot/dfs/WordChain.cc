#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

// adj[i][j] = i 와 j 사이의 간선 개수
vector<vector<int>> adj;
// graph[i][j] = i로 시작하여 j로 끝나는 단어의 모음
vector<string> graph[26][26];

// indegree[i] = i 로 들어오는 간선의 수
// outdegree[i] = i 에서 나가는 간선의 수
vector<int> indegree, outdegree;
int number_of_test_cases;
int number_of_words;
string answer;

void getEulerCircuit (int here, vector<int> &circuit) {
    for (int there =0; there < 26; ++there) {
        if (adj[here][there] > 0) {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

vector<int> getEulerTrailOrCircuit() {
    vector<int> circuit;

    for (int i=0; i < 26; ++i) {
        if (outdegree[i] == indegree[i]+1) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }

    for (int i=0; i< 26; ++i) {
        if (outdegree[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }

    return circuit;
}

void makeGraph (const vector<string> &words) {
    for (int i=0; i< 26; ++i) {
        for (int j=0; j< 26; ++j) {
            graph[i][j].clear();
        }
    }

    adj = vector<vector<int>> (26, vector<int>(26, 0));
    indegree = outdegree = vector<int>(26,0);

    for (int i=0; i< words.size(); ++i) {
        int a = words[i][0]-'a';
        int b = words[i][words[i].size()-1]-'a';
        graph[a][b].push_back(words[i]);
        adj[a][b]++;
        outdegree[a]++;
        indegree[b]++;
    }
}

bool checkEuler() {
    int plus1 = 0, minus1 =0;

    for (int i=0; i< 26; ++i) {
        int delta = outdegree[i] - indegree[i];
        if (delta < -1 || 1< delta) return false;
        if (delta == 1) plus1++;
        if (delta == -1) minus1++;
    }

    return (plus1 == 1 && minus1 ==1) || (plus1 == 0 && minus1 == 0);
}

string solve (const vector<string> &words) {
    makeGraph(words);
    if (!checkEuler()) return "IMPOSSIBLE";

    vector<int> circuit = getEulerTrailOrCircuit();
    if (circuit.size() != words.size() +1) return "IMPOSSIBLE";

    reverse (circuit.begin(), circuit.end());
    string ret;
    for (int i=1; i< circuit.size(); ++i) {
        int a = circuit[i-1], b = circuit[i];
        if (ret.size()) ret += " ";
        ret += graph[a][b].back();
        graph[a][b].pop_back();
    }

    return ret;
}

int main() {
    cin >> number_of_test_cases;

    for (int i=0; i< number_of_test_cases; ++i) {
        vector<string> words;
        cin >> number_of_words;
        for (int j=0; j< number_of_words; ++j) {
            string temp;
            cin >> temp;
            words.push_back(temp);
        }
        
        answer = solve (words);
        cout << answer << endl;
    }

    return 0;
}










