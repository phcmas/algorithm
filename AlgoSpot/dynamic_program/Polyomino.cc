#include <iostream>
#include <cstring>

int MOD = 10000000;
int number_of_test_cases =1;
int cache[100][100];
int n;
int answers[50];

using namespace std;

int PolyominoWithHeight (int n, int h) {
    int &ret = cache[n][h];
    if (ret != -1) return ret;

    if (n ==h) { ret =1; return ret;}

    ret =0;
    for (int i=1; i<= n-h; ++i) {
        ret += (h+i-1) * PolyominoWithHeight(n-h,i);
        ret = ret % MOD;
    }

    return ret;
}

int Polyomino (int n) {
    int answer = 0;

    for (int i=1; i<= n; ++i) {
        answer += PolyominoWithHeight(n, i);
        answer = answer % MOD;
    }

    return answer;
}

int main() {
    cin >> number_of_test_cases;

    for (int i=0; i < number_of_test_cases; ++i) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        answers[i] = Polyomino(n);
    }

    for (int i=0; i < number_of_test_cases; ++i) {
        cout << answers[i] << endl;
    }

    return 0;
}



