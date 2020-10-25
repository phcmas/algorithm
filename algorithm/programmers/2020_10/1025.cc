/* 등굣길 */

#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int cache[120][120];
vector<vector<int> > pudds;

bool cannotGo (int i, int j, int m, int n) {
    bool ret = (i > m) || (j > n);
    for (int k = 0; k < pudds.size(); ++k) {
        if (i == pudds[k][0] && j == pudds[k][1]) {
            ret = true;
            break;
        }
    }

    return ret;
}

int shortestPath (int i, int j, int m, int n) {
    int &ret = cache[i][j];
    if (ret != -1) return ret;

    ret = 0;
    if (cannotGo(i,j,m,n)) return ret;
    
    ret = 1;
    if (i == m && j == n) return ret;

    ret = shortestPath(i+1,j,m,n) % 1000000007 + shortestPath(i,j+1,m,n) % 1000000007;
    ret %= 1000000007;
    return ret;
}

int solution(int m, int n, vector<vector<int> > puddles) {
    pudds = puddles;
    memset(cache, -1, sizeof(cache));

    return shortestPath(1,1,m,n);
}

int main() {
    int m = 4;
    int n = 3;
    vector<int> puddle;
    puddle.push_back(2);
    puddle.push_back(2);

    vector<vector<int> > puddles;
    puddles.push_back(puddle);
    int answer = solution (m, n, puddles);

    cout << answer << endl;

    return 0;
}




