/* 도둑질 */

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