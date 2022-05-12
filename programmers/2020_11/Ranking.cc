/* 순위 2020_11_01 */
/** n명의 권투선수가 권투 대회에 참여했고 각각 1번부터 n번까지 번호를 받았습니다. 권투 경기는 1대1 방식으로 진행이 되고, 
 *  만약 A 선수가 B 선수보다 실력이 좋다면 A 선수는 B 선수를 항상 이깁니다. 심판은 주어진 경기 결과를 가지고 선수들의 순위를 매기려 합니다. 하지만 몇몇 경기 결과를 분실하여 정확하게 순위를 매길 수 없습니다.
 *  선수의 수 n, 경기 결과를 담은 2차원 배열 results가 매개변수로 주어질 때 정확하게 순위를 매길 수 있는 선수의 수를 return 하도록 solution 함수를 작성해주세요.
 * 
 *  제한사항
 *  선수의 수는 1명 이상 100명 이하입니다.
 *  경기 결과는 1개 이상 4,500개 이하입니다.
 *  results 배열 각 행 [A, B]는 A 선수가 B 선수를 이겼다는 의미입니다.
 *  모든 경기 결과에는 모순이 없습니다.
 *  
 *  입출력 예
 *  n	results	return
 *  5	[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]	2
 *  입출력 예 설명
 *  2번 선수는 [1, 3, 4] 선수에게 패배했고 5번 선수에게 승리했기 때문에 4위입니다.
 *  5번 선수는 4위인 2번 선수에게 패배했기 때문에 5위입니다. **/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool visited[101];
vector<vector<int> > adj;

void dfs(int start, int direction) {
    if (visited[start]) return;
    visited[start] = true;
    vector<int> neighbor = adj[start];

    for (int i = 0; i < neighbor.size(); ++i) {
        if (neighbor[i] * direction > 0) {
            dfs (abs(neighbor[i]), direction);
        }
    }
}

int solution(int n, vector<vector<int> > results) {
    int answer = 0;
    bool canDecide = true;
    adj.resize(n+1);

    for (int i = 0; i < results.size(); ++i) {
        adj[results[i][0]].push_back(results[i][1]);
        adj[results[i][1]].push_back(-results[i][0]);
    }

    for (int i = 1; i <= n; ++i) {
        canDecide = true;
        memset (visited, false, sizeof(visited));
        dfs (i, 1);
        visited[i] = false;
        dfs (i, -1);

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                canDecide = false;
                break;
            }
        }

        if (canDecide) answer++;
    }

    return answer;
}

int main() {
    vector<vector<int> > results;
    int n = 8;
    vector<int> adj1 {1,2};
    vector<int> adj2 {2,3};
    vector<int> adj3 {3,4};
    vector<int> adj4 {5,6};
    vector<int> adj5 {6,7};
    vector<int> adj6 {7,8};

    results.push_back(adj1);
    results.push_back(adj2);
    results.push_back(adj3);
    results.push_back(adj4);
    results.push_back(adj5);
    results.push_back(adj6);

    int answer = solution(n, results);

    cout << answer << endl;

    return 0;
}




