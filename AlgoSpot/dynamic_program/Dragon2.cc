#include <iostream>
#include <math.h>
#include <string>

/* 종만북에 나온 코드 */

using namespace std;
const int MAX = 1000000000+1;
int number_of_test_cases = 0;
int n=0;
int p=0;
int l=0;
int length[51];
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

void SetLength() {
    length[0] =1;
    for (int i=1; i<=50; ++i) {
        length[i] = min (MAX, length[i-1]*2+2);
    }
}

char Dragon(const string &seed, int generation, int skip) {
    if (generation ==0) return seed[skip];

    for (int i=0; i<seed.size(); ++i) {
        if (seed[i] == 'X' || seed[i] == 'Y') {
            if (skip >= length[generation]) skip -= length[generation];
            else if (seed[i] == 'X') return Dragon(EXPAND_X, generation-1, skip);
            else return Dragon(EXPAND_Y, generation-1, skip);
        } else if (skip >0) {
            skip--;
        } else {
            return seed[i];
        }
    }
    
    return '#';
}

int main() {
    SetLength();
    cin >> number_of_test_cases;

    for (int i=0; i < number_of_test_cases; ++i) {
        cin >> n >> p >> l;
        for (int j=p-1; j<p+l-1; ++j) {
            cout << Dragon("FX",n, j);
        }
        cout <<endl;
    }

    return 0;
}

















