/* 등굣길 2020_10_25*/
/** 계속되는 폭우로 일부 지역이 물에 잠겼습니다. 물에 잠기지 않은 지역을 통해 학교를 가려고 합니다. 
 *  집에서 학교까지 가는 길은 m x n 크기의 격자모양으로 나타낼 수 있습니다.
 *  아래 그림은 m = 4, n = 3 인 경우입니다.
 *  
 *  가장 왼쪽 위, 즉 집이 있는 곳의 좌표는 (1, 1)로 나타내고 가장 오른쪽 아래, 즉 학교가 있는 곳의 좌표는 (m, n)으로 나타냅니다.
 *  격자의 크기 m, n과 물이 잠긴 지역의 좌표를 담은 2차원 배열 puddles이 매개변수로 주어집니다. 
 *  오른쪽과 아래쪽으로만 움직여 집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지를 return 하도록 solution 함수를 작성해주세요.
 * 
 *  제한사항
 *  격자의 크기 m, n은 1 이상 100 이하인 자연수입니다.
 *  m과 n이 모두 1인 경우는 입력으로 주어지지 않습니다.
 *  물에 잠긴 지역은 0개 이상 10개 이하입니다.
 *  집과 학교가 물에 잠긴 경우는 입력으로 주어지지 않습니다.
 *  입출력 예
 *  m	n	puddles	return
 *  4	3	[[2, 2]]	4 **/

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




