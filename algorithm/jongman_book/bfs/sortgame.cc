#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;
map<vector<int>, int> toSort;
int number_of_test_case;
int length;

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
            for (int j=i+2; j<=n; ++i) {
                reverse (here.begin()+i, here.begin()+j);
                if (toSort.count(here) == 0) {
                    toSort[here] = cost +1;
                    queue.push(here);
                }
                reverse (here.begin()+i, here.begin()+j);
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
    number_of_test_case = 1;
    cout << "aa";

    for (int i=0; i< number_of_test_case; ++i) {
        //cin >> length;
        length = 8;
        vector<int> perm (length);
        for (int j=0; j<length;++j) perm[j]=j;
        //for (int j=0; j < length; ++j) {
        //    int temp;
        //    cin >> temp;
        //    perm[j] = temp;
        //}
        precalc (length);
        cout << solve (perm) << endl;

    }

    return 0;
}



