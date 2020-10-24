/* 도둑질 */

#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[1000000];

int maxProfit (vector<int> &money, int start){
    int &ret = cache[start];
    int fst, snd;
    if (ret != -1) return ret;
    if (money.size()-1 < start) return 0;

    ret = money[start];
    if (money.size()-1 == start) return ret;

    fst = ret + maxProfit(money, start+2);
    snd = maxProfit(money, start+1);
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
    fst = money[0] + maxProfit(money, 2);
    memset(cache, -1, sizeof(cache));
    money.push_back(back);
    snd = maxProfit(money, 1);

    return max(fst, snd);
}

int main() {
    vector<int> money;
    money.push_back(1);
    money.push_back(2);
    money.push_back(3);
    money.push_back(1);

    int answer = solution(money);
    cout << answer << endl;
    return 0;
}