/* 짝수 행 세기 2020_10_07 */
/** 모든 수가 0 또는 1로 이루어진 2차원 배열 a가 주어집니다. 다음 조건을 모두 만족하는 2차원 배열 b의 경우의 수를 (107 + 19)로 나눈 나머지를 return 하도록 solution 함수를 완성해주세요.
b의 모든 원소는 0 아니면 1입니다.
a의 행/열의 개수와 b의 행/열의 개수가 같습니다. (= a와 b의 크기가 같습니다.)
i = 1, 2, ..., (a의 열의 개수)에 대해서 a의 i번째 열과 b의 i번째 열에 들어 있는 1의 개수가 같습니다.
b의 각 행에 들어 있는 1의 개수가 짝수입니다. (0도 짝수입니다.)
제한 사항
a의 행의 개수는 1 이상 300 이하입니다.
a의 각 행의 길이는 1 이상 300 이하로 모두 동일합니다.
입출력 예
a	result
[[0,1,0],[1,1,1],[1,1,0],[0,1,1]]	6
[[1,0,0],[1,0,0]]	0
[[1,0,0,1,1],[0,0,0,0,0],[1,1,0,0,0],[0,0,0,0,1]]	72 **/

#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int binomial (int n , int k) {
    /* 0 <= k <= n */
    double ret =1;
    if (n == 0) return 1;
    for (int i=0; i<k;++i) {
        ret *= (double)(n-i)/(i+1);
    }

    return (int)ret;
}

int solution(vector<vector<int>> a) {
    int c = a[0].size();
    int r = a.size();
    int cache [c][r+1];
    int oneCount[c];
    int answer = 0;

    memset(cache, 0, sizeof(cache));
    memset(oneCount, 0, sizeof(oneCount));

    for (int i=0; i < c; ++i) {
        for (int j=0; j < r; ++j) {
            if (a[j][i] == 1) oneCount[i]++;
        }
    }

    cache[0][r-oneCount[0]] = binomial(r, r-oneCount[0]);

    for (int n=0; n < c-1; ++n) {
        int c = oneCount[n+1];
        for (int l=0; l<=r; ++l) {
            for (int a=0; a<=r; ++a) {
                if (a+c-l < 0 || (a+c-l) %2 != 0) continue;
                int k = (a+c-l)/2;
                int minimum = max (0,c+a-r);
                int maximum = min (a,c);
                if (k < minimum || k > maximum) continue;
                cache[n+1][l] += cache[n][a] * binomial(a, k) * binomial(r-a, c-k);
            }
        }
    }

    return cache[c-1][r];
}

int main() {
    //vector<int> x {0,1,0};
    //vector<int> y {1,1,1};
    //vector<int> z {1,1,0};
    //vector<int> w {0,1,1};

    vector<int> x {1,0,0,1,1};
    vector<int> y {0,0,0,0,0};
    vector<int> z {1,1,0,0,0};
    vector<int> w {0,0,0,0,1};
    vector<vector<int>> a;
    a.push_back(x);
    a.push_back(y);
    a.push_back(z);
    a.push_back(w);

    int answer = solution(a);

    cout << answer << endl;

    return 0;
}

