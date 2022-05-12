#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_DISCS = 12;
int number_of_test_cases;
int cost[1<< (MAX_DISCS*2)];

int get (int state, int index) {
    return (state >> (index *2)) & 3;
}

int set (int state, int index, int value) {
    return (state & ~(3 << (index *2))) | (value << (index *2));
}

int sgn(int x) { if (!x) return 0; return x >0 ? 1: -1;}
int incr(int x) {if (x<0) return x-1; return x+1; }

int bidr (int discs, int begin, int end) {
    if (begin == end) return 0;
    queue<int> q;
    memset(cost, 0, sizeof(cost));
    q.push(begin); cost[begin] = 1;
    q.push(end); cost[end] = -1;

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        int top[4] = {-1,-1,-1,-1};
        for (int i=discs-1;i>=0;--i) top[get(here,i)] = i;

        for (int i=0; i<4; ++i) {
            if (top[i] != -1) {
                for (int j=0; j<4;++j) {
                    if (i !=j && (top[j] == -1 || top[j] > top[i])) {
                        int there = set (here, top[i], j);
                        if (cost[there] == 0) {
                            cost[there] = incr(cost[here]);
                            q.push(there);
                        } else if (sgn(cost[there]) != sgn (cost[here])) {
                            return abs(cost[here]) + abs(cost[there])-1;
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    int begin, end, discs, temp1,temp2;
    cin >> number_of_test_cases;

    for (int i =0; i< number_of_test_cases; ++i) {
        begin = 0;
        end = 0;
        cin >> discs;

        for (int j=0; j < discs; ++j) {
            end = set (end, j, 3);
        }

        for (int j=0; j < 4; ++j) {
            cin >> temp1;
            for (int k=0; k< temp1; ++k) {
                cin >> temp2;
                begin = set (begin, temp2-1, j);
            }
        }
        cout << bidr (discs,begin, end) << endl;
    }

    return 0;
}