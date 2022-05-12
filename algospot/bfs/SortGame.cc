#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;
map<vector<int>, int> toSort;
int number_of_test_case;
int length;

void reverse (vector<int> &src, int i, int j) {
    int temp;
    while (i < j-1) {
        temp = src[i];
        src[i] = src[j-1];
        src[j-1] = temp;
        i++; j--;
    }
}

void precalc (int n) {
    vector<int> perm(n);
    for (int i=0; i<n; ++i) perm[i] = i;
    queue<vector<int> > queue;
    queue.push(perm);
    toSort[perm] = 0;

    while (!queue.empty()) {
        vector<int> here = queue.front();
        queue.pop();
        int cost = toSort[here];
        for (int i=0; i<n; ++i) {
            for (int j=i+2; j<=n; ++j) {
                reverse (here, i, j);
                if (toSort.count(here) == 0) {
                    toSort[here] = cost +1;
                    queue.push(here);
                }
                reverse (here, i, j);
            }
        }
    }   
}

int solve (const vector<int> &perm) {
    int size = perm.size();
    vector<int> fixed(size);

    for (int i=0; i < size; ++i) {
        int smaller =0;
        for (int j=0; j < size; ++j) {
            if (perm[i] > perm[j]) smaller++;
        }
        fixed[i] = smaller;
    }

    return toSort[fixed];
}

int main() {
    //cin >> number_of_test_case;
    int test = 9 >> 2;

    for (int i=0; i< number_of_test_case; ++i) {
        cin >> length;
        vector<int> perm (length);
        for (int j=0; j < length; ++j) {
            cin >> perm[j];
        }
        precalc (length);
        cout << solve (perm) << endl;
    }

    return 0;
}



