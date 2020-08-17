#include <vector>
#include <map>
#include <limits.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int fb = INT_MIN, sb = INT_MIN;
    int fs = 0, ss=0;

    for (int i=0; i<prices.size(); ++i) {
        fb = max(fb, -prices[i]);
        fs = max(fs, fb+prices[i]);
        sb = max(sb, fs-prices[i]);
        ss = max(ss, sb+prices[i]);
    }

    return ss;
}

int main() {
    vector<int> prices {3,3,5,0,0,3,1,4};
    int answer = maxProfit(prices);

    printf("%d\n", answer);

    return 0;
}