/* 등굣길 */

#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int cache[120][120];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    memset(cache, 0, sizeof(cache));
    cache[m+1][n] = 1;

    for (int i = 0; i < puddles.size(); ++i) {
        cache[puddles[i][0]][puddles[i][1]] = -1;
    }

    for (int i = m; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (cache[i][j] == -1) {
                cache[i][j] = 0;
            } else {
                cache[i][j] = (cache[i+1][j] + cache[i][j+1]) % 1000000007;
            }
        }
    }

    return cache[1][1];
}

int main() {
    int m = 4;
    int n = 3;
    vector<int> puddle;
    puddle.push_back(2);
    puddle.push_back(2);

    vector<vector<int>> puddles;
    puddles.push_back(puddle);
    int answer = solution (m, n, puddles);

    cout << answer << endl;

    return 0;
}




