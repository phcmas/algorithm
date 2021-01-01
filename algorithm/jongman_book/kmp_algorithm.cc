#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> getPartialMatch(const string &N) {
    int n = N.size();
    int matched = 0;
    vector<int> pi (n, 0);

    for (int i = 1; i < n; ++i) {
        while (matched > 0 && N[i] != N[matched])
            matched = pi[matched-1];

        if (N[i] == N[matched]) {
            matched++;
            pi[i] = matched;
        }
    }

    return pi;
}

vector<int> kmpSearch(const string &N, const string &M) {
    int n = N.size(), m = M.size();
    int matched = 0;
    vector<int> ret;

    vector<int> pi = getPartialMatch(N);

    for (int i = 0; i < n; ++i) {
        while (matched > 0 && N[i] != M[matched])
            matched = pi[matched-1];

        if (N[i] == M[matched]) {
            matched++;
            if (matched == m) {
                ret.push_back(i-m+1);
                matched = pi[matched-1];
            }
        }
    }

    return ret;
}

int main() {
    string N0 = "caabadaabaabad";
    string M0 = "aabaaba";
     
    vector<int> ans0 = kmpSearch(N0, M0);

    string N1 = "babacderrd";
    string M1 = "derr";
     
    vector<int> ans1 = kmpSearch(N1, M1);

    string N2 = "aaaaa";
    string M2 = "aa";
     
    vector<int> ans2 = kmpSearch(N2, M2);

    for (int i = 0; i < ans0.size(); ++i) {
        cout << ans0[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < ans1.size(); ++i) {
        cout << ans1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < ans2.size(); ++i) {
        cout << ans2[i] << " ";
    }
    cout << endl;

    return 0;
}


