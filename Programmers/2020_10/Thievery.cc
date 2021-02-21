/* 도둑질 2020_10_24*/
/** 도둑이 어느 마을을 털 계획을 하고 있습니다. 이 마을의 모든 집들은 아래 그림과 같이 동그랗게 배치되어 있습니다.
 *  각 집들은 서로 인접한 집들과 방범장치가 연결되어 있기 때문에 인접한 두 집을 털면 경보가 울립니다.
 *  각 집에 있는 돈이 담긴 배열 money가 주어질 때, 도둑이 훔칠 수 있는 돈의 최댓값을 return 하도록 solution 함수를 작성하세요.
 * 
 *  제한사항
 *  이 마을에 있는 집은 3개 이상 1,000,000개 이하입니다.
 *  money 배열의 각 원소는 0 이상 1,000 이하인 정수입니다.
 *  입출력 예
 *  money	return
 *  [1, 2, 3, 1]	4 **/

#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[1000000][2];

int maxProfit (vector<int> &money, int start, int firstSelected){
    int &ret = cache[start][firstSelected];
    int fst, snd;
    if (ret != -1) return ret;
    if (money.size()-1 < start) return 0;

    ret = money[start];
    if (money.size()-1 == start) return ret;

    fst = ret + maxProfit(money, start+2, firstSelected);
    snd = maxProfit(money, start+1, firstSelected);
    ret = max (fst, snd);

    return ret;
}

int solution(vector<int> money) {
    int answer = 0;
    int fst, snd;
    int back;
    memset(cache, -1, sizeof(cache));

    back = money.back();
    money.pop_back();
    fst = money[0] + maxProfit(money, 2, 1);
    
    money.push_back(back);
    snd = maxProfit(money, 1, 0);

    return max(fst, snd);
}

int main() {
    vector<int> money {1,2,3,1};

    int answer = solution(money);
    cout << answer << endl;
    return 0;
}