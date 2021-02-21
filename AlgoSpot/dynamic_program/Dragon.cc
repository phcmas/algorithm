#include <math.h>
#include <iostream>
#include <string>

using namespace std;

/* 내가 처음 구현 했던 코드 - 논리자체는 맞으나 시간초과 및 스택이 터지는 것으로 추정 */

int number_of_created = 5;
int number_of_test_cases = 1;
int n=0;
int p=0;
int l=0;
string dragon0 = "FX";
string dragon1= "FX+YF";

string Dragon(int m, string &previous_dragon) {
    // m이 2이상이라고 가정, (m-1)번째 dragon을 받아서 m번째 dragon을 생성
    string mth_dragon = previous_dragon;

    for (int i= 3* pow(2,m-2)-1; i< previous_dragon.size(); ++i) {
        switch (previous_dragon[i]) {
            case 'X':{
                mth_dragon += "X+YF";
                number_of_created +=4;
                break;
            }
            case 'Y': {
                mth_dragon += "FX-Y";
                number_of_created +=4;
                break;
            }
            default: {
                mth_dragon += previous_dragon[i];
                number_of_created ++;
                break;
            }
        }

        if (number_of_created >= p+l) return mth_dragon.substr(p-1,l);
    }

    return Dragon (m+1, mth_dragon);
}

int main() {
    cin >> number_of_test_cases;

    for (int i=0; i<number_of_test_cases; ++i) {
        cin >> n >> p >> l;
        if (n==0) {
            cout << dragon0.substr(p-1,l) << endl;
        } else if (n==1) {
            cout << dragon1.substr(p-1,l) << endl;
        } else {
            cout << Dragon(2, dragon1) << endl;
        }
    }

    return 0;
}