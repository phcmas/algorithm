#include <iostream>
#include <string>
#include <cstring>

/* 종만북에 나온 코드 재현 */
using namespace std;

const int MOD = 1000000007;
string digits;
string e;
int n;
int m;
int cache[1<<14][20][2];
int number_of_test_cases;

string quickSort (string e) {
    int min_index =0;
    char temp;

    for (int i=0; i<e.size();++i) {
        min_index = i;
        for (int j=i+1; j<e.size(); ++j) {
            if (e[j] < e[min_index]) min_index = j;
        }
        temp = e[i];
        e[i] = e[min_index];
        e[min_index] = temp;
    }

    return e;
}

int price (int index, int taken, int mod, int less) {
    if (index == n) return (less && mod ==0) ? 1 : 0;

    int &ret = cache[taken][mod][less];
    if (ret != -1) return ret;
    ret =0;

    for (int i=0; i < n; ++i) {
        if ((taken & (1<<i)) !=0) continue;
        if (!less && e[index] < digits[i]) continue;
        if (i>0 && digits[i-1] == digits[i] && (taken & (1<<i-1)) == 0) continue;

        int nextTaken = taken | (1<<i);
        int nextMod = (mod*10 + digits[i] -'0') %m;
        int nextLess = less || e[index] > digits[i];
        ret += price (index+1, nextTaken, nextMod, nextLess);
        ret %= MOD;
    }
    return ret;
}

int main() {
    cin>> number_of_test_cases;
    
    for (int i=0; i < number_of_test_cases; ++i) {
        memset (cache, -1, sizeof(cache));
        cin >> e >> m;
        n = e.size();
        digits = quickSort(e);
        cout << price(0,0,0,0) << endl;
    }

    return 0;

}