#include <vector>
#include <list>
#include <math.h>

using namespace std;

list<int> cache[10][10][10];

list<int> numsSameConsecDiff(int first, int N, int K) {
    list<int> &newList = cache[first][N][K];
    list<int> temp;

    if (N == 0) return list<int> {0};
    if (N == 1) return list<int> {first};
    if (!newList.empty()) return newList;
    if (K == 0) {
        int number = 0;
        for (int i=0; i < N; ++i) {
            number += first * pow(10,i);
        }
        return list<int> {number};
    }


    if (first-K == 0) {
        temp = numsSameConsecDiff(first, N-2,K);
        for (int &iter : temp) {
            newList.push_back(first *pow(10,N-1) + iter);
        }
    }

    if (first-K > 0) {
        temp = numsSameConsecDiff(first-K, N-1, K);
        for (int &iter : temp) {
            newList.push_back(first *pow(10,N-1) + iter);
        }
    }

    if (first+K < 10) {
        temp = numsSameConsecDiff(first+K, N-1, K);
        for (int &iter : temp) {
            newList.push_back(first *pow(10,N-1) + iter);
        }
    }

    return newList;
}

vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> answer;
    list<int> temp;
    
    if (N == 1) {
        for (int i=0; i<10; ++i) {
            answer.push_back(i);
        }
        return answer;
    }

    for (int i=1; i < 10; ++i) {
        temp = numsSameConsecDiff(i, N, K);
        for (int &iter : temp) {
            answer.push_back(iter);
        }
    }

    return answer;
}

int main() {

    vector<int> answer = numsSameConsecDiff(2, 0);

    return 0;
}





